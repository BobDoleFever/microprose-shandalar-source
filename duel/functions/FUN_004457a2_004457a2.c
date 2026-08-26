/*
 * Decompiled function: FUN_004457a2
 * Entry Point: 004457a2
 * Size: 1891 bytes
 */
#include "duel.h"


uint FUN_004457a2(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_10;
  int local_c;
  uint local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  local_8 = _memcmp(&DAT_00601620,&DAT_006826c0,0xb640);
  FID_conflict__memcpy(&DAT_00601620,&DAT_006826c0,0xb640);
  if ((DAT_00666408 != DAT_00615458) || (DAT_0061545c != DAT_0066640c)) {
    local_8 = 1;
  }
  DAT_00615458 = DAT_00666408;
  DAT_0061545c = DAT_0066640c;
  if ((DAT_00681ea8 != DAT_00616a00) || (DAT_00681eac != DAT_00664a50)) {
    local_8 = 1;
  }
  DAT_00616a00 = DAT_00681ea8;
  DAT_00664a50 = DAT_00681eac;
  if ((DAT_006668f0 != DAT_0060cc80) || (DAT_006668f4 != DAT_00664dac)) {
    local_8 = 1;
  }
  DAT_0060cc80 = DAT_006668f0;
  DAT_00664dac = DAT_006668f4;
  uVar3 = _memcmp(&DAT_006152c0,&DAT_0068f2e0,0x1c);
  uVar4 = _memcmp(&DAT_0060cc90,&DAT_0068f300,0x1c);
  FID_conflict__memcpy(&DAT_006152c0,&DAT_0068f2e0,0x1c);
  FID_conflict__memcpy(&DAT_0060cc90,&DAT_0068f300,0x1c);
  uVar5 = _memcmp(&DAT_0060ccc0,&DAT_0068f370,2000);
  uVar6 = _memcmp(&DAT_00662e40,&DAT_0068fb40,2000);
  DAT_00664a54 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_0068f370 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = CardIDFromType(*(uint *)(&DAT_0068f370 + local_c * 4));
    (&DAT_0060ccc0)[DAT_00664a54] = uVar7;
    DAT_00664a54 = DAT_00664a54 + 1;
  }
  DAT_00664d94 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_0068fb40 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = CardIDFromType(*(uint *)(&DAT_0068fb40 + local_c * 4));
    (&DAT_00662e40)[DAT_00664d94] = uVar7;
    DAT_00664d94 = DAT_00664d94 + 1;
  }
  uVar8 = _memcmp(&DAT_00663e70,&DAT_0068dd10,2000);
  uVar9 = _memcmp(&DAT_00617980,&DAT_0068e4e0,2000);
  DAT_00664b68 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_0068dd10 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = CardIDFromType(*(uint *)(&DAT_0068dd10 + local_c * 4));
    (&DAT_00663e70)[DAT_00664b68] = uVar7;
    DAT_00664b68 = DAT_00664b68 + 1;
  }
  DAT_00618948 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_0068e4e0 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = CardIDFromType(*(uint *)(&DAT_0068e4e0 + local_c * 4));
    (&DAT_00617980)[DAT_00618948] = uVar7;
    DAT_00618948 = DAT_00618948 + 1;
  }
  uVar10 = _memcmp(&DAT_00618170,&DAT_006669f0,2000);
  uVar11 = _memcmp(&DAT_00663620,&DAT_006671c0,2000);
  local_8 = local_8 | uVar3 | uVar4 | uVar5 | uVar6 | uVar8 | uVar9 | uVar10 | uVar11;
  DAT_00618944 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_006669f0 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = CardIDFromType(*(uint *)(&DAT_006669f0 + local_c * 4));
    (&DAT_00618170)[DAT_00618944] = uVar7;
    DAT_00618944 = DAT_00618944 + 1;
  }
  DAT_00618980 = 0;
  for (local_c = 0; (local_c < 500 && (*(int *)(&DAT_006671c0 + local_c * 4) != -1));
      local_c = local_c + 1) {
    uVar7 = CardIDFromType(*(uint *)(&DAT_006671c0 + local_c * 4));
    (&DAT_00663620)[DAT_00618980] = uVar7;
    DAT_00618980 = DAT_00618980 + 1;
  }
  DAT_00618984 = 0;
  for (local_c = 0; ((&DAT_0068efb0)[local_c * 2] != -1 && (local_c < 0x20)); local_c = local_c + 1)
  {
    if (*(int *)(&DAT_00666460 + local_c * 4) != 0) {
      iVar1 = (&DAT_0068efb0)[local_c * 2];
      iVar2 = *(int *)(&DAT_0068efb4 + local_c * 8);
      (&DAT_00615470)[DAT_00618984 * 0x2b] = iVar1;
      (&DAT_00615474)[DAT_00618984 * 0x2b] = iVar2;
      (&DAT_00615518)[DAT_00618984 * 0x2b] =
           (int)(char)(&DAT_006827b8)[iVar2 * 0x120 + iVar1 * 0x5b20];
      for (local_10 = 0; local_10 < (char)(&DAT_006827b8)[iVar2 * 0x120 + iVar1 * 0x5b20];
          local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_00615478 + local_10 * 8 + DAT_00618984 * 0xac) =
             *(undefined4 *)(&DAT_00682718 + iVar2 * 0x120 + iVar1 * 0x5b20 + local_10 * 8);
        *(undefined4 *)(&DAT_0061547c + local_10 * 8 + DAT_00618984 * 0xac) =
             *(undefined4 *)(&DAT_0068271c + iVar2 * 0x120 + iVar1 * 0x5b20 + local_10 * 8);
      }
      DAT_00618984 = DAT_00618984 + 1;
    }
  }
  DAT_006152dc = 0;
  for (local_c = 0; (local_c < 0x10 && ((&DAT_0068ed90)[local_c] != -1)); local_c = local_c + 1) {
    DAT_006152dc = DAT_006152dc + 1;
  }
  FID_conflict__memcpy(&DAT_00664640,&DAT_0068ed90,0x40);
  DAT_00664db4 = 0;
  for (local_c = 0; (local_c < 0x10 && ((&DAT_0068ed50)[local_c] != -1)); local_c = local_c + 1) {
    DAT_00664db4 = DAT_00664db4 + 1;
  }
  FID_conflict__memcpy(&DAT_00664d50,&DAT_0068ed50,0x40);
  for (local_c = 0; local_c < 0x26; local_c = local_c + 1) {
    if (*(int *)(&DAT_006667c0 + local_c * 4) != *(int *)(&DAT_00664690 + local_c * 4)) {
      local_8 = local_8 | 1;
    }
    if (*(int *)(&DAT_00666858 + local_c * 4) != *(int *)(&DAT_00617390 + local_c * 4)) {
      local_8 = local_8 | 1;
    }
    *(uint *)(&DAT_00664690 + local_c * 4) = *(uint *)(&DAT_006667c0 + local_c * 4) & 1;
    *(uint *)(&DAT_00617390 + local_c * 4) = *(uint *)(&DAT_00666858 + local_c * 4) & 1;
  }
  if (DAT_0068edd4 != DAT_005f76d8) {
    local_8 = 1;
  }
  DAT_005f76d8 = DAT_0068edd4;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return local_8;
}


