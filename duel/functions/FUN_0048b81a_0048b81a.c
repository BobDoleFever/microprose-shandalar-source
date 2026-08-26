/*
 * Decompiled function: FUN_0048b81a
 * Entry Point: 0048b81a
 * Size: 2824 bytes
 */
#include "duel.h"


uint FUN_0048b81a(int x,int y,int width,undefined4 arg_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  uint local_1c;
  int local_18;
  int local_10;
  int local_c;
  uint local_8;
  
  uVar3 = DAT_005ef980;
  DAT_006663e0 = DAT_006663e0 + 1;
  if (DAT_0068eed8 != 0) {
    FUN_0048cac9();
  }
  DAT_0068ecb0 = x;
  DAT_00690c48 = y;
  DAT_00681ecc = *(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20);
  DAT_0068ee64 = (int)(char)(&DAT_004ff596)[DAT_00681ecc * 0x34];
  DAT_0068ecfc = arg_4;
  switch(width) {
  case 0x32:
    if (((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 2) == 0) {
      local_8 = (uint)*(short *)(&DAT_004ff59a + DAT_00681ecc * 0x34);
    }
    else {
      local_8 = (int)*(short *)(&DAT_004ff59a + DAT_00681ecc * 0x34) & 0xffffbfff;
    }
    local_8 = local_8 + (int)*(short *)(&DAT_006826d8 + y * 0x120 + x * 0x5b20);
    if (((&DAT_006826ff)[y * 0x120 + x * 0x5b20] & 4) != 0) {
      *(uint *)(&DAT_006826fc + y * 0x120 + x * 0x5b20) =
           *(uint *)(&DAT_006826fc + y * 0x120 + x * 0x5b20) & 0xfbffffff;
      goto LAB_0048be41;
    }
    DAT_0066642c = (uint)*(short *)(&DAT_006826d4 + y * 0x120 + x * 0x5b20);
    break;
  case 0x33:
    if (((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 2) == 0) {
      local_8 = (uint)*(short *)(&DAT_004ff59c + DAT_00681ecc * 0x34);
    }
    else {
      local_8 = (int)*(short *)(&DAT_004ff59c + DAT_00681ecc * 0x34) & 0xffffbfff;
    }
    local_8 = local_8 + (int)*(short *)(&DAT_006826da + y * 0x120 + x * 0x5b20);
    if (((&DAT_006826ff)[y * 0x120 + x * 0x5b20] & 2) != 0) {
      *(uint *)(&DAT_006826fc + y * 0x120 + x * 0x5b20) =
           *(uint *)(&DAT_006826fc + y * 0x120 + x * 0x5b20) & 0xfdffffff;
      goto LAB_0048be41;
    }
    DAT_0066642c = (uint)*(short *)(&DAT_006826d6 + y * 0x120 + x * 0x5b20);
    break;
  case 0x34:
    uVar1 = *(uint *)(&DAT_006826fc + y * 0x120 + x * 0x5b20);
    uVar2 = *(uint *)(&DAT_004ff5a4 + DAT_00681ecc * 0x34);
    local_8 = uVar1 & 0x7000000 | uVar2;
    if ((uVar2 & 0x1ff81f) != 0) {
      local_1c = 0;
      for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
        if ((local_8 & 1 << ((byte)local_18 & 0x1f)) != 0) {
          cVar4 = FUN_004af74c(x,y,local_18 + 1);
          local_1c = local_1c | 1 << (cVar4 - 1U & 0x1f);
        }
        if ((local_8 & 0x800 << ((byte)local_18 & 0x1f)) != 0) {
          cVar4 = FUN_004af7bb(x,y,local_18 + 1);
          local_1c = local_1c | 0x800 << (cVar4 - 1U & 0x1f);
        }
      }
      local_8 = uVar1 & 0x7000000 | uVar2 & 0xffe007e0 | local_1c;
    }
    if (((&DAT_006826ff)[y * 0x120 + x * 0x5b20] & 8) != 0) {
      *(uint *)(&DAT_006826fc + y * 0x120 + x * 0x5b20) =
           *(uint *)(&DAT_006826fc + y * 0x120 + x * 0x5b20) & 0xf7ffffff;
      goto LAB_0048be41;
    }
    DAT_0066642c = *(uint *)(&DAT_006826fc + y * 0x120 + x * 0x5b20);
    break;
  case 0x35:
    local_8 = (uint)*(short *)(&DAT_006826d0 + y * 0x120 + x * 0x5b20);
    goto LAB_0048be41;
  case 0x36:
    local_8 = (uint)(char)(&DAT_004ff596)[DAT_00681ecc * 0x34];
    goto LAB_0048be41;
  default:
    local_8 = 0;
LAB_0048be41:
    DAT_0066642c = local_8;
    if ((DAT_0068eed8 != 0) && (Magic_ScanCards(width), (DAT_00681eb0 & 0x10000) != 0)) {
      DAT_00681eb0 = DAT_00681eb0 & 0xfffeffff;
      *(uint *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) = DAT_0066642c;
      DAT_00681eb0 = DAT_00681eb0 | 0x20000;
      Magic_ScanCards(width);
      DAT_00681eb0 = DAT_00681eb0 & 0xfffdffff;
    }
    if (width == 0x32) {
      if ((int)DAT_0066642c < 0) {
        DAT_0066642c = 0;
      }
      if (((&DAT_006826f9)[y * 0x120 + x * 0x5b20] & 0x40) != 0) {
        DAT_0066642c = DAT_0066642c << 1;
      }
    }
    break;
  case 0x3c:
    if (((*(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) < DAT_0068f104) ||
        (DAT_0068f104 + 0x1d <= *(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20))) &&
       (*(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) != -1)) {
      local_8 = *(uint *)(&DAT_006826c0 + y * 0x120 + x * 0x5b20);
      if (((&DAT_006826ff)[y * 0x120 + x * 0x5b20] & 1) != 0) {
        *(undefined4 *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) =
             *(undefined4 *)(&DAT_006826c0 + y * 0x120 + x * 0x5b20);
        *(uint *)(&DAT_006826fc + y * 0x120 + x * 0x5b20) =
             *(uint *)(&DAT_006826fc + y * 0x120 + x * 0x5b20) & 0xfeffffff;
        (&DAT_006827df)[y * 0x120 + x * 0x5b20] = 0;
        goto LAB_0048be41;
      }
      DAT_0066642c = *(uint *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20);
    }
    else {
      DAT_0066642c = *(uint *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20);
    }
  }
  uVar1 = DAT_0066642c;
  iVar5 = FUN_0048a33f(x,y);
  if (((iVar5 != 0) && (width == 0x33)) &&
     ((((&DAT_004ff594)[DAT_00681ecc * 0x34] & 2) != 0 &&
      (((((int)uVar1 < 1 || ((int)uVar1 <= (int)*(short *)(&DAT_006826d0 + y * 0x120 + x * 0x5b20)))
        && (DAT_0068f230 == -1)) && ((DAT_00681eb0 & 0x204) == 0)))))) {
    FUN_0046e571(x,y,2);
    Pic_Subsystem_004488a0();
  }
  if (DAT_0068eed8 != 0) {
    FUN_0048cb7f();
  }
  if (width == 0x32) {
    *(short *)(&DAT_006826d4 + y * 0x120 + x * 0x5b20) = (short)uVar1;
  }
  if (width == 0x33) {
    *(short *)(&DAT_006826d6 + y * 0x120 + x * 0x5b20) = (short)uVar1;
  }
  if (width == 0x34) {
    *(uint *)(&DAT_006826fc + y * 0x120 + x * 0x5b20) = uVar1;
  }
  if (width != 0x3c) {
    DAT_005ef980 = uVar3;
    return uVar1;
  }
  *(uint *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) = uVar1;
  if (((&DAT_004ff5a9)[uVar1 * 0x34] & 0x10) == 0) goto LAB_0048c17d;
  iVar5 = *(int *)(&DAT_004ff590 + uVar1 * 0x34);
  if (iVar5 < 0x12d) {
    if (iVar5 == 300) {
      (&DAT_006826dc)[y * 0x120 + x * 0x5b20] = 1;
      goto LAB_0048c17d;
    }
    if (iVar5 == 0xf) {
      (&DAT_006826dc)[y * 0x120 + x * 0x5b20] = 0x3e;
      goto LAB_0048c17d;
    }
  }
  else if ((iVar5 == 0x13e) || (iVar5 == 0x366)) goto LAB_0048c17d;
  (&DAT_006826dc)[y * 0x120 + x * 0x5b20] = (&DAT_004ff596)[uVar1 * 0x34];
LAB_0048c17d:
  if ((((&DAT_006826f8)[y * 0x120 + x * 0x5b20] & 0x40) != 0) &&
     (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) * 0x34] & 2) == 0)) {
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      for (local_10 = 0; local_10 < (int)(&DAT_00666408)[local_c]; local_10 = local_10 + 1) {
        if ((((*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_c * 0x5b20) != -1) &&
             (((&DAT_006826cc)[local_10 * 0x120 + local_c * 0x5b20] & 2) != 0)) &&
            ((char)(&DAT_006826d2)[local_10 * 0x120 + local_c * 0x5b20] == x)) &&
           (((*(int *)(&DAT_006826e8 + local_10 * 0x120 + local_c * 0x5b20) == y &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_c * 0x5b20) * 0x34]
              & 4) != 0)) &&
            (*(int *)(&DAT_00618ad8 +
                     *(int *)(&DAT_004ff590 +
                             *(int *)(&DAT_006826c4 + local_10 * 0x120 + local_c * 0x5b20) * 0x34) *
                     0x98) == 0x2d)))) {
          FUN_0046e571(local_c,local_10,3);
        }
      }
    }
  }
  DAT_005ef980 = uVar3;
  return uVar1;
}


