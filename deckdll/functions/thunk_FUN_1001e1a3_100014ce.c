/*
 * Decompiled function: thunk_FUN_1001e1a3
 * Entry Point: 100014ce
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1001e1a3(HDC hdc,RECT *arg_2,int arg_3)

{
  int val_1;
  HBRUSH hbr;
  uint8_t auStack_38 [4];
  int iStack_34;
  int iStack_30;
  int *piStack_20;
  tagRECT tStack_1c;
  int32_t uStack_c;
  int32_t uStack_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (RECT *)0x0)) && (arg_3 != 0)) {
    if (*(int *)(arg_3 + 0x10) == 1) {
      piStack_20 = &DAT_1013e60c;
    }
    else if (*(int *)(arg_3 + 0x10) == 8) {
      piStack_20 = &DAT_1013e034;
    }
    else if (*(int *)(arg_3 + 0x10) == 7) {
      piStack_20 = &DAT_1013e600;
    }
    else if (*(int *)(arg_3 + 0x10) == 5) {
      piStack_20 = &DAT_1013dff4;
    }
    else if (*(int *)(arg_3 + 0x10) == 2) {
      piStack_20 = &DAT_1013e5f4;
    }
    else if (*(int *)(arg_3 + 0x10) == 4) {
      piStack_20 = &DAT_1013e204;
    }
    else if (*(int *)(arg_3 + 0x10) == 0) {
      piStack_20 = &DAT_1013e5dc;
    }
    else if (*(int *)(arg_3 + 0x10) == 3) {
      piStack_20 = &DAT_1013e5dc;
    }
    else if (*(int *)(arg_3 + 0x10) == 6) {
      if ((*(uint8_t *)(arg_3 + 0xc) & 2) == 0) {
        if ((*(uint8_t *)(arg_3 + 0xc) & 4) == 0) {
          if ((*(uint8_t *)(arg_3 + 0xc) & 0x20) == 0) {
            if ((*(uint8_t *)(arg_3 + 0xd) & 1) == 0) {
              if ((*(uint8_t *)(arg_3 + 0xc) & 8) == 0) {
                val_1 = strcmp(*(char **)(arg_3 + 4),s_Swamp_100438a0);
                if (val_1 == 0) {
                  piStack_20 = &DAT_1013e1f4;
                }
                else {
                  val_1 = strcmp(*(char **)(arg_3 + 4),s_Plains_100438a8);
                  if (val_1 == 0) {
                    piStack_20 = &DAT_1013e200;
                  }
                  else {
                    val_1 = strcmp(*(char **)(arg_3 + 4),s_Mountain_100438b0);
                    if (val_1 == 0) {
                      piStack_20 = &DAT_1013e564;
                    }
                    else {
                      val_1 = strcmp(*(char **)(arg_3 + 4),s_Forest_100438bc);
                      if (val_1 == 0) {
                        piStack_20 = &DAT_1013e038;
                      }
                      else {
                        val_1 = strcmp(*(char **)(arg_3 + 4),s_Island_100438c4);
                        if (val_1 == 0) {
                          piStack_20 = &DAT_1013e3b8;
                        }
                        else {
                          piStack_20 = &DAT_1013e608;
                        }
                      }
                    }
                  }
                }
              }
              else {
                piStack_20 = &DAT_1013e608;
              }
            }
            else {
              piStack_20 = &DAT_1013dfe8;
            }
          }
          else {
            piStack_20 = &DAT_1013e594;
          }
        }
        else {
          piStack_20 = &DAT_1013e5e4;
        }
      }
      else {
        piStack_20 = &DAT_1013e608;
      }
    }
    else if (*(int *)(arg_3 + 0x10) == -1) {
      piStack_20 = &DAT_1013e5d8;
    }
    else {
      piStack_20 = &DAT_1013e5dc;
    }
    thunk_FUN_1001a9ec(piStack_20);
    if (*piStack_20 == 0) {
      hbr = GetStockObject(0);
      FillRect(hdc,arg_2,hbr);
    }
    else {
      GetObjectA((HANDLE)*piStack_20,0x18,auStack_38);
      SetRect(&tStack_1c,0,0,200,0x118);
      thunk_FUN_10031697(hdc,&tStack_1c.left,(HANDLE)*piStack_20,0,0,iStack_34,
                         (iStack_30 * 0x3b) / 100);
      uStack_8 = 0x1e;
      uStack_c = 0x16;
      SetRect(&tStack_1c,0,0x16,200,0x34);
      thunk_FUN_10031697(hdc,&tStack_1c.left,(HANDLE)*piStack_20,0,2,iStack_34,
                         (((iStack_30 * 0x3b) / 100) * 0xb) / 100 + 2);
    }
  }
  return;
}


