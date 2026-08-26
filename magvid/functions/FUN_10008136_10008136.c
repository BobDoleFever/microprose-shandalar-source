/*
 * Decompiled function: FUN_10008136
 * Entry Point: 10008136
 * Size: 318 bytes
 */
#include "magvid.h"


void __fastcall FUN_10008136(int32_t *ptr_1)

{
  int val_1;
  int local_8;
  
  if ((int)ptr_1[0x12] < (int)ptr_1[0x13]) {
    ptr_1[0x12] = ptr_1[0x13] + -1;
  }
  local_8 = ptr_1[0x12];
  while ((local_8 = local_8 + 1, local_8 < (int)ptr_1[0x11] &&
         (val_1 = AVIStreamRead(ptr_1[3],local_8,1,ptr_1[0x17],ptr_1[0x18],0,0), val_1 == 0))) {
    if (ptr_1[6] == 0) {
      thunk_FUN_100085b0(&DAT_1001bf60,s_vidsCatchup_____m_bPlaying__Draw_10010658);
      val_1 = thunk_FUN_1000b2fb((void *)*ptr_1,ptr_1[0x17],0);
      thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],val_1,0,0);
      thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
    }
    else {
      thunk_FUN_100085b0(&DAT_1001bf60,s_vidsCatchup_____m_bPlaying__Draw_1001067c);
      val_1 = thunk_FUN_1000b2fb((void *)*ptr_1,ptr_1[0x17],0x80000000);
      thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],val_1,0,0);
      thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
    }
    ptr_1[0x12] = local_8;
  }
  return;
}


