/*
 * Decompiled function: Pic_Load_menu2_hi_0047abf1
 * Entry Point: 0047abf1
 * Size: 945 bytes
 */
#include "magic.h"


int Pic_Load_menu2_hi_0047abf1(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_8;
  
  FUN_005112b0(0,(short)DAT_00530d9c);
  FUN_00510b70(1,0,0,s_menu2_pic_00526a38,
               (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,DAT_00522458,DAT_0052245c);
  iVar1 = Ai_Util_004c3bc4(0x19d);
  iVar2 = Ai_Util_004c3bc4(0xa4);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0x1b1,0x43,0xa4,0x19d,
                     (int *)g_DisplaySurfaceBackBuffer,200,0,iVar2,iVar1);
  FUN_005115a0(0,(short)DAT_00530d9c);
  Mem_AllocOrFree_00510e20(1,s_menu2_norm_pic_00526a44);
  iVar1 = Ai_Util_004c3bc4(0x19d);
  iVar2 = Ai_Util_004c3bc4(0xa4);
  iVar3 = Ai_Util_004c3bc4(0x43);
  iVar4 = Ai_Util_004c3bc4(0x1b1);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0xa4,0x19d,
                     (int *)g_DisplaySurfaceBackBuffer,iVar4,iVar3,iVar2,iVar1);
  Mem_AllocOrFree_00510e20(2,s_menu2_hi_pic_00526a54);
  iVar1 = Ai_Util_004c3bc4(0x19d);
  iVar2 = Ai_Util_004c3bc4(0xa4);
  iVar3 = Ai_Util_004c3bc4(0x43);
  iVar4 = Ai_Util_004c3bc4(0x1b1);
  Surface_StretchBlt((int *)g_DisplaySurfaceWork,0,0,0xa4,0x19d,(int *)g_DisplaySurfaceWork,iVar4,
                     iVar3,iVar2,iVar1);
  if (DAT_00525fb8 == DAT_00525fa8) {
    for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00526150 + local_8 * 0x10));
      *(undefined4 *)(&DAT_00526150 + local_8 * 0x10) = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00526154 + local_8 * 0x10));
      *(undefined4 *)(&DAT_00526154 + local_8 * 0x10) = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00526158 + local_8 * 0x10));
      *(undefined4 *)(&DAT_00526158 + local_8 * 0x10) = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_0052615c + local_8 * 0x10));
      *(undefined4 *)(&DAT_0052615c + local_8 * 0x10) = uVar5;
      uVar5 = Ai_Util_004c3bc4((&DAT_00525fb8)[local_8 * 0x15]);
      (&DAT_00525fb8)[local_8 * 0x15] = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00525fbc + local_8 * 0x54));
      *(undefined4 *)(&DAT_00525fbc + local_8 * 0x54) = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00525fc0 + local_8 * 0x54));
      *(undefined4 *)(&DAT_00525fc0 + local_8 * 0x54) = uVar5;
      uVar5 = Ai_Util_004c3bc4(*(int *)(&DAT_00525fc4 + local_8 * 0x54));
      *(undefined4 *)(&DAT_00525fc4 + local_8 * 0x54) = uVar5;
    }
  }
  iVar1 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(iVar1);
  FUN_0041f17e(0x525fa8,5,iVar1);
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    FUN_0047aa7c(local_8,0);
  }
  DAT_00525f28 = -1;
  while (DAT_00525f28 == -1) {
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  FUN_0041f391();
  Mem_AllocOrFree_0041f12b(iVar1);
  return DAT_00525f28 + -1;
}


