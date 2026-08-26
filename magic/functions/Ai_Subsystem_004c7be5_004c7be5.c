/*
 * Decompiled function: Ai_Subsystem_004c7be5
 * Entry Point: 004c7be5
 * Size: 388 bytes
 */
#include "magic.h"


void Ai_Subsystem_004c7be5(undefined4 arg1,int arg2)

{
  int iVar1;
  int local_c;
  
  if (arg2 == DAT_00559b1c) {
    iVar1 = Ai_Subsystem_004c7d69();
    if (DAT_0055a008 < iVar1) {
      DAT_0055a008 = iVar1;
      memcpy(&DAT_005597c0,&DAT_00559958,0x1c);
      DAT_00559998 = DAT_00559f80;
    }
  }
  else {
    iVar1 = (&DAT_0055a050)[arg2] * 0x120 + DAT_00559a20 * 0x5b20;
    if ((((&DAT_006a5f3d)[iVar1] & 0x80) == 0) || ((&g_CardSlot_ColorMask)[iVar1] == -1)) {
      *(undefined4 *)(&DAT_00559958 + arg2 * 4) = 0xffffffff;
      Ai_Subsystem_004c7be5(arg1,arg2 + 1);
    }
    for (local_c = 0; local_c < DAT_00559a94; local_c = local_c + 1) {
      if (((*(int *)(&DAT_00559b40 + local_c * 4) < DAT_00559888) &&
          (((&DAT_00559890)[local_c] & 1 << ((byte)arg2 & 0x1f)) != 0)) &&
         ((((&DAT_006a5f3d)[iVar1] & 0x80) == 0 ||
          ((int)(char)(&g_CardSlot_ColorMask)[iVar1] == (&DAT_005596b8)[local_c])))) {
        *(int *)(&DAT_00559b40 + local_c * 4) = *(int *)(&DAT_00559b40 + local_c * 4) + 1;
        *(undefined4 *)(&DAT_00559958 + arg2 * 4) = (&DAT_005596b8)[local_c];
        Ai_Subsystem_004c7be5(arg1,arg2 + 1);
        *(int *)(&DAT_00559b40 + local_c * 4) = *(int *)(&DAT_00559b40 + local_c * 4) + -1;
      }
    }
  }
  return;
}


