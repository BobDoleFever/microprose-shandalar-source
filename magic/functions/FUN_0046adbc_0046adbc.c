/*
 * Decompiled function: FUN_0046adbc
 * Entry Point: 0046adbc
 * Size: 654 bytes
 */
#include "magic.h"


bool FUN_0046adbc(int arg1,int arg2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  
  bVar1 = *(int *)(arg1 + 4) == *(int *)(arg2 + 4);
  bVar2 = ((*(uint *)(arg1 + 0xc) ^ *(uint *)(arg2 + 0xc) & 0x30000) & 0x30000) == 0;
  bVar3 = ((*(uint *)(arg1 + 0xc) ^ *(uint *)(arg2 + 0xc) & 0x10) & 0x10) == 0;
  bVar4 = ((*(uint *)(arg1 + 0xc) ^ *(uint *)(arg2 + 0xc) & 0x1000) & 0x1000) == 0;
  bVar5 = ((*(uint *)(arg1 + 0xc) ^ *(uint *)(arg2 + 0xc) & 0x200000) & 0x200000) == 0;
  bVar6 = ((*(uint *)(arg1 + 0xc) ^ *(uint *)(arg2 + 0xc) & 0x100000) & 0x100000) == 0;
  bVar7 = *(short *)(arg1 + 0x10) == *(short *)(arg2 + 0x10);
  bVar8 = *(short *)(arg1 + 0x14) == *(short *)(arg2 + 0x14);
  bVar9 = *(short *)(arg1 + 0x16) == *(short *)(arg2 + 0x16);
  bVar10 = *(char *)(arg1 + 0x1c) == *(char *)(arg2 + 0x1c);
  bVar11 = *(char *)(arg1 + 0x1d) == *(char *)(arg2 + 0x1d);
  bVar12 = *(char *)(arg1 + 0x1e) == *(char *)(arg2 + 0x1e);
  bVar13 = *(int *)(arg1 + 0x24) == *(int *)(arg2 + 0x24);
  bVar14 = *(int *)(arg1 + 0x4c) == *(int *)(arg2 + 0x4c);
  bVar15 = ((*(uint *)(arg1 + 0x38) ^ *(uint *)(arg2 + 0x38) & 0x20000) & 0x20000) == 0;
  bVar16 = *(int *)(arg1 + 0x44) == *(int *)(arg2 + 0x44);
  bVar17 = *(int *)(arg1 + 0x108) == *(int *)(arg2 + 0x108);
  bVar18 = *(char *)(arg1 + 0x20) == *(char *)(arg2 + 0x20);
  if ((!bVar18 ||
       (!bVar17 ||
       (!bVar16 ||
       (!bVar15 ||
       (!bVar14 ||
       (!bVar13 ||
       (!bVar12 ||
       (!bVar11 ||
       (!bVar10 ||
       (!bVar9 ||
       (!bVar8 || (!bVar7 || (!bVar6 || (!bVar5 || (!bVar4 || (!bVar3 || (!bVar2 || !bVar1))))))))))
       ))))))) && (DAT_0068a674 != 0)) {
    FUN_0046b04a(arg1,arg2);
  }
  return bVar18 && (bVar17 &&
                   (bVar16 &&
                   (bVar15 &&
                   (bVar14 &&
                   (bVar13 &&
                   (bVar12 &&
                   (bVar11 &&
                   (bVar10 &&
                   (bVar9 && (bVar8 && (bVar7 && (bVar6 && (bVar5 && (bVar4 && (bVar3 && (bVar2 && 
                                                  bVar1))))))))))))))));
}


