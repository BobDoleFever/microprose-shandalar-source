/*
 * Decompiled function: PlaySndFile
 * Entry Point: 100010aa
 * Size: 5 bytes
 */
#include "magsnd.h"


int __cdecl PlaySndFile(LPSTR arg_1,int arg_2,int *ptr_3)

{
  uint8_t auStack_1c [4];
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int32_t uStack_8;
  
                    /* 0x10aa  7  PlaySndFile */
  uStack_8 = 0;
  iStack_18 = 0;
  iStack_10 = 0;
  if ((arg_2 < 0x100) && (-1 < arg_2)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_2 * 4) == 0) {
      iStack_c = thunk_FUN_1000560f(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
      if (iStack_c == 0) {
        thunk_FUN_1000460c(*(int *)(&DAT_1000a648 + arg_2 * 4));
        thunk_FUN_10004534(*(int *)(&DAT_1000a648 + arg_2 * 4));
        if (((DAT_1000a420 == 1) && (DAT_1000a424 == 0)) &&
           (iStack_c = thunk_FUN_100046fb(), iStack_c != 0)) {
          UnloadSnd(arg_2);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        }
        else {
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x10) = arg_2;
          if (ptr_3 == (int *)0x0) {
            iStack_18 = 0;
            *(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = 400;
            iStack_10 = *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x7c);
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = iStack_10;
            iStack_14 = 0;
            *(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = 0;
          }
          else {
            iStack_18 = *ptr_3;
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = iStack_18;
            if (400 < iStack_18) {
              iStack_18 = 400;
            }
            iStack_18 = (iStack_18 * 5 + -2000) * 2;
            if (ptr_3[1] == 0) {
              iStack_10 = *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x7c);
            }
            else {
              iStack_10 = ptr_3[1];
            }
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = iStack_10;
            if (ptr_3[2] == 0) {
              iStack_14 = 0;
            }
            else {
              iStack_14 = ptr_3[2];
            }
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = iStack_14;
            iStack_14 = iStack_14 * 10;
            if ((*(uint8_t *)(ptr_3 + 7) & 1) != 0) {
              *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
                   *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 1;
            }
            if (((uint32_t)ptr_3[7] >> 3 & 1) != 0) {
              *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
                   *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 4;
            }
          }
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 2;
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x3c))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),iStack_18);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = iStack_18;
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x44))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),iStack_10);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = iStack_10;
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x40))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),iStack_14);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = iStack_14;
          thunk_FUN_10005f0c(*(int32_t **)(&DAT_1000a648 + arg_2 * 4),0);
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x30))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),0,0,1);
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x10))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),
                     *(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1d8,auStack_1c);
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) | 1;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          iStack_c = 0;
        }
      }
      else {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      }
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      iStack_c = 2;
    }
  }
  else {
    iStack_c = 5;
  }
  return iStack_c;
}


