/*
 * Decompiled function: UI_CreateWindow_0049d17d
 * Entry Point: 0049d17d
 * Size: 579 bytes
 */
#include "duel.h"


LRESULT UI_CreateWindow_0049d17d(HWND hwnd)

{
  LRESULT LVar1;
  int iVar2;
  size_t sVar3;
  uint local_32c [66];
  uint local_224 [66];
  HWND local_11c;
  char local_118 [264];
  WPARAM local_10;
  FILE *local_c;
  char *local_8;
  
  local_11c = CreateWindowExA(0,s_LISTBOX_00505ddc,&DAT_00505dd8,0x40a00003,0,0,0,0,hwnd,(HMENU)0x0,
                              DAT_00664680,(LPVOID)0x0);
  if (local_11c == (HWND)0x0) {
    LVar1 = -1;
  }
  else {
    Mem_AllocOrFree_004d9630(local_224,(uint *)&DAT_00664a60);
    FUN_004d9640(local_224,(uint *)s____DCK_00505de4);
    SendMessageA(local_11c,0x18d,0,(LPARAM)local_224);
    LVar1 = SendMessageA(local_11c,0x18b,0,0);
    for (local_10 = 0; (int)local_10 < LVar1; local_10 = local_10 + 1) {
      SendMessageA(local_11c,0x189,local_10,(LPARAM)local_224);
      Mem_AllocOrFree_004d9630(local_32c,(uint *)&DAT_00664a60);
      FUN_004d9640(local_32c,(uint *)&DAT_00505dec);
      FUN_004d9640(local_32c,local_224);
      iVar2 = Deck_FilterAttributes_0049d3c0((char *)local_32c);
      if ((iVar2 != 0) &&
         (local_c = _fopen((char *)local_32c,&DAT_00505df0), local_c != (FILE *)0x0)) {
        local_118[0] = '\0';
        sVar3 = _strlen(local_118);
        local_8 = local_118 + sVar3;
        while( true ) {
          iVar2 = _fgetc(local_c);
          *local_8 = (char)iVar2;
          if (*local_8 == '\n') break;
          if (*local_8 != ';') {
            local_8 = local_8 + 1;
          }
        }
        *local_8 = '\0';
        _fclose(local_c);
        SendDlgItemMessageA(hwnd,0x462,0x143,0,(LPARAM)local_118);
        SendDlgItemMessageA(hwnd,0x463,0x143,0,(LPARAM)local_118);
        FUN_0049d139(local_118,local_10);
      }
    }
    DestroyWindow(local_11c);
  }
  return LVar1;
}


