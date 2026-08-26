/*
 * Decompiled function: FUN_00469f11
 * Entry Point: 00469f11
 * Size: 3040 bytes
 */
#include "duel.h"


undefined4 FUN_00469f11(int arg_1,int arg_2,int arg_3)

{
  byte bVar1;
  short sVar2;
  uint arg_11;
  int iVar3;
  uint arg_12;
  uint arg_13;
  int iVar4;
  int iVar5;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  int local_c;
  int local_8;
  
  arg_20 = 0;
  arg_19 = 0;
  arg_18 = 0;
  arg_17 = 0xffffffff;
  arg_16 = 0xffffffff;
  iVar5 = -1;
  iVar4 = -1;
  arg_13 = 0;
  arg_12 = 0;
  arg_11 = FUN_004521e2(arg_1,arg_2);
  iVar4 = Rules_ParseFilter_0041c0ab
                    (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                     *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),(undefined1 *)0x0,
                     arg_1,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar4,iVar5,arg_16,arg_17,arg_18,
                     arg_19,arg_20);
  if (iVar4 == 0) {
    DAT_00681ea4 = 1;
  }
  else {
    iVar4 = *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20);
    iVar5 = *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20);
    local_c = -1;
    if ((((-1 < arg_3) && (arg_3 < 0x14)) && (arg_3 != 0xd)) && (arg_3 != 1)) {
      Mem_AllocOrFree_004d9630
                ((uint *)&DAT_005f6810,(uint *)(s_casts_Berserk__004f8ed8 + arg_3 * 0x32));
      FUN_0045102d(arg_1,arg_1,arg_2,iVar4,iVar5,&DAT_005f6810,0);
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x24);
      }
    }
    switch(arg_3) {
    case 0:
      local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00681ec8,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined4 *)(&DAT_006826e4 + local_c * 0x120 + arg_1 * 0x5b20) = 0x80;
        *(undefined2 *)(&DAT_006826d8 + local_c * 0x120 + arg_1 * 0x5b20) =
             *(undefined2 *)(&DAT_006826d4 + iVar4 * 0x5b20 + iVar5 * 0x120);
        *(uint *)(&DAT_006826f8 + local_c * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826f8 + local_c * 0x120 + arg_1 * 0x5b20) | 0x4000;
      }
      break;
    case 1:
      if (*(short *)(&DAT_006826d4 + iVar4 * 0x5b20 + iVar5 * 0x120) < 3) {
        FUN_0045102d(arg_1,arg_1,arg_2,iVar4,iVar5,s_activates_Tawnos_s_Wand_effect__004f93bc,0);
        local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_006667b0,iVar4,iVar5);
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x24);
        }
      }
      else {
        DAT_00681ea4 = 1;
        FUN_0045102d(arg_1,arg_1,arg_2,iVar4,iVar5,s_fizzles_attempting_Tawnos_s_Wand_004f93e0,0);
      }
      break;
    case 2:
      local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined2 *)(&DAT_006826d8 + local_c * 0x120 + arg_1 * 0x5b20) = 4;
        sVar2 = FUN_0049aa14(4,0,*(short *)(&DAT_006826d6 + iVar4 * 0x5b20 + iVar5 * 0x120) + -1);
        *(short *)(&DAT_006826da + local_c * 0x120 + arg_1 * 0x5b20) = -sVar2;
      }
      break;
    case 3:
      bVar1 = FUN_004af7bb(arg_1,arg_2,3);
      (&DAT_006826dd)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 4:
      bVar1 = FUN_004af7bb(arg_1,arg_2,5);
      (&DAT_006826dd)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 5:
      bVar1 = FUN_004af7bb(arg_1,arg_2,4);
      (&DAT_006826dd)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 6:
      FUN_004af950(iVar4,iVar5,3,DAT_00690af0,DAT_0068efa0);
      break;
    case 7:
      local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined4 *)(&DAT_006826fc + local_c * 0x120 + arg_1 * 0x5b20) = 0;
        *(undefined4 *)(&DAT_006826e4 + local_c * 0x120 + arg_1 * 0x5b20) = 0x20;
      }
      break;
    case 8:
      local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined2 *)(&DAT_006826d8 + local_c * 0x120 + arg_1 * 0x5b20) = 3;
        *(undefined2 *)(&DAT_006826da + local_c * 0x120 + arg_1 * 0x5b20) = 3;
      }
      break;
    case 9:
      local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined4 *)(&DAT_006826e4 + local_c * 0x120 + arg_1 * 0x5b20) = 0x40;
      }
      *(undefined4 *)(&DAT_006826fc + iVar4 * 0x5b20 + iVar5 * 0x120) = 0x8000000;
      break;
    case 10:
      bVar1 = FUN_004af7bb(arg_1,arg_2,1);
      (&DAT_006826dd)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 0xb:
      bVar1 = FUN_004af7bb(arg_1,arg_2,2);
      (&DAT_006826dd)[iVar4 * 0x5b20 + iVar5 * 0x120] = (char)(1 << (bVar1 & 0x1f));
      break;
    case 0xc:
      local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00681ec8,iVar4,iVar5);
      if (local_c != -1) {
        *(uint *)(&DAT_006826f8 + local_c * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826f8 + local_c * 0x120 + arg_1 * 0x5b20) | 0x800000;
      }
      *(undefined4 *)(&DAT_006826fc + iVar4 * 0x5b20 + iVar5 * 0x120) = 0x8000000;
      break;
    case 0xd:
      iVar3 = FUN_0045102d(arg_1,arg_1,arg_2,iVar4,iVar5,s_casts_Twiddle__Tap__Untap__004f939c,
                           (*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x10) >> 4);
      if (iVar3 == 0) {
        FUN_004a7b83(iVar4,iVar5);
      }
      else {
        *(uint *)(&DAT_006826cc + iVar4 * 0x5b20 + iVar5 * 0x120) =
             *(uint *)(&DAT_006826cc + iVar4 * 0x5b20 + iVar5 * 0x120) & 0xffffffef;
      }
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x24);
      }
      break;
    case 0xe:
      local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,iVar4,iVar5);
      if (local_c != -1) {
        *(undefined2 *)(&DAT_006826d8 + local_c * 0x120 + arg_1 * 0x5b20) = 0xfffe;
        *(undefined2 *)(&DAT_006826da + local_c * 0x120 + arg_1 * 0x5b20) = 0;
      }
      break;
    case 0xf:
      FUN_004af82a(iVar4,iVar5);
      break;
    case 0x10:
      FUN_004af950(iVar4,iVar5,1,DAT_00690af0,DAT_0068efa0);
      break;
    case 0x11:
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
          if (((*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) == DAT_0068eed0) &&
              (((&DAT_006826cc)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
             (((char)(&DAT_006826d2)[local_c * 0x120 + local_8 * 0x5b20] == iVar4 &&
              (*(int *)(&DAT_006826e8 + local_c * 0x120 + local_8 * 0x5b20) == iVar5)))) {
            *(uint *)(&DAT_006826f8 + local_c * 0x120 + local_8 * 0x5b20) =
                 *(uint *)(&DAT_006826f8 + local_c * 0x120 + local_8 * 0x5b20) & 0xfeffffff;
          }
        }
      }
      local_c = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0068eed0,iVar4,iVar5);
      if (local_c != -1) {
        *(uint *)(&DAT_006826f8 + local_c * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826f8 + local_c * 0x120 + arg_1 * 0x5b20) | 0x1000000;
        *(ushort *)(&DAT_006826d8 + local_c * 0x120 + arg_1 * 0x5b20) =
             -(*(ushort *)
                (&DAT_004ff59a + *(int *)(&DAT_006826c4 + iVar4 * 0x5b20 + iVar5 * 0x120) * 0x34) &
              0xbfff);
        *(ushort *)(&DAT_006826da + local_c * 0x120 + arg_1 * 0x5b20) =
             2 - (*(ushort *)
                   (&DAT_004ff59c + *(int *)(&DAT_006826c4 + iVar4 * 0x5b20 + iVar5 * 0x120) * 0x34)
                 & 0xbfff);
      }
      break;
    case 0x12:
      iVar3 = FUN_0048b81a(iVar4,iVar5,0x32,0xffffffff);
      (&DAT_00681ea8)[iVar4] = (&DAT_00681ea8)[iVar4] + iVar3;
      FUN_0046e571(iVar4,iVar5,4);
      break;
    case 0x13:
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x2c);
        Sleep(0xdac);
      }
      *(short *)(&DAT_006826da + iVar4 * 0x5b20 + iVar5 * 0x120) =
           *(short *)(&DAT_006826da + iVar4 * 0x5b20 + iVar5 * 0x120) + -1;
      *(int *)(&DAT_0068270c + iVar4 * 0x5b20 + iVar5 * 0x120) =
           *(int *)(&DAT_0068270c + iVar4 * 0x5b20 + iVar5 * 0x120) + 0x1000000;
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x2b);
      }
      break;
    default:
      FUN_0045102d(arg_1,arg_1,arg_2,iVar4,iVar5,s_made_an_error__004f940c,0);
    }
    if (local_c != -1) {
      iVar4 = FUN_00486c12(*(int *)(&DAT_004f8e80 + arg_3 * 4),arg_1,arg_2);
      *(uint *)(&DAT_00682704 + local_c * 0x120 + arg_1 * 0x5b20) =
           iVar4 << 0x10 | *(uint *)(&DAT_004f8e80 + arg_3 * 4);
    }
  }
  (&DAT_006827b8)
  [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
  return 0;
}


