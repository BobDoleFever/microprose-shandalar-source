# SDL2 Win32 API implementation plan

> **Status:** a code review written on 2026-08-27, before the oracle-based verification work. Its counts (358 imported Win32 entry points, 32 implemented) were not re-checked and the tree has changed since. Use it as a starting checklist, not as fact.

## Goal

Provide the Windows 95 behavior that the recovered game code needs, while keeping SDL2 and portable C as the platform boundary. The target runtime path is:

`recovered game code -> Win32-compatible API -> SDL2 or portable operating-system service`

This plan does not propose a general Win32 implementation. It implements only behavior that the seven recovered game binaries use.

## Review scope and method

The review covered:

- `src/platform/display_shim_sdl2.c`, `src/platform/win32_compat.c`, and the related headers.
- Recovered source under `src/magic`, `src/duel`, `magic`, `duel`, `deck`, `deckdll`, `magsnd`, `magvid`, and `statwin`.
- The external import inventories in each `symbols.csv` file.
- The caller inventories in `scratch_*_context.tsv`.
- The Make and CMake build definitions.

The seven import inventories contain 358 distinct Windows or Windows-multimedia entry points after the C runtime and `DeckBuilderMain` are excluded. The caller inventories identify callers for 355 of them. `CreatePolygonRgn`, `LoadAcceleratorsA`, and `SetWindowRgn` are imported but do not have a recovered caller.

Only 32 imported APIs have a same-name definition in `src/platform/win32_compat.c`. The other 326 APIs have no same-name implementation. `display_shim_sdl2.c` contains low-level helpers for three of the missing APIs, but the legacy call sites cannot use them because the names, signatures, handles, and state models are different.

The present Makefile also builds a small reconstructed game path, not the complete recovered source tree. CMake declares recovered core and monolithic libraries, but it does not include the SDL2 platform sources or link a runnable full-game target. API completion is necessary, but the full game will also require staged source integration and removal of decompiled Microsoft C runtime code.

## Current support assessment

### Display helpers

`display_shim_sdl2.c` currently provides window creation, palette expansion, texture presentation, a basic event poller, and these software helpers:

| Helper | Intended Win32 equivalent | Current limitation |
| --- | --- | --- |
| `Shim_CreateDIBSection` | `CreateDIBSection` | It has a different signature and returns the pixel pointer as the handle. It does not keep bitmap metadata, DIB orientation, four-byte row alignment, a palette, or mapping ownership. |
| `Shim_BitBlt` | `BitBlt` | It accepts `ScreenSurface`, not `HDC`. It ignores the raster operation. It does not fully clip negative source or destination coordinates. It uses `memcpy` for possible overlapping regions. |
| `Shim_StretchBlt` | `StretchBlt` | It accepts `ScreenSurface`, not `HDC`. It ignores raster operations, mirroring, DC state, and parts of source clipping. |

The event path is duplicated. `Shandalar_PollEvents` consumes SDL events but does not dispatch them. `GetMessageA` separately consumes SDL events and emits only a small message subset. These paths can lose events if both are used.

### Same-name Win32 definitions

The current same-name definitions are:

`BringWindowToTop`, `CreateThread`, `CreateWindowExA`, `DefWindowProcA`, `DeleteCriticalSection`, `DispatchMessageA`, `DuplicateHandle`, `FindWindowA`, `FindWindowExA`, `GetCurrentProcess`, `GetCurrentThread`, `GetDC`, `GetDeviceCaps`, `GetMessageA`, `GetStockObject`, `GetTickCount`, `InitializeCriticalSection`, `LoadCursorA`, `LoadIconA`, `MessageBoxA`, `PeekMessageA`, `PostMessageA`, `PostQuitMessage`, `RegisterClassA`, `ReleaseDC`, `SetSystemPaletteUse`, `ShowWindow`, `TranslateMessage`, `UpdateWindow`, `timeBeginPeriod`, `timeEndPeriod`, and `timeSetEvent`.

Most of these functions are placeholders rather than compatible implementations:

- One global window procedure replaces the class registry.
- Every created window receives the handle value `1`. A child-window tree does not exist.
- `CreateWindowExA` attempts to initialize the one SDL window for every legacy window.
- `PostMessageA` calls the window procedure immediately instead of adding a message to a queue.
- `PeekMessageA` calls `GetMessageA`, ignores `PM_REMOVE`, and can block or synthesize paint work.
- Mouse coordinates are clamped to 640 x 480 instead of being mapped through the SDL logical viewport.
- Key symbols are passed as Win32 virtual-key codes without translation. Key-up, character, focus, resize, capture, double-click, wheel, activation, and timer messages are absent.
- `CreateThread` does not run its start routine. Critical-section functions do not lock. Multimedia timers do not call their callbacks.
- DC, stock-object, icon, cursor, process, thread, and duplicated handles are fake constants.
- Window visibility, focus, z-order, paint invalidation, palette selection, and update calls do not keep state.

These definitions must be upgraded even though they do not appear in the 326-symbol missing list.

### Highest-use gaps

Caller counts show that the first implementation work must focus on object state, messages, and GDI:

| API | Recovered functions that call it |
| --- | ---: |
| `LeaveCriticalSection` | 172 |
| `EnterCriticalSection` | 169 |
| `GetStockObject` | 168 |
| `SendMessageA` | 165 |
| `DeleteObject` | 147 |
| `GetClientRect` | 142 |
| `GetWindowLongA` | 138 |
| `SelectObject` | 135 |
| `FillRect` | 130 |
| `InvalidateRect` | 97 |
| `CreateWindowExA` | 51 |
| `BitBlt` | 45 |
| `CreateDIBSection` | 19 |
| `SetDIBitsToDevice` | 11 |

## Architecture

Do not add all compatibility code to `display_shim_sdl2.c`. Keep that file responsible for the SDL window, renderer, texture, palette upload, logical-size conversion, and final presentation. Add small compatibility modules around it:

| Proposed module | Responsibility |
| --- | --- |
| `platform_handle.[ch]` | Type-tagged 32-bit handle IDs, validation, ownership, reference counts, and diagnostics. |
| `win32_user.c` | Window classes, logical top-level and child windows, focus, capture, z-order, geometry, text, controls, menus, and dialogs. |
| `win32_message.c` | FIFO message queue, send and post semantics, timers, SDL event translation, and paint scheduling. |
| `win32_gdi.c` | DCs, bitmap/DIB objects, palettes, pens, brushes, fonts, regions, clipping, transforms, drawing, and blits. |
| `win32_kernel.c` | Files, mappings, resources, global memory, threads, synchronization, clocks, module lookup, and error state. |
| `win32_config.c` | INI profile calls, registry emulation, path policy, and persisted game settings. |
| `win32_multimedia.c` | WinMM timers, WAV and MMIO adapters, the MAGSND bridge, and optional AVI adapters. |

Many recovered structures store handles in 32-bit `int` fields. Raw SDL pointers are unsafe on 64-bit systems. The handle registry must therefore return small 32-bit IDs and resolve them to native objects. It must not expose SDL pointers as `HWND`, `HDC`, or `HGDIOBJ` values.

Keep one SDL top-level window for each visible game application window. Represent the original Win32 child windows as logical objects rendered into the shared 8-bit framebuffer. This preserves the original window procedures and avoids creating many native child windows that SDL2 cannot manage.

## Implementation phases

### Phase 0: Freeze the compatibility contract

1. Generate a checked API manifest from the seven `symbols.csv` files. Record the owning binary and recovered caller count for each symbol.
2. Add the required Win32 constants, callback types, and structures to `windows_types.h`. Use fixed-width members when the recovered ABI depends on 32-bit layout.
3. Add the type-tagged handle registry. Reject a handle when its type does not match the requested API.
4. Add thread-local `GetLastError` state and a trace mode that reports an unsupported API once, with its first caller.
5. Add a link target that compiles recovered modules against the compatibility library. An unresolved import or an uncategorized manifest entry must fail this target.

Exit condition: all 358 imports are classified as implemented, intentionally replaced, optional, or removed with the host CRT. The build has no accidental implicit function declarations.

### Phase 1: Window objects, messages, and input

Implement the class registry and logical window tree first. Support multiple registered classes, per-window procedures, parent/owner links, control IDs, styles, rectangles, text, visibility, enable state, user data, focus, capture, and z-order.

Implement correct synchronous `SendMessageA` and `CallWindowProcA` behavior. Implement an asynchronous FIFO for `PostMessageA`. Make `GetMessageA` and `PeekMessageA` honor filters, target windows, `PM_REMOVE`, `WM_QUIT`, and empty-queue behavior. Use one SDL event intake function.

Translate SDL events to the required Win32 messages. Initial coverage must include create/destroy, close/quit, paint, size, activation, focus, timer, command, horizontal and vertical scroll, key-down, key-up, character input, mouse move, both mouse buttons, double-click, capture changes, and palette notifications. Map pointer coordinates through the renderer logical viewport. Convert SDL key codes and modifiers to Win32 virtual-key and `MK_*` values.

Implement the window, geometry, focus, input, and timer APIs in the inventory. Use `SDL_ShowMessageBox` for message boxes. Use logical controls for dialogs and menus. Load dialog definitions and accelerator tables from a portable resource manifest rather than attempting to execute PE resources.

Exit condition: the recovered startup code can register all classes, create its complete logical child-window tree, receive timer and input messages in order, repaint invalid regions, and close cleanly.

### Phase 2: GDI object and framebuffer compatibility

Create typed objects for DCs, DIBs, compatible bitmaps, palettes, fonts, pens, brushes, and regions. A memory DC must own selected-object state and a clip region. A window DC must target the logical window's rectangle in the shared 8-bit framebuffer.

Replace the current DIB helper with a real `CreateDIBSection` adapter. Parse `BITMAPINFO`, use four-byte aligned rows, support top-down and bottom-up DIBs, retain palette and mapping ownership, and return a separate bitmap handle and pixel pointer.

Wire `BitBlt` and `StretchBlt` through HDC lookup. Implement the raster operations observed in recovered call sites first:

- `SRCCOPY` (`0x00CC0020`)
- `SRCAND` (`0x008800C6`)
- `SRCPAINT` (`0x00EE0086`)

Add correct source and destination clipping, overlapping copies, negative extents, DIB orientation, selected palettes, and nearest-neighbor stretch behavior. Then implement DIB transfer, palette, drawing, text, transform, save/restore, and region APIs. Reuse the recovered bitmap font path where possible. Add SDL_ttf only if the original text metrics cannot be reproduced from game assets.

`GdiFlush`, `EndPaint`, and `UpdateWindow` must mark or present the shared framebuffer through `Shandalar_UpdateSurface` and `Shandalar_PresentFrame`. Presentation must occur on the main SDL thread.

Exit condition: pixel tests match reference output for menu art, card art, transparent text masks, palette changes, clipping, and scaled blits. DIB and GDI objects have no leaks or stale selected handles.

### Phase 3: Files, resources, modules, and configuration

Implement Win32 files on portable file descriptors or `SDL_RWops`. Support read, write, size, seek, flush, copy, delete, directory creation, mappings, and handle closure. Add a path resolver that converts backslashes, resolves the configured asset root, and performs controlled case-insensitive lookup for original asset names on case-sensitive file systems.

Replace CD-ROM probing through `GetDriveTypeA` and `DeviceIoControl` with an asset-location service. Do not access physical drives.

Implement global memory and resource handles. Store icons, cursors, bitmaps, dialogs, accelerators, and strings in a generated portable resource manifest. Implement `LoadLibraryA` and `GetProcAddress` as a static module/export registry for MAGSND, MAGVID, DECKDLL, and STATWIN. Do not try to load the original PE DLLs on macOS or Linux.

Implement INI profile calls and registry calls on one portable settings store. Preserve Win32 default-value and buffer-size behavior. Remove the hard-coded asset path from `src/main_game_entry.c` and resolve assets from a command-line option, environment override, or platform data directory.

Exit condition: startup, save/load, deck data, card art, and configuration work from paths that contain spaces and from a case-sensitive file system.

### Phase 4: Threads, synchronization, timers, and sound

Implement `CRITICAL_SECTION` with a recursive SDL mutex. Implement threads, exit codes, waits, priorities as best-effort hints, and handle cleanup. Use SDL atomics or compiler atomics for interlocked operations. Implement `Sleep` with `SDL_Delay`.

Implement `SetTimer` and WinMM timer IDs on a monotonic clock. Queue callbacks or `WM_TIMER` messages to the main thread unless a recovered call site explicitly requires a worker callback. `timeKillEvent` and `KillTimer` must prevent future callbacks and be safe during shutdown.

Bypass the DirectSound COM interface at the MAGSND boundary. Implement the recovered high-level sound exports with SDL audio: WAV loading, mixing, volume, pan, pitch policy, markers, pause/resume, and deterministic channel ownership. Implement only the MMIO RIFF operations still used after this replacement.

Exit condition: the main loop and audio worker do not race, all timer and thread handles terminate, and sound effects and music can play, stop, pause, and resume.

### Phase 5: Dialogs, menus, common dialogs, and deck tools

Complete the logical implementations for dialog controls, check and radio buttons, scroll bars, popup menus, accelerator dispatch, and modal loops. Implement open/save selection as an in-game SDL dialog or a small optional platform abstraction. Keep headless defaults for automated tests.

Treat `Ordinal_17` as `InitCommonControls`; this identification is an inference from its use during class registration. It can register the logical control classes and then return success. Treat `SHAppBarMessage` as a request for the SDL display work area. Treat `WinHelpA` as optional: open bundled documentation when available, or log one nonfatal message.

Exit condition: deck builder and status windows can open, edit data, use popup menus and scroll bars, and close without blocking the main message loop.

### Phase 6: AVI playback

The MAGVID and coin-toss paths use AVIFile, AVIStream, DrawDib, ICM, MCIWnd, MMIO, and waveOut APIs. SDL2 does not decode AVI video.

Use two delivery levels:

1. Cross-platform runtime milestone: make video calls nonfatal, preserve timing and completion messages, and display a still frame or skip the clip.
2. Fidelity milestone: implement a narrow adapter with libavformat/libavcodec, or convert the original AVI assets to a supported format during asset preparation. Render decoded frames into the same SDL texture path and send the original completion messages.

Do not implement a general Video for Windows codec manager.

Exit condition: all video paths complete without deadlock. The optional fidelity backend keeps audio and video time within one frame at the target frame rate.

### Phase 7: Remove recovered CRT dependencies and integrate the full build

Do not implement the Windows APIs that appear only because Microsoft C runtime startup and heap code was decompiled. Compile against the host C runtime and exclude recovered CRT units such as heap, environment, locale, exception, and low-level stream startup code where a normal C99 function already replaces them.

Integrate recovered game modules in vertical slices: startup and menu, overworld, duel, deck builder, sound, status, then video. Add each slice to both Make and CMake after its required API group passes tests.

Exit condition: the complete application links without the original Windows DLLs or decompiled Microsoft CRT, and no runtime path reports an unsupported required API.

## API-family work list

| Priority | Family | Required work |
| --- | --- | --- |
| P0 | Handles and lifecycle | Real window, DC, GDI object, file, map, module, thread, timer, resource, and global-memory handles. Implement `CloseHandle`, `DeleteObject`, `DeleteDC`, and `DestroyWindow` with type checks. |
| P0 | Window and messages | Class registry, window tree, send/post queue, paint invalidation, geometry, focus, capture, SDL input conversion, scroll state, timers, and modal loops. |
| P0 | GDI and DIB | DC state, DIB allocation and transfer, palette realization, `SRCCOPY`/`SRCAND`/`SRCPAINT`, clipping, transforms, primitives, and text metrics/output. |
| P0 | Files and assets | File I/O, mappings, path normalization, case-insensitive asset lookup, resource manifest, and static DLL export lookup. |
| P1 | Synchronization and sound | Recursive locks, real threads and waits, multimedia timers, WAV mixer, and the high-level MAGSND adapter. |
| P1 | Dialog and deck UI | Controls, menus, accelerators, common file dialogs, settings persistence, and deck/status windows. |
| P2 | Video | Nonfatal skip/still fallback first, then a narrow AVI decoder adapter. |
| Remove | Recovered CRT support | Use the host C runtime instead of emulating Windows heap, environment, locale, exception, and console-startup internals. |

## Test and verification plan

1. Run unit tests with `SDL_VIDEODRIVER=dummy` for handles, message order, `PeekMessageA`, focus, capture, timers, rectangles, paths, file mappings, and object destruction.
2. Use `SDL_PushEvent` to test every supported input translation without manual input.
3. Add byte-exact tests for DIB row layout, top-down and bottom-up images, each required raster operation, clipping, palette updates, and stretch samples.
4. Add framebuffer checksum or golden-image tests for the main menu, overworld, duel battlefield, dialog, and deck builder.
5. When possible, record API traces and framebuffer hashes from the original program under Windows or Wine. Compare message order, return values, and pixels at stable checkpoints.
6. Run AddressSanitizer and UndefinedBehaviorSanitizer builds. Test invalid, double-freed, and selected-then-deleted handles.
7. Build and run CI on macOS, Linux, and Windows, on at least one 64-bit ARM target and one 64-bit x86 target.

## Runtime acceptance criteria

- No raw SDL pointer is stored in a recovered 32-bit handle field.
- No required API returns a constant success value without preserving the state that callers later query.
- The application has one SDL event intake path and one ordered Win32-compatible message queue.
- The asset root is configurable and no user-specific absolute path remains.
- A user can start a campaign, move on the overworld, enter and finish a duel, open the deck builder, save, reload, and exit.
- Resize, fullscreen, focus loss, mouse capture, keyboard input, palette changes, sound, and clean shutdown work on all target platforms.
- Video can be optional for the first runtime milestone, but video calls must remain nonfatal and must preserve control flow.
- The compatibility manifest has no uncategorized or unresolved required import.

## Exact missing same-name symbol inventory

The following 326 imported APIs have no same-name definition in the current compatibility layer. Some will be replaced at a higher subsystem boundary or removed with the recovered CRT instead of being implemented literally.

```text
AVIFileExit, AVIFileGetStream, AVIFileInit, AVIFileOpenA, AVIFileRelease,
AVIStreamFindSample, AVIStreamInfoA, AVIStreamRead, AVIStreamReadFormat,
AVIStreamRelease, AVIStreamSampleToTime, AVIStreamTimeToSample,
AddFontResourceA, AdjustWindowRect, AnimatePalette, AppendMenuA, BeginPaint,
BitBlt, CallWindowProcA, CheckDlgButton, CheckMenuItem, CheckRadioButton,
ClientToScreen, CloseHandle, CompareStringA, CompareStringW, CopyFileA,
CopyRect, CreateBitmap, CreateBrushIndirect, CreateCompatibleBitmap,
CreateCompatibleDC, CreateDCA, CreateDIBSection, CreateDirectoryA, CreateFileA,
CreateFileMappingA, CreateFontA, CreateFontIndirectA, CreateHatchBrush,
CreatePalette, CreatePen, CreatePenIndirect, CreatePolygonRgn, CreatePopupMenu,
CreateRectRgn, CreateRectRgnIndirect, CreateSolidBrush, DPtoLP, DebugBreak,
DeleteDC, DeleteFileA, DeleteMenu, DeleteObject, DestroyCursor, DestroyIcon,
DestroyMenu, DestroyWindow, DeviceIoControl, DialogBoxParamA,
DirectSoundCreate, DisableThreadLibraryCalls, DrawDibBegin, DrawDibClose,
DrawDibDraw, DrawDibEnd, DrawDibOpen, DrawDibStart, DrawDibStop,
DrawFocusRect, DrawTextA, Ellipse, EnableMenuItem, EnableWindow, EndDialog,
EndPaint, EnterCriticalSection, EnumChildWindows, ExitProcess, ExitThread,
FillRect, FindResourceA, FlushFileBuffers, FormatMessageA, FrameRect,
FreeEnvironmentStringsA, FreeEnvironmentStringsW, FreeLibrary, GdiFlush,
GdiGetBatchLimit, GdiSetBatchLimit, GetACP, GetActiveWindow,
GetAsyncKeyState, GetCPInfo, GetCapture, GetCharABCWidthsA, GetCharWidthA,
GetClassNameA, GetClientRect, GetCommandLineA, GetCurrentDirectoryA,
GetCursorPos, GetDateFormatA, GetDesktopWindow, GetDlgCtrlID, GetDlgItem,
GetDlgItemInt, GetDlgItemTextA, GetDoubleClickTime, GetDriveTypeA,
GetEnvironmentStrings, GetEnvironmentStringsW, GetExitCodeThread, GetFileSize,
GetFileType, GetFocus, GetKeyState, GetLastError, GetLocalTime, GetMenu,
GetMenuItemCount, GetMessageTime, GetModuleFileNameA, GetModuleHandleA,
GetNearestPaletteIndex, GetOEMCP, GetObjectA, GetOpenFileNameA,
GetPaletteEntries, GetParent, GetPixel, GetPriorityClass,
GetPrivateProfileIntA, GetPrivateProfileStringA, GetProcAddress,
GetSaveFileNameA, GetScrollPos, GetScrollRange, GetStartupInfoA, GetStdHandle,
GetStringTypeA, GetStringTypeW, GetSubMenu, GetSysColor, GetSystemMetrics,
GetSystemTime, GetTextAlign, GetTextExtentPoint32A, GetTextExtentPointA,
GetTextMetricsA, GetThreadPriority, GetTimeZoneInformation, GetTopWindow,
GetVersion, GetWindow, GetWindowDC, GetWindowLongA, GetWindowRect,
GetWindowTextA, GetWindowThreadProcessId, GetWindowWord, GlobalAlloc,
GlobalFree, GlobalHandle, GlobalLock, GlobalUnlock, HeapAlloc, HeapCreate,
HeapDestroy, HeapFree, HeapReAlloc, HeapValidate, ICClose, ICDrawBegin,
ICLocate, ICSendMessage, InflateRect, InsertMenuA, InterlockedDecrement,
InterlockedIncrement, IntersectClipRect, IntersectRect, InvalidateRect,
IsBadReadPtr, IsBadWritePtr, IsDlgButtonChecked, IsIconic, IsRectEmpty,
IsWindowVisible, KillTimer, LCMapStringA, LCMapStringW, LPtoDP,
LeaveCriticalSection, LineTo, LoadAcceleratorsA, LoadBitmapA, LoadLibraryA,
LoadResource, LocalFree, LockResource, LockWindowUpdate, MCIWndCreateA,
MapViewOfFile, MapWindowPoints, MessageBeep, ModifyMenuA, MoveToEx, MoveWindow,
MultiByteToWideChar, OffsetRect, OffsetViewportOrgEx, Ordinal_17,
OutputDebugStringA, PtInRect, ReadFile, RealizePalette, Rectangle, RegCloseKey,
RegCreateKeyExA, RegFlushKey, RegOpenKeyExA, RegQueryValueExA, RegSetValueExA,
ReleaseCapture, RemoveFontResourceA, RemoveMenu, RestoreDC, RoundRect, RtlUnwind,
SHAppBarMessage, SaveDC, ScreenToClient, ScrollWindow, SelectClipRgn,
SelectObject, SelectPalette, SendDlgItemMessageA, SendMessageA, SetActiveWindow,
SetBitmapDimensionEx, SetBkColor, SetBkMode, SetCapture, SetClassLongA,
SetConsoleCtrlHandler, SetCurrentDirectoryA, SetCursor, SetCursorPos,
SetDIBColorTable, SetDIBits, SetDIBitsToDevice, SetDlgItemInt, SetDlgItemTextA,
SetEndOfFile, SetEnvironmentVariableA, SetFilePointer, SetFocus,
SetForegroundWindow, SetHandleCount, SetMapMode, SetPaletteEntries, SetParent,
SetPixel, SetPixelV, SetPriorityClass, SetROP2, SetRect, SetRectRgn,
SetScrollPos, SetScrollRange, SetStdHandle, SetStretchBltMode, SetTextAlign,
SetTextColor, SetThreadPriority, SetTimer, SetViewportExtEx, SetViewportOrgEx,
SetWindowExtEx, SetWindowLongA, SetWindowOrgEx, SetWindowPos, SetWindowRgn,
SetWindowTextA, SetWindowWord, ShowCursor, Sleep, StretchBlt, TerminateProcess,
TextOutA, TrackPopupMenu, TranslateAcceleratorA, UnhandledExceptionFilter,
UnionRect, UnmapViewOfFile, UnrealizeObject, UnregisterClassA, VirtualAlloc,
VirtualFree, WaitForSingleObject, WideCharToMultiByte, WinHelpA, WindowFromPoint,
WriteFile, _lclose, _lopen, lstrcatA, lstrcpyA, lstrlenA, mmioAdvance,
mmioAscend, mmioClose, mmioDescend, mmioGetInfo, mmioOpenA, mmioRead,
mmioSeek, mmioSetInfo, timeGetDevCaps, timeGetTime, timeKillEvent,
waveOutWrite, wsprintfA, wvsprintfA
```
