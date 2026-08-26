/*
 * shandalar/ui.h - User Interface, Window Procedures & Dialogs
 */
#ifndef SHANDALAR_UI_H
#define SHANDALAR_UI_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* UI Window Procedures & Dialog Handlers */
LRESULT CALLBACK UI_BigCardWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL    CALLBACK UI_BigCardDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
ATOM             UI_RegisterBigCardClass(HINSTANCE hInstance);
int              Merchant_ProcessBuy(HWND hwnd, int item_id);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_UI_H */
