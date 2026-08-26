/*
 * Decompiled function: thunk_FUN_10007c85
 * Entry Point: 100010cd
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __fastcall thunk_FUN_10007c85(int *ptr_1)

{
  int32_t uval_1;
  DWORD DVar2;
  int val_3;
  int iStack_14;
  uint8_t auStack_10 [4];
  DWORD DStack_c;
  uint8_t auStack_8 [4];
  
  if (*ptr_1 == 0) {
    uval_1 = 0xffffffeb;
  }
  else {
    thunk_FUN_100051e4();
    if (ptr_1[0xd] < 0) {
      uval_1 = 0xffffffe9;
    }
    else {
      if (ptr_1[6] == 0) {
        if (ptr_1[0x16] < ptr_1[0x11]) {
          ptr_1[0x11] = ptr_1[0x16];
        }
        if (ptr_1[0x12] == ptr_1[0x11]) {
          thunk_FUN_100027a0((int)ptr_1);
        }
      }
      else {
        iStack_14 = thunk_FUN_100073d1();
        if (iStack_14 < 0) {
          DVar2 = timeGetTime();
          iStack_14 = (DVar2 - ptr_1[0xd]) + ptr_1[0xe];
        }
        val_3 = thunk_FUN_10007eaf(ptr_1,iStack_14);
        ptr_1[0x11] = val_3;
        if (ptr_1[0x16] < ptr_1[0x11]) {
          ptr_1[0x11] = ptr_1[0x16];
        }
        if (ptr_1[0x12] == ptr_1[0x11]) {
          thunk_FUN_100051e4();
          return 0;
        }
      }
      val_3 = thunk_FUN_10007f71(ptr_1);
      if (val_3 == 0) {
        uval_1 = 0;
      }
      else {
        DStack_c = AVIStreamRead(ptr_1[3],ptr_1[0x11],1,ptr_1[0x17],ptr_1[0x18],auStack_8,auStack_10
                                );
        if (DStack_c == 0) {
          thunk_FUN_100085b0(&DAT_1001bf60,s_vidsdraw__vcmDraw_m_pvBuf___rval_10010634);
          DStack_c = thunk_FUN_1000af14((void *)*ptr_1,ptr_1[0x17],0);
          if ((int)DStack_c < 2) {
            thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],DStack_c,0,0);
            thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
            ptr_1[0x12] = ptr_1[0x11];
            if (ptr_1[6] != 0) {
              ptr_1[0x10] = ptr_1[0x10] + (ptr_1[0x11] - ptr_1[0xf]) + -1;
              ptr_1[0xf] = ptr_1[0x11];
            }
            thunk_FUN_100051e4();
            uval_1 = 0;
          }
          else {
            thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],DStack_c,ptr_1[0xd],0);
            thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
            uval_1 = 0xffffffeb;
          }
        }
        else {
          uval_1 = 0xffffffe8;
        }
      }
    }
  }
  return uval_1;
}


