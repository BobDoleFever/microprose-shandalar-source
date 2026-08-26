/*
 * Decompiled function: FUN_0042d247
 * Entry Point: 0042d247
 * Size: 2317 bytes
 */
#include "duel.h"


undefined4 FUN_0042d247(int arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,int arg_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  byte local_28;
  byte local_20;
  int local_18;
  int local_14;
  int local_c;
  
  bVar1 = false;
  for (local_14 = 0; local_14 < 7; local_14 = local_14 + 1) {
    if ((&DAT_0068ece0)[local_14] == -1) {
      bVar1 = true;
    }
  }
  iVar3 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
  if (iVar3 == 0) {
    for (local_c = 0; local_c < (int)(&DAT_00666408)[arg_1]; local_c = local_c + 1) {
      iVar3 = FUN_0042db54(arg_1,local_c,(byte)arg_4);
      if (iVar3 != 0) {
        iVar3 = FUN_0048c907(arg_1,local_c,0x73,1 - arg_1,0xffffffff);
        if (iVar3 != 0) {
          bVar2 = false;
          for (local_14 = 0; local_14 < 7; local_14 = local_14 + 1) {
            if (((&DAT_0068ece0)[local_14] < 1) ||
               ((1 << ((byte)local_14 & 0x1f) &
                (int)(char)(&DAT_006826dc)[local_c * 0x120 + arg_1 * 0x5b20]) == 0)) {
              if ((((&DAT_0068ece0)[local_14] == -1) &&
                  ((DAT_00681ea0 < DAT_0068ed04 && (DAT_0068ed04 != -1)))) &&
                 ((1 << ((byte)local_14 & 0x1f) &
                  (int)(char)(&DAT_006826dc)[local_c * 0x120 + arg_1 * 0x5b20]) != 0)) {
                bVar2 = true;
              }
            }
            else {
              bVar2 = true;
            }
          }
          if ((arg_5 != 0) && (!bVar2)) {
            local_18 = 0;
            while ((local_18 < 10 && (*(int *)(&DAT_00666900 + local_18 * 4 + arg_1 * 0x2c) != -1)))
            {
              local_20 = (byte)*(undefined2 *)(&DAT_00666900 + local_18 * 4 + arg_1 * 0x2c);
              if (((&DAT_0068ece0)[*(uint *)(&DAT_00666900 + local_18 * 4 + arg_1 * 0x2c) >> 0x10] <
                   1) || ((1 << (local_20 & 0x1f) &
                          (int)(char)(&DAT_006826dc)[local_c * 0x120 + arg_1 * 0x5b20]) == 0)) {
                if (((&DAT_0068ece0)[*(uint *)(&DAT_00666900 + local_18 * 4 + arg_1 * 0x2c) >> 0x10]
                     == -1) &&
                   (((DAT_00681ea0 < DAT_0068ed04 && (DAT_0068ed04 != -1)) &&
                    ((1 << (local_20 & 0x1f) &
                     (int)(char)(&DAT_006826dc)[local_c * 0x120 + arg_1 * 0x5b20]) != 0)))) {
                  bVar2 = true;
                }
              }
              else {
                bVar2 = true;
              }
              local_18 = local_18 + 1;
            }
          }
          if (bVar2) {
            iVar3 = FUN_0042dd5e(arg_1,local_c);
            if (iVar3 != 0) {
              iVar3 = FUN_0049b309(arg_1,6,1);
              iVar4 = FUN_0049b309(arg_1,7,1);
              iVar3 = iVar3 - iVar4;
              FUN_0042c815(arg_1,arg_2,arg_3,iVar3);
              FUN_0042c9be(arg_1,arg_2,arg_3,iVar3,&DAT_00681ea0,DAT_0068ed04);
              FUN_0042cbbb(arg_1,arg_2,arg_3,iVar3,&DAT_00681ea0,DAT_0068ed04);
            }
          }
        }
      }
    }
  }
  iVar3 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
  if ((iVar3 == 0) && ((DAT_0068ece0 != 0 || (DAT_0068ecf8 != 0)))) {
    for (local_c = 0; local_c < (int)(&DAT_00666408)[arg_1]; local_c = local_c + 1) {
      iVar3 = FUN_0042db54(arg_1,local_c,(byte)arg_4);
      if (iVar3 != 0) {
        iVar3 = FUN_0048c907(arg_1,local_c,0x73,1 - arg_1,0xffffffff);
        if (iVar3 != 0) {
          bVar2 = false;
          if (DAT_0068ece0 < 1) {
            if (((DAT_0068ece0 == -1) && (DAT_00681ea0 < DAT_0068ed04)) && (DAT_0068ed04 != -1)) {
              bVar2 = true;
            }
            else if (DAT_0068ecf8 < 1) {
              if (((DAT_0068ecf8 == -1) && (DAT_00681ea0 < DAT_0068ed04)) && (DAT_0068ed04 != -1)) {
                bVar2 = true;
              }
            }
            else {
              bVar2 = true;
            }
          }
          else {
            bVar2 = true;
          }
          if (((&DAT_006826dc)[local_c * 0x120 + arg_1 * 0x5b20] == '@') && (DAT_0068ecf8 == 0)) {
            bVar2 = false;
          }
          if (bVar2) {
            iVar3 = FUN_0042dd5e(arg_1,local_c);
            if (iVar3 != 0) {
              iVar3 = FUN_0049b309(arg_1,6,1);
              iVar4 = FUN_0049b309(arg_1,7,1);
              iVar3 = iVar3 - iVar4;
              FUN_0042c815(arg_1,arg_2,arg_3,iVar3);
              FUN_0042c9be(arg_1,arg_2,arg_3,iVar3,&DAT_00681ea0,DAT_0068ed04);
              FUN_0042cbbb(arg_1,arg_2,arg_3,iVar3,&DAT_00681ea0,DAT_0068ed04);
            }
          }
        }
      }
    }
  }
  iVar3 = FUN_0042cdb6(0x68ece0,DAT_00681ea0,DAT_0068ed04);
  if (((iVar3 == 0) && (bVar1)) && (DAT_0068ed04 == -1)) {
    for (local_c = 0; local_c < (int)(&DAT_00666408)[arg_1]; local_c = local_c + 1) {
      iVar3 = FUN_0042db54(arg_1,local_c,(byte)arg_4);
      if (iVar3 != 0) {
        iVar3 = FUN_0048c907(arg_1,local_c,0x73,1 - arg_1,0xffffffff);
        if (iVar3 != 0) {
          bVar1 = false;
          for (local_14 = 1; local_14 < 7; local_14 = local_14 + 1) {
            if (((DAT_0068ed04 == -1) && ((&DAT_0068ece0)[local_14] == -1)) &&
               ((1 << ((byte)local_14 & 0x1f) &
                (int)(char)(&DAT_006826dc)[local_c * 0x120 + arg_1 * 0x5b20]) != 0)) {
              bVar1 = true;
            }
            else if ((DAT_0068ed04 == -1) && (DAT_0068ece0 == -1)) {
              bVar1 = true;
            }
            else if ((DAT_0068ed04 == -1) && (DAT_0068ecf8 == -1)) {
              bVar1 = true;
            }
          }
          if (((&DAT_006826dc)[local_c * 0x120 + arg_1 * 0x5b20] == '@') && (DAT_0068ecf8 != -1)) {
            bVar1 = false;
          }
          if ((arg_5 != 0) && (!bVar1)) {
            local_18 = 0;
            while ((local_18 < 10 && (*(int *)(&DAT_00666900 + local_18 * 4 + arg_1 * 0x2c) != -1)))
            {
              if (((DAT_0068ed04 == -1) &&
                  ((&DAT_0068ece0)[*(uint *)(&DAT_00666900 + local_18 * 4 + arg_1 * 0x2c) >> 0x10]
                   == -1)) &&
                 (local_28 = (byte)*(undefined2 *)(&DAT_00666900 + local_18 * 4 + arg_1 * 0x2c),
                 (1 << (local_28 & 0x1f) &
                 (int)(char)(&DAT_006826dc)[local_c * 0x120 + arg_1 * 0x5b20]) != 0)) {
                bVar1 = true;
              }
              local_18 = local_18 + 1;
            }
          }
          if (bVar1) {
            iVar3 = FUN_0042dd5e(arg_1,local_c);
            if (iVar3 != 0) {
              iVar3 = FUN_0049b309(arg_1,6,1);
              iVar4 = FUN_0049b309(arg_1,7,1);
              iVar3 = iVar3 - iVar4;
              FUN_0042c815(arg_1,arg_2,arg_3,iVar3);
              FUN_0042c9be(arg_1,arg_2,arg_3,iVar3,&DAT_00681ea0,DAT_0068ed04);
              FUN_0042cbbb(arg_1,arg_2,arg_3,iVar3,&DAT_00681ea0,DAT_0068ed04);
            }
          }
        }
      }
    }
  }
  FUN_00446d17();
  return 1;
}


