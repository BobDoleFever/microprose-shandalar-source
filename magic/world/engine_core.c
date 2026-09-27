/*
 * magic/world/engine_core.c - Shandalar Engine - Core Memory Management & Low-Level Dispatchers
 * Reconstructed Module containing 438 functions
 */
#include "magic.h"

/*
 * Decompiled function: Mem_AllocOrFree_00401d23
 * Entry Point: 00401d23
 * Size: 11 bytes
 */


void Mem_AllocOrFree_00401d23(void)

{
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_00401f40
 * Entry Point: 00401f40
 * Size: 48 bytes
 */


void Mem_AllocOrFree_00401f40(void)

{
  if (DAT_00536e70 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_00536e70);
  }
  DAT_00536e70 = (HANDLE)0x0;
  return;
}

/*
 * Decompiled function: FUN_00403189
 * Entry Point: 00403189
 * Size: 185 bytes
 */


bool FUN_00403189(HWND hwnd,int y)

{
  LONG LVar1;
  size_t sVar2;
  bool bVar3;
  int local_10;
  char *local_8;
  
  if (hwnd == (HWND)0x0) {
    bVar3 = false;
  }
  else {
    local_8 = (char *)GetWindowLongA(hwnd,4);
    LVar1 = GetWindowLongA(hwnd,8);
    if (LVar1 + -1 < y) {
      bVar3 = false;
    }
    else {
      for (local_10 = 0; local_10 < y; local_10 = local_10 + 1) {
        sVar2 = strlen(local_8);
        local_8 = local_8 + sVar2 + 1;
      }
      bVar3 = *local_8 != '_';
    }
  }
  return bVar3;
}

/*
 * Decompiled function: UI_PaintBigCardInfo
 * Entry Point: 00403250
 * Size: 955 bytes
 */


undefined4
UI_PaintBigCardInfo(int *value,int min_val,int max_val,uint target_slot,uint flags,uint arg_6,uint arg_7,uint arg_8,
            uint arg_9,uint arg_10,uint arg_11,uint arg_12,int arg_13,int arg_14,uint arg_15,
            uint arg_16,uint arg_17,uint arg_18,uint arg_19)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  int local_2c;
  int local_28;
  undefined4 local_20;
  int local_18;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_18 = 0;
  local_20 = 0;
  if (((min_val == 0) || (min_val == 1)) || (min_val == 2)) {
    bVar1 = false;
    local_28 = 0;
    while( true ) {
      if (1 < local_28) break;
      iVar2 = Rules_ParseFilter_0040360b
                        (local_28,-1,(char *)0x0,max_val,(byte)target_slot,(byte)flags,arg_6,arg_7,arg_8,
                         arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18,arg_19
                        );
      if (iVar2 != 0) {
        local_20 = 1;
        local_18 = local_18 + 1;
        if (value == (int *)0x0) {
          bVar1 = true;
        }
      }
      local_28 = local_28 + 1;
    }
    if (max_val == 0) {
      local_8 = (uint)((target_slot & 2) == 0);
    }
    else if (((flags & 2) == 0) && ((flags & 1) == 0)) {
      local_8 = 0;
    }
    else {
      local_8 = 1;
    }
    local_28 = 0;
    while ((local_28 < 2 && (!bVar1))) {
      local_c = 0;
      while( true ) {
        iVar2 = DAT_006808bc;
        if (DAT_006808bc <= g_PlayerActiveCardCount) {
          iVar2 = g_PlayerActiveCardCount;
        }
        if ((iVar2 <= local_c) || (bVar1)) break;
        if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1) {
          if (min_val == 0) {
            local_10 = local_8;
            local_2c = local_c;
            bVar3 = true;
          }
          else if (min_val == 1) {
            bVar3 = *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) ==
                    DAT_006ff2e0;
            if (bVar3) {
              local_10 = (uint)(char)(&g_CardSlot_Toughness)[local_c * 0x120 + local_8 * 0x5b20];
              local_2c = *(int *)(&g_CardSlot_OriginalCardId + local_c * 0x120 + local_8 * 0x5b20);
            }
          }
          else if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == DAT_006ff2e0
                  ) {
            local_10 = (uint)(char)(&g_CardSlot_DamageReceived)[local_c * 0x120 + local_8 * 0x5b20];
            local_2c = *(int *)(&g_CardSlot_TypeFlags + local_c * 0x120 + local_8 * 0x5b20);
            bVar3 = true;
          }
          else {
            bVar3 = false;
          }
          if ((bVar3) &&
             (iVar2 = Rules_ParseFilter_0040360b
                                (local_10,local_2c,(char *)0x0,max_val,(byte)target_slot,(byte)flags,arg_6,
                                 arg_7,arg_8,arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,
                                 arg_17,arg_18,arg_19), iVar2 != 0)) {
            local_20 = 1;
            local_18 = local_18 + 1;
            if (value == (int *)0x0) {
              bVar1 = true;
            }
          }
        }
        local_c = local_c + 1;
      }
      local_28 = local_28 + 1;
      local_8 = 1 - local_8;
    }
    if (value != (int *)0x0) {
      *value = local_18;
    }
  }
  else {
    local_20 = 0;
  }
  return local_20;
}

/*
 * Decompiled function: FUN_00405277
 * Entry Point: 00405277
 * Size: 249 bytes
 */


int FUN_00405277(int x,int y)

{
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  local_8 = 0;
  while ((local_8 < 2 && (local_10 == 0))) {
    local_c = 0;
    while ((local_c < (int)(&g_PlayerActiveCardCount)[local_8] && (local_10 == 0))) {
      if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == DAT_006ff2e0) &&
          ((char)(&g_CardSlot_Toughness)[local_c * 0x120 + local_8 * 0x5b20] == x)) &&
         (*(int *)(&g_CardSlot_OriginalCardId + local_c * 0x120 + local_8 * 0x5b20) == y)) {
        local_10 = 1;
      }
      local_c = local_c + 1;
    }
    local_8 = local_8 + 1;
  }
  return local_10;
}

/*
 * Decompiled function: FUN_00405edf
 * Entry Point: 00405edf
 * Size: 184 bytes
 */


undefined4 FUN_00405edf(int x,int y)

{
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) < 5) {
    local_8 = 1;
  }
  else {
    for (local_c = 0; local_c < 5; local_c = local_c + 1) {
      if ((&DAT_006ff2c0)[local_c] ==
          *(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34)) {
        local_8 = 1;
      }
    }
  }
  return local_8;
}

/*
 * Decompiled function: FUN_00405f97
 * Entry Point: 00405f97
 * Size: 324 bytes
 */


undefined4 FUN_00405f97(int x,int y)

{
  undefined4 local_8;
  
  local_8 = 0;
  if ((y == 0) &&
     ((x == 0 || (*(int *)(&g_MasterCardTypeTable + x * 0x34) == DAT_006ff2c0)))) {
    local_8 = 1;
  }
  if ((y == 1) &&
     ((x == 1 || (*(int *)(&g_MasterCardTypeTable + x * 0x34) == DAT_006ff2c4)))) {
    local_8 = 1;
  }
  if ((y == 2) &&
     ((x == 2 || (*(int *)(&g_MasterCardTypeTable + x * 0x34) == DAT_006ff2c8)))) {
    local_8 = 1;
  }
  if ((y == 3) &&
     ((x == 3 || (*(int *)(&g_MasterCardTypeTable + x * 0x34) == DAT_006ff2cc)))) {
    local_8 = 1;
  }
  if ((y == 4) &&
     ((x == 4 || (*(int *)(&g_MasterCardTypeTable + x * 0x34) == DAT_006ff2d0)))) {
    local_8 = 1;
  }
  return local_8;
}

/*
 * Decompiled function: FUN_0040683a
 * Entry Point: 0040683a
 * Size: 583 bytes
 */


int FUN_0040683a(char *str_1,int min_val,int max_val,int target_slot,undefined4 flags)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  char local_24;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_10 = 0;
  local_c = 0;
  iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  sVar3 = strlen(str_1);
  for (local_18 = 0; local_18 < (int)sVar3; local_18 = local_18 + 1) {
    if (str_1[local_18] < '\0') {
      local_24 = str_1[local_18] + -0x80;
    }
    else {
      local_24 = str_1[local_18];
    }
    iVar4 = FUN_0050f390(*(int *)(g_DisplaySurfaceScreen + 0x20),local_24);
    local_c = local_c + iVar4;
    if (((str_1[local_18] == ' ') || (str_1[local_18] == '\n')) || (str_1[local_18] == '^')) {
      local_8 = local_18;
    }
    if (((str_1[local_18] == '\n') || (str_1[local_18] == '^')) || (min_val * 8 < local_c)) {
      cVar1 = str_1[local_8];
      str_1[local_8] = '\0';
      if (10 < iVar2) {
        strcpy(str_1 + 0x200,str_1);
        FUN_00406a88(str_1 + local_10,(g_DisplayScreenWidth + -2) - max_val);
      }
      FUN_0040c274(str_1 + local_10,max_val,target_slot,flags);
      if (10 < iVar2) {
        strcpy(str_1,str_1 + 0x200);
      }
      str_1[local_8] = cVar1;
      target_slot = target_slot + iVar2;
      local_c = 0;
      local_10 = local_8 + 1;
      if (str_1[local_18] == '^') {
        local_10 = local_8 + 2;
      }
      local_18 = local_8;
      if (g_DisplayScreenHeight + -8 < target_slot) break;
    }
  }
  if ((0 < local_c) && (target_slot <= g_DisplayScreenHeight + -8)) {
    FUN_0040c274(str_1 + local_10,max_val,target_slot,flags);
    target_slot = target_slot + iVar2;
  }
  return target_slot;
}

/*
 * Decompiled function: FUN_00406a88
 * Entry Point: 00406a88
 * Size: 121 bytes
 */


void FUN_00406a88(char *str_1,int y)

{
  int iVar1;
  size_t sVar2;
  
  while( true ) {
    iVar1 = FUN_0040c465(str_1);
    if (iVar1 <= y) break;
    sVar2 = strlen(str_1);
    if (str_1[sVar2 - 3] != ' ') {
      sVar2 = strlen(str_1);
      str_1[sVar2 - 2] = '.';
    }
    sVar2 = strlen(str_1);
    str_1[sVar2 - 1] = '\0';
  }
  return;
}

/*
 * Decompiled function: FUN_00406b01
 * Entry Point: 00406b01
 * Size: 75 bytes
 */


bool FUN_00406b01(char *str_1)

{
  FILE *_File;
  
  _File = fopen(str_1,&DAT_0051646c);
  if (_File != (FILE *)0x0) {
    fclose(_File);
  }
  return _File != (FILE *)0x0;
}

/*
 * Decompiled function: FUN_00407499
 * Entry Point: 00407499
 * Size: 681 bytes
 */


int FUN_00407499(int value)

{
  int iVar1;
  int iVar2;
  int local_420;
  int local_41c;
  int local_418;
  int aiStack_404 [256];
  
  local_420 = 0;
  for (local_418 = 0; local_418 < 0x100; local_418 = local_418 + 1) {
    if (*(int *)(&DAT_00701944 + local_418 * 8) == -1) {
      if (((*(int *)(&DAT_00701940 + local_418 * 8) ==
            *(int *)(&g_MasterCardTypeTable + value * 0x34)) &&
          (iVar1 = FUN_00407747(*(int *)(&DAT_00701940 + local_418 * 8)), iVar1 == 0)) &&
         ((*(uint *)(&DAT_00701430 + local_418 * 4) & 1 << ((byte)DAT_0067f380 & 0x1f)) != 0)) {
        local_41c = 0;
        while ((local_41c < 500 &&
               ((((&g_MasterCardColorTable)[(*(uint *)(&deck + local_41c * 4) & 0xfff) * 0x34] & 1)
                 == 0 || (((&DAT_0051aebe)[(*(uint *)(&deck + local_41c * 4) & 0xfff) * 0x34] &
                          (&DAT_0051aebe)[value * 0x34]) == 0))))) {
          local_41c = local_41c + 1;
        }
      }
    }
    else {
      iVar1 = FUN_00407747(*(int *)(&DAT_00701940 + local_418 * 8));
      iVar2 = FUN_00407747(*(int *)(&DAT_00701944 + local_418 * 8));
      if (((iVar1 == 0) || (iVar2 == 0)) &&
         ((*(uint *)(&DAT_00701430 + local_418 * 4) & 1 << ((byte)DAT_0067f380 & 0x1f)) != 0)) {
        if ((*(int *)(&DAT_00701940 + local_418 * 8) ==
             *(int *)(&g_MasterCardTypeTable + value * 0x34)) && (iVar2 != 0)) {
          aiStack_404[local_420] = local_418;
          local_420 = local_420 + 1;
        }
        if ((*(int *)(&DAT_00701944 + local_418 * 8) ==
             *(int *)(&g_MasterCardTypeTable + value * 0x34)) && (iVar1 != 0)) {
          aiStack_404[local_420] = local_418;
          local_420 = local_420 + 1;
        }
      }
    }
  }
  if (local_420 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = Math_RandomRange(local_420);
    iVar1 = aiStack_404[iVar1];
  }
  return iVar1;
}

/*
 * Decompiled function: FUN_00407747
 * Entry Point: 00407747
 * Size: 103 bytes
 */


undefined4 FUN_00407747(int value)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return 0;
    }
    if (*(int *)(&g_MasterCardTypeTable + (*(uint *)(&deck + local_8 * 4) & 0xfff) * 0x34) == value)
    break;
    local_8 = local_8 + 1;
  }
  return 1;
}

/*
 * Decompiled function: FUN_004077ae
 * Entry Point: 004077ae
 * Size: 144 bytes
 */


char * FUN_004077ae(char *str_1)

{
  for (; ((*str_1 != '\0' && (*str_1 == ' ')) && (*str_1 != '\n')); str_1 = str_1 + 1) {
  }
  for (; ((*str_1 != '\0' && (*str_1 != ' ')) && (*str_1 != '\n')); str_1 = str_1 + 1) {
  }
  if (*str_1 == '\0') {
    str_1 = (char *)0x0;
  }
  return str_1;
}

/*
 * Decompiled function: FUN_00407843
 * Entry Point: 00407843
 * Size: 753 bytes
 */


char * FUN_00407843(char *str_1,char *str_2,int max_val)

{
  int iVar1;
  undefined4 *puVar2;
  char *local_114;
  int local_110;
  size_t local_10c;
  char *local_108;
  char local_104;
  undefined4 local_103 [63];
  
  local_110 = 0;
  local_108 = str_1;
  local_104 = '\0';
  puVar2 = local_103;
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *str_2 = '\0';
  while (local_114 = (char *)FUN_004077ae(local_108), local_114 != (char *)0x0) {
    local_10c = (int)local_114 - (int)local_108;
    iVar1 = FUN_0050f610((int *)g_DisplaySurfaceScreen,local_108,local_10c);
    if (max_val < local_110 + iVar1) {
      strcat(&local_104,&DAT_00516590);
      strcat(str_2,&local_104);
      local_104 = '\0';
      for (; (local_108 != (char *)0x0 && (*local_108 == ' ')); local_108 = local_108 + 1) {
        local_10c = local_10c - 1;
      }
      strncat(&local_104,local_108,local_10c);
      for (; (*local_114 != '\0' && (*local_114 == '\n')); local_114 = local_114 + 1) {
        strcat(str_2,&DAT_00516594);
      }
      local_110 = FUN_0050f610((int *)g_DisplaySurfaceScreen,local_114,local_10c);
      local_108 = local_114;
    }
    else {
      iVar1 = FUN_0050f610((int *)g_DisplaySurfaceScreen,local_108,local_10c);
      local_110 = local_110 + iVar1;
      strncat(&local_104,local_108,local_10c);
      if (*local_114 == '\n') {
        strcat(str_2,&local_104);
      }
      for (; (local_108 = local_114, *local_114 != '\0' && (*local_114 == '\n'));
          local_114 = local_114 + 1) {
        strcat(str_2,&DAT_00516598);
        local_110 = 0;
        local_104 = '\0';
      }
    }
  }
  iVar1 = FUN_0050f440((int *)g_DisplaySurfaceScreen,local_108);
  if (max_val < local_110 + iVar1) {
    strcat(&local_104,&DAT_0051659c);
    strcat(str_2,&local_104);
    strcat(str_2,local_108);
  }
  else {
    strcat(str_2,&local_104);
    strcat(str_2,local_108);
  }
  return str_2;
}

/*
 * Decompiled function: FUN_00407e40
 * Entry Point: 00407e40
 * Size: 585 bytes
 */


void FUN_00407e40(undefined4 x,uint y)

{
  ushort uVar1;
  SHORT SVar2;
  SHORT SVar3;
  uint uVar4;
  int *piVar5;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  if (DAT_005382d8 == 0) {
    do {
      SVar2 = GetAsyncKeyState(0x12);
    } while (SVar2 != 0);
    do {
      SVar2 = GetAsyncKeyState(0x11);
    } while (SVar2 != 0);
    DAT_005382d8 = 1;
  }
  if (DAT_00516bdc == 0x31) {
    MessageBeep(0xffffffff);
  }
  else {
    uVar4 = (y & 0xff0000) >> 0x10;
    SVar2 = GetAsyncKeyState(0x12);
    if (SVar2 == 0) {
      SVar2 = GetAsyncKeyState(0x11);
      if (SVar2 == 0) {
        piVar5 = (int *)__p___mb_cur_max();
        if (*piVar5 < 2) {
          uVar1 = *(ushort *)(&DAT_0051664a + uVar4 * 0x10);
          piVar5 = (int *)__p__pctype();
          local_14 = *(ushort *)(*piVar5 + (uVar1 & 0xff) * 2) & 0x103;
        }
        else {
          local_14 = _isctype(*(ushort *)(&DAT_0051664a + uVar4 * 0x10) & 0xff,0x103);
        }
        if (local_14 == 0) {
          if ((uVar4 < 0x47) || (0x53 < uVar4)) {
            SVar2 = GetAsyncKeyState(0x10);
            if (SVar2 != 0) {
              local_c = 1;
            }
          }
          else {
            SVar2 = GetAsyncKeyState(0x90);
            SVar3 = GetAsyncKeyState(0x10);
            local_c = (uint)((SVar2 != 0) != (SVar3 != 0));
          }
        }
        else {
          SVar2 = GetAsyncKeyState(0x10);
          SVar3 = GetAsyncKeyState(0x14);
          local_c = (uint)((SVar2 != 0) != (SVar3 != 0));
        }
      }
      else {
        local_c = 2;
      }
    }
    else {
      local_c = 3;
    }
    if (*(char *)(uVar4 * 0x10 + 0x516648 + local_c * 4) != '\0') {
      uVar1 = *(ushort *)(&DAT_0051664a + local_c * 4 + uVar4 * 0x10);
      local_10 = 0x32U - DAT_00516bdc;
      if ((int)(y & 0xffff) <= (int)(0x32U - DAT_00516bdc)) {
        local_10 = y & 0xffff;
      }
      while (local_10 != 0) {
        (&DAT_00538210)[DAT_00516bdc] = (uint)uVar1;
        DAT_00516bdc = DAT_00516bdc + 1;
        local_10 = local_10 - 1;
      }
    }
  }
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_00408089
 * Entry Point: 00408089
 * Size: 41 bytes
 */


bool Mem_AllocOrFree_00408089(void)

{
  return DAT_00516bdc != 0;
}

/*
 * Decompiled function: FUN_004080b2
 * Entry Point: 004080b2
 * Size: 93 bytes
 */


undefined4 FUN_004080b2(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00538210;
  if (DAT_00516bdc == 0) {
    uVar1 = 0;
  }
  else {
    DAT_00516bdc = DAT_00516bdc + -1;
    if (DAT_00516bdc != 0) {
      memcpy(&DAT_00538210,&DAT_00538214,DAT_00516bdc * 4);
    }
  }
  return uVar1;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040810f
 * Entry Point: 0040810f
 * Size: 41 bytes
 */


undefined4 Mem_AllocOrFree_0040810f(void)

{
  undefined4 uVar1;
  
  if (DAT_00516bdc == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040813d
 * Entry Point: 0040813d
 * Size: 41 bytes
 */


undefined4 Mem_AllocOrFree_0040813d(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00538210;
  if (DAT_00516bdc == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0040816b
 * Entry Point: 0040816b
 * Size: 57 bytes
 */


void FUN_0040816b(undefined4 value)

{
  memmove(&DAT_00538214,&DAT_00538210,DAT_00516bdc << 2);
  DAT_00516bdc = DAT_00516bdc + 1;
  DAT_00538210 = value;
  return;
}

/*
 * Decompiled function: FUN_004082d1
 * Entry Point: 004082d1
 * Size: 153 bytes
 */


void FUN_004082d1(void)

{
  if (DAT_006b2d8c != 0) {
    KillTimer((HWND)0x0,DAT_006b2d8c);
    DAT_006b2d8c = 0;
  }
  if (DAT_005382dc != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005382dc);
  }
  if (DAT_005382e8 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005382e8);
  }
  if (DAT_005382e4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005382e4);
  }
  DAT_005382dc = (HGDIOBJ)0x0;
  DAT_005382e8 = (HGDIOBJ)0x0;
  DAT_005382e4 = (HGDIOBJ)0x0;
  return;
}

/*
 * Decompiled function: FUN_004088d0
 * Entry Point: 004088d0
 * Size: 1068 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004088d0(int *value)

{
  POINT Point;
  BOOL BVar1;
  int iVar2;
  int iVar3;
  LRESULT LVar4;
  undefined4 uVar5;
  tagPOINT local_f0;
  tagPOINT local_e8;
  HWND local_e0;
  int local_dc;
  char local_d8 [100];
  tagPOINT local_74;
  int local_6c;
  char local_68 [100];
  
  switch(value[1]) {
  case 0x113:
    if ((*value == 0) && (value[2] == DAT_006b2d8c)) {
      KillTimer((HWND)0x0,DAT_006b2d8c);
      DAT_006b2d8c = 0;
      GetCursorPos(&local_e8);
      Point.y = local_e8.y;
      Point.x = local_e8.x;
      local_e0 = WindowFromPoint(Point);
      local_f0.x = local_e8.x;
      local_f0.y = local_e8.y;
      ScreenToClient(local_e0,&local_f0);
      LVar4 = SendMessageA(local_e0,0x437,(WPARAM)local_68,local_f0.y << 0x10 | local_f0.x & 0xffffU
                          );
      if ((LVar4 != 0) && (DAT_006fe420 != 0)) {
        SendMessageA(DAT_006b1570,0x400,
                     (local_e8.y + _DAT_006a4a4c) * 0x10000 | local_e8.x + _DAT_007006b8 & 0xffffU,
                     (LPARAM)local_68);
      }
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
    break;
  default:
    uVar5 = 0;
    break;
  case 0x200:
    BVar1 = IsWindowVisible(DAT_006b1570);
    if (BVar1 == 0) {
      if (DAT_006b2d8c != 0) {
        KillTimer((HWND)0x0,DAT_006b2d8c);
        DAT_006b2d8c = 0;
      }
      DAT_006b2d8c = SetTimer((HWND)0x0,0,DAT_006a2850,(TIMERPROC)0x0);
    }
    else if (*value == DAT_00516be0) {
      local_6c = 1;
      local_dc = 1;
      if (*value == DAT_00516be0) {
        iVar3 = abs(((uint)value[3] >> 0x10) - _DAT_00516bec);
        iVar2 = abs(*(ushort *)(value + 3) - _DAT_00516be8);
        if (DAT_00695f10 < iVar3 + iVar2) {
          local_dc = SendMessageA((HWND)*value,0x437,(WPARAM)local_68,value[3]);
        }
        else {
          local_6c = 0;
        }
      }
      else {
        local_dc = SendMessageA((HWND)*value,0x437,(WPARAM)local_68,value[3]);
      }
      if (local_dc == 0) {
        ShowWindow(DAT_006b1570,0);
      }
      else if (local_6c != 0) {
        DAT_00516be0 = *value;
        _DAT_00516be8 = (uint)*(ushort *)(value + 3);
        _DAT_00516bec = (uint)value[3] >> 0x10;
        GetCursorPos(&local_74);
        if (DAT_006fe420 == 0) {
          ShowWindow(DAT_006b1570,0);
        }
        else {
          SendMessageA(DAT_006b1570,0x401,0,(LPARAM)local_d8);
          iVar3 = strcmp(local_d8,local_68);
          if (iVar3 != 0) {
            SendMessageA(DAT_006b1570,0x400,
                         (local_74.y + _DAT_006a4a4c) * 0x10000 |
                         local_74.x + _DAT_007006b8 & 0xffffU,(LPARAM)local_68);
          }
        }
      }
    }
    else {
      if (DAT_006b2d8c != 0) {
        KillTimer((HWND)0x0,DAT_006b2d8c);
        DAT_006b2d8c = 0;
      }
      DAT_006b2d8c = SetTimer((HWND)0x0,0,DAT_006a2850,(TIMERPROC)0x0);
      DAT_00516be0 = *value;
      ShowWindow(DAT_006b1570,0);
    }
    uVar5 = 0;
    break;
  case 0x201:
  case 0x204:
  case 0x207:
    ShowWindow(DAT_006b1570,0);
    if (DAT_006b2d8c != 0) {
      KillTimer((HWND)0x0,DAT_006b2d8c);
      DAT_006b2d8c = 0;
    }
    uVar5 = 0;
  }
  return uVar5;
}

/*
 * Decompiled function: FUN_00409052
 * Entry Point: 00409052
 * Size: 164 bytes
 */


void FUN_00409052(void)

{
  int local_8;
  
  if (DAT_00538308 != (HMENU)0x0) {
    DestroyMenu(DAT_00538308);
  }
  DAT_00538308 = (HMENU)0x0;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00538310 + local_8 * 4) != 0) {
      GDI_DestroyDIBSection_Magic(*(HANDLE *)(&DAT_00538310 + local_8 * 4));
      *(undefined4 *)(&DAT_00538310 + local_8 * 4) = 0;
    }
  }
  if (DAT_0053830c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0053830c);
  }
  DAT_0053830c = (HGDIOBJ)0x0;
  return;
}

/*
 * Decompiled function: FUN_004097e2
 * Entry Point: 004097e2
 * Size: 842 bytes
 */


void FUN_004097e2(HDC hdc,RECT *min_val,int max_val)

{
  HBRUSH hbr;
  char *pcVar1;
  size_t sVar2;
  undefined1 local_7c [4];
  int local_78;
  int local_74;
  int local_64;
  tagRECT local_60;
  HANDLE local_50;
  tagPOINT local_4c;
  int local_44;
  HANDLE local_40;
  char local_3c [52];
  HWND local_8;
  
  if (max_val == 0) {
    local_8 = DAT_0068a620;
  }
  else {
    local_8 = DAT_006a49f0;
  }
  local_40 = (HANDLE)GetWindowLongA(local_8,0);
  if (max_val == 0) {
    local_50 = *(HANDLE *)(&DAT_00538310 + DAT_006a3f60 * 4);
  }
  else {
    local_50 = *(HANDLE *)(&DAT_00538310 + DAT_006fe490 * 4);
  }
  if (local_50 == (HANDLE)0x0) {
    hbr = GetStockObject(4);
    FillRect(hdc,min_val,hbr);
  }
  else {
    FUN_004f3b5f((int)hdc,(int)min_val,local_50);
  }
  if (local_40 != (HANDLE)0x0) {
    GetObjectA(local_40,0x18,local_7c);
    local_78 = local_78 / 2;
    local_64 = SaveDC(hdc);
    SetMapMode(hdc,7);
    SetWindowOrgEx(hdc,local_78 / 2,local_74 / 2,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,min_val->left + (min_val->right - min_val->left) / 2,
                     min_val->top + (min_val->bottom - min_val->top) / 2,(LPPOINT)0x0);
    SetWindowExtEx(hdc,local_78,local_74,(LPSIZE)0x0);
    SetViewportExtEx(hdc,min_val->right - min_val->left,min_val->bottom - min_val->top,(LPSIZE)0x0);
    SetRect(&local_60,0,0,local_78,local_74);
    FUN_004f3e29(hdc,&local_60,local_40);
    RestoreDC(hdc,local_64);
  }
  if (max_val == 1) {
    Ai_Subsystem_004b6f49(local_3c);
  }
  else {
    strcpy(local_3c,&DAT_0068a6a0);
    pcVar1 = strchr(local_3c,0x2d);
    if (pcVar1 != (char *)0x0) {
      pcVar1 = strchr(local_3c,0x2d);
      *pcVar1 = '\0';
    }
  }
  sVar2 = strlen(local_3c);
  if (sVar2 != 0) {
    local_44 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,min_val->right - min_val->left,100,(LPSIZE)0x0);
    SetViewportExtEx(hdc,min_val->right - min_val->left,min_val->bottom - min_val->top,(LPSIZE)0x0);
    SelectObject(hdc,DAT_0053830c);
    SetBkMode(hdc,1);
    SetTextAlign(hdc,0xe);
    local_4c.x = min_val->left + (min_val->right - min_val->left) / 2;
    local_4c.y = min_val->bottom;
    DPtoLP(hdc,&local_4c,1);
    SetTextColor(hdc,DAT_005382f4);
    sVar2 = strlen(local_3c);
    TextOutA(hdc,local_4c.x + 1,local_4c.y + 1,local_3c,sVar2);
    SetTextColor(hdc,DAT_005382f0);
    sVar2 = strlen(local_3c);
    TextOutA(hdc,local_4c.x,local_4c.y,local_3c,sVar2);
    RestoreDC(hdc,local_44);
  }
  return;
}

/*
 * Decompiled function: FUN_00409b2c
 * Entry Point: 00409b2c
 * Size: 327 bytes
 */


void FUN_00409b2c(int x,int y)

{
  HWND hWnd;
  HWND hWnd_00;
  HWND hWnd_01;
  HWND hWnd_02;
  undefined4 local_c;
  
  if (x == 0) {
    local_c = DAT_006b2d60;
    hWnd = DAT_006b2e10;
    hWnd_00 = DAT_006fe48c;
    hWnd_01 = DAT_006b2530;
    hWnd_02 = DAT_0068a620;
  }
  else {
    local_c = DAT_006ff560;
    hWnd = DAT_006a4928;
    hWnd_00 = DAT_006ff388;
    hWnd_01 = DAT_006ff4a8;
    hWnd_02 = DAT_006a49f0;
  }
  if (y == 0) {
    ShowWindow(hWnd_01,5);
    ShowWindow(hWnd_00,5);
    ShowWindow(hWnd,5);
    ShowWindow(local_c,5);
    ShowWindow(hWnd_02,0);
  }
  else {
    ShowWindow(hWnd_02,5);
    BringWindowToTop(hWnd_02);
    ShowWindow(hWnd_01,0);
    if (DAT_006fe444 != 2) {
      ShowWindow(hWnd_00,0);
      ShowWindow(hWnd,0);
      ShowWindow(local_c,0);
    }
  }
  return;
}

/*
 * Decompiled function: FUN_00409c73
 * Entry Point: 00409c73
 * Size: 63 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00409c73(undefined4 value)

{
  _DAT_005382f8 = 0;
  _DAT_005382fc = value;
  _DAT_00538300 = 0xffffffff;
  PostMessageA(g_MainAppHwnd,0x464,0,0x5382f8);
  return;
}

/*
 * Decompiled function: FUN_00409cb2
 * Entry Point: 00409cb2
 * Size: 74 bytes
 */


undefined4 FUN_00409cb2(int value)

{
  undefined4 uVar1;
  
  if (((value == 1) && (DAT_006fefa0 != 0)) || ((value == 0 && (DAT_006fefa4 != 0)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00409d10
 * Entry Point: 00409d10
 * Size: 166 bytes
 */


undefined4 FUN_00409d10(void)

{
  undefined4 uVar1;
  FARPROC pFVar2;
  int local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    (&DAT_00701020)[local_8] = 0;
  }
  DAT_00516ca8 = LoadLibraryA(s_statwin_dll_00516cac);
  if (DAT_00516ca8 == (HMODULE)0x0) {
    uVar1 = 1;
  }
  else {
    for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
      pFVar2 = GetProcAddress(DAT_00516ca8,(LPCSTR)(local_8 + 1U & 0xffff));
      (&DAT_00701020)[local_8] = pFVar2;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00409db6
 * Entry Point: 00409db6
 * Size: 93 bytes
 */


void FUN_00409db6(void)

{
  int local_8;
  
  if (DAT_00516ca8 != (HMODULE)0x0) {
    FreeLibrary(DAT_00516ca8);
    DAT_00516ca8 = (HMODULE)0x0;
  }
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    (&DAT_00701020)[local_8] = 0;
  }
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_00409e13
 * Entry Point: 00409e13
 * Size: 41 bytes
 */


void Mem_AllocOrFree_00409e13(undefined4 x,undefined4 y)

{
  if (DAT_00701020 != (code *)0x0) {
    (*DAT_00701020)(x,y);
  }
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_00409e3c
 * Entry Point: 00409e3c
 * Size: 49 bytes
 */


undefined4 Mem_AllocOrFree_00409e3c(undefined4 value)

{
  undefined4 uVar1;
  
  if (DAT_00701024 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_00701024)(value);
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00409e6d
 * Entry Point: 00409e6d
 * Size: 61 bytes
 */


undefined4 FUN_00409e6d(undefined4 value,undefined4 min_val,undefined4 max_val,undefined4 target_slot)

{
  undefined4 uVar1;
  
  if (DAT_00701028 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_00701028)(value,min_val,max_val,target_slot);
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00409eb0
 * Entry Point: 00409eb0
 * Size: 102 bytes
 */


void FUN_00409eb0(int value)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00516cb8 + local_8 * 8) =
         *(undefined4 *)(&DAT_00516cb8 + local_8 * 8 + value * 0x280);
    *(undefined4 *)(&DAT_00516cbc + local_8 * 8) =
         *(undefined4 *)(&DAT_00516cbc + local_8 * 8 + value * 0x280);
  }
  return;
}

/*
 * Decompiled function: FUN_00409f16
 * Entry Point: 00409f16
 * Size: 131 bytes
 */


void FUN_00409f16(int x,int y)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x4f < local_8) {
      return;
    }
    if ((0 < *(int *)(&DAT_00516cbc + local_8 * 8 + x * 0x280)) &&
       (iVar1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00516cb8 + local_8 * 8 + x * 0x280)),
       iVar1 == y)) break;
    local_8 = local_8 + 1;
  }
  *(int *)(&DAT_00516cbc + local_8 * 8 + x * 0x280) =
       *(int *)(&DAT_00516cbc + local_8 * 8 + x * 0x280) + -1;
  return;
}

/*
 * Decompiled function: FUN_00409f99
 * Entry Point: 00409f99
 * Size: 145 bytes
 */


void FUN_00409f99(char *str_1,int y,uint width,int height)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00516cbc + local_8 * 8 + y * 0x280) = 0;
    *(undefined4 *)(&DAT_00516cb8 + local_8 * 8 + y * 0x280) =
         *(undefined4 *)(&DAT_00516cbc + local_8 * 8 + y * 0x280);
  }
  Deck_FilterAttributes_00406b4c(str_1,(int)(&DAT_00516cb8 + y * 0x280),width,height);
  return;
}

/*
 * Decompiled function: FUN_0040a02a
 * Entry Point: 0040a02a
 * Size: 324 bytes
 */


int FUN_0040a02a(int value)

{
  int iVar1;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (value == -1) {
    iVar1 = -1;
  }
  else {
    local_10 = 0;
    for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
      local_10 = local_10 + *(int *)(&DAT_00516cbc + local_8 * 8 + value * 0x280);
    }
    if (local_10 == 0) {
      iVar1 = -1;
    }
    else {
      local_c = Math_RandomRange(local_10);
      for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
        local_c = local_c - *(int *)(&DAT_00516cbc + local_8 * 8 + value * 0x280);
        if (local_c < 0) {
          local_14 = *(int *)(&DAT_00516cb8 + local_8 * 8 + value * 0x280);
          if (g_IsAiThinking != 1) {
            *(int *)(&DAT_00516cbc + local_8 * 8 + value * 0x280) =
                 *(int *)(&DAT_00516cbc + local_8 * 8 + value * 0x280) + -1;
          }
          break;
        }
      }
      for (local_8 = 0;
          (iVar1 = g_MasterCardCount, local_8 < g_MasterCardCount &&
          (iVar1 = local_8, *(int *)(&g_MasterCardTypeTable + local_8 * 0x34) != local_14));
          local_8 = local_8 + 1) {
      }
    }
  }
  return iVar1;
}

/*
 * Decompiled function: FUN_0040a16e
 * Entry Point: 0040a16e
 * Size: 53 bytes
 */


void FUN_0040a16e(void)

{
  Pic_Load_004509e8(g_CurrentTurnPhase,0x69ef00,500,s_Opponent_library_005171bc,0);
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040a1a3
 * Entry Point: 0040a1a3
 * Size: 47 bytes
 */


void Mem_AllocOrFree_0040a1a3(void)

{
  Pic_Load_004509e8(g_CurrentTurnPhase,0x69e730,500,s_Your_Library_005171d4,0);
  return;
}

/*
 * Decompiled function: Math_RandomRange
 * Entry Point: 0040a1d2
 * Size: 45 bytes
 */


int Math_RandomRange(int value)

{
  int iVar1;
  
  if (value < 2) {
    iVar1 = 0;
  }
  else {
    iVar1 = rand();
    iVar1 = iVar1 % value;
  }
  return iVar1;
}

/*
 * Decompiled function: FUN_0040a1ff
 * Entry Point: 0040a1ff
 * Size: 65 bytes
 */


void FUN_0040a1ff(void)

{
  int iVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < 100; local_8 = local_8 + 1) {
    iVar1 = rand();
    *(int *)(&DAT_00538338 + local_8 * 4) = iVar1;
  }
  Mem_AllocOrFree_0040a240();
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040a240
 * Entry Point: 0040a240
 * Size: 21 bytes
 */


void Mem_AllocOrFree_0040a240(void)

{
  DAT_00538334 = 0;
  return;
}

/*
 * Decompiled function: FUN_0040a255
 * Entry Point: 0040a255
 * Size: 101 bytes
 */


uint FUN_0040a255(uint value)

{
  uint uVar1;
  
  if (DAT_00538334 < 100) {
    uVar1 = (int)(*(int *)(&DAT_00538338 + (DAT_00538334 % 100) * 4) * value) >> 0xf;
  }
  else {
    uVar1 = DAT_00538334 % value;
  }
  DAT_00538334 = DAT_00538334 + 1;
  return uVar1;
}

/*
 * Decompiled function: FUN_0040a2c0
 * Entry Point: 0040a2c0
 * Size: 69 bytes
 */


undefined4 FUN_0040a2c0(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  DAT_00701018 = DVar1 & 0x7fff;
  srand(DAT_00701018 * 0x43);
  DAT_00701014 = 1;
  return 0;
}

/*
 * Decompiled function: Math_Clamp
 * Entry Point: 0040a305
 * Size: 55 bytes
 */


int Math_Clamp(int value,int min_val,int max_val)

{
  if (value < min_val) {
    value = min_val;
  }
  if (max_val < value) {
    value = max_val;
  }
  return value;
}

/*
 * Decompiled function: FUN_0040a33c
 * Entry Point: 0040a33c
 * Size: 51 bytes
 */


void FUN_0040a33c(void)

{
  return;
}

/*
 * Decompiled function: FUN_0040a36f
 * Entry Point: 0040a36f
 * Size: 114 bytes
 */


int FUN_0040a36f(int x,int y)

{
  undefined4 local_8;
  
  if (x < 0) {
    x = -x;
  }
  if (y < 0) {
    y = -y;
  }
  if (y < x) {
    local_8 = x * 2 + y;
  }
  else {
    local_8 = y * 2 + x;
  }
  if (local_8 < 0) {
    local_8 = 0x7ffe;
  }
  return local_8;
}

/*
 * Decompiled function: App_ProcessPendingMessages
 * Entry Point: 0040a3e1
 * Size: 65 bytes
 */


void App_ProcessPendingMessages(void)

{
  int iVar1;
  
  iVar1 = DAT_005239ec;
  while (iVar1 != 0) {
    Pic_Subsystem_0044b84b();
    iVar1 = DAT_0067bda0;
  }
  while (iVar1 = Mem_AllocOrFree_00408089(), iVar1 != 0) {
    FUN_0048ac2f();
  }
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040a422
 * Entry Point: 0040a422
 * Size: 34 bytes
 */


void Mem_AllocOrFree_0040a422(void)

{
  int iVar1;
  
  while( true ) {
    iVar1 = Mem_AllocOrFree_00408089();
    if (iVar1 == 0) break;
    FUN_0048ac2f();
  }
  return;
}

/*
 * Decompiled function: FUN_0040a444
 * Entry Point: 0040a444
 * Size: 104 bytes
 */


int FUN_0040a444(void)

{
  int iVar1;
  undefined4 local_8;
  
  if (g_IsAiThinking == 0) {
    do {
      Pic_Subsystem_0044b84b();
      if (DAT_0067bda0 != 0) break;
      iVar1 = Mem_AllocOrFree_00408089();
    } while (iVar1 == 0);
    local_8 = DAT_0067bda0;
    if (DAT_0067bda0 == 0) {
      local_8 = FUN_0048ac2f();
    }
    App_ProcessPendingMessages();
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040a4ac
 * Entry Point: 0040a4ac
 * Size: 40 bytes
 */


void Mem_AllocOrFree_0040a4ac(void *value,void *min_val,size_t max_val)

{
  memcpy(min_val,value,max_val);
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040a4d4
 * Entry Point: 0040a4d4
 * Size: 40 bytes
 */


void Mem_AllocOrFree_0040a4d4(void *value,void *min_val,size_t max_val)

{
  memcpy(min_val,value,max_val);
  return;
}

/*
 * Decompiled function: Pic_Load_advfac64_0040a4fc
 * Entry Point: 0040a4fc
 * Size: 106 bytes
 */


undefined4 Pic_Load_advfac64_0040a4fc(void)

{
  SetFocus(_hwndScreen);
  LoadPalNoPic(s_advfac64_pic_005171e4);
  Catalog_LoadPaletteMap(s_todpal_tr_005171f4,(char *)0x0);
  SelectPalette(*(HDC *)(DAT_0070a850 + 4),_hLibPal,0);
  RealizePalette(*(HDC *)(DAT_0070a850 + 4));
  FUN_0040a566();
  App_ProcessPendingMessages();
  return 0;
}

/*
 * Decompiled function: FUN_0040a566
 * Entry Point: 0040a566
 * Size: 120 bytes
 */


undefined4 FUN_0040a566(void)

{
  int local_8;
  
  DAT_0067bde8 = 0;
  DAT_0067f3b8 = 0;
  for (local_8 = 0; local_8 < 500; local_8 = local_8 + 1) {
    if ((*(int *)(&deck + local_8 * 4) != -1) &&
       (DAT_0067bde8 = DAT_0067bde8 + 1, ((&DAT_00702151)[local_8 * 4] & 0x40) == 0)) {
      DAT_0067f3b8 = DAT_0067f3b8 + 1;
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_0040a5de
 * Entry Point: 0040a5de
 * Size: 327 bytes
 */


void FUN_0040a5de(void)

{
  int arg_9;
  int arg_10;
  undefined4 local_8;
  
  Surface_BlitToDevice((int *)g_DisplaySurfaceScreen,(int)g_DisplayScreenWidth / 2 - 0x50,
               (int)g_DisplayScreenHeight / 3 + -0x3c,0xa0,0x78,(int *)g_DisplaySurfaceBackBuffer,0,0);
  for (local_8 = 3; local_8 < 9; local_8 = local_8 + 1) {
    arg_9 = (int)(g_DisplayScreenWidth * local_8 + ((int)(g_DisplayScreenWidth * local_8) >> 0x1f & 7U)) >> 3;
    arg_10 = (int)(g_DisplayScreenHeight * local_8 + ((int)(g_DisplayScreenHeight * local_8) >> 0x1f & 7U)) >> 3;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0xa0,0x78,(int *)g_DisplaySurfaceScreen
                       ,(int)g_DisplayScreenWidth / 2 - arg_9 / 2,
                       (((int)g_DisplayScreenHeight / 3) * (8 - local_8) +
                       ((int)g_DisplayScreenHeight / 2) * (local_8 + -2)) / 6 - arg_10 / 2,arg_9,arg_10);
  }
  Surface_BlitToDevice((int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
               (int *)g_DisplaySurfaceBackBuffer,0,0);
  App_ProcessPendingMessages();
  return;
}

/*
 * Decompiled function: FUN_0040a725
 * Entry Point: 0040a725
 * Size: 350 bytes
 */


void FUN_0040a725(char *value)

{
  int arg_9;
  int arg_10;
  undefined4 local_8;
  
  Mem_AllocOrFree_00510e20(1,value);
  *(undefined4 *)g_DisplaySurfaceScreen = 1;
  FUN_0048a2a5(0,0,0x13f,199,0xff);
  *(undefined4 *)g_DisplaySurfaceScreen = 0;
  for (local_8 = 2; local_8 < 9; local_8 = local_8 + 1) {
    arg_9 = (int)(g_DisplayScreenWidth * local_8 + ((int)(g_DisplayScreenWidth * local_8) >> 0x1f & 7U)) >> 3;
    arg_10 = (int)(g_DisplayScreenHeight * local_8 + ((int)(g_DisplayScreenHeight * local_8) >> 0x1f & 7U)) >> 3;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x140,200,(int *)g_DisplaySurfaceScreen
                       ,(int)g_DisplayScreenWidth / 2 - arg_9 / 2,
                       (((int)g_DisplayScreenHeight / 3) * (8 - local_8) +
                       (local_8 + -2) * ((int)g_DisplayScreenHeight / 2)) / 6 - arg_10 / 2,arg_9,arg_10);
    FUN_00501736((int)((10 - local_8) + (10 - local_8 >> 0x1f & 3U)) >> 2);
  }
  Surface_BlitToDevice((int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
               (int *)g_DisplaySurfaceBackBuffer,0,0);
  return;
}

/*
 * Decompiled function: FUN_0040a883
 * Entry Point: 0040a883
 * Size: 218 bytes
 */


void FUN_0040a883(char *value)

{
  uint min_val;
  int arg_8;
  uint target_slot;
  DWORD flags;
  
  min_val = Ai_Util_004c3bc4(0x40);
  arg_8 = Ai_Util_004c3bc4(0x30);
  target_slot = Ai_Util_004c3bc4(0x200);
  flags = Ai_Util_004c3bc4(0x118);
  FUN_00510b70(1,0,g_DisplayScreenHeight + -0x118,value,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,min_val,arg_8,target_slot,flags);
  FUN_0050b9d5(g_DisplaySurfaceBackBuffer);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,min_val,arg_8,target_slot,flags,
               (int *)g_DisplaySurfaceScreen,min_val,arg_8);
  return;
}

/*
 * Decompiled function: FUN_0040a95d
 * Entry Point: 0040a95d
 * Size: 404 bytes
 */


void FUN_0040a95d(char *value)

{
  int max_val;
  int arg_9;
  int arg_10;
  int iVar1;
  int arg_9_00;
  int arg_10_00;
  undefined4 local_18;
  
  max_val = g_DisplayScreenHeight + -0x118;
  FUN_00510b70(1,0,max_val,value,(short *)0x0);
  arg_9 = Ai_Util_004c3ba3(0x100);
  arg_10 = Ai_Util_004c3ba3(0x8c);
  iVar1 = Ai_Util_004c3ba3(0x5e);
  for (local_18 = 2; local_18 < 9; local_18 = local_18 + 1) {
    arg_9_00 = (int)(local_18 * arg_9 + (local_18 * arg_9 >> 0x1f & 7U)) >> 3;
    arg_10_00 = (int)(local_18 * arg_10 + (local_18 * arg_10 >> 0x1f & 7U)) >> 3;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,max_val,0x200,0x118,
                       (int *)g_DisplaySurfaceScreen,g_DisplayScreenWidth / 2 - arg_9_00 / 2,
                       iVar1 - arg_10_00 / 2,arg_9_00,arg_10_00);
  }
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,max_val,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,g_DisplayScreenWidth / 2 - arg_9 / 2,
                     iVar1 - arg_10 / 2,arg_9,arg_10);
  FUN_0050b9d5(g_DisplaySurfaceScreen);
  return;
}

/*
 * Decompiled function: FUN_0040aaf1
 * Entry Point: 0040aaf1
 * Size: 264 bytes
 */


void FUN_0040aaf1(char *value)

{
  int iVar1;
  int iVar2;
  int arg_7;
  int arg_8;
  int arg_9;
  int arg_10;
  
  arg_7 = Ai_Util_004c3bc4(0x40);
  arg_8 = Ai_Util_004c3bc4(0x30);
  arg_9 = Ai_Util_004c3bc4(0x200);
  arg_10 = Ai_Util_004c3bc4(0x118);
  iVar1 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceBackBuffer];
  iVar2 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen];
  FUN_00510b70(1,0,g_DisplayScreenHeight + -0x118,value,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,arg_7,arg_8,arg_9,arg_10);
  FUN_0050b9d5(g_DisplaySurfaceBackBuffer);
  FUN_00511e20(*(HDC *)(iVar2 + 4),arg_7,arg_8,arg_9,arg_10,0x20,3,8,8,*(HDC *)(iVar1 + 4));
  FUN_00501736(0x2d);
  return;
}

/*
 * Decompiled function: FUN_0040abf9
 * Entry Point: 0040abf9
 * Size: 260 bytes
 */


void FUN_0040abf9(char *value)

{
  int iVar1;
  int iVar2;
  int arg_7;
  int arg_8;
  int arg_9;
  int arg_10;
  
  arg_7 = Ai_Util_004c3bc4(0x40);
  arg_8 = Ai_Util_004c3bc4(0x30);
  arg_9 = Ai_Util_004c3bc4(0x200);
  arg_10 = Ai_Util_004c3bc4(0x118);
  iVar1 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceBackBuffer];
  iVar2 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen];
  FUN_00510b70(1,0,g_DisplayScreenHeight + -0x118,value,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,arg_7,arg_8,arg_9,arg_10);
  FUN_0050b9d5(g_DisplaySurfaceBackBuffer);
  FUN_005119e0(*(HDC *)(iVar2 + 4),arg_7,arg_8,arg_9,arg_10,5,5,*(HDC *)(iVar1 + 4));
  FUN_00501736(0x2d);
  return;
}

/*
 * Decompiled function: FUN_0040acfd
 * Entry Point: 0040acfd
 * Size: 178 bytes
 */


void FUN_0040acfd(char *value)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceBackBuffer];
  iVar2 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen];
  FUN_00510b70(1,0,g_DisplayScreenHeight + -0x1e0,value,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight + -0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  FUN_005119e0(*(HDC *)(iVar2 + 4),0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,8,8,*(HDC *)(iVar1 + 4));
  return;
}

/*
 * Decompiled function: FUN_0040adaf
 * Entry Point: 0040adaf
 * Size: 182 bytes
 */


void FUN_0040adaf(char *value,int min_val,int max_val)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceBackBuffer];
  iVar2 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen];
  FUN_00510b70(1,0,g_DisplayScreenHeight + -0x1e0,value,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_DisplayScreenHeight + -0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  FUN_005119e0(*(HDC *)(iVar2 + 4),0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,min_val,max_val,*(HDC *)(iVar1 + 4));
  return;
}

/*
 * Decompiled function: FUN_0040ae70
 * Entry Point: 0040ae70
 * Size: 407 bytes
 */


undefined4 FUN_0040ae70(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  int local_28;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    if (y == 0) {
      local_28 = 0;
    }
    else if (y == 1) {
      local_28 = 1;
    }
    else if (y == 2) {
      local_28 = 2;
    }
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,DAT_00517210,DAT_00517214,DAT_00517218,
                      DAT_0051721c,(&DAT_00641890)[local_28 + DAT_0051722c * 3]);
    if ((y == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0040b03e
 * Entry Point: 0040b03e
 * Size: 261 bytes
 */


undefined4 FUN_0040b03e(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    if ((y == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0040b143
 * Entry Point: 0040b143
 * Size: 389 bytes
 */


undefined4 FUN_0040b143(int value)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int arg_6;
  int iVar5;
  int iVar6;
  
  arg_6 = DAT_006498e4;
  iVar1 = *(int *)(value + 0x30);
  Pic_Subsystem_0044b84b();
  iVar5 = *(int *)(value + 0x14) + *(int *)(value + 0x70) / 2;
  if (iVar5 <= DAT_0067bda8) {
    iVar5 = DAT_0067bda8;
  }
  iVar6 = (*(int *)(value + 0x14) + *(int *)(value + 0x1c)) - *(int *)(value + 0x70) / 2;
  if (iVar5 <= iVar6) {
    iVar6 = iVar5;
  }
  iVar5 = *(int *)(value + 0x14);
  iVar2 = *(int *)(value + 0x70);
  iVar3 = *(int *)(value + 0x1c);
  iVar4 = *(int *)(value + 0x70);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(value + 0x10),*(int *)(value + 0x14),
                    *(int *)(value + 0x18),*(int *)(value + 0x1c),DAT_00641878);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(value + 0x10),
                    iVar6 - *(int *)(value + 0x70) / 2,*(int *)(value + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(value + 0x18)) / *(int *)(value + 8),
                    arg_6);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,*(uint *)(value + 0x10),*(int *)(value + 0x14),
               *(uint *)(value + 0x18),*(DWORD *)(value + 0x1c),(int *)g_DisplaySurfaceScreen,
               *(int *)(value + 0x10),*(int *)(value + 0x14));
  Castle_Process_0040b7fa((((iVar6 - iVar5) - iVar2 / 2) * iVar1) / (iVar3 - iVar4));
  DAT_005384d0 = *(undefined4 *)(value + 0x2c);
  return *(undefined4 *)(value + 0x2c);
}

/*
 * Decompiled function: FUN_0040b2c8
 * Entry Point: 0040b2c8
 * Size: 250 bytes
 */


undefined4 FUN_0040b2c8(int value)

{
  int iVar1;
  int iVar2;
  int arg_6;
  
  arg_6 = DAT_006498e4;
  iVar1 = *(int *)(value + 0x70);
  iVar2 = *(int *)(value + 0x14);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(value + 0x10),*(int *)(value + 0x14),
                    *(int *)(value + 0x18),*(int *)(value + 0x1c),DAT_00641878);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(value + 0x10),
                    (iVar2 + iVar1 / 2) - *(int *)(value + 0x70) / 2,*(int *)(value + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(value + 0x18)) / *(int *)(value + 8),
                    arg_6);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,*(uint *)(value + 0x10),*(int *)(value + 0x14),
               *(uint *)(value + 0x18),*(DWORD *)(value + 0x1c),(int *)g_DisplaySurfaceScreen,
               *(int *)(value + 0x10),*(int *)(value + 0x14));
  return 0;
}

/*
 * Decompiled function: FUN_0040b3c2
 * Entry Point: 0040b3c2
 * Size: 127 bytes
 */


void FUN_0040b3c2(undefined4 x,undefined4 y)

{
  if (DAT_0067bde0 < 0x100) {
    *(undefined4 *)(&DAT_0067a9a0 + DAT_0067bde0 * 0x10) = x;
    *(undefined4 *)(&DAT_0067a9a4 + DAT_0067bde0 * 0x10) = y;
    *(int *)(&DAT_0067a9a8 + DAT_0067bde0 * 0x10) =
         (int)(DAT_0052eff0 + (DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5;
    *(int *)(&DAT_0067a9ac + DAT_0067bde0 * 0x10) =
         (int)(DAT_0052eff4 + (DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5;
    DAT_0067bde0 = DAT_0067bde0 + 1;
  }
  return;
}

/*
 * Decompiled function: FUN_0040b441
 * Entry Point: 0040b441
 * Size: 167 bytes
 */


void FUN_0040b441(int *x,int y)

{
  int iVar1;
  int local_8;
  
  if ((g_DisplayScreenWidth != 0x280) && (x[4] == *x)) {
    for (local_8 = 0; local_8 < y; local_8 = local_8 + 1) {
      iVar1 = Ai_Util_004c3bc4(x[4]);
      x[4] = iVar1;
      iVar1 = Ai_Util_004c3bc4(x[5]);
      x[5] = iVar1;
      iVar1 = Ai_Util_004c3bc4(x[6]);
      x[6] = iVar1;
      iVar1 = Ai_Util_004c3bc4(x[7]);
      x[7] = iVar1;
      x = x + 0x15;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0040b4e8
 * Entry Point: 0040b4e8
 * Size: 771 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b4e8(void)

{
  int iVar1;
  int iVar2;
  int local_1c;
  
  Ai_CastleEncounter_004c24b3(4);
  Surface_BlitToDevice((int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
               (int *)g_DisplaySurfaceBackBuffer,0,0);
  DAT_005384e0 = 0xffffffff;
  DAT_005384dc = 0xffffffff;
  for (local_1c = 0; (local_1c < 10000 && (*(int *)(&DAT_0067a9a0 + local_1c * 0x10) != 0));
      local_1c = local_1c + 1) {
  }
  DAT_005384d8 = local_1c;
  _DAT_00517284 = local_1c;
  DAT_005384d4 = -1;
  FUN_0040b441((int *)&DAT_00517200,3);
  iVar1 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(iVar1);
  _DAT_005172e8 = 3;
  FUN_0041f17e(0x517200,3,iVar1);
  DAT_00680770 = 1;
  *(undefined4 *)g_DisplaySurfaceScreen = 1;
  FUN_0040ae70(0x517200,0);
  FUN_0040b2c8(0x517254);
  DAT_00680770 = 0;
  *(undefined4 *)g_DisplaySurfaceScreen = 0;
  Castle_Process_0040b7fa(0);
  do {
    Mem_AllocOrFree_005016f9();
    DAT_005384d0 = -1;
    while (DAT_005384d0 == -1) {
      iVar1 = Mem_AllocOrFree_00501721();
      iVar2 = Mem_AllocOrFree_00501721();
      if (iVar2 % 10 == 0 && iVar1 % 0x14 == 0) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,DAT_005384c8 + -2,DAT_005384cc + -2,5,5,0xff)
        ;
      }
      iVar1 = Mem_AllocOrFree_00501721();
      iVar2 = Mem_AllocOrFree_00501721();
      if ((iVar2 % 0x14 & (uint)(iVar1 % 10 == 0)) != 0) {
        Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,DAT_005384c8 - 2,DAT_005384cc + -2,5,5,
                     (int *)g_DisplaySurfaceScreen,DAT_005384c8,DAT_005384cc);
      }
      Pic_Subsystem_0044b84b();
      FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
      if ((DAT_005384d0 == -1) &&
         ((DAT_007039c4 != 0 || (iVar1 = Mem_AllocOrFree_0040810f(), iVar1 == 0)))) {
        iVar1 = FUN_004080b2();
        if (((DAT_007039c4 & 1) == 0) && (iVar1 != 0x5000)) {
          if (((DAT_007039c4 & 2) != 0) || (iVar1 == 0x4800)) {
            Castle_Process_0040b7fa(DAT_005384d4 + -1);
          }
        }
        else {
          Castle_Process_0040b7fa(DAT_005384d4 + 1);
        }
        App_ProcessPendingMessages();
      }
    }
  } while (DAT_005384d0 == 1);
  if (DAT_005384d0 == 4) {
    App_ProcessPendingMessages();
    FUN_0041f391();
    Mem_AllocOrFree_0050fc50(DAT_00641890);
  }
  return;
}

/*
 * Decompiled function: FUN_0040bcff
 * Entry Point: 0040bcff
 * Size: 1147 bytes
 */


void FUN_0040bcff(uint x,uint y)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (DAT_005384dc == -1) {
    DAT_005384dc = x;
    DAT_005384e0 = y;
    Ai_Subsystem_004c3aa1(x,y,(int *)&local_c,(int *)&local_14);
    local_c = (int)(local_c * g_DisplayScreenWidth) / 0x280;
    local_14 = (int)(local_14 * g_DisplayScreenHeight) / 0x1e0;
    iVar1 = Ai_Util_004c3bc4(0x40);
    local_14 = local_14 + iVar1;
  }
  else {
    Ai_Subsystem_004c3aa1(DAT_005384dc,DAT_005384e0,(int *)&local_8,(int *)&local_10);
    local_8 = (int)(local_8 * g_DisplayScreenWidth) / 0x280;
    local_10 = (int)(local_10 * g_DisplayScreenHeight) / 0x1e0;
    iVar1 = Ai_Util_004c3bc4(0x40);
    local_10 = local_10 + iVar1;
    Ai_Subsystem_004c3aa1(x,y,(int *)&local_c,(int *)&local_14);
    local_c = (int)(local_c * g_DisplayScreenWidth) / 0x280;
    local_14 = (int)(local_14 * g_DisplayScreenHeight) / 0x1e0;
    iVar1 = Ai_Util_004c3bc4(0x40);
    local_14 = local_14 + iVar1;
    DAT_005384dc = x;
    DAT_005384e0 = y;
    iVar1 = local_c - local_8;
    iVar4 = local_14 - local_10;
    x = local_8;
    y = local_10;
    iVar2 = abs(iVar4);
    iVar3 = abs(iVar1);
    if (iVar2 < iVar3) {
      while (local_c != x) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,x,y,2,2,0xff);
        FUN_00501736(5);
        if ((x & 1) == 0) {
          Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,x,y,2,2,(int *)g_DisplaySurfaceScreen
                       ,x,y);
        }
        else {
          Surface_FillRect((int *)g_DisplaySurfaceScreen,x,y,2,2,0);
        }
        iVar2 = FUN_0040a33c(iVar1);
        x = x + iVar2;
        iVar2 = abs(x - local_8);
        iVar3 = abs(iVar1);
        y = local_10 + (iVar2 * iVar4) / iVar3;
      }
    }
    else {
      while (local_14 != y) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,x,y,2,2,0xff);
        FUN_00501736(5);
        if ((y & 1) == 0) {
          Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,x,y,2,2,(int *)g_DisplaySurfaceScreen
                       ,x,y);
        }
        else {
          Surface_FillRect((int *)g_DisplaySurfaceScreen,x,y,2,2,0);
        }
        iVar2 = FUN_0040a33c(iVar4);
        y = y + iVar2;
        iVar2 = abs(y - local_10);
        iVar3 = abs(iVar4);
        x = local_8 + (iVar2 * iVar1) / iVar3;
      }
    }
  }
  DAT_005384c8 = local_c;
  DAT_005384cc = local_14;
  if (g_OverworldWorldState != '\0') {
    Math_Clamp(local_c - 0x50,0,0xa0);
    Math_Clamp(local_14 - 10,0,0xbf);
    iVar1 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
    iVar4 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    *(undefined4 *)(g_DisplaySurfaceWork + 0x20) = *(undefined4 *)(g_DisplaySurfaceScreen + 0x20);
    Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,(local_c - 2) - iVar1 / 2,local_14 - 2,iVar1 + 2,
                 iVar4 + 2,(int *)g_DisplaySurfaceWork,0,0xa0);
    Ai_Subsystem_004c2340((undefined4 *)g_DisplaySurfaceWork,0,0xa0,iVar1 + 2,iVar4 + 2,0x3f3f3f,1);
    FUN_0040d269((int)g_DisplaySurfaceWork,0xff,iVar1 / 2 + 1,iVar4 / 2 + 0xa1);
    Surface_BlitToDevice((int *)g_DisplaySurfaceWork,0,0xa0,iVar1 + 2,iVar4 + 2,
                 (int *)g_DisplaySurfaceScreen,(local_c - 2) - iVar1 / 2,local_14 - 2);
  }
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040c180
 * Entry Point: 0040c180
 * Size: 45 bytes
 */


void Mem_AllocOrFree_0040c180(int value,int min_val,int max_val,int target_slot,int flags)

{
  Surface_DrawLine((int *)g_DisplaySurfaceScreen,value,min_val,max_val,target_slot,flags);
  return;
}

/*
 * Decompiled function: FUN_0040c1ad
 * Entry Point: 0040c1ad
 * Size: 199 bytes
 */


void FUN_0040c1ad(char *value,int y,int width,undefined4 target_slot)

{
  int iVar1;
  int iVar2;
  
  if (y < 0) {
    y = 0;
  }
  if (width < 0) {
    width = 0;
  }
  iVar1 = FUN_0040c465(value);
  if (g_DisplayScreenWidth <= y + iVar1) {
    iVar2 = g_DisplayScreenWidth + -1;
    iVar1 = FUN_0040c465(value);
    y = iVar2 - iVar1;
  }
  iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  if (g_DisplayScreenHeight <= width + iVar1) {
    iVar2 = g_DisplayScreenHeight + -1;
    iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    width = iVar2 - iVar1;
  }
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x18) = target_slot;
  FUN_0050f820((int *)g_DisplaySurfaceScreen,y,width,value);
  return;
}

/*
 * Decompiled function: FUN_0040c274
 * Entry Point: 0040c274
 * Size: 59 bytes
 */


void FUN_0040c274(undefined4 value,int y,int width,undefined4 target_slot)

{
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x14) = 0;
  FUN_0040c1ad(value,y,width,target_slot);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x14) = 1;
  return;
}

/*
 * Decompiled function: FUN_0040c2af
 * Entry Point: 0040c2af
 * Size: 58 bytes
 */


void FUN_0040c2af(undefined4 value,int y,int width,undefined4 target_slot)

{
  FUN_0040c274(value,y,width + 1,0);
  FUN_0040c274(value,y,width,target_slot);
  return;
}

/*
 * Decompiled function: FUN_0040c2e9
 * Entry Point: 0040c2e9
 * Size: 77 bytes
 */


void FUN_0040c2e9(undefined4 value,int y,int width,undefined4 target_slot)

{
  FUN_0040c3cc(value,(y * g_DisplayScreenWidth) / 0x140,(width * g_DisplayScreenHeight) / 0xf0,target_slot);
  return;
}

/*
 * Decompiled function: FUN_0040c336
 * Entry Point: 0040c336
 * Size: 75 bytes
 */


void FUN_0040c336(undefined4 value,int y,int width,int target_slot)

{
  FUN_0040c421(value,(g_DisplayScreenWidth * y) / 0x140,(g_DisplayScreenHeight * width) / 0xf0,target_slot);
  return;
}

/*
 * Decompiled function: FUN_0040c381
 * Entry Point: 0040c381
 * Size: 75 bytes
 */


void FUN_0040c381(undefined4 value,int y,int width,undefined4 target_slot)

{
  FUN_0040c274(value,(g_DisplayScreenWidth * y) / 0x140,(g_DisplayScreenHeight * width) / 0xf0,target_slot);
  return;
}

/*
 * Decompiled function: FUN_0040c3cc
 * Entry Point: 0040c3cc
 * Size: 85 bytes
 */


void FUN_0040c3cc(char *value,int y,int width,undefined4 target_slot)

{
  int iVar1;
  
  iVar1 = FUN_0040c465(value);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x14) = 0;
  FUN_0040c1ad(value,y - iVar1 / 2,width,target_slot);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x14) = 1;
  return;
}

/*
 * Decompiled function: FUN_0040c421
 * Entry Point: 0040c421
 * Size: 68 bytes
 */


void FUN_0040c421(undefined4 value,int y,int width,int height)

{
  if (height != 0) {
    FUN_0040c3cc(value,y,width + 1,0);
  }
  FUN_0040c3cc(value,y,width,height);
  return;
}

/*
 * Decompiled function: FUN_0040c465
 * Entry Point: 0040c465
 * Size: 96 bytes
 */


int FUN_0040c465(char *str_1)

{
  int x;
  int iVar1;
  int local_10;
  char *local_c;
  
  local_c = str_1;
  x = *(int *)(g_DisplaySurfaceScreen + 0x20);
  local_10 = 0;
  while (*local_c != '\0') {
    iVar1 = FUN_0050f390(x,*local_c);
    local_10 = local_10 + iVar1;
    local_c = local_c + 1;
  }
  return local_10;
}

/*
 * Decompiled function: FUN_0040c4c5
 * Entry Point: 0040c4c5
 * Size: 139 bytes
 */


void FUN_0040c4c5(int *value,int min_val,int max_val,int target_slot,int flags,int *arg_6,int arg_7,int arg_8)

{
  Surface_BlitToDevice(value,(min_val * g_DisplayScreenWidth) / 0x140,(max_val * g_DisplayScreenHeight) / 0xf0,
               (target_slot * g_DisplayScreenWidth) / 0x140,(flags * g_DisplayScreenHeight) / 0xf0,arg_6,
               (g_DisplayScreenWidth * arg_7) / 0x140,(g_DisplayScreenHeight * arg_8) / 0xf0);
  return;
}

/*
 * Decompiled function: FUN_0040c550
 * Entry Point: 0040c550
 * Size: 137 bytes
 */


void FUN_0040c550(int *value,int min_val,int max_val,int target_slot,int flags,int *arg_6,int arg_7,int arg_8)

{
  Surface_BlitToDevice(value,(g_DisplayScreenWidth * min_val) / 0x140,(g_DisplayScreenHeight * max_val) / 0xf0,
               (g_DisplayScreenWidth * target_slot) / 0x140,(g_DisplayScreenHeight * flags) / 0xf0,arg_6,
               (arg_7 * g_DisplayScreenWidth) / 0x140,(arg_8 * g_DisplayScreenHeight) / 0xf0);
  return;
}

/*
 * Decompiled function: FUN_0040c5d9
 * Entry Point: 0040c5d9
 * Size: 137 bytes
 */


void FUN_0040c5d9(int *value,int min_val,int max_val,int target_slot,int flags,int *arg_6,int arg_7,int arg_8)

{
  FUN_0050e040(value,(min_val * g_DisplayScreenWidth) / 0x140,(max_val * g_DisplayScreenHeight) / 0xf0,
               (g_DisplayScreenWidth * target_slot) / 0x140,(g_DisplayScreenHeight * flags) / 0xf0,arg_6,
               (g_DisplayScreenWidth * arg_7) / 0x140,(g_DisplayScreenHeight * arg_8) / 0xf0);
  return;
}

/*
 * Decompiled function: FUN_0040c662
 * Entry Point: 0040c662
 * Size: 101 bytes
 */


void FUN_0040c662(int *value,int min_val,int max_val,int target_slot,int flags,uint arg_6)

{
  Surface_FillRect(value,(g_DisplayScreenWidth * min_val) / 0x140,(g_DisplayScreenHeight * max_val) / 0xf0,
                   (target_slot * g_DisplayScreenWidth) / 0x140,(flags * g_DisplayScreenHeight) / 0xf0,arg_6);
  return;
}

/*
 * Decompiled function: FUN_0040c6c7
 * Entry Point: 0040c6c7
 * Size: 101 bytes
 */


void FUN_0040c6c7(int *value,int min_val,int max_val,int target_slot,int flags,int arg_6)

{
  Sprite_DrawScaled(value,(min_val * g_DisplayScreenWidth) / 0x140,(max_val * g_DisplayScreenHeight) / 0xf0,
                    (g_DisplayScreenWidth * target_slot) / 0x140,(g_DisplayScreenHeight * flags) / 0xf0,arg_6);
  return;
}

/*
 * Decompiled function: FUN_0040c72c
 * Entry Point: 0040c72c
 * Size: 53 bytes
 */


void FUN_0040c72c(int value,int min_val,int max_val,int target_slot,uint flags)

{
  Surface_FillRect((int *)g_DisplaySurfaceScreen,value,min_val,(max_val - value) + 1,(target_slot - min_val) + 1
                   ,flags);
  return;
}

/*
 * Decompiled function: Surface_GetPixelColor
 * Entry Point: 0040c761
 * Size: 95 bytes
 */


uint Surface_GetPixelColor(int x,int y)

{
  uint uVar1;
  
  if ((0x3f < x) || (x < 0)) {
    x = 0;
  }
  if ((0x3f < y) || (y < 0)) {
    y = 0;
  }
  uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,x,y);
  return uVar1 & 0xf;
}

/*
 * Decompiled function: FUN_0040c7c0
 * Entry Point: 0040c7c0
 * Size: 92 bytes
 */


undefined4 FUN_0040c7c0(int x,int y)

{
  undefined4 uVar1;
  
  if ((x < 0x40) && (-1 < x)) {
    if ((y < 0x40) && (-1 < y)) {
      uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,x,y);
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0040c81c
 * Entry Point: 0040c81c
 * Size: 109 bytes
 */


void FUN_0040c81c(uint value,int min_val,int max_val)

{
  uint uVar1;
  
  if ((((min_val < 0x40) && (-1 < min_val)) && (max_val < 0x40)) && (-1 < max_val)) {
    uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,min_val,max_val);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,min_val,max_val,uVar1 | value);
  }
  return;
}

/*
 * Decompiled function: FUN_0040c889
 * Entry Point: 0040c889
 * Size: 113 bytes
 */


void FUN_0040c889(uint value,int min_val,int max_val)

{
  uint uVar1;
  
  if ((((min_val < 0x40) && (-1 < min_val)) && (max_val < 0x40)) && (-1 < max_val)) {
    uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,min_val,max_val);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,min_val,max_val,uVar1 & ~value);
  }
  return;
}

/*
 * Decompiled function: FUN_0040c8fa
 * Entry Point: 0040c8fa
 * Size: 95 bytes
 */


undefined4 FUN_0040c8fa(int x,int y)

{
  undefined4 uVar1;
  
  if ((x < 0x40) && (-1 < x)) {
    if ((y < 0x40) && (-1 < y)) {
      uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,x + 0x40,y);
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0040c959
 * Entry Point: 0040c959
 * Size: 115 bytes
 */


void FUN_0040c959(uint value,int min_val,int max_val)

{
  uint uVar1;
  
  if ((((min_val < 0x40) && (-1 < min_val)) && (max_val < 0x40)) && (-1 < max_val)) {
    uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,min_val + 0x40,max_val);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,min_val + 0x40,max_val,uVar1 | value);
  }
  return;
}

/*
 * Decompiled function: FUN_0040c9cc
 * Entry Point: 0040c9cc
 * Size: 119 bytes
 */


void FUN_0040c9cc(uint value,int min_val,int max_val)

{
  uint uVar1;
  
  if ((((min_val < 0x40) && (-1 < min_val)) && (max_val < 0x40)) && (-1 < max_val)) {
    uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,min_val + 0x40,max_val);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,min_val + 0x40,max_val,uVar1 & ~value);
  }
  return;
}

/*
 * Decompiled function: FUN_0040ca43
 * Entry Point: 0040ca43
 * Size: 268 bytes
 */


void FUN_0040ca43(int value,int min_val,int max_val)

{
  int arg_2_00;
  int arg_3_00;
  uint uVar1;
  
  if ((((value < 0x40) && (-1 < value)) && (min_val < 0x40)) && (-1 < min_val)) {
    uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,value,min_val + 0x40);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,value,min_val + 0x40,
                     uVar1 | 1 << ((char)max_val - 1U & 0x1f));
    FUN_0040c81c(0x20,value,min_val);
    arg_2_00 = value + *(int *)(&DAT_00522378 + max_val * 4);
    arg_3_00 = min_val + *(int *)(&DAT_005223e0 + max_val * 4);
    uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_2_00,arg_3_00 + 0x40);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,arg_2_00,arg_3_00 + 0x40,
                     uVar1 | 1 << ((char)max_val + 3U & 7));
    FUN_0040c81c(0x20,arg_2_00,arg_3_00);
  }
  return;
}

/*
 * Decompiled function: FUN_0040cb4f
 * Entry Point: 0040cb4f
 * Size: 110 bytes
 */


uint FUN_0040cb4f(int value,int min_val,char max_val)

{
  uint uVar1;
  
  if ((value < 0x40) && (-1 < value)) {
    if ((min_val < 0x40) && (-1 < min_val)) {
      uVar1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,value,min_val + 0x40);
      uVar1 = uVar1 & 1 << (max_val - 1U & 0x1f);
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0040cbbd
 * Entry Point: 0040cbbd
 * Size: 75 bytes
 */


undefined4 FUN_0040cbbd(int x,int y)

{
  undefined4 uVar1;
  
  if ((x < 0) || (0x3f < x)) {
    uVar1 = 0;
  }
  else if ((y < 0) || (0x3f < y)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0040cc08
 * Entry Point: 0040cc08
 * Size: 118 bytes
 */


int FUN_0040cc08(char *str_1)

{
  char *pcVar1;
  char cVar2;
  int local_8;
  
  local_8 = 0;
  if (str_1 == (char *)0x0) {
    local_8 = 0;
  }
  else {
    while (*str_1 != '\0') {
      pcVar1 = str_1 + 1;
      cVar2 = *str_1;
      str_1 = pcVar1;
      if (cVar2 == '\n') {
        local_8 = local_8 + 1;
      }
    }
    if (str_1[-1] != '\n') {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}

/*
 * Decompiled function: Font_DrawFormattedText
 * Entry Point: 0040cc7e
 * Size: 551 bytes
 */


int Font_DrawFormattedText(int value,int min_val,int max_val,int target_slot,int flags,int arg_6,int arg_7,int arg_8,
                undefined4 *arg_9)

{
  int iVar1;
  int iVar2;
  undefined4 local_41c;
  int local_418;
  int local_414;
  char *local_410;
  char local_40c [1024];
  char *local_c;
  va_list local_8;
  
  local_8 = (va_list)(arg_9 + 1);
  iVar1 = _vsnprintf(local_40c,0x400,(char *)*arg_9,local_8);
  local_418 = FUN_0040cc08(local_40c);
  if (target_slot != 0) {
    arg_7 = (arg_7 * g_DisplayScreenWidth) / 0x280;
    arg_8 = (g_DisplayScreenHeight * arg_8) / 0x1e0;
  }
  if (arg_6 != 0) {
    iVar2 = Mem_AllocOrFree_0050f740(*(int *)(value + 0x20));
    arg_8 = arg_8 - (iVar2 * local_418) / 2;
  }
  if (-1 < min_val) {
    local_41c = *(undefined4 *)(value + 0x18);
    *(int *)(value + 0x18) = min_val;
  }
  local_410 = local_40c;
  local_c = local_410;
  while( true ) {
    if (local_418 == 0) break;
    for (; (*local_410 != '\0' && (*local_410 != '\n')); local_410 = local_410 + 1) {
    }
    *local_410 = '\0';
    if (flags == 0) {
      local_414 = arg_7;
    }
    else {
      iVar2 = FUN_0050f440((int *)value,local_c);
      local_414 = arg_7 - iVar2 / 2;
    }
    if (max_val != 0) {
      local_41c = *(undefined4 *)(value + 0x18);
      *(undefined4 *)(value + 0x18) = 0;
      FUN_0050f820((int *)value,local_414 + 1,arg_8 + 1,local_c);
      *(undefined4 *)(value + 0x18) = local_41c;
    }
    FUN_0050f820((int *)value,local_414,arg_8,local_c);
    *local_410 = '\n';
    local_410 = local_410 + 1;
    local_c = local_410;
    iVar2 = Mem_AllocOrFree_0050f740(*(int *)(value + 0x20));
    arg_8 = arg_8 + iVar2;
    local_418 = local_418 + -1;
  }
  if (-1 < min_val) {
    *(undefined4 *)(value + 0x18) = local_41c;
  }
  return iVar1;
}

/*
 * Decompiled function: FUN_0040cea5
 * Entry Point: 0040cea5
 * Size: 50 bytes
 */


void FUN_0040cea5(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,0,0,0,0,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040ced7
 * Entry Point: 0040ced7
 * Size: 50 bytes
 */


void FUN_0040ced7(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,0,0,1,0,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040cf09
 * Entry Point: 0040cf09
 * Size: 50 bytes
 */


void FUN_0040cf09(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,0,0,0,1,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040cf3b
 * Entry Point: 0040cf3b
 * Size: 50 bytes
 */


void FUN_0040cf3b(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,0,0,1,1,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040cf6d
 * Entry Point: 0040cf6d
 * Size: 52 bytes
 */


void FUN_0040cf6d(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,0,0,0,0,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040cfa1
 * Entry Point: 0040cfa1
 * Size: 52 bytes
 */


void FUN_0040cfa1(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,0,0,1,0,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040cfd5
 * Entry Point: 0040cfd5
 * Size: 52 bytes
 */


void FUN_0040cfd5(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,0,0,0,1,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d009
 * Entry Point: 0040d009
 * Size: 52 bytes
 */


void FUN_0040d009(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,0,0,1,1,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d03d
 * Entry Point: 0040d03d
 * Size: 50 bytes
 */


void FUN_0040d03d(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,1,0,0,0,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d06f
 * Entry Point: 0040d06f
 * Size: 50 bytes
 */


void FUN_0040d06f(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,1,0,1,0,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d0a1
 * Entry Point: 0040d0a1
 * Size: 50 bytes
 */


void FUN_0040d0a1(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,1,0,0,1,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d0d3
 * Entry Point: 0040d0d3
 * Size: 50 bytes
 */


void FUN_0040d0d3(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,1,0,1,1,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d105
 * Entry Point: 0040d105
 * Size: 50 bytes
 */


void FUN_0040d105(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,0,1,0,0,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d137
 * Entry Point: 0040d137
 * Size: 50 bytes
 */


void FUN_0040d137(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,0,1,1,0,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d169
 * Entry Point: 0040d169
 * Size: 50 bytes
 */


void FUN_0040d169(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,0,1,0,1,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d19b
 * Entry Point: 0040d19b
 * Size: 50 bytes
 */


void FUN_0040d19b(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,0,1,1,1,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d1cd
 * Entry Point: 0040d1cd
 * Size: 52 bytes
 */


void FUN_0040d1cd(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,1,0,0,0,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d201
 * Entry Point: 0040d201
 * Size: 52 bytes
 */


void FUN_0040d201(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,1,0,1,0,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d235
 * Entry Point: 0040d235
 * Size: 52 bytes
 */


void FUN_0040d235(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,1,0,0,1,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d269
 * Entry Point: 0040d269
 * Size: 52 bytes
 */


void FUN_0040d269(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,1,0,1,1,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d29d
 * Entry Point: 0040d29d
 * Size: 52 bytes
 */


void FUN_0040d29d(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,0,1,0,0,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d2d1
 * Entry Point: 0040d2d1
 * Size: 52 bytes
 */


void FUN_0040d2d1(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,0,1,1,0,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d305
 * Entry Point: 0040d305
 * Size: 52 bytes
 */


void FUN_0040d305(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,0,1,0,1,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d339
 * Entry Point: 0040d339
 * Size: 52 bytes
 */


void FUN_0040d339(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,0,1,1,1,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d36d
 * Entry Point: 0040d36d
 * Size: 50 bytes
 */


void FUN_0040d36d(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,1,1,0,0,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d39f
 * Entry Point: 0040d39f
 * Size: 50 bytes
 */


void FUN_0040d39f(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,1,1,1,0,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d3d1
 * Entry Point: 0040d3d1
 * Size: 50 bytes
 */


void FUN_0040d3d1(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,1,1,0,1,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d403
 * Entry Point: 0040d403
 * Size: 50 bytes
 */


void FUN_0040d403(int value,int min_val,int max_val)

{
  Font_DrawFormattedText(value,-1,1,1,1,1,min_val,max_val,(undefined4 *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d435
 * Entry Point: 0040d435
 * Size: 52 bytes
 */


void FUN_0040d435(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,1,1,0,0,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d469
 * Entry Point: 0040d469
 * Size: 52 bytes
 */


void FUN_0040d469(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,1,1,1,0,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d49d
 * Entry Point: 0040d49d
 * Size: 52 bytes
 */


void FUN_0040d49d(int x,int y,int width,int height)

{
  Font_DrawFormattedText(x,y,1,1,0,1,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: Font_DrawTextInRect
 * Entry Point: 0040d4d1
 * Size: 52 bytes
 */


void Font_DrawTextInRect(int x, int y, int width, int height)

{
  Font_DrawFormattedText(x,y,1,1,1,1,width,height,(undefined4 *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d510
 * Entry Point: 0040d510
 * Size: 66 bytes
 */


undefined4 FUN_0040d510(int value,int min_val,int max_val)

{
  *(int *)(&DAT_0063ee30 + min_val * 4 + value * 0x20) =
       *(int *)(&DAT_0063ee30 + min_val * 4 + value * 0x20) + max_val;
  *(int *)(&DAT_0063ee4c + value * 0x20) = *(int *)(&DAT_0063ee4c + value * 0x20) + max_val;
  return *(undefined4 *)(&DAT_0063ee30 + min_val * 4 + value * 0x20);
}

/*
 * Decompiled function: FUN_0040d552
 * Entry Point: 0040d552
 * Size: 74 bytes
 */


undefined4 FUN_0040d552(int value,int min_val,int max_val)

{
  *(int *)(&DAT_0063ee30 + min_val * 4 + value * 0x20) =
       *(int *)(&DAT_0063ee30 + min_val * 4 + value * 0x20) - max_val;
  *(int *)(&DAT_0063ee4c + value * 0x20) = *(int *)(&DAT_0063ee4c + value * 0x20) - max_val;
  return *(undefined4 *)(&DAT_0063ee30 + min_val * 4 + value * 0x20);
}

/*
 * Decompiled function: FUN_0040d59c
 * Entry Point: 0040d59c
 * Size: 176 bytes
 */


void FUN_0040d59c(int value,uint min_val,int max_val)

{
  bool bVar1;
  int local_c;
  
  if (0 < (int)min_val) {
    bVar1 = false;
    local_c = 0;
    while ((local_c < 0x32 && (!bVar1))) {
      if (*(int *)(&DAT_00627870 + local_c * 4 + value * 0xcc) == -1) {
        bVar1 = true;
        *(uint *)(&DAT_00627870 + local_c * 4 + value * 0xcc) = max_val << 0x10 | min_val;
        *(undefined4 *)(&DAT_00627874 + local_c * 4 + value * 0xcc) = 0xffffffff;
      }
      local_c = local_c + 1;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0040d64c
 * Entry Point: 0040d64c
 * Size: 223 bytes
 */


void FUN_0040d64c(int value,uint min_val,int max_val)

{
  bool bVar1;
  int local_10;
  int local_c;
  
  bVar1 = false;
  local_c = 0;
  while (((local_c < 0x32 && (*(int *)(&DAT_00627870 + local_c * 4 + value * 0xcc) != -1)) &&
         (!bVar1))) {
    if (*(uint *)(&DAT_00627870 + local_c * 4 + value * 0xcc) == (max_val << 0x10 | min_val)) {
      bVar1 = true;
      for (local_10 = local_c; local_10 < 0x31; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_00627870 + local_10 * 4 + value * 0xcc) =
             *(undefined4 *)(&DAT_00627874 + local_10 * 4 + value * 0xcc);
      }
    }
    local_c = local_c + 1;
  }
  return;
}

/*
 * Decompiled function: FUN_0040d72b
 * Entry Point: 0040d72b
 * Size: 190 bytes
 */


void FUN_0040d72b(int value,uint min_val,int max_val)

{
  bool bVar1;
  int local_c;
  
  if ((0 < (int)min_val) && (0 < max_val)) {
    bVar1 = false;
    local_c = 0;
    while ((local_c < 10 && (!bVar1))) {
      if (*(int *)(&DAT_00627a20 + local_c * 4 + value * 0x2c) == -1) {
        bVar1 = true;
        *(uint *)(&DAT_00627a20 + local_c * 4 + value * 0x2c) = max_val << 0x10 | min_val & 0xffff;
        *(undefined4 *)(&DAT_00627a24 + local_c * 4 + value * 0x2c) = 0xffffffff;
      }
      local_c = local_c + 1;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0040d7e9
 * Entry Point: 0040d7e9
 * Size: 66 bytes
 */


undefined4 FUN_0040d7e9(int value,int min_val,int max_val)

{
  *(int *)(&DAT_0063edd0 + min_val * 4 + value * 0x20) =
       *(int *)(&DAT_0063edd0 + min_val * 4 + value * 0x20) + max_val;
  *(int *)(&DAT_0063edec + value * 0x20) = *(int *)(&DAT_0063edec + value * 0x20) + max_val;
  return *(undefined4 *)(&DAT_0063edd0 + min_val * 4 + value * 0x20);
}

/*
 * Decompiled function: FUN_0040d82b
 * Entry Point: 0040d82b
 * Size: 74 bytes
 */


undefined4 FUN_0040d82b(int value,int min_val,int max_val)

{
  *(int *)(&DAT_0063edd0 + min_val * 4 + value * 0x20) =
       *(int *)(&DAT_0063edd0 + min_val * 4 + value * 0x20) - max_val;
  *(int *)(&DAT_0063edec + value * 0x20) = *(int *)(&DAT_0063edec + value * 0x20) - max_val;
  return *(undefined4 *)(&DAT_0063edd0 + min_val * 4 + value * 0x20);
}

/*
 * Decompiled function: FUN_0040d875
 * Entry Point: 0040d875
 * Size: 66 bytes
 */


undefined4 FUN_0040d875(int value,int min_val,int max_val)

{
  *(int *)(&DAT_0063ee90 + min_val * 4 + value * 0x20) =
       *(int *)(&DAT_0063ee90 + min_val * 4 + value * 0x20) + max_val;
  *(int *)(&DAT_0063eeac + value * 0x20) = *(int *)(&DAT_0063eeac + value * 0x20) + max_val;
  return *(undefined4 *)(&DAT_0063ee90 + min_val * 4 + value * 0x20);
}

/*
 * Decompiled function: FUN_0040d8b7
 * Entry Point: 0040d8b7
 * Size: 74 bytes
 */


undefined4 FUN_0040d8b7(int value,int min_val,int max_val)

{
  *(int *)(&DAT_0063ee90 + min_val * 4 + value * 0x20) =
       *(int *)(&DAT_0063ee90 + min_val * 4 + value * 0x20) - max_val;
  *(int *)(&DAT_0063eeac + value * 0x20) = *(int *)(&DAT_0063eeac + value * 0x20) - max_val;
  return *(undefined4 *)(&DAT_0063ee90 + min_val * 4 + value * 0x20);
}

/*
 * Decompiled function: FUN_0040d901
 * Entry Point: 0040d901
 * Size: 72 bytes
 */


undefined4 FUN_0040d901(int value,int min_val,int max_val)

{
  FUN_0040d82b(value,min_val,max_val);
  FUN_0040d875(value,min_val,max_val);
  return *(undefined4 *)(&DAT_0063ee90 + min_val * 4 + value * 0x20);
}

/*
 * Decompiled function: Font_DrawString
 * Entry Point: 0040d949
 * Size: 892 bytes
 */


int Font_DrawString(int value, uint min_val, int max_val)

{
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_1c;
  int local_10;
  byte local_8;
  
  if (min_val == 6) {
    local_28 = 7;
  }
  else if (min_val == 0) {
    local_28 = 7;
  }
  else {
    local_28 = min_val;
  }
  if (max_val == 0) {
    local_34 = 1;
  }
  else {
    local_2c = 0;
    local_24 = 0;
    while (((int)local_24 < 10 && (*(int *)(&DAT_00627a20 + local_24 * 4 + value * 0x2c) != -1))) {
      if (local_28 == *(uint *)(&DAT_00627a20 + local_24 * 4 + value * 0x2c) >> 0x10) {
        local_8 = (byte)*(undefined2 *)(&DAT_00627a20 + local_24 * 4 + value * 0x2c);
        local_2c = local_2c | 1 << (local_8 & 0x1f);
      }
      local_24 = local_24 + 1;
    }
    local_30 = *(int *)(&DAT_0063ee90 + local_28 * 4 + value * 0x20);
    for (local_24 = 0; (int)local_24 < 7; local_24 = local_24 + 1) {
      if ((local_24 != local_28) && ((local_2c & 1 << ((byte)local_24 & 0x1f)) != 0)) {
        local_30 = local_30 + *(int *)(&DAT_0063ee90 + local_24 * 4 + value * 0x20);
      }
    }
    local_1c = *(int *)(&DAT_0063edd0 + local_28 * 4 + value * 0x20);
    if (((value == g_ActivePlayerPriority) || (DAT_006fedc0 != 0)) || (g_IsAiThinking == 1)) {
      for (local_24 = 0; (int)local_24 < 7; local_24 = local_24 + 1) {
        if ((local_24 != local_28) && ((local_2c & 1 << ((byte)local_24 & 0x1f)) != 0)) {
          local_1c = local_1c + *(int *)(&DAT_0063edd0 + local_24 * 4 + value * 0x20);
        }
      }
    }
    local_10 = 0;
    local_24 = 0;
    while (((int)local_24 < 0x32 && (*(int *)(&DAT_00627870 + local_24 * 4 + value * 0xcc) != -1)))
    {
      if (local_28 == 7) {
        local_10 = local_10 + (*(int *)(&DAT_00627870 + local_24 * 4 + value * 0xcc) >> 0x10);
      }
      else if ((*(uint *)(&DAT_00627870 + local_24 * 4 + value * 0xcc) &
               1 << ((byte)local_28 & 0x1f)) == 0) {
        if ((((value == g_ActivePlayerPriority) || (DAT_006fedc0 != 0)) || (g_IsAiThinking == 1)) &&
           ((local_2c & *(uint *)(&DAT_00627870 + local_24 * 4 + value * 0xcc)) != 0)) {
          local_10 = local_10 + (*(int *)(&DAT_00627870 + local_24 * 4 + value * 0xcc) >> 0x10);
        }
      }
      else {
        local_10 = local_10 + (*(int *)(&DAT_00627870 + local_24 * 4 + value * 0xcc) >> 0x10);
      }
      local_24 = local_24 + 1;
    }
    if ((min_val == 7) || (min_val == 0)) {
      local_34 = (((local_30 - *(int *)(&DAT_0063eea8 + value * 0x20)) + local_1c) -
                 *(int *)(&DAT_0063ede8 + value * 0x20)) + local_10;
    }
    else {
      local_34 = local_1c + local_10 + local_30;
    }
    if (local_34 < max_val) {
      local_34 = 0;
    }
  }
  return local_34;
}

/*
 * Decompiled function: FUN_0040dcca
 * Entry Point: 0040dcca
 * Size: 338 bytes
 */


int FUN_0040dcca(int x,int y,uint width,int height)

{
  int iVar1;
  int iVar2;
  
  if (height == 0) {
    iVar1 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
    if (*(int *)(&DAT_006330d0 + iVar1 * 4) < 1) {
      iVar1 = 1;
    }
    else {
      iVar1 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
      iVar1 = Font_DrawString(x,7,*(int *)(&DAT_006330d0 + iVar1 * 4));
    }
  }
  else {
    iVar1 = Font_DrawString(x,width,height);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar2 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
      if (0 < *(int *)(&DAT_006330d0 + iVar2 * 4)) {
        iVar1 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[y * 0x120 + x * 0x5b20]);
        iVar1 = Font_DrawString(x,7,*(int *)(&DAT_006330d0 + iVar1 * 4) + height);
      }
    }
  }
  return iVar1;
}

/*
 * Decompiled function: FUN_0040eab1
 * Entry Point: 0040eab1
 * Size: 83 bytes
 */


int FUN_0040eab1(void)

{
  int value;
  int iVar1;
  
  do {
    do {
      value = Math_RandomRange(g_MasterCardCount + -0x29);
      iVar1 = Pic_Subsystem_00452551(value);
    } while (iVar1 < 3);
    iVar1 = FUN_00485005(value);
  } while (iVar1 == 0);
  return value;
}

/*
 * Decompiled function: FUN_0040eb04
 * Entry Point: 0040eb04
 * Size: 86 bytes
 */


void FUN_0040eb04(int value)

{
  char cVar1;
  size_t sVar2;
  int local_10;
  
  local_10 = 0;
  sVar2 = strlen(&g_OverworldWorldState);
  do {
    cVar1 = (&PTR_s_Restless_Graveyard_005174e8)[value][local_10];
    (&g_OverworldWorldState)[local_10 + sVar2] = cVar1;
    local_10 = local_10 + 1;
  } while (cVar1 != '\0');
  return;
}

/*
 * Decompiled function: Pic_Load_winbak01_0040eb5a
 * Entry Point: 0040eb5a
 * Size: 835 bytes
 */


void Pic_Load_winbak01_0040eb5a(int x,int y)

{
  uint value;
  int iVar1;
  undefined4 min_val;
  int iVar2;
  int target_slot;
  char *str_5;
  uint auStack_20 [5];
  int local_c;
  LPVOID local_8;
  
  for (local_c = 0; local_c < y; local_c = local_c + 1) {
    do {
      do {
        value = Math_RandomRange(g_MasterCardCount + -0x29);
        iVar1 = Pic_Subsystem_00452551(value);
      } while (iVar1 < 3);
      iVar1 = FUN_00485005(value);
    } while (iVar1 == 0);
    auStack_20[local_c] = value;
    FUN_0050b206(value,(int)(0x96 / (longlong)y) * local_c + 100,
                 (int)(10 / (longlong)y) * local_c + 100,1,&DAT_00519184);
  }
  local_8 = (LPVOID)Glue_Subsystem_004ea97c(0,x);
  strcpy(&g_OverworldWorldState,s_You_encounter_00519188);
  Glue_Subsystem_004eaa19((int)local_8,1,0);
  if (x == 0xd) {
    strcat(&g_OverworldWorldState,s_Genie_00519198);
  }
  else if (x == 0x10) {
    strcat(&g_OverworldWorldState,s_Spectre_005191a0);
  }
  else if (x == 0x12) {
    strcat(&g_OverworldWorldState,s_Dragon_005191ac);
  }
  else {
    strcat(&g_OverworldWorldState,s_warily_005191b4);
  }
  strcat(&g_OverworldWorldState,s_guarding_a_horde_of_valuable_spe_005191bc);
  iVar1 = FUN_00489710(&g_OverworldWorldState,0x5a,100);
  if (iVar1 == 1) {
    min_val = Pic_Subsystem_0045268f(*(int *)(&DAT_0052262c + (int)local_8 * 0x44));
    FUN_004909d3((int)local_8,min_val,0,-1);
    DAT_006b2d64 = Card_ColorMaskToColorIndex((&DAT_0052262b)[(int)local_8 * 0x44]);
    DAT_0063ee24 = 0;
    DAT_00695df0 = 3;
    iVar1 = Pic_Load_0044ef70(min_val,local_8);
    if (iVar1 != 0) {
      Mem_AllocOrFree_00510de0(1,s_winbak01_pic_00519214);
      Glue_Subsystem_004ebfef(1);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
      for (local_c = 0; local_c < y; local_c = local_c + 1) {
        iVar1 = (int)(300 / (longlong)(y + 1));
        iVar2 = Pic_Subsystem_00452551(auStack_20[local_c]);
        strcpy(&g_OverworldWorldState,(char *)(&DAT_0052b73c)[iVar2]);
        str_5 = &g_OverworldWorldState;
        target_slot = 1;
        iVar2 = Math_RandomRange(10);
        FUN_0050b206(auStack_20[local_c],(iVar1 * local_c + 0x6f) - ((y + -1) * iVar1) / 2,
                     iVar2 + 0x10,target_slot,str_5);
        local_8 = (LPVOID)Pic_Subsystem_00451e40(auStack_20[local_c]);
        if (local_8 != (LPVOID)0xffffffff) {
          *(uint *)(&deck + (int)local_8 * 4) = *(uint *)(&deck + (int)local_8 * 4) | 0x4000;
        }
      }
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
      FUN_004896be(s_Won_These_Cards_00519224,0x40,0x96);
    }
    StopSnd(0x10);
  }
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040eea2
 * Entry Point: 0040eea2
 * Size: 18 bytes
 */


undefined4 Mem_AllocOrFree_0040eea2(void)

{
  return 0;
}

/*
 * Decompiled function: FUN_0040eeb4
 * Entry Point: 0040eeb4
 * Size: 1632 bytes
 */


undefined4 FUN_0040eeb4(int x,int y)

{
  bool bVar1;
  undefined *puVar2;
  byte value;
  undefined4 arg_1_00;
  uint arg_1_01;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint local_30;
  int local_28;
  int local_24;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  puVar2 = PTR_FUN_00527b3c;
  local_14 = 1;
  PTR_FUN_00527b3c = Mem_AllocOrFree_0040eea2;
LAB_0040eed6:
  if (y == -1) {
    local_30 = Palette_Color_0049716e(s_Which_card_do_you_seek__00519250,0,0xffffffff,local_14,1);
  }
  else {
    local_30 = Palette_Color_0049716e
                         (s_Which_card_do_you_seek__00519238,
                          *(uint *)(&DAT_0067bdfc + y * 100) & 0xff,
                          (*(int *)(&DAT_0067bdfc + y * 100) >> 8) - 1,local_14,1);
  }
  local_14 = 0;
  if (x == 0) {
    local_24 = 0;
    for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
      local_24 = local_24 + (&DAT_0067bdc0)[local_10];
    }
  }
  if (local_30 != 0xffffffff) {
    if (x != -2) goto LAB_0040efc0;
    bVar1 = true;
    if ((int)local_30 < 5) {
      local_c = 4;
    }
    else {
      local_c = 1;
    }
    goto LAB_0040f49b;
  }
LAB_0040f4fb:
  Palette_Subsystem_00496eaf();
  PTR_FUN_00527b3c = puVar2;
  return 0;
LAB_0040efc0:
  local_28 = Pic_Subsystem_00452551(local_30);
  if (local_28 == 1) {
    if ((int)local_30 < 5) {
      local_c = 4;
    }
    else {
      local_c = 1;
    }
  }
  else if (local_28 == 2) {
    local_c = 1;
  }
  else {
    local_c = 1;
  }
  if ((local_28 < 2) && (((&DAT_0051aed1)[local_30 * 0x34] & 4) != 0)) {
    local_28 = local_28 + 1;
  }
  iVar6 = FUN_0050a9bf(local_30);
  local_8 = iVar6 * 4;
  arg_1_00 = Surface_GetPixelColor((int)(DAT_0052eff0 + ((int)DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5,
                          (int)(DAT_0052eff4 + ((int)DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5);
  value = Glue_Subsystem_004ea7a6(arg_1_00);
  arg_1_01 = Card_ColorMaskToColorIndex(value);
  if (((arg_1_01 & (int)(char)(&DAT_0051aebe)[local_30 * 0x34]) == 0) &&
     ((&DAT_0051aebe)[local_30 * 0x34] != '\0')) {
    iVar3 = Pic_Subsystem_004521a6(arg_1_01,(int)(char)(&DAT_0051aebe)[local_30 * 0x34],3);
    if (iVar3 == 0) {
      local_8 = iVar6 << 3;
    }
    else {
      local_8 = (iVar6 * 0xc) / 2;
    }
  }
  iVar6 = Math_RandomRange(((DAT_0052eff0 & 0x1f) * (DAT_0052eff4 & 0x1f)) / 10);
  iVar3 = Math_Clamp((((local_8 * 0x4e2) / (iVar6 + 0x2ee)) / 0x32) * 5,5,1000);
  iVar6 = local_28 * 0x32;
  if (local_28 * 0x32 <= (int)(iVar3 * local_c)) {
    iVar6 = iVar3 * local_c;
  }
  strcpy(&g_OverworldWorldState,s_I_ll_trade_you_00519268);
  pcVar4 = _itoa(local_c,&DAT_00538610,10);
  strcat(&g_OverworldWorldState,pcVar4);
  strcat(&g_OverworldWorldState,&DAT_00519278);
  strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + local_30 * 0x34);
  if (1 < local_c) {
    strcat(&g_OverworldWorldState,&DAT_0051927c);
  }
  strcat(&g_OverworldWorldState,s_for_00519280);
  if (x < 0) {
    pcVar4 = _itoa(iVar6,&DAT_00538610,10);
    strcat(&g_OverworldWorldState,pcVar4);
    strcat(&g_OverworldWorldState,s_Gold_pieces__005192a4);
  }
  else {
    pcVar4 = _itoa(local_28,&DAT_00538610,10);
    strcat(&g_OverworldWorldState,pcVar4);
    if (0 < x) {
      strcat(&g_OverworldWorldState,&DAT_00519288);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e(x);
      strcat(&g_OverworldWorldState,pcVar4);
    }
    strcat(&g_OverworldWorldState,s_amulets__0051928c + ((1 < local_28) - 1 & 0xc));
  }
  bVar1 = true;
  if ((0 < x) && (*(int *)(&DAT_0067bdbc + x * 4) < local_28)) {
    bVar1 = false;
  }
  if ((x == 0) && (local_24 < local_28)) {
    bVar1 = false;
  }
  if ((x == -1) && (Gold < iVar6)) {
    bVar1 = false;
  }
  if (bVar1) {
    strcat(&g_OverworldWorldState,s_Do_you_wish_to_trade__Yes__I_ll_t_005192b4);
  }
  else {
    strcat(&g_OverworldWorldState,s_Hmmm____you_can_t_afford_this_ca_005192e8);
  }
  iVar3 = Ai_Util_004c3bc4(0x15c);
  iVar3 = iVar3 + 10;
  iVar5 = Ai_Util_004c3bc4(0xf4);
  iVar3 = FUN_00489710(&g_OverworldWorldState,iVar5 + 10,iVar3);
  if ((iVar3 == 0) && (bVar1)) {
    bVar1 = false;
    if ((0 < x) && (local_28 <= *(int *)(&DAT_0067bdbc + x * 4))) {
      bVar1 = true;
      *(int *)(&DAT_0067bdbc + x * 4) = *(int *)(&DAT_0067bdbc + x * 4) - local_28;
    }
    if ((x == 0) && (local_28 <= local_24)) {
      bVar1 = true;
      do {
        do {
          iVar3 = Math_RandomRange(5);
        } while ((&DAT_0067bdc0)[iVar3] == 0);
        local_28 = local_28 + -1;
        (&DAT_0067bdc0)[iVar3] = (&DAT_0067bdc0)[iVar3] + -1;
      } while (local_28 != 0);
    }
    if ((x == -1) && (iVar6 <= Gold)) {
      bVar1 = true;
      Gold = Gold - iVar6;
    }
LAB_0040f49b:
    if (!bVar1) goto LAB_0040f4fb;
    for (local_10 = 0; local_10 < (int)local_c; local_10 = local_10 + 1) {
      iVar6 = Pic_Subsystem_00451e40(local_30);
      if (iVar6 != -1) {
        *(uint *)(&deck + iVar6 * 4) = *(uint *)(&deck + iVar6 * 4) | 0x4000;
      }
    }
    FUN_0040a566();
    Palette_Subsystem_00496eaf();
  }
  goto LAB_0040eed6;
}

/*
 * Decompiled function: FUN_0040f514
 * Entry Point: 0040f514
 * Size: 290 bytes
 */


void FUN_0040f514(byte value)

{
  undefined4 uVar1;
  int aiStack_50 [16];
  int local_10;
  int local_c;
  int local_8;
  
  strcpy(&g_OverworldWorldState,s_Whose_deck_would_you_like_to_see_00519314);
  local_8 = 0;
  for (local_c = 1; local_c < DAT_00523524; local_c = local_c + 1) {
    if ((1 << (value & 0x1f) & (int)(char)(&DAT_0052262b)[local_c * 0x44]) != 0) {
      aiStack_50[local_8] = local_c;
      local_8 = local_8 + 1;
      Glue_Subsystem_004eaa19(local_c,0,0);
      strcat(&g_OverworldWorldState,&DAT_00519338);
    }
  }
  local_10 = FUN_00489710(&g_OverworldWorldState,100,0x46);
  if (local_10 != -1) {
    local_10 = aiStack_50[local_10];
    FUN_004909d3(local_10,0xffffffff,0,-1);
    for (local_c = 0; local_c < 500; local_c = local_c + 1) {
      uVar1 = FUN_0040a02a(DAT_0052eff8);
      *(undefined4 *)(&DAT_0069ef00 + local_c * 4) = uVar1;
    }
    FUN_0040a16e(DAT_0052eff8);
  }
  return;
}

/*
 * Decompiled function: FUN_0040f636
 * Entry Point: 0040f636
 * Size: 75 bytes
 */


int FUN_0040f636(char *str_1)

{
  char *pcVar1;
  char cVar2;
  int local_8;
  
  local_8 = 0;
  while (*str_1 != '\0') {
    pcVar1 = str_1 + 1;
    cVar2 = *str_1;
    str_1 = pcVar1;
    if (cVar2 == '\n') {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}

/*
 * Decompiled function: FUN_0040f681
 * Entry Point: 0040f681
 * Size: 104 bytes
 */


int FUN_0040f681(int *x,undefined4 *y)

{
  int local_8;
  
  local_8 = 1;
  *y = x;
  for (; (char)*x != '\0'; x = (int *)((int)x + 1)) {
    if (*x == 0xa0a0a0a) {
      y[local_8] = x + 1;
      local_8 = local_8 + 1;
    }
  }
  y[local_8] = x;
  return local_8;
}

/*
 * Decompiled function: FUN_0040f6e9
 * Entry Point: 0040f6e9
 * Size: 164 bytes
 */


int FUN_0040f6e9(void)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    if ((DAT_0067bdb4 & 1 << ((byte)local_c & 0x1f)) == 0) {
      local_8 = local_8 + 1;
    }
  }
  local_10 = Math_RandomRange(local_8);
  local_c = 1;
  while ((local_c < 6 && (local_10 != 0))) {
    if ((DAT_0067bdb4 & 1 << ((byte)local_c & 0x1f)) == 0) {
      local_10 = local_10 + -1;
    }
    local_c = local_c + 1;
  }
  return local_c;
}

/*
 * Decompiled function: FUN_0040f78d
 * Entry Point: 0040f78d
 * Size: 554 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0040f78d(int value)

{
  int iVar1;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  iVar1 = value * 7;
  local_20 = (int)(char)(&DAT_00522628)[value * 0x1dc];
  if ((iVar1 < 0x25) && (iVar1 % 7 != 0)) {
    local_20 = local_20 + DAT_0067f380 * 2;
  }
  else if ((iVar1 < 0x25) && (iVar1 % 7 == 0)) {
    local_20 = local_20 + DAT_0067f380 * 5;
  }
  else if (iVar1 < 0x37) {
    local_20 = local_20 + DAT_0067f380 * 2;
  }
  else if (0x36 < iVar1) {
    local_20 = local_20 + DAT_0067f380 * 0x32;
  }
  if ((&DAT_0052262a)[value * 0x1dc] == '\v') {
    for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
      if ((_DAT_0067f374 & 1 << ((byte)local_10 & 0x1f)) != 0) {
        local_20 = local_20 + 1;
      }
    }
  }
  if ((&DAT_0052262a)[value * 0x1dc] == '\f') {
    local_18 = 0;
    local_8 = 0;
    for (local_10 = 0; (local_10 < 1000 && ((&DAT_0067b9b0)[local_10] != '\0'));
        local_10 = local_10 + 1) {
      if ((int)(char)(&DAT_0067b9b0)[local_10] >> 4 == 1 << ((byte)value & 0x1f)) {
        local_18 = local_18 + 1;
      }
    }
    for (local_14 = 0; local_14 < 0x80; local_14 = local_14 + 1) {
      if (((&DAT_0067be01)[local_14 * 100] != '\0') &&
         ((*(int *)(&DAT_0067be00 + local_14 * 100) >> 8) + -1 == local_10)) {
        local_8 = local_8 + 1;
      }
    }
    iVar1 = ((local_20 + 10) - local_18) + DAT_0067f380 * local_8;
    local_20 = DAT_0067f380 * 5 + 0x14;
    if (local_20 <= iVar1) {
      local_20 = iVar1;
    }
  }
  return local_20;
}

/*
 * Decompiled function: FUN_0040f9b7
 * Entry Point: 0040f9b7
 * Size: 130 bytes
 */


int FUN_0040f9b7(byte value)

{
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < 0x80; local_c = local_c + 1) {
    if (((&DAT_0067be01)[local_c * 100] != '\0') &&
       ((*(int *)(&DAT_0067be00 + local_c * 100) >> 8) + -1 == 1 << (value & 0x1f))) {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}

/*
 * Decompiled function: FUN_0040fa39
 * Entry Point: 0040fa39
 * Size: 420 bytes
 */


undefined4 FUN_0040fa39(char *str_1,char *str_2,int max_val)

{
  undefined4 uVar1;
  int local_c;
  uint local_8;
  
  if (max_val != 0) {
    DAT_00517590 = 0;
    for (local_8 = 0; (int)local_8 < 0x80; local_8 = local_8 + 1) {
      if (((&DAT_0067be00)[local_8 * 100] & 1) != 0) {
        DAT_00517590 = DAT_00517590 + 1;
      }
    }
    if (DAT_00517590 < 2) {
      return 0xffffffff;
    }
    DAT_005384f8 = Math_RandomRange(DAT_00517590);
    DAT_005384fc = Math_RandomRange(DAT_00517590);
    while (DAT_005384fc == DAT_005384f8) {
      DAT_005384fc = Math_RandomRange(DAT_00517590);
    }
  }
  if (DAT_00517590 < 2) {
    uVar1 = 0xffffffff;
  }
  else {
    local_c = 0;
    for (local_8 = 0; (int)local_8 < 0x80; local_8 = local_8 + 1) {
      if (((&DAT_0067be00)[local_8 * 100] & 1) != 0) {
        if (DAT_005384f8 == local_c) {
          g_OverworldWorldState = 0;
          Ai_TownEncounter_004c3b19(local_8);
          strcpy(str_1,&g_OverworldWorldState);
          local_c = local_c + 1;
        }
        else if (DAT_005384fc == local_c) {
          g_OverworldWorldState = 0;
          Ai_TownEncounter_004c3b19(local_8);
          strcpy(str_2,&g_OverworldWorldState);
          local_c = local_c + 1;
        }
        else {
          local_c = local_c + 1;
        }
      }
    }
    uVar1 = 2;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0040fbe2
 * Entry Point: 0040fbe2
 * Size: 184 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0040fbe2(void)

{
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < 0xc; local_c = local_c + 1) {
    if ((_DAT_0067f374 & 1 << ((byte)local_c & 0x1f)) == 0) {
      local_8 = local_8 + 1;
    }
  }
  if (local_8 == 0) {
    local_c = -1;
  }
  else {
    local_10 = Math_RandomRange(local_8);
    local_c = 0;
    while ((local_c < 0xc && (local_10 != 0))) {
      if ((_DAT_0067f374 & 1 << ((byte)local_c & 0x1f)) == 0) {
        local_10 = local_10 + -1;
      }
      local_c = local_c + 1;
    }
  }
  return local_c;
}

/*
 * Decompiled function: FUN_0040fc9a
 * Entry Point: 0040fc9a
 * Size: 88 bytes
 */


void FUN_0040fc9a(int value,char *str_2,char *str_3)

{
  uint arg_1_00;
  
  arg_1_00 = *(uint *)(&DAT_005224e8 + value * 0x10);
  strcpy(str_2,(&PTR_s_Sleight_of_hand_005225d0)[value]);
  g_OverworldWorldState = 0;
  Ai_TownEncounter_004c3b19(arg_1_00);
  strcpy(str_3,&g_OverworldWorldState);
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040fcf2
 * Entry Point: 0040fcf2
 * Size: 11 bytes
 */


void Mem_AllocOrFree_0040fcf2(void)

{
  return;
}

/*
 * Decompiled function: FUN_00410c7d
 * Entry Point: 00410c7d
 * Size: 65 bytes
 */


void FUN_00410c7d(char *value)

{
  Mem_AllocOrFree_00510de0(1,value);
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
               (int *)g_DisplaySurfaceScreen,0,0);
  return;
}

/*
 * Decompiled function: Card_ApplyTriggerEffect
 * Entry Point: 00410cc0
 * Size: 561 bytes
 */


int Card_ApplyTriggerEffect(int value,int min_val,int max_val,int target_slot,int flags)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = Pic_Subsystem_00451291(value,max_val);
  if (iVar2 != -1) {
    *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + value * 0x5b20) =
         CONCAT31((uint3)((value == 0) - 1 >> 8) & 0x10,2);
    (&DAT_006a5f4c)[iVar2 * 0x120 + value * 0x5b20] =
         (&DAT_006a5f4c)[min_val * 0x120 + value * 0x5b20];
    (&DAT_006a5f4d)[iVar2 * 0x120 + value * 0x5b20] =
         (&DAT_006a5f4d)[min_val * 0x120 + value * 0x5b20];
    (&g_CardSlot_DamageReceived)[iVar2 * 0x120 + value * 0x5b20] = (undefined1)value;
    *(int *)(&g_CardSlot_TypeFlags + iVar2 * 0x120 + value * 0x5b20) = min_val;
    uVar1 = *(uint *)(&g_MasterCardTypeTable +
                     *(int *)(&g_CardSlot_CardId + min_val * 0x120 + value * 0x5b20) * 0x34);
    iVar3 = FUN_00478aa4(*(int *)(&g_MasterCardTypeTable +
                                 *(int *)(&g_CardSlot_CardId + min_val * 0x120 + value * 0x5b20) *
                                 0x34),value,min_val);
    *(uint *)(&DAT_006a5f74 + iVar2 * 0x120 + value * 0x5b20) = uVar1 | iVar3 << 0x10;
    (&g_CardSlot_Toughness)[iVar2 * 0x120 + value * 0x5b20] = (undefined1)target_slot;
    *(int *)(&g_CardSlot_OriginalCardId + iVar2 * 0x120 + value * 0x5b20) = flags;
    if ((target_slot != -1) && (flags != -1)) {
      *(uint *)(&g_CardSlot_Abilities2 + target_slot * 0x5b20 + flags * 0x120) =
           *(uint *)(&g_CardSlot_Abilities2 + target_slot * 0x5b20 + flags * 0x120) | 0xf000000;
    }
  }
  return iVar2;
}

/*
 * Decompiled function: FUN_00410ef1
 * Entry Point: 00410ef1
 * Size: 622 bytes
 */


undefined4 FUN_00410ef1(int value,int min_val,int max_val)

{
  if (((*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) == g_EventSourceSlot)
      && ((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] == g_EventSourcePlayer))
     && (g_EventSourceSlot != -1)) {
    if ((((&DAT_006a5f56)[min_val * 0x120 + value * 0x5b20] & 8) != 0) &&
       (*(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) != -1)) {
      *(ushort *)(&DAT_006a5f48 + min_val * 0x120 + value * 0x5b20) =
           (ushort)*(undefined4 *)
                    (&g_CardSlot_ConvertedManaCost +
                    *(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] * 0x5b20) &
           0xff;
      *(ushort *)(&DAT_006a5f4a + min_val * 0x120 + value * 0x5b20) =
           (ushort)((uint)*(undefined4 *)
                           (&g_CardSlot_ConvertedManaCost +
                           *(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) * 0x120
                           + (char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] *
                             0x5b20) >> 8) & 0xff;
    }
    if (max_val == 0x32) {
      g_CardEventResult = g_CardEventResult + *(short *)(&DAT_006a5f48 + min_val * 0x120 + value * 0x5b20)
      ;
    }
    if (max_val == 0x33) {
      g_CardEventResult = g_CardEventResult + *(short *)(&DAT_006a5f4a + min_val * 0x120 + value * 0x5b20)
      ;
    }
  }
  if ((((&g_CardSlot_Abilities1)[min_val * 0x120 + value * 0x5b20] & 0x20) == 0) &&
     ((max_val == 0x22 || (max_val == 199)))) {
    Pic_Subsystem_0044867e(value,min_val,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_0041115f
 * Entry Point: 0041115f
 * Size: 162 bytes
 */


undefined4 FUN_0041115f(int value,int min_val,int max_val)

{
  if (((max_val == 0x78) &&
      (*(int *)(&g_CardSlot_OriginalCardId + value * 0x5b20 + min_val * 0x120) == g_EventTargetSlot)) &&
     ((char)(&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120] == g_EventTargetPlayer)) {
    g_CardEventResult = g_CardEventResult + 1;
  }
  if ((max_val == 0x22) || (max_val == 199)) {
    Pic_Subsystem_0044867e(value,min_val,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00411201
 * Entry Point: 00411201
 * Size: 269 bytes
 */


undefined4 FUN_00411201(int value,int min_val,int max_val)

{
  if (((max_val == 0x22) || (max_val == 199)) &&
     ((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] == g_TurnPlayer)) {
    if (*(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) == 0) {
      *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) + 1;
    }
    else {
      *(uint *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) &
           0xffff7fff;
      Pic_Subsystem_0044867e(value,min_val,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_0041130e
 * Entry Point: 0041130e
 * Size: 1093 bytes
 */


undefined4 FUN_0041130e(int value,int min_val,int max_val)

{
  if ((((max_val == 0x34) &&
       (*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) == g_EventSourceSlot)
       ) && ((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] ==
             g_EventSourcePlayer)) && (g_EventSourceSlot != -1)) {
    g_CardEventResult =
         g_CardEventResult | *(uint *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20)
    ;
  }
  if ((((max_val == 0x77) &&
       (*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) == g_EventSourceSlot)
       ) && (((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] ==
              g_EventSourcePlayer &&
             ((g_EventSourceSlot != -1 &&
              ((&DAT_006a5f50)
               [*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20] != '\x04')))
             ))) &&
     (*(int *)(&g_MasterCardTypeTable +
              *(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) * 0x120 +
                      (char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] * 0x5b20) *
              0x34) == 0x1a3)) {
    Pic_Subsystem_0044867e
              ((int)(char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20],
               *(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20),2);
  }
  if ((g_EventSourceSlot == min_val) && (g_EventSourcePlayer == value)) {
    if ((&DAT_006a5f50)[min_val * 0x120 + value * 0x5b20] == '\x05') {
      if (((g_CurrentStepCode == 0xcd) || (max_val == 199)) &&
         ((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] == DAT_006a4b5c)) {
        if (max_val == 0x7d) {
          g_CardEventResult = g_CardEventResult | 2;
        }
        if (((max_val == 0x7e) || (max_val == 199)) &&
           (Pic_Subsystem_0044867e
                      ((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20),2),
           *(int *)(&g_CardSlot_CardId + min_val * 0x120 + value * 0x5b20) != -1)) {
          Pic_Subsystem_0044867e(value,min_val,2);
        }
      }
    }
    else if ((((&g_CardSlot_Abilities1)[min_val * 0x120 + value * 0x5b20] & 0x20) == 0) &&
            ((max_val == 0x22 || (max_val == 199)))) {
      if ((&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] != -1) {
        *(undefined4 *)
         (&g_CardSlot_Abilities2 +
         *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
         (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) = 0x8000000;
      }
      Pic_Subsystem_0044867e(value,min_val,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00411753
 * Entry Point: 00411753
 * Size: 341 bytes
 */


undefined4 FUN_00411753(int value,int min_val,int max_val)

{
  if ((((max_val == 0x34) &&
       (*(int *)(&g_CardSlot_OriginalCardId + value * 0x5b20 + min_val * 0x120) == g_EventSourceSlot)
       ) && ((char)(&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120] ==
             g_EventSourcePlayer)) && (g_EventSourceSlot != -1)) {
    g_CardEventResult =
         g_CardEventResult &
         ~*(uint *)(&g_CardSlot_ConvertedManaCost + value * 0x5b20 + min_val * 0x120);
  }
  if ((max_val == 0x22) || (max_val == 199)) {
    if ((&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120] != -1) {
      *(undefined4 *)
       (&g_CardSlot_Abilities2 +
       *(int *)(&g_CardSlot_OriginalCardId + value * 0x5b20 + min_val * 0x120) * 0x120 +
       (char)(&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120] * 0x5b20) = 0x8000000;
    }
    Pic_Subsystem_0044867e(value,min_val,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_004118a8
 * Entry Point: 004118a8
 * Size: 1776 bytes
 */


undefined4 FUN_004118a8(int value,int min_val,int max_val)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if ((((g_EventSourceSlot == min_val) && (g_EventSourcePlayer == value)) &&
      (*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) != -1)) &&
     (((byte)g_DuelModeFlags & 4) != 0)) {
    uVar2 = Magic_QueryCardAttribute((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                         *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20),0x34,
                         0xffffffff);
    if ((uVar2 & 0x1ff800) != 0) {
      cVar1 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)
                           [*(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) * 0x120
                            + (char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] *
                              0x5b20]);
      if ((uVar2 & 0x800 << (cVar1 - 1U & 0x1f)) != 0) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) = 0;
        Pic_Subsystem_0044867e(value,min_val,1);
      }
    }
  }
  if (((max_val == 0x6e) && (g_EventSourceSlot == min_val)) &&
     ((g_EventSourcePlayer == value &&
      (((&g_CardSlot_Flags)[min_val * 0x120 + value * 0x5b20] & 0x10) == 0)))) {
    *(uint *)(&g_CardSlot_Flags + min_val * 0x120 + value * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + min_val * 0x120 + value * 0x5b20) | 0x10;
    if (*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) == -1) {
      if (g_IsAiThinking != 1) {
        Duel_PlaySoundById(0xe);
      }
      if (*(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId +
                          *(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) * 0x120 +
                          (char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] *
                          0x5b20) * 0x34) == DAT_006a2848) {
        (&DAT_00700ec0)
        [(char)(&g_CardSlot_DamageReceived)
               [*(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] * 0x5b20] * 0xa0
         + (int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] +
           *(int *)(&g_CardSlot_TypeFlags +
                   *(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) * 0x120 +
                   (char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] * 0x5b20) * 2]
             = (&DAT_00700ec0)
               [(char)(&g_CardSlot_DamageReceived)
                      [*(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) * 0x120 +
                       (char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] * 0x5b20]
                * 0xa0 + (int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] +
                         *(int *)(&g_CardSlot_TypeFlags +
                                 *(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) *
                                 0x120 + (char)(&g_CardSlot_DamageReceived)
                                               [min_val * 0x120 + value * 0x5b20] * 0x5b20) * 2] +
               (char)*(undefined4 *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20)
        ;
      }
      else {
        (&DAT_00700ec0)
        [*(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) * 2 +
         (char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] * 0xa0 +
         (int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20]] =
             (&DAT_00700ec0)
             [*(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) * 2 +
              (char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] * 0xa0 +
              (int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20]] +
             (char)*(undefined4 *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20);
      }
      (&g_PlayerCreatureCount)[(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20]] =
           (&g_PlayerCreatureCount)[(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20]] -
           *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20);
      *(int *)(&DAT_006b3030 + (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 4) =
           *(int *)(&DAT_006b3030 +
                   (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 4) +
           *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20);
    }
    else {
      iVar3 = Card_IsTapped((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                           *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20));
      if ((iVar3 != 0) &&
         (*(short *)(&g_CardSlot_Power +
                    *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) =
               *(short *)(&g_CardSlot_Power +
                         *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) *
                         0x120 + (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] *
                                 0x5b20) +
               (short)*(undefined4 *)
                       (&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20),
         g_IsAiThinking != 1)) {
        Duel_PlaySoundById(0x16);
        Ai_Subsystem_004cc3f8
                  ((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                   *(undefined4 *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20),6,2)
        ;
      }
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00411f98
 * Entry Point: 00411f98
 * Size: 435 bytes
 */


undefined4 FUN_00411f98(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  int iVar2;
  
  if (max_val == 0x73) {
    uVar1 = Font_DrawString(value,7,1);
  }
  else {
    if (((max_val == 0x6d) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value)) {
      iVar2 = Font_DrawString(value,7,1);
      if (iVar2 != 0) {
        Ai_CalcManaRequirement_004ba890(value,0,1);
      }
    }
    if (max_val == 0x72) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,4);
    }
    if ((((g_CurrentStepCode == 0xce) || (max_val == 199)) &&
        ((g_EventSourceSlot == min_val &&
         ((g_EventSourcePlayer == value && (g_TurnPlayer == value)))))) &&
       (value == DAT_006a4b5c)) {
      if (max_val == 0x7d) {
        g_CardEventResult = g_CardEventResult | 2;
      }
      if ((max_val == 0x7e) || (max_val == 199)) {
        Ai_Subsystem_004cc56d(value,value,min_val,-1,-1,s_Naf_s_Asp_takes_1_life__005196ac,0);
        Mem_AllocOrFree_0041df33(value,1,value,min_val);
      }
    }
    if ((max_val == 0x22) || (max_val == 199)) {
      if (g_IsAiThinking == 1) {
        Mem_AllocOrFree_0041df33(value,1,value,min_val);
      }
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0041214b
 * Entry Point: 0041214b
 * Size: 251 bytes
 */


undefined4 FUN_0041214b(int value,int min_val,int max_val)

{
  if ((((g_CurrentStepCode == 0xcc) || (max_val == 199)) && (g_EventSourceSlot == min_val)) &&
     (g_EventSourcePlayer == value)) {
    if (max_val == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((max_val == 0x7e) || (max_val == 199)) {
      if ((&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] != -1) {
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20),2);
      }
      Pic_Subsystem_0044867e(value,min_val,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00412246
 * Entry Point: 00412246
 * Size: 461 bytes
 */


undefined4 FUN_00412246(int value,int min_val,int max_val)

{
  if ((((g_CurrentStepCode == 0xcc) || (max_val == 199)) && (min_val == g_EventSourceSlot)) &&
     (value == g_EventSourcePlayer)) {
    if (max_val == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((max_val == 0x7e) || (max_val == 199)) {
      if ((&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120] != -1) {
        Mem_AllocOrFree_0041df33(value,5,value,min_val);
      }
      if ((*(int *)(&g_CardSlot_CardId +
                   *(int *)(&g_CardSlot_TypeFlags + value * 0x5b20 + min_val * 0x120) * 0x120 +
                   (char)(&g_CardSlot_DamageReceived)[value * 0x5b20 + min_val * 0x120] * 0x5b20) !=
           -1) && (((&g_CardSlot_Flags)
                    [*(int *)(&g_CardSlot_TypeFlags + value * 0x5b20 + min_val * 0x120) * 0x120 +
                     (char)(&g_CardSlot_DamageReceived)[value * 0x5b20 + min_val * 0x120] * 0x5b20] &
                   2) != 0)) {
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_DamageReceived)[value * 0x5b20 + min_val * 0x120],
                   *(int *)(&g_CardSlot_TypeFlags + value * 0x5b20 + min_val * 0x120),1);
      }
      Pic_Subsystem_0044867e(value,min_val,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00412413
 * Entry Point: 00412413
 * Size: 371 bytes
 */


undefined4 FUN_00412413(int value,int min_val,int max_val)

{
  int iVar1;
  
  if ((((max_val == 0x32) &&
       (*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) == g_EventSourceSlot)
       ) && ((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] ==
             g_EventSourcePlayer)) && (g_EventSourceSlot != -1)) {
    iVar1 = Card_IsTapped((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                         *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20));
    if ((iVar1 != 0) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) * 0x34] &
        2) != 0)) {
      g_CardEventResult = g_CardEventResult + -2;
    }
  }
  if ((max_val == 0x22) || (max_val == 199)) {
    Pic_Subsystem_0044867e(value,min_val,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00412586
 * Entry Point: 00412586
 * Size: 260 bytes
 */


undefined4 FUN_00412586(int value,int min_val,int max_val)

{
  if ((max_val == 0x21) &&
     (((g_ScWillyScore == 0x1a || (g_ScWillyScore == 0x19)) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_TypeFlags +
                         g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) * 0x120 +
                 (char)(&g_CardSlot_DamageReceived)
                       [g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] * 0x5b20) *
         0x34] & 2) != 0)))) {
    *(undefined4 *)
     (&g_CardSlot_ConvertedManaCost + g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120)
         = 0;
  }
  if ((max_val == 0x22) || (max_val == 199)) {
    Pic_Subsystem_0044867e(value,min_val,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_0041268a
 * Entry Point: 0041268a
 * Size: 437 bytes
 */


bool FUN_0041268a(int value,int min_val,int max_val)

{
  bool bVar1;
  int local_8;
  
  if (max_val == 0x73) {
    if ((g_ActivePlayerPriority == value) && ((&g_PlayerCreatureCount)[value] == 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = 0 < (int)(&g_PlayerCreatureCount)[value];
    }
  }
  else {
    if (max_val == 0x6d) {
      bVar1 = false;
      while ((!bVar1 && (g_ActivePlayer != 1))) {
        local_8 = Ai_Subsystem_004cc8de(value,s_Spend_how_much_life_for_generic_m_005196c4,1);
        if (local_8 < 0) {
          g_ActivePlayer = 1;
        }
        else if ((int)(&g_PlayerCreatureCount)[value] < local_8) {
          if (g_IsAiThinking != 1) {
            Ai_Util_004cc42d(s_Illegal_Amount___must_be_between_005196ec);
            Sleep(2000);
            Ai_Util_004cc42d(&DAT_0051971c);
          }
        }
        else {
          bVar1 = true;
        }
      }
      if (g_ActivePlayer != 1) {
        FUN_0040d901(value,0,local_8);
        (&g_PlayerCreatureCount)[value] = (&g_PlayerCreatureCount)[value] - local_8;
      }
    }
    if ((max_val == 0x22) || (max_val == 199)) {
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    if (((max_val == 0x7f) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value)) {
      FUN_0040d7e9(value,0,(&g_PlayerCreatureCount)[value]);
    }
    bVar1 = false;
  }
  return bVar1;
}

/*
 * Decompiled function: FUN_0041283f
 * Entry Point: 0041283f
 * Size: 1750 bytes
 */


undefined4 FUN_0041283f(int value,int min_val,int max_val)

{
  int iVar1;
  
  if (((&DAT_006a5f69)[min_val * 0x120 + value * 0x5b20] & 0x40) != 0) {
    if (((*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) ==
          g_EventSourceSlot) &&
        ((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] == g_EventSourcePlayer))
       && (g_EventSourceSlot != -1)) {
      if (max_val == 0x34) {
        g_CardEventResult =
             g_CardEventResult |
             *(uint *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20);
      }
      if (max_val == 0x32) {
        g_CardEventResult =
             g_CardEventResult + (int)*(short *)(&DAT_006a5f48 + min_val * 0x120 + value * 0x5b20);
      }
    }
    if (((g_EventSourceSlot == min_val) && (value == g_EventSourcePlayer)) &&
       ((max_val == 0x22 &&
        ((*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) != -1 &&
         (((&g_CardSlot_Flags)
           [*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20] & 0x40) != 0))))
       )) {
      (&DAT_006a5f50)[min_val * 0x120 + value * 0x5b20] = 5;
    }
  }
  if (((&DAT_006a5f69)[min_val * 0x120 + value * 0x5b20] & 0x10) != 0) {
    if (((((max_val == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) &&
         (*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) ==
          g_EventSourceSlot)) &&
        (((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] == g_EventSourcePlayer
         && (g_EventSourceSlot != -1)))) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] * 0x5b20) != -1))
    {
      iVar1 = Card_UntapCard(value, min_val, *(int *)(&g_CardSlot_ConvertedManaCost +
                                   *(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20)
                                   * 0x120 + (char)(&g_CardSlot_DamageReceived)
                                                   [min_val * 0x120 + value * 0x5b20] * 0x5b20));
      g_CardEventResult = iVar1 - 1;
    }
    if (((max_val == 0x77) &&
        ((char)(&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] ==
         g_EventSourcePlayer)) &&
       (*(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) == g_EventSourceSlot)) {
      *(uint *)(&g_CardSlot_Abilities2 +
               *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 +
                    *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) |
           0x1000000;
      Pic_Subsystem_0044867e(value,min_val,1);
    }
  }
  if (((&DAT_006a5f6a)[min_val * 0x120 + value * 0x5b20] & 0x40) != 0) {
    if ((max_val == 0x6a) && (value == g_TurnPlayer)) {
      Pic_Subsystem_0044867e(value,min_val,2);
      *(undefined4 *)(&DAT_00680780 + value * 4) = 0;
    }
    if ((max_val == 0x79) &&
       ((*(uint *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) &
        *(uint *)(&g_CardSlot_Abilities2 +
                 g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120)) == 0)) {
      g_CardEventResult = g_CardEventResult + 1;
    }
  }
  if (((&DAT_006a5f69)[min_val * 0x120 + value * 0x5b20] & 1) != 0) {
    if ((max_val == 0x6a) && (DAT_006ff2d8 == -1)) {
      DAT_006ff2d8 = value;
    }
    if ((max_val == 0x22) && (DAT_007006d4 == 0)) {
      DAT_007006d4 = 1 << ((byte)value & 0x1f);
      *(uint *)(&g_CardSlot_Abilities1 + min_val * 0x120 + value * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + min_val * 0x120 + value * 0x5b20) & 0xffffffdf;
    }
  }
  if ((g_EventSourceSlot == min_val) && (value == g_EventSourcePlayer)) {
    if ((&DAT_006a5f50)[min_val * 0x120 + value * 0x5b20] == '\x05') {
      if (((g_CurrentStepCode == 0xcd) || (max_val == 199)) &&
         ((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] == DAT_006a4b5c)) {
        if (max_val == 0x7d) {
          g_CardEventResult = g_CardEventResult | 2;
        }
        if (((max_val == 0x7e) || (max_val == 199)) &&
           (Pic_Subsystem_0044867e
                      ((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20),2),
           *(int *)(&g_CardSlot_CardId + min_val * 0x120 + value * 0x5b20) != -1)) {
          Pic_Subsystem_0044867e(value,min_val,2);
        }
      }
    }
    else if ((((&g_CardSlot_Abilities1)[min_val * 0x120 + value * 0x5b20] & 0x20) == 0) &&
            ((max_val == 0x22 || (max_val == 199)))) {
      Pic_Subsystem_0044867e(value,min_val,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00412f15
 * Entry Point: 00412f15
 * Size: 1617 bytes
 */


undefined4 FUN_00412f15(int value,int min_val,int max_val)

{
  uint uVar1;
  int iVar2;
  int local_14;
  uint local_c;
  int local_8;
  
  if ((((*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) == g_EventSourceSlot
        ) && ((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] ==
              g_EventSourcePlayer)) && (g_EventSourceSlot != -1)) &&
     (((max_val == 0x32 && (((&g_CardSlot_TargetSlot)[min_val * 0x120 + value * 0x5b20] & 4) != 0)) ||
      ((max_val == 0x33 && (((&g_CardSlot_TargetSlot)[min_val * 0x120 + value * 0x5b20] & 8) != 0))))))
  {
    local_c = 0;
    uVar1 = *(uint *)(&g_CardSlot_TargetSlot + min_val * 0x120 + value * 0x5b20) & 0xf00;
    if (uVar1 < 0x201) {
      if (uVar1 == 0x200) {
        for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
          if (((*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) == local_14)
              && (((&g_CardSlot_TargetSlot)[min_val * 0x120 + value * 0x5b20] & 1) != 0)) ||
             ((*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) != local_14 &&
              (((&g_CardSlot_TargetSlot)[min_val * 0x120 + value * 0x5b20] & 2) != 0)))) {
            for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_14];
                local_8 = local_8 + 1) {
              if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_14 * 0x5b20) != -1) &&
                  (((&g_CardSlot_Flags)[local_8 * 0x120 + local_14 * 0x5b20] & 2) != 0)) &&
                 (*(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) ==
                  *(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_14 * 0x5b20))) {
                local_c = local_c + 1;
              }
            }
          }
        }
      }
      else if (uVar1 == 0x100) {
        if (((&g_CardSlot_TargetSlot)[min_val * 0x120 + value * 0x5b20] & 1) != 0) {
          iVar2 = Card_UntapCard((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20)
                               ,*(int *)(&g_CardSlot_ConvertedManaCost +
                                        min_val * 0x120 + value * 0x5b20));
          local_c = *(uint *)(&DAT_0063ee30 +
                             iVar2 * 4 +
                             (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x20);
        }
        if (((&g_CardSlot_TargetSlot)[min_val * 0x120 + value * 0x5b20] & 2) != 0) {
          iVar2 = Card_UntapCard((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20)
                               ,*(int *)(&g_CardSlot_ConvertedManaCost +
                                        min_val * 0x120 + value * 0x5b20));
          local_c = local_c + *(int *)(&DAT_0063ee30 +
                                      iVar2 * 4 +
                                      (1 - (char)(&g_CardSlot_Toughness)
                                                 [min_val * 0x120 + value * 0x5b20]) * 0x20);
        }
      }
    }
    else if (uVar1 == 0x400) {
      if (max_val == 0x32) {
        local_c = *(uint *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) & 0xff;
      }
      else {
        local_c = (uint)(byte)(&DAT_006a5f55)[min_val * 0x120 + value * 0x5b20];
      }
    }
    else if (uVar1 == 0x800) {
      for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
        if ((((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] == local_14) &&
            (((&g_CardSlot_TargetSlot)[min_val * 0x120 + value * 0x5b20] & 1) != 0)) ||
           (((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] != local_14 &&
            (((&g_CardSlot_TargetSlot)[min_val * 0x120 + value * 0x5b20] & 2) != 0)))) {
          for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_14];
              local_8 = local_8 + 1) {
            iVar2 = Card_IsTapped(local_14,local_8);
            if (((iVar2 != 0) &&
                (((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_14 * 0x5b20) * 0x34] & 2)
                 != 0)) &&
               ((&DAT_0051aebd)
                [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_14 * 0x5b20) * 0x34] != '\0')
               ) {
              local_c = local_c + 1;
            }
          }
        }
      }
    }
    g_CardEventResult = g_CardEventResult + local_c;
    if (max_val == 0x32) {
      *(short *)(&DAT_006a5f48 + min_val * 0x120 + value * 0x5b20) = (short)local_c;
    }
    else {
      *(short *)(&DAT_006a5f4a + min_val * 0x120 + value * 0x5b20) = (short)local_c;
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413570
 * Entry Point: 00413570
 * Size: 761 bytes
 */


undefined4 FUN_00413570(int value,int min_val,int max_val)

{
  bool bVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_8;
  
  if ((((((&DAT_006a5f6b)[value * 0x5b20 + min_val * 0x120] & 1) != 0) &&
       (*(int *)(&g_CardSlot_OriginalCardId + value * 0x5b20 + min_val * 0x120) == g_EventSourceSlot)
       ) && ((char)(&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120] ==
             g_EventSourcePlayer)) &&
     ((g_EventSourceSlot != -1 && ((max_val == 0x32 || (max_val == 0x33)))))) {
    local_14 = 0;
    local_10 = 0;
    iVar2 = (int)(char)(&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120];
    local_8 = 0;
    bVar1 = false;
    while ((local_8 < (int)(&g_PlayerActiveCardCount)[iVar2] && (!bVar1))) {
      if ((((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + iVar2 * 0x5b20) == DAT_00701000) &&
           (((&g_CardSlot_Flags)[local_8 * 0x120 + iVar2 * 0x5b20] & 2) != 0)) &&
          ((&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120] ==
           (&g_CardSlot_Toughness)[local_8 * 0x120 + iVar2 * 0x5b20])) &&
         (*(int *)(&g_CardSlot_OriginalCardId + value * 0x5b20 + min_val * 0x120) ==
          *(int *)(&g_CardSlot_OriginalCardId + local_8 * 0x120 + iVar2 * 0x5b20))) {
        bVar1 = true;
        local_10 = -(int)*(short *)(&DAT_006a5f48 + local_8 * 0x120 + iVar2 * 0x5b20);
        local_14 = -(int)*(short *)(&DAT_006a5f4a + local_8 * 0x120 + iVar2 * 0x5b20);
      }
      local_8 = local_8 + 1;
    }
    if (max_val == 0x32) {
      g_CardEventResult =
           g_CardEventResult + *(short *)(&DAT_006a5f48 + value * 0x5b20 + min_val * 0x120) + local_10;
    }
    else {
      g_CardEventResult =
           g_CardEventResult + *(short *)(&DAT_006a5f4a + value * 0x5b20 + min_val * 0x120) + local_14;
    }
  }
  if ((((&g_CardSlot_Abilities1)[value * 0x5b20 + min_val * 0x120] & 0x20) == 0) &&
     ((max_val == 0x22 || (max_val == 199)))) {
    Pic_Subsystem_0044867e(value,min_val,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413869
 * Entry Point: 00413869
 * Size: 457 bytes
 */


undefined4 FUN_00413869(int value,int min_val,int max_val)

{
  if ((max_val == 0x22) && (*(int *)(&g_CardSlot_TargetSlot + min_val * 0x120 + value * 0x5b20) == 0)) {
    Mem_AllocOrFree_0041d942(*(int *)(&g_CardSlot_Controller + min_val * 0x120 + value * 0x5b20));
    Pic_Subsystem_0044867e(value,min_val,1);
    *(uint *)(&g_CardSlot_Abilities2 +
             *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
             (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities2 +
                  *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) |
         0x1000000;
    Magic_QueryCardAttribute((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                 *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20),0x3c,
                 0xffffffff);
    Ai_Subsystem_004cced8();
  }
  if ((((max_val == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) &&
      (*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) == g_EventSourceSlot))
     && (((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] == g_EventSourcePlayer
         && (g_EventSourceSlot != -1)))) {
    g_CardEventResult = *(undefined4 *)(&g_CardSlot_Controller + min_val * 0x120 + value * 0x5b20);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413a32
 * Entry Point: 00413a32
 * Size: 376 bytes
 */


undefined4 FUN_00413a32(int value,int min_val,int max_val)

{
  if (((&g_CardSlot_Abilities1)
       [*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
        (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20] & 0x80) != 0) {
    (&DAT_006a5f50)
    [*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
     (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20] = 4;
  }
  if ((max_val == 0x22) || (max_val == 199)) {
    if ((&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] != -1) {
      *(undefined4 *)
       (&g_CardSlot_Abilities2 +
       *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
       (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) = 0x8000000;
    }
    Pic_Subsystem_0044867e(value,min_val,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413baa
 * Entry Point: 00413baa
 * Size: 343 bytes
 */


undefined4 FUN_00413baa(int value,int min_val,int max_val)

{
  int iVar1;
  int x;
  int iVar2;
  int local_c;
  
  if (max_val == 0x89) {
    Glue_Subsystem_004e65e1(FUN_00413d01,-1);
  }
  if ((((max_val == 0x22) || (max_val == 199)) && (g_EventSourceSlot == min_val)) &&
     (g_EventSourcePlayer == value)) {
    x = 1 - value;
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[x]; local_c = local_c + 1) {
      iVar1 = *(int *)(&g_CardSlot_CardId + local_c * 0x120 + x * 0x5b20);
      iVar2 = Card_IsTapped(x,local_c);
      if (((iVar2 != 0) && (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0)) &&
         (((&DAT_0051aebd)[iVar1 * 0x34] != '\0' &&
          ((*(uint *)(&g_CardSlot_Flags + local_c * 0x120 + x * 0x5b20) & 0x30040) == 0)))) {
        Pic_Subsystem_0044867e(x,local_c,2);
      }
    }
    Pic_Subsystem_0044867e(value,min_val,2);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413d01
 * Entry Point: 00413d01
 * Size: 140 bytes
 */


undefined4 FUN_00413d01(int x,int y)

{
  int iVar1;
  
  if ((g_TurnPlayer == x) && (((&DAT_006a5f3d)[y * 0x120 + x * 0x5b20] & 0x80) == 0))
  {
    *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x8000;
    iVar1 = FUN_004726c5(x,y);
    if (iVar1 != 0) {
      DAT_006a5f20 = 1;
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413d8d
 * Entry Point: 00413d8d
 * Size: 551 bytes
 */


undefined4 FUN_00413d8d(int value,int min_val,int max_val)

{
  if ((max_val == 0x21) && ((g_ScWillyScore == 0x1a || (g_ScWillyScore == 0x19)))) {
    if (((&g_CardSlot_Toughness)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] ==
         (&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20]) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) ==
        *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20))) {
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) = 0;
    }
    if (((&g_CardSlot_DamageReceived)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120]
         == (&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20]) &&
       (*(int *)(&g_CardSlot_TypeFlags +
                g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) ==
        *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20))) {
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) = 0;
    }
  }
  if ((((g_CurrentStepCode == 0xcc) || (max_val == 199)) && (g_EventSourceSlot == min_val)) &&
     (g_EventSourcePlayer == value)) {
    if (max_val == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((max_val == 0x7e) || (max_val == 199)) {
      Pic_Subsystem_0044867e(value,min_val,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413fb4
 * Entry Point: 00413fb4
 * Size: 700 bytes
 */


undefined4 FUN_00413fb4(int value,int min_val,int max_val)

{
  if ((((max_val == 0x3c) && ((g_DuelModeFlags._2_1_ & 2) == 0)) &&
      (*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) == g_EventSourceSlot))
     && ((((char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] == g_EventSourcePlayer
          && (g_EventSourceSlot != -1)) &&
         (*(int *)(&g_CardSlot_Controller + min_val * 0x120 + value * 0x5b20) != -1)))) {
    g_CardEventResult = *(uint *)(&g_CardSlot_Controller + min_val * 0x120 + value * 0x5b20);
    *(uint *)(&g_CardSlot_Abilities1 +
             *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
             (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 +
                  *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) | 0x40;
  }
  if (((g_CurrentStepCode == 0xc9) || (max_val == 199)) &&
     ((g_EventSourceSlot == min_val &&
      (((g_EventSourcePlayer == value && (g_TurnPlayer == value)) &&
       (DAT_006a4b5c == value)))))) {
    if (max_val == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if ((max_val == 0x7e) || (max_val == 199)) {
      Mem_AllocOrFree_0041d942(*(int *)(&g_CardSlot_Controller + min_val * 0x120 + value * 0x5b20));
      *(undefined4 *)(&g_CardSlot_Controller + min_val * 0x120 + value * 0x5b20) = 0xffffffff;
      *(uint *)(&g_CardSlot_Abilities2 +
               *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 +
                    *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] * 0x5b20) |
           0x1000000;
      Magic_QueryCardAttribute((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20),0x3c,
                   0xffffffff);
      Ai_Subsystem_004cced8();
      Pic_Subsystem_0044867e(value,min_val,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00414270
 * Entry Point: 00414270
 * Size: 813 bytes
 */


undefined4 FUN_00414270(int value,int min_val,int max_val)

{
  int iVar1;
  int local_c;
  int local_8;
  
  if ((((g_CurrentStepCode == 0xd5) && (g_EventSourceSlot == min_val)) &&
      (g_EventSourcePlayer == value)) && (value == DAT_006a4b5c)) {
    if (max_val == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (max_val == 0x7e) {
      iVar1 = Pic_Subsystem_0045268f(0x200);
      if (*(int *)(&g_ActiveCardsInPlay + value * 0x5b20 + min_val * 0x120) == iVar1) {
        if ((g_IsAiThinking == 1) && (value == g_CurrentTurnPhase)) {
          (&g_PlayerCreatureCount)[value] = (&g_PlayerCreatureCount)[value] + 1;
        }
        else {
          (&g_PlayerCreatureCount)[value] = (&g_PlayerCreatureCount)[value] + 2;
        }
      }
      iVar1 = Pic_Subsystem_0045268f(0xb5);
      if (*(int *)(&g_ActiveCardsInPlay + value * 0x5b20 + min_val * 0x120) == iVar1) {
        (&g_PlayerCreatureCount)
        [(*(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) & 0x1000) >> 0xc] =
             (int)(&g_PlayerCreatureCount)
                  [(*(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) & 0x1000) >> 0xc]
             / 2;
      }
      iVar1 = Pic_Subsystem_0045268f(0x32);
      if (*(int *)(&g_ActiveCardsInPlay + value * 0x5b20 + min_val * 0x120) == iVar1) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120],
                   *(int *)(&g_CardSlot_ConvertedManaCost + value * 0x5b20 + min_val * 0x120),value,
                   min_val);
      }
      iVar1 = Pic_Subsystem_0045268f(0x109);
      if (*(int *)(&g_ActiveCardsInPlay + value * 0x5b20 + min_val * 0x120) == iVar1) {
        for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
          Mem_AllocOrFree_0041df33
                    (local_8,*(int *)(&g_CardSlot_ConvertedManaCost + value * 0x5b20 + min_val * 0x120
                                     ),value,min_val);
          for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8];
              local_c = local_c + 1) {
            iVar1 = Card_IsTapped(local_8,local_c);
            if ((iVar1 != 0) &&
               (((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) !=
                0)) {
              Card_ApplyCombatDamage(local_8, local_c, *(int *)(&g_CardSlot_ConvertedManaCost + value * 0x5b20 + min_val * 0x120),
                           value,min_val);
            }
          }
        }
      }
      Pic_Subsystem_0044867e(value,min_val,4);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_0041459d
 * Entry Point: 0041459d
 * Size: 519 bytes
 */


undefined4 FUN_0041459d(int value,int min_val,int max_val)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  if ((((g_CurrentStepCode == 0xd7) && (g_EventSourceSlot == min_val)) &&
      (value == g_EventSourcePlayer)) && (value == DAT_006a4b5c)) {
    if (max_val == 0x7d) {
      g_CardEventResult = g_CardEventResult | 2;
    }
    if (max_val == 0x7e) {
      iVar1 = Pic_Subsystem_0045268f(0x44);
      if (*(int *)(&g_ActiveCardsInPlay + min_val * 0x120 + value * 0x5b20) == iVar1) {
        local_8 = 0;
        for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
          for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_10];
              local_c = local_c + 1) {
            if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_10 * 0x5b20) == DAT_006ff2e0
                 ) && ((&g_CardSlot_DamageReceived)[min_val * 0x120 + value * 0x5b20] ==
                       (&g_CardSlot_DamageReceived)[local_c * 0x120 + local_10 * 0x5b20])) &&
               (*(int *)(&g_CardSlot_TypeFlags + min_val * 0x120 + value * 0x5b20) ==
                *(int *)(&g_CardSlot_TypeFlags + local_c * 0x120 + local_10 * 0x5b20))) {
              local_8 = local_8 + *(int *)(&g_CardSlot_ConvertedManaCost +
                                          local_c * 0x120 + local_10 * 0x5b20);
            }
          }
        }
        iVar1 = *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20);
        if (local_8 <= *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20)) {
          iVar1 = local_8;
        }
        (&g_PlayerCreatureCount)[value] = (&g_PlayerCreatureCount)[value] + iVar1;
      }
      Pic_Subsystem_0044867e(value,min_val,4);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_004147a4
 * Entry Point: 004147a4
 * Size: 189 bytes
 */


undefined4 FUN_004147a4(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  
  if (((max_val == 0x72) || (max_val == 0x86)) || (max_val == 0x7e)) {
    g_DialogPromptHwnd = *(undefined4 *)(&g_CardSlot_TapState + min_val * 0x120 + value * 0x5b20);
    g_DuelArenaHwnd = *(undefined4 *)(&g_CardSlot_SicknessState + min_val * 0x120 + value * 0x5b20);
    uVar1 = (**(code **)(&DAT_0051aec8 +
                        *(int *)(&g_ActiveCardsInPlay + min_val * 0x120 + value * 0x5b20) * 0x34))
                      (value,min_val,max_val);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00414875
 * Entry Point: 00414875
 * Size: 210 bytes
 */


undefined4 FUN_00414875(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  
  if ((((max_val == 0x73) && (g_ScWillyScore == 10)) && (DAT_0063edc0 == value)) &&
     ((*(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) == 0 &&
      (g_CurrentStepCode == -1)))) {
    DAT_006a4920 = DAT_006a4920 | 3;
    uVar1 = 1;
  }
  else {
    if (max_val == 0x6d) {
      *(uint *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) | 1;
    }
    if (max_val == 0x72) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,4);
      Magic_ExecuteDrawPhase(value);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00414947
 * Entry Point: 00414947
 * Size: 378 bytes
 */


undefined4 FUN_00414947(int value,undefined4 min_val,int max_val)

{
  undefined4 uVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10 [3];
  
  if (max_val == 0x74) {
    uVar1 = 1;
  }
  else {
    if (max_val == 0x71) {
      iVar2 = Ai_Subsystem_004cc814
                        (value,s_Natural_Selection__0051974c,0,s_See_your_library_00519738,
                         s_See_opponent_s_library_00519720,(char *)0x0);
      if (iVar2 == 0) {
        local_14 = value;
      }
      else {
        local_14 = 1 - value;
      }
      while( true ) {
        for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
          local_10[local_18] = *(int *)(&DAT_0069e730 + local_18 * 4 + local_14 * 2000);
        }
        Pic_Load_004509e8(value,(int)local_10,3,s_Next_3__R_to_L__library_cards_00519768,0);
        iVar2 = Ai_Subsystem_004cc814
                          (value,s_Natural_Selection__005197bc,0,s_No_change_005197b0,
                           s_Rearrange_these_cards_00519798,s_Shuffle_deck_00519788);
        if (iVar2 != 1) break;
        for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
          do {
            iVar2 = Math_RandomRange(3);
          } while (local_10[iVar2] == -2);
          *(int *)(&DAT_0069e730 + local_18 * 4 + local_14 * 2000) = local_10[iVar2];
          local_10[iVar2] = -2;
        }
      }
      if (iVar2 == 2) {
        Pic_Subsystem_00452276(local_14);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00414ac1
 * Entry Point: 00414ac1
 * Size: 723 bytes
 */


undefined4 FUN_00414ac1(int value,int min_val,int max_val)

{
  int iVar1;
  undefined4 uVar2;
  
  if (max_val == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (DAT_006b2d3c == -1) {
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) =
           g_TurnCounter;
      if ((((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20) * 0x34] &
           0x18) == 0) ||
         (iVar1 = Rules_ParseFilter_0040360b
                            (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,value,2,2,0,0,0,0,0,0,0,-1,-1,
                             0xffffffff,0xffffffff,2,0,0), iVar1 == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 99;
      }
    }
  }
  else {
    if (((max_val == 0x6c) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value)) {
      if (DAT_006b2d3c == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20) = DAT_006b2d2c;
        (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 1;
      }
    }
    if (max_val == 0x71) {
      iVar1 = Pic_Subsystem_00451291
                        (value,*(int *)(&g_CardSlot_CardId +
                                       *(int *)(&g_CardSlot_AttachedAura +
                                               min_val * 0x120 + value * 0x5b20) * 0x120 +
                                       *(int *)(&g_CardSlot_CombatTarget +
                                               min_val * 0x120 + value * 0x5b20) * 0x5b20));
      if (iVar1 != -1) {
        (&DAT_006a5f4d)[iVar1 * 0x120 + value * 0x5b20] = 0x10;
        *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + value * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + iVar1 * 0x120 + value * 0x5b20) | 8;
        g_TurnCounter =
             *(undefined4 *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20);
        g_DuelModeFlags = g_DuelModeFlags | 0x400;
        Pic_Subsystem_0042ac1f(value,iVar1);
        g_DuelModeFlags = g_DuelModeFlags & 0xfffffbff;
      }
      (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 0;
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_00414f59
 * Entry Point: 00414f59
 * Size: 295 bytes
 */


undefined4 FUN_00414f59(int value,int min_val,int max_val)

{
  DAT_006ff4ac = 1;
  DAT_006ff2d4 = 0xffffffff;
  if ((((((&g_CardSlot_Flags)[min_val * 0x120 + value * 0x5b20] & 0x10) == 0) &&
       (((&g_MasterCardColorTable)[max_val * 0x34] & 1) != 0)) &&
      (((&DAT_0051aed1)[max_val * 0x34] & 0x10) != 0)) &&
     ((((&g_CardSlot_Flags)[min_val * 0x120 + value * 0x5b20] & 0x10) == 0 &&
      (((&g_MasterCardColorTable)[max_val * 0x34] & 1) != 0)))) {
    Magic_TriggerCardEvent(value,min_val,0x6d,1 - value,0xffffffff);
    if (((&g_CardSlot_Flags)[min_val * 0x120 + value * 0x5b20] & 0x10) != 0) {
      Magic_BroadcastCardEvent(value,min_val,0x81);
    }
  }
  DAT_006ff4ac = 0;
  return 0;
}

/*
 * Decompiled function: FUN_00415080
 * Entry Point: 00415080
 * Size: 126 bytes
 */


undefined4 FUN_00415080(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  
  if (max_val == 0x74) {
    if ((value == g_TurnPlayer) || (0x14 < g_ScWillyScore)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (max_val == 0x71) {
      Card_ApplyTriggerEffect(value,min_val,DAT_0068a658,-1,-1);
      Pic_Subsystem_0044867e(value,min_val,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00415d48
 * Entry Point: 00415d48
 * Size: 176 bytes
 */


undefined4 FUN_00415d48(int x,int y)

{
  if (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) == 0) {
    *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
    if (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] & 1) != 0) {
      DAT_006ff2d4 = 0xffffffff;
    }
    Magic_BroadcastCardEvent(x,y,0x81);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00416059
 * Entry Point: 00416059
 * Size: 208 bytes
 */


undefined4 FUN_00416059(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  int iVar2;
  
  if (max_val == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((max_val == 0x6c) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value)) {
      Glue_Subsystem_004df8ba(value,min_val);
    }
    if (max_val == 0x71) {
      iVar2 = Glue_Subsystem_004dfb23(value,min_val,0x71,4);
      if (iVar2 != 0) {
        Mem_AllocOrFree_0041df33(value,2,value,min_val);
      }
      (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 0;
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00416129
 * Entry Point: 00416129
 * Size: 249 bytes
 */


undefined4 FUN_00416129(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (max_val == 0x74) {
    uVar1 = 1;
  }
  else {
    if (max_val == 0x71) {
      for (local_c = 0; local_c < 2; local_c = local_c + 1) {
        for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_c]; local_8 = local_8 + 1)
        {
          iVar2 = Card_IsTapped(local_c,local_8);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120) * 0x34] & 2) != 0)
             ) {
            Card_ApplyTriggerEffect(value,min_val,DAT_006ff374,local_c,local_8);
          }
        }
      }
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00416cda
 * Entry Point: 00416cda
 * Size: 92 bytes
 */


undefined4 FUN_00416cda(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  
  if (max_val == 0x74) {
    uVar1 = 1;
  }
  else {
    if (max_val == 0x71) {
      Card_ApplyTriggerEffect(value,min_val,DAT_0068a670,-1,-1);
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00417919
 * Entry Point: 00417919
 * Size: 139 bytes
 */


undefined4 FUN_00417919(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  
  if (max_val == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((max_val == 0x32) &&
       (((&g_CardSlot_Flags)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120] & 4) !=
        0)) {
      g_CardEventResult = g_CardEventResult + 2;
    }
    if ((max_val == 0x22) || (max_val == 199)) {
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_004179a4
 * Entry Point: 004179a4
 * Size: 179 bytes
 */


undefined4 FUN_004179a4(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  int iVar2;
  
  if (max_val == 0x74) {
    uVar1 = 1;
  }
  else {
    if (max_val == 0x71) {
      DAT_00538728 = value;
      DAT_0053872c = min_val;
      Glue_Subsystem_004e65e1(FUN_00417a57,g_TurnPlayer);
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    if (max_val == 0x3b) {
      iVar2 = Font_DrawString(value,5,2);
      if (iVar2 != 0) {
        iVar2 = Font_DrawString(value,7,3);
        if (iVar2 != 0) {
          *(int *)(&DAT_00695eb0 + value * 4) = *(int *)(&DAT_00695eb0 + value * 4) + 1;
          *(int *)(&DAT_00695eb8 + value * 4) = *(int *)(&DAT_00695eb8 + value * 4) + 1;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00417a57
 * Entry Point: 00417a57
 * Size: 178 bytes
 */


undefined4 FUN_00417a57(int x,int y)

{
  int iVar1;
  
  if (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 4) != 0) {
    iVar1 = Card_ApplyTriggerEffect(DAT_00538728,DAT_0053872c,DAT_006a2854,x,y);
    if (iVar1 != -1) {
      *(undefined2 *)(&DAT_006a5f48 + iVar1 * 0x120 + DAT_00538728 * 0x5b20) = 1;
      *(undefined2 *)(&DAT_006a5f4a + iVar1 * 0x120 + DAT_00538728 * 0x5b20) = 1;
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00417b09
 * Entry Point: 00417b09
 * Size: 176 bytes
 */


undefined4 FUN_00417b09(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  int iVar2;
  
  if (max_val == 0x74) {
    uVar1 = 1;
  }
  else {
    if (max_val == 0x71) {
      DAT_00538740 = value;
      DAT_0053873c = min_val;
      Glue_Subsystem_004e65e1(FUN_00417bb9,1 - g_TurnPlayer);
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    if (max_val == 0x3b) {
      iVar2 = Font_DrawString(value,5,1);
      if (iVar2 != 0) {
        iVar2 = Font_DrawString(value,7,2);
        if (iVar2 != 0) {
          *(int *)(&DAT_00695eb8 + value * 4) = *(int *)(&DAT_00695eb8 + value * 4) + 3;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00417bb9
 * Entry Point: 00417bb9
 * Size: 221 bytes
 */


undefined4 FUN_00417bb9(int x,int y)

{
  int iVar1;
  
  if (((&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20] != -1) &&
     (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 4) == 0)) {
    iVar1 = Card_ApplyTriggerEffect(DAT_00538740,DAT_0053873c,DAT_006a2854,x,y);
    if (iVar1 != -1) {
      *(undefined2 *)(&DAT_006a5f48 + DAT_00538740 * 0x5b20 + iVar1 * 0x120) = 0;
      *(undefined2 *)(&DAT_006a5f4a + DAT_00538740 * 0x5b20 + iVar1 * 0x120) = 3;
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00417c96
 * Entry Point: 00417c96
 * Size: 674 bytes
 */


undefined4 FUN_00417c96(int value,int min_val,int max_val)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 arg_11;
  int iVar7;
  uint uVar8;
  undefined4 arg_13;
  uint uVar9;
  undefined4 arg_14;
  uint uVar10;
  undefined4 arg_15;
  uint uVar11;
  undefined4 arg_16;
  uint uVar12;
  undefined4 arg_17;
  char *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (max_val == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    bVar1 = Card_SetTapState(value, min_val, 1);
    iVar4 = 1 << (bVar1 & 0x1f);
    arg_11 = 0;
    uVar2 = Glue_Subsystem_004d0a42(value,min_val);
    uVar2 = UI_PaintBigCardInfo((int *)0x0,0,value,2,2,0x200,2,0x40,0,uVar2,arg_11,iVar4,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((max_val == 0x6c) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value)) {
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = s_Target_Creature_00519974;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar4 = -1;
      bVar1 = Card_SetTapState(value, min_val, 1);
      uVar5 = 1 << (bVar1 & 0x1f);
      uVar6 = 0;
      uVar3 = Glue_Subsystem_004d0a42(value,min_val);
      iVar4 = Duel_ChooseTarget
                        (value,2,1 - value,0x200,2,0x40,0,uVar3,uVar6,uVar5,iVar4,iVar7,uVar8,uVar9,
                         uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
      if (iVar4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 1;
      }
    }
    if (max_val == 0x71) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20);
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar4 = -1;
      bVar1 = Card_SetTapState(value, min_val, 1);
      uVar5 = 1 << (bVar1 & 0x1f);
      uVar6 = 0;
      uVar3 = Glue_Subsystem_004d0a42(value,min_val);
      iVar4 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,value,2,2,0x200,2,0x40,0,uVar3,uVar6,uVar5,
                         iVar4,iVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
      if (iVar4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(local_c,local_8,1);
      }
      (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 0;
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_004186ac
 * Entry Point: 004186ac
 * Size: 126 bytes
 */


bool FUN_004186ac(int value,int min_val,int max_val)

{
  bool bVar1;
  
  if (max_val == 0x74) {
    if (value == g_CurrentTurnPhase) {
      bVar1 = true;
    }
    else {
      bVar1 = value != g_TurnPlayer;
    }
  }
  else {
    if (max_val == 0x71) {
      Glue_Subsystem_004e65e1(FUN_0041872f,-1);
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    bVar1 = false;
  }
  return bVar1;
}

/*
 * Decompiled function: FUN_0041872f
 * Entry Point: 0041872f
 * Size: 86 bytes
 */


undefined4 FUN_0041872f(int x,int y)

{
  if (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 4) != 0) {
    Card_ApplyCombatDamage(x,y,1,g_EventSourcePlayer,g_EventSourceSlot);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00418c59
 * Entry Point: 00418c59
 * Size: 209 bytes
 */


void FUN_00418c59(int x,int y,int width,undefined1 target_slot)

{
  int local_8;
  
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    if ((char)(&DAT_006a602f)[y * 0x120 + x * 0x5b20 + local_8] == width) {
      (&DAT_006a602f)[y * 0x120 + x * 0x5b20 + local_8] = target_slot;
    }
  }
  if ((&DAT_006a602f)[width + x * 0x5b20 + y * 0x120] == '\0') {
    (&DAT_006a602f)[width + x * 0x5b20 + y * 0x120] = target_slot;
  }
  return;
}

/*
 * Decompiled function: FUN_004194cf
 * Entry Point: 004194cf
 * Size: 213 bytes
 */


void FUN_004194cf(int x,int y,int width,undefined1 target_slot)

{
  int local_8;
  
  for (local_8 = 1; local_8 < 6; local_8 = local_8 + 1) {
    if ((char)(&DAT_006a6029)[local_8 + y * 0x120 + x * 0x5b20] == width) {
      (&DAT_006a6029)[local_8 + y * 0x120 + x * 0x5b20] = target_slot;
    }
  }
  if ((&DAT_006a6029)[width + y * 0x120 + x * 0x5b20] == '\0') {
    (&DAT_006a6029)[width + y * 0x120 + x * 0x5b20] = target_slot;
  }
  return;
}

/*
 * Decompiled function: FUN_0041a245
 * Entry Point: 0041a245
 * Size: 636 bytes
 */


uint FUN_0041a245(int value,int min_val,int max_val)

{
  uint uVar1;
  int local_8;
  
  if (max_val == 0x74) {
    if (((&g_MasterCardColorTable)[DAT_0068a708 * 0x34] & 0x40) == 0) {
      uVar1 = 0;
    }
    else {
      Ai_GetOpponentPlayerScore(0);
      if (value == g_CurrentTurnPhase) {
        uVar1 = g_DuelModeFlags & 0x20;
      }
      else if (((g_DuelModeFlags & 0x20) == 0) || (g_TurnPlayer != g_CurrentTurnPhase)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    if (((max_val == 0x6c) && (min_val == g_EventSourceSlot)) && (value == g_EventSourcePlayer)) {
      if (local_8 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_OriginalCardId + value * 0x5b20 + min_val * 0x120) = local_8;
        (&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120] = DAT_0063ee20;
      }
    }
    if (max_val == 0x71) {
      if (((*(int *)(&g_CardSlot_OriginalCardId + value * 0x5b20 + min_val * 0x120) != -1) &&
          (((&g_CardSlot_Flags)
            [*(int *)(&g_CardSlot_OriginalCardId + value * 0x5b20 + min_val * 0x120) * 0x120 +
             (char)(&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120] * 0x5b20] & 0x20) != 0))
         && (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId +
                       *(int *)(&g_CardSlot_OriginalCardId + value * 0x5b20 + min_val * 0x120) * 0x120
                       + (char)(&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120] * 0x5b20) *
               0x34] & 0x40) != 0)) {
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_Toughness)[value * 0x5b20 + min_val * 0x120],
                   *(int *)(&g_CardSlot_OriginalCardId + value * 0x5b20 + min_val * 0x120),2);
      }
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0041a4c6
 * Entry Point: 0041a4c6
 * Size: 695 bytes
 */


undefined4 FUN_0041a4c6(int value,int min_val,int max_val)

{
  int iVar1;
  undefined4 uVar2;
  
  if (max_val == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (DAT_006b2d3c == -1) {
      uVar2 = 0;
    }
    else {
      iVar1 = Rules_ParseFilter_0040360b
                        (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,value,2,2,0,0,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 99;
      }
    }
  }
  else {
    if (((max_val == 0x6c) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value)) {
      if ((value == g_CurrentTurnPhase) || (DAT_006b2d3c != -1)) {
        *(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20) = DAT_006b2d2c;
        (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 1;
      }
      else {
        g_ActivePlayer = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + -0x24;
    }
    if ((max_val == 0x38) && (1 < *(int *)(&DAT_0063edd8 + value * 0x20))) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
    }
    if (max_val == 0x71) {
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20),
                         (char *)0x0,value,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else if (((&g_CardSlot_Flags)
                [*(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20) * 0x120] & 0x20
               ) != 0) {
        Pic_Subsystem_0044867e
                  (*(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20),1);
      }
      (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 0;
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0041a782
 * Entry Point: 0041a782
 * Size: 1594 bytes
 */


undefined4 FUN_0041a782(int value,int min_val,int max_val)

{
  int arg_2_00;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  int local_14;
  int local_8;
  
  if (max_val == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (DAT_006b2d3c == -1) {
      uVar2 = 0;
    }
    else if ((g_ActivePlayerPriority == value) && (iVar1 = Font_DrawString(value,7,2), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      iVar1 = Rules_ParseFilter_0040360b
                        (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,value,2,2,0,0,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 99;
      }
    }
  }
  else {
    if (((max_val == 0x6c) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value)) {
      if (DAT_006b2d3c == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20) = DAT_006b2d2c;
        (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 1;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) =
             g_TurnCounter;
      }
    }
    if (max_val == 0x71) {
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20),
                         (char *)0x0,value,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        iVar1 = *(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20);
        arg_2_00 = *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20);
        if (iVar1 == g_CurrentTurnPhase) {
          Magic_PushSpellStack(value,min_val,0x7e,0,0);
          local_8 = Ai_CalcManaRequirement_004ba890
                              (iVar1,0,*(int *)(&g_CardSlot_ConvertedManaCost +
                                               min_val * 0x120 + value * 0x5b20));
          Magic_DropTopSpell();
          g_ActivePlayer = 0;
        }
        else {
          iVar3 = Font_DrawString(iVar1,7,1);
          if (iVar3 == 0) {
            local_8 = 0;
          }
          else {
            local_8 = Ai_CalcManaRequirement_004ba890
                                (iVar1,0,*(int *)(&g_CardSlot_ConvertedManaCost +
                                                 min_val * 0x120 + value * 0x5b20));
          }
        }
        if (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20)) {
          local_14 = 0;
          while ((local_14 < 7 &&
                 (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20)
                 ))) {
            for (; (0 < *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) &&
                   (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost +
                                      min_val * 0x120 + value * 0x5b20))); local_8 = local_8 + 1) {
              *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) =
                   *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) + -1;
              *(int *)(&DAT_0063eeac + iVar1 * 0x20) = *(int *)(&DAT_0063eeac + iVar1 * 0x20) + -1;
            }
            local_14 = local_14 + 1;
          }
          local_18 = 0;
          while ((local_18 < (int)(&g_PlayerActiveCardCount)[iVar1] &&
                 (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20)
                 ))) {
            iVar3 = Card_IsTapped(iVar1,local_18);
            if (((iVar3 != 0) &&
                ((((&g_MasterCardColorTable)
                   [*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + iVar1 * 0x5b20) * 0x34] & 1) !=
                  0 && (((&g_CardSlot_Flags)[local_18 * 0x120 + iVar1 * 0x5b20] & 0x10) == 0)))) &&
               ((((&DAT_006a5f3e)[local_18 * 0x120 + iVar1 * 0x5b20] & 3) == 0 ||
                (((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + iVar1 * 0x5b20) * 0x34] & 2) ==
                 0)))) {
              Ai_Subsystem_004bd23f(iVar1,local_18);
              local_14 = 0;
              while ((local_14 < 7 &&
                     (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost +
                                        min_val * 0x120 + value * 0x5b20)))) {
                for (; (0 < *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) &&
                       (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost +
                                          min_val * 0x120 + value * 0x5b20))); local_8 = local_8 + 1)
                {
                  *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) =
                       *(int *)(&DAT_0063ee90 + local_14 * 4 + iVar1 * 0x20) + -1;
                  *(int *)(&DAT_0063eeac + iVar1 * 0x20) =
                       *(int *)(&DAT_0063eeac + iVar1 * 0x20) + -1;
                }
                local_14 = local_14 + 1;
              }
            }
            local_18 = local_18 + 1;
          }
        }
        if (local_8 < *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20)) {
          Pic_Subsystem_0044867e(iVar1,arg_2_00,1);
        }
      }
      (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 0;
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0041adc1
 * Entry Point: 0041adc1
 * Size: 995 bytes
 */


undefined4 FUN_0041adc1(int value,int min_val,int max_val)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  
  if (max_val == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (DAT_006b2d3c == -1) {
      uVar3 = 0;
    }
    else if ((g_ActivePlayerPriority == value) && (iVar2 = Font_DrawString(value,7,2), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      local_c = (int)(char)(&DAT_0051aec0)
                           [*(int *)(&g_CardSlot_CardId +
                                    DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20) * 0x34];
      if (local_c == -1) {
        local_c = g_TurnCounter;
      }
      cVar1 = (&DAT_0051aebf)
              [*(int *)(&g_CardSlot_CardId + DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20) * 0x34];
      *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) = cVar1 + local_c;
      iVar2 = Font_DrawString(value,2,1);
      if (((iVar2 == 0) || (iVar2 = Font_DrawString(value,7,cVar1 + local_c + 1), iVar2 == 0)) ||
         (iVar2 = Rules_ParseFilter_0040360b
                            (DAT_006b2d3c,DAT_006b2d2c,(char *)0x0,value,2,2,0,0,0,0,0,0,0,-1,-1,
                             0xffffffff,0xffffffff,2,0,0), iVar2 == 0)) {
        uVar3 = 0;
      }
      else {
        DAT_006fe3f4 = 1;
        uVar3 = 99;
      }
    }
  }
  else {
    if ((((max_val == 0x6c) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value))
       && (DAT_006b2d3c != -1)) {
      DAT_006b2d48 = 1;
      Ai_CalcManaRequirement_004ba890
                (value,0,*(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20));
      if (g_ActivePlayer != 1) {
        *(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20) = DAT_006b2d3c;
        *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20) = DAT_006b2d2c;
        (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 1;
        g_TurnCounter = *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20);
      }
    }
    if (max_val == 0x71) {
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20),
                         (char *)0x0,value,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else if (((&g_CardSlot_Flags)
                [*(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20) * 0x120] & 0x20
               ) != 0) {
        Pic_Subsystem_0044867e
                  (*(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20),2);
      }
      (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 0;
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}

/*
 * Decompiled function: FUN_0041b695
 * Entry Point: 0041b695
 * Size: 519 bytes
 */


uint FUN_0041b695(int value,int min_val,int max_val)

{
  uint uVar1;
  int local_10;
  
  if (max_val == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = (&DAT_006a2828)[value] & 2;
  }
  else {
    if (((max_val == 0x6c) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value)) {
      if (local_10 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) = local_10;
        (&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] = DAT_0063ee20;
      }
    }
    if (max_val == 0x71) {
      if (*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) != -1) {
        FUN_0040d875(value,1,(int)(char)(&DAT_0051aebf)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 *(int *)(&g_CardSlot_OriginalCardId +
                                                         min_val * 0x120 + value * 0x5b20) * 0x120 +
                                                 (char)(&g_CardSlot_Toughness)
                                                       [min_val * 0x120 + value * 0x5b20] * 0x5b20) *
                                         0x34] +
                             (int)(char)(&DAT_0051aec0)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 *(int *)(&g_CardSlot_OriginalCardId +
                                                         min_val * 0x120 + value * 0x5b20) * 0x120 +
                                                 (char)(&g_CardSlot_Toughness)
                                                       [min_val * 0x120 + value * 0x5b20] * 0x5b20) *
                                         0x34]);
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20),2);
      }
      (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] = 0;
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0041b89c
 * Entry Point: 0041b89c
 * Size: 158 bytes
 */


undefined4 FUN_0041b89c(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  
  if (max_val == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((max_val == 0x6c) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value)) {
      if ((int)(&DAT_006b3008)[value] < 8) {
        g_SpellStackDepth = g_SpellStackDepth + -0x3c;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    if (max_val == 0x71) {
      FUN_0040d875(value,1,3);
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041b93a
 * Entry Point: 0041b93a
 * Size: 42 bytes
 */


void Mem_AllocOrFree_0041b93a(int value,int min_val,int max_val)

{
  Prompts_Load_0041b98a(value,min_val,max_val,g_TurnCounter);
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041b964
 * Entry Point: 0041b964
 * Size: 38 bytes
 */


void Mem_AllocOrFree_0041b964(int value,int min_val,int max_val)

{
  Prompts_Load_0041b98a(value,min_val,max_val,3);
  return;
}

/*
 * Decompiled function: FUN_0041cb9a
 * Entry Point: 0041cb9a
 * Size: 1029 bytes
 */


uint FUN_0041cb9a(int value,int min_val,int max_val)

{
  uint uVar1;
  int iVar2;
  
  if (max_val == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = g_DuelModeFlags & 4;
  }
  else {
    if (((max_val == 0x6c) && (g_EventSourceSlot == min_val)) && (value == g_EventSourcePlayer)) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20) * 0x5b20) ==
          DAT_006ff2e0) {
        (&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] =
             (&g_CardSlot_Toughness)
             [*(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20) * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) =
             *(undefined4 *)
              (&g_CardSlot_OriginalCardId +
              *(int *)(&g_CardSlot_AttachedAura + min_val * 0x120 + value * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + min_val * 0x120 + value * 0x5b20) * 0x5b20);
        *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) = g_TurnCounter;
      }
      else {
        g_ActivePlayer = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + -0x30;
    }
    if (((max_val == 0x6e) &&
        (*(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) != -1)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId +
                 g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) ==
         *(int *)(&g_CardSlot_OriginalCardId + min_val * 0x120 + value * 0x5b20) &&
        ((&g_CardSlot_Toughness)[min_val * 0x120 + value * 0x5b20] ==
         (&g_CardSlot_Toughness)[g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120]))))
    {
      iVar2 = Math_Clamp(*(int *)(&g_CardSlot_ConvertedManaCost +
                                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120),0,
                           *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20))
      ;
      *(int *)(&g_CardSlot_ConvertedManaCost +
              g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) =
           *(int *)(&g_CardSlot_ConvertedManaCost +
                   g_EventSourcePlayer * 0x5b20 + g_EventSourceSlot * 0x120) - iVar2;
      *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) - iVar2;
    }
    if (max_val == 0x73) {
      if (((g_DuelModeFlags & 4) == 0) || (iVar2 = Font_DrawString(value,7,1), iVar2 == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      if ((max_val == 0x6d) && (Ai_CalcManaRequirement_004ba890(value,0,-1), g_ActivePlayer != 1)) {
        *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) +
             g_TurnCounter;
      }
      if ((max_val == 0x22) || (max_val == 199)) {
        Pic_Subsystem_0044867e(value,min_val,1);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0041cf9f
 * Entry Point: 0041cf9f
 * Size: 117 bytes
 */


undefined4 FUN_0041cf9f(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  
  if (max_val == 0x74) {
    if (value == g_CurrentTurnPhase) {
      uVar1 = 1;
    }
    else {
      uVar1 = *(undefined4 *)(&DAT_006b3028 + value * 4);
    }
  }
  else {
    if (max_val == 0x71) {
      (&g_PlayerCreatureCount)[value] =
           (&g_PlayerCreatureCount)[value] + *(int *)(&DAT_006b3028 + value * 4) * 2;
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0041d019
 * Entry Point: 0041d019
 * Size: 402 bytes
 */


undefined4 FUN_0041d019(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (max_val == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((max_val == 0x6c) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20) = 6;
    }
    if (max_val == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        Mem_AllocOrFree_0041df33
                  (local_8,*(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20),
                   value,min_val);
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = Card_IsTapped(local_8,local_c);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)
             ) {
            Card_ApplyCombatDamage(local_8,local_c,
                         *(int *)(&g_CardSlot_ConvertedManaCost + min_val * 0x120 + value * 0x5b20),
                         value,min_val);
          }
        }
      }
      Pic_Subsystem_0044867e(value,min_val,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0041d411
 * Entry Point: 0041d411
 * Size: 1173 bytes
 */


undefined4 FUN_0041d411(int value,int min_val,int max_val)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  undefined4 arg_15;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  int local_508;
  undefined4 local_504 [320];
  
  if (max_val == 0x74) {
    if ((g_ActivePlayerPriority == value) && (iVar1 = Font_DrawString(value,7,3), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      arg_19_00 = 0;
      arg_18_00 = 0;
      arg_17_00 = 0;
      arg_16_00 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13_00 = 0xffffffff;
      arg_12_00 = 0;
      arg_11_00 = 0;
      uVar2 = Glue_Subsystem_004d0a42(value,min_val);
      uVar2 = UI_PaintBigCardInfo((int *)0x0,0,value,2,2,0x200,2,0,0,uVar2,arg_11_00,arg_12_00,arg_13_00,
                           arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
    }
  }
  else {
    if ((((max_val == 0x6c) && (g_EventSourceSlot == min_val)) && (g_EventSourcePlayer == value))
       && (iVar1 = Palette_Subsystem_004a7bcd(value,min_val,(int)local_504), iVar1 != 0)) {
      for (local_508 = 0; local_508 < g_TurnCounter; local_508 = local_508 + 1) {
        iVar3 = Math_RandomRange(iVar1);
        *(undefined4 *)
         (&g_CardSlot_CombatTarget +
         min_val * 0x120 +
         value * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] * 8) =
             local_504[iVar3 * 2];
        *(undefined4 *)
         (&g_CardSlot_AttachedAura +
         min_val * 0x120 +
         value * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] * 8) =
             local_504[iVar3 * 2 + 1];
        (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] =
             (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] + '\x01';
      }
    }
    if (max_val == 0x71) {
      if (g_IsAiThinking != 1) {
        Duel_PlaySoundById(0x2c);
        Sleep(0xdac);
      }
      while ((&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] != '\0') {
        (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] =
             (&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] + -1;
        arg_20 = 0;
        arg_19 = 0;
        arg_18 = 0;
        arg_17 = 0xffffffff;
        arg_16 = 0xffffffff;
        iVar3 = -1;
        iVar1 = -1;
        arg_13 = 0;
        arg_12 = 0;
        arg_11 = Glue_Subsystem_004d0a42(value,min_val);
        iVar1 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   min_val * 0x120 +
                                   value * 0x5b20 +
                                   (char)(&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] *
                                   8),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   min_val * 0x120 +
                                   value * 0x5b20 +
                                   (char)(&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] *
                                   8),(char *)0x0,value,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar1,
                           iVar3,arg_16,arg_17,arg_18,arg_19,arg_20);
        if (iVar1 != 0) {
          *(short *)(&DAT_006a5f4a +
                    *(int *)(&g_CardSlot_AttachedAura +
                            min_val * 0x120 +
                            value * 0x5b20 +
                            (char)(&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] * 8) *
                    0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                    min_val * 0x120 +
                                    value * 0x5b20 +
                                    (char)(&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] *
                                    8) * 0x5b20) =
               *(short *)(&DAT_006a5f4a +
                         *(int *)(&g_CardSlot_AttachedAura +
                                 min_val * 0x120 +
                                 value * 0x5b20 +
                                 (char)(&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] * 8)
                         * 0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                           min_val * 0x120 +
                                           value * 0x5b20 +
                                           (char)(&g_CardSlot_TurnPlayed)
                                                 [min_val * 0x120 + value * 0x5b20] * 8) * 0x5b20) +
               -1;
          *(int *)(&DAT_006a5f7c +
                  *(int *)(&g_CardSlot_AttachedAura +
                          min_val * 0x120 +
                          value * 0x5b20 +
                          (char)(&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] * 8) *
                  0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                  min_val * 0x120 +
                                  value * 0x5b20 +
                                  (char)(&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] * 8
                                  ) * 0x5b20) =
               *(int *)(&DAT_006a5f7c +
                       *(int *)(&g_CardSlot_AttachedAura +
                               min_val * 0x120 +
                               value * 0x5b20 +
                               (char)(&g_CardSlot_TurnPlayed)[min_val * 0x120 + value * 0x5b20] * 8) *
                       0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                       min_val * 0x120 +
                                       value * 0x5b20 +
                                       (char)(&g_CardSlot_TurnPlayed)
                                             [min_val * 0x120 + value * 0x5b20] * 8) * 0x5b20) +
               0x1000000;
          if (g_IsAiThinking != 1) {
            Duel_PlaySoundById(0x2b);
          }
        }
      }
      Pic_Subsystem_0044867e(value,min_val,2);
    }
    uVar2 = 0;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0041d8a6
 * Entry Point: 0041d8a6
 * Size: 156 bytes
 */


int FUN_0041d8a6(int value)

{
  int local_8;
  
  local_8 = g_MasterCardCount;
  while( true ) {
    if (g_MasterCardCount + 0x10 <= local_8) {
      Engine_ReportFatalError(s_AddType_error_00519bfc);
      return -1;
    }
    if (*(int *)(&g_MasterCardTypeTable + local_8 * 0x34) == -1) break;
    local_8 = local_8 + 1;
  }
  memcpy(&g_MasterCardTable + local_8 * 0x34,&g_MasterCardTable + value * 0x34,0x34);
  return local_8;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041d942
 * Entry Point: 0041d942
 * Size: 33 bytes
 */


void Mem_AllocOrFree_0041d942(int value)

{
  *(undefined4 *)(&g_MasterCardTypeTable + value * 0x34) = 0xffffffff;
  return;
}

/*
 * Decompiled function: Card_UntapCard
 * Entry Point: 0041d963
 * Size: 106 bytes
 */


int Card_UntapCard(int value,int min_val,int max_val)

{
  if ((&DAT_006a602f)[max_val + value * 0x5b20 + min_val * 0x120] != '\0') {
    max_val = (int)(char)(&DAT_006a602f)[max_val + value * 0x5b20 + min_val * 0x120];
  }
  return max_val;
}

/*
 * Decompiled function: Card_SetTapState
 * Entry Point: 0041d9d2
 * Size: 106 bytes
 */


int Card_SetTapState(int value,int min_val,int max_val)

{
  if ((&DAT_006a6029)[max_val + value * 0x5b20 + min_val * 0x120] != '\0') {
    max_val = (int)(char)(&DAT_006a6029)[max_val + value * 0x5b20 + min_val * 0x120];
  }
  return max_val;
}

/*
 * Decompiled function: FUN_0041da41
 * Entry Point: 0041da41
 * Size: 294 bytes
 */


void FUN_0041da41(int x,int y)

{
  int min_val;
  uint local_c;
  
  DAT_00695f08 = x;
  DAT_006b2e14 = y;
  FUN_00476205(g_TurnPlayer,0xd4,s_Card_leaving_play_00519c0c,0);
  *(undefined4 *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) = 0xffffffff;
  Pic_Subsystem_00448e29(x,y);
  if (((&g_CardSlot_Abilities1)[y * 0x120 + x * 0x5b20] & 0x10) == 0) {
    local_c = (uint)(((&DAT_006a5f3d)[y * 0x120 + x * 0x5b20] & 0x10) != 0);
    min_val = Pic_Subsystem_00451291
                      (local_c,*(int *)(&g_ActiveCardsInPlay + y * 0x120 + x * 0x5b20));
    if (min_val != -1) {
      Ai_Subsystem_004cc3f8(local_c,min_val,8,2);
    }
    (&DAT_006b3008)[local_c] = (&DAT_006b3008)[local_c] + 1;
  }
  return;
}

/*
 * Decompiled function: Card_ApplyCombatDamage
 * Entry Point: 0041db67
 * Size: 972 bytes
 */


int Card_ApplyCombatDamage(int value,int min_val,int max_val,int target_slot,int flags)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_8;
  
  if (((value == -1) || (target_slot == -1)) || (max_val < 1)) {
    iVar1 = -1;
  }
  else {
    if (min_val == -1) {
      local_8 = value;
    }
    else {
      local_8 = target_slot;
    }
    iVar1 = Pic_Subsystem_00451291(local_8,DAT_006ff2e0);
    if (iVar1 != -1) {
      *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + local_8 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + local_8 * 0x5b20) |
           CONCAT31((uint3)((local_8 == 0) - 1 >> 8) & 0x10,2);
      (&g_CardSlot_Toughness)[iVar1 * 0x120 + local_8 * 0x5b20] = (undefined1)value;
      *(int *)(&g_CardSlot_OriginalCardId + iVar1 * 0x120 + local_8 * 0x5b20) = min_val;
      *(int *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + local_8 * 0x5b20) = max_val;
      (&g_CardSlot_DamageReceived)[iVar1 * 0x120 + local_8 * 0x5b20] = (undefined1)target_slot;
      *(int *)(&g_CardSlot_TypeFlags + iVar1 * 0x120 + local_8 * 0x5b20) = flags;
      if (flags == -1) {
        *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + local_8 * 0x5b20) = 0xef;
      }
      else {
        if ((*(int *)(&g_CardSlot_CardId + flags * 0x120 + target_slot * 0x5b20) == -1) ||
           (*(int *)(&g_CardSlot_CardId + flags * 0x120 + target_slot * 0x5b20) == g_StackObjectCardId)) {
          local_10 = *(int *)(&g_ActiveCardsInPlay + flags * 0x120 + target_slot * 0x5b20);
        }
        else {
          local_10 = *(int *)(&g_CardSlot_CardId + flags * 0x120 + target_slot * 0x5b20);
        }
        (&DAT_006a5f4d)[iVar1 * 0x120 + local_8 * 0x5b20] =
             (&DAT_006a5f4d)[flags * 0x120 + target_slot * 0x5b20];
        if (((&g_MasterCardColorTable)[local_10 * 0x34] & 0x40) != 0) {
          (&DAT_006a5f4d)[iVar1 * 0x120 + local_8 * 0x5b20] =
               (&DAT_006a5f4d)[iVar1 * 0x120 + local_8 * 0x5b20] | 0x40;
        }
        *(uint *)(&g_CardSlot_TargetSlot + iVar1 * 0x120 + local_8 * 0x5b20) =
             (uint)(byte)(&g_MasterCardColorTable)[local_10 * 0x34];
        if ((*(int *)(&g_MasterCardTypeTable + local_10 * 0x34) == DAT_0068a694) ||
           (*(int *)(&g_MasterCardTypeTable + local_10 * 0x34) == DAT_006a2848)) {
          *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + local_8 * 0x5b20) =
               *(undefined4 *)(&DAT_006a5f74 + flags * 0x120 + target_slot * 0x5b20);
        }
        else {
          iVar2 = FUN_00478aa4(*(int *)(&g_MasterCardTypeTable + local_10 * 0x34),target_slot,flags);
          *(uint *)(&DAT_006a5f74 + iVar1 * 0x120 + local_8 * 0x5b20) =
               iVar2 << 0x10 | *(uint *)(&g_MasterCardTypeTable + local_10 * 0x34);
        }
      }
      g_DuelModeFlags = g_DuelModeFlags | 2;
    }
  }
  return iVar1;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041df33
 * Entry Point: 0041df33
 * Size: 37 bytes
 */


void Mem_AllocOrFree_0041df33(int x,int y,int width,int height)

{
  Card_ApplyCombatDamage(x,-1,y,width,height);
  return;
}

/*
 * Decompiled function: FUN_0041e370
 * Entry Point: 0041e370
 * Size: 278 bytes
 */


undefined4 FUN_0041e370(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    Sprite_DrawScaled((int *)PTR_DAT_00519c20,*(int *)(x + 0x10),*(int *)(x + 0x14),
                      *(int *)(x + 0x18),*(int *)(x + 0x1c),*(int *)(x + 0x44 + y * 4));
    if ((y == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0041e486
 * Entry Point: 0041e486
 * Size: 508 bytes
 */


undefined4 FUN_0041e486(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    if (y == 2) {
      iVar3 = Ai_Util_004c3bc4(4);
      iVar4 = Ai_Util_004c3bc4(8);
      Surface_BlitToDevice((int *)PTR_DAT_005174e4,*(uint *)(x + 0x10),*(int *)(x + 0x14),
                   *(uint *)(x + 0x18),*(DWORD *)(x + 0x1c),(int *)g_DisplaySurfaceBackBuffer,
                   *(int *)(x + 0x10),*(int *)(x + 0x14));
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(x + 0x10) + iVar3,
                        *(int *)(x + 0x14) + iVar3,*(int *)(x + 0x18) - iVar4,
                        *(int *)(x + 0x1c) - iVar4,*(int *)(x + 0x4c));
      Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,*(uint *)(x + 0x10),*(int *)(x + 0x14),
                   *(uint *)(x + 0x18),*(DWORD *)(x + 0x1c),(int *)g_DisplaySurfaceScreen,
                   *(int *)(x + 0x10),*(int *)(x + 0x14));
      if (*(int *)(x + 0x28) != 0) {
        (**(code **)(x + 0x28))(x);
      }
    }
    else {
      Sprite_DrawScaled((int *)PTR_DAT_00519c20,*(int *)(x + 0x10),*(int *)(x + 0x14),
                        *(int *)(x + 0x18),*(int *)(x + 0x1c),*(int *)(x + 0x44 + y * 4)
                       );
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0041e682
 * Entry Point: 0041e682
 * Size: 566 bytes
 */


undefined4 FUN_0041e682(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  DWORD flags;
  uint target_slot;
  int iVar3;
  int iVar4;
  int iVar5;
  uint min_val;
  int local_8;
  
  if (y == 0) {
    local_8 = DAT_00676d78;
  }
  else {
    local_8 = DAT_00676d7c;
  }
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x10) + *(int *)(x + 0x18) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    flags = Ai_Util_004c3bc4(0x30);
    target_slot = Ai_Util_004c3bc4((*(short *)(local_8 + 4) * 0x30) / (int)*(short *)(local_8 + 6));
    iVar3 = Ai_Util_004c3bc4(0x20);
    min_val = iVar3 - (int)target_slot / 2;
    iVar3 = Ai_Util_004c3bc4(0x106);
    iVar3 = iVar3 - (int)flags / 2;
    if (y == 2) {
      iVar4 = Ai_Util_004c3bc4(4);
      iVar5 = Ai_Util_004c3bc4(8);
      Surface_BlitToDevice((int *)PTR_DAT_005174e4,min_val,iVar3,target_slot,flags,(int *)g_DisplaySurfaceBackBuffer
                   ,min_val,iVar3);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,min_val + iVar4,iVar3 + iVar4,target_slot - iVar5,
                        flags - iVar5,local_8);
      Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,min_val,iVar3,target_slot,flags,
                   (int *)g_DisplaySurfaceScreen,min_val,iVar3);
      if (*(int *)(x + 0x28) != 0) {
        (**(code **)(x + 0x28))(x);
      }
    }
    else {
      Sprite_DrawScaled((int *)PTR_DAT_00519c20,min_val,iVar3,target_slot,flags,local_8);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0041e8b8
 * Entry Point: 0041e8b8
 * Size: 981 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041e8b8(int x,int y)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint target_slot;
  DWORD flags;
  int *arg_6;
  uint arg_7;
  int arg_8;
  int local_58 [6];
  int local_40;
  int local_3c [6];
  int local_24;
  uint local_20;
  DWORD local_1c;
  uint local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = *(int *)(x + 0x2c) * 2 + -0x60;
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar3 = 0;
  }
  else {
    if (((_DAT_0067f374 & 1 << ((byte)local_8 & 0x1f)) != 0) &&
       (local_c = Glue_Subsystem_004f0de8(local_8), *(int *)(&DAT_0067bdbc + (local_8 / 2) * 4) != 0
       )) {
      if (y == 2) {
        local_14 = *(int *)(&DAT_00519dc4 + (*(int *)(x + 0x2c) + -0x31) * 0x54);
        local_20 = Ai_Util_004c3bc4(*(int *)(&DAT_00519f20 + local_8 * 0x10));
        local_24 = Ai_Util_004c3bc4(*(int *)(&DAT_00519f24 + local_8 * 0x10));
        local_18 = Ai_Util_004c3bc4(*(int *)(&DAT_00519f28 + local_8 * 0x10));
        local_1c = Ai_Util_004c3bc4(*(int *)(&DAT_00519f2c + local_8 * 0x10));
        local_10 = Ai_Util_004c3bc4(4);
        iVar2 = local_24;
        target_slot = local_18;
        flags = local_1c;
        arg_6 = (int *)g_DisplaySurfaceBackBuffer;
        arg_7 = local_20;
        arg_8 = local_24;
        iVar4 = Ai_Util_004c3bc4(0x148);
        Surface_BlitToDevice((int *)PTR_DAT_005174bc,local_20,iVar2 - iVar4,target_slot,flags,arg_6,arg_7,arg_8);
        Ai_Subsystem_004be3c4
                  (g_DisplaySurfaceBackBuffer,*(int *)(&DAT_00519f20 + local_8 * 0x10),
                   *(int *)(&DAT_00519f24 + local_8 * 0x10),
                   *(undefined4 *)(&DAT_00678330 + local_8 * 4),
                   *(int *)(&DAT_00519f28 + local_8 * 0x10),*(int *)(&DAT_00519f2c + local_8 * 0x10)
                  );
        Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,local_20 + local_10,local_24 + local_10,
                          local_18 + local_10 * -2,local_1c + local_10 * -2,local_14);
        iVar2 = DAT_006776a0;
        local_3c[5] = DAT_006776a0;
        local_3c[0] = 0x6c;
        local_3c[1] = 0xbf;
        local_3c[2] = 0x10e;
        local_3c[3] = 0x15e;
        local_3c[4] = 0x1b1;
        local_58[0] = 2;
        local_58[1] = 1;
        local_58[2] = 4;
        local_58[3] = 3;
        local_58[4] = 0;
        local_58[5] = local_8 / 2 + -1;
        *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
        local_40 = 400 - (int)*(short *)(iVar2 + 6) / 2;
        Ai_Subsystem_004be3c4
                  (g_DisplaySurfaceBackBuffer,local_3c[local_58[5]] + -0x1e,local_40,
                   (&DAT_006776a0)[local_58[local_58[5]]],(int)*(short *)(iVar2 + 4),
                   (int)*(short *)(iVar2 + 6));
        Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,local_20,local_24,local_18,local_1c,
                     (int *)g_DisplaySurfaceScreen,local_20,local_24);
        if (*(int *)(x + 0x28) != 0) {
          (**(code **)(x + 0x28))(x);
        }
      }
      else {
        Ai_Subsystem_004be3c4
                  (g_DisplaySurfaceScreen,*(int *)(&DAT_00519f20 + local_8 * 0x10),
                   *(int *)(&DAT_00519f24 + local_8 * 0x10),
                   *(undefined4 *)
                    (&DAT_00519dbc + (*(int *)(x + 0x2c) + -0x31) * 0x54 + y * 4),
                   *(int *)(&DAT_00519f28 + local_8 * 0x10),*(int *)(&DAT_00519f2c + local_8 * 0x10)
                  );
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}

/*
 * Decompiled function: FUN_0041ec8d
 * Entry Point: 0041ec8d
 * Size: 87 bytes
 */


undefined4 FUN_0041ec8d(int value)

{
  App_ProcessPendingMessages();
  if (DAT_00640f08 == 0) {
    DAT_00640f08 = *(int *)(value + 0x2c);
  }
  DAT_007039c4 = 0;
  Glue_Subsystem_004ebcdc(*(undefined4 *)(&DAT_00519f1c + *(int *)(value + 0x2c) * 4),0xf,100,100,0)
  ;
  return 0;
}

/*
 * Decompiled function: FUN_0041ece4
 * Entry Point: 0041ece4
 * Size: 86 bytes
 */


undefined4 FUN_0041ece4(int value)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(value + 0x40);
  DAT_00680770 = 1;
  *(undefined4 *)(value + 0x40) = 0;
  (**(code **)(value + 0x24))(value,3);
  DAT_00680770 = 0;
  *(undefined4 *)(value + 0x40) = 3;
  return uVar1;
}

/*
 * Decompiled function: FUN_0041ed3a
 * Entry Point: 0041ed3a
 * Size: 76 bytes
 */


undefined4 FUN_0041ed3a(int value)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(value + 0x40);
  *(undefined4 *)(value + 0x40) = 0;
  DAT_00680770 = 1;
  (**(code **)(value + 0x24))(value,0);
  DAT_00680770 = 0;
  return uVar1;
}

/*
 * Decompiled function: FUN_0041edd4
 * Entry Point: 0041edd4
 * Size: 855 bytes
 */


undefined4 FUN_0041edd4(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_10;
  int local_8;
  
  puVar2 = (undefined4 *)g_DisplaySurfaceScreen;
  puVar3 = &DAT_0067f750;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00519c6c + local_8 * 0x54) = *(undefined4 *)(&DAT_0067f730 + local_8 * 4);
    *(undefined4 *)(&DAT_00519c70 + local_8 * 0x54) = *(undefined4 *)(&DAT_0067f740 + local_8 * 4);
    *(undefined4 *)(&DAT_00519c74 + local_8 * 0x54) = *(undefined4 *)(&DAT_0067f740 + local_8 * 4);
    *(undefined4 *)(&DAT_00519c78 + local_8 * 0x54) = *(undefined4 *)(&DAT_0067f730 + local_8 * 4);
  }
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    iVar1 = local_8 * 2 + 2;
    *(undefined4 *)(&DAT_00519dbc + local_8 * 0x54) = *(undefined4 *)(&DAT_006782a0 + iVar1 * 4);
    *(undefined4 *)(&DAT_00519dc0 + local_8 * 0x54) = *(undefined4 *)(&DAT_006782d0 + iVar1 * 4);
    *(undefined4 *)(&DAT_00519dc4 + local_8 * 0x54) = *(undefined4 *)(&DAT_006782d0 + iVar1 * 4);
    *(undefined4 *)(&DAT_00519dc8 + local_8 * 0x54) = *(undefined4 *)(&DAT_00678300 + iVar1 * 4);
  }
  if (g_DisplayScreenWidth != 0x280) {
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      *(int *)(&DAT_00519c38 + local_10 * 0x54) =
           (*(int *)(&DAT_00519c38 + local_10 * 0x54) * g_DisplayScreenWidth) / 0x280;
      *(int *)(&DAT_00519c3c + local_10 * 0x54) =
           (*(int *)(&DAT_00519c3c + local_10 * 0x54) * g_DisplayScreenWidth) / 0x280;
      *(int *)(&DAT_00519c40 + local_10 * 0x54) =
           (*(int *)(&DAT_00519c40 + local_10 * 0x54) * g_DisplayScreenWidth) / 0x280;
      *(int *)(&DAT_00519c44 + local_10 * 0x54) =
           (*(int *)(&DAT_00519c44 + local_10 * 0x54) * g_DisplayScreenWidth) / 0x280;
    }
    for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
      *(int *)(&DAT_00519d88 + local_10 * 0x54) =
           (*(int *)(&DAT_00519d88 + local_10 * 0x54) * g_DisplayScreenWidth) / 0x280;
      *(int *)(&DAT_00519d8c + local_10 * 0x54) =
           (*(int *)(&DAT_00519d8c + local_10 * 0x54) * g_DisplayScreenWidth) / 0x280;
      *(int *)(&DAT_00519d90 + local_10 * 0x54) =
           (*(int *)(&DAT_00519d90 + local_10 * 0x54) * g_DisplayScreenWidth) / 0x280;
      *(int *)(&DAT_00519d94 + local_10 * 0x54) =
           (*(int *)(&DAT_00519d94 + local_10 * 0x54) * g_DisplayScreenWidth) / 0x280;
    }
  }
  FUN_0041f17e(0x519c28,4,0);
  FUN_0041f17e(0x519d78,5,0);
  return 1;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041f12b
 * Entry Point: 0041f12b
 * Size: 46 bytes
 */


undefined4 Mem_AllocOrFree_0041f12b(int value)

{
  *(undefined4 *)(&DAT_0067f780 + value * 4) = 0;
  *(undefined4 *)(&DAT_00538750 + value * 4) = 1;
  return 0;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041f159
 * Entry Point: 0041f159
 * Size: 37 bytes
 */


undefined4 Mem_AllocOrFree_0041f159(undefined4 value)

{
  *(undefined4 *)(&DAT_00538750 + DAT_00519c24 * 4) = value;
  return 1;
}

/*
 * Decompiled function: FUN_0041f17e
 * Entry Point: 0041f17e
 * Size: 149 bytes
 */


undefined4 FUN_0041f17e(int value,int min_val,int max_val)

{
  int local_c;
  int local_8;
  
  local_c = *(int *)(&DAT_0067f780 + max_val * 4);
  for (local_8 = 0; local_8 < min_val; local_8 = local_8 + 1) {
    *(int *)(&DAT_0067f7d0 + max_val * 200 + local_c * 4) = local_8 * 0x54 + value;
    local_c = local_c + 1;
  }
  *(int *)(&DAT_0067f780 + max_val * 4) = *(int *)(&DAT_0067f780 + max_val * 4) + min_val;
  DAT_00680770 = 0;
  return *(undefined4 *)(&DAT_0067f780 + max_val * 4);
}

/*
 * Decompiled function: FUN_0041f213
 * Entry Point: 0041f213
 * Size: 156 bytes
 */


undefined4 FUN_0041f213(void)

{
  int local_8;
  
  DAT_00680770 = 1;
  for (local_8 = 0; local_8 < *(int *)(&DAT_0067f780 + DAT_00519c24 * 4); local_8 = local_8 + 1) {
    (**(code **)(*(int *)(&DAT_0067f7d0 + local_8 * 4 + DAT_00519c24 * 200) + 0x24))
              (*(undefined4 *)(&DAT_0067f7d0 + local_8 * 4 + DAT_00519c24 * 200),
               local_8 == DAT_00519ff8);
  }
  DAT_00680770 = 0;
  return 1;
}

/*
 * Decompiled function: FUN_0041f2af
 * Entry Point: 0041f2af
 * Size: 165 bytes
 */


undefined4 FUN_0041f2af(int x,int y)

{
  int iVar1;
  int local_c;
  
  iVar1 = *(int *)(&DAT_0067f780 + DAT_00519c24 * 4);
  if (y + x <= *(int *)(&DAT_0067f780 + DAT_00519c24 * 4)) {
    iVar1 = y + x;
  }
  DAT_00680770 = 1;
  for (local_c = x; local_c < iVar1; local_c = local_c + 1) {
    (**(code **)(*(int *)(&DAT_0067f7d0 + local_c * 4 + DAT_00519c24 * 200) + 0x24))
              (*(undefined4 *)(&DAT_0067f7d0 + local_c * 4 + DAT_00519c24 * 200),0);
  }
  DAT_00680770 = 0;
  return 1;
}

/*
 * Decompiled function: FUN_0041f354
 * Entry Point: 0041f354
 * Size: 61 bytes
 */


int FUN_0041f354(void)

{
  DAT_00519c24 = DAT_00519c24 + 1;
  DAT_00519ff4 = 0xffffffff;
  DAT_00519ff8 = 0xffffffff;
  Mem_AllocOrFree_0041f12b(DAT_00519c24);
  return DAT_00519c24;
}

/*
 * Decompiled function: FUN_0041f391
 * Entry Point: 0041f391
 * Size: 89 bytes
 */


int FUN_0041f391(void)

{
  Mem_AllocOrFree_0041f12b(DAT_00519c24);
  if (DAT_00519c24 == 0) {
    DAT_00519c24 = 0;
  }
  else {
    DAT_00519c24 = DAT_00519c24 + -1;
  }
  DAT_00519ff4 = 0xffffffff;
  DAT_00519ff8 = 0xffffffff;
  return DAT_00519c24;
}

/*
 * Decompiled function: FUN_0041f3ea
 * Entry Point: 0041f3ea
 * Size: 2675 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0041f3ea(undefined4 value,undefined4 min_val,int max_val)

{
  uint _Val;
  bool bVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int local_1c;
  int local_14;
  int local_c;
  
  _DAT_00538748 = 1;
  iVar2 = Mem_AllocOrFree_00408089();
  if (iVar2 != 0) {
    uVar3 = Mem_AllocOrFree_0040813d();
    if (((uVar3 == 0xf09) || (uVar3 == 0xf0f)) ||
       ((*(int *)(&DAT_00538750 + DAT_00519c24 * 4) != 0 && ((uVar3 == 0x4800 || (uVar3 == 0x5000)))
        ))) {
      FUN_004080b2();
      if ((int)uVar3 < 0xf10) {
        if (uVar3 == 0xf0f) {
          local_1c = -1;
        }
        else if (uVar3 == 0xf09) {
          local_1c = 1;
        }
      }
      else if (uVar3 == 0x4800) {
        local_1c = -1;
      }
      else if (uVar3 == 0x5000) {
        local_1c = 1;
      }
      if (DAT_00519ff4 == -1) {
        if (local_1c < 1) {
          DAT_00519ff4 = *(int *)(&DAT_0067f780 + DAT_00519c24 * 4) + -1;
        }
        else {
          DAT_00519ff4 = 0;
        }
      }
      else {
        DAT_00519ff4 = (*(int *)(&DAT_0067f780 + DAT_00519c24 * 4) + DAT_00519ff4 + local_1c) %
                       *(int *)(&DAT_0067f780 + DAT_00519c24 * 4);
      }
      while (*(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x40) == 3)
      {
        DAT_00519ff4 = (*(int *)(&DAT_0067f780 + DAT_00519c24 * 4) + DAT_00519ff4 + local_1c) %
                       *(int *)(&DAT_0067f780 + DAT_00519c24 * 4);
      }
      if (DAT_00519ff8 != -1) {
        (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x24))
                  (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200),0);
      }
      if (*(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x10) != -1) {
        SetCursorPos(*(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x10
                             ) +
                     *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x18
                             ) / 2,
                     *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x14
                             ) +
                     *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x1c
                             ) / 2);
      }
      (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
                (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),1);
    }
    _Val = uVar3 & 0xff;
    if ((_Val != 0) || (*(int *)(&DAT_00538750 + DAT_00519c24 * 4) == 0)) {
      local_c = 0;
      if (DAT_00519ff4 == -1) {
        local_14 = 0;
      }
      else {
        local_14 = DAT_00519ff4 + 1;
      }
      for (; local_c < *(int *)(&DAT_0067f780 + DAT_00519c24 * 4); local_c = local_c + 1) {
        iVar2 = (local_14 + local_c) % *(int *)(&DAT_0067f780 + DAT_00519c24 * 4);
        if ((*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x40) != 3) &&
           ((*(uint *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x3c) == uVar3 ||
            (((_Val != 0 &&
              (*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x34) != 0)) &&
             (pcVar4 = strchr(*(char **)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) +
                                        0x34),_Val), pcVar4 != (char *)0x0)))))) {
          DAT_00519ff4 = iVar2;
          if (*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x10) != -1) {
            SetCursorPos(*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x10) +
                         *(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x18) /
                         2,*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x14)
                           + *(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) +
                                     0x1c) / 2);
          }
          if (DAT_00519ff8 != -1) {
            (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x24))
                      (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200),0);
          }
          (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
                    (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),1);
          if ((*(uint *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x3c) == uVar3)
             || (((_Val != 0 &&
                  (*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x38) != 0))
                 && (pcVar4 = strchr(*(char **)(*(int *)(&DAT_0067f7d0 +
                                                        iVar2 * 4 + DAT_00519c24 * 200) + 0x38),_Val
                                    ), pcVar4 != (char *)0x0)))) {
            DAT_00680770 = 1;
            (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
                      (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),2);
            DAT_00680770 = 0;
            DAT_00519ff8 = DAT_00519ff4;
            FUN_004080b2();
            _DAT_00538748 = 0;
            return DAT_00519ff4;
          }
          FUN_004080b2();
          break;
        }
      }
      if ((_Val == 0xd) && (DAT_00519ff4 != -1)) {
        if (DAT_00519ff8 != -1) {
          (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
                    (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200),0);
        }
        (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
                  (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),2);
        DAT_00519ff8 = DAT_00519ff4;
        FUN_004080b2();
        _DAT_00538748 = 0;
        return DAT_00519ff4;
      }
      DAT_00519ff8 = DAT_00519ff4;
    }
  }
  FUN_004080b2();
  if (-1 < DAT_00519ff8) {
    if ((DAT_007039cc <
         *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x10)) ||
       (*(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x18) +
        *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x10) <
        DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 <
              *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x14)) ||
            (*(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x14) +
             *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x1c) <
             DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_00680770 = 1;
      (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x24))
                (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200),0);
      DAT_00519ff8 = -1;
      DAT_00519ff4 = -1;
      DAT_00680770 = 0;
    }
  }
  for (local_c = 0; local_c < *(int *)(&DAT_0067f780 + DAT_00519c24 * 4); local_c = local_c + 1) {
    if ((local_c != DAT_00519ff8) &&
       (iVar2 = (**(code **)(*(int *)(&DAT_0067f7d0 + local_c * 4 + DAT_00519c24 * 200) + 0x24))
                          (*(undefined4 *)(&DAT_0067f7d0 + local_c * 4 + DAT_00519c24 * 200),0),
       iVar2 != 0)) {
      DAT_00519ff4 = local_c;
    }
  }
  if (DAT_00519ff8 != DAT_00519ff4) {
    if (-1 < DAT_00519ff8) {
      DAT_00680770 = 1;
      (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x24))
                (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200),0);
      DAT_00680770 = 0;
    }
    (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
              (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),1);
  }
  if ((max_val == 1) && (-1 < DAT_00519ff4)) {
    (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
              (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),2);
  }
  DAT_00519ff8 = DAT_00519ff4;
  _DAT_00538748 = 0;
  return DAT_00519ff4;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041feab
 * Entry Point: 0041feab
 * Size: 28 bytes
 */


undefined4 Mem_AllocOrFree_0041feab(void)

{
  DAT_005387b0 = 0xe;
  return 0;
}

/*
 * Decompiled function: FUN_0041fec7
 * Entry Point: 0041fec7
 * Size: 309 bytes
 */


undefined4 FUN_0041fec7(int value,int min_val,int max_val,int target_slot,char *str_5,int arg_6)

{
  size_t sVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  sVar1 = strlen(str_5);
  uVar2 = Mem_AllocOrFree_00501721();
  if ((uVar2 & 7) == 0) {
    uVar3 = 0;
  }
  else {
    for (local_c = 0; local_c < arg_6; local_c = local_c + 1) {
      if (local_c < (int)sVar1) {
        iVar4 = FUN_0050f390(*(int *)(value + 0x20),str_5[local_c]);
      }
      else {
        iVar4 = FUN_0050f390(*(int *)(value + 0x20),' ');
      }
      max_val = max_val + iVar4;
    }
    if (local_c < (int)sVar1) {
      local_8 = FUN_0050f390(*(int *)(value + 0x20),str_5[arg_6]);
    }
    else {
      local_8 = FUN_0050f390(*(int *)(value + 0x20),' ');
    }
    iVar4 = Mem_AllocOrFree_0050f740(*(int *)(value + 0x20));
    iVar4 = target_slot + iVar4 / 2;
    Surface_DrawLine((int *)value,max_val,iVar4 + -1,local_8 + max_val,iVar4 + -1,min_val);
    uVar3 = Surface_DrawLine((int *)value,max_val,iVar4,local_8 + max_val,iVar4,min_val);
  }
  return uVar3;
}

/*
 * Decompiled function: FUN_0041fffc
 * Entry Point: 0041fffc
 * Size: 595 bytes
 */


undefined4 FUN_0041fffc(int value,int *min_val,int max_val,int target_slot,char *str_5,int arg_6,int arg_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  int local_1c;
  int local_18;
  int local_14;
  int local_c;
  
  iVar1 = Ai_Util_004c3bc4(max_val);
  local_18 = Ai_Util_004c3bc4(target_slot);
  iVar5 = *min_val;
  iVar4 = iVar5;
  iVar2 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 6));
  iVar3 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
  Sprite_DrawScaled((int *)value,0,0,iVar3,iVar2,iVar4);
  local_14 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
  iVar5 = min_val[1];
  for (; local_14 < iVar1; local_14 = local_14 + iVar4) {
    iVar4 = iVar5;
    iVar2 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 6));
    iVar3 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
    Sprite_DrawScaled((int *)value,local_14,0,iVar3,iVar2,iVar4);
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
  }
  iVar5 = min_val[2];
  iVar2 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
  iVar4 = iVar5;
  iVar3 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 6));
  iVar5 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
  Sprite_DrawScaled((int *)value,iVar1 - iVar2,0,iVar5,iVar3,iVar4);
  *(int *)(value + 0x20) = arg_6;
  Mem_AllocOrFree_0050f740(arg_6);
  local_1c = FUN_0050f440((int *)value,str_5);
  while (iVar1 < local_1c) {
    sVar6 = strlen(str_5);
    str_5[sVar6 - 1] = '\0';
    local_1c = FUN_0050f440((int *)value,str_5);
  }
  local_14 = 10;
  local_18 = local_18 / 2;
  local_c = 0x25;
  if (arg_7 == 1) {
    local_c = 0x67;
  }
  if (arg_7 == 2) {
    local_c = 0x67;
    local_18 = local_18 + 2;
    local_14 = 8;
  }
  if (arg_7 == 3) {
    local_c = 0xf0;
  }
  FUN_0040cfd5(value,local_c,local_14,local_18);
  if (DAT_00538834 != 0) {
    FUN_0041fec7(value,local_c,local_14,local_18,str_5,DAT_00538830);
  }
  return 0;
}

/*
 * Decompiled function: FUN_0042024f
 * Entry Point: 0042024f
 * Size: 296 bytes
 */


undefined4 FUN_0042024f(int x,int y)

{
  int flags;
  int target_slot;
  int *arg_6;
  int arg_7;
  int arg_8;
  int arg_9;
  int arg_10;
  int *local_8;
  
  switch(y) {
  case 0:
    local_8 = (int *)&DAT_00538818;
    break;
  case 1:
    local_8 = (int *)&DAT_00538818;
    break;
  case 2:
    local_8 = (int *)&DAT_00538824;
    break;
  case 3:
    local_8 = (int *)&DAT_00538818;
  }
  arg_7 = (&DAT_0051a090)[x * 0x15];
  arg_8 = *(int *)(&DAT_0051a094 + x * 0x54);
  arg_9 = *(int *)(&DAT_0051a098 + x * 0x54);
  arg_10 = *(int *)(&DAT_0051a09c + x * 0x54);
  FUN_0041fffc((int)g_DisplaySurfaceBackBuffer,local_8,0x168,0x1b,&DAT_0067f450 + x * 0x40,4,y
              );
  arg_6 = (int *)g_DisplaySurfaceScreen;
  flags = Ai_Util_004c3bc4(0x1a);
  target_slot = Ai_Util_004c3bc4(0x168);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,target_slot,flags,arg_6,arg_7,arg_8,arg_9,
                     arg_10);
  return 0;
}

/*
 * Decompiled function: FUN_0042038c
 * Entry Point: 0042038c
 * Size: 1052 bytes
 */


undefined4 FUN_0042038c(int *value,int min_val,int max_val,int target_slot,int flags)

{
  undefined4 *puVar1;
  short sVar2;
  undefined2 uVar3;
  int arg_2_00;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_a8;
  int local_a4;
  int local_a0;
  undefined4 uStack_9c;
  short local_98 [2];
  undefined4 auStack_94 [3];
  short local_88;
  short local_86;
  short local_78;
  short local_76;
  short local_68;
  short local_66;
  short local_58;
  short local_56;
  short local_48;
  short local_46;
  short local_38;
  short local_36;
  short local_28;
  short local_26;
  short local_18;
  short local_16;
  int local_c;
  int *local_8;
  
  local_8 = &DAT_005387b8;
  for (local_a4 = 0; local_a4 < 9; local_a4 = local_a4 + 1) {
    puVar1 = (undefined4 *)local_8[local_a4];
    (&uStack_9c)[local_a4 * 4] = *puVar1;
    *(undefined4 *)(local_98 + local_a4 * 8) = puVar1[1];
    auStack_94[local_a4 * 4] = puVar1[2];
    auStack_94[local_a4 * 4 + 1] = puVar1[3];
    sVar2 = Ai_Util_004c3bc4((int)local_98[local_a4 * 8]);
    local_98[local_a4 * 8] = sVar2;
    uVar3 = Ai_Util_004c3bc4((int)*(short *)((int)auStack_94 + local_a4 * 0x10 + -2));
    *(undefined2 *)((int)auStack_94 + local_a4 * 0x10 + -2) = uVar3;
  }
  arg_2_00 = Ai_Util_004c3bc4(min_val);
  iVar4 = Ai_Util_004c3bc4(max_val);
  iVar5 = Ai_Util_004c3bc4(target_slot);
  iVar6 = Ai_Util_004c3bc4(flags);
  Sprite_DrawScaled(value,(arg_2_00 + iVar5 / 2) - (int)local_98[0] / 2,
                    iVar4 - ((int)local_98[1] - (int)local_46),(int)local_98[0],(int)local_98[1],
                    *local_8);
  local_a0 = (int)local_98[0] / 2 + iVar5 / 2 + arg_2_00;
  for (local_c = ((arg_2_00 + iVar5 / 2) - (int)local_98[0] / 2) - (int)local_48; arg_2_00 < local_c
      ; local_c = local_c - local_48) {
    Sprite_DrawScaled(value,local_c,iVar4,(int)local_48,(int)local_46,local_8[5]);
    Sprite_DrawScaled(value,local_a0,iVar4,(int)local_48,(int)local_46,local_8[5]);
    local_a0 = local_a0 + local_48;
  }
  Sprite_DrawScaled(value,arg_2_00,iVar4,(int)local_88,(int)local_86,local_8[1]);
  Sprite_DrawScaled(value,(iVar5 + arg_2_00) - (int)local_78,iVar4,(int)local_78,(int)local_76,
                    local_8[2]);
  iVar7 = (int)local_18;
  for (local_a8 = local_86 + iVar4; local_a8 < (iVar6 + iVar4) - (int)local_66;
      local_a8 = local_a8 + local_16) {
    Sprite_DrawScaled(value,arg_2_00,local_a8,(int)local_18,(int)local_16,local_8[8]);
    Sprite_DrawScaled(value,(iVar5 + arg_2_00) - iVar7,local_a8,(int)local_38,(int)local_36,
                      local_8[6]);
  }
  Sprite_DrawScaled(value,arg_2_00,(iVar6 + iVar4) - (int)local_66,(int)local_68,(int)local_66,
                    local_8[3]);
  Sprite_DrawScaled(value,(iVar5 + arg_2_00) - (int)local_58,(iVar6 + iVar4) - (int)local_56,
                    (int)local_58,(int)local_56,local_8[4]);
  local_a0 = ((iVar5 + arg_2_00) - (int)local_58) - (int)local_28;
  iVar4 = iVar4 + (iVar6 - local_26);
  for (local_c = local_68 + arg_2_00; local_c < arg_2_00 + iVar5 / 2; local_c = local_c + local_28)
  {
    Sprite_DrawScaled(value,local_c,iVar4,(int)local_28,(int)local_26,local_8[7]);
    Sprite_DrawScaled(value,local_a0,iVar4,(int)local_28,(int)local_26,local_8[7]);
    local_a0 = local_a0 - local_28;
  }
  return 0;
}

/*
 * Decompiled function: FUN_004211bd
 * Entry Point: 004211bd
 * Size: 247 bytes
 */


undefined4 FUN_004211bd(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    FUN_0042024f(*(int *)(x + 0x2c) + -4,y);
    if ((y == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_004212f0
 * Entry Point: 004212f0
 * Size: 479 bytes
 */


undefined4 FUN_004212f0(int x,int y)

{
  int arg_6;
  int min_val;
  int max_val;
  uint target_slot;
  DWORD flags;
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    arg_6 = *(int *)(&DAT_00538a88 + y * 4 + (*(int *)(x + 0x2c) + -1) * 0x10);
    min_val = *(int *)(x + 0x10);
    max_val = *(int *)(x + 0x14);
    target_slot = *(uint *)(x + 0x18);
    flags = *(DWORD *)(x + 0x1c);
    if (y == 2) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceWork,0,max_val + 0x80,target_slot,flags,
                        *(int *)(&DAT_00538a8c + (*(int *)(x + 0x2c) + -1) * 0x10));
      Sprite_DrawScaled((int *)g_DisplaySurfaceWork,2,max_val + 0x82,target_slot - 4,flags - 4,arg_6);
      Surface_BlitToDevice((int *)g_DisplaySurfaceWork,0,max_val + 0x80,target_slot,flags,
                   (int *)g_DisplaySurfaceScreen,min_val,max_val);
      if (*(int *)(x + 0x28) != 0) {
        (**(code **)(x + 0x28))(x);
      }
    }
    else {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,min_val,max_val,target_slot,flags,arg_6);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_004214cf
 * Entry Point: 004214cf
 * Size: 390 bytes
 */


undefined4 FUN_004214cf(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    if (y == 2) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(x + 0x10) + 2,
                        *(int *)(x + 0x14) + 2,*(int *)(x + 0x18) + -4,
                        *(int *)(x + 0x1c) + -4,*(int *)(x + 0x48));
      if (*(int *)(x + 0x28) != 0) {
        (**(code **)(x + 0x28))(x);
      }
    }
    else {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(x + 0x10),*(int *)(x + 0x14),
                        *(int *)(x + 0x18),*(int *)(x + 0x1c),*(int *)(x + 0x44 + y * 4)
                       );
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_004216e5
 * Entry Point: 004216e5
 * Size: 261 bytes
 */


undefined4 FUN_004216e5(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    if ((y == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_004217ea
 * Entry Point: 004217ea
 * Size: 321 bytes
 */


undefined4 FUN_004217ea(int value)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int arg_6;
  int iVar4;
  int iVar5;
  
  arg_6 = DAT_00538ac4;
  Pic_Subsystem_0044b84b();
  iVar4 = *(int *)(value + 0x14) + *(int *)(value + 0x70) / 2;
  if (iVar4 <= DAT_0067bda8) {
    iVar4 = DAT_0067bda8;
  }
  iVar5 = (*(int *)(value + 0x14) + *(int *)(value + 0x1c)) - *(int *)(value + 0x70) / 2;
  if (iVar4 <= iVar5) {
    iVar5 = iVar4;
  }
  iVar4 = *(int *)(value + 0x14);
  iVar1 = *(int *)(value + 0x70);
  iVar2 = *(int *)(value + 0x1c);
  iVar3 = *(int *)(value + 0x70);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,*(int *)(value + 0x10),*(int *)(value + 0x14),
                   *(int *)(value + 0x18),*(int *)(value + 0x1c),0);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(value + 0x10),
                    iVar5 - *(int *)(value + 0x70) / 2,*(int *)(value + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(value + 0x18)) / *(int *)(value + 8),
                    arg_6);
  FUN_00422b04((((iVar5 - iVar4) - iVar1 / 2) * 0x11) / (iVar2 - iVar3));
  DAT_00538a28 = *(undefined4 *)(value + 0x2c);
  return *(undefined4 *)(value + 0x2c);
}

/*
 * Decompiled function: FUN_0042192b
 * Entry Point: 0042192b
 * Size: 182 bytes
 */


undefined4 FUN_0042192b(int value)

{
  int iVar1;
  int iVar2;
  int arg_6;
  
  arg_6 = DAT_00538ac4;
  iVar1 = *(int *)(value + 0x70);
  iVar2 = *(int *)(value + 0x14);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,*(int *)(value + 0x10),*(int *)(value + 0x14),
                   *(int *)(value + 0x18),*(int *)(value + 0x1c),0);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(value + 0x10),
                    (iVar2 + iVar1 / 2) - *(int *)(value + 0x70) / 2,*(int *)(value + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(value + 0x18)) / *(int *)(value + 8),
                    arg_6);
  return 0;
}

/*
 * Decompiled function: FUN_004219e1
 * Entry Point: 004219e1
 * Size: 160 bytes
 */


void FUN_004219e1(int *value,int min_val,int max_val,int target_slot,int flags,int arg_6)

{
  int arg_4_00;
  int arg_5_00;
  
  arg_4_00 = min_val + target_slot;
  arg_5_00 = flags + max_val;
  Surface_DrawLine(value,min_val,max_val,arg_4_00,max_val,arg_6);
  Surface_DrawLine(value,arg_4_00,max_val,arg_4_00,arg_5_00,arg_6);
  Surface_DrawLine(value,arg_4_00,arg_5_00,min_val,arg_5_00,arg_6);
  Surface_DrawLine(value,min_val,arg_5_00,min_val,max_val,arg_6);
  return;
}

/*
 * Decompiled function: FUN_00421a81
 * Entry Point: 00421a81
 * Size: 177 bytes
 */


undefined4 FUN_00421a81(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  
  if ((DAT_007039cc < *(int *)(x + 0x10)) ||
     (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
    bVar1 = false;
  }
  else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
          (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if (y == 2) {
      DAT_00538a28 = *(undefined4 *)(x + 0x2c);
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_00422b04
 * Entry Point: 00422b04
 * Size: 1026 bytes
 */


void FUN_00422b04(int value)

{
  DWORD DVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int local_38;
  uint local_34;
  int local_2c [6];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (value == 0x12) {
    local_38 = 1;
  }
  else {
    local_38 = 2;
  }
  local_2c[0] = 0xbf;
  local_2c[1] = 0xbc;
  local_2c[2] = 0xb7;
  local_2c[3] = 0xf4;
  local_2c[4] = 0xf6;
  local_34 = value * 3;
  iVar8 = 0x80;
  iVar7 = 0;
  piVar6 = (int *)g_DisplaySurfaceWork;
  DVar1 = Ai_Util_004c3bc4(0x7f);
  uVar2 = Ai_Util_004c3bc4(0x173);
  Surface_BlitToDevice((int *)g_DisplaySurfaceWork,0,0x154,uVar2,DVar1,piVar6,iVar7,iVar8);
  for (local_14 = 0; local_14 < local_38; local_14 = local_14 + 1) {
    local_10 = 0;
    for (; (local_10 < 3 && ((int)local_34 < 0x37)); local_34 = local_34 + 1) {
      if ((*(int *)(&DAT_00538858 + local_34 * 8) != 0) ||
         ((*(int *)(&DAT_0053885c + local_34 * 8) != 0 || (DAT_0067b9a4 != 0)))) {
        local_c = *(int *)(&DAT_00538858 + local_34 * 8);
        local_2c[5] = *(int *)(&DAT_0053885c + local_34 * 8);
        iVar7 = local_c + local_2c[5];
        if (iVar7 < 2) {
          iVar7 = 1;
        }
        iVar7 = (local_c * 100) / iVar7;
        if (local_c < local_2c[5]) {
          if ((local_2c[5] - local_c < 6) || (0x19 < iVar7)) {
            if ((local_c + local_2c[5] < 5) || (0x28 < iVar7)) {
              local_8 = 2;
            }
            else {
              local_8 = 1;
            }
          }
          else {
            local_8 = 0;
          }
        }
        else if ((local_c - local_2c[5] < 6) || (iVar7 < 0x4b)) {
          if ((local_c + local_2c[5] < 5) || (iVar7 < 0x3d)) {
            local_8 = 2;
          }
          else {
            local_8 = 3;
          }
        }
        else {
          local_8 = 4;
        }
        iVar8 = Ai_Util_004c3bc4(local_14 << 6);
        iVar8 = iVar8 + 0x80;
        iVar3 = Ai_Util_004c3bc4(0x7c);
        iVar3 = iVar3 * local_10;
        iVar7 = *(int *)(DAT_0051a4c8 * 8 + 0x51a4d4);
        piVar6 = (int *)g_DisplaySurfaceWork;
        iVar4 = Ai_Util_004c3bc4(3);
        DVar1 = (iVar7 + -2) - iVar4;
        uVar2 = *(int *)(DAT_0051a4c8 * 8 + 0x51a4d0) - 2;
        iVar7 = *(int *)(DAT_0051a4c8 * 8 + 0x51a4d4);
        uVar5 = (int)local_34 >> 0x1f;
        iVar4 = Ai_Util_004c3bc4(3);
        Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,
                     *(int *)(DAT_0051a4c8 * 8 + 0x51a4d0) *
                     (((local_34 ^ uVar5) - uVar5 & 7 ^ uVar5) - uVar5) + 1,
                     iVar7 * ((int)(local_34 + (uVar5 & 7)) >> 3) + iVar4 + 1,uVar2,DVar1,piVar6,
                     iVar3,iVar8);
        *(undefined4 *)(g_DisplaySurfaceWork + 0x20) = 4;
        iVar7 = Ai_Util_004c3bc4(local_14 * 0x40 + -3);
        iVar8 = Ai_Util_004c3bc4(0x20);
        iVar3 = iVar7 + iVar8 + 0x80;
        iVar7 = Ai_Util_004c3bc4(0x7c);
        iVar7 = iVar7 * local_10;
        iVar8 = Ai_Util_004c3bc4(0x5e);
        FUN_0040d269((int)g_DisplaySurfaceWork,local_2c[local_8],iVar7 + iVar8,iVar3);
        *(undefined4 *)(g_DisplaySurfaceWork + 0x20) = 1;
        iVar7 = Ai_Util_004c3bc4(local_14 << 6);
        iVar8 = Ai_Util_004c3bc4(0x36);
        iVar3 = iVar7 + iVar8 + 0x80;
        iVar7 = Ai_Util_004c3bc4(0x7c);
        iVar7 = iVar7 * local_10;
        iVar8 = Ai_Util_004c3bc4(0x3e);
        FUN_0040d269((int)g_DisplaySurfaceWork,0xb7,iVar7 + iVar8,iVar3);
      }
      local_10 = local_10 + 1;
    }
  }
  iVar7 = Ai_Util_004c3bc4(0x43);
  iVar8 = Ai_Util_004c3bc4(0xf6);
  piVar6 = (int *)g_DisplaySurfaceScreen;
  iVar3 = Ai_Util_004c3bc4(0x40);
  DVar1 = iVar3 * 2 - 2;
  iVar3 = Ai_Util_004c3bc4(0x7c);
  Surface_BlitToDevice((int *)g_DisplaySurfaceWork,0,0x80,iVar3 * 3 - 2,DVar1,piVar6,iVar8,iVar7);
  DAT_00538ac8 = value;
  return;
}

/*
 * Decompiled function: FUN_00422f06
 * Entry Point: 00422f06
 * Size: 380 bytes
 */


void FUN_00422f06(void)

{
  uint uVar1;
  int local_1c;
  
  memset(&DAT_00538850,0,0x1c0);
  DAT_00538a6c = 0;
  DAT_00538a68 = 0;
  DAT_00538a60 = 0;
  DAT_00538a70 = 0;
  DAT_00538ab8 = 0;
  DAT_00538a64 = 0;
  DAT_00538a24 = 0;
  local_1c = 0;
  while( true ) {
    if (9999 < local_1c) {
      return;
    }
    uVar1 = *(uint *)(&DAT_0067a9a4 + local_1c * 0x10);
    if (*(int *)(&DAT_0067a9a0 + local_1c * 0x10) == 0) break;
    switch(*(undefined4 *)(&DAT_0067a9a0 + local_1c * 0x10)) {
    case 2:
      if ((uVar1 & 0x80) == 0) {
        DAT_00538a64 = DAT_00538a64 + 1;
        *(int *)(&DAT_00538854 + (uVar1 & 0x7f) * 8) =
             *(int *)(&DAT_00538854 + (uVar1 & 0x7f) * 8) + 1;
      }
      else {
        DAT_00538a24 = DAT_00538a24 + 1;
        *(int *)(&DAT_00538850 + (uVar1 & 0x7f) * 8) =
             *(int *)(&DAT_00538850 + (uVar1 & 0x7f) * 8) + 1;
      }
      break;
    case 4:
      *(int *)(&DAT_00538838 + (uVar1 & 0x7f) * 4) =
           *(int *)(&DAT_00538838 + (uVar1 & 0x7f) * 4) + 1;
      break;
    case 7:
      DAT_00538a60 = DAT_00538a60 + 1;
      break;
    case 0xd:
      DAT_00538a70 = DAT_00538a70 + 1;
      break;
    case 0xf:
      break;
    case 0x10:
      DAT_00538a68 = DAT_00538a68 + 1;
      break;
    case 0x11:
      DAT_00538a6c = DAT_00538a6c + 1;
      break;
    case 0x13:
      DAT_00538ab8 = DAT_00538ab8 + 1;
    }
    local_1c = local_1c + 1;
  }
  return;
}

/*
 * Decompiled function: Pic_Load_worlbak1_004230bd
 * Entry Point: 004230bd
 * Size: 560 bytes
 */


void Pic_Load_worlbak1_004230bd(int value)

{
  int flags;
  int target_slot;
  int max_val;
  int min_val;
  int iVar1;
  int iVar2;
  int arg_1_00;
  int arg_1_01;
  
  Mem_AllocOrFree_00510e20(1,s_worlbak1_pic_0051ae80);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
  Glue_Subsystem_004f0de8(value);
  iVar2 = *(int *)(&DAT_006782a0 + value * 4);
  arg_1_00 = (0x4e - *(short *)(iVar2 + 6)) / 2 + 0x4c;
  arg_1_01 = (0x4f - *(short *)(iVar2 + 4)) / 2 + 0x14f;
  iVar1 = *(int *)(&DAT_006782a0 + value * 4);
  flags = Ai_Util_004c3bc4((int)*(short *)(iVar2 + 6));
  target_slot = Ai_Util_004c3bc4((int)*(short *)(iVar2 + 4));
  max_val = Ai_Util_004c3bc4(arg_1_00);
  min_val = Ai_Util_004c3bc4(arg_1_01);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,min_val,max_val,target_slot,flags,iVar1);
  iVar1 = (arg_1_00 + *(short *)(iVar2 + 6) + 0x10) / 2;
  iVar2 = (arg_1_01 + (int)*(short *)(iVar2 + 4) / 2) / 2;
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  Font_DrawTextInRect((int)g_DisplaySurfaceScreen,0x7b,0x176,0x4b);
  g_OverworldWorldState = 0;
  strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[value]);
  FUN_0040c336(&g_OverworldWorldState,iVar2,iVar1 + -5,0x40);
  strcpy(&g_OverworldWorldState,&DAT_0051ae9c);
  strcat(&g_OverworldWorldState,(&PTR_s_A_clever_duelist_can_switch_ante_005225a0)[value]);
  strcat(&g_OverworldWorldState,&DAT_0051aea0);
  iVar1 = Ai_Util_004c3ba3(iVar1 + 3);
  iVar2 = Ai_Util_004c3ba3(iVar2);
  FUN_0040d201((int)g_DisplaySurfaceScreen,0x7b,iVar2,iVar1);
  App_ProcessPendingMessages();
  Ai_Subsystem_004cd1d1();
  return;
}

/*
 * Decompiled function: FUN_004232f0
 * Entry Point: 004232f0
 * Size: 555 bytes
 */


undefined * FUN_004232f0(int value,int min_val,int max_val)

{
  int iVar1;
  DWORD dwMaximumSizeLow;
  undefined4 uVar2;
  HANDLE pvVar3;
  HDC pHVar4;
  HBITMAP pHVar5;
  undefined *puVar6;
  uint uVar7;
  
  *(int *)(PTR_DAT_00520cb8 + 0x20) = value;
  *(int *)(PTR_DAT_00520cb8 + 0x24) = min_val;
  *(int *)(PTR_DAT_00520cb8 + 0x28) = max_val;
  iVar1 = max_val * value + (max_val * value >> 0x1f & 7U);
  uVar7 = iVar1 >> 0x1f;
  if (((iVar1 >> 3 ^ uVar7) - uVar7 & 3 ^ uVar7) == uVar7) {
    *(undefined4 *)(PTR_DAT_00520cb8 + 0x2c) = 0;
  }
  else {
    iVar1 = max_val * value + (max_val * value >> 0x1f & 7U);
    uVar7 = iVar1 >> 0x1f;
    *(uint *)(PTR_DAT_00520cb8 + 0x2c) = 4 - (((iVar1 >> 3 ^ uVar7) - uVar7 & 3 ^ uVar7) - uVar7);
  }
  iVar1 = (*(int *)(PTR_DAT_00520cb8 + 0x2c) + value) * max_val * min_val;
  dwMaximumSizeLow = ((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) + 0x10;
  *(DWORD *)(PTR_DAT_00520cb8 + 0x1c) = dwMaximumSizeLow;
  uVar2 = FUN_0050ec90(value,min_val,max_val);
  *(undefined4 *)(PTR_DAT_00520cb8 + 0x10) = uVar2;
  if (*(int *)(PTR_DAT_00520cb8 + 0x10) == 0) {
    puVar6 = (undefined *)0x0;
  }
  else {
    pvVar3 = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,
                                dwMaximumSizeLow,(LPCSTR)0x0);
    *(HANDLE *)PTR_DAT_00520cb8 = pvVar3;
    if (*(int *)PTR_DAT_00520cb8 == 0) {
      Mem_AllocOrFree_0050ed10(*(void **)(PTR_DAT_00520cb8 + 0x10));
      puVar6 = (undefined *)0x0;
    }
    else {
      pHVar4 = GetDC((HWND)0x0);
      *(HDC *)(PTR_DAT_00520cb8 + 4) = pHVar4;
      GDI_RealizeAndFlushPalette_Magic(*(HDC *)(PTR_DAT_00520cb8 + 4));
      pHVar5 = CreateDIBSection(*(HDC *)(PTR_DAT_00520cb8 + 4),
                                *(BITMAPINFO **)(PTR_DAT_00520cb8 + 0x10),(uint)(max_val == 8),
                                (void **)(PTR_DAT_00520cb8 + 0x18),*(HANDLE *)PTR_DAT_00520cb8,0);
      *(HBITMAP *)(PTR_DAT_00520cb8 + 8) = pHVar5;
      ReleaseDC((HWND)0x0,*(HDC *)(PTR_DAT_00520cb8 + 4));
      if (*(int *)(PTR_DAT_00520cb8 + 8) == 0) {
        Mem_AllocOrFree_0050ed10(*(void **)(PTR_DAT_00520cb8 + 0x10));
        CloseHandle(*(HANDLE *)PTR_DAT_00520cb8);
        puVar6 = (undefined *)0x0;
      }
      else {
        Mem_AllocOrFree_0050ed10(*(void **)(PTR_DAT_00520cb8 + 0x10));
        puVar6 = PTR_DAT_00520cb8;
      }
    }
  }
  return puVar6;
}

/*
 * Decompiled function: FUN_0046aa75
 * Entry Point: 0046aa75
 * Size: 176 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046aa75(HWND hwnd)

{
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = GetWindowLongA(hwnd,0);
  local_10 = GetWindowLongA(hwnd,4);
  local_8 = Ai_Subsystem_004b5cbb(local_c,local_10);
  if (local_8 == DAT_006ff2dc) {
    Ai_Subsystem_004b6da5(&local_18,local_c,local_10);
    _DAT_00538de4 = local_18;
    _DAT_00538de8 = local_14;
  }
  else {
    _DAT_00538de4 = local_c;
    _DAT_00538de8 = local_10;
  }
  _DAT_00538de0 = 0;
  PostMessageA(g_MainAppHwnd,0x464,0,0x538de0);
  return;
}

/*
 * Decompiled function: FUN_0046ab25
 * Entry Point: 0046ab25
 * Size: 549 bytes
 */


undefined4 FUN_0046ab25(HWND hwnd)

{
  LONG x;
  LONG y;
  uint uVar1;
  uint uVar2;
  HWND pHVar3;
  undefined4 local_24;
  undefined4 local_14;
  undefined4 local_10;
  
  x = GetWindowLongA(hwnd,0);
  y = GetWindowLongA(hwnd,4);
  uVar1 = Ai_Subsystem_004b613b(x,y);
  uVar2 = Ai_Subsystem_004b6356(x,y);
  local_24 = -1;
  local_10 = 0xffffffff;
  pHVar3 = GetParent(hwnd);
  if (pHVar3 == DAT_0069e720) {
    local_24 = 0;
    local_10 = 2;
  }
  else if (DAT_006fe400 == pHVar3) {
    local_24 = 1;
    local_10 = 2;
  }
  else if (DAT_006a4924 == pHVar3) {
    local_24 = 0;
    local_10 = 1;
  }
  else if (DAT_006b2e2c == pHVar3) {
    local_24 = 1;
    local_10 = 1;
  }
  else if (pHVar3 == DAT_006b2e10) {
    local_24 = 0;
    local_10 = 0x10;
  }
  else if (pHVar3 == DAT_006a4928) {
    local_24 = 1;
    local_10 = 0x10;
  }
  if ((((((DAT_006feec0 == -1) || (DAT_006feec0 == x)) &&
        ((DAT_006feec4 == 0xffffffff || ((DAT_006feec4 == 0 || ((uVar1 & DAT_006feec4) != 0)))))) &&
       (((DAT_006feec8 == 0xffffffff || ((DAT_006feec8 == 0 || ((uVar2 & DAT_006feec8) != 0)))) ||
        ((((DAT_006feec8 & 0x100) != 0 && ((uVar1 & 0x40) != 0)) ||
         (((DAT_006feec8 & 0x200) != 0 && ((uVar1 & 1) != 0)))))))) &&
      ((DAT_006feecc == -1 || (DAT_006feecc == local_24)))) &&
     ((DAT_006feed0 == 0xffffffff || ((local_10 & DAT_006feed0) != 0)))) {
    local_14 = 1;
  }
  else {
    local_14 = 0;
  }
  return local_14;
}

/*
 * Decompiled function: FUN_0046ad4a
 * Entry Point: 0046ad4a
 * Size: 114 bytes
 */


int FUN_0046ad4a(HWND hwnd)

{
  LONG x;
  LONG y;
  uint uVar1;
  uint uVar2;
  
  x = GetWindowLongA(hwnd,0);
  y = GetWindowLongA(hwnd,4);
  uVar1 = Ai_Subsystem_004b5cbb(x,y);
  uVar2 = (int)uVar1 >> 0x1f;
  return (y % 3) * 3 + (((uVar1 ^ uVar2) - uVar2 & 3 ^ uVar2) - uVar2) * 2;
}

/*
 * Decompiled function: FUN_0046adbc
 * Entry Point: 0046adbc
 * Size: 654 bytes
 */


bool FUN_0046adbc(int x,int y)

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
  
  bVar1 = *(int *)(x + 4) == *(int *)(y + 4);
  bVar2 = ((*(uint *)(x + 0xc) ^ *(uint *)(y + 0xc) & 0x30000) & 0x30000) == 0;
  bVar3 = ((*(uint *)(x + 0xc) ^ *(uint *)(y + 0xc) & 0x10) & 0x10) == 0;
  bVar4 = ((*(uint *)(x + 0xc) ^ *(uint *)(y + 0xc) & 0x1000) & 0x1000) == 0;
  bVar5 = ((*(uint *)(x + 0xc) ^ *(uint *)(y + 0xc) & 0x200000) & 0x200000) == 0;
  bVar6 = ((*(uint *)(x + 0xc) ^ *(uint *)(y + 0xc) & 0x100000) & 0x100000) == 0;
  bVar7 = *(short *)(x + 0x10) == *(short *)(y + 0x10);
  bVar8 = *(short *)(x + 0x14) == *(short *)(y + 0x14);
  bVar9 = *(short *)(x + 0x16) == *(short *)(y + 0x16);
  bVar10 = *(char *)(x + 0x1c) == *(char *)(y + 0x1c);
  bVar11 = *(char *)(x + 0x1d) == *(char *)(y + 0x1d);
  bVar12 = *(char *)(x + 0x1e) == *(char *)(y + 0x1e);
  bVar13 = *(int *)(x + 0x24) == *(int *)(y + 0x24);
  bVar14 = *(int *)(x + 0x4c) == *(int *)(y + 0x4c);
  bVar15 = ((*(uint *)(x + 0x38) ^ *(uint *)(y + 0x38) & 0x20000) & 0x20000) == 0;
  bVar16 = *(int *)(x + 0x44) == *(int *)(y + 0x44);
  bVar17 = *(int *)(x + 0x108) == *(int *)(y + 0x108);
  bVar18 = *(char *)(x + 0x20) == *(char *)(y + 0x20);
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
    FUN_0046b04a(x,y);
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

/*
 * Decompiled function: FUN_0046b04a
 * Entry Point: 0046b04a
 * Size: 924 bytes
 */


uint FUN_0046b04a(int x,int y)

{
  uint local_10c;
  int local_108;
  char local_104 [256];
  
  local_10c = 0;
  if (*(int *)(y + 4) == *(int *)(x + 4)) {
    if (((*(uint *)(y + 0xc) ^ *(uint *)(x + 0xc) & 0x30000) & 0x30000) != 0) {
      local_10c = 2;
    }
    if (((*(uint *)(y + 0xc) ^ *(uint *)(x + 0xc) & 0x10) & 0x10) != 0) {
      local_10c = local_10c | 8;
    }
    if (((*(uint *)(y + 0xc) ^ *(uint *)(x + 0xc) & 0x1000) & 0x1000) != 0) {
      local_10c = local_10c | 0x10;
    }
    if (((*(uint *)(y + 0xc) ^ *(uint *)(x + 0xc) & 0x200000) & 0x200000) != 0) {
      local_10c = local_10c | 0x20;
    }
    if (((*(uint *)(y + 0xc) ^ *(uint *)(x + 0xc) & 0x100000) & 0x100000) != 0) {
      local_10c = local_10c | 0x40;
    }
    if (*(short *)(y + 0x10) != *(short *)(x + 0x10)) {
      local_10c = local_10c | 0x80;
    }
    if (*(short *)(y + 0x14) != *(short *)(x + 0x14)) {
      local_10c = local_10c | 0x100;
    }
    if (*(short *)(y + 0x16) != *(short *)(x + 0x16)) {
      local_10c = local_10c | 0x200;
    }
    if (*(char *)(y + 0x1c) != *(char *)(x + 0x1c)) {
      local_10c = local_10c | 0x400;
    }
    if (*(char *)(y + 0x1d) != *(char *)(x + 0x1d)) {
      local_10c = local_10c | 0x800;
    }
    if (*(char *)(x + 0x1e) != *(char *)(y + 0x1e)) {
      local_10c = local_10c | 0x1000;
    }
    if (*(int *)(y + 0x24) != *(int *)(x + 0x24)) {
      local_10c = local_10c | 0x4000;
    }
    if (*(int *)(y + 0x4c) != *(int *)(x + 0x4c)) {
      local_10c = local_10c | 0x8000;
    }
    if (((*(uint *)(x + 0x38) ^ *(uint *)(y + 0x38) & 0x20000) & 0x20000) != 0) {
      local_10c = local_10c | 0x10000;
    }
    if (*(int *)(y + 0x44) != *(int *)(x + 0x44)) {
      local_10c = local_10c | 0x20000;
    }
    if (*(int *)(y + 0x108) != *(int *)(x + 0x108)) {
      local_10c = local_10c | 0x40000;
    }
    if (*(char *)(y + 0x20) != *(char *)(x + 0x20)) {
      local_10c = local_10c | 0x80000;
    }
  }
  else {
    local_10c = 1;
  }
  sprintf(local_104,s__s__s_00524dbc,s_Swamp_0051aea9 + *(int *)(x + 4) * 0x34,
          s_Swamp_0051aea9 + *(int *)(y + 4) * 0x34);
  OutputDebugStringA(local_104);
  for (local_108 = 0; local_108 < 0x20; local_108 = local_108 + 1) {
    if ((local_10c & 1 << ((byte)local_108 & 0x1f)) != 0) {
      if (local_108 == 0) {
        sprintf(local_104,s__s__d__d_00524dc8,PTR_s_Type_005247d0,*(undefined4 *)(x + 4),
                *(undefined4 *)(y + 4));
      }
      else {
        sprintf(local_104,&DAT_00524dd4,(&PTR_s_Type_005247d0)[local_108]);
      }
      OutputDebugStringA(local_104);
    }
  }
  return local_10c;
}

/*
 * Decompiled function: FUN_0046b3e6
 * Entry Point: 0046b3e6
 * Size: 54 bytes
 */


bool FUN_0046b3e6(int x,int y)

{
  return *(int *)(y + 0x3c) == *(int *)(x + 0x3c);
}

/*
 * Decompiled function: FUN_0046b41c
 * Entry Point: 0046b41c
 * Size: 159 bytes
 */


bool FUN_0046b41c(int x,int y)

{
  return ((*(uint *)(x + 0xc) ^ *(uint *)(y + 0xc) & 0x10) & 0x10) == 0 &&
         (((*(uint *)(x + 0xc) ^ *(uint *)(y + 0xc) & 0x30000) & 0x30000) == 0 &&
         (*(int *)(x + 0x44) == *(int *)(y + 0x44) && *(int *)(x + 4) == *(int *)(y + 4)
         ));
}

/*
 * Decompiled function: Mem_AllocOrFree_0046b4bb
 * Entry Point: 0046b4bb
 * Size: 32 bytes
 */


void Mem_AllocOrFree_0046b4bb(int x,int y)

{
  FUN_0046adbc(x,y);
  return;
}

/*
 * Decompiled function: FUN_0046b4db
 * Entry Point: 0046b4db
 * Size: 940 bytes
 */


void FUN_0046b4db(char *str_1,int min_val,undefined4 max_val)

{
  if (str_1 != (char *)0x0) {
    if (min_val == 0x1d7) {
      sprintf(str_1,s_Doom_counters___d_00524dd8,max_val);
    }
    else if (min_val == 0x244) {
      sprintf(str_1,s_Charge_counters___d_00524dec,max_val);
    }
    else if (min_val == 0x248) {
      sprintf(str_1,s_Charge_counters___d_00524e00,max_val);
    }
    else if (min_val == 0x296) {
      sprintf(str_1,s_Charge_counters___d_00524e14,max_val);
    }
    else if (min_val == 0x2fd) {
      sprintf(str_1,s_Charge_counters___d_00524e28,max_val);
    }
    else if (min_val == 0x354) {
      sprintf(str_1,s_Charge_counters___d_00524e3c,max_val);
    }
    else if (min_val == 0x1e4) {
      sprintf(str_1,s_Clockwork___1__0__counters___d_00524e50,max_val);
    }
    else if (min_val == 0x26) {
      sprintf(str_1,s_Clockwork___1__0__counters___d_00524e70,max_val);
    }
    else if (min_val == 0x34) {
      sprintf(str_1,s_Life_counters___d_00524e90,max_val);
    }
    else if (min_val == 0x7b) {
      sprintf(str_1,s_Life_counters___d_00524ea4,max_val);
    }
    else if (min_val == 0x80) {
      sprintf(str_1,s_Life_counters___d_00524eb8,max_val);
    }
    else if (min_val == 0xf6) {
      sprintf(str_1,s_Life_counters___d_00524ecc,max_val);
    }
    else if (min_val == 0x120) {
      sprintf(str_1,s_Life_counters___d_00524ee0,max_val);
    }
    else if (min_val == 0x5e) {
      sprintf(str_1,s__1__1_counters___d_00524ef4,max_val);
    }
    else if (min_val == 0x353) {
      sprintf(str_1,s__1__1_counters___d_00524f08,max_val);
    }
    else if (min_val == 0x92) {
      sprintf(str_1,s_Vitality_counters___d_00524f1c,max_val);
    }
    else if (min_val == 0x2e0) {
      sprintf(str_1,s_Carrion_counters___d_00524f34,max_val);
    }
    else if (min_val == 0xd7) {
      sprintf(str_1,s_Corpse_counters___d_00524f4c,max_val);
    }
    else if (min_val == 0xdc) {
      sprintf(str_1,s__1__1_counters___d_00524f60,max_val);
    }
    else if (min_val == 0x367) {
      sprintf(str_1,s_Corpse_counters___d_00524f74,max_val);
    }
    else if (min_val == 0x21a) {
      sprintf(str_1,s__1__1_counters___d_00524f88,max_val);
    }
    else if (min_val == 0x216) {
      sprintf(str_1,s_Drone___1__1__counters___d_00524f9c,max_val);
    }
    else if (min_val == 0xf8) {
      sprintf(str_1,s_Turn_counters___d_00524fb8,max_val);
    }
    else {
      *str_1 = '\0';
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0046b887
 * Entry Point: 0046b887
 * Size: 164 bytes
 */


void FUN_0046b887(char *str_1,int min_val,int max_val)

{
  if ((str_1 != (char *)0x0) && (strcpy(str_1,&DAT_00524fcc), max_val != 0)) {
    if (min_val == 1) {
      sprintf(str_1,s_Damage___0__1__counters___d_00524fd0,max_val);
    }
    else if (min_val == 2) {
      sprintf(str_1,s_Mutation___1__1__counters___d_00524fec,max_val);
    }
    else if (min_val == 3) {
      sprintf(str_1,s_Shackle___0__2__counters___d_0052500c,max_val);
    }
  }
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0046b92b
 * Entry Point: 0046b92b
 * Size: 19 bytes
 */


void Mem_AllocOrFree_0046b92b(void)

{
  return;
}

/*
 * Decompiled function: FUN_0046ba19
 * Entry Point: 0046ba19
 * Size: 272 bytes
 */


void FUN_0046ba19(HDC hdc,int y,undefined4 max_val,undefined4 target_slot)

{
  size_t sVar1;
  char local_18 [12];
  int local_c;
  HFONT local_8;
  
  local_c = SaveDC(hdc);
  sprintf(local_18,s__d__d_0052502c,max_val,target_slot);
  local_8 = CreateFontA(0x12,0,0,0,400,0,0,0,0,0,0,0,0x12,s_Times_New_Roman_00525034);
  SelectObject(hdc,local_8);
  SetBkMode(hdc,1);
  SetTextAlign(hdc,2);
  SetTextColor(hdc,0xffffff);
  sVar1 = strlen(local_18);
  TextOutA(hdc,*(int *)(y + 8),*(int *)(y + 4) + 1,local_18,sVar1);
  SetTextColor(hdc,0x808080);
  sVar1 = strlen(local_18);
  TextOutA(hdc,*(int *)(y + 8) + -1,*(int *)(y + 4),local_18,sVar1);
  RestoreDC(hdc,local_c);
  DeleteObject(local_8);
  return;
}

/*
 * Decompiled function: FUN_0046bb29
 * Entry Point: 0046bb29
 * Size: 125 bytes
 */


undefined4 FUN_0046bb29(HWND hwnd,int *y)

{
  undefined4 uVar1;
  LONG LVar2;
  LONG LVar3;
  
  if ((hwnd == (HWND)0x0) || (y == (int *)0x0)) {
    uVar1 = 0;
  }
  else {
    LVar2 = GetWindowLongA(hwnd,0);
    LVar3 = GetWindowLongA(hwnd,4);
    if ((*y == LVar2) && (y[1] == LVar3)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0046bbab
 * Entry Point: 0046bbab
 * Size: 127 bytes
 */


undefined4 FUN_0046bbab(HWND hwnd,int y)

{
  undefined4 uVar1;
  LONG x;
  LONG arg2_00;
  int iVar2;
  
  if ((hwnd == (HWND)0x0) || (y < 0)) {
    uVar1 = 0;
  }
  else {
    x = GetWindowLongA(hwnd,0);
    arg2_00 = GetWindowLongA(hwnd,4);
    iVar2 = Ai_Subsystem_004b5cbb(x,arg2_00);
    if (iVar2 == y) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0046bc2f
 * Entry Point: 0046bc2f
 * Size: 99 bytes
 */


undefined4 FUN_0046bc2f(HWND hwnd)

{
  undefined4 uVar1;
  LONG x;
  LONG y;
  
  if (hwnd == (HWND)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    x = GetWindowLongA(hwnd,0);
    y = GetWindowLongA(hwnd,4);
    uVar1 = Ai_Subsystem_004b5cbb(x,y);
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0046bc92
 * Entry Point: 0046bc92
 * Size: 41 bytes
 */


LONG FUN_0046bc92(HWND hwnd)

{
  LONG LVar1;
  
  LVar1 = GetWindowLongA(hwnd,8);
  return LVar1;
}

/*
 * Decompiled function: FUN_0046bcc0
 * Entry Point: 0046bcc0
 * Size: 620 bytes
 */


int FUN_0046bcc0(WPARAM value,int min_val,int width,int height)

{
  int local_154;
  char local_150 [264];
  HBITMAP local_48;
  HDC local_44;
  int local_40;
  int local_3c;
  void *local_38;
  void *local_34;
  BITMAPINFO local_30;
  
  local_40 = 1;
  if (value == 0xffffffff) {
    local_40 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + value * 0x98) < 2) {
    if (*(int *)(&DAT_00696a20 + value * 0x10) != 0) {
      if ((*(int *)(&DAT_00696a28 + value * 0x10) == width) &&
         (*(int *)(&DAT_00696a2c + value * 0x10) == height)) {
        return 1;
      }
      FUN_0046c1b3(value);
    }
    sprintf(local_150,s__s__04d_WVL_00525044,&DAT_006808d0,value);
    local_3c = Glue_Subsystem_004f15c0(0,local_150,0);
    if (local_3c == 0) {
      local_40 = 0;
    }
    else {
      local_44 = GetDC((HWND)0x0);
      GDI_RealizeAndFlushPalette_Magic(local_44);
      FUN_005017f0((undefined4 *)&local_30,width,height);
      local_48 = CreateDIBSection(local_44,&local_30,0,&local_38,(HANDLE)0x0,0);
      if (local_48 == (HBITMAP)0x0) {
        local_40 = 0;
      }
      else {
        local_34 = (void *)FUN_004f27c0(0,local_3c,width,height);
        if (local_34 == (void *)0x0) {
          local_40 = 0;
          DeleteObject(local_48);
        }
        else {
          if ((-width & 3U) == 0) {
            local_154 = 0;
          }
          else {
            local_154 = 4 - (-width & 3U);
          }
          memcpy(local_38,local_34,(width * 3 + local_154) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_44);
      Glue_Util_004f1910(local_3c);
    }
    if (local_40 != 0) {
      *(HBITMAP *)(&DAT_00696a20 + value * 0x10) = local_48;
      *(void **)(&DAT_00696a24 + value * 0x10) = local_38;
      *(int *)(&DAT_00696a28 + value * 0x10) = width;
      *(int *)(&DAT_00696a2c + value * 0x10) = height;
      PostMessageA(g_MainAppHwnd,0x433,value,0);
    }
  }
  else {
    local_40 = FUN_0046c203(value,min_val,width,height);
  }
  return local_40;
}

/*
 * Decompiled function: FUN_0046bf31
 * Entry Point: 0046bf31
 * Size: 130 bytes
 */


undefined4 FUN_0046bf31(int x,int y)

{
  undefined4 uVar1;
  int iVar2;
  
  if (x == -1) {
    uVar1 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + x * 0x98) < 2) {
    if (*(int *)(&DAT_00696a20 + x * 0x10) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    iVar2 = FUN_0046c4b5(x,y);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0046bfc2
 * Entry Point: 0046bfc2
 * Size: 221 bytes
 */


int FUN_0046bfc2(HDC hdc,RECT *min_val,int width,int target_slot)

{
  int iVar1;
  HBRUSH hbr;
  int local_8;
  
  if ((hdc == (HDC)0x0) || (min_val == (RECT *)0x0)) {
    local_8 = 0;
  }
  else if (width == -1) {
    local_8 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + width * 0x98) < 2) {
    iVar1 = FUN_0046bf31(width,target_slot);
    if (iVar1 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_004f3b5f((int)hdc,(int)min_val,*(HANDLE *)(&DAT_00696a20 + width * 0x10));
    }
    if (local_8 == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,min_val,hbr);
    }
  }
  else {
    local_8 = FUN_0046c54b(hdc,min_val,width,target_slot);
  }
  return local_8;
}

/*
 * Decompiled function: FUN_0046c09f
 * Entry Point: 0046c09f
 * Size: 271 bytes
 */


undefined4 FUN_0046c09f(WPARAM value,int min_val,int width,int height)

{
  HGDIOBJ ho;
  undefined4 uVar1;
  int iVar2;
  
  if (value == 0xffffffff) {
    uVar1 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + value * 0x98) < 2) {
    if (((*(int *)(&DAT_00696a20 + value * 0x10) == 0) ||
        (*(int *)(&DAT_00696a28 + value * 0x10) != width)) ||
       (*(int *)(&DAT_00696a2c + value * 0x10) != height)) {
      ho = *(HGDIOBJ *)(&DAT_00696a20 + value * 0x10);
      *(undefined4 *)(&DAT_00696a20 + value * 0x10) = 0;
      iVar2 = FUN_0046bcc0(value,min_val,width,height);
      if (iVar2 == 0) {
        *(HGDIOBJ *)(&DAT_00696a20 + value * 0x10) = ho;
        uVar1 = 0;
      }
      else {
        if (ho != (HGDIOBJ)0x0) {
          DeleteObject(ho);
        }
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = FUN_0046c636(value,min_val,width,height);
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0046c1b3
 * Entry Point: 0046c1b3
 * Size: 80 bytes
 */


void FUN_0046c1b3(int value)

{
  if ((value != -1) && (*(int *)(&DAT_00696a20 + value * 0x10) != 0)) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00696a20 + value * 0x10));
    *(undefined4 *)(&DAT_00696a20 + value * 0x10) = 0;
  }
  return;
}

/*
 * Decompiled function: FUN_0046c203
 * Entry Point: 0046c203
 * Size: 685 bytes
 */


int FUN_0046c203(WPARAM value,int y,int width,int height)

{
  int local_158;
  char local_154 [264];
  HBITMAP local_4c;
  HDC local_48;
  int local_44;
  int local_40;
  void *local_3c;
  void *local_38;
  BITMAPINFO local_34;
  int local_8;
  
  local_44 = 1;
  if (value == 0xffffffff) {
    local_44 = 0;
  }
  else {
    local_8 = FUN_0046c4b5(value,y);
    if (local_8 != 0) {
      if ((*(int *)(local_8 + 8) == width) && (*(int *)(local_8 + 0xc) == height)) {
        return 1;
      }
      FUN_0046c6e5(value,y);
    }
    if (y == 0) {
      sprintf(local_154,s__s__04d_WVL_00525060,&DAT_006808d0,value);
    }
    else {
      sprintf(local_154,s__s__04d_c_WVL_00525050,&DAT_006808d0,value,(int)(char)((char)y + '`'));
    }
    local_40 = Glue_Subsystem_004f15c0(0,local_154,0);
    if (local_40 == 0) {
      local_44 = 0;
    }
    else {
      local_48 = GetDC((HWND)0x0);
      GDI_RealizeAndFlushPalette_Magic(local_48);
      FUN_005017f0((undefined4 *)&local_34,width,height);
      local_4c = CreateDIBSection(local_48,&local_34,0,&local_3c,(HANDLE)0x0,0);
      if (local_4c == (HBITMAP)0x0) {
        local_44 = 0;
      }
      else {
        local_38 = (void *)FUN_004f27c0(0,local_40,width,height);
        if (local_38 == (void *)0x0) {
          local_44 = 0;
          DeleteObject(local_4c);
        }
        else {
          if ((-width & 3U) == 0) {
            local_158 = 0;
          }
          else {
            local_158 = 4 - (-width & 3U);
          }
          memcpy(local_3c,local_38,(width * 3 + local_158) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_48);
      Glue_Util_004f1910(local_40);
    }
    if (local_44 != 0) {
      *(HBITMAP *)(&DAT_006a3f80 + DAT_006fe404 * 0x18) = local_4c;
      *(void **)(&DAT_006a3f84 + DAT_006fe404 * 0x18) = local_3c;
      *(int *)(&DAT_006a3f88 + DAT_006fe404 * 0x18) = width;
      *(int *)(&DAT_006a3f8c + DAT_006fe404 * 0x18) = height;
      *(WPARAM *)(&DAT_006a3f90 + DAT_006fe404 * 0x18) = value;
      *(int *)(&DAT_006a3f94 + DAT_006fe404 * 0x18) = y;
      DAT_006fe404 = DAT_006fe404 + 1;
      PostMessageA(g_MainAppHwnd,0x433,value,y);
    }
  }
  return local_44;
}

/*
 * Decompiled function: FUN_0046c4b5
 * Entry Point: 0046c4b5
 * Size: 150 bytes
 */


undefined * FUN_0046c4b5(int x,int y)

{
  int local_c;
  undefined *local_8;
  
  local_8 = (undefined *)0x0;
  if (x == -1) {
    local_8 = (undefined *)0x0;
  }
  else {
    local_c = 0;
    while ((local_c < DAT_006fe404 && (local_8 == (undefined *)0x0))) {
      if ((*(int *)(&DAT_006a3f90 + local_c * 0x18) == x) &&
         (*(int *)(&DAT_006a3f94 + local_c * 0x18) == y)) {
        local_8 = &DAT_006a3f80 + local_c * 0x18;
      }
      local_c = local_c + 1;
    }
  }
  return local_8;
}

/*
 * Decompiled function: FUN_0046c54b
 * Entry Point: 0046c54b
 * Size: 235 bytes
 */


int FUN_0046c54b(HDC hdc,RECT *min_val,int width,int height)

{
  bool bVar1;
  HBRUSH hbr;
  int local_14;
  int local_10;
  int local_c;
  
  if (width == -1) {
    local_14 = 0;
  }
  else {
    local_c = 0;
    bVar1 = false;
    while ((local_c < DAT_006fe404 && (!bVar1))) {
      if ((*(int *)(&DAT_006a3f90 + local_c * 0x18) == width) &&
         (*(int *)(&DAT_006a3f94 + local_c * 0x18) == height)) {
        bVar1 = true;
        local_10 = local_c;
      }
      local_c = local_c + 1;
    }
    if (bVar1) {
      local_14 = FUN_004f3b5f((int)hdc,(int)min_val,*(HANDLE *)(&DAT_006a3f80 + local_10 * 0x18));
    }
    else {
      local_14 = 0;
    }
    if (local_14 == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,min_val,hbr);
    }
  }
  return local_14;
}

/*
 * Decompiled function: FUN_0046c636
 * Entry Point: 0046c636
 * Size: 165 bytes
 */


undefined4 FUN_0046c636(WPARAM value,int y,int width,int height)

{
  undefined4 uVar1;
  int iVar2;
  
  if (value == 0xffffffff) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_0046c4b5(value,y);
    if (iVar2 != 0) {
      if ((*(int *)(iVar2 + 8) == width) && (*(int *)(iVar2 + 0xc) == height)) {
        return 1;
      }
      FUN_0046c6e5(value,y);
    }
    iVar2 = FUN_0046c203(value,y,width,height);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0046c6e5
 * Entry Point: 0046c6e5
 * Size: 372 bytes
 */


void FUN_0046c6e5(int x,int y)

{
  bool bVar1;
  int local_10;
  int local_c;
  
  if (x != -1) {
    local_c = 0;
    bVar1 = false;
    while ((local_c < DAT_006fe404 && (!bVar1))) {
      if ((*(int *)(&DAT_006a3f90 + local_c * 0x18) == x) &&
         (*(int *)(&DAT_006a3f94 + local_c * 0x18) == y)) {
        bVar1 = true;
        if (*(int *)(&DAT_006a3f80 + local_c * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_006a3f80 + local_c * 0x18));
        }
        DAT_006fe404 = DAT_006fe404 + -1;
        for (local_10 = local_c; local_10 < DAT_006fe404; local_10 = local_10 + 1) {
          *(undefined4 *)(&DAT_006a3f80 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f80 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006a3f84 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f84 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006a3f88 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f88 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006a3f8c + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f8c + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006a3f90 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f90 + (local_10 * 3 + 3) * 8);
          *(undefined4 *)(&DAT_006a3f94 + local_10 * 0x18) =
               *(undefined4 *)(&DAT_006a3f94 + (local_10 * 3 + 3) * 8);
        }
      }
      local_c = local_c + 1;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0046c859
 * Entry Point: 0046c859
 * Size: 78 bytes
 */


void FUN_0046c859(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_006fe404; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_006a3f80 + local_8 * 0x18));
  }
  DAT_006fe404 = 0;
  return;
}

/*
 * Decompiled function: Sprite_Load_BK_AMG_0046d333
 * Entry Point: 0046d333
 * Size: 4866 bytes
 */


void Sprite_Load_BK_AMG_0046d333(undefined4 value,int min_val,int max_val)

{
  int iVar1;
  bool bVar2;
  char *pcVar3;
  
  bVar2 = true;
  if (*(int *)(&g_OverworldFoodAmount + min_val * 0xb4) == 0) {
    switch(value) {
    case 1:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BK_FWZ_spr_00525294);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SFWZ_spr_005252a0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 2:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BK_KHT_spr_005252ac);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SB_KHT_spr_005252b8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 3:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BK_MWZ_spr_005252c4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SMWZ_spr_005252d0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 4:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BK_LRD_spr_005252dc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SB_LRD_spr_005252e8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 5:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BK_WG_spr_005252f4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SBK_WG_spr_00525300);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 6:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BK_AMG_spr_0052530c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SB_AMG_spr_00525318);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    default:
      bVar2 = false;
      break;
    case 8:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_W_MWZ_spr_00525324);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SW_MWZ_spr_00525330);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 9:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_W_FWZ_spr_0052533c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SFWZ_spr_00525348);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 10:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_W_KHT_spr_00525354);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SKHT_spr_00525360);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0xb:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_W_LRD_spr_0052536c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SW_LRD_spr_00525378);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0xc:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_W_WG_spr_00525384);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SW_WG_spr_00525390);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0xd:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_W_AMG_spr_0052539c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SW_AMG_spr_005253a8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0xf:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BU_FWZ_spr_005253b4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SFWZ_spr_005253c0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x10:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BU_LRD_spr_005253cc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SU_LRD_spr_005253d8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x11:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BU_MWZ_spr_005253e4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SMWZ_spr_005253f0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x12:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BU_WRM_spr_005253fc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SWRM_spr_00525408);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x13:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_B_SFR_spr_00525414);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SB_SFT_spr_00525420);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x14:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BU_AMG_spr_0052542c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SU_AMG_spr_00525438);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x16:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_G_MWZ_spr_00525444);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SMWZ_spr_00525450);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x17:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_G_KHT_spr_0052545c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SKHT_spr_00525468);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x18:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_G_FWZ_spr_00525474);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SFWZ_spr_00525480);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x19:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_G_WRM_spr_0052548c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SWRM_spr_00525498);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x1a:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_G_LRD_spr_005254a4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SG_LRD_spr_005254b0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x1b:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_G_AMG_spr_005254bc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SG_AMG_spr_005254c8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x1d:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_R_FWZ_spr_005254d4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SR_FWZ_spr_005254e0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x1e:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_R_MWZ_spr_005254ec);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SMWZ_spr_005254f8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x1f:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_TROLL_spr_00525504);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_STRL_spr_00525510);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x20:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_R_LRD_spr_0052551c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SR_LRD_spr_00525528);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x21:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_R_WRM_spr_00525534);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SR_WRM_spr_00525540);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x22:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_R_AMG_spr_0052554c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SR_AMG_spr_00525558);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x23:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_R_AMG_spr_00525564);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SR_AMG_spr_00525570);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x24:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_M_TSK_spr_0052557c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SM_TSK_spr_00525588);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x25:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_M_TRL_spr_00525594);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SM_TRL_spr_005255a0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x26:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_M_APE_spr_005255ac);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SM_APE_spr_005255b8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x27:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_M_CEN2_spr_005255c4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SM_CEN_spr_005255d0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x28:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_M_WG_spr_005255dc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SM_WG_spr_005255e8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x29:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_M_FNG_spr_005255f4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SM_FNG_spr_00525600);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x2a:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_M_CEN_spr_0052560c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SM_CEN2_spr_00525618);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x2b:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_M_LRD_spr_00525624);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SM_LRD_spr_00525630);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x2c:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_M_KHT_spr_0052563c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SKHT_spr_00525648);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x2d:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_M_FWZ_spr_00525654);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SFWZ_spr_00525660);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x2e:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BK_DJN_spr_0052566c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SDJN_spr_00525678);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x2f:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_G_DJN_spr_00525684);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SDJN_spr_00525690);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x30:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_R_DJN_spr_0052569c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SDJN_spr_005256a8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x31:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_BU_DJN_spr_005256b4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_SDJN_spr_005256c0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x32:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_DG_BRU_spr_005256cc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_S_DG_spr_005256d8);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x33:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_DG_UWB_spr_005256e4);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_S_DG_spr_005256f0);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x34:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_DG_GWR_spr_005256fc);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_S_DG_spr_00525708);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x35:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_DG_RBG_spr_00525714);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_S_DG_spr_00525720);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
      break;
    case 0x36:
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_DG_WUG_spr_0052572c);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4),pcVar3);
      pcVar3 = (char *)Sprite_ResolveAssetPath(s_S_DG_spr_00525738);
      Sprite_LoadAll((undefined4 *)(&g_OverworldFoodAmount + max_val * 0xb4),pcVar3);
    }
    if (bVar2) {
      iVar1 = *(int *)(&g_OverworldFoodAmount + min_val * 0xb4);
      *(int *)(&DAT_006783f0 + min_val * 4) = (int)*(short *)(iVar1 + 4);
      *(int *)(&DAT_00678470 + min_val * 4) = (int)*(short *)(iVar1 + 6);
      *(int *)(&DAT_00677990 + min_val * 4) = (int)*(short *)(iVar1 + 10);
      if (*(int *)(&DAT_00678470 + min_val * 4) < *(int *)(&DAT_00677990 + min_val * 4)) {
        *(int *)(&DAT_00677990 + min_val * 4) = (*(int *)(&DAT_00678470 + min_val * 4) * 2) / 3;
      }
      *(undefined4 *)(&DAT_006783f0 + max_val * 4) = *(undefined4 *)(&DAT_006783f0 + min_val * 4);
      *(undefined4 *)(&DAT_00678470 + max_val * 4) = *(undefined4 *)(&DAT_00678470 + min_val * 4);
      *(undefined4 *)(&DAT_00677990 + max_val * 4) = *(undefined4 *)(&DAT_00677990 + min_val * 4);
    }
    else {
      *(undefined4 *)(&g_OverworldFoodAmount + min_val * 0xb4) = 0;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0046e70d
 * Entry Point: 0046e70d
 * Size: 109 bytes
 */


void FUN_0046e70d(int x,int y)

{
  if (*(int *)(&g_OverworldFoodAmount + x * 0xb4) != 0) {
    Mem_AllocOrFree_0050fc50(*(void **)(&g_OverworldFoodAmount + x * 0xb4));
    Mem_AllocOrFree_0050fc50(*(void **)(&g_OverworldFoodAmount + y * 0xb4));
    *(undefined4 *)(&g_OverworldFoodAmount + x * 0xb4) = 0;
  }
  return;
}

/*
 * Decompiled function: FUN_0046e77a
 * Entry Point: 0046e77a
 * Size: 424 bytes
 */


void FUN_0046e77a(char *x,int y)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  Mem_AllocOrFree_00510e20(1,x);
  iVar1 = Surface_GetPixel(1,1,0xc);
  local_c = 4;
  for (local_10 = 2; local_10 < g_DisplayScreenWidth; local_10 = local_10 + 1) {
    iVar2 = Surface_GetPixel(1,local_10,0xd);
    if (iVar2 == iVar1) {
      local_c = local_10;
      break;
    }
  }
  local_8 = 0x10;
  *(undefined4 *)(&DAT_00677990 + y * 4) = 0;
  local_14 = 0xd;
  do {
    if (g_DisplayScreenHeight <= local_14) {
LAB_0046e877:
      for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
        for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
          uVar3 = Sprite_EncodeFromSurface
                            (1,(local_c + -1) * local_10 + 2,(local_8 + -0xc) * local_14 + 0xd,
                             local_c - 2U,local_8 + -0xd);
          *(undefined4 *)(&g_OverworldFoodAmount + y * 0xb4 + local_14 * 0x14 + local_10 * 4) =
               uVar3;
        }
      }
      *(uint *)(&DAT_006783f0 + y * 4) = local_c - 2U;
      *(int *)(&DAT_00678470 + y * 4) = local_8 + -0xd;
      return;
    }
    iVar2 = Surface_GetPixel(1,1,local_14);
    if (iVar2 != iVar1) {
      *(int *)(&DAT_00677990 + y * 4) = local_14 + -0xd;
    }
    iVar2 = Surface_GetPixel(1,2,local_14);
    if (iVar2 == iVar1) {
      local_8 = local_14;
      goto LAB_0046e877;
    }
    local_14 = local_14 + 1;
  } while( true );
}

/*
 * Decompiled function: FUN_0046e922
 * Entry Point: 0046e922
 * Size: 62 bytes
 */


/*
 * Deck_PickRandomSecondaryColor
 * Purpose: Select a random color that is not already in the player deck.
 * Parameters:
 *   existing_color_mask: Bitmask of colors already selected for the deck.
 * Returns: Bitmask for the selected secondary color (1 << color_index).
 */
int Deck_PickRandomSecondaryColor(uint32_t existing_color_mask)
{
  char random_roll;
  undefined1 color_index;
  
  do {
    random_roll = Math_RandomRange(5);
    color_index = random_roll + 1;
  } while ((existing_color_mask & (1 << (color_index & 0x1f))) != 0);
  return 1 << (color_index & 0x1f);
}
int FUN_0046e922(uint32_t value) { return Deck_PickRandomSecondaryColor(value); }

/*
 * Deck_GenerateStartingResources
 * Purpose: Allocate starting resources (cards, amulets, gold, and life) for a new campaign.
 * Procedure:
 * 1. Clear the player 500-slot card inventory.
 * 2. Seed the random number generator using the system uptime timer.
 * 3. Populate cards based on the selected campaign difficulty level:
 *    - Level 0 (Apprentice): Mono-color deck (13 Lands, 12 Spells/Artifacts, 10 Creatures, 1 Rare).
 *    - Level 1 (Mage): Two-color deck (15 Lands, 7 Spells/Artifacts, 16 Creatures, 1 Rare).
 *    - Level 2 (Archmage): Three-color deck (18 Lands, 9 Spells/Artifacts, 16 Creatures, 1 Rare).
 *    - Level 3 (Wizard): Multi-color 5-color deck (17 Lands, 8 Spells/Artifacts, 19 Creatures, 1 Rare).
 * 4. Allocate 1 primary amulet plus (3 - difficulty) random amulets.
 * 5. Set starting gold to (5 - difficulty) * 50.
 * 6. Set starting life total to 8.
 * 7. Mark starting cards as active in the player deck (bit 0x10000).
 */
void Deck_GenerateStartingResources(void)
{
  uint primary_color_mask;
  DWORD timer_seed;
  uint secondary_color_mask;
  int tertiary_lands;
  int tertiary_spells;
  int tertiary_creatures;
  int tertiary_rares;
  int allow_artifacts;
  int slot_idx;
  
  if (g_IsAiThinking == 0) {
    for (slot_idx = 0; slot_idx < 500; slot_idx = slot_idx + 1) {
      *(undefined4 *)(&deck + slot_idx * 4) = 0xffffffff;
    }
    if (DAT_0067f388 == 0) {
      for (slot_idx = 0; slot_idx < 7; slot_idx = slot_idx + 1) {
        *(undefined4 *)(&DAT_006a48f0 + slot_idx * 4) = 0;
        *(undefined4 *)(&DAT_006a4908 + slot_idx * 4) = 0xffffffff;
      }
      _DAT_0067f374 = _DAT_0067f374 | (1 << ((char)DAT_0052effc * '\x02' & 0x1fU));
      *(undefined4 *)(&DAT_005224e8 + DAT_0052effc * 0x20) = 0;
      primary_color_mask = 1 << ((byte)DAT_0052effc & 0x1f);
      timer_seed = GetTickCount();
      srand(timer_seed);
      switch(DAT_0067f380) {
      case 0:
        /* Level 0 - Apprentice: 13 Lands, 12 Spells/Artifacts, 10 Creatures, 1 Rare (Mono-color) */
        Deck_PopulateCategoryCards(primary_color_mask, 13, 12, 10, 1, 1);
        break;
      case 1:
        /* Level 1 - Mage: Primary Color (11 Lands, 4 Spells, 12 Creatures, 1 Rare) */
        Deck_PopulateCategoryCards(primary_color_mask, 11, 4, 12, 1, 1);
        /* Secondary Color (4 Lands, 3 Spells, 4 Creatures, 0 Rares) */
        allow_artifacts = 1;
        tertiary_rares = 0;
        tertiary_creatures = 4;
        tertiary_spells = 3;
        tertiary_lands = 4;
        secondary_color_mask = Deck_PickRandomSecondaryColor(primary_color_mask);
        Deck_PopulateCategoryCards(secondary_color_mask, tertiary_lands, tertiary_spells, tertiary_creatures, tertiary_rares, allow_artifacts);
        break;
      case 2:
        /* Level 2 - Archmage: Primary Color (9 Lands, 3 Spells, 9 Creatures, 1 Rare) */
        Deck_PopulateCategoryCards(primary_color_mask, 9, 3, 9, 1, 1);
        /* Secondary Color (5 Lands, 3 Spells, 4 Creatures, 0 Rares) */
        secondary_color_mask = Deck_PickRandomSecondaryColor(primary_color_mask);
        Deck_PopulateCategoryCards(secondary_color_mask, 5, 3, 4, 0, 1);
        /* Tertiary Color (4 Lands, 3 Spells, 3 Creatures, 0 Rares) */
        allow_artifacts = 1;
        tertiary_rares = 0;
        tertiary_creatures = 3;
        tertiary_spells = 3;
        tertiary_lands = 4;
        secondary_color_mask = Deck_PickRandomSecondaryColor(primary_color_mask | secondary_color_mask);
        Deck_PopulateCategoryCards(secondary_color_mask, tertiary_lands, tertiary_spells, tertiary_creatures, tertiary_rares, allow_artifacts);
        break;
      case 3:
        /* Level 3 - Wizard: Primary Color (6 Lands, 3 Spells, 5 Creatures, 1 Rare) */
        Deck_PopulateCategoryCards(primary_color_mask, 6, 3, 5, 1, 1);
        /* All Colors (11 Lands, 5 Spells, 14 Creatures, 0 Rares) */
        Deck_PopulateCategoryCards(1, 11, 5, 14, 0, 1);
      }
      DAT_0067bde0 = 0;
      for (slot_idx = 0; slot_idx < 5; slot_idx = slot_idx + 1) {
        (&DAT_0067bdc0)[slot_idx] = 0;
      }
      /* Add 1 amulet for the player starting color */
      *(int *)(&DAT_0067bdbc + DAT_0052effc * 4) = *(int *)(&DAT_0067bdbc + DAT_0052effc * 4) + 1;
      /* Add (3 - difficulty) random amulets */
      for (slot_idx = 0; slot_idx < 3 - DAT_0067f380; slot_idx = slot_idx + 1) {
        tertiary_lands = Math_RandomRange(5);
        (&DAT_0067bdc0)[tertiary_lands] = (&DAT_0067bdc0)[tertiary_lands] + 1;
      }
      for (slot_idx = 0; slot_idx < 0x80; slot_idx = slot_idx + 1) {
        *(undefined4 *)(&DAT_0067bdf0 + slot_idx * 100) = 0xffffffff;
      }
      for (slot_idx = 0; slot_idx < 8; slot_idx = slot_idx + 1) {
        *(undefined4 *)(&DAT_0067f2d0 + slot_idx * 0x14) = 0xffffffff;
      }
      for (slot_idx = 0; slot_idx < 1000; slot_idx = slot_idx + 1) {
        DAT_0067b9b0 = 0;
      }
      for (slot_idx = 0; slot_idx < 4; slot_idx = slot_idx + 1) {
        *(undefined4 *)(&g_PlayerLifeTotals + slot_idx * 4) = 8;
      }
      for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
        *(uint *)(&deck + slot_idx * 4) = *(uint *)(&deck + slot_idx * 4) | 0x10000;
      }
      DAT_0052effc = -1;
    }
  }
  return;
}
void FUN_0046e960(void) { Deck_GenerateStartingResources(); }

/*
 * Deck_PopulateCategoryCards
 * Purpose: Select and insert random cards into the player deck matching color, type, and rarity rules.
 * Parameters:
 *   color_mask: Bitmask of acceptable colors for selected cards.
 *   num_lands: Quantity of basic land cards to generate.
 *   num_spells: Quantity of non-creature spell and artifact cards to generate.
 *   num_creatures: Quantity of creature cards to generate.
 *   guaranteed_rare_count: Number of guaranteed Rare cards to generate (1 or 0).
 *   allow_colorless_artifacts: 1 to allow colorless artifact rolls, 0 for colored spells only.
 * Returns: 0 on success.
 */
int32_t Deck_PopulateCategoryCards(uint32_t color_mask, int num_lands, int num_spells, int num_creatures, int guaranteed_rare_count, int allow_colorless_artifacts)
{
  bool copy_limit_ok;
  int card_rarity;
  uint color_filter;
  uint spell_color_filter;
  uint is_artifact_roll;
  uint candidate_card_id;
  uint card_counter;
  int creature_attempt_counter;
  
  /* 1. Generate Basic Lands */
  for (card_counter = 0; (int)card_counter < num_lands; card_counter = card_counter + 1) {
    candidate_card_id = Pic_Subsystem_00451d90(1, color_mask);
    card_rarity = Pic_Subsystem_004521a6((int)(char)(&DAT_0051aebe)[candidate_card_id * 0x34], color_mask, 0);
    if (((card_rarity == 0) || (4 < (int)candidate_card_id)) || (((&DAT_0051aed6)[candidate_card_id * 0x34] & 0xc1) == 0)) {
      card_counter = card_counter - 1;
    }
    else {
      Pic_Subsystem_00451e40(candidate_card_id);
    }
  }
  
  /* 2. Generate Non-Creature Spells and Artifacts */
  for (card_counter = 0; (int)card_counter < num_spells; card_counter = card_counter + 1) {
    if (allow_colorless_artifacts == 0) {
      is_artifact_roll = 0;
    }
    else {
      is_artifact_roll = rand() & 1;
    }
    if (is_artifact_roll == 0) {
      spell_color_filter = color_mask;
    }
    else {
      spell_color_filter = 1;
    }
    candidate_card_id = Pic_Subsystem_00451d90((-(uint)(is_artifact_roll == 0) & 0xffffffc4) + 0x40, spell_color_filter);
    if (((DAT_0067f380 == 0) && (((&DAT_0051aecc)[candidate_card_id * 0x34] & 3) != 0)) ||
       (((&DAT_0051aed1)[candidate_card_id * 0x34] & 9) != 0)) {
      card_counter = card_counter - 1;
    }
    else {
      if (((&g_MasterCardColorTable)[candidate_card_id * 0x34] & 4) != 0) {
        is_artifact_roll = 0;
      }
      if (is_artifact_roll == 0) {
        color_filter = color_mask;
      }
      else {
        color_filter = 1;
      }
      card_rarity = Pic_Subsystem_004521a6((int)(char)(&DAT_0051aebe)[candidate_card_id * 0x34], color_filter, 0);
      if (((card_rarity == 0) ||
          (card_rarity = Pic_Subsystem_00452551(candidate_card_id), (int)(((card_counter & 1) == 0) + 1) < card_rarity)) ||
         (((&DAT_0051aed6)[candidate_card_id * 0x34] & 0xc1) == 0)) {
        card_counter = card_counter - 1;
      }
      else {
        Pic_Subsystem_00451e40(candidate_card_id);
      }
    }
  }
  
  /* 3. Generate Creatures */
  creature_attempt_counter = 0;
  for (card_counter = 0; (int)card_counter < num_creatures; card_counter = card_counter + 1) {
    candidate_card_id = Pic_Subsystem_00451d90(2, color_mask);
    if (((DAT_0067f380 < 4) && (((&DAT_0051aecc)[candidate_card_id * 0x34] & 3) != 0)) ||
       (((&DAT_0051aed1)[candidate_card_id * 0x34] & 9) != 0)) {
      card_counter = card_counter - 1;
      creature_attempt_counter = creature_attempt_counter - 1;
    }
    else {
      if (creature_attempt_counter < 1000) {
        card_rarity = Glue_Subsystem_004f0b50(candidate_card_id);
        copy_limit_ok = (0 < card_rarity);
      }
      else {
        copy_limit_ok = true;
      }
      card_rarity = Pic_Subsystem_004521a6((int)(char)(&DAT_0051aebe)[candidate_card_id * 0x34], color_mask, 0);
      if (((card_rarity == 0) ||
          (card_rarity = Pic_Subsystem_00452551(candidate_card_id), (int)(((card_counter & 1) == 0) + 1) < card_rarity)) ||
         ((!copy_limit_ok || (((&DAT_0051aed6)[candidate_card_id * 0x34] & 0xc1) == 0)))) {
        card_counter = card_counter - 1;
      }
      else {
        Pic_Subsystem_00451e40(candidate_card_id);
      }
    }
    creature_attempt_counter = creature_attempt_counter + 1;
  }
  
  /* 4. Generate Guaranteed Rare */
  if (guaranteed_rare_count != 0) {
    do {
      do {
        candidate_card_id = Pic_Subsystem_00451d90(0xe, 1);
        card_rarity = Pic_Subsystem_004521a6((int)(char)(&DAT_0051aebe)[candidate_card_id * 0x34], color_mask, 1);
      } while (card_rarity == 0);
      card_rarity = Pic_Subsystem_00452551(candidate_card_id);
    } while ((((card_rarity < 3) || (card_rarity = Glue_Subsystem_004f0b50(candidate_card_id), card_rarity < 1)) ||
             ((DAT_0067f380 == 0 && (((&DAT_0051aecc)[candidate_card_id * 0x34] & 3) != 0)))) ||
            ((((&DAT_0051aed1)[candidate_card_id * 0x34] & 9) != 0 ||
             (((&DAT_0051aed6)[candidate_card_id * 0x34] & 0xc1) == 0))));
    Pic_Subsystem_00451e40(candidate_card_id);
  }
  return 0;
}
int32_t FUN_0046ed22(uint value,int min_val,int max_val,int target_slot,int flags,int arg_6) {
  return Deck_PopulateCategoryCards(value, min_val, max_val, target_slot, flags, arg_6);
}

/*
 * Decompiled function: Sprite_ResolveAssetPath
 * Entry Point: 0046f172
 * Size: 167 bytes
 */


undefined1 * Sprite_ResolveAssetPath(char *str_1)

{
  if (g_DisplayScreenWidth == 0x280) {
    strcpy(&g_OverworldWorldState,&DAT_00525744);
  }
  else if (g_DisplayScreenWidth == 800) {
    strcpy(&g_OverworldWorldState,s_spr800__0052574c);
  }
  else if (g_DisplayScreenWidth == 0x400) {
    strcpy(&g_OverworldWorldState,s_spr1024__00525754);
  }
  strcat(&g_OverworldWorldState,str_1);
  return &g_OverworldWorldState;
}

/*
 * Decompiled function: FUN_0046f21e
 * Entry Point: 0046f21e
 * Size: 211 bytes
 */


void FUN_0046f21e(char *value,undefined4 min_val,undefined4 max_val)

{
  int local_330;
  int local_32c;
  int local_328;
  undefined4 local_324 [200];
  
  local_330 = 0;
  if (DAT_006781d0 != (void *)0x0) {
    Mem_AllocOrFree_0050fc50(DAT_006781d0);
  }
  Sprite_LoadAll(local_324,value);
  for (local_328 = 0; local_328 < 4; local_328 = local_328 + 1) {
    for (local_32c = 0; local_32c < 9; local_32c = local_32c + 1) {
      (&DAT_006781d0)[local_328 * 9 + local_32c] = (void *)local_324[local_330];
      local_330 = local_330 + 1;
    }
  }
  DAT_00527b34 = min_val;
  DAT_00527b38 = max_val;
  return;
}

/*
 * Decompiled function: FUN_0046f300
 * Entry Point: 0046f300
 * Size: 721 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046f300(void)

{
  int local_c;
  int local_8;
  
  g_CurrentTurnPhase = 0;
  g_ActivePlayerPriority = 1;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    (&DAT_00696870)[local_8] = 0;
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_0063ee90 + local_c * 4 + local_8 * 0x20) = 0;
      *(undefined4 *)(&DAT_0063ee30 + local_c * 4 + local_8 * 0x20) =
           *(undefined4 *)(&DAT_0063ee90 + local_c * 4 + local_8 * 0x20);
      *(undefined4 *)(&DAT_0063edd0 + local_c * 4 + local_8 * 0x20) =
           *(undefined4 *)(&DAT_0063ee30 + local_c * 4 + local_8 * 0x20);
      *(undefined4 *)(&DAT_00627870 + local_8 * 0xcc) = 0xffffffff;
      *(undefined4 *)(&DAT_00627a20 + local_8 * 0x2c) = 0xffffffff;
      *(undefined4 *)(&DAT_0063eed0 + local_8 * 4) = 0;
    }
  }
  g_SpellStackObjects = 0xffffffff;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if ((&g_MasterCardTable)[(g_MasterCardCount + local_c) * 0x34] == -1) {
      *(undefined4 *)(&g_MasterCardTypeTable + (g_MasterCardCount + local_c) * 0x34) = 0xffffffff;
    }
  }
  g_DuelModeFlags = 0;
  DAT_00680788 = 0xffffffff;
  DAT_00627a88 = 0xffffffff;
  DAT_0063ee88 = 0;
  if (DAT_0067f380 == 0) {
    _DAT_006feebc = _DAT_006feebc | 2;
  }
  else {
    _DAT_006feebc = _DAT_006feebc & 0xfffffffd;
  }
  DAT_00680790 = 0;
  DAT_0063edc8 = 0x30;
  DAT_0063ee70 = 0xffffffff;
  _DAT_006fdbd8 = 0xffffffff;
  _DAT_006a2830 = 0xffffffff;
  DAT_00695ec8 = 0xffffffff;
  DAT_006ff2d4 = 0xffffffff;
  DAT_006fedc0 = 0;
  _DAT_006a4934 = 1;
  DAT_006fe3f8 = 0;
  DAT_0063ee1c = 0;
  DAT_007006d0 = 0;
  DAT_006a5f20 = 0;
  DAT_006ff2d8 = 0xffffffff;
  DAT_007006d4 = 0;
  DAT_00627a10 = 1;
  DAT_006ff684 = 0;
  DAT_006b2d24 = 0;
  DAT_006fd3f0 = 0;
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    (&DAT_006b2d40)[local_c] = 0;
  }
  g_OverworldPlayerCoordY = 0xffffffff;
  DAT_006b2d3c = 0xffffffff;
  DAT_006b2d2c = 0xffffffff;
  _DAT_00680780 = 0;
  _DAT_00680784 = 0;
  return;
}

/*
 * Decompiled function: Magic_ExecuteDrawPhase
 * Entry Point: 0046f5d1
 * Size: 1130 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Magic_ExecuteDrawPhase(int value)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  byte local_8;
  
  DAT_006fe408 = 0;
  Magic_RunTurnStep(value,0xcf,s_Draw_a_card_Phase_00525af8,1);
  if (DAT_006fe408 == 0) {
    if (g_CurrentTurnPhase == value) {
      if (DAT_0052effc == -1) {
        local_c = *(int *)(&DAT_0069e730 + value * 2000);
        if (local_c != -1) {
          Pic_Subsystem_004523fd(value,0);
          local_c = Pic_Subsystem_00451291(value,local_c);
        }
      }
      else {
        iVar1 = FUN_0040a02a(DAT_0052effc);
        local_c = Pic_Subsystem_00451291(value,iVar1);
      }
      if ((local_c == -1) || (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + value * 0x5b20) == -1)
         ) {
        if (g_IsAiThinking == 1) {
          (&g_PlayerCreatureCount)[g_CurrentTurnPhase] = 0;
          (&g_PlayerCreatureCount)[1 - g_CurrentTurnPhase] = 0x14;
        }
        else {
          Ai_Util_004cc42d(s_No_more_cards__you_lose__00525b24);
          Sleep(0x9c4);
          Ai_Util_004cc42d(&DAT_00525b40);
          Pic_Util_00450975(0);
        }
      }
      else {
        Ai_Subsystem_004cc9c5(0,0x30);
        if (g_IsAiThinking != 1) {
          if (DAT_0063ee18 == 0) {
            Ai_Subsystem_004cc50a
                      (*(undefined4 *)(&g_CardSlot_CardId + local_c * 0x120 + value * 0x5b20),0xf6,
                       s_Draw_Card_00525b18);
          }
          else {
            Ai_Subsystem_004b137d
                      (*(undefined4 *)(&g_CardSlot_CardId + local_c * 0x120 + value * 0x5b20),value,
                       local_c);
          }
        }
      }
    }
    else {
      if (DAT_0052eff8 == -1) {
        iVar1 = Math_RandomRange(3);
        if (iVar1 == 0) {
          local_8 = 1;
        }
        else if (iVar1 == 1) {
          local_8 = 2;
        }
        else if (iVar1 == 2) {
          local_8 = 0x3c;
        }
        do {
          iVar1 = Math_RandomRange(g_MasterCardCount);
          local_10 = Pic_Subsystem_004521a6
                               ((int)(char)(&DAT_0051aebe)[iVar1 * 0x34],DAT_006b2d64,DAT_00696a18);
          if ((local_10 != 0) && (iVar2 = Pic_Subsystem_00452551(iVar1), DAT_00695df0 < iVar2)) {
            local_10 = 0;
          }
        } while (((local_10 == 0) || ((local_8 & (&g_MasterCardColorTable)[iVar1 * 0x34]) == 0)) ||
                (((&DAT_0051aed0)[iVar1 * 0x34] & 0x40) != 0));
        local_c = Pic_Subsystem_00451291(value,iVar1);
      }
      else if (*(int *)(&DAT_0069e730 + value * 2000) == -1) {
        local_c = -1;
      }
      else {
        local_c = Pic_Subsystem_00451291(value,*(int *)(&DAT_0069e730 + value * 2000));
        if (local_c != -1) {
          Pic_Subsystem_004523fd(value,0);
        }
      }
      if (local_c == -1) {
        if (g_IsAiThinking == 1) {
          (&g_PlayerCreatureCount)[1 - g_CurrentTurnPhase] = 0;
          (&g_PlayerCreatureCount)[g_CurrentTurnPhase] = 0x14;
        }
        else {
          Ai_Util_004cc42d(s_No_more_cards__opponent_loses__00525b44);
          Sleep(0x9c4);
          Ai_Util_004cc42d(&DAT_00525b64);
          Pic_Util_00450975(1);
        }
      }
      Ai_Subsystem_004cc9c5(0,0x30);
    }
    (&DAT_006b3008)[value] = (&DAT_006b3008)[value] + 1;
    _DAT_006b3038 = _DAT_006b3038 + 1;
    if ((g_IsAiThinking != 1) && (local_c != -1)) {
      Duel_PlaySoundById(2);
    }
    if (local_c != -1) {
      *(uint *)(&g_CardSlot_Flags + local_c * 0x120 + value * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + local_c * 0x120 + value * 0x5b20) | 1;
    }
  }
  else {
    local_c = 0;
  }
  return local_c;
}

/*
 * Decompiled function: FUN_0046fe86
 * Entry Point: 0046fe86
 * Size: 202 bytes
 */


undefined4 FUN_0046fe86(int x,int y)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  bVar3 = DAT_00695ec4 == 0xd3;
  if (bVar3) {
    DAT_00525778 = 1;
  }
  iVar1 = FUN_0046ff50(x,y,0);
  if (((iVar1 == 0) || (iVar1 = FUN_0046ff50(x,y,1), iVar1 == 0)) ||
     (iVar1 = FUN_00470b36(x,y), iVar1 == 0)) {
    if (bVar3) {
      DAT_00525778 = 0;
    }
    uVar2 = 0;
  }
  else {
    if (bVar3) {
      DAT_00525778 = 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0046ff50
 * Entry Point: 0046ff50
 * Size: 2993 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0046ff50(int value,int min_val,int max_val)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *str_2;
  undefined4 uVar6;
  int local_18;
  
  iVar5 = *(int *)(&g_CardSlot_CardId + value * 0x5b20 + min_val * 0x120);
  iVar3 = Card_ColorMaskToColorIndex((&DAT_0051aebe)[iVar5 * 0x34]);
  iVar2 = DAT_006b2d3c;
  iVar1 = DAT_006b2d2c;
  iVar4 = DAT_0068a708;
  if (max_val == 0) {
    iVar4 = FUN_00470ea3(value,value,min_val);
    if (iVar4 == 0) {
      return 0;
    }
    DAT_006fefa8 = 0xffffffff;
    DAT_006fe3f4 = 0;
    g_OverworldPlayerCoordY = -1;
    if ((((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x3c) != 0) &&
       (iVar4 = Magic_TriggerCardEvent(value,min_val,0x74,1 - value,0xffffffff), iVar4 == 0)) {
      return 0;
    }
    iVar2 = DAT_006b2d3c;
    iVar1 = DAT_006b2d2c;
    iVar4 = DAT_0068a708;
    g_ActivePlayer = -1;
    DAT_006b2d3c = value;
    DAT_006b2d2c = min_val;
    DAT_0068a708 = iVar5;
    Magic_PushSpellStack(value,min_val,0x71,value,0);
    Ai_Subsystem_004bd4f0();
    if (DAT_006fe3f4 == 0) {
      if ((g_CurrentTurnPhase == value) && (g_IsAiThinking != 1)) {
        if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x40) == 0) {
          (&DAT_006b2d40)[iVar3] = (int)(char)(&DAT_0051aebf)[iVar5 * 0x34];
          DAT_006b2d40 = DAT_006b2d40 + (char)(&DAT_0051aec0)[iVar5 * 0x34];
        }
        else {
          DAT_006b2d58 = (int)(char)(&DAT_0051aebf)[iVar5 * 0x34] +
                         (int)(char)(&DAT_0051aec0)[iVar5 * 0x34];
        }
        Ai_Subsystem_004be192(value,min_val,0,0);
      }
      else if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x40) == 0) {
        if ((&DAT_0051aebf)[iVar5 * 0x34] != '\0') {
          (&DAT_006b2d40)[iVar3] = (int)(char)(&DAT_0051aebf)[iVar5 * 0x34];
        }
        if ('\0' < (char)(&DAT_0051aec0)[iVar5 * 0x34]) {
          DAT_006b2d40 = (int)(char)(&DAT_0051aec0)[iVar5 * 0x34];
        }
        Ai_Subsystem_004be192(value,min_val,0,0);
        if ((&DAT_0051aec0)[iVar5 * 0x34] == -1) {
          if (g_CurrentTurnPhase == value) {
            g_OverworldPlayerCoordY = Font_DrawString(value,7,1);
            Ai_CalcManaRequirement_004ba890(value,0,-1);
          }
          else {
            if (g_IsAiThinking == 1) {
              iVar3 = Math_RandomRange(2);
              if (iVar3 == 0) {
                iVar3 = Font_DrawString(value,7,1);
                if (iVar3 == 0) {
                  iVar3 = Font_DrawString(value,7,1);
                  g_AiChoiceValue = Math_RandomRange(iVar3 + 1);
                  local_18 = g_AiChoiceValue;
                }
                else {
                  iVar3 = Math_RandomRange(iVar3);
                  g_AiChoiceValue = iVar3 + 1;
                  local_18 = g_AiChoiceValue;
                }
              }
              else if (iVar3 == 1) {
                local_18 = Font_DrawString(value,7,1);
                g_AiChoiceValue = local_18;
                if ((g_PlayerCreatureCount < local_18) && (iVar3 = Math_RandomRange(3), iVar3 == 0)) {
                  local_18 = g_PlayerCreatureCount;
                  g_AiChoiceValue = g_PlayerCreatureCount;
                }
                if ((g_OverworldPlayerCoordY != -1) && (g_OverworldPlayerCoordY < g_AiChoiceValue)
                   ) {
                  local_18 = g_OverworldPlayerCoordY;
                  g_AiChoiceValue = g_OverworldPlayerCoordY;
                }
              }
              Ai_RecordChoice();
            }
            else {
              Ai_ReplayChoice();
              local_18 = g_AiChoiceValue;
            }
            g_OverworldPlayerCoordY = local_18;
            Ai_CalcManaRequirement_004ba890(value,0,-1);
          }
          if (g_TurnCounter == 0) {
            g_SpellStackDepth = g_SpellStackDepth + -100;
          }
        }
      }
      else {
        Ai_Subsystem_004be192
                  (value,min_val,6,
                   (int)(char)(&DAT_0051aebf)[iVar5 * 0x34] +
                   (int)(char)(&DAT_0051aec0)[iVar5 * 0x34]);
      }
    }
    g_OverworldPlayerCoordY = -1;
    if (iVar5 != -1) {
      DAT_0068a650 = value;
      _DAT_006a3f70 = 1;
      (&DAT_006b3008)[value] = (&DAT_006b3008)[value] + -1;
      if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 2) != 0) {
        *(int *)(&DAT_006b3010 + value * 4) = *(int *)(&DAT_006b3010 + value * 4) + 1;
      }
      if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x40) != 0) {
        (&DAT_006b3018)[value] = (&DAT_006b3018)[value] + 1;
      }
      if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 4) != 0) {
        *(int *)(&DAT_006b3020 + value * 4) = *(int *)(&DAT_006b3020 + value * 4) + 1;
      }
      (&DAT_006a2828)[value] =
           (&DAT_006a2828)[value] | (uint)(byte)(&g_MasterCardColorTable)[iVar5 * 0x34];
      *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) =
           *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) | 0x20;
      g_DuelModeFlags = g_DuelModeFlags | 0x20;
      if ((g_CurrentTurnPhase == value) || (g_IsAiThinking != 1)) {
        *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) =
             *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) | 0x30000;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) =
             *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) | 0x10000;
      }
      DAT_0068a708 = iVar4;
      DAT_006b2d2c = iVar1;
      DAT_006b2d3c = iVar2;
      if (g_ActivePlayer == 1) {
        Ai_Util_004bd5af();
      }
      else {
        iVar4 = Magic_BroadcastCardEvent(value,min_val,0x6c);
        if (iVar4 != 0) {
          Engine_ReportFatalError(s_Illegal_cast_00525bcc);
          g_ActivePlayer = 1;
        }
        if (g_ActivePlayer == 1) {
          Ai_Subsystem_004bd5e3(value);
        }
        Ai_Util_004bd5af();
        if (g_ActivePlayer != 1) {
          if (((g_IsAiThinking == 1) && (g_ActivePlayerPriority == value)) &&
             ((&DAT_0051aec0)[iVar5 * 0x34] == -1)) {
            iVar5 = FUN_00473d98(value);
            g_SpellStackDepth = g_SpellStackDepth + iVar5 * -0xc;
          }
          return 1;
        }
      }
    }
  }
  else {
    DAT_006b2d3c = value;
    DAT_006b2d2c = min_val;
    DAT_0068a708 = iVar5;
    if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 1) == 0) {
      Magic_MainTurnPhase(1);
    }
    if (((&g_MasterCardColorTable)[iVar5 * 0x34] != '\x01') &&
       (((&g_MasterCardColorTable)[iVar5 * 0x34] != ' ' ||
        (((&DAT_0051aed1)[iVar5 * 0x34] & 0x10) == 0)))) {
      strcpy(&g_OverworldWorldState,s_Trying_to_cast_00525bdc);
      Ai_Subsystem_004b90de(DAT_006b2d3c,DAT_006b2d2c);
      FUN_00475c8a(-2,g_ScWillyScore,&g_OverworldWorldState,0xd3);
    }
    if (*(int *)(&g_CardSlot_CardId + value * 0x5b20 + min_val * 0x120) == -1) {
      g_ActivePlayer = 1;
    }
    g_DuelModeFlags = g_DuelModeFlags & 0xffffffdf;
    DAT_0068a708 = iVar4;
    DAT_006b2d2c = iVar1;
    DAT_006b2d3c = iVar2;
    *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) =
         *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) |
         CONCAT31((uint3)((value == 0) - 1 >> 8) & 0x4000,0x80);
    if (g_IsAiThinking != 1) {
      FUN_004755fd();
    }
    if (g_ActivePlayer != 1) {
      if (((g_CurrentTurnPhase != value) && (g_IsAiThinking != 1)) &&
         (((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x7e) != 0)) {
        strcpy(&g_OverworldWorldState,&DAT_00695e10);
        strcat(&g_OverworldWorldState,s_casts____00525bec);
        if ((&DAT_0051aec0)[iVar5 * 0x34] == -1) {
          strcat(&g_OverworldWorldState,s_X_is_00525bf8);
          str_2 = _itoa(g_TurnCounter,&DAT_00538df8,10);
          strcat(&g_OverworldWorldState,str_2);
          strcat(&g_OverworldWorldState,&DAT_00525c00);
        }
        if ((&g_CardSlot_TurnPlayed)[value * 0x5b20 + min_val * 0x120] == '\0') {
          Ai_Subsystem_004b574d(value,min_val,-1,-1,&g_OverworldWorldState,0);
        }
        else if ((&g_CardSlot_TurnPlayed)[value * 0x5b20 + min_val * 0x120] == '\x01') {
          Ai_Subsystem_004b574d
                    (value,min_val,*(int *)(&g_CardSlot_CombatTarget + value * 0x5b20 + min_val * 0x120)
                     ,*(int *)(&g_CardSlot_AttachedAura + value * 0x5b20 + min_val * 0x120),
                     &g_OverworldWorldState,0);
        }
        else {
          Ai_Subsystem_004b574d(value,min_val,-1,-1,&g_OverworldWorldState,0);
        }
        DAT_00627a84 = g_TurnPlayer;
        DAT_00627a88 = g_ScWillyScore;
      }
      if (g_IsAiThinking != 1) {
        Ai_Subsystem_004cc3f8(value,min_val,2,1);
      }
    }
  }
  if (g_ActivePlayer == 1) {
    (&DAT_006b3008)[value] = (&DAT_006b3008)[value] + 1;
    if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 2) != 0) {
      *(int *)(&DAT_006b3010 + value * 4) = *(int *)(&DAT_006b3010 + value * 4) + -1;
    }
    if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 0x40) != 0) {
      (&DAT_006b3018)[value] = (&DAT_006b3018)[value] + -1;
    }
    if (((&g_MasterCardColorTable)[iVar5 * 0x34] & 4) != 0) {
      *(int *)(&DAT_006b3020 + value * 4) = *(int *)(&DAT_006b3020 + value * 4) + -1;
    }
    *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) =
         *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) & 0xffffff5d;
    *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) =
         *(uint *)(&g_CardSlot_Flags + value * 0x5b20 + min_val * 0x120) & 0xfffcffff;
    if (g_CurrentTurnPhase != value) {
      DAT_00701008 = 1;
    }
    g_ActivePlayer = 0;
    Magic_DropTopSpell();
    g_DuelModeFlags = g_DuelModeFlags & 0xffffffdf;
    uVar6 = 0;
  }
  else {
    FUN_00476482(value,min_val);
    uVar6 = 1;
  }
  return uVar6;
}

/*
 * Decompiled function: FUN_00470b36
 * Entry Point: 00470b36
 * Size: 877 bytes
 */


undefined4 FUN_00470b36(int x,int y)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20);
  Card_ColorMaskToColorIndex((&DAT_0051aebe)[iVar1 * 0x34]);
  if (iVar1 == -1) {
    Magic_DropTopSpell();
    uVar3 = 0;
  }
  else {
    if (((&g_MasterCardColorTable)[iVar1 * 0x34] != '\x01') &&
       (((&g_MasterCardColorTable)[iVar1 * 0x34] != ' ' ||
        (((&DAT_0051aed1)[iVar1 * 0x34] & 0x10) == 0)))) {
      strcpy(&g_OverworldWorldState,s_Cast_00525c04);
      Ai_Subsystem_004b90de(x,y);
      FUN_00475c8a(-2,g_ScWillyScore,&g_OverworldWorldState,0x6c);
    }
    *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0xffffffdf;
    *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 2;
    g_DuelModeFlags = g_DuelModeFlags & 0xffffffdf;
    if (*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) == iVar1) {
      (&DAT_006a2828)[x] =
           (&DAT_006a2828)[x] | (uint)(byte)(&g_MasterCardColorTable)[iVar1 * 0x34];
      if (g_IsAiThinking != 1) {
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0) {
          Duel_PlaySoundById(0x11);
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x40) != 0) {
          Duel_PlaySoundById(0);
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 4) != 0) {
          Duel_PlaySoundById(3);
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x10) != 0) {
          Duel_PlaySoundById(6);
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x20) != 0) {
          Duel_PlaySoundById(7);
        }
        if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 8) != 0) {
          Duel_PlaySoundById(0x10);
        }
      }
      Magic_ResolveTopSpell();
      uVar2 = DAT_006b2e14;
      uVar3 = DAT_00695f08;
      DAT_00695f08 = x;
      DAT_006b2e14 = y;
      FUN_00476205(g_TurnPlayer,0xd3,s_Casting_00525c0c,0);
      DAT_00695f08 = uVar3;
      DAT_006b2e14 = uVar2;
      Pic_Subsystem_004475a4(x);
      DAT_0068a650 = 0xffffffff;
      DAT_0068a708 = 0xffffffff;
      if (g_ActivePlayer == 1) {
        if (g_IsAiThinking != 1) {
          Ai_Util_004cc42d(s_fizzle_00525c14);
          Sleep(2000);
          Ai_Util_004cc42d(&DAT_00525c1c);
        }
        DAT_00701008 = 1;
        g_ActivePlayer = 0;
        uVar3 = 0;
      }
      else {
        g_ActivePlayer = 0;
        Ai_Subsystem_004cc9c5(0,0xff);
        uVar3 = 1;
      }
    }
    else {
      Magic_DropTopSpell();
      uVar3 = 0;
    }
  }
  return uVar3;
}

/*
 * Decompiled function: FUN_00470ea3
 * Entry Point: 00470ea3
 * Size: 408 bytes
 */


bool FUN_00470ea3(int value,int min_val,int max_val)

{
  int iVar1;
  uint width;
  int iVar2;
  bool bVar3;
  
  if (((value == -1) || (min_val == -1)) || (max_val == -1)) {
    bVar3 = false;
  }
  else {
    iVar1 = *(int *)(&g_CardSlot_CardId + max_val * 0x120 + min_val * 0x5b20);
    if (iVar1 == -1) {
      bVar3 = false;
    }
    else if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x40) == 0) {
      width = Card_ColorMaskToColorIndex((&DAT_0051aebe)[iVar1 * 0x34]);
      iVar2 = FUN_0040dcca(value,max_val,width,(int)(char)(&DAT_0051aebf)[iVar1 * 0x34]);
      bVar3 = iVar2 != 0;
      if (('\0' < (char)(&DAT_0051aec0)[iVar1 * 0x34]) &&
         (iVar1 = FUN_0040dcca(value,max_val,7,
                               (int)(char)(&DAT_0051aebf)[iVar1 * 0x34] +
                               (int)(char)(&DAT_0051aec0)[iVar1 * 0x34]), iVar1 == 0)) {
        bVar3 = false;
      }
    }
    else {
      iVar1 = Font_DrawString(value,6,(int)(char)(&DAT_0051aebf)[iVar1 * 0x34] +
                                   (int)(char)(&DAT_0051aec0)[iVar1 * 0x34]);
      bVar3 = iVar1 != 0;
    }
  }
  return bVar3;
}

/*
 * Decompiled function: FUN_0047103b
 * Entry Point: 0047103b
 * Size: 2358 bytes
 */


bool FUN_0047103b(int x,int y)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  uint local_28;
  int local_24;
  int local_20;
  uint local_18;
  uint local_14;
  int local_c;
  
  local_c = x;
  if (g_ScWillyScore == 4) {
    local_c = DAT_0063edc0;
  }
  if ((g_CurrentTurnPhase != local_c) && (g_IsAiThinking != 1)) {
    Magic_TriggerCardEvent(x,y,0x90,1 - x,0xffffffff);
    strcpy(&g_OverworldWorldState,&DAT_00695e10);
    strcat(&g_OverworldWorldState,s_activates____00525c20);
    iVar2 = FUN_004769c4(x,y);
    if (iVar2 == 0) {
      if (((((&DAT_0051aed0)[*(int *)(&g_CardSlot_CardId + x * 0x5b20 + y * 0x120) * 0x34] &
            0x18) != 0) && (g_TurnPlayer == x)) && (DAT_0062785c != 0)) {
        strcat(&g_OverworldWorldState,s__with_00525c3c);
        pcVar3 = _itoa(DAT_0062785c,&DAT_00538df8,10);
        strcat(&g_OverworldWorldState,pcVar3);
        strcat(&g_OverworldWorldState,s_mana___00525c44);
      }
    }
    else {
      strcat(&g_OverworldWorldState,s_X_is_00525c30);
      pcVar3 = _itoa(DAT_0062785c,&DAT_00538df8,10);
      strcat(&g_OverworldWorldState,pcVar3);
      strcat(&g_OverworldWorldState,&DAT_00525c38);
    }
    if ((&g_CardSlot_TurnPlayed)[x * 0x5b20 + y * 0x120] == '\0') {
      if (DAT_006fefa8 == 0xffffffff) {
        Ai_Subsystem_004b574d(x,y,-1,-1,&g_OverworldWorldState,0);
      }
      else {
        Ai_Subsystem_004b574d
                  (x,y,(int)DAT_006fefa8 >> 8,DAT_006fefa8 & 0xff,&g_OverworldWorldState,0);
      }
    }
    else if ((&g_CardSlot_TurnPlayed)[x * 0x5b20 + y * 0x120] == '\x01') {
      Ai_Subsystem_004b574d
                (x,y,*(int *)(&g_CardSlot_CombatTarget + x * 0x5b20 + y * 0x120),
                 *(int *)(&g_CardSlot_AttachedAura + x * 0x5b20 + y * 0x120),
                 &g_OverworldWorldState,0);
    }
    else {
      Ai_Subsystem_004b574d(x,y,-1,-1,&g_OverworldWorldState,0);
    }
  }
  Magic_PushSpellStack(x,y,0x72,x,0);
  DAT_00695df8 = 0;
  if (((&g_CardSlot_SpecialState)[x * 0x5b20 + y * 0x120] & 1) == 0) {
    if ((((&g_CardSlot_SpecialState)[x * 0x5b20 + y * 0x120] & 0x10) != 0) &&
       (iVar2 = FUN_00476675(x,y), iVar2 != 0)) {
      for (local_24 = 0; local_24 < 7; local_24 = local_24 + 1) {
        (&DAT_006b2d40)[local_24] =
             (int)(char)(&DAT_006a603c)[local_24 + y * 0x120 + x * 0x5b20];
      }
      Ai_CalcManaRequirement_004ba890(x,0,0);
      if ((g_ActivePlayer == 0) &&
         (Magic_TriggerCardEvent(x,y,1,1 - x,0xffffffff), DAT_006b2e38 == 0)) {
        *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) =
             *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) | 0x40;
      }
      if (g_ActivePlayer != 0) {
        g_ActivePlayer = 0;
        Magic_DropTopSpell();
        return false;
      }
      *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) =
           *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) & 0xffffffef;
      *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) =
           *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) | 0x80;
      Magic_MainTurnPhase(1);
      return true;
    }
    iVar2 = Magic_BroadcastCardEvent(x,y,0x80);
    if (iVar2 == 0) {
      if (((&DAT_0051aed1)[*(int *)(&g_CardSlot_CardId + x * 0x5b20 + y * 0x120) * 0x34] &
          0x10) != 0) {
        DAT_006ff2d4 = -1;
      }
      Ai_Subsystem_004bd4f0();
      uVar1 = *(uint *)(&g_CardSlot_Flags + x * 0x5b20 + y * 0x120);
      Magic_TriggerCardEvent(x,y,0x6d,1 - x,0xffffffff);
      bVar4 = g_ActivePlayer == 1;
      if (bVar4) {
        Ai_Subsystem_004bd5e3(x);
        Magic_DropTopSpell();
      }
      bVar4 = !bVar4;
      Ai_Util_004bd5af();
      if (bVar4) {
        if (((uVar1 & 0x10) == 0) &&
           (((&g_CardSlot_Flags)[x * 0x5b20 + y * 0x120] & 0x10) != 0)) {
          Magic_BroadcastCardEvent(x,y,0x81);
        }
        if (*(int *)(&g_CardSlot_CardId + x * 0x5b20 + y * 0x120) == -1) {
          local_28 = *(uint *)(&DAT_0051aed0 +
                              *(int *)(&g_ActiveCardsInPlay + x * 0x5b20 + y * 0x120) * 0x34);
        }
        else {
          local_28 = *(uint *)(&DAT_0051aed0 +
                              *(int *)(&g_CardSlot_CardId + x * 0x5b20 + y * 0x120) * 0x34);
        }
        local_28 = local_28 & 0x1000;
        if ((local_28 == 0) || (DAT_006ff2d4 == -1)) {
          Magic_MainTurnPhase(1);
        }
        else {
          Magic_MainTurnPhase(0);
        }
        if (g_IsAiThinking != 1) {
          if ((((&DAT_0051aed1)[*(int *)(&g_CardSlot_CardId + x * 0x5b20 + y * 0x120) * 0x34]
               & 0x10) == 0) || (DAT_006ff2d4 == -1)) {
            Duel_PlaySoundById(0x1c);
          }
          else {
            Duel_PlaySoundById(0x12);
          }
        }
        if (g_IsAiThinking != 1) {
          FUN_004755fd();
        }
      }
    }
    else {
      Magic_DropTopSpell();
      bVar4 = false;
    }
    if (bVar4 != false) {
      return bVar4;
    }
    DAT_00695df8 = 0;
    return false;
  }
  bVar4 = true;
  local_20 = 0;
  for (local_18 = 0; (int)local_18 < 7; local_18 = local_18 + 1) {
    (&DAT_006b2d40)[local_18] = (int)(char)(&DAT_006a6048)[local_18 + y * 0x120 + x * 0x5b20];
    if ((0 < (int)local_18) &&
       (iVar2 = Font_DrawString(x,local_18,(&DAT_006b2d40)[local_18]), iVar2 == 0)) {
      bVar4 = false;
    }
    local_20 = local_20 + (&DAT_006b2d40)[local_18];
  }
  iVar2 = Font_DrawString(local_c,7,local_20);
  if (iVar2 == 0) {
    bVar4 = false;
  }
  local_14 = (uint)!bVar4;
  if ((((&DAT_006a6045)[x * 0x5b20 + y * 0x120] & 1) != 0) ||
     (iVar2 = Ai_Subsystem_004cc56d
                        (local_c,x,y,-1,-1,s_Pay_Upkeep_costs__Don_t_pay_Upke_00525c4c,
                         local_14), iVar2 == 0)) {
    if (!bVar4) goto LAB_004714f6;
    Ai_CalcManaRequirement_004ba890(local_c,0,0);
    if ((g_ActivePlayer == 0) &&
       (Magic_TriggerCardEvent(x,y,4,1 - x,0xffffffff), DAT_006b2e38 == 0)) {
      *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) =
           *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) | 0x200;
    }
  }
  if (g_ActivePlayer != 0) {
    g_ActivePlayer = 0;
    Magic_DropTopSpell();
    return false;
  }
LAB_004714f6:
  for (local_18 = 0; (int)local_18 < 7; local_18 = local_18 + 1) {
    (&DAT_006b2d40)[local_18] = 0;
  }
  *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) =
       *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) & 0xfffffffe;
  *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) =
       *(uint *)(&g_CardSlot_SpecialState + x * 0x5b20 + y * 0x120) | 8;
  Magic_MainTurnPhase(1);
  return true;
}

/*
 * Decompiled function: FUN_00471971
 * Entry Point: 00471971
 * Size: 329 bytes
 */


undefined4 FUN_00471971(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_14;
  
  if ((((&DAT_0051aed1)[*(int *)(&g_CardSlot_CardId + x * 0x5b20 + y * 0x120) * 0x34] & 0x10)
       == 0) || (DAT_006ff2d4 == -1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (g_ActivePlayer != 1) {
    if ((!bVar1) && (DAT_00695df8 == 0)) {
      strcpy(&g_OverworldWorldState,s_Activate_00525c74);
      Ai_Subsystem_004b90de(x,y);
      if ((DAT_0063ee1c == 0) || (x != g_CurrentTurnPhase)) {
        local_14 = -2;
      }
      else {
        local_14 = -1;
      }
      FUN_00475c8a(local_14,g_ScWillyScore,&g_OverworldWorldState,0x6d);
    }
    Magic_ResolveTopSpell();
    uVar3 = DAT_006b2e14;
    uVar2 = DAT_00695f08;
    DAT_00695f08 = x;
    DAT_006b2e14 = y;
    FUN_00476205(g_TurnPlayer,0xd2,s_Tapping_00525c80,0);
    DAT_00695f08 = uVar2;
    DAT_006b2e14 = uVar3;
  }
  return 1;
}

/*
 * Decompiled function: FUN_00471aba
 * Entry Point: 00471aba
 * Size: 262 bytes
 */


undefined4 FUN_00471aba(int value,int min_val,int max_val)

{
  undefined4 uVar1;
  
  DAT_0068078c = 1;
  Magic_PushSpellStack(value,min_val,0x7e,max_val,0);
  if (g_ActivePlayer == 1) {
    Magic_DropTopSpell();
    uVar1 = 0;
  }
  else {
    if (g_IsAiThinking != 1) {
      FUN_004755fd();
      if (g_CurrentTurnPhase != DAT_006a4b5c) {
        strcpy(&g_OverworldWorldState,&DAT_00695e10);
        strcat(&g_OverworldWorldState,s_processes____00525c88);
        Ai_Subsystem_004b574d(value,min_val,-1,-1,&g_OverworldWorldState,0);
      }
    }
    *(uint *)(&g_CardSlot_Flags + min_val * 0x120 + value * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + min_val * 0x120 + value * 0x5b20) | 0x100;
    strcpy(&g_OverworldWorldState,s_Process_00525c98);
    Ai_Subsystem_004b90de(value,min_val);
    uVar1 = Magic_ResolveTopSpell();
  }
  DAT_0068078c = 0;
  return uVar1;
}

/*
 * Decompiled function: FUN_00471bc0
 * Entry Point: 00471bc0
 * Size: 114 bytes
 */


bool FUN_00471bc0(int x,int y)

{
  bool bVar1;
  
  if (*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) == -1) {
    bVar1 = false;
  }
  else {
    bVar1 = ((byte)*(undefined4 *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0x22) != 2;
  }
  return bVar1;
}

/*
 * Decompiled function: Card_IsTapped
 * Entry Point: 00471c32
 * Size: 114 bytes
 */


bool Card_IsTapped(int x,int y)

{
  bool bVar1;
  
  if (*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) == -1) {
    bVar1 = false;
  }
  else {
    bVar1 = ((byte)*(undefined4 *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0x22) == 2;
  }
  return bVar1;
}

/*
 * Decompiled function: FUN_00471ca4
 * Entry Point: 00471ca4
 * Size: 114 bytes
 */


undefined4 FUN_00471ca4(int x,int y)

{
  undefined4 uVar1;
  
  if (*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) == -1) {
    uVar1 = 0;
  }
  else if (((byte)*(undefined4 *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0x1e) == 2) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00471d16
 * Entry Point: 00471d16
 * Size: 722 bytes
 */


void FUN_00471d16(uint value)

{
  int iVar1;
  int aiStack_100 [16];
  int aiStack_c0 [16];
  uint local_80;
  int local_70;
  int local_64;
  int local_50;
  int local_3c;
  int local_38;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  if (g_IsAiThinking != 1) {
    Ai_Subsystem_004cc9c5(0,0xff);
    local_80 = value;
    local_2c = 1 - value;
    local_70 = 0;
    local_30 = 0;
    for (local_50 = 0; local_50 < (int)(&g_PlayerActiveCardCount)[value]; local_50 = local_50 + 1) {
      local_38 = *(int *)(&g_CardSlot_CardId + local_50 * 0x120 + value * 0x5b20);
      if ((local_38 != -1) && (((&g_CardSlot_Flags)[local_50 * 0x120 + value * 0x5b20] & 4) != 0)) {
        local_64 = Magic_QueryCardAttribute(value,local_50,0x32,0xffffffff);
        aiStack_100[local_30] = local_50;
        aiStack_c0[local_30] = local_64;
        local_30 = local_30 + 1;
        if (local_70 < local_64) {
          local_70 = local_64;
        }
      }
    }
    local_20 = 0;
    while ((local_20 == 0 && (iVar1 = FUN_00472a0a(local_2c), iVar1 != 0))) {
      iVar1 = Duel_ChooseTarget
                        (local_2c,local_2c,local_2c,0x2200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0
                         ,0,0x11,s_Choose_blockers_00525ca4,2,&local_28);
      if (iVar1 == 0) {
        local_20 = 1;
      }
      else {
        iVar1 = Duel_ChooseTarget
                          (local_2c,local_80,local_80,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,
                           0,2,0,s_Block_which_attacker__00525cb4,1,&local_1c);
        if (iVar1 != 0) {
          iVar1 = FUN_00472e08(local_28,local_24,local_1c,local_18);
          if (iVar1 == 0) {
            if (g_IsAiThinking != 1) {
              Ai_Util_004cc42d(s_Illegal_block__00525ccc);
              Sleep(2000);
              Ai_Util_004cc42d(&DAT_00525cdc);
            }
          }
          else {
            local_3c = (int)(char)(&g_CardSlot_ColorMask)[local_1c * 0x5b20 + local_18 * 0x120];
            if (local_3c == -1) {
              (&g_CardSlot_ColorMask)[local_28 * 0x5b20 + local_24 * 0x120] = (undefined1)local_18;
            }
            else {
              (&g_CardSlot_ColorMask)[local_28 * 0x5b20 + local_24 * 0x120] =
                   (&g_CardSlot_ColorMask)[local_1c * 0x5b20 + local_18 * 0x120];
            }
            *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) | 8;
            Ai_Subsystem_004cc9c5(0,0xff);
          }
        }
      }
    }
  }
  return;
}

/*
 * Decompiled function: FUN_00472616
 * Entry Point: 00472616
 * Size: 175 bytes
 */


undefined4 FUN_00472616(int value)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if ((int)(&g_PlayerActiveCardCount)[value] <= local_8) {
      return 0;
    }
    if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + value * 0x5b20) != -1) &&
        (((&g_CardSlot_Flags)[local_8 * 0x120 + value * 0x5b20] & 6) != 0)) &&
       (iVar1 = FUN_004726c5(value,local_8), iVar1 != 0)) break;
    local_8 = local_8 + 1;
  }
  return 1;
}

/*
 * Decompiled function: FUN_004726c5
 * Entry Point: 004726c5
 * Size: 510 bytes
 */


undefined4 FUN_004726c5(int x,int y)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = g_ActivePlayer;
  iVar3 = g_CardEventResult;
  if (((((&DAT_0051aebd)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] == '\0'
        ) && (((&DAT_006a5f69)[y * 0x120 + x * 0x5b20] & 8) == 0)) ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] & 2) == 0)) ||
     (((*(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0x10010) != 0 ||
      (((&DAT_006a5f69)[y * 0x120 + x * 0x5b20] & 0x80) != 0)))) {
    uVar2 = 0;
    g_CardEventResult = iVar3;
    g_ActivePlayer = uVar1;
  }
  else {
    g_CardEventResult = 0;
    (**(code **)(&DAT_0051aec8 + *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34)
    )(x,y,0x79);
    if (g_CardEventResult == 0) {
      g_CardEventResult = iVar3;
      g_ActivePlayer = uVar1;
      if (g_ActivePlayerPriority == x) {
        Magic_PushEventContext();
        g_CardEventResult = 0;
        g_EventSourcePlayer = x;
        g_EventSourceSlot = y;
        Glue_Subsystem_004e65e1(Pic_Subsystem_0042e80e,-1);
        iVar3 = g_CardEventResult;
        Magic_PopEventContext();
        if (iVar3 != 0) {
          return 0;
        }
      }
      if ((*(int *)(&DAT_00680780 + (1 - x) * 4) != 0) &&
         (iVar3 = Magic_BroadcastCardEvent(x,y,0x79), iVar3 != 0)) {
        return 0;
      }
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
      g_CardEventResult = iVar3;
      g_ActivePlayer = uVar1;
    }
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_004728c3
 * Entry Point: 004728c3
 * Size: 66 bytes
 */


bool FUN_004728c3(int x,int y)

{
  return ((&DAT_006a5f3d)[y * 0x120 + x * 0x5b20] & 0x20) != 0;
}

/*
 * Decompiled function: FUN_00472905
 * Entry Point: 00472905
 * Size: 261 bytes
 */


undefined4 FUN_00472905(int value)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  DAT_006a5f20 = 0;
  DAT_00626810 = 0;
  for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[value]; local_8 = local_8 + 1) {
    iVar1 = Card_IsTapped(value,local_8);
    if (iVar1 != 0) {
      if (((&g_CardSlot_Flags)[value * 0x5b20 + local_8 * 0x120] & 4) == 0) {
        if (((&DAT_006a5f3d)[value * 0x5b20 + local_8 * 0x120] & 0x80) != 0) {
          iVar1 = FUN_004726c5(value,local_8);
          if (iVar1 != 0) {
            DAT_00626810 = DAT_00626810 + 1;
          }
        }
      }
      else {
        DAT_006a5f20 = 1;
      }
    }
  }
  if ((DAT_006a5f20 == 0) && (DAT_00626810 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_00472a0a
 * Entry Point: 00472a0a
 * Size: 391 bytes
 */


undefined4 FUN_00472a0a(int value)

{
  int x;
  uint flags;
  int iVar1;
  int local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  x = 1 - value;
  Ai_FilterValidBlockers(&local_8,&local_10);
  if (value == 1) {
    local_14 = local_8;
  }
  else {
    local_14 = local_10;
  }
  local_c = 0;
  do {
    if ((int)(&g_PlayerActiveCardCount)[x] <= local_c) {
      return 0;
    }
    if ((*(int *)(&g_CardSlot_CardId + x * 0x5b20 + local_c * 0x120) != -1) &&
       (((&g_CardSlot_Flags)[x * 0x5b20 + local_c * 0x120] & 4) != 0)) {
      flags = Magic_QueryCardAttribute(x,local_c,0x34,0xffffffff);
      for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[value]; local_18 = local_18 + 1)
      {
        if (((*(int *)(&g_CardSlot_CardId + x * 0x5b20 + local_c * 0x120) != -1) &&
            (((byte)*(undefined4 *)(&g_CardSlot_Flags + local_18 * 0x120 + value * 0x5b20) & 0x1a)
             == 2)) && (iVar1 = FUN_00472c0c(value,local_18,x,local_c,flags,local_14), iVar1 != 0))
        {
          return 1;
        }
      }
    }
    local_c = local_c + 1;
  } while( true );
}

/*
 * Decompiled function: FUN_00472b91
 * Entry Point: 00472b91
 * Size: 123 bytes
 */


undefined4 FUN_00472b91(int x,int min_val,int max_val,int target_slot)

{
  uint flags;
  undefined4 uVar1;
  uint local_10;
  uint local_c;
  uint local_8;
  
  flags = Magic_QueryCardAttribute(max_val,target_slot,0x34,0xffffffff);
  Ai_FilterValidBlockers(&local_8,&local_c);
  if (x == 1) {
    local_10 = local_8;
  }
  else {
    local_10 = local_c;
  }
  uVar1 = FUN_00472c0c(x,min_val,max_val,target_slot,flags,local_10);
  return uVar1;
}

/*
 * Decompiled function: FUN_00472c0c
 * Entry Point: 00472c0c
 * Size: 508 bytes
 */


/* WARNING: Removing unreachable block (ram,0x00472d06) */

bool FUN_00472c0c(int value,int min_val,undefined4 max_val,undefined4 target_slot,uint flags,uint arg_6)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  if (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + min_val * 0x120 + value * 0x5b20) * 0x34] & 2) == 0) {
    bVar2 = false;
  }
  else if ((*(int *)(&g_CardSlot_CardId + min_val * 0x120 + value * 0x5b20) == -1) ||
          (((&g_CardSlot_Flags)[min_val * 0x120 + value * 0x5b20] & 0x18) != 0)) {
    bVar2 = false;
  }
  else if ((((&g_CardSlot_Flags)[min_val * 0x120 + value * 0x5b20] & 4) == 0) ||
          (iVar3 = FUN_004728c3(value,min_val), iVar3 != 0)) {
    if (((flags & 0x20) == 0) ||
       (uVar4 = Magic_QueryCardAttribute(value,min_val,0x34,0xffffffff), (uVar4 & 0x420) != 0)) {
      if (((flags & 0x1ff800) == 0) ||
         (cVar1 = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[min_val * 0x120 + value * 0x5b20]),
         (flags & 0x800 << (cVar1 - 1U & 0x1f)) == 0)) {
        if ((arg_6 & flags & 0x1f) == 0) {
          Magic_PushEventContext();
          g_EventSourcePlayer = value;
          g_EventSourceSlot = min_val;
          g_EventTargetPlayer = max_val;
          g_EventTargetSlot = target_slot;
          g_CardEventResult = 0;
          Magic_ScanCards(0x78);
          bVar2 = g_CardEventResult < 1;
          Magic_PopEventContext();
        }
        else {
          bVar2 = false;
        }
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}

/*
 * Decompiled function: FUN_00472e08
 * Entry Point: 00472e08
 * Size: 260 bytes
 */


int FUN_00472e08(int x,int y,undefined4 max_val,undefined4 target_slot)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = *(undefined4 *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20);
  uVar1 = (&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20];
  *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
       *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0xfffffff7;
  (&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20] = 0xff;
  iVar3 = FUN_00472b91(x,y,max_val,target_slot);
  if (iVar3 == 0) {
    *(undefined4 *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) = uVar2;
    (&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20] = uVar1;
  }
  return iVar3;
}

/*
 * Decompiled function: FUN_00472f0c
 * Entry Point: 00472f0c
 * Size: 162 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00472f0c(undefined4 x,int y)

{
  char cVar1;
  int iVar2;
  
  DAT_0069f6d8 = 0xffffd8f1;
  g_IsAiThinking = 1;
  DAT_006808a8 = x;
  iVar2 = (DAT_0067f380 + 1) * y;
  DAT_006fe40c = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
  cVar1 = Math_RandomRange(5);
  _DAT_00679ed0 = 1 << (cVar1 + 1U & 0x1f);
  Ai_SaveGameState();
  Mem_AllocOrFree_005016f9();
  Glue_Util_004cd715();
  DAT_006b1580 = 0;
  DAT_006a2838 = 1;
  Pic_Subsystem_0044b8da();
  Mem_AllocOrFree_00512220(1,1,DAT_006784f0);
  Pic_Subsystem_0044b8aa();
  DAT_0067bdb0 = 0;
  return;
}

/*
 * Decompiled function: FUN_00472fae
 * Entry Point: 00472fae
 * Size: 459 bytes
 */


void FUN_00472fae(void)

{
  short sVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      if ((((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0) &&
         (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1)) {
        *(uint *)(&g_CardSlot_Abilities2 + local_c * 0x120 + local_8 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + local_c * 0x120 + local_8 * 0x5b20) | 0xf000000;
        Magic_QueryCardAttribute(local_8,local_c,0x3c,0xffffffff);
      }
    }
  }
  Ai_Subsystem_004cced8();
  Ai_Subsystem_004ccca3();
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      iVar2 = Card_IsTapped(local_8,local_c);
      if (((iVar2 != 0) &&
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0))
         && (sVar1 = *(short *)(&g_CardSlot_Power + local_c * 0x120 + local_8 * 0x5b20),
            iVar2 = Magic_QueryCardAttribute(local_8,local_c,0x33,0xffffffff), sVar1 < iVar2)) {
        Magic_QueryCardAttribute(local_8,local_c,0x32,0xffffffff);
      }
    }
  }
  return;
}

/*
 * Decompiled function: Magic_QueryCardAttribute
 * Entry Point: 00473179
 * Size: 2823 bytes
 */


uint Magic_QueryCardAttribute(int player,int slot,int event_code,undefined4 target_slot)

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
  
  uVar3 = DAT_0067bdb0;
  DAT_00677340 = DAT_00677340 + 1;
  if (DAT_0063ee18 != 0) {
    Magic_PushEventContext();
  }
  g_EventSourcePlayer = player;
  g_EventSourceSlot = slot;
  g_EventCardId = *(int *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20);
  g_EventCardColorMask = (int)(char)(&DAT_0051aebe)[g_EventCardId * 0x34];
  g_EventTargetSlot = target_slot;
  switch(event_code) {
  case 0x32:
    if (((&g_CardSlot_Flags)[slot * 0x120 + player * 0x5b20] & 2) == 0) {
      local_8 = (uint)*(short *)(&DAT_0051aec2 + g_EventCardId * 0x34);
    }
    else {
      local_8 = (int)*(short *)(&DAT_0051aec2 + g_EventCardId * 0x34) & 0xffffbfff;
    }
    local_8 = local_8 + (int)*(short *)(&DAT_006a5f48 + slot * 0x120 + player * 0x5b20);
    if (((&DAT_006a5f6f)[slot * 0x120 + player * 0x5b20] & 4) != 0) {
      *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) & 0xfbffffff;
      goto LAB_004737a0;
    }
    g_CardEventResult = (uint)*(short *)(&g_CardSlot_Counters + slot * 0x120 + player * 0x5b20);
    break;
  case 0x33:
    if (((&g_CardSlot_Flags)[slot * 0x120 + player * 0x5b20] & 2) == 0) {
      local_8 = (uint)*(short *)(&DAT_0051aec4 + g_EventCardId * 0x34);
    }
    else {
      local_8 = (int)*(short *)(&DAT_0051aec4 + g_EventCardId * 0x34) & 0xffffbfff;
    }
    local_8 = local_8 + (int)*(short *)(&DAT_006a5f4a + slot * 0x120 + player * 0x5b20);
    if (((&DAT_006a5f6f)[slot * 0x120 + player * 0x5b20] & 2) != 0) {
      *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) & 0xfdffffff;
      goto LAB_004737a0;
    }
    g_CardEventResult = (uint)*(short *)(&DAT_006a5f46 + slot * 0x120 + player * 0x5b20);
    break;
  case 0x34:
    uVar1 = *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20);
    uVar2 = *(uint *)(&DAT_0051aecc + g_EventCardId * 0x34);
    local_8 = uVar1 & 0x7000000 | uVar2;
    if ((uVar2 & 0x1ff81f) != 0) {
      local_1c = 0;
      for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
        if ((local_8 & 1 << ((byte)local_18 & 0x1f)) != 0) {
          cVar4 = Card_UntapCard(player,slot,local_18 + 1);
          local_1c = local_1c | 1 << (cVar4 - 1U & 0x1f);
        }
        if ((local_8 & 0x800 << ((byte)local_18 & 0x1f)) != 0) {
          cVar4 = Card_SetTapState(player,slot,local_18 + 1);
          local_1c = local_1c | 0x800 << (cVar4 - 1U & 0x1f);
        }
      }
      local_8 = uVar1 & 0x7000000 | uVar2 & 0xffe007e0 | local_1c;
    }
    if (((&DAT_006a5f6f)[slot * 0x120 + player * 0x5b20] & 8) != 0) {
      *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) & 0xf7ffffff;
      goto LAB_004737a0;
    }
    g_CardEventResult = *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20);
    break;
  case 0x35:
    local_8 = (uint)*(short *)(&g_CardSlot_Power + slot * 0x120 + player * 0x5b20);
    goto LAB_004737a0;
  case 0x36:
    local_8 = (uint)(char)(&DAT_0051aebe)[g_EventCardId * 0x34];
    goto LAB_004737a0;
  default:
    local_8 = 0;
LAB_004737a0:
    g_CardEventResult = local_8;
    if ((DAT_0063ee18 != 0) && (Magic_ScanCards(event_code), (g_DuelModeFlags & 0x10000) != 0)) {
      g_DuelModeFlags = g_DuelModeFlags & 0xfffeffff;
      *(uint *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) = g_CardEventResult;
      g_DuelModeFlags = g_DuelModeFlags | 0x20000;
      Magic_ScanCards(event_code);
      g_DuelModeFlags = g_DuelModeFlags & 0xfffdffff;
    }
    if (event_code == 0x32) {
      if ((int)g_CardEventResult < 0) {
        g_CardEventResult = 0;
      }
      if (((&DAT_006a5f69)[slot * 0x120 + player * 0x5b20] & 0x40) != 0) {
        g_CardEventResult = g_CardEventResult << 1;
      }
    }
    break;
  case 0x3c:
    if (((*(int *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) < DAT_006ff2e0) ||
        (DAT_006ff2e0 + 0x1d <= *(int *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20))) &&
       (*(int *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) != -1)) {
      local_8 = *(uint *)(&g_ActiveCardsInPlay + slot * 0x120 + player * 0x5b20);
      if (((&DAT_006a5f6f)[slot * 0x120 + player * 0x5b20] & 1) != 0) {
        *(undefined4 *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) =
             *(undefined4 *)(&g_ActiveCardsInPlay + slot * 0x120 + player * 0x5b20);
        *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) & 0xfeffffff;
        (&DAT_006a604f)[slot * 0x120 + player * 0x5b20] = 0;
        goto LAB_004737a0;
      }
      g_CardEventResult = *(uint *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20);
    }
    else {
      g_CardEventResult = *(uint *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20);
    }
  }
  uVar1 = g_CardEventResult;
  iVar5 = Card_IsTapped(player,slot);
  if (((iVar5 != 0) && (event_code == 0x33)) &&
     ((((&g_MasterCardColorTable)[g_EventCardId * 0x34] & 2) != 0 &&
      (((((int)uVar1 < 1 ||
         ((int)uVar1 <= (int)*(short *)(&g_CardSlot_Power + slot * 0x120 + player * 0x5b20))) &&
        (g_CurrentStepCode == -1)) && ((g_DuelModeFlags & 0x204) == 0)))))) {
    Pic_Subsystem_0044867e(player,slot,2);
    Pic_Subsystem_004488a0();
  }
  if (DAT_0063ee18 != 0) {
    Magic_PopEventContext();
  }
  if (event_code == 0x32) {
    *(short *)(&g_CardSlot_Counters + slot * 0x120 + player * 0x5b20) = (short)uVar1;
  }
  if (event_code == 0x33) {
    *(short *)(&DAT_006a5f46 + slot * 0x120 + player * 0x5b20) = (short)uVar1;
  }
  if (event_code == 0x34) {
    *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) = uVar1;
  }
  if (event_code != 0x3c) {
    DAT_0067bdb0 = uVar3;
    return uVar1;
  }
  *(uint *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) = uVar1;
  if (((&DAT_0051aed1)[uVar1 * 0x34] & 0x10) == 0) goto LAB_00473adb;
  iVar5 = *(int *)(&g_MasterCardTypeTable + uVar1 * 0x34);
  if (iVar5 < 0x12d) {
    if (iVar5 == 300) {
      (&DAT_006a5f4c)[slot * 0x120 + player * 0x5b20] = 1;
      goto LAB_00473adb;
    }
    if (iVar5 == 0xf) {
      (&DAT_006a5f4c)[slot * 0x120 + player * 0x5b20] = 0x3e;
      goto LAB_00473adb;
    }
  }
  else if ((iVar5 == 0x13e) || (iVar5 == 0x366)) goto LAB_00473adb;
  (&DAT_006a5f4c)[slot * 0x120 + player * 0x5b20] = (&DAT_0051aebe)[uVar1 * 0x34];
LAB_00473adb:
  if ((((&g_CardSlot_Abilities1)[slot * 0x120 + player * 0x5b20] & 0x40) != 0) &&
     (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) * 0x34] & 2)
      == 0)) {
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_c];
          local_10 = local_10 + 1) {
        if ((((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20) != -1) &&
             (((&g_CardSlot_Flags)[local_10 * 0x120 + local_c * 0x5b20] & 2) != 0)) &&
            ((char)(&g_CardSlot_Toughness)[local_10 * 0x120 + local_c * 0x5b20] == player)) &&
           (((*(int *)(&g_CardSlot_OriginalCardId + local_10 * 0x120 + local_c * 0x5b20) == slot &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20) * 0x34] & 4) != 0
             )) && (*(int *)(&DAT_006b3088 +
                            *(int *)(&g_MasterCardTypeTable +
                                    *(int *)(&g_CardSlot_CardId +
                                            local_10 * 0x120 + local_c * 0x5b20) * 0x34) * 0x98) ==
                    0x2d)))) {
          Pic_Subsystem_0044867e(local_c,local_10,3);
        }
      }
    }
  }
  DAT_0067bdb0 = uVar3;
  return uVar1;
}

/*
 * Decompiled function: Card_ColorMaskToColorIndex
 * Entry Point: 00473cc5
 * Size: 121 bytes
 */


undefined4 Card_ColorMaskToColorIndex(byte value)

{
  undefined4 uVar1;
  
  if ((value & 2) == 0) {
    if ((value & 4) == 0) {
      if ((value & 8) == 0) {
        if ((value & 0x10) == 0) {
          if ((value & 0x20) == 0) {
            uVar1 = 0;
          }
          else {
            uVar1 = 5;
          }
        }
        else {
          uVar1 = 4;
        }
      }
      else {
        uVar1 = 3;
      }
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/*
 * Decompiled function: Mem_AllocOrFree_00473d7e
 * Entry Point: 00473d7e
 * Size: 26 bytes
 */


undefined * Mem_AllocOrFree_00473d7e(int value)

{
  return (&PTR_s_Colorless_00525760)[value];
}

/*
 * Decompiled function: FUN_00473d98
 * Entry Point: 00473d98
 * Size: 209 bytes
 */


int FUN_00473d98(int value)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_10 = 0;
  for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[value]; local_c = local_c + 1) {
    iVar1 = *(int *)(&g_CardSlot_CardId + value * 0x5b20 + local_c * 0x120);
    if ((((iVar1 != -1) && (((&g_CardSlot_Flags)[value * 0x5b20 + local_c * 0x120] & 2) == 0)) &&
        (((&g_MasterCardColorTable)[iVar1 * 0x34] & 1) != 0)) &&
       ((&DAT_0051aebe)[iVar1 * 0x34] != '\0')) {
      local_10 = local_10 + 1;
    }
  }
  return local_10;
}

/*
 * Decompiled function: Magic_BroadcastCardEvent
 * Entry Point: 00473e69
 * Size: 157 bytes
 */


undefined4 Magic_BroadcastCardEvent(int player,undefined4 slot,int event_code)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  Magic_PushEventContext();
  uVar2 = g_CurrentStepCode;
  g_CardEventResult = 0;
  g_EventSourcePlayer = player;
  g_EventSourceSlot = slot;
  g_EventTargetPlayer = 1 - player;
  g_EventTargetSlot = 0xffffffff;
  if ((event_code != 0x7d) && (event_code != 0x7e)) {
    g_CurrentStepCode = 0xffffffff;
  }
  Magic_ScanCards(event_code);
  uVar1 = g_CardEventResult;
  g_EventSourcePlayer = 0xffffffff;
  g_CurrentStepCode = uVar2;
  Magic_PopEventContext();
  return uVar1;
}

/*
 * Decompiled function: FUN_00481491
 * Entry Point: 00481491
 * Size: 245 bytes
 */


undefined4 FUN_00481491(int value,int min_val,int max_val)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < max_val; local_c = local_c + 1) {
    if (*(int *)(min_val + local_c * 4) != 0) {
      iVar1 = FUN_0046bc92(*(HWND *)(min_val + local_c * 4));
      if (iVar1 == value) {
        FUN_00481491(*(int *)(min_val + local_c * 4),min_val,max_val);
        DestroyWindow(*(HWND *)(min_val + local_c * 4));
        *(undefined4 *)(min_val + local_c * 4) = 0;
      }
    }
  }
  for (local_c = 0; local_c < max_val; local_c = local_c + 1) {
    if (*(int *)(min_val + local_c * 4) == value) {
      DestroyWindow(*(HWND *)(min_val + local_c * 4));
      *(undefined4 *)(min_val + local_c * 4) = 0;
      local_8 = 1;
    }
  }
  return local_8;
}

/*
 * Decompiled function: FUN_00481586
 * Entry Point: 00481586
 * Size: 2708 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00481586(HWND hwnd)

{
  int iVar1;
  HBRUSH max_val;
  int iVar2;
  DWORD dwStyle;
  int nWidth;
  BOOL BVar3;
  tagRECT local_b4;
  tagRECT local_a4;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  undefined1 local_5c [8];
  int local_54;
  LONG local_44;
  int local_40;
  LONG local_3c;
  int local_38;
  int local_34;
  int local_30;
  RECT local_2c;
  int local_1c;
  HWND local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_44 = GetWindowLongA(hwnd,0);
  local_3c = GetWindowLongA(hwnd,4);
  local_18 = GetDlgItem(hwnd,0);
  local_8 = SendMessageA(local_18,0xe1,0,0);
  Ai_Subsystem_004b74b1(&local_1c,&local_38);
  if ((((local_38 < 0x15) || (0x1d < local_38)) || (iVar1 = Ai_Subsystem_004b7629(), iVar1 == 0)) ||
     ((local_1c == 1 && (local_3c == 0)))) {
    ShowWindow(DAT_006a283c,0);
    ShowWindow(DAT_006a284c,5);
    ShowWindow(hwnd,0);
    ShowWindow(DAT_00539540,0);
    UpdateWindow(DAT_006b2e2c);
    SendMessageA(local_18,0x468,0,0);
    SendMessageA(DAT_006b3064,0x40c,0,0);
    SendMessageA(DAT_006a4924,0x401,0,0);
    SendMessageA(DAT_006b2e2c,0x401,0,0);
    DAT_006b2ff4 = 5;
    _DAT_006b2ff0 = 5;
    _DAT_007006c0 = DAT_006b2e30 / 2;
    DAT_007006c4 = _DAT_007006c0;
  }
  else {
    max_val = GetStockObject(1);
    FUN_004f5048(s_LayoutAttackCards_00526da4,0xff00ff,max_val);
    DAT_00539554 = 10;
    DAT_00539584 = 10;
    _DAT_00539560 = (DAT_006a28b0 * 0xf) / 100;
    _DAT_00539538 = 5;
    local_34 = 2;
    if (DAT_00539544 == (HANDLE)0x0) {
      local_40 = GetSystemMetrics(3);
      local_40 = local_40 * 2;
    }
    else {
      GetObjectA(DAT_00539544,0x18,local_5c);
      iVar1 = GetSystemMetrics(3);
      if (iVar1 * 2 < local_54 / 2) {
        local_40 = local_54 / 2;
      }
      else {
        local_40 = GetSystemMetrics(3);
        local_40 = local_40 * 2;
      }
    }
    local_70 = 0;
    local_60 = 0;
    for (local_64 = 0; local_64 < local_3c; local_64 = local_64 + 1) {
      for (local_68 = 0; local_68 < *(int *)(local_44 + 0xcc + local_64 * 0x19c);
          local_68 = local_68 + 1) {
        iVar1 = FUN_0046bc92(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + local_44));
        if ((iVar1 == 0) &&
           (local_6c = FUN_004833e9(hwnd,*(int *)(local_68 * 4 + local_64 * 0x19c + 4 + local_44)),
           local_70 < local_6c)) {
          local_70 = local_6c;
        }
      }
      for (local_68 = 0; local_68 < *(int *)(local_44 + 0x198 + local_64 * 0x19c);
          local_68 = local_68 + 1) {
        iVar1 = FUN_0046bc92(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + local_44));
        if ((iVar1 == 0) &&
           (local_6c = FUN_004833e9(hwnd,*(int *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + local_44)
                                   ), local_60 < local_6c)) {
          local_60 = local_6c;
        }
      }
    }
    if (local_1c == 0) {
      local_30 = local_70;
      local_14 = local_60;
    }
    else {
      local_14 = local_70;
      local_30 = local_60;
    }
    iVar1 = local_34;
    if (local_34 <= local_14) {
      iVar1 = local_14;
    }
    DAT_00539570 = iVar1 * DAT_006ff67c + DAT_00539584;
    iVar1 = local_34;
    if (local_34 <= local_30) {
      iVar1 = local_30;
    }
    DAT_00539574 = iVar1 * DAT_006ff67c + DAT_00539570 + local_40 + _DAT_00539538 * 2 + DAT_006b2e30
    ;
    local_c = DAT_006a28b0 / 3;
    local_10 = DAT_006a28b0 / 3;
    SetWindowPos(local_18,(HWND)0x0,0,DAT_00539570 + _DAT_00539538 + DAT_006b2e30,0,0,5);
    local_80 = DAT_00539554 - local_8;
    iVar1 = local_34;
    if (local_34 <= local_14) {
      iVar1 = local_14;
    }
    local_2c.top = DAT_00539570 - iVar1 * DAT_006ff67c;
    local_2c.bottom = DAT_006b2e30 + DAT_00539574;
    if (local_1c == 0) {
      local_88 = DAT_00539574;
      local_7c = DAT_00539570;
    }
    else {
      local_88 = DAT_00539570;
      local_7c = DAT_00539574;
    }
    local_2c.left = local_80;
    local_2c.right = local_80;
    for (local_84 = 0; local_84 < local_3c; local_84 = local_84 + 1) {
      local_74 = local_80;
      local_78 = local_80;
      local_90 = 0;
      for (local_8c = 0; local_8c < *(int *)(local_44 + 0xcc + local_84 * 0x19c);
          local_8c = local_8c + 1) {
        iVar1 = FUN_0046bc92(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 4 + local_44));
        if (iVar1 == 0) {
          local_78 = local_90 * local_c + local_80;
          MoveWindow(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 4 + local_44),local_78,local_88,
                     DAT_006a28b0,DAT_006b2e30,1);
          local_90 = local_90 + 1;
          if (local_2c.right < local_78 + DAT_006a28b0) {
            local_2c.right = local_78 + DAT_006a28b0;
          }
        }
      }
      local_90 = 0;
      for (local_8c = 0; local_8c < *(int *)(local_44 + 0x198 + local_84 * 0x19c);
          local_8c = local_8c + 1) {
        iVar1 = FUN_0046bc92(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 0xd0 + local_44));
        if (iVar1 == 0) {
          local_74 = local_90 * local_10 + local_80;
          MoveWindow(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 0xd0 + local_44),local_74,local_7c,
                     DAT_006a28b0,DAT_006b2e30,1);
          local_90 = local_90 + 1;
          if (local_2c.right < local_74 + DAT_006a28b0) {
            local_2c.right = local_74 + DAT_006a28b0;
          }
        }
      }
      iVar1 = local_74;
      if (local_74 <= local_78) {
        iVar1 = local_78;
      }
      local_80 = iVar1 + _DAT_00539560 + DAT_006a28b0;
    }
    iVar1 = DAT_006a28b0 / 3;
    local_2c.left = local_2c.left - DAT_00539554;
    local_2c.right = local_2c.right + DAT_00539554;
    local_2c.top = local_2c.top - DAT_00539584;
    local_2c.bottom = local_2c.bottom + DAT_00539584;
    iVar2 = DAT_00539554 * 2 + DAT_006a28b0;
    if (local_2c.right - local_2c.left < iVar2) {
      local_2c.right = local_2c.left + iVar2;
    }
    dwStyle = GetWindowLongA(hwnd,-0x10);
    CopyRect(&local_b4,&local_2c);
    AdjustWindowRect(&local_b4,dwStyle,0);
    GetWindowRect(DAT_006a4924,&local_a4);
    iVar2 = local_a4.top - (local_b4.bottom - local_b4.top);
    if (iVar2 < 6) {
      iVar2 = 5;
    }
    nWidth = (local_a4.right - local_a4.left) - iVar1;
    if (local_b4.right - local_b4.left <= nWidth) {
      nWidth = local_b4.right - local_b4.left;
    }
    MoveWindow(DAT_006b2e24,local_a4.left,iVar2,iVar1,local_b4.bottom - local_b4.top,1);
    MoveWindow(hwnd,iVar1 + local_a4.left,iVar2,nWidth,local_b4.bottom - local_b4.top,1);
    GetClientRect(hwnd,&local_b4);
    SetWindowPos(local_18,(HWND)0x0,0,0,local_b4.right,local_40,6);
    UpdateWindow(DAT_006b2e2c);
    UpdateWindow(DAT_006a4924);
    GetClientRect(hwnd,&local_b4);
    if (local_b4.right < local_2c.right - local_2c.left) {
      iVar1 = (local_2c.right - local_2c.left) - local_b4.right;
      SendMessageA(local_18,0xe2,0,iVar1);
      SendMessageA(local_18,0x468,1,0);
      if (local_8 < 0) {
        local_8 = 0;
      }
      if (iVar1 < local_8) {
        local_8 = iVar1;
      }
      SendMessageA(hwnd,0x114,CONCAT31((int3)((uint)(local_8 << 0x10) >> 8),4),(LPARAM)local_18);
    }
    else {
      SendMessageA(local_18,0x468,0,0);
      local_8 = 0;
      SendMessageA(hwnd,0x114,4,(LPARAM)local_18);
    }
    BVar3 = IsWindowVisible(hwnd);
    if ((BVar3 == 0) && (BVar3 = IsWindowVisible(DAT_00539540), BVar3 == 0)) {
      FUN_00482d6f(hwnd);
      ShowWindow(DAT_006a283c,5);
      ShowWindow(DAT_006a284c,0);
      ShowWindow(hwnd,5);
      UpdateWindow(DAT_006b2e24);
      UpdateWindow(hwnd);
      UpdateWindow(DAT_006a283c);
      FUN_004f59f7();
    }
    UpdateWindow(hwnd);
    UpdateWindow(DAT_006b2e2c);
  }
  return;
}

/*
 * Decompiled function: FUN_0048201a
 * Entry Point: 0048201a
 * Size: 578 bytes
 */


void FUN_0048201a(HWND hwnd,LPRECT y)

{
  LONG LVar1;
  LONG LVar2;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  LVar1 = GetWindowLongA(hwnd,0);
  LVar2 = GetWindowLongA(hwnd,4);
  if ((hwnd != (HWND)0x0) && (y != (LPRECT)0x0)) {
    local_30 = 5000;
    local_2c = -5000;
    local_28 = 5000;
    local_20 = 0;
    for (local_18 = 0; local_18 < LVar2; local_18 = local_18 + 1) {
      for (local_1c = 0; local_1c < *(int *)(LVar1 + 0xcc + local_18 * 0x19c);
          local_1c = local_1c + 1) {
        GetWindowRect(*(HWND *)(local_1c * 4 + local_18 * 0x19c + 4 + LVar1),&local_14);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14,2);
        if (local_14.left < local_30) {
          local_30 = local_14.left;
        }
        if (local_2c < local_14.right) {
          local_2c = local_14.right;
        }
        if (local_14.top < local_28) {
          local_28 = local_14.top;
        }
        if (local_20 < local_14.bottom) {
          local_20 = local_14.bottom;
        }
      }
      for (local_1c = 0; local_1c < *(int *)(LVar1 + 0x198 + local_18 * 0x19c);
          local_1c = local_1c + 1) {
        GetWindowRect(*(HWND *)(local_1c * 4 + local_18 * 0x19c + 0xd0 + LVar1),&local_14);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14,2);
        if (local_14.left < local_30) {
          local_30 = local_14.left;
        }
        if (local_2c < local_14.right) {
          local_2c = local_14.right;
        }
        if (local_14.top < local_28) {
          local_28 = local_14.top;
        }
        if (local_20 < local_14.bottom) {
          local_20 = local_14.bottom;
        }
      }
    }
    if (local_30 == 5000) {
      SetRect(y,0,0,0,0);
    }
    else {
      SetRect(y,local_30,local_28,local_2c,local_20);
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0048225c
 * Entry Point: 0048225c
 * Size: 91 bytes
 */


bool FUN_0048225c(int x,int y)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_004726c5(x,y);
  uVar2 = Ai_Subsystem_004b6288(x,y);
  return (uVar2 & 0x40) != 0 && iVar1 != 0;
}

/*
 * Decompiled function: FUN_00482d6f
 * Entry Point: 00482d6f
 * Size: 103 bytes
 */


void FUN_00482d6f(HWND hwnd)

{
  char local_6c [100];
  int local_8;
  
  Ai_Subsystem_004b74b1(&local_8,(undefined4 *)0x0);
  if (local_8 == 0) {
    strcpy(local_6c,s_Your_attack_00526de8);
  }
  else {
    Ai_Subsystem_004b6f49(local_6c);
    strcat(local_6c,s__s_attack_00526df4);
  }
  SetWindowTextA(hwnd,local_6c);
  return;
}

/*
 * Decompiled function: FUN_00483139
 * Entry Point: 00483139
 * Size: 688 bytes
 */


int FUN_00483139(HWND hwnd,int *min_val,undefined4 *max_val,undefined4 *target_slot,undefined4 *flags)

{
  LONG LVar1;
  LONG LVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((hwnd == (HWND)0x0) || (min_val == (int *)0x0)) {
    local_8 = 0;
  }
  else {
    LVar1 = GetWindowLongA(hwnd,0);
    LVar2 = GetWindowLongA(hwnd,4);
    local_8 = 0;
    for (local_14 = 0; local_14 < LVar2; local_14 = local_14 + 1) {
      local_18 = 0;
      while ((local_18 < *(int *)(LVar1 + 0xcc + local_14 * 0x19c) && (local_8 == 0))) {
        iVar3 = FUN_0046bb29(*(HWND *)(local_18 * 4 + local_14 * 0x19c + 4 + LVar1),min_val);
        if (iVar3 != 0) {
          local_8 = 1;
          local_20 = FUN_0046bc2f(*(HWND *)(local_18 * 4 + local_14 * 0x19c + 4 + LVar1));
          local_10 = *(undefined4 *)(local_18 * 4 + local_14 * 0x19c + 4 + LVar1);
          local_c = 1;
        }
        local_18 = local_18 + 1;
      }
      local_18 = 0;
      while ((local_18 < *(int *)(LVar1 + 0x198 + local_14 * 0x19c) && (local_8 == 0))) {
        iVar3 = FUN_0046bb29(*(HWND *)(local_18 * 4 + local_14 * 0x19c + 0xd0 + LVar1),min_val);
        if (iVar3 != 0) {
          local_8 = 1;
          local_20 = FUN_0046bc2f(*(HWND *)(local_18 * 4 + local_14 * 0x19c + 0xd0 + LVar1));
          local_10 = *(undefined4 *)(local_18 * 4 + local_14 * 0x19c + 0xd0 + LVar1);
          local_c = 0;
        }
        local_18 = local_18 + 1;
      }
    }
  }
  if (max_val != (undefined4 *)0x0) {
    if (local_8 == 0) {
      *max_val = 0xffffffff;
    }
    else {
      *max_val = local_20;
    }
  }
  if (target_slot != (undefined4 *)0x0) {
    if (local_8 == 0) {
      *target_slot = 0;
    }
    else {
      *target_slot = local_10;
    }
  }
  if (flags != (undefined4 *)0x0) {
    if (local_8 == 0) {
      *flags = 0;
    }
    else {
      *flags = local_c;
    }
  }
  return local_8;
}

/*
 * Decompiled function: FUN_004833e9
 * Entry Point: 004833e9
 * Size: 417 bytes
 */


int FUN_004833e9(HWND hwnd,int y)

{
  LONG LVar1;
  LONG LVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  LVar1 = GetWindowLongA(hwnd,0);
  LVar2 = GetWindowLongA(hwnd,4);
  local_10 = 0;
  for (local_8 = 0; local_8 < LVar2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < *(int *)(LVar1 + 0xcc + local_8 * 0x19c); local_c = local_c + 1) {
      iVar3 = FUN_0046bc92(*(HWND *)(local_c * 4 + local_8 * 0x19c + 4 + LVar1));
      if (iVar3 == y) {
        iVar3 = FUN_004833e9(hwnd,*(int *)(local_8 * 0x19c + local_c * 4 + 4 + LVar1));
        local_10 = local_10 + 1 + iVar3;
      }
    }
    for (local_c = 0; local_c < *(int *)(LVar1 + 0x198 + local_8 * 0x19c); local_c = local_c + 1) {
      iVar3 = FUN_0046bc92(*(HWND *)(local_c * 4 + local_8 * 0x19c + 0xd0 + LVar1));
      if (iVar3 == y) {
        iVar3 = FUN_004833e9(hwnd,*(int *)(local_8 * 0x19c + local_c * 4 + 0xd0 + LVar1));
        local_10 = local_10 + 1 + iVar3;
      }
    }
  }
  return local_10;
}

/*
 * Decompiled function: FUN_00483590
 * Entry Point: 00483590
 * Size: 204 bytes
 */


void FUN_00483590(char *str_1,int min_val,int max_val)

{
  int y;
  int width;
  int iVar1;
  int target_slot;
  
  y = min_val * 2;
  width = max_val * 2;
  iVar1 = FUN_0040c465(str_1);
  target_slot = iVar1 + 0x10;
  Surface_FillRect((int *)g_DisplaySurfaceScreen,(y - target_slot / 2) + -1,width + -5,iVar1 + 0x11,0x13,
                   0xff);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,y - target_slot / 2,width + -4,iVar1 + 0x11,0x12,0xf4);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,y - target_slot / 2,width + -4,target_slot,0x11,0xf6);
  FUN_0040c3cc(str_1,y,width,0xe3);
  return;
}

/*
 * Decompiled function: FUN_0048365c
 * Entry Point: 0048365c
 * Size: 64 bytes
 */


undefined4 FUN_0048365c(void)

{
  undefined4 uVar1;
  
  if (g_IsAiThinking == 1) {
    uVar1 = 1;
  }
  else if (DAT_0063ee18 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/*
 * Decompiled function: Pic_Load_combat2_0048369c
 * Entry Point: 0048369c
 * Size: 3951 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pic_Load_combat2_0048369c(int x,int y)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int local_3c;
  int local_38;
  int local_34;
  int local_24;
  uint local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  if (g_IsAiThinking != 1) {
    Pic_Subsystem_0044b8da();
    *(undefined4 *)g_DisplaySurfaceScreen = 1;
    _DAT_00539598 = 0;
    iVar1 = 1 - x;
    DAT_0063ee78 = 0;
    for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
      if (local_18 == g_CurrentTurnPhase) {
        local_3c = 0x174;
      }
      else {
        local_3c = 0xac;
      }
      for (local_34 = 0; local_34 < 7; local_34 = local_34 + 1) {
        for (local_1c = 0; (int)local_1c < *(int *)(&DAT_0063ee90 + local_34 * 4 + local_18 * 0x20);
            local_1c = local_1c + 1) {
          Surface_FillRect((int *)g_DisplaySurfaceScreen,0x68,local_3c + 3,0x14,0xe,
                           (-(uint)(local_18 == 0) & 0x23) + 0xdc);
          Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,0x66,local_3c,
                            *(int *)(&DAT_0067f390 + local_34 * 4));
          local_3c = local_3c + -0x10;
        }
      }
    }
    local_3c = 0x86;
    local_38 = 0x82;
    local_8 = 0x41;
    local_10 = 0x82;
    for (local_c = 0; local_c <= *(int *)(&DAT_006ff4b8 + x * 4); local_c = local_c + 1) {
      local_1c = (&g_PlayerActiveCardCount)[x];
      do {
        local_1c = local_1c - 1;
        iVar3 = local_8;
        if ((int)local_1c < 0) goto LAB_004837f3;
      } while ((*(int *)(&g_CardSlot_CardId + local_1c * 0x120 + x * 0x5b20) == -1) ||
              (*(int *)(&g_CardSlot_DisplayIndex + local_1c * 0x120 + x * 0x5b20) != local_c));
      if (((&g_CardSlot_Flags)[local_1c * 0x120 + x * 0x5b20] & 2) == 0) {
        Mem_AllocOrFree_00484ebb(x,local_1c,(local_1c & 0xf) + 0xff,local_3c);
        local_3c = local_3c + -0x12;
      }
      else if ((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_1c * 0x120 + x * 0x5b20) * 0x34] == '\x01') {
        local_34 = 1;
        for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
          for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[local_18];
              local_24 = local_24 + 1) {
            if (((*(uint *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + local_18 * 0x5b20) ==
                  local_1c) &&
                ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + local_18 * 0x5b20] == x)) &&
               (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + local_18 * 0x5b20) != -1)) {
              Mem_AllocOrFree_00484ebb
                        (local_18,local_24,(int)(8 / (longlong)local_34) + 1,local_38 + 4);
              local_34 = local_34 + 1;
            }
          }
        }
        Mem_AllocOrFree_00484ebb(x,local_1c,(local_1c & 7) + 1,local_38);
        local_38 = local_38 + -8;
      }
      else if (*(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + x * 0x5b20) == -1) {
        local_34 = 1;
        for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
          for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[local_18];
              local_24 = local_24 + 1) {
            if (((*(uint *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + local_18 * 0x5b20) ==
                  local_1c) &&
                ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + local_18 * 0x5b20] == x)) &&
               (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + local_18 * 0x5b20) != -1)) {
              Mem_AllocOrFree_00484ebb
                        (local_18,local_24,local_8 + (int)(4 / (longlong)local_34),
                         local_10 + (int)(8 / (longlong)local_34));
              local_34 = local_34 + 1;
            }
          }
        }
        Mem_AllocOrFree_00484ebb(x,local_1c,local_8,local_10);
        local_10 = local_10 + -6;
        iVar3 = local_8 + 0x33;
        if (0xe0 < local_8 + 0x33) {
          iVar3 = local_8 + -0x62;
        }
      }
LAB_004837f3:
      local_8 = iVar3;
    }
    local_38 = 0x2a;
    local_8 = 0x41;
    local_10 = 0x2a;
    for (local_c = 0; local_c <= *(int *)(&DAT_006ff4b8 + iVar1 * 4); local_c = local_c + 1) {
      local_1c = (&g_PlayerActiveCardCount)[iVar1];
      iVar3 = local_8;
      while (local_8 = iVar3, local_1c = local_1c - 1, -1 < (int)local_1c) {
        iVar3 = local_8;
        if (((*(int *)(&g_CardSlot_CardId + local_1c * 0x120 + iVar1 * 0x5b20) != -1) &&
            (*(int *)(&g_CardSlot_DisplayIndex + local_1c * 0x120 + iVar1 * 0x5b20) == local_c)) &&
           (((&g_CardSlot_Flags)[local_1c * 0x120 + iVar1 * 0x5b20] & 2) != 0)) {
          if ((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + local_1c * 0x120 + iVar1 * 0x5b20) * 0x34] == '\x01') {
            local_34 = 1;
            for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
              for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[local_18];
                  local_24 = local_24 + 1) {
                if (((*(uint *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + local_18 * 0x5b20)
                      == local_1c) &&
                    ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + local_18 * 0x5b20] == iVar1))
                   && (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + local_18 * 0x5b20) != -1)) {
                  Mem_AllocOrFree_00484ebb
                            (local_18,local_24,(int)(8 / (longlong)local_34) + 1,local_38 + 4);
                  local_34 = local_34 + 1;
                }
              }
            }
            Mem_AllocOrFree_00484ebb(iVar1,local_1c,(local_1c & 7) + 1,local_38);
            local_38 = local_38 + -8;
          }
          else if (*(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + iVar1 * 0x5b20) == -1) {
            local_34 = 1;
            for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
              for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[local_18];
                  local_24 = local_24 + 1) {
                if (((*(uint *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + local_18 * 0x5b20)
                      == local_1c) &&
                    ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + local_18 * 0x5b20] == iVar1))
                   && (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + local_18 * 0x5b20) != -1)) {
                  Mem_AllocOrFree_00484ebb
                            (local_18,local_24,local_8 + (int)(4 / (longlong)local_34),
                             local_10 + (int)(8 / (longlong)local_34));
                  local_34 = local_34 + 1;
                }
              }
            }
            Mem_AllocOrFree_00484ebb(iVar1,local_1c,local_8,local_10);
            local_10 = local_10 + -6;
            iVar3 = local_8 + 0x33;
            if (0xe0 < local_8 + 0x33) {
              iVar3 = local_8 + -0x62;
            }
          }
        }
      }
    }
    switch(g_ScWillyScore) {
    case 0:
    case 1:
      strcpy(&g_OverworldWorldState,s_UNTAP_00526ed8);
      break;
    case 2:
    case 4:
      strcpy(&g_OverworldWorldState,s_UPKEEP_00526ee0);
      break;
    default:
      strcpy(&g_OverworldWorldState,&DAT_00526f10);
      break;
    case 10:
      strcpy(&g_OverworldWorldState,&DAT_00526ee8);
      break;
    case 0x14:
      strcpy(&g_OverworldWorldState,&DAT_00526ef0);
      break;
    case 0x15:
    case 0x17:
    case 0x19:
    case 0x1a:
    case 0x1b:
      strcpy(&g_OverworldWorldState,s_ATTACK_00526ef8);
      break;
    case 0x1e:
      strcpy(&g_OverworldWorldState,s_MAIN2_00526f00);
      break;
    case 0x1f:
    case 0x20:
    case 0x22:
      strcpy(&g_OverworldWorldState,s_HEALING_00526f08);
    }
    FUN_0040c3cc(&g_OverworldWorldState,0x248,4,(-(uint)(g_TurnPlayer == 0) & 0x23) + 0xdc);
    if (DAT_0068a64c == -1) {
      FUN_0040c274(&DAT_00701830,4,4,0);
    }
    else {
      FUN_0040c274(s_Swamp_0051aea9 + DAT_0068a64c * 0x34,4,4,0xff);
    }
    g_OverworldWorldState = 0;
    pcVar2 = _itoa(DAT_006b300c + DAT_00627a14,&DAT_005395a0,10);
    strcat(&g_OverworldWorldState,pcVar2);
    strcat(&g_OverworldWorldState,s_cards_00526f18);
    FUN_0040c274(&g_OverworldWorldState,4,0x12,0xff);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0xfe,400,0x84,0x20,0xff);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0x100,0x192,0x80,0x1e,3);
    FUN_0040c421(s_Our_Hero_00526f20,(int)g_DisplayScreenWidth / 2,0x194,0xff);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0xfe,0,0x84,0x22,0);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0x100,0,0x80,0x20,0xd8);
    FUN_0040c421(&DAT_00695e10,(int)g_DisplayScreenWidth / 2,0x12,0xdc);
    iVar3 = Math_Clamp((&g_PlayerCreatureCount)[x],0x19,100);
    iVar3 = (int)(400 / (longlong)iVar3);
    for (local_1c = 0; (int)local_1c < (int)(&g_PlayerCreatureCount)[x]; local_1c = local_1c + 1)
    {
      Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,
                        (local_1c * iVar3 + (int)g_DisplayScreenWidth / 2) -
                        ((&g_PlayerCreatureCount)[x] * iVar3) / 2,0x1a0,DAT_0067f3a8);
    }
    strcpy(&g_OverworldWorldState,&DAT_00526f2c);
    iVar4 = 10;
    pcVar2 = &DAT_005395a0;
    iVar3 = Math_Clamp((&g_PlayerCreatureCount)[x],0,99);
    pcVar2 = _itoa(iVar3,pcVar2,iVar4);
    strcat(&g_OverworldWorldState,pcVar2);
    if ((&DAT_00696870)[x] != 0) {
      strcat(&g_OverworldWorldState,&DAT_00526f30);
      pcVar2 = _itoa((&DAT_00696870)[x],&DAT_005395a0,10);
      strcat(&g_OverworldWorldState,pcVar2);
      strcat(&g_OverworldWorldState,&DAT_00526f34);
    }
    strcat(&g_OverworldWorldState,&DAT_00526f38);
    FUN_0040c3cc(&g_OverworldWorldState,(int)g_DisplayScreenWidth / 2,0x1a0,0);
    iVar3 = Math_Clamp((&g_PlayerCreatureCount)[iVar1],0x19,100);
    iVar3 = (int)(400 / (longlong)iVar3);
    for (local_1c = 0; (int)local_1c < (int)(&g_PlayerCreatureCount)[iVar1]; local_1c = local_1c + 1
        ) {
      Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,
                        (local_1c * iVar3 + (int)g_DisplayScreenWidth / 2) -
                        ((&g_PlayerCreatureCount)[iVar1] * iVar3) / 2,4,DAT_0067f3ac);
    }
    strcpy(&g_OverworldWorldState,&DAT_00526f3c);
    iVar4 = 10;
    pcVar2 = &DAT_005395a0;
    iVar3 = Math_Clamp((&g_PlayerCreatureCount)[iVar1],0,99);
    pcVar2 = _itoa(iVar3,pcVar2,iVar4);
    strcat(&g_OverworldWorldState,pcVar2);
    if ((&DAT_00696870)[iVar1] != 0) {
      strcat(&g_OverworldWorldState,&DAT_00526f40);
      pcVar2 = _itoa((&DAT_00696870)[iVar1],&DAT_005395a0,10);
      strcat(&g_OverworldWorldState,pcVar2);
      strcat(&g_OverworldWorldState,&DAT_00526f44);
    }
    strcat(&g_OverworldWorldState,&DAT_00526f48);
    FUN_0040c3cc(&g_OverworldWorldState,(int)g_DisplayScreenWidth / 2,4,0xff);
    Pic_Subsystem_00452708(&DAT_005395b0);
    if (g_TurnPlayer == g_CurrentTurnPhase) {
      if (g_ScWillyScore < 0x15) {
        strcpy(&g_OverworldWorldState,s_ATTACK_00526f4c + ((DAT_0063ee78 != 0) - 1 & 8));
      }
      else {
        strcpy(&g_OverworldWorldState,s_CHARGE__00526f5c + ((0 < DAT_006a5f20) - 1 & 8));
        if (0x1d < g_ScWillyScore) {
          strcpy(&g_OverworldWorldState,&DAT_00526f6c);
        }
      }
      if (((byte)g_DuelModeFlags & 0x80) != 0) {
        FUN_00483590(&g_OverworldWorldState,0x127,200);
      }
      if (g_ActivePlayer == -1) {
        FUN_00483590(s_Cancel_00526f74,0x10,200);
      }
      if (g_ActivePlayer != -1) {
        FUN_00483590(s_Concede_00526f7c,0x18,200);
      }
    }
    if (y == 0) {
      *(undefined4 *)g_DisplaySurfaceScreen = 0;
      Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
                   (int *)g_DisplaySurfaceScreen,0,0);
    }
    else {
      FUN_0050d520(1);
      *(undefined4 *)g_DisplaySurfaceScreen = 0;
      Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
                   (int *)g_DisplaySurfaceScreen,0,0);
      FUN_0050d4e0(0);
    }
    Mem_AllocOrFree_00510e20(1,s_combat2_pic_00526f84);
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x140,200,
                       (int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight);
    Pic_Subsystem_0044b8aa();
  }
  return;
}

/*
 * Decompiled function: FUN_00484668
 * Entry Point: 00484668
 * Size: 41 bytes
 */


void FUN_00484668(char *str_1)

{
  strcpy(&DAT_005395b0,str_1);
  Pic_Subsystem_00452708(&DAT_005395b0);
  return;
}

/*
 * Decompiled function: FUN_00484691
 * Entry Point: 00484691
 * Size: 167 bytes
 */


void FUN_00484691(byte x,int y)

{
  int local_c;
  
  for (local_c = 0; local_c < 500; local_c = local_c + 1) {
    if ((*(int *)(&deck + local_c * 4) != -1) &&
       ((1 << (x & 0x1f) &
        (int)(char)(&DAT_0051aebe)[(*(uint *)(&deck + local_c * 4) & 0xfff) * 0x34]) != 0)) {
      if (y == 0) {
        *(uint *)(&deck + local_c * 4) = *(uint *)(&deck + local_c * 4) | 0x4000;
      }
      else {
        *(uint *)(&deck + local_c * 4) = *(uint *)(&deck + local_c * 4) & 0xffffbfff;
      }
    }
  }
  return;
}

/*
 * Decompiled function: Sprite_Load_dungbutt_00484738
 * Entry Point: 00484738
 * Size: 386 bytes
 */


void Sprite_Load_dungbutt_00484738(int value,undefined4 min_val,char *str_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *arg_6;
  undefined4 target_slot;
  char local_1fc [100];
  undefined4 local_198;
  void *local_194 [100];
  
  if (g_IsAiThinking != 1) {
    Pic_Subsystem_0044b8da();
    strcpy(local_1fc,str_3);
    Sprite_LoadAll(local_194,s_dungbutt_spr_00526f90);
    arg_6 = local_194[0];
    iVar1 = Ai_Util_004c3ba3(0x10f);
    iVar1 = iVar1 / 2;
    iVar2 = Ai_Util_004c3ba3(0xc5);
    iVar2 = iVar2 / 2;
    iVar3 = Ai_Util_004c3ba3(0x34);
    iVar3 = iVar3 / 2;
    iVar4 = Ai_Util_004c3ba3(0xdc);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar4 / 2,iVar3,iVar2,iVar1,(int)arg_6);
    FUN_0050b3de(value,0x7a,0x29,0x4b,0x70,1,&DAT_00526fa0);
    Mem_AllocOrFree_0050fc50(local_194[0]);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    local_198 = FUN_0040c465(local_1fc);
    target_slot = 0;
    iVar1 = Ai_Util_004c3bc4(0x52);
    iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    FUN_0040c3cc(local_1fc,g_DisplayScreenWidth / 2,(iVar1 - iVar2) + -2,target_slot);
    iVar1 = Ai_Util_004c3bc4(0x52);
    iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    FUN_0040c3cc(local_1fc,g_DisplayScreenWidth / 2,(iVar1 - iVar2) + -3,min_val);
    Pic_Subsystem_0044b8aa();
  }
  return;
}

/*
 * Decompiled function: FUN_00484c45
 * Entry Point: 00484c45
 * Size: 263 bytes
 */


void FUN_00484c45(undefined4 value)

{
  switch(value) {
  case 1:
    strcat(&g_OverworldWorldState,&DAT_00527020);
    break;
  case 2:
    strcat(&g_OverworldWorldState,s_Creature_00527028);
    break;
  case 4:
    strcat(&g_OverworldWorldState,s_Enchantment_00527034);
    break;
  case 8:
    strcat(&g_OverworldWorldState,s_Sorcery_00527040);
    break;
  case 0x10:
    strcat(&g_OverworldWorldState,s_Instant_00527048);
    break;
  case 0x20:
    strcat(&g_OverworldWorldState,s_Interrupt_00527050);
    break;
  case 0x40:
    strcat(&g_OverworldWorldState,s_Artifact_0052705c);
    break;
  case 0x42:
    strcat(&g_OverworldWorldState,s_A_creature_00527068);
    break;
  case 0x80:
    strcat(&g_OverworldWorldState,s_Game_effect_00527074);
  }
  return;
}

/*
 * Decompiled function: FUN_00484df9
 * Entry Point: 00484df9
 * Size: 52 bytes
 */


void FUN_00484df9(undefined4 x,undefined4 y)

{
  if (g_IsAiThinking != 1) {
    Mem_AllocOrFree_00484ebb(x,y,0xba,0x33);
  }
  return;
}

/*
 * Decompiled function: FUN_00484e2d
 * Entry Point: 00484e2d
 * Size: 142 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00484e2d(int value,undefined4 min_val,undefined4 max_val,int target_slot,undefined4 flags)

{
  _DAT_006ab814 = value;
  if (target_slot == 0) {
    _DAT_006ab81c = 0;
  }
  else {
    _DAT_006ab81c = 0x10;
  }
  _DAT_006ab838 = flags;
  DAT_006ab82e = 0xff;
  DAT_006ab82c = (&DAT_0051aebe)[value * 0x34];
  _DAT_006ab84c = 0x8000000;
  _DAT_006ab834 = 0;
  Mem_AllocOrFree_00484ebb(0,0x4f,min_val,max_val);
  _DAT_006ab814 = 0xffffffff;
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_00484ebb
 * Entry Point: 00484ebb
 * Size: 18 bytes
 */


undefined4 Mem_AllocOrFree_00484ebb(void)

{
  return 0;
}

/*
 * Decompiled function: FUN_00484ecd
 * Entry Point: 00484ecd
 * Size: 292 bytes
 */


int FUN_00484ecd(int x,int y,int width,undefined4 target_slot)

{
  int iVar1;
  int local_8;
  
  if (DAT_0063ee18 == 0) {
    iVar1 = *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20);
    switch(width) {
    case 0x32:
      local_8 = (int)*(short *)(&DAT_0051aec2 + iVar1 * 0x34);
      break;
    case 0x33:
      local_8 = (int)*(short *)(&DAT_0051aec4 + iVar1 * 0x34);
      break;
    case 0x34:
      local_8 = *(int *)(&DAT_0051aecc + iVar1 * 0x34);
      break;
    case 0x35:
      local_8 = (int)*(short *)(&g_CardSlot_Power + y * 0x120 + x * 0x5b20);
      break;
    case 0x36:
      local_8 = (int)(char)(&DAT_0051aebe)[iVar1 * 0x34];
      break;
    default:
      local_8 = 0;
    }
  }
  else {
    local_8 = Magic_QueryCardAttribute(x,y,width,target_slot);
  }
  return local_8;
}

/*
 * Decompiled function: FUN_00485005
 * Entry Point: 00485005
 * Size: 57 bytes
 */


bool FUN_00485005(int value)

{
  return ((&DAT_0051aed6)[value * 0x34] & 0xc1) != 0;
}

/*
 * Decompiled function: FUN_00485040
 * Entry Point: 00485040
 * Size: 64 bytes
 */


undefined4 FUN_00485040(undefined4 x,undefined4 y)

{
  return y;
}

/*
 * Decompiled function: Mem_AllocOrFree_00485229
 * Entry Point: 00485229
 * Size: 11 bytes
 */


void Mem_AllocOrFree_00485229(void)

{
  return;
}

/*
 * Decompiled function: FUN_00485234
 * Entry Point: 00485234
 * Size: 398 bytes
 */


void FUN_00485234(int value)

{
  int iVar1;
  int iVar2;
  char *str_2;
  int local_10;
  int local_c;
  
  g_OverworldWorldState = 0;
  for (local_c = 0; local_c < 0x50; local_c = local_c + 1) {
    iVar1 = *(int *)(&g_CardSlot_CardId + value * 0x5b20 + local_c * 0x120);
    if ((iVar1 != -1) && (((&g_CardSlot_Flags)[value * 0x5b20 + local_c * 0x120] & 2) == 0)) {
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar1 * 0x34);
      strcat(&g_OverworldWorldState,&DAT_005270b0);
      for (local_10 = 0; local_10 < (char)(&DAT_0051aebf)[iVar1 * 0x34]; local_10 = local_10 + 1) {
        iVar2 = Card_ColorMaskToColorIndex((&DAT_0051aebe)[iVar1 * 0x34]);
        strcat(&g_OverworldWorldState,(&PTR_DAT_00527080)[iVar2]);
      }
      if ((&DAT_0051aec0)[iVar1 * 0x34] != '\0') {
        str_2 = _itoa((int)(char)(&DAT_0051aec0)[iVar1 * 0x34],&DAT_005395f0,10);
        strcat(&g_OverworldWorldState,str_2);
      }
      strcat(&g_OverworldWorldState,&DAT_005270b4);
    }
  }
  FUN_00489710(&g_OverworldWorldState,10,10);
  return;
}

/*
 * Decompiled function: FUN_004853c2
 * Entry Point: 004853c2
 * Size: 226 bytes
 */


void FUN_004853c2(void)

{
  int local_8;
  
  FUN_0050d560(0,3);
  FUN_0040c421(s_My_Ante_005270b8,0xa0,100,0xff);
  FUN_0040c421(s_Opponent_s_Ante_005270c0,0xa0,1,0xff);
  for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
    if ((&DAT_006b2dd0)[local_8] != -1) {
      FUN_00484e2d((&DAT_006b2dd0)[local_8],(local_8 + 1) * 0x6a,8,0,0xffffffff);
    }
    if ((&DAT_006b2d90)[local_8] != -1) {
      FUN_00484e2d((&DAT_006b2d90)[local_8],(local_8 + 1) * 0x6a,0x6c,0,0xffffffff);
    }
  }
  return;
}

/*
 * Decompiled function: FUN_004854a4
 * Entry Point: 004854a4
 * Size: 353 bytes
 */


int FUN_004854a4(int value,char *str_2,int max_val)

{
  int iVar1;
  
  if (g_IsAiThinking != 1) {
    if (g_CurrentTurnPhase == value) {
      iVar1 = FUN_0040c465(str_2);
      iVar1 = iVar1 + 0x10;
      if (0x10 < iVar1) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,g_DisplayScreenWidth / 2 - iVar1 / 2,0x5a,iVar1,0x14,
                         0xff);
        FUN_0040c3cc(str_2,g_DisplayScreenWidth / 2,0x5c,0);
        FUN_0040c3cc(&DAT_005270e0,g_DisplayScreenWidth / 2,100,0);
      }
      do {
        iVar1 = FUN_0048ac2f();
        if (iVar1 == 0x79) {
          return 1;
        }
      } while (iVar1 != 0x6e);
      max_val = 0;
    }
    else {
      strcpy(&g_OverworldWorldState,s__YES__005270d0 + ((max_val != 0) - 1 & 8));
      FUN_0040c3cc(&g_OverworldWorldState,g_DisplayScreenWidth / 2,7,0xd8);
      FUN_0040c3cc(&g_OverworldWorldState,g_DisplayScreenWidth / 2,6,0xdc);
      FUN_00501736(0x78);
    }
  }
  return max_val;
}

/*
 * Decompiled function: FUN_00485605
 * Entry Point: 00485605
 * Size: 168 bytes
 */


int FUN_00485605(int value,char *str_2,int max_val)

{
  int iVar1;
  
  if ((g_CurrentTurnPhase == value) && (g_IsAiThinking != 1)) {
    iVar1 = FUN_0040c465(str_2);
    iVar1 = iVar1 + 0x10;
    if (0x10 < iVar1) {
      Surface_FillRect((int *)g_DisplaySurfaceScreen,g_DisplayScreenWidth / 2 - iVar1 / 2,0x5a,iVar1,0x14,
                       0xff);
      FUN_0040c3cc(str_2,g_DisplayScreenWidth / 2,0x5c,0);
    }
    iVar1 = FUN_0048ac2f();
    max_val = iVar1 + -0x30;
  }
  return max_val;
}

/*
 * Decompiled function: FUN_00488f92
 * Entry Point: 00488f92
 * Size: 73 bytes
 */


undefined4 FUN_00488f92(int value)

{
  strcat(&g_OverworldWorldState,&DAT_00527a94 + ((*(int *)(&DAT_005270e4 + value * 4) != 0) - 1 & 8)
        );
  return *(undefined4 *)(&DAT_005270e4 + value * 4);
}

/*
 * Decompiled function: FUN_00488fdb
 * Entry Point: 00488fdb
 * Size: 429 bytes
 */


void FUN_00488fdb(undefined4 *value,int min_val,int max_val,int target_slot,int flags,char *str_6,char *str_7)

{
  byte *pbVar1;
  undefined1 uVar2;
  int iVar3;
  byte local_42c [1040];
  int local_1c;
  int local_18;
  uint local_14;
  uint local_c;
  uint local_8;
  
  iVar3 = strcmp(PTR_DAT_00527aa4,str_6);
  if (iVar3 == 0) {
    iVar3 = strcmp(PTR_DAT_00527aa8,str_7);
    if (iVar3 == 0) goto LAB_004890e3;
  }
  FUN_00510b70(-1,0,0,str_6,(short *)&DAT_00539928);
  FUN_00510b70(-1,0,0,str_7,(short *)&DAT_00539600);
  DAT_00539c48 = &DAT_0053992e;
  PTR_DAT_00527aa4 = str_6;
  PTR_DAT_00527aa8 = str_7;
  for (local_18 = 0; pbVar1 = DAT_00539c48, local_18 < 0x100; local_18 = local_18 + 1) {
    local_c = (uint)*DAT_00539c48;
    DAT_00539c48 = DAT_00539c48 + 1;
    local_14 = (uint)*DAT_00539c48;
    DAT_00539c48 = pbVar1 + 2;
    local_8 = (uint)*DAT_00539c48;
    DAT_00539c48 = pbVar1 + 3;
    uVar2 = Ai_Subsystem_004c22a2(local_c,local_14,local_8,&DAT_00539606);
    (&DAT_00539c50)[local_18] = uVar2;
  }
LAB_004890e3:
  for (local_1c = max_val; local_1c < flags + max_val; local_1c = local_1c + 1) {
    Surface_GetLine((undefined4 *)local_42c,*value,min_val,local_1c,target_slot);
    for (local_18 = 0; local_18 < target_slot; local_18 = local_18 + 1) {
      local_42c[local_18] = (&DAT_00539c50)[local_42c[local_18]];
    }
    Surface_PutLine((undefined4 *)local_42c,*value,min_val,local_1c,target_slot);
  }
  return;
}

/*
 * Decompiled function: Pic_Load_advfac64_00489188
 * Entry Point: 00489188
 * Size: 1192 bytes
 */


void Pic_Load_advfac64_00489188(int value,int min_val,int max_val,int target_slot,int flags)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *arg_1_00;
  DWORD DVar5;
  uint uVar6;
  int iVar7;
  uint arg_2_00;
  int iVar8;
  int *piVar9;
  int arg_6;
  char *str_6;
  int arg_7;
  void *pvVar10;
  char *str_7;
  HDC pHVar11;
  char local_20 [24];
  void *local_8;
  
  Mem_AllocOrFree_00510e20(1,s_prdfrmc_pic_00527ab4 + ((target_slot != 0) - 1 & 0xc));
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  if (target_slot != 0) {
    FUN_00488fdb((undefined4 *)g_DisplaySurfaceBackBuffer,1,0x15a,0xb3,0x23,s_prdblk_pic_00527adc,
                 s_advfac64_pic_00527acc);
  }
  Mem_AllocOrFree_0050fc00();
  local_8 = (void *)Sprite_EncodeFromSurface(1,1,0x15a,0xb3,0x23);
  FUN_0050fc20();
  iVar2 = g_DisplayScreenWidth;
  iVar1 = Ai_Util_004c3bc4(0xb4);
  iVar8 = g_DisplayScreenHeight;
  arg_2_00 = iVar2 - iVar1;
  iVar2 = Ai_Util_004c3bc4(0xb4);
  iVar8 = iVar8 - iVar2;
  if (flags == 1) {
    *(undefined4 *)g_DisplaySurfaceScreen = 1;
  }
  pvVar10 = local_8;
  iVar1 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 6));
  iVar3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 4));
  iVar2 = max_val;
  iVar4 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 4) / 2);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,min_val - iVar4,iVar2,iVar3,iVar1,(int)pvVar10);
  g_OverworldWorldState = 0;
  Glue_Subsystem_004eaa19(value,0,0);
  iVar2 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 6) / 2);
  FUN_0040d009((int)g_DisplaySurfaceScreen,(-(uint)(target_slot == 0) & 0x38) + 0xae,min_val,max_val + iVar2);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
  if (flags == 1) {
    *(undefined4 *)g_DisplaySurfaceScreen = 0;
  }
  iVar2 = Ai_Util_004c3bc4(0xb4);
  iVar1 = Ai_Util_004c3bc4(0xb4);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,1,0xa5,0xb4,0xb4,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2_00,iVar8,iVar1,iVar2);
  sprintf(local_20,s_faces__03d_pic_00527ae8,value);
  FUN_00510b70(1,0,g_DisplayScreenHeight + -0xf0,local_20,(short *)0x0);
  Mem_AllocOrFree_0050fc00();
  arg_1_00 = (void *)Sprite_EncodeFromSurface(1,0,g_DisplayScreenHeight + -0xf0,0x8a,0xaa);
  FUN_0050fc20();
  pvVar10 = arg_1_00;
  iVar2 = Ai_Util_004c3bc4(0xaa);
  iVar1 = Ai_Util_004c3bc4(0x8a);
  iVar3 = Ai_Util_004c3bc4(5);
  iVar3 = iVar8 + iVar3;
  iVar4 = Ai_Util_004c3bc4(0x15);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_2_00 + iVar4,iVar3,iVar1,iVar2,
                    (int)pvVar10);
  if (target_slot != 0) {
    str_7 = s_advfac64_pic_00527af8;
    str_6 = s_prdblk_pic_00527b08;
    iVar2 = Ai_Util_004c3bc4(0xb4);
    iVar1 = Ai_Util_004c3bc4(0xb4);
    FUN_00488fdb((undefined4 *)g_DisplaySurfaceBackBuffer,arg_2_00,iVar8,iVar1,iVar2,str_6,str_7);
  }
  if (flags == 0) {
    iVar2 = Ai_Util_004c3bc4(0x2d);
    iVar2 = max_val + iVar2;
    iVar1 = Ai_Util_004c3bc4(0x5a);
    iVar1 = min_val - iVar1;
    piVar9 = (int *)g_DisplaySurfaceScreen;
    DVar5 = Ai_Util_004c3bc4(0xb4);
    uVar6 = Ai_Util_004c3bc4(0xb4);
    Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,arg_2_00,iVar8,uVar6,DVar5,piVar9,iVar1,iVar2);
  }
  else {
    iVar2 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceBackBuffer];
    iVar1 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen];
    iVar3 = Ai_Util_004c3bc4(0x2d);
    iVar3 = max_val + iVar3;
    iVar4 = Ai_Util_004c3bc4(0x5a);
    iVar4 = min_val - iVar4;
    piVar9 = (int *)g_DisplaySurfaceBackBuffer;
    DVar5 = Ai_Util_004c3bc4(0xb4);
    uVar6 = Ai_Util_004c3bc4(0xb4);
    Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,arg_2_00,iVar8,uVar6,DVar5,piVar9,iVar4,iVar3);
    pHVar11 = *(HDC *)(iVar2 + 4);
    arg_7 = 3;
    arg_6 = 3;
    iVar8 = Ai_Util_004c3bc4(0xb4);
    iVar3 = Ai_Util_004c3bc4(0xb4);
    iVar4 = Ai_Util_004c3bc4(0x2d);
    iVar4 = max_val + iVar4;
    iVar7 = Ai_Util_004c3bc4(0x5a);
    FUN_005119e0(*(HDC *)(iVar1 + 4),min_val - iVar7,iVar4,iVar3,iVar8,arg_6,arg_7,pHVar11);
    if (flags == 1) {
      pHVar11 = *(HDC *)(iVar2 + 4);
      iVar7 = 2;
      iVar4 = 2;
      iVar2 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 6));
      iVar8 = Ai_Util_004c3bc4(*(short *)((int)local_8 + 4) + -0x16);
      iVar3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 4) / 2 + -0xb);
      FUN_005119e0(*(HDC *)(iVar1 + 4),min_val - iVar3,max_val,iVar8,iVar2,iVar4,iVar7,pHVar11);
    }
  }
  Mem_AllocOrFree_0050fc50(arg_1_00);
  Mem_AllocOrFree_0050fc50(local_8);
  return;
}

/*
 * Decompiled function: FUN_00489630
 * Entry Point: 00489630
 * Size: 88 bytes
 */


void FUN_00489630(uint value)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return;
    }
    if ((*(uint *)(&deck + local_8 * 4) & 0xfff) == value) break;
    local_8 = local_8 + 1;
  }
  Pic_Subsystem_00452065(local_8);
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_00489690
 * Entry Point: 00489690
 * Size: 46 bytes
 */


void Mem_AllocOrFree_00489690(undefined4 value,undefined4 min_val,undefined4 max_val)

{
  DAT_00539dec = min_val;
  DAT_00539df0 = max_val;
  FUN_00489748(value,0);
  return;
}

/*
 * Decompiled function: FUN_004896be
 * Entry Point: 004896be
 * Size: 82 bytes
 */


void FUN_004896be(undefined4 value,int min_val,uint max_val)

{
  FUN_00489710(value,(min_val * g_DisplayScreenWidth) / 0x140,
               (int)((max_val - (max_val & 1)) * g_DisplayScreenHeight) / 200 + (max_val & 1));
  return;
}

/*
 * Decompiled function: FUN_00489710
 * Entry Point: 00489710
 * Size: 56 bytes
 */


void FUN_00489710(undefined4 value,undefined4 min_val,undefined4 max_val)

{
  DAT_00539dec = min_val;
  DAT_00539df0 = max_val;
  DAT_00527b18 = 0xffffffff;
  FUN_00489748(value,1);
  return;
}

/*
 * Decompiled function: FUN_00489748
 * Entry Point: 00489748
 * Size: 1359 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00489748(char *x,int y)

{
  bool bVar1;
  int iVar2;
  char *str_2;
  int iVar3;
  uint uVar4;
  int local_34;
  int local_28;
  int local_1c;
  char local_18 [4];
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((y != 0) && (DAT_00676d3c == 0)) {
    App_ProcessPendingMessages();
  }
  local_1c = -1;
  DAT_00527b28 = 0;
  _DAT_00527b1c = 0;
  DAT_00539de4 = 0;
  local_34 = 0;
  if (DAT_00527b18 != -1) {
    local_34 = DAT_00527b18;
  }
  DAT_00676d50 = -1;
  DAT_00676d38 = 1;
  DAT_00539e04 = -1;
  DAT_00527b30 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  local_14 = 0x16;
  DAT_00539de0 = 0xff;
  if (DAT_0067bde4 == 0) {
    local_14 = 0xffffffff;
  }
  local_c = 0;
  bVar1 = false;
  Pic_Subsystem_0044b8da();
  FUN_00489c9c(x,DAT_00527b18);
  Pic_Subsystem_0044b8aa();
  if (DAT_00676d3c == 0) {
    if (DAT_00527b2c != -1) {
      Mem_AllocOrFree_005016f9();
      local_8 = -1;
    }
    do {
      DAT_00676d38 = 0;
      DAT_0067bda0 = 0;
      if (DAT_00701014 == 0) {
        FUN_0040a2c0();
      }
      iVar3 = DAT_00527b2c;
      if (DAT_00527b2c != -1) {
        iVar2 = Mem_AllocOrFree_00501721();
        local_10 = iVar3 - iVar2 / (DAT_0052244c * 0x3c);
        if (local_10 == 0) {
          local_34 = -1;
          bVar1 = true;
        }
        if (local_8 != local_10) {
          str_2 = _itoa(local_10,&DAT_00539df8,10);
          strcpy(local_18,str_2);
          Surface_FillRect((int *)g_DisplaySurfaceScreen,DAT_00676d44 + -0xe,DAT_00539df0 + 4,0xc,7,
                           0xbc);
          FUN_0040c3cc(local_18,DAT_00676d44 + -8,DAT_00539df0 + 5,0xff);
          local_8 = local_10;
        }
      }
      Pic_Subsystem_0044b84b();
      if ((DAT_0067bda0 == 0) && (local_c == 0)) {
        iVar3 = Mem_AllocOrFree_00408089();
        if (iVar3 != 0) {
          uVar4 = FUN_0048ac2f();
          iVar3 = local_34;
          if ((int)uVar4 < 0x1c) {
            if (uVar4 == 0x1b) {
              local_34 = -1;
              bVar1 = true;
            }
            else {
              if (uVar4 == 0xd) goto LAB_00489ab3;
LAB_00489af7:
              do {
                iVar2 = iVar3;
                local_28 = iVar2 + 1;
                if (0x1f < local_28) goto LAB_00489b95;
                iVar3 = local_28;
              } while (((&DAT_00676d11)[iVar2] == -1) ||
                      (iVar3 = local_28,
                      (((int)(char)(&DAT_00676d11)[iVar2] ^ uVar4 & 0x1f) & 0x1f) != 0));
              local_34 = local_28;
            }
          }
          else if (uVar4 == 0x20) {
LAB_00489ab3:
            if ((DAT_00676d58 & 1 << ((byte)local_34 & 0x1f)) == 0) {
              bVar1 = true;
            }
          }
          else if (uVar4 == 0x4800) {
            if (0 < local_34) {
              local_34 = local_34 + -1;
            }
          }
          else {
            if (uVar4 != 0x5000) goto LAB_00489af7;
            if (local_34 < DAT_00676d40 + -1) {
              local_34 = local_34 + 1;
            }
          }
        }
      }
      else {
        DAT_00527b28 = 1;
        local_c = 1;
        if (DAT_0067bda0 == 2) {
          _DAT_00527b1c = 1;
        }
        local_34 = ((DAT_0067bda8 - DAT_00539df0) + -4) / DAT_00527b30 - DAT_00676d50;
        if ((DAT_0067bda4 < DAT_00539dec) || (DAT_00676d44 < DAT_0067bda4)) {
          local_34 = -1;
        }
        if ((DAT_00676d58 & 1 << ((byte)local_34 & 0x1f)) == 0) {
          if (DAT_0067bda0 == 0) {
            bVar1 = true;
          }
        }
        else {
          local_34 = local_1c;
        }
      }
LAB_00489b95:
      if ((((local_34 < 0) || (DAT_00676d40 <= local_34)) || (DAT_00676d4c != 0)) ||
         (DAT_00676d34 != 0)) {
        local_34 = -1;
      }
      if (local_1c != local_34) {
        FUN_00489c9c(x,local_34);
        local_1c = local_34;
        DAT_00539e04 = local_34;
      }
    } while (!bVar1);
    DAT_00539de4 = 1;
    if (local_34 == -1) {
      _DAT_00527b1c = 0;
    }
    else {
      Pic_Subsystem_0044b8da();
      FUN_00489c9c(x,local_34);
      FUN_00501736(0x14);
      Pic_Subsystem_0044b8aa();
    }
    DAT_00527b2c = -1;
    DAT_00527b20 = 0xffffffff;
    DAT_00527b18 = -1;
    DAT_00527b24 = 0;
    DAT_00676d34 = 0;
    DAT_00676d58 = 0;
    _DAT_00676d30 = 0;
  }
  else {
    DAT_00676d3c = 0;
    local_34 = -1;
  }
  return local_34;
}

/*
 * Decompiled function: FUN_00489c9c
 * Entry Point: 00489c9c
 * Size: 1310 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00489c9c(char *str_1,int y)

{
  size_t sVar1;
  int iVar2;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  _DAT_00539d60 = 0;
  if (DAT_00676d38 == 1) {
    DAT_00527b30 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    for (local_14 = 0; (int)local_14 < 0x20; local_14 = local_14 + 1) {
      (&DAT_00676d10)[local_14] = 0xff;
    }
    local_c = 0;
    DAT_00539de8 = 0;
    local_8 = 0;
    DAT_00676d48 = 0;
    for (local_14 = 0; sVar1 = strlen(str_1), local_14 < sVar1; local_14 = local_14 + 1) {
      if (str_1[local_14] == '\n') {
        if (DAT_00676d48 < local_8) {
          DAT_00676d48 = local_8;
        }
        local_8 = 0;
        DAT_00539de8 = DAT_00539de8 + 1;
        *(uint *)(&DAT_00539d60 + DAT_00539de8 * 4) = local_14 + 1;
      }
      else {
        if ((local_8 == 0) && ((str_1[local_14] == ' ' || (str_1[local_14] == '_')))) {
          if (local_c < 0x20) {
            (&DAT_00676d10)[local_c] = str_1[local_14 + 1];
          }
          if (DAT_00676d50 == -1) {
            DAT_00676d50 = DAT_00539de8;
          }
          local_c = local_c + 1;
        }
        iVar2 = FUN_0050f390(*(int *)(g_DisplaySurfaceScreen + 0x20),str_1[local_14]);
        local_8 = local_8 + iVar2;
      }
    }
    DAT_00539de8 = Math_Clamp(DAT_00539de8,0,(g_DisplayScreenHeight - DAT_00539df0) / DAT_00527b30);
    if (DAT_00539dec == -1) {
      DAT_00539dec = 0xa0 - (DAT_00676d48 + 8) / 2;
    }
    DAT_00676d44 = DAT_00539dec + DAT_00676d48 + 8;
    iVar2 = DAT_00527b30 * DAT_00539de8 + DAT_00539df0;
    local_10 = iVar2 + 6;
    if (DAT_00527b24 != 0) {
      local_10 = iVar2 + 8;
    }
    sVar1 = strlen(str_1);
    if (str_1[sVar1 - 1] != '\n') {
      local_c = local_c + -1;
    }
    DAT_00676d40 = local_c;
    FUN_0048a1ba(DAT_00539dec,DAT_00539df0,DAT_00676d44 - DAT_00539dec,local_10 - DAT_00539df0);
    if (DAT_00676d4c != 0) {
      FUN_0040c1ad(&DAT_00527b40,DAT_00676d44 + -0x11,local_10 + -8,0xfe);
      FUN_0048a2a5(DAT_00676d44 + -0x14,local_10 + -10,0x14,10,0xfe);
    }
  }
  if ((*str_1 == ' ') || (*str_1 == '_')) {
    local_c = 0;
  }
  else {
    local_c = -1;
  }
  DAT_00539de0 = DAT_00527b34;
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x18) = DAT_00527b34;
  for (local_14 = 0; (int)local_14 < DAT_00539de8; local_14 = local_14 + 1) {
    if (((DAT_00676d38 != 0) || (DAT_00539e04 == local_c)) || (y == local_c)) {
      str_1[*(int *)(&DAT_00539d64 + local_14 * 4) + -1] = '\0';
      if ((local_c < 0) || ((_DAT_00676d30 & 1 << ((byte)local_c & 0x1f)) == 0)) {
        if (local_c < 0) {
          local_1c = DAT_00539de0;
        }
        else if (y == local_c) {
          local_1c = DAT_00527b38;
        }
        else {
          local_1c = DAT_00527b34;
        }
        FUN_0040c274(str_1 + *(int *)(&DAT_00539d60 + local_14 * 4),DAT_00539dec + 5,
                     DAT_00527b30 * local_14 + DAT_00539df0 + 5,local_1c);
      }
      else {
        str_1[*(int *)(&DAT_00539d60 + local_14 * 4)] = '^';
        if ((DAT_00539de4 == 0) || (y != local_c)) {
          if (local_c < 0) {
            local_18 = DAT_00539de0;
          }
          else if (y == local_c) {
            local_18 = DAT_00527b38;
          }
          else {
            local_18 = DAT_00527b34;
          }
          FUN_0040c274(str_1 + *(int *)(&DAT_00539d60 + local_14 * 4),DAT_00539dec + 5,
                       DAT_00527b30 * local_14 + DAT_00539df0 + 5,local_18);
        }
        else {
          FUN_0040c274(str_1 + *(int *)(&DAT_00539d60 + local_14 * 4),DAT_00539dec + 5,
                       DAT_00527b30 * local_14 + DAT_00539df0 + 5,0xff);
        }
        str_1[*(int *)(&DAT_00539d60 + local_14 * 4)] = ' ';
      }
      str_1[*(int *)(&DAT_00539d64 + local_14 * 4) + -1] = '\n';
    }
    if ((str_1[*(int *)(&DAT_00539d64 + local_14 * 4)] == ' ') ||
       (str_1[*(int *)(&DAT_00539d64 + local_14 * 4)] == '_')) {
      local_c = local_c + 1;
    }
  }
  return y;
}

/*
 * Decompiled function: FUN_0048a1ba
 * Entry Point: 0048a1ba
 * Size: 116 bytes
 */


void FUN_0048a1ba(undefined4 value,int y,undefined4 max_val,undefined4 target_slot)

{
  if (DAT_00676d54 == 0) {
    (*(code *)PTR_FUN_00527b3c)(value,y,max_val,target_slot,(int)(y + (y >> 0x1f & 7U)) >> 3 & 3);
  }
  else {
    (*(code *)PTR_FUN_00527b3c)(value,y,max_val,target_slot,DAT_00676d54);
    DAT_00676d54 = 0;
  }
  return;
}

/*
 * Decompiled function: FUN_0048a2a5
 * Entry Point: 0048a2a5
 * Size: 147 bytes
 */


void FUN_0048a2a5(int value,int min_val,int max_val,int target_slot,undefined4 flags)

{
  Mem_AllocOrFree_0040c180(value,min_val,max_val + value,min_val,flags);
  Mem_AllocOrFree_0040c180(value,target_slot + min_val,max_val + value,target_slot + min_val,flags);
  Mem_AllocOrFree_0040c180(max_val + value,min_val,max_val + value,target_slot + min_val,flags);
  Mem_AllocOrFree_0040c180(value,min_val,value,target_slot + min_val,flags);
  return;
}

/*
 * Decompiled function: FUN_0048a338
 * Entry Point: 0048a338
 * Size: 148 bytes
 */


void FUN_0048a338(int value,int min_val,int max_val,int target_slot,undefined4 flags,undefined4 arg_6)

{
  Mem_AllocOrFree_0040c180(value,min_val,max_val + value,min_val,arg_6);
  Mem_AllocOrFree_0040c180(value,target_slot + min_val,max_val + value,target_slot + min_val,flags);
  Mem_AllocOrFree_0040c180(max_val + value,min_val,max_val + value,target_slot + min_val,arg_6);
  Mem_AllocOrFree_0040c180(value,min_val + 1,value,target_slot + min_val,flags);
  return;
}

/*
 * Decompiled function: FUN_0048a3cc
 * Entry Point: 0048a3cc
 * Size: 803 bytes
 */


void FUN_0048a3cc(int value,int min_val,int max_val,int target_slot,int flags)

{
  int arg_2_00;
  int arg_3_00;
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  iVar1 = (int)(max_val + 0x17 + (max_val + 0x17 >> 0x1f & 0xfU)) >> 4;
  iVar2 = (int)(target_slot + 0x17 + (target_slot + 0x17 >> 0x1f & 0xfU)) >> 4;
  arg_2_00 = (value + -4) - (iVar1 * 0x10 - (max_val + 8)) / 2;
  arg_3_00 = (min_val + -4) - (iVar2 * 0x10 - (target_slot + 8)) / 2;
  *(undefined4 *)g_DisplaySurfaceScreen = 1;
  Surface_FillRect((int *)g_DisplaySurfaceScreen,arg_2_00,arg_3_00,iVar1 << 4,iVar2 << 4,0xe3);
  for (local_c = 0; local_c < iVar2; local_c = local_c + 1) {
    for (local_8 = 0; local_8 < iVar1; local_8 = local_8 + 1) {
      Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_8 * 0x10 + arg_2_00,
                        local_c * 0x10 + arg_3_00,(&DAT_006781d0)[flags * 9]);
    }
  }
  for (local_8 = 0; local_8 < iVar1; local_8 = local_8 + 1) {
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_8 * 0x10 + arg_2_00,arg_3_00 + -10,
                      *(int *)(&DAT_006781e4 + flags * 0x24));
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_8 * 0x10 + arg_2_00,
                      iVar2 * 0x10 + arg_3_00 + -6,*(int *)(&DAT_006781ec + flags * 0x24));
  }
  for (local_c = 0; local_c < iVar2; local_c = local_c + 1) {
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00 + -10,local_c * 0x10 + arg_3_00,
                      *(int *)(&DAT_006781f0 + flags * 0x24));
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar1 * 0x10 + arg_2_00 + -6,
                      local_c * 0x10 + arg_3_00,*(int *)(&DAT_006781e8 + flags * 0x24));
  }
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00 + -10,arg_3_00 + -10,
                    *(int *)(&DAT_006781d4 + flags * 0x24));
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar1 * 0x10 + arg_2_00 + -6,arg_3_00 + -10,
                    *(int *)(&DAT_006781d8 + flags * 0x24));
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00 + -10,iVar2 * 0x10 + arg_3_00 + -6,
                    *(int *)(&DAT_006781dc + flags * 0x24));
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar1 * 0x10 + arg_2_00 + -6,
                    iVar2 * 0x10 + arg_3_00 + -6,*(int *)(&DAT_006781e0 + flags * 0x24));
  *(undefined4 *)g_DisplaySurfaceScreen = 0;
  Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,arg_2_00 - 10,arg_3_00 + -10,iVar1 * 0x10 + 0x14,
               iVar2 * 0x10 + 0x14,(int *)g_DisplaySurfaceScreen,arg_2_00 + -10,arg_3_00 + -10);
  return;
}

/*
 * Decompiled function: FUN_0048a6ef
 * Entry Point: 0048a6ef
 * Size: 1344 bytes
 */


void FUN_0048a6ef(int value,int min_val,int max_val,int target_slot,undefined4 *flags)

{
  undefined4 *puVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  undefined4 uStack_a8;
  short local_a4 [2];
  undefined4 auStack_a0 [3];
  short local_94;
  short local_92;
  short local_84;
  short local_82;
  short local_74;
  short local_72;
  short local_64;
  short local_62;
  short local_54;
  short local_52;
  short local_44;
  short local_42;
  short local_34;
  short local_32;
  short local_24;
  short local_22;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  
  local_c = flags;
  for (local_b0 = 0; local_b0 < 9; local_b0 = local_b0 + 1) {
    if (local_c[local_b0] != 0) {
      puVar1 = (undefined4 *)local_c[local_b0];
      (&uStack_a8)[local_b0 * 4] = *puVar1;
      *(undefined4 *)(local_a4 + local_b0 * 8) = puVar1[1];
      auStack_a0[local_b0 * 4] = puVar1[2];
      auStack_a0[local_b0 * 4 + 1] = puVar1[3];
      sVar2 = Ai_Util_004c3bc4((int)local_a4[local_b0 * 8]);
      local_a4[local_b0 * 8] = sVar2;
      uVar3 = Ai_Util_004c3bc4((int)*(short *)((int)auStack_a0 + local_b0 * 0x10 + -2));
      *(undefined2 *)((int)auStack_a0 + local_b0 * 0x10 + -2) = uVar3;
    }
  }
  if (local_c[8] == 0) {
    local_14 = target_slot;
    local_10 = max_val;
  }
  else {
    if (target_slot % (int)local_22 != 0) {
      local_14 = (target_slot / (int)local_22 + 1) * (int)local_22;
    }
    if (max_val % (int)local_24 != 0) {
      local_10 = (max_val / (int)local_24 + 1) * (int)local_24;
    }
    value = (value + 4) - (local_10 - max_val) / 2;
    min_val = (min_val + 4) - (local_14 - target_slot) / 2;
    for (local_b4 = 0; local_b4 < local_14 / (int)local_22; local_b4 = local_b4 + 1) {
      for (local_b0 = 0; local_b0 < local_10 / (int)local_24; local_b0 = local_b0 + 1) {
        Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_24 * local_b0 + value,
                          local_22 * local_b4 + min_val,(int)local_24,(int)local_22,local_c[8]);
      }
    }
  }
  local_ac = (local_94 + local_10 + value) - (int)local_94;
  for (local_18 = (value - local_44) + (int)local_a4[0]; local_18 < value + local_10 / 2;
      local_18 = local_18 + local_64) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,min_val,(int)local_64,(int)local_62,
                      local_c[4]);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_ac,min_val,(int)local_64,(int)local_62,
                      local_c[4]);
    local_ac = local_ac - local_64;
  }
  local_18 = value - local_44;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,min_val,(int)local_a4[0],(int)local_a4[1],
                    *local_c);
  local_18 = (local_34 + max_val + value) - (int)local_94;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,min_val,(int)local_94,(int)local_92,
                    local_c[1]);
  local_18 = value - local_44;
  iVar4 = local_10 + value;
  for (local_b8 = local_a4[1] + min_val; local_b8 < (min_val + local_14) - (int)local_82;
      local_b8 = local_b8 + local_42) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,local_b8,(int)local_44,(int)local_42,
                      local_c[6]);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar4,local_b8,(int)local_34,(int)local_32,
                      local_c[7]);
  }
  iVar4 = (min_val + local_14) - (int)local_82;
  local_18 = value - local_44;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,iVar4,(int)local_84,(int)local_82,
                    local_c[2]);
  local_18 = (local_34 + local_10 + value) - (int)local_94;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,iVar4,(int)local_74,(int)local_72,
                    local_c[3]);
  local_ac = (local_94 + local_10 + value) - (int)local_94;
  iVar4 = min_val + local_14;
  for (local_18 = (value - local_44) + (int)local_a4[0]; local_18 < value + local_10 / 2;
      local_18 = local_18 + local_54) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_18,iVar4,(int)local_54,(int)local_52,
                      local_c[5]);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_ac,iVar4,(int)local_54,(int)local_52,
                      local_c[5]);
    local_ac = local_ac - local_54;
  }
  return;
}

/*
 * Decompiled function: FUN_0048ac2f
 * Entry Point: 0048ac2f
 * Size: 684 bytes
 */


uint FUN_0048ac2f(void)

{
  uint local_8;
  
  do {
    local_8 = FUN_004080b2();
  } while (local_8 == 0);
  if ((int)local_8 < 0x4738) {
    if (local_8 == 0x4737) {
      return 0x4737;
    }
    if (local_8 == 0x4700) {
      return 0x4700;
    }
  }
  else if ((int)local_8 < 0x4801) {
    if (local_8 == 0x4800) {
      return 0x4800;
    }
    if (local_8 == 0x475c) {
      return 0x4700;
    }
  }
  else if ((int)local_8 < 0x487f) {
    if (local_8 == 0x487e) {
      return 0x4800;
    }
    if (local_8 == 0x4838) {
      return 0x4838;
    }
  }
  else if ((int)local_8 < 0x493a) {
    if (local_8 == 0x4939) {
      return 0x4939;
    }
    if (local_8 == 0x4900) {
      return 0x4900;
    }
  }
  else if ((int)local_8 < 0x4b35) {
    if (local_8 == 0x4b34) {
      return 0x4b34;
    }
    if (local_8 == 0x4b00) {
      return 0x4b00;
    }
  }
  else if ((int)local_8 < 0x4b7d) {
    if (local_8 == 0x4b7c) {
      return 0x4b00;
    }
    if (local_8 == 0x4b43) {
      return 0x4b34;
    }
  }
  else if ((int)local_8 < 0x4d37) {
    if (local_8 == 0x4d36) {
      return 0x4d36;
    }
    if (local_8 == 0x4d00) {
      return 0x4d00;
    }
  }
  else if ((int)local_8 < 0x4f01) {
    if (local_8 == 0x4f00) {
      return 0x4f00;
    }
    if (local_8 == 0x4d46) {
      return 0x4d36;
    }
  }
  else if ((int)local_8 < 0x5001) {
    if (local_8 == 0x5000) {
      return 0x5000;
    }
    if (local_8 == 0x4f31) {
      return 0x4f31;
    }
  }
  else if ((int)local_8 < 0x5061) {
    if (local_8 == 0x5060) {
      return 0x5000;
    }
    if (local_8 == 0x5032) {
      return 0x5032;
    }
  }
  else {
    if (local_8 == 0x5100) {
      return 0x5100;
    }
    if (local_8 == 0x5133) {
      return 0x5133;
    }
    if (local_8 == 0xf400) {
      return 0x4d00;
    }
  }
  if ((char)local_8 != '\0') {
    local_8 = local_8 & 0xff;
  }
  return local_8;
}

/*
 * Decompiled function: FUN_0048aee0
 * Entry Point: 0048aee0
 * Size: 59 bytes
 */


void FUN_0048aee0(undefined8 *x,uint y)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = y;
  if (((uint)x & 4) != 0) {
    *(undefined1 *)x = 0;
    x = (undefined8 *)((int)x + 4);
    uVar1 = y - 1;
    if (uVar1 == 0 || (int)y < 1) {
      return;
    }
  }
  uVar2 = uVar1 >> 1;
  if (uVar2 != 0) {
    while (uVar2 = uVar2 - 1, uVar2 != 0) {
      *x = 0;
      x = x + 1;
    }
    *x = 0;
  }
  if ((uVar1 & 1) != 0) {
    *(undefined1 *)x = 0;
  }
  return;
}

/*
 * Decompiled function: FUN_0048b950
 * Entry Point: 0048b950
 * Size: 579 bytes
 */


int FUN_0048b950(uint *value,undefined4 min_val,undefined4 max_val)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint local_4;
  
  iVar3 = 0;
  local_4 = 0xd;
  do {
    (&DAT_00539e08)[iVar3] = 0xffffffff >> ((byte)iVar3 & 0x1f);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x20);
  DAT_0053aa94 = value;
  DAT_0053aa90 = value + 1;
  DAT_0053aa98 = 100000;
  DAT_00527b44 = 0x13;
  uVar1 = DAT_00539e54 & *value;
  DAT_00539e8c = *value >> 0xd;
  DAT_0053aa9c = uVar1;
  if (0 < (int)uVar1) {
    puVar5 = &DAT_0053aaa8;
    local_4 = uVar1 * 0x1a + 0xd;
    do {
      if (DAT_00527b44 < 0xd) {
        iVar3 = 0xd - DAT_00527b44;
        if ((int)DAT_0053aa90 + (4 - (int)value) < 100000) {
          uVar2 = *DAT_0053aa90;
          DAT_0053aa90 = DAT_0053aa90 + 1;
          uVar4 = DAT_00539e8c | ((&DAT_00539e88)[-iVar3] & uVar2) << ((byte)DAT_00527b44 & 0x1f);
          DAT_00539e8c = uVar2 >> ((byte)iVar3 & 0x1f);
          DAT_00527b44 = 0x20 - iVar3;
          *puVar5 = uVar4;
        }
        else {
          *puVar5 = 0xffffffff;
        }
      }
      else {
        uVar2 = DAT_00539e54 & DAT_00539e8c;
        DAT_00539e8c = DAT_00539e8c >> 0xd;
        DAT_00527b44 = DAT_00527b44 - 0xd;
        *puVar5 = uVar2;
      }
      if (DAT_00527b44 < 0xd) {
        iVar3 = 0xd - DAT_00527b44;
        if ((int)DAT_0053aa90 + (4 - (int)value) < 100000) {
          uVar2 = *DAT_0053aa90;
          DAT_0053aa90 = DAT_0053aa90 + 1;
          uVar4 = DAT_00539e8c | ((&DAT_00539e88)[-iVar3] & uVar2) << ((byte)DAT_00527b44 & 0x1f);
          DAT_00539e8c = uVar2 >> ((byte)iVar3 & 0x1f);
          DAT_00527b44 = 0x20 - iVar3;
          puVar5[1] = uVar4;
        }
        else {
          puVar5[1] = 0xffffffff;
        }
      }
      else {
        uVar2 = DAT_00539e54 & DAT_00539e8c;
        DAT_00539e8c = DAT_00539e8c >> 0xd;
        DAT_00527b44 = DAT_00527b44 - 0xd;
        puVar5[1] = uVar2;
      }
      puVar5 = puVar5 + 2;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  DAT_0053aaa0 = max_val;
  DAT_0053aaa4 = min_val;
  FUN_0048bba0(DAT_0053aa9c);
  return ((int)(local_4 + ((int)local_4 >> 0x1f & 7U)) >> 3) + (uint)((local_4 & 7) != 0);
}

/*
 * Decompiled function: FUN_0048bba0
 * Entry Point: 0048bba0
 * Size: 487 bytes
 */


undefined4 FUN_0048bba0(int value)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int local_b8 [11];
  undefined4 uStack_8c;
  int aiStack_30 [12];
  
  local_b8[0] = 0x100;
  local_b8[1] = 0x200;
  local_b8[2] = 0x400;
  piVar8 = local_b8 + 3;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar8 = 1;
    piVar8 = piVar8 + 1;
  }
  iVar1 = value + -1;
  aiStack_30[1] = iVar1;
  iVar3 = 0;
  do {
    iVar4 = iVar3 + 1;
    if (local_b8[iVar3 + 3] == 0) {
      iVar2 = (&DAT_0053aaac)[iVar1 * 2];
    }
    else {
      iVar2 = (&DAT_0053aaa8)[iVar1 * 2];
    }
    iVar1 = iVar2 - DAT_0053aaa0;
    aiStack_30[iVar3 + 2] = iVar1;
    if (iVar1 < 0) {
      iVar1 = 0;
      uVar9 = 0;
      if (0 < iVar4) {
        do {
          uVar9 = uVar9 | local_b8[iVar1 + 3] << ((byte)iVar1 & 0x1f);
          iVar1 = iVar1 + 1;
        } while (iVar1 < iVar4);
      }
      iVar6 = 0;
      iVar1 = local_b8[-iVar4];
      if (0 < iVar1) {
        puVar5 = (undefined4 *)(iVar2 * 4 + DAT_0053aaa4);
        do {
          uVar7 = iVar6 << ((byte)iVar4 & 0x1f) | uVar9;
          iVar6 = iVar6 + 1;
          (&DAT_00539e94)[uVar7 * 3] = iVar4;
          (&DAT_00539e90)[uVar7 * 3] = *puVar5;
          (&DAT_00539e98)[uVar7 * 3] = 0xffffffff;
        } while (iVar6 < iVar1);
      }
      local_b8[iVar3 + 4] = 1;
      local_b8[iVar3 + 3] = local_b8[iVar3 + 3] + -1;
LAB_0048bd35:
      iVar2 = iVar3 * 4;
      iVar1 = aiStack_30[iVar3 + 1];
      iVar4 = iVar3;
      if (local_b8[3] < 0) {
        return 0;
      }
      do {
        if (-1 < *(int *)((int)local_b8 + iVar2 + 0xc)) break;
        iVar1 = *(int *)((int)aiStack_30 + iVar2);
        *(undefined4 *)((int)local_b8 + iVar2 + 0xc) = 1;
        iVar4 = iVar4 + -1;
        *(int *)((int)local_b8 + iVar2 + 8) = *(int *)((int)local_b8 + iVar2 + 8) + -1;
        iVar2 = iVar2 + -4;
      } while (-1 < local_b8[3]);
    }
    else if (iVar4 == 8) {
      iVar4 = 0;
      uVar9 = 0;
      do {
        uVar9 = uVar9 | local_b8[iVar4 + 3] << ((byte)iVar4 & 0x1f);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 8);
      uStack_8c = 1;
      (&DAT_00539e90)[uVar9 * 3] = 0x7fffffff;
      (&DAT_00539e94)[uVar9 * 3] = 8;
      (&DAT_00539e98)[uVar9 * 3] = iVar1;
      local_b8[iVar3 + 3] = local_b8[iVar3 + 3] + -1;
      goto LAB_0048bd35;
    }
    iVar3 = iVar4;
    if (local_b8[3] < 0) {
      return 0;
    }
  } while( true );
}

/*
 * Decompiled function: FUN_0048bda1
 * Entry Point: 0048bda1
 * Size: 208 bytes
 */


undefined4 __thiscall FUN_0048bda1(void *this)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int unaff_retaddr;
  int iStack00000080;
  int in_stack_00000104;
  
  iVar5 = 0;
  puVar6 = (undefined4 *)register0x00000010;
  for (; this != (void *)0x0; this = (void *)((int)this + -1)) {
    *puVar6 = in_EAX;
    puVar6 = puVar6 + 1;
  }
  iVar4 = in_stack_00000104 + -1;
  iStack00000080 = iVar4;
  puVar6 = &DAT_00676c90;
  for (iVar3 = 0x20; iVar1 = DAT_0053aaa0, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  do {
    iVar3 = iVar5 + 1;
    if (*(int *)(&stack0x00000000 + iVar5 * 4) == 0) {
      iVar4 = (&DAT_0053aaac)[iVar4 * 2];
    }
    else {
      iVar4 = (&DAT_0053aaa8)[iVar4 * 2];
    }
    iVar4 = iVar4 - iVar1;
    *(int *)((int)&stack0x00000080 + iVar3 * 4) = iVar4;
    if (iVar4 < 0) {
      iVar4 = (&DAT_00676c90)[iVar3];
      *(undefined4 *)(&stack0x00000000 + iVar3 * 4) = 1;
      (&DAT_00676c90)[iVar3] = iVar4 + 1;
      iVar2 = iVar5 * 4;
      *(int *)(&stack0x00000000 + iVar2) = *(int *)(&stack0x00000000 + iVar5 * 4) + -1;
      iVar4 = *(int *)((int)&stack0x00000080 + iVar2);
      iVar3 = iVar5;
      if (unaff_retaddr < 0) {
        return 0;
      }
      do {
        if (-1 < *(int *)(&stack0x00000000 + iVar2)) break;
        *(undefined4 *)(&stack0x00000000 + iVar2) = 1;
        iVar3 = iVar3 + -1;
        *(int *)(&stack0xfffffffc + iVar2) = *(int *)(&stack0xfffffffc + iVar2) + -1;
        iVar4 = *(int *)(&stack0x0000007c + iVar2);
        iVar2 = iVar2 + -4;
      } while (-1 < unaff_retaddr);
    }
    iVar5 = iVar3;
    if (unaff_retaddr < 0) {
      return 0;
    }
  } while( true );
}

/*
 * Decompiled function: FUN_0048be80
 * Entry Point: 0048be80
 * Size: 488 bytes
 */


int FUN_0048be80(undefined4 *value,uint *min_val,int max_val)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int local_8;
  
  local_8 = 0;
  DAT_0053aa90 = min_val;
  DAT_0053aa94 = min_val;
  iVar3 = DAT_0053aa9c + -1;
  DAT_0053aa98 = max_val;
  DAT_00527b44 = 0;
  do {
    if (DAT_00527b44 == 0) {
      if ((int)DAT_0053aa90 - (int)DAT_0053aa94 < DAT_0053aa98) {
        DAT_00539e8c = *DAT_0053aa90;
        DAT_0053aa90 = DAT_0053aa90 + 1;
        DAT_00527b44 = 0x20;
        goto LAB_0048bf03;
      }
      uVar5 = 0xffffffff;
    }
    else {
LAB_0048bf03:
      uVar5 = (uint)((DAT_00539e8c & 1) != 0);
      DAT_00539e8c = DAT_00539e8c >> 1;
      DAT_00527b44 = DAT_00527b44 - 1;
    }
    if (uVar5 == 0xffffffff) {
      return local_8;
    }
    if (uVar5 == 0) {
      iVar1 = (&DAT_0053aaac)[iVar3 * 2];
    }
    else {
      iVar1 = (&DAT_0053aaa8)[iVar3 * 2];
    }
    iVar3 = iVar1 - DAT_0053aaa0;
    if (iVar3 < 0) {
      if (iVar1 == 0) {
        if (DAT_00527b44 < 10) {
          iVar3 = 10 - DAT_00527b44;
          if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uVar5 = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            uVar4 = DAT_00539e8c | ((&DAT_00539e88)[-iVar3] & uVar5) << ((byte)DAT_00527b44 & 0x1f);
            DAT_00539e8c = uVar5 >> ((byte)iVar3 & 0x1f);
            DAT_00527b44 = 0x20 - iVar3;
          }
          else {
            uVar4 = 0xffffffff;
          }
        }
        else {
          uVar4 = DAT_00539e60 & DAT_00539e8c;
          DAT_00539e8c = DAT_00539e8c >> 10;
          DAT_00527b44 = DAT_00527b44 - 10;
        }
        if ((int)uVar4 < 0) {
          return local_8;
        }
        puVar2 = value + uVar4;
        for (uVar5 = uVar4 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
          *value = 0;
          value = value + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)value = 0;
          value = (undefined4 *)((int)value + 1);
        }
        local_8 = local_8 + uVar4;
      }
      else {
        puVar2 = value + 1;
        local_8 = local_8 + 1;
        *value = *(undefined4 *)(DAT_0053aaa4 + iVar1 * 4);
      }
      iVar3 = DAT_0053aa9c + -1;
      value = puVar2;
    }
  } while( true );
}

/*
 * Decompiled function: FUN_0048c070
 * Entry Point: 0048c070
 * Size: 1619 bytes
 */


int FUN_0048c070(int *value,uint *min_val,int max_val)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  byte local_8;
  
  DAT_0053aa90 = min_val;
  if (((uint)min_val & 3) == 0) {
    DAT_00527b44 = 0;
    DAT_00539e8c = 0;
  }
  else {
    iVar5 = 4 - ((uint)min_val & 3);
    DAT_00527b44 = iVar5 * 8;
    DAT_0053aa90 = (uint *)(iVar5 + (int)min_val);
    DAT_00539e8c = 0xffffffffU >> (0x20U - (char)DAT_00527b44 & 0x1f) & *min_val;
  }
  piVar1 = value;
  DAT_0053aa98 = max_val;
  DAT_0053aa94 = min_val;
  if (DAT_00527b44 < 8) {
    iVar5 = 8 - DAT_00527b44;
    if ((int)DAT_0053aa90 + (4 - (int)min_val) < max_val) {
      uVar2 = *DAT_0053aa90;
      DAT_0053aa90 = DAT_0053aa90 + 1;
      uVar7 = DAT_00539e8c | ((&DAT_00539e88)[-iVar5] & uVar2) << ((byte)DAT_00527b44 & 0x1f);
      DAT_00539e8c = uVar2 >> ((byte)iVar5 & 0x1f);
      DAT_00527b44 = 0x20 - iVar5;
    }
    else {
      uVar7 = 0xffffffff;
    }
  }
  else {
    uVar7 = DAT_00539e68 & DAT_00539e8c;
    DAT_00539e8c = DAT_00539e8c >> 8;
    DAT_00527b44 = DAT_00527b44 - 8;
  }
  while (uVar7 != 0xffffffff) {
    iVar5 = (&DAT_00539e90)[uVar7 * 3];
    if (iVar5 < 0x7fffffff) {
      uVar2 = (&DAT_00539e94)[uVar7 * 3];
      local_8 = (byte)uVar2;
      if (iVar5 == -0x80000000) {
        uVar2 = uVar2 + 2;
        if (DAT_00527b44 < uVar2) {
          uVar2 = uVar2 - DAT_00527b44;
          if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uVar3 = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            uVar4 = DAT_00539e8c | ((&DAT_00539e88)[-uVar2] & uVar3) << ((byte)DAT_00527b44 & 0x1f);
            DAT_00539e8c = uVar3 >> ((byte)uVar2 & 0x1f);
            DAT_00527b44 = 0x20;
            goto LAB_0048c281;
          }
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (&DAT_00539e88)[-uVar2] & DAT_00539e8c;
          DAT_00539e8c = DAT_00539e8c >> ((byte)uVar2 & 0x1f);
LAB_0048c281:
          DAT_00527b44 = DAT_00527b44 - uVar2;
        }
        if ((int)uVar4 < 0) break;
        uVar7 = uVar4 << (8 - local_8 & 0x1f) | (int)uVar7 >> (local_8 & 0x1f);
        uVar2 = uVar7;
        piVar8 = piVar1;
        if (((uint)piVar1 & 4) == 0) {
LAB_0048c2bd:
          uVar3 = uVar2 >> 1;
          if (uVar3 != 0) {
            while (uVar3 = uVar3 - 1, uVar3 != 0) {
              piVar8[0] = 0;
              piVar8[1] = 0;
              piVar8 = piVar8 + 2;
            }
            piVar8[0] = 0;
            piVar8[1] = 0;
          }
          if ((uVar2 & 1) != 0) {
            *(undefined1 *)piVar8 = 0;
          }
        }
        else {
          *(undefined1 *)piVar1 = 0;
          piVar8 = piVar1 + 1;
          uVar2 = uVar7 - 1;
          if (uVar2 != 0 && 0 < (int)uVar7) goto LAB_0048c2bd;
        }
        piVar1 = piVar1 + uVar7;
        if (DAT_00527b44 < 8) {
          if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
LAB_0048c661:
            iVar5 = 8 - DAT_00527b44;
            uVar2 = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            uVar7 = DAT_00539e8c | ((&DAT_00539e88)[-iVar5] & uVar2) << ((byte)DAT_00527b44 & 0x1f);
            DAT_00539e8c = uVar2 >> ((byte)iVar5 & 0x1f);
            DAT_00527b44 = 0x20 - iVar5;
          }
          else {
LAB_0048c65a:
            uVar7 = 0xffffffff;
          }
        }
        else {
          uVar7 = DAT_00539e68 & DAT_00539e8c;
          DAT_00539e8c = DAT_00539e8c >> 8;
          DAT_00527b44 = DAT_00527b44 - 8;
        }
      }
      else {
        *piVar1 = iVar5;
        piVar1 = piVar1 + 1;
        if (DAT_00527b44 < uVar2) {
          uVar2 = uVar2 - DAT_00527b44;
          if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uVar3 = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            uVar4 = DAT_00539e8c | ((&DAT_00539e88)[-uVar2] & uVar3) << ((byte)DAT_00527b44 & 0x1f);
            DAT_00539e8c = uVar3 >> ((byte)uVar2 & 0x1f);
            DAT_00527b44 = 0x20;
            goto LAB_0048c419;
          }
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (&DAT_00539e88)[-uVar2] & DAT_00539e8c;
          DAT_00539e8c = DAT_00539e8c >> (local_8 & 0x1f);
LAB_0048c419:
          DAT_00527b44 = DAT_00527b44 - uVar2;
        }
        if (uVar4 == 0xffffffff) break;
        uVar7 = (int)uVar7 >> (local_8 & 0x1f) | uVar4 << (8 - local_8 & 0x1f);
      }
    }
    else {
      iVar5 = (&DAT_00539e98)[uVar7 * 3];
      do {
        if (DAT_00527b44 == 0) {
          if ((int)DAT_0053aa90 - (int)DAT_0053aa94 < DAT_0053aa98) {
            DAT_00539e8c = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            DAT_00527b44 = 0x20;
            goto LAB_0048c492;
          }
          uVar2 = 0xffffffff;
        }
        else {
LAB_0048c492:
          uVar2 = (uint)((DAT_00539e8c & 1) != 0);
          DAT_00539e8c = DAT_00539e8c >> 1;
          DAT_00527b44 = DAT_00527b44 - 1;
        }
        if (uVar2 == 0xffffffff) goto LAB_0048c5f9;
        if (uVar2 == 0) {
          iVar6 = (&DAT_0053aaac)[iVar5 * 2];
        }
        else {
          iVar6 = (&DAT_0053aaa8)[iVar5 * 2];
        }
        iVar5 = iVar6 - DAT_0053aaa0;
      } while (-1 < iVar5);
      if (iVar6 == 0) {
        if (DAT_00527b44 < 10) {
          iVar5 = 10 - DAT_00527b44;
          if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uVar2 = *DAT_0053aa90;
            DAT_0053aa90 = DAT_0053aa90 + 1;
            uVar7 = DAT_00539e8c | ((&DAT_00539e88)[-iVar5] & uVar2) << ((byte)DAT_00527b44 & 0x1f);
            DAT_00539e8c = uVar2 >> ((byte)iVar5 & 0x1f);
            DAT_00527b44 = 0x20 - iVar5;
          }
          else {
            uVar7 = 0xffffffff;
          }
        }
        else {
          uVar7 = DAT_00539e60 & DAT_00539e8c;
          DAT_00539e8c = DAT_00539e8c >> 10;
          DAT_00527b44 = DAT_00527b44 - 10;
        }
        if (-1 < (int)uVar7) {
          uVar2 = uVar7;
          piVar8 = piVar1;
          if (((uint)piVar1 & 4) == 0) {
LAB_0048c5c3:
            uVar3 = uVar2 >> 1;
            if (uVar3 != 0) {
              while (uVar3 = uVar3 - 1, uVar3 != 0) {
                piVar8[0] = 0;
                piVar8[1] = 0;
                piVar8 = piVar8 + 2;
              }
              piVar8[0] = 0;
              piVar8[1] = 0;
            }
            if ((uVar2 & 1) != 0) {
              *(undefined1 *)piVar8 = 0;
            }
          }
          else {
            *(undefined1 *)piVar1 = 0;
            piVar8 = piVar1 + 1;
            uVar2 = uVar7 - 1;
            if (uVar2 != 0 && 0 < (int)uVar7) goto LAB_0048c5c3;
          }
          piVar1 = piVar1 + uVar7;
        }
      }
      else {
        *piVar1 = *(int *)(DAT_0053aaa4 + iVar6 * 4);
        piVar1 = piVar1 + 1;
      }
LAB_0048c5f9:
      if (DAT_00527b44 < 8) {
        if ((int)DAT_0053aa90 + (4 - (int)DAT_0053aa94) < DAT_0053aa98) goto LAB_0048c661;
        goto LAB_0048c65a;
      }
      uVar7 = DAT_00539e68 & DAT_00539e8c;
      DAT_00539e8c = DAT_00539e8c >> 8;
      DAT_00527b44 = DAT_00527b44 - 8;
    }
  }
  return (int)piVar1 - (int)value >> 2;
}

/*
 * Decompiled function: FUN_0048c6d0
 * Entry Point: 0048c6d0
 * Size: 80 bytes
 */


int FUN_0048c6d0(int value)

{
  int iVar1;
  
  if ((value < 0) || (9 < value)) {
    if ((value < 10) || (0xf < value)) {
      iVar1 = 0;
    }
    else {
      iVar1 = value + 0x57;
    }
  }
  else {
    iVar1 = value + 0x30;
  }
  return iVar1;
}

/*
 * Decompiled function: FUN_0048c72a
 * Entry Point: 0048c72a
 * Size: 387 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0048c72a(int value)

{
  int iVar1;
  uint local_8;
  
  DAT_0054aab0 = 1;
  Pic_Subsystem_0044b8da();
  iVar1 = FUN_0048cb40();
  if (iVar1 == -1) {
    Pic_Subsystem_0044b8aa();
    iVar1 = -1;
  }
  else {
    if (value == -1) {
      strcpy(&g_OverworldWorldState,&DAT_00527c50);
      _DAT_0063ee7c = 0;
      for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
        s_D_MAGIC0_SVE_00527b48[7] = FUN_0048c6d0(local_8);
        iVar1 = FUN_0048c8b2(s_D_MAGIC0_SVE_00527b48,1);
        if (iVar1 != 0) {
          _DAT_0063ee7c = _DAT_0063ee7c | 1 << ((byte)local_8 & 0x1f);
        }
      }
      Pic_Subsystem_0044b8aa();
      DAT_00627a78 = FUN_00489710(&g_OverworldWorldState,0x30,0x40);
      Pic_Subsystem_0044b8da();
      if ((_DAT_0063ee7c & 1 << ((byte)DAT_00627a78 & 0x1f)) == 0) {
        DAT_00627a78 = -1;
      }
    }
    else {
      DAT_00627a78 = value;
    }
    if (DAT_00627a78 != -1) {
      s_D_MAGIC0_SVE_00527b48[7] = FUN_0048c6d0(DAT_00627a78);
      iVar1 = FUN_0048c8b2(s_D_MAGIC0_SVE_00527b48,0);
      if (iVar1 == 0) {
        DAT_00627a78 = -1;
      }
    }
    if (DAT_00627a78 == -1) {
      FUN_00489710(s_Error_Loading_Save_Game_File_EXI_00527c68,100,0x50);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    Pic_Subsystem_0044b8aa();
    iVar1 = DAT_00627a78;
  }
  return iVar1;
}

/*
 * Decompiled function: FUN_0048c8b2
 * Entry Point: 0048c8b2
 * Size: 180 bytes
 */


uint FUN_0048c8b2(char *str_1,int y)

{
  uint uVar1;
  
  strcpy(str_1 + 9,&DAT_00527c90);
  if (y == 0) {
    uVar1 = FUN_0048ce07(str_1);
  }
  else {
    DAT_0054aab8 = _open(str_1,0x8000);
    if (DAT_0054aab8 == -1) {
      strcat(&g_OverworldWorldState,s__EMPTY__00527c98);
    }
    else {
      strcat(&g_OverworldWorldState,&DAT_00527c94);
    }
    _close(DAT_0054aab8);
    uVar1 = (uint)(DAT_0054aab8 != -1);
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0048c970
 * Entry Point: 0048c970
 * Size: 319 bytes
 */


void FUN_0048c970(int value)

{
  int iVar1;
  
  DAT_0054aad4 = 0;
  DAT_0054aab0 = 0;
  Pic_Subsystem_0044b8da();
  iVar1 = FUN_0048cb40();
  if (iVar1 != -1) {
    if (value == -1) {
      Pic_Subsystem_0044b8aa();
      value = FUN_00489710(&g_OverworldWorldState,0x30,0x20);
      Pic_Subsystem_0044b8da();
    }
    if (value != -1) {
      DAT_00627a78 = value;
      s_D_MAGIC0_SVE_00527b48[7] = FUN_0048c6d0(value);
      iVar1 = FUN_0048caaf(s_D_MAGIC0_SVE_00527b48);
      if (iVar1 != 0) {
        if (DAT_0054aad4 == 0) {
          strcpy(&g_OverworldWorldState,s_Game_has_been_saved__00527ca4);
        }
        else {
          strcpy(&g_OverworldWorldState,s_Game_NOT_saved__00527cbc);
          Surface_FillRect((int *)g_DisplaySurfaceScreen,0x40,0x7f,0xc0,0x22,0xc);
        }
        if (DAT_0054aad4 == 0xd) {
          strcat(&g_OverworldWorldState,s_Write_access_denied__00527cd0);
        }
        if (DAT_0054aad4 == 0x1c) {
          strcat(&g_OverworldWorldState,s_Disk_Full__00527ce8);
        }
        strcat(&g_OverworldWorldState,s_Press_key_to_continue__00527cf8);
      }
    }
  }
  Pic_Subsystem_0044b8aa();
  return;
}

/*
 * Decompiled function: FUN_0048caaf
 * Entry Point: 0048caaf
 * Size: 69 bytes
 */


undefined4 FUN_0048caaf(char *value)

{
  strcpy(&g_OverworldWorldState,&DAT_00527d14);
  strcat(&g_OverworldWorldState,s_____save_in_progress__00527d18);
  FUN_0048d087(value);
  return 1;
}

/*
 * Decompiled function: FUN_0048caf4
 * Entry Point: 0048caf4
 * Size: 71 bytes
 */


bool FUN_0048caf4(int value,void *min_val,uint max_val)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = _write(value,min_val,max_val);
  if (iVar1 == -1) {
    piVar2 = _errno();
    DAT_0054aad4 = *piVar2;
  }
  return iVar1 != -1;
}

/*
 * Decompiled function: FUN_0048cb40
 * Entry Point: 0048cb40
 * Size: 84 bytes
 */


int FUN_0048cb40(void)

{
  int iVar1;
  char local_108 [260];
  
  if (DAT_00527c4c == -1) {
    GetCurrentDirectoryA(0x100,local_108);
    s_D_MAGIC0_SVE_00527b48[0] = local_108[0];
  }
  iVar1 = tolower((int)s_D_MAGIC0_SVE_00527b48[0]);
  return iVar1 + -0x61;
}

/*
 * Decompiled function: Mem_AllocOrFree_0048cdf5
 * Entry Point: 0048cdf5
 * Size: 18 bytes
 */


undefined4 Mem_AllocOrFree_0048cdf5(void)

{
  return 0;
}

/*
 * Decompiled function: FUN_0048ce07
 * Entry Point: 0048ce07
 * Size: 640 bytes
 */


undefined4 FUN_0048ce07(char *str_1)

{
  undefined4 uVar1;
  int local_5c [4];
  int local_4c [9];
  int *local_28;
  undefined4 local_20;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  
  strcpy(str_1 + 9,&DAT_00527e2c);
  DAT_0054aab8 = _open(str_1,0x8000);
  if (DAT_0054aab8 == -1) {
    strcpy(&g_OverworldWorldState,s_File_Error__00527e30);
    strcat(&g_OverworldWorldState,str_1);
    strcat(&g_OverworldWorldState,&DAT_00527e40);
    FUN_00489710(&g_OverworldWorldState,100,0x50);
    uVar1 = 0;
  }
  else {
    DAT_0054aab0 = 1;
    FUN_0048d259();
    _close(DAT_0054aab8);
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      for (local_c = 0; local_c < 0x50; local_c = local_c + 1) {
        if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1) {
          (&g_PlayerActiveCardCount)[local_8] = local_c;
        }
      }
    }
    if (DAT_0063ee18 == 0) {
      Pic_Subsystem_0044b8da();
      strcpy(str_1 + 9,&DAT_00527e44);
      Mem_AllocOrFree_00510e20(2,str_1);
      Pic_Subsystem_0044b8aa();
    }
    local_4c[0] = 4;
    local_4c[1] = 0;
    local_4c[2] = 0;
    local_4c[3] = 800;
    local_4c[4] = 600;
    local_4c[5] = 1;
    local_4c[6] = 0xf;
    local_4c[7] = 4;
    local_4c[8] = 0;
    local_28 = local_4c;
    local_14 = 0x89;
    local_18 = 0xa9;
    local_20 = FUN_0050d0b0(4,0x112,0xa9,8);
    FUN_0050d370(4,local_20);
    FUN_0050e6f0(local_5c,(int)local_28,0,0,local_14 * 2,local_18);
    Surface_FillRect(local_28,0,0,local_14 * 2,local_18,0);
    strcpy(str_1 + 9,&DAT_00527e48);
    Mem_AllocOrFree_00510e20(4,str_1);
    DAT_0067bdd8 = *(undefined4 *)(DAT_0070a860 + 8);
    DAT_0067bdd4 = DAT_0070a860;
    SelectObject(*(HDC *)(DAT_0070a860 + 4),*(HGDIOBJ *)(DAT_0070a860 + 0xc));
    DAT_0070a860 = 0;
    Sprite_Load__16faces_0047c1a7(DAT_006ff678);
    uVar1 = 1;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0048d087
 * Entry Point: 0048d087
 * Size: 466 bytes
 */


undefined4 FUN_0048d087(char *str_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  
  if (DAT_0063ee18 == 0) {
    strcpy(str_1 + 9,&DAT_00527e4c);
    iVar1 = FUN_00512ba0(2,str_1);
    if (iVar1 != 0) {
      strcpy(&g_OverworldWorldState,s_Error_writing_map_file__00527e50);
      FUN_00489710(&g_OverworldWorldState,4,0x40);
      DAT_0054aad4 = 1;
      return 0;
    }
  }
  strcpy(str_1 + 9,&DAT_00527e6c);
  DAT_0054aab8 = _open(str_1,0x8301,0x80);
  if (DAT_0054aab8 == -1) {
    strcpy(&g_OverworldWorldState,s_File_Error__00527e70);
    strcat(&g_OverworldWorldState,str_1);
    strcat(&g_OverworldWorldState,&DAT_00527e80);
    FUN_00489710(&g_OverworldWorldState,100,0x50);
    uVar2 = 0;
  }
  else {
    DAT_0054aab0 = 0;
    FUN_0048d259();
    _close(DAT_0054aab8);
    local_44 = 4;
    local_40 = 0;
    local_3c = 0;
    local_38 = 800;
    local_34 = 600;
    local_30 = 1;
    local_2c = 0xf;
    local_28 = 4;
    local_24 = 0;
    local_20 = &local_44;
    DAT_0070a860 = DAT_0067bdd4;
    strcpy(str_1 + 9,&DAT_00527e84);
    FUN_00512c00(4,0,0,*(undefined4 *)(DAT_0067bdd4 + 0x20),*(undefined4 *)(DAT_0067bdd4 + 0x24),0,
                 str_1);
    DAT_0070a860 = 0;
    if (DAT_0054aad4 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0048d259
 * Entry Point: 0048d259
 * Size: 3524 bytes
 */


uint FUN_0048d259(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  uint uVar47;
  uint uVar48;
  uint uVar49;
  uint uVar50;
  uint uVar51;
  uint uVar52;
  uint uVar53;
  uint uVar54;
  uint uVar55;
  uint uVar56;
  uint uVar57;
  uint uVar58;
  uint uVar59;
  uint uVar60;
  uint uVar61;
  uint uVar62;
  uint uVar63;
  uint uVar64;
  uint uVar65;
  uint uVar66;
  uint uVar67;
  uint uVar68;
  uint uVar69;
  uint uVar70;
  uint uVar71;
  uint uVar72;
  uint uVar73;
  uint uVar74;
  uint uVar75;
  uint uVar76;
  uint uVar77;
  uint uVar78;
  uint uVar79;
  uint uVar80;
  uint uVar81;
  uint uVar82;
  uint uVar83;
  uint uVar84;
  uint uVar85;
  uint uVar86;
  uint uVar87;
  uint uVar88;
  uint uVar89;
  uint uVar90;
  uint uVar91;
  uint uVar92;
  uint uVar93;
  uint uVar94;
  uint uVar95;
  uint uVar96;
  uint uVar97;
  uint uVar98;
  uint uVar99;
  uint uVar100;
  uint uVar101;
  uint uVar102;
  uint uVar103;
  uint uVar104;
  uint uVar105;
  uint uVar106;
  uint uVar107;
  uint uVar108;
  uint uVar109;
  uint uVar110;
  uint uVar111;
  uint uVar112;
  uint uVar113;
  uint uVar114;
  uint uVar115;
  uint uVar116;
  uint uVar117;
  uint uVar118;
  uint uVar119;
  uint uVar120;
  uint uVar121;
  uint uVar122;
  uint uVar123;
  uint uVar124;
  uint uVar125;
  uint uVar126;
  uint uVar127;
  uint uVar128;
  uint uVar129;
  uint uVar130;
  uint uVar131;
  uint uVar132;
  uint uVar133;
  uint uVar134;
  uint uVar135;
  uint uVar136;
  uint uVar137;
  uint uVar138;
  uint uVar139;
  uint uVar140;
  uint uVar141;
  uint uVar142;
  uint uVar143;
  uint uVar144;
  uint uVar145;
  uint uVar146;
  uint uVar147;
  uint uVar148;
  uint uVar149;
  uint uVar150;
  uint uVar151;
  uint uVar152;
  uint uVar153;
  uint uVar154;
  uint uVar155;
  uint uVar156;
  uint uVar157;
  uint uVar158;
  uint uVar159;
  uint uVar160;
  uint uVar161;
  uint uVar162;
  uint uVar163;
  uint uVar164;
  uint uVar165;
  uint uVar166;
  uint uVar167;
  uint uVar168;
  uint uVar169;
  uint uVar170;
  uint uVar171;
  uint uVar172;
  uint uVar173;
  uint uVar174;
  uint uVar175;
  uint uVar176;
  uint uVar177;
  uint uVar178;
  uint uVar179;
  uint uVar180;
  uint uVar181;
  uint uVar182;
  uint uVar183;
  uint uVar184;
  uint uVar185;
  uint uVar186;
  uint uVar187;
  uint uVar188;
  
  uVar1 = FileIo_ReadStream(&g_MasterCardTable + g_MasterCardCount * 0x34, 0x340);
  uVar2 = FileIo_ReadStream(&DAT_00516cb8,0x500);
  uVar3 = FileIo_ReadStream(&DAT_0063ee20,4);
  uVar4 = FileIo_ReadStream(&DAT_00627858,4);
  uVar5 = FileIo_ReadStream(&DAT_00633430,4);
  uVar6 = FileIo_ReadStream(&DAT_00627a88,4);
  uVar7 = FileIo_ReadStream(&DAT_00627a84,4);
  uVar8 = FileIo_ReadStream(&DAT_00627864,4);
  uVar9 = FileIo_ReadStream(&DAT_00627a0c,4);
  uVar10 = FileIo_ReadStream(&DAT_0063ee1c,4);
  uVar11 = FileIo_ReadStream(&DAT_00633434,4);
  uVar12 = FileIo_ReadStream(&DAT_00676c8c,4);
  uVar13 = FileIo_ReadStream(&DAT_0063edc8,4);
  uVar14 = FileIo_ReadStream(&DAT_0063ee70,4);
  uVar15 = FileIo_ReadStream(&DAT_0063ee10,4);
  uVar16 = FileIo_ReadStream(&DAT_0063ee78,4);
  uVar17 = FileIo_ReadStream(&DAT_00627a08,4);
  uVar18 = FileIo_ReadStream(&DAT_0063eed8,4);
  uVar19 = FileIo_ReadStream(&DAT_0063edc4,4);
  uVar20 = FileIo_ReadStream(&DAT_0063edc0,4);
  uVar21 = FileIo_ReadStream(&DAT_00627a10,4);
  uVar22 = FileIo_ReadStream(&DAT_0063edd0,0x40);
  uVar23 = FileIo_ReadStream(&DAT_00627870,0x198);
  uVar24 = FileIo_ReadStream(&DAT_00627a20,0x58);
  uVar25 = FileIo_ReadStream(&DAT_0063eed0,8);
  uVar26 = FileIo_ReadStream(&DAT_0063ee90,0x40);
  uVar27 = FileIo_ReadStream(&DAT_0063ee30,0x40);
  uVar28 = FileIo_ReadStream(&DAT_00627a7c,4);
  uVar29 = FileIo_ReadStream(&DAT_00627868,4);
  uVar30 = FileIo_ReadStream(&DAT_0063ee80,4);
  uVar31 = FileIo_ReadStream(&DAT_0063ee18,4);
  uVar32 = FileIo_ReadStream(&DAT_00627a14,4);
  uVar33 = FileIo_ReadStream(&DAT_0063ee24,4);
  uVar34 = FileIo_ReadStream(&DAT_0063ee14,4);
  uVar35 = FileIo_ReadStream(&deck,2000);
  uVar36 = FileIo_ReadStream(&g_ActiveCardsInPlay,0xb640);
  uVar37 = FileIo_ReadStream(&DAT_00700ec0,0x140);
  uVar38 = FileIo_ReadStream(&DAT_006ff710,4000);
  uVar39 = FileIo_ReadStream(&DAT_006b1590,4000);
  uVar40 = FileIo_ReadStream(&DAT_0069e730,4000);
  uVar41 = FileIo_ReadStream(&DAT_006b2d90,0x80);
  uVar42 = FileIo_ReadStream(&DAT_007006d4,4);
  uVar43 = FileIo_ReadStream(&DAT_006ff2d8,4);
  uVar44 = FileIo_ReadStream(&g_AiChoiceValue,4);
  uVar45 = FileIo_ReadStream(&DAT_006fefa8,4);
  uVar46 = FileIo_ReadStream(&DAT_006b3000,0x60);
  uVar47 = FileIo_ReadStream(&DAT_0068a668,8);
  uVar48 = FileIo_ReadStream(&DAT_006b2d40,0x1c);
  uVar49 = FileIo_ReadStream(&DAT_006fdbd8,4);
  uVar50 = FileIo_ReadStream(&g_PlayerLifeTotals,0x10);
  uVar51 = FileIo_ReadStream(&g_ActivePlayer,4);
  uVar52 = FileIo_ReadStream(&g_PlayerActiveCardCount,8);
  uVar53 = FileIo_ReadStream(&DAT_00680790,4);
  uVar54 = FileIo_ReadStream(&DAT_00695e10,100);
  uVar55 = FileIo_ReadStream(&g_PlayerCreatureCount,8);
  uVar56 = FileIo_ReadStream(&DAT_00696870,8);
  uVar57 = FileIo_ReadStream(&DAT_006ff4b8,8);
  uVar58 = FileIo_ReadStream(&DAT_00695eb0,0x10);
  uVar59 = FileIo_ReadStream(&g_TurnPlayer,4);
  uVar60 = FileIo_ReadStream(&DAT_006b2d64,4);
  uVar61 = FileIo_ReadStream(&g_SpellStackDepth,4);
  uVar62 = FileIo_ReadStream(&g_ScWillyScore,4);
  uVar63 = FileIo_ReadStream(&g_DuelModeFlags,4);
  uVar64 = FileIo_ReadStream(&DAT_006a5f20,4);
  uVar65 = FileIo_ReadStream(&DAT_0068a67c,4);
  uVar66 = FileIo_ReadStream(&DAT_00696a18,4);
  uVar67 = FileIo_ReadStream(&DAT_00695df0,4);
  uVar68 = FileIo_ReadStream(&g_TurnCounter,4);
  uVar69 = FileIo_ReadStream(&g_OverworldPlayerCoordY,4);
  uVar70 = FileIo_ReadStream(&g_CurrentTurnPhase,4);
  uVar71 = FileIo_ReadStream(&g_ActivePlayerPriority,4);
  uVar72 = FileIo_ReadStream(&g_EventSourcePlayer,4);
  uVar73 = FileIo_ReadStream(&g_EventSourceSlot,4);
  uVar74 = FileIo_ReadStream(&g_EventCardId,4);
  uVar75 = FileIo_ReadStream(&g_EventCardColorMask,4);
  uVar76 = FileIo_ReadStream(&g_EventTargetPlayer,4);
  uVar77 = FileIo_ReadStream(&g_EventTargetSlot,4);
  uVar78 = FileIo_ReadStream(&g_CardEventResult,4);
  uVar79 = FileIo_ReadStream(&DAT_006a2838,4);
  uVar80 = FileIo_ReadStream(&DAT_006a2840,4);
  uVar81 = FileIo_ReadStream(&DAT_0068a650,4);
  uVar82 = FileIo_ReadStream(&DAT_0068a708,4);
  uVar83 = FileIo_ReadStream(&DAT_006ff190,4);
  uVar84 = FileIo_ReadStream(&DAT_006a2830,4);
  uVar85 = FileIo_ReadStream(&DAT_00695ec8,4);
  uVar86 = FileIo_ReadStream(&DAT_006ff2d4,4);
  uVar87 = FileIo_ReadStream(&DAT_006b2d3c,4);
  uVar88 = FileIo_ReadStream(&DAT_006b2d2c,4);
  uVar89 = FileIo_ReadStream(&DAT_006b2fe8,4);
  uVar90 = FileIo_ReadStream(&g_CurrentStepCode,4);
  uVar91 = FileIo_ReadStream(&DAT_00695f08,4);
  uVar92 = FileIo_ReadStream(&DAT_006b2e14,4);
  uVar93 = FileIo_ReadStream(&g_DialogPromptHwnd,4);
  uVar94 = FileIo_ReadStream(&g_DuelArenaHwnd,4);
  uVar95 = FileIo_ReadStream(&DAT_006a4b5c,4);
  uVar96 = FileIo_ReadStream(&DAT_00695ec4,4);
  uVar97 = FileIo_ReadStream(&DAT_0068a64c,4);
  uVar98 = FileIo_ReadStream(&DAT_006b2fe0,4);
  uVar99 = FileIo_ReadStream(&DAT_006feebc,4);
  uVar100 = FileIo_ReadStream(&DAT_006966f0,0x40);
  uVar101 = FileIo_ReadStream(&DAT_006a2844,4);
  uVar102 = FileIo_ReadStream(&DAT_006b2538,8);
  uVar103 = FileIo_ReadStream(&DAT_006fe3b0,0x40);
  uVar104 = FileIo_ReadStream(&DAT_0069f6d8,4);
  uVar105 = FileIo_ReadStream(&DAT_006b2d28,4);
  uVar106 = FileIo_ReadStream(&DAT_00680788,4);
  uVar107 = FileIo_ReadStream(&DAT_00701008,4);
  uVar108 = FileIo_ReadStream(&DAT_00695f0c,4);
  uVar109 = FileIo_ReadStream(&DAT_0068a714,4);
  uVar110 = FileIo_ReadStream(&DAT_0068078c,4);
  uVar111 = FileIo_ReadStream(&DAT_006fe3f4,4);
  uVar112 = FileIo_ReadStream(&DAT_006b2e40,0x40);
  uVar113 = FileIo_ReadStream(&DAT_006b2fa0,0x40);
  uVar114 = FileIo_ReadStream(&DAT_006ff690,0x40);
  uVar115 = FileIo_ReadStream(&DAT_006a2828,8);
  uVar116 = FileIo_ReadStream(&DAT_006a4a10,8);
  uVar117 = FileIo_ReadStream(&DAT_006a3f70,4);
  uVar118 = FileIo_ReadStream(&DAT_006fe40c,4);
  uVar119 = FileIo_ReadStream(&DAT_006808a8,4);
  uVar120 = FileIo_ReadStream(&DAT_00695e00,8);
  uVar121 = FileIo_ReadStream(&DAT_006a48f0,0x30);
  uVar122 = FileIo_ReadStream(&DAT_006a4934,4);
  uVar123 = FileIo_ReadStream(&DAT_006ff4ac,4);
  uVar124 = FileIo_ReadStream(&DAT_006a4b58,4);
  uVar125 = FileIo_ReadStream(&DAT_006a2858,4);
  uVar126 = FileIo_ReadStream(&DAT_00680780,8);
  uVar127 = FileIo_ReadStream(&g_SpellStackEntries,0x80);
  uVar128 = FileIo_ReadStream(&g_SpellStackObjects,0x100);
  uVar129 = FileIo_ReadStream(&DAT_006ff390,0x100);
  uVar130 = FileIo_ReadStream(&DAT_00696880,0x80);
  uVar131 = FileIo_ReadStream(&DAT_00695d70,0x80);
  uVar132 = FileIo_ReadStream(&g_SpellStackCount,4);
  uVar133 = FileIo_ReadStream(&DAT_006a4920,4);
  uVar134 = FileIo_ReadStream(&DAT_006b1584,4);
  uVar135 = FileIo_ReadStream(&DAT_0068a704,4);
  uVar136 = FileIo_ReadStream(&DAT_006b2e38,4);
  uVar137 = FileIo_ReadStream(&DAT_006808b0,4);
  uVar138 = FileIo_ReadStream(&DAT_00695df8,4);
  uVar139 = FileIo_ReadStream(&DAT_006b1580,4);
  uVar140 = FileIo_ReadStream(&DAT_007006e0,2000);
  uVar141 = FileIo_ReadStream(&DAT_006a5750,2000);
  uVar142 = FileIo_ReadStream(&DAT_006ff550,4);
  uVar143 = FileIo_ReadStream(&DAT_006fe408,4);
  uVar144 = FileIo_ReadStream(&DAT_0068a65c,4);
  uVar145 = FileIo_ReadStream(&DAT_006ff684,4);
  uVar146 = FileIo_ReadStream(&DAT_006b2d24,4);
  uVar147 = FileIo_ReadStream(&DAT_006fd3f0,4);
  uVar148 = FileIo_ReadStream(&DAT_006ff380,4);
  uVar149 = FileIo_ReadStream(&DAT_0052eff8,4);
  uVar150 = FileIo_ReadStream(&DAT_0052effc,4);
  uVar151 = FileIo_ReadStream(&DAT_0052f000,4);
  uVar152 = FileIo_ReadStream(&DAT_0067f380,4);
  uVar153 = FileIo_ReadStream(&DAT_0067f388,4);
  uVar154 = FileIo_ReadStream(&DAT_0067f2d0,0xa0);
  uVar155 = FileIo_ReadStream(&DAT_0052eff0,4);
  uVar156 = FileIo_ReadStream(&DAT_0052eff4,4);
  uVar157 = FileIo_ReadStream(&DAT_0067f37c,4);
  uVar158 = FileIo_ReadStream(&DAT_0067bdf0,0x3200);
  uVar159 = FileIo_ReadStream(&DAT_0067f2c0,4);
  uVar160 = FileIo_ReadStream(&DAT_00522450,4);
  uVar161 = FileIo_ReadStream(&DAT_0067b9a0,4);
  uVar162 = FileIo_ReadStream(&DAT_0067f3bc,4);
  uVar163 = FileIo_ReadStream(&DAT_0067bddc,4);
  uVar164 = FileIo_ReadStream(&DAT_0067bdc0,0x14);
  uVar165 = FileIo_ReadStream(&Gold,4);
  uVar166 = FileIo_ReadStream(&DAT_00522448,4);
  uVar167 = FileIo_ReadStream(&DAT_0067b9b0,1000);
  uVar168 = FileIo_ReadStream(&DAT_0067f374,4);
  uVar169 = FileIo_ReadStream(&Scards,0xc0);
  uVar170 = FileIo_ReadStream(&DAT_0067bdb4,4);
  uVar171 = FileIo_ReadStream(&DAT_0067eff0,0x2d0);
  uVar172 = FileIo_ReadStream(&DAT_0052f004,4);
  uVar173 = FileIo_ReadStream(&DAT_0067f384,4);
  uVar174 = FileIo_ReadStream(&DAT_00641020,4);
  uVar175 = FileIo_ReadStream(&DAT_006ff678,4);
  uVar176 = FileIo_ReadStream(&DAT_006410d8,4);
  uVar177 = FileIo_ReadStream(&DAT_00627a7c,4);
  uVar178 = FileIo_ReadStream(&DAT_00522454,4);
  uVar179 = FileIo_ReadStream(&_currentDeck,4);
  uVar180 = FileIo_ReadStream(&DAT_0067a9a0,0x1000);
  uVar181 = FileIo_ReadStream(&DAT_0067bde0,4);
  uVar182 = FileIo_ReadStream(&DAT_006fe448,4);
  uVar183 = FileIo_ReadStream(&DAT_006fe44c,4);
  uVar184 = FileIo_ReadStream(&DAT_006a3f60,4);
  uVar185 = FileIo_ReadStream(&DAT_006fe490,4);
  uVar186 = FileIo_ReadStream(&DAT_006a4930,4);
  uVar187 = FileIo_ReadStream(s_Ned_Way_the_Ratiocinator_0052f020,0x40);
  strcpy(&DAT_0068a6a0,s_Ned_Way_the_Ratiocinator_0052f020);
  uVar188 = FileIo_ReadStream(&DAT_006410b0,4);
  return uVar1 & 1 & uVar2 & uVar3 & uVar4 & uVar5 & uVar6 & uVar7 & uVar8 & uVar9 & uVar10 & uVar11
         & uVar12 & uVar13 & uVar14 & uVar15 & uVar16 & uVar17 & uVar18 & uVar19 & uVar20 & uVar21 &
         uVar22 & uVar23 & uVar24 & uVar25 & uVar26 & uVar27 & uVar28 & uVar29 & uVar30 & uVar31 &
         uVar32 & uVar33 & uVar34 & uVar35 & uVar36 & uVar37 & uVar38 & uVar39 & uVar40 & uVar41 &
         uVar42 & uVar43 & uVar44 & uVar45 & uVar46 & uVar47 & uVar48 & uVar49 & uVar50 & uVar51 &
         uVar52 & uVar53 & uVar54 & uVar55 & uVar56 & uVar57 & uVar58 & uVar59 & uVar60 & uVar61 &
         uVar62 & uVar63 & uVar64 & uVar65 & uVar66 & uVar67 & uVar68 & uVar69 & uVar70 & uVar71 &
         uVar72 & uVar73 & uVar74 & uVar75 & uVar76 & uVar77 & uVar78 & uVar79 & uVar80 & uVar81 &
         uVar82 & uVar83 & uVar84 & uVar85 & uVar86 & uVar87 & uVar88 & uVar89 & uVar90 & uVar91 &
         uVar92 & uVar93 & uVar94 & uVar95 & uVar96 & uVar97 & uVar98 & uVar99 & uVar100 & uVar101 &
         uVar102 & uVar103 & uVar104 & uVar105 & uVar106 & uVar107 & uVar108 & uVar109 & uVar110 &
         uVar111 & uVar112 & uVar113 & uVar114 & uVar115 & uVar116 & uVar117 & uVar118 & uVar119 &
         uVar120 & uVar121 & uVar122 & uVar123 & uVar124 & uVar125 & uVar126 & uVar127 & uVar128 &
         uVar129 & uVar130 & uVar131 & uVar132 & uVar133 & uVar134 & uVar135 & uVar136 & uVar137 &
         uVar138 & uVar139 & uVar140 & uVar141 & uVar142 & uVar143 & uVar144 & uVar145 & uVar146 &
         uVar147 & uVar148 & uVar149 & uVar150 & uVar151 & uVar152 & uVar153 & uVar154 & uVar155 &
         uVar156 & uVar157 & uVar158 & uVar159 & uVar160 & uVar161 & uVar162 & uVar163 & uVar164 &
         uVar165 & uVar166 & uVar167 & uVar168 & uVar169 & uVar170 & uVar171 & uVar172 & uVar173 &
         uVar174 & uVar175 & uVar176 & uVar177 & uVar178 & uVar179 & uVar180 & uVar181 & uVar182 &
         uVar183 & uVar184 & uVar185 & uVar186 & uVar187 & uVar188;
}

/*
 * Decompiled function: FileIo_ReadStream
 * Entry Point: 0048e01d
 * Size: 132 bytes
 */


uint FileIo_ReadStream(void *x,uint y)

{
  uint uVar1;
  uint local_8;
  
  if (DAT_0054aab0 == 0) {
    local_8 = FUN_0048caf4(DAT_0054aab8,x,y);
  }
  else {
    uVar1 = _read(DAT_0054aab8,x,y);
    local_8 = (uint)(uVar1 == y);
  }
  if (local_8 == 0) {
    OutputDebugStringA(&DAT_00527e88);
  }
  return local_8;
}

/*
 * Decompiled function: FUN_0048e0a1
 * Entry Point: 0048e0a1
 * Size: 77 bytes
 */


int FUN_0048e0a1(char *str_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  for (; *str_1 != '\0'; str_1 = str_1 + 1) {
    iVar1 = FUN_0050f390(*(int *)(g_DisplaySurfaceScreen + 0x20),*str_1);
    local_8 = local_8 + iVar1;
  }
  return local_8;
}

/*
 * Decompiled function: Mem_AllocOrFree_0048e0ee
 * Entry Point: 0048e0ee
 * Size: 26 bytes
 */


void Mem_AllocOrFree_0048e0ee(void)

{
  Save_ProcessGame_004207a8(1);
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0048e108
 * Entry Point: 0048e108
 * Size: 26 bytes
 */


void Mem_AllocOrFree_0048e108(void)

{
  Save_ProcessGame_004207a8(0);
  return;
}

/*
 * Decompiled function: FUN_0048e122
 * Entry Point: 0048e122
 * Size: 157 bytes
 */


void FUN_0048e122(char *str_1)

{
  DAT_0054aab8 = _open(str_1,0x8301,0x80);
  if (DAT_0054aab8 != -1) {
    DAT_0054aab0 = 0;
    FileIo_ReadStream(&DAT_00695e98,4);
    FUN_0048d259();
    FileIo_ReadStream(&_PlayerFace,4);
    FileIo_ReadStream(&_OpponFace,4);
    FileIo_ReadStream(&DAT_006ff310,0x32);
    FileIo_ReadStream(&DAT_0068a6a0,0x32);
    _close(DAT_0054aab8);
  }
  return;
}

/*
 * Decompiled function: FUN_0048e1bf
 * Entry Point: 0048e1bf
 * Size: 239 bytes
 */


uint FUN_0048e1bf(char *str_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_c;
  int local_8;
  
  DAT_0054aab8 = _open(str_1,0x8000);
  if (DAT_0054aab8 == -1) {
    local_c = 0;
  }
  else {
    DAT_0054aab0 = 1;
    uVar1 = FileIo_ReadStream(&local_8,4);
    if (local_8 == DAT_00695e98) {
      uVar2 = FUN_0048d259();
      uVar3 = FileIo_ReadStream(&_PlayerFace,4);
      uVar4 = FileIo_ReadStream(&_OpponFace,4);
      uVar5 = FileIo_ReadStream(&DAT_006ff310,0x32);
      DAT_006ff342 = 0;
      local_c = FileIo_ReadStream(&DAT_0068a6a0,0x32);
      local_c = uVar1 & 1 & uVar2 & uVar3 & uVar4 & uVar5 & local_c;
      DAT_0068a6d2 = 0;
    }
    else {
      local_c = 0;
    }
    _close(DAT_0054aab8);
  }
  return local_c;
}

/*
 * Decompiled function: FUN_0048e2b0
 * Entry Point: 0048e2b0
 * Size: 86 bytes
 */


void FUN_0048e2b0(int value)

{
  char cVar1;
  size_t sVar2;
  int local_10;
  
  local_10 = 0;
  sVar2 = strlen(&g_OverworldWorldState);
  do {
    cVar1 = (&PTR_s_Castle_Necris_00527f50)[value][local_10];
    (&g_OverworldWorldState)[local_10 + sVar2] = cVar1;
    local_10 = local_10 + 1;
  } while (cVar1 != '\0');
  return;
}

/*
 * Decompiled function: FUN_0048e306
 * Entry Point: 0048e306
 * Size: 1882 bytes
 */


void FUN_0048e306(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int y;
  int iVar5;
  uint uVar6;
  undefined4 value;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_10;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 0xf; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0067eff8 + local_8 * 0x30) = 0xffffffff;
    *(undefined4 *)(&DAT_0067eff4 + local_8 * 0x30) =
         *(undefined4 *)(&DAT_0067eff8 + local_8 * 0x30);
    *(undefined4 *)(&DAT_0067eff0 + local_8 * 0x30) =
         *(undefined4 *)(&DAT_0067eff4 + local_8 * 0x30);
    *(undefined4 *)(&DAT_0067f018 + local_8 * 0x30) = 0xffffffff;
    *(undefined4 *)(&DAT_0067f01c + local_8 * 0x30) =
         *(undefined4 *)(&DAT_0067f018 + local_8 * 0x30);
  }
  for (local_2c = 0; local_2c < g_MasterCardCount + -0x29; local_2c = local_2c + 1) {
    if (((&DAT_0051aed1)[local_2c * 0x34] & 1) != 0) {
      do {
        iVar4 = Math_RandomRange(10);
        iVar4 = iVar4 + 5;
      } while (*(int *)(&DAT_0067eff8 + iVar4 * 0x30) != -1);
      if (*(int *)(&DAT_0067eff0 + iVar4 * 0x30) == -1) {
        *(int *)(&DAT_0067eff0 + iVar4 * 0x30) = local_2c;
      }
      else if (*(int *)(&DAT_0067eff4 + iVar4 * 0x30) == -1) {
        *(int *)(&DAT_0067eff4 + iVar4 * 0x30) = local_2c;
      }
      else {
        *(int *)(&DAT_0067eff8 + iVar4 * 0x30) = local_2c;
      }
    }
  }
  local_8 = 0;
  do {
    if (0xe < local_8) {
      return;
    }
    do {
      do {
        do {
          iVar4 = Math_RandomRange(0x40);
          y = Math_RandomRange(0x40);
          iVar5 = Surface_GetPixelColor(iVar4,y);
        } while (iVar5 == 0);
        uVar6 = FUN_0040c7c0(iVar4,y);
      } while ((uVar6 & 0x30) != 0);
      local_28 = 0xff;
      for (local_20 = 0; local_20 < 0x80; local_20 = local_20 + 1) {
        if ((local_8 < 5) && (*(int *)(&DAT_0067bdf0 + local_20 * 100) == 4)) {
          value = Surface_GetPixelColor(*(int *)(&DAT_0067bdf4 + local_20 * 100),
                               *(int *)(&DAT_0067bdf8 + local_20 * 100));
          iVar5 = Glue_Subsystem_004ea7a6(value);
          if (iVar5 == 1 << ((char)local_8 + 1U & 0x1f)) {
            local_10 = local_20;
          }
        }
        if (((1 < *(int *)(&DAT_0067bdf0 + local_20 * 100)) &&
            (*(int *)(&DAT_0067bdf0 + local_20 * 100) != 4)) &&
           (iVar5 = FUN_0040a36f(*(int *)(&DAT_0067bdf4 + local_20 * 100) - iVar4,
                                 *(int *)(&DAT_0067bdf8 + local_20 * 100) - y), iVar5 < local_28)
           ) {
          local_24 = local_20;
          local_28 = iVar5;
        }
      }
      for (local_20 = 0; local_20 < local_8; local_20 = local_20 + 1) {
        iVar5 = FUN_0040a36f(*(int *)(&DAT_0067f000 + local_20 * 0x30) - iVar4,
                             *(int *)(&DAT_0067f004 + local_20 * 0x30) - y);
        if (iVar5 < local_28) {
          local_28 = iVar5;
        }
      }
    } while (local_28 < 4);
    FUN_0040c81c(0x40,iVar4,y);
    *(int *)(&DAT_0067f000 + local_8 * 0x30) = iVar4;
    *(int *)(&DAT_0067f004 + local_8 * 0x30) = y;
    *(int *)(&DAT_0067f008 + local_8 * 0x30) = local_24;
    cVar3 = Math_RandomRange(5);
    (&DAT_0067f00c)[local_8 * 0x30] = cVar3 + '\x01';
    (&DAT_0067f00d)[local_8 * 0x30] = 2;
    if (local_8 < 5) {
      (&DAT_0067f00c)[local_8 * 0x30] = (char)local_8 + '\x01';
      (&DAT_0067f00d)[local_8 * 0x30] = 0x81;
      *(undefined4 *)(&DAT_0067f000 + local_8 * 0x30) =
           *(undefined4 *)(&DAT_0067bdf4 + local_10 * 100);
      *(undefined4 *)(&DAT_0067f004 + local_8 * 0x30) =
           *(undefined4 *)(&DAT_0067bdf8 + local_10 * 100);
    }
    bVar1 = (&DAT_0067f00d)[local_8 * 0x30];
    iVar4 = Math_RandomRange(2);
    if (iVar4 + 1 < (int)(uint)bVar1) {
      local_c = 0;
      for (local_20 = 0; local_20 < (int)(uint)(byte)(&DAT_0067f00d)[local_8 * 0x30];
          local_20 = local_20 + 1) {
        local_c = local_c + local_20 * 2 + 4;
      }
    }
    else {
      if ((byte)(&DAT_0067f00d)[local_8 * 0x30] < 2) {
        local_c = 0x10;
      }
      else {
        local_c = 0x1c;
      }
      (&DAT_0067f00d)[local_8 * 0x30] = (&DAT_0067f00d)[local_8 * 0x30] | 0x80;
    }
    if (*(int *)(&DAT_0067eff4 + local_8 * 0x30) == -1) {
      local_c = (local_c * 3) / 2;
    }
    if (*(int *)(&DAT_0067eff8 + local_8 * 0x30) != -1) {
      local_c = (local_c * 2) / 3;
    }
    bVar1 = (&DAT_0067f00d)[local_8 * 0x30];
    bVar2 = (&DAT_0067f00d)[local_8 * 0x30];
    iVar4 = Math_RandomRange(2);
    *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) =
         *(undefined4 *)
          (&DAT_00527e9c + ((((bVar1 & 0xc0) == 0) - 1 & 4) + (bVar2 & 0x7f) + iVar4) * 4);
    *(undefined4 *)(&DAT_0067f014 + local_8 * 0x30) = 1;
    switch((int)(local_c + (local_c >> 0x1f & 3U)) >> 2) {
    case 0:
    case 1:
    case 2:
      (&DAT_0067f00d)[local_8 * 0x30] = (&DAT_0067f00d)[local_8 * 0x30] + '\x01';
    case 3:
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) =
           *(undefined4 *)(&DAT_00527e8c + (char)(&DAT_0067f00c)[local_8 * 0x30] * 4);
      cVar3 = Math_RandomRange(5);
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) =
           *(uint *)(&DAT_0067f014 + local_8 * 0x30) | 1 << (cVar3 + 4U & 0x1f);
      break;
    case 4:
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) =
           *(undefined4 *)(&DAT_00527e8c + (char)(&DAT_0067f00c)[local_8 * 0x30] * 4);
      break;
    case 5:
      cVar3 = Math_RandomRange(5);
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) =
           *(uint *)(&DAT_0067f014 + local_8 * 0x30) | 1 << (cVar3 + 4U & 0x1f);
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) = 0xffffffff;
      break;
    case 6:
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) = 0xffffffff;
    }
    if ((((&DAT_0067f015)[local_8 * 0x30] & 1) != 0) ||
       ((((&DAT_0067f00d)[local_8 * 0x30] & 0x3f) < 2 &&
        (((&DAT_0067f014)[local_8 * 0x30] & 0x20) != 0)))) {
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) =
           *(undefined4 *)(&DAT_00527e8c + (char)(&DAT_0067f00c)[local_8 * 0x30] * 4);
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) =
           *(uint *)(&DAT_0067f014 + local_8 * 0x30) & 0xfffffedf;
    }
    if (((&DAT_0067f00d)[local_8 * 0x30] & 0x7f) == 1) {
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) =
           *(uint *)(&DAT_0067f014 + local_8 * 0x30) & 0xfffffffe;
    }
    if (local_8 < 5) {
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) = *(uint *)(&DAT_0067f014 + local_8 * 0x30) | 1;
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) = *(uint *)(&DAT_0067f014 + local_8 * 0x30) | 2;
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) =
           *(undefined4 *)(&DAT_00527ec0 + DAT_0067f380 * 4 + local_8 * 0x10);
    }
    local_8 = local_8 + 1;
  } while( true );
}

/*
 * Decompiled function: FUN_0048ea81
 * Entry Point: 0048ea81
 * Size: 91 bytes
 */


void FUN_0048ea81(int value)

{
  byte bVar1;
  
  do {
    bVar1 = Math_RandomRange(3);
  } while ((*(uint *)(&DAT_0067f010 + value * 0x30) & 1 << (bVar1 & 0x1f)) != 0);
  *(uint *)(&DAT_0067f010 + value * 0x30) =
       *(uint *)(&DAT_0067f010 + value * 0x30) | 1 << (bVar1 & 0x1f);
  Castle_Process_00492ddf(value);
  return;
}

/*
 * Decompiled function: FUN_0048eadc
 * Entry Point: 0048eadc
 * Size: 396 bytes
 */


undefined4 FUN_0048eadc(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    if (y == 2) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,1,1,*(int *)(x + 0x18) + -2,
                        *(int *)(x + 0x1c) + -2,iRam00676b98);
      Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,*(int *)(x + 0x18) + 1,
                   *(int *)(x + 0x1c) + 1,(int *)g_DisplaySurfaceScreen,*(int *)(x + 0x10),
                   *(int *)(x + 0x14));
      if (*(int *)(x + 0x28) != 0) {
        (**(code **)(x + 0x28))(x);
      }
    }
    else {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(x + 0x10),*(int *)(x + 0x14),
                        *(int *)(x + 0x18),*(int *)(x + 0x1c),(&DAT_00676b90)[y]);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0048ec9a
 * Entry Point: 0048ec9a
 * Size: 106 bytes
 */


int FUN_0048ec9a(int x,int y)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xe < local_8) {
      return -1;
    }
    if ((*(int *)(&DAT_0067f000 + local_8 * 0x30) == x) &&
       (*(int *)(&DAT_0067f004 + local_8 * 0x30) == y)) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

/*
 * Decompiled function: FUN_0048ed04
 * Entry Point: 0048ed04
 * Size: 231 bytes
 */


void FUN_0048ed04(int value,uint *min_val,int *max_val)

{
  short sVar1;
  byte *pbVar2;
  uint uVar3;
  int local_20;
  uint local_18;
  byte *local_10;
  
  *min_val = 0x7fffffff;
  *max_val = 0;
  if (value != 0) {
    sVar1 = *(short *)(value + 0xe);
    local_10 = (byte *)(value + 0x10);
    for (local_20 = 0; local_20 < sVar1; local_20 = local_20 + 1) {
      uVar3 = (uint)*local_10;
      pbVar2 = local_10 + 1;
      if (uVar3 != 0xff) {
        local_18 = (uint)local_10[1];
        pbVar2 = local_10 + 2;
        if (local_18 == 0xfe) {
          local_18 = (uint)local_10[2];
          pbVar2 = local_10 + 3;
        }
        local_10 = pbVar2;
        if ((int)uVar3 < (int)*min_val) {
          *min_val = uVar3;
        }
        if (*max_val < (int)(local_18 + uVar3)) {
          *max_val = local_18 + uVar3;
        }
        pbVar2 = local_10 + local_18;
      }
      local_10 = pbVar2;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0048edeb
 * Entry Point: 0048edeb
 * Size: 82 bytes
 */


undefined4 FUN_0048edeb(int value,int min_val,int max_val,int target_slot,int flags,int arg_6)

{
  undefined4 uVar1;
  
  if ((((max_val < value) && (value < flags + max_val)) && (target_slot < min_val)) && (min_val < arg_6 + target_slot))
  {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0048ee42
 * Entry Point: 0048ee42
 * Size: 389 bytes
 */


undefined4 FUN_0048ee42(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *in_stack_00000018;
  int local_30;
  int local_2c;
  uint local_24;
  int local_20;
  uint local_1c [4];
  int local_c;
  int local_8;
  
  local_c = *in_stack_00000018;
  local_2c = in_stack_00000018[1];
  if (local_c == 0) {
    uVar1 = 0;
  }
  else {
    Surface_FillRect((int *)g_DisplaySurfaceWork,0,0x80,*(short *)(local_c + 4) + 1,
                     *(short *)(local_c + 6) + 1,0);
    Sprite_DrawDirect((int *)g_DisplaySurfaceWork,0,0x80,*in_stack_00000018);
    Sprite_DrawDirect((int *)g_DisplaySurfaceWork,0,0x80,in_stack_00000018[1]);
    FUN_0048ed04(*in_stack_00000018,local_1c,&local_30);
    FUN_0048ed04(in_stack_00000018[1],&local_24,&local_8);
    if ((int)local_1c[0] <= (int)local_24) {
      local_24 = local_1c[0];
    }
    if (local_8 <= local_30) {
      local_8 = local_30;
    }
    local_30 = local_8;
    if (0xfa < (int)(local_8 - local_24)) {
      local_30 = local_24 + 0xfa;
    }
    local_20 = (int)*(short *)(local_2c + 0xc);
    if ((int)*(short *)(local_c + 0xc) <= (int)*(short *)(local_2c + 0xc)) {
      local_20 = (int)*(short *)(local_c + 0xc);
    }
    iVar2 = (int)*(short *)(local_2c + 0xc) + (int)*(short *)(local_2c + 0xe);
    iVar3 = (int)*(short *)(local_c + 0xc) + (int)*(short *)(local_c + 0xe);
    if (iVar2 <= iVar3) {
      iVar2 = iVar3;
    }
    uVar1 = Sprite_EncodeFromSurface
                      (*(int *)g_DisplaySurfaceWork,local_24,local_20 + 0x80,
                       (local_30 - local_24) + 1,(iVar2 - local_20) + 1);
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0048efc7
 * Entry Point: 0048efc7
 * Size: 231 bytes
 */


undefined4 FUN_0048efc7(int *value,int min_val,int max_val,int target_slot,int flags,int arg_6)

{
  int iVar1;
  
  if (arg_6 != 0) {
    if ((flags << 8) / (int)*(short *)(arg_6 + 6) < (target_slot << 8) / (int)*(short *)(arg_6 + 4)) {
      iVar1 = (*(short *)(arg_6 + 4) * flags) / (int)*(short *)(arg_6 + 6);
      Sprite_DrawScaled(value,min_val + (target_slot - iVar1) / 2,max_val,iVar1,flags,arg_6);
    }
    else {
      iVar1 = (*(short *)(arg_6 + 6) * target_slot) / (int)*(short *)(arg_6 + 4);
      Sprite_DrawScaled(value,min_val,max_val + (flags - iVar1) / 2,target_slot,iVar1,arg_6);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_0048f0ae
 * Entry Point: 0048f0ae
 * Size: 374 bytes
 */


int FUN_0048f0ae(int *value,int min_val,int max_val,int target_slot,int flags,int arg_6)

{
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = arg_6;
  if (arg_6 == 0) {
    local_1c = 0;
  }
  else {
    Surface_FillRect((int *)g_DisplaySurfaceWork,0,0x80,(int)*(short *)(arg_6 + 4),
                     (int)*(short *)(arg_6 + 6),0);
    Sprite_DrawDirect((int *)g_DisplaySurfaceWork,0,0x80,arg_6);
    FUN_0048ed04(arg_6,&local_18,&local_20);
    local_1c = Sprite_EncodeFromSurface
                         (*(int *)g_DisplaySurfaceWork,local_18,*(short *)(local_8 + 0xc) + 0x80,
                          (local_20 - local_18) + 1,(int)*(short *)(local_8 + 0xe));
    local_14 = local_1c;
    if ((flags << 8) / (int)*(short *)(local_1c + 6) < (target_slot << 8) / (int)*(short *)(local_1c + 4))
    {
      local_c = (*(short *)(local_1c + 4) * flags) / (int)*(short *)(local_1c + 6);
      Sprite_DrawScaled(value,min_val + (target_slot - local_c) / 2,max_val,local_c,flags,local_1c);
    }
    else {
      local_10 = (*(short *)(local_1c + 6) * target_slot) / (int)*(short *)(local_1c + 4);
      Sprite_DrawScaled(value,min_val,max_val + (flags - local_10) / 2,target_slot,local_10,local_1c);
    }
  }
  return local_1c;
}

/*
 * Decompiled function: FUN_0048f224
 * Entry Point: 0048f224
 * Size: 287 bytes
 */


undefined4 FUN_0048f224(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(x + 0x10),*(int *)(x + 0x14),
                      *(int *)(x + 0x18),*(int *)(x + 0x1c),
                      *(int *)(&DAT_00676ba0 + y * 4 + *(int *)(x + 0x30) * 0x10));
    if ((y == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0048f375
 * Entry Point: 0048f375
 * Size: 430 bytes
 */


undefined4 FUN_0048f375(int *value,int min_val,int max_val)

{
  undefined4 uVar1;
  int local_20;
  int local_1c;
  int local_8;
  
  if (value[0x10] == 0) {
    local_20 = value[6] + value[0xe] / 2;
    local_8 = value[8] - value[0xe] / 2;
  }
  else {
    local_20 = value[7] + value[0xf] / 2;
    local_8 = value[9] - value[0xf] / 2;
  }
  if ((min_val < local_20) || (local_8 < min_val)) {
    uVar1 = 0xffffffff;
  }
  else {
    value[0x13] = min_val;
    for (local_1c = 0; local_1c < value[5]; local_1c = local_1c + 1) {
      Surface_PutLine((undefined4 *)(value[4] * local_1c + value[0xd]),*(int *)*value,value[4],
                      value[2],value[3]);
    }
    Sprite_DrawScaled((int *)*value,value[2] - value[0xe] / 2,value[3] - value[0xf] / 2,value[0xe],
                      value[0xf],value[max_val + 10]);
    if (*value != value[1]) {
      Surface_BlitToDevice((int *)*value,value[2],value[3],value[4],value[5],(int *)value[1],value[6],
                   value[7]);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_0049094c
 * Entry Point: 0049094c
 * Size: 84 bytes
 */


int FUN_0049094c(void)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 1;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    if ((DAT_0067bdb4 & 1 << ((byte)local_8 & 0x1f)) != 0) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}

/*
 * Decompiled function: FUN_004909a0
 * Entry Point: 004909a0
 * Size: 51 bytes
 */


void FUN_004909a0(int value)

{
  Palette_Subsystem_004a2ef0(value);
  DAT_006b2fe0 = 0xffffffff;
  DAT_0068a64c = 0xffffffff;
  return;
}

/*
 * Decompiled function: FUN_004909d3
 * Entry Point: 004909d3
 * Size: 271 bytes
 */


void FUN_004909d3(int x,undefined4 min_val,uint width,int height)

{
  char *str_2;
  int iVar1;
  
  strcpy(&g_OverworldWorldState,s_decks_0_00528600);
  if (*(int *)(&DAT_0052262c + x * 0x44) < 100) {
    strcat(&g_OverworldWorldState,&DAT_00528608);
    if (*(int *)(&DAT_0052262c + x * 0x44) < 10) {
      strcat(&g_OverworldWorldState,&DAT_0052860c);
    }
  }
  str_2 = _itoa(*(int *)(&DAT_0052262c + x * 0x44),&DAT_0054aae8,10);
  strcat(&g_OverworldWorldState,str_2);
  strcat(&g_OverworldWorldState,&DAT_00528610);
  iVar1 = FUN_00406b01(&g_OverworldWorldState);
  if (iVar1 == 0) {
    FUN_00409f99(s_decks_0179_dck_00528618,1,width,height);
  }
  else {
    FUN_00409f99(&g_OverworldWorldState,1,width,height);
  }
  DAT_0052eff8 = 1;
  return;
}

/*
 * Decompiled function: FUN_00490ae2
 * Entry Point: 00490ae2
 * Size: 287 bytes
 */


undefined4 FUN_00490ae2(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x1c) + *(int *)(x + 0x14) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(x + 0x10),*(int *)(x + 0x14),
                      *(int *)(x + 0x18),*(int *)(x + 0x1c),
                      (&DAT_00676c40)[*(int *)(x + 0x30) * 4 + y]);
    if ((y == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_00490c33
 * Entry Point: 00490c33
 * Size: 278 bytes
 */


undefined4 FUN_00490c33(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(x + 0x10),*(int *)(x + 0x14),
                      *(int *)(x + 0x18),*(int *)(x + 0x1c),*(int *)(&DAT_00676be0 + y * 4)
                     );
    if ((y == 2) && (*(int *)(x + 0x28) != 0)) {
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_004922dc
 * Entry Point: 004922dc
 * Size: 194 bytes
 */


int FUN_004922dc(void)

{
  int local_10;
  int local_8;
  
  local_10 = -DAT_006410b4;
  for (local_8 = 0; local_8 < 0x80; local_8 = local_8 + 1) {
    if ((&DAT_0067be01)[local_8 * 100] != '\0') {
      local_10 = local_10 + -2;
    }
  }
  local_10 = local_10 * 3;
  for (local_8 = 0; local_8 < 1000; local_8 = local_8 + 1) {
    if ((&DAT_0067b9b0)[local_8] != '\0') {
      local_10 = local_10 + ((int)(char)(&DAT_0067b9b0)[local_8] & 0xfU) + 2;
      if (((int)(char)(&DAT_0067b9b0)[local_8] & 0xfU) == 0xc) {
        local_10 = local_10 + 0x19;
      }
    }
  }
  return local_10 << 1;
}

/*
 * Decompiled function: FUN_00492cb1
 * Entry Point: 00492cb1
 * Size: 302 bytes
 */


int FUN_00492cb1(int x,int y)

{
  int iVar1;
  int iVar2;
  int y;
  ushort local_3f4 [2];
  char local_3f0 [1000];
  int local_8;
  
  iVar1 = FUN_0050f440((int *)g_DisplaySurfaceScreen,(char *)&g_OverworldWorldState);
  iVar2 = Ai_Util_004c3bc4(0xbe);
  if (iVar2 < iVar1) {
    local_8 = FUN_0050f390(4,(char)local_3f4[0]);
    local_3f4[0] = (ushort)g_OverworldWorldState;
    iVar1 = x;
    iVar2 = y;
    y = Ai_Util_004c3ba3(0x10);
    FUN_0040c1ad(local_3f4,y,iVar1,iVar2);
    iVar1 = Ai_Util_004c3bc4(0xbe);
    FUN_00407843(&DAT_00626851,local_3f0,iVar1 - local_8);
    iVar1 = x;
    iVar2 = Ai_Util_004c3ba3(0x10);
    FUN_0040d1cd((int)g_DisplaySurfaceScreen,y,local_8 + iVar2,iVar1);
    iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    iVar1 = iVar1 * 2;
  }
  else {
    iVar1 = x;
    iVar2 = Ai_Util_004c3ba3(0x10);
    FUN_0040c1ad(&g_OverworldWorldState,iVar2,iVar1,y);
    iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  }
  x = x + iVar1;
  return x;
}

/*
 * Decompiled function: FUN_00505c74
 * Entry Point: 00505c74
 * Size: 172 bytes
 */


undefined4 FUN_00505c74(void)

{
  if ((DAT_00627a88 != -1) && (g_IsAiThinking != 1)) {
    if ((g_ScWillyScore < DAT_00627a88) || (DAT_00627a84 != g_TurnPlayer)) {
      return 1;
    }
    if ((g_CurrentStepCode != -1) && (g_ScWillyScore == DAT_00627a88)) {
      return 1;
    }
    if ((DAT_00627a88 < g_ScWillyScore) && (DAT_00627a84 == g_TurnPlayer)) {
      DAT_00627a88 = -1;
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00505d20
 * Entry Point: 00505d20
 * Size: 287 bytes
 */


bool FUN_00505d20(int value)

{
  int iVar1;
  bool bVar2;
  int local_c;
  
  if (g_IsAiThinking == 1) {
    bVar2 = false;
  }
  else if (DAT_0063ee1c == 0) {
    iVar1 = Pic_Subsystem_0044724d();
    if (iVar1 == 0) {
      bVar2 = false;
    }
    else if (DAT_00627860 == 0) {
      bVar2 = false;
    }
    else {
      if ((value < 2) || (5 < value)) {
        if ((value < 0x20) || (0x25 < value)) {
          if ((value < 2) || (5 < value)) {
            local_c = value;
          }
          else {
            local_c = 4;
          }
        }
        else {
          local_c = 0x20;
        }
      }
      else {
        local_c = 4;
      }
      bVar2 = DAT_00627a88 == local_c;
      if ((DAT_00627a88 == -1) &&
         (((&DAT_00696740)[local_c * 4 + g_TurnPlayer * 0x98] & 1) != 0)) {
        bVar2 = true;
      }
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}

/*
 * Decompiled function: FUN_00505e3f
 * Entry Point: 00505e3f
 * Size: 104 bytes
 */


undefined4 FUN_00505e3f(int value)

{
  undefined4 uVar1;
  
  if (*(int *)(&DAT_00696740 + value * 4 + g_TurnPlayer * 0x98) == 0) {
    if ((DAT_00627a88 == value) && (DAT_00627a84 == g_TurnPlayer)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/*
 * Decompiled function: FUN_00505ea7
 * Entry Point: 00505ea7
 * Size: 386 bytes
 */


void FUN_00505ea7(int value)

{
  bool bVar1;
  
  if ((DAT_00627a88 == value) && (DAT_00627a84 == g_TurnPlayer)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((g_IsAiThinking != 1) &&
     (((*(uint *)(&DAT_00696740 + value * 4 + g_TurnPlayer * 0x98) & 1) != 0 || (bVar1)))) {
    strcpy(&g_OverworldWorldState,s_Paused_005314e8);
    if (value == 4) {
      strcat(&g_OverworldWorldState,s___Upkeep_phase_005314f0);
    }
    if (value == 1) {
      strcat(&g_OverworldWorldState,s___Untap_phase_00531500);
    }
    if (value == 10) {
      strcat(&g_OverworldWorldState,s___Draw_phase_00531510);
    }
    if (value == 0x14) {
      strcat(&g_OverworldWorldState,s___Main_phase_00531520);
    }
    if (value == 0x1f) {
      strcat(&g_OverworldWorldState,s___Discard_phase_00531530);
    }
    if (value == 0x22) {
      strcat(&g_OverworldWorldState,s___Cleanup_phase_00531540);
    }
    if (value == 0x19) {
      strcat(&g_OverworldWorldState,s___First_strike_damage_resolution_00531550);
    }
    if (value == 0x1a) {
      strcat(&g_OverworldWorldState,s___Combat_damage_resolution_00531574);
    }
    FUN_00506029(&g_OverworldWorldState);
  }
  return;
}

/*
 * Decompiled function: FUN_00506029
 * Entry Point: 00506029
 * Size: 207 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00506029(char *str_1)

{
  bool bVar1;
  int y;
  int iVar2;
  
  bVar1 = false;
  while (!bVar1) {
    y = Glue_Subsystem_004efd50
                     (g_CurrentTurnPhase,g_CurrentTurnPhase,g_CurrentTurnPhase,0xff,0,str_1,2);
    if (DAT_0063ee8c != -3) {
      if (DAT_0063ee8c == -2) {
        bVar1 = true;
      }
      else if (((DAT_0063ee8c == 0) && (y != -1)) &&
              (iVar2 = FUN_005063f6(_DAT_0063ee20,y), iVar2 != 0)) {
        FUN_005064e9(_DAT_0063ee20,y);
      }
    }
  }
  return;
}

/*
 * Decompiled function: FUN_00506102
 * Entry Point: 00506102
 * Size: 431 bytes
 */


void FUN_00506102(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  while (*(int *)(&DAT_0063eeac + g_ActivePlayerPriority * 0x20) != 0) {
    local_c = 0;
    while( true ) {
      if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <= local_c) goto LAB_005061ff;
      if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1)
          && (((byte)*(undefined4 *)
                      (&g_CardSlot_Flags + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) & 0x22
              ) == 2)) &&
         (Magic_TriggerCardEvent
                    (g_ActivePlayerPriority,local_c,0x8f,1 - g_ActivePlayerPriority,0xffffffff),
         DAT_006b2e38 != 0)) break;
      local_c = local_c + 1;
    }
    iVar1 = FUN_0047103b(g_ActivePlayerPriority,local_c);
    if (iVar1 != 0) {
      FUN_00471971(g_ActivePlayerPriority,local_c);
    }
  }
LAB_005061ff:
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    if (0 < *(int *)(&DAT_0063eeac + local_8 * 0x20)) {
      if (g_IsAiThinking != 1) {
        Duel_PlaySoundById(0x20);
        Ai_Subsystem_004b784d(local_8,*(undefined4 *)(&DAT_0063eeac + local_8 * 0x20));
      }
      (&g_PlayerCreatureCount)[local_8] =
           (&g_PlayerCreatureCount)[local_8] - *(int *)(&DAT_0063eeac + local_8 * 0x20);
      for (local_c = 0; local_c < 8; local_c = local_c + 1) {
        *(undefined4 *)(&DAT_0063ee90 + local_c * 4 + local_8 * 0x20) = 0;
      }
    }
  }
  return;
}

/*
 * Decompiled function: FUN_005062b1
 * Entry Point: 005062b1
 * Size: 220 bytes
 */


undefined4 FUN_005062b1(void)

{
  bool bVar1;
  undefined4 local_8;
  
  if ((g_PlayerCreatureCount < 1) || (DAT_006a4a04 < 1)) {
    bVar1 = true;
  }
  else if ((DAT_00696870 < 10) && (DAT_00696874 < 10)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if (g_IsAiThinking == 1) {
      if (9 < DAT_00696870) {
        g_PlayerCreatureCount = 0;
      }
      if (9 < DAT_00696874) {
        DAT_006a4a04 = 0;
      }
      local_8 = 0;
    }
    else {
      Ai_Subsystem_004cc9c5(0,0xff);
      local_8 = 1;
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

/*
 * Decompiled function: FUN_0050638d
 * Entry Point: 0050638d
 * Size: 105 bytes
 */


undefined4 FUN_0050638d(int x,int y,int width,int height)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < y; local_c = local_c + 1) {
    if ((*(int *)(x + local_c * 8) == width) && (*(int *)(x + 4 + local_c * 8) == height)) {
      local_8 = 1;
    }
  }
  return local_8;
}

/*
 * Decompiled function: FUN_005063f6
 * Entry Point: 005063f6
 * Size: 238 bytes
 */


undefined4 FUN_005063f6(int x,int y)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Card_IsTapped(x,y);
  if ((((iVar1 == 0) ||
       (((&DAT_0051aed1)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] & 0x10)
        == 0)) || (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) != 0)) ||
     ((((&DAT_006a5f3e)[y * 0x120 + x * 0x5b20] & 3) != 0 &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] & 2) != 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_005064e9
 * Entry Point: 005064e9
 * Size: 139 bytes
 */


undefined4 FUN_005064e9(int x,int y)

{
  DAT_006ff4ac = 1;
  DAT_006ff2d4 = 0xffffffff;
  Magic_TriggerCardEvent(x,y,0x6d,1 - x,0xffffffff);
  if (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x10) != 0) {
    Magic_BroadcastCardEvent(x,y,0x81);
  }
  DAT_006ff4ac = 0;
  return DAT_006ff2d4;
}

/*
 * Decompiled function: FUN_00507b44
 * Entry Point: 00507b44
 * Size: 322 bytes
 */


undefined4 FUN_00507b44(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    FUN_0050b65f(*(int *)(x + 0x10) + *(int *)(x + 0x18) / 2,
                 *(int *)(x + 0x14) + *(int *)(x + 0x1c) / 2,*(int *)(x + 0x2c) + -1,y,
                 &DAT_00626610 + *(int *)(x + 0x30) * 100);
    if ((y == 2) && (*(int *)(x + 0x28) != 0)) {
      Glue_Subsystem_004ebd62(0x12,100,100,0);
      (**(code **)(x + 0x28))(x);
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0050935e
 * Entry Point: 0050935e
 * Size: 441 bytes
 */


undefined4 FUN_0050935e(int x,int y)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint target_slot;
  int iVar4;
  uint min_val;
  int *local_c;
  
  iVar4 = DAT_0061e108;
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(x + 0x10)) ||
       (*(int *)(x + 0x18) + *(int *)(x + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(x + 0x14)) ||
            (*(int *)(x + 0x14) + *(int *)(x + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(x + 0x40) == 3) {
    uVar2 = 0;
  }
  else {
    if (y == 2) {
      local_c = (int *)g_DisplaySurfaceBackBuffer;
    }
    else {
      local_c = (int *)g_DisplaySurfaceScreen;
    }
    iVar3 = Ai_Util_004c3ba3((int)*(short *)(DAT_0061e108 + 4));
    target_slot = iVar3 / 2;
    iVar4 = Ai_Util_004c3ba3((int)*(short *)(iVar4 + 6));
    min_val = g_DisplayScreenWidth / 2 - (int)target_slot / 2;
    iVar3 = Ai_Util_004c3ba3(0x112);
    iVar3 = iVar3 / 2;
    Sprite_DrawScaled(local_c,min_val,iVar3,target_slot,iVar4 / 2,(&DAT_0061e108)[y]);
    if (y == 2) {
      Glue_Subsystem_004ebd62(0x12,100,100,0);
      Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,min_val,iVar3,target_slot,iVar4 / 2,
                   (int *)g_DisplaySurfaceScreen,min_val,iVar3);
      DAT_00626600 = 1;
    }
    uVar2 = 1;
  }
  return uVar2;
}

/*
 * Decompiled function: FUN_0050a2e0
 * Entry Point: 0050a2e0
 * Size: 241 bytes
 */


void FUN_0050a2e0(int value,int min_val,char *str_3)

{
  int flags;
  int target_slot;
  int max_val;
  int arg_2_00;
  char local_6c [100];
  undefined4 local_8;
  
  if (g_IsAiThinking != 1) {
    Pic_Subsystem_0044b8da();
    strcpy(local_6c,str_3);
    flags = Ai_Util_004c3ba3(0xdf);
    target_slot = Ai_Util_004c3ba3(0x95);
    max_val = Ai_Util_004c3ba3(0x34);
    arg_2_00 = Ai_Util_004c3ba3(0xdc);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2_00,max_val,target_slot,flags,min_val);
    FUN_0050b206(value,0x78,0x26,1,&DAT_005323e8);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    local_8 = FUN_0040c465(local_6c);
    FUN_0040c3cc(local_6c,g_DisplayScreenWidth / 2,0x48,0);
    FUN_0040c3cc(local_6c,g_DisplayScreenWidth / 2,0x47,0xff);
    Pic_Subsystem_0044b8aa();
  }
  return;
}

/*
 * Decompiled function: FUN_0050a73e
 * Entry Point: 0050a73e
 * Size: 331 bytes
 */


undefined1 * FUN_0050a73e(int value)

{
  int arg_1_00;
  char *str_2;
  
  if ((&DAT_0067bdfc)[value * 100] == '\0') {
    strcat(&g_OverworldWorldState,&DAT_00532468);
  }
  else {
    arg_1_00 = Card_ColorMaskToColorIndex((byte)*(undefined4 *)(&DAT_0067bdfc + value * 100));
    str_2 = (char *)Mem_AllocOrFree_00473d7e(arg_1_00);
    strcat(&g_OverworldWorldState,str_2);
  }
  switch(*(int *)(&DAT_0067bdfc + value * 100) >> 8) {
  case 0:
    strcat(&g_OverworldWorldState,s_cards_0053246c);
    break;
  case 1:
    strcat(&g_OverworldWorldState,s_land_00532474);
    break;
  case 2:
    strcat(&g_OverworldWorldState,s_creatures_0053247c);
    break;
  case 3:
    strcat(&g_OverworldWorldState,s_enchantments_00532488);
    break;
  case 4:
    strcat(&g_OverworldWorldState,s_sorceries_00532498);
    break;
  case 5:
    strcat(&g_OverworldWorldState,s_fast_effects_005324a4);
    break;
  case 7:
    strcat(&g_OverworldWorldState,s_artifacts_005324b4);
  }
  return &g_OverworldWorldState;
}

/*
 * Decompiled function: FUN_0050a9bf
 * Entry Point: 0050a9bf
 * Size: 1228 bytes
 */


int FUN_0050a9bf(int value)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0x28;
  switch((&g_MasterCardColorTable)[value * 0x34]) {
  case 2:
  case 0x42:
    if ((*(ushort *)(&DAT_0051aec2 + value * 0x34) & 0xbfff) == 0xfffe) {
      local_10 = (int)*(short *)(&DAT_0051aec2 + value * 0x34);
    }
    else {
      local_10 = ((int)*(short *)(&DAT_0051aec2 + value * 0x34) & 0xffffbfffU) + 3;
    }
    if ((*(ushort *)(&DAT_0051aec4 + value * 0x34) & 0xbfff) == 0xfffe) {
      local_c = (int)*(short *)(&DAT_0051aec4 + value * 0x34);
    }
    else {
      local_c = ((int)*(short *)(&DAT_0051aec4 + value * 0x34) & 0xffffbfffU) + 3;
    }
    local_c = (*(int *)(&DAT_0051aed8 + value * 0x34) + local_10) * local_c;
    local_8 = local_c * 5;
    if (((&DAT_0051aecc)[value * 0x34] & 0x1f) != 0) {
      local_8 = (local_c * 0xf) / 2;
    }
    if (((&DAT_0051aecd)[value * 0x34] & 2) != 0) {
      local_8 = (local_8 * 3) / 2;
    }
    if (*(code **)(&DAT_0051aec8 + value * 0x34) != Glue_Util_004d0a30) {
      local_8 = (local_8 * 3) / 2;
    }
    if ((*(uint *)(&DAT_0051aecc + value * 0x34) & 0x1c0) != 0) {
      local_8 = (local_8 * 3) / 2;
    }
    if (((&DAT_0051aed0)[value * 0x34] & 8) != 0) {
      local_8 = local_8 * 3;
    }
    if (((&DAT_0051aed0)[value * 0x34] & 0x10) != 0) {
      local_8 = local_8 * 3;
    }
    iVar1 = abs((int)(char)(&DAT_0051aec0)[value * 0x34]);
    local_8 = local_8 / ((char)(&DAT_0051aebf)[value * 0x34] + iVar1 + 1);
    break;
  case 4:
    iVar1 = abs((int)(char)(&DAT_0051aec0)[value * 0x34]);
    iVar1 = (iVar1 + (char)(&DAT_0051aebf)[value * 0x34] + *(int *)(&DAT_0051aed8 + value * 0x34)) *
            5 + 5;
    local_8 = iVar1 * 5;
    if (((&DAT_0051aed0)[value * 0x34] & 3) != 0) {
      local_8 = iVar1 * 10;
    }
    break;
  case 8:
    iVar1 = abs((int)(char)(&DAT_0051aec0)[value * 0x34]);
    local_8 = ((iVar1 + (char)(&DAT_0051aebf)[value * 0x34] + *(int *)(&DAT_0051aed8 + value * 0x34)
               ) * 4 + 4) * 5;
    break;
  case 0x10:
  case 0x20:
    iVar1 = abs((int)(char)(&DAT_0051aec0)[value * 0x34]);
    local_8 = *(int *)(&DAT_0051aed8 + value * 0x34) * 0x14 +
              ((iVar1 + (char)(&DAT_0051aebf)[value * 0x34]) * 5 + 5) * 8;
    if ((&DAT_0051aec0)[value * 0x34] == -1) {
      local_8 = (local_8 * 3) / 2;
    }
    break;
  case 0x40:
    iVar1 = abs((int)(char)(&DAT_0051aec0)[value * 0x34]);
    local_8 = (int)(0xfa / (longlong)(*(int *)(&DAT_0051aed8 + value * 0x34) + iVar1 + 2));
  }
  iVar1 = Pic_Subsystem_00452551(value);
  if (iVar1 == 2) {
    local_8 = Math_Clamp(local_8 * 2,100,9999);
  }
  else if (iVar1 == 3) {
    local_8 = Math_Clamp(local_8 << 2,200,9999);
  }
  else if (iVar1 == 4) {
    local_8 = Math_Clamp(local_8 << 3,200,9999);
  }
  if (((&DAT_0051aed1)[value * 0x34] & 2) != 0) {
    local_8 = local_8 << 1;
  }
  if (((&DAT_0051aed1)[value * 0x34] & 4) != 0) {
    local_8 = (local_8 * 3) / 2;
  }
  return local_8;
}

/*
 * Decompiled function: FUN_0050aef6
 * Entry Point: 0050aef6
 * Size: 199 bytes
 */


undefined4 FUN_0050aef6(int x,int y)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = x - DAT_00641010;
  if (y - DAT_00641014 < 1) {
    strcat(&g_OverworldWorldState,s_North_005324d0 + ((0 < iVar1) - 1 & 8));
    if (iVar1 < 1) {
      local_8 = 3;
    }
    else {
      local_8 = 0;
    }
  }
  else {
    strcat(&g_OverworldWorldState,&DAT_005324c0 + ((0 < iVar1) - 1 & 8));
    if (iVar1 < 1) {
      local_8 = 2;
    }
    else {
      local_8 = 1;
    }
  }
  return local_8;
}

/*
 * Decompiled function: FUN_0050afbd
 * Entry Point: 0050afbd
 * Size: 79 bytes
 */


void FUN_0050afbd(void)

{
  int iVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < 0xf; local_8 = local_8 + 1) {
    iVar1 = Math_RandomRange(3);
    if (iVar1 == 0) {
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) =
           *(uint *)(&DAT_0067f014 + local_8 * 0x30) & 0xfffffdff;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0050b00c
 * Entry Point: 0050b00c
 * Size: 240 bytes
 */


int FUN_0050b00c(void)

{
  int value;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0x7fff;
  local_c = -1;
  for (local_14 = 0; local_14 < 0xf; local_14 = local_14 + 1) {
    if ((*(int *)(&DAT_0067eff0 + local_14 * 0x30) != -1) &&
       (*(int *)(&DAT_0067f010 + local_14 * 0x30) != 7)) {
      value = FUN_0040a36f(DAT_00641010 - *(int *)(&DAT_0067f000 + local_14 * 0x30),
                           DAT_00641014 - *(int *)(&DAT_0067f004 + local_14 * 0x30));
      local_8 = Math_RandomRange(value);
      local_8 = local_8 + value / 2;
      if (((&DAT_0067f015)[local_14 * 0x30] & 2) != 0) {
        local_8 = local_8 * 3;
      }
      if (local_8 < local_10) {
        local_c = local_14;
        local_10 = local_8;
      }
    }
  }
  return local_c;
}

/*
 * Decompiled function: FUN_0050b0fc
 * Entry Point: 0050b0fc
 * Size: 164 bytes
 */


int FUN_0050b0fc(byte x,byte y)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (499 < local_c) {
      return 0;
    }
    if (((*(int *)(&deck + local_c * 4) != -1) &&
        ((1 << (x & 0x1f) &
         (int)(char)(&DAT_0051aebe)[(*(uint *)(&deck + local_c * 4) & 0xfff) * 0x34]) != 0)) &&
       ((y & (&g_MasterCardColorTable)[(*(uint *)(&deck + local_c * 4) & 0xfff) * 0x34]) != 0))
    break;
    local_c = local_c + 1;
  }
  return local_c + 1;
}

/*
 * Decompiled function: FUN_0050b1a0
 * Entry Point: 0050b1a0
 * Size: 102 bytes
 */


void FUN_0050b1a0(void)

{
  char *str_2;
  
  str_2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
  strcat(&g_OverworldWorldState,str_2);
  strcat(&g_OverworldWorldState,&DAT_005324e0);
  FUN_00484c45(1 << ((byte)DAT_00522450 & 3));
  strcat(&g_OverworldWorldState,s_spell_005324e4);
  return;
}

/*
 * Decompiled function: FUN_0050b206
 * Entry Point: 0050b206
 * Size: 472 bytes
 */


void FUN_0050b206(int value,int min_val,int max_val,int target_slot,char *str_5)

{
  int xLeft;
  int yTop;
  int local_20;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  if (target_slot == 0) {
    local_1c = Ai_Util_004c3ba3(0x30);
    local_20 = Ai_Util_004c3ba3(0x30);
  }
  else {
    local_1c = Ai_Util_004c3ba3(0x50);
    local_20 = Ai_Util_004c3ba3(0x70);
    if (0xf0 < max_val + 0x70) {
      max_val = 0x7f;
    }
  }
  xLeft = Ai_Util_004c3ba3(min_val);
  yTop = Ai_Util_004c3ba3(max_val);
  SetRect(&local_18,xLeft,yTop,local_1c + xLeft,local_20 + yTop);
  if (target_slot == 0) {
    Palette_Subsystem_0049f8cd
              (*(HDC *)((&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen] + 4),&local_18.left,
               (WPARAM *)(&DAT_006b3070 + *(int *)(&g_MasterCardTypeTable + value * 0x34) * 0x98),0,
               1);
  }
  else {
    Palette_Subsystem_0049c7c7
              (*(HDC *)((&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen] + 4),&local_18.left,
               (WPARAM *)(&DAT_006b3070 + *(int *)(&g_MasterCardTypeTable + value * 0x34) * 0x98),0,
               1,1);
  }
  if ((str_5 != (char *)0x0) && (*str_5 != '\0')) {
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    local_8 = FUN_0040c465(str_5);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,((xLeft + local_1c / 2) - local_8 / 2) + -10,
                      yTop + -0x18,local_8 + 0x14,0x14,DAT_00678514);
    FUN_0040c3cc(str_5,xLeft + local_1c / 2,yTop + -0x14,0xff);
  }
  return;
}

/*
 * Decompiled function: FUN_0050b3de
 * Entry Point: 0050b3de
 * Size: 480 bytes
 */


void FUN_0050b3de(int value,int min_val,int max_val,int target_slot,int flags,int arg_6,char *str_7)

{
  int xLeft;
  int yTop;
  tagRECT local_18;
  int local_8;
  
  if (arg_6 == 0) {
    target_slot = Ai_Util_004c3ba3(target_slot);
    flags = Ai_Util_004c3ba3(flags);
  }
  else {
    target_slot = Ai_Util_004c3ba3(target_slot);
    flags = Ai_Util_004c3ba3(flags);
    if (0xf0 < max_val + 0x70) {
      max_val = 0x7f;
    }
  }
  xLeft = Ai_Util_004c3ba3(min_val);
  yTop = Ai_Util_004c3ba3(max_val);
  SetRect(&local_18,xLeft,yTop,target_slot + xLeft,flags + yTop);
  if (arg_6 == 0) {
    Palette_Subsystem_0049f8cd
              (*(HDC *)((&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen] + 4),&local_18.left,
               (WPARAM *)(&DAT_006b3070 + *(int *)(&g_MasterCardTypeTable + value * 0x34) * 0x98),0,
               1);
  }
  else {
    Palette_Subsystem_0049c7c7
              (*(HDC *)((&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen] + 4),&local_18.left,
               (WPARAM *)(&DAT_006b3070 + *(int *)(&g_MasterCardTypeTable + value * 0x34) * 0x98),0,
               1,1);
  }
  if ((str_7 != (char *)0x0) && (*str_7 != '\0')) {
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    local_8 = FUN_0040c465(str_7);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,((xLeft + target_slot / 2) - local_8 / 2) + -10,
                      yTop + -0x18,local_8 + 0x14,0x14,DAT_00678514);
    FUN_0040c3cc(str_7,xLeft + target_slot / 2,yTop + -0x14,0xff);
  }
  return;
}

/*
 * Decompiled function: FUN_0050b5be
 * Entry Point: 0050b5be
 * Size: 161 bytes
 */


void FUN_0050b5be(int value,int min_val,int max_val,int target_slot,int flags)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int xLeft;
  tagRECT local_14;
  
  iVar1 = Ai_Util_004c3ba3(flags);
  iVar2 = Ai_Util_004c3ba3(max_val);
  iVar1 = iVar1 + iVar2;
  iVar2 = Ai_Util_004c3ba3(target_slot);
  iVar3 = Ai_Util_004c3ba3(min_val);
  iVar2 = iVar2 + iVar3;
  iVar3 = Ai_Util_004c3ba3(max_val);
  xLeft = Ai_Util_004c3ba3(min_val);
  SetRect(&local_14,xLeft,iVar3,iVar2,iVar1);
  Palette_Subsystem_00496d30
            (*(HDC *)((&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen] + 4),&local_14.left,
             (WPARAM *)(&DAT_006b3070 + value * 0x98),1);
  return;
}

/*
 * Decompiled function: FUN_0050b65f
 * Entry Point: 0050b65f
 * Size: 865 bytes
 */


void FUN_0050b65f(int value,int min_val,int max_val,int target_slot,char *str_5)

{
  int arg_3_00;
  int arg_6;
  int iVar1;
  uint arg_2_00;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int arg_2_01;
  int arg_3_01;
  int local_10;
  
  bVar5 = target_slot == 2;
  arg_2_00 = value - 0x2b;
  arg_3_00 = min_val + -0x26;
  switch(target_slot) {
  case 0:
    target_slot = 0;
    break;
  case 1:
    target_slot = 1;
    break;
  case 2:
    target_slot = 1;
    break;
  case 3:
    return;
  }
  if (bVar5) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,value + -0x21,min_val + -0x1e,
                      *(short *)(*(int *)(&DAT_00678390 + max_val * 4) + 4) + -4,
                      *(short *)(*(int *)(&DAT_00678390 + max_val * 4) + 6) + -2,
                      *(int *)(&DAT_00678390 + max_val * 4));
    iVar3 = *(int *)(&DAT_00678260 + target_slot * 0x10);
    Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,value + -0x29,min_val + -0x24,
                      *(short *)(iVar3 + 4) + -4,*(short *)(iVar3 + 6) + -2,
                      *(int *)(&DAT_00678260 + target_slot * 0x10));
    Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,arg_2_00,arg_3_00,(int)*(short *)(iVar3 + 4),
                 (int)*(short *)(iVar3 + 6),(int *)g_DisplaySurfaceScreen,arg_2_00,arg_3_00);
  }
  else {
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,value + -0x23,min_val + -0x20,
                      *(int *)(&DAT_00678390 + max_val * 4));
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00,arg_3_00,
                      *(int *)(&DAT_00678260 + target_slot * 0x10));
  }
  if (DAT_006265f0 != 0) {
    iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    iVar3 = Ai_Util_004c3bc4(8);
    iVar2 = iVar2 + iVar3;
    iVar3 = *(int *)(&DAT_00678268 + target_slot * 0x10);
    arg_6 = *(int *)(&DAT_00678264 + target_slot * 0x10);
    iVar1 = *(int *)(target_slot * 0x10 + 0x67826c);
    arg_3_01 = 999;
    arg_2_01 = 0x60;
    iVar4 = FUN_0040c465(str_5);
    iVar4 = Math_Clamp(iVar4 + 0x20,arg_2_01,arg_3_01);
    for (local_10 = 0; local_10 < (int)(iVar4 + (iVar4 >> 0x1f & 0x3fU)) >> 6;
        local_10 = local_10 + 1) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(value - iVar4 / 2) + local_10 * 0x40,
                        min_val + 0x12,0x40,iVar2,arg_6);
    }
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,value + iVar4 / 2 + -0x40,min_val + 0x12,0x40,
                      iVar2,*(int *)(&DAT_00678264 + target_slot * 0x10));
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(value - iVar4 / 2) + -8,min_val + 0x12,
                      (int)*(short *)(iVar3 + 4),iVar2,*(int *)(&DAT_00678268 + target_slot * 0x10));
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,value + iVar4 / 2,min_val + 0x12,
                      (int)*(short *)(iVar1 + 4),iVar2,*(int *)(target_slot * 0x10 + 0x67826c));
    FUN_0040d009((int)g_DisplaySurfaceScreen,0xff,value,arg_3_00 + iVar2 / 2 + 0x38);
  }
  return;
}

/*
 * Decompiled function: FUN_0050b9d5
 * Entry Point: 0050b9d5
 * Size: 442 bytes
 */


void FUN_0050b9d5(int *value)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int min_val;
  int local_3c [4];
  int local_2c [4];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_18 = DAT_00677e10;
  if (g_DisplayScreenWidth == 0x280) {
    local_1c = 0;
  }
  else if (g_DisplayScreenWidth == 800) {
    local_1c = 1;
  }
  else if (g_DisplayScreenWidth == 0x400) {
    local_1c = 2;
  }
  iVar1 = Ai_Util_004c3ba3(0x8c);
  iVar2 = Ai_Util_004c3ba3(0x100);
  iVar3 = Ai_Util_004c3bc4(0x30);
  iVar4 = Ai_Util_004c3bc4(0x40);
  piVar5 = (int *)FUN_0050e6f0(local_2c,(int)g_DisplaySurfaceScreen,iVar4,iVar3,iVar2,iVar1);
  local_14 = *piVar5;
  local_10 = piVar5[1];
  local_c = piVar5[2];
  local_8 = piVar5[3];
  iVar1 = DAT_00677e10;
  iVar2 = Ai_Util_004c3bc4((int)*(short *)(local_18 + 6));
  iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_18 + 4));
  iVar4 = Ai_Util_004c3bc4(0x135);
  min_val = Ai_Util_004c3bc4(0x181);
  Sprite_DrawScaled(value,min_val,iVar4,iVar3,iVar2,iVar1);
  Sprite_DrawDirect(value,*(int *)(&DAT_005318e8 + local_1c * 4),
                    *(int *)(&DAT_005318f8 + local_1c * 4),DAT_00677fb0);
  Sprite_DrawDirect(value,*(int *)(&DAT_00531908 + local_1c * 4),
                    *(int *)(&DAT_00531920 + local_1c * 4),DAT_00677fe4);
  Sprite_DrawDirect(value,*(int *)(&DAT_00531914 + local_1c * 4),
                    *(int *)(&DAT_00531920 + local_1c * 4),DAT_00677fe4);
  FUN_0050e6f0(local_3c,(int)g_DisplaySurfaceScreen,local_14,local_10,local_c,local_8);
  return;
}

/*
 * Decompiled function: FUN_0050bcd6
 * Entry Point: 0050bcd6
 * Size: 81 bytes
 */


void FUN_0050bcd6(void)

{
  if (DAT_0061e118 != (HMENU)0x0) {
    DestroyMenu(DAT_0061e118);
  }
  if (DAT_0061e11c != (HMENU)0x0) {
    DestroyMenu(DAT_0061e11c);
  }
  DAT_0061e118 = (HMENU)0x0;
  DAT_0061e11c = (HMENU)0x0;
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0050c82b
 * Entry Point: 0050c82b
 * Size: 41 bytes
 */


void Mem_AllocOrFree_0050c82b(int value)

{
  undefined1 local_7d4 [2000];
  
  Ai_Subsystem_004b72d0(local_7d4,value);
  return;
}

/*
 * Decompiled function: GetSaveFileNameA
 * Entry Point: 0050ce18
 * Size: 6 bytes
 */


BOOL GetSaveFileNameA(LPOPENFILENAMEA value)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0050ce18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetSaveFileNameA(value);
  return BVar1;
}

/*
 * Decompiled function: MCIWndCreateA
 * Entry Point: 0050ce66
 * Size: 6 bytes
 */


void MCIWndCreateA(void)

{
                    /* WARNING: Could not recover jumptable at 0x0050ce66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MCIWndCreateA();
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0050ce80
 * Entry Point: 0050ce80
 * Size: 3 bytes
 */


undefined4 Mem_AllocOrFree_0050ce80(void)

{
  return 0;
}

/*
 * Decompiled function: Mem_AllocOrFree_0050ce90
 * Entry Point: 0050ce90
 * Size: 21 bytes
 */


undefined4 Mem_AllocOrFree_0050ce90(undefined4 x,int y)

{
  undefined4 uVar1;
  
  if (y != 0) {
    uVar1 = FUN_0050edf0((char *)y);
    return uVar1;
  }
  return 0;
}

/*
 * Decompiled function: thunk_FUN_0050cef0
 * Entry Point: 0050ceb0
 * Size: 5 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * thunk_FUN_0050cef0(void)

{
  LOGPALETTE *pLVar1;
  undefined4 *puVar2;
  int iVar3;
  int min_val;
  int max_val;
  int iVar4;
  undefined4 uVar5;
  LOGPALETTE *plpal;
  HPALETTE hPal;
  undefined4 **ppuVar6;
  undefined4 **ppuVar7;
  char acStack_a [10];
  
  acStack_a[0] = DAT_00532572;
  acStack_a[1] = '\0';
  acStack_a[2] = '\0';
  acStack_a[3] = '\0';
  acStack_a[4] = '\0';
  acStack_a[5] = '\0';
  acStack_a[6] = '\0';
  acStack_a[7] = '\0';
  acStack_a[8] = '\0';
  acStack_a[9] = 0;
  if (DAT_0053255c != 0) {
    return DAT_0070a850;
  }
  puVar2 = malloc(0x30);
  iVar3 = GetDeviceCaps(_hdcScreen,8);
  DAT_0070a87c = iVar3;
  puVar2[8] = iVar3;
  min_val = GetDeviceCaps(_hdcScreen,10);
  DAT_0070a878 = min_val;
  puVar2[9] = min_val;
  max_val = GetDeviceCaps(_hdcScreen,0xc);
  DAT_0070a880 = max_val;
  puVar2[10] = max_val;
  iVar4 = max_val * min_val * iVar3;
  _DAT_00532554 = 0;
  puVar2[7] = ((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + 0x10;
  _itoa(0,acStack_a,10);
  puVar2[1] = _hdcScreen;
  uVar5 = FUN_0050ec90(iVar3,min_val,max_val);
  puVar2[4] = uVar5;
  uVar5 = FUN_0050ec90(iVar3,min_val,8);
  puVar2[4] = uVar5;
  *puVar2 = 0;
  puVar2[2] = 0;
  plpal = malloc(0x408);
  plpal->palVersion = 0x300;
  iVar3 = 0x100;
  plpal->palNumEntries = 0x100;
  pLVar1 = plpal;
  do {
    pLVar1->palPalEntry[0].peRed = '\0';
    iVar3 = iVar3 + -1;
    pLVar1->palPalEntry[0].peGreen = '\0';
    pLVar1->palPalEntry[0].peBlue = '\0';
    pLVar1->palPalEntry[0].peFlags = '\x01';
    pLVar1 = (LOGPALETTE *)pLVar1->palPalEntry;
  } while (iVar3 != 0);
  plpal->palPalEntry[0].peFlags = '\0';
  *(undefined1 *)((int)&plpal[0x80].palNumEntries + 1) = 0;
  ppuVar6 = (undefined4 **)&DAT_0070a450;
  _DAT_0070ac90 = plpal;
  do {
    *(undefined1 *)ppuVar6 = 0;
    ppuVar7 = ppuVar6 + 1;
    *(undefined1 *)((int)ppuVar6 + 1) = 0;
    *(undefined1 *)((int)ppuVar6 + 2) = 0;
    *(undefined1 *)((int)ppuVar6 + 3) = 1;
    ppuVar6 = ppuVar7;
  } while (ppuVar7 < &DAT_0070a850);
  DAT_0070a453 = 0;
  DAT_0070a84f = 0;
  hPal = CreatePalette(plpal);
  DAT_00626834 = hPal;
  _hLibPal = hPal;
  puVar2[5] = hPal;
  SelectPalette((HDC)puVar2[1],hPal,0);
  RealizePalette((HDC)puVar2[1]);
  SetStretchBltMode((HDC)puVar2[1],3);
  DAT_0070a850 = puVar2;
  DAT_0053255c = 1;
  return puVar2;
}

/*
 * Decompiled function: Mem_AllocOrFree_0050cec0
 * Entry Point: 0050cec0
 * Size: 38 bytes
 */


void Mem_AllocOrFree_0050cec0(int value)

{
  if (value == 0) {
    FUN_0050cef0();
    return;
  }
  FUN_0050d0b0(value,DAT_0070a87c,DAT_0070a878,8);
  return;
}

/*
 * Decompiled function: FUN_0050cef0
 * Entry Point: 0050cef0
 * Size: 440 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0050cef0(void)

{
  LOGPALETTE *pLVar1;
  undefined4 *puVar2;
  int iVar3;
  int min_val;
  int max_val;
  int iVar4;
  undefined4 uVar5;
  LOGPALETTE *plpal;
  HPALETTE hPal;
  undefined4 **ppuVar6;
  undefined4 **ppuVar7;
  char local_a [10];
  
  local_a[0] = DAT_00532572;
  local_a[1] = '\0';
  local_a[2] = '\0';
  local_a[3] = '\0';
  local_a[4] = '\0';
  local_a[5] = '\0';
  local_a[6] = '\0';
  local_a[7] = '\0';
  local_a[8] = '\0';
  local_a[9] = 0;
  if (DAT_0053255c != 0) {
    return DAT_0070a850;
  }
  puVar2 = malloc(0x30);
  iVar3 = GetDeviceCaps(_hdcScreen,8);
  DAT_0070a87c = iVar3;
  puVar2[8] = iVar3;
  min_val = GetDeviceCaps(_hdcScreen,10);
  DAT_0070a878 = min_val;
  puVar2[9] = min_val;
  max_val = GetDeviceCaps(_hdcScreen,0xc);
  DAT_0070a880 = max_val;
  puVar2[10] = max_val;
  iVar4 = max_val * min_val * iVar3;
  _DAT_00532554 = 0;
  puVar2[7] = ((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + 0x10;
  _itoa(0,local_a,10);
  puVar2[1] = _hdcScreen;
  uVar5 = FUN_0050ec90(iVar3,min_val,max_val);
  puVar2[4] = uVar5;
  uVar5 = FUN_0050ec90(iVar3,min_val,8);
  puVar2[4] = uVar5;
  *puVar2 = 0;
  puVar2[2] = 0;
  plpal = malloc(0x408);
  plpal->palVersion = 0x300;
  iVar3 = 0x100;
  plpal->palNumEntries = 0x100;
  pLVar1 = plpal;
  do {
    pLVar1->palPalEntry[0].peRed = '\0';
    iVar3 = iVar3 + -1;
    pLVar1->palPalEntry[0].peGreen = '\0';
    pLVar1->palPalEntry[0].peBlue = '\0';
    pLVar1->palPalEntry[0].peFlags = '\x01';
    pLVar1 = (LOGPALETTE *)pLVar1->palPalEntry;
  } while (iVar3 != 0);
  plpal->palPalEntry[0].peFlags = '\0';
  *(undefined1 *)((int)&plpal[0x80].palNumEntries + 1) = 0;
  ppuVar6 = (undefined4 **)&DAT_0070a450;
  _DAT_0070ac90 = plpal;
  do {
    *(undefined1 *)ppuVar6 = 0;
    ppuVar7 = ppuVar6 + 1;
    *(undefined1 *)((int)ppuVar6 + 1) = 0;
    *(undefined1 *)((int)ppuVar6 + 2) = 0;
    *(undefined1 *)((int)ppuVar6 + 3) = 1;
    ppuVar6 = ppuVar7;
  } while (ppuVar7 < &DAT_0070a850);
  DAT_0070a453 = 0;
  DAT_0070a84f = 0;
  hPal = CreatePalette(plpal);
  DAT_00626834 = hPal;
  _hLibPal = hPal;
  puVar2[5] = hPal;
  SelectPalette((HDC)puVar2[1],hPal,0);
  RealizePalette((HDC)puVar2[1]);
  SetStretchBltMode((HDC)puVar2[1],3);
  DAT_0070a850 = puVar2;
  DAT_0053255c = 1;
  return puVar2;
}

/*
 * Decompiled function: FUN_0070d000
 * Entry Point: 0070d000
 * Size: 396 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0070d000(undefined4 value,undefined4 min_val,ushort *max_val)

{
  ushort uVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 unaff_EBX;
  ushort *puVar3;
  ushort *puVar4;
  
  while( true ) {
    puVar3 = DAT_00706500;
    if (PTR_DAT_005327b0 <= DAT_00706500) {
      (*DAT_0067f43c)(min_val,value,unaff_EBX);
      puVar3 = DAT_00706500;
    }
    DAT_00706500 = puVar3 + 1;
    uVar1 = *puVar3;
    if ((char)uVar1 == 'X') break;
    puVar3 = &DAT_00532860;
    if ((uVar1 == 0x304d) || (uVar1 == 0x314d)) {
      if ((int)max_val < 1) {
        puVar3 = (ushort *)&DAT_00532862;
      }
      else if (max_val != (ushort *)0x1) {
        puVar3 = max_val;
      }
    }
    *puVar3 = uVar1;
    puVar4 = puVar3;
    if (PTR_DAT_005327b0 <= DAT_00706500) {
      (*DAT_0067f43c)(min_val,value);
    }
    uVar1 = *DAT_00706500;
    DAT_00706500 = DAT_00706500 + 1;
    puVar3[1] = uVar1;
    puVar3 = puVar3 + 2;
    for (uVar2 = (uint)(uVar1 >> 1); uVar2 != 0; uVar2 = uVar2 - 1) {
      if (PTR_DAT_005327b0 <= DAT_00706500) {
        (*DAT_0067f43c)();
      }
      uVar1 = *DAT_00706500;
      DAT_00706500 = DAT_00706500 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
    }
    value = 0;
    if (puVar4 == &DAT_00532860) {
      FUN_0050e8b0(&DAT_00532860);
      value = extraout_ECX;
      min_val = extraout_EDX;
    }
  }
  DAT_00536885 = (byte)(uVar1 >> 8) & 1;
  if (PTR_DAT_005327b0 <= DAT_00706500) {
    (*DAT_0067f43c)(min_val,value,unaff_EBX);
  }
  puVar3 = DAT_00706500 + 1;
  _DAT_00536868 = (uint)*DAT_00706500;
  if (PTR_DAT_005327b0 <= puVar3) {
    DAT_00706500 = puVar3;
    (*DAT_0067f43c)(min_val,value,unaff_EBX);
    puVar3 = DAT_00706500;
  }
  DAT_00706500 = puVar3 + 1;
  DAT_00536860 = (uint)*puVar3;
  if (PTR_DAT_005327b0 <= DAT_00706500) {
    (*DAT_0067f43c)(min_val,value,unaff_EBX);
  }
  DAT_00536864 = (uint)*DAT_00706500;
  DAT_00706500 = DAT_00706500 + 1;
  FUN_0070d245(value,min_val);
  return;
}

/*
 * Decompiled function: FUN_0070d245
 * Entry Point: 0070d245
 * Size: 112 bytes
 */


void __fastcall FUN_0070d245(undefined4 x,undefined4 y)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_00536860 == 0 && DAT_00536864 == 0) {
    return;
  }
  DAT_00536874 = 0;
  DAT_00536875 = 0;
  DAT_0053686c = &DAT_00536c8b;
  if (PTR_DAT_005327b0 <= DAT_00706500) {
    (*DAT_0067f43c)(y,x);
  }
  uVar1 = *DAT_00706500;
  DAT_00536880 = (uint)uVar1;
  if (0xb < (byte)uVar1) {
    DAT_00536880 = CONCAT31((uint3)(byte)(uVar1 >> 8),0xb);
  }
  DAT_00536877 = (undefined1)DAT_00536880;
  DAT_00536884 = 8;
  DAT_00536876 = 9;
  DAT_00536878 = 0x1ff;
  DAT_0053687c = 0x100;
  iVar4 = 0;
  iVar3 = 0x800;
  DAT_00706500 = DAT_00706500 + 1;
  do {
    *(undefined2 *)((int)&DAT_00532860 + iVar4) = 0xffff;
    iVar4 = iVar4 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  cVar2 = '\0';
  iVar4 = 0;
  iVar3 = 0x100;
  do {
    (&DAT_00532862)[iVar4] = cVar2;
    cVar2 = cVar2 + '\x01';
    iVar4 = iVar4 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/*
 * Decompiled function: FUN_0070d2b5
 * Entry Point: 0070d2b5
 * Size: 75 bytes
 */


void FUN_0070d2b5(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  DAT_00536876 = 9;
  DAT_00536878 = 0x1ff;
  DAT_0053687c = 0x100;
  iVar3 = 0;
  iVar2 = 0x800;
  do {
    *(undefined2 *)((int)&DAT_00532860 + iVar3) = 0xffff;
    iVar3 = iVar3 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  cVar1 = '\0';
  iVar3 = 0;
  iVar2 = 0x100;
  do {
    (&DAT_00532862)[iVar3] = cVar1;
    cVar1 = cVar1 + '\x01';
    iVar3 = iVar3 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/*
 * Decompiled function: FUN_0070d300
 * Entry Point: 0070d300
 * Size: 146 bytes
 */


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0070d300(uint value)

{
  char cVar1;
  ushort uVar2;
  uint arg_1_00;
  uint extraout_ECX;
  uint min_val;
  uint extraout_EDX;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char *unaff_EDI;
  
  if (DAT_00536885 != '\0') {
    value = value + 1 >> 1;
  }
  LOCK();
  UNLOCK();
  uVar3 = DAT_0053687c;
  puVar4 = (undefined4 *)DAT_0053686c;
  DAT_0053686c = (undefined1 *)register0x00000010;
  _DAT_00536870 = value;
  do {
    puVar5 = puVar4;
    if (DAT_00536874 == '\0') {
      puVar4[-1] = 0x70d32c;
      cVar1 = FUN_0070d392(value,uVar3,*puVar4);
      puVar5 = puVar4 + 1;
      value = arg_1_00;
      uVar3 = min_val;
      if (cVar1 == -0x70) {
        *puVar4 = 0x70d33c;
        cVar1 = FUN_0070d392(arg_1_00,min_val,puVar4[1]);
        puVar5 = puVar4 + 2;
        value = extraout_ECX;
        uVar3 = extraout_EDX;
        if (cVar1 != '\0') {
          DAT_00536874 = cVar1 + -1;
          goto LAB_0070d350;
        }
        DAT_00536875 = -0x70;
        puVar5 = puVar4 + 2;
        cVar1 = DAT_00536875;
      }
    }
    else {
LAB_0070d350:
      DAT_00536874 = DAT_00536874 + -1;
      cVar1 = DAT_00536875;
    }
    DAT_00536875 = cVar1;
    if (DAT_00536885 == '\0') {
      *unaff_EDI = DAT_00536875;
      unaff_EDI = unaff_EDI + 1;
    }
    else {
      uVar2 = CONCAT11(DAT_00536875,DAT_00536875) & 0xff0f;
      *(ushort *)unaff_EDI = CONCAT11((byte)(uVar2 >> 0xc),(char)uVar2);
      unaff_EDI = unaff_EDI + 2;
    }
    _DAT_00536870 = _DAT_00536870 - 1;
    puVar4 = puVar5;
    if (_DAT_00536870 == 0) {
      DAT_0053687c = uVar3;
      LOCK();
      DAT_0053686c = (undefined1 *)puVar5;
      UNLOCK();
      return;
    }
  } while( true );
}

/*
 * Decompiled function: FUN_0070d392
 * Entry Point: 0070d392
 * Size: 242 bytes
 */


undefined4 __fastcall FUN_0070d392(undefined4 value,uint min_val,undefined4 max_val)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint extraout_ECX;
  uint uVar4;
  ushort *unaff_ESI;
  ushort *puVar5;
  
  uVar3 = DAT_00536886;
  if (&stack0x00000000 == (undefined1 *)0x536c87) {
    uVar4 = DAT_00536880 >> (0x10 - DAT_00536884 & 0x1f);
    for (bVar2 = DAT_00536884; (char)bVar2 < DAT_00536876; bVar2 = bVar2 + 0x10) {
      puVar5 = unaff_ESI;
      if (PTR_DAT_005327b0 <= unaff_ESI) {
        (*DAT_0067f43c)();
        puVar5 = DAT_00706500;
      }
      unaff_ESI = puVar5 + 1;
      DAT_00536880 = (uint)*puVar5;
      uVar4 = uVar4 | DAT_00536880 << (bVar2 & 0x1f);
    }
    DAT_00536884 = bVar2 - DAT_00536876;
    uVar4 = uVar4 & DAT_00536878;
    uVar3 = uVar4;
    if ((int)min_val <= (int)uVar4) {
      uVar4 = DAT_00536886;
      uVar3 = min_val;
    }
    while( true ) {
      iVar1 = uVar4 * 3;
      if (*(short *)((int)&DAT_00532860 + iVar1) == -1) break;
      uVar4 = CONCAT22((short)(uVar4 >> 0x10),*(short *)((int)&DAT_00532860 + iVar1));
      max_val = CONCAT31((int3)((uint)iVar1 >> 8),(&DAT_00532862)[iVar1]);
    }
    DAT_0053688a = (&DAT_00532862)[iVar1];
    (&DAT_00532862)[min_val * 3] = DAT_0053688a;
    *(short *)((int)&DAT_00532860 + min_val * 3) = (short)DAT_00536886;
    if ((int)DAT_00536878 < (int)(min_val + 1)) {
      DAT_00536876 = DAT_00536876 + '\x01';
      DAT_00536878 = DAT_00536878 << 1 | 1;
    }
    if (DAT_00536877 < DAT_00536876) {
      FUN_0070d2b5();
      uVar3 = extraout_ECX;
    }
  }
  DAT_00536886 = uVar3;
                    /* WARNING: Treating indirect jump as return */
  return max_val;
}

/*
 * Decompiled function: Mem_AllocOrFree_0070d484
 * Entry Point: 0070d484
 * Size: 36 bytes
 */


void Mem_AllocOrFree_0070d484(undefined4 x,uint y)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00706500;
  FUN_0070d300(y);
  DAT_00706500 = uVar1;
  return;
}

