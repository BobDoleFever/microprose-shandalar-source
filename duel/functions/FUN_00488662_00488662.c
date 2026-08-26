/*
 * Decompiled function: FUN_00488662
 * Entry Point: 00488662
 * Size: 2992 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00488662(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *arg2;
  undefined4 uVar6;
  int local_18;
  
  iVar5 = *(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20);
  iVar3 = FUN_0048c367((&DAT_004ff596)[iVar5 * 0x34]);
  iVar2 = DAT_0068ecd0;
  iVar1 = DAT_0068eccc;
  iVar4 = DAT_0066644c;
  if (arg_3 == 0) {
    iVar4 = FUN_004895b4(arg_1,arg_1,arg_2);
    if (iVar4 == 0) {
      return 0;
    }
    DAT_0068f0bc = 0xffffffff;
    DAT_0068ef44 = 0;
    DAT_0068ed04 = -1;
    if ((((&DAT_004ff594)[iVar5 * 0x34] & 0x3c) != 0) &&
       (iVar4 = FUN_0048c907(arg_1,arg_2,0x74,1 - arg_1,0xffffffff), iVar4 == 0)) {
      return 0;
    }
    iVar2 = DAT_0068ecd0;
    iVar1 = DAT_0068eccc;
    iVar4 = DAT_0066644c;
    DAT_00681ea4 = -1;
    DAT_0068ecd0 = arg_1;
    DAT_0068eccc = arg_2;
    DAT_0066644c = iVar5;
    FUN_0048d878(arg_1,arg_2,0x71,arg_1,0);
    FUN_0042e00f();
    if (DAT_0068ef44 == 0) {
      if ((DAT_00676510 == arg_1) && (DAT_0066aaf4 != 1)) {
        if (((&DAT_004ff594)[iVar5 * 0x34] & 0x40) == 0) {
          (&DAT_0068ece0)[iVar3] = (int)(char)(&DAT_004ff597)[iVar5 * 0x34];
          DAT_0068ece0 = DAT_0068ece0 + (char)(&DAT_004ff598)[iVar5 * 0x34];
        }
        else {
          DAT_0068ecf8 = (int)(char)(&DAT_004ff597)[iVar5 * 0x34] +
                         (int)(char)(&DAT_004ff598)[iVar5 * 0x34];
        }
        FUN_0042ecaf(arg_1,arg_2,0,0);
      }
      else if (((&DAT_004ff594)[iVar5 * 0x34] & 0x40) == 0) {
        if ((&DAT_004ff597)[iVar5 * 0x34] != '\0') {
          (&DAT_0068ece0)[iVar3] = (int)(char)(&DAT_004ff597)[iVar5 * 0x34];
        }
        if ('\0' < (char)(&DAT_004ff598)[iVar5 * 0x34]) {
          DAT_0068ece0 = (int)(char)(&DAT_004ff598)[iVar5 * 0x34];
        }
        FUN_0042ecaf(arg_1,arg_2,0,0);
        if ((&DAT_004ff598)[iVar5 * 0x34] == -1) {
          if (DAT_00676510 == arg_1) {
            DAT_0068ed04 = FUN_0049b309(arg_1,7,1);
            Ai_CalcManaRequirement_004ba890(arg_1,0,-1);
          }
          else {
            if (DAT_0066aaf4 == 1) {
              iVar3 = FUN_00439892(2);
              if (iVar3 == 0) {
                iVar3 = FUN_0049b309(arg_1,7,1);
                if (iVar3 == 0) {
                  iVar3 = FUN_0049b309(arg_1,7,1);
                  DAT_0068f2c8 = FUN_00439892(iVar3 + 1);
                  local_18 = DAT_0068f2c8;
                }
                else {
                  iVar3 = FUN_00439892(iVar3);
                  DAT_0068f2c8 = iVar3 + 1;
                  local_18 = DAT_0068f2c8;
                }
              }
              else if (iVar3 == 1) {
                local_18 = FUN_0049b309(arg_1,7,1);
                DAT_0068f2c8 = local_18;
                if ((DAT_00681ea8 < local_18) && (iVar3 = FUN_00439892(3), iVar3 == 0)) {
                  local_18 = DAT_00681ea8;
                  DAT_0068f2c8 = DAT_00681ea8;
                }
                if ((DAT_0068ed04 != -1) && (DAT_0068ed04 < DAT_0068f2c8)) {
                  local_18 = DAT_0068ed04;
                  DAT_0068f2c8 = DAT_0068ed04;
                }
              }
              FUN_0043064a();
            }
            else {
              FUN_004307b2();
              local_18 = DAT_0068f2c8;
            }
            DAT_0068ed04 = local_18;
            Ai_CalcManaRequirement_004ba890(arg_1,0,-1);
          }
          if (DAT_00681ea0 == 0) {
            DAT_0068f2d4 = DAT_0068f2d4 + -100;
          }
        }
      }
      else {
        FUN_0042ecaf(arg_1,arg_2,6,
                     (int)(char)(&DAT_004ff597)[iVar5 * 0x34] +
                     (int)(char)(&DAT_004ff598)[iVar5 * 0x34]);
      }
    }
    DAT_0068ed04 = 0xffffffff;
    if (iVar5 != -1) {
      DAT_0066641c = arg_1;
      _DAT_006764b0 = 1;
      (&DAT_0068ee78)[arg_1] = (&DAT_0068ee78)[arg_1] + -1;
      if (((&DAT_004ff594)[iVar5 * 0x34] & 2) != 0) {
        *(int *)(&DAT_0068ee80 + arg_1 * 4) = *(int *)(&DAT_0068ee80 + arg_1 * 4) + 1;
      }
      if (((&DAT_004ff594)[iVar5 * 0x34] & 0x40) != 0) {
        (&DAT_0068ee88)[arg_1] = (&DAT_0068ee88)[arg_1] + 1;
      }
      if (((&DAT_004ff594)[iVar5 * 0x34] & 4) != 0) {
        *(int *)(&DAT_0068ee90 + arg_1 * 4) = *(int *)(&DAT_0068ee90 + arg_1 * 4) + 1;
      }
      *(uint *)(&DAT_0066aad0 + arg_1 * 4) =
           *(uint *)(&DAT_0066aad0 + arg_1 * 4) | (uint)(byte)(&DAT_004ff594)[iVar5 * 0x34];
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x20;
      DAT_00681eb0 = DAT_00681eb0 | 0x20;
      if ((DAT_00676510 == arg_1) || (DAT_0066aaf4 != 1)) {
        *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x30000;
      }
      else {
        *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10000;
      }
      DAT_0066644c = iVar4;
      DAT_0068eccc = iVar1;
      DAT_0068ecd0 = iVar2;
      if (DAT_00681ea4 == 1) {
        Mem_AllocOrFree_0042e0cd();
      }
      else {
        iVar4 = FUN_0048c50b(arg_1,arg_2,0x6c);
        if (iVar4 != 0) {
          FUN_004d7e62(s_Illegal_cast_004faf9c);
          DAT_00681ea4 = 1;
        }
        if (DAT_00681ea4 == 1) {
          FUN_0042e101(arg_1);
        }
        Mem_AllocOrFree_0042e0cd();
        if (DAT_00681ea4 != 1) {
          if (((DAT_0066aaf4 == 1) && (DAT_00676504 == arg_1)) &&
             ((&DAT_004ff598)[iVar5 * 0x34] == -1)) {
            iVar5 = FUN_0048c43a(arg_1);
            DAT_0068f2d4 = DAT_0068f2d4 + iVar5 * -0xc;
          }
          return 1;
        }
      }
    }
  }
  else {
    DAT_0068ecd0 = arg_1;
    DAT_0068eccc = arg_2;
    DAT_0066644c = iVar5;
    if (((&DAT_004ff594)[iVar5 * 0x34] & 1) == 0) {
      FUN_0048d41e(1);
    }
    if (((&DAT_004ff594)[iVar5 * 0x34] != '\x01') &&
       (((&DAT_004ff594)[iVar5 * 0x34] != ' ' || (((&DAT_004ff5a9)[iVar5 * 0x34] & 0x10) == 0)))) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Trying_to_cast_004fafac);
      FUN_0044a5a4(DAT_0068ecd0,DAT_0068eccc);
      FUN_0048e32b(-2,DAT_0068f2c4,&DAT_005f6810,0xd3);
    }
    if (*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
      DAT_00681ea4 = 1;
    }
    DAT_00681eb0 = DAT_00681eb0 & 0xffffffdf;
    DAT_0066644c = iVar4;
    DAT_0068eccc = iVar1;
    DAT_0068ecd0 = iVar2;
    *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) |
         CONCAT31((uint3)((arg_1 == 0) - 1 >> 8) & 0x4000,0x80);
    if (DAT_0066aaf4 != 1) {
      FUN_0048dc9e();
    }
    if (DAT_00681ea4 != 1) {
      if (((DAT_00676510 != arg_1) && (DAT_0066aaf4 != 1)) &&
         (((&DAT_004ff594)[iVar5 * 0x34] & 0x7e) != 0)) {
        Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)&DAT_00666500);
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_casts____004fafbc);
        if ((&DAT_004ff598)[iVar5 * 0x34] == -1) {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_X_is_004fafc8);
          arg2 = (uint *)__itoa(DAT_00681ea0,&DAT_005dadf8,10);
          FUN_004d9640((uint *)&DAT_005f6810,arg2);
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004fafd0);
        }
        if ((&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] == '\0') {
          FUN_00446c16(arg_1,arg_2,-1,-1,&DAT_005f6810,0);
        }
        else if ((&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] == '\x01') {
          FUN_00446c16(arg_1,arg_2,*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                       *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),&DAT_005f6810,0);
        }
        else {
          FUN_00446c16(arg_1,arg_2,-1,-1,&DAT_005f6810,0);
        }
        DAT_0066aac4 = DAT_00666458;
        DAT_0066ab04 = DAT_0068f2c4;
      }
      if (DAT_0066aaf4 != 1) {
        FUN_00450eb8(arg_1,arg_2,2,1);
      }
    }
  }
  if (DAT_00681ea4 == 1) {
    (&DAT_0068ee78)[arg_1] = (&DAT_0068ee78)[arg_1] + 1;
    if (((&DAT_004ff594)[iVar5 * 0x34] & 2) != 0) {
      *(int *)(&DAT_0068ee80 + arg_1 * 4) = *(int *)(&DAT_0068ee80 + arg_1 * 4) + -1;
    }
    if (((&DAT_004ff594)[iVar5 * 0x34] & 0x40) != 0) {
      (&DAT_0068ee88)[arg_1] = (&DAT_0068ee88)[arg_1] + -1;
    }
    if (((&DAT_004ff594)[iVar5 * 0x34] & 4) != 0) {
      *(int *)(&DAT_0068ee90 + arg_1 * 4) = *(int *)(&DAT_0068ee90 + arg_1 * 4) + -1;
    }
    *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffffff5d;
    *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffcffff;
    if (DAT_00676510 != arg_1) {
      DAT_00690c44 = 1;
    }
    DAT_00681ea4 = 0;
    FUN_0048e251();
    DAT_00681eb0 = DAT_00681eb0 & 0xffffffdf;
    uVar6 = 0;
  }
  else {
    FUN_0048eb25(arg_1,arg_2);
    uVar6 = 1;
  }
  return uVar6;
}


