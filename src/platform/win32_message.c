/*
 * src/platform/win32_message.c - Win32 Message Queue, Event Translation & Timers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>

#include <SDL.h>

#include "windows_types.h"
#include "shandalar/platform_handle.h"
#include "shandalar/win32_internal.h"
#include "shandalar/win32_compat.h"
#include "shandalar/display_shim.h"

#define MESSAGE_QUEUE_SIZE 1024
#define MAX_TIMERS          64

typedef struct Win32Timer {
    HWND         hwnd;
    UINT_PTR     id;
    UINT         elapse;
    TIMERPROC    timer_proc;
    uint32_t     last_tick;
    bool         is_active;
} Win32Timer;

static struct {
    tagMSG          queue[MESSAGE_QUEUE_SIZE];
    size_t          head;
    size_t          tail;
    size_t          count;

    Win32Timer      timers[MAX_TIMERS];
    size_t          timer_count;

    bool            quit_posted;
    int             quit_code;
    DWORD           last_message_time;

    uint32_t        last_click_time_left;
    POINT           last_click_pos_left;
    uint32_t        last_click_time_right;
    POINT           last_click_pos_right;

    pthread_mutex_t lock;
    bool            is_initialized;
} g_MsgState = {0};

void Message_InternalInit(void)
{
    if (g_MsgState.is_initialized) return;

    pthread_mutex_init(&g_MsgState.lock, NULL);
    pthread_mutex_lock(&g_MsgState.lock);

    g_MsgState.head = 0;
    g_MsgState.tail = 0;
    g_MsgState.count = 0;
    g_MsgState.timer_count = 0;
    g_MsgState.quit_posted = false;
    g_MsgState.quit_code = 0;
    g_MsgState.last_message_time = 0;
    g_MsgState.is_initialized = true;

    pthread_mutex_unlock(&g_MsgState.lock);
}

void Message_InternalShutdown(void)
{
    if (!g_MsgState.is_initialized) return;
    pthread_mutex_destroy(&g_MsgState.lock);
    g_MsgState.is_initialized = false;
}

static WPARAM SdlKeyToVirtualKey(SDL_Keycode sym)
{
    if (sym >= SDLK_a && sym <= SDLK_z) return (WPARAM)('A' + (sym - SDLK_a));
    if (sym >= SDLK_0 && sym <= SDLK_9) return (WPARAM)('0' + (sym - SDLK_0));
    if (sym >= SDLK_F1 && sym <= SDLK_F12) return (WPARAM)(VK_F1 + (sym - SDLK_F1));

    switch (sym) {
        case SDLK_RETURN:    return VK_RETURN;
        case SDLK_ESCAPE:    return VK_ESCAPE;
        case SDLK_BACKSPACE: return VK_BACK;
        case SDLK_TAB:       return VK_TAB;
        case SDLK_SPACE:     return VK_SPACE;
        case SDLK_LEFT:      return VK_LEFT;
        case SDLK_UP:        return VK_UP;
        case SDLK_RIGHT:     return VK_RIGHT;
        case SDLK_DOWN:      return VK_DOWN;
        case SDLK_DELETE:    return VK_DELETE;
        case SDLK_INSERT:    return VK_INSERT;
        case SDLK_HOME:      return VK_HOME;
        case SDLK_END:       return VK_END;
        case SDLK_PAGEUP:    return VK_PRIOR;
        case SDLK_PAGEDOWN:  return VK_NEXT;
        case SDLK_LSHIFT:
        case SDLK_RSHIFT:   return VK_SHIFT;
        case SDLK_LCTRL:
        case SDLK_RCTRL:    return VK_CONTROL;
        case SDLK_LALT:
        case SDLK_RALT:     return VK_MENU;
        default:             return (WPARAM)sym;
    }
}

static WPARAM GetMouseWParam(Uint32 sdl_buttons)
{
    WPARAM wp = 0;
    if (sdl_buttons & SDL_BUTTON_LMASK) wp |= MK_LBUTTON;
    if (sdl_buttons & SDL_BUTTON_RMASK) wp |= MK_RBUTTON;
    if (sdl_buttons & SDL_BUTTON_MMASK) wp |= MK_MBUTTON;

    SDL_Keymod mod = SDL_GetModState();
    if (mod & KMOD_SHIFT) wp |= MK_SHIFT;
    if (mod & KMOD_CTRL)  wp |= MK_CONTROL;
    return wp;
}

static void EnqueueMessage_Locked(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (g_MsgState.count >= MESSAGE_QUEUE_SIZE) {
        /* Drop oldest on overflow */
        g_MsgState.head = (g_MsgState.head + 1) % MESSAGE_QUEUE_SIZE;
        g_MsgState.count--;
    }

    tagMSG *m = &g_MsgState.queue[g_MsgState.tail];
    m->hwnd = hwnd;
    m->message = msg;
    m->wParam = wParam;
    m->lParam = lParam;
    m->time = (DWORD)SDL_GetTicks();
    m->pt.x = (LONG)(lParam & 0xffff);
    m->pt.y = (LONG)((lParam >> 16) & 0xffff);

    g_MsgState.tail = (g_MsgState.tail + 1) % MESSAGE_QUEUE_SIZE;
    g_MsgState.count++;
}

/*
 * Process SDL events and translate to Win32 message queue
 */
static void PumpSdlEvents(void)
{
    SDL_Event event;
    HWND target_hwnd = User_GetActiveWindowInternal();

    while (SDL_PollEvent(&event)) {
        HWND capture = User_GetCaptureInternal();
        HWND cur_target = capture ? capture : target_hwnd;

        switch (event.type) {
            case SDL_QUIT:
                PostQuitMessage(0);
                break;

            case SDL_MOUSEMOTION: {
                int mx = event.motion.x;
                int my = event.motion.y;
                if (mx < 0) mx = 0; else if (mx >= 640) mx = 639;
                if (my < 0) my = 0; else if (my >= 480) my = 479;

                WPARAM wp = GetMouseWParam(event.motion.state);
                LPARAM lp = ((my & 0xffff) << 16) | (mx & 0xffff);

                POINT pt = {mx, my};
                HWND win_at_pt = WindowFromPoint(pt);
                HWND dest = capture ? capture : (win_at_pt ? win_at_pt : cur_target);

                pthread_mutex_lock(&g_MsgState.lock);
                EnqueueMessage_Locked(dest, WM_MOUSEMOVE, wp, lp);
                pthread_mutex_unlock(&g_MsgState.lock);
                break;
            }

            case SDL_MOUSEBUTTONDOWN: {
                int bx = event.button.x;
                int by = event.button.y;
                if (bx < 0) bx = 0; else if (bx >= 640) bx = 639;
                if (by < 0) by = 0; else if (by >= 480) by = 479;

                WPARAM wp = GetMouseWParam(SDL_GetMouseState(NULL, NULL));
                LPARAM lp = ((by & 0xffff) << 16) | (bx & 0xffff);

                POINT pt = {bx, by};
                HWND win_at_pt = WindowFromPoint(pt);
                HWND dest = capture ? capture : (win_at_pt ? win_at_pt : cur_target);

                uint32_t now = SDL_GetTicks();
                UINT msg = WM_LBUTTONDOWN;

                if (event.button.button == SDL_BUTTON_LEFT) {
                    if ((now - g_MsgState.last_click_time_left < 400) &&
                        abs(bx - g_MsgState.last_click_pos_left.x) < 5 &&
                        abs(by - g_MsgState.last_click_pos_left.y) < 5) {
                        msg = WM_LBUTTONDBLCLK;
                    } else {
                        msg = WM_LBUTTONDOWN;
                    }
                    g_MsgState.last_click_time_left = now;
                    g_MsgState.last_click_pos_left.x = bx;
                    g_MsgState.last_click_pos_left.y = by;
                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                    if ((now - g_MsgState.last_click_time_right < 400) &&
                        abs(bx - g_MsgState.last_click_pos_right.x) < 5 &&
                        abs(by - g_MsgState.last_click_pos_right.y) < 5) {
                        msg = WM_RBUTTONDBLCLK;
                    } else {
                        msg = WM_RBUTTONDOWN;
                    }
                    g_MsgState.last_click_time_right = now;
                    g_MsgState.last_click_pos_right.x = bx;
                    g_MsgState.last_click_pos_right.y = by;
                }

                pthread_mutex_lock(&g_MsgState.lock);
                EnqueueMessage_Locked(dest, msg, wp, lp);
                pthread_mutex_unlock(&g_MsgState.lock);
                break;
            }

            case SDL_MOUSEBUTTONUP: {
                int bx = event.button.x;
                int by = event.button.y;
                if (bx < 0) bx = 0; else if (bx >= 640) bx = 639;
                if (by < 0) by = 0; else if (by >= 480) by = 479;

                WPARAM wp = GetMouseWParam(SDL_GetMouseState(NULL, NULL));
                LPARAM lp = ((by & 0xffff) << 16) | (bx & 0xffff);

                POINT pt = {bx, by};
                HWND win_at_pt = WindowFromPoint(pt);
                HWND dest = capture ? capture : (win_at_pt ? win_at_pt : cur_target);
                UINT msg = (event.button.button == SDL_BUTTON_LEFT) ? WM_LBUTTONUP : WM_RBUTTONUP;

                pthread_mutex_lock(&g_MsgState.lock);
                EnqueueMessage_Locked(dest, msg, wp, lp);
                pthread_mutex_unlock(&g_MsgState.lock);
                break;
            }

            case SDL_KEYDOWN: {
                WPARAM vk = SdlKeyToVirtualKey(event.key.keysym.sym);
                LPARAM lp = 1 | ((DWORD)event.key.keysym.scancode << 16);
                if (event.key.repeat) lp |= (1 << 30);

                pthread_mutex_lock(&g_MsgState.lock);
                EnqueueMessage_Locked(cur_target, WM_KEYDOWN, vk, lp);
                pthread_mutex_unlock(&g_MsgState.lock);
                break;
            }

            case SDL_KEYUP: {
                WPARAM vk = SdlKeyToVirtualKey(event.key.keysym.sym);
                LPARAM lp = 1 | ((DWORD)event.key.keysym.scancode << 16) | (1 << 30) | (1 << 31);

                pthread_mutex_lock(&g_MsgState.lock);
                EnqueueMessage_Locked(cur_target, WM_KEYUP, vk, lp);
                pthread_mutex_unlock(&g_MsgState.lock);
                break;
            }

            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
                    SetFocus(cur_target);
                } else if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
                    SetFocus(NULL);
                } else if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                    PostMessageA(cur_target, WM_CLOSE, 0, 0);
                }
                break;

            default:
                break;
        }
    }
}

/* Check active timers and post WM_TIMER messages */
static void CheckTimers(void)
{
    uint32_t now = SDL_GetTicks();

    pthread_mutex_lock(&g_MsgState.lock);
    for (size_t i = 0; i < g_MsgState.timer_count; i++) {
        Win32Timer *t = &g_MsgState.timers[i];
        if (t->is_active && (now - t->last_tick >= t->elapse)) {
            t->last_tick = now;
            HWND target = t->hwnd ? t->hwnd : User_GetActiveWindowInternal();
            if (t->timer_proc) {
                /* Direct callback */
                pthread_mutex_unlock(&g_MsgState.lock);
                t->timer_proc(t->hwnd, WM_TIMER, t->id, now);
                pthread_mutex_lock(&g_MsgState.lock);
            } else {
                EnqueueMessage_Locked(target, WM_TIMER, (WPARAM)t->id, (LPARAM)0);
            }
        }
    }
    pthread_mutex_unlock(&g_MsgState.lock);
}

/* ==========================================================================
 * Win32 Messaging API Functions
 * ========================================================================== */

BOOL PostMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    Message_InternalInit();
    pthread_mutex_lock(&g_MsgState.lock);
    EnqueueMessage_Locked(hWnd, Msg, wParam, lParam);
    pthread_mutex_unlock(&g_MsgState.lock);
    return TRUE;
}

void PostQuitMessage(int nExitCode)
{
    Message_InternalInit();
    pthread_mutex_lock(&g_MsgState.lock);
    g_MsgState.quit_posted = true;
    g_MsgState.quit_code = nExitCode;
    pthread_mutex_unlock(&g_MsgState.lock);
}

LRESULT SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return 0;

    if (w->wndproc) {
        return w->wndproc(hWnd, Msg, wParam, lParam);
    }
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
}

LRESULT CallWindowProcA(WNDPROC lpPrevWndFunc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    if (lpPrevWndFunc) {
        return lpPrevWndFunc(hWnd, Msg, wParam, lParam);
    }
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
}

LRESULT DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    LogicalWindow *w = User_GetWindow(hWnd);
    if (!w) return 0;

    switch (Msg) {
        case WM_CLOSE:
            DestroyWindow(hWnd);
            return 0;

        case WM_ERASEBKGND:
            return 1;

        case WM_PAINT:
            /* Default paint handler if none provided */
            return 0;

        case WM_SETTEXT:
            if (lParam) {
                strncpy(w->text, (const char *)(intptr_t)lParam, sizeof(w->text) - 1);
            } else {
                w->text[0] = '\0';
            }
            return TRUE;

        case WM_GETTEXT:
            if (lParam && wParam > 0) {
                strncpy((char *)(intptr_t)lParam, w->text, wParam - 1);
                ((char *)(intptr_t)lParam)[wParam - 1] = '\0';
                return (LRESULT)strlen((char *)(intptr_t)lParam);
            }
            return 0;

        case WM_GETTEXTLENGTH:
            return (LRESULT)strlen(w->text);

        default:
            return 0;
    }
}

BOOL GetMessageA(tagMSG *lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
    (void)wMsgFilterMin;
    (void)wMsgFilterMax;
    Message_InternalInit();

    while (1) {
        pthread_mutex_lock(&g_MsgState.lock);
        if (g_MsgState.quit_posted) {
            if (lpMsg) {
                lpMsg->hwnd = NULL;
                lpMsg->message = WM_QUIT;
                lpMsg->wParam = (WPARAM)g_MsgState.quit_code;
                lpMsg->lParam = 0;
                lpMsg->time = (DWORD)SDL_GetTicks();
            }
            pthread_mutex_unlock(&g_MsgState.lock);
            return FALSE;
        }

        if (g_MsgState.count > 0) {
            tagMSG m = g_MsgState.queue[g_MsgState.head];
            g_MsgState.head = (g_MsgState.head + 1) % MESSAGE_QUEUE_SIZE;
            g_MsgState.count--;
            g_MsgState.last_message_time = m.time;

            if (!hWnd || m.hwnd == hWnd) {
                if (lpMsg) *lpMsg = m;
                pthread_mutex_unlock(&g_MsgState.lock);
                return (m.message != WM_QUIT);
            }
        }
        pthread_mutex_unlock(&g_MsgState.lock);

        PumpSdlEvents();
        CheckTimers();

        pthread_mutex_lock(&g_MsgState.lock);
        if (g_MsgState.count == 0 && !g_MsgState.quit_posted) {
            pthread_mutex_unlock(&g_MsgState.lock);
            SDL_Delay(1); /* Yield CPU */
        } else {
            pthread_mutex_unlock(&g_MsgState.lock);
        }
    }
}

BOOL PeekMessageA(tagMSG *lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg)
{
    (void)wMsgFilterMin;
    (void)wMsgFilterMax;
    Message_InternalInit();

    PumpSdlEvents();
    CheckTimers();

    pthread_mutex_lock(&g_MsgState.lock);
    if (g_MsgState.quit_posted) {
        if (lpMsg) {
            lpMsg->hwnd = NULL;
            lpMsg->message = WM_QUIT;
            lpMsg->wParam = (WPARAM)g_MsgState.quit_code;
            lpMsg->lParam = 0;
            lpMsg->time = (DWORD)SDL_GetTicks();
        }
        pthread_mutex_unlock(&g_MsgState.lock);
        return TRUE;
    }

    if (g_MsgState.count > 0) {
        tagMSG m = g_MsgState.queue[g_MsgState.head];
        if (!hWnd || m.hwnd == hWnd) {
            if (wRemoveMsg & PM_REMOVE) {
                g_MsgState.head = (g_MsgState.head + 1) % MESSAGE_QUEUE_SIZE;
                g_MsgState.count--;
            }
            g_MsgState.last_message_time = m.time;
            if (lpMsg) *lpMsg = m;
            pthread_mutex_unlock(&g_MsgState.lock);
            return TRUE;
        }
    }

    pthread_mutex_unlock(&g_MsgState.lock);
    return FALSE;
}

BOOL TranslateMessage(const tagMSG *lpMsg)
{
    if (!lpMsg) return FALSE;

    /* If key down is an ASCII character key, generate WM_CHAR */
    if (lpMsg->message == WM_KEYDOWN) {
        WPARAM vk = lpMsg->wParam;
        char ch = 0;
        SDL_Keymod mod = SDL_GetModState();
        bool shift = (mod & KMOD_SHIFT) != 0;

        if (vk >= 'A' && vk <= 'Z') {
            ch = shift ? (char)vk : (char)(vk + ('a' - 'A'));
        } else if (vk >= '0' && vk <= '9') {
            if (!shift) ch = (char)vk;
            else {
                const char *shift_digits = ")!@#$%^&*(";
                ch = shift_digits[vk - '0'];
            }
        } else if (vk == VK_SPACE) {
            ch = ' ';
        } else if (vk == VK_RETURN) {
            ch = '\r';
        } else if (vk == VK_BACK) {
            ch = '\b';
        } else if (vk == VK_TAB) {
            ch = '\t';
        }

        if (ch != 0) {
            PostMessageA(lpMsg->hwnd, WM_CHAR, (WPARAM)(uint8_t)ch, lpMsg->lParam);
            return TRUE;
        }
    }
    return FALSE;
}

LRESULT DispatchMessageA(const tagMSG *lpMsg)
{
    if (!lpMsg) return 0;
    LogicalWindow *w = User_GetWindow(lpMsg->hwnd);
    if (w && w->wndproc) {
        return w->wndproc(lpMsg->hwnd, lpMsg->message, lpMsg->wParam, lpMsg->lParam);
    }
    return DefWindowProcA(lpMsg->hwnd, lpMsg->message, lpMsg->wParam, lpMsg->lParam);
}

DWORD GetMessageTime(void)
{
    return g_MsgState.last_message_time;
}

/* ==========================================================================
 * Win32 Timer Implementation
 * ========================================================================== */

UINT_PTR SetTimer(HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc)
{
    Message_InternalInit();

    pthread_mutex_lock(&g_MsgState.lock);
    /* Check if timer already exists for this hwnd / id */
    for (size_t i = 0; i < g_MsgState.timer_count; i++) {
        if (g_MsgState.timers[i].hwnd == hWnd && g_MsgState.timers[i].id == nIDEvent) {
            g_MsgState.timers[i].elapse = uElapse ? uElapse : 10;
            g_MsgState.timers[i].timer_proc = lpTimerFunc;
            g_MsgState.timers[i].last_tick = SDL_GetTicks();
            g_MsgState.timers[i].is_active = true;
            pthread_mutex_unlock(&g_MsgState.lock);
            return nIDEvent;
        }
    }

    if (g_MsgState.timer_count < MAX_TIMERS) {
        size_t idx = g_MsgState.timer_count++;
        g_MsgState.timers[idx].hwnd = hWnd;
        g_MsgState.timers[idx].id = nIDEvent ? nIDEvent : (UINT_PTR)(idx + 1);
        g_MsgState.timers[idx].elapse = uElapse ? uElapse : 10;
        g_MsgState.timers[idx].timer_proc = lpTimerFunc;
        g_MsgState.timers[idx].last_tick = SDL_GetTicks();
        g_MsgState.timers[idx].is_active = true;
        UINT_PTR ret = g_MsgState.timers[idx].id;
        pthread_mutex_unlock(&g_MsgState.lock);
        return ret;
    }

    pthread_mutex_unlock(&g_MsgState.lock);
    return 0;
}

BOOL KillTimer(HWND hWnd, UINT_PTR uIDEvent)
{
    if (!g_MsgState.is_initialized) return FALSE;

    pthread_mutex_lock(&g_MsgState.lock);
    for (size_t i = 0; i < g_MsgState.timer_count; i++) {
        if (g_MsgState.timers[i].hwnd == hWnd && g_MsgState.timers[i].id == uIDEvent) {
            g_MsgState.timers[i].is_active = false;
            pthread_mutex_unlock(&g_MsgState.lock);
            return TRUE;
        }
    }
    pthread_mutex_unlock(&g_MsgState.lock);
    return FALSE;
}
