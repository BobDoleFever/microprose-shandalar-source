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
    Pic_DestroyDIBSection(DAT_00536e70);
  }
  DAT_00536e70 = (HANDLE)0x0;
  return;
}

/*
 * Decompiled function: FUN_00403189
 * Entry Point: 00403189
 * Size: 185 bytes
 */


bool FUN_00403189(HWND hwnd,int arg2)

{
  LONG LVar1;
  size_t len_2;
  bool flag_3;
  int card_idx;
  char *slot_idx;
  
  if (hwnd == (HWND)0x0) {
    flag_3 = false;
  }
  else {
    slot_idx = (char *)GetWindowLongA(hwnd,4);
    LVar1 = GetWindowLongA(hwnd,8);
    if (LVar1 + -1 < arg2) {
      flag_3 = false;
    }
    else {
      for (card_idx = 0; card_idx < arg2; card_idx = card_idx + 1) {
        len_2 = strlen(slot_idx);
        slot_idx = slot_idx + len_2 + 1;
      }
      flag_3 = *slot_idx != '_';
    }
  }
  return flag_3;
}

/*
 * Decompiled function: FUN_00403250
 * Entry Point: 00403250
 * Size: 955 bytes
 */


int32_t
FUN_00403250(int *arg_1,int card_slot,int event_type,uint32_t arg_4,uint32_t arg_5,uint32_t arg_6,uint32_t arg_7,uint32_t arg_8,
            uint32_t arg_9,uint32_t arg_10,uint32_t arg_11,uint32_t arg_12,int arg_13,int arg_14,uint32_t arg_15,
            uint32_t arg_16,uint32_t arg_17,uint32_t arg_18,uint32_t arg_19)

{
  bool flag_1;
  int val_2;
  bool flag_3;
  int local_2c;
  int local_28;
  int32_t loop_idx;
  int target_idx;
  uint32_t card_idx;
  int match_count;
  uint32_t slot_idx;
  
  target_idx = 0;
  loop_idx = 0;
  if (((arg_2 == 0) || (arg_2 == 1)) || (arg_2 == 2)) {
    flag_1 = false;
    local_28 = 0;
    while( true ) {
      if (1 < local_28) break;
      val_2 = Rules_ParseFilter_0040360b
                        (local_28,-1,(char *)0x0,arg_3,(uint8_t)arg_4,(uint8_t)arg_5,arg_6,arg_7,arg_8,
                         arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18,arg_19
                        );
      if (val_2 != 0) {
        loop_idx = 1;
        target_idx = target_idx + 1;
        if (arg_1 == (int *)0x0) {
          flag_1 = true;
        }
      }
      local_28 = local_28 + 1;
    }
    if (arg_3 == 0) {
      slot_idx = (uint32_t)((arg_4 & 2) == 0);
    }
    else if (((arg_5 & 2) == 0) && ((arg_5 & 1) == 0)) {
      slot_idx = 0;
    }
    else {
      slot_idx = 1;
    }
    local_28 = 0;
    while ((local_28 < 2 && (!flag_1))) {
      match_count = 0;
      while( true ) {
        val_2 = DAT_006808bc;
        if (DAT_006808bc <= g_PlayerActiveCardCount) {
          val_2 = g_PlayerActiveCardCount;
        }
        if ((val_2 <= match_count) || (flag_1)) break;
        if (*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) != -1) {
          if (arg_2 == 0) {
            card_idx = slot_idx;
            local_2c = match_count;
            flag_3 = true;
          }
          else if (arg_2 == 1) {
            flag_3 = *(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) ==
                    g_PendingSpellTargetSlot;
            if (flag_3) {
              card_idx = (uint32_t)(char)(&g_CardSlot_Toughness)[match_count * 0x120 + slot_idx * 0x5b20];
              local_2c = *(int *)(&g_CardSlot_OriginalCardId + match_count * 0x120 + slot_idx * 0x5b20);
            }
          }
          else if (*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) == g_PendingSpellTargetSlot
                  ) {
            card_idx = (uint32_t)(char)(&g_CardSlot_DamageReceived)[match_count * 0x120 + slot_idx * 0x5b20];
            local_2c = *(int *)(&g_CardSlot_TypeFlags + match_count * 0x120 + slot_idx * 0x5b20);
            flag_3 = true;
          }
          else {
            flag_3 = false;
          }
          if ((flag_3) &&
             (val_2 = Rules_ParseFilter_0040360b
                                (card_idx,local_2c,(char *)0x0,arg_3,(uint8_t)arg_4,(uint8_t)arg_5,arg_6,
                                 arg_7,arg_8,arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,
                                 arg_17,arg_18,arg_19), val_2 != 0)) {
            loop_idx = 1;
            target_idx = target_idx + 1;
            if (arg_1 == (int *)0x0) {
              flag_1 = true;
            }
          }
        }
        match_count = match_count + 1;
      }
      local_28 = local_28 + 1;
      slot_idx = 1 - slot_idx;
    }
    if (arg_1 != (int *)0x0) {
      *arg_1 = target_idx;
    }
  }
  else {
    loop_idx = 0;
  }
  return loop_idx;
}

/*
 * Decompiled function: FUN_00405277
 * Entry Point: 00405277
 * Size: 249 bytes
 */


int FUN_00405277(int arg1,int arg2)

{
  int card_idx;
  int match_count;
  int slot_idx;
  
  card_idx = 0;
  slot_idx = 0;
  while ((slot_idx < 2 && (card_idx == 0))) {
    match_count = 0;
    while ((match_count < (int)(&g_PlayerActiveCardCount)[slot_idx] && (card_idx == 0))) {
      if (((*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) == g_PendingSpellTargetSlot) &&
          ((char)(&g_CardSlot_Toughness)[match_count * 0x120 + slot_idx * 0x5b20] == arg1)) &&
         (*(int *)(&g_CardSlot_OriginalCardId + match_count * 0x120 + slot_idx * 0x5b20) == arg2)) {
        card_idx = 1;
      }
      match_count = match_count + 1;
    }
    slot_idx = slot_idx + 1;
  }
  return card_idx;
}

/*
 * Decompiled function: FUN_00405edf
 * Entry Point: 00405edf
 * Size: 184 bytes
 */


int32_t FUN_00405edf(int arg1,int arg2)

{
  int match_count;
  int32_t slot_idx;
  
  slot_idx = 0;
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) < 5) {
    slot_idx = 1;
  }
  else {
    for (match_count = 0; match_count < 5; match_count = match_count + 1) {
      if ((&DAT_006ff2c0)[match_count] ==
          *(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34)) {
        slot_idx = 1;
      }
    }
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_00405f97
 * Entry Point: 00405f97
 * Size: 324 bytes
 */


int32_t FUN_00405f97(int arg1,int arg2)

{
  int32_t slot_idx;
  
  slot_idx = 0;
  if ((arg2 == 0) &&
     ((arg1 == 0 || (*(int *)(&g_MasterCardTypeTable + arg1 * 0x34) == DAT_006ff2c0)))) {
    slot_idx = 1;
  }
  if ((arg2 == 1) &&
     ((arg1 == 1 || (*(int *)(&g_MasterCardTypeTable + arg1 * 0x34) == DAT_006ff2c4)))) {
    slot_idx = 1;
  }
  if ((arg2 == 2) &&
     ((arg1 == 2 || (*(int *)(&g_MasterCardTypeTable + arg1 * 0x34) == DAT_006ff2c8)))) {
    slot_idx = 1;
  }
  if ((arg2 == 3) &&
     ((arg1 == 3 || (*(int *)(&g_MasterCardTypeTable + arg1 * 0x34) == DAT_006ff2cc)))) {
    slot_idx = 1;
  }
  if ((arg2 == 4) &&
     ((arg1 == 4 || (*(int *)(&g_MasterCardTypeTable + arg1 * 0x34) == DAT_006ff2d0)))) {
    slot_idx = 1;
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0040683a
 * Entry Point: 0040683a
 * Size: 583 bytes
 */


int FUN_0040683a(char *filepath,int card_slot,int event_type,int arg_4,int32_t arg_5)

{
  char cVar1;
  int val_2;
  size_t len_3;
  int val_4;
  char local_24;
  int target_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  slot_idx = 0;
  card_idx = 0;
  match_count = 0;
  val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  len_3 = strlen(str_1);
  for (target_idx = 0; target_idx < (int)len_3; target_idx = target_idx + 1) {
    if (str_1[target_idx] < '\0') {
      local_24 = str_1[target_idx] + -0x80;
    }
    else {
      local_24 = str_1[target_idx];
    }
    val_4 = FUN_0050f390(*(int *)(g_DisplaySurfaceScreen + 0x20),local_24);
    match_count = match_count + val_4;
    if (((str_1[target_idx] == ' ') || (str_1[target_idx] == '\n')) || (str_1[target_idx] == '^')) {
      slot_idx = target_idx;
    }
    if (((str_1[target_idx] == '\n') || (str_1[target_idx] == '^')) || (arg_2 * 8 < match_count)) {
      cVar1 = str_1[slot_idx];
      str_1[slot_idx] = '\0';
      if (10 < val_2) {
        strcpy(str_1 + 0x200,str_1);
        FUN_00406a88(str_1 + card_idx,(g_AiManaColorCost_Red + -2) - arg_3);
      }
      FUN_0040c274(str_1 + card_idx,arg_3,arg_4,arg_5);
      if (10 < val_2) {
        strcpy(str_1,str_1 + 0x200);
      }
      str_1[slot_idx] = cVar1;
      arg_4 = arg_4 + val_2;
      match_count = 0;
      card_idx = slot_idx + 1;
      if (str_1[target_idx] == '^') {
        card_idx = slot_idx + 2;
      }
      target_idx = slot_idx;
      if (g_AiManaColorCost_Green + -8 < arg_4) break;
    }
  }
  if ((0 < match_count) && (arg_4 <= g_AiManaColorCost_Green + -8)) {
    FUN_0040c274(str_1 + card_idx,arg_3,arg_4,arg_5);
    arg_4 = arg_4 + val_2;
  }
  return arg_4;
}

/*
 * Decompiled function: FUN_00406a88
 * Entry Point: 00406a88
 * Size: 121 bytes
 */


void FUN_00406a88(char *filepath,int arg2)

{
  int val_1;
  size_t len_2;
  
  while( true ) {
    val_1 = FUN_0040c465(str_1);
    if (val_1 <= arg2) break;
    len_2 = strlen(str_1);
    if (str_1[len_2 - 3] != ' ') {
      len_2 = strlen(str_1);
      str_1[len_2 - 2] = '.';
    }
    len_2 = strlen(str_1);
    str_1[len_2 - 1] = '\0';
  }
  return;
}

/*
 * Decompiled function: FUN_00406b01
 * Entry Point: 00406b01
 * Size: 75 bytes
 */


bool FUN_00406b01(char *filepath)

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


int FUN_00407499(int player_id)

{
  int val_1;
  int val_2;
  int local_420;
  int local_41c;
  int local_418;
  int aiStack_404 [256];
  
  local_420 = 0;
  for (local_418 = 0; local_418 < 0x100; local_418 = local_418 + 1) {
    if (*(int *)(&DAT_00701944 + local_418 * 8) == -1) {
      if (((*(int *)(&DAT_00701940 + local_418 * 8) ==
            *(int *)(&g_MasterCardTypeTable + arg_1 * 0x34)) &&
          (val_1 = FUN_00407747(*(int *)(&DAT_00701940 + local_418 * 8)), val_1 == 0)) &&
         ((*(uint32_t *)(&DAT_00701430 + local_418 * 4) & 1 << ((uint8_t)g_CampaignDifficultyLevel & 0x1f)) != 0)) {
        local_41c = 0;
        while ((local_41c < 500 &&
               ((((&g_MasterCardColorTable)[(*(uint32_t *)(&deck + local_41c * 4) & 0xfff) * 0x34] & 1)
                 == 0 || (((&g_MasterCardColorTable)[(*(uint32_t *)(&deck + local_41c * 4) & 0xfff) * 0x34] &
                          (&g_MasterCardColorTable)[arg_1 * 0x34]) == 0))))) {
          local_41c = local_41c + 1;
        }
      }
    }
    else {
      val_1 = FUN_00407747(*(int *)(&DAT_00701940 + local_418 * 8));
      val_2 = FUN_00407747(*(int *)(&DAT_00701944 + local_418 * 8));
      if (((val_1 == 0) || (val_2 == 0)) &&
         ((*(uint32_t *)(&DAT_00701430 + local_418 * 4) & 1 << ((uint8_t)g_CampaignDifficultyLevel & 0x1f)) != 0)) {
        if ((*(int *)(&DAT_00701940 + local_418 * 8) ==
             *(int *)(&g_MasterCardTypeTable + arg_1 * 0x34)) && (val_2 != 0)) {
          aiStack_404[local_420] = local_418;
          local_420 = local_420 + 1;
        }
        if ((*(int *)(&DAT_00701944 + local_418 * 8) ==
             *(int *)(&g_MasterCardTypeTable + arg_1 * 0x34)) && (val_1 != 0)) {
          aiStack_404[local_420] = local_418;
          local_420 = local_420 + 1;
        }
      }
    }
  }
  if (local_420 == 0) {
    val_1 = -1;
  }
  else {
    val_1 = Util_GetRandomNumber(local_420);
    val_1 = aiStack_404[val_1];
  }
  return val_1;
}

/*
 * Decompiled function: FUN_00407747
 * Entry Point: 00407747
 * Size: 103 bytes
 */


int32_t FUN_00407747(int player_id)

{
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (499 < slot_idx) {
      return 0;
    }
    if (*(int *)(&g_MasterCardTypeTable + (*(uint32_t *)(&deck + slot_idx * 4) & 0xfff) * 0x34) == arg_1)
    break;
    slot_idx = slot_idx + 1;
  }
  return 1;
}

/*
 * Decompiled function: FUN_004077ae
 * Entry Point: 004077ae
 * Size: 144 bytes
 */


char * FUN_004077ae(char *filepath)

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


char * FUN_00407843(char *filepath,char *mode_str,int event_type)

{
  int val_1;
  int32_t *u_ptr_2;
  char *local_114;
  int local_110;
  size_t local_10c;
  char *local_108;
  char local_104;
  int32_t local_103 [63];
  
  local_110 = 0;
  local_108 = str_1;
  local_104 = '\0';
  u_ptr_2 = local_103;
  for (val_1 = 0x3f; val_1 != 0; val_1 = val_1 + -1) {
    *u_ptr_2 = 0;
    u_ptr_2 = u_ptr_2 + 1;
  }
  *(int16_t *)u_ptr_2 = 0;
  *str_2 = '\0';
  while (local_114 = (char *)FUN_004077ae(local_108), local_114 != (char *)0x0) {
    local_10c = (int)local_114 - (int)local_108;
    val_1 = FUN_0050f610((int *)g_DisplaySurfaceScreen,local_108,local_10c);
    if (arg_3 < local_110 + val_1) {
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
      val_1 = FUN_0050f610((int *)g_DisplaySurfaceScreen,local_108,local_10c);
      local_110 = local_110 + val_1;
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
  val_1 = FUN_0050f440((int *)g_DisplaySurfaceScreen,local_108);
  if (arg_3 < local_110 + val_1) {
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
 * Decompiled function: UI_ProcessKeyboardInput
 * Entry Point: 00407e40
 * Size: 585 bytes
 */


void UI_ProcessKeyboardInput(int32_t arg1,uint32_t arg2)

{
  uint16_t uval_1;
  SHORT SVar2;
  SHORT SVar3;
  uint32_t uval_4;
  int *piVar5;
  uint32_t player_idx;
  uint32_t card_idx;
  uint32_t match_count;
  
  match_count = 0;
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
    uval_4 = (arg2 & 0xff0000) >> 0x10;
    SVar2 = GetAsyncKeyState(0x12);
    if (SVar2 == 0) {
      SVar2 = GetAsyncKeyState(0x11);
      if (SVar2 == 0) {
        piVar5 = (int *)__p___mb_cur_max();
        if (*piVar5 < 2) {
          uval_1 = *(uint16_t *)(&DAT_0051664a + uval_4 * 0x10);
          piVar5 = (int *)__p__pctype();
          player_idx = *(uint16_t *)(*piVar5 + (uval_1 & 0xff) * 2) & 0x103;
        }
        else {
          player_idx = _isctype(*(uint16_t *)(&DAT_0051664a + uval_4 * 0x10) & 0xff,0x103);
        }
        if (player_idx == 0) {
          if ((uval_4 < 0x47) || (0x53 < uval_4)) {
            SVar2 = GetAsyncKeyState(0x10);
            if (SVar2 != 0) {
              match_count = 1;
            }
          }
          else {
            SVar2 = GetAsyncKeyState(0x90);
            SVar3 = GetAsyncKeyState(0x10);
            match_count = (uint32_t)((SVar2 != 0) != (SVar3 != 0));
          }
        }
        else {
          SVar2 = GetAsyncKeyState(0x10);
          SVar3 = GetAsyncKeyState(0x14);
          match_count = (uint32_t)((SVar2 != 0) != (SVar3 != 0));
        }
      }
      else {
        match_count = 2;
      }
    }
    else {
      match_count = 3;
    }
    if (*(char *)(uval_4 * 0x10 + 0x516648 + match_count * 4) != '\0') {
      uval_1 = *(uint16_t *)(&DAT_0051664a + match_count * 4 + uval_4 * 0x10);
      card_idx = 0x32U - DAT_00516bdc;
      if ((int)(arg2 & 0xffff) <= (int)(0x32U - DAT_00516bdc)) {
        card_idx = arg2 & 0xffff;
      }
      while (card_idx != 0) {
        (&DAT_00538210)[DAT_00516bdc] = (uint32_t)uval_1;
        DAT_00516bdc = DAT_00516bdc + 1;
        card_idx = card_idx - 1;
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
 * Decompiled function: Util_CopyMemoryBuffer
 * Entry Point: 004080b2
 * Size: 93 bytes
 */


int32_t Util_CopyMemoryBuffer(void)

{
  int32_t uval_1;
  
  uval_1 = DAT_00538210;
  if (DAT_00516bdc == 0) {
    uval_1 = 0;
  }
  else {
    DAT_00516bdc = DAT_00516bdc + -1;
    if (DAT_00516bdc != 0) {
      memcpy(&DAT_00538210,&DAT_00538214,DAT_00516bdc * 4);
    }
  }
  return uval_1;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040810f
 * Entry Point: 0040810f
 * Size: 41 bytes
 */


int32_t Mem_AllocOrFree_0040810f(void)

{
  int32_t uval_1;
  
  if (DAT_00516bdc == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040813d
 * Entry Point: 0040813d
 * Size: 41 bytes
 */


int32_t Mem_AllocOrFree_0040813d(void)

{
  int32_t uval_1;
  
  uval_1 = DAT_00538210;
  if (DAT_00516bdc == 0) {
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Util_MoveMemoryBuffer
 * Entry Point: 0040816b
 * Size: 57 bytes
 */


void Util_MoveMemoryBuffer(int32_t arg_1)

{
  memmove(&DAT_00538214,&DAT_00538210,DAT_00516bdc << 2);
  DAT_00516bdc = DAT_00516bdc + 1;
  DAT_00538210 = arg_1;
  return;
}

/*
 * Decompiled function: UI_UnregisterCueCardClass
 * Entry Point: 004082d1
 * Size: 153 bytes
 */


void UI_UnregisterCueCardClass(void)

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
 * Decompiled function: UI_UpdateCueCardPosition
 * Entry Point: 004088d0
 * Size: 1068 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t UI_UpdateCueCardPosition(int *arg_1)

{
  POINT Point;
  BOOL BVar1;
  int val_2;
  int val_3;
  LRESULT LVar4;
  int32_t uval_5;
  tagPOINT local_f0;
  tagPOINT local_e8;
  HWND local_e0;
  int local_dc;
  char local_d8 [100];
  tagPOINT local_74;
  int local_6c;
  char local_68 [100];
  
  switch(arg_1[1]) {
  case 0x113:
    if ((*arg_1 == 0) && (arg_1[2] == DAT_006b2d8c)) {
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
      uval_5 = 1;
    }
    else {
      uval_5 = 0;
    }
    break;
  default:
    uval_5 = 0;
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
    else if (*arg_1 == DAT_00516be0) {
      local_6c = 1;
      local_dc = 1;
      if (*arg_1 == DAT_00516be0) {
        val_3 = abs(((uint32_t)arg_1[3] >> 0x10) - _DAT_00516bec);
        val_2 = abs(*(uint16_t *)(arg_1 + 3) - _DAT_00516be8);
        if (DAT_00695f10 < val_3 + val_2) {
          local_dc = SendMessageA((HWND)*arg_1,0x437,(WPARAM)local_68,arg_1[3]);
        }
        else {
          local_6c = 0;
        }
      }
      else {
        local_dc = SendMessageA((HWND)*arg_1,0x437,(WPARAM)local_68,arg_1[3]);
      }
      if (local_dc == 0) {
        ShowWindow(DAT_006b1570,0);
      }
      else if (local_6c != 0) {
        DAT_00516be0 = *arg_1;
        _DAT_00516be8 = (uint32_t)*(uint16_t *)(arg_1 + 3);
        _DAT_00516bec = (uint32_t)arg_1[3] >> 0x10;
        GetCursorPos(&local_74);
        if (DAT_006fe420 == 0) {
          ShowWindow(DAT_006b1570,0);
        }
        else {
          SendMessageA(DAT_006b1570,0x401,0,(LPARAM)local_d8);
          val_3 = strcmp(local_d8,local_68);
          if (val_3 != 0) {
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
      DAT_00516be0 = *arg_1;
      ShowWindow(DAT_006b1570,0);
    }
    uval_5 = 0;
    break;
  case 0x201:
  case 0x204:
  case 0x207:
    ShowWindow(DAT_006b1570,0);
    if (DAT_006b2d8c != 0) {
      KillTimer((HWND)0x0,DAT_006b2d8c);
      DAT_006b2d8c = 0;
    }
    uval_5 = 0;
  }
  return uval_5;
}

/*
 * Decompiled function: UI_UnregisterFaceClass
 * Entry Point: 00409052
 * Size: 164 bytes
 */


void UI_UnregisterFaceClass(void)

{
  int slot_idx;
  
  if (DAT_00538308 != (HMENU)0x0) {
    DestroyMenu(DAT_00538308);
  }
  DAT_00538308 = (HMENU)0x0;
  for (slot_idx = 0; slot_idx < 6; slot_idx = slot_idx + 1) {
    if (*(int *)(&DAT_00538310 + slot_idx * 4) != 0) {
      Pic_DestroyDIBSection(*(HANDLE *)(&DAT_00538310 + slot_idx * 4));
      *(int32_t *)(&DAT_00538310 + slot_idx * 4) = 0;
    }
  }
  if (DAT_0053830c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0053830c);
  }
  DAT_0053830c = (HGDIOBJ)0x0;
  return;
}

/*
 * Decompiled function: UI_RenderDuelStatusBanner
 * Entry Point: 004097e2
 * Size: 842 bytes
 */


void UI_RenderDuelStatusBanner(HDC hdc,RECT *arg_2,int event_type)

{
  HBRUSH hbr;
  char *char_ptr_1;
  size_t len_2;
  uint8_t local_7c [4];
  int local_78;
  int local_74;
  int local_64;
  tagRECT local_60;
  HANDLE local_50;
  tagPOINT local_4c;
  int local_44;
  HANDLE local_40;
  char local_3c [52];
  HWND slot_idx;
  
  if (arg_3 == 0) {
    slot_idx = DAT_0068a620;
  }
  else {
    slot_idx = DAT_006a49f0;
  }
  local_40 = (HANDLE)GetWindowLongA(slot_idx,0);
  if (arg_3 == 0) {
    local_50 = *(HANDLE *)(&DAT_00538310 + DAT_006a3f60 * 4);
  }
  else {
    local_50 = *(HANDLE *)(&DAT_00538310 + DAT_006fe490 * 4);
  }
  if (local_50 == (HANDLE)0x0) {
    hbr = GetStockObject(4);
    FillRect(hdc,arg_2,hbr);
  }
  else {
    FUN_004f3b5f((int)hdc,(int)arg_2,local_50);
  }
  if (local_40 != (HANDLE)0x0) {
    GetObjectA(local_40,0x18,local_7c);
    local_78 = local_78 / 2;
    local_64 = SaveDC(hdc);
    SetMapMode(hdc,7);
    SetWindowOrgEx(hdc,local_78 / 2,local_74 / 2,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,arg_2->left + (arg_2->right - arg_2->left) / 2,
                     arg_2->top + (arg_2->bottom - arg_2->top) / 2,(LPPOINT)0x0);
    SetWindowExtEx(hdc,local_78,local_74,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2->right - arg_2->left,arg_2->bottom - arg_2->top,(LPSIZE)0x0);
    SetRect(&local_60,0,0,local_78,local_74);
    FUN_004f3e29(hdc,&local_60,local_40);
    RestoreDC(hdc,local_64);
  }
  if (arg_3 == 1) {
    Ai_Subsystem_004b6f49(local_3c);
  }
  else {
    strcpy(local_3c,&DAT_0068a6a0);
    char_ptr_1 = strchr(local_3c,0x2d);
    if (char_ptr_1 != (char *)0x0) {
      char_ptr_1 = strchr(local_3c,0x2d);
      *char_ptr_1 = '\0';
    }
  }
  len_2 = strlen(local_3c);
  if (len_2 != 0) {
    local_44 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,arg_2->right - arg_2->left,100,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2->right - arg_2->left,arg_2->bottom - arg_2->top,(LPSIZE)0x0);
    SelectObject(hdc,DAT_0053830c);
    SetBkMode(hdc,1);
    SetTextAlign(hdc,0xe);
    local_4c.x = arg_2->left + (arg_2->right - arg_2->left) / 2;
    local_4c.y = arg_2->bottom;
    DPtoLP(hdc,&local_4c,1);
    SetTextColor(hdc,DAT_005382f4);
    len_2 = strlen(local_3c);
    TextOutA(hdc,local_4c.x + 1,local_4c.y + 1,local_3c,len_2);
    SetTextColor(hdc,DAT_005382f0);
    len_2 = strlen(local_3c);
    TextOutA(hdc,local_4c.x,local_4c.y,local_3c,len_2);
    RestoreDC(hdc,local_44);
  }
  return;
}

/*
 * Decompiled function: UI_ShowDuelArenaWindow
 * Entry Point: 00409b2c
 * Size: 327 bytes
 */


void UI_ShowDuelArenaWindow(int arg1,int arg2)

{
  HWND hWnd;
  HWND hWnd_00;
  HWND hWnd_01;
  HWND hWnd_02;
  int32_t match_count;
  
  if (arg1 == 0) {
    match_count = g_AiSelectedCardTargetSlot;
    hWnd = DAT_006b2e10;
    hWnd_00 = DAT_006fe48c;
    hWnd_01 = DAT_006b2530;
    hWnd_02 = DAT_0068a620;
  }
  else {
    match_count = DAT_006ff560;
    hWnd = DAT_006a4928;
    hWnd_00 = DAT_006ff388;
    hWnd_01 = DAT_006ff4a8;
    hWnd_02 = DAT_006a49f0;
  }
  if (arg2 == 0) {
    ShowWindow(hWnd_01,5);
    ShowWindow(hWnd_00,5);
    ShowWindow(hWnd,5);
    ShowWindow(match_count,5);
    ShowWindow(hWnd_02,0);
  }
  else {
    ShowWindow(hWnd_02,5);
    BringWindowToTop(hWnd_02);
    ShowWindow(hWnd_01,0);
    if (g_DuelArenaStatusFlags != 2) {
      ShowWindow(hWnd_00,0);
      ShowWindow(hWnd,0);
      ShowWindow(match_count,0);
    }
  }
  return;
}

/*
 * Decompiled function: UI_PostDuelArenaMessage
 * Entry Point: 00409c73
 * Size: 63 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UI_PostDuelArenaMessage(int32_t arg_1)

{
  _DAT_005382f8 = 0;
  _DAT_005382fc = arg_1;
  _DAT_00538300 = 0xffffffff;
  PostMessageA(g_MainAppHwnd,0x464,0,0x5382f8);
  return;
}

/*
 * Decompiled function: FUN_00409cb2
 * Entry Point: 00409cb2
 * Size: 74 bytes
 */


int32_t FUN_00409cb2(int player_id)

{
  int32_t uval_1;
  
  if (((arg_1 == 1) && (DAT_006fefa0 != 0)) || ((arg_1 == 0 && (DAT_006fefa4 != 0)))) {
    uval_1 = 1;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Subsystem_LoadStatWinDll
 * Entry Point: 00409d10
 * Size: 166 bytes
 */


int32_t Subsystem_LoadStatWinDll(void)

{
  int32_t uval_1;
  FARPROC pFVar2;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 3; slot_idx = slot_idx + 1) {
    (&DAT_00701020)[slot_idx] = 0;
  }
  DAT_00516ca8 = LoadLibraryA(s_statwin_dll_00516cac);
  if (DAT_00516ca8 == (HMODULE)0x0) {
    uval_1 = 1;
  }
  else {
    for (slot_idx = 0; slot_idx < 3; slot_idx = slot_idx + 1) {
      pFVar2 = GetProcAddress(DAT_00516ca8,(LPCSTR)(slot_idx + 1U & 0xffff));
      (&DAT_00701020)[slot_idx] = pFVar2;
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Subsystem_FreeStatWinDll
 * Entry Point: 00409db6
 * Size: 93 bytes
 */


void Subsystem_FreeStatWinDll(void)

{
  int slot_idx;
  
  if (DAT_00516ca8 != (HMODULE)0x0) {
    FreeLibrary(DAT_00516ca8);
    DAT_00516ca8 = (HMODULE)0x0;
  }
  for (slot_idx = 0; slot_idx < 3; slot_idx = slot_idx + 1) {
    (&DAT_00701020)[slot_idx] = 0;
  }
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_00409e13
 * Entry Point: 00409e13
 * Size: 41 bytes
 */


void Mem_AllocOrFree_00409e13(int32_t arg1,int32_t arg2)

{
  if (DAT_00701020 != (code *)0x0) {
    (*DAT_00701020)(arg1,arg2);
  }
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_00409e3c
 * Entry Point: 00409e3c
 * Size: 49 bytes
 */


int32_t Mem_AllocOrFree_00409e3c(int32_t arg_1)

{
  int32_t uval_1;
  
  if (DAT_00701024 == (code *)0x0) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_00701024)(arg_1);
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_00409e6d
 * Entry Point: 00409e6d
 * Size: 61 bytes
 */


int32_t FUN_00409e6d(int32_t arg_1,int32_t arg_2,int32_t arg_3,int32_t arg_4)

{
  int32_t uval_1;
  
  if (DAT_00701028 == (code *)0x0) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_00701028)(arg_1,arg_2,arg_3,arg_4);
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_00409eb0
 * Entry Point: 00409eb0
 * Size: 102 bytes
 */


void FUN_00409eb0(int player_id)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_00516cb8 + slot_idx * 8) =
         *(int32_t *)(&DAT_00516cb8 + slot_idx * 8 + arg_1 * 0x280);
    *(int32_t *)(&DAT_00516cbc + slot_idx * 8) =
         *(int32_t *)(&DAT_00516cbc + slot_idx * 8 + arg_1 * 0x280);
  }
  return;
}

/*
 * Decompiled function: FUN_00409f16
 * Entry Point: 00409f16
 * Size: 131 bytes
 */


void FUN_00409f16(int arg1,int arg2)

{
  int val_1;
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (0x4f < slot_idx) {
      return;
    }
    if ((0 < *(int *)(&DAT_00516cbc + slot_idx * 8 + arg1 * 0x280)) &&
       (val_1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00516cb8 + slot_idx * 8 + arg1 * 0x280)),
       val_1 == arg2)) break;
    slot_idx = slot_idx + 1;
  }
  *(int *)(&DAT_00516cbc + slot_idx * 8 + arg1 * 0x280) =
       *(int *)(&DAT_00516cbc + slot_idx * 8 + arg1 * 0x280) + -1;
  return;
}

/*
 * Decompiled function: FUN_00409f99
 * Entry Point: 00409f99
 * Size: 145 bytes
 */


void FUN_00409f99(char *filepath,int y,uint32_t width,int height)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_00516cbc + slot_idx * 8 + y * 0x280) = 0;
    *(int32_t *)(&DAT_00516cb8 + slot_idx * 8 + y * 0x280) =
         *(int32_t *)(&DAT_00516cbc + slot_idx * 8 + y * 0x280);
  }
  Deck_FilterAttributes_00406b4c(str_1,(int)(&DAT_00516cb8 + y * 0x280),width,height);
  return;
}

/*
 * Decompiled function: FUN_0040a02a
 * Entry Point: 0040a02a
 * Size: 324 bytes
 */


int FUN_0040a02a(int player_id)

{
  int val_1;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (arg_1 == -1) {
    val_1 = -1;
  }
  else {
    card_idx = 0;
    for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
      card_idx = card_idx + *(int *)(&DAT_00516cbc + slot_idx * 8 + arg_1 * 0x280);
    }
    if (card_idx == 0) {
      val_1 = -1;
    }
    else {
      match_count = Util_GetRandomNumber(card_idx);
      for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
        match_count = match_count - *(int *)(&DAT_00516cbc + slot_idx * 8 + arg_1 * 0x280);
        if (match_count < 0) {
          player_idx = *(int *)(&DAT_00516cb8 + slot_idx * 8 + arg_1 * 0x280);
          if (g_IsAiThinking != 1) {
            *(int *)(&DAT_00516cbc + slot_idx * 8 + arg_1 * 0x280) =
                 *(int *)(&DAT_00516cbc + slot_idx * 8 + arg_1 * 0x280) + -1;
          }
          break;
        }
      }
      for (slot_idx = 0;
          (val_1 = g_MasterCardCount, slot_idx < g_MasterCardCount &&
          (val_1 = slot_idx, *(int *)(&g_MasterCardTypeTable + slot_idx * 0x34) != player_idx));
          slot_idx = slot_idx + 1) {
      }
    }
  }
  return val_1;
}

/*
 * Decompiled function: UI_RenderOpponentLibraryPrompt
 * Entry Point: 0040a16e
 * Size: 53 bytes
 */


void UI_RenderOpponentLibraryPrompt(void)

{
  UI_DeckSelectionMenu(g_CurrentTurnPhase,0x69ef00,500,s_Opponent_library_005171bc,0);
  return;
}

/*
 * Decompiled function: UI_RenderPlayerLibraryPrompt
 * Entry Point: 0040a1a3
 * Size: 47 bytes
 */


void UI_RenderPlayerLibraryPrompt(void)

{
  UI_DeckSelectionMenu(g_CurrentTurnPhase,0x69e730,500,s_Your_Library_005171d4,0);
  return;
}

/*
 * Decompiled function: Util_GetRandomNumber
 * Entry Point: 0040a1d2
 * Size: 45 bytes
 */


int Util_GetRandomNumber(int player_id)

{
  int val_1;
  
  if (arg_1 < 2) {
    val_1 = 0;
  }
  else {
    val_1 = rand();
    val_1 = val_1 % arg_1;
  }
  return val_1;
}

/*
 * Decompiled function: Ai_SyncLookaheadBuffers
 * Entry Point: 0040a1ff
 * Size: 65 bytes
 */


void Ai_SyncLookaheadBuffers(void)

{
  int val_1;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 100; slot_idx = slot_idx + 1) {
    val_1 = rand();
    *(int *)(&DAT_00538338 + slot_idx * 4) = val_1;
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


uint32_t FUN_0040a255(uint32_t arg_1)

{
  uint32_t uval_1;
  
  if (DAT_00538334 < 100) {
    uval_1 = (int)(*(int *)(&DAT_00538338 + (DAT_00538334 % 100) * 4) * arg_1) >> 0xf;
  }
  else {
    uval_1 = DAT_00538334 % arg_1;
  }
  DAT_00538334 = DAT_00538334 + 1;
  return uval_1;
}

/*
 * Decompiled function: Util_SeedRandomGenerator
 * Entry Point: 0040a2c0
 * Size: 69 bytes
 */


int32_t Util_SeedRandomGenerator(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  DAT_00701018 = DVar1 & 0x7fff;
  srand(DAT_00701018 * 0x43);
  DAT_00701014 = 1;
  return 0;
}

/*
 * Decompiled function: FUN_0040a305
 * Entry Point: 0040a305
 * Size: 55 bytes
 */


int FUN_0040a305(int player_id,int card_slot,int event_type)

{
  if (arg_1 < arg_2) {
    arg_1 = arg_2;
  }
  if (arg_3 < arg_1) {
    arg_1 = arg_3;
  }
  return arg_1;
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


int FUN_0040a36f(int arg1,int arg2)

{
  int32_t slot_idx;
  
  if (arg1 < 0) {
    arg1 = -arg1;
  }
  if (arg2 < 0) {
    arg2 = -arg2;
  }
  if (arg2 < arg1) {
    slot_idx = arg1 * 2 + arg2;
  }
  else {
    slot_idx = arg2 * 2 + arg1;
  }
  if (slot_idx < 0) {
    slot_idx = 0x7ffe;
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0040a3e1
 * Entry Point: 0040a3e1
 * Size: 65 bytes
 */


void FUN_0040a3e1(void)

{
  int val_1;
  
  val_1 = DAT_005239ec;
  while (val_1 != 0) {
    Pic_Subsystem_0044b84b();
    val_1 = g_CombatAttackerSlotIndex;
  }
  while (val_1 = Mem_AllocOrFree_00408089(), val_1 != 0) {
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
  int val_1;
  
  while( true ) {
    val_1 = Mem_AllocOrFree_00408089();
    if (val_1 == 0) break;
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
  int val_1;
  int32_t slot_idx;
  
  if (g_IsAiThinking == 0) {
    do {
      Pic_Subsystem_0044b84b();
      if (g_CombatAttackerSlotIndex != 0) break;
      val_1 = Mem_AllocOrFree_00408089();
    } while (val_1 == 0);
    slot_idx = g_CombatAttackerSlotIndex;
    if (g_CombatAttackerSlotIndex == 0) {
      slot_idx = FUN_0048ac2f();
    }
    FUN_0040a3e1();
  }
  else {
    slot_idx = 0;
  }
  return slot_idx;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040a4ac
 * Entry Point: 0040a4ac
 * Size: 40 bytes
 */


void Mem_AllocOrFree_0040a4ac(void *arg_1,void *arg_2,size_t arg_3)

{
  memcpy(arg_2,arg_1,arg_3);
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040a4d4
 * Entry Point: 0040a4d4
 * Size: 40 bytes
 */


void Mem_AllocOrFree_0040a4d4(void *arg_1,void *arg_2,size_t arg_3)

{
  memcpy(arg_2,arg_1,arg_3);
  return;
}

/*
 * Decompiled function: Pic_Load_advfac64_0040a4fc
 * Entry Point: 0040a4fc
 * Size: 106 bytes
 */


int32_t Pic_Load_advfac64_0040a4fc(void)

{
  SetFocus(_hwndScreen);
  LoadPalNoPic(s_advfac64_pic_005171e4);
  Catalog_LoadPaletteMap(s_todpal_tr_005171f4,(char *)0x0);
  SelectPalette(*(HDC *)(g_ScreenSurfaces + 4),_hLibPal,0);
  RealizePalette(*(HDC *)(g_ScreenSurfaces + 4));
  FUN_0040a566();
  FUN_0040a3e1();
  return 0;
}

/*
 * Decompiled function: FUN_0040a566
 * Entry Point: 0040a566
 * Size: 120 bytes
 */


int32_t FUN_0040a566(void)

{
  int slot_idx;
  
  DAT_0067bde8 = 0;
  DAT_0067f3b8 = 0;
  for (slot_idx = 0; slot_idx < 500; slot_idx = slot_idx + 1) {
    if ((*(int *)(&deck + slot_idx * 4) != -1) &&
       (DAT_0067bde8 = DAT_0067bde8 + 1, ((&DAT_00702151)[slot_idx * 4] & 0x40) == 0)) {
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
  int32_t slot_idx;
  
  FUN_0050dce0((int *)g_DisplaySurfaceScreen,(int)g_AiManaColorCost_Red / 2 - 0x50,
               (int)g_AiManaColorCost_Green / 3 + -0x3c,0xa0,0x78,(int *)g_DisplaySurfaceBackBuffer,0,0);
  for (slot_idx = 3; slot_idx < 9; slot_idx = slot_idx + 1) {
    arg_9 = (int)(g_AiManaColorCost_Red * slot_idx + ((int)(g_AiManaColorCost_Red * slot_idx) >> 0x1f & 7U)) >> 3;
    arg_10 = (int)(g_AiManaColorCost_Green * slot_idx + ((int)(g_AiManaColorCost_Green * slot_idx) >> 0x1f & 7U)) >> 3;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0xa0,0x78,(int *)g_DisplaySurfaceScreen
                       ,(int)g_AiManaColorCost_Red / 2 - arg_9 / 2,
                       (((int)g_AiManaColorCost_Green / 3) * (8 - slot_idx) +
                       ((int)g_AiManaColorCost_Green / 2) * (slot_idx + -2)) / 6 - arg_10 / 2,arg_9,arg_10);
  }
  FUN_0050dce0((int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
               (int *)g_DisplaySurfaceBackBuffer,0,0);
  FUN_0040a3e1();
  return;
}

/*
 * Decompiled function: FUN_0040a725
 * Entry Point: 0040a725
 * Size: 350 bytes
 */


void FUN_0040a725(char *arg_1)

{
  int arg_9;
  int arg_10;
  int32_t slot_idx;
  
  Mem_AllocOrFree_00510e20(1,arg_1);
  *(int32_t *)g_DisplaySurfaceScreen = 1;
  FUN_0048a2a5(0,0,0x13f,199,0xff);
  *(int32_t *)g_DisplaySurfaceScreen = 0;
  for (slot_idx = 2; slot_idx < 9; slot_idx = slot_idx + 1) {
    arg_9 = (int)(g_AiManaColorCost_Red * slot_idx + ((int)(g_AiManaColorCost_Red * slot_idx) >> 0x1f & 7U)) >> 3;
    arg_10 = (int)(g_AiManaColorCost_Green * slot_idx + ((int)(g_AiManaColorCost_Green * slot_idx) >> 0x1f & 7U)) >> 3;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x140,200,(int *)g_DisplaySurfaceScreen
                       ,(int)g_AiManaColorCost_Red / 2 - arg_9 / 2,
                       (((int)g_AiManaColorCost_Green / 3) * (8 - slot_idx) +
                       (slot_idx + -2) * ((int)g_AiManaColorCost_Green / 2)) / 6 - arg_10 / 2,arg_9,arg_10);
    FUN_00501736((int)((10 - slot_idx) + (10 - slot_idx >> 0x1f & 3U)) >> 2);
  }
  FUN_0050dce0((int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
               (int *)g_DisplaySurfaceBackBuffer,0,0);
  return;
}

/*
 * Decompiled function: FUN_0040a883
 * Entry Point: 0040a883
 * Size: 218 bytes
 */


void FUN_0040a883(char *arg_1)

{
  uint32_t arg_2;
  int arg_8;
  uint32_t arg_4;
  DWORD arg_5;
  
  arg_2 = Ai_Util_004c3bc4(0x40);
  arg_8 = Ai_Util_004c3bc4(0x30);
  arg_4 = Ai_Util_004c3bc4(0x200);
  arg_5 = Ai_Util_004c3bc4(0x118);
  FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green + -0x118,arg_1,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_8,arg_4,arg_5);
  FUN_0050b9d5(g_DisplaySurfaceBackBuffer);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2,arg_8,arg_4,arg_5,
               (int *)g_DisplaySurfaceScreen,arg_2,arg_8);
  return;
}

/*
 * Decompiled function: FUN_0040a95d
 * Entry Point: 0040a95d
 * Size: 404 bytes
 */


void FUN_0040a95d(char *arg_1)

{
  int event_type;
  int arg_9;
  int arg_10;
  int val_1;
  int arg_9_00;
  int arg_10_00;
  int32_t target_idx;
  
  arg_3 = g_AiManaColorCost_Green + -0x118;
  FileIO_OpenFileStream(1,0,arg_3,arg_1,(short *)0x0);
  arg_9 = Ai_Util_004c3ba3(0x100);
  arg_10 = Ai_Util_004c3ba3(0x8c);
  val_1 = Ai_Util_004c3ba3(0x5e);
  for (target_idx = 2; target_idx < 9; target_idx = target_idx + 1) {
    arg_9_00 = (int)(target_idx * arg_9 + (target_idx * arg_9 >> 0x1f & 7U)) >> 3;
    arg_10_00 = (int)(target_idx * arg_10 + (target_idx * arg_10 >> 0x1f & 7U)) >> 3;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,arg_3,0x200,0x118,
                       (int *)g_DisplaySurfaceScreen,g_AiManaColorCost_Red / 2 - arg_9_00 / 2,
                       val_1 - arg_10_00 / 2,arg_9_00,arg_10_00);
  }
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,arg_3,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,g_AiManaColorCost_Red / 2 - arg_9 / 2,
                     val_1 - arg_10 / 2,arg_9,arg_10);
  FUN_0050b9d5(g_DisplaySurfaceScreen);
  return;
}

/*
 * Decompiled function: FUN_0040aaf1
 * Entry Point: 0040aaf1
 * Size: 264 bytes
 */


void FUN_0040aaf1(char *arg_1)

{
  int val_1;
  int val_2;
  int arg_7;
  int arg_8;
  int arg_9;
  int arg_10;
  
  arg_7 = Ai_Util_004c3bc4(0x40);
  arg_8 = Ai_Util_004c3bc4(0x30);
  arg_9 = Ai_Util_004c3bc4(0x200);
  arg_10 = Ai_Util_004c3bc4(0x118);
  val_1 = (&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceBackBuffer];
  val_2 = (&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceScreen];
  FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green + -0x118,arg_1,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,arg_7,arg_8,arg_9,arg_10);
  FUN_0050b9d5(g_DisplaySurfaceBackBuffer);
  FUN_00511e20(*(HDC *)(val_2 + 4),arg_7,arg_8,arg_9,arg_10,0x20,3,8,8,*(HDC *)(val_1 + 4));
  FUN_00501736(0x2d);
  return;
}

/*
 * Decompiled function: FUN_0040abf9
 * Entry Point: 0040abf9
 * Size: 260 bytes
 */


void FUN_0040abf9(char *arg_1)

{
  int val_1;
  int val_2;
  int arg_7;
  int arg_8;
  int arg_9;
  int arg_10;
  
  arg_7 = Ai_Util_004c3bc4(0x40);
  arg_8 = Ai_Util_004c3bc4(0x30);
  arg_9 = Ai_Util_004c3bc4(0x200);
  arg_10 = Ai_Util_004c3bc4(0x118);
  val_1 = (&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceBackBuffer];
  val_2 = (&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceScreen];
  FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green + -0x118,arg_1,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,arg_7,arg_8,arg_9,arg_10);
  FUN_0050b9d5(g_DisplaySurfaceBackBuffer);
  FUN_005119e0(*(HDC *)(val_2 + 4),arg_7,arg_8,arg_9,arg_10,5,5,*(HDC *)(val_1 + 4));
  FUN_00501736(0x2d);
  return;
}

/*
 * Decompiled function: FUN_0040acfd
 * Entry Point: 0040acfd
 * Size: 178 bytes
 */


void FUN_0040acfd(char *arg_1)

{
  int val_1;
  int val_2;
  
  val_1 = (&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceBackBuffer];
  val_2 = (&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceScreen];
  FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green + -0x1e0,arg_1,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green + -0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  FUN_005119e0(*(HDC *)(val_2 + 4),0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,8,8,*(HDC *)(val_1 + 4));
  return;
}

/*
 * Decompiled function: FUN_0040adaf
 * Entry Point: 0040adaf
 * Size: 182 bytes
 */


void FUN_0040adaf(char *arg_1,int card_slot,int event_type)

{
  int val_1;
  int val_2;
  
  val_1 = (&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceBackBuffer];
  val_2 = (&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceScreen];
  FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green + -0x1e0,arg_1,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,g_AiManaColorCost_Green + -0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  FUN_005119e0(*(HDC *)(val_2 + 4),0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,arg_2,arg_3,*(HDC *)(val_1 + 4));
  return;
}

/*
 * Decompiled function: FUN_0040ae70
 * Entry Point: 0040ae70
 * Size: 407 bytes
 */


int32_t FUN_0040ae70(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  int local_28;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    if (arg2 == 0) {
      local_28 = 0;
    }
    else if (arg2 == 1) {
      local_28 = 1;
    }
    else if (arg2 == 2) {
      local_28 = 2;
    }
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,DAT_00517210,DAT_00517214,DAT_00517218,
                      DAT_0051721c,(&DAT_00641890)[local_28 + DAT_0051722c * 3]);
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0040b03e
 * Entry Point: 0040b03e
 * Size: 261 bytes
 */


int32_t FUN_0040b03e(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0040b143
 * Entry Point: 0040b143
 * Size: 389 bytes
 */


int32_t FUN_0040b143(int player_id)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  int arg_6;
  int val_5;
  int val_6;
  
  arg_6 = DAT_006498e4;
  val_1 = *(int *)(arg_1 + 0x30);
  Pic_Subsystem_0044b84b();
  val_5 = *(int *)(arg_1 + 0x14) + *(int *)(arg_1 + 0x70) / 2;
  if (val_5 <= g_MouseScreenCoordY) {
    val_5 = g_MouseScreenCoordY;
  }
  val_6 = (*(int *)(arg_1 + 0x14) + *(int *)(arg_1 + 0x1c)) - *(int *)(arg_1 + 0x70) / 2;
  if (val_5 <= val_6) {
    val_6 = val_5;
  }
  val_5 = *(int *)(arg_1 + 0x14);
  val_2 = *(int *)(arg_1 + 0x70);
  val_3 = *(int *)(arg_1 + 0x1c);
  val_4 = *(int *)(arg_1 + 0x70);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
                    *(int *)(arg_1 + 0x18),*(int *)(arg_1 + 0x1c),DAT_00641878);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(arg_1 + 0x10),
                    val_6 - *(int *)(arg_1 + 0x70) / 2,*(int *)(arg_1 + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(arg_1 + 0x18)) / *(int *)(arg_1 + 8),
                    arg_6);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,*(uint32_t *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
               *(uint32_t *)(arg_1 + 0x18),*(DWORD *)(arg_1 + 0x1c),(int *)g_DisplaySurfaceScreen,
               *(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14));
  Castle_Process_0040b7fa((((val_6 - val_5) - val_2 / 2) * val_1) / (val_3 - val_4));
  DAT_005384d0 = *(int32_t *)(arg_1 + 0x2c);
  return *(int32_t *)(arg_1 + 0x2c);
}

/*
 * Decompiled function: FUN_0040b2c8
 * Entry Point: 0040b2c8
 * Size: 250 bytes
 */


int32_t FUN_0040b2c8(int player_id)

{
  int val_1;
  int val_2;
  int arg_6;
  
  arg_6 = DAT_006498e4;
  val_1 = *(int *)(arg_1 + 0x70);
  val_2 = *(int *)(arg_1 + 0x14);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
                    *(int *)(arg_1 + 0x18),*(int *)(arg_1 + 0x1c),DAT_00641878);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(arg_1 + 0x10),
                    (val_2 + val_1 / 2) - *(int *)(arg_1 + 0x70) / 2,*(int *)(arg_1 + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(arg_1 + 0x18)) / *(int *)(arg_1 + 8),
                    arg_6);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,*(uint32_t *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
               *(uint32_t *)(arg_1 + 0x18),*(DWORD *)(arg_1 + 0x1c),(int *)g_DisplaySurfaceScreen,
               *(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14));
  return 0;
}

/*
 * Decompiled function: FUN_0040b3c2
 * Entry Point: 0040b3c2
 * Size: 127 bytes
 */


void FUN_0040b3c2(int32_t arg1,int32_t arg2)

{
  if (DAT_0067bde0 < 0x100) {
    *(int32_t *)(&DAT_0067a9a0 + DAT_0067bde0 * 0x10) = arg1;
    *(int32_t *)(&DAT_0067a9a4 + DAT_0067bde0 * 0x10) = arg2;
    *(int *)(&DAT_0067a9a8 + DAT_0067bde0 * 0x10) =
         (int)(g_OverworldMapPixelX + (g_OverworldMapPixelX >> 0x1f & 0x1fU)) >> 5;
    *(int *)(&DAT_0067a9ac + DAT_0067bde0 * 0x10) =
         (int)(g_OverworldMapPixelY + (g_OverworldMapPixelY >> 0x1f & 0x1fU)) >> 5;
    DAT_0067bde0 = DAT_0067bde0 + 1;
  }
  return;
}

/*
 * Decompiled function: FUN_0040b441
 * Entry Point: 0040b441
 * Size: 167 bytes
 */


void FUN_0040b441(int *arg1,int arg2)

{
  int val_1;
  int slot_idx;
  
  if ((g_AiManaColorCost_Red != 0x280) && (arg1[4] == *arg1)) {
    for (slot_idx = 0; slot_idx < arg2; slot_idx = slot_idx + 1) {
      val_1 = Ai_Util_004c3bc4(arg1[4]);
      arg1[4] = val_1;
      val_1 = Ai_Util_004c3bc4(arg1[5]);
      arg1[5] = val_1;
      val_1 = Ai_Util_004c3bc4(arg1[6]);
      arg1[6] = val_1;
      val_1 = Ai_Util_004c3bc4(arg1[7]);
      arg1[7] = val_1;
      arg1 = arg1 + 0x15;
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
  int val_1;
  int val_2;
  int color_idx;
  
  Ai_CastleEncounter_004c24b3(4);
  FUN_0050dce0((int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
               (int *)g_DisplaySurfaceBackBuffer,0,0);
  DAT_005384e0 = 0xffffffff;
  DAT_005384dc = 0xffffffff;
  for (color_idx = 0; (color_idx < 10000 && (*(int *)(&DAT_0067a9a0 + color_idx * 0x10) != 0));
      color_idx = color_idx + 1) {
  }
  DAT_005384d8 = color_idx;
  _DAT_00517284 = color_idx;
  DAT_005384d4 = -1;
  FUN_0040b441((int *)&DAT_00517200,3);
  val_1 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(val_1);
  _DAT_005172e8 = 3;
  FUN_0041f17e(0x517200,3,val_1);
  g_MouseCaptureFlag = 1;
  *(int32_t *)g_DisplaySurfaceScreen = 1;
  FUN_0040ae70(0x517200,0);
  FUN_0040b2c8(0x517254);
  g_MouseCaptureFlag = 0;
  *(int32_t *)g_DisplaySurfaceScreen = 0;
  Castle_Process_0040b7fa(0);
  do {
    Mem_AllocOrFree_005016f9();
    DAT_005384d0 = -1;
    while (DAT_005384d0 == -1) {
      val_1 = Mem_AllocOrFree_00501721();
      val_2 = Mem_AllocOrFree_00501721();
      if (val_2 % 10 == 0 && val_1 % 0x14 == 0) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,DAT_005384c8 + -2,DAT_005384cc + -2,5,5,0xff)
        ;
      }
      val_1 = Mem_AllocOrFree_00501721();
      val_2 = Mem_AllocOrFree_00501721();
      if ((val_2 % 0x14 & (uint32_t)(val_1 % 10 == 0)) != 0) {
        FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,DAT_005384c8 - 2,DAT_005384cc + -2,5,5,
                     (int *)g_DisplaySurfaceScreen,DAT_005384c8,DAT_005384cc);
      }
      Pic_Subsystem_0044b84b();
      FUN_0041f3ea(g_MouseScreenCoordX,g_MouseScreenCoordY,g_MouseCursorButtonState);
      if ((DAT_005384d0 == -1) &&
         ((g_MouseCursorButtonState != 0 || (val_1 = Mem_AllocOrFree_0040810f(), val_1 == 0)))) {
        val_1 = Util_CopyMemoryBuffer();
        if (((g_MouseCursorButtonState & 1) == 0) && (val_1 != 0x5000)) {
          if (((g_MouseCursorButtonState & 2) != 0) || (val_1 == 0x4800)) {
            Castle_Process_0040b7fa(DAT_005384d4 + -1);
          }
        }
        else {
          Castle_Process_0040b7fa(DAT_005384d4 + 1);
        }
        FUN_0040a3e1();
      }
    }
  } while (DAT_005384d0 == 1);
  if (DAT_005384d0 == 4) {
    FUN_0040a3e1();
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


void FUN_0040bcff(uint32_t arg1,uint32_t arg2)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  uint32_t player_idx;
  uint32_t card_idx;
  uint32_t match_count;
  uint32_t slot_idx;
  
  if (DAT_005384dc == -1) {
    DAT_005384dc = arg1;
    DAT_005384e0 = arg2;
    Ai_Subsystem_004c3aa1(arg1,arg2,(int *)&match_count,(int *)&player_idx);
    match_count = (int)(match_count * g_AiManaColorCost_Red) / 0x280;
    player_idx = (int)(player_idx * g_AiManaColorCost_Green) / 0x1e0;
    val_1 = Ai_Util_004c3bc4(0x40);
    player_idx = player_idx + val_1;
  }
  else {
    Ai_Subsystem_004c3aa1(DAT_005384dc,DAT_005384e0,(int *)&slot_idx,(int *)&card_idx);
    slot_idx = (int)(slot_idx * g_AiManaColorCost_Red) / 0x280;
    card_idx = (int)(card_idx * g_AiManaColorCost_Green) / 0x1e0;
    val_1 = Ai_Util_004c3bc4(0x40);
    card_idx = card_idx + val_1;
    Ai_Subsystem_004c3aa1(arg1,arg2,(int *)&match_count,(int *)&player_idx);
    match_count = (int)(match_count * g_AiManaColorCost_Red) / 0x280;
    player_idx = (int)(player_idx * g_AiManaColorCost_Green) / 0x1e0;
    val_1 = Ai_Util_004c3bc4(0x40);
    player_idx = player_idx + val_1;
    DAT_005384dc = arg1;
    DAT_005384e0 = arg2;
    val_1 = match_count - slot_idx;
    val_4 = player_idx - card_idx;
    arg1 = slot_idx;
    arg2 = card_idx;
    val_2 = abs(val_4);
    val_3 = abs(val_1);
    if (val_2 < val_3) {
      while (match_count != arg1) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,arg1,arg2,2,2,0xff);
        FUN_00501736(5);
        if ((arg1 & 1) == 0) {
          FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg1,arg2,2,2,(int *)g_DisplaySurfaceScreen
                       ,arg1,arg2);
        }
        else {
          Surface_FillRect((int *)g_DisplaySurfaceScreen,arg1,arg2,2,2,0);
        }
        val_2 = FUN_0040a33c(val_1);
        arg1 = arg1 + val_2;
        val_2 = abs(arg1 - slot_idx);
        val_3 = abs(val_1);
        arg2 = card_idx + (val_2 * val_4) / val_3;
      }
    }
    else {
      while (player_idx != arg2) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,arg1,arg2,2,2,0xff);
        FUN_00501736(5);
        if ((arg2 & 1) == 0) {
          FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg1,arg2,2,2,(int *)g_DisplaySurfaceScreen
                       ,arg1,arg2);
        }
        else {
          Surface_FillRect((int *)g_DisplaySurfaceScreen,arg1,arg2,2,2,0);
        }
        val_2 = FUN_0040a33c(val_4);
        arg2 = arg2 + val_2;
        val_2 = abs(arg2 - card_idx);
        val_3 = abs(val_4);
        arg1 = slot_idx + (val_2 * val_1) / val_3;
      }
    }
  }
  DAT_005384c8 = match_count;
  DAT_005384cc = player_idx;
  if (g_OverworldWorldState != '\0') {
    FUN_0040a305(match_count - 0x50,0,0xa0);
    FUN_0040a305(player_idx - 10,0,0xbf);
    val_1 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
    val_4 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    *(int32_t *)(g_DisplaySurfaceWork + 0x20) = *(int32_t *)(g_DisplaySurfaceScreen + 0x20);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,(match_count - 2) - val_1 / 2,player_idx - 2,val_1 + 2,
                 val_4 + 2,(int *)g_DisplaySurfaceWork,0,0xa0);
    Ai_Subsystem_004c2340((int32_t *)g_DisplaySurfaceWork,0,0xa0,val_1 + 2,val_4 + 2,0x3f3f3f,1);
    FUN_0040d269((int)g_DisplaySurfaceWork,0xff,val_1 / 2 + 1,val_4 / 2 + 0xa1);
    FUN_0050dce0((int *)g_DisplaySurfaceWork,0,0xa0,val_1 + 2,val_4 + 2,
                 (int *)g_DisplaySurfaceScreen,(match_count - 2) - val_1 / 2,player_idx - 2);
  }
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040c180
 * Entry Point: 0040c180
 * Size: 45 bytes
 */


void Mem_AllocOrFree_0040c180(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  Surface_DrawLine((int *)g_DisplaySurfaceScreen,arg_1,arg_2,arg_3,arg_4,arg_5);
  return;
}

/*
 * Decompiled function: FUN_0040c1ad
 * Entry Point: 0040c1ad
 * Size: 199 bytes
 */


void FUN_0040c1ad(char *arg_1,int y,int width,int32_t arg_4)

{
  int val_1;
  int val_2;
  
  if (y < 0) {
    y = 0;
  }
  if (width < 0) {
    width = 0;
  }
  val_1 = FUN_0040c465(arg_1);
  if (g_AiManaColorCost_Red <= y + val_1) {
    val_2 = g_AiManaColorCost_Red + -1;
    val_1 = FUN_0040c465(arg_1);
    y = val_2 - val_1;
  }
  val_1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  if (g_AiManaColorCost_Green <= width + val_1) {
    val_2 = g_AiManaColorCost_Green + -1;
    val_1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    width = val_2 - val_1;
  }
  *(int32_t *)(g_DisplaySurfaceScreen + 0x18) = arg_4;
  FUN_0050f820((int *)g_DisplaySurfaceScreen,y,width,arg_1);
  return;
}

/*
 * Decompiled function: FUN_0040c274
 * Entry Point: 0040c274
 * Size: 59 bytes
 */


void FUN_0040c274(int32_t arg_1,int y,int width,int32_t arg_4)

{
  *(int32_t *)(g_DisplaySurfaceScreen + 0x14) = 0;
  FUN_0040c1ad(arg_1,y,width,arg_4);
  *(int32_t *)(g_DisplaySurfaceScreen + 0x14) = 1;
  return;
}

/*
 * Decompiled function: FUN_0040c2af
 * Entry Point: 0040c2af
 * Size: 58 bytes
 */


void FUN_0040c2af(int32_t arg_1,int y,int width,int32_t arg_4)

{
  FUN_0040c274(arg_1,y,width + 1,0);
  FUN_0040c274(arg_1,y,width,arg_4);
  return;
}

/*
 * Decompiled function: FUN_0040c2e9
 * Entry Point: 0040c2e9
 * Size: 77 bytes
 */


void FUN_0040c2e9(int32_t arg_1,int y,int width,int32_t arg_4)

{
  UI_DrawCombatString(arg_1,(y * g_AiManaColorCost_Red) / 0x140,(width * g_AiManaColorCost_Green) / 0xf0,arg_4);
  return;
}

/*
 * Decompiled function: FUN_0040c336
 * Entry Point: 0040c336
 * Size: 75 bytes
 */


void FUN_0040c336(int32_t arg_1,int y,int width,int arg_4)

{
  FUN_0040c421(arg_1,(g_AiManaColorCost_Red * y) / 0x140,(g_AiManaColorCost_Green * width) / 0xf0,arg_4);
  return;
}

/*
 * Decompiled function: FUN_0040c381
 * Entry Point: 0040c381
 * Size: 75 bytes
 */


void FUN_0040c381(int32_t arg_1,int y,int width,int32_t arg_4)

{
  FUN_0040c274(arg_1,(g_AiManaColorCost_Red * y) / 0x140,(g_AiManaColorCost_Green * width) / 0xf0,arg_4);
  return;
}

/*
 * Decompiled function: UI_DrawCombatString
 * Entry Point: 0040c3cc
 * Size: 85 bytes
 */


void UI_DrawCombatString(char *arg_1,int y,int width,int32_t arg_4)

{
  int val_1;
  
  val_1 = FUN_0040c465(arg_1);
  *(int32_t *)(g_DisplaySurfaceScreen + 0x14) = 0;
  FUN_0040c1ad(arg_1,y - val_1 / 2,width,arg_4);
  *(int32_t *)(g_DisplaySurfaceScreen + 0x14) = 1;
  return;
}

/*
 * Decompiled function: FUN_0040c421
 * Entry Point: 0040c421
 * Size: 68 bytes
 */


void FUN_0040c421(int32_t arg_1,int y,int width,int height)

{
  if (height != 0) {
    UI_DrawCombatString(arg_1,y,width + 1,0);
  }
  UI_DrawCombatString(arg_1,y,width,height);
  return;
}

/*
 * Decompiled function: FUN_0040c465
 * Entry Point: 0040c465
 * Size: 96 bytes
 */


int FUN_0040c465(char *filepath)

{
  int arg1;
  int val_1;
  int card_idx;
  char *match_count;
  
  match_count = str_1;
  arg1 = *(int *)(g_DisplaySurfaceScreen + 0x20);
  card_idx = 0;
  while (*match_count != '\0') {
    val_1 = FUN_0050f390(arg1,*match_count);
    card_idx = card_idx + val_1;
    match_count = match_count + 1;
  }
  return card_idx;
}

/*
 * Decompiled function: FUN_0040c4c5
 * Entry Point: 0040c4c5
 * Size: 139 bytes
 */


void FUN_0040c4c5(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,int *arg_6,int arg_7,int arg_8)

{
  FUN_0050dce0(arg_1,(arg_2 * g_AiManaColorCost_Red) / 0x140,(arg_3 * g_AiManaColorCost_Green) / 0xf0,
               (arg_4 * g_AiManaColorCost_Red) / 0x140,(arg_5 * g_AiManaColorCost_Green) / 0xf0,arg_6,
               (g_AiManaColorCost_Red * arg_7) / 0x140,(g_AiManaColorCost_Green * arg_8) / 0xf0);
  return;
}

/*
 * Decompiled function: FUN_0040c550
 * Entry Point: 0040c550
 * Size: 137 bytes
 */


void FUN_0040c550(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,int *arg_6,int arg_7,int arg_8)

{
  FUN_0050dce0(arg_1,(g_AiManaColorCost_Red * arg_2) / 0x140,(g_AiManaColorCost_Green * arg_3) / 0xf0,
               (g_AiManaColorCost_Red * arg_4) / 0x140,(g_AiManaColorCost_Green * arg_5) / 0xf0,arg_6,
               (arg_7 * g_AiManaColorCost_Red) / 0x140,(arg_8 * g_AiManaColorCost_Green) / 0xf0);
  return;
}

/*
 * Decompiled function: FUN_0040c5d9
 * Entry Point: 0040c5d9
 * Size: 137 bytes
 */


void FUN_0040c5d9(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,int *arg_6,int arg_7,int arg_8)

{
  FUN_0050e040(arg_1,(arg_2 * g_AiManaColorCost_Red) / 0x140,(arg_3 * g_AiManaColorCost_Green) / 0xf0,
               (g_AiManaColorCost_Red * arg_4) / 0x140,(g_AiManaColorCost_Green * arg_5) / 0xf0,arg_6,
               (g_AiManaColorCost_Red * arg_7) / 0x140,(g_AiManaColorCost_Green * arg_8) / 0xf0);
  return;
}

/*
 * Decompiled function: FUN_0040c662
 * Entry Point: 0040c662
 * Size: 101 bytes
 */


void FUN_0040c662(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,uint32_t arg_6)

{
  Surface_FillRect(arg_1,(g_AiManaColorCost_Red * arg_2) / 0x140,(g_AiManaColorCost_Green * arg_3) / 0xf0,
                   (arg_4 * g_AiManaColorCost_Red) / 0x140,(arg_5 * g_AiManaColorCost_Green) / 0xf0,arg_6);
  return;
}

/*
 * Decompiled function: FUN_0040c6c7
 * Entry Point: 0040c6c7
 * Size: 101 bytes
 */


void FUN_0040c6c7(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,int arg_6)

{
  Sprite_DrawScaled(arg_1,(arg_2 * g_AiManaColorCost_Red) / 0x140,(arg_3 * g_AiManaColorCost_Green) / 0xf0,
                    (g_AiManaColorCost_Red * arg_4) / 0x140,(g_AiManaColorCost_Green * arg_5) / 0xf0,arg_6);
  return;
}

/*
 * Decompiled function: FUN_0040c72c
 * Entry Point: 0040c72c
 * Size: 53 bytes
 */


void FUN_0040c72c(int player_id,int card_slot,int event_type,int arg_4,uint32_t arg_5)

{
  Surface_FillRect((int *)g_DisplaySurfaceScreen,arg_1,arg_2,(arg_3 - arg_1) + 1,(arg_4 - arg_2) + 1
                   ,arg_5);
  return;
}

/*
 * Decompiled function: FUN_0040c761
 * Entry Point: 0040c761
 * Size: 95 bytes
 */


uint32_t FUN_0040c761(int arg1,int arg2)

{
  uint32_t uval_1;
  
  if ((0x3f < arg1) || (arg1 < 0)) {
    arg1 = 0;
  }
  if ((0x3f < arg2) || (arg2 < 0)) {
    arg2 = 0;
  }
  uval_1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg1,arg2);
  return uval_1 & 0xf;
}

/*
 * Decompiled function: FUN_0040c7c0
 * Entry Point: 0040c7c0
 * Size: 92 bytes
 */


int32_t FUN_0040c7c0(int arg1,int arg2)

{
  int32_t uval_1;
  
  if ((arg1 < 0x40) && (-1 < arg1)) {
    if ((arg2 < 0x40) && (-1 < arg2)) {
      uval_1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg1,arg2);
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0040c81c
 * Entry Point: 0040c81c
 * Size: 109 bytes
 */


void FUN_0040c81c(uint32_t arg_1,int card_slot,int event_type)

{
  uint32_t uval_1;
  
  if ((((arg_2 < 0x40) && (-1 < arg_2)) && (arg_3 < 0x40)) && (-1 < arg_3)) {
    uval_1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_2,arg_3);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,arg_2,arg_3,uval_1 | arg_1);
  }
  return;
}

/*
 * Decompiled function: FUN_0040c889
 * Entry Point: 0040c889
 * Size: 113 bytes
 */


void FUN_0040c889(uint32_t arg_1,int card_slot,int event_type)

{
  uint32_t uval_1;
  
  if ((((arg_2 < 0x40) && (-1 < arg_2)) && (arg_3 < 0x40)) && (-1 < arg_3)) {
    uval_1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_2,arg_3);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,arg_2,arg_3,uval_1 & ~arg_1);
  }
  return;
}

/*
 * Decompiled function: FUN_0040c8fa
 * Entry Point: 0040c8fa
 * Size: 95 bytes
 */


int32_t FUN_0040c8fa(int arg1,int arg2)

{
  int32_t uval_1;
  
  if ((arg1 < 0x40) && (-1 < arg1)) {
    if ((arg2 < 0x40) && (-1 < arg2)) {
      uval_1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg1 + 0x40,arg2);
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0040c959
 * Entry Point: 0040c959
 * Size: 115 bytes
 */


void FUN_0040c959(uint32_t arg_1,int card_slot,int event_type)

{
  uint32_t uval_1;
  
  if ((((arg_2 < 0x40) && (-1 < arg_2)) && (arg_3 < 0x40)) && (-1 < arg_3)) {
    uval_1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_2 + 0x40,arg_3);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,arg_2 + 0x40,arg_3,uval_1 | arg_1);
  }
  return;
}

/*
 * Decompiled function: FUN_0040c9cc
 * Entry Point: 0040c9cc
 * Size: 119 bytes
 */


void FUN_0040c9cc(uint32_t arg_1,int card_slot,int event_type)

{
  uint32_t uval_1;
  
  if ((((arg_2 < 0x40) && (-1 < arg_2)) && (arg_3 < 0x40)) && (-1 < arg_3)) {
    uval_1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_2 + 0x40,arg_3);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,arg_2 + 0x40,arg_3,uval_1 & ~arg_1);
  }
  return;
}

/*
 * Decompiled function: FUN_0040ca43
 * Entry Point: 0040ca43
 * Size: 268 bytes
 */


void FUN_0040ca43(int player_id,int card_slot,int event_type)

{
  int arg_2_00;
  int arg_3_00;
  uint32_t uval_1;
  
  if ((((arg_1 < 0x40) && (-1 < arg_1)) && (arg_2 < 0x40)) && (-1 < arg_2)) {
    uval_1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_1,arg_2 + 0x40);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,arg_1,arg_2 + 0x40,
                     uval_1 | 1 << ((char)arg_3 - 1U & 0x1f));
    FUN_0040c81c(0x20,arg_1,arg_2);
    arg_2_00 = arg_1 + *(int *)(&DAT_00522378 + arg_3 * 4);
    arg_3_00 = arg_2 + *(int *)(&DAT_005223e0 + arg_3 * 4);
    uval_1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_2_00,arg_3_00 + 0x40);
    Surface_PutPixel((int *)g_DisplaySurfaceWork,arg_2_00,arg_3_00 + 0x40,
                     uval_1 | 1 << ((char)arg_3 + 3U & 7));
    FUN_0040c81c(0x20,arg_2_00,arg_3_00);
  }
  return;
}

/*
 * Decompiled function: FUN_0040cb4f
 * Entry Point: 0040cb4f
 * Size: 110 bytes
 */


uint32_t FUN_0040cb4f(int player_id,int card_slot,char arg_3)

{
  uint32_t uval_1;
  
  if ((arg_1 < 0x40) && (-1 < arg_1)) {
    if ((arg_2 < 0x40) && (-1 < arg_2)) {
      uval_1 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,arg_1,arg_2 + 0x40);
      uval_1 = uval_1 & 1 << (arg_3 - 1U & 0x1f);
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0040cbbd
 * Entry Point: 0040cbbd
 * Size: 75 bytes
 */


int32_t FUN_0040cbbd(int arg1,int arg2)

{
  int32_t uval_1;
  
  if ((arg1 < 0) || (0x3f < arg1)) {
    uval_1 = 0;
  }
  else if ((arg2 < 0) || (0x3f < arg2)) {
    uval_1 = 0;
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0040cc08
 * Entry Point: 0040cc08
 * Size: 118 bytes
 */


int FUN_0040cc08(char *filepath)

{
  char *char_ptr_1;
  char cVar2;
  int slot_idx;
  
  slot_idx = 0;
  if (str_1 == (char *)0x0) {
    slot_idx = 0;
  }
  else {
    while (*str_1 != '\0') {
      char_ptr_1 = str_1 + 1;
      cVar2 = *str_1;
      str_1 = char_ptr_1;
      if (cVar2 == '\n') {
        slot_idx = slot_idx + 1;
      }
    }
    if (str_1[-1] != '\n') {
      slot_idx = slot_idx + 1;
    }
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0040cc7e
 * Entry Point: 0040cc7e
 * Size: 551 bytes
 */


int FUN_0040cc7e(int player_id,int card_slot,int event_type,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
                int32_t *arg_9)

{
  int val_1;
  int val_2;
  int32_t local_41c;
  int local_418;
  int local_414;
  char *local_410;
  char local_40c [1024];
  char *match_count;
  va_list slot_idx;
  
  slot_idx = (va_list)(arg_9 + 1);
  val_1 = _vsnprintf(local_40c,0x400,(char *)*arg_9,slot_idx);
  local_418 = FUN_0040cc08(local_40c);
  if (arg_4 != 0) {
    arg_7 = (arg_7 * g_AiManaColorCost_Red) / 0x280;
    arg_8 = (g_AiManaColorCost_Green * arg_8) / 0x1e0;
  }
  if (arg_6 != 0) {
    val_2 = Mem_AllocOrFree_0050f740(*(int *)(arg_1 + 0x20));
    arg_8 = arg_8 - (val_2 * local_418) / 2;
  }
  if (-1 < arg_2) {
    local_41c = *(int32_t *)(arg_1 + 0x18);
    *(int *)(arg_1 + 0x18) = arg_2;
  }
  local_410 = local_40c;
  match_count = local_410;
  while( true ) {
    if (local_418 == 0) break;
    for (; (*local_410 != '\0' && (*local_410 != '\n')); local_410 = local_410 + 1) {
    }
    *local_410 = '\0';
    if (arg_5 == 0) {
      local_414 = arg_7;
    }
    else {
      val_2 = FUN_0050f440((int *)arg_1,match_count);
      local_414 = arg_7 - val_2 / 2;
    }
    if (arg_3 != 0) {
      local_41c = *(int32_t *)(arg_1 + 0x18);
      *(int32_t *)(arg_1 + 0x18) = 0;
      FUN_0050f820((int *)arg_1,local_414 + 1,arg_8 + 1,match_count);
      *(int32_t *)(arg_1 + 0x18) = local_41c;
    }
    FUN_0050f820((int *)arg_1,local_414,arg_8,match_count);
    *local_410 = '\n';
    local_410 = local_410 + 1;
    match_count = local_410;
    val_2 = Mem_AllocOrFree_0050f740(*(int *)(arg_1 + 0x20));
    arg_8 = arg_8 + val_2;
    local_418 = local_418 + -1;
  }
  if (-1 < arg_2) {
    *(int32_t *)(arg_1 + 0x18) = local_41c;
  }
  return val_1;
}

/*
 * Decompiled function: FUN_0040cea5
 * Entry Point: 0040cea5
 * Size: 50 bytes
 */


void FUN_0040cea5(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,0,0,0,0,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040ced7
 * Entry Point: 0040ced7
 * Size: 50 bytes
 */


void FUN_0040ced7(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,0,0,1,0,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040cf09
 * Entry Point: 0040cf09
 * Size: 50 bytes
 */


void FUN_0040cf09(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,0,0,0,1,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040cf3b
 * Entry Point: 0040cf3b
 * Size: 50 bytes
 */


void FUN_0040cf3b(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,0,0,1,1,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040cf6d
 * Entry Point: 0040cf6d
 * Size: 52 bytes
 */


void FUN_0040cf6d(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,0,0,0,0,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040cfa1
 * Entry Point: 0040cfa1
 * Size: 52 bytes
 */


void FUN_0040cfa1(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,0,0,1,0,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040cfd5
 * Entry Point: 0040cfd5
 * Size: 52 bytes
 */


void FUN_0040cfd5(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,0,0,0,1,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d009
 * Entry Point: 0040d009
 * Size: 52 bytes
 */


void FUN_0040d009(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,0,0,1,1,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d03d
 * Entry Point: 0040d03d
 * Size: 50 bytes
 */


void FUN_0040d03d(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,1,0,0,0,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d06f
 * Entry Point: 0040d06f
 * Size: 50 bytes
 */


void FUN_0040d06f(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,1,0,1,0,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d0a1
 * Entry Point: 0040d0a1
 * Size: 50 bytes
 */


void FUN_0040d0a1(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,1,0,0,1,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d0d3
 * Entry Point: 0040d0d3
 * Size: 50 bytes
 */


void FUN_0040d0d3(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,1,0,1,1,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d105
 * Entry Point: 0040d105
 * Size: 50 bytes
 */


void FUN_0040d105(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,0,1,0,0,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d137
 * Entry Point: 0040d137
 * Size: 50 bytes
 */


void FUN_0040d137(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,0,1,1,0,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d169
 * Entry Point: 0040d169
 * Size: 50 bytes
 */


void FUN_0040d169(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,0,1,0,1,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d19b
 * Entry Point: 0040d19b
 * Size: 50 bytes
 */


void FUN_0040d19b(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,0,1,1,1,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d1cd
 * Entry Point: 0040d1cd
 * Size: 52 bytes
 */


void FUN_0040d1cd(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,1,0,0,0,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d201
 * Entry Point: 0040d201
 * Size: 52 bytes
 */


void FUN_0040d201(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,1,0,1,0,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d235
 * Entry Point: 0040d235
 * Size: 52 bytes
 */


void FUN_0040d235(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,1,0,0,1,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d269
 * Entry Point: 0040d269
 * Size: 52 bytes
 */


void FUN_0040d269(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,1,0,1,1,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d29d
 * Entry Point: 0040d29d
 * Size: 52 bytes
 */


void FUN_0040d29d(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,0,1,0,0,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d2d1
 * Entry Point: 0040d2d1
 * Size: 52 bytes
 */


void FUN_0040d2d1(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,0,1,1,0,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d305
 * Entry Point: 0040d305
 * Size: 52 bytes
 */


void FUN_0040d305(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,0,1,0,1,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d339
 * Entry Point: 0040d339
 * Size: 52 bytes
 */


void FUN_0040d339(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,0,1,1,1,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d36d
 * Entry Point: 0040d36d
 * Size: 50 bytes
 */


void FUN_0040d36d(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,1,1,0,0,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d39f
 * Entry Point: 0040d39f
 * Size: 50 bytes
 */


void FUN_0040d39f(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,1,1,1,0,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d3d1
 * Entry Point: 0040d3d1
 * Size: 50 bytes
 */


void FUN_0040d3d1(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,1,1,0,1,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d403
 * Entry Point: 0040d403
 * Size: 50 bytes
 */


void FUN_0040d403(int player_id,int card_slot,int event_type)

{
  FUN_0040cc7e(arg_1,-1,1,1,1,1,arg_2,arg_3,(int32_t *)&stack0x00000010);
  return;
}

/*
 * Decompiled function: FUN_0040d435
 * Entry Point: 0040d435
 * Size: 52 bytes
 */


void FUN_0040d435(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,1,1,0,0,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d469
 * Entry Point: 0040d469
 * Size: 52 bytes
 */


void FUN_0040d469(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,1,1,1,0,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d49d
 * Entry Point: 0040d49d
 * Size: 52 bytes
 */


void FUN_0040d49d(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,1,1,0,1,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d4d1
 * Entry Point: 0040d4d1
 * Size: 52 bytes
 */


void FUN_0040d4d1(int x,int y,int width,int height)

{
  FUN_0040cc7e(x,y,1,1,1,1,width,height,(int32_t *)&stack0x00000014);
  return;
}

/*
 * Decompiled function: FUN_0040d510
 * Entry Point: 0040d510
 * Size: 66 bytes
 */


int32_t FUN_0040d510(int player_id,int card_slot,int event_type)

{
  *(int *)(&g_AiCombatScore_Attacker + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&g_AiCombatScore_Attacker + arg_2 * 4 + arg_1 * 0x20) + arg_3;
  *(int *)(&g_PlayerManaPoolDelta + arg_1 * 0x20) = *(int *)(&g_PlayerManaPoolDelta + arg_1 * 0x20) + arg_3;
  return *(int32_t *)(&g_AiCombatScore_Attacker + arg_2 * 4 + arg_1 * 0x20);
}

/*
 * Decompiled function: FUN_0040d552
 * Entry Point: 0040d552
 * Size: 74 bytes
 */


int32_t FUN_0040d552(int player_id,int card_slot,int event_type)

{
  *(int *)(&g_AiCombatScore_Attacker + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&g_AiCombatScore_Attacker + arg_2 * 4 + arg_1 * 0x20) - arg_3;
  *(int *)(&g_PlayerManaPoolDelta + arg_1 * 0x20) = *(int *)(&g_PlayerManaPoolDelta + arg_1 * 0x20) - arg_3;
  return *(int32_t *)(&g_AiCombatScore_Attacker + arg_2 * 4 + arg_1 * 0x20);
}

/*
 * Decompiled function: FUN_0040d59c
 * Entry Point: 0040d59c
 * Size: 176 bytes
 */


void FUN_0040d59c(int player_id,uint32_t arg_2,int event_type)

{
  bool flag_1;
  int match_count;
  
  if (0 < (int)arg_2) {
    flag_1 = false;
    match_count = 0;
    while ((match_count < 0x32 && (!flag_1))) {
      if (*(int *)(&DAT_00627870 + match_count * 4 + arg_1 * 0xcc) == -1) {
        flag_1 = true;
        *(uint32_t *)(&DAT_00627870 + match_count * 4 + arg_1 * 0xcc) = arg_3 << 0x10 | arg_2;
        *(int32_t *)(&DAT_00627874 + match_count * 4 + arg_1 * 0xcc) = 0xffffffff;
      }
      match_count = match_count + 1;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0040d64c
 * Entry Point: 0040d64c
 * Size: 223 bytes
 */


void FUN_0040d64c(int player_id,uint32_t arg_2,int event_type)

{
  bool flag_1;
  int card_idx;
  int match_count;
  
  flag_1 = false;
  match_count = 0;
  while (((match_count < 0x32 && (*(int *)(&DAT_00627870 + match_count * 4 + arg_1 * 0xcc) != -1)) &&
         (!flag_1))) {
    if (*(uint32_t *)(&DAT_00627870 + match_count * 4 + arg_1 * 0xcc) == (arg_3 << 0x10 | arg_2)) {
      flag_1 = true;
      for (card_idx = match_count; card_idx < 0x31; card_idx = card_idx + 1) {
        *(int32_t *)(&DAT_00627870 + card_idx * 4 + arg_1 * 0xcc) =
             *(int32_t *)(&DAT_00627874 + card_idx * 4 + arg_1 * 0xcc);
      }
    }
    match_count = match_count + 1;
  }
  return;
}

/*
 * Decompiled function: FUN_0040d72b
 * Entry Point: 0040d72b
 * Size: 190 bytes
 */


void FUN_0040d72b(int player_id,uint32_t arg_2,int event_type)

{
  bool flag_1;
  int match_count;
  
  if ((0 < (int)arg_2) && (0 < arg_3)) {
    flag_1 = false;
    match_count = 0;
    while ((match_count < 10 && (!flag_1))) {
      if (*(int *)(&g_AiTempTargetBuffer + match_count * 4 + arg_1 * 0x2c) == -1) {
        flag_1 = true;
        *(uint32_t *)(&g_AiTempTargetBuffer + match_count * 4 + arg_1 * 0x2c) = arg_3 << 0x10 | arg_2 & 0xffff;
        *(int32_t *)(&DAT_00627a24 + match_count * 4 + arg_1 * 0x2c) = 0xffffffff;
      }
      match_count = match_count + 1;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0040d7e9
 * Entry Point: 0040d7e9
 * Size: 66 bytes
 */


int32_t FUN_0040d7e9(int player_id,int card_slot,int event_type)

{
  *(int *)(&g_AiCombatScore_Total + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&g_AiCombatScore_Total + arg_2 * 4 + arg_1 * 0x20) + arg_3;
  *(int *)(&DAT_0063edec + arg_1 * 0x20) = *(int *)(&DAT_0063edec + arg_1 * 0x20) + arg_3;
  return *(int32_t *)(&g_AiCombatScore_Total + arg_2 * 4 + arg_1 * 0x20);
}

/*
 * Decompiled function: FUN_0040d82b
 * Entry Point: 0040d82b
 * Size: 74 bytes
 */


int32_t FUN_0040d82b(int player_id,int card_slot,int event_type)

{
  *(int *)(&g_AiCombatScore_Total + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&g_AiCombatScore_Total + arg_2 * 4 + arg_1 * 0x20) - arg_3;
  *(int *)(&DAT_0063edec + arg_1 * 0x20) = *(int *)(&DAT_0063edec + arg_1 * 0x20) - arg_3;
  return *(int32_t *)(&g_AiCombatScore_Total + arg_2 * 4 + arg_1 * 0x20);
}

/*
 * Decompiled function: FUN_0040d875
 * Entry Point: 0040d875
 * Size: 66 bytes
 */


int32_t FUN_0040d875(int player_id,int card_slot,int event_type)

{
  *(int *)(&g_AiLookaheadDepth + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&g_AiLookaheadDepth + arg_2 * 4 + arg_1 * 0x20) + arg_3;
  *(int *)(&DAT_0063eeac + arg_1 * 0x20) = *(int *)(&DAT_0063eeac + arg_1 * 0x20) + arg_3;
  return *(int32_t *)(&g_AiLookaheadDepth + arg_2 * 4 + arg_1 * 0x20);
}

/*
 * Decompiled function: FUN_0040d8b7
 * Entry Point: 0040d8b7
 * Size: 74 bytes
 */


int32_t FUN_0040d8b7(int player_id,int card_slot,int event_type)

{
  *(int *)(&g_AiLookaheadDepth + arg_2 * 4 + arg_1 * 0x20) =
       *(int *)(&g_AiLookaheadDepth + arg_2 * 4 + arg_1 * 0x20) - arg_3;
  *(int *)(&DAT_0063eeac + arg_1 * 0x20) = *(int *)(&DAT_0063eeac + arg_1 * 0x20) - arg_3;
  return *(int32_t *)(&g_AiLookaheadDepth + arg_2 * 4 + arg_1 * 0x20);
}

/*
 * Decompiled function: FUN_0040d901
 * Entry Point: 0040d901
 * Size: 72 bytes
 */


int32_t FUN_0040d901(int player_id,int card_slot,int event_type)

{
  FUN_0040d82b(arg_1,arg_2,arg_3);
  FUN_0040d875(arg_1,arg_2,arg_3);
  return *(int32_t *)(&g_AiLookaheadDepth + arg_2 * 4 + arg_1 * 0x20);
}

/*
 * Decompiled function: FUN_0040d949
 * Entry Point: 0040d949
 * Size: 892 bytes
 */


int FUN_0040d949(int player_id,uint32_t arg_2,int event_type)

{
  int local_34;
  int local_30;
  uint32_t local_2c;
  uint32_t local_28;
  uint32_t local_24;
  int color_idx;
  int card_idx;
  uint8_t slot_idx;
  
  if (arg_2 == 6) {
    local_28 = 7;
  }
  else if (arg_2 == 0) {
    local_28 = 7;
  }
  else {
    local_28 = arg_2;
  }
  if (arg_3 == 0) {
    local_34 = 1;
  }
  else {
    local_2c = 0;
    local_24 = 0;
    while (((int)local_24 < 10 && (*(int *)(&g_AiTempTargetBuffer + local_24 * 4 + arg_1 * 0x2c) != -1))) {
      if (local_28 == *(uint32_t *)(&g_AiTempTargetBuffer + local_24 * 4 + arg_1 * 0x2c) >> 0x10) {
        slot_idx = (uint8_t)*(int16_t *)(&g_AiTempTargetBuffer + local_24 * 4 + arg_1 * 0x2c);
        local_2c = local_2c | 1 << (slot_idx & 0x1f);
      }
      local_24 = local_24 + 1;
    }
    local_30 = *(int *)(&g_AiLookaheadDepth + local_28 * 4 + arg_1 * 0x20);
    for (local_24 = 0; (int)local_24 < 7; local_24 = local_24 + 1) {
      if ((local_24 != local_28) && ((local_2c & 1 << ((uint8_t)local_24 & 0x1f)) != 0)) {
        local_30 = local_30 + *(int *)(&g_AiLookaheadDepth + local_24 * 4 + arg_1 * 0x20);
      }
    }
    color_idx = *(int *)(&g_AiCombatScore_Total + local_28 * 4 + arg_1 * 0x20);
    if (((arg_1 == g_ActivePlayerPriority) || (g_AiTurnDecisionFlag != 0)) || (g_IsAiThinking == 1)) {
      for (local_24 = 0; (int)local_24 < 7; local_24 = local_24 + 1) {
        if ((local_24 != local_28) && ((local_2c & 1 << ((uint8_t)local_24 & 0x1f)) != 0)) {
          color_idx = color_idx + *(int *)(&g_AiCombatScore_Total + local_24 * 4 + arg_1 * 0x20);
        }
      }
    }
    card_idx = 0;
    local_24 = 0;
    while (((int)local_24 < 0x32 && (*(int *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc) != -1)))
    {
      if (local_28 == 7) {
        card_idx = card_idx + (*(int *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc) >> 0x10);
      }
      else if ((*(uint32_t *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc) &
               1 << ((uint8_t)local_28 & 0x1f)) == 0) {
        if ((((arg_1 == g_ActivePlayerPriority) || (g_AiTurnDecisionFlag != 0)) || (g_IsAiThinking == 1)) &&
           ((local_2c & *(uint32_t *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc)) != 0)) {
          card_idx = card_idx + (*(int *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc) >> 0x10);
        }
      }
      else {
        card_idx = card_idx + (*(int *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc) >> 0x10);
      }
      local_24 = local_24 + 1;
    }
    if ((arg_2 == 7) || (arg_2 == 0)) {
      local_34 = (((local_30 - *(int *)(&DAT_0063eea8 + arg_1 * 0x20)) + color_idx) -
                 *(int *)(&DAT_0063ede8 + arg_1 * 0x20)) + card_idx;
    }
    else {
      local_34 = color_idx + card_idx + local_30;
    }
    if (local_34 < arg_3) {
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


int FUN_0040dcca(int x,int y,uint32_t width,int height)

{
  int val_1;
  int val_2;
  
  if (height == 0) {
    val_1 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[y * 0x120 + x * 0x5b20]);
    if (*(int *)(&DAT_006330d0 + val_1 * 4) < 1) {
      val_1 = 1;
    }
    else {
      val_1 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[y * 0x120 + x * 0x5b20]);
      val_1 = FUN_0040d949(x,7,*(int *)(&DAT_006330d0 + val_1 * 4));
    }
  }
  else {
    val_1 = FUN_0040d949(x,width,height);
    if (val_1 == 0) {
      val_1 = 0;
    }
    else {
      val_2 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[y * 0x120 + x * 0x5b20]);
      if (0 < *(int *)(&DAT_006330d0 + val_2 * 4)) {
        val_1 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[y * 0x120 + x * 0x5b20]);
        val_1 = FUN_0040d949(x,7,*(int *)(&DAT_006330d0 + val_1 * 4) + height);
      }
    }
  }
  return val_1;
}

/*
 * Decompiled function: FUN_0040eab1
 * Entry Point: 0040eab1
 * Size: 83 bytes
 */


int FUN_0040eab1(void)

{
  int player_id;
  int val_1;
  
  do {
    do {
      arg_1 = Util_GetRandomNumber(g_MasterCardCount + -0x29);
      val_1 = File_Load_Info(arg_1);
    } while (val_1 < 3);
    val_1 = FUN_00485005(arg_1);
  } while (val_1 == 0);
  return arg_1;
}

/*
 * Decompiled function: FUN_0040eb04
 * Entry Point: 0040eb04
 * Size: 86 bytes
 */


void FUN_0040eb04(int player_id)

{
  char cVar1;
  size_t len_2;
  int card_idx;
  
  card_idx = 0;
  len_2 = strlen(&g_OverworldWorldState);
  do {
    cVar1 = (&PTR_s_Restless_Graveyard_005174e8)[arg_1][card_idx];
    (&g_OverworldWorldState)[card_idx + len_2] = cVar1;
    card_idx = card_idx + 1;
  } while (cVar1 != '\0');
  return;
}

/*
 * Decompiled function: Pic_Load_winbak01_0040eb5a
 * Entry Point: 0040eb5a
 * Size: 835 bytes
 */


void Pic_Load_winbak01_0040eb5a(int arg1,int arg2)

{
  uint32_t arg_1;
  int val_1;
  int32_t arg_2;
  int val_2;
  int arg_4;
  char *str_5;
  uint32_t auStack_20 [5];
  int match_count;
  LPVOID slot_idx;
  
  for (match_count = 0; match_count < arg2; match_count = match_count + 1) {
    do {
      do {
        arg_1 = Util_GetRandomNumber(g_MasterCardCount + -0x29);
        val_1 = File_Load_Info(arg_1);
      } while (val_1 < 3);
      val_1 = FUN_00485005(arg_1);
    } while (val_1 == 0);
    auStack_20[match_count] = arg_1;
    FUN_0050b206(arg_1,(int)(0x96 / (longlong)arg2) * match_count + 100,
                 (int)(10 / (longlong)arg2) * match_count + 100,1,&DAT_00519184);
  }
  slot_idx = (LPVOID)Glue_Subsystem_004ea97c(0,arg1);
  strcpy(&g_OverworldWorldState,s_You_encounter_00519188);
  Glue_Subsystem_004eaa19((int)slot_idx,1,0);
  if (arg1 == 0xd) {
    strcat(&g_OverworldWorldState,s_Genie_00519198);
  }
  else if (arg1 == 0x10) {
    strcat(&g_OverworldWorldState,s_Spectre_005191a0);
  }
  else if (arg1 == 0x12) {
    strcat(&g_OverworldWorldState,s_Dragon_005191ac);
  }
  else {
    strcat(&g_OverworldWorldState,s_warily_005191b4);
  }
  strcat(&g_OverworldWorldState,s_guarding_a_horde_of_valuable_spe_005191bc);
  val_1 = FUN_00489710(&g_OverworldWorldState,0x5a,100);
  if (val_1 == 1) {
    arg_2 = Pic_Subsystem_0045268f(*(int *)(&DAT_0052262c + (int)slot_idx * 0x44));
    Deck_LoadPreconstructedDeck((int)slot_idx,arg_2,0,-1);
    DAT_006b2d64 = Rules_CalculateManaCostReduction((&DAT_0052262b)[(int)slot_idx * 0x44]);
    DAT_0063ee24 = 0;
    DAT_00695df0 = 3;
    val_1 = Deck_LoadOneDeckProfile(arg_2,slot_idx);
    if (val_1 != 0) {
      Mem_AllocOrFree_00510de0(1,s_winbak01_pic_00519214);
      Glue_Subsystem_004ebfef(1);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
      for (match_count = 0; match_count < arg2; match_count = match_count + 1) {
        val_1 = (int)(300 / (longlong)(arg2 + 1));
        val_2 = File_Load_Info(auStack_20[match_count]);
        strcpy(&g_OverworldWorldState,(char *)(&DAT_0052b73c)[val_2]);
        str_5 = &g_OverworldWorldState;
        arg_4 = 1;
        val_2 = Util_GetRandomNumber(10);
        FUN_0050b206(auStack_20[match_count],(val_1 * match_count + 0x6f) - ((arg2 + -1) * val_1) / 2,
                     val_2 + 0x10,arg_4,str_5);
        slot_idx = (LPVOID)Pic_Subsystem_00451e40(auStack_20[match_count]);
        if (slot_idx != (LPVOID)0xffffffff) {
          *(uint32_t *)(&deck + (int)slot_idx * 4) = *(uint32_t *)(&deck + (int)slot_idx * 4) | 0x4000;
        }
      }
      *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
      FUN_004896be(s_Won_These_Cards_00519224,0x40,0x96);
    }
    Pic_Subsystem_00423c82(0x10);
  }
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0040eea2
 * Entry Point: 0040eea2
 * Size: 18 bytes
 */


int32_t Mem_AllocOrFree_0040eea2(void)

{
  return 0;
}

/*
 * Decompiled function: Bazaar_TradeCardDialogue
 * Entry Point: 0040eeb4
 * Size: 1632 bytes
 */


int32_t Bazaar_TradeCardDialogue(int arg1,int arg2)

{
  bool flag_1;
  uint8_t *u_ptr_2;
  uint8_t arg_1;
  int32_t arg_1_00;
  uint32_t arg_1_01;
  int val_3;
  char *pcVar4;
  int val_5;
  int val_6;
  uint32_t local_30;
  int local_28;
  int local_24;
  int player_idx;
  int card_idx;
  uint32_t match_count;
  int slot_idx;
  
  u_ptr_2 = PTR_FUN_00527b3c;
  player_idx = 1;
  PTR_FUN_00527b3c = Mem_AllocOrFree_0040eea2;
LAB_0040eed6:
  if (arg2 == -1) {
    local_30 = Palette_Color_0049716e(s_Which_card_do_you_seek__00519250,0,0xffffffff,player_idx,1);
  }
  else {
    local_30 = Palette_Color_0049716e
                         (s_Which_card_do_you_seek__00519238,
                          *(uint32_t *)(&DAT_0067bdfc + arg2 * 100) & 0xff,
                          (*(int *)(&DAT_0067bdfc + arg2 * 100) >> 8) - 1,player_idx,1);
  }
  player_idx = 0;
  if (arg1 == 0) {
    local_24 = 0;
    for (card_idx = 0; card_idx < 5; card_idx = card_idx + 1) {
      local_24 = local_24 + (&DAT_0067bdc0)[card_idx];
    }
  }
  if (local_30 != 0xffffffff) {
    if (arg1 != -2) goto LAB_0040efc0;
    flag_1 = true;
    if ((int)local_30 < 5) {
      match_count = 4;
    }
    else {
      match_count = 1;
    }
    goto LAB_0040f49b;
  }
LAB_0040f4fb:
  Palette_Subsystem_00496eaf();
  PTR_FUN_00527b3c = u_ptr_2;
  return 0;
LAB_0040efc0:
  local_28 = File_Load_Info(local_30);
  if (local_28 == 1) {
    if ((int)local_30 < 5) {
      match_count = 4;
    }
    else {
      match_count = 1;
    }
  }
  else if (local_28 == 2) {
    match_count = 1;
  }
  else {
    match_count = 1;
  }
  if ((local_28 < 2) && (((&g_MasterCardFlagsTable)[local_30 * 0x34] & 4) != 0)) {
    local_28 = local_28 + 1;
  }
  val_6 = FUN_0050a9bf(local_30);
  slot_idx = val_6 * 4;
  arg_1_00 = FUN_0040c761((int)(g_OverworldMapPixelX + ((int)g_OverworldMapPixelX >> 0x1f & 0x1fU)) >> 5,
                          (int)(g_OverworldMapPixelY + ((int)g_OverworldMapPixelY >> 0x1f & 0x1fU)) >> 5);
  arg_1 = Glue_Subsystem_004ea7a6(arg_1_00);
  arg_1_01 = Rules_CalculateManaCostReduction(arg_1);
  if (((arg_1_01 & (int)(char)(&g_MasterCardColorTable)[local_30 * 0x34]) == 0) &&
     ((&g_MasterCardColorTable)[local_30 * 0x34] != '\0')) {
    val_3 = Pic_Subsystem_004521a6(arg_1_01,(int)(char)(&g_MasterCardColorTable)[local_30 * 0x34],3);
    if (val_3 == 0) {
      slot_idx = val_6 << 3;
    }
    else {
      slot_idx = (val_6 * 0xc) / 2;
    }
  }
  val_6 = Util_GetRandomNumber(((g_OverworldMapPixelX & 0x1f) * (g_OverworldMapPixelY & 0x1f)) / 10);
  val_3 = FUN_0040a305((((slot_idx * 0x4e2) / (val_6 + 0x2ee)) / 0x32) * 5,5,1000);
  val_6 = local_28 * 0x32;
  if (local_28 * 0x32 <= (int)(val_3 * match_count)) {
    val_6 = val_3 * match_count;
  }
  strcpy(&g_OverworldWorldState,s_I_ll_trade_you_00519268);
  pcVar4 = _itoa(match_count,&DAT_00538610,10);
  strcat(&g_OverworldWorldState,pcVar4);
  strcat(&g_OverworldWorldState,&DAT_00519278);
  strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + local_30 * 0x34);
  if (1 < match_count) {
    strcat(&g_OverworldWorldState,&DAT_0051927c);
  }
  strcat(&g_OverworldWorldState,s_for_00519280);
  if (arg1 < 0) {
    pcVar4 = _itoa(val_6,&DAT_00538610,10);
    strcat(&g_OverworldWorldState,pcVar4);
    strcat(&g_OverworldWorldState,s_Gold_pieces__005192a4);
  }
  else {
    pcVar4 = _itoa(local_28,&DAT_00538610,10);
    strcat(&g_OverworldWorldState,pcVar4);
    if (0 < arg1) {
      strcat(&g_OverworldWorldState,&DAT_00519288);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e(arg1);
      strcat(&g_OverworldWorldState,pcVar4);
    }
    strcat(&g_OverworldWorldState,s_amulets__0051928c + ((1 < local_28) - 1 & 0xc));
  }
  flag_1 = true;
  if ((0 < arg1) && (*(int *)(&DAT_0067bdbc + arg1 * 4) < local_28)) {
    flag_1 = false;
  }
  if ((arg1 == 0) && (local_24 < local_28)) {
    flag_1 = false;
  }
  if ((arg1 == -1) && (Gold < val_6)) {
    flag_1 = false;
  }
  if (flag_1) {
    strcat(&g_OverworldWorldState,s_Do_you_wish_to_trade__Yes__I_ll_t_005192b4);
  }
  else {
    strcat(&g_OverworldWorldState,s_Hmmm____you_can_t_afford_this_ca_005192e8);
  }
  val_3 = Ai_Util_004c3bc4(0x15c);
  val_3 = val_3 + 10;
  val_5 = Ai_Util_004c3bc4(0xf4);
  val_3 = FUN_00489710(&g_OverworldWorldState,val_5 + 10,val_3);
  if ((val_3 == 0) && (flag_1)) {
    flag_1 = false;
    if ((0 < arg1) && (local_28 <= *(int *)(&DAT_0067bdbc + arg1 * 4))) {
      flag_1 = true;
      *(int *)(&DAT_0067bdbc + arg1 * 4) = *(int *)(&DAT_0067bdbc + arg1 * 4) - local_28;
    }
    if ((arg1 == 0) && (local_28 <= local_24)) {
      flag_1 = true;
      do {
        do {
          val_3 = Util_GetRandomNumber(5);
        } while ((&DAT_0067bdc0)[val_3] == 0);
        local_28 = local_28 + -1;
        (&DAT_0067bdc0)[val_3] = (&DAT_0067bdc0)[val_3] + -1;
      } while (local_28 != 0);
    }
    if ((arg1 == -1) && (val_6 <= Gold)) {
      flag_1 = true;
      Gold = Gold - val_6;
    }
LAB_0040f49b:
    if (!flag_1) goto LAB_0040f4fb;
    for (card_idx = 0; card_idx < (int)match_count; card_idx = card_idx + 1) {
      val_6 = Pic_Subsystem_00451e40(local_30);
      if (val_6 != -1) {
        *(uint32_t *)(&deck + val_6 * 4) = *(uint32_t *)(&deck + val_6 * 4) | 0x4000;
      }
    }
    FUN_0040a566();
    Palette_Subsystem_00496eaf();
  }
  goto LAB_0040eed6;
}

/*
 * Decompiled function: UI_PromptDeckInspection
 * Entry Point: 0040f514
 * Size: 290 bytes
 */


void UI_PromptDeckInspection(uint8_t arg_1)

{
  int32_t uval_1;
  int aiStack_50 [16];
  int card_idx;
  int match_count;
  int slot_idx;
  
  strcpy(&g_OverworldWorldState,s_Whose_deck_would_you_like_to_see_00519314);
  slot_idx = 0;
  for (match_count = 1; match_count < DAT_00523524; match_count = match_count + 1) {
    if ((1 << (arg_1 & 0x1f) & (int)(char)(&DAT_0052262b)[match_count * 0x44]) != 0) {
      aiStack_50[slot_idx] = match_count;
      slot_idx = slot_idx + 1;
      Glue_Subsystem_004eaa19(match_count,0,0);
      strcat(&g_OverworldWorldState,&DAT_00519338);
    }
  }
  card_idx = FUN_00489710(&g_OverworldWorldState,100,0x46);
  if (card_idx != -1) {
    card_idx = aiStack_50[card_idx];
    Deck_LoadPreconstructedDeck(card_idx,0xffffffff,0,-1);
    for (match_count = 0; match_count < 500; match_count = match_count + 1) {
      uval_1 = FUN_0040a02a(DAT_0052eff8);
      *(int32_t *)(&DAT_0069ef00 + match_count * 4) = uval_1;
    }
    UI_RenderOpponentLibraryPrompt(DAT_0052eff8);
  }
  return;
}

/*
 * Decompiled function: FUN_0040f636
 * Entry Point: 0040f636
 * Size: 75 bytes
 */


int FUN_0040f636(char *filepath)

{
  char *char_ptr_1;
  char cVar2;
  int slot_idx;
  
  slot_idx = 0;
  while (*str_1 != '\0') {
    char_ptr_1 = str_1 + 1;
    cVar2 = *str_1;
    str_1 = char_ptr_1;
    if (cVar2 == '\n') {
      slot_idx = slot_idx + 1;
    }
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0040f681
 * Entry Point: 0040f681
 * Size: 104 bytes
 */


int FUN_0040f681(int *arg1,int32_t *arg2)

{
  int slot_idx;
  
  slot_idx = 1;
  *arg2 = arg1;
  for (; (char)*arg1 != '\0'; arg1 = (int *)((int)arg1 + 1)) {
    if (*arg1 == 0xa0a0a0a) {
      arg2[slot_idx] = arg1 + 1;
      slot_idx = slot_idx + 1;
    }
  }
  arg2[slot_idx] = arg1;
  return slot_idx;
}

/*
 * Decompiled function: FUN_0040f6e9
 * Entry Point: 0040f6e9
 * Size: 164 bytes
 */


int FUN_0040f6e9(void)

{
  int32_t card_idx;
  int32_t match_count;
  int32_t slot_idx;
  
  slot_idx = 0;
  for (match_count = 1; match_count < 6; match_count = match_count + 1) {
    if ((DAT_0067bdb4 & 1 << ((uint8_t)match_count & 0x1f)) == 0) {
      slot_idx = slot_idx + 1;
    }
  }
  card_idx = Util_GetRandomNumber(slot_idx);
  match_count = 1;
  while ((match_count < 6 && (card_idx != 0))) {
    if ((DAT_0067bdb4 & 1 << ((uint8_t)match_count & 0x1f)) == 0) {
      card_idx = card_idx + -1;
    }
    match_count = match_count + 1;
  }
  return match_count;
}

/*
 * Decompiled function: FUN_0040f78d
 * Entry Point: 0040f78d
 * Size: 554 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0040f78d(int player_id)

{
  int val_1;
  int loop_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int slot_idx;
  
  val_1 = arg_1 * 7;
  loop_idx = (int)(char)(&DAT_00522628)[arg_1 * 0x1dc];
  if ((val_1 < 0x25) && (val_1 % 7 != 0)) {
    loop_idx = loop_idx + g_CampaignDifficultyLevel * 2;
  }
  else if ((val_1 < 0x25) && (val_1 % 7 == 0)) {
    loop_idx = loop_idx + g_CampaignDifficultyLevel * 5;
  }
  else if (val_1 < 0x37) {
    loop_idx = loop_idx + g_CampaignDifficultyLevel * 2;
  }
  else if (0x36 < val_1) {
    loop_idx = loop_idx + g_CampaignDifficultyLevel * 0x32;
  }
  if ((&DAT_0052262a)[arg_1 * 0x1dc] == '\v') {
    for (card_idx = 0; card_idx < 10; card_idx = card_idx + 1) {
      if ((g_OverworldMovementFlags & 1 << ((uint8_t)card_idx & 0x1f)) != 0) {
        loop_idx = loop_idx + 1;
      }
    }
  }
  if ((&DAT_0052262a)[arg_1 * 0x1dc] == '\f') {
    target_idx = 0;
    slot_idx = 0;
    for (card_idx = 0; (card_idx < 1000 && ((&DAT_0067b9b0)[card_idx] != '\0'));
        card_idx = card_idx + 1) {
      if ((int)(char)(&DAT_0067b9b0)[card_idx] >> 4 == 1 << ((uint8_t)arg_1 & 0x1f)) {
        target_idx = target_idx + 1;
      }
    }
    for (player_idx = 0; player_idx < 0x80; player_idx = player_idx + 1) {
      if (((&DAT_0067be01)[player_idx * 100] != '\0') &&
         ((*(int *)(&g_CardSlot_StatusFlags + player_idx * 100) >> 8) + -1 == card_idx)) {
        slot_idx = slot_idx + 1;
      }
    }
    val_1 = ((loop_idx + 10) - target_idx) + g_CampaignDifficultyLevel * slot_idx;
    loop_idx = g_CampaignDifficultyLevel * 5 + 0x14;
    if (loop_idx <= val_1) {
      loop_idx = val_1;
    }
  }
  return loop_idx;
}

/*
 * Decompiled function: FUN_0040f9b7
 * Entry Point: 0040f9b7
 * Size: 130 bytes
 */


int FUN_0040f9b7(uint8_t arg_1)

{
  int match_count;
  int slot_idx;
  
  slot_idx = 0;
  for (match_count = 0; match_count < 0x80; match_count = match_count + 1) {
    if (((&DAT_0067be01)[match_count * 100] != '\0') &&
       ((*(int *)(&g_CardSlot_StatusFlags + match_count * 100) >> 8) + -1 == 1 << (arg_1 & 0x1f))) {
      slot_idx = slot_idx + 1;
    }
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0040fa39
 * Entry Point: 0040fa39
 * Size: 420 bytes
 */


int32_t FUN_0040fa39(char *filepath,char *mode_str,int event_type)

{
  int32_t uval_1;
  int match_count;
  uint32_t slot_idx;
  
  if (arg_3 != 0) {
    DAT_00517590 = 0;
    for (slot_idx = 0; (int)slot_idx < 0x80; slot_idx = slot_idx + 1) {
      if (((&g_CardSlot_StatusFlags)[slot_idx * 100] & 1) != 0) {
        DAT_00517590 = DAT_00517590 + 1;
      }
    }
    if (DAT_00517590 < 2) {
      return 0xffffffff;
    }
    DAT_005384f8 = Util_GetRandomNumber(DAT_00517590);
    DAT_005384fc = Util_GetRandomNumber(DAT_00517590);
    while (DAT_005384fc == DAT_005384f8) {
      DAT_005384fc = Util_GetRandomNumber(DAT_00517590);
    }
  }
  if (DAT_00517590 < 2) {
    uval_1 = 0xffffffff;
  }
  else {
    match_count = 0;
    for (slot_idx = 0; (int)slot_idx < 0x80; slot_idx = slot_idx + 1) {
      if (((&g_CardSlot_StatusFlags)[slot_idx * 100] & 1) != 0) {
        if (DAT_005384f8 == match_count) {
          g_OverworldWorldState = 0;
          Ai_TownEncounter_004c3b19(slot_idx);
          strcpy(str_1,&g_OverworldWorldState);
          match_count = match_count + 1;
        }
        else if (DAT_005384fc == match_count) {
          g_OverworldWorldState = 0;
          Ai_TownEncounter_004c3b19(slot_idx);
          strcpy(str_2,&g_OverworldWorldState);
          match_count = match_count + 1;
        }
        else {
          match_count = match_count + 1;
        }
      }
    }
    uval_1 = 2;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0040fbe2
 * Entry Point: 0040fbe2
 * Size: 184 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0040fbe2(void)

{
  int card_idx;
  int match_count;
  int slot_idx;
  
  slot_idx = 0;
  for (match_count = 0; match_count < 0xc; match_count = match_count + 1) {
    if ((g_OverworldMovementFlags & 1 << ((uint8_t)match_count & 0x1f)) == 0) {
      slot_idx = slot_idx + 1;
    }
  }
  if (slot_idx == 0) {
    match_count = -1;
  }
  else {
    card_idx = Util_GetRandomNumber(slot_idx);
    match_count = 0;
    while ((match_count < 0xc && (card_idx != 0))) {
      if ((g_OverworldMovementFlags & 1 << ((uint8_t)match_count & 0x1f)) == 0) {
        card_idx = card_idx + -1;
      }
      match_count = match_count + 1;
    }
  }
  return match_count;
}

/*
 * Decompiled function: FUN_0040fc9a
 * Entry Point: 0040fc9a
 * Size: 88 bytes
 */


void FUN_0040fc9a(int player_id,char *mode_str,char *str_3)

{
  uint32_t arg_1_00;
  
  arg_1_00 = *(uint32_t *)(&DAT_005224e8 + arg_1 * 0x10);
  strcpy(str_2,(&PTR_s_Sleight_of_hand_005225d0)[arg_1]);
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


void FUN_00410c7d(char *arg_1)

{
  Mem_AllocOrFree_00510de0(1,arg_1);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
               (int *)g_DisplaySurfaceScreen,0,0);
  return;
}

/*
 * Decompiled function: FUN_00410cc0
 * Entry Point: 00410cc0
 * Size: 561 bytes
 */


int FUN_00410cc0(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  uint32_t uval_1;
  int val_2;
  int val_3;
  
  val_2 = Deck_AddCardToDeck(arg_1,arg_3);
  if (val_2 != -1) {
    *(uint32_t *)(&g_CardSlot_Flags + val_2 * 0x120 + arg_1 * 0x5b20) =
         CONCAT31((uint3)((arg_1 == 0) - 1 >> 8) & 0x10,2);
    (&g_CardSlot_PlusOneCounters)[val_2 * 0x120 + arg_1 * 0x5b20] =
         (&g_CardSlot_PlusOneCounters)[arg_2 * 0x120 + arg_1 * 0x5b20];
    (&g_CardSlot_MinusOneCounters)[val_2 * 0x120 + arg_1 * 0x5b20] =
         (&g_CardSlot_MinusOneCounters)[arg_2 * 0x120 + arg_1 * 0x5b20];
    (&g_CardSlot_DamageReceived)[val_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)arg_1;
    *(int *)(&g_CardSlot_TypeFlags + val_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
    uval_1 = *(uint32_t *)(&g_MasterCardTypeTable +
                     *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34);
    val_3 = FUN_00478aa4(*(int *)(&g_MasterCardTypeTable +
                                 *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                 0x34),arg_1,arg_2);
    *(uint32_t *)(&DAT_006a5f74 + val_2 * 0x120 + arg_1 * 0x5b20) = uval_1 | val_3 << 0x10;
    (&g_CardSlot_Toughness)[val_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)arg_4;
    *(int *)(&g_CardSlot_OriginalCardId + val_2 * 0x120 + arg_1 * 0x5b20) = arg_5;
    if ((arg_4 != -1) && (arg_5 != -1)) {
      *(uint32_t *)(&g_CardSlot_Abilities2 + arg_4 * 0x5b20 + arg_5 * 0x120) =
           *(uint32_t *)(&g_CardSlot_Abilities2 + arg_4 * 0x5b20 + arg_5 * 0x120) | 0xf000000;
    }
  }
  return val_2;
}

/*
 * Decompiled function: FUN_00410ef1
 * Entry Point: 00410ef1
 * Size: 622 bytes
 */


int32_t FUN_00410ef1(int player_id,int card_slot,int event_type)

{
  if (((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)
      && ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX))
     && (g_OverworldMapGrid != -1)) {
    if ((((&DAT_006a5f56)[arg_2 * 0x120 + arg_1 * 0x5b20] & 8) != 0) &&
       (*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      *(uint16_t *)(&g_CardSlot_PowerCounters + arg_2 * 0x120 + arg_1 * 0x5b20) =
           (uint16_t)*(int32_t *)
                    (&g_CardSlot_ConvertedManaCost +
                    *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) &
           0xff;
      *(uint16_t *)(&g_CardSlot_ToughnessCounters + arg_2 * 0x120 + arg_1 * 0x5b20) =
           (uint16_t)((uint32_t)*(int32_t *)
                           (&g_CardSlot_ConvertedManaCost +
                           *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120
                           + (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                             0x5b20) >> 8) & 0xff;
    }
    if (arg_3 == 0x32) {
      g_ActivePalette = g_ActivePalette + *(short *)(&g_CardSlot_PowerCounters + arg_2 * 0x120 + arg_1 * 0x5b20)
      ;
    }
    if (arg_3 == 0x33) {
      g_ActivePalette = g_ActivePalette + *(short *)(&g_CardSlot_ToughnessCounters + arg_2 * 0x120 + arg_1 * 0x5b20)
      ;
    }
  }
  if ((((&g_CardSlot_Abilities1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) &&
     ((arg_3 == 0x22 || (arg_3 == 199)))) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_0041115f
 * Entry Point: 0041115f
 * Size: 162 bytes
 */


int32_t FUN_0041115f(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x78) &&
      (*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) == DAT_006b2d5c)) &&
     ((char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] == DAT_007006c8)) {
    g_ActivePalette = g_ActivePalette + 1;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00411201
 * Entry Point: 00411201
 * Size: 269 bytes
 */


int32_t FUN_00411201(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x22) || (arg_3 == 199)) &&
     ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_DefendingPlayer)) {
    if (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
    }
    else {
      *(uint32_t *)(&g_CardSlot_Abilities1 +
               *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities1 +
                    *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) &
           0xffff7fff;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_0041130e
 * Entry Point: 0041130e
 * Size: 1093 bytes
 */


int32_t FUN_0041130e(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x34) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)
       ) && ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
             g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) {
    g_ActivePalette =
         g_ActivePalette | *(uint32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)
    ;
  }
  if ((((arg_3 == 0x77) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)
       ) && (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
              g_OverworldPlayerCoordX &&
             ((g_OverworldMapGrid != -1 &&
              ((&g_CardSlot_CardTypeIndex)
               [*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] != '\x04')))
             ))) &&
     (*(int *)(&g_MasterCardTypeTable +
              *(int *)(&g_CardSlot_CardId +
                      *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) *
              0x34) == 0x1a3)) {
    Pic_Subsystem_0044867e
              ((int)(char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20],
               *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20),2);
  }
  if ((g_OverworldMapGrid == arg_2) && (g_OverworldPlayerCoordX == arg_1)) {
    if ((&g_CardSlot_CardTypeIndex)[arg_2 * 0x120 + arg_1 * 0x5b20] == '\x05') {
      if (((g_PlayerManaPool == 0xcd) || (arg_3 == 199)) &&
         ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_CurrentCardColorTarget)) {
        if (arg_3 == 0x7d) {
          g_ActivePalette = g_ActivePalette | 2;
        }
        if (((arg_3 == 0x7e) || (arg_3 == 199)) &&
           (Pic_Subsystem_0044867e
                      ((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),2),
           *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
          Pic_Subsystem_0044867e(arg_1,arg_2,2);
        }
      }
    }
    else if ((((&g_CardSlot_Abilities1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) &&
            ((arg_3 == 0x22 || (arg_3 == 199)))) {
      if ((&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1) {
        *(int32_t *)
         (&g_CardSlot_Abilities2 +
         *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) = 0x8000000;
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00411753
 * Entry Point: 00411753
 * Size: 341 bytes
 */


int32_t FUN_00411753(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x34) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) == g_OverworldMapGrid)
       ) && ((char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] ==
             g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) {
    g_ActivePalette =
         g_ActivePalette &
         ~*(uint32_t *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120);
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    if ((&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1) {
      *(int32_t *)
       (&g_CardSlot_Abilities2 +
       *(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
       (char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) = 0x8000000;
    }
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_004118a8
 * Entry Point: 004118a8
 * Size: 1776 bytes
 */


int32_t FUN_004118a8(int player_id,int card_slot,int event_type)

{
  char cVar1;
  uint32_t uval_2;
  int val_3;
  
  if ((((g_OverworldMapGrid == arg_2) && (g_OverworldPlayerCoordX == arg_1)) &&
      (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) &&
     (((uint8_t)g_PlayerHandCardCount & 4) != 0)) {
    uval_2 = FUN_00473179((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                         *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),0x34,
                         0xffffffff);
    if ((uval_2 & 0x1ff800) != 0) {
      cVar1 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)
                           [*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120
                            + (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                              0x5b20]);
      if ((uval_2 & 0x800 << (cVar1 - 1U & 0x1f)) != 0) {
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        Pic_Subsystem_0044867e(arg_1,arg_2,1);
      }
    }
  }
  if (((arg_3 == 0x6e) && (g_OverworldMapGrid == arg_2)) &&
     ((g_OverworldPlayerCoordX == arg_1 &&
      (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)))) {
    *(uint32_t *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    if (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0xe);
      }
      if (*(int *)(&g_MasterCardTypeTable +
                  *(int *)(&g_CardSlot_CardId +
                          *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                          (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                          0x5b20) * 0x34) == DAT_006a2848) {
        (&DAT_00700ec0)
        [(char)(&g_CardSlot_DamageReceived)
               [*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] * 0xa0
         + (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] +
           *(int *)(&g_CardSlot_TypeFlags +
                   *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 2]
             = (&DAT_00700ec0)
               [(char)(&g_CardSlot_DamageReceived)
                      [*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                       (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20]
                * 0xa0 + (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] +
                         *(int *)(&g_CardSlot_TypeFlags +
                                 *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                 0x120 + (char)(&g_CardSlot_DamageReceived)
                                               [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 2] +
               (char)*(int32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)
        ;
      }
      else {
        (&DAT_00700ec0)
        [*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 2 +
         (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0xa0 +
         (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]] =
             (&DAT_00700ec0)
             [*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 2 +
              (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0xa0 +
              (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]] +
             (char)*(int32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      (&g_PlayerCreatureCount)[(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]] =
           (&g_PlayerCreatureCount)[(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]] -
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(int *)(&DAT_006b3030 + (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 4) =
           *(int *)(&DAT_006b3030 +
                   (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 4) +
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    else {
      val_3 = FUN_00471c32((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                           *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20));
      if ((val_3 != 0) &&
         (*(short *)(&g_CardSlot_Power +
                    *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
               *(short *)(&g_CardSlot_Power +
                         *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) *
                         0x120 + (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                                 0x5b20) +
               (short)*(int32_t *)
                       (&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20),
         g_IsAiThinking != 1)) {
        Magic_UpkeepPhase(0x16);
        Ai_Subsystem_004cc3f8
                  ((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(int32_t *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),6,2)
        ;
      }
    }
  }
  return 0;
}

/*
 * Decompiled function: CardScript_NafsAsp_DamageTrigger
 * Entry Point: 00411f98
 * Size: 435 bytes
 */


int32_t CardScript_NafsAsp_DamageTrigger(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x73) {
    uval_1 = FUN_0040d949(arg_1,7,1);
  }
  else {
    if (((arg_3 == 0x6d) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      val_2 = FUN_0040d949(arg_1,7,1);
      if (val_2 != 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,0,1);
      }
    }
    if (arg_3 == 0x72) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,4);
    }
    if ((((g_PlayerManaPool == 0xce) || (arg_3 == 199)) &&
        ((g_OverworldMapGrid == arg_2 &&
         ((g_OverworldPlayerCoordX == arg_1 && (g_DefendingPlayer == arg_1)))))) &&
       (arg_1 == g_CurrentCardColorTarget)) {
      if (arg_3 == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Naf_s_Asp_takes_1_life__005196ac,0);
        Mem_AllocOrFree_0041df33(arg_1,1,arg_1,arg_2);
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      if (g_IsAiThinking == 1) {
        Mem_AllocOrFree_0041df33(arg_1,1,arg_1,arg_2);
      }
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0041214b
 * Entry Point: 0041214b
 * Size: 251 bytes
 */


int32_t FUN_0041214b(int player_id,int card_slot,int event_type)

{
  if ((((g_PlayerManaPool == 0xcc) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
     (g_OverworldPlayerCoordX == arg_1)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      if ((&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1) {
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00412246
 * Entry Point: 00412246
 * Size: 461 bytes
 */


int32_t FUN_00412246(int player_id,int card_slot,int event_type)

{
  if ((((g_PlayerManaPool == 0xcc) || (arg_3 == 199)) && (arg_2 == g_OverworldMapGrid)) &&
     (arg_1 == g_OverworldPlayerCoordX)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      if ((&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1) {
        Mem_AllocOrFree_0041df33(arg_1,5,arg_1,arg_2);
      }
      if ((*(int *)(&g_CardSlot_CardId +
                   *(int *)(&g_CardSlot_TypeFlags + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                   (char)(&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) !=
           -1) && (((&g_CardSlot_Flags)
                    [*(int *)(&g_CardSlot_TypeFlags + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                     (char)(&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20] &
                   2) != 0)) {
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120],
                   *(int *)(&g_CardSlot_TypeFlags + arg_1 * 0x5b20 + arg_2 * 0x120),1);
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00412413
 * Entry Point: 00412413
 * Size: 371 bytes
 */


int32_t FUN_00412413(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if ((((arg_3 == 0x32) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)
       ) && ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
             g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) {
    val_1 = FUN_00471c32((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                         *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20));
    if ((val_1 != 0) &&
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 0x34] &
        2) != 0)) {
      g_ActivePalette = g_ActivePalette + -2;
    }
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00412586
 * Entry Point: 00412586
 * Size: 260 bytes
 */


int32_t FUN_00412586(int player_id,int card_slot,int event_type)

{
  if ((arg_3 == 0x21) &&
     (((g_ScWillyScore == 0x1a || (g_ScWillyScore == 0x19)) &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_TypeFlags +
                         g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x120 +
                 (char)(&g_CardSlot_DamageReceived)
                       [g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] * 0x5b20) *
         0x34] & 2) != 0)))) {
    *(int32_t *)
     (&g_CardSlot_ConvertedManaCost + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)
         = 0;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}

/*
 * Decompiled function: UI_PromptLifeBidValidation
 * Entry Point: 0041268a
 * Size: 437 bytes
 */


bool UI_PromptLifeBidValidation(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int slot_idx;
  
  if (arg_3 == 0x73) {
    if ((g_ActivePlayerPriority == arg_1) && ((&g_PlayerCreatureCount)[arg_1] == 1)) {
      flag_1 = false;
    }
    else {
      flag_1 = 0 < (int)(&g_PlayerCreatureCount)[arg_1];
    }
  }
  else {
    if (arg_3 == 0x6d) {
      flag_1 = false;
      while ((!flag_1 && (g_ActivePlayer != 1))) {
        slot_idx = Ai_Subsystem_004cc8de(arg_1,s_Spend_how_much_life_for_generic_m_005196c4,1);
        if (slot_idx < 0) {
          g_ActivePlayer = 1;
        }
        else if ((int)(&g_PlayerCreatureCount)[arg_1] < slot_idx) {
          if (g_IsAiThinking != 1) {
            Ai_Util_004cc42d(s_Illegal_Amount___must_be_between_005196ec);
            Sleep(2000);
            Ai_Util_004cc42d(&DAT_0051971c);
          }
        }
        else {
          flag_1 = true;
        }
      }
      if (g_ActivePlayer != 1) {
        FUN_0040d901(arg_1,0,slot_idx);
        (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] - slot_idx;
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    if (((arg_3 == 0x7f) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      FUN_0040d7e9(arg_1,0,(&g_PlayerCreatureCount)[arg_1]);
    }
    flag_1 = false;
  }
  return flag_1;
}

/*
 * Decompiled function: FUN_0041283f
 * Entry Point: 0041283f
 * Size: 1750 bytes
 */


int32_t FUN_0041283f(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((&DAT_006a5f69)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x40) != 0) {
    if (((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) ==
          g_OverworldMapGrid) &&
        ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX))
       && (g_OverworldMapGrid != -1)) {
      if (arg_3 == 0x34) {
        g_ActivePalette =
             g_ActivePalette |
             *(uint32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      if (arg_3 == 0x32) {
        g_ActivePalette =
             g_ActivePalette + (int)*(short *)(&g_CardSlot_PowerCounters + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
    }
    if (((g_OverworldMapGrid == arg_2) && (arg_1 == g_OverworldPlayerCoordX)) &&
       ((arg_3 == 0x22 &&
        ((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1 &&
         (((&g_CardSlot_Flags)
           [*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
            (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] & 0x40) != 0))))
       )) {
      (&g_CardSlot_CardTypeIndex)[arg_2 * 0x120 + arg_1 * 0x5b20] = 5;
    }
  }
  if (((&DAT_006a5f69)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0) {
    if (((((arg_3 == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
         (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) ==
          g_OverworldMapGrid)) &&
        (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX
         && (g_OverworldMapGrid != -1)))) &&
       (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) != -1))
    {
      val_1 = FUN_0041d963(arg_1,arg_2,
                           *(int *)(&g_CardSlot_ConvertedManaCost +
                                   *(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20)
                                   * 0x120 + (char)(&g_CardSlot_DamageReceived)
                                                   [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20));
      g_ActivePalette = val_1 - 1;
    }
    if (((arg_3 == 0x77) &&
        ((char)(&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
         g_OverworldPlayerCoordX)) &&
       (*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)) {
      *(uint32_t *)(&g_CardSlot_Abilities2 +
               *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities2 +
                    *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) |
           0x1000000;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  if (((&DAT_006a5f6a)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x40) != 0) {
    if ((arg_3 == 0x6a) && (arg_1 == g_DefendingPlayer)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
      *(int32_t *)(&DAT_00680780 + arg_1 * 4) = 0;
    }
    if ((arg_3 == 0x79) &&
       ((*(uint32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) &
        *(uint32_t *)(&g_CardSlot_Abilities2 +
                 g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)) == 0)) {
      g_ActivePalette = g_ActivePalette + 1;
    }
  }
  if (((&DAT_006a5f69)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0) {
    if ((arg_3 == 0x6a) && (DAT_006ff2d8 == -1)) {
      DAT_006ff2d8 = arg_1;
    }
    if ((arg_3 == 0x22) && (DAT_007006d4 == 0)) {
      DAT_007006d4 = 1 << ((uint8_t)arg_1 & 0x1f);
      *(uint32_t *)(&g_CardSlot_Abilities1 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities1 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffffffdf;
    }
  }
  if ((g_OverworldMapGrid == arg_2) && (arg_1 == g_OverworldPlayerCoordX)) {
    if ((&g_CardSlot_CardTypeIndex)[arg_2 * 0x120 + arg_1 * 0x5b20] == '\x05') {
      if (((g_PlayerManaPool == 0xcd) || (arg_3 == 199)) &&
         ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_CurrentCardColorTarget)) {
        if (arg_3 == 0x7d) {
          g_ActivePalette = g_ActivePalette | 2;
        }
        if (((arg_3 == 0x7e) || (arg_3 == 199)) &&
           (Pic_Subsystem_0044867e
                      ((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),2),
           *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
          Pic_Subsystem_0044867e(arg_1,arg_2,2);
        }
      }
    }
    else if ((((&g_CardSlot_Abilities1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) &&
            ((arg_3 == 0x22 || (arg_3 == 199)))) {
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00412f15
 * Entry Point: 00412f15
 * Size: 1617 bytes
 */


int32_t FUN_00412f15(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  int val_2;
  int player_idx;
  uint32_t match_count;
  int slot_idx;
  
  if ((((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid
        ) && ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
              g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) &&
     (((arg_3 == 0x32 && (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) ||
      ((arg_3 == 0x33 && (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 8) != 0))))))
  {
    match_count = 0;
    uval_1 = *(uint32_t *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xf00;
    if (uval_1 < 0x201) {
      if (uval_1 == 0x200) {
        for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
          if (((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == player_idx)
              && (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) ||
             ((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != player_idx &&
              (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)))) {
            for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[player_idx];
                slot_idx = slot_idx + 1) {
              if (((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + player_idx * 0x5b20) != -1) &&
                  (((&g_CardSlot_Flags)[slot_idx * 0x120 + player_idx * 0x5b20] & 2) != 0)) &&
                 (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) ==
                  *(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + player_idx * 0x5b20))) {
                match_count = match_count + 1;
              }
            }
          }
        }
      }
      else if (uval_1 == 0x100) {
        if (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0) {
          val_2 = FUN_0041d963((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20)
                               ,*(int *)(&g_CardSlot_ConvertedManaCost +
                                        arg_2 * 0x120 + arg_1 * 0x5b20));
          match_count = *(uint32_t *)(&g_AiCombatScore_Attacker +
                             val_2 * 4 +
                             (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x20);
        }
        if (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0) {
          val_2 = FUN_0041d963((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20)
                               ,*(int *)(&g_CardSlot_ConvertedManaCost +
                                        arg_2 * 0x120 + arg_1 * 0x5b20));
          match_count = match_count + *(int *)(&g_AiCombatScore_Attacker +
                                      val_2 * 4 +
                                      (1 - (char)(&g_CardSlot_Toughness)
                                                 [arg_2 * 0x120 + arg_1 * 0x5b20]) * 0x20);
        }
      }
    }
    else if (uval_1 == 0x400) {
      if (arg_3 == 0x32) {
        match_count = *(uint32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff;
      }
      else {
        match_count = (uint32_t)(uint8_t)(&DAT_006a5f55)[arg_2 * 0x120 + arg_1 * 0x5b20];
      }
    }
    else if (uval_1 == 0x800) {
      for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
        if ((((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == player_idx) &&
            (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) ||
           (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] != player_idx &&
            (((&g_CardSlot_TargetSlot)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)))) {
          for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[player_idx];
              slot_idx = slot_idx + 1) {
            val_2 = FUN_00471c32(player_idx,slot_idx);
            if (((val_2 != 0) &&
                (((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + player_idx * 0x5b20) * 0x34] & 2)
                 != 0)) &&
               ((&g_MasterCardRarityTable)
                [*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + player_idx * 0x5b20) * 0x34] != '\0')
               ) {
              match_count = match_count + 1;
            }
          }
        }
      }
    }
    g_ActivePalette = g_ActivePalette + match_count;
    if (arg_3 == 0x32) {
      *(short *)(&g_CardSlot_PowerCounters + arg_2 * 0x120 + arg_1 * 0x5b20) = (short)match_count;
    }
    else {
      *(short *)(&g_CardSlot_ToughnessCounters + arg_2 * 0x120 + arg_1 * 0x5b20) = (short)match_count;
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413570
 * Entry Point: 00413570
 * Size: 761 bytes
 */


int32_t FUN_00413570(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int val_2;
  int player_idx;
  int card_idx;
  int slot_idx;
  
  if ((((((&DAT_006a5f6b)[arg_1 * 0x5b20 + arg_2 * 0x120] & 1) != 0) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) == g_OverworldMapGrid)
       ) && ((char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] ==
             g_OverworldPlayerCoordX)) &&
     ((g_OverworldMapGrid != -1 && ((arg_3 == 0x32 || (arg_3 == 0x33)))))) {
    player_idx = 0;
    card_idx = 0;
    val_2 = (int)(char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120];
    slot_idx = 0;
    flag_1 = false;
    while ((slot_idx < (int)(&g_PlayerActiveCardCount)[val_2] && (!flag_1))) {
      if ((((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + val_2 * 0x5b20) == DAT_00701000) &&
           (((&g_CardSlot_Flags)[slot_idx * 0x120 + val_2 * 0x5b20] & 2) != 0)) &&
          ((&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] ==
           (&g_CardSlot_Toughness)[slot_idx * 0x120 + val_2 * 0x5b20])) &&
         (*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) ==
          *(int *)(&g_CardSlot_OriginalCardId + slot_idx * 0x120 + val_2 * 0x5b20))) {
        flag_1 = true;
        card_idx = -(int)*(short *)(&g_CardSlot_PowerCounters + slot_idx * 0x120 + val_2 * 0x5b20);
        player_idx = -(int)*(short *)(&g_CardSlot_ToughnessCounters + slot_idx * 0x120 + val_2 * 0x5b20);
      }
      slot_idx = slot_idx + 1;
    }
    if (arg_3 == 0x32) {
      g_ActivePalette =
           g_ActivePalette + *(short *)(&g_CardSlot_PowerCounters + arg_1 * 0x5b20 + arg_2 * 0x120) + card_idx;
    }
    else {
      g_ActivePalette =
           g_ActivePalette + *(short *)(&g_CardSlot_ToughnessCounters + arg_1 * 0x5b20 + arg_2 * 0x120) + player_idx;
    }
  }
  if ((((&g_CardSlot_Abilities1)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x20) == 0) &&
     ((arg_3 == 0x22 || (arg_3 == 199)))) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413869
 * Entry Point: 00413869
 * Size: 457 bytes
 */


int32_t FUN_00413869(int player_id,int card_slot,int event_type)

{
  if ((arg_3 == 0x22) && (*(int *)(&g_CardSlot_TargetSlot + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    Mem_AllocOrFree_0041d942(*(int *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20));
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
    *(uint32_t *)(&g_CardSlot_Abilities2 +
             *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
             (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Abilities2 +
                  *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) |
         0x1000000;
    FUN_00473179((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                 *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),0x3c,
                 0xffffffff);
    Ai_Subsystem_004cced8();
  }
  if ((((arg_3 == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
      (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid))
     && (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX
         && (g_OverworldMapGrid != -1)))) {
    g_ActivePalette = *(int32_t *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413a32
 * Entry Point: 00413a32
 * Size: 376 bytes
 */


int32_t FUN_00413a32(int player_id,int card_slot,int event_type)

{
  if (((&g_CardSlot_Abilities1)
       [*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
        (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] & 0x80) != 0) {
    (&g_CardSlot_CardTypeIndex)
    [*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
     (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] = 4;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    if ((&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1) {
      *(int32_t *)
       (&g_CardSlot_Abilities2 +
       *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
       (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) = 0x8000000;
    }
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413baa
 * Entry Point: 00413baa
 * Size: 343 bytes
 */


int32_t FUN_00413baa(int player_id,int card_slot,int event_type)

{
  int val_1;
  int arg1;
  int val_2;
  int match_count;
  
  if (arg_3 == 0x89) {
    Glue_Subsystem_004e65e1(FUN_00413d01,-1);
  }
  if ((((arg_3 == 0x22) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
     (g_OverworldPlayerCoordX == arg_1)) {
    arg1 = 1 - arg_1;
    for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[arg1]; match_count = match_count + 1) {
      val_1 = *(int *)(&g_CardSlot_CardId + match_count * 0x120 + arg1 * 0x5b20);
      val_2 = FUN_00471c32(arg1,match_count);
      if (((val_2 != 0) && (((&g_MasterCardColorTable)[val_1 * 0x34] & 2) != 0)) &&
         (((&g_MasterCardRarityTable)[val_1 * 0x34] != '\0' &&
          ((*(uint32_t *)(&g_CardSlot_Flags + match_count * 0x120 + arg1 * 0x5b20) & 0x30040) == 0)))) {
        Pic_Subsystem_0044867e(arg1,match_count,2);
      }
    }
    Pic_Subsystem_0044867e(arg_1,arg_2,2);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413d01
 * Entry Point: 00413d01
 * Size: 140 bytes
 */


int32_t FUN_00413d01(int arg1,int arg2)

{
  int val_1;
  
  if ((g_DefendingPlayer == arg1) && (((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) == 0))
  {
    *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) | 0x8000;
    val_1 = FUN_004726c5(arg1,arg2);
    if (val_1 != 0) {
      g_ActiveBattlefieldFlag = 1;
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413d8d
 * Entry Point: 00413d8d
 * Size: 551 bytes
 */


int32_t FUN_00413d8d(int player_id,int card_slot,int event_type)

{
  if ((arg_3 == 0x21) && ((g_ScWillyScore == 0x1a || (g_ScWillyScore == 0x19)))) {
    if (((&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] ==
         (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20))) {
      *(int32_t *)
       (&g_CardSlot_ConvertedManaCost +
       g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) = 0;
    }
    if (((&g_CardSlot_DamageReceived)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]
         == (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]) &&
       (*(int *)(&g_CardSlot_TypeFlags +
                g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20))) {
      *(int32_t *)
       (&g_CardSlot_ConvertedManaCost +
       g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) = 0;
    }
  }
  if ((((g_PlayerManaPool == 0xcc) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
     (g_OverworldPlayerCoordX == arg_1)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00413fb4
 * Entry Point: 00413fb4
 * Size: 700 bytes
 */


int32_t FUN_00413fb4(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) &&
      (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid))
     && ((((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX
          && (g_OverworldMapGrid != -1)) &&
         (*(int *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)))) {
    g_ActivePalette = *(uint32_t *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(uint32_t *)(&g_CardSlot_Abilities1 +
             *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
             (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Abilities1 +
                  *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) | 0x40;
  }
  if (((g_PlayerManaPool == 0xc9) || (arg_3 == 199)) &&
     ((g_OverworldMapGrid == arg_2 &&
      (((g_OverworldPlayerCoordX == arg_1 && (g_DefendingPlayer == arg_1)) &&
       (g_CurrentCardColorTarget == arg_1)))))) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      Mem_AllocOrFree_0041d942(*(int *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20));
      *(int32_t *)(&g_CardSlot_Controller + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      *(uint32_t *)(&g_CardSlot_Abilities2 +
               *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities2 +
                    *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) |
           0x1000000;
      FUN_00473179((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),0x3c,
                   0xffffffff);
      Ai_Subsystem_004cced8();
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00414270
 * Entry Point: 00414270
 * Size: 813 bytes
 */


int32_t FUN_00414270(int player_id,int card_slot,int event_type)

{
  int val_1;
  int match_count;
  int slot_idx;
  
  if ((((g_PlayerManaPool == 0xd5) && (g_OverworldMapGrid == arg_2)) &&
      (g_OverworldPlayerCoordX == arg_1)) && (arg_1 == g_CurrentCardColorTarget)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      val_1 = Pic_Subsystem_0045268f(0x200);
      if (*(int *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + arg_2 * 0x120) == val_1) {
        if ((g_IsAiThinking == 1) && (arg_1 == g_CurrentTurnPhase)) {
          (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + 1;
        }
        else {
          (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + 2;
        }
      }
      val_1 = Pic_Subsystem_0045268f(0xb5);
      if (*(int *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + arg_2 * 0x120) == val_1) {
        (&g_PlayerCreatureCount)
        [(*(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x1000) >> 0xc] =
             (int)(&g_PlayerCreatureCount)
                  [(*(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x1000) >> 0xc]
             / 2;
      }
      val_1 = Pic_Subsystem_0045268f(0x32);
      if (*(int *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + arg_2 * 0x120) == val_1) {
        Mem_AllocOrFree_0041df33
                  ((int)(char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120],
                   *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120),arg_1,
                   arg_2);
      }
      val_1 = Pic_Subsystem_0045268f(0x109);
      if (*(int *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + arg_2 * 0x120) == val_1) {
        for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
          Mem_AllocOrFree_0041df33
                    (slot_idx,*(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120
                                     ),arg_1,arg_2);
          for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx];
              match_count = match_count + 1) {
            val_1 = FUN_00471c32(slot_idx,match_count);
            if ((val_1 != 0) &&
               (((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 2) !=
                0)) {
              FUN_0041db67(slot_idx,match_count,
                           *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120),
                           arg_1,arg_2);
            }
          }
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,4);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_0041459d
 * Entry Point: 0041459d
 * Size: 519 bytes
 */


int32_t FUN_0041459d(int player_id,int card_slot,int event_type)

{
  int val_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if ((((g_PlayerManaPool == 0xd7) && (g_OverworldMapGrid == arg_2)) &&
      (arg_1 == g_OverworldPlayerCoordX)) && (arg_1 == g_CurrentCardColorTarget)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      val_1 = Pic_Subsystem_0045268f(0x44);
      if (*(int *)(&g_ActiveCardsInPlay + arg_2 * 0x120 + arg_1 * 0x5b20) == val_1) {
        slot_idx = 0;
        for (card_idx = 0; card_idx < 2; card_idx = card_idx + 1) {
          for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[card_idx];
              match_count = match_count + 1) {
            if (((*(int *)(&g_CardSlot_CardId + match_count * 0x120 + card_idx * 0x5b20) == g_PendingSpellTargetSlot
                 ) && ((&g_CardSlot_DamageReceived)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
                       (&g_CardSlot_DamageReceived)[match_count * 0x120 + card_idx * 0x5b20])) &&
               (*(int *)(&g_CardSlot_TypeFlags + arg_2 * 0x120 + arg_1 * 0x5b20) ==
                *(int *)(&g_CardSlot_TypeFlags + match_count * 0x120 + card_idx * 0x5b20))) {
              slot_idx = slot_idx + *(int *)(&g_CardSlot_ConvertedManaCost +
                                          match_count * 0x120 + card_idx * 0x5b20);
            }
          }
        }
        val_1 = *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
        if (slot_idx <= *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          val_1 = slot_idx;
        }
        (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + val_1;
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,4);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_004147a4
 * Entry Point: 004147a4
 * Size: 189 bytes
 */


int32_t FUN_004147a4(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (((arg_3 == 0x72) || (arg_3 == 0x86)) || (arg_3 == 0x7e)) {
    g_DialogPromptHwnd = *(int32_t *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20);
    g_DuelArenaHwnd = *(int32_t *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20);
    uval_1 = (**(code **)(&g_CardScriptCallbackTable +
                        *(int *)(&g_ActiveCardsInPlay + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34))
                      (arg_1,arg_2,arg_3);
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_00414875
 * Entry Point: 00414875
 * Size: 210 bytes
 */


int32_t FUN_00414875(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if ((((arg_3 == 0x73) && (g_ScWillyScore == 10)) && (g_CurrentTurnTargetPlayer == arg_1)) &&
     ((*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0 &&
      (g_PlayerManaPool == -1)))) {
    g_CombatPhaseFlags = g_CombatPhaseFlags | 3;
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x6d) {
      *(uint32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    }
    if (arg_3 == 0x72) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,4);
      Magic_ExecuteDrawPhase(arg_1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: CardScript_NaturalSelection
 * Entry Point: 00414947
 * Size: 378 bytes
 */


int32_t CardScript_NaturalSelection(int player_id,int32_t arg_2,int event_type)

{
  int32_t uval_1;
  int val_2;
  int target_idx;
  int player_idx;
  int card_idx [3];
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      val_2 = Ai_Subsystem_004cc814
                        (arg_1,s_Natural_Selection__0051974c,0,s_See_your_library_00519738,
                         s_See_opponent_s_library_00519720,(char *)0x0);
      if (val_2 == 0) {
        player_idx = arg_1;
      }
      else {
        player_idx = 1 - arg_1;
      }
      while( true ) {
        for (target_idx = 0; target_idx < 3; target_idx = target_idx + 1) {
          card_idx[target_idx] = *(int *)(&g_PlayerDeckCardList + target_idx * 4 + player_idx * 2000);
        }
        UI_DeckSelectionMenu(arg_1,(int)card_idx,3,s_Next_3__R_to_L__library_cards_00519768,0);
        val_2 = Ai_Subsystem_004cc814
                          (arg_1,s_Natural_Selection__005197bc,0,s_No_change_005197b0,
                           s_Rearrange_these_cards_00519798,s_Shuffle_deck_00519788);
        if (val_2 != 1) break;
        for (target_idx = 0; target_idx < 3; target_idx = target_idx + 1) {
          do {
            val_2 = Util_GetRandomNumber(3);
          } while (card_idx[val_2] == -2);
          *(int *)(&g_PlayerDeckCardList + target_idx * 4 + player_idx * 2000) = card_idx[val_2];
          card_idx[val_2] = -2;
        }
      }
      if (val_2 == 2) {
        Pic_Subsystem_00452276(player_idx);
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_00414ac1
 * Entry Point: 00414ac1
 * Size: 723 bytes
 */


int32_t FUN_00414ac1(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (g_SelectedTargetPlayer == -1) {
      uval_2 = 0;
    }
    else {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           g_TurnCounter;
      if ((((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + g_SelectedTargetSlot * 0x120 + g_SelectedTargetPlayer * 0x5b20) * 0x34] &
           0x18) == 0) ||
         (val_1 = Rules_ParseFilter_0040360b
                            (g_SelectedTargetPlayer,g_SelectedTargetSlot,(char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,
                             0xffffffff,0xffffffff,2,0,0), val_1 == 0)) {
        uval_2 = 0;
      }
      else {
        uval_2 = 99;
      }
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if (g_SelectedTargetPlayer == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = g_SelectedTargetPlayer;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = g_SelectedTargetSlot;
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      }
    }
    if (arg_3 == 0x71) {
      val_1 = Deck_AddCardToDeck
                        (arg_1,*(int *)(&g_CardSlot_CardId +
                                       *(int *)(&g_CardSlot_AttachedAura +
                                               arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                       *(int *)(&g_CardSlot_CombatTarget +
                                               arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20));
      if (val_1 != -1) {
        (&g_CardSlot_MinusOneCounters)[val_1 * 0x120 + arg_1 * 0x5b20] = 0x10;
        *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities1 + val_1 * 0x120 + arg_1 * 0x5b20) | 8;
        g_TurnCounter =
             *(int32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
        g_PlayerHandCardCount = g_PlayerHandCardCount | 0x400;
        Pic_Subsystem_0042ac1f(arg_1,val_1);
        g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffffbff;
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_00414f59
 * Entry Point: 00414f59
 * Size: 295 bytes
 */


int32_t FUN_00414f59(int player_id,int card_slot,int event_type)

{
  g_AiManaPoolReserve = 1;
  g_PendingAttackersTargetSlot = 0xffffffff;
  if ((((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       (((&g_MasterCardColorTable)[arg_3 * 0x34] & 1) != 0)) &&
      (((&g_MasterCardFlagsTable)[arg_3 * 0x34] & 0x10) != 0)) &&
     ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 &&
      (((&g_MasterCardColorTable)[arg_3 * 0x34] & 1) != 0)))) {
    Magic_TriggerCardEvent(arg_1,arg_2,0x6d,1 - arg_1,0xffffffff);
    if (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0) {
      Rules_ApplyContinuousDamage(arg_1,arg_2,0x81);
    }
  }
  g_AiManaPoolReserve = 0;
  return 0;
}

/*
 * Decompiled function: FUN_00415080
 * Entry Point: 00415080
 * Size: 126 bytes
 */


int32_t FUN_00415080(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    if ((arg_1 == g_DefendingPlayer) || (0x14 < g_ScWillyScore)) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    if (arg_3 == 0x71) {
      FUN_00410cc0(arg_1,arg_2,DAT_0068a658,-1,-1);
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_00415d48
 * Entry Point: 00415d48
 * Size: 176 bytes
 */


int32_t FUN_00415d48(int arg1,int arg2)

{
  if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) {
    *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) | 0x10;
    if (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 1) != 0) {
      g_PendingAttackersTargetSlot = 0xffffffff;
    }
    Rules_ApplyContinuousDamage(arg1,arg2,0x81);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00416059
 * Entry Point: 00416059
 * Size: 208 bytes
 */


int32_t FUN_00416059(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      Glue_Subsystem_004df8ba(arg_1,arg_2);
    }
    if (arg_3 == 0x71) {
      val_2 = Glue_Subsystem_004dfb23(arg_1,arg_2,0x71,4);
      if (val_2 != 0) {
        Mem_AllocOrFree_0041df33(arg_1,2,arg_1,arg_2);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_00416129
 * Entry Point: 00416129
 * Size: 249 bytes
 */


int32_t FUN_00416129(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (match_count = 0; match_count < 2; match_count = match_count + 1) {
        for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[match_count]; slot_idx = slot_idx + 1)
        {
          val_2 = FUN_00471c32(match_count,slot_idx);
          if ((val_2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + match_count * 0x5b20 + slot_idx * 0x120) * 0x34] & 2) != 0)
             ) {
            FUN_00410cc0(arg_1,arg_2,DAT_006ff374,match_count,slot_idx);
          }
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_00416cda
 * Entry Point: 00416cda
 * Size: 92 bytes
 */


int32_t FUN_00416cda(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      FUN_00410cc0(arg_1,arg_2,DAT_0068a670,-1,-1);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_00417919
 * Entry Point: 00417919
 * Size: 139 bytes
 */


int32_t FUN_00417919(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if ((arg_3 == 0x32) &&
       (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 4) !=
        0)) {
      g_ActivePalette = g_ActivePalette + 2;
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_004179a4
 * Entry Point: 004179a4
 * Size: 179 bytes
 */


int32_t FUN_004179a4(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      DAT_00538728 = arg_1;
      DAT_0053872c = arg_2;
      Glue_Subsystem_004e65e1(FUN_00417a57,g_DefendingPlayer);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    if (arg_3 == 0x3b) {
      val_2 = FUN_0040d949(arg_1,5,2);
      if (val_2 != 0) {
        val_2 = FUN_0040d949(arg_1,7,3);
        if (val_2 != 0) {
          *(int *)(&DAT_00695eb0 + arg_1 * 4) = *(int *)(&DAT_00695eb0 + arg_1 * 4) + 1;
          *(int *)(&DAT_00695eb8 + arg_1 * 4) = *(int *)(&DAT_00695eb8 + arg_1 * 4) + 1;
        }
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_00417a57
 * Entry Point: 00417a57
 * Size: 178 bytes
 */


int32_t FUN_00417a57(int arg1,int arg2)

{
  int val_1;
  
  if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
    val_1 = FUN_00410cc0(DAT_00538728,DAT_0053872c,g_PlayerSelectionPriority,arg1,arg2);
    if (val_1 != -1) {
      *(int16_t *)(&g_CardSlot_PowerCounters + val_1 * 0x120 + DAT_00538728 * 0x5b20) = 1;
      *(int16_t *)(&g_CardSlot_ToughnessCounters + val_1 * 0x120 + DAT_00538728 * 0x5b20) = 1;
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00417b09
 * Entry Point: 00417b09
 * Size: 176 bytes
 */


int32_t FUN_00417b09(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      DAT_00538740 = arg_1;
      DAT_0053873c = arg_2;
      Glue_Subsystem_004e65e1(FUN_00417bb9,1 - g_DefendingPlayer);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    if (arg_3 == 0x3b) {
      val_2 = FUN_0040d949(arg_1,5,1);
      if (val_2 != 0) {
        val_2 = FUN_0040d949(arg_1,7,2);
        if (val_2 != 0) {
          *(int *)(&DAT_00695eb8 + arg_1 * 4) = *(int *)(&DAT_00695eb8 + arg_1 * 4) + 3;
        }
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_00417bb9
 * Entry Point: 00417bb9
 * Size: 221 bytes
 */


int32_t FUN_00417bb9(int arg1,int arg2)

{
  int val_1;
  
  if (((&g_CardSlot_ColorMask)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
     (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 4) == 0)) {
    val_1 = FUN_00410cc0(DAT_00538740,DAT_0053873c,g_PlayerSelectionPriority,arg1,arg2);
    if (val_1 != -1) {
      *(int16_t *)(&g_CardSlot_PowerCounters + DAT_00538740 * 0x5b20 + val_1 * 0x120) = 0;
      *(int16_t *)(&g_CardSlot_ToughnessCounters + DAT_00538740 * 0x5b20 + val_1 * 0x120) = 3;
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_00417c96
 * Entry Point: 00417c96
 * Size: 674 bytes
 */


int32_t FUN_00417c96(int player_id,int card_slot,int event_type)

{
  uint8_t flag_1;
  int32_t uval_2;
  uint32_t uval_3;
  int val_4;
  uint32_t uval_5;
  uint32_t uval_6;
  int32_t arg_11;
  int val_7;
  uint32_t uval_8;
  int32_t arg_13;
  uint32_t uVar9;
  int32_t arg_14;
  uint32_t uVar10;
  int32_t arg_15;
  uint32_t uVar11;
  int32_t arg_16;
  uint32_t uVar12;
  int32_t arg_17;
  char *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    flag_1 = FUN_0041d9d2(arg_1,arg_2,1);
    val_4 = 1 << (flag_1 & 0x1f);
    arg_11 = 0;
    uval_2 = Glue_Subsystem_004d0a42(arg_1,arg_2);
    uval_2 = FUN_00403250((int *)0x0,0,arg_1,2,2,0x200,2,0x40,0,uval_2,arg_11,val_4,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      arg_20 = &match_count;
      uval_2 = 1;
      arg_18 = s_Target_Creature_00519974;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      val_4 = -1;
      flag_1 = FUN_0041d9d2(arg_1,arg_2,1);
      uval_5 = 1 << (flag_1 & 0x1f);
      uval_6 = 0;
      uval_3 = Glue_Subsystem_004d0a42(arg_1,arg_2);
      val_4 = Action_ValidateTarget_00405802
                        (arg_1,2,1 - arg_1,0x200,2,0x40,0,uval_3,uval_6,uval_5,val_4,val_7,uval_8,uVar9,
                         uVar10,uVar11,uVar12,arg_18,uval_2,arg_20);
      if (val_4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = match_count;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = slot_idx;
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      }
    }
    if (arg_3 == 0x71) {
      match_count = *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20);
      slot_idx = *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20);
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      val_4 = -1;
      flag_1 = FUN_0041d9d2(arg_1,arg_2,1);
      uval_5 = 1 << (flag_1 & 0x1f);
      uval_6 = 0;
      uval_3 = Glue_Subsystem_004d0a42(arg_1,arg_2);
      val_4 = Rules_ParseFilter_0040360b
                        (match_count,slot_idx,(char *)0x0,arg_1,2,2,0x200,2,0x40,0,uval_3,uval_6,uval_5,
                         val_4,val_7,uval_8,uVar9,uVar10,uVar11,uVar12);
      if (val_4 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Pic_Subsystem_0044867e(match_count,slot_idx,1);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_004186ac
 * Entry Point: 004186ac
 * Size: 126 bytes
 */


bool FUN_004186ac(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  
  if (arg_3 == 0x74) {
    if (arg_1 == g_CurrentTurnPhase) {
      flag_1 = true;
    }
    else {
      flag_1 = arg_1 != g_DefendingPlayer;
    }
  }
  else {
    if (arg_3 == 0x71) {
      Glue_Subsystem_004e65e1(FUN_0041872f,-1);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    flag_1 = false;
  }
  return flag_1;
}

/*
 * Decompiled function: FUN_0041872f
 * Entry Point: 0041872f
 * Size: 86 bytes
 */


int32_t FUN_0041872f(int arg1,int arg2)

{
  if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
    FUN_0041db67(arg1,arg2,1,g_OverworldPlayerCoordX,g_OverworldMapGrid);
  }
  return 0;
}

/*
 * Decompiled function: FUN_00418c59
 * Entry Point: 00418c59
 * Size: 209 bytes
 */


void FUN_00418c59(int x,int y,int width,uint8_t arg_4)

{
  int slot_idx;
  
  for (slot_idx = 1; slot_idx < 6; slot_idx = slot_idx + 1) {
    if ((char)(&DAT_006a602f)[y * 0x120 + x * 0x5b20 + slot_idx] == width) {
      (&DAT_006a602f)[y * 0x120 + x * 0x5b20 + slot_idx] = arg_4;
    }
  }
  if ((&DAT_006a602f)[width + x * 0x5b20 + y * 0x120] == '\0') {
    (&DAT_006a602f)[width + x * 0x5b20 + y * 0x120] = arg_4;
  }
  return;
}

/*
 * Decompiled function: FUN_004194cf
 * Entry Point: 004194cf
 * Size: 213 bytes
 */


void FUN_004194cf(int x,int y,int width,uint8_t arg_4)

{
  int slot_idx;
  
  for (slot_idx = 1; slot_idx < 6; slot_idx = slot_idx + 1) {
    if ((char)(&DAT_006a6029)[slot_idx + y * 0x120 + x * 0x5b20] == width) {
      (&DAT_006a6029)[slot_idx + y * 0x120 + x * 0x5b20] = arg_4;
    }
  }
  if ((&DAT_006a6029)[width + y * 0x120 + x * 0x5b20] == '\0') {
    (&DAT_006a6029)[width + y * 0x120 + x * 0x5b20] = arg_4;
  }
  return;
}

/*
 * Decompiled function: FUN_0041a245
 * Entry Point: 0041a245
 * Size: 636 bytes
 */


uint32_t FUN_0041a245(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    if (((&g_MasterCardColorTable)[DAT_0068a708 * 0x34] & 0x40) == 0) {
      uval_1 = 0;
    }
    else {
      Ai_GetOpponentPlayerScore(0);
      if (arg_1 == g_CurrentTurnPhase) {
        uval_1 = g_PlayerHandCardCount & 0x20;
      }
      else if (((g_PlayerHandCardCount & 0x20) == 0) || (g_DefendingPlayer != g_CurrentTurnPhase)) {
        uval_1 = 0;
      }
      else {
        uval_1 = 1;
      }
    }
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
      if (slot_idx == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) = slot_idx;
        (&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] = g_TemporaryToughnessBuffer;
      }
    }
    if (arg_3 == 0x71) {
      if (((*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) != -1) &&
          (((&g_CardSlot_Flags)
            [*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
             (char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20] & 0x20) != 0))
         && (((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId +
                       *(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120
                       + (char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) *
               0x34] & 0x40) != 0)) {
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120],
                   *(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120),2);
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0041a4c6
 * Entry Point: 0041a4c6
 * Size: 695 bytes
 */


int32_t FUN_0041a4c6(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (g_SelectedTargetPlayer == -1) {
      uval_2 = 0;
    }
    else {
      val_1 = Rules_ParseFilter_0040360b
                        (g_SelectedTargetPlayer,g_SelectedTargetSlot,(char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,2,0,0);
      if (val_1 == 0) {
        uval_2 = 0;
      }
      else {
        uval_2 = 99;
      }
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if ((arg_1 == g_CurrentTurnPhase) || (g_SelectedTargetPlayer != -1)) {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = g_SelectedTargetPlayer;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = g_SelectedTargetSlot;
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      }
      else {
        g_ActivePlayer = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + -0x24;
    }
    if ((arg_3 == 0x38) && (1 < *(int *)(&DAT_0063edd8 + arg_1 * 0x20))) {
      g_SpellStackDepth = g_SpellStackDepth + 0x18;
    }
    if (arg_3 == 0x71) {
      val_1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),
                         (char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else if (((&g_CardSlot_Flags)
                [*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 0x20
               ) != 0) {
        Pic_Subsystem_0044867e
                  (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),1);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0041a782
 * Entry Point: 0041a782
 * Size: 1594 bytes
 */


int32_t FUN_0041a782(int player_id,int card_slot,int event_type)

{
  int arg_2_00;
  int val_1;
  int32_t uval_2;
  int val_3;
  int target_idx;
  int player_idx;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (g_SelectedTargetPlayer == -1) {
      uval_2 = 0;
    }
    else if ((g_ActivePlayerPriority == arg_1) && (val_1 = FUN_0040d949(arg_1,7,2), val_1 == 0)) {
      uval_2 = 0;
    }
    else {
      val_1 = Rules_ParseFilter_0040360b
                        (g_SelectedTargetPlayer,g_SelectedTargetSlot,(char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,2,0,0);
      if (val_1 == 0) {
        uval_2 = 0;
      }
      else {
        uval_2 = 99;
      }
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if (g_SelectedTargetPlayer == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = g_SelectedTargetPlayer;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = g_SelectedTargetSlot;
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        *(int32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             g_TurnCounter;
      }
    }
    if (arg_3 == 0x71) {
      val_1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),
                         (char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (val_1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        val_1 = *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20);
        arg_2_00 = *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20);
        if (val_1 == g_CurrentTurnPhase) {
          Magic_CombatPhase(arg_1,arg_2,0x7e,0,0);
          slot_idx = Ai_CalcManaRequirement_004ba890
                              (val_1,0,*(int *)(&g_CardSlot_ConvertedManaCost +
                                               arg_2 * 0x120 + arg_1 * 0x5b20));
          Magic_DiscardToHandSize();
          g_ActivePlayer = 0;
        }
        else {
          val_3 = FUN_0040d949(val_1,7,1);
          if (val_3 == 0) {
            slot_idx = 0;
          }
          else {
            slot_idx = Ai_CalcManaRequirement_004ba890
                                (val_1,0,*(int *)(&g_CardSlot_ConvertedManaCost +
                                                 arg_2 * 0x120 + arg_1 * 0x5b20));
          }
        }
        if (slot_idx < *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          player_idx = 0;
          while ((player_idx < 7 &&
                 (slot_idx < *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)
                 ))) {
            for (; (0 < *(int *)(&g_AiLookaheadDepth + player_idx * 4 + val_1 * 0x20) &&
                   (slot_idx < *(int *)(&g_CardSlot_ConvertedManaCost +
                                      arg_2 * 0x120 + arg_1 * 0x5b20))); slot_idx = slot_idx + 1) {
              *(int *)(&g_AiLookaheadDepth + player_idx * 4 + val_1 * 0x20) =
                   *(int *)(&g_AiLookaheadDepth + player_idx * 4 + val_1 * 0x20) + -1;
              *(int *)(&DAT_0063eeac + val_1 * 0x20) = *(int *)(&DAT_0063eeac + val_1 * 0x20) + -1;
            }
            player_idx = player_idx + 1;
          }
          target_idx = 0;
          while ((target_idx < (int)(&g_PlayerActiveCardCount)[val_1] &&
                 (slot_idx < *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)
                 ))) {
            val_3 = FUN_00471c32(val_1,target_idx);
            if (((val_3 != 0) &&
                ((((&g_MasterCardColorTable)
                   [*(int *)(&g_CardSlot_CardId + target_idx * 0x120 + val_1 * 0x5b20) * 0x34] & 1) !=
                  0 && (((&g_CardSlot_Flags)[target_idx * 0x120 + val_1 * 0x5b20] & 0x10) == 0)))) &&
               ((((&g_CardSlot_Subtypes)[target_idx * 0x120 + val_1 * 0x5b20] & 3) == 0 ||
                (((&g_MasterCardColorTable)
                  [*(int *)(&g_CardSlot_CardId + target_idx * 0x120 + val_1 * 0x5b20) * 0x34] & 2) ==
                 0)))) {
              Ai_Subsystem_004bd23f(val_1,target_idx);
              player_idx = 0;
              while ((player_idx < 7 &&
                     (slot_idx < *(int *)(&g_CardSlot_ConvertedManaCost +
                                        arg_2 * 0x120 + arg_1 * 0x5b20)))) {
                for (; (0 < *(int *)(&g_AiLookaheadDepth + player_idx * 4 + val_1 * 0x20) &&
                       (slot_idx < *(int *)(&g_CardSlot_ConvertedManaCost +
                                          arg_2 * 0x120 + arg_1 * 0x5b20))); slot_idx = slot_idx + 1)
                {
                  *(int *)(&g_AiLookaheadDepth + player_idx * 4 + val_1 * 0x20) =
                       *(int *)(&g_AiLookaheadDepth + player_idx * 4 + val_1 * 0x20) + -1;
                  *(int *)(&DAT_0063eeac + val_1 * 0x20) =
                       *(int *)(&DAT_0063eeac + val_1 * 0x20) + -1;
                }
                player_idx = player_idx + 1;
              }
            }
            target_idx = target_idx + 1;
          }
        }
        if (slot_idx < *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          Pic_Subsystem_0044867e(val_1,arg_2_00,1);
        }
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0041adc1
 * Entry Point: 0041adc1
 * Size: 995 bytes
 */


int32_t FUN_0041adc1(int player_id,int card_slot,int event_type)

{
  char cVar1;
  int val_2;
  int32_t uval_3;
  int match_count;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (g_SelectedTargetPlayer == -1) {
      uval_3 = 0;
    }
    else if ((g_ActivePlayerPriority == arg_1) && (val_2 = FUN_0040d949(arg_1,7,2), val_2 == 0)) {
      uval_3 = 0;
    }
    else {
      match_count = (int)(char)(&g_MasterCardManaCostTable)
                           [*(int *)(&g_CardSlot_CardId +
                                    g_SelectedTargetSlot * 0x120 + g_SelectedTargetPlayer * 0x5b20) * 0x34];
      if (match_count == -1) {
        match_count = g_TurnCounter;
      }
      cVar1 = (&g_MasterCardSubTypeTable2)
              [*(int *)(&g_CardSlot_CardId + g_SelectedTargetSlot * 0x120 + g_SelectedTargetPlayer * 0x5b20) * 0x34];
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = cVar1 + match_count;
      val_2 = FUN_0040d949(arg_1,2,1);
      if (((val_2 == 0) || (val_2 = FUN_0040d949(arg_1,7,cVar1 + match_count + 1), val_2 == 0)) ||
         (val_2 = Rules_ParseFilter_0040360b
                            (g_SelectedTargetPlayer,g_SelectedTargetSlot,(char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,
                             0xffffffff,0xffffffff,2,0,0), val_2 == 0)) {
        uval_3 = 0;
      }
      else {
        DAT_006fe3f4 = 1;
        uval_3 = 99;
      }
    }
  }
  else {
    if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1))
       && (g_SelectedTargetPlayer != -1)) {
      DAT_006b2d48 = 1;
      Ai_CalcManaRequirement_004ba890
                (arg_1,0,*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20));
      if (g_ActivePlayer != 1) {
        *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) = g_SelectedTargetPlayer;
        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) = g_SelectedTargetSlot;
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        g_TurnCounter = *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
    }
    if (arg_3 == 0x71) {
      val_2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),
                         (char *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (val_2 == 0) {
        g_ActivePlayer = 1;
      }
      else if (((&g_CardSlot_Flags)
                [*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 0x20
               ) != 0) {
        Pic_Subsystem_0044867e
                  (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_3 = 0;
  }
  return uval_3;
}

/*
 * Decompiled function: FUN_0041b695
 * Entry Point: 0041b695
 * Size: 519 bytes
 */


uint32_t FUN_0041b695(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  int card_idx;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    uval_1 = (&g_PlayerPoisonCounters)[arg_1] & 2;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if (card_idx == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = card_idx;
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = g_TemporaryToughnessBuffer;
      }
    }
    if (arg_3 == 0x71) {
      if (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1) {
        FUN_0040d875(arg_1,1,(int)(char)(&g_MasterCardSubTypeTable2)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 *(int *)(&g_CardSlot_OriginalCardId +
                                                         arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                                 (char)(&g_CardSlot_Toughness)
                                                       [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) *
                                         0x34] +
                             (int)(char)(&g_MasterCardManaCostTable)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 *(int *)(&g_CardSlot_OriginalCardId +
                                                         arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                                 (char)(&g_CardSlot_Toughness)
                                                       [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) *
                                         0x34]);
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0041b89c
 * Entry Point: 0041b89c
 * Size: 158 bytes
 */


int32_t FUN_0041b89c(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if ((int)(&g_ActivePlayerSpellPriority)[arg_1] < 8) {
        g_SpellStackDepth = g_SpellStackDepth + -0x3c;
      }
      else {
        g_SpellStackDepth = g_SpellStackDepth + -0x18;
      }
    }
    if (arg_3 == 0x71) {
      FUN_0040d875(arg_1,1,3);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041b93a
 * Entry Point: 0041b93a
 * Size: 42 bytes
 */


void Mem_AllocOrFree_0041b93a(int player_id,int card_slot,int event_type)

{
  Prompts_Load_0041b98a(arg_1,arg_2,arg_3,g_TurnCounter);
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041b964
 * Entry Point: 0041b964
 * Size: 38 bytes
 */


void Mem_AllocOrFree_0041b964(int player_id,int card_slot,int event_type)

{
  Prompts_Load_0041b98a(arg_1,arg_2,arg_3,3);
  return;
}

/*
 * Decompiled function: FUN_0041cb9a
 * Entry Point: 0041cb9a
 * Size: 1029 bytes
 */


uint32_t FUN_0041cb9a(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    uval_1 = g_PlayerHandCardCount & 4;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (arg_1 == g_OverworldPlayerCoordX)) {
      if (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) ==
          g_PendingSpellTargetSlot) {
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&g_CardSlot_Toughness)
             [*(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20];
        *(int32_t *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int32_t *)
              (&g_CardSlot_OriginalCardId +
              *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
              *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20);
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = g_TurnCounter;
      }
      else {
        g_ActivePlayer = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + -0x30;
    }
    if (((arg_3 == 0x6e) &&
        (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId +
                 g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
         *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) &&
        ((&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
         (&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]))))
    {
      val_2 = FUN_0040a305(*(int *)(&g_CardSlot_ConvertedManaCost +
                                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120),0,
                           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20))
      ;
      *(int *)(&g_CardSlot_ConvertedManaCost +
              g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
           *(int *)(&g_CardSlot_ConvertedManaCost +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) - val_2;
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) - val_2;
    }
    if (arg_3 == 0x73) {
      if (((g_PlayerHandCardCount & 4) == 0) || (val_2 = FUN_0040d949(arg_1,7,1), val_2 == 0)) {
        uval_1 = 0;
      }
      else {
        uval_1 = 1;
      }
    }
    else {
      if ((arg_3 == 0x6d) && (Ai_CalcManaRequirement_004ba890(arg_1,0,-1), g_ActivePlayer != 1)) {
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) +
             g_TurnCounter;
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        Pic_Subsystem_0044867e(arg_1,arg_2,1);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0041cf9f
 * Entry Point: 0041cf9f
 * Size: 117 bytes
 */


int32_t FUN_0041cf9f(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 0x74) {
    if (arg_1 == g_CurrentTurnPhase) {
      uval_1 = 1;
    }
    else {
      uval_1 = *(int32_t *)(&DAT_006b3028 + arg_1 * 4);
    }
  }
  else {
    if (arg_3 == 0x71) {
      (&g_PlayerCreatureCount)[arg_1] =
           (&g_PlayerCreatureCount)[arg_1] + *(int *)(&DAT_006b3028 + arg_1 * 4) * 2;
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0041d019
 * Entry Point: 0041d019
 * Size: 402 bytes
 */


int32_t FUN_0041d019(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 0x74) {
    uval_1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      *(int32_t *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 6;
    }
    if (arg_3 == 0x71) {
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        Mem_AllocOrFree_0041df33
                  (slot_idx,*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20),
                   arg_1,arg_2);
        for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1)
        {
          val_2 = FUN_00471c32(slot_idx,match_count);
          if ((val_2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 2) != 0)
             ) {
            FUN_0041db67(slot_idx,match_count,
                         *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20),
                         arg_1,arg_2);
          }
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0041d411
 * Entry Point: 0041d411
 * Size: 1173 bytes
 */


int32_t FUN_0041d411(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int val_3;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int32_t arg_14;
  int32_t arg_15;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  int local_508;
  int32_t local_504 [320];
  
  if (arg_3 == 0x74) {
    if ((g_ActivePlayerPriority == arg_1) && (val_1 = FUN_0040d949(arg_1,7,3), val_1 == 0)) {
      uval_2 = 0;
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
      uval_2 = Glue_Subsystem_004d0a42(arg_1,arg_2);
      uval_2 = FUN_00403250((int *)0x0,0,arg_1,2,2,0x200,2,0,0,uval_2,arg_11_00,arg_12_00,arg_13_00,
                           arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
    }
  }
  else {
    if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1))
       && (val_1 = Palette_Subsystem_004a7bcd(arg_1,arg_2,(int)local_504), val_1 != 0)) {
      for (local_508 = 0; local_508 < g_TurnCounter; local_508 = local_508 + 1) {
        val_3 = Util_GetRandomNumber(val_1);
        *(int32_t *)
         (&g_CardSlot_CombatTarget +
         arg_2 * 0x120 +
         arg_1 * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) =
             local_504[val_3 * 2];
        *(int32_t *)
         (&g_CardSlot_AttachedAura +
         arg_2 * 0x120 +
         arg_1 * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) =
             local_504[val_3 * 2 + 1];
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x01';
      }
    }
    if (arg_3 == 0x71) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x2c);
        Sleep(0xdac);
      }
      while ((&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0') {
        (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] + -1;
        arg_20 = 0;
        arg_19 = 0;
        arg_18 = 0;
        arg_17 = 0xffffffff;
        arg_16 = 0xffffffff;
        val_3 = -1;
        val_1 = -1;
        arg_13 = 0;
        arg_12 = 0;
        arg_11 = Glue_Subsystem_004d0a42(arg_1,arg_2);
        val_1 = Rules_ParseFilter_0040360b
                          (*(int *)(&g_CardSlot_CombatTarget +
                                   arg_2 * 0x120 +
                                   arg_1 * 0x5b20 +
                                   (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                                   8),
                           *(int *)(&g_CardSlot_AttachedAura +
                                   arg_2 * 0x120 +
                                   arg_1 * 0x5b20 +
                                   (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                                   8),(char *)0x0,arg_1,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_1,
                           val_3,arg_16,arg_17,arg_18,arg_19,arg_20);
        if (val_1 != 0) {
          *(short *)(&g_CardSlot_ToughnessCounters +
                    *(int *)(&g_CardSlot_AttachedAura +
                            arg_2 * 0x120 +
                            arg_1 * 0x5b20 +
                            (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) *
                    0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                    arg_2 * 0x120 +
                                    arg_1 * 0x5b20 +
                                    (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                                    8) * 0x5b20) =
               *(short *)(&g_CardSlot_ToughnessCounters +
                         *(int *)(&g_CardSlot_AttachedAura +
                                 arg_2 * 0x120 +
                                 arg_1 * 0x5b20 +
                                 (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8)
                         * 0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                           arg_2 * 0x120 +
                                           arg_1 * 0x5b20 +
                                           (char)(&g_CardSlot_TurnPlayed)
                                                 [arg_2 * 0x120 + arg_1 * 0x5b20] * 8) * 0x5b20) +
               -1;
          *(int *)(&DAT_006a5f7c +
                  *(int *)(&g_CardSlot_AttachedAura +
                          arg_2 * 0x120 +
                          arg_1 * 0x5b20 +
                          (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) *
                  0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                  arg_2 * 0x120 +
                                  arg_1 * 0x5b20 +
                                  (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8
                                  ) * 0x5b20) =
               *(int *)(&DAT_006a5f7c +
                       *(int *)(&g_CardSlot_AttachedAura +
                               arg_2 * 0x120 +
                               arg_1 * 0x5b20 +
                               (char)(&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) *
                       0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                       arg_2 * 0x120 +
                                       arg_1 * 0x5b20 +
                                       (char)(&g_CardSlot_TurnPlayed)
                                             [arg_2 * 0x120 + arg_1 * 0x5b20] * 8) * 0x5b20) +
               0x1000000;
          if (g_IsAiThinking != 1) {
            Magic_UpkeepPhase(0x2b);
          }
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
    }
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0041d8a6
 * Entry Point: 0041d8a6
 * Size: 156 bytes
 */


int FUN_0041d8a6(int player_id)

{
  int slot_idx;
  
  slot_idx = g_MasterCardCount;
  while( true ) {
    if (g_MasterCardCount + 0x10 <= slot_idx) {
      Engine_ReportFatalError(s_AddType_error_00519bfc);
      return -1;
    }
    if (*(int *)(&g_MasterCardTypeTable + slot_idx * 0x34) == -1) break;
    slot_idx = slot_idx + 1;
  }
  memcpy(&g_MasterCardTable + slot_idx * 0x34,&g_MasterCardTable + arg_1 * 0x34,0x34);
  return slot_idx;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041d942
 * Entry Point: 0041d942
 * Size: 33 bytes
 */


void Mem_AllocOrFree_0041d942(int player_id)

{
  *(int32_t *)(&g_MasterCardTypeTable + arg_1 * 0x34) = 0xffffffff;
  return;
}

/*
 * Decompiled function: FUN_0041d963
 * Entry Point: 0041d963
 * Size: 106 bytes
 */


int FUN_0041d963(int player_id,int card_slot,int event_type)

{
  if ((&DAT_006a602f)[arg_3 + arg_1 * 0x5b20 + arg_2 * 0x120] != '\0') {
    arg_3 = (int)(char)(&DAT_006a602f)[arg_3 + arg_1 * 0x5b20 + arg_2 * 0x120];
  }
  return arg_3;
}

/*
 * Decompiled function: FUN_0041d9d2
 * Entry Point: 0041d9d2
 * Size: 106 bytes
 */


int FUN_0041d9d2(int player_id,int card_slot,int event_type)

{
  if ((&DAT_006a6029)[arg_3 + arg_1 * 0x5b20 + arg_2 * 0x120] != '\0') {
    arg_3 = (int)(char)(&DAT_006a6029)[arg_3 + arg_1 * 0x5b20 + arg_2 * 0x120];
  }
  return arg_3;
}

/*
 * Decompiled function: FUN_0041da41
 * Entry Point: 0041da41
 * Size: 294 bytes
 */


void FUN_0041da41(int arg1,int arg2)

{
  int card_slot;
  uint32_t match_count;
  
  DAT_00695f08 = arg1;
  DAT_006b2e14 = arg2;
  FUN_00476205(g_DefendingPlayer,0xd4,s_Card_leaving_play_00519c0c,0);
  *(int32_t *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) = 0xffffffff;
  Pic_Subsystem_00448e29(arg1,arg2);
  if (((&g_CardSlot_Abilities1)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) {
    match_count = (uint32_t)(((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0);
    arg_2 = Deck_AddCardToDeck
                      (match_count,*(int *)(&g_ActiveCardsInPlay + arg2 * 0x120 + arg1 * 0x5b20));
    if (arg_2 != -1) {
      Ai_Subsystem_004cc3f8(match_count,arg_2,8,2);
    }
    (&g_ActivePlayerSpellPriority)[match_count] = (&g_ActivePlayerSpellPriority)[match_count] + 1;
  }
  return;
}

/*
 * Decompiled function: FUN_0041db67
 * Entry Point: 0041db67
 * Size: 972 bytes
 */


int FUN_0041db67(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  int val_1;
  int val_2;
  int card_idx;
  int slot_idx;
  
  if (((arg_1 == -1) || (arg_4 == -1)) || (arg_3 < 1)) {
    val_1 = -1;
  }
  else {
    if (arg_2 == -1) {
      slot_idx = arg_1;
    }
    else {
      slot_idx = arg_4;
    }
    val_1 = Deck_AddCardToDeck(slot_idx,g_PendingSpellTargetSlot);
    if (val_1 != -1) {
      *(uint32_t *)(&g_CardSlot_Flags + val_1 * 0x120 + slot_idx * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + val_1 * 0x120 + slot_idx * 0x5b20) |
           CONCAT31((uint3)((slot_idx == 0) - 1 >> 8) & 0x10,2);
      (&g_CardSlot_Toughness)[val_1 * 0x120 + slot_idx * 0x5b20] = (uint8_t)arg_1;
      *(int *)(&g_CardSlot_OriginalCardId + val_1 * 0x120 + slot_idx * 0x5b20) = arg_2;
      *(int *)(&g_CardSlot_ConvertedManaCost + val_1 * 0x120 + slot_idx * 0x5b20) = arg_3;
      (&g_CardSlot_DamageReceived)[val_1 * 0x120 + slot_idx * 0x5b20] = (uint8_t)arg_4;
      *(int *)(&g_CardSlot_TypeFlags + val_1 * 0x120 + slot_idx * 0x5b20) = arg_5;
      if (arg_5 == -1) {
        *(int32_t *)(&DAT_006a5f74 + val_1 * 0x120 + slot_idx * 0x5b20) = 0xef;
      }
      else {
        if ((*(int *)(&g_CardSlot_CardId + arg_5 * 0x120 + arg_4 * 0x5b20) == -1) ||
           (*(int *)(&g_CardSlot_CardId + arg_5 * 0x120 + arg_4 * 0x5b20) == DAT_006fd3f4)) {
          card_idx = *(int *)(&g_ActiveCardsInPlay + arg_5 * 0x120 + arg_4 * 0x5b20);
        }
        else {
          card_idx = *(int *)(&g_CardSlot_CardId + arg_5 * 0x120 + arg_4 * 0x5b20);
        }
        (&g_CardSlot_MinusOneCounters)[val_1 * 0x120 + slot_idx * 0x5b20] =
             (&g_CardSlot_MinusOneCounters)[arg_5 * 0x120 + arg_4 * 0x5b20];
        if (((&g_MasterCardColorTable)[card_idx * 0x34] & 0x40) != 0) {
          (&g_CardSlot_MinusOneCounters)[val_1 * 0x120 + slot_idx * 0x5b20] =
               (&g_CardSlot_MinusOneCounters)[val_1 * 0x120 + slot_idx * 0x5b20] | 0x40;
        }
        *(uint32_t *)(&g_CardSlot_TargetSlot + val_1 * 0x120 + slot_idx * 0x5b20) =
             (uint32_t)(uint8_t)(&g_MasterCardColorTable)[card_idx * 0x34];
        if ((*(int *)(&g_MasterCardTypeTable + card_idx * 0x34) == DAT_0068a694) ||
           (*(int *)(&g_MasterCardTypeTable + card_idx * 0x34) == DAT_006a2848)) {
          *(int32_t *)(&DAT_006a5f74 + val_1 * 0x120 + slot_idx * 0x5b20) =
               *(int32_t *)(&DAT_006a5f74 + arg_5 * 0x120 + arg_4 * 0x5b20);
        }
        else {
          val_2 = FUN_00478aa4(*(int *)(&g_MasterCardTypeTable + card_idx * 0x34),arg_4,arg_5);
          *(uint32_t *)(&DAT_006a5f74 + val_1 * 0x120 + slot_idx * 0x5b20) =
               val_2 << 0x10 | *(uint32_t *)(&g_MasterCardTypeTable + card_idx * 0x34);
        }
      }
      g_PlayerHandCardCount = g_PlayerHandCardCount | 2;
    }
  }
  return val_1;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041df33
 * Entry Point: 0041df33
 * Size: 37 bytes
 */


void Mem_AllocOrFree_0041df33(int x,int y,int width,int height)

{
  FUN_0041db67(x,-1,y,width,height);
  return;
}

/*
 * Decompiled function: FUN_0041e370
 * Entry Point: 0041e370
 * Size: 278 bytes
 */


int32_t FUN_0041e370(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    Sprite_DrawScaled((int *)PTR_DAT_00519c20,*(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                      *(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),*(int *)(arg1 + 0x44 + arg2 * 4));
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0041e486
 * Entry Point: 0041e486
 * Size: 508 bytes
 */


int32_t FUN_0041e486(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  int val_4;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    if (arg2 == 2) {
      val_3 = Ai_Util_004c3bc4(4);
      val_4 = Ai_Util_004c3bc4(8);
      FUN_0050dce0((int *)PTR_DAT_005174e4,*(uint32_t *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                   *(uint32_t *)(arg1 + 0x18),*(DWORD *)(arg1 + 0x1c),(int *)g_DisplaySurfaceBackBuffer,
                   *(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14));
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,*(int *)(arg1 + 0x10) + val_3,
                        *(int *)(arg1 + 0x14) + val_3,*(int *)(arg1 + 0x18) - val_4,
                        *(int *)(arg1 + 0x1c) - val_4,*(int *)(arg1 + 0x4c));
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,*(uint32_t *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                   *(uint32_t *)(arg1 + 0x18),*(DWORD *)(arg1 + 0x1c),(int *)g_DisplaySurfaceScreen,
                   *(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14));
      if (*(int *)(arg1 + 0x28) != 0) {
        (**(code **)(arg1 + 0x28))(arg1);
      }
    }
    else {
      Sprite_DrawScaled((int *)PTR_DAT_00519c20,*(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                        *(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),*(int *)(arg1 + 0x44 + arg2 * 4)
                       );
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0041e682
 * Entry Point: 0041e682
 * Size: 566 bytes
 */


int32_t FUN_0041e682(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  DWORD arg_5;
  uint32_t arg_4;
  int val_3;
  int val_4;
  int val_5;
  uint32_t arg_2;
  int slot_idx;
  
  if (arg2 == 0) {
    slot_idx = DAT_00676d78;
  }
  else {
    slot_idx = DAT_00676d7c;
  }
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x10) + *(int *)(arg1 + 0x18) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    arg_5 = Ai_Util_004c3bc4(0x30);
    arg_4 = Ai_Util_004c3bc4((*(short *)(slot_idx + 4) * 0x30) / (int)*(short *)(slot_idx + 6));
    val_3 = Ai_Util_004c3bc4(0x20);
    arg_2 = val_3 - (int)arg_4 / 2;
    val_3 = Ai_Util_004c3bc4(0x106);
    val_3 = val_3 - (int)arg_5 / 2;
    if (arg2 == 2) {
      val_4 = Ai_Util_004c3bc4(4);
      val_5 = Ai_Util_004c3bc4(8);
      FUN_0050dce0((int *)PTR_DAT_005174e4,arg_2,val_3,arg_4,arg_5,(int *)g_DisplaySurfaceBackBuffer
                   ,arg_2,val_3);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_2 + val_4,val_3 + val_4,arg_4 - val_5,
                        arg_5 - val_5,slot_idx);
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2,val_3,arg_4,arg_5,
                   (int *)g_DisplaySurfaceScreen,arg_2,val_3);
      if (*(int *)(arg1 + 0x28) != 0) {
        (**(code **)(arg1 + 0x28))(arg1);
      }
    }
    else {
      Sprite_DrawScaled((int *)PTR_DAT_00519c20,arg_2,val_3,arg_4,arg_5,slot_idx);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0041e8b8
 * Entry Point: 0041e8b8
 * Size: 981 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t FUN_0041e8b8(int arg1,int arg2)

{
  bool flag_1;
  int val_2;
  int32_t uval_3;
  int val_4;
  uint32_t arg_4;
  DWORD arg_5;
  int *arg_6;
  uint32_t arg_7;
  int arg_8;
  int local_58 [6];
  int local_40;
  int local_3c [6];
  int local_24;
  uint32_t loop_idx;
  DWORD color_idx;
  uint32_t target_idx;
  int player_idx;
  int card_idx;
  int32_t match_count;
  int slot_idx;
  
  slot_idx = *(int *)(arg1 + 0x2c) * 2 + -0x60;
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_3 = 0;
  }
  else {
    if (((g_OverworldMovementFlags & 1 << ((uint8_t)slot_idx & 0x1f)) != 0) &&
       (match_count = Glue_Subsystem_004f0de8(slot_idx), *(int *)(&DAT_0067bdbc + (slot_idx / 2) * 4) != 0
       )) {
      if (arg2 == 2) {
        player_idx = *(int *)(&DAT_00519dc4 + (*(int *)(arg1 + 0x2c) + -0x31) * 0x54);
        loop_idx = Ai_Util_004c3bc4(*(int *)(&DAT_00519f20 + slot_idx * 0x10));
        local_24 = Ai_Util_004c3bc4(*(int *)(&DAT_00519f24 + slot_idx * 0x10));
        target_idx = Ai_Util_004c3bc4(*(int *)(&DAT_00519f28 + slot_idx * 0x10));
        color_idx = Ai_Util_004c3bc4(*(int *)(&DAT_00519f2c + slot_idx * 0x10));
        card_idx = Ai_Util_004c3bc4(4);
        val_2 = local_24;
        arg_4 = target_idx;
        arg_5 = color_idx;
        arg_6 = (int *)g_DisplaySurfaceBackBuffer;
        arg_7 = loop_idx;
        arg_8 = local_24;
        val_4 = Ai_Util_004c3bc4(0x148);
        FUN_0050dce0((int *)PTR_DAT_005174bc,loop_idx,val_2 - val_4,arg_4,arg_5,arg_6,arg_7,arg_8);
        Ai_Subsystem_004be3c4
                  (g_DisplaySurfaceBackBuffer,*(int *)(&DAT_00519f20 + slot_idx * 0x10),
                   *(int *)(&DAT_00519f24 + slot_idx * 0x10),
                   *(int32_t *)(&DAT_00678330 + slot_idx * 4),
                   *(int *)(&DAT_00519f28 + slot_idx * 0x10),*(int *)(&DAT_00519f2c + slot_idx * 0x10)
                  );
        Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,loop_idx + card_idx,local_24 + card_idx,
                          target_idx + card_idx * -2,color_idx + card_idx * -2,player_idx);
        val_2 = g_AiBackupBoardRegister;
        local_3c[5] = g_AiBackupBoardRegister;
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
        local_58[5] = slot_idx / 2 + -1;
        *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
        local_40 = 400 - (int)*(short *)(val_2 + 6) / 2;
        Ai_Subsystem_004be3c4
                  (g_DisplaySurfaceBackBuffer,local_3c[local_58[5]] + -0x1e,local_40,
                   (&g_AiBackupBoardRegister)[local_58[local_58[5]]],(int)*(short *)(val_2 + 4),
                   (int)*(short *)(val_2 + 6));
        FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,loop_idx,local_24,target_idx,color_idx,
                     (int *)g_DisplaySurfaceScreen,loop_idx,local_24);
        if (*(int *)(arg1 + 0x28) != 0) {
          (**(code **)(arg1 + 0x28))(arg1);
        }
      }
      else {
        Ai_Subsystem_004be3c4
                  (g_DisplaySurfaceScreen,*(int *)(&DAT_00519f20 + slot_idx * 0x10),
                   *(int *)(&DAT_00519f24 + slot_idx * 0x10),
                   *(int32_t *)
                    (&DAT_00519dbc + (*(int *)(arg1 + 0x2c) + -0x31) * 0x54 + arg2 * 4),
                   *(int *)(&DAT_00519f28 + slot_idx * 0x10),*(int *)(&DAT_00519f2c + slot_idx * 0x10)
                  );
      }
    }
    uval_3 = 1;
  }
  return uval_3;
}

/*
 * Decompiled function: FUN_0041ec8d
 * Entry Point: 0041ec8d
 * Size: 87 bytes
 */


int32_t FUN_0041ec8d(int player_id)

{
  FUN_0040a3e1();
  if (DAT_00640f08 == 0) {
    DAT_00640f08 = *(int *)(arg_1 + 0x2c);
  }
  g_MouseCursorButtonState = 0;
  Glue_Subsystem_004ebcdc(*(int32_t *)(&DAT_00519f1c + *(int *)(arg_1 + 0x2c) * 4),0xf,100,100,0)
  ;
  return 0;
}

/*
 * Decompiled function: FUN_0041ece4
 * Entry Point: 0041ece4
 * Size: 86 bytes
 */


int32_t FUN_0041ece4(int player_id)

{
  int32_t uval_1;
  
  uval_1 = *(int32_t *)(arg_1 + 0x40);
  g_MouseCaptureFlag = 1;
  *(int32_t *)(arg_1 + 0x40) = 0;
  (**(code **)(arg_1 + 0x24))(arg_1,3);
  g_MouseCaptureFlag = 0;
  *(int32_t *)(arg_1 + 0x40) = 3;
  return uval_1;
}

/*
 * Decompiled function: FUN_0041ed3a
 * Entry Point: 0041ed3a
 * Size: 76 bytes
 */


int32_t FUN_0041ed3a(int player_id)

{
  int32_t uval_1;
  
  uval_1 = *(int32_t *)(arg_1 + 0x40);
  *(int32_t *)(arg_1 + 0x40) = 0;
  g_MouseCaptureFlag = 1;
  (**(code **)(arg_1 + 0x24))(arg_1,0);
  g_MouseCaptureFlag = 0;
  return uval_1;
}

/*
 * Decompiled function: FUN_0041edd4
 * Entry Point: 0041edd4
 * Size: 855 bytes
 */


int32_t FUN_0041edd4(void)

{
  int val_1;
  int32_t *u_ptr_2;
  int32_t *u_ptr_3;
  int card_idx;
  int slot_idx;
  
  u_ptr_2 = (int32_t *)g_DisplaySurfaceScreen;
  u_ptr_3 = &DAT_0067f750;
  for (val_1 = 9; val_1 != 0; val_1 = val_1 + -1) {
    *u_ptr_3 = *u_ptr_2;
    u_ptr_2 = u_ptr_2 + 1;
    u_ptr_3 = u_ptr_3 + 1;
  }
  for (slot_idx = 0; slot_idx < 4; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_00519c6c + slot_idx * 0x54) = *(int32_t *)(&DAT_0067f730 + slot_idx * 4);
    *(int32_t *)(&DAT_00519c70 + slot_idx * 0x54) = *(int32_t *)(&DAT_0067f740 + slot_idx * 4);
    *(int32_t *)(&DAT_00519c74 + slot_idx * 0x54) = *(int32_t *)(&DAT_0067f740 + slot_idx * 4);
    *(int32_t *)(&DAT_00519c78 + slot_idx * 0x54) = *(int32_t *)(&DAT_0067f730 + slot_idx * 4);
  }
  for (slot_idx = 0; slot_idx < 5; slot_idx = slot_idx + 1) {
    val_1 = slot_idx * 2 + 2;
    *(int32_t *)(&DAT_00519dbc + slot_idx * 0x54) = *(int32_t *)(&DAT_006782a0 + val_1 * 4);
    *(int32_t *)(&DAT_00519dc0 + slot_idx * 0x54) = *(int32_t *)(&DAT_006782d0 + val_1 * 4);
    *(int32_t *)(&DAT_00519dc4 + slot_idx * 0x54) = *(int32_t *)(&DAT_006782d0 + val_1 * 4);
    *(int32_t *)(&DAT_00519dc8 + slot_idx * 0x54) = *(int32_t *)(&DAT_00678300 + val_1 * 4);
  }
  if (g_AiManaColorCost_Red != 0x280) {
    for (card_idx = 0; card_idx < 4; card_idx = card_idx + 1) {
      *(int *)(&DAT_00519c38 + card_idx * 0x54) =
           (*(int *)(&DAT_00519c38 + card_idx * 0x54) * g_AiManaColorCost_Red) / 0x280;
      *(int *)(&DAT_00519c3c + card_idx * 0x54) =
           (*(int *)(&DAT_00519c3c + card_idx * 0x54) * g_AiManaColorCost_Red) / 0x280;
      *(int *)(&DAT_00519c40 + card_idx * 0x54) =
           (*(int *)(&DAT_00519c40 + card_idx * 0x54) * g_AiManaColorCost_Red) / 0x280;
      *(int *)(&DAT_00519c44 + card_idx * 0x54) =
           (*(int *)(&DAT_00519c44 + card_idx * 0x54) * g_AiManaColorCost_Red) / 0x280;
    }
    for (card_idx = 0; card_idx < 5; card_idx = card_idx + 1) {
      *(int *)(&DAT_00519d88 + card_idx * 0x54) =
           (*(int *)(&DAT_00519d88 + card_idx * 0x54) * g_AiManaColorCost_Red) / 0x280;
      *(int *)(&DAT_00519d8c + card_idx * 0x54) =
           (*(int *)(&DAT_00519d8c + card_idx * 0x54) * g_AiManaColorCost_Red) / 0x280;
      *(int *)(&DAT_00519d90 + card_idx * 0x54) =
           (*(int *)(&DAT_00519d90 + card_idx * 0x54) * g_AiManaColorCost_Red) / 0x280;
      *(int *)(&DAT_00519d94 + card_idx * 0x54) =
           (*(int *)(&DAT_00519d94 + card_idx * 0x54) * g_AiManaColorCost_Red) / 0x280;
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


int32_t Mem_AllocOrFree_0041f12b(int player_id)

{
  *(int32_t *)(&g_SoundChannelActiveCount + arg_1 * 4) = 0;
  *(int32_t *)(&g_SoundSampleBufferTable + arg_1 * 4) = 1;
  return 0;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041f159
 * Entry Point: 0041f159
 * Size: 37 bytes
 */


int32_t Mem_AllocOrFree_0041f159(int32_t arg_1)

{
  *(int32_t *)(&g_SoundSampleBufferTable + g_CurrentActiveAudioTrack * 4) = arg_1;
  return 1;
}

/*
 * Decompiled function: FUN_0041f17e
 * Entry Point: 0041f17e
 * Size: 149 bytes
 */


int32_t FUN_0041f17e(int player_id,int card_slot,int event_type)

{
  int match_count;
  int slot_idx;
  
  match_count = *(int *)(&g_SoundChannelActiveCount + arg_3 * 4);
  for (slot_idx = 0; slot_idx < arg_2; slot_idx = slot_idx + 1) {
    *(int *)(&g_SoundChannelTable + arg_3 * 200 + match_count * 4) = slot_idx * 0x54 + arg_1;
    match_count = match_count + 1;
  }
  *(int *)(&g_SoundChannelActiveCount + arg_3 * 4) = *(int *)(&g_SoundChannelActiveCount + arg_3 * 4) + arg_2;
  g_MouseCaptureFlag = 0;
  return *(int32_t *)(&g_SoundChannelActiveCount + arg_3 * 4);
}

/*
 * Decompiled function: FUN_0041f213
 * Entry Point: 0041f213
 * Size: 156 bytes
 */


int32_t FUN_0041f213(void)

{
  int slot_idx;
  
  g_MouseCaptureFlag = 1;
  for (slot_idx = 0; slot_idx < *(int *)(&g_SoundChannelActiveCount + g_CurrentActiveAudioTrack * 4); slot_idx = slot_idx + 1) {
    (**(code **)(*(int *)(&g_SoundChannelTable + slot_idx * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
              (*(int32_t *)(&g_SoundChannelTable + slot_idx * 4 + g_CurrentActiveAudioTrack * 200),
               slot_idx == DAT_00519ff8);
  }
  g_MouseCaptureFlag = 0;
  return 1;
}

/*
 * Decompiled function: FUN_0041f2af
 * Entry Point: 0041f2af
 * Size: 165 bytes
 */


int32_t FUN_0041f2af(int arg1,int arg2)

{
  int val_1;
  int match_count;
  
  val_1 = *(int *)(&g_SoundChannelActiveCount + g_CurrentActiveAudioTrack * 4);
  if (arg2 + arg1 <= *(int *)(&g_SoundChannelActiveCount + g_CurrentActiveAudioTrack * 4)) {
    val_1 = arg2 + arg1;
  }
  g_MouseCaptureFlag = 1;
  for (match_count = arg1; match_count < val_1; match_count = match_count + 1) {
    (**(code **)(*(int *)(&g_SoundChannelTable + match_count * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
              (*(int32_t *)(&g_SoundChannelTable + match_count * 4 + g_CurrentActiveAudioTrack * 200),0);
  }
  g_MouseCaptureFlag = 0;
  return 1;
}

/*
 * Decompiled function: FUN_0041f354
 * Entry Point: 0041f354
 * Size: 61 bytes
 */


int FUN_0041f354(void)

{
  g_CurrentActiveAudioTrack = g_CurrentActiveAudioTrack + 1;
  g_SoundMidiSequenceId = 0xffffffff;
  DAT_00519ff8 = 0xffffffff;
  Mem_AllocOrFree_0041f12b(g_CurrentActiveAudioTrack);
  return g_CurrentActiveAudioTrack;
}

/*
 * Decompiled function: FUN_0041f391
 * Entry Point: 0041f391
 * Size: 89 bytes
 */


int FUN_0041f391(void)

{
  Mem_AllocOrFree_0041f12b(g_CurrentActiveAudioTrack);
  if (g_CurrentActiveAudioTrack == 0) {
    g_CurrentActiveAudioTrack = 0;
  }
  else {
    g_CurrentActiveAudioTrack = g_CurrentActiveAudioTrack + -1;
  }
  g_SoundMidiSequenceId = 0xffffffff;
  DAT_00519ff8 = 0xffffffff;
  return g_CurrentActiveAudioTrack;
}

/*
 * Decompiled function: FUN_0041f3ea
 * Entry Point: 0041f3ea
 * Size: 2675 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0041f3ea(int32_t arg_1,int32_t arg_2,int event_type)

{
  uint32_t _Val;
  bool flag_1;
  int val_2;
  uint32_t uval_3;
  char *pcVar4;
  int color_idx;
  int player_idx;
  int match_count;
  
  _DAT_00538748 = 1;
  val_2 = Mem_AllocOrFree_00408089();
  if (val_2 != 0) {
    uval_3 = Mem_AllocOrFree_0040813d();
    if (((uval_3 == 0xf09) || (uval_3 == 0xf0f)) ||
       ((*(int *)(&g_SoundSampleBufferTable + g_CurrentActiveAudioTrack * 4) != 0 && ((uval_3 == 0x4800 || (uval_3 == 0x5000)))
        ))) {
      Util_CopyMemoryBuffer();
      if ((int)uval_3 < 0xf10) {
        if (uval_3 == 0xf0f) {
          color_idx = -1;
        }
        else if (uval_3 == 0xf09) {
          color_idx = 1;
        }
      }
      else if (uval_3 == 0x4800) {
        color_idx = -1;
      }
      else if (uval_3 == 0x5000) {
        color_idx = 1;
      }
      if (g_SoundMidiSequenceId == -1) {
        if (color_idx < 1) {
          g_SoundMidiSequenceId = *(int *)(&g_SoundChannelActiveCount + g_CurrentActiveAudioTrack * 4) + -1;
        }
        else {
          g_SoundMidiSequenceId = 0;
        }
      }
      else {
        g_SoundMidiSequenceId = (*(int *)(&g_SoundChannelActiveCount + g_CurrentActiveAudioTrack * 4) + g_SoundMidiSequenceId + color_idx) %
                       *(int *)(&g_SoundChannelActiveCount + g_CurrentActiveAudioTrack * 4);
      }
      while (*(int *)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x40) == 3)
      {
        g_SoundMidiSequenceId = (*(int *)(&g_SoundChannelActiveCount + g_CurrentActiveAudioTrack * 4) + g_SoundMidiSequenceId + color_idx) %
                       *(int *)(&g_SoundChannelActiveCount + g_CurrentActiveAudioTrack * 4);
      }
      if (DAT_00519ff8 != -1) {
        (**(code **)(*(int *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
                  (*(int32_t *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200),0);
      }
      if (*(int *)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x10) != -1) {
        SetCursorPos(*(int *)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x10
                             ) +
                     *(int *)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x18
                             ) / 2,
                     *(int *)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x14
                             ) +
                     *(int *)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x1c
                             ) / 2);
      }
      (**(code **)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
                (*(int32_t *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200),1);
    }
    _Val = uval_3 & 0xff;
    if ((_Val != 0) || (*(int *)(&g_SoundSampleBufferTable + g_CurrentActiveAudioTrack * 4) == 0)) {
      match_count = 0;
      if (g_SoundMidiSequenceId == -1) {
        player_idx = 0;
      }
      else {
        player_idx = g_SoundMidiSequenceId + 1;
      }
      for (; match_count < *(int *)(&g_SoundChannelActiveCount + g_CurrentActiveAudioTrack * 4); match_count = match_count + 1) {
        val_2 = (player_idx + match_count) % *(int *)(&g_SoundChannelActiveCount + g_CurrentActiveAudioTrack * 4);
        if ((*(int *)(*(int *)(&g_SoundChannelTable + val_2 * 4 + g_CurrentActiveAudioTrack * 200) + 0x40) != 3) &&
           ((*(uint32_t *)(*(int *)(&g_SoundChannelTable + val_2 * 4 + g_CurrentActiveAudioTrack * 200) + 0x3c) == uval_3 ||
            (((_Val != 0 &&
              (*(int *)(*(int *)(&g_SoundChannelTable + val_2 * 4 + g_CurrentActiveAudioTrack * 200) + 0x34) != 0)) &&
             (pcVar4 = strchr(*(char **)(*(int *)(&g_SoundChannelTable + val_2 * 4 + g_CurrentActiveAudioTrack * 200) +
                                        0x34),_Val), pcVar4 != (char *)0x0)))))) {
          g_SoundMidiSequenceId = val_2;
          if (*(int *)(*(int *)(&g_SoundChannelTable + val_2 * 4 + g_CurrentActiveAudioTrack * 200) + 0x10) != -1) {
            SetCursorPos(*(int *)(*(int *)(&g_SoundChannelTable + val_2 * 4 + g_CurrentActiveAudioTrack * 200) + 0x10) +
                         *(int *)(*(int *)(&g_SoundChannelTable + val_2 * 4 + g_CurrentActiveAudioTrack * 200) + 0x18) /
                         2,*(int *)(*(int *)(&g_SoundChannelTable + val_2 * 4 + g_CurrentActiveAudioTrack * 200) + 0x14)
                           + *(int *)(*(int *)(&g_SoundChannelTable + val_2 * 4 + g_CurrentActiveAudioTrack * 200) +
                                     0x1c) / 2);
          }
          if (DAT_00519ff8 != -1) {
            (**(code **)(*(int *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
                      (*(int32_t *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200),0);
          }
          (**(code **)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
                    (*(int32_t *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200),1);
          if ((*(uint32_t *)(*(int *)(&g_SoundChannelTable + val_2 * 4 + g_CurrentActiveAudioTrack * 200) + 0x3c) == uval_3)
             || (((_Val != 0 &&
                  (*(int *)(*(int *)(&g_SoundChannelTable + val_2 * 4 + g_CurrentActiveAudioTrack * 200) + 0x38) != 0))
                 && (pcVar4 = strchr(*(char **)(*(int *)(&g_SoundChannelTable +
                                                        val_2 * 4 + g_CurrentActiveAudioTrack * 200) + 0x38),_Val
                                    ), pcVar4 != (char *)0x0)))) {
            g_MouseCaptureFlag = 1;
            (**(code **)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
                      (*(int32_t *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200),2);
            g_MouseCaptureFlag = 0;
            DAT_00519ff8 = g_SoundMidiSequenceId;
            Util_CopyMemoryBuffer();
            _DAT_00538748 = 0;
            return g_SoundMidiSequenceId;
          }
          Util_CopyMemoryBuffer();
          break;
        }
      }
      if ((_Val == 0xd) && (g_SoundMidiSequenceId != -1)) {
        if (DAT_00519ff8 != -1) {
          (**(code **)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
                    (*(int32_t *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200),0);
        }
        (**(code **)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
                  (*(int32_t *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200),2);
        DAT_00519ff8 = g_SoundMidiSequenceId;
        Util_CopyMemoryBuffer();
        _DAT_00538748 = 0;
        return g_SoundMidiSequenceId;
      }
      DAT_00519ff8 = g_SoundMidiSequenceId;
    }
  }
  Util_CopyMemoryBuffer();
  if (-1 < DAT_00519ff8) {
    if ((g_MouseCursorX <
         *(int *)(*(int *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200) + 0x10)) ||
       (*(int *)(*(int *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200) + 0x18) +
        *(int *)(*(int *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200) + 0x10) <
        g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY <
              *(int *)(*(int *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200) + 0x14)) ||
            (*(int *)(*(int *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200) + 0x14) +
             *(int *)(*(int *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200) + 0x1c) <
             g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      g_MouseCaptureFlag = 1;
      (**(code **)(*(int *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
                (*(int32_t *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200),0);
      DAT_00519ff8 = -1;
      g_SoundMidiSequenceId = -1;
      g_MouseCaptureFlag = 0;
    }
  }
  for (match_count = 0; match_count < *(int *)(&g_SoundChannelActiveCount + g_CurrentActiveAudioTrack * 4); match_count = match_count + 1) {
    if ((match_count != DAT_00519ff8) &&
       (val_2 = (**(code **)(*(int *)(&g_SoundChannelTable + match_count * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
                          (*(int32_t *)(&g_SoundChannelTable + match_count * 4 + g_CurrentActiveAudioTrack * 200),0),
       val_2 != 0)) {
      g_SoundMidiSequenceId = match_count;
    }
  }
  if (DAT_00519ff8 != g_SoundMidiSequenceId) {
    if (-1 < DAT_00519ff8) {
      g_MouseCaptureFlag = 1;
      (**(code **)(*(int *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
                (*(int32_t *)(&g_SoundChannelTable + DAT_00519ff8 * 4 + g_CurrentActiveAudioTrack * 200),0);
      g_MouseCaptureFlag = 0;
    }
    (**(code **)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
              (*(int32_t *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200),1);
  }
  if ((arg_3 == 1) && (-1 < g_SoundMidiSequenceId)) {
    (**(code **)(*(int *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200) + 0x24))
              (*(int32_t *)(&g_SoundChannelTable + g_SoundMidiSequenceId * 4 + g_CurrentActiveAudioTrack * 200),2);
  }
  DAT_00519ff8 = g_SoundMidiSequenceId;
  _DAT_00538748 = 0;
  return g_SoundMidiSequenceId;
}

/*
 * Decompiled function: Mem_AllocOrFree_0041feab
 * Entry Point: 0041feab
 * Size: 28 bytes
 */


int32_t Mem_AllocOrFree_0041feab(void)

{
  DAT_005387b0 = 0xe;
  return 0;
}

/*
 * Decompiled function: FUN_0041fec7
 * Entry Point: 0041fec7
 * Size: 309 bytes
 */


int32_t FUN_0041fec7(int player_id,int card_slot,int event_type,int arg_4,char *str_5,int arg_6)

{
  size_t len_1;
  uint32_t uval_2;
  int32_t uval_3;
  int val_4;
  int match_count;
  int slot_idx;
  
  len_1 = strlen(str_5);
  uval_2 = Mem_AllocOrFree_00501721();
  if ((uval_2 & 7) == 0) {
    uval_3 = 0;
  }
  else {
    for (match_count = 0; match_count < arg_6; match_count = match_count + 1) {
      if (match_count < (int)len_1) {
        val_4 = FUN_0050f390(*(int *)(arg_1 + 0x20),str_5[match_count]);
      }
      else {
        val_4 = FUN_0050f390(*(int *)(arg_1 + 0x20),' ');
      }
      arg_3 = arg_3 + val_4;
    }
    if (match_count < (int)len_1) {
      slot_idx = FUN_0050f390(*(int *)(arg_1 + 0x20),str_5[arg_6]);
    }
    else {
      slot_idx = FUN_0050f390(*(int *)(arg_1 + 0x20),' ');
    }
    val_4 = Mem_AllocOrFree_0050f740(*(int *)(arg_1 + 0x20));
    val_4 = arg_4 + val_4 / 2;
    Surface_DrawLine((int *)arg_1,arg_3,val_4 + -1,slot_idx + arg_3,val_4 + -1,arg_2);
    uval_3 = Surface_DrawLine((int *)arg_1,arg_3,val_4,slot_idx + arg_3,val_4,arg_2);
  }
  return uval_3;
}

/*
 * Decompiled function: FUN_0041fffc
 * Entry Point: 0041fffc
 * Size: 595 bytes
 */


int32_t FUN_0041fffc(int player_id,int *arg_2,int event_type,int arg_4,char *str_5,int arg_6,int arg_7)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  int val_5;
  size_t sVar6;
  int color_idx;
  int target_idx;
  int player_idx;
  int match_count;
  
  val_1 = Ai_Util_004c3bc4(arg_3);
  target_idx = Ai_Util_004c3bc4(arg_4);
  val_5 = *arg_2;
  val_4 = val_5;
  val_2 = Ai_Util_004c3bc4((int)*(short *)(val_5 + 6));
  val_3 = Ai_Util_004c3bc4((int)*(short *)(val_5 + 4));
  Sprite_DrawScaled((int *)arg_1,0,0,val_3,val_2,val_4);
  player_idx = Ai_Util_004c3bc4((int)*(short *)(val_5 + 4));
  val_5 = arg_2[1];
  for (; player_idx < val_1; player_idx = player_idx + val_4) {
    val_4 = val_5;
    val_2 = Ai_Util_004c3bc4((int)*(short *)(val_5 + 6));
    val_3 = Ai_Util_004c3bc4((int)*(short *)(val_5 + 4));
    Sprite_DrawScaled((int *)arg_1,player_idx,0,val_3,val_2,val_4);
    val_4 = Ai_Util_004c3bc4((int)*(short *)(val_5 + 4));
  }
  val_5 = arg_2[2];
  val_2 = Ai_Util_004c3bc4((int)*(short *)(val_5 + 4));
  val_4 = val_5;
  val_3 = Ai_Util_004c3bc4((int)*(short *)(val_5 + 6));
  val_5 = Ai_Util_004c3bc4((int)*(short *)(val_5 + 4));
  Sprite_DrawScaled((int *)arg_1,val_1 - val_2,0,val_5,val_3,val_4);
  *(int *)(arg_1 + 0x20) = arg_6;
  Mem_AllocOrFree_0050f740(arg_6);
  color_idx = FUN_0050f440((int *)arg_1,str_5);
  while (val_1 < color_idx) {
    sVar6 = strlen(str_5);
    str_5[sVar6 - 1] = '\0';
    color_idx = FUN_0050f440((int *)arg_1,str_5);
  }
  player_idx = 10;
  target_idx = target_idx / 2;
  match_count = 0x25;
  if (arg_7 == 1) {
    match_count = 0x67;
  }
  if (arg_7 == 2) {
    match_count = 0x67;
    target_idx = target_idx + 2;
    player_idx = 8;
  }
  if (arg_7 == 3) {
    match_count = 0xf0;
  }
  FUN_0040cfd5(arg_1,match_count,player_idx,target_idx);
  if (DAT_00538834 != 0) {
    FUN_0041fec7(arg_1,match_count,player_idx,target_idx,str_5,DAT_00538830);
  }
  return 0;
}

/*
 * Decompiled function: FUN_0042024f
 * Entry Point: 0042024f
 * Size: 296 bytes
 */


int32_t FUN_0042024f(int arg1,int arg2)

{
  int arg_5;
  int arg_4;
  int *arg_6;
  int arg_7;
  int arg_8;
  int arg_9;
  int arg_10;
  int *slot_idx;
  
  switch(arg2) {
  case 0:
    slot_idx = (int *)&DAT_00538818;
    break;
  case 1:
    slot_idx = (int *)&DAT_00538818;
    break;
  case 2:
    slot_idx = (int *)&DAT_00538824;
    break;
  case 3:
    slot_idx = (int *)&DAT_00538818;
  }
  arg_7 = (&DAT_0051a090)[arg1 * 0x15];
  arg_8 = *(int *)(&DAT_0051a094 + arg1 * 0x54);
  arg_9 = *(int *)(&DAT_0051a098 + arg1 * 0x54);
  arg_10 = *(int *)(&DAT_0051a09c + arg1 * 0x54);
  FUN_0041fffc((int)g_DisplaySurfaceBackBuffer,slot_idx,0x168,0x1b,&DAT_0067f450 + arg1 * 0x40,4,arg2
              );
  arg_6 = (int *)g_DisplaySurfaceScreen;
  arg_5 = Ai_Util_004c3bc4(0x1a);
  arg_4 = Ai_Util_004c3bc4(0x168);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,arg_4,arg_5,arg_6,arg_7,arg_8,arg_9,
                     arg_10);
  return 0;
}

/*
 * Decompiled function: FUN_0042038c
 * Entry Point: 0042038c
 * Size: 1052 bytes
 */


int32_t FUN_0042038c(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5)

{
  int32_t *u_ptr_1;
  short len_2;
  int16_t uval_3;
  int arg_2_00;
  int val_4;
  int val_5;
  int val_6;
  int val_7;
  int local_a8;
  int local_a4;
  int local_a0;
  int32_t uStack_9c;
  short local_98 [2];
  int32_t auStack_94 [3];
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
  short target_idx;
  short local_16;
  int match_count;
  int *slot_idx;
  
  slot_idx = &DAT_005387b8;
  for (local_a4 = 0; local_a4 < 9; local_a4 = local_a4 + 1) {
    u_ptr_1 = (int32_t *)slot_idx[local_a4];
    (&uStack_9c)[local_a4 * 4] = *u_ptr_1;
    *(int32_t *)(local_98 + local_a4 * 8) = u_ptr_1[1];
    auStack_94[local_a4 * 4] = u_ptr_1[2];
    auStack_94[local_a4 * 4 + 1] = u_ptr_1[3];
    len_2 = Ai_Util_004c3bc4((int)local_98[local_a4 * 8]);
    local_98[local_a4 * 8] = len_2;
    uval_3 = Ai_Util_004c3bc4((int)*(short *)((int)auStack_94 + local_a4 * 0x10 + -2));
    *(int16_t *)((int)auStack_94 + local_a4 * 0x10 + -2) = uval_3;
  }
  arg_2_00 = Ai_Util_004c3bc4(arg_2);
  val_4 = Ai_Util_004c3bc4(arg_3);
  val_5 = Ai_Util_004c3bc4(arg_4);
  val_6 = Ai_Util_004c3bc4(arg_5);
  Sprite_DrawScaled(arg_1,(arg_2_00 + val_5 / 2) - (int)local_98[0] / 2,
                    val_4 - ((int)local_98[1] - (int)local_46),(int)local_98[0],(int)local_98[1],
                    *slot_idx);
  local_a0 = (int)local_98[0] / 2 + val_5 / 2 + arg_2_00;
  for (match_count = ((arg_2_00 + val_5 / 2) - (int)local_98[0] / 2) - (int)local_48; arg_2_00 < match_count
      ; match_count = match_count - local_48) {
    Sprite_DrawScaled(arg_1,match_count,val_4,(int)local_48,(int)local_46,slot_idx[5]);
    Sprite_DrawScaled(arg_1,local_a0,val_4,(int)local_48,(int)local_46,slot_idx[5]);
    local_a0 = local_a0 + local_48;
  }
  Sprite_DrawScaled(arg_1,arg_2_00,val_4,(int)local_88,(int)local_86,slot_idx[1]);
  Sprite_DrawScaled(arg_1,(val_5 + arg_2_00) - (int)local_78,val_4,(int)local_78,(int)local_76,
                    slot_idx[2]);
  val_7 = (int)target_idx;
  for (local_a8 = local_86 + val_4; local_a8 < (val_6 + val_4) - (int)local_66;
      local_a8 = local_a8 + local_16) {
    Sprite_DrawScaled(arg_1,arg_2_00,local_a8,(int)target_idx,(int)local_16,slot_idx[8]);
    Sprite_DrawScaled(arg_1,(val_5 + arg_2_00) - val_7,local_a8,(int)local_38,(int)local_36,
                      slot_idx[6]);
  }
  Sprite_DrawScaled(arg_1,arg_2_00,(val_6 + val_4) - (int)local_66,(int)local_68,(int)local_66,
                    slot_idx[3]);
  Sprite_DrawScaled(arg_1,(val_5 + arg_2_00) - (int)local_58,(val_6 + val_4) - (int)local_56,
                    (int)local_58,(int)local_56,slot_idx[4]);
  local_a0 = ((val_5 + arg_2_00) - (int)local_58) - (int)local_28;
  val_4 = val_4 + (val_6 - local_26);
  for (match_count = local_68 + arg_2_00; match_count < arg_2_00 + val_5 / 2; match_count = match_count + local_28)
  {
    Sprite_DrawScaled(arg_1,match_count,val_4,(int)local_28,(int)local_26,slot_idx[7]);
    Sprite_DrawScaled(arg_1,local_a0,val_4,(int)local_28,(int)local_26,slot_idx[7]);
    local_a0 = local_a0 - local_28;
  }
  return 0;
}

/*
 * Decompiled function: FUN_004211bd
 * Entry Point: 004211bd
 * Size: 247 bytes
 */


int32_t FUN_004211bd(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    FUN_0042024f(*(int *)(arg1 + 0x2c) + -4,arg2);
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_004212f0
 * Entry Point: 004212f0
 * Size: 479 bytes
 */


int32_t FUN_004212f0(int arg1,int arg2)

{
  int arg_6;
  int card_slot;
  int event_type;
  uint32_t arg_4;
  DWORD arg_5;
  bool flag_1;
  int32_t uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    arg_6 = *(int *)(&DAT_00538a88 + arg2 * 4 + (*(int *)(arg1 + 0x2c) + -1) * 0x10);
    arg_2 = *(int *)(arg1 + 0x10);
    arg_3 = *(int *)(arg1 + 0x14);
    arg_4 = *(uint32_t *)(arg1 + 0x18);
    arg_5 = *(DWORD *)(arg1 + 0x1c);
    if (arg2 == 2) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceWork,0,arg_3 + 0x80,arg_4,arg_5,
                        *(int *)(&DAT_00538a8c + (*(int *)(arg1 + 0x2c) + -1) * 0x10));
      Sprite_DrawScaled((int *)g_DisplaySurfaceWork,2,arg_3 + 0x82,arg_4 - 4,arg_5 - 4,arg_6);
      FUN_0050dce0((int *)g_DisplaySurfaceWork,0,arg_3 + 0x80,arg_4,arg_5,
                   (int *)g_DisplaySurfaceScreen,arg_2,arg_3);
      if (*(int *)(arg1 + 0x28) != 0) {
        (**(code **)(arg1 + 0x28))(arg1);
      }
    }
    else {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,arg_6);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_004214cf
 * Entry Point: 004214cf
 * Size: 390 bytes
 */


int32_t FUN_004214cf(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    if (arg2 == 2) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg1 + 0x10) + 2,
                        *(int *)(arg1 + 0x14) + 2,*(int *)(arg1 + 0x18) + -4,
                        *(int *)(arg1 + 0x1c) + -4,*(int *)(arg1 + 0x48));
      if (*(int *)(arg1 + 0x28) != 0) {
        (**(code **)(arg1 + 0x28))(arg1);
      }
    }
    else {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                        *(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),*(int *)(arg1 + 0x44 + arg2 * 4)
                       );
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_004216e5
 * Entry Point: 004216e5
 * Size: 261 bytes
 */


int32_t FUN_004216e5(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_004217ea
 * Entry Point: 004217ea
 * Size: 321 bytes
 */


int32_t FUN_004217ea(int player_id)

{
  int val_1;
  int val_2;
  int val_3;
  int arg_6;
  int val_4;
  int val_5;
  
  arg_6 = DAT_00538ac4;
  Pic_Subsystem_0044b84b();
  val_4 = *(int *)(arg_1 + 0x14) + *(int *)(arg_1 + 0x70) / 2;
  if (val_4 <= g_MouseScreenCoordY) {
    val_4 = g_MouseScreenCoordY;
  }
  val_5 = (*(int *)(arg_1 + 0x14) + *(int *)(arg_1 + 0x1c)) - *(int *)(arg_1 + 0x70) / 2;
  if (val_4 <= val_5) {
    val_5 = val_4;
  }
  val_4 = *(int *)(arg_1 + 0x14);
  val_1 = *(int *)(arg_1 + 0x70);
  val_2 = *(int *)(arg_1 + 0x1c);
  val_3 = *(int *)(arg_1 + 0x70);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,*(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
                   *(int *)(arg_1 + 0x18),*(int *)(arg_1 + 0x1c),0);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg_1 + 0x10),
                    val_5 - *(int *)(arg_1 + 0x70) / 2,*(int *)(arg_1 + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(arg_1 + 0x18)) / *(int *)(arg_1 + 8),
                    arg_6);
  FUN_00422b04((((val_5 - val_4) - val_1 / 2) * 0x11) / (val_2 - val_3));
  DAT_00538a28 = *(int32_t *)(arg_1 + 0x2c);
  return *(int32_t *)(arg_1 + 0x2c);
}

/*
 * Decompiled function: FUN_0042192b
 * Entry Point: 0042192b
 * Size: 182 bytes
 */


int32_t FUN_0042192b(int player_id)

{
  int val_1;
  int val_2;
  int arg_6;
  
  arg_6 = DAT_00538ac4;
  val_1 = *(int *)(arg_1 + 0x70);
  val_2 = *(int *)(arg_1 + 0x14);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,*(int *)(arg_1 + 0x10),*(int *)(arg_1 + 0x14),
                   *(int *)(arg_1 + 0x18),*(int *)(arg_1 + 0x1c),0);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg_1 + 0x10),
                    (val_2 + val_1 / 2) - *(int *)(arg_1 + 0x70) / 2,*(int *)(arg_1 + 0x18),
                    ((int)*(short *)(arg_6 + 6) * *(int *)(arg_1 + 0x18)) / *(int *)(arg_1 + 8),
                    arg_6);
  return 0;
}

/*
 * Decompiled function: FUN_004219e1
 * Entry Point: 004219e1
 * Size: 160 bytes
 */


void FUN_004219e1(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,int arg_6)

{
  int arg_4_00;
  int arg_5_00;
  
  arg_4_00 = arg_2 + arg_4;
  arg_5_00 = arg_5 + arg_3;
  Surface_DrawLine(arg_1,arg_2,arg_3,arg_4_00,arg_3,arg_6);
  Surface_DrawLine(arg_1,arg_4_00,arg_3,arg_4_00,arg_5_00,arg_6);
  Surface_DrawLine(arg_1,arg_4_00,arg_5_00,arg_2,arg_5_00,arg_6);
  Surface_DrawLine(arg_1,arg_2,arg_5_00,arg_2,arg_3,arg_6);
  return;
}

/*
 * Decompiled function: FUN_00421a81
 * Entry Point: 00421a81
 * Size: 177 bytes
 */


int32_t FUN_00421a81(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  
  if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
     (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
    flag_1 = false;
  }
  else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
          (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
    flag_1 = false;
  }
  else {
    flag_1 = true;
  }
  if (flag_1) {
    if (arg2 == 2) {
      DAT_00538a28 = *(int32_t *)(arg1 + 0x2c);
    }
    uval_2 = 1;
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_00422b04
 * Entry Point: 00422b04
 * Size: 1026 bytes
 */


void FUN_00422b04(int player_id)

{
  DWORD DVar1;
  uint32_t uval_2;
  int val_3;
  int val_4;
  uint32_t uval_5;
  int *piVar6;
  int val_7;
  int val_8;
  int local_38;
  uint32_t local_34;
  int local_2c [6];
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (arg_1 == 0x12) {
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
  local_34 = arg_1 * 3;
  val_8 = 0x80;
  val_7 = 0;
  piVar6 = (int *)g_DisplaySurfaceWork;
  DVar1 = Ai_Util_004c3bc4(0x7f);
  uval_2 = Ai_Util_004c3bc4(0x173);
  FUN_0050dce0((int *)g_DisplaySurfaceWork,0,0x154,uval_2,DVar1,piVar6,val_7,val_8);
  for (player_idx = 0; player_idx < local_38; player_idx = player_idx + 1) {
    card_idx = 0;
    for (; (card_idx < 3 && ((int)local_34 < 0x37)); local_34 = local_34 + 1) {
      if ((*(int *)(&DAT_00538858 + local_34 * 8) != 0) ||
         ((*(int *)(&DAT_0053885c + local_34 * 8) != 0 || (g_CardSlot_ToughnessBonus != 0)))) {
        match_count = *(int *)(&DAT_00538858 + local_34 * 8);
        local_2c[5] = *(int *)(&DAT_0053885c + local_34 * 8);
        val_7 = match_count + local_2c[5];
        if (val_7 < 2) {
          val_7 = 1;
        }
        val_7 = (match_count * 100) / val_7;
        if (match_count < local_2c[5]) {
          if ((local_2c[5] - match_count < 6) || (0x19 < val_7)) {
            if ((match_count + local_2c[5] < 5) || (0x28 < val_7)) {
              slot_idx = 2;
            }
            else {
              slot_idx = 1;
            }
          }
          else {
            slot_idx = 0;
          }
        }
        else if ((match_count - local_2c[5] < 6) || (val_7 < 0x4b)) {
          if ((match_count + local_2c[5] < 5) || (val_7 < 0x3d)) {
            slot_idx = 2;
          }
          else {
            slot_idx = 3;
          }
        }
        else {
          slot_idx = 4;
        }
        val_8 = Ai_Util_004c3bc4(player_idx << 6);
        val_8 = val_8 + 0x80;
        val_3 = Ai_Util_004c3bc4(0x7c);
        val_3 = val_3 * card_idx;
        val_7 = *(int *)(DAT_0051a4c8 * 8 + 0x51a4d4);
        piVar6 = (int *)g_DisplaySurfaceWork;
        val_4 = Ai_Util_004c3bc4(3);
        DVar1 = (val_7 + -2) - val_4;
        uval_2 = *(int *)(DAT_0051a4c8 * 8 + 0x51a4d0) - 2;
        val_7 = *(int *)(DAT_0051a4c8 * 8 + 0x51a4d4);
        uval_5 = (int)local_34 >> 0x1f;
        val_4 = Ai_Util_004c3bc4(3);
        FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,
                     *(int *)(DAT_0051a4c8 * 8 + 0x51a4d0) *
                     (((local_34 ^ uval_5) - uval_5 & 7 ^ uval_5) - uval_5) + 1,
                     val_7 * ((int)(local_34 + (uval_5 & 7)) >> 3) + val_4 + 1,uval_2,DVar1,piVar6,
                     val_3,val_8);
        *(int32_t *)(g_DisplaySurfaceWork + 0x20) = 4;
        val_7 = Ai_Util_004c3bc4(player_idx * 0x40 + -3);
        val_8 = Ai_Util_004c3bc4(0x20);
        val_3 = val_7 + val_8 + 0x80;
        val_7 = Ai_Util_004c3bc4(0x7c);
        val_7 = val_7 * card_idx;
        val_8 = Ai_Util_004c3bc4(0x5e);
        FUN_0040d269((int)g_DisplaySurfaceWork,local_2c[slot_idx],val_7 + val_8,val_3);
        *(int32_t *)(g_DisplaySurfaceWork + 0x20) = 1;
        val_7 = Ai_Util_004c3bc4(player_idx << 6);
        val_8 = Ai_Util_004c3bc4(0x36);
        val_3 = val_7 + val_8 + 0x80;
        val_7 = Ai_Util_004c3bc4(0x7c);
        val_7 = val_7 * card_idx;
        val_8 = Ai_Util_004c3bc4(0x3e);
        FUN_0040d269((int)g_DisplaySurfaceWork,0xb7,val_7 + val_8,val_3);
      }
      card_idx = card_idx + 1;
    }
  }
  val_7 = Ai_Util_004c3bc4(0x43);
  val_8 = Ai_Util_004c3bc4(0xf6);
  piVar6 = (int *)g_DisplaySurfaceScreen;
  val_3 = Ai_Util_004c3bc4(0x40);
  DVar1 = val_3 * 2 - 2;
  val_3 = Ai_Util_004c3bc4(0x7c);
  FUN_0050dce0((int *)g_DisplaySurfaceWork,0,0x80,val_3 * 3 - 2,DVar1,piVar6,val_8,val_7);
  DAT_00538ac8 = arg_1;
  return;
}

/*
 * Decompiled function: FUN_00422f06
 * Entry Point: 00422f06
 * Size: 380 bytes
 */


void FUN_00422f06(void)

{
  uint32_t uval_1;
  int color_idx;
  
  memset(&DAT_00538850,0,0x1c0);
  DAT_00538a6c = 0;
  DAT_00538a68 = 0;
  DAT_00538a60 = 0;
  DAT_00538a70 = 0;
  DAT_00538ab8 = 0;
  DAT_00538a64 = 0;
  DAT_00538a24 = 0;
  color_idx = 0;
  while( true ) {
    if (9999 < color_idx) {
      return;
    }
    uval_1 = *(uint32_t *)(&DAT_0067a9a4 + color_idx * 0x10);
    if (*(int *)(&DAT_0067a9a0 + color_idx * 0x10) == 0) break;
    switch(*(int32_t *)(&DAT_0067a9a0 + color_idx * 0x10)) {
    case 2:
      if ((uval_1 & 0x80) == 0) {
        DAT_00538a64 = DAT_00538a64 + 1;
        *(int *)(&DAT_00538854 + (uval_1 & 0x7f) * 8) =
             *(int *)(&DAT_00538854 + (uval_1 & 0x7f) * 8) + 1;
      }
      else {
        DAT_00538a24 = DAT_00538a24 + 1;
        *(int *)(&DAT_00538850 + (uval_1 & 0x7f) * 8) =
             *(int *)(&DAT_00538850 + (uval_1 & 0x7f) * 8) + 1;
      }
      break;
    case 4:
      *(int *)(&DAT_00538838 + (uval_1 & 0x7f) * 4) =
           *(int *)(&DAT_00538838 + (uval_1 & 0x7f) * 4) + 1;
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
    color_idx = color_idx + 1;
  }
  return;
}

/*
 * Decompiled function: Pic_Load_worlbak1_004230bd
 * Entry Point: 004230bd
 * Size: 560 bytes
 */


void Pic_Load_worlbak1_004230bd(int player_id)

{
  int arg_5;
  int arg_4;
  int event_type;
  int card_slot;
  int val_1;
  int val_2;
  int arg_1_00;
  int arg_1_01;
  
  Mem_AllocOrFree_00510e20(1,s_worlbak1_pic_0051ae80);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
  Glue_Subsystem_004f0de8(arg_1);
  val_2 = *(int *)(&DAT_006782a0 + arg_1 * 4);
  arg_1_00 = (0x4e - *(short *)(val_2 + 6)) / 2 + 0x4c;
  arg_1_01 = (0x4f - *(short *)(val_2 + 4)) / 2 + 0x14f;
  val_1 = *(int *)(&DAT_006782a0 + arg_1 * 4);
  arg_5 = Ai_Util_004c3bc4((int)*(short *)(val_2 + 6));
  arg_4 = Ai_Util_004c3bc4((int)*(short *)(val_2 + 4));
  arg_3 = Ai_Util_004c3bc4(arg_1_00);
  arg_2 = Ai_Util_004c3bc4(arg_1_01);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,val_1);
  val_1 = (arg_1_00 + *(short *)(val_2 + 6) + 0x10) / 2;
  val_2 = (arg_1_01 + (int)*(short *)(val_2 + 4) / 2) / 2;
  *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
  FUN_0040d4d1((int)g_DisplaySurfaceScreen,0x7b,0x176,0x4b);
  g_OverworldWorldState = 0;
  strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[arg_1]);
  FUN_0040c336(&g_OverworldWorldState,val_2,val_1 + -5,0x40);
  strcpy(&g_OverworldWorldState,&DAT_0051ae9c);
  strcat(&g_OverworldWorldState,(&PTR_s_A_clever_duelist_can_switch_ante_005225a0)[arg_1]);
  strcat(&g_OverworldWorldState,&DAT_0051aea0);
  val_1 = Ai_Util_004c3ba3(val_1 + 3);
  val_2 = Ai_Util_004c3ba3(val_2);
  FUN_0040d201((int)g_DisplaySurfaceScreen,0x7b,val_2,val_1);
  FUN_0040a3e1();
  Ai_Subsystem_004cd1d1();
  return;
}

/*
 * Decompiled function: Pic_AllocateImageBuffer
 * Entry Point: 004232f0
 * Size: 555 bytes
 */


uint8_t * Pic_AllocateImageBuffer(int player_id,int card_slot,int event_type)

{
  int val_1;
  DWORD dwMaximumSizeLow;
  int32_t uval_2;
  HANDLE buf_ptr_3;
  HDC pHVar4;
  HBITMAP pHVar5;
  uint8_t *puVar6;
  uint32_t uval_7;
  
  *(int *)(PTR_DAT_00520cb8 + 0x20) = arg_1;
  *(int *)(PTR_DAT_00520cb8 + 0x24) = arg_2;
  *(int *)(PTR_DAT_00520cb8 + 0x28) = arg_3;
  val_1 = arg_3 * arg_1 + (arg_3 * arg_1 >> 0x1f & 7U);
  uval_7 = val_1 >> 0x1f;
  if (((val_1 >> 3 ^ uval_7) - uval_7 & 3 ^ uval_7) == uval_7) {
    *(int32_t *)(PTR_DAT_00520cb8 + 0x2c) = 0;
  }
  else {
    val_1 = arg_3 * arg_1 + (arg_3 * arg_1 >> 0x1f & 7U);
    uval_7 = val_1 >> 0x1f;
    *(uint32_t *)(PTR_DAT_00520cb8 + 0x2c) = 4 - (((val_1 >> 3 ^ uval_7) - uval_7 & 3 ^ uval_7) - uval_7);
  }
  val_1 = (*(int *)(PTR_DAT_00520cb8 + 0x2c) + arg_1) * arg_3 * arg_2;
  dwMaximumSizeLow = ((int)(val_1 + (val_1 >> 0x1f & 7U)) >> 3) + 0x10;
  *(DWORD *)(PTR_DAT_00520cb8 + 0x1c) = dwMaximumSizeLow;
  uval_2 = FUN_0050ec90(arg_1,arg_2,arg_3);
  *(int32_t *)(PTR_DAT_00520cb8 + 0x10) = uval_2;
  if (*(int *)(PTR_DAT_00520cb8 + 0x10) == 0) {
    puVar6 = (uint8_t *)0x0;
  }
  else {
    buf_ptr_3 = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,
                                dwMaximumSizeLow,(LPCSTR)0x0);
    *(HANDLE *)PTR_DAT_00520cb8 = buf_ptr_3;
    if (*(int *)PTR_DAT_00520cb8 == 0) {
      Mem_AllocOrFree_0050ed10(*(void **)(PTR_DAT_00520cb8 + 0x10));
      puVar6 = (uint8_t *)0x0;
    }
    else {
      pHVar4 = GetDC((HWND)0x0);
      *(HDC *)(PTR_DAT_00520cb8 + 4) = pHVar4;
      FUN_004f3955(*(HDC *)(PTR_DAT_00520cb8 + 4));
      pHVar5 = CreateDIBSection(*(HDC *)(PTR_DAT_00520cb8 + 4),
                                *(BITMAPINFO **)(PTR_DAT_00520cb8 + 0x10),(uint32_t)(arg_3 == 8),
                                (void **)(PTR_DAT_00520cb8 + 0x18),*(HANDLE *)PTR_DAT_00520cb8,0);
      *(HBITMAP *)(PTR_DAT_00520cb8 + 8) = pHVar5;
      ReleaseDC((HWND)0x0,*(HDC *)(PTR_DAT_00520cb8 + 4));
      if (*(int *)(PTR_DAT_00520cb8 + 8) == 0) {
        Mem_AllocOrFree_0050ed10(*(void **)(PTR_DAT_00520cb8 + 0x10));
        CloseHandle(*(HANDLE *)PTR_DAT_00520cb8);
        puVar6 = (uint8_t *)0x0;
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
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  match_count = GetWindowLongA(hwnd,0);
  card_idx = GetWindowLongA(hwnd,4);
  slot_idx = Ai_Subsystem_004b5cbb(match_count,card_idx);
  if (slot_idx == DAT_006ff2dc) {
    Ai_Subsystem_004b6da5(&target_idx,match_count,card_idx);
    _DAT_00538de4 = target_idx;
    _DAT_00538de8 = player_idx;
  }
  else {
    _DAT_00538de4 = match_count;
    _DAT_00538de8 = card_idx;
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


int32_t FUN_0046ab25(HWND hwnd)

{
  LONG arg1;
  LONG arg2;
  uint32_t uval_1;
  uint32_t uval_2;
  HWND pHVar3;
  int32_t local_24;
  int32_t player_idx;
  int32_t card_idx;
  
  arg1 = GetWindowLongA(hwnd,0);
  arg2 = GetWindowLongA(hwnd,4);
  uval_1 = Ai_Subsystem_004b613b(arg1,arg2);
  uval_2 = Ai_Subsystem_004b6356(arg1,arg2);
  local_24 = -1;
  card_idx = 0xffffffff;
  pHVar3 = GetParent(hwnd);
  if (pHVar3 == g_AiLookaheadTreeRoot) {
    local_24 = 0;
    card_idx = 2;
  }
  else if (g_AiDuelTurnState == pHVar3) {
    local_24 = 1;
    card_idx = 2;
  }
  else if (g_TurnPriorityState == pHVar3) {
    local_24 = 0;
    card_idx = 1;
  }
  else if (g_AiSelectedActionCode == pHVar3) {
    local_24 = 1;
    card_idx = 1;
  }
  else if (pHVar3 == DAT_006b2e10) {
    local_24 = 0;
    card_idx = 0x10;
  }
  else if (pHVar3 == DAT_006a4928) {
    local_24 = 1;
    card_idx = 0x10;
  }
  if ((((((DAT_006feec0 == -1) || (DAT_006feec0 == arg1)) &&
        ((DAT_006feec4 == 0xffffffff || ((DAT_006feec4 == 0 || ((uval_1 & DAT_006feec4) != 0)))))) &&
       (((DAT_006feec8 == 0xffffffff || ((DAT_006feec8 == 0 || ((uval_2 & DAT_006feec8) != 0)))) ||
        ((((DAT_006feec8 & 0x100) != 0 && ((uval_1 & 0x40) != 0)) ||
         (((DAT_006feec8 & 0x200) != 0 && ((uval_1 & 1) != 0)))))))) &&
      ((DAT_006feecc == -1 || (DAT_006feecc == local_24)))) &&
     ((DAT_006feed0 == 0xffffffff || ((card_idx & DAT_006feed0) != 0)))) {
    player_idx = 1;
  }
  else {
    player_idx = 0;
  }
  return player_idx;
}

/*
 * Decompiled function: FUN_0046ad4a
 * Entry Point: 0046ad4a
 * Size: 114 bytes
 */


int FUN_0046ad4a(HWND hwnd)

{
  LONG arg1;
  LONG arg2;
  uint32_t uval_1;
  uint32_t uval_2;
  
  arg1 = GetWindowLongA(hwnd,0);
  arg2 = GetWindowLongA(hwnd,4);
  uval_1 = Ai_Subsystem_004b5cbb(arg1,arg2);
  uval_2 = (int)uval_1 >> 0x1f;
  return (arg2 % 3) * 3 + (((uval_1 ^ uval_2) - uval_2 & 3 ^ uval_2) - uval_2) * 2;
}

/*
 * Decompiled function: FUN_0046adbc
 * Entry Point: 0046adbc
 * Size: 654 bytes
 */


bool FUN_0046adbc(int arg1,int arg2)

{
  bool flag_1;
  bool flag_2;
  bool flag_3;
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
  
  flag_1 = *(int *)(arg1 + 4) == *(int *)(arg2 + 4);
  flag_2 = ((*(uint32_t *)(arg1 + 0xc) ^ *(uint32_t *)(arg2 + 0xc) & 0x30000) & 0x30000) == 0;
  flag_3 = ((*(uint32_t *)(arg1 + 0xc) ^ *(uint32_t *)(arg2 + 0xc) & 0x10) & 0x10) == 0;
  bVar4 = ((*(uint32_t *)(arg1 + 0xc) ^ *(uint32_t *)(arg2 + 0xc) & 0x1000) & 0x1000) == 0;
  bVar5 = ((*(uint32_t *)(arg1 + 0xc) ^ *(uint32_t *)(arg2 + 0xc) & 0x200000) & 0x200000) == 0;
  bVar6 = ((*(uint32_t *)(arg1 + 0xc) ^ *(uint32_t *)(arg2 + 0xc) & 0x100000) & 0x100000) == 0;
  bVar7 = *(short *)(arg1 + 0x10) == *(short *)(arg2 + 0x10);
  bVar8 = *(short *)(arg1 + 0x14) == *(short *)(arg2 + 0x14);
  bVar9 = *(short *)(arg1 + 0x16) == *(short *)(arg2 + 0x16);
  bVar10 = *(char *)(arg1 + 0x1c) == *(char *)(arg2 + 0x1c);
  bVar11 = *(char *)(arg1 + 0x1d) == *(char *)(arg2 + 0x1d);
  bVar12 = *(char *)(arg1 + 0x1e) == *(char *)(arg2 + 0x1e);
  bVar13 = *(int *)(arg1 + 0x24) == *(int *)(arg2 + 0x24);
  bVar14 = *(int *)(arg1 + 0x4c) == *(int *)(arg2 + 0x4c);
  bVar15 = ((*(uint32_t *)(arg1 + 0x38) ^ *(uint32_t *)(arg2 + 0x38) & 0x20000) & 0x20000) == 0;
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
       (!bVar8 || (!bVar7 || (!bVar6 || (!bVar5 || (!bVar4 || (!flag_3 || (!flag_2 || !flag_1))))))))))
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
                   (bVar9 && (bVar8 && (bVar7 && (bVar6 && (bVar5 && (bVar4 && (flag_3 && (flag_2 && 
                                                  flag_1))))))))))))))));
}

/*
 * Decompiled function: FUN_0046b04a
 * Entry Point: 0046b04a
 * Size: 924 bytes
 */


uint32_t FUN_0046b04a(int arg1,int arg2)

{
  uint32_t local_10c;
  int local_108;
  char local_104 [256];
  
  local_10c = 0;
  if (*(int *)(arg2 + 4) == *(int *)(arg1 + 4)) {
    if (((*(uint32_t *)(arg2 + 0xc) ^ *(uint32_t *)(arg1 + 0xc) & 0x30000) & 0x30000) != 0) {
      local_10c = 2;
    }
    if (((*(uint32_t *)(arg2 + 0xc) ^ *(uint32_t *)(arg1 + 0xc) & 0x10) & 0x10) != 0) {
      local_10c = local_10c | 8;
    }
    if (((*(uint32_t *)(arg2 + 0xc) ^ *(uint32_t *)(arg1 + 0xc) & 0x1000) & 0x1000) != 0) {
      local_10c = local_10c | 0x10;
    }
    if (((*(uint32_t *)(arg2 + 0xc) ^ *(uint32_t *)(arg1 + 0xc) & 0x200000) & 0x200000) != 0) {
      local_10c = local_10c | 0x20;
    }
    if (((*(uint32_t *)(arg2 + 0xc) ^ *(uint32_t *)(arg1 + 0xc) & 0x100000) & 0x100000) != 0) {
      local_10c = local_10c | 0x40;
    }
    if (*(short *)(arg2 + 0x10) != *(short *)(arg1 + 0x10)) {
      local_10c = local_10c | 0x80;
    }
    if (*(short *)(arg2 + 0x14) != *(short *)(arg1 + 0x14)) {
      local_10c = local_10c | 0x100;
    }
    if (*(short *)(arg2 + 0x16) != *(short *)(arg1 + 0x16)) {
      local_10c = local_10c | 0x200;
    }
    if (*(char *)(arg2 + 0x1c) != *(char *)(arg1 + 0x1c)) {
      local_10c = local_10c | 0x400;
    }
    if (*(char *)(arg2 + 0x1d) != *(char *)(arg1 + 0x1d)) {
      local_10c = local_10c | 0x800;
    }
    if (*(char *)(arg1 + 0x1e) != *(char *)(arg2 + 0x1e)) {
      local_10c = local_10c | 0x1000;
    }
    if (*(int *)(arg2 + 0x24) != *(int *)(arg1 + 0x24)) {
      local_10c = local_10c | 0x4000;
    }
    if (*(int *)(arg2 + 0x4c) != *(int *)(arg1 + 0x4c)) {
      local_10c = local_10c | 0x8000;
    }
    if (((*(uint32_t *)(arg1 + 0x38) ^ *(uint32_t *)(arg2 + 0x38) & 0x20000) & 0x20000) != 0) {
      local_10c = local_10c | 0x10000;
    }
    if (*(int *)(arg2 + 0x44) != *(int *)(arg1 + 0x44)) {
      local_10c = local_10c | 0x20000;
    }
    if (*(int *)(arg2 + 0x108) != *(int *)(arg1 + 0x108)) {
      local_10c = local_10c | 0x40000;
    }
    if (*(char *)(arg2 + 0x20) != *(char *)(arg1 + 0x20)) {
      local_10c = local_10c | 0x80000;
    }
  }
  else {
    local_10c = 1;
  }
  sprintf(local_104,s__s__s_00524dbc,s_Swamp_0051aea9 + *(int *)(arg1 + 4) * 0x34,
          s_Swamp_0051aea9 + *(int *)(arg2 + 4) * 0x34);
  OutputDebugStringA(local_104);
  for (local_108 = 0; local_108 < 0x20; local_108 = local_108 + 1) {
    if ((local_10c & 1 << ((uint8_t)local_108 & 0x1f)) != 0) {
      if (local_108 == 0) {
        sprintf(local_104,s__s__d__d_00524dc8,PTR_s_Type_005247d0,*(int32_t *)(arg1 + 4),
                *(int32_t *)(arg2 + 4));
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


bool FUN_0046b3e6(int arg1,int arg2)

{
  return *(int *)(arg2 + 0x3c) == *(int *)(arg1 + 0x3c);
}

/*
 * Decompiled function: FUN_0046b41c
 * Entry Point: 0046b41c
 * Size: 159 bytes
 */


bool FUN_0046b41c(int arg1,int arg2)

{
  return ((*(uint32_t *)(arg1 + 0xc) ^ *(uint32_t *)(arg2 + 0xc) & 0x10) & 0x10) == 0 &&
         (((*(uint32_t *)(arg1 + 0xc) ^ *(uint32_t *)(arg2 + 0xc) & 0x30000) & 0x30000) == 0 &&
         (*(int *)(arg1 + 0x44) == *(int *)(arg2 + 0x44) && *(int *)(arg1 + 4) == *(int *)(arg2 + 4)
         ));
}

/*
 * Decompiled function: Mem_AllocOrFree_0046b4bb
 * Entry Point: 0046b4bb
 * Size: 32 bytes
 */


void Mem_AllocOrFree_0046b4bb(int arg1,int arg2)

{
  FUN_0046adbc(arg1,arg2);
  return;
}

/*
 * Decompiled function: UI_FormatCardCounterString
 * Entry Point: 0046b4db
 * Size: 940 bytes
 */


void UI_FormatCardCounterString(char *filepath,int card_slot,int32_t arg_3)

{
  if (str_1 != (char *)0x0) {
    if (arg_2 == 0x1d7) {
      sprintf(str_1,s_Doom_counters___d_00524dd8,arg_3);
    }
    else if (arg_2 == 0x244) {
      sprintf(str_1,s_Charge_counters___d_00524dec,arg_3);
    }
    else if (arg_2 == 0x248) {
      sprintf(str_1,s_Charge_counters___d_00524e00,arg_3);
    }
    else if (arg_2 == 0x296) {
      sprintf(str_1,s_Charge_counters___d_00524e14,arg_3);
    }
    else if (arg_2 == 0x2fd) {
      sprintf(str_1,s_Charge_counters___d_00524e28,arg_3);
    }
    else if (arg_2 == 0x354) {
      sprintf(str_1,s_Charge_counters___d_00524e3c,arg_3);
    }
    else if (arg_2 == 0x1e4) {
      sprintf(str_1,s_Clockwork___1__0__counters___d_00524e50,arg_3);
    }
    else if (arg_2 == 0x26) {
      sprintf(str_1,s_Clockwork___1__0__counters___d_00524e70,arg_3);
    }
    else if (arg_2 == 0x34) {
      sprintf(str_1,s_Life_counters___d_00524e90,arg_3);
    }
    else if (arg_2 == 0x7b) {
      sprintf(str_1,s_Life_counters___d_00524ea4,arg_3);
    }
    else if (arg_2 == 0x80) {
      sprintf(str_1,s_Life_counters___d_00524eb8,arg_3);
    }
    else if (arg_2 == 0xf6) {
      sprintf(str_1,s_Life_counters___d_00524ecc,arg_3);
    }
    else if (arg_2 == 0x120) {
      sprintf(str_1,s_Life_counters___d_00524ee0,arg_3);
    }
    else if (arg_2 == 0x5e) {
      sprintf(str_1,s__1__1_counters___d_00524ef4,arg_3);
    }
    else if (arg_2 == 0x353) {
      sprintf(str_1,s__1__1_counters___d_00524f08,arg_3);
    }
    else if (arg_2 == 0x92) {
      sprintf(str_1,s_Vitality_counters___d_00524f1c,arg_3);
    }
    else if (arg_2 == 0x2e0) {
      sprintf(str_1,s_Carrion_counters___d_00524f34,arg_3);
    }
    else if (arg_2 == 0xd7) {
      sprintf(str_1,s_Corpse_counters___d_00524f4c,arg_3);
    }
    else if (arg_2 == 0xdc) {
      sprintf(str_1,s__1__1_counters___d_00524f60,arg_3);
    }
    else if (arg_2 == 0x367) {
      sprintf(str_1,s_Corpse_counters___d_00524f74,arg_3);
    }
    else if (arg_2 == 0x21a) {
      sprintf(str_1,s__1__1_counters___d_00524f88,arg_3);
    }
    else if (arg_2 == 0x216) {
      sprintf(str_1,s_Drone___1__1__counters___d_00524f9c,arg_3);
    }
    else if (arg_2 == 0xf8) {
      sprintf(str_1,s_Turn_counters___d_00524fb8,arg_3);
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


void FUN_0046b887(char *filepath,int card_slot,int event_type)

{
  if ((str_1 != (char *)0x0) && (strcpy(str_1,&DAT_00524fcc), arg_3 != 0)) {
    if (arg_2 == 1) {
      sprintf(str_1,s_Damage___0__1__counters___d_00524fd0,arg_3);
    }
    else if (arg_2 == 2) {
      sprintf(str_1,s_Mutation___1__1__counters___d_00524fec,arg_3);
    }
    else if (arg_2 == 3) {
      sprintf(str_1,s_Shackle___0__2__counters___d_0052500c,arg_3);
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


void FUN_0046ba19(HDC hdc,int y,int32_t arg_3,int32_t arg_4)

{
  size_t len_1;
  char target_idx [12];
  int match_count;
  HFONT slot_idx;
  
  match_count = SaveDC(hdc);
  sprintf(target_idx,s__d__d_0052502c,arg_3,arg_4);
  slot_idx = CreateFontA(0x12,0,0,0,400,0,0,0,0,0,0,0,0x12,s_Times_New_Roman_00525034);
  SelectObject(hdc,slot_idx);
  SetBkMode(hdc,1);
  SetTextAlign(hdc,2);
  SetTextColor(hdc,0xffffff);
  len_1 = strlen(target_idx);
  TextOutA(hdc,*(int *)(y + 8),*(int *)(y + 4) + 1,target_idx,len_1);
  SetTextColor(hdc,0x808080);
  len_1 = strlen(target_idx);
  TextOutA(hdc,*(int *)(y + 8) + -1,*(int *)(y + 4),target_idx,len_1);
  RestoreDC(hdc,match_count);
  DeleteObject(slot_idx);
  return;
}

/*
 * Decompiled function: FUN_0046bb29
 * Entry Point: 0046bb29
 * Size: 125 bytes
 */


int32_t FUN_0046bb29(HWND hwnd,int *arg2)

{
  int32_t uval_1;
  LONG LVar2;
  LONG LVar3;
  
  if ((hwnd == (HWND)0x0) || (arg2 == (int *)0x0)) {
    uval_1 = 0;
  }
  else {
    LVar2 = GetWindowLongA(hwnd,0);
    LVar3 = GetWindowLongA(hwnd,4);
    if ((*arg2 == LVar2) && (arg2[1] == LVar3)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0046bbab
 * Entry Point: 0046bbab
 * Size: 127 bytes
 */


int32_t FUN_0046bbab(HWND hwnd,int arg2)

{
  int32_t uval_1;
  LONG arg1;
  LONG arg2_00;
  int val_2;
  
  if ((hwnd == (HWND)0x0) || (arg2 < 0)) {
    uval_1 = 0;
  }
  else {
    arg1 = GetWindowLongA(hwnd,0);
    arg2_00 = GetWindowLongA(hwnd,4);
    val_2 = Ai_Subsystem_004b5cbb(arg1,arg2_00);
    if (val_2 == arg2) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0046bc2f
 * Entry Point: 0046bc2f
 * Size: 99 bytes
 */


int32_t FUN_0046bc2f(HWND hwnd)

{
  int32_t uval_1;
  LONG arg1;
  LONG arg2;
  
  if (hwnd == (HWND)0x0) {
    uval_1 = 0xffffffff;
  }
  else {
    arg1 = GetWindowLongA(hwnd,0);
    arg2 = GetWindowLongA(hwnd,4);
    uval_1 = Ai_Subsystem_004b5cbb(arg1,arg2);
  }
  return uval_1;
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
 * Decompiled function: Catalog_LoadWaveletArt
 * Entry Point: 0046bcc0
 * Size: 620 bytes
 */


int Catalog_LoadWaveletArt(WPARAM arg_1,int card_slot,int width,int height)

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
  if (arg_1 == 0xffffffff) {
    local_40 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + arg_1 * 0x98) < 2) {
    if (*(int *)(&DAT_00696a20 + arg_1 * 0x10) != 0) {
      if ((*(int *)(&DAT_00696a28 + arg_1 * 0x10) == width) &&
         (*(int *)(&DAT_00696a2c + arg_1 * 0x10) == height)) {
        return 1;
      }
      FUN_0046c1b3(arg_1);
    }
    sprintf(local_150,s__s__04d_WVL_00525044,&g_CardArtDirectory,arg_1);
    local_3c = Glue_Subsystem_004f15c0(0,local_150,0);
    if (local_3c == 0) {
      local_40 = 0;
    }
    else {
      local_44 = GetDC((HWND)0x0);
      FUN_004f3955(local_44);
      FUN_005017f0((int32_t *)&local_30,width,height);
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
      *(HBITMAP *)(&DAT_00696a20 + arg_1 * 0x10) = local_48;
      *(void **)(&DAT_00696a24 + arg_1 * 0x10) = local_38;
      *(int *)(&DAT_00696a28 + arg_1 * 0x10) = width;
      *(int *)(&DAT_00696a2c + arg_1 * 0x10) = height;
      PostMessageA(g_MainAppHwnd,0x433,arg_1,0);
    }
  }
  else {
    local_40 = Catalog_LoadWaveletArtAlt(arg_1,arg_2,width,height);
  }
  return local_40;
}

/*
 * Decompiled function: FUN_0046bf31
 * Entry Point: 0046bf31
 * Size: 130 bytes
 */


int32_t FUN_0046bf31(int arg1,int arg2)

{
  int32_t uval_1;
  int val_2;
  
  if (arg1 == -1) {
    uval_1 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + arg1 * 0x98) < 2) {
    if (*(int *)(&DAT_00696a20 + arg1 * 0x10) == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    val_2 = FUN_0046c4b5(arg1,arg2);
    if (val_2 == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0046bfc2
 * Entry Point: 0046bfc2
 * Size: 221 bytes
 */


int FUN_0046bfc2(HDC hdc,RECT *arg_2,int width,int arg_4)

{
  int val_1;
  HBRUSH hbr;
  int slot_idx;
  
  if ((hdc == (HDC)0x0) || (arg_2 == (RECT *)0x0)) {
    slot_idx = 0;
  }
  else if (width == -1) {
    slot_idx = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + width * 0x98) < 2) {
    val_1 = FUN_0046bf31(width,arg_4);
    if (val_1 == 0) {
      slot_idx = 0;
    }
    else {
      slot_idx = FUN_004f3b5f((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_00696a20 + width * 0x10));
    }
    if (slot_idx == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  else {
    slot_idx = FUN_0046c54b(hdc,arg_2,width,arg_4);
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0046c09f
 * Entry Point: 0046c09f
 * Size: 271 bytes
 */


int32_t FUN_0046c09f(WPARAM arg_1,int card_slot,int width,int height)

{
  HGDIOBJ ho;
  int32_t uval_1;
  int val_2;
  
  if (arg_1 == 0xffffffff) {
    uval_1 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + arg_1 * 0x98) < 2) {
    if (((*(int *)(&DAT_00696a20 + arg_1 * 0x10) == 0) ||
        (*(int *)(&DAT_00696a28 + arg_1 * 0x10) != width)) ||
       (*(int *)(&DAT_00696a2c + arg_1 * 0x10) != height)) {
      ho = *(HGDIOBJ *)(&DAT_00696a20 + arg_1 * 0x10);
      *(int32_t *)(&DAT_00696a20 + arg_1 * 0x10) = 0;
      val_2 = Catalog_LoadWaveletArt(arg_1,arg_2,width,height);
      if (val_2 == 0) {
        *(HGDIOBJ *)(&DAT_00696a20 + arg_1 * 0x10) = ho;
        uval_1 = 0;
      }
      else {
        if (ho != (HGDIOBJ)0x0) {
          DeleteObject(ho);
        }
        uval_1 = 1;
      }
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    uval_1 = FUN_0046c636(arg_1,arg_2,width,height);
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0046c1b3
 * Entry Point: 0046c1b3
 * Size: 80 bytes
 */


void FUN_0046c1b3(int player_id)

{
  if ((arg_1 != -1) && (*(int *)(&DAT_00696a20 + arg_1 * 0x10) != 0)) {
    DeleteObject(*(HGDIOBJ *)(&DAT_00696a20 + arg_1 * 0x10));
    *(int32_t *)(&DAT_00696a20 + arg_1 * 0x10) = 0;
  }
  return;
}

/*
 * Decompiled function: Catalog_LoadWaveletArtAlt
 * Entry Point: 0046c203
 * Size: 685 bytes
 */


int Catalog_LoadWaveletArtAlt(WPARAM arg_1,int y,int width,int height)

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
  int slot_idx;
  
  local_44 = 1;
  if (arg_1 == 0xffffffff) {
    local_44 = 0;
  }
  else {
    slot_idx = FUN_0046c4b5(arg_1,y);
    if (slot_idx != 0) {
      if ((*(int *)(slot_idx + 8) == width) && (*(int *)(slot_idx + 0xc) == height)) {
        return 1;
      }
      FUN_0046c6e5(arg_1,y);
    }
    if (y == 0) {
      sprintf(local_154,s__s__04d_WVL_00525060,&g_CardArtDirectory,arg_1);
    }
    else {
      sprintf(local_154,s__s__04d_c_WVL_00525050,&g_CardArtDirectory,arg_1,(int)(char)((char)y + '`'));
    }
    local_40 = Glue_Subsystem_004f15c0(0,local_154,0);
    if (local_40 == 0) {
      local_44 = 0;
    }
    else {
      local_48 = GetDC((HWND)0x0);
      FUN_004f3955(local_48);
      FUN_005017f0((int32_t *)&local_34,width,height);
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
      *(WPARAM *)(&DAT_006a3f90 + DAT_006fe404 * 0x18) = arg_1;
      *(int *)(&DAT_006a3f94 + DAT_006fe404 * 0x18) = y;
      DAT_006fe404 = DAT_006fe404 + 1;
      PostMessageA(g_MainAppHwnd,0x433,arg_1,y);
    }
  }
  return local_44;
}

/*
 * Decompiled function: FUN_0046c4b5
 * Entry Point: 0046c4b5
 * Size: 150 bytes
 */


uint8_t * FUN_0046c4b5(int arg1,int arg2)

{
  int match_count;
  uint8_t *slot_idx;
  
  slot_idx = (uint8_t *)0x0;
  if (arg1 == -1) {
    slot_idx = (uint8_t *)0x0;
  }
  else {
    match_count = 0;
    while ((match_count < DAT_006fe404 && (slot_idx == (uint8_t *)0x0))) {
      if ((*(int *)(&DAT_006a3f90 + match_count * 0x18) == arg1) &&
         (*(int *)(&DAT_006a3f94 + match_count * 0x18) == arg2)) {
        slot_idx = &DAT_006a3f80 + match_count * 0x18;
      }
      match_count = match_count + 1;
    }
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0046c54b
 * Entry Point: 0046c54b
 * Size: 235 bytes
 */


int FUN_0046c54b(HDC hdc,RECT *arg_2,int width,int height)

{
  bool flag_1;
  HBRUSH hbr;
  int player_idx;
  int card_idx;
  int match_count;
  
  if (width == -1) {
    player_idx = 0;
  }
  else {
    match_count = 0;
    flag_1 = false;
    while ((match_count < DAT_006fe404 && (!flag_1))) {
      if ((*(int *)(&DAT_006a3f90 + match_count * 0x18) == width) &&
         (*(int *)(&DAT_006a3f94 + match_count * 0x18) == height)) {
        flag_1 = true;
        card_idx = match_count;
      }
      match_count = match_count + 1;
    }
    if (flag_1) {
      player_idx = FUN_004f3b5f((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_006a3f80 + card_idx * 0x18));
    }
    else {
      player_idx = 0;
    }
    if (player_idx == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  return player_idx;
}

/*
 * Decompiled function: FUN_0046c636
 * Entry Point: 0046c636
 * Size: 165 bytes
 */


int32_t FUN_0046c636(WPARAM arg_1,int y,int width,int height)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_1 == 0xffffffff) {
    uval_1 = 0;
  }
  else {
    val_2 = FUN_0046c4b5(arg_1,y);
    if (val_2 != 0) {
      if ((*(int *)(val_2 + 8) == width) && (*(int *)(val_2 + 0xc) == height)) {
        return 1;
      }
      FUN_0046c6e5(arg_1,y);
    }
    val_2 = Catalog_LoadWaveletArtAlt(arg_1,y,width,height);
    if (val_2 == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0046c6e5
 * Entry Point: 0046c6e5
 * Size: 372 bytes
 */


void FUN_0046c6e5(int arg1,int arg2)

{
  bool flag_1;
  int card_idx;
  int match_count;
  
  if (arg1 != -1) {
    match_count = 0;
    flag_1 = false;
    while ((match_count < DAT_006fe404 && (!flag_1))) {
      if ((*(int *)(&DAT_006a3f90 + match_count * 0x18) == arg1) &&
         (*(int *)(&DAT_006a3f94 + match_count * 0x18) == arg2)) {
        flag_1 = true;
        if (*(int *)(&DAT_006a3f80 + match_count * 0x18) != 0) {
          DeleteObject(*(HGDIOBJ *)(&DAT_006a3f80 + match_count * 0x18));
        }
        DAT_006fe404 = DAT_006fe404 + -1;
        for (card_idx = match_count; card_idx < DAT_006fe404; card_idx = card_idx + 1) {
          *(int32_t *)(&DAT_006a3f80 + card_idx * 0x18) =
               *(int32_t *)(&DAT_006a3f80 + (card_idx * 3 + 3) * 8);
          *(int32_t *)(&DAT_006a3f84 + card_idx * 0x18) =
               *(int32_t *)(&DAT_006a3f84 + (card_idx * 3 + 3) * 8);
          *(int32_t *)(&DAT_006a3f88 + card_idx * 0x18) =
               *(int32_t *)(&DAT_006a3f88 + (card_idx * 3 + 3) * 8);
          *(int32_t *)(&DAT_006a3f8c + card_idx * 0x18) =
               *(int32_t *)(&DAT_006a3f8c + (card_idx * 3 + 3) * 8);
          *(int32_t *)(&DAT_006a3f90 + card_idx * 0x18) =
               *(int32_t *)(&DAT_006a3f90 + (card_idx * 3 + 3) * 8);
          *(int32_t *)(&DAT_006a3f94 + card_idx * 0x18) =
               *(int32_t *)(&DAT_006a3f94 + (card_idx * 3 + 3) * 8);
        }
      }
      match_count = match_count + 1;
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
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < DAT_006fe404; slot_idx = slot_idx + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_006a3f80 + slot_idx * 0x18));
  }
  DAT_006fe404 = 0;
  return;
}

/*
 * Decompiled function: Sprite_Load_BK_AMG_0046d333
 * Entry Point: 0046d333
 * Size: 4866 bytes
 */


void Sprite_Load_BK_AMG_0046d333(int32_t arg_1,int card_slot,int event_type)

{
  int val_1;
  bool flag_2;
  char *char_ptr_3;
  
  flag_2 = true;
  if (*(int *)(&g_OverworldFoodAmount + arg_2 * 0xb4) == 0) {
    switch(arg_1) {
    case 1:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BK_FWZ_spr_00525294);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SFWZ_spr_005252a0);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 2:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BK_KHT_spr_005252ac);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SB_KHT_spr_005252b8);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 3:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BK_MWZ_spr_005252c4);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SMWZ_spr_005252d0);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 4:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BK_LRD_spr_005252dc);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SB_LRD_spr_005252e8);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 5:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BK_WG_spr_005252f4);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SBK_WG_spr_00525300);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 6:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BK_AMG_spr_0052530c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SB_AMG_spr_00525318);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    default:
      flag_2 = false;
      break;
    case 8:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_W_MWZ_spr_00525324);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SW_MWZ_spr_00525330);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 9:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_W_FWZ_spr_0052533c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SFWZ_spr_00525348);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 10:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_W_KHT_spr_00525354);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SKHT_spr_00525360);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0xb:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_W_LRD_spr_0052536c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SW_LRD_spr_00525378);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0xc:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_W_WG_spr_00525384);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SW_WG_spr_00525390);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0xd:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_W_AMG_spr_0052539c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SW_AMG_spr_005253a8);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0xf:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BU_FWZ_spr_005253b4);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SFWZ_spr_005253c0);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x10:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BU_LRD_spr_005253cc);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SU_LRD_spr_005253d8);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x11:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BU_MWZ_spr_005253e4);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SMWZ_spr_005253f0);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x12:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BU_WRM_spr_005253fc);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SWRM_spr_00525408);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x13:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_B_SFR_spr_00525414);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SB_SFT_spr_00525420);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x14:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BU_AMG_spr_0052542c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SU_AMG_spr_00525438);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x16:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_G_MWZ_spr_00525444);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SMWZ_spr_00525450);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x17:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_G_KHT_spr_0052545c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SKHT_spr_00525468);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x18:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_G_FWZ_spr_00525474);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SFWZ_spr_00525480);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x19:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_G_WRM_spr_0052548c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SWRM_spr_00525498);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x1a:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_G_LRD_spr_005254a4);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SG_LRD_spr_005254b0);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x1b:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_G_AMG_spr_005254bc);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SG_AMG_spr_005254c8);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x1d:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_R_FWZ_spr_005254d4);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SR_FWZ_spr_005254e0);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x1e:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_R_MWZ_spr_005254ec);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SMWZ_spr_005254f8);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x1f:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_TROLL_spr_00525504);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_STRL_spr_00525510);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x20:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_R_LRD_spr_0052551c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SR_LRD_spr_00525528);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x21:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_R_WRM_spr_00525534);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SR_WRM_spr_00525540);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x22:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_R_AMG_spr_0052554c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SR_AMG_spr_00525558);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x23:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_R_AMG_spr_00525564);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SR_AMG_spr_00525570);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x24:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_M_TSK_spr_0052557c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SM_TSK_spr_00525588);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x25:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_M_TRL_spr_00525594);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SM_TRL_spr_005255a0);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x26:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_M_APE_spr_005255ac);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SM_APE_spr_005255b8);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x27:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_M_CEN2_spr_005255c4);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SM_CEN_spr_005255d0);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x28:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_M_WG_spr_005255dc);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SM_WG_spr_005255e8);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x29:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_M_FNG_spr_005255f4);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SM_FNG_spr_00525600);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x2a:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_M_CEN_spr_0052560c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SM_CEN2_spr_00525618);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x2b:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_M_LRD_spr_00525624);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SM_LRD_spr_00525630);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x2c:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_M_KHT_spr_0052563c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SKHT_spr_00525648);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x2d:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_M_FWZ_spr_00525654);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SFWZ_spr_00525660);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x2e:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BK_DJN_spr_0052566c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SDJN_spr_00525678);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x2f:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_G_DJN_spr_00525684);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SDJN_spr_00525690);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x30:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_R_DJN_spr_0052569c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SDJN_spr_005256a8);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x31:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_BU_DJN_spr_005256b4);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_SDJN_spr_005256c0);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x32:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_DG_BRU_spr_005256cc);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_S_DG_spr_005256d8);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x33:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_DG_UWB_spr_005256e4);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_S_DG_spr_005256f0);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x34:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_DG_GWR_spr_005256fc);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_S_DG_spr_00525708);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x35:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_DG_RBG_spr_00525714);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_S_DG_spr_00525720);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
      break;
    case 0x36:
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_DG_WUG_spr_0052572c);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4),char_ptr_3);
      char_ptr_3 = (char *)Sprite_SelectResolutionFolder(s_S_DG_spr_00525738);
      Sprite_LoadAll((int32_t *)(&g_OverworldFoodAmount + arg_3 * 0xb4),char_ptr_3);
    }
    if (flag_2) {
      val_1 = *(int *)(&g_OverworldFoodAmount + arg_2 * 0xb4);
      *(int *)(&DAT_006783f0 + arg_2 * 4) = (int)*(short *)(val_1 + 4);
      *(int *)(&DAT_00678470 + arg_2 * 4) = (int)*(short *)(val_1 + 6);
      *(int *)(&DAT_00677990 + arg_2 * 4) = (int)*(short *)(val_1 + 10);
      if (*(int *)(&DAT_00678470 + arg_2 * 4) < *(int *)(&DAT_00677990 + arg_2 * 4)) {
        *(int *)(&DAT_00677990 + arg_2 * 4) = (*(int *)(&DAT_00678470 + arg_2 * 4) * 2) / 3;
      }
      *(int32_t *)(&DAT_006783f0 + arg_3 * 4) = *(int32_t *)(&DAT_006783f0 + arg_2 * 4);
      *(int32_t *)(&DAT_00678470 + arg_3 * 4) = *(int32_t *)(&DAT_00678470 + arg_2 * 4);
      *(int32_t *)(&DAT_00677990 + arg_3 * 4) = *(int32_t *)(&DAT_00677990 + arg_2 * 4);
    }
    else {
      *(int32_t *)(&g_OverworldFoodAmount + arg_2 * 0xb4) = 0;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0046e70d
 * Entry Point: 0046e70d
 * Size: 109 bytes
 */


void FUN_0046e70d(int arg1,int arg2)

{
  if (*(int *)(&g_OverworldFoodAmount + arg1 * 0xb4) != 0) {
    Mem_AllocOrFree_0050fc50(*(void **)(&g_OverworldFoodAmount + arg1 * 0xb4));
    Mem_AllocOrFree_0050fc50(*(void **)(&g_OverworldFoodAmount + arg2 * 0xb4));
    *(int32_t *)(&g_OverworldFoodAmount + arg1 * 0xb4) = 0;
  }
  return;
}

/*
 * Decompiled function: FUN_0046e77a
 * Entry Point: 0046e77a
 * Size: 424 bytes
 */


void FUN_0046e77a(char *arg1,int arg2)

{
  int val_1;
  int val_2;
  int32_t uval_3;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  Mem_AllocOrFree_00510e20(1,arg1);
  val_1 = Surface_GetPixel(1,1,0xc);
  match_count = 4;
  for (card_idx = 2; card_idx < g_AiManaColorCost_Red; card_idx = card_idx + 1) {
    val_2 = Surface_GetPixel(1,card_idx,0xd);
    if (val_2 == val_1) {
      match_count = card_idx;
      break;
    }
  }
  slot_idx = 0x10;
  *(int32_t *)(&DAT_00677990 + arg2 * 4) = 0;
  player_idx = 0xd;
  do {
    if (g_AiManaColorCost_Green <= player_idx) {
LAB_0046e877:
      for (card_idx = 0; card_idx < 5; card_idx = card_idx + 1) {
        for (player_idx = 0; player_idx < 8; player_idx = player_idx + 1) {
          uval_3 = Sprite_EncodeFromSurface
                            (1,(match_count + -1) * card_idx + 2,(slot_idx + -0xc) * player_idx + 0xd,
                             match_count - 2U,slot_idx + -0xd);
          *(int32_t *)(&g_OverworldFoodAmount + arg2 * 0xb4 + player_idx * 0x14 + card_idx * 4) =
               uval_3;
        }
      }
      *(uint32_t *)(&DAT_006783f0 + arg2 * 4) = match_count - 2U;
      *(int *)(&DAT_00678470 + arg2 * 4) = slot_idx + -0xd;
      return;
    }
    val_2 = Surface_GetPixel(1,1,player_idx);
    if (val_2 != val_1) {
      *(int *)(&DAT_00677990 + arg2 * 4) = player_idx + -0xd;
    }
    val_2 = Surface_GetPixel(1,2,player_idx);
    if (val_2 == val_1) {
      slot_idx = player_idx;
      goto LAB_0046e877;
    }
    player_idx = player_idx + 1;
  } while( true );
}

/*
 * Decompiled function: FUN_0046e922
 * Entry Point: 0046e922
 * Size: 62 bytes
 */


int FUN_0046e922(uint32_t arg_1)

{
  char cVar1;
  uint8_t slot_idx;
  
  do {
    cVar1 = Util_GetRandomNumber(5);
    slot_idx = cVar1 + 1;
  } while ((arg_1 & 1 << (slot_idx & 0x1f)) != 0);
  return 1 << (slot_idx & 0x1f);
}

/*
 * Decompiled function: FUN_0046e960
 * Entry Point: 0046e960
 * Size: 941 bytes
 */


/* WARNING: Removing unreachable block (ram,0x0046ea84) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046e960(void)

{
  uint32_t uval_1;
  DWORD _Seed;
  uint32_t arg_1;
  int val_2;
  int val_3;
  int val_4;
  int val_5;
  int val_6;
  int card_idx;
  
  if (g_IsAiThinking == 0) {
    for (card_idx = 0; card_idx < 500; card_idx = card_idx + 1) {
      *(int32_t *)(&deck + card_idx * 4) = 0xffffffff;
    }
    if (DAT_0067f388 == 0) {
      for (card_idx = 0; card_idx < 7; card_idx = card_idx + 1) {
        *(int32_t *)(&DAT_006a48f0 + card_idx * 4) = 0;
        *(int32_t *)(&DAT_006a4908 + card_idx * 4) = 0xffffffff;
      }
      g_OverworldMovementFlags = g_OverworldMovementFlags | 1 << ((char)g_OverworldPlayerDirection * '\x02' & 0x1fU);
      *(int32_t *)(&DAT_005224e8 + g_OverworldPlayerDirection * 0x20) = 0;
      uval_1 = 1 << ((uint8_t)g_OverworldPlayerDirection & 0x1f);
      _Seed = GetTickCount();
      srand(_Seed);
      switch(g_CampaignDifficultyLevel) {
      case 0:
        FUN_0046ed22(uval_1,0xd,0xc,10,1,1);
        break;
      case 1:
        FUN_0046ed22(uval_1,0xb,4,0xc,1,1);
        val_6 = 1;
        val_5 = 0;
        val_4 = 4;
        val_3 = 3;
        val_2 = 4;
        uval_1 = FUN_0046e922(uval_1);
        FUN_0046ed22(uval_1,val_2,val_3,val_4,val_5,val_6);
        break;
      case 2:
        FUN_0046ed22(uval_1,9,3,9,1,1);
        arg_1 = FUN_0046e922(uval_1);
        FUN_0046ed22(arg_1,5,3,4,0,1);
        val_6 = 1;
        val_5 = 0;
        val_4 = 3;
        val_3 = 3;
        val_2 = 4;
        uval_1 = FUN_0046e922(uval_1 | arg_1);
        FUN_0046ed22(uval_1,val_2,val_3,val_4,val_5,val_6);
        break;
      case 3:
        FUN_0046ed22(uval_1,6,3,5,1,1);
        FUN_0046ed22(1,0xb,5,0xe,0,1);
      }
      DAT_0067bde0 = 0;
      for (card_idx = 0; card_idx < 5; card_idx = card_idx + 1) {
        (&DAT_0067bdc0)[card_idx] = 0;
      }
      *(int *)(&DAT_0067bdbc + g_OverworldPlayerDirection * 4) = *(int *)(&DAT_0067bdbc + g_OverworldPlayerDirection * 4) + 1;
      for (card_idx = 0; card_idx < 3 - g_CampaignDifficultyLevel; card_idx = card_idx + 1) {
        val_2 = Util_GetRandomNumber(5);
        (&DAT_0067bdc0)[val_2] = (&DAT_0067bdc0)[val_2] + 1;
      }
      for (card_idx = 0; card_idx < 0x80; card_idx = card_idx + 1) {
        *(int32_t *)(&g_CardSlot_CreatureType + card_idx * 100) = 0xffffffff;
      }
      for (card_idx = 0; card_idx < 8; card_idx = card_idx + 1) {
        *(int32_t *)(&g_TownBuildingCoordinates + card_idx * 0x14) = 0xffffffff;
      }
      for (card_idx = 0; card_idx < 1000; card_idx = card_idx + 1) {
        DAT_0067b9b0 = 0;
      }
      for (card_idx = 0; card_idx < 4; card_idx = card_idx + 1) {
        *(int32_t *)(&g_PlayerLifeTotals + card_idx * 4) = 8;
      }
      for (card_idx = 0; card_idx < 0x50; card_idx = card_idx + 1) {
        *(uint32_t *)(&deck + card_idx * 4) = *(uint32_t *)(&deck + card_idx * 4) | 0x10000;
      }
      g_OverworldPlayerDirection = -1;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0046ed22
 * Entry Point: 0046ed22
 * Size: 1104 bytes
 */


int32_t FUN_0046ed22(uint32_t arg_1,int card_slot,int event_type,int arg_4,int arg_5,int arg_6)

{
  bool flag_1;
  int val_2;
  uint32_t loop_idx;
  uint32_t color_idx;
  uint32_t target_idx;
  uint32_t player_idx;
  uint32_t card_idx;
  int match_count;
  
  for (card_idx = 0; (int)card_idx < arg_2; card_idx = card_idx + 1) {
    player_idx = Pic_Subsystem_00451d90(1,arg_1);
    val_2 = Pic_Subsystem_004521a6((int)(char)(&g_MasterCardColorTable)[player_idx * 0x34],arg_1,0);
    if (((val_2 == 0) || (4 < (int)player_idx)) || (((&DAT_0051aed6)[player_idx * 0x34] & 0xc1) == 0)) {
      card_idx = card_idx + -1;
    }
    else {
      Pic_Subsystem_00451e40(player_idx);
    }
  }
  for (card_idx = 0; (int)card_idx < arg_3; card_idx = card_idx + 1) {
    if (arg_6 == 0) {
      target_idx = 0;
    }
    else {
      target_idx = rand();
      target_idx = target_idx & 1;
    }
    if (target_idx == 0) {
      color_idx = arg_1;
    }
    else {
      color_idx = 1;
    }
    player_idx = Pic_Subsystem_00451d90((-(uint32_t)(target_idx == 0) & 0xffffffc4) + 0x40,color_idx);
    if (((g_CampaignDifficultyLevel == 0) && (((&DAT_0051aecc)[player_idx * 0x34] & 3) != 0)) ||
       (((&g_MasterCardFlagsTable)[player_idx * 0x34] & 9) != 0)) {
      card_idx = card_idx - 1;
    }
    else {
      if (((&g_MasterCardColorTable)[player_idx * 0x34] & 4) != 0) {
        target_idx = 0;
      }
      if (target_idx == 0) {
        loop_idx = arg_1;
      }
      else {
        loop_idx = 1;
      }
      val_2 = Pic_Subsystem_004521a6((int)(char)(&g_MasterCardColorTable)[player_idx * 0x34],loop_idx,0);
      if (((val_2 == 0) ||
          (val_2 = File_Load_Info(player_idx), (int)(((card_idx & 1) == 0) + 1) < val_2)) ||
         (((&DAT_0051aed6)[player_idx * 0x34] & 0xc1) == 0)) {
        card_idx = card_idx - 1;
      }
      else {
        Pic_Subsystem_00451e40(player_idx);
      }
    }
  }
  match_count = 0;
  for (card_idx = 0; (int)card_idx < arg_4; card_idx = card_idx + 1) {
    player_idx = Pic_Subsystem_00451d90(2,arg_1);
    if (((g_CampaignDifficultyLevel < 4) && (((&DAT_0051aecc)[player_idx * 0x34] & 3) != 0)) ||
       (((&g_MasterCardFlagsTable)[player_idx * 0x34] & 9) != 0)) {
      card_idx = card_idx - 1;
      match_count = match_count + -1;
    }
    else {
      if (match_count < 1000) {
        val_2 = Glue_Subsystem_004f0b50(player_idx);
        flag_1 = 0 < val_2;
      }
      else {
        flag_1 = true;
      }
      val_2 = Pic_Subsystem_004521a6((int)(char)(&g_MasterCardColorTable)[player_idx * 0x34],arg_1,0);
      if (((val_2 == 0) ||
          (val_2 = File_Load_Info(player_idx), (int)(((card_idx & 1) == 0) + 1) < val_2)) ||
         ((!flag_1 || (((&DAT_0051aed6)[player_idx * 0x34] & 0xc1) == 0)))) {
        card_idx = card_idx - 1;
      }
      else {
        Pic_Subsystem_00451e40(player_idx);
      }
    }
    match_count = match_count + 1;
  }
  if (arg_5 != 0) {
    do {
      do {
        player_idx = Pic_Subsystem_00451d90(0xe,1);
        val_2 = Pic_Subsystem_004521a6((int)(char)(&g_MasterCardColorTable)[player_idx * 0x34],arg_1,1);
      } while (val_2 == 0);
      val_2 = File_Load_Info(player_idx);
    } while ((((val_2 < 3) || (val_2 = Glue_Subsystem_004f0b50(player_idx), val_2 < 1)) ||
             ((g_CampaignDifficultyLevel == 0 && (((&DAT_0051aecc)[player_idx * 0x34] & 3) != 0)))) ||
            ((((&g_MasterCardFlagsTable)[player_idx * 0x34] & 9) != 0 ||
             (((&DAT_0051aed6)[player_idx * 0x34] & 0xc1) == 0))));
  }
  Pic_Subsystem_00451e40(player_idx);
  return 0;
}

/*
 * Decompiled function: Sprite_SelectResolutionFolder
 * Entry Point: 0046f172
 * Size: 167 bytes
 */


uint8_t * Sprite_SelectResolutionFolder(char *filepath)

{
  if (g_AiManaColorCost_Red == 0x280) {
    strcpy(&g_OverworldWorldState,&DAT_00525744);
  }
  else if (g_AiManaColorCost_Red == 800) {
    strcpy(&g_OverworldWorldState,s_spr800__0052574c);
  }
  else if (g_AiManaColorCost_Red == 0x400) {
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


void FUN_0046f21e(char *arg_1,int32_t arg_2,int32_t arg_3)

{
  int local_330;
  int local_32c;
  int local_328;
  int32_t local_324 [200];
  
  local_330 = 0;
  if (DAT_006781d0 != (void *)0x0) {
    Mem_AllocOrFree_0050fc50(DAT_006781d0);
  }
  Sprite_LoadAll(local_324,arg_1);
  for (local_328 = 0; local_328 < 4; local_328 = local_328 + 1) {
    for (local_32c = 0; local_32c < 9; local_32c = local_32c + 1) {
      (&DAT_006781d0)[local_328 * 9 + local_32c] = (void *)local_324[local_330];
      local_330 = local_330 + 1;
    }
  }
  DAT_00527b34 = arg_2;
  DAT_00527b38 = arg_3;
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
  int match_count;
  int slot_idx;
  
  g_CurrentTurnPhase = 0;
  g_ActivePlayerPriority = 1;
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    (&DAT_00696870)[slot_idx] = 0;
    for (match_count = 0; match_count < 8; match_count = match_count + 1) {
      *(int32_t *)(&g_AiLookaheadDepth + match_count * 4 + slot_idx * 0x20) = 0;
      *(int32_t *)(&g_AiCombatScore_Attacker + match_count * 4 + slot_idx * 0x20) =
           *(int32_t *)(&g_AiLookaheadDepth + match_count * 4 + slot_idx * 0x20);
      *(int32_t *)(&g_AiCombatScore_Total + match_count * 4 + slot_idx * 0x20) =
           *(int32_t *)(&g_AiCombatScore_Attacker + match_count * 4 + slot_idx * 0x20);
      *(int32_t *)(&DAT_00627870 + slot_idx * 0xcc) = 0xffffffff;
      *(int32_t *)(&g_AiTempTargetBuffer + slot_idx * 0x2c) = 0xffffffff;
      *(int32_t *)(&DAT_0063eed0 + slot_idx * 4) = 0;
    }
  }
  DAT_006fecc0 = 0xffffffff;
  for (match_count = 0; match_count < 0x10; match_count = match_count + 1) {
    if ((&g_MasterCardTable)[(g_MasterCardCount + match_count) * 0x34] == -1) {
      *(int32_t *)(&g_MasterCardTypeTable + (g_MasterCardCount + match_count) * 0x34) = 0xffffffff;
    }
  }
  g_PlayerHandCardCount = 0;
  DAT_00680788 = 0xffffffff;
  DAT_00627a88 = 0xffffffff;
  DAT_0063ee88 = 0;
  if (g_CampaignDifficultyLevel == 0) {
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
  g_AiCombatDamageAssigned = 0xffffffff;
  g_PendingAttackersTargetSlot = 0xffffffff;
  g_AiTurnDecisionFlag = 0;
  _DAT_006a4934 = 1;
  g_CardScanDepth = 0;
  DAT_0063ee1c = 0;
  DAT_007006d0 = 0;
  g_ActiveBattlefieldFlag = 0;
  DAT_006ff2d8 = 0xffffffff;
  DAT_007006d4 = 0;
  DAT_00627a10 = 1;
  DAT_006ff684 = 0;
  DAT_006b2d24 = 0;
  DAT_006fd3f0 = 0;
  for (match_count = 0; match_count < 8; match_count = match_count + 1) {
    (&g_AiSelectedTargetCard)[match_count] = 0;
  }
  g_OverworldPlayerCoordY = 0xffffffff;
  g_SelectedTargetPlayer = 0xffffffff;
  g_SelectedTargetSlot = 0xffffffff;
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

int Magic_ExecuteDrawPhase(int player_id)

{
  int val_1;
  int val_2;
  int card_idx;
  int match_count;
  uint8_t slot_idx;
  
  DAT_006fe408 = 0;
  FUN_0047624f(arg_1,0xcf,s_Draw_a_card_Phase_00525af8,1);
  if (DAT_006fe408 == 0) {
    if (g_CurrentTurnPhase == arg_1) {
      if (g_OverworldPlayerDirection == -1) {
        match_count = *(int *)(&g_PlayerDeckCardList + arg_1 * 2000);
        if (match_count != -1) {
          Pic_Subsystem_004523fd(arg_1,0);
          match_count = Deck_AddCardToDeck(arg_1,match_count);
        }
      }
      else {
        val_1 = FUN_0040a02a(g_OverworldPlayerDirection);
        match_count = Deck_AddCardToDeck(arg_1,val_1);
      }
      if ((match_count == -1) || (*(int *)(&g_CardSlot_CardId + match_count * 0x120 + arg_1 * 0x5b20) == -1)
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
        Ai_EvaluateTacticalPosition(0,0x30);
        if (g_IsAiThinking != 1) {
          if (g_AiCombatScore_Blocker == 0) {
            Ai_Subsystem_004cc50a
                      (*(int32_t *)(&g_CardSlot_CardId + match_count * 0x120 + arg_1 * 0x5b20),0xf6,
                       s_Draw_Card_00525b18);
          }
          else {
            Ai_Subsystem_004b137d
                      (*(int32_t *)(&g_CardSlot_CardId + match_count * 0x120 + arg_1 * 0x5b20),arg_1,
                       match_count);
          }
        }
      }
    }
    else {
      if (DAT_0052eff8 == -1) {
        val_1 = Util_GetRandomNumber(3);
        if (val_1 == 0) {
          slot_idx = 1;
        }
        else if (val_1 == 1) {
          slot_idx = 2;
        }
        else if (val_1 == 2) {
          slot_idx = 0x3c;
        }
        do {
          val_1 = Util_GetRandomNumber(g_MasterCardCount);
          card_idx = Pic_Subsystem_004521a6
                               ((int)(char)(&g_MasterCardColorTable)[val_1 * 0x34],DAT_006b2d64,DAT_00696a18);
          if ((card_idx != 0) && (val_2 = File_Load_Info(val_1), DAT_00695df0 < val_2)) {
            card_idx = 0;
          }
        } while (((card_idx == 0) || ((slot_idx & (&g_MasterCardColorTable)[val_1 * 0x34]) == 0)) ||
                (((&g_MasterCardSubtypeTable)[val_1 * 0x34] & 0x40) != 0));
        match_count = Deck_AddCardToDeck(arg_1,val_1);
      }
      else if (*(int *)(&g_PlayerDeckCardList + arg_1 * 2000) == -1) {
        match_count = -1;
      }
      else {
        match_count = Deck_AddCardToDeck(arg_1,*(int *)(&g_PlayerDeckCardList + arg_1 * 2000));
        if (match_count != -1) {
          Pic_Subsystem_004523fd(arg_1,0);
        }
      }
      if (match_count == -1) {
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
      Ai_EvaluateTacticalPosition(0,0x30);
    }
    (&g_ActivePlayerSpellPriority)[arg_1] = (&g_ActivePlayerSpellPriority)[arg_1] + 1;
    _DAT_006b3038 = _DAT_006b3038 + 1;
    if ((g_IsAiThinking != 1) && (match_count != -1)) {
      Magic_UpkeepPhase(2);
    }
    if (match_count != -1) {
      *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Flags + match_count * 0x120 + arg_1 * 0x5b20) | 1;
    }
  }
  else {
    match_count = 0;
  }
  return match_count;
}

/*
 * Decompiled function: FUN_0046fe86
 * Entry Point: 0046fe86
 * Size: 202 bytes
 */


int32_t FUN_0046fe86(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  bool flag_3;
  
  flag_3 = g_ActiveCardTargetSlot == 0xd3;
  if (flag_3) {
    DAT_00525778 = 1;
  }
  val_1 = Magic_ExecuteCastSpellPhase(arg1,arg2,0);
  if (((val_1 == 0) || (val_1 = Magic_ExecuteCastSpellPhase(arg1,arg2,1), val_1 == 0)) ||
     (val_1 = Magic_ResolveCastSpell(arg1,arg2), val_1 == 0)) {
    if (flag_3) {
      DAT_00525778 = 0;
    }
    uval_2 = 0;
  }
  else {
    if (flag_3) {
      DAT_00525778 = 0;
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: Magic_ExecuteCastSpellPhase
 * Entry Point: 0046ff50
 * Size: 2993 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Magic_ExecuteCastSpellPhase(int player_id,int card_slot,int event_type)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  int val_5;
  char *mode_str;
  int32_t uval_6;
  int target_idx;
  
  val_5 = *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120);
  val_3 = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)[val_5 * 0x34]);
  val_2 = g_SelectedTargetPlayer;
  val_1 = g_SelectedTargetSlot;
  val_4 = DAT_0068a708;
  if (arg_3 == 0) {
    val_4 = FUN_00470ea3(arg_1,arg_1,arg_2);
    if (val_4 == 0) {
      return 0;
    }
    g_AiCurrentSearchPath = 0xffffffff;
    DAT_006fe3f4 = 0;
    g_OverworldPlayerCoordY = -1;
    if ((((&g_MasterCardColorTable)[val_5 * 0x34] & 0x3c) != 0) &&
       (val_4 = Magic_TriggerCardEvent(arg_1,arg_2,0x74,1 - arg_1,0xffffffff), val_4 == 0)) {
      return 0;
    }
    val_2 = g_SelectedTargetPlayer;
    val_1 = g_SelectedTargetSlot;
    val_4 = DAT_0068a708;
    g_ActivePlayer = -1;
    g_SelectedTargetPlayer = arg_1;
    g_SelectedTargetSlot = arg_2;
    DAT_0068a708 = val_5;
    Magic_CombatPhase(arg_1,arg_2,0x71,arg_1,0);
    Ai_Subsystem_004bd4f0();
    if (DAT_006fe3f4 == 0) {
      if ((g_CurrentTurnPhase == arg_1) && (g_IsAiThinking != 1)) {
        if (((&g_MasterCardColorTable)[val_5 * 0x34] & 0x40) == 0) {
          (&g_AiSelectedTargetCard)[val_3] = (int)(char)(&g_MasterCardSubTypeTable2)[val_5 * 0x34];
          g_AiSelectedTargetCard = g_AiSelectedTargetCard + (char)(&g_MasterCardManaCostTable)[val_5 * 0x34];
        }
        else {
          g_AiSelectedTargetPlayer = (int)(char)(&g_MasterCardSubTypeTable2)[val_5 * 0x34] +
                         (int)(char)(&g_MasterCardManaCostTable)[val_5 * 0x34];
        }
        Ai_Subsystem_004be192(arg_1,arg_2,0,0);
      }
      else if (((&g_MasterCardColorTable)[val_5 * 0x34] & 0x40) == 0) {
        if ((&g_MasterCardSubTypeTable2)[val_5 * 0x34] != '\0') {
          (&g_AiSelectedTargetCard)[val_3] = (int)(char)(&g_MasterCardSubTypeTable2)[val_5 * 0x34];
        }
        if ('\0' < (char)(&g_MasterCardManaCostTable)[val_5 * 0x34]) {
          g_AiSelectedTargetCard = (int)(char)(&g_MasterCardManaCostTable)[val_5 * 0x34];
        }
        Ai_Subsystem_004be192(arg_1,arg_2,0,0);
        if ((&g_MasterCardManaCostTable)[val_5 * 0x34] == -1) {
          if (g_CurrentTurnPhase == arg_1) {
            g_OverworldPlayerCoordY = FUN_0040d949(arg_1,7,1);
            Ai_CalcManaRequirement_004ba890(arg_1,0,-1);
          }
          else {
            if (g_IsAiThinking == 1) {
              val_3 = Util_GetRandomNumber(2);
              if (val_3 == 0) {
                val_3 = FUN_0040d949(arg_1,7,1);
                if (val_3 == 0) {
                  val_3 = FUN_0040d949(arg_1,7,1);
                  g_AiDecisionScore = Util_GetRandomNumber(val_3 + 1);
                  target_idx = g_AiDecisionScore;
                }
                else {
                  val_3 = Util_GetRandomNumber(val_3);
                  g_AiDecisionScore = val_3 + 1;
                  target_idx = g_AiDecisionScore;
                }
              }
              else if (val_3 == 1) {
                target_idx = FUN_0040d949(arg_1,7,1);
                g_AiDecisionScore = target_idx;
                if ((g_PlayerCreatureCount < target_idx) && (val_3 = Util_GetRandomNumber(3), val_3 == 0)) {
                  target_idx = g_PlayerCreatureCount;
                  g_AiDecisionScore = g_PlayerCreatureCount;
                }
                if ((g_OverworldPlayerCoordY != -1) && (g_OverworldPlayerCoordY < g_AiDecisionScore)
                   ) {
                  target_idx = g_OverworldPlayerCoordY;
                  g_AiDecisionScore = g_OverworldPlayerCoordY;
                }
              }
              Ai_EvaluateCreaturePower();
            }
            else {
              Ai_CalcCardAdvantage();
              target_idx = g_AiDecisionScore;
            }
            g_OverworldPlayerCoordY = target_idx;
            Ai_CalcManaRequirement_004ba890(arg_1,0,-1);
          }
          if (g_TurnCounter == 0) {
            g_SpellStackDepth = g_SpellStackDepth + -100;
          }
        }
      }
      else {
        Ai_Subsystem_004be192
                  (arg_1,arg_2,6,
                   (int)(char)(&g_MasterCardSubTypeTable2)[val_5 * 0x34] +
                   (int)(char)(&g_MasterCardManaCostTable)[val_5 * 0x34]);
      }
    }
    g_OverworldPlayerCoordY = -1;
    if (val_5 != -1) {
      DAT_0068a650 = arg_1;
      _DAT_006a3f70 = 1;
      (&g_ActivePlayerSpellPriority)[arg_1] = (&g_ActivePlayerSpellPriority)[arg_1] + -1;
      if (((&g_MasterCardColorTable)[val_5 * 0x34] & 2) != 0) {
        *(int *)(&DAT_006b3010 + arg_1 * 4) = *(int *)(&DAT_006b3010 + arg_1 * 4) + 1;
      }
      if (((&g_MasterCardColorTable)[val_5 * 0x34] & 0x40) != 0) {
        (&DAT_006b3018)[arg_1] = (&DAT_006b3018)[arg_1] + 1;
      }
      if (((&g_MasterCardColorTable)[val_5 * 0x34] & 4) != 0) {
        *(int *)(&DAT_006b3020 + arg_1 * 4) = *(int *)(&DAT_006b3020 + arg_1 * 4) + 1;
      }
      (&g_PlayerPoisonCounters)[arg_1] =
           (&g_PlayerPoisonCounters)[arg_1] | (uint32_t)(uint8_t)(&g_MasterCardColorTable)[val_5 * 0x34];
      *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x20;
      g_PlayerHandCardCount = g_PlayerHandCardCount | 0x20;
      if ((g_CurrentTurnPhase == arg_1) || (g_IsAiThinking != 1)) {
        *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x30000;
      }
      else {
        *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10000;
      }
      DAT_0068a708 = val_4;
      g_SelectedTargetSlot = val_1;
      g_SelectedTargetPlayer = val_2;
      if (g_ActivePlayer == 1) {
        Ai_Util_004bd5af();
      }
      else {
        val_4 = Rules_ApplyContinuousDamage(arg_1,arg_2,0x6c);
        if (val_4 != 0) {
          Engine_ReportFatalError(s_Illegal_cast_00525bcc);
          g_ActivePlayer = 1;
        }
        if (g_ActivePlayer == 1) {
          Ai_Subsystem_004bd5e3(arg_1);
        }
        Ai_Util_004bd5af();
        if (g_ActivePlayer != 1) {
          if (((g_IsAiThinking == 1) && (g_ActivePlayerPriority == arg_1)) &&
             ((&g_MasterCardManaCostTable)[val_5 * 0x34] == -1)) {
            val_5 = FUN_00473d98(arg_1);
            g_SpellStackDepth = g_SpellStackDepth + val_5 * -0xc;
          }
          return 1;
        }
      }
    }
  }
  else {
    g_SelectedTargetPlayer = arg_1;
    g_SelectedTargetSlot = arg_2;
    DAT_0068a708 = val_5;
    if (((&g_MasterCardColorTable)[val_5 * 0x34] & 1) == 0) {
      Magic_MainTurnPhase(1);
    }
    if (((&g_MasterCardColorTable)[val_5 * 0x34] != '\x01') &&
       (((&g_MasterCardColorTable)[val_5 * 0x34] != ' ' ||
        (((&g_MasterCardFlagsTable)[val_5 * 0x34] & 0x10) == 0)))) {
      strcpy(&g_OverworldWorldState,s_Trying_to_cast_00525bdc);
      Ai_Subsystem_004b90de(g_SelectedTargetPlayer,g_SelectedTargetSlot);
      FUN_00475c8a(-2,g_ScWillyScore,&g_OverworldWorldState,0xd3);
    }
    if (*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120) == -1) {
      g_ActivePlayer = 1;
    }
    g_PlayerHandCardCount = g_PlayerHandCardCount & 0xffffffdf;
    DAT_0068a708 = val_4;
    g_SelectedTargetSlot = val_1;
    g_SelectedTargetPlayer = val_2;
    *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) |
         CONCAT31((uint3)((arg_1 == 0) - 1 >> 8) & 0x4000,0x80);
    if (g_IsAiThinking != 1) {
      FUN_004755fd();
    }
    if (g_ActivePlayer != 1) {
      if (((g_CurrentTurnPhase != arg_1) && (g_IsAiThinking != 1)) &&
         (((&g_MasterCardColorTable)[val_5 * 0x34] & 0x7e) != 0)) {
        strcpy(&g_OverworldWorldState,&DAT_00695e10);
        strcat(&g_OverworldWorldState,s_casts____00525bec);
        if ((&g_MasterCardManaCostTable)[val_5 * 0x34] == -1) {
          strcat(&g_OverworldWorldState,s_X_is_00525bf8);
          str_2 = _itoa(g_TurnCounter,&DAT_00538df8,10);
          strcat(&g_OverworldWorldState,str_2);
          strcat(&g_OverworldWorldState,&DAT_00525c00);
        }
        if ((&g_CardSlot_TurnPlayed)[arg_1 * 0x5b20 + arg_2 * 0x120] == '\0') {
          Ai_Subsystem_004b574d(arg_1,arg_2,-1,-1,&g_OverworldWorldState,0);
        }
        else if ((&g_CardSlot_TurnPlayed)[arg_1 * 0x5b20 + arg_2 * 0x120] == '\x01') {
          Ai_Subsystem_004b574d
                    (arg_1,arg_2,*(int *)(&g_CardSlot_CombatTarget + arg_1 * 0x5b20 + arg_2 * 0x120)
                     ,*(int *)(&g_CardSlot_AttachedAura + arg_1 * 0x5b20 + arg_2 * 0x120),
                     &g_OverworldWorldState,0);
        }
        else {
          Ai_Subsystem_004b574d(arg_1,arg_2,-1,-1,&g_OverworldWorldState,0);
        }
        DAT_00627a84 = g_DefendingPlayer;
        DAT_00627a88 = g_ScWillyScore;
      }
      if (g_IsAiThinking != 1) {
        Ai_Subsystem_004cc3f8(arg_1,arg_2,2,1);
      }
    }
  }
  if (g_ActivePlayer == 1) {
    (&g_ActivePlayerSpellPriority)[arg_1] = (&g_ActivePlayerSpellPriority)[arg_1] + 1;
    if (((&g_MasterCardColorTable)[val_5 * 0x34] & 2) != 0) {
      *(int *)(&DAT_006b3010 + arg_1 * 4) = *(int *)(&DAT_006b3010 + arg_1 * 4) + -1;
    }
    if (((&g_MasterCardColorTable)[val_5 * 0x34] & 0x40) != 0) {
      (&DAT_006b3018)[arg_1] = (&DAT_006b3018)[arg_1] + -1;
    }
    if (((&g_MasterCardColorTable)[val_5 * 0x34] & 4) != 0) {
      *(int *)(&DAT_006b3020 + arg_1 * 4) = *(int *)(&DAT_006b3020 + arg_1 * 4) + -1;
    }
    *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffffff5d;
    *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint32_t *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffcffff;
    if (g_CurrentTurnPhase != arg_1) {
      DAT_00701008 = 1;
    }
    g_ActivePlayer = 0;
    Magic_DiscardToHandSize();
    g_PlayerHandCardCount = g_PlayerHandCardCount & 0xffffffdf;
    uval_6 = 0;
  }
  else {
    FUN_00476482(arg_1,arg_2);
    uval_6 = 1;
  }
  return uval_6;
}

/*
 * Decompiled function: Magic_ResolveCastSpell
 * Entry Point: 00470b36
 * Size: 877 bytes
 */


int32_t Magic_ResolveCastSpell(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  int32_t uval_3;
  
  val_1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  Rules_CalculateManaCostReduction((&g_MasterCardColorTable)[val_1 * 0x34]);
  if (val_1 == -1) {
    Magic_DiscardToHandSize();
    uval_3 = 0;
  }
  else {
    if (((&g_MasterCardColorTable)[val_1 * 0x34] != '\x01') &&
       (((&g_MasterCardColorTable)[val_1 * 0x34] != ' ' ||
        (((&g_MasterCardFlagsTable)[val_1 * 0x34] & 0x10) == 0)))) {
      strcpy(&g_OverworldWorldState,s_Cast_00525c04);
      Ai_Subsystem_004b90de(arg1,arg2);
      FUN_00475c8a(-2,g_ScWillyScore,&g_OverworldWorldState,0x6c);
    }
    *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffffdf;
    *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) | 2;
    g_PlayerHandCardCount = g_PlayerHandCardCount & 0xffffffdf;
    if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == val_1) {
      (&g_PlayerPoisonCounters)[arg1] =
           (&g_PlayerPoisonCounters)[arg1] | (uint32_t)(uint8_t)(&g_MasterCardColorTable)[val_1 * 0x34];
      if (g_IsAiThinking != 1) {
        if (((&g_MasterCardColorTable)[val_1 * 0x34] & 2) != 0) {
          Magic_UpkeepPhase(0x11);
        }
        if (((&g_MasterCardColorTable)[val_1 * 0x34] & 0x40) != 0) {
          Magic_UpkeepPhase(0);
        }
        if (((&g_MasterCardColorTable)[val_1 * 0x34] & 4) != 0) {
          Magic_UpkeepPhase(3);
        }
        if (((&g_MasterCardColorTable)[val_1 * 0x34] & 0x10) != 0) {
          Magic_UpkeepPhase(6);
        }
        if (((&g_MasterCardColorTable)[val_1 * 0x34] & 0x20) != 0) {
          Magic_UpkeepPhase(7);
        }
        if (((&g_MasterCardColorTable)[val_1 * 0x34] & 8) != 0) {
          Magic_UpkeepPhase(0x10);
        }
      }
      Magic_EndTurnPhase();
      uval_2 = DAT_006b2e14;
      uval_3 = DAT_00695f08;
      DAT_00695f08 = arg1;
      DAT_006b2e14 = arg2;
      FUN_00476205(g_DefendingPlayer,0xd3,s_Casting_00525c0c,0);
      DAT_00695f08 = uval_3;
      DAT_006b2e14 = uval_2;
      Rules_ProcessDamagePrevention(arg1);
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
        uval_3 = 0;
      }
      else {
        g_ActivePlayer = 0;
        Ai_EvaluateTacticalPosition(0,0xff);
        uval_3 = 1;
      }
    }
    else {
      Magic_DiscardToHandSize();
      uval_3 = 0;
    }
  }
  return uval_3;
}

/*
 * Decompiled function: FUN_00470ea3
 * Entry Point: 00470ea3
 * Size: 408 bytes
 */


bool FUN_00470ea3(int player_id,int card_slot,int event_type)

{
  int val_1;
  uint32_t width;
  int val_2;
  bool flag_3;
  
  if (((arg_1 == -1) || (arg_2 == -1)) || (arg_3 == -1)) {
    flag_3 = false;
  }
  else {
    val_1 = *(int *)(&g_CardSlot_CardId + arg_3 * 0x120 + arg_2 * 0x5b20);
    if (val_1 == -1) {
      flag_3 = false;
    }
    else if (((&g_MasterCardColorTable)[val_1 * 0x34] & 0x40) == 0) {
      width = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)[val_1 * 0x34]);
      val_2 = FUN_0040dcca(arg_1,arg_3,width,(int)(char)(&g_MasterCardSubTypeTable2)[val_1 * 0x34]);
      flag_3 = val_2 != 0;
      if (('\0' < (char)(&g_MasterCardManaCostTable)[val_1 * 0x34]) &&
         (val_1 = FUN_0040dcca(arg_1,arg_3,7,
                               (int)(char)(&g_MasterCardSubTypeTable2)[val_1 * 0x34] +
                               (int)(char)(&g_MasterCardManaCostTable)[val_1 * 0x34]), val_1 == 0)) {
        flag_3 = false;
      }
    }
    else {
      val_1 = FUN_0040d949(arg_1,6,(int)(char)(&g_MasterCardSubTypeTable2)[val_1 * 0x34] +
                                   (int)(char)(&g_MasterCardManaCostTable)[val_1 * 0x34]);
      flag_3 = val_1 != 0;
    }
  }
  return flag_3;
}

/*
 * Decompiled function: Magic_ExecuteUpkeepPhase
 * Entry Point: 0047103b
 * Size: 2358 bytes
 */


bool Magic_ExecuteUpkeepPhase(int arg1,int arg2)

{
  uint32_t uval_1;
  int val_2;
  char *char_ptr_3;
  bool bVar4;
  uint32_t local_28;
  int local_24;
  int loop_idx;
  uint32_t target_idx;
  uint32_t player_idx;
  int match_count;
  
  match_count = arg1;
  if (g_ScWillyScore == 4) {
    match_count = g_CurrentTurnTargetPlayer;
  }
  if ((g_CurrentTurnPhase != match_count) && (g_IsAiThinking != 1)) {
    Magic_TriggerCardEvent(arg1,arg2,0x90,1 - arg1,0xffffffff);
    strcpy(&g_OverworldWorldState,&DAT_00695e10);
    strcat(&g_OverworldWorldState,s_activates____00525c20);
    val_2 = FUN_004769c4(arg1,arg2);
    if (val_2 == 0) {
      if (((((&g_MasterCardSubtypeTable)[*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] &
            0x18) != 0) && (g_DefendingPlayer == arg1)) && (DAT_0062785c != 0)) {
        strcat(&g_OverworldWorldState,s__with_00525c3c);
        char_ptr_3 = _itoa(DAT_0062785c,&DAT_00538df8,10);
        strcat(&g_OverworldWorldState,char_ptr_3);
        strcat(&g_OverworldWorldState,s_mana___00525c44);
      }
    }
    else {
      strcat(&g_OverworldWorldState,s_X_is_00525c30);
      char_ptr_3 = _itoa(DAT_0062785c,&DAT_00538df8,10);
      strcat(&g_OverworldWorldState,char_ptr_3);
      strcat(&g_OverworldWorldState,&DAT_00525c38);
    }
    if ((&g_CardSlot_TurnPlayed)[arg1 * 0x5b20 + arg2 * 0x120] == '\0') {
      if (g_AiCurrentSearchPath == 0xffffffff) {
        Ai_Subsystem_004b574d(arg1,arg2,-1,-1,&g_OverworldWorldState,0);
      }
      else {
        Ai_Subsystem_004b574d
                  (arg1,arg2,(int)g_AiCurrentSearchPath >> 8,g_AiCurrentSearchPath & 0xff,&g_OverworldWorldState,0);
      }
    }
    else if ((&g_CardSlot_TurnPlayed)[arg1 * 0x5b20 + arg2 * 0x120] == '\x01') {
      Ai_Subsystem_004b574d
                (arg1,arg2,*(int *)(&g_CardSlot_CombatTarget + arg1 * 0x5b20 + arg2 * 0x120),
                 *(int *)(&g_CardSlot_AttachedAura + arg1 * 0x5b20 + arg2 * 0x120),
                 &g_OverworldWorldState,0);
    }
    else {
      Ai_Subsystem_004b574d(arg1,arg2,-1,-1,&g_OverworldWorldState,0);
    }
  }
  Magic_CombatPhase(arg1,arg2,0x72,arg1,0);
  DAT_00695df8 = 0;
  if (((&g_CardSlot_SpecialState)[arg1 * 0x5b20 + arg2 * 0x120] & 1) == 0) {
    if ((((&g_CardSlot_SpecialState)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) != 0) &&
       (val_2 = FUN_00476675(arg1,arg2), val_2 != 0)) {
      for (local_24 = 0; local_24 < 7; local_24 = local_24 + 1) {
        (&g_AiSelectedTargetCard)[local_24] =
             (int)(char)(&DAT_006a603c)[local_24 + arg2 * 0x120 + arg1 * 0x5b20];
      }
      Ai_CalcManaRequirement_004ba890(arg1,0,0);
      if ((g_ActivePlayer == 0) &&
         (Magic_TriggerCardEvent(arg1,arg2,1,1 - arg1,0xffffffff), DAT_006b2e38 == 0)) {
        *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
             *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) | 0x40;
      }
      if (g_ActivePlayer != 0) {
        g_ActivePlayer = 0;
        Magic_DiscardToHandSize();
        return false;
      }
      *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
           *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) & 0xffffffef;
      *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
           *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) | 0x80;
      Magic_MainTurnPhase(1);
      return true;
    }
    val_2 = Rules_ApplyContinuousDamage(arg1,arg2,0x80);
    if (val_2 == 0) {
      if (((&g_MasterCardFlagsTable)[*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] &
          0x10) != 0) {
        g_PendingAttackersTargetSlot = -1;
      }
      Ai_Subsystem_004bd4f0();
      uval_1 = *(uint32_t *)(&g_CardSlot_Flags + arg1 * 0x5b20 + arg2 * 0x120);
      Magic_TriggerCardEvent(arg1,arg2,0x6d,1 - arg1,0xffffffff);
      bVar4 = g_ActivePlayer == 1;
      if (bVar4) {
        Ai_Subsystem_004bd5e3(arg1);
        Magic_DiscardToHandSize();
      }
      bVar4 = !bVar4;
      Ai_Util_004bd5af();
      if (bVar4) {
        if (((uval_1 & 0x10) == 0) &&
           (((&g_CardSlot_Flags)[arg1 * 0x5b20 + arg2 * 0x120] & 0x10) != 0)) {
          Rules_ApplyContinuousDamage(arg1,arg2,0x81);
        }
        if (*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) == -1) {
          local_28 = *(uint32_t *)(&g_MasterCardSubtypeTable +
                              *(int *)(&g_ActiveCardsInPlay + arg1 * 0x5b20 + arg2 * 0x120) * 0x34);
        }
        else {
          local_28 = *(uint32_t *)(&g_MasterCardSubtypeTable +
                              *(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34);
        }
        local_28 = local_28 & 0x1000;
        if ((local_28 == 0) || (g_PendingAttackersTargetSlot == -1)) {
          Magic_MainTurnPhase(1);
        }
        else {
          Magic_MainTurnPhase(0);
        }
        if (g_IsAiThinking != 1) {
          if ((((&g_MasterCardFlagsTable)[*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34]
               & 0x10) == 0) || (g_PendingAttackersTargetSlot == -1)) {
            Magic_UpkeepPhase(0x1c);
          }
          else {
            Magic_UpkeepPhase(0x12);
          }
        }
        if (g_IsAiThinking != 1) {
          FUN_004755fd();
        }
      }
    }
    else {
      Magic_DiscardToHandSize();
      bVar4 = false;
    }
    if (bVar4 != false) {
      return bVar4;
    }
    DAT_00695df8 = 0;
    return false;
  }
  bVar4 = true;
  loop_idx = 0;
  for (target_idx = 0; (int)target_idx < 7; target_idx = target_idx + 1) {
    (&g_AiSelectedTargetCard)[target_idx] = (int)(char)(&DAT_006a6048)[target_idx + arg2 * 0x120 + arg1 * 0x5b20];
    if ((0 < (int)target_idx) &&
       (val_2 = FUN_0040d949(arg1,target_idx,(&g_AiSelectedTargetCard)[target_idx]), val_2 == 0)) {
      bVar4 = false;
    }
    loop_idx = loop_idx + (&g_AiSelectedTargetCard)[target_idx];
  }
  val_2 = FUN_0040d949(match_count,7,loop_idx);
  if (val_2 == 0) {
    bVar4 = false;
  }
  player_idx = (uint32_t)!bVar4;
  if ((((&DAT_006a6045)[arg1 * 0x5b20 + arg2 * 0x120] & 1) != 0) ||
     (val_2 = Ai_Subsystem_004cc56d
                        (match_count,arg1,arg2,-1,-1,s_Pay_Upkeep_costs__Don_t_pay_Upke_00525c4c,
                         player_idx), val_2 == 0)) {
    if (!bVar4) goto LAB_004714f6;
    Ai_CalcManaRequirement_004ba890(match_count,0,0);
    if ((g_ActivePlayer == 0) &&
       (Magic_TriggerCardEvent(arg1,arg2,4,1 - arg1,0xffffffff), DAT_006b2e38 == 0)) {
      *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
           *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) | 0x200;
    }
  }
  if (g_ActivePlayer != 0) {
    g_ActivePlayer = 0;
    Magic_DiscardToHandSize();
    return false;
  }
LAB_004714f6:
  for (target_idx = 0; (int)target_idx < 7; target_idx = target_idx + 1) {
    (&g_AiSelectedTargetCard)[target_idx] = 0;
  }
  *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
       *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) & 0xfffffffe;
  *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) =
       *(uint32_t *)(&g_CardSlot_SpecialState + arg1 * 0x5b20 + arg2 * 0x120) | 8;
  Magic_MainTurnPhase(1);
  return true;
}

/*
 * Decompiled function: Magic_ExecuteTapCardAction
 * Entry Point: 00471971
 * Size: 329 bytes
 */


int32_t Magic_ExecuteTapCardAction(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  int32_t uval_3;
  int player_idx;
  
  if ((((&g_MasterCardFlagsTable)[*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34] & 0x10)
       == 0) || (g_PendingAttackersTargetSlot == -1)) {
    flag_1 = false;
  }
  else {
    flag_1 = true;
  }
  if (g_ActivePlayer != 1) {
    if ((!flag_1) && (DAT_00695df8 == 0)) {
      strcpy(&g_OverworldWorldState,s_Activate_00525c74);
      Ai_Subsystem_004b90de(arg1,arg2);
      if ((DAT_0063ee1c == 0) || (arg1 != g_CurrentTurnPhase)) {
        player_idx = -2;
      }
      else {
        player_idx = -1;
      }
      FUN_00475c8a(player_idx,g_ScWillyScore,&g_OverworldWorldState,0x6d);
    }
    Magic_EndTurnPhase();
    uval_3 = DAT_006b2e14;
    uval_2 = DAT_00695f08;
    DAT_00695f08 = arg1;
    DAT_006b2e14 = arg2;
    FUN_00476205(g_DefendingPlayer,0xd2,s_Tapping_00525c80,0);
    DAT_00695f08 = uval_2;
    DAT_006b2e14 = uval_3;
  }
  return 1;
}

/*
 * Decompiled function: Magic_ExecuteProcessTriggers
 * Entry Point: 00471aba
 * Size: 262 bytes
 */


int32_t Magic_ExecuteProcessTriggers(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  DAT_0068078c = 1;
  Magic_CombatPhase(arg_1,arg_2,0x7e,arg_3,0);
  if (g_ActivePlayer == 1) {
    Magic_DiscardToHandSize();
    uval_1 = 0;
  }
  else {
    if (g_IsAiThinking != 1) {
      FUN_004755fd();
      if (g_CurrentTurnPhase != g_CurrentCardColorTarget) {
        strcpy(&g_OverworldWorldState,&DAT_00695e10);
        strcat(&g_OverworldWorldState,s_processes____00525c88);
        Ai_Subsystem_004b574d(arg_1,arg_2,-1,-1,&g_OverworldWorldState,0);
      }
    }
    *(uint32_t *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x100;
    strcpy(&g_OverworldWorldState,s_Process_00525c98);
    Ai_Subsystem_004b90de(arg_1,arg_2);
    uval_1 = Magic_EndTurnPhase();
  }
  DAT_0068078c = 0;
  return uval_1;
}

/*
 * Decompiled function: FUN_00471bc0
 * Entry Point: 00471bc0
 * Size: 114 bytes
 */


bool FUN_00471bc0(int arg1,int arg2)

{
  bool flag_1;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    flag_1 = false;
  }
  else {
    flag_1 = ((uint8_t)*(int32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0x22) != 2;
  }
  return flag_1;
}

/*
 * Decompiled function: FUN_00471c32
 * Entry Point: 00471c32
 * Size: 114 bytes
 */


bool FUN_00471c32(int arg1,int arg2)

{
  bool flag_1;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    flag_1 = false;
  }
  else {
    flag_1 = ((uint8_t)*(int32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0x22) == 2;
  }
  return flag_1;
}

/*
 * Decompiled function: FUN_00471ca4
 * Entry Point: 00471ca4
 * Size: 114 bytes
 */


int32_t FUN_00471ca4(int arg1,int arg2)

{
  int32_t uval_1;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    uval_1 = 0;
  }
  else if (((uint8_t)*(int32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0x1e) == 2) {
    uval_1 = 1;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: Magic_ExecuteDeclareBlockersPhase
 * Entry Point: 00471d16
 * Size: 722 bytes
 */


void Magic_ExecuteDeclareBlockersPhase(uint32_t arg_1)

{
  int val_1;
  int aiStack_100 [16];
  int aiStack_c0 [16];
  uint32_t local_80;
  int local_70;
  int local_64;
  int local_50;
  int local_3c;
  int local_38;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int loop_idx;
  int color_idx;
  int target_idx;
  
  if (g_IsAiThinking != 1) {
    Ai_EvaluateTacticalPosition(0,0xff);
    local_80 = arg_1;
    local_2c = 1 - arg_1;
    local_70 = 0;
    local_30 = 0;
    for (local_50 = 0; local_50 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_50 = local_50 + 1) {
      local_38 = *(int *)(&g_CardSlot_CardId + local_50 * 0x120 + arg_1 * 0x5b20);
      if ((local_38 != -1) && (((&g_CardSlot_Flags)[local_50 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
        local_64 = FUN_00473179(arg_1,local_50,0x32,0xffffffff);
        aiStack_100[local_30] = local_50;
        aiStack_c0[local_30] = local_64;
        local_30 = local_30 + 1;
        if (local_70 < local_64) {
          local_70 = local_64;
        }
      }
    }
    loop_idx = 0;
    while ((loop_idx == 0 && (val_1 = FUN_00472a0a(local_2c), val_1 != 0))) {
      val_1 = Action_ValidateTarget_00405802
                        (local_2c,local_2c,local_2c,0x2200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0
                         ,0,0x11,s_Choose_blockers_00525ca4,2,&local_28);
      if (val_1 == 0) {
        loop_idx = 1;
      }
      else {
        val_1 = Action_ValidateTarget_00405802
                          (local_2c,local_80,local_80,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,
                           0,2,0,s_Block_which_attacker__00525cb4,1,&color_idx);
        if (val_1 != 0) {
          val_1 = FUN_00472e08(local_28,local_24,color_idx,target_idx);
          if (val_1 == 0) {
            if (g_IsAiThinking != 1) {
              Ai_Util_004cc42d(s_Illegal_block__00525ccc);
              Sleep(2000);
              Ai_Util_004cc42d(&DAT_00525cdc);
            }
          }
          else {
            local_3c = (int)(char)(&g_CardSlot_ColorMask)[color_idx * 0x5b20 + target_idx * 0x120];
            if (local_3c == -1) {
              (&g_CardSlot_ColorMask)[local_28 * 0x5b20 + local_24 * 0x120] = (uint8_t)target_idx;
            }
            else {
              (&g_CardSlot_ColorMask)[local_28 * 0x5b20 + local_24 * 0x120] =
                   (&g_CardSlot_ColorMask)[color_idx * 0x5b20 + target_idx * 0x120];
            }
            *(uint32_t *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) =
                 *(uint32_t *)(&g_CardSlot_Flags + local_28 * 0x5b20 + local_24 * 0x120) | 8;
            Ai_EvaluateTacticalPosition(0,0xff);
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


int32_t FUN_00472616(int player_id)

{
  int val_1;
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if ((int)(&g_PlayerActiveCardCount)[arg_1] <= slot_idx) {
      return 0;
    }
    if (((*(int *)(&g_CardSlot_CardId + slot_idx * 0x120 + arg_1 * 0x5b20) != -1) &&
        (((&g_CardSlot_Flags)[slot_idx * 0x120 + arg_1 * 0x5b20] & 6) != 0)) &&
       (val_1 = FUN_004726c5(arg_1,slot_idx), val_1 != 0)) break;
    slot_idx = slot_idx + 1;
  }
  return 1;
}

/*
 * Decompiled function: FUN_004726c5
 * Entry Point: 004726c5
 * Size: 510 bytes
 */


int32_t FUN_004726c5(int arg1,int arg2)

{
  int32_t uval_1;
  int32_t uval_2;
  int val_3;
  
  uval_1 = g_ActivePlayer;
  val_3 = g_ActivePalette;
  if (((((&g_MasterCardRarityTable)[*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] == '\0'
        ) && (((&DAT_006a5f69)[arg2 * 0x120 + arg1 * 0x5b20] & 8) == 0)) ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0)) ||
     (((*(uint32_t *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0x10010) != 0 ||
      (((&DAT_006a5f69)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) != 0)))) {
    uval_2 = 0;
    g_ActivePalette = val_3;
    g_ActivePlayer = uval_1;
  }
  else {
    g_ActivePalette = 0;
    (**(code **)(&g_CardScriptCallbackTable + *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34)
    )(arg1,arg2,0x79);
    if (g_ActivePalette == 0) {
      g_ActivePalette = val_3;
      g_ActivePlayer = uval_1;
      if (g_ActivePlayerPriority == arg1) {
        Magic_PayManaCost();
        g_ActivePalette = 0;
        g_OverworldPlayerCoordX = arg1;
        g_OverworldMapGrid = arg2;
        Glue_Subsystem_004e65e1(Pic_Subsystem_0042e80e,-1);
        val_3 = g_ActivePalette;
        Magic_TapCardForMana();
        if (val_3 != 0) {
          return 0;
        }
      }
      if ((*(int *)(&DAT_00680780 + (1 - arg1) * 4) != 0) &&
         (val_3 = Rules_ApplyContinuousDamage(arg1,arg2,0x79), val_3 != 0)) {
        return 0;
      }
      uval_2 = 1;
    }
    else {
      uval_2 = 0;
      g_ActivePalette = val_3;
      g_ActivePlayer = uval_1;
    }
  }
  return uval_2;
}

/*
 * Decompiled function: Rules_ValidateCardTargetSlot
 * Entry Point: 004728c3
 * Size: 66 bytes
 */


bool Rules_ValidateCardTargetSlot(int arg1,int arg2)

{
  return ((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) != 0;
}

/*
 * Decompiled function: FUN_00472905
 * Entry Point: 00472905
 * Size: 261 bytes
 */


int32_t FUN_00472905(int player_id)

{
  int val_1;
  int32_t uval_2;
  int slot_idx;
  
  g_ActiveBattlefieldFlag = 0;
  DAT_00626810 = 0;
  for (slot_idx = 0; slot_idx < (int)(&g_PlayerActiveCardCount)[arg_1]; slot_idx = slot_idx + 1) {
    val_1 = FUN_00471c32(arg_1,slot_idx);
    if (val_1 != 0) {
      if (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + slot_idx * 0x120] & 4) == 0) {
        if (((&DAT_006a5f3d)[arg_1 * 0x5b20 + slot_idx * 0x120] & 0x80) != 0) {
          val_1 = FUN_004726c5(arg_1,slot_idx);
          if (val_1 != 0) {
            DAT_00626810 = DAT_00626810 + 1;
          }
        }
      }
      else {
        g_ActiveBattlefieldFlag = 1;
      }
    }
  }
  if ((g_ActiveBattlefieldFlag == 0) && (DAT_00626810 == 0)) {
    uval_2 = 1;
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_00472a0a
 * Entry Point: 00472a0a
 * Size: 391 bytes
 */


int32_t FUN_00472a0a(int player_id)

{
  int x;
  uint32_t arg_5;
  int val_1;
  int target_idx;
  uint32_t player_idx;
  uint32_t card_idx;
  int match_count;
  uint32_t slot_idx;
  
  x = 1 - arg_1;
  Ai_FilterValidBlockers(&slot_idx,&card_idx);
  if (arg_1 == 1) {
    player_idx = slot_idx;
  }
  else {
    player_idx = card_idx;
  }
  match_count = 0;
  do {
    if ((int)(&g_PlayerActiveCardCount)[x] <= match_count) {
      return 0;
    }
    if ((*(int *)(&g_CardSlot_CardId + x * 0x5b20 + match_count * 0x120) != -1) &&
       (((&g_CardSlot_Flags)[x * 0x5b20 + match_count * 0x120] & 4) != 0)) {
      arg_5 = FUN_00473179(x,match_count,0x34,0xffffffff);
      for (target_idx = 0; target_idx < (int)(&g_PlayerActiveCardCount)[arg_1]; target_idx = target_idx + 1)
      {
        if (((*(int *)(&g_CardSlot_CardId + x * 0x5b20 + match_count * 0x120) != -1) &&
            (((uint8_t)*(int32_t *)(&g_CardSlot_Flags + target_idx * 0x120 + arg_1 * 0x5b20) & 0x1a)
             == 2)) && (val_1 = FUN_00472c0c(arg_1,target_idx,x,match_count,arg_5,player_idx), val_1 != 0))
        {
          return 1;
        }
      }
    }
    match_count = match_count + 1;
  } while( true );
}

/*
 * Decompiled function: FUN_00472b91
 * Entry Point: 00472b91
 * Size: 123 bytes
 */


int32_t FUN_00472b91(int x,int card_slot,int event_type,int arg_4)

{
  uint32_t arg_5;
  int32_t uval_1;
  uint32_t card_idx;
  uint32_t match_count;
  uint32_t slot_idx;
  
  arg_5 = FUN_00473179(arg_3,arg_4,0x34,0xffffffff);
  Ai_FilterValidBlockers(&slot_idx,&match_count);
  if (x == 1) {
    card_idx = slot_idx;
  }
  else {
    card_idx = match_count;
  }
  uval_1 = FUN_00472c0c(x,arg_2,arg_3,arg_4,arg_5,card_idx);
  return uval_1;
}

/*
 * Decompiled function: FUN_00472c0c
 * Entry Point: 00472c0c
 * Size: 508 bytes
 */


/* WARNING: Removing unreachable block (ram,0x00472d06) */

bool FUN_00472c0c(int player_id,int card_slot,int32_t arg_3,int32_t arg_4,uint32_t arg_5,uint32_t arg_6)

{
  char cVar1;
  bool flag_2;
  int val_3;
  uint32_t uval_4;
  
  if (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0) {
    flag_2 = false;
  }
  else if ((*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) ||
          (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x18) != 0)) {
    flag_2 = false;
  }
  else if ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) == 0) ||
          (val_3 = Rules_ValidateCardTargetSlot(arg_1,arg_2), val_3 != 0)) {
    if (((arg_5 & 0x20) == 0) ||
       (uval_4 = FUN_00473179(arg_1,arg_2,0x34,0xffffffff), (uval_4 & 0x420) != 0)) {
      if (((arg_5 & 0x1ff800) == 0) ||
         (cVar1 = Rules_CalculateManaCostReduction((&g_CardSlot_MinusOneCounters)[arg_2 * 0x120 + arg_1 * 0x5b20]),
         (arg_5 & 0x800 << (cVar1 - 1U & 0x1f)) == 0)) {
        if ((arg_6 & arg_5 & 0x1f) == 0) {
          Magic_PayManaCost();
          g_OverworldPlayerCoordX = arg_1;
          g_OverworldMapGrid = arg_2;
          DAT_007006c8 = arg_3;
          DAT_006b2d5c = arg_4;
          g_ActivePalette = 0;
          Magic_ScanCards(0x78);
          flag_2 = g_ActivePalette < 1;
          Magic_TapCardForMana();
        }
        else {
          flag_2 = false;
        }
      }
      else {
        flag_2 = false;
      }
    }
    else {
      flag_2 = false;
    }
  }
  else {
    flag_2 = false;
  }
  return flag_2;
}

/*
 * Decompiled function: FUN_00472e08
 * Entry Point: 00472e08
 * Size: 260 bytes
 */


int FUN_00472e08(int x,int y,int32_t arg_3,int32_t arg_4)

{
  uint8_t uval_1;
  int32_t uval_2;
  int val_3;
  
  uval_2 = *(int32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20);
  uval_1 = (&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20];
  *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
       *(uint32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0xfffffff7;
  (&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20] = 0xff;
  val_3 = FUN_00472b91(x,y,arg_3,arg_4);
  if (val_3 == 0) {
    *(int32_t *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) = uval_2;
    (&g_CardSlot_ColorMask)[y * 0x120 + x * 0x5b20] = uval_1;
  }
  return val_3;
}

/*
 * Decompiled function: FUN_00472f0c
 * Entry Point: 00472f0c
 * Size: 162 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00472f0c(int32_t arg1,int arg2)

{
  char cVar1;
  int val_2;
  
  DAT_0069f6d8 = 0xffffd8f1;
  g_IsAiThinking = 1;
  DAT_006808a8 = arg1;
  val_2 = (g_CampaignDifficultyLevel + 1) * arg2;
  DAT_006fe40c = (int)(val_2 + (val_2 >> 0x1f & 3U)) >> 2;
  cVar1 = Util_GetRandomNumber(5);
  _DAT_00679ed0 = 1 << (cVar1 + 1U & 0x1f);
  Ai_SaveGameState();
  Mem_AllocOrFree_005016f9();
  Glue_Util_004cd715();
  DAT_006b1580 = 0;
  DAT_006a2838 = 1;
  UI_PrepareCombatViewport();
  Mem_AllocOrFree_00512220(1,1,DAT_006784f0);
  Pic_Subsystem_0044b8aa();
  g_CardSlot_PowerBonus = 0;
  return;
}

/*
 * Decompiled function: Rules_ProcessCombatDamageStep
 * Entry Point: 00472fae
 * Size: 459 bytes
 */


void Rules_ProcessCombatDamageStep(void)

{
  short len_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1) {
      if ((((&g_CardSlot_Flags)[match_count * 0x120 + slot_idx * 0x5b20] & 2) != 0) &&
         (*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) != -1)) {
        *(uint32_t *)(&g_CardSlot_Abilities2 + match_count * 0x120 + slot_idx * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities2 + match_count * 0x120 + slot_idx * 0x5b20) | 0xf000000;
        FUN_00473179(slot_idx,match_count,0x3c,0xffffffff);
      }
    }
  }
  Ai_Subsystem_004cced8();
  Ai_Subsystem_004ccca3();
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[slot_idx]; match_count = match_count + 1) {
      val_2 = FUN_00471c32(slot_idx,match_count);
      if (((val_2 != 0) &&
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 2) != 0))
         && (len_1 = *(short *)(&g_CardSlot_Power + match_count * 0x120 + slot_idx * 0x5b20),
            val_2 = FUN_00473179(slot_idx,match_count,0x33,0xffffffff), len_1 < val_2)) {
        FUN_00473179(slot_idx,match_count,0x32,0xffffffff);
      }
    }
  }
  return;
}

/*
 * Decompiled function: FUN_00473179
 * Entry Point: 00473179
 * Size: 2823 bytes
 */


uint32_t FUN_00473179(int x,int y,int width,int32_t arg_4)

{
  uint32_t uval_1;
  uint32_t uval_2;
  int32_t uval_3;
  char cVar4;
  int val_5;
  uint32_t color_idx;
  int target_idx;
  int card_idx;
  int match_count;
  uint32_t slot_idx;
  
  uval_3 = g_CardSlot_PowerBonus;
  DAT_00677340 = DAT_00677340 + 1;
  if (g_AiCombatScore_Blocker != 0) {
    Magic_PayManaCost();
  }
  g_OverworldPlayerCoordX = x;
  g_OverworldMapGrid = y;
  DAT_006a4f70 = *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20);
  DAT_006b2fe4 = (int)(char)(&g_MasterCardColorTable)[DAT_006a4f70 * 0x34];
  DAT_006b2d5c = arg_4;
  switch(width) {
  case 0x32:
    if (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 2) == 0) {
      slot_idx = (uint32_t)*(short *)(&DAT_0051aec2 + DAT_006a4f70 * 0x34);
    }
    else {
      slot_idx = (int)*(short *)(&DAT_0051aec2 + DAT_006a4f70 * 0x34) & 0xffffbfff;
    }
    slot_idx = slot_idx + (int)*(short *)(&g_CardSlot_PowerCounters + y * 0x120 + x * 0x5b20);
    if (((&DAT_006a5f6f)[y * 0x120 + x * 0x5b20] & 4) != 0) {
      *(uint32_t *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xfbffffff;
      goto LAB_004737a0;
    }
    g_ActivePalette = (uint32_t)*(short *)(&g_CardSlot_Counters + y * 0x120 + x * 0x5b20);
    break;
  case 0x33:
    if (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 2) == 0) {
      slot_idx = (uint32_t)*(short *)(&DAT_0051aec4 + DAT_006a4f70 * 0x34);
    }
    else {
      slot_idx = (int)*(short *)(&DAT_0051aec4 + DAT_006a4f70 * 0x34) & 0xffffbfff;
    }
    slot_idx = slot_idx + (int)*(short *)(&g_CardSlot_ToughnessCounters + y * 0x120 + x * 0x5b20);
    if (((&DAT_006a5f6f)[y * 0x120 + x * 0x5b20] & 2) != 0) {
      *(uint32_t *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xfdffffff;
      goto LAB_004737a0;
    }
    g_ActivePalette = (uint32_t)*(short *)(&DAT_006a5f46 + y * 0x120 + x * 0x5b20);
    break;
  case 0x34:
    uval_1 = *(uint32_t *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20);
    uval_2 = *(uint32_t *)(&DAT_0051aecc + DAT_006a4f70 * 0x34);
    slot_idx = uval_1 & 0x7000000 | uval_2;
    if ((uval_2 & 0x1ff81f) != 0) {
      color_idx = 0;
      for (target_idx = 0; target_idx < 5; target_idx = target_idx + 1) {
        if ((slot_idx & 1 << ((uint8_t)target_idx & 0x1f)) != 0) {
          cVar4 = FUN_0041d963(x,y,target_idx + 1);
          color_idx = color_idx | 1 << (cVar4 - 1U & 0x1f);
        }
        if ((slot_idx & 0x800 << ((uint8_t)target_idx & 0x1f)) != 0) {
          cVar4 = FUN_0041d9d2(x,y,target_idx + 1);
          color_idx = color_idx | 0x800 << (cVar4 - 1U & 0x1f);
        }
      }
      slot_idx = uval_1 & 0x7000000 | uval_2 & 0xffe007e0 | color_idx;
    }
    if (((&DAT_006a5f6f)[y * 0x120 + x * 0x5b20] & 8) != 0) {
      *(uint32_t *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
           *(uint32_t *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xf7ffffff;
      goto LAB_004737a0;
    }
    g_ActivePalette = *(uint32_t *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20);
    break;
  case 0x35:
    slot_idx = (uint32_t)*(short *)(&g_CardSlot_Power + y * 0x120 + x * 0x5b20);
    goto LAB_004737a0;
  case 0x36:
    slot_idx = (uint32_t)(char)(&g_MasterCardColorTable)[DAT_006a4f70 * 0x34];
    goto LAB_004737a0;
  default:
    slot_idx = 0;
LAB_004737a0:
    g_ActivePalette = slot_idx;
    if ((g_AiCombatScore_Blocker != 0) && (Magic_ScanCards(width), (g_PlayerHandCardCount & 0x10000) != 0)) {
      g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffeffff;
      *(uint32_t *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) = g_ActivePalette;
      g_PlayerHandCardCount = g_PlayerHandCardCount | 0x20000;
      Magic_ScanCards(width);
      g_PlayerHandCardCount = g_PlayerHandCardCount & 0xfffdffff;
    }
    if (width == 0x32) {
      if ((int)g_ActivePalette < 0) {
        g_ActivePalette = 0;
      }
      if (((&DAT_006a5f69)[y * 0x120 + x * 0x5b20] & 0x40) != 0) {
        g_ActivePalette = g_ActivePalette << 1;
      }
    }
    break;
  case 0x3c:
    if (((*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) < g_PendingSpellTargetSlot) ||
        (g_PendingSpellTargetSlot + 0x1d <= *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20))) &&
       (*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) != -1)) {
      slot_idx = *(uint32_t *)(&g_ActiveCardsInPlay + y * 0x120 + x * 0x5b20);
      if (((&DAT_006a5f6f)[y * 0x120 + x * 0x5b20] & 1) != 0) {
        *(int32_t *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) =
             *(int32_t *)(&g_ActiveCardsInPlay + y * 0x120 + x * 0x5b20);
        *(uint32_t *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
             *(uint32_t *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xfeffffff;
        (&DAT_006a604f)[y * 0x120 + x * 0x5b20] = 0;
        goto LAB_004737a0;
      }
      g_ActivePalette = *(uint32_t *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20);
    }
    else {
      g_ActivePalette = *(uint32_t *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20);
    }
  }
  uval_1 = g_ActivePalette;
  val_5 = FUN_00471c32(x,y);
  if (((val_5 != 0) && (width == 0x33)) &&
     ((((&g_MasterCardColorTable)[DAT_006a4f70 * 0x34] & 2) != 0 &&
      (((((int)uval_1 < 1 ||
         ((int)uval_1 <= (int)*(short *)(&g_CardSlot_Power + y * 0x120 + x * 0x5b20))) &&
        (g_PlayerManaPool == -1)) && ((g_PlayerHandCardCount & 0x204) == 0)))))) {
    Pic_Subsystem_0044867e(x,y,2);
    Rules_SendCardsToGraveyard();
  }
  if (g_AiCombatScore_Blocker != 0) {
    Magic_TapCardForMana();
  }
  if (width == 0x32) {
    *(short *)(&g_CardSlot_Counters + y * 0x120 + x * 0x5b20) = (short)uval_1;
  }
  if (width == 0x33) {
    *(short *)(&DAT_006a5f46 + y * 0x120 + x * 0x5b20) = (short)uval_1;
  }
  if (width == 0x34) {
    *(uint32_t *)(&g_CardSlot_Abilities2 + y * 0x120 + x * 0x5b20) = uval_1;
  }
  if (width != 0x3c) {
    g_CardSlot_PowerBonus = uval_3;
    return uval_1;
  }
  *(uint32_t *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) = uval_1;
  if (((&g_MasterCardFlagsTable)[uval_1 * 0x34] & 0x10) == 0) goto LAB_00473adb;
  val_5 = *(int *)(&g_MasterCardTypeTable + uval_1 * 0x34);
  if (val_5 < 0x12d) {
    if (val_5 == 300) {
      (&g_CardSlot_PlusOneCounters)[y * 0x120 + x * 0x5b20] = 1;
      goto LAB_00473adb;
    }
    if (val_5 == 0xf) {
      (&g_CardSlot_PlusOneCounters)[y * 0x120 + x * 0x5b20] = 0x3e;
      goto LAB_00473adb;
    }
  }
  else if ((val_5 == 0x13e) || (val_5 == 0x366)) goto LAB_00473adb;
  (&g_CardSlot_PlusOneCounters)[y * 0x120 + x * 0x5b20] = (&g_MasterCardColorTable)[uval_1 * 0x34];
LAB_00473adb:
  if ((((&g_CardSlot_Abilities1)[y * 0x120 + x * 0x5b20] & 0x40) != 0) &&
     (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] & 2)
      == 0)) {
    for (match_count = 0; match_count < 2; match_count = match_count + 1) {
      for (card_idx = 0; card_idx < (int)(&g_PlayerActiveCardCount)[match_count];
          card_idx = card_idx + 1) {
        if ((((*(int *)(&g_CardSlot_CardId + card_idx * 0x120 + match_count * 0x5b20) != -1) &&
             (((&g_CardSlot_Flags)[card_idx * 0x120 + match_count * 0x5b20] & 2) != 0)) &&
            ((char)(&g_CardSlot_Toughness)[card_idx * 0x120 + match_count * 0x5b20] == x)) &&
           (((*(int *)(&g_CardSlot_OriginalCardId + card_idx * 0x120 + match_count * 0x5b20) == y &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + card_idx * 0x120 + match_count * 0x5b20) * 0x34] & 4) != 0
             )) && (*(int *)(&DAT_006b3088 +
                            *(int *)(&g_MasterCardTypeTable +
                                    *(int *)(&g_CardSlot_CardId +
                                            card_idx * 0x120 + match_count * 0x5b20) * 0x34) * 0x98) ==
                    0x2d)))) {
          Pic_Subsystem_0044867e(match_count,card_idx,3);
        }
      }
    }
  }
  g_CardSlot_PowerBonus = uval_3;
  return uval_1;
}

/*
 * Decompiled function: Rules_CalculateManaCostReduction
 * Entry Point: 00473cc5
 * Size: 121 bytes
 */


int32_t Rules_CalculateManaCostReduction(uint8_t arg_1)

{
  int32_t uval_1;
  
  if ((arg_1 & 2) == 0) {
    if ((arg_1 & 4) == 0) {
      if ((arg_1 & 8) == 0) {
        if ((arg_1 & 0x10) == 0) {
          if ((arg_1 & 0x20) == 0) {
            uval_1 = 0;
          }
          else {
            uval_1 = 5;
          }
        }
        else {
          uval_1 = 4;
        }
      }
      else {
        uval_1 = 3;
      }
    }
    else {
      uval_1 = 2;
    }
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}

/*
 * Decompiled function: Mem_AllocOrFree_00473d7e
 * Entry Point: 00473d7e
 * Size: 26 bytes
 */


uint8_t * Mem_AllocOrFree_00473d7e(int player_id)

{
  return (&PTR_s_Colorless_00525760)[arg_1];
}

/*
 * Decompiled function: FUN_00473d98
 * Entry Point: 00473d98
 * Size: 209 bytes
 */


int FUN_00473d98(int player_id)

{
  int val_1;
  int card_idx;
  int match_count;
  
  card_idx = 0;
  for (match_count = 0; match_count < (int)(&g_PlayerActiveCardCount)[arg_1]; match_count = match_count + 1) {
    val_1 = *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + match_count * 0x120);
    if ((((val_1 != -1) && (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + match_count * 0x120] & 2) == 0)) &&
        (((&g_MasterCardColorTable)[val_1 * 0x34] & 1) != 0)) &&
       ((&g_MasterCardColorTable)[val_1 * 0x34] != '\0')) {
      card_idx = card_idx + 1;
    }
  }
  return card_idx;
}

/*
 * Decompiled function: Rules_ApplyContinuousDamage
 * Entry Point: 00473e69
 * Size: 157 bytes
 */


int32_t Rules_ApplyContinuousDamage(int player_id,int32_t arg_2,int event_type)

{
  int32_t uval_1;
  int32_t uval_2;
  
  Magic_PayManaCost();
  uval_2 = g_PlayerManaPool;
  g_ActivePalette = 0;
  g_OverworldPlayerCoordX = arg_1;
  g_OverworldMapGrid = arg_2;
  DAT_007006c8 = 1 - arg_1;
  DAT_006b2d5c = 0xffffffff;
  if ((arg_3 != 0x7d) && (arg_3 != 0x7e)) {
    g_PlayerManaPool = 0xffffffff;
  }
  Magic_ScanCards(arg_3);
  uval_1 = g_ActivePalette;
  g_OverworldPlayerCoordX = 0xffffffff;
  g_PlayerManaPool = uval_2;
  Magic_TapCardForMana();
  return uval_1;
}

/*
 * Decompiled function: FUN_00481491
 * Entry Point: 00481491
 * Size: 245 bytes
 */


int32_t FUN_00481491(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t match_count;
  int32_t slot_idx;
  
  slot_idx = 0;
  for (match_count = 0; match_count < arg_3; match_count = match_count + 1) {
    if (*(int *)(arg_2 + match_count * 4) != 0) {
      val_1 = FUN_0046bc92(*(HWND *)(arg_2 + match_count * 4));
      if (val_1 == arg_1) {
        FUN_00481491(*(int *)(arg_2 + match_count * 4),arg_2,arg_3);
        DestroyWindow(*(HWND *)(arg_2 + match_count * 4));
        *(int32_t *)(arg_2 + match_count * 4) = 0;
      }
    }
  }
  for (match_count = 0; match_count < arg_3; match_count = match_count + 1) {
    if (*(int *)(arg_2 + match_count * 4) == arg_1) {
      DestroyWindow(*(HWND *)(arg_2 + match_count * 4));
      *(int32_t *)(arg_2 + match_count * 4) = 0;
      slot_idx = 1;
    }
  }
  return slot_idx;
}

/*
 * Decompiled function: UI_LayoutAttackCards
 * Entry Point: 00481586
 * Size: 2708 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UI_LayoutAttackCards(HWND hwnd)

{
  int val_1;
  HBRUSH arg_3;
  int val_2;
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
  uint8_t local_5c [8];
  int local_54;
  LONG local_44;
  int local_40;
  LONG local_3c;
  int local_38;
  int local_34;
  int local_30;
  RECT local_2c;
  int color_idx;
  HWND target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  local_44 = GetWindowLongA(hwnd,0);
  local_3c = GetWindowLongA(hwnd,4);
  target_idx = GetDlgItem(hwnd,0);
  slot_idx = SendMessageA(target_idx,0xe1,0,0);
  Ai_Subsystem_004b74b1(&color_idx,&local_38);
  if ((((local_38 < 0x15) || (0x1d < local_38)) || (val_1 = Ai_Subsystem_004b7629(), val_1 == 0)) ||
     ((color_idx == 1 && (local_3c == 0)))) {
    ShowWindow(DAT_006a283c,0);
    ShowWindow(DAT_006a284c,5);
    ShowWindow(hwnd,0);
    ShowWindow(DAT_00539540,0);
    UpdateWindow(g_AiSelectedActionCode);
    SendMessageA(target_idx,0x468,0,0);
    SendMessageA(g_AiDecisionMatrix_Row,0x40c,0,0);
    SendMessageA(g_TurnPriorityState,0x401,0,0);
    SendMessageA(g_AiSelectedActionCode,0x401,0,0);
    DAT_006b2ff4 = 5;
    _DAT_006b2ff0 = 5;
    _DAT_007006c0 = g_PlayerAmuletGems / 2;
    DAT_007006c4 = _DAT_007006c0;
  }
  else {
    arg_3 = GetStockObject(1);
    FUN_004f5048(s_LayoutAttackCards_00526da4,0xff00ff,arg_3);
    DAT_00539554 = 10;
    DAT_00539584 = 10;
    _DAT_00539560 = (g_PlayerGoldCoins * 0xf) / 100;
    _DAT_00539538 = 5;
    local_34 = 2;
    if (DAT_00539544 == (HANDLE)0x0) {
      local_40 = GetSystemMetrics(3);
      local_40 = local_40 * 2;
    }
    else {
      GetObjectA(DAT_00539544,0x18,local_5c);
      val_1 = GetSystemMetrics(3);
      if (val_1 * 2 < local_54 / 2) {
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
        val_1 = FUN_0046bc92(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 4 + local_44));
        if ((val_1 == 0) &&
           (local_6c = FUN_004833e9(hwnd,*(int *)(local_68 * 4 + local_64 * 0x19c + 4 + local_44)),
           local_70 < local_6c)) {
          local_70 = local_6c;
        }
      }
      for (local_68 = 0; local_68 < *(int *)(local_44 + 0x198 + local_64 * 0x19c);
          local_68 = local_68 + 1) {
        val_1 = FUN_0046bc92(*(HWND *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + local_44));
        if ((val_1 == 0) &&
           (local_6c = FUN_004833e9(hwnd,*(int *)(local_68 * 4 + local_64 * 0x19c + 0xd0 + local_44)
                                   ), local_60 < local_6c)) {
          local_60 = local_6c;
        }
      }
    }
    if (color_idx == 0) {
      local_30 = local_70;
      player_idx = local_60;
    }
    else {
      player_idx = local_70;
      local_30 = local_60;
    }
    val_1 = local_34;
    if (local_34 <= player_idx) {
      val_1 = player_idx;
    }
    DAT_00539570 = val_1 * DAT_006ff67c + DAT_00539584;
    val_1 = local_34;
    if (local_34 <= local_30) {
      val_1 = local_30;
    }
    DAT_00539574 = val_1 * DAT_006ff67c + DAT_00539570 + local_40 + _DAT_00539538 * 2 + g_PlayerAmuletGems
    ;
    match_count = g_PlayerGoldCoins / 3;
    card_idx = g_PlayerGoldCoins / 3;
    SetWindowPos(target_idx,(HWND)0x0,0,DAT_00539570 + _DAT_00539538 + g_PlayerAmuletGems,0,0,5);
    local_80 = DAT_00539554 - slot_idx;
    val_1 = local_34;
    if (local_34 <= player_idx) {
      val_1 = player_idx;
    }
    local_2c.top = DAT_00539570 - val_1 * DAT_006ff67c;
    local_2c.bottom = g_PlayerAmuletGems + DAT_00539574;
    if (color_idx == 0) {
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
        val_1 = FUN_0046bc92(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 4 + local_44));
        if (val_1 == 0) {
          local_78 = local_90 * match_count + local_80;
          MoveWindow(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 4 + local_44),local_78,local_88,
                     g_PlayerGoldCoins,g_PlayerAmuletGems,1);
          local_90 = local_90 + 1;
          if (local_2c.right < local_78 + g_PlayerGoldCoins) {
            local_2c.right = local_78 + g_PlayerGoldCoins;
          }
        }
      }
      local_90 = 0;
      for (local_8c = 0; local_8c < *(int *)(local_44 + 0x198 + local_84 * 0x19c);
          local_8c = local_8c + 1) {
        val_1 = FUN_0046bc92(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 0xd0 + local_44));
        if (val_1 == 0) {
          local_74 = local_90 * card_idx + local_80;
          MoveWindow(*(HWND *)(local_8c * 4 + local_84 * 0x19c + 0xd0 + local_44),local_74,local_7c,
                     g_PlayerGoldCoins,g_PlayerAmuletGems,1);
          local_90 = local_90 + 1;
          if (local_2c.right < local_74 + g_PlayerGoldCoins) {
            local_2c.right = local_74 + g_PlayerGoldCoins;
          }
        }
      }
      val_1 = local_74;
      if (local_74 <= local_78) {
        val_1 = local_78;
      }
      local_80 = val_1 + _DAT_00539560 + g_PlayerGoldCoins;
    }
    val_1 = g_PlayerGoldCoins / 3;
    local_2c.left = local_2c.left - DAT_00539554;
    local_2c.right = local_2c.right + DAT_00539554;
    local_2c.top = local_2c.top - DAT_00539584;
    local_2c.bottom = local_2c.bottom + DAT_00539584;
    val_2 = DAT_00539554 * 2 + g_PlayerGoldCoins;
    if (local_2c.right - local_2c.left < val_2) {
      local_2c.right = local_2c.left + val_2;
    }
    dwStyle = GetWindowLongA(hwnd,-0x10);
    CopyRect(&local_b4,&local_2c);
    AdjustWindowRect(&local_b4,dwStyle,0);
    GetWindowRect(g_TurnPriorityState,&local_a4);
    val_2 = local_a4.top - (local_b4.bottom - local_b4.top);
    if (val_2 < 6) {
      val_2 = 5;
    }
    nWidth = (local_a4.right - local_a4.left) - val_1;
    if (local_b4.right - local_b4.left <= nWidth) {
      nWidth = local_b4.right - local_b4.left;
    }
    MoveWindow(DAT_006b2e24,local_a4.left,val_2,val_1,local_b4.bottom - local_b4.top,1);
    MoveWindow(hwnd,val_1 + local_a4.left,val_2,nWidth,local_b4.bottom - local_b4.top,1);
    GetClientRect(hwnd,&local_b4);
    SetWindowPos(target_idx,(HWND)0x0,0,0,local_b4.right,local_40,6);
    UpdateWindow(g_AiSelectedActionCode);
    UpdateWindow(g_TurnPriorityState);
    GetClientRect(hwnd,&local_b4);
    if (local_b4.right < local_2c.right - local_2c.left) {
      val_1 = (local_2c.right - local_2c.left) - local_b4.right;
      SendMessageA(target_idx,0xe2,0,val_1);
      SendMessageA(target_idx,0x468,1,0);
      if (slot_idx < 0) {
        slot_idx = 0;
      }
      if (val_1 < slot_idx) {
        slot_idx = val_1;
      }
      SendMessageA(hwnd,0x114,CONCAT31((int3)((uint32_t)(slot_idx << 0x10) >> 8),4),(LPARAM)target_idx);
    }
    else {
      SendMessageA(target_idx,0x468,0,0);
      slot_idx = 0;
      SendMessageA(hwnd,0x114,4,(LPARAM)target_idx);
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
    UpdateWindow(g_AiSelectedActionCode);
  }
  return;
}

/*
 * Decompiled function: FUN_0048201a
 * Entry Point: 0048201a
 * Size: 578 bytes
 */


void FUN_0048201a(HWND hwnd,LPRECT arg2)

{
  LONG LVar1;
  LONG LVar2;
  int local_30;
  int local_2c;
  int local_28;
  int loop_idx;
  int color_idx;
  int target_idx;
  tagRECT player_idx;
  
  LVar1 = GetWindowLongA(hwnd,0);
  LVar2 = GetWindowLongA(hwnd,4);
  if ((hwnd != (HWND)0x0) && (arg2 != (LPRECT)0x0)) {
    local_30 = 5000;
    local_2c = -5000;
    local_28 = 5000;
    loop_idx = 0;
    for (target_idx = 0; target_idx < LVar2; target_idx = target_idx + 1) {
      for (color_idx = 0; color_idx < *(int *)(LVar1 + 0xcc + target_idx * 0x19c);
          color_idx = color_idx + 1) {
        GetWindowRect(*(HWND *)(color_idx * 4 + target_idx * 0x19c + 4 + LVar1),&player_idx);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&player_idx,2);
        if (player_idx.left < local_30) {
          local_30 = player_idx.left;
        }
        if (local_2c < player_idx.right) {
          local_2c = player_idx.right;
        }
        if (player_idx.top < local_28) {
          local_28 = player_idx.top;
        }
        if (loop_idx < player_idx.bottom) {
          loop_idx = player_idx.bottom;
        }
      }
      for (color_idx = 0; color_idx < *(int *)(LVar1 + 0x198 + target_idx * 0x19c);
          color_idx = color_idx + 1) {
        GetWindowRect(*(HWND *)(color_idx * 4 + target_idx * 0x19c + 0xd0 + LVar1),&player_idx);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&player_idx,2);
        if (player_idx.left < local_30) {
          local_30 = player_idx.left;
        }
        if (local_2c < player_idx.right) {
          local_2c = player_idx.right;
        }
        if (player_idx.top < local_28) {
          local_28 = player_idx.top;
        }
        if (loop_idx < player_idx.bottom) {
          loop_idx = player_idx.bottom;
        }
      }
    }
    if (local_30 == 5000) {
      SetRect(arg2,0,0,0,0);
    }
    else {
      SetRect(arg2,local_30,local_28,local_2c,loop_idx);
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0048225c
 * Entry Point: 0048225c
 * Size: 91 bytes
 */


bool FUN_0048225c(int arg1,int arg2)

{
  int val_1;
  uint32_t uval_2;
  
  val_1 = FUN_004726c5(arg1,arg2);
  uval_2 = Ai_Subsystem_004b6288(arg1,arg2);
  return (uval_2 & 0x40) != 0 && val_1 != 0;
}

/*
 * Decompiled function: FUN_00482d6f
 * Entry Point: 00482d6f
 * Size: 103 bytes
 */


void FUN_00482d6f(HWND hwnd)

{
  char local_6c [100];
  int slot_idx;
  
  Ai_Subsystem_004b74b1(&slot_idx,(int32_t *)0x0);
  if (slot_idx == 0) {
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


int FUN_00483139(HWND hwnd,int *arg_2,int32_t *arg_3,int32_t *arg_4,int32_t *arg_5)

{
  LONG LVar1;
  LONG LVar2;
  int val_3;
  int32_t loop_idx;
  int32_t target_idx;
  int32_t player_idx;
  int32_t card_idx;
  int32_t match_count;
  int32_t slot_idx;
  
  if ((hwnd == (HWND)0x0) || (arg_2 == (int *)0x0)) {
    slot_idx = 0;
  }
  else {
    LVar1 = GetWindowLongA(hwnd,0);
    LVar2 = GetWindowLongA(hwnd,4);
    slot_idx = 0;
    for (player_idx = 0; player_idx < LVar2; player_idx = player_idx + 1) {
      target_idx = 0;
      while ((target_idx < *(int *)(LVar1 + 0xcc + player_idx * 0x19c) && (slot_idx == 0))) {
        val_3 = FUN_0046bb29(*(HWND *)(target_idx * 4 + player_idx * 0x19c + 4 + LVar1),arg_2);
        if (val_3 != 0) {
          slot_idx = 1;
          loop_idx = FUN_0046bc2f(*(HWND *)(target_idx * 4 + player_idx * 0x19c + 4 + LVar1));
          card_idx = *(int32_t *)(target_idx * 4 + player_idx * 0x19c + 4 + LVar1);
          match_count = 1;
        }
        target_idx = target_idx + 1;
      }
      target_idx = 0;
      while ((target_idx < *(int *)(LVar1 + 0x198 + player_idx * 0x19c) && (slot_idx == 0))) {
        val_3 = FUN_0046bb29(*(HWND *)(target_idx * 4 + player_idx * 0x19c + 0xd0 + LVar1),arg_2);
        if (val_3 != 0) {
          slot_idx = 1;
          loop_idx = FUN_0046bc2f(*(HWND *)(target_idx * 4 + player_idx * 0x19c + 0xd0 + LVar1));
          card_idx = *(int32_t *)(target_idx * 4 + player_idx * 0x19c + 0xd0 + LVar1);
          match_count = 0;
        }
        target_idx = target_idx + 1;
      }
    }
  }
  if (arg_3 != (int32_t *)0x0) {
    if (slot_idx == 0) {
      *arg_3 = 0xffffffff;
    }
    else {
      *arg_3 = loop_idx;
    }
  }
  if (arg_4 != (int32_t *)0x0) {
    if (slot_idx == 0) {
      *arg_4 = 0;
    }
    else {
      *arg_4 = card_idx;
    }
  }
  if (arg_5 != (int32_t *)0x0) {
    if (slot_idx == 0) {
      *arg_5 = 0;
    }
    else {
      *arg_5 = match_count;
    }
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_004833e9
 * Entry Point: 004833e9
 * Size: 417 bytes
 */


int FUN_004833e9(HWND hwnd,int arg2)

{
  LONG LVar1;
  LONG LVar2;
  int val_3;
  int32_t card_idx;
  int32_t match_count;
  int32_t slot_idx;
  
  LVar1 = GetWindowLongA(hwnd,0);
  LVar2 = GetWindowLongA(hwnd,4);
  card_idx = 0;
  for (slot_idx = 0; slot_idx < LVar2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < *(int *)(LVar1 + 0xcc + slot_idx * 0x19c); match_count = match_count + 1) {
      val_3 = FUN_0046bc92(*(HWND *)(match_count * 4 + slot_idx * 0x19c + 4 + LVar1));
      if (val_3 == arg2) {
        val_3 = FUN_004833e9(hwnd,*(int *)(slot_idx * 0x19c + match_count * 4 + 4 + LVar1));
        card_idx = card_idx + 1 + val_3;
      }
    }
    for (match_count = 0; match_count < *(int *)(LVar1 + 0x198 + slot_idx * 0x19c); match_count = match_count + 1) {
      val_3 = FUN_0046bc92(*(HWND *)(match_count * 4 + slot_idx * 0x19c + 0xd0 + LVar1));
      if (val_3 == arg2) {
        val_3 = FUN_004833e9(hwnd,*(int *)(slot_idx * 0x19c + match_count * 4 + 0xd0 + LVar1));
        card_idx = card_idx + 1 + val_3;
      }
    }
  }
  return card_idx;
}

/*
 * Decompiled function: FUN_00483590
 * Entry Point: 00483590
 * Size: 204 bytes
 */


void FUN_00483590(char *filepath,int card_slot,int event_type)

{
  int y;
  int width;
  int val_1;
  int arg_4;
  
  y = arg_2 * 2;
  width = arg_3 * 2;
  val_1 = FUN_0040c465(str_1);
  arg_4 = val_1 + 0x10;
  Surface_FillRect((int *)g_DisplaySurfaceScreen,(y - arg_4 / 2) + -1,width + -5,val_1 + 0x11,0x13,
                   0xff);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,y - arg_4 / 2,width + -4,val_1 + 0x11,0x12,0xf4);
  Surface_FillRect((int *)g_DisplaySurfaceScreen,y - arg_4 / 2,width + -4,arg_4,0x11,0xf6);
  UI_DrawCombatString(str_1,y,width,0xe3);
  return;
}

/*
 * Decompiled function: FUN_0048365c
 * Entry Point: 0048365c
 * Size: 64 bytes
 */


int32_t FUN_0048365c(void)

{
  int32_t uval_1;
  
  if (g_IsAiThinking == 1) {
    uval_1 = 1;
  }
  else if (g_AiCombatScore_Blocker == 0) {
    uval_1 = 0;
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}

/*
 * Decompiled function: Pic_Load_combat2_0048369c
 * Entry Point: 0048369c
 * Size: 3951 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pic_Load_combat2_0048369c(int arg1,int arg2)

{
  int val_1;
  char *char_ptr_2;
  int val_3;
  int val_4;
  int local_3c;
  int local_38;
  int local_34;
  int local_24;
  uint32_t color_idx;
  int target_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (g_IsAiThinking != 1) {
    UI_PrepareCombatViewport();
    *(int32_t *)g_DisplaySurfaceScreen = 1;
    _DAT_00539598 = 0;
    val_1 = 1 - arg1;
    DAT_0063ee78 = 0;
    for (target_idx = 0; target_idx < 2; target_idx = target_idx + 1) {
      if (target_idx == g_CurrentTurnPhase) {
        local_3c = 0x174;
      }
      else {
        local_3c = 0xac;
      }
      for (local_34 = 0; local_34 < 7; local_34 = local_34 + 1) {
        for (color_idx = 0; (int)color_idx < *(int *)(&g_AiLookaheadDepth + local_34 * 4 + target_idx * 0x20);
            color_idx = color_idx + 1) {
          Surface_FillRect((int *)g_DisplaySurfaceScreen,0x68,local_3c + 3,0x14,0xe,
                           (-(uint32_t)(target_idx == 0) & 0x23) + 0xdc);
          Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,0x66,local_3c,
                            *(int *)(&DAT_0067f390 + local_34 * 4));
          local_3c = local_3c + -0x10;
        }
      }
    }
    local_3c = 0x86;
    local_38 = 0x82;
    slot_idx = 0x41;
    card_idx = 0x82;
    for (match_count = 0; match_count <= *(int *)(&DAT_006ff4b8 + arg1 * 4); match_count = match_count + 1) {
      color_idx = (&g_PlayerActiveCardCount)[arg1];
      do {
        color_idx = color_idx - 1;
        val_3 = slot_idx;
        if ((int)color_idx < 0) goto LAB_004837f3;
      } while ((*(int *)(&g_CardSlot_CardId + color_idx * 0x120 + arg1 * 0x5b20) == -1) ||
              (*(int *)(&g_CardSlot_DisplayIndex + color_idx * 0x120 + arg1 * 0x5b20) != match_count));
      if (((&g_CardSlot_Flags)[color_idx * 0x120 + arg1 * 0x5b20] & 2) == 0) {
        Mem_AllocOrFree_00484ebb(arg1,color_idx,(color_idx & 0xf) + 0xff,local_3c);
        local_3c = local_3c + -0x12;
      }
      else if ((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + color_idx * 0x120 + arg1 * 0x5b20) * 0x34] == '\x01') {
        local_34 = 1;
        for (target_idx = 0; target_idx < 2; target_idx = target_idx + 1) {
          for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[target_idx];
              local_24 = local_24 + 1) {
            if (((*(uint32_t *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + target_idx * 0x5b20) ==
                  color_idx) &&
                ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + target_idx * 0x5b20] == arg1)) &&
               (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + target_idx * 0x5b20) != -1)) {
              Mem_AllocOrFree_00484ebb
                        (target_idx,local_24,(int)(8 / (longlong)local_34) + 1,local_38 + 4);
              local_34 = local_34 + 1;
            }
          }
        }
        Mem_AllocOrFree_00484ebb(arg1,color_idx,(color_idx & 7) + 1,local_38);
        local_38 = local_38 + -8;
      }
      else if (*(int *)(&g_CardSlot_OriginalCardId + color_idx * 0x120 + arg1 * 0x5b20) == -1) {
        local_34 = 1;
        for (target_idx = 0; target_idx < 2; target_idx = target_idx + 1) {
          for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[target_idx];
              local_24 = local_24 + 1) {
            if (((*(uint32_t *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + target_idx * 0x5b20) ==
                  color_idx) &&
                ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + target_idx * 0x5b20] == arg1)) &&
               (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + target_idx * 0x5b20) != -1)) {
              Mem_AllocOrFree_00484ebb
                        (target_idx,local_24,slot_idx + (int)(4 / (longlong)local_34),
                         card_idx + (int)(8 / (longlong)local_34));
              local_34 = local_34 + 1;
            }
          }
        }
        Mem_AllocOrFree_00484ebb(arg1,color_idx,slot_idx,card_idx);
        card_idx = card_idx + -6;
        val_3 = slot_idx + 0x33;
        if (0xe0 < slot_idx + 0x33) {
          val_3 = slot_idx + -0x62;
        }
      }
LAB_004837f3:
      slot_idx = val_3;
    }
    local_38 = 0x2a;
    slot_idx = 0x41;
    card_idx = 0x2a;
    for (match_count = 0; match_count <= *(int *)(&DAT_006ff4b8 + val_1 * 4); match_count = match_count + 1) {
      color_idx = (&g_PlayerActiveCardCount)[val_1];
      val_3 = slot_idx;
      while (slot_idx = val_3, color_idx = color_idx - 1, -1 < (int)color_idx) {
        val_3 = slot_idx;
        if (((*(int *)(&g_CardSlot_CardId + color_idx * 0x120 + val_1 * 0x5b20) != -1) &&
            (*(int *)(&g_CardSlot_DisplayIndex + color_idx * 0x120 + val_1 * 0x5b20) == match_count)) &&
           (((&g_CardSlot_Flags)[color_idx * 0x120 + val_1 * 0x5b20] & 2) != 0)) {
          if ((&g_MasterCardColorTable)
              [*(int *)(&g_CardSlot_CardId + color_idx * 0x120 + val_1 * 0x5b20) * 0x34] == '\x01') {
            local_34 = 1;
            for (target_idx = 0; target_idx < 2; target_idx = target_idx + 1) {
              for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[target_idx];
                  local_24 = local_24 + 1) {
                if (((*(uint32_t *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + target_idx * 0x5b20)
                      == color_idx) &&
                    ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + target_idx * 0x5b20] == val_1))
                   && (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + target_idx * 0x5b20) != -1)) {
                  Mem_AllocOrFree_00484ebb
                            (target_idx,local_24,(int)(8 / (longlong)local_34) + 1,local_38 + 4);
                  local_34 = local_34 + 1;
                }
              }
            }
            Mem_AllocOrFree_00484ebb(val_1,color_idx,(color_idx & 7) + 1,local_38);
            local_38 = local_38 + -8;
          }
          else if (*(int *)(&g_CardSlot_OriginalCardId + color_idx * 0x120 + val_1 * 0x5b20) == -1) {
            local_34 = 1;
            for (target_idx = 0; target_idx < 2; target_idx = target_idx + 1) {
              for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[target_idx];
                  local_24 = local_24 + 1) {
                if (((*(uint32_t *)(&g_CardSlot_OriginalCardId + local_24 * 0x120 + target_idx * 0x5b20)
                      == color_idx) &&
                    ((char)(&g_CardSlot_Toughness)[local_24 * 0x120 + target_idx * 0x5b20] == val_1))
                   && (*(int *)(&g_CardSlot_CardId + local_24 * 0x120 + target_idx * 0x5b20) != -1)) {
                  Mem_AllocOrFree_00484ebb
                            (target_idx,local_24,slot_idx + (int)(4 / (longlong)local_34),
                             card_idx + (int)(8 / (longlong)local_34));
                  local_34 = local_34 + 1;
                }
              }
            }
            Mem_AllocOrFree_00484ebb(val_1,color_idx,slot_idx,card_idx);
            card_idx = card_idx + -6;
            val_3 = slot_idx + 0x33;
            if (0xe0 < slot_idx + 0x33) {
              val_3 = slot_idx + -0x62;
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
    UI_DrawCombatString(&g_OverworldWorldState,0x248,4,(-(uint32_t)(g_DefendingPlayer == 0) & 0x23) + 0xdc);
    if (g_GlobalEnchantmentCardId == -1) {
      FUN_0040c274(&DAT_00701830,4,4,0);
    }
    else {
      FUN_0040c274(s_Swamp_0051aea9 + g_GlobalEnchantmentCardId * 0x34,4,4,0xff);
    }
    g_OverworldWorldState = 0;
    char_ptr_2 = _itoa(DAT_006b300c + g_PendingSpellResolutionFlag,&DAT_005395a0,10);
    strcat(&g_OverworldWorldState,char_ptr_2);
    strcat(&g_OverworldWorldState,s_cards_00526f18);
    FUN_0040c274(&g_OverworldWorldState,4,0x12,0xff);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0xfe,400,0x84,0x20,0xff);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0x100,0x192,0x80,0x1e,3);
    FUN_0040c421(s_Our_Hero_00526f20,(int)g_AiManaColorCost_Red / 2,0x194,0xff);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0xfe,0,0x84,0x22,0);
    Surface_FillRect((int *)g_DisplaySurfaceScreen,0x100,0,0x80,0x20,0xd8);
    FUN_0040c421(&DAT_00695e10,(int)g_AiManaColorCost_Red / 2,0x12,0xdc);
    val_3 = FUN_0040a305((&g_PlayerCreatureCount)[arg1],0x19,100);
    val_3 = (int)(400 / (longlong)val_3);
    for (color_idx = 0; (int)color_idx < (int)(&g_PlayerCreatureCount)[arg1]; color_idx = color_idx + 1)
    {
      Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,
                        (color_idx * val_3 + (int)g_AiManaColorCost_Red / 2) -
                        ((&g_PlayerCreatureCount)[arg1] * val_3) / 2,0x1a0,DAT_0067f3a8);
    }
    strcpy(&g_OverworldWorldState,&DAT_00526f2c);
    val_4 = 10;
    char_ptr_2 = &DAT_005395a0;
    val_3 = FUN_0040a305((&g_PlayerCreatureCount)[arg1],0,99);
    char_ptr_2 = _itoa(val_3,char_ptr_2,val_4);
    strcat(&g_OverworldWorldState,char_ptr_2);
    if ((&DAT_00696870)[arg1] != 0) {
      strcat(&g_OverworldWorldState,&DAT_00526f30);
      char_ptr_2 = _itoa((&DAT_00696870)[arg1],&DAT_005395a0,10);
      strcat(&g_OverworldWorldState,char_ptr_2);
      strcat(&g_OverworldWorldState,&DAT_00526f34);
    }
    strcat(&g_OverworldWorldState,&DAT_00526f38);
    UI_DrawCombatString(&g_OverworldWorldState,(int)g_AiManaColorCost_Red / 2,0x1a0,0);
    val_3 = FUN_0040a305((&g_PlayerCreatureCount)[val_1],0x19,100);
    val_3 = (int)(400 / (longlong)val_3);
    for (color_idx = 0; (int)color_idx < (int)(&g_PlayerCreatureCount)[val_1]; color_idx = color_idx + 1
        ) {
      Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,
                        (color_idx * val_3 + (int)g_AiManaColorCost_Red / 2) -
                        ((&g_PlayerCreatureCount)[val_1] * val_3) / 2,4,DAT_0067f3ac);
    }
    strcpy(&g_OverworldWorldState,&DAT_00526f3c);
    val_4 = 10;
    char_ptr_2 = &DAT_005395a0;
    val_3 = FUN_0040a305((&g_PlayerCreatureCount)[val_1],0,99);
    char_ptr_2 = _itoa(val_3,char_ptr_2,val_4);
    strcat(&g_OverworldWorldState,char_ptr_2);
    if ((&DAT_00696870)[val_1] != 0) {
      strcat(&g_OverworldWorldState,&DAT_00526f40);
      char_ptr_2 = _itoa((&DAT_00696870)[val_1],&DAT_005395a0,10);
      strcat(&g_OverworldWorldState,char_ptr_2);
      strcat(&g_OverworldWorldState,&DAT_00526f44);
    }
    strcat(&g_OverworldWorldState,&DAT_00526f48);
    UI_DrawCombatString(&g_OverworldWorldState,(int)g_AiManaColorCost_Red / 2,4,0xff);
    Pic_Subsystem_00452708(&DAT_005395b0);
    if (g_DefendingPlayer == g_CurrentTurnPhase) {
      if (g_ScWillyScore < 0x15) {
        strcpy(&g_OverworldWorldState,s_ATTACK_00526f4c + ((DAT_0063ee78 != 0) - 1 & 8));
      }
      else {
        strcpy(&g_OverworldWorldState,s_CHARGE__00526f5c + ((0 < g_ActiveBattlefieldFlag) - 1 & 8));
        if (0x1d < g_ScWillyScore) {
          strcpy(&g_OverworldWorldState,&DAT_00526f6c);
        }
      }
      if (((uint8_t)g_PlayerHandCardCount & 0x80) != 0) {
        FUN_00483590(&g_OverworldWorldState,0x127,200);
      }
      if (g_ActivePlayer == -1) {
        FUN_00483590(s_Cancel_00526f74,0x10,200);
      }
      if (g_ActivePlayer != -1) {
        FUN_00483590(s_Concede_00526f7c,0x18,200);
      }
    }
    if (arg2 == 0) {
      *(int32_t *)g_DisplaySurfaceScreen = 0;
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
                   (int *)g_DisplaySurfaceScreen,0,0);
    }
    else {
      FUN_0050d520(1);
      *(int32_t *)g_DisplaySurfaceScreen = 0;
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green,
                   (int *)g_DisplaySurfaceScreen,0,0);
      FUN_0050d4e0(0);
    }
    Mem_AllocOrFree_00510e20(1,s_combat2_pic_00526f84);
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x140,200,
                       (int *)g_DisplaySurfaceBackBuffer,0,0,g_AiManaColorCost_Red,g_AiManaColorCost_Green);
    Pic_Subsystem_0044b8aa();
  }
  return;
}

/*
 * Decompiled function: FUN_00484668
 * Entry Point: 00484668
 * Size: 41 bytes
 */


void FUN_00484668(char *filepath)

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


void FUN_00484691(uint8_t arg1,int arg2)

{
  int match_count;
  
  for (match_count = 0; match_count < 500; match_count = match_count + 1) {
    if ((*(int *)(&deck + match_count * 4) != -1) &&
       ((1 << (arg1 & 0x1f) &
        (int)(char)(&g_MasterCardColorTable)[(*(uint32_t *)(&deck + match_count * 4) & 0xfff) * 0x34]) != 0)) {
      if (arg2 == 0) {
        *(uint32_t *)(&deck + match_count * 4) = *(uint32_t *)(&deck + match_count * 4) | 0x4000;
      }
      else {
        *(uint32_t *)(&deck + match_count * 4) = *(uint32_t *)(&deck + match_count * 4) & 0xffffbfff;
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


void Sprite_Load_dungbutt_00484738(int player_id,int32_t arg_2,char *str_3)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  void *arg_6;
  int32_t arg_4;
  char local_1fc [100];
  int32_t local_198;
  void *local_194 [100];
  
  if (g_IsAiThinking != 1) {
    UI_PrepareCombatViewport();
    strcpy(local_1fc,str_3);
    Sprite_LoadAll(local_194,s_dungbutt_spr_00526f90);
    arg_6 = local_194[0];
    val_1 = Ai_Util_004c3ba3(0x10f);
    val_1 = val_1 / 2;
    val_2 = Ai_Util_004c3ba3(0xc5);
    val_2 = val_2 / 2;
    val_3 = Ai_Util_004c3ba3(0x34);
    val_3 = val_3 / 2;
    val_4 = Ai_Util_004c3ba3(0xdc);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,val_4 / 2,val_3,val_2,val_1,(int)arg_6);
    FUN_0050b3de(arg_1,0x7a,0x29,0x4b,0x70,1,&DAT_00526fa0);
    Mem_AllocOrFree_0050fc50(local_194[0]);
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
    local_198 = FUN_0040c465(local_1fc);
    arg_4 = 0;
    val_1 = Ai_Util_004c3bc4(0x52);
    val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    UI_DrawCombatString(local_1fc,g_AiManaColorCost_Red / 2,(val_1 - val_2) + -2,arg_4);
    val_1 = Ai_Util_004c3bc4(0x52);
    val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    UI_DrawCombatString(local_1fc,g_AiManaColorCost_Red / 2,(val_1 - val_2) + -3,arg_2);
    Pic_Subsystem_0044b8aa();
  }
  return;
}

/*
 * Decompiled function: FUN_00484c45
 * Entry Point: 00484c45
 * Size: 263 bytes
 */


void FUN_00484c45(int32_t arg_1)

{
  switch(arg_1) {
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


void FUN_00484df9(int32_t arg1,int32_t arg2)

{
  if (g_IsAiThinking != 1) {
    Mem_AllocOrFree_00484ebb(arg1,arg2,0xba,0x33);
  }
  return;
}

/*
 * Decompiled function: FUN_00484e2d
 * Entry Point: 00484e2d
 * Size: 142 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00484e2d(int player_id,int32_t arg_2,int32_t arg_3,int arg_4,int32_t arg_5)

{
  _DAT_006ab814 = arg_1;
  if (arg_4 == 0) {
    _DAT_006ab81c = 0;
  }
  else {
    _DAT_006ab81c = 0x10;
  }
  _DAT_006ab838 = arg_5;
  DAT_006ab82e = 0xff;
  DAT_006ab82c = (&g_MasterCardColorTable)[arg_1 * 0x34];
  _DAT_006ab84c = 0x8000000;
  _DAT_006ab834 = 0;
  Mem_AllocOrFree_00484ebb(0,0x4f,arg_2,arg_3);
  _DAT_006ab814 = 0xffffffff;
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_00484ebb
 * Entry Point: 00484ebb
 * Size: 18 bytes
 */


int32_t Mem_AllocOrFree_00484ebb(void)

{
  return 0;
}

/*
 * Decompiled function: FUN_00484ecd
 * Entry Point: 00484ecd
 * Size: 292 bytes
 */


int FUN_00484ecd(int x,int y,int width,int32_t arg_4)

{
  int val_1;
  int slot_idx;
  
  if (g_AiCombatScore_Blocker == 0) {
    val_1 = *(int *)(&g_CardSlot_CardId + y * 0x120 + x * 0x5b20);
    switch(width) {
    case 0x32:
      slot_idx = (int)*(short *)(&DAT_0051aec2 + val_1 * 0x34);
      break;
    case 0x33:
      slot_idx = (int)*(short *)(&DAT_0051aec4 + val_1 * 0x34);
      break;
    case 0x34:
      slot_idx = *(int *)(&DAT_0051aecc + val_1 * 0x34);
      break;
    case 0x35:
      slot_idx = (int)*(short *)(&g_CardSlot_Power + y * 0x120 + x * 0x5b20);
      break;
    case 0x36:
      slot_idx = (int)(char)(&g_MasterCardColorTable)[val_1 * 0x34];
      break;
    default:
      slot_idx = 0;
    }
  }
  else {
    slot_idx = FUN_00473179(x,y,width,arg_4);
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_00485005
 * Entry Point: 00485005
 * Size: 57 bytes
 */


bool FUN_00485005(int player_id)

{
  return ((&DAT_0051aed6)[arg_1 * 0x34] & 0xc1) != 0;
}

/*
 * Decompiled function: FUN_00485040
 * Entry Point: 00485040
 * Size: 64 bytes
 */


int32_t FUN_00485040(int32_t arg1,int32_t arg2)

{
  return arg2;
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


void FUN_00485234(int player_id)

{
  int val_1;
  int val_2;
  char *mode_str;
  int card_idx;
  int match_count;
  
  g_OverworldWorldState = 0;
  for (match_count = 0; match_count < 0x50; match_count = match_count + 1) {
    val_1 = *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + match_count * 0x120);
    if ((val_1 != -1) && (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + match_count * 0x120] & 2) == 0)) {
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + val_1 * 0x34);
      strcat(&g_OverworldWorldState,&DAT_005270b0);
      for (card_idx = 0; card_idx < (char)(&g_MasterCardSubTypeTable2)[val_1 * 0x34]; card_idx = card_idx + 1) {
        val_2 = Rules_CalculateManaCostReduction((&g_MasterCardColorTable)[val_1 * 0x34]);
        strcat(&g_OverworldWorldState,(&PTR_DAT_00527080)[val_2]);
      }
      if ((&g_MasterCardManaCostTable)[val_1 * 0x34] != '\0') {
        str_2 = _itoa((int)(char)(&g_MasterCardManaCostTable)[val_1 * 0x34],&DAT_005395f0,10);
        strcat(&g_OverworldWorldState,str_2);
      }
      strcat(&g_OverworldWorldState,&DAT_005270b4);
    }
  }
  FUN_00489710(&g_OverworldWorldState,10,10);
  return;
}

/*
 * Decompiled function: UI_AnteCardDisplayWndProc
 * Entry Point: 004853c2
 * Size: 226 bytes
 */


void UI_AnteCardDisplayWndProc(void)

{
  int slot_idx;
  
  FUN_0050d560(0,3);
  FUN_0040c421(s_My_Ante_005270b8,0xa0,100,0xff);
  FUN_0040c421(s_Opponent_s_Ante_005270c0,0xa0,1,0xff);
  for (slot_idx = 0; slot_idx < 0x10; slot_idx = slot_idx + 1) {
    if ((&DAT_006b2dd0)[slot_idx] != -1) {
      FUN_00484e2d((&DAT_006b2dd0)[slot_idx],(slot_idx + 1) * 0x6a,8,0,0xffffffff);
    }
    if ((&DAT_006b2d90)[slot_idx] != -1) {
      FUN_00484e2d((&DAT_006b2d90)[slot_idx],(slot_idx + 1) * 0x6a,0x6c,0,0xffffffff);
    }
  }
  return;
}

/*
 * Decompiled function: FUN_004854a4
 * Entry Point: 004854a4
 * Size: 353 bytes
 */


int FUN_004854a4(int player_id,char *mode_str,int event_type)

{
  int val_1;
  
  if (g_IsAiThinking != 1) {
    if (g_CurrentTurnPhase == arg_1) {
      val_1 = FUN_0040c465(str_2);
      val_1 = val_1 + 0x10;
      if (0x10 < val_1) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,g_AiManaColorCost_Red / 2 - val_1 / 2,0x5a,val_1,0x14,
                         0xff);
        UI_DrawCombatString(str_2,g_AiManaColorCost_Red / 2,0x5c,0);
        UI_DrawCombatString(&DAT_005270e0,g_AiManaColorCost_Red / 2,100,0);
      }
      do {
        val_1 = FUN_0048ac2f();
        if (val_1 == 0x79) {
          return 1;
        }
      } while (val_1 != 0x6e);
      arg_3 = 0;
    }
    else {
      strcpy(&g_OverworldWorldState,s__YES__005270d0 + ((arg_3 != 0) - 1 & 8));
      UI_DrawCombatString(&g_OverworldWorldState,g_AiManaColorCost_Red / 2,7,0xd8);
      UI_DrawCombatString(&g_OverworldWorldState,g_AiManaColorCost_Red / 2,6,0xdc);
      FUN_00501736(0x78);
    }
  }
  return arg_3;
}

/*
 * Decompiled function: FUN_00485605
 * Entry Point: 00485605
 * Size: 168 bytes
 */


int FUN_00485605(int player_id,char *mode_str,int event_type)

{
  int val_1;
  
  if ((g_CurrentTurnPhase == arg_1) && (g_IsAiThinking != 1)) {
    val_1 = FUN_0040c465(str_2);
    val_1 = val_1 + 0x10;
    if (0x10 < val_1) {
      Surface_FillRect((int *)g_DisplaySurfaceScreen,g_AiManaColorCost_Red / 2 - val_1 / 2,0x5a,val_1,0x14,
                       0xff);
      UI_DrawCombatString(str_2,g_AiManaColorCost_Red / 2,0x5c,0);
    }
    val_1 = FUN_0048ac2f();
    arg_3 = val_1 + -0x30;
  }
  return arg_3;
}

/*
 * Decompiled function: FUN_00488f92
 * Entry Point: 00488f92
 * Size: 73 bytes
 */


int32_t FUN_00488f92(int player_id)

{
  strcat(&g_OverworldWorldState,&DAT_00527a94 + ((*(int *)(&DAT_005270e4 + arg_1 * 4) != 0) - 1 & 8)
        );
  return *(int32_t *)(&DAT_005270e4 + arg_1 * 4);
}

/*
 * Decompiled function: FUN_00488fdb
 * Entry Point: 00488fdb
 * Size: 429 bytes
 */


void FUN_00488fdb(int32_t *arg_1,int card_slot,int event_type,int arg_4,int arg_5,char *str_6,char *str_7)

{
  uint8_t *pbVar1;
  uint8_t uval_2;
  int val_3;
  uint8_t local_42c [1040];
  int color_idx;
  int target_idx;
  uint32_t player_idx;
  uint32_t match_count;
  uint32_t slot_idx;
  
  val_3 = strcmp(PTR_DAT_00527aa4,str_6);
  if (val_3 == 0) {
    val_3 = strcmp(PTR_DAT_00527aa8,str_7);
    if (val_3 == 0) goto LAB_004890e3;
  }
  FileIO_OpenFileStream(-1,0,0,str_6,(short *)&DAT_00539928);
  FileIO_OpenFileStream(-1,0,0,str_7,(short *)&DAT_00539600);
  DAT_00539c48 = &DAT_0053992e;
  PTR_DAT_00527aa4 = str_6;
  PTR_DAT_00527aa8 = str_7;
  for (target_idx = 0; pbVar1 = DAT_00539c48, target_idx < 0x100; target_idx = target_idx + 1) {
    match_count = (uint32_t)*DAT_00539c48;
    DAT_00539c48 = DAT_00539c48 + 1;
    player_idx = (uint32_t)*DAT_00539c48;
    DAT_00539c48 = pbVar1 + 2;
    slot_idx = (uint32_t)*DAT_00539c48;
    DAT_00539c48 = pbVar1 + 3;
    uval_2 = Ai_Subsystem_004c22a2(match_count,player_idx,slot_idx,&DAT_00539606);
    (&DAT_00539c50)[target_idx] = uval_2;
  }
LAB_004890e3:
  for (color_idx = arg_3; color_idx < arg_5 + arg_3; color_idx = color_idx + 1) {
    Surface_GetLine((int32_t *)local_42c,*arg_1,arg_2,color_idx,arg_4);
    for (target_idx = 0; target_idx < arg_4; target_idx = target_idx + 1) {
      local_42c[target_idx] = (&DAT_00539c50)[local_42c[target_idx]];
    }
    Surface_PutLine((int32_t *)local_42c,*arg_1,arg_2,color_idx,arg_4);
  }
  return;
}

/*
 * Decompiled function: Pic_Load_advfac64_00489188
 * Entry Point: 00489188
 * Size: 1192 bytes
 */


void Pic_Load_advfac64_00489188(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  void *arg_1_00;
  DWORD DVar5;
  uint32_t uval_6;
  int val_7;
  uint32_t arg_2_00;
  int val_8;
  int *piVar9;
  int arg_6;
  char *str_6;
  int arg_7;
  void *pvVar10;
  char *str_7;
  HDC pHVar11;
  char loop_idx [24];
  void *slot_idx;
  
  Mem_AllocOrFree_00510e20(1,s_prdfrmc_pic_00527ab4 + ((arg_4 != 0) - 1 & 0xc));
  *(int32_t *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
  *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 4;
  if (arg_4 != 0) {
    FUN_00488fdb((int32_t *)g_DisplaySurfaceBackBuffer,1,0x15a,0xb3,0x23,s_prdblk_pic_00527adc,
                 s_advfac64_pic_00527acc);
  }
  Mem_AllocOrFree_0050fc00();
  slot_idx = (void *)Sprite_EncodeFromSurface(1,1,0x15a,0xb3,0x23);
  FUN_0050fc20();
  val_2 = g_AiManaColorCost_Red;
  val_1 = Ai_Util_004c3bc4(0xb4);
  val_8 = g_AiManaColorCost_Green;
  arg_2_00 = val_2 - val_1;
  val_2 = Ai_Util_004c3bc4(0xb4);
  val_8 = val_8 - val_2;
  if (arg_5 == 1) {
    *(int32_t *)g_DisplaySurfaceScreen = 1;
  }
  pvVar10 = slot_idx;
  val_1 = Ai_Util_004c3bc4((int)*(short *)((int)slot_idx + 6));
  val_3 = Ai_Util_004c3bc4((int)*(short *)((int)slot_idx + 4));
  val_2 = arg_3;
  val_4 = Ai_Util_004c3bc4((int)*(short *)((int)slot_idx + 4) / 2);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2 - val_4,val_2,val_3,val_1,(int)pvVar10);
  g_OverworldWorldState = 0;
  Glue_Subsystem_004eaa19(arg_1,0,0);
  val_2 = Ai_Util_004c3bc4((int)*(short *)((int)slot_idx + 6) / 2);
  FUN_0040d009((int)g_DisplaySurfaceScreen,(-(uint32_t)(arg_4 == 0) & 0x38) + 0xae,arg_2,arg_3 + val_2);
  *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
  if (arg_5 == 1) {
    *(int32_t *)g_DisplaySurfaceScreen = 0;
  }
  val_2 = Ai_Util_004c3bc4(0xb4);
  val_1 = Ai_Util_004c3bc4(0xb4);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,1,0xa5,0xb4,0xb4,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2_00,val_8,val_1,val_2);
  sprintf(loop_idx,s_faces__03d_pic_00527ae8,arg_1);
  FileIO_OpenFileStream(1,0,g_AiManaColorCost_Green + -0xf0,loop_idx,(short *)0x0);
  Mem_AllocOrFree_0050fc00();
  arg_1_00 = (void *)Sprite_EncodeFromSurface(1,0,g_AiManaColorCost_Green + -0xf0,0x8a,0xaa);
  FUN_0050fc20();
  pvVar10 = arg_1_00;
  val_2 = Ai_Util_004c3bc4(0xaa);
  val_1 = Ai_Util_004c3bc4(0x8a);
  val_3 = Ai_Util_004c3bc4(5);
  val_3 = val_8 + val_3;
  val_4 = Ai_Util_004c3bc4(0x15);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_2_00 + val_4,val_3,val_1,val_2,
                    (int)pvVar10);
  if (arg_4 != 0) {
    str_7 = s_advfac64_pic_00527af8;
    str_6 = s_prdblk_pic_00527b08;
    val_2 = Ai_Util_004c3bc4(0xb4);
    val_1 = Ai_Util_004c3bc4(0xb4);
    FUN_00488fdb((int32_t *)g_DisplaySurfaceBackBuffer,arg_2_00,val_8,val_1,val_2,str_6,str_7);
  }
  if (arg_5 == 0) {
    val_2 = Ai_Util_004c3bc4(0x2d);
    val_2 = arg_3 + val_2;
    val_1 = Ai_Util_004c3bc4(0x5a);
    val_1 = arg_2 - val_1;
    piVar9 = (int *)g_DisplaySurfaceScreen;
    DVar5 = Ai_Util_004c3bc4(0xb4);
    uval_6 = Ai_Util_004c3bc4(0xb4);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2_00,val_8,uval_6,DVar5,piVar9,val_1,val_2);
  }
  else {
    val_2 = (&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceBackBuffer];
    val_1 = (&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceScreen];
    val_3 = Ai_Util_004c3bc4(0x2d);
    val_3 = arg_3 + val_3;
    val_4 = Ai_Util_004c3bc4(0x5a);
    val_4 = arg_2 - val_4;
    piVar9 = (int *)g_DisplaySurfaceBackBuffer;
    DVar5 = Ai_Util_004c3bc4(0xb4);
    uval_6 = Ai_Util_004c3bc4(0xb4);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2_00,val_8,uval_6,DVar5,piVar9,val_4,val_3);
    pHVar11 = *(HDC *)(val_2 + 4);
    arg_7 = 3;
    arg_6 = 3;
    val_8 = Ai_Util_004c3bc4(0xb4);
    val_3 = Ai_Util_004c3bc4(0xb4);
    val_4 = Ai_Util_004c3bc4(0x2d);
    val_4 = arg_3 + val_4;
    val_7 = Ai_Util_004c3bc4(0x5a);
    FUN_005119e0(*(HDC *)(val_1 + 4),arg_2 - val_7,val_4,val_3,val_8,arg_6,arg_7,pHVar11);
    if (arg_5 == 1) {
      pHVar11 = *(HDC *)(val_2 + 4);
      val_7 = 2;
      val_4 = 2;
      val_2 = Ai_Util_004c3bc4((int)*(short *)((int)slot_idx + 6));
      val_8 = Ai_Util_004c3bc4(*(short *)((int)slot_idx + 4) + -0x16);
      val_3 = Ai_Util_004c3bc4((int)*(short *)((int)slot_idx + 4) / 2 + -0xb);
      FUN_005119e0(*(HDC *)(val_1 + 4),arg_2 - val_3,arg_3,val_8,val_2,val_4,val_7,pHVar11);
    }
  }
  Mem_AllocOrFree_0050fc50(arg_1_00);
  Mem_AllocOrFree_0050fc50(slot_idx);
  return;
}

/*
 * Decompiled function: FUN_00489630
 * Entry Point: 00489630
 * Size: 88 bytes
 */


void FUN_00489630(uint32_t arg_1)

{
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (499 < slot_idx) {
      return;
    }
    if ((*(uint32_t *)(&deck + slot_idx * 4) & 0xfff) == arg_1) break;
    slot_idx = slot_idx + 1;
  }
  Pic_Subsystem_00452065(slot_idx);
  return;
}

/*
 * Decompiled function: Mem_AllocOrFree_00489690
 * Entry Point: 00489690
 * Size: 46 bytes
 */


void Mem_AllocOrFree_00489690(int32_t arg_1,int32_t arg_2,int32_t arg_3)

{
  DAT_00539dec = arg_2;
  DAT_00539df0 = arg_3;
  FUN_00489748(arg_1,0);
  return;
}

/*
 * Decompiled function: FUN_004896be
 * Entry Point: 004896be
 * Size: 82 bytes
 */


void FUN_004896be(int32_t arg_1,int card_slot,uint32_t arg_3)

{
  FUN_00489710(arg_1,(arg_2 * g_AiManaColorCost_Red) / 0x140,
               (int)((arg_3 - (arg_3 & 1)) * g_AiManaColorCost_Green) / 200 + (arg_3 & 1));
  return;
}

/*
 * Decompiled function: FUN_00489710
 * Entry Point: 00489710
 * Size: 56 bytes
 */


void FUN_00489710(int32_t arg_1,int32_t arg_2,int32_t arg_3)

{
  DAT_00539dec = arg_2;
  DAT_00539df0 = arg_3;
  DAT_00527b18 = 0xffffffff;
  FUN_00489748(arg_1,1);
  return;
}

/*
 * Decompiled function: FUN_00489748
 * Entry Point: 00489748
 * Size: 1359 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00489748(char *arg1,int arg2)

{
  bool flag_1;
  int val_2;
  char *mode_str;
  int val_3;
  uint32_t uval_4;
  int local_34;
  int local_28;
  int color_idx;
  char target_idx [4];
  int32_t player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if ((arg2 != 0) && (DAT_00676d3c == 0)) {
    FUN_0040a3e1();
  }
  color_idx = -1;
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
  player_idx = 0x16;
  DAT_00539de0 = 0xff;
  if (DAT_0067bde4 == 0) {
    player_idx = 0xffffffff;
  }
  match_count = 0;
  flag_1 = false;
  UI_PrepareCombatViewport();
  FUN_00489c9c(arg1,DAT_00527b18);
  Pic_Subsystem_0044b8aa();
  if (DAT_00676d3c == 0) {
    if (DAT_00527b2c != -1) {
      Mem_AllocOrFree_005016f9();
      slot_idx = -1;
    }
    do {
      DAT_00676d38 = 0;
      g_CombatAttackerSlotIndex = 0;
      if (DAT_00701014 == 0) {
        Util_SeedRandomGenerator();
      }
      val_3 = DAT_00527b2c;
      if (DAT_00527b2c != -1) {
        val_2 = Mem_AllocOrFree_00501721();
        card_idx = val_3 - val_2 / (DAT_0052244c * 0x3c);
        if (card_idx == 0) {
          local_34 = -1;
          flag_1 = true;
        }
        if (slot_idx != card_idx) {
          str_2 = _itoa(card_idx,&DAT_00539df8,10);
          strcpy(target_idx,str_2);
          Surface_FillRect((int *)g_DisplaySurfaceScreen,DAT_00676d44 + -0xe,DAT_00539df0 + 4,0xc,7,
                           0xbc);
          UI_DrawCombatString(target_idx,DAT_00676d44 + -8,DAT_00539df0 + 5,0xff);
          slot_idx = card_idx;
        }
      }
      Pic_Subsystem_0044b84b();
      if ((g_CombatAttackerSlotIndex == 0) && (match_count == 0)) {
        val_3 = Mem_AllocOrFree_00408089();
        if (val_3 != 0) {
          uval_4 = FUN_0048ac2f();
          val_3 = local_34;
          if ((int)uval_4 < 0x1c) {
            if (uval_4 == 0x1b) {
              local_34 = -1;
              flag_1 = true;
            }
            else {
              if (uval_4 == 0xd) goto LAB_00489ab3;
LAB_00489af7:
              do {
                val_2 = val_3;
                local_28 = val_2 + 1;
                if (0x1f < local_28) goto LAB_00489b95;
                val_3 = local_28;
              } while (((&DAT_00676d11)[val_2] == -1) ||
                      (val_3 = local_28,
                      (((int)(char)(&DAT_00676d11)[val_2] ^ uval_4 & 0x1f) & 0x1f) != 0));
              local_34 = local_28;
            }
          }
          else if (uval_4 == 0x20) {
LAB_00489ab3:
            if ((DAT_00676d58 & 1 << ((uint8_t)local_34 & 0x1f)) == 0) {
              flag_1 = true;
            }
          }
          else if (uval_4 == 0x4800) {
            if (0 < local_34) {
              local_34 = local_34 + -1;
            }
          }
          else {
            if (uval_4 != 0x5000) goto LAB_00489af7;
            if (local_34 < DAT_00676d40 + -1) {
              local_34 = local_34 + 1;
            }
          }
        }
      }
      else {
        DAT_00527b28 = 1;
        match_count = 1;
        if (g_CombatAttackerSlotIndex == 2) {
          _DAT_00527b1c = 1;
        }
        local_34 = ((g_MouseScreenCoordY - DAT_00539df0) + -4) / DAT_00527b30 - DAT_00676d50;
        if ((g_MouseScreenCoordX < DAT_00539dec) || (DAT_00676d44 < g_MouseScreenCoordX)) {
          local_34 = -1;
        }
        if ((DAT_00676d58 & 1 << ((uint8_t)local_34 & 0x1f)) == 0) {
          if (g_CombatAttackerSlotIndex == 0) {
            flag_1 = true;
          }
        }
        else {
          local_34 = color_idx;
        }
      }
LAB_00489b95:
      if ((((local_34 < 0) || (DAT_00676d40 <= local_34)) || (DAT_00676d4c != 0)) ||
         (DAT_00676d34 != 0)) {
        local_34 = -1;
      }
      if (color_idx != local_34) {
        FUN_00489c9c(arg1,local_34);
        color_idx = local_34;
        DAT_00539e04 = local_34;
      }
    } while (!flag_1);
    DAT_00539de4 = 1;
    if (local_34 == -1) {
      _DAT_00527b1c = 0;
    }
    else {
      UI_PrepareCombatViewport();
      FUN_00489c9c(arg1,local_34);
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

int FUN_00489c9c(char *filepath,int arg2)

{
  size_t len_1;
  int val_2;
  int32_t color_idx;
  int32_t target_idx;
  uint32_t player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  _DAT_00539d60 = 0;
  if (DAT_00676d38 == 1) {
    DAT_00527b30 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    for (player_idx = 0; (int)player_idx < 0x20; player_idx = player_idx + 1) {
      (&DAT_00676d10)[player_idx] = 0xff;
    }
    match_count = 0;
    DAT_00539de8 = 0;
    slot_idx = 0;
    DAT_00676d48 = 0;
    for (player_idx = 0; len_1 = strlen(str_1), player_idx < len_1; player_idx = player_idx + 1) {
      if (str_1[player_idx] == '\n') {
        if (DAT_00676d48 < slot_idx) {
          DAT_00676d48 = slot_idx;
        }
        slot_idx = 0;
        DAT_00539de8 = DAT_00539de8 + 1;
        *(uint32_t *)(&DAT_00539d60 + DAT_00539de8 * 4) = player_idx + 1;
      }
      else {
        if ((slot_idx == 0) && ((str_1[player_idx] == ' ' || (str_1[player_idx] == '_')))) {
          if (match_count < 0x20) {
            (&DAT_00676d10)[match_count] = str_1[player_idx + 1];
          }
          if (DAT_00676d50 == -1) {
            DAT_00676d50 = DAT_00539de8;
          }
          match_count = match_count + 1;
        }
        val_2 = FUN_0050f390(*(int *)(g_DisplaySurfaceScreen + 0x20),str_1[player_idx]);
        slot_idx = slot_idx + val_2;
      }
    }
    DAT_00539de8 = FUN_0040a305(DAT_00539de8,0,(g_AiManaColorCost_Green - DAT_00539df0) / DAT_00527b30);
    if (DAT_00539dec == -1) {
      DAT_00539dec = 0xa0 - (DAT_00676d48 + 8) / 2;
    }
    DAT_00676d44 = DAT_00539dec + DAT_00676d48 + 8;
    val_2 = DAT_00527b30 * DAT_00539de8 + DAT_00539df0;
    card_idx = val_2 + 6;
    if (DAT_00527b24 != 0) {
      card_idx = val_2 + 8;
    }
    len_1 = strlen(str_1);
    if (str_1[len_1 - 1] != '\n') {
      match_count = match_count + -1;
    }
    DAT_00676d40 = match_count;
    FUN_0048a1ba(DAT_00539dec,DAT_00539df0,DAT_00676d44 - DAT_00539dec,card_idx - DAT_00539df0);
    if (DAT_00676d4c != 0) {
      FUN_0040c1ad(&DAT_00527b40,DAT_00676d44 + -0x11,card_idx + -8,0xfe);
      FUN_0048a2a5(DAT_00676d44 + -0x14,card_idx + -10,0x14,10,0xfe);
    }
  }
  if ((*str_1 == ' ') || (*str_1 == '_')) {
    match_count = 0;
  }
  else {
    match_count = -1;
  }
  DAT_00539de0 = DAT_00527b34;
  *(int32_t *)(g_DisplaySurfaceScreen + 0x18) = DAT_00527b34;
  for (player_idx = 0; (int)player_idx < DAT_00539de8; player_idx = player_idx + 1) {
    if (((DAT_00676d38 != 0) || (DAT_00539e04 == match_count)) || (arg2 == match_count)) {
      str_1[*(int *)(&DAT_00539d64 + player_idx * 4) + -1] = '\0';
      if ((match_count < 0) || ((_DAT_00676d30 & 1 << ((uint8_t)match_count & 0x1f)) == 0)) {
        if (match_count < 0) {
          color_idx = DAT_00539de0;
        }
        else if (arg2 == match_count) {
          color_idx = DAT_00527b38;
        }
        else {
          color_idx = DAT_00527b34;
        }
        FUN_0040c274(str_1 + *(int *)(&DAT_00539d60 + player_idx * 4),DAT_00539dec + 5,
                     DAT_00527b30 * player_idx + DAT_00539df0 + 5,color_idx);
      }
      else {
        str_1[*(int *)(&DAT_00539d60 + player_idx * 4)] = '^';
        if ((DAT_00539de4 == 0) || (arg2 != match_count)) {
          if (match_count < 0) {
            target_idx = DAT_00539de0;
          }
          else if (arg2 == match_count) {
            target_idx = DAT_00527b38;
          }
          else {
            target_idx = DAT_00527b34;
          }
          FUN_0040c274(str_1 + *(int *)(&DAT_00539d60 + player_idx * 4),DAT_00539dec + 5,
                       DAT_00527b30 * player_idx + DAT_00539df0 + 5,target_idx);
        }
        else {
          FUN_0040c274(str_1 + *(int *)(&DAT_00539d60 + player_idx * 4),DAT_00539dec + 5,
                       DAT_00527b30 * player_idx + DAT_00539df0 + 5,0xff);
        }
        str_1[*(int *)(&DAT_00539d60 + player_idx * 4)] = ' ';
      }
      str_1[*(int *)(&DAT_00539d64 + player_idx * 4) + -1] = '\n';
    }
    if ((str_1[*(int *)(&DAT_00539d64 + player_idx * 4)] == ' ') ||
       (str_1[*(int *)(&DAT_00539d64 + player_idx * 4)] == '_')) {
      match_count = match_count + 1;
    }
  }
  return arg2;
}

/*
 * Decompiled function: FUN_0048a1ba
 * Entry Point: 0048a1ba
 * Size: 116 bytes
 */


void FUN_0048a1ba(int32_t arg_1,int y,int32_t arg_3,int32_t arg_4)

{
  if (DAT_00676d54 == 0) {
    (*(code *)PTR_FUN_00527b3c)(arg_1,y,arg_3,arg_4,(int)(y + (y >> 0x1f & 7U)) >> 3 & 3);
  }
  else {
    (*(code *)PTR_FUN_00527b3c)(arg_1,y,arg_3,arg_4,DAT_00676d54);
    DAT_00676d54 = 0;
  }
  return;
}

/*
 * Decompiled function: FUN_0048a2a5
 * Entry Point: 0048a2a5
 * Size: 147 bytes
 */


void FUN_0048a2a5(int player_id,int card_slot,int event_type,int arg_4,int32_t arg_5)

{
  Mem_AllocOrFree_0040c180(arg_1,arg_2,arg_3 + arg_1,arg_2,arg_5);
  Mem_AllocOrFree_0040c180(arg_1,arg_4 + arg_2,arg_3 + arg_1,arg_4 + arg_2,arg_5);
  Mem_AllocOrFree_0040c180(arg_3 + arg_1,arg_2,arg_3 + arg_1,arg_4 + arg_2,arg_5);
  Mem_AllocOrFree_0040c180(arg_1,arg_2,arg_1,arg_4 + arg_2,arg_5);
  return;
}

/*
 * Decompiled function: FUN_0048a338
 * Entry Point: 0048a338
 * Size: 148 bytes
 */


void FUN_0048a338(int player_id,int card_slot,int event_type,int arg_4,int32_t arg_5,int32_t arg_6)

{
  Mem_AllocOrFree_0040c180(arg_1,arg_2,arg_3 + arg_1,arg_2,arg_6);
  Mem_AllocOrFree_0040c180(arg_1,arg_4 + arg_2,arg_3 + arg_1,arg_4 + arg_2,arg_5);
  Mem_AllocOrFree_0040c180(arg_3 + arg_1,arg_2,arg_3 + arg_1,arg_4 + arg_2,arg_6);
  Mem_AllocOrFree_0040c180(arg_1,arg_2 + 1,arg_1,arg_4 + arg_2,arg_5);
  return;
}

/*
 * Decompiled function: FUN_0048a3cc
 * Entry Point: 0048a3cc
 * Size: 803 bytes
 */


void FUN_0048a3cc(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  int arg_2_00;
  int arg_3_00;
  int val_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  val_1 = (int)(arg_3 + 0x17 + (arg_3 + 0x17 >> 0x1f & 0xfU)) >> 4;
  val_2 = (int)(arg_4 + 0x17 + (arg_4 + 0x17 >> 0x1f & 0xfU)) >> 4;
  arg_2_00 = (arg_1 + -4) - (val_1 * 0x10 - (arg_3 + 8)) / 2;
  arg_3_00 = (arg_2 + -4) - (val_2 * 0x10 - (arg_4 + 8)) / 2;
  *(int32_t *)g_DisplaySurfaceScreen = 1;
  Surface_FillRect((int *)g_DisplaySurfaceScreen,arg_2_00,arg_3_00,val_1 << 4,val_2 << 4,0xe3);
  for (match_count = 0; match_count < val_2; match_count = match_count + 1) {
    for (slot_idx = 0; slot_idx < val_1; slot_idx = slot_idx + 1) {
      Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,slot_idx * 0x10 + arg_2_00,
                        match_count * 0x10 + arg_3_00,(&DAT_006781d0)[arg_5 * 9]);
    }
  }
  for (slot_idx = 0; slot_idx < val_1; slot_idx = slot_idx + 1) {
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,slot_idx * 0x10 + arg_2_00,arg_3_00 + -10,
                      *(int *)(&DAT_006781e4 + arg_5 * 0x24));
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,slot_idx * 0x10 + arg_2_00,
                      val_2 * 0x10 + arg_3_00 + -6,*(int *)(&DAT_006781ec + arg_5 * 0x24));
  }
  for (match_count = 0; match_count < val_2; match_count = match_count + 1) {
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00 + -10,match_count * 0x10 + arg_3_00,
                      *(int *)(&DAT_006781f0 + arg_5 * 0x24));
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,val_1 * 0x10 + arg_2_00 + -6,
                      match_count * 0x10 + arg_3_00,*(int *)(&DAT_006781e8 + arg_5 * 0x24));
  }
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00 + -10,arg_3_00 + -10,
                    *(int *)(&DAT_006781d4 + arg_5 * 0x24));
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,val_1 * 0x10 + arg_2_00 + -6,arg_3_00 + -10,
                    *(int *)(&DAT_006781d8 + arg_5 * 0x24));
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00 + -10,val_2 * 0x10 + arg_3_00 + -6,
                    *(int *)(&DAT_006781dc + arg_5 * 0x24));
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,val_1 * 0x10 + arg_2_00 + -6,
                    val_2 * 0x10 + arg_3_00 + -6,*(int *)(&DAT_006781e0 + arg_5 * 0x24));
  *(int32_t *)g_DisplaySurfaceScreen = 0;
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2_00 - 10,arg_3_00 + -10,val_1 * 0x10 + 0x14,
               val_2 * 0x10 + 0x14,(int *)g_DisplaySurfaceScreen,arg_2_00 + -10,arg_3_00 + -10);
  return;
}

/*
 * Decompiled function: FUN_0048a6ef
 * Entry Point: 0048a6ef
 * Size: 1344 bytes
 */


void FUN_0048a6ef(int player_id,int card_slot,int event_type,int arg_4,int32_t *arg_5)

{
  int32_t *u_ptr_1;
  short len_2;
  int16_t uval_3;
  int val_4;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int32_t uStack_a8;
  short local_a4 [2];
  int32_t auStack_a0 [3];
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
  int target_idx;
  int player_idx;
  int card_idx;
  int *match_count;
  
  match_count = arg_5;
  for (local_b0 = 0; local_b0 < 9; local_b0 = local_b0 + 1) {
    if (match_count[local_b0] != 0) {
      u_ptr_1 = (int32_t *)match_count[local_b0];
      (&uStack_a8)[local_b0 * 4] = *u_ptr_1;
      *(int32_t *)(local_a4 + local_b0 * 8) = u_ptr_1[1];
      auStack_a0[local_b0 * 4] = u_ptr_1[2];
      auStack_a0[local_b0 * 4 + 1] = u_ptr_1[3];
      len_2 = Ai_Util_004c3bc4((int)local_a4[local_b0 * 8]);
      local_a4[local_b0 * 8] = len_2;
      uval_3 = Ai_Util_004c3bc4((int)*(short *)((int)auStack_a0 + local_b0 * 0x10 + -2));
      *(int16_t *)((int)auStack_a0 + local_b0 * 0x10 + -2) = uval_3;
    }
  }
  if (match_count[8] == 0) {
    player_idx = arg_4;
    card_idx = arg_3;
  }
  else {
    if (arg_4 % (int)local_22 != 0) {
      player_idx = (arg_4 / (int)local_22 + 1) * (int)local_22;
    }
    if (arg_3 % (int)local_24 != 0) {
      card_idx = (arg_3 / (int)local_24 + 1) * (int)local_24;
    }
    arg_1 = (arg_1 + 4) - (card_idx - arg_3) / 2;
    arg_2 = (arg_2 + 4) - (player_idx - arg_4) / 2;
    for (local_b4 = 0; local_b4 < player_idx / (int)local_22; local_b4 = local_b4 + 1) {
      for (local_b0 = 0; local_b0 < card_idx / (int)local_24; local_b0 = local_b0 + 1) {
        Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_24 * local_b0 + arg_1,
                          local_22 * local_b4 + arg_2,(int)local_24,(int)local_22,match_count[8]);
      }
    }
  }
  local_ac = (local_94 + card_idx + arg_1) - (int)local_94;
  for (target_idx = (arg_1 - local_44) + (int)local_a4[0]; target_idx < arg_1 + card_idx / 2;
      target_idx = target_idx + local_64) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,target_idx,arg_2,(int)local_64,(int)local_62,
                      match_count[4]);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_ac,arg_2,(int)local_64,(int)local_62,
                      match_count[4]);
    local_ac = local_ac - local_64;
  }
  target_idx = arg_1 - local_44;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,target_idx,arg_2,(int)local_a4[0],(int)local_a4[1],
                    *match_count);
  target_idx = (local_34 + arg_3 + arg_1) - (int)local_94;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,target_idx,arg_2,(int)local_94,(int)local_92,
                    match_count[1]);
  target_idx = arg_1 - local_44;
  val_4 = card_idx + arg_1;
  for (local_b8 = local_a4[1] + arg_2; local_b8 < (arg_2 + player_idx) - (int)local_82;
      local_b8 = local_b8 + local_42) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,target_idx,local_b8,(int)local_44,(int)local_42,
                      match_count[6]);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,val_4,local_b8,(int)local_34,(int)local_32,
                      match_count[7]);
  }
  val_4 = (arg_2 + player_idx) - (int)local_82;
  target_idx = arg_1 - local_44;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,target_idx,val_4,(int)local_84,(int)local_82,
                    match_count[2]);
  target_idx = (local_34 + card_idx + arg_1) - (int)local_94;
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,target_idx,val_4,(int)local_74,(int)local_72,
                    match_count[3]);
  local_ac = (local_94 + card_idx + arg_1) - (int)local_94;
  val_4 = arg_2 + player_idx;
  for (target_idx = (arg_1 - local_44) + (int)local_a4[0]; target_idx < arg_1 + card_idx / 2;
      target_idx = target_idx + local_54) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,target_idx,val_4,(int)local_54,(int)local_52,
                      match_count[5]);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_ac,val_4,(int)local_54,(int)local_52,
                      match_count[5]);
    local_ac = local_ac - local_54;
  }
  return;
}

/*
 * Decompiled function: FUN_0048ac2f
 * Entry Point: 0048ac2f
 * Size: 684 bytes
 */


uint32_t FUN_0048ac2f(void)

{
  uint32_t slot_idx;
  
  do {
    slot_idx = Util_CopyMemoryBuffer();
  } while (slot_idx == 0);
  if ((int)slot_idx < 0x4738) {
    if (slot_idx == 0x4737) {
      return 0x4737;
    }
    if (slot_idx == 0x4700) {
      return 0x4700;
    }
  }
  else if ((int)slot_idx < 0x4801) {
    if (slot_idx == 0x4800) {
      return 0x4800;
    }
    if (slot_idx == 0x475c) {
      return 0x4700;
    }
  }
  else if ((int)slot_idx < 0x487f) {
    if (slot_idx == 0x487e) {
      return 0x4800;
    }
    if (slot_idx == 0x4838) {
      return 0x4838;
    }
  }
  else if ((int)slot_idx < 0x493a) {
    if (slot_idx == 0x4939) {
      return 0x4939;
    }
    if (slot_idx == 0x4900) {
      return 0x4900;
    }
  }
  else if ((int)slot_idx < 0x4b35) {
    if (slot_idx == 0x4b34) {
      return 0x4b34;
    }
    if (slot_idx == 0x4b00) {
      return 0x4b00;
    }
  }
  else if ((int)slot_idx < 0x4b7d) {
    if (slot_idx == 0x4b7c) {
      return 0x4b00;
    }
    if (slot_idx == 0x4b43) {
      return 0x4b34;
    }
  }
  else if ((int)slot_idx < 0x4d37) {
    if (slot_idx == 0x4d36) {
      return 0x4d36;
    }
    if (slot_idx == 0x4d00) {
      return 0x4d00;
    }
  }
  else if ((int)slot_idx < 0x4f01) {
    if (slot_idx == 0x4f00) {
      return 0x4f00;
    }
    if (slot_idx == 0x4d46) {
      return 0x4d36;
    }
  }
  else if ((int)slot_idx < 0x5001) {
    if (slot_idx == 0x5000) {
      return 0x5000;
    }
    if (slot_idx == 0x4f31) {
      return 0x4f31;
    }
  }
  else if ((int)slot_idx < 0x5061) {
    if (slot_idx == 0x5060) {
      return 0x5000;
    }
    if (slot_idx == 0x5032) {
      return 0x5032;
    }
  }
  else {
    if (slot_idx == 0x5100) {
      return 0x5100;
    }
    if (slot_idx == 0x5133) {
      return 0x5133;
    }
    if (slot_idx == 0xf400) {
      return 0x4d00;
    }
  }
  if ((char)slot_idx != '\0') {
    slot_idx = slot_idx & 0xff;
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0048aee0
 * Entry Point: 0048aee0
 * Size: 59 bytes
 */


void FUN_0048aee0(undefined8 *arg1,uint32_t arg2)

{
  uint32_t uval_1;
  uint32_t uval_2;
  
  uval_1 = arg2;
  if (((uint32_t)arg1 & 4) != 0) {
    *(uint8_t *)arg1 = 0;
    arg1 = (undefined8 *)((int)arg1 + 4);
    uval_1 = arg2 - 1;
    if (uval_1 == 0 || (int)arg2 < 1) {
      return;
    }
  }
  uval_2 = uval_1 >> 1;
  if (uval_2 != 0) {
    while (uval_2 = uval_2 - 1, uval_2 != 0) {
      *arg1 = 0;
      arg1 = arg1 + 1;
    }
    *arg1 = 0;
  }
  if ((uval_1 & 1) != 0) {
    *(uint8_t *)arg1 = 0;
  }
  return;
}

/*
 * Decompiled function: FUN_0048b950
 * Entry Point: 0048b950
 * Size: 579 bytes
 */


int FUN_0048b950(uint32_t *arg_1,int32_t arg_2,int32_t arg_3)

{
  uint32_t uval_1;
  uint32_t uval_2;
  int val_3;
  uint32_t uval_4;
  uint32_t *puVar5;
  uint32_t local_4;
  
  val_3 = 0;
  local_4 = 0xd;
  do {
    (&DAT_00539e08)[val_3] = 0xffffffff >> ((uint8_t)val_3 & 0x1f);
    val_3 = val_3 + 1;
  } while (val_3 < 0x20);
  DAT_0053aa94 = arg_1;
  g_WaveletDecompressCursor = arg_1 + 1;
  DAT_0053aa98 = 100000;
  g_WaveletBitsRemaining = 0x13;
  uval_1 = DAT_00539e54 & *arg_1;
  g_WaveletBitAccumulator = *arg_1 >> 0xd;
  DAT_0053aa9c = uval_1;
  if (0 < (int)uval_1) {
    puVar5 = &DAT_0053aaa8;
    local_4 = uval_1 * 0x1a + 0xd;
    do {
      if (g_WaveletBitsRemaining < 0xd) {
        val_3 = 0xd - g_WaveletBitsRemaining;
        if ((int)g_WaveletDecompressCursor + (4 - (int)arg_1) < 100000) {
          uval_2 = *g_WaveletDecompressCursor;
          g_WaveletDecompressCursor = g_WaveletDecompressCursor + 1;
          uval_4 = g_WaveletBitAccumulator | ((&g_WaveletBitmaskTable)[-val_3] & uval_2) << ((uint8_t)g_WaveletBitsRemaining & 0x1f);
          g_WaveletBitAccumulator = uval_2 >> ((uint8_t)val_3 & 0x1f);
          g_WaveletBitsRemaining = 0x20 - val_3;
          *puVar5 = uval_4;
        }
        else {
          *puVar5 = 0xffffffff;
        }
      }
      else {
        uval_2 = DAT_00539e54 & g_WaveletBitAccumulator;
        g_WaveletBitAccumulator = g_WaveletBitAccumulator >> 0xd;
        g_WaveletBitsRemaining = g_WaveletBitsRemaining - 0xd;
        *puVar5 = uval_2;
      }
      if (g_WaveletBitsRemaining < 0xd) {
        val_3 = 0xd - g_WaveletBitsRemaining;
        if ((int)g_WaveletDecompressCursor + (4 - (int)arg_1) < 100000) {
          uval_2 = *g_WaveletDecompressCursor;
          g_WaveletDecompressCursor = g_WaveletDecompressCursor + 1;
          uval_4 = g_WaveletBitAccumulator | ((&g_WaveletBitmaskTable)[-val_3] & uval_2) << ((uint8_t)g_WaveletBitsRemaining & 0x1f);
          g_WaveletBitAccumulator = uval_2 >> ((uint8_t)val_3 & 0x1f);
          g_WaveletBitsRemaining = 0x20 - val_3;
          puVar5[1] = uval_4;
        }
        else {
          puVar5[1] = 0xffffffff;
        }
      }
      else {
        uval_2 = DAT_00539e54 & g_WaveletBitAccumulator;
        g_WaveletBitAccumulator = g_WaveletBitAccumulator >> 0xd;
        g_WaveletBitsRemaining = g_WaveletBitsRemaining - 0xd;
        puVar5[1] = uval_2;
      }
      puVar5 = puVar5 + 2;
      uval_1 = uval_1 - 1;
    } while (uval_1 != 0);
  }
  DAT_0053aaa0 = arg_3;
  DAT_0053aaa4 = arg_2;
  FUN_0048bba0(DAT_0053aa9c);
  return ((int)(local_4 + ((int)local_4 >> 0x1f & 7U)) >> 3) + (uint32_t)((local_4 & 7) != 0);
}

/*
 * Decompiled function: FUN_0048bba0
 * Entry Point: 0048bba0
 * Size: 487 bytes
 */


int32_t FUN_0048bba0(int player_id)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  int32_t *puVar5;
  int val_6;
  uint32_t uval_7;
  int *piVar8;
  uint32_t uVar9;
  int local_b8 [11];
  int32_t uStack_8c;
  int aiStack_30 [12];
  
  local_b8[0] = 0x100;
  local_b8[1] = 0x200;
  local_b8[2] = 0x400;
  piVar8 = local_b8 + 3;
  for (val_1 = 0x20; val_1 != 0; val_1 = val_1 + -1) {
    *piVar8 = 1;
    piVar8 = piVar8 + 1;
  }
  val_1 = arg_1 + -1;
  aiStack_30[1] = val_1;
  val_3 = 0;
  do {
    val_4 = val_3 + 1;
    if (local_b8[val_3 + 3] == 0) {
      val_2 = (&DAT_0053aaac)[val_1 * 2];
    }
    else {
      val_2 = (&DAT_0053aaa8)[val_1 * 2];
    }
    val_1 = val_2 - DAT_0053aaa0;
    aiStack_30[val_3 + 2] = val_1;
    if (val_1 < 0) {
      val_1 = 0;
      uVar9 = 0;
      if (0 < val_4) {
        do {
          uVar9 = uVar9 | local_b8[val_1 + 3] << ((uint8_t)val_1 & 0x1f);
          val_1 = val_1 + 1;
        } while (val_1 < val_4);
      }
      val_6 = 0;
      val_1 = local_b8[-val_4];
      if (0 < val_1) {
        puVar5 = (int32_t *)(val_2 * 4 + DAT_0053aaa4);
        do {
          uval_7 = val_6 << ((uint8_t)val_4 & 0x1f) | uVar9;
          val_6 = val_6 + 1;
          (&DAT_00539e94)[uval_7 * 3] = val_4;
          (&DAT_00539e90)[uval_7 * 3] = *puVar5;
          (&DAT_00539e98)[uval_7 * 3] = 0xffffffff;
        } while (val_6 < val_1);
      }
      local_b8[val_3 + 4] = 1;
      local_b8[val_3 + 3] = local_b8[val_3 + 3] + -1;
LAB_0048bd35:
      val_2 = val_3 * 4;
      val_1 = aiStack_30[val_3 + 1];
      val_4 = val_3;
      if (local_b8[3] < 0) {
        return 0;
      }
      do {
        if (-1 < *(int *)((int)local_b8 + val_2 + 0xc)) break;
        val_1 = *(int *)((int)aiStack_30 + val_2);
        *(int32_t *)((int)local_b8 + val_2 + 0xc) = 1;
        val_4 = val_4 + -1;
        *(int *)((int)local_b8 + val_2 + 8) = *(int *)((int)local_b8 + val_2 + 8) + -1;
        val_2 = val_2 + -4;
      } while (-1 < local_b8[3]);
    }
    else if (val_4 == 8) {
      val_4 = 0;
      uVar9 = 0;
      do {
        uVar9 = uVar9 | local_b8[val_4 + 3] << ((uint8_t)val_4 & 0x1f);
        val_4 = val_4 + 1;
      } while (val_4 < 8);
      uStack_8c = 1;
      (&DAT_00539e90)[uVar9 * 3] = 0x7fffffff;
      (&DAT_00539e94)[uVar9 * 3] = 8;
      (&DAT_00539e98)[uVar9 * 3] = val_1;
      local_b8[val_3 + 3] = local_b8[val_3 + 3] + -1;
      goto LAB_0048bd35;
    }
    val_3 = val_4;
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


int32_t __thiscall FUN_0048bda1(void *this)

{
  int val_1;
  int32_t reg_eax;
  int val_2;
  int val_3;
  int val_4;
  int val_5;
  int32_t *puVar6;
  int unaff_retaddr;
  int iStack00000080;
  int stack_arg;
  
  val_5 = 0;
  puVar6 = (int32_t *)register0x00000010;
  for (; this != (void *)0x0; this = (void *)((int)this + -1)) {
    *puVar6 = reg_eax;
    puVar6 = puVar6 + 1;
  }
  val_4 = stack_arg + -1;
  iStack00000080 = val_4;
  puVar6 = &DAT_00676c90;
  for (val_3 = 0x20; val_1 = DAT_0053aaa0, val_3 != 0; val_3 = val_3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  do {
    val_3 = val_5 + 1;
    if (*(int *)(&stack0x00000000 + val_5 * 4) == 0) {
      val_4 = (&DAT_0053aaac)[val_4 * 2];
    }
    else {
      val_4 = (&DAT_0053aaa8)[val_4 * 2];
    }
    val_4 = val_4 - val_1;
    *(int *)((int)&stack0x00000080 + val_3 * 4) = val_4;
    if (val_4 < 0) {
      val_4 = (&DAT_00676c90)[val_3];
      *(int32_t *)(&stack0x00000000 + val_3 * 4) = 1;
      (&DAT_00676c90)[val_3] = val_4 + 1;
      val_2 = val_5 * 4;
      *(int *)(&stack0x00000000 + val_2) = *(int *)(&stack0x00000000 + val_5 * 4) + -1;
      val_4 = *(int *)((int)&stack0x00000080 + val_2);
      val_3 = val_5;
      if (unaff_retaddr < 0) {
        return 0;
      }
      do {
        if (-1 < *(int *)(&stack0x00000000 + val_2)) break;
        *(int32_t *)(&stack0x00000000 + val_2) = 1;
        val_3 = val_3 + -1;
        *(int *)(&stack0xfffffffc + val_2) = *(int *)(&stack0xfffffffc + val_2) + -1;
        val_4 = *(int *)(&stack0x0000007c + val_2);
        val_2 = val_2 + -4;
      } while (-1 < unaff_retaddr);
    }
    val_5 = val_3;
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


int FUN_0048be80(int32_t *arg_1,uint32_t *arg_2,int event_type)

{
  int val_1;
  int32_t *u_ptr_2;
  int val_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int slot_idx;
  
  slot_idx = 0;
  g_WaveletDecompressCursor = arg_2;
  DAT_0053aa94 = arg_2;
  val_3 = DAT_0053aa9c + -1;
  DAT_0053aa98 = arg_3;
  g_WaveletBitsRemaining = 0;
  do {
    if (g_WaveletBitsRemaining == 0) {
      if ((int)g_WaveletDecompressCursor - (int)DAT_0053aa94 < DAT_0053aa98) {
        g_WaveletBitAccumulator = *g_WaveletDecompressCursor;
        g_WaveletDecompressCursor = g_WaveletDecompressCursor + 1;
        g_WaveletBitsRemaining = 0x20;
        goto LAB_0048bf03;
      }
      uval_5 = 0xffffffff;
    }
    else {
LAB_0048bf03:
      uval_5 = (uint32_t)((g_WaveletBitAccumulator & 1) != 0);
      g_WaveletBitAccumulator = g_WaveletBitAccumulator >> 1;
      g_WaveletBitsRemaining = g_WaveletBitsRemaining - 1;
    }
    if (uval_5 == 0xffffffff) {
      return slot_idx;
    }
    if (uval_5 == 0) {
      val_1 = (&DAT_0053aaac)[val_3 * 2];
    }
    else {
      val_1 = (&DAT_0053aaa8)[val_3 * 2];
    }
    val_3 = val_1 - DAT_0053aaa0;
    if (val_3 < 0) {
      if (val_1 == 0) {
        if (g_WaveletBitsRemaining < 10) {
          val_3 = 10 - g_WaveletBitsRemaining;
          if ((int)g_WaveletDecompressCursor + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uval_5 = *g_WaveletDecompressCursor;
            g_WaveletDecompressCursor = g_WaveletDecompressCursor + 1;
            uval_4 = g_WaveletBitAccumulator | ((&g_WaveletBitmaskTable)[-val_3] & uval_5) << ((uint8_t)g_WaveletBitsRemaining & 0x1f);
            g_WaveletBitAccumulator = uval_5 >> ((uint8_t)val_3 & 0x1f);
            g_WaveletBitsRemaining = 0x20 - val_3;
          }
          else {
            uval_4 = 0xffffffff;
          }
        }
        else {
          uval_4 = DAT_00539e60 & g_WaveletBitAccumulator;
          g_WaveletBitAccumulator = g_WaveletBitAccumulator >> 10;
          g_WaveletBitsRemaining = g_WaveletBitsRemaining - 10;
        }
        if ((int)uval_4 < 0) {
          return slot_idx;
        }
        u_ptr_2 = arg_1 + uval_4;
        for (uval_5 = uval_4 & 0x3fffffff; uval_5 != 0; uval_5 = uval_5 - 1) {
          *arg_1 = 0;
          arg_1 = arg_1 + 1;
        }
        for (val_3 = 0; val_3 != 0; val_3 = val_3 + -1) {
          *(uint8_t *)arg_1 = 0;
          arg_1 = (int32_t *)((int)arg_1 + 1);
        }
        slot_idx = slot_idx + uval_4;
      }
      else {
        u_ptr_2 = arg_1 + 1;
        slot_idx = slot_idx + 1;
        *arg_1 = *(int32_t *)(DAT_0053aaa4 + val_1 * 4);
      }
      val_3 = DAT_0053aa9c + -1;
      arg_1 = u_ptr_2;
    }
  } while( true );
}

/*
 * Decompiled function: FUN_0048c070
 * Entry Point: 0048c070
 * Size: 1619 bytes
 */


int FUN_0048c070(int *arg_1,uint32_t *arg_2,int event_type)

{
  int *i_ptr_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int val_6;
  uint32_t uval_7;
  int *piVar8;
  uint8_t slot_idx;
  
  g_WaveletDecompressCursor = arg_2;
  if (((uint32_t)arg_2 & 3) == 0) {
    g_WaveletBitsRemaining = 0;
    g_WaveletBitAccumulator = 0;
  }
  else {
    val_5 = 4 - ((uint32_t)arg_2 & 3);
    g_WaveletBitsRemaining = val_5 * 8;
    g_WaveletDecompressCursor = (uint32_t *)(val_5 + (int)arg_2);
    g_WaveletBitAccumulator = 0xffffffffU >> (0x20U - (char)g_WaveletBitsRemaining & 0x1f) & *arg_2;
  }
  i_ptr_1 = arg_1;
  DAT_0053aa98 = arg_3;
  DAT_0053aa94 = arg_2;
  if (g_WaveletBitsRemaining < 8) {
    val_5 = 8 - g_WaveletBitsRemaining;
    if ((int)g_WaveletDecompressCursor + (4 - (int)arg_2) < arg_3) {
      uval_2 = *g_WaveletDecompressCursor;
      g_WaveletDecompressCursor = g_WaveletDecompressCursor + 1;
      uval_7 = g_WaveletBitAccumulator | ((&g_WaveletBitmaskTable)[-val_5] & uval_2) << ((uint8_t)g_WaveletBitsRemaining & 0x1f);
      g_WaveletBitAccumulator = uval_2 >> ((uint8_t)val_5 & 0x1f);
      g_WaveletBitsRemaining = 0x20 - val_5;
    }
    else {
      uval_7 = 0xffffffff;
    }
  }
  else {
    uval_7 = DAT_00539e68 & g_WaveletBitAccumulator;
    g_WaveletBitAccumulator = g_WaveletBitAccumulator >> 8;
    g_WaveletBitsRemaining = g_WaveletBitsRemaining - 8;
  }
  while (uval_7 != 0xffffffff) {
    val_5 = (&DAT_00539e90)[uval_7 * 3];
    if (val_5 < 0x7fffffff) {
      uval_2 = (&DAT_00539e94)[uval_7 * 3];
      slot_idx = (uint8_t)uval_2;
      if (val_5 == -0x80000000) {
        uval_2 = uval_2 + 2;
        if (g_WaveletBitsRemaining < uval_2) {
          uval_2 = uval_2 - g_WaveletBitsRemaining;
          if ((int)g_WaveletDecompressCursor + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uval_3 = *g_WaveletDecompressCursor;
            g_WaveletDecompressCursor = g_WaveletDecompressCursor + 1;
            uval_4 = g_WaveletBitAccumulator | ((&g_WaveletBitmaskTable)[-uval_2] & uval_3) << ((uint8_t)g_WaveletBitsRemaining & 0x1f);
            g_WaveletBitAccumulator = uval_3 >> ((uint8_t)uval_2 & 0x1f);
            g_WaveletBitsRemaining = 0x20;
            goto LAB_0048c281;
          }
          uval_4 = 0xffffffff;
        }
        else {
          uval_4 = (&g_WaveletBitmaskTable)[-uval_2] & g_WaveletBitAccumulator;
          g_WaveletBitAccumulator = g_WaveletBitAccumulator >> ((uint8_t)uval_2 & 0x1f);
LAB_0048c281:
          g_WaveletBitsRemaining = g_WaveletBitsRemaining - uval_2;
        }
        if ((int)uval_4 < 0) break;
        uval_7 = uval_4 << (8 - slot_idx & 0x1f) | (int)uval_7 >> (slot_idx & 0x1f);
        uval_2 = uval_7;
        piVar8 = i_ptr_1;
        if (((uint32_t)i_ptr_1 & 4) == 0) {
LAB_0048c2bd:
          uval_3 = uval_2 >> 1;
          if (uval_3 != 0) {
            while (uval_3 = uval_3 - 1, uval_3 != 0) {
              piVar8[0] = 0;
              piVar8[1] = 0;
              piVar8 = piVar8 + 2;
            }
            piVar8[0] = 0;
            piVar8[1] = 0;
          }
          if ((uval_2 & 1) != 0) {
            *(uint8_t *)piVar8 = 0;
          }
        }
        else {
          *(uint8_t *)i_ptr_1 = 0;
          piVar8 = i_ptr_1 + 1;
          uval_2 = uval_7 - 1;
          if (uval_2 != 0 && 0 < (int)uval_7) goto LAB_0048c2bd;
        }
        i_ptr_1 = i_ptr_1 + uval_7;
        if (g_WaveletBitsRemaining < 8) {
          if ((int)g_WaveletDecompressCursor + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
LAB_0048c661:
            val_5 = 8 - g_WaveletBitsRemaining;
            uval_2 = *g_WaveletDecompressCursor;
            g_WaveletDecompressCursor = g_WaveletDecompressCursor + 1;
            uval_7 = g_WaveletBitAccumulator | ((&g_WaveletBitmaskTable)[-val_5] & uval_2) << ((uint8_t)g_WaveletBitsRemaining & 0x1f);
            g_WaveletBitAccumulator = uval_2 >> ((uint8_t)val_5 & 0x1f);
            g_WaveletBitsRemaining = 0x20 - val_5;
          }
          else {
LAB_0048c65a:
            uval_7 = 0xffffffff;
          }
        }
        else {
          uval_7 = DAT_00539e68 & g_WaveletBitAccumulator;
          g_WaveletBitAccumulator = g_WaveletBitAccumulator >> 8;
          g_WaveletBitsRemaining = g_WaveletBitsRemaining - 8;
        }
      }
      else {
        *i_ptr_1 = val_5;
        i_ptr_1 = i_ptr_1 + 1;
        if (g_WaveletBitsRemaining < uval_2) {
          uval_2 = uval_2 - g_WaveletBitsRemaining;
          if ((int)g_WaveletDecompressCursor + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uval_3 = *g_WaveletDecompressCursor;
            g_WaveletDecompressCursor = g_WaveletDecompressCursor + 1;
            uval_4 = g_WaveletBitAccumulator | ((&g_WaveletBitmaskTable)[-uval_2] & uval_3) << ((uint8_t)g_WaveletBitsRemaining & 0x1f);
            g_WaveletBitAccumulator = uval_3 >> ((uint8_t)uval_2 & 0x1f);
            g_WaveletBitsRemaining = 0x20;
            goto LAB_0048c419;
          }
          uval_4 = 0xffffffff;
        }
        else {
          uval_4 = (&g_WaveletBitmaskTable)[-uval_2] & g_WaveletBitAccumulator;
          g_WaveletBitAccumulator = g_WaveletBitAccumulator >> (slot_idx & 0x1f);
LAB_0048c419:
          g_WaveletBitsRemaining = g_WaveletBitsRemaining - uval_2;
        }
        if (uval_4 == 0xffffffff) break;
        uval_7 = (int)uval_7 >> (slot_idx & 0x1f) | uval_4 << (8 - slot_idx & 0x1f);
      }
    }
    else {
      val_5 = (&DAT_00539e98)[uval_7 * 3];
      do {
        if (g_WaveletBitsRemaining == 0) {
          if ((int)g_WaveletDecompressCursor - (int)DAT_0053aa94 < DAT_0053aa98) {
            g_WaveletBitAccumulator = *g_WaveletDecompressCursor;
            g_WaveletDecompressCursor = g_WaveletDecompressCursor + 1;
            g_WaveletBitsRemaining = 0x20;
            goto LAB_0048c492;
          }
          uval_2 = 0xffffffff;
        }
        else {
LAB_0048c492:
          uval_2 = (uint32_t)((g_WaveletBitAccumulator & 1) != 0);
          g_WaveletBitAccumulator = g_WaveletBitAccumulator >> 1;
          g_WaveletBitsRemaining = g_WaveletBitsRemaining - 1;
        }
        if (uval_2 == 0xffffffff) goto LAB_0048c5f9;
        if (uval_2 == 0) {
          val_6 = (&DAT_0053aaac)[val_5 * 2];
        }
        else {
          val_6 = (&DAT_0053aaa8)[val_5 * 2];
        }
        val_5 = val_6 - DAT_0053aaa0;
      } while (-1 < val_5);
      if (val_6 == 0) {
        if (g_WaveletBitsRemaining < 10) {
          val_5 = 10 - g_WaveletBitsRemaining;
          if ((int)g_WaveletDecompressCursor + (4 - (int)DAT_0053aa94) < DAT_0053aa98) {
            uval_2 = *g_WaveletDecompressCursor;
            g_WaveletDecompressCursor = g_WaveletDecompressCursor + 1;
            uval_7 = g_WaveletBitAccumulator | ((&g_WaveletBitmaskTable)[-val_5] & uval_2) << ((uint8_t)g_WaveletBitsRemaining & 0x1f);
            g_WaveletBitAccumulator = uval_2 >> ((uint8_t)val_5 & 0x1f);
            g_WaveletBitsRemaining = 0x20 - val_5;
          }
          else {
            uval_7 = 0xffffffff;
          }
        }
        else {
          uval_7 = DAT_00539e60 & g_WaveletBitAccumulator;
          g_WaveletBitAccumulator = g_WaveletBitAccumulator >> 10;
          g_WaveletBitsRemaining = g_WaveletBitsRemaining - 10;
        }
        if (-1 < (int)uval_7) {
          uval_2 = uval_7;
          piVar8 = i_ptr_1;
          if (((uint32_t)i_ptr_1 & 4) == 0) {
LAB_0048c5c3:
            uval_3 = uval_2 >> 1;
            if (uval_3 != 0) {
              while (uval_3 = uval_3 - 1, uval_3 != 0) {
                piVar8[0] = 0;
                piVar8[1] = 0;
                piVar8 = piVar8 + 2;
              }
              piVar8[0] = 0;
              piVar8[1] = 0;
            }
            if ((uval_2 & 1) != 0) {
              *(uint8_t *)piVar8 = 0;
            }
          }
          else {
            *(uint8_t *)i_ptr_1 = 0;
            piVar8 = i_ptr_1 + 1;
            uval_2 = uval_7 - 1;
            if (uval_2 != 0 && 0 < (int)uval_7) goto LAB_0048c5c3;
          }
          i_ptr_1 = i_ptr_1 + uval_7;
        }
      }
      else {
        *i_ptr_1 = *(int *)(DAT_0053aaa4 + val_6 * 4);
        i_ptr_1 = i_ptr_1 + 1;
      }
LAB_0048c5f9:
      if (g_WaveletBitsRemaining < 8) {
        if ((int)g_WaveletDecompressCursor + (4 - (int)DAT_0053aa94) < DAT_0053aa98) goto LAB_0048c661;
        goto LAB_0048c65a;
      }
      uval_7 = DAT_00539e68 & g_WaveletBitAccumulator;
      g_WaveletBitAccumulator = g_WaveletBitAccumulator >> 8;
      g_WaveletBitsRemaining = g_WaveletBitsRemaining - 8;
    }
  }
  return (int)i_ptr_1 - (int)arg_1 >> 2;
}

/*
 * Decompiled function: FUN_0048c6d0
 * Entry Point: 0048c6d0
 * Size: 80 bytes
 */


int FUN_0048c6d0(int player_id)

{
  int val_1;
  
  if ((arg_1 < 0) || (9 < arg_1)) {
    if ((arg_1 < 10) || (0xf < arg_1)) {
      val_1 = 0;
    }
    else {
      val_1 = arg_1 + 0x57;
    }
  }
  else {
    val_1 = arg_1 + 0x30;
  }
  return val_1;
}

/*
 * Decompiled function: SaveGame_LoadCampaignFile
 * Entry Point: 0048c72a
 * Size: 387 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SaveGame_LoadCampaignFile(int player_id)

{
  int val_1;
  uint32_t slot_idx;
  
  DAT_0054aab0 = 1;
  UI_PrepareCombatViewport();
  val_1 = FUN_0048cb40();
  if (val_1 == -1) {
    Pic_Subsystem_0044b8aa();
    val_1 = -1;
  }
  else {
    if (arg_1 == -1) {
      strcpy(&g_OverworldWorldState,&DAT_00527c50);
      _DAT_0063ee7c = 0;
      for (slot_idx = 0; slot_idx < 10; slot_idx = slot_idx + 1) {
        s_D_MAGIC0_SVE_00527b48[7] = FUN_0048c6d0(slot_idx);
        val_1 = FUN_0048c8b2(s_D_MAGIC0_SVE_00527b48,1);
        if (val_1 != 0) {
          _DAT_0063ee7c = _DAT_0063ee7c | 1 << ((uint8_t)slot_idx & 0x1f);
        }
      }
      Pic_Subsystem_0044b8aa();
      DAT_00627a78 = FUN_00489710(&g_OverworldWorldState,0x30,0x40);
      UI_PrepareCombatViewport();
      if ((_DAT_0063ee7c & 1 << ((uint8_t)DAT_00627a78 & 0x1f)) == 0) {
        DAT_00627a78 = -1;
      }
    }
    else {
      DAT_00627a78 = arg_1;
    }
    if (DAT_00627a78 != -1) {
      s_D_MAGIC0_SVE_00527b48[7] = FUN_0048c6d0(DAT_00627a78);
      val_1 = FUN_0048c8b2(s_D_MAGIC0_SVE_00527b48,0);
      if (val_1 == 0) {
        DAT_00627a78 = -1;
      }
    }
    if (DAT_00627a78 == -1) {
      FUN_00489710(s_Error_Loading_Save_Game_File_EXI_00527c68,100,0x50);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    Pic_Subsystem_0044b8aa();
    val_1 = DAT_00627a78;
  }
  return val_1;
}

/*
 * Decompiled function: FUN_0048c8b2
 * Entry Point: 0048c8b2
 * Size: 180 bytes
 */


uint32_t FUN_0048c8b2(char *filepath,int arg2)

{
  uint32_t uval_1;
  
  strcpy(str_1 + 9,&DAT_00527c90);
  if (arg2 == 0) {
    uval_1 = FUN_0048ce07(str_1);
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
    uval_1 = (uint32_t)(DAT_0054aab8 != -1);
  }
  return uval_1;
}

/*
 * Decompiled function: SaveGame_SaveCampaignFile
 * Entry Point: 0048c970
 * Size: 319 bytes
 */


void SaveGame_SaveCampaignFile(int player_id)

{
  int val_1;
  
  DAT_0054aad4 = 0;
  DAT_0054aab0 = 0;
  UI_PrepareCombatViewport();
  val_1 = FUN_0048cb40();
  if (val_1 != -1) {
    if (arg_1 == -1) {
      Pic_Subsystem_0044b8aa();
      arg_1 = FUN_00489710(&g_OverworldWorldState,0x30,0x20);
      UI_PrepareCombatViewport();
    }
    if (arg_1 != -1) {
      DAT_00627a78 = arg_1;
      s_D_MAGIC0_SVE_00527b48[7] = FUN_0048c6d0(arg_1);
      val_1 = FUN_0048caaf(s_D_MAGIC0_SVE_00527b48);
      if (val_1 != 0) {
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


int32_t FUN_0048caaf(char *arg_1)

{
  strcpy(&g_OverworldWorldState,&DAT_00527d14);
  strcat(&g_OverworldWorldState,s_____save_in_progress__00527d18);
  Overworld_SaveMapFile(arg_1);
  return 1;
}

/*
 * Decompiled function: FUN_0048caf4
 * Entry Point: 0048caf4
 * Size: 71 bytes
 */


bool FUN_0048caf4(int player_id,void *arg_2,uint32_t arg_3)

{
  int val_1;
  int *i_ptr_2;
  
  val_1 = _write(arg_1,arg_2,arg_3);
  if (val_1 == -1) {
    i_ptr_2 = _errno();
    DAT_0054aad4 = *i_ptr_2;
  }
  return val_1 != -1;
}

/*
 * Decompiled function: FUN_0048cb40
 * Entry Point: 0048cb40
 * Size: 84 bytes
 */


int FUN_0048cb40(void)

{
  int val_1;
  char local_108 [260];
  
  if (DAT_00527c4c == -1) {
    GetCurrentDirectoryA(0x100,local_108);
    s_D_MAGIC0_SVE_00527b48[0] = local_108[0];
  }
  val_1 = tolower((int)s_D_MAGIC0_SVE_00527b48[0]);
  return val_1 + -0x61;
}

/*
 * Decompiled function: Mem_AllocOrFree_0048cdf5
 * Entry Point: 0048cdf5
 * Size: 18 bytes
 */


int32_t Mem_AllocOrFree_0048cdf5(void)

{
  return 0;
}

/*
 * Decompiled function: FUN_0048ce07
 * Entry Point: 0048ce07
 * Size: 640 bytes
 */


int32_t FUN_0048ce07(char *filepath)

{
  int32_t uval_1;
  int local_5c [4];
  int local_4c [9];
  int *local_28;
  int32_t loop_idx;
  int target_idx;
  int player_idx;
  int match_count;
  int slot_idx;
  
  strcpy(str_1 + 9,&DAT_00527e2c);
  DAT_0054aab8 = _open(str_1,0x8000);
  if (DAT_0054aab8 == -1) {
    strcpy(&g_OverworldWorldState,s_File_Error__00527e30);
    strcat(&g_OverworldWorldState,str_1);
    strcat(&g_OverworldWorldState,&DAT_00527e40);
    FUN_00489710(&g_OverworldWorldState,100,0x50);
    uval_1 = 0;
  }
  else {
    DAT_0054aab0 = 1;
    FUN_0048d259();
    _close(DAT_0054aab8);
    for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
      for (match_count = 0; match_count < 0x50; match_count = match_count + 1) {
        if (*(int *)(&g_CardSlot_CardId + match_count * 0x120 + slot_idx * 0x5b20) != -1) {
          (&g_PlayerActiveCardCount)[slot_idx] = match_count;
        }
      }
    }
    if (g_AiCombatScore_Blocker == 0) {
      UI_PrepareCombatViewport();
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
    player_idx = 0x89;
    target_idx = 0xa9;
    loop_idx = Memory_AllocateVirtualPage(4,0x112,0xa9,8);
    FUN_0050d370(4,loop_idx);
    FUN_0050e6f0(local_5c,(int)local_28,0,0,player_idx * 2,target_idx);
    Surface_FillRect(local_28,0,0,player_idx * 2,target_idx,0);
    strcpy(str_1 + 9,&DAT_00527e48);
    Mem_AllocOrFree_00510e20(4,str_1);
    DAT_0067bdd8 = *(int32_t *)(DAT_0070a860 + 8);
    DAT_0067bdd4 = DAT_0070a860;
    SelectObject(*(HDC *)(DAT_0070a860 + 4),*(HGDIOBJ *)(DAT_0070a860 + 0xc));
    DAT_0070a860 = 0;
    Sprite_Load__16faces_0047c1a7(DAT_006ff678);
    uval_1 = 1;
  }
  return uval_1;
}

/*
 * Decompiled function: Overworld_SaveMapFile
 * Entry Point: 0048d087
 * Size: 466 bytes
 */


int32_t Overworld_SaveMapFile(char *filepath)

{
  int val_1;
  int32_t uval_2;
  int32_t local_44;
  int32_t local_40;
  int32_t local_3c;
  int32_t local_38;
  int32_t local_34;
  int32_t local_30;
  int32_t local_2c;
  int32_t local_28;
  int32_t local_24;
  int32_t *loop_idx;
  
  if (g_AiCombatScore_Blocker == 0) {
    strcpy(str_1 + 9,&DAT_00527e4c);
    val_1 = FUN_00512ba0(2,str_1);
    if (val_1 != 0) {
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
    uval_2 = 0;
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
    loop_idx = &local_44;
    DAT_0070a860 = DAT_0067bdd4;
    strcpy(str_1 + 9,&DAT_00527e84);
    FUN_00512c00(4,0,0,*(int32_t *)(DAT_0067bdd4 + 0x20),*(int32_t *)(DAT_0067bdd4 + 0x24),0,
                 str_1);
    DAT_0070a860 = 0;
    if (DAT_0054aad4 == 0) {
      uval_2 = 1;
    }
    else {
      uval_2 = 0;
    }
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0048d259
 * Entry Point: 0048d259
 * Size: 3524 bytes
 */


uint32_t FUN_0048d259(void)

{
  uint32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  uint32_t uval_6;
  uint32_t uval_7;
  uint32_t uval_8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  uint32_t uVar12;
  uint32_t uVar13;
  uint32_t uVar14;
  uint32_t uVar15;
  uint32_t uVar16;
  uint32_t uVar17;
  uint32_t uVar18;
  uint32_t uVar19;
  uint32_t uVar20;
  uint32_t uVar21;
  uint32_t uVar22;
  uint32_t uVar23;
  uint32_t uVar24;
  uint32_t uVar25;
  uint32_t uVar26;
  uint32_t uVar27;
  uint32_t uVar28;
  uint32_t uVar29;
  uint32_t uVar30;
  uint32_t uVar31;
  uint32_t uVar32;
  uint32_t uVar33;
  uint32_t uVar34;
  uint32_t uVar35;
  uint32_t uVar36;
  uint32_t uVar37;
  uint32_t uVar38;
  uint32_t uVar39;
  uint32_t uVar40;
  uint32_t uVar41;
  uint32_t uVar42;
  uint32_t uVar43;
  uint32_t uVar44;
  uint32_t uVar45;
  uint32_t uVar46;
  uint32_t uVar47;
  uint32_t uVar48;
  uint32_t uVar49;
  uint32_t uVar50;
  uint32_t uVar51;
  uint32_t uVar52;
  uint32_t uVar53;
  uint32_t uVar54;
  uint32_t uVar55;
  uint32_t uVar56;
  uint32_t uVar57;
  uint32_t uVar58;
  uint32_t uVar59;
  uint32_t uVar60;
  uint32_t uVar61;
  uint32_t uVar62;
  uint32_t uVar63;
  uint32_t uVar64;
  uint32_t uVar65;
  uint32_t uVar66;
  uint32_t uVar67;
  uint32_t uVar68;
  uint32_t uVar69;
  uint32_t uVar70;
  uint32_t uVar71;
  uint32_t uVar72;
  uint32_t uVar73;
  uint32_t uVar74;
  uint32_t uVar75;
  uint32_t uVar76;
  uint32_t uVar77;
  uint32_t uVar78;
  uint32_t uVar79;
  uint32_t uVar80;
  uint32_t uVar81;
  uint32_t uVar82;
  uint32_t uVar83;
  uint32_t uVar84;
  uint32_t uVar85;
  uint32_t uVar86;
  uint32_t uVar87;
  uint32_t uVar88;
  uint32_t uVar89;
  uint32_t uVar90;
  uint32_t uVar91;
  uint32_t uVar92;
  uint32_t uVar93;
  uint32_t uVar94;
  uint32_t uVar95;
  uint32_t uVar96;
  uint32_t uVar97;
  uint32_t uVar98;
  uint32_t uVar99;
  uint32_t uVar100;
  uint32_t uVar101;
  uint32_t uVar102;
  uint32_t uVar103;
  uint32_t uVar104;
  uint32_t uVar105;
  uint32_t uVar106;
  uint32_t uVar107;
  uint32_t uVar108;
  uint32_t uVar109;
  uint32_t uVar110;
  uint32_t uVar111;
  uint32_t uVar112;
  uint32_t uVar113;
  uint32_t uVar114;
  uint32_t uVar115;
  uint32_t uVar116;
  uint32_t uVar117;
  uint32_t uVar118;
  uint32_t uVar119;
  uint32_t uVar120;
  uint32_t uVar121;
  uint32_t uVar122;
  uint32_t uVar123;
  uint32_t uVar124;
  uint32_t uVar125;
  uint32_t uVar126;
  uint32_t uVar127;
  uint32_t uVar128;
  uint32_t uVar129;
  uint32_t uVar130;
  uint32_t uVar131;
  uint32_t uVar132;
  uint32_t uVar133;
  uint32_t uVar134;
  uint32_t uVar135;
  uint32_t uVar136;
  uint32_t uVar137;
  uint32_t uVar138;
  uint32_t uVar139;
  uint32_t uVar140;
  uint32_t uVar141;
  uint32_t uVar142;
  uint32_t uVar143;
  uint32_t uVar144;
  uint32_t uVar145;
  uint32_t uVar146;
  uint32_t uVar147;
  uint32_t uVar148;
  uint32_t uVar149;
  uint32_t uVar150;
  uint32_t uVar151;
  uint32_t uVar152;
  uint32_t uVar153;
  uint32_t uVar154;
  uint32_t uVar155;
  uint32_t uVar156;
  uint32_t uVar157;
  uint32_t uVar158;
  uint32_t uVar159;
  uint32_t uVar160;
  uint32_t uVar161;
  uint32_t uVar162;
  uint32_t uVar163;
  uint32_t uVar164;
  uint32_t uVar165;
  uint32_t uVar166;
  uint32_t uVar167;
  uint32_t uVar168;
  uint32_t uVar169;
  uint32_t uVar170;
  uint32_t uVar171;
  uint32_t uVar172;
  uint32_t uVar173;
  uint32_t uVar174;
  uint32_t uVar175;
  uint32_t uVar176;
  uint32_t uVar177;
  uint32_t uVar178;
  uint32_t uVar179;
  uint32_t uVar180;
  uint32_t uVar181;
  uint32_t uVar182;
  uint32_t uVar183;
  uint32_t uVar184;
  uint32_t uVar185;
  uint32_t uVar186;
  uint32_t uVar187;
  uint32_t uVar188;
  
  uval_1 = FUN_0048e01d(&g_MasterCardTable + g_MasterCardCount * 0x34,0x340);
  uval_2 = FUN_0048e01d(&DAT_00516cb8,0x500);
  uval_3 = FUN_0048e01d(&g_TemporaryToughnessBuffer,4);
  uval_4 = FUN_0048e01d(&DAT_00627858,4);
  uval_5 = FUN_0048e01d(&g_AiGameStateBackupBuffer,4);
  uval_6 = FUN_0048e01d(&DAT_00627a88,4);
  uval_7 = FUN_0048e01d(&DAT_00627a84,4);
  uval_8 = FUN_0048e01d(&g_AiTemporaryCardState,4);
  uVar9 = FUN_0048e01d(&DAT_00627a0c,4);
  uVar10 = FUN_0048e01d(&DAT_0063ee1c,4);
  uVar11 = FUN_0048e01d(&DAT_00633434,4);
  uVar12 = FUN_0048e01d(&DAT_00676c8c,4);
  uVar13 = FUN_0048e01d(&DAT_0063edc8,4);
  uVar14 = FUN_0048e01d(&DAT_0063ee70,4);
  uVar15 = FUN_0048e01d(&DAT_0063ee10,4);
  uVar16 = FUN_0048e01d(&DAT_0063ee78,4);
  uVar17 = FUN_0048e01d(&DAT_00627a08,4);
  uVar18 = FUN_0048e01d(&DAT_0063eed8,4);
  uVar19 = FUN_0048e01d(&DAT_0063edc4,4);
  uVar20 = FUN_0048e01d(&g_CurrentTurnTargetPlayer,4);
  uVar21 = FUN_0048e01d(&DAT_00627a10,4);
  uVar22 = FUN_0048e01d(&g_AiCombatScore_Total,0x40);
  uVar23 = FUN_0048e01d(&DAT_00627870,0x198);
  uVar24 = FUN_0048e01d(&g_AiTempTargetBuffer,0x58);
  uVar25 = FUN_0048e01d(&DAT_0063eed0,8);
  uVar26 = FUN_0048e01d(&g_AiLookaheadDepth,0x40);
  uVar27 = FUN_0048e01d(&g_AiCombatScore_Attacker,0x40);
  uVar28 = FUN_0048e01d(&g_AiCombatLookaheadTarget,4);
  uVar29 = FUN_0048e01d(&DAT_00627868,4);
  uVar30 = FUN_0048e01d(&DAT_0063ee80,4);
  uVar31 = FUN_0048e01d(&g_AiCombatScore_Blocker,4);
  uVar32 = FUN_0048e01d(&g_PendingSpellResolutionFlag,4);
  uVar33 = FUN_0048e01d(&DAT_0063ee24,4);
  uVar34 = FUN_0048e01d(&DAT_0063ee14,4);
  uVar35 = FUN_0048e01d(&deck,2000);
  uVar36 = FUN_0048e01d(&g_ActiveCardsInPlay,0xb640);
  uVar37 = FUN_0048e01d(&DAT_00700ec0,0x140);
  uVar38 = FUN_0048e01d(&g_PlayerGraveyardList,4000);
  uVar39 = FUN_0048e01d(&DAT_006b1590,4000);
  uVar40 = FUN_0048e01d(&g_PlayerDeckCardList,4000);
  uVar41 = FUN_0048e01d(&DAT_006b2d90,0x80);
  uVar42 = FUN_0048e01d(&DAT_007006d4,4);
  uVar43 = FUN_0048e01d(&DAT_006ff2d8,4);
  uVar44 = FUN_0048e01d(&g_AiDecisionScore,4);
  uVar45 = FUN_0048e01d(&g_AiCurrentSearchPath,4);
  uVar46 = FUN_0048e01d(&DAT_006b3000,0x60);
  uVar47 = FUN_0048e01d(&DAT_0068a668,8);
  uVar48 = FUN_0048e01d(&g_AiSelectedTargetCard,0x1c);
  uVar49 = FUN_0048e01d(&DAT_006fdbd8,4);
  uVar50 = FUN_0048e01d(&g_PlayerLifeTotals,0x10);
  uVar51 = FUN_0048e01d(&g_ActivePlayer,4);
  uVar52 = FUN_0048e01d(&g_PlayerActiveCardCount,8);
  uVar53 = FUN_0048e01d(&DAT_00680790,4);
  uVar54 = FUN_0048e01d(&DAT_00695e10,100);
  uVar55 = FUN_0048e01d(&g_PlayerCreatureCount,8);
  uVar56 = FUN_0048e01d(&DAT_00696870,8);
  uVar57 = FUN_0048e01d(&DAT_006ff4b8,8);
  uVar58 = FUN_0048e01d(&DAT_00695eb0,0x10);
  uVar59 = FUN_0048e01d(&g_DefendingPlayer,4);
  uVar60 = FUN_0048e01d(&DAT_006b2d64,4);
  uVar61 = FUN_0048e01d(&g_SpellStackDepth,4);
  uVar62 = FUN_0048e01d(&g_ScWillyScore,4);
  uVar63 = FUN_0048e01d(&g_PlayerHandCardCount,4);
  uVar64 = FUN_0048e01d(&g_ActiveBattlefieldFlag,4);
  uVar65 = FUN_0048e01d(&DAT_0068a67c,4);
  uVar66 = FUN_0048e01d(&DAT_00696a18,4);
  uVar67 = FUN_0048e01d(&DAT_00695df0,4);
  uVar68 = FUN_0048e01d(&g_TurnCounter,4);
  uVar69 = FUN_0048e01d(&g_OverworldPlayerCoordY,4);
  uVar70 = FUN_0048e01d(&g_CurrentTurnPhase,4);
  uVar71 = FUN_0048e01d(&g_ActivePlayerPriority,4);
  uVar72 = FUN_0048e01d(&g_OverworldPlayerCoordX,4);
  uVar73 = FUN_0048e01d(&g_OverworldMapGrid,4);
  uVar74 = FUN_0048e01d(&DAT_006a4f70,4);
  uVar75 = FUN_0048e01d(&DAT_006b2fe4,4);
  uVar76 = FUN_0048e01d(&DAT_007006c8,4);
  uVar77 = FUN_0048e01d(&DAT_006b2d5c,4);
  uVar78 = FUN_0048e01d(&g_ActivePalette,4);
  uVar79 = FUN_0048e01d(&DAT_006a2838,4);
  uVar80 = FUN_0048e01d(&DAT_006a2840,4);
  uVar81 = FUN_0048e01d(&DAT_0068a650,4);
  uVar82 = FUN_0048e01d(&DAT_0068a708,4);
  uVar83 = FUN_0048e01d(&DAT_006ff190,4);
  uVar84 = FUN_0048e01d(&DAT_006a2830,4);
  uVar85 = FUN_0048e01d(&g_AiCombatDamageAssigned,4);
  uVar86 = FUN_0048e01d(&g_PendingAttackersTargetSlot,4);
  uVar87 = FUN_0048e01d(&g_SelectedTargetPlayer,4);
  uVar88 = FUN_0048e01d(&g_SelectedTargetSlot,4);
  uVar89 = FUN_0048e01d(&DAT_006b2fe8,4);
  uVar90 = FUN_0048e01d(&g_PlayerManaPool,4);
  uVar91 = FUN_0048e01d(&DAT_00695f08,4);
  uVar92 = FUN_0048e01d(&DAT_006b2e14,4);
  uVar93 = FUN_0048e01d(&g_DialogPromptHwnd,4);
  uVar94 = FUN_0048e01d(&g_DuelArenaHwnd,4);
  uVar95 = FUN_0048e01d(&g_CurrentCardColorTarget,4);
  uVar96 = FUN_0048e01d(&g_ActiveCardTargetSlot,4);
  uVar97 = FUN_0048e01d(&g_GlobalEnchantmentCardId,4);
  uVar98 = FUN_0048e01d(&DAT_006b2fe0,4);
  uVar99 = FUN_0048e01d(&DAT_006feebc,4);
  uVar100 = FUN_0048e01d(&DAT_006966f0,0x40);
  uVar101 = FUN_0048e01d(&DAT_006a2844,4);
  uVar102 = FUN_0048e01d(&DAT_006b2538,8);
  uVar103 = FUN_0048e01d(&DAT_006fe3b0,0x40);
  uVar104 = FUN_0048e01d(&DAT_0069f6d8,4);
  uVar105 = FUN_0048e01d(&DAT_006b2d28,4);
  uVar106 = FUN_0048e01d(&DAT_00680788,4);
  uVar107 = FUN_0048e01d(&DAT_00701008,4);
  uVar108 = FUN_0048e01d(&g_TurnPhaseStateFlags,4);
  uVar109 = FUN_0048e01d(&DAT_0068a714,4);
  uVar110 = FUN_0048e01d(&DAT_0068078c,4);
  uVar111 = FUN_0048e01d(&DAT_006fe3f4,4);
  uVar112 = FUN_0048e01d(&DAT_006b2e40,0x40);
  uVar113 = FUN_0048e01d(&DAT_006b2fa0,0x40);
  uVar114 = FUN_0048e01d(&DAT_006ff690,0x40);
  uVar115 = FUN_0048e01d(&g_PlayerPoisonCounters,8);
  uVar116 = FUN_0048e01d(&DAT_006a4a10,8);
  uVar117 = FUN_0048e01d(&DAT_006a3f70,4);
  uVar118 = FUN_0048e01d(&DAT_006fe40c,4);
  uVar119 = FUN_0048e01d(&DAT_006808a8,4);
  uVar120 = FUN_0048e01d(&DAT_00695e00,8);
  uVar121 = FUN_0048e01d(&DAT_006a48f0,0x30);
  uVar122 = FUN_0048e01d(&DAT_006a4934,4);
  uVar123 = FUN_0048e01d(&g_AiManaPoolReserve,4);
  uVar124 = FUN_0048e01d(&DAT_006a4b58,4);
  uVar125 = FUN_0048e01d(&DAT_006a2858,4);
  uVar126 = FUN_0048e01d(&DAT_00680780,8);
  uVar127 = FUN_0048e01d(&DAT_006ff4d0,0x80);
  uVar128 = FUN_0048e01d(&DAT_006fecc0,0x100);
  uVar129 = FUN_0048e01d(&DAT_006ff390,0x100);
  uVar130 = FUN_0048e01d(&DAT_00696880,0x80);
  uVar131 = FUN_0048e01d(&DAT_00695d70,0x80);
  uVar132 = FUN_0048e01d(&g_AiEvaluatedMoveCount,4);
  uVar133 = FUN_0048e01d(&g_CombatPhaseFlags,4);
  uVar134 = FUN_0048e01d(&DAT_006b1584,4);
  uVar135 = FUN_0048e01d(&g_CurrentScanningCardIndex,4);
  uVar136 = FUN_0048e01d(&DAT_006b2e38,4);
  uVar137 = FUN_0048e01d(&DAT_006808b0,4);
  uVar138 = FUN_0048e01d(&DAT_00695df8,4);
  uVar139 = FUN_0048e01d(&DAT_006b1580,4);
  uVar140 = FUN_0048e01d(&g_CardDisplayOrder_Player,2000);
  uVar141 = FUN_0048e01d(&g_CardDisplayOrder_Slot,2000);
  uVar142 = FUN_0048e01d(&DAT_006ff550,4);
  uVar143 = FUN_0048e01d(&DAT_006fe408,4);
  uVar144 = FUN_0048e01d(&DAT_0068a65c,4);
  uVar145 = FUN_0048e01d(&DAT_006ff684,4);
  uVar146 = FUN_0048e01d(&DAT_006b2d24,4);
  uVar147 = FUN_0048e01d(&DAT_006fd3f0,4);
  uVar148 = FUN_0048e01d(&DAT_006ff380,4);
  uVar149 = FUN_0048e01d(&DAT_0052eff8,4);
  uVar150 = FUN_0048e01d(&g_OverworldPlayerDirection,4);
  uVar151 = FUN_0048e01d(&DAT_0052f000,4);
  uVar152 = FUN_0048e01d(&g_CampaignDifficultyLevel,4);
  uVar153 = FUN_0048e01d(&DAT_0067f388,4);
  uVar154 = FUN_0048e01d(&g_TownBuildingCoordinates,0xa0);
  uVar155 = FUN_0048e01d(&g_OverworldMapPixelX,4);
  uVar156 = FUN_0048e01d(&g_OverworldMapPixelY,4);
  uVar157 = FUN_0048e01d(&DAT_0067f37c,4);
  uVar158 = FUN_0048e01d(&g_CardSlot_CreatureType,0x3200);
  uVar159 = FUN_0048e01d(&g_AiHandEvaluationBuffer,4);
  uVar160 = FUN_0048e01d(&g_AiManaColorCost_White,4);
  uVar161 = FUN_0048e01d(&DAT_0067b9a0,4);
  uVar162 = FUN_0048e01d(&g_CampaignCompassHeading,4);
  uVar163 = FUN_0048e01d(&DAT_0067bddc,4);
  uVar164 = FUN_0048e01d(&DAT_0067bdc0,0x14);
  uVar165 = FUN_0048e01d(&Gold,4);
  uVar166 = FUN_0048e01d(&DAT_00522448,4);
  uVar167 = FUN_0048e01d(&DAT_0067b9b0,1000);
  uVar168 = FUN_0048e01d(&g_OverworldMovementFlags,4);
  uVar169 = FUN_0048e01d(&Scards,0xc0);
  uVar170 = FUN_0048e01d(&DAT_0067bdb4,4);
  uVar171 = FUN_0048e01d(&DAT_0067eff0,0x2d0);
  uVar172 = FUN_0048e01d(&DAT_0052f004,4);
  uVar173 = FUN_0048e01d(&DAT_0067f384,4);
  uVar174 = FUN_0048e01d(&DAT_00641020,4);
  uVar175 = FUN_0048e01d(&DAT_006ff678,4);
  uVar176 = FUN_0048e01d(&DAT_006410d8,4);
  uVar177 = FUN_0048e01d(&g_AiCombatLookaheadTarget,4);
  uVar178 = FUN_0048e01d(&g_AiManaColorCost_Blue,4);
  uVar179 = FUN_0048e01d(&_currentDeck,4);
  uVar180 = FUN_0048e01d(&DAT_0067a9a0,0x1000);
  uVar181 = FUN_0048e01d(&DAT_0067bde0,4);
  uVar182 = FUN_0048e01d(&DAT_006fe448,4);
  uVar183 = FUN_0048e01d(&DAT_006fe44c,4);
  uVar184 = FUN_0048e01d(&DAT_006a3f60,4);
  uVar185 = FUN_0048e01d(&DAT_006fe490,4);
  uVar186 = FUN_0048e01d(&DAT_006a4930,4);
  uVar187 = FUN_0048e01d(s_Ned_Way_the_Ratiocinator_0052f020,0x40);
  strcpy(&DAT_0068a6a0,s_Ned_Way_the_Ratiocinator_0052f020);
  uVar188 = FUN_0048e01d(&DAT_006410b0,4);
  return uval_1 & 1 & uval_2 & uval_3 & uval_4 & uval_5 & uval_6 & uval_7 & uval_8 & uVar9 & uVar10 & uVar11
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
 * Decompiled function: FUN_0048e01d
 * Entry Point: 0048e01d
 * Size: 132 bytes
 */


uint32_t FUN_0048e01d(void *arg1,uint32_t arg2)

{
  uint32_t uval_1;
  uint32_t slot_idx;
  
  if (DAT_0054aab0 == 0) {
    slot_idx = FUN_0048caf4(DAT_0054aab8,arg1,arg2);
  }
  else {
    uval_1 = _read(DAT_0054aab8,arg1,arg2);
    slot_idx = (uint32_t)(uval_1 == arg2);
  }
  if (slot_idx == 0) {
    OutputDebugStringA(&DAT_00527e88);
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0048e0a1
 * Entry Point: 0048e0a1
 * Size: 77 bytes
 */


int FUN_0048e0a1(char *filepath)

{
  int val_1;
  int slot_idx;
  
  slot_idx = 0;
  for (; *str_1 != '\0'; str_1 = str_1 + 1) {
    val_1 = FUN_0050f390(*(int *)(g_DisplaySurfaceScreen + 0x20),*str_1);
    slot_idx = slot_idx + val_1;
  }
  return slot_idx;
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


void FUN_0048e122(char *filepath)

{
  DAT_0054aab8 = _open(str_1,0x8301,0x80);
  if (DAT_0054aab8 != -1) {
    DAT_0054aab0 = 0;
    FUN_0048e01d(&DAT_00695e98,4);
    FUN_0048d259();
    FUN_0048e01d(&_PlayerFace,4);
    FUN_0048e01d(&_OpponFace,4);
    FUN_0048e01d(&DAT_006ff310,0x32);
    FUN_0048e01d(&DAT_0068a6a0,0x32);
    _close(DAT_0054aab8);
  }
  return;
}

/*
 * Decompiled function: FUN_0048e1bf
 * Entry Point: 0048e1bf
 * Size: 239 bytes
 */


uint32_t FUN_0048e1bf(char *filepath)

{
  uint32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  uint32_t match_count;
  int slot_idx;
  
  DAT_0054aab8 = _open(str_1,0x8000);
  if (DAT_0054aab8 == -1) {
    match_count = 0;
  }
  else {
    DAT_0054aab0 = 1;
    uval_1 = FUN_0048e01d(&slot_idx,4);
    if (slot_idx == DAT_00695e98) {
      uval_2 = FUN_0048d259();
      uval_3 = FUN_0048e01d(&_PlayerFace,4);
      uval_4 = FUN_0048e01d(&_OpponFace,4);
      uval_5 = FUN_0048e01d(&DAT_006ff310,0x32);
      DAT_006ff342 = 0;
      match_count = FUN_0048e01d(&DAT_0068a6a0,0x32);
      match_count = uval_1 & 1 & uval_2 & uval_3 & uval_4 & uval_5 & match_count;
      DAT_0068a6d2 = 0;
    }
    else {
      match_count = 0;
    }
    _close(DAT_0054aab8);
  }
  return match_count;
}

/*
 * Decompiled function: FUN_0048e2b0
 * Entry Point: 0048e2b0
 * Size: 86 bytes
 */


void FUN_0048e2b0(int player_id)

{
  char cVar1;
  size_t len_2;
  int card_idx;
  
  card_idx = 0;
  len_2 = strlen(&g_OverworldWorldState);
  do {
    cVar1 = (&PTR_s_Castle_Necris_00527f50)[arg_1][card_idx];
    (&g_OverworldWorldState)[card_idx + len_2] = cVar1;
    card_idx = card_idx + 1;
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
  uint8_t flag_1;
  uint8_t flag_2;
  char cVar3;
  int val_4;
  int arg2;
  int val_5;
  uint32_t uval_6;
  int32_t arg_1;
  int local_2c;
  int local_28;
  int local_24;
  int loop_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0xf; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_0067eff8 + slot_idx * 0x30) = 0xffffffff;
    *(int32_t *)(&DAT_0067eff4 + slot_idx * 0x30) =
         *(int32_t *)(&DAT_0067eff8 + slot_idx * 0x30);
    *(int32_t *)(&DAT_0067eff0 + slot_idx * 0x30) =
         *(int32_t *)(&DAT_0067eff4 + slot_idx * 0x30);
    *(int32_t *)(&DAT_0067f018 + slot_idx * 0x30) = 0xffffffff;
    *(int32_t *)(&DAT_0067f01c + slot_idx * 0x30) =
         *(int32_t *)(&DAT_0067f018 + slot_idx * 0x30);
  }
  for (local_2c = 0; local_2c < g_MasterCardCount + -0x29; local_2c = local_2c + 1) {
    if (((&g_MasterCardFlagsTable)[local_2c * 0x34] & 1) != 0) {
      do {
        val_4 = Util_GetRandomNumber(10);
        val_4 = val_4 + 5;
      } while (*(int *)(&DAT_0067eff8 + val_4 * 0x30) != -1);
      if (*(int *)(&DAT_0067eff0 + val_4 * 0x30) == -1) {
        *(int *)(&DAT_0067eff0 + val_4 * 0x30) = local_2c;
      }
      else if (*(int *)(&DAT_0067eff4 + val_4 * 0x30) == -1) {
        *(int *)(&DAT_0067eff4 + val_4 * 0x30) = local_2c;
      }
      else {
        *(int *)(&DAT_0067eff8 + val_4 * 0x30) = local_2c;
      }
    }
  }
  slot_idx = 0;
  do {
    if (0xe < slot_idx) {
      return;
    }
    do {
      do {
        do {
          val_4 = Util_GetRandomNumber(0x40);
          arg2 = Util_GetRandomNumber(0x40);
          val_5 = FUN_0040c761(val_4,arg2);
        } while (val_5 == 0);
        uval_6 = FUN_0040c7c0(val_4,arg2);
      } while ((uval_6 & 0x30) != 0);
      local_28 = 0xff;
      for (loop_idx = 0; loop_idx < 0x80; loop_idx = loop_idx + 1) {
        if ((slot_idx < 5) && (*(int *)(&g_CardSlot_CreatureType + loop_idx * 100) == 4)) {
          arg_1 = FUN_0040c761(*(int *)(&g_DungeonMapTileX + loop_idx * 100),
                               *(int *)(&g_DungeonMapTileY + loop_idx * 100));
          val_5 = Glue_Subsystem_004ea7a6(arg_1);
          if (val_5 == 1 << ((char)slot_idx + 1U & 0x1f)) {
            card_idx = loop_idx;
          }
        }
        if (((1 < *(int *)(&g_CardSlot_CreatureType + loop_idx * 100)) &&
            (*(int *)(&g_CardSlot_CreatureType + loop_idx * 100) != 4)) &&
           (val_5 = FUN_0040a36f(*(int *)(&g_DungeonMapTileX + loop_idx * 100) - val_4,
                                 *(int *)(&g_DungeonMapTileY + loop_idx * 100) - arg2), val_5 < local_28)
           ) {
          local_24 = loop_idx;
          local_28 = val_5;
        }
      }
      for (loop_idx = 0; loop_idx < slot_idx; loop_idx = loop_idx + 1) {
        val_5 = FUN_0040a36f(*(int *)(&DAT_0067f000 + loop_idx * 0x30) - val_4,
                             *(int *)(&DAT_0067f004 + loop_idx * 0x30) - arg2);
        if (val_5 < local_28) {
          local_28 = val_5;
        }
      }
    } while (local_28 < 4);
    FUN_0040c81c(0x40,val_4,arg2);
    *(int *)(&DAT_0067f000 + slot_idx * 0x30) = val_4;
    *(int *)(&DAT_0067f004 + slot_idx * 0x30) = arg2;
    *(int *)(&DAT_0067f008 + slot_idx * 0x30) = local_24;
    cVar3 = Util_GetRandomNumber(5);
    (&DAT_0067f00c)[slot_idx * 0x30] = cVar3 + '\x01';
    (&DAT_0067f00d)[slot_idx * 0x30] = 2;
    if (slot_idx < 5) {
      (&DAT_0067f00c)[slot_idx * 0x30] = (char)slot_idx + '\x01';
      (&DAT_0067f00d)[slot_idx * 0x30] = 0x81;
      *(int32_t *)(&DAT_0067f000 + slot_idx * 0x30) =
           *(int32_t *)(&g_DungeonMapTileX + card_idx * 100);
      *(int32_t *)(&DAT_0067f004 + slot_idx * 0x30) =
           *(int32_t *)(&g_DungeonMapTileY + card_idx * 100);
    }
    flag_1 = (&DAT_0067f00d)[slot_idx * 0x30];
    val_4 = Util_GetRandomNumber(2);
    if (val_4 + 1 < (int)(uint32_t)flag_1) {
      match_count = 0;
      for (loop_idx = 0; loop_idx < (int)(uint32_t)(uint8_t)(&DAT_0067f00d)[slot_idx * 0x30];
          loop_idx = loop_idx + 1) {
        match_count = match_count + loop_idx * 2 + 4;
      }
    }
    else {
      if ((uint8_t)(&DAT_0067f00d)[slot_idx * 0x30] < 2) {
        match_count = 0x10;
      }
      else {
        match_count = 0x1c;
      }
      (&DAT_0067f00d)[slot_idx * 0x30] = (&DAT_0067f00d)[slot_idx * 0x30] | 0x80;
    }
    if (*(int *)(&DAT_0067eff4 + slot_idx * 0x30) == -1) {
      match_count = (match_count * 3) / 2;
    }
    if (*(int *)(&DAT_0067eff8 + slot_idx * 0x30) != -1) {
      match_count = (match_count * 2) / 3;
    }
    flag_1 = (&DAT_0067f00d)[slot_idx * 0x30];
    flag_2 = (&DAT_0067f00d)[slot_idx * 0x30];
    val_4 = Util_GetRandomNumber(2);
    *(int32_t *)(&DAT_0067effc + slot_idx * 0x30) =
         *(int32_t *)
          (&DAT_00527e9c + ((((flag_1 & 0xc0) == 0) - 1 & 4) + (flag_2 & 0x7f) + val_4) * 4);
    *(int32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) = 1;
    switch((int)(match_count + (match_count >> 0x1f & 3U)) >> 2) {
    case 0:
    case 1:
    case 2:
      (&DAT_0067f00d)[slot_idx * 0x30] = (&DAT_0067f00d)[slot_idx * 0x30] + '\x01';
    case 3:
      *(int32_t *)(&DAT_0067effc + slot_idx * 0x30) =
           *(int32_t *)(&DAT_00527e8c + (char)(&DAT_0067f00c)[slot_idx * 0x30] * 4);
      cVar3 = Util_GetRandomNumber(5);
      *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) =
           *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) | 1 << (cVar3 + 4U & 0x1f);
      break;
    case 4:
      *(int32_t *)(&DAT_0067effc + slot_idx * 0x30) =
           *(int32_t *)(&DAT_00527e8c + (char)(&DAT_0067f00c)[slot_idx * 0x30] * 4);
      break;
    case 5:
      cVar3 = Util_GetRandomNumber(5);
      *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) =
           *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) | 1 << (cVar3 + 4U & 0x1f);
      *(int32_t *)(&DAT_0067effc + slot_idx * 0x30) = 0xffffffff;
      break;
    case 6:
      *(int32_t *)(&DAT_0067effc + slot_idx * 0x30) = 0xffffffff;
    }
    if ((((&DAT_0067f015)[slot_idx * 0x30] & 1) != 0) ||
       ((((&DAT_0067f00d)[slot_idx * 0x30] & 0x3f) < 2 &&
        (((&g_TownBuildingFlagsTable)[slot_idx * 0x30] & 0x20) != 0)))) {
      *(int32_t *)(&DAT_0067effc + slot_idx * 0x30) =
           *(int32_t *)(&DAT_00527e8c + (char)(&DAT_0067f00c)[slot_idx * 0x30] * 4);
      *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) =
           *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) & 0xfffffedf;
    }
    if (((&DAT_0067f00d)[slot_idx * 0x30] & 0x7f) == 1) {
      *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) =
           *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) & 0xfffffffe;
    }
    if (slot_idx < 5) {
      *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) = *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) | 1;
      *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) = *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) | 2;
      *(int32_t *)(&DAT_0067effc + slot_idx * 0x30) =
           *(int32_t *)(&DAT_00527ec0 + g_CampaignDifficultyLevel * 4 + slot_idx * 0x10);
    }
    slot_idx = slot_idx + 1;
  } while( true );
}

/*
 * Decompiled function: FUN_0048ea81
 * Entry Point: 0048ea81
 * Size: 91 bytes
 */


void FUN_0048ea81(int player_id)

{
  uint8_t flag_1;
  
  do {
    flag_1 = Util_GetRandomNumber(3);
  } while ((*(uint32_t *)(&DAT_0067f010 + arg_1 * 0x30) & 1 << (flag_1 & 0x1f)) != 0);
  *(uint32_t *)(&DAT_0067f010 + arg_1 * 0x30) =
       *(uint32_t *)(&DAT_0067f010 + arg_1 * 0x30) | 1 << (flag_1 & 0x1f);
  Castle_Process_00492ddf(arg_1);
  return;
}

/*
 * Decompiled function: FUN_0048eadc
 * Entry Point: 0048eadc
 * Size: 396 bytes
 */


int32_t FUN_0048eadc(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    if (arg2 == 2) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,1,1,*(int *)(arg1 + 0x18) + -2,
                        *(int *)(arg1 + 0x1c) + -2,iRam00676b98);
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,*(int *)(arg1 + 0x18) + 1,
                   *(int *)(arg1 + 0x1c) + 1,(int *)g_DisplaySurfaceScreen,*(int *)(arg1 + 0x10),
                   *(int *)(arg1 + 0x14));
      if (*(int *)(arg1 + 0x28) != 0) {
        (**(code **)(arg1 + 0x28))(arg1);
      }
    }
    else {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                        *(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),(&DAT_00676b90)[arg2]);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0048ec9a
 * Entry Point: 0048ec9a
 * Size: 106 bytes
 */


int FUN_0048ec9a(int arg1,int arg2)

{
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (0xe < slot_idx) {
      return -1;
    }
    if ((*(int *)(&DAT_0067f000 + slot_idx * 0x30) == arg1) &&
       (*(int *)(&DAT_0067f004 + slot_idx * 0x30) == arg2)) break;
    slot_idx = slot_idx + 1;
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0048ed04
 * Entry Point: 0048ed04
 * Size: 231 bytes
 */


void FUN_0048ed04(int player_id,uint32_t *arg_2,int *arg_3)

{
  short len_1;
  uint8_t *pbVar2;
  uint32_t uval_3;
  int loop_idx;
  uint32_t target_idx;
  uint8_t *card_idx;
  
  *arg_2 = 0x7fffffff;
  *arg_3 = 0;
  if (arg_1 != 0) {
    len_1 = *(short *)(arg_1 + 0xe);
    card_idx = (uint8_t *)(arg_1 + 0x10);
    for (loop_idx = 0; loop_idx < len_1; loop_idx = loop_idx + 1) {
      uval_3 = (uint32_t)*card_idx;
      pbVar2 = card_idx + 1;
      if (uval_3 != 0xff) {
        target_idx = (uint32_t)card_idx[1];
        pbVar2 = card_idx + 2;
        if (target_idx == 0xfe) {
          target_idx = (uint32_t)card_idx[2];
          pbVar2 = card_idx + 3;
        }
        card_idx = pbVar2;
        if ((int)uval_3 < (int)*arg_2) {
          *arg_2 = uval_3;
        }
        if (*arg_3 < (int)(target_idx + uval_3)) {
          *arg_3 = target_idx + uval_3;
        }
        pbVar2 = card_idx + target_idx;
      }
      card_idx = pbVar2;
    }
  }
  return;
}

/*
 * Decompiled function: FUN_0048edeb
 * Entry Point: 0048edeb
 * Size: 82 bytes
 */


int32_t FUN_0048edeb(int player_id,int card_slot,int event_type,int arg_4,int arg_5,int arg_6)

{
  int32_t uval_1;
  
  if ((((arg_3 < arg_1) && (arg_1 < arg_5 + arg_3)) && (arg_4 < arg_2)) && (arg_2 < arg_6 + arg_4))
  {
    uval_1 = 1;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0048ee42
 * Entry Point: 0048ee42
 * Size: 389 bytes
 */


int32_t FUN_0048ee42(void)

{
  int32_t uval_1;
  int val_2;
  int val_3;
  int *stack_arg;
  int local_30;
  int local_2c;
  uint32_t local_24;
  int loop_idx;
  uint32_t color_idx [4];
  int match_count;
  int slot_idx;
  
  match_count = *stack_arg;
  local_2c = stack_arg[1];
  if (match_count == 0) {
    uval_1 = 0;
  }
  else {
    Surface_FillRect((int *)g_DisplaySurfaceWork,0,0x80,*(short *)(match_count + 4) + 1,
                     *(short *)(match_count + 6) + 1,0);
    Sprite_DrawDirect((int *)g_DisplaySurfaceWork,0,0x80,*stack_arg);
    Sprite_DrawDirect((int *)g_DisplaySurfaceWork,0,0x80,stack_arg[1]);
    FUN_0048ed04(*stack_arg,color_idx,&local_30);
    FUN_0048ed04(stack_arg[1],&local_24,&slot_idx);
    if ((int)color_idx[0] <= (int)local_24) {
      local_24 = color_idx[0];
    }
    if (slot_idx <= local_30) {
      slot_idx = local_30;
    }
    local_30 = slot_idx;
    if (0xfa < (int)(slot_idx - local_24)) {
      local_30 = local_24 + 0xfa;
    }
    loop_idx = (int)*(short *)(local_2c + 0xc);
    if ((int)*(short *)(match_count + 0xc) <= (int)*(short *)(local_2c + 0xc)) {
      loop_idx = (int)*(short *)(match_count + 0xc);
    }
    val_2 = (int)*(short *)(local_2c + 0xc) + (int)*(short *)(local_2c + 0xe);
    val_3 = (int)*(short *)(match_count + 0xc) + (int)*(short *)(match_count + 0xe);
    if (val_2 <= val_3) {
      val_2 = val_3;
    }
    uval_1 = Sprite_EncodeFromSurface
                      (*(int *)g_DisplaySurfaceWork,local_24,loop_idx + 0x80,
                       (local_30 - local_24) + 1,(val_2 - loop_idx) + 1);
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0048efc7
 * Entry Point: 0048efc7
 * Size: 231 bytes
 */


int32_t FUN_0048efc7(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,int arg_6)

{
  int val_1;
  
  if (arg_6 != 0) {
    if ((arg_5 << 8) / (int)*(short *)(arg_6 + 6) < (arg_4 << 8) / (int)*(short *)(arg_6 + 4)) {
      val_1 = (*(short *)(arg_6 + 4) * arg_5) / (int)*(short *)(arg_6 + 6);
      Sprite_DrawScaled(arg_1,arg_2 + (arg_4 - val_1) / 2,arg_3,val_1,arg_5,arg_6);
    }
    else {
      val_1 = (*(short *)(arg_6 + 6) * arg_4) / (int)*(short *)(arg_6 + 4);
      Sprite_DrawScaled(arg_1,arg_2,arg_3 + (arg_5 - val_1) / 2,arg_4,val_1,arg_6);
    }
  }
  return 0;
}

/*
 * Decompiled function: FUN_0048f0ae
 * Entry Point: 0048f0ae
 * Size: 374 bytes
 */


int FUN_0048f0ae(int *arg_1,int card_slot,int event_type,int arg_4,int arg_5,int arg_6)

{
  int loop_idx;
  int color_idx;
  uint32_t target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  slot_idx = arg_6;
  if (arg_6 == 0) {
    color_idx = 0;
  }
  else {
    Surface_FillRect((int *)g_DisplaySurfaceWork,0,0x80,(int)*(short *)(arg_6 + 4),
                     (int)*(short *)(arg_6 + 6),0);
    Sprite_DrawDirect((int *)g_DisplaySurfaceWork,0,0x80,arg_6);
    FUN_0048ed04(arg_6,&target_idx,&loop_idx);
    color_idx = Sprite_EncodeFromSurface
                         (*(int *)g_DisplaySurfaceWork,target_idx,*(short *)(slot_idx + 0xc) + 0x80,
                          (loop_idx - target_idx) + 1,(int)*(short *)(slot_idx + 0xe));
    player_idx = color_idx;
    if ((arg_5 << 8) / (int)*(short *)(color_idx + 6) < (arg_4 << 8) / (int)*(short *)(color_idx + 4))
    {
      match_count = (*(short *)(color_idx + 4) * arg_5) / (int)*(short *)(color_idx + 6);
      Sprite_DrawScaled(arg_1,arg_2 + (arg_4 - match_count) / 2,arg_3,match_count,arg_5,color_idx);
    }
    else {
      card_idx = (*(short *)(color_idx + 6) * arg_4) / (int)*(short *)(color_idx + 4);
      Sprite_DrawScaled(arg_1,arg_2,arg_3 + (arg_5 - card_idx) / 2,arg_4,card_idx,color_idx);
    }
  }
  return color_idx;
}

/*
 * Decompiled function: FUN_0048f224
 * Entry Point: 0048f224
 * Size: 287 bytes
 */


int32_t FUN_0048f224(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                      *(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),
                      *(int *)(&DAT_00676ba0 + arg2 * 4 + *(int *)(arg1 + 0x30) * 0x10));
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0048f375
 * Entry Point: 0048f375
 * Size: 430 bytes
 */


int32_t FUN_0048f375(int *arg_1,int card_slot,int event_type)

{
  int32_t uval_1;
  int loop_idx;
  int color_idx;
  int slot_idx;
  
  if (arg_1[0x10] == 0) {
    loop_idx = arg_1[6] + arg_1[0xe] / 2;
    slot_idx = arg_1[8] - arg_1[0xe] / 2;
  }
  else {
    loop_idx = arg_1[7] + arg_1[0xf] / 2;
    slot_idx = arg_1[9] - arg_1[0xf] / 2;
  }
  if ((arg_2 < loop_idx) || (slot_idx < arg_2)) {
    uval_1 = 0xffffffff;
  }
  else {
    arg_1[0x13] = arg_2;
    for (color_idx = 0; color_idx < arg_1[5]; color_idx = color_idx + 1) {
      Surface_PutLine((int32_t *)(arg_1[4] * color_idx + arg_1[0xd]),*(int *)*arg_1,arg_1[4],
                      arg_1[2],arg_1[3]);
    }
    Sprite_DrawScaled((int *)*arg_1,arg_1[2] - arg_1[0xe] / 2,arg_1[3] - arg_1[0xf] / 2,arg_1[0xe],
                      arg_1[0xf],arg_1[arg_3 + 10]);
    if (*arg_1 != arg_1[1]) {
      FUN_0050dce0((int *)*arg_1,arg_1[2],arg_1[3],arg_1[4],arg_1[5],(int *)arg_1[1],arg_1[6],
                   arg_1[7]);
    }
    uval_1 = 0;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_0049094c
 * Entry Point: 0049094c
 * Size: 84 bytes
 */


int FUN_0049094c(void)

{
  int32_t match_count;
  int32_t slot_idx;
  
  match_count = 1;
  for (slot_idx = 0; slot_idx < 6; slot_idx = slot_idx + 1) {
    if ((DAT_0067bdb4 & 1 << ((uint8_t)slot_idx & 0x1f)) != 0) {
      match_count = match_count + 1;
    }
  }
  return match_count;
}

/*
 * Decompiled function: FUN_004909a0
 * Entry Point: 004909a0
 * Size: 51 bytes
 */


void FUN_004909a0(int player_id)

{
  Palette_Subsystem_004a2ef0(arg_1);
  DAT_006b2fe0 = 0xffffffff;
  g_GlobalEnchantmentCardId = 0xffffffff;
  return;
}

/*
 * Decompiled function: Deck_LoadPreconstructedDeck
 * Entry Point: 004909d3
 * Size: 271 bytes
 */


void Deck_LoadPreconstructedDeck(int x,int32_t arg_2,uint32_t width,int height)

{
  char *mode_str;
  int val_1;
  
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
  val_1 = FUN_00406b01(&g_OverworldWorldState);
  if (val_1 == 0) {
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


int32_t FUN_00490ae2(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x1c) + *(int *)(arg1 + 0x14) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                      *(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),
                      (&DAT_00676c40)[*(int *)(arg1 + 0x30) * 4 + arg2]);
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_00490c33
 * Entry Point: 00490c33
 * Size: 278 bytes
 */


int32_t FUN_00490c33(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,*(int *)(arg1 + 0x10),*(int *)(arg1 + 0x14),
                      *(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c),*(int *)(&DAT_00676be0 + arg2 * 4)
                     );
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_004922dc
 * Entry Point: 004922dc
 * Size: 194 bytes
 */


int FUN_004922dc(void)

{
  int card_idx;
  int slot_idx;
  
  card_idx = -DAT_006410b4;
  for (slot_idx = 0; slot_idx < 0x80; slot_idx = slot_idx + 1) {
    if ((&DAT_0067be01)[slot_idx * 100] != '\0') {
      card_idx = card_idx + -2;
    }
  }
  card_idx = card_idx * 3;
  for (slot_idx = 0; slot_idx < 1000; slot_idx = slot_idx + 1) {
    if ((&DAT_0067b9b0)[slot_idx] != '\0') {
      card_idx = card_idx + ((int)(char)(&DAT_0067b9b0)[slot_idx] & 0xfU) + 2;
      if (((int)(char)(&DAT_0067b9b0)[slot_idx] & 0xfU) == 0xc) {
        card_idx = card_idx + 0x19;
      }
    }
  }
  return card_idx << 1;
}

/*
 * Decompiled function: FUN_00492cb1
 * Entry Point: 00492cb1
 * Size: 302 bytes
 */


int FUN_00492cb1(int arg1,int arg2)

{
  int val_1;
  int val_2;
  int y;
  uint16_t local_3f4 [2];
  char local_3f0 [1000];
  int slot_idx;
  
  val_1 = FUN_0050f440((int *)g_DisplaySurfaceScreen,(char *)&g_OverworldWorldState);
  val_2 = Ai_Util_004c3bc4(0xbe);
  if (val_2 < val_1) {
    slot_idx = FUN_0050f390(4,(char)local_3f4[0]);
    local_3f4[0] = (uint16_t)g_OverworldWorldState;
    val_1 = arg1;
    val_2 = arg2;
    y = Ai_Util_004c3ba3(0x10);
    FUN_0040c1ad(local_3f4,y,val_1,val_2);
    val_1 = Ai_Util_004c3bc4(0xbe);
    FUN_00407843(&DAT_00626851,local_3f0,val_1 - slot_idx);
    val_1 = arg1;
    val_2 = Ai_Util_004c3ba3(0x10);
    FUN_0040d1cd((int)g_DisplaySurfaceScreen,arg2,slot_idx + val_2,val_1);
    val_1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    val_1 = val_1 * 2;
  }
  else {
    val_1 = arg1;
    val_2 = Ai_Util_004c3ba3(0x10);
    FUN_0040c1ad(&g_OverworldWorldState,val_2,val_1,arg2);
    val_1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  }
  arg1 = arg1 + val_1;
  return arg1;
}

/*
 * Decompiled function: FUN_00505c74
 * Entry Point: 00505c74
 * Size: 172 bytes
 */


int32_t FUN_00505c74(void)

{
  if ((DAT_00627a88 != -1) && (g_IsAiThinking != 1)) {
    if ((g_ScWillyScore < DAT_00627a88) || (DAT_00627a84 != g_DefendingPlayer)) {
      return 1;
    }
    if ((g_PlayerManaPool != -1) && (g_ScWillyScore == DAT_00627a88)) {
      return 1;
    }
    if ((DAT_00627a88 < g_ScWillyScore) && (DAT_00627a84 == g_DefendingPlayer)) {
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


bool FUN_00505d20(int player_id)

{
  int val_1;
  bool flag_2;
  int match_count;
  
  if (g_IsAiThinking == 1) {
    flag_2 = false;
  }
  else if (DAT_0063ee1c == 0) {
    val_1 = Pic_Subsystem_0044724d();
    if (val_1 == 0) {
      flag_2 = false;
    }
    else if (DAT_00627860 == 0) {
      flag_2 = false;
    }
    else {
      if ((arg_1 < 2) || (5 < arg_1)) {
        if ((arg_1 < 0x20) || (0x25 < arg_1)) {
          if ((arg_1 < 2) || (5 < arg_1)) {
            match_count = arg_1;
          }
          else {
            match_count = 4;
          }
        }
        else {
          match_count = 0x20;
        }
      }
      else {
        match_count = 4;
      }
      flag_2 = DAT_00627a88 == match_count;
      if ((DAT_00627a88 == -1) &&
         (((&g_PlayerManaPoolAvailable)[match_count * 4 + g_DefendingPlayer * 0x98] & 1) != 0)) {
        flag_2 = true;
      }
    }
  }
  else {
    flag_2 = false;
  }
  return flag_2;
}

/*
 * Decompiled function: FUN_00505e3f
 * Entry Point: 00505e3f
 * Size: 104 bytes
 */


int32_t FUN_00505e3f(int player_id)

{
  int32_t uval_1;
  
  if (*(int *)(&g_PlayerManaPoolAvailable + arg_1 * 4 + g_DefendingPlayer * 0x98) == 0) {
    if ((DAT_00627a88 == arg_1) && (DAT_00627a84 == g_DefendingPlayer)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}

/*
 * Decompiled function: FUN_00505ea7
 * Entry Point: 00505ea7
 * Size: 386 bytes
 */


void FUN_00505ea7(int player_id)

{
  bool flag_1;
  
  if ((DAT_00627a88 == arg_1) && (DAT_00627a84 == g_DefendingPlayer)) {
    flag_1 = true;
  }
  else {
    flag_1 = false;
  }
  if ((g_IsAiThinking != 1) &&
     (((*(uint32_t *)(&g_PlayerManaPoolAvailable + arg_1 * 4 + g_DefendingPlayer * 0x98) & 1) != 0 || (flag_1)))) {
    strcpy(&g_OverworldWorldState,s_Paused_005314e8);
    if (arg_1 == 4) {
      strcat(&g_OverworldWorldState,s___Upkeep_phase_005314f0);
    }
    if (arg_1 == 1) {
      strcat(&g_OverworldWorldState,s___Untap_phase_00531500);
    }
    if (arg_1 == 10) {
      strcat(&g_OverworldWorldState,s___Draw_phase_00531510);
    }
    if (arg_1 == 0x14) {
      strcat(&g_OverworldWorldState,s___Main_phase_00531520);
    }
    if (arg_1 == 0x1f) {
      strcat(&g_OverworldWorldState,s___Discard_phase_00531530);
    }
    if (arg_1 == 0x22) {
      strcat(&g_OverworldWorldState,s___Cleanup_phase_00531540);
    }
    if (arg_1 == 0x19) {
      strcat(&g_OverworldWorldState,s___First_strike_damage_resolution_00531550);
    }
    if (arg_1 == 0x1a) {
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

void FUN_00506029(char *filepath)

{
  bool flag_1;
  int arg2;
  int val_2;
  
  flag_1 = false;
  while (!flag_1) {
    arg2 = Glue_Subsystem_004efd50
                     (g_CurrentTurnPhase,g_CurrentTurnPhase,g_CurrentTurnPhase,0xff,0,str_1,2);
    if (DAT_0063ee8c != -3) {
      if (DAT_0063ee8c == -2) {
        flag_1 = true;
      }
      else if (((DAT_0063ee8c == 0) && (arg2 != -1)) &&
              (val_2 = FUN_005063f6(g_TemporaryToughnessBuffer,arg2), val_2 != 0)) {
        FUN_005064e9(g_TemporaryToughnessBuffer,arg2);
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
  int val_1;
  int match_count;
  int slot_idx;
  
  while (*(int *)(&DAT_0063eeac + g_ActivePlayerPriority * 0x20) != 0) {
    match_count = 0;
    while( true ) {
      if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <= match_count) goto LAB_005061ff;
      if (((*(int *)(&g_CardSlot_CardId + match_count * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1)
          && (((uint8_t)*(int32_t *)
                      (&g_CardSlot_Flags + match_count * 0x120 + g_ActivePlayerPriority * 0x5b20) & 0x22
              ) == 2)) &&
         (Magic_TriggerCardEvent
                    (g_ActivePlayerPriority,match_count,0x8f,1 - g_ActivePlayerPriority,0xffffffff),
         DAT_006b2e38 != 0)) break;
      match_count = match_count + 1;
    }
    val_1 = Magic_ExecuteUpkeepPhase(g_ActivePlayerPriority,match_count);
    if (val_1 != 0) {
      Magic_ExecuteTapCardAction(g_ActivePlayerPriority,match_count);
    }
  }
LAB_005061ff:
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    if (0 < *(int *)(&DAT_0063eeac + slot_idx * 0x20)) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x20);
        Ai_Subsystem_004b784d(slot_idx,*(int32_t *)(&DAT_0063eeac + slot_idx * 0x20));
      }
      (&g_PlayerCreatureCount)[slot_idx] =
           (&g_PlayerCreatureCount)[slot_idx] - *(int *)(&DAT_0063eeac + slot_idx * 0x20);
      for (match_count = 0; match_count < 8; match_count = match_count + 1) {
        *(int32_t *)(&g_AiLookaheadDepth + match_count * 4 + slot_idx * 0x20) = 0;
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


int32_t FUN_005062b1(void)

{
  bool flag_1;
  int32_t slot_idx;
  
  if ((g_PlayerCreatureCount < 1) || (g_PlayerDeckCardCount < 1)) {
    flag_1 = true;
  }
  else if ((DAT_00696870 < 10) && (DAT_00696874 < 10)) {
    flag_1 = false;
  }
  else {
    flag_1 = true;
  }
  if (flag_1) {
    if (g_IsAiThinking == 1) {
      if (9 < DAT_00696870) {
        g_PlayerCreatureCount = 0;
      }
      if (9 < DAT_00696874) {
        g_PlayerDeckCardCount = 0;
      }
      slot_idx = 0;
    }
    else {
      Ai_EvaluateTacticalPosition(0,0xff);
      slot_idx = 1;
    }
  }
  else {
    slot_idx = 0;
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0050638d
 * Entry Point: 0050638d
 * Size: 105 bytes
 */


int32_t FUN_0050638d(int x,int y,int width,int height)

{
  int32_t match_count;
  int32_t slot_idx;
  
  slot_idx = 0;
  for (match_count = 0; match_count < y; match_count = match_count + 1) {
    if ((*(int *)(x + match_count * 8) == width) && (*(int *)(x + 4 + match_count * 8) == height)) {
      slot_idx = 1;
    }
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_005063f6
 * Entry Point: 005063f6
 * Size: 238 bytes
 */


int32_t FUN_005063f6(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00471c32(arg1,arg2);
  if ((((val_1 == 0) ||
       (((&g_MasterCardFlagsTable)[*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x10)
        == 0)) || (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) ||
     ((((&g_CardSlot_Subtypes)[arg2 * 0x120 + arg1 * 0x5b20] & 3) != 0 &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) != 0)))) {
    uval_2 = 0;
  }
  else {
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_005064e9
 * Entry Point: 005064e9
 * Size: 139 bytes
 */


int32_t FUN_005064e9(int arg1,int arg2)

{
  g_AiManaPoolReserve = 1;
  g_PendingAttackersTargetSlot = 0xffffffff;
  Magic_TriggerCardEvent(arg1,arg2,0x6d,1 - arg1,0xffffffff);
  if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) {
    Rules_ApplyContinuousDamage(arg1,arg2,0x81);
  }
  g_AiManaPoolReserve = 0;
  return g_PendingAttackersTargetSlot;
}

/*
 * Decompiled function: FUN_00507b44
 * Entry Point: 00507b44
 * Size: 322 bytes
 */


int32_t FUN_00507b44(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    FUN_0050b65f(*(int *)(arg1 + 0x10) + *(int *)(arg1 + 0x18) / 2,
                 *(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) / 2,*(int *)(arg1 + 0x2c) + -1,arg2,
                 &DAT_00626610 + *(int *)(arg1 + 0x30) * 100);
    if ((arg2 == 2) && (*(int *)(arg1 + 0x28) != 0)) {
      Glue_Subsystem_004ebd62(0x12,100,100,0);
      (**(code **)(arg1 + 0x28))(arg1);
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0050935e
 * Entry Point: 0050935e
 * Size: 441 bytes
 */


int32_t FUN_0050935e(int arg1,int arg2)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  uint32_t arg_4;
  int val_4;
  uint32_t arg_2;
  int *match_count;
  
  val_4 = DAT_0061e108;
  if (g_MouseCaptureFlag == 0) {
    if ((g_MouseCursorX < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < g_MouseCursorX)) {
      flag_1 = false;
    }
    else if ((g_MouseCursorY < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < g_MouseCursorY)) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if (!flag_1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uval_2 = 0;
  }
  else {
    if (arg2 == 2) {
      match_count = (int *)g_DisplaySurfaceBackBuffer;
    }
    else {
      match_count = (int *)g_DisplaySurfaceScreen;
    }
    val_3 = Ai_Util_004c3ba3((int)*(short *)(DAT_0061e108 + 4));
    arg_4 = val_3 / 2;
    val_4 = Ai_Util_004c3ba3((int)*(short *)(val_4 + 6));
    arg_2 = g_AiManaColorCost_Red / 2 - (int)arg_4 / 2;
    val_3 = Ai_Util_004c3ba3(0x112);
    val_3 = val_3 / 2;
    Sprite_DrawScaled(match_count,arg_2,val_3,arg_4,val_4 / 2,(&DAT_0061e108)[arg2]);
    if (arg2 == 2) {
      Glue_Subsystem_004ebd62(0x12,100,100,0);
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2,val_3,arg_4,val_4 / 2,
                   (int *)g_DisplaySurfaceScreen,arg_2,val_3);
      DAT_00626600 = 1;
    }
    uval_2 = 1;
  }
  return uval_2;
}

/*
 * Decompiled function: FUN_0050a2e0
 * Entry Point: 0050a2e0
 * Size: 241 bytes
 */


void FUN_0050a2e0(int player_id,int card_slot,char *str_3)

{
  int arg_5;
  int arg_4;
  int event_type;
  int arg_2_00;
  char local_6c [100];
  int32_t slot_idx;
  
  if (g_IsAiThinking != 1) {
    UI_PrepareCombatViewport();
    strcpy(local_6c,str_3);
    arg_5 = Ai_Util_004c3ba3(0xdf);
    arg_4 = Ai_Util_004c3ba3(0x95);
    arg_3 = Ai_Util_004c3ba3(0x34);
    arg_2_00 = Ai_Util_004c3ba3(0xdc);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2_00,arg_3,arg_4,arg_5,arg_2);
    FUN_0050b206(arg_1,0x78,0x26,1,&DAT_005323e8);
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
    slot_idx = FUN_0040c465(local_6c);
    UI_DrawCombatString(local_6c,g_AiManaColorCost_Red / 2,0x48,0);
    UI_DrawCombatString(local_6c,g_AiManaColorCost_Red / 2,0x47,0xff);
    Pic_Subsystem_0044b8aa();
  }
  return;
}

/*
 * Decompiled function: FUN_0050a73e
 * Entry Point: 0050a73e
 * Size: 331 bytes
 */


uint8_t * FUN_0050a73e(int player_id)

{
  int arg_1_00;
  char *mode_str;
  
  if ((&DAT_0067bdfc)[arg_1 * 100] == '\0') {
    strcat(&g_OverworldWorldState,&DAT_00532468);
  }
  else {
    arg_1_00 = Rules_CalculateManaCostReduction((uint8_t)*(int32_t *)(&DAT_0067bdfc + arg_1 * 100));
    str_2 = (char *)Mem_AllocOrFree_00473d7e(arg_1_00);
    strcat(&g_OverworldWorldState,str_2);
  }
  switch(*(int *)(&DAT_0067bdfc + arg_1 * 100) >> 8) {
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


int FUN_0050a9bf(int player_id)

{
  int val_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  slot_idx = 0x28;
  switch((&g_MasterCardColorTable)[arg_1 * 0x34]) {
  case 2:
  case 0x42:
    if ((*(uint16_t *)(&DAT_0051aec2 + arg_1 * 0x34) & 0xbfff) == 0xfffe) {
      card_idx = (int)*(short *)(&DAT_0051aec2 + arg_1 * 0x34);
    }
    else {
      card_idx = ((int)*(short *)(&DAT_0051aec2 + arg_1 * 0x34) & 0xffffbfffU) + 3;
    }
    if ((*(uint16_t *)(&DAT_0051aec4 + arg_1 * 0x34) & 0xbfff) == 0xfffe) {
      match_count = (int)*(short *)(&DAT_0051aec4 + arg_1 * 0x34);
    }
    else {
      match_count = ((int)*(short *)(&DAT_0051aec4 + arg_1 * 0x34) & 0xffffbfffU) + 3;
    }
    match_count = (*(int *)(&DAT_0051aed8 + arg_1 * 0x34) + card_idx) * match_count;
    slot_idx = match_count * 5;
    if (((&DAT_0051aecc)[arg_1 * 0x34] & 0x1f) != 0) {
      slot_idx = (match_count * 0xf) / 2;
    }
    if (((&DAT_0051aecd)[arg_1 * 0x34] & 2) != 0) {
      slot_idx = (slot_idx * 3) / 2;
    }
    if (*(code **)(&g_CardScriptCallbackTable + arg_1 * 0x34) != Glue_Util_004d0a30) {
      slot_idx = (slot_idx * 3) / 2;
    }
    if ((*(uint32_t *)(&DAT_0051aecc + arg_1 * 0x34) & 0x1c0) != 0) {
      slot_idx = (slot_idx * 3) / 2;
    }
    if (((&g_MasterCardSubtypeTable)[arg_1 * 0x34] & 8) != 0) {
      slot_idx = slot_idx * 3;
    }
    if (((&g_MasterCardSubtypeTable)[arg_1 * 0x34] & 0x10) != 0) {
      slot_idx = slot_idx * 3;
    }
    val_1 = abs((int)(char)(&g_MasterCardManaCostTable)[arg_1 * 0x34]);
    slot_idx = slot_idx / ((char)(&g_MasterCardSubTypeTable2)[arg_1 * 0x34] + val_1 + 1);
    break;
  case 4:
    val_1 = abs((int)(char)(&g_MasterCardManaCostTable)[arg_1 * 0x34]);
    val_1 = (val_1 + (char)(&g_MasterCardSubTypeTable2)[arg_1 * 0x34] + *(int *)(&DAT_0051aed8 + arg_1 * 0x34)) *
            5 + 5;
    slot_idx = val_1 * 5;
    if (((&g_MasterCardSubtypeTable)[arg_1 * 0x34] & 3) != 0) {
      slot_idx = val_1 * 10;
    }
    break;
  case 8:
    val_1 = abs((int)(char)(&g_MasterCardManaCostTable)[arg_1 * 0x34]);
    slot_idx = ((val_1 + (char)(&g_MasterCardSubTypeTable2)[arg_1 * 0x34] + *(int *)(&DAT_0051aed8 + arg_1 * 0x34)
               ) * 4 + 4) * 5;
    break;
  case 0x10:
  case 0x20:
    val_1 = abs((int)(char)(&g_MasterCardManaCostTable)[arg_1 * 0x34]);
    slot_idx = *(int *)(&DAT_0051aed8 + arg_1 * 0x34) * 0x14 +
              ((val_1 + (char)(&g_MasterCardSubTypeTable2)[arg_1 * 0x34]) * 5 + 5) * 8;
    if ((&g_MasterCardManaCostTable)[arg_1 * 0x34] == -1) {
      slot_idx = (slot_idx * 3) / 2;
    }
    break;
  case 0x40:
    val_1 = abs((int)(char)(&g_MasterCardManaCostTable)[arg_1 * 0x34]);
    slot_idx = (int)(0xfa / (longlong)(*(int *)(&DAT_0051aed8 + arg_1 * 0x34) + val_1 + 2));
  }
  val_1 = File_Load_Info(arg_1);
  if (val_1 == 2) {
    slot_idx = FUN_0040a305(slot_idx * 2,100,9999);
  }
  else if (val_1 == 3) {
    slot_idx = FUN_0040a305(slot_idx << 2,200,9999);
  }
  else if (val_1 == 4) {
    slot_idx = FUN_0040a305(slot_idx << 3,200,9999);
  }
  if (((&g_MasterCardFlagsTable)[arg_1 * 0x34] & 2) != 0) {
    slot_idx = slot_idx << 1;
  }
  if (((&g_MasterCardFlagsTable)[arg_1 * 0x34] & 4) != 0) {
    slot_idx = (slot_idx * 3) / 2;
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0050aef6
 * Entry Point: 0050aef6
 * Size: 199 bytes
 */


int32_t FUN_0050aef6(int arg1,int arg2)

{
  int val_1;
  int32_t slot_idx;
  
  val_1 = arg1 - DAT_00641010;
  if (arg2 - DAT_00641014 < 1) {
    strcat(&g_OverworldWorldState,s_North_005324d0 + ((0 < val_1) - 1 & 8));
    if (val_1 < 1) {
      slot_idx = 3;
    }
    else {
      slot_idx = 0;
    }
  }
  else {
    strcat(&g_OverworldWorldState,&DAT_005324c0 + ((0 < val_1) - 1 & 8));
    if (val_1 < 1) {
      slot_idx = 2;
    }
    else {
      slot_idx = 1;
    }
  }
  return slot_idx;
}

/*
 * Decompiled function: FUN_0050afbd
 * Entry Point: 0050afbd
 * Size: 79 bytes
 */


void FUN_0050afbd(void)

{
  int val_1;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0xf; slot_idx = slot_idx + 1) {
    val_1 = Util_GetRandomNumber(3);
    if (val_1 == 0) {
      *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) =
           *(uint32_t *)(&g_TownBuildingFlagsTable + slot_idx * 0x30) & 0xfffffdff;
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
  int player_id;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  card_idx = 0x7fff;
  match_count = -1;
  for (player_idx = 0; player_idx < 0xf; player_idx = player_idx + 1) {
    if ((*(int *)(&DAT_0067eff0 + player_idx * 0x30) != -1) &&
       (*(int *)(&DAT_0067f010 + player_idx * 0x30) != 7)) {
      arg_1 = FUN_0040a36f(DAT_00641010 - *(int *)(&DAT_0067f000 + player_idx * 0x30),
                           DAT_00641014 - *(int *)(&DAT_0067f004 + player_idx * 0x30));
      slot_idx = Util_GetRandomNumber(arg_1);
      slot_idx = slot_idx + arg_1 / 2;
      if (((&DAT_0067f015)[player_idx * 0x30] & 2) != 0) {
        slot_idx = slot_idx * 3;
      }
      if (slot_idx < card_idx) {
        match_count = player_idx;
        card_idx = slot_idx;
      }
    }
  }
  return match_count;
}

/*
 * Decompiled function: FUN_0050b0fc
 * Entry Point: 0050b0fc
 * Size: 164 bytes
 */


int FUN_0050b0fc(uint8_t arg1,uint8_t arg2)

{
  int match_count;
  
  match_count = 0;
  while( true ) {
    if (499 < match_count) {
      return 0;
    }
    if (((*(int *)(&deck + match_count * 4) != -1) &&
        ((1 << (arg1 & 0x1f) &
         (int)(char)(&g_MasterCardColorTable)[(*(uint32_t *)(&deck + match_count * 4) & 0xfff) * 0x34]) != 0)) &&
       ((arg2 & (&g_MasterCardColorTable)[(*(uint32_t *)(&deck + match_count * 4) & 0xfff) * 0x34]) != 0))
    break;
    match_count = match_count + 1;
  }
  return match_count + 1;
}

/*
 * Decompiled function: FUN_0050b1a0
 * Entry Point: 0050b1a0
 * Size: 102 bytes
 */


void FUN_0050b1a0(void)

{
  char *mode_str;
  
  str_2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
  strcat(&g_OverworldWorldState,str_2);
  strcat(&g_OverworldWorldState,&DAT_005324e0);
  FUN_00484c45(1 << ((uint8_t)g_AiManaColorCost_White & 3));
  strcat(&g_OverworldWorldState,s_spell_005324e4);
  return;
}

/*
 * Decompiled function: FUN_0050b206
 * Entry Point: 0050b206
 * Size: 472 bytes
 */


void FUN_0050b206(int player_id,int card_slot,int event_type,int arg_4,char *str_5)

{
  int xLeft;
  int yTop;
  int loop_idx;
  int color_idx;
  tagRECT target_idx;
  int slot_idx;
  
  if (arg_4 == 0) {
    color_idx = Ai_Util_004c3ba3(0x30);
    loop_idx = Ai_Util_004c3ba3(0x30);
  }
  else {
    color_idx = Ai_Util_004c3ba3(0x50);
    loop_idx = Ai_Util_004c3ba3(0x70);
    if (0xf0 < arg_3 + 0x70) {
      arg_3 = 0x7f;
    }
  }
  xLeft = Ai_Util_004c3ba3(arg_2);
  yTop = Ai_Util_004c3ba3(arg_3);
  SetRect(&target_idx,xLeft,yTop,color_idx + xLeft,loop_idx + yTop);
  if (arg_4 == 0) {
    Palette_Subsystem_0049f8cd
              (*(HDC *)((&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceScreen] + 4),&target_idx.left,
               (WPARAM *)(&DAT_006b3070 + *(int *)(&g_MasterCardTypeTable + arg_1 * 0x34) * 0x98),0,
               1);
  }
  else {
    Palette_Subsystem_0049c7c7
              (*(HDC *)((&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceScreen] + 4),&target_idx.left,
               (WPARAM *)(&DAT_006b3070 + *(int *)(&g_MasterCardTypeTable + arg_1 * 0x34) * 0x98),0,
               1,1);
  }
  if ((str_5 != (char *)0x0) && (*str_5 != '\0')) {
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
    slot_idx = FUN_0040c465(str_5);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,((xLeft + color_idx / 2) - slot_idx / 2) + -10,
                      yTop + -0x18,slot_idx + 0x14,0x14,DAT_00678514);
    UI_DrawCombatString(str_5,xLeft + color_idx / 2,yTop + -0x14,0xff);
  }
  return;
}

/*
 * Decompiled function: FUN_0050b3de
 * Entry Point: 0050b3de
 * Size: 480 bytes
 */


void FUN_0050b3de(int player_id,int card_slot,int event_type,int arg_4,int arg_5,int arg_6,char *str_7)

{
  int xLeft;
  int yTop;
  tagRECT target_idx;
  int slot_idx;
  
  if (arg_6 == 0) {
    arg_4 = Ai_Util_004c3ba3(arg_4);
    arg_5 = Ai_Util_004c3ba3(arg_5);
  }
  else {
    arg_4 = Ai_Util_004c3ba3(arg_4);
    arg_5 = Ai_Util_004c3ba3(arg_5);
    if (0xf0 < arg_3 + 0x70) {
      arg_3 = 0x7f;
    }
  }
  xLeft = Ai_Util_004c3ba3(arg_2);
  yTop = Ai_Util_004c3ba3(arg_3);
  SetRect(&target_idx,xLeft,yTop,arg_4 + xLeft,arg_5 + yTop);
  if (arg_6 == 0) {
    Palette_Subsystem_0049f8cd
              (*(HDC *)((&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceScreen] + 4),&target_idx.left,
               (WPARAM *)(&DAT_006b3070 + *(int *)(&g_MasterCardTypeTable + arg_1 * 0x34) * 0x98),0,
               1);
  }
  else {
    Palette_Subsystem_0049c7c7
              (*(HDC *)((&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceScreen] + 4),&target_idx.left,
               (WPARAM *)(&DAT_006b3070 + *(int *)(&g_MasterCardTypeTable + arg_1 * 0x34) * 0x98),0,
               1,1);
  }
  if ((str_7 != (char *)0x0) && (*str_7 != '\0')) {
    *(int32_t *)(g_DisplaySurfaceScreen + 0x20) = 1;
    slot_idx = FUN_0040c465(str_7);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,((xLeft + arg_4 / 2) - slot_idx / 2) + -10,
                      yTop + -0x18,slot_idx + 0x14,0x14,DAT_00678514);
    UI_DrawCombatString(str_7,xLeft + arg_4 / 2,yTop + -0x14,0xff);
  }
  return;
}

/*
 * Decompiled function: FUN_0050b5be
 * Entry Point: 0050b5be
 * Size: 161 bytes
 */


void FUN_0050b5be(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  int val_1;
  int val_2;
  int val_3;
  int xLeft;
  tagRECT player_idx;
  
  val_1 = Ai_Util_004c3ba3(arg_5);
  val_2 = Ai_Util_004c3ba3(arg_3);
  val_1 = val_1 + val_2;
  val_2 = Ai_Util_004c3ba3(arg_4);
  val_3 = Ai_Util_004c3ba3(arg_2);
  val_2 = val_2 + val_3;
  val_3 = Ai_Util_004c3ba3(arg_3);
  xLeft = Ai_Util_004c3ba3(arg_2);
  SetRect(&player_idx,xLeft,val_3,val_2,val_1);
  Palette_Subsystem_00496d30
            (*(HDC *)((&g_ScreenSurfaces)[*(int *)g_DisplaySurfaceScreen] + 4),&player_idx.left,
             (WPARAM *)(&DAT_006b3070 + arg_1 * 0x98),1);
  return;
}

/*
 * Decompiled function: FUN_0050b65f
 * Entry Point: 0050b65f
 * Size: 865 bytes
 */


void FUN_0050b65f(int player_id,int card_slot,int event_type,int arg_4,char *str_5)

{
  int arg_3_00;
  int arg_6;
  int val_1;
  uint32_t arg_2_00;
  int val_2;
  int val_3;
  int val_4;
  bool bVar5;
  int arg_2_01;
  int arg_3_01;
  int card_idx;
  
  bVar5 = arg_4 == 2;
  arg_2_00 = arg_1 - 0x2b;
  arg_3_00 = arg_2 + -0x26;
  switch(arg_4) {
  case 0:
    arg_4 = 0;
    break;
  case 1:
    arg_4 = 1;
    break;
  case 2:
    arg_4 = 1;
    break;
  case 3:
    return;
  }
  if (bVar5) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_1 + -0x21,arg_2 + -0x1e,
                      *(short *)(*(int *)(&DAT_00678390 + arg_3 * 4) + 4) + -4,
                      *(short *)(*(int *)(&DAT_00678390 + arg_3 * 4) + 6) + -2,
                      *(int *)(&DAT_00678390 + arg_3 * 4));
    val_3 = *(int *)(&DAT_00678260 + arg_4 * 0x10);
    Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_1 + -0x29,arg_2 + -0x24,
                      *(short *)(val_3 + 4) + -4,*(short *)(val_3 + 6) + -2,
                      *(int *)(&DAT_00678260 + arg_4 * 0x10));
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2_00,arg_3_00,(int)*(short *)(val_3 + 4),
                 (int)*(short *)(val_3 + 6),(int *)g_DisplaySurfaceScreen,arg_2_00,arg_3_00);
  }
  else {
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_1 + -0x23,arg_2 + -0x20,
                      *(int *)(&DAT_00678390 + arg_3 * 4));
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00,arg_3_00,
                      *(int *)(&DAT_00678260 + arg_4 * 0x10));
  }
  if (DAT_006265f0 != 0) {
    val_2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    val_3 = Ai_Util_004c3bc4(8);
    val_2 = val_2 + val_3;
    val_3 = *(int *)(&DAT_00678268 + arg_4 * 0x10);
    arg_6 = *(int *)(&DAT_00678264 + arg_4 * 0x10);
    val_1 = *(int *)(arg_4 * 0x10 + 0x67826c);
    arg_3_01 = 999;
    arg_2_01 = 0x60;
    val_4 = FUN_0040c465(str_5);
    val_4 = FUN_0040a305(val_4 + 0x20,arg_2_01,arg_3_01);
    for (card_idx = 0; card_idx < (int)(val_4 + (val_4 >> 0x1f & 0x3fU)) >> 6;
        card_idx = card_idx + 1) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(arg_1 - val_4 / 2) + card_idx * 0x40,
                        arg_2 + 0x12,0x40,val_2,arg_6);
    }
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_1 + val_4 / 2 + -0x40,arg_2 + 0x12,0x40,
                      val_2,*(int *)(&DAT_00678264 + arg_4 * 0x10));
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(arg_1 - val_4 / 2) + -8,arg_2 + 0x12,
                      (int)*(short *)(val_3 + 4),val_2,*(int *)(&DAT_00678268 + arg_4 * 0x10));
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_1 + val_4 / 2,arg_2 + 0x12,
                      (int)*(short *)(val_1 + 4),val_2,*(int *)(arg_4 * 0x10 + 0x67826c));
    FUN_0040d009((int)g_DisplaySurfaceScreen,0xff,arg_1,arg_3_00 + val_2 / 2 + 0x38);
  }
  return;
}

/*
 * Decompiled function: FUN_0050b9d5
 * Entry Point: 0050b9d5
 * Size: 442 bytes
 */


void FUN_0050b9d5(int *arg_1)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  int *piVar5;
  int card_slot;
  int local_3c [4];
  int local_2c [4];
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  target_idx = DAT_00677e10;
  if (g_AiManaColorCost_Red == 0x280) {
    color_idx = 0;
  }
  else if (g_AiManaColorCost_Red == 800) {
    color_idx = 1;
  }
  else if (g_AiManaColorCost_Red == 0x400) {
    color_idx = 2;
  }
  val_1 = Ai_Util_004c3ba3(0x8c);
  val_2 = Ai_Util_004c3ba3(0x100);
  val_3 = Ai_Util_004c3bc4(0x30);
  val_4 = Ai_Util_004c3bc4(0x40);
  piVar5 = (int *)FUN_0050e6f0(local_2c,(int)g_DisplaySurfaceScreen,val_4,val_3,val_2,val_1);
  player_idx = *piVar5;
  card_idx = piVar5[1];
  match_count = piVar5[2];
  slot_idx = piVar5[3];
  val_1 = DAT_00677e10;
  val_2 = Ai_Util_004c3bc4((int)*(short *)(target_idx + 6));
  val_3 = Ai_Util_004c3bc4((int)*(short *)(target_idx + 4));
  val_4 = Ai_Util_004c3bc4(0x135);
  arg_2 = Ai_Util_004c3bc4(0x181);
  Sprite_DrawScaled(arg_1,arg_2,val_4,val_3,val_2,val_1);
  Sprite_DrawDirect(arg_1,*(int *)(&DAT_005318e8 + color_idx * 4),
                    *(int *)(&DAT_005318f8 + color_idx * 4),DAT_00677fb0);
  Sprite_DrawDirect(arg_1,*(int *)(&DAT_00531908 + color_idx * 4),
                    *(int *)(&DAT_00531920 + color_idx * 4),DAT_00677fe4);
  Sprite_DrawDirect(arg_1,*(int *)(&DAT_00531914 + color_idx * 4),
                    *(int *)(&DAT_00531920 + color_idx * 4),DAT_00677fe4);
  FUN_0050e6f0(local_3c,(int)g_DisplaySurfaceScreen,player_idx,card_idx,match_count,slot_idx);
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


void Mem_AllocOrFree_0050c82b(int player_id)

{
  uint8_t local_7d4 [2000];
  
  Ai_Subsystem_004b72d0(local_7d4,arg_1);
  return;
}

/*
 * Decompiled function: GetSaveFileNameA
 * Entry Point: 0050ce18
 * Size: 6 bytes
 */


BOOL GetSaveFileNameA(LPOPENFILENAMEA arg_1)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0050ce18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetSaveFileNameA(arg_1);
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


int32_t Mem_AllocOrFree_0050ce80(void)

{
  return 0;
}

/*
 * Decompiled function: Mem_AllocOrFree_0050ce90
 * Entry Point: 0050ce90
 * Size: 21 bytes
 */


int32_t Mem_AllocOrFree_0050ce90(int32_t arg1,int arg2)

{
  int32_t uval_1;
  
  if (arg2 != 0) {
    uval_1 = Font_LoadFontFile((char *)arg2);
    return uval_1;
  }
  return 0;
}

/*
 * Decompiled function: thunk_FUN_0050cef0
 * Entry Point: 0050ceb0
 * Size: 5 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t * thunk_FUN_0050cef0(void)

{
  LOGPALETTE *pLVar1;
  int32_t *u_ptr_2;
  int val_3;
  int card_slot;
  int event_type;
  int val_4;
  int32_t uval_5;
  LOGPALETTE *plpal;
  HPALETTE hPal;
  int32_t **ppuVar6;
  int32_t **ppuVar7;
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
    return g_ScreenSurfaces;
  }
  u_ptr_2 = malloc(0x30);
  val_3 = GetDeviceCaps(_hdcScreen,8);
  DAT_0070a87c = val_3;
  u_ptr_2[8] = val_3;
  arg_2 = GetDeviceCaps(_hdcScreen,10);
  DAT_0070a878 = arg_2;
  u_ptr_2[9] = arg_2;
  arg_3 = GetDeviceCaps(_hdcScreen,0xc);
  DAT_0070a880 = arg_3;
  u_ptr_2[10] = arg_3;
  val_4 = arg_3 * arg_2 * val_3;
  _DAT_00532554 = 0;
  u_ptr_2[7] = ((int)(val_4 + (val_4 >> 0x1f & 7U)) >> 3) + 0x10;
  _itoa(0,acStack_a,10);
  u_ptr_2[1] = _hdcScreen;
  uval_5 = FUN_0050ec90(val_3,arg_2,arg_3);
  u_ptr_2[4] = uval_5;
  uval_5 = FUN_0050ec90(val_3,arg_2,8);
  u_ptr_2[4] = uval_5;
  *u_ptr_2 = 0;
  u_ptr_2[2] = 0;
  plpal = malloc(0x408);
  plpal->palVersion = 0x300;
  val_3 = 0x100;
  plpal->palNumEntries = 0x100;
  pLVar1 = plpal;
  do {
    pLVar1->palPalEntry[0].peRed = '\0';
    val_3 = val_3 + -1;
    pLVar1->palPalEntry[0].peGreen = '\0';
    pLVar1->palPalEntry[0].peBlue = '\0';
    pLVar1->palPalEntry[0].peFlags = '\x01';
    pLVar1 = (LOGPALETTE *)pLVar1->palPalEntry;
  } while (val_3 != 0);
  plpal->palPalEntry[0].peFlags = '\0';
  *(uint8_t *)((int)&plpal[0x80].palNumEntries + 1) = 0;
  ppuVar6 = (int32_t **)&DAT_0070a450;
  _DAT_0070ac90 = plpal;
  do {
    *(uint8_t *)ppuVar6 = 0;
    ppuVar7 = ppuVar6 + 1;
    *(uint8_t *)((int)ppuVar6 + 1) = 0;
    *(uint8_t *)((int)ppuVar6 + 2) = 0;
    *(uint8_t *)((int)ppuVar6 + 3) = 1;
    ppuVar6 = ppuVar7;
  } while (ppuVar7 < &g_ScreenSurfaces);
  DAT_0070a453 = 0;
  DAT_0070a84f = 0;
  hPal = CreatePalette(plpal);
  DAT_00626834 = hPal;
  _hLibPal = hPal;
  u_ptr_2[5] = hPal;
  SelectPalette((HDC)u_ptr_2[1],hPal,0);
  RealizePalette((HDC)u_ptr_2[1]);
  SetStretchBltMode((HDC)u_ptr_2[1],3);
  g_ScreenSurfaces = u_ptr_2;
  DAT_0053255c = 1;
  return u_ptr_2;
}

/*
 * Decompiled function: Mem_AllocOrFree_0050cec0
 * Entry Point: 0050cec0
 * Size: 38 bytes
 */


void Mem_AllocOrFree_0050cec0(int player_id)

{
  if (arg_1 == 0) {
    FUN_0050cef0();
    return;
  }
  Memory_AllocateVirtualPage(arg_1,DAT_0070a87c,DAT_0070a878,8);
  return;
}

/*
 * Decompiled function: FUN_0050cef0
 * Entry Point: 0050cef0
 * Size: 440 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t * FUN_0050cef0(void)

{
  LOGPALETTE *pLVar1;
  int32_t *u_ptr_2;
  int val_3;
  int card_slot;
  int event_type;
  int val_4;
  int32_t uval_5;
  LOGPALETTE *plpal;
  HPALETTE hPal;
  int32_t **ppuVar6;
  int32_t **ppuVar7;
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
    return g_ScreenSurfaces;
  }
  u_ptr_2 = malloc(0x30);
  val_3 = GetDeviceCaps(_hdcScreen,8);
  DAT_0070a87c = val_3;
  u_ptr_2[8] = val_3;
  arg_2 = GetDeviceCaps(_hdcScreen,10);
  DAT_0070a878 = arg_2;
  u_ptr_2[9] = arg_2;
  arg_3 = GetDeviceCaps(_hdcScreen,0xc);
  DAT_0070a880 = arg_3;
  u_ptr_2[10] = arg_3;
  val_4 = arg_3 * arg_2 * val_3;
  _DAT_00532554 = 0;
  u_ptr_2[7] = ((int)(val_4 + (val_4 >> 0x1f & 7U)) >> 3) + 0x10;
  _itoa(0,local_a,10);
  u_ptr_2[1] = _hdcScreen;
  uval_5 = FUN_0050ec90(val_3,arg_2,arg_3);
  u_ptr_2[4] = uval_5;
  uval_5 = FUN_0050ec90(val_3,arg_2,8);
  u_ptr_2[4] = uval_5;
  *u_ptr_2 = 0;
  u_ptr_2[2] = 0;
  plpal = malloc(0x408);
  plpal->palVersion = 0x300;
  val_3 = 0x100;
  plpal->palNumEntries = 0x100;
  pLVar1 = plpal;
  do {
    pLVar1->palPalEntry[0].peRed = '\0';
    val_3 = val_3 + -1;
    pLVar1->palPalEntry[0].peGreen = '\0';
    pLVar1->palPalEntry[0].peBlue = '\0';
    pLVar1->palPalEntry[0].peFlags = '\x01';
    pLVar1 = (LOGPALETTE *)pLVar1->palPalEntry;
  } while (val_3 != 0);
  plpal->palPalEntry[0].peFlags = '\0';
  *(uint8_t *)((int)&plpal[0x80].palNumEntries + 1) = 0;
  ppuVar6 = (int32_t **)&DAT_0070a450;
  _DAT_0070ac90 = plpal;
  do {
    *(uint8_t *)ppuVar6 = 0;
    ppuVar7 = ppuVar6 + 1;
    *(uint8_t *)((int)ppuVar6 + 1) = 0;
    *(uint8_t *)((int)ppuVar6 + 2) = 0;
    *(uint8_t *)((int)ppuVar6 + 3) = 1;
    ppuVar6 = ppuVar7;
  } while (ppuVar7 < &g_ScreenSurfaces);
  DAT_0070a453 = 0;
  DAT_0070a84f = 0;
  hPal = CreatePalette(plpal);
  DAT_00626834 = hPal;
  _hLibPal = hPal;
  u_ptr_2[5] = hPal;
  SelectPalette((HDC)u_ptr_2[1],hPal,0);
  RealizePalette((HDC)u_ptr_2[1]);
  SetStretchBltMode((HDC)u_ptr_2[1],3);
  g_ScreenSurfaces = u_ptr_2;
  DAT_0053255c = 1;
  return u_ptr_2;
}

/*
 * Decompiled function: Pic_ReadCompressedChunk
 * Entry Point: 0070d000
 * Size: 396 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall Pic_ReadCompressedChunk(int32_t arg_1,int32_t arg_2,uint16_t *arg_3)

{
  uint16_t uval_1;
  uint32_t uval_2;
  int32_t extraout_ECX;
  int32_t extraout_EDX;
  int32_t unaff_EBX;
  uint16_t *u_ptr_3;
  uint16_t *puVar4;
  
  while( true ) {
    u_ptr_3 = DAT_00706500;
    if (PTR_DAT_005327b0 <= DAT_00706500) {
      (*DAT_0067f43c)(arg_2,arg_1,unaff_EBX);
      u_ptr_3 = DAT_00706500;
    }
    DAT_00706500 = u_ptr_3 + 1;
    uval_1 = *u_ptr_3;
    if ((char)uval_1 == 'X') break;
    u_ptr_3 = &DAT_00532860;
    if ((uval_1 == 0x304d) || (uval_1 == 0x314d)) {
      if ((int)arg_3 < 1) {
        u_ptr_3 = (uint16_t *)&DAT_00532862;
      }
      else if (arg_3 != (uint16_t *)0x1) {
        u_ptr_3 = arg_3;
      }
    }
    *u_ptr_3 = uval_1;
    puVar4 = u_ptr_3;
    if (PTR_DAT_005327b0 <= DAT_00706500) {
      (*DAT_0067f43c)(arg_2,arg_1);
    }
    uval_1 = *DAT_00706500;
    DAT_00706500 = DAT_00706500 + 1;
    u_ptr_3[1] = uval_1;
    u_ptr_3 = u_ptr_3 + 2;
    for (uval_2 = (uint32_t)(uval_1 >> 1); uval_2 != 0; uval_2 = uval_2 - 1) {
      if (PTR_DAT_005327b0 <= DAT_00706500) {
        (*DAT_0067f43c)();
      }
      uval_1 = *DAT_00706500;
      DAT_00706500 = DAT_00706500 + 1;
      *u_ptr_3 = uval_1;
      u_ptr_3 = u_ptr_3 + 1;
    }
    arg_1 = 0;
    if (puVar4 == &DAT_00532860) {
      FUN_0050e8b0(&DAT_00532860);
      arg_1 = extraout_ECX;
      arg_2 = extraout_EDX;
    }
  }
  DAT_00536885 = (uint8_t)(uval_1 >> 8) & 1;
  if (PTR_DAT_005327b0 <= DAT_00706500) {
    (*DAT_0067f43c)(arg_2,arg_1,unaff_EBX);
  }
  u_ptr_3 = DAT_00706500 + 1;
  _DAT_00536868 = (uint32_t)*DAT_00706500;
  if (PTR_DAT_005327b0 <= u_ptr_3) {
    DAT_00706500 = u_ptr_3;
    (*DAT_0067f43c)(arg_2,arg_1,unaff_EBX);
    u_ptr_3 = DAT_00706500;
  }
  DAT_00706500 = u_ptr_3 + 1;
  g_PicSourceWidth = (uint32_t)*u_ptr_3;
  if (PTR_DAT_005327b0 <= DAT_00706500) {
    (*DAT_0067f43c)(arg_2,arg_1,unaff_EBX);
  }
  g_PicSourceHeight = (uint32_t)*DAT_00706500;
  DAT_00706500 = DAT_00706500 + 1;
  FUN_0070d245(arg_1,arg_2);
  return;
}

/*
 * Decompiled function: FUN_0070d245
 * Entry Point: 0070d245
 * Size: 112 bytes
 */


void __fastcall FUN_0070d245(int32_t arg1,int32_t arg2)

{
  uint16_t uval_1;
  char cVar2;
  int val_3;
  int val_4;
  
  if (g_PicSourceWidth == 0 && g_PicSourceHeight == 0) {
    return;
  }
  DAT_00536874 = 0;
  DAT_00536875 = 0;
  DAT_0053686c = &DAT_00536c8b;
  if (PTR_DAT_005327b0 <= DAT_00706500) {
    (*DAT_0067f43c)(arg2,arg1);
  }
  uval_1 = *DAT_00706500;
  DAT_00536880 = (uint32_t)uval_1;
  if (0xb < (uint8_t)uval_1) {
    DAT_00536880 = CONCAT31((uint3)(uint8_t)(uval_1 >> 8),0xb);
  }
  DAT_00536877 = (uint8_t)DAT_00536880;
  DAT_00536884 = 8;
  DAT_00536876 = 9;
  DAT_00536878 = 0x1ff;
  DAT_0053687c = 0x100;
  val_4 = 0;
  val_3 = 0x800;
  DAT_00706500 = DAT_00706500 + 1;
  do {
    *(int16_t *)((int)&DAT_00532860 + val_4) = 0xffff;
    val_4 = val_4 + 3;
    val_3 = val_3 + -1;
  } while (val_3 != 0);
  cVar2 = '\0';
  val_4 = 0;
  val_3 = 0x100;
  do {
    (&DAT_00532862)[val_4] = cVar2;
    cVar2 = cVar2 + '\x01';
    val_4 = val_4 + 3;
    val_3 = val_3 + -1;
  } while (val_3 != 0);
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
  int val_2;
  int val_3;
  
  DAT_00536876 = 9;
  DAT_00536878 = 0x1ff;
  DAT_0053687c = 0x100;
  val_3 = 0;
  val_2 = 0x800;
  do {
    *(int16_t *)((int)&DAT_00532860 + val_3) = 0xffff;
    val_3 = val_3 + 3;
    val_2 = val_2 + -1;
  } while (val_2 != 0);
  cVar1 = '\0';
  val_3 = 0;
  val_2 = 0x100;
  do {
    (&DAT_00532862)[val_3] = cVar1;
    cVar1 = cVar1 + '\x01';
    val_3 = val_3 + 3;
    val_2 = val_2 + -1;
  } while (val_2 != 0);
  return;
}

/*
 * Decompiled function: FUN_0070d300
 * Entry Point: 0070d300
 * Size: 146 bytes
 */


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0070d300(uint32_t arg_1)

{
  char cVar1;
  uint16_t uval_2;
  uint32_t arg_1_00;
  uint32_t extraout_ECX;
  uint32_t arg_2;
  uint32_t extraout_EDX;
  uint32_t uval_3;
  int32_t *puVar4;
  int32_t *puVar5;
  char *unaff_EDI;
  
  if (DAT_00536885 != '\0') {
    arg_1 = arg_1 + 1 >> 1;
  }
  LOCK();
  UNLOCK();
  uval_3 = DAT_0053687c;
  puVar4 = (int32_t *)DAT_0053686c;
  DAT_0053686c = (uint8_t *)register0x00000010;
  _DAT_00536870 = arg_1;
  do {
    puVar5 = puVar4;
    if (DAT_00536874 == '\0') {
      puVar4[-1] = 0x70d32c;
      cVar1 = FUN_0070d392(arg_1,uval_3,*puVar4);
      puVar5 = puVar4 + 1;
      arg_1 = arg_1_00;
      uval_3 = arg_2;
      if (cVar1 == -0x70) {
        *puVar4 = 0x70d33c;
        cVar1 = FUN_0070d392(arg_1_00,arg_2,puVar4[1]);
        puVar5 = puVar4 + 2;
        arg_1 = extraout_ECX;
        uval_3 = extraout_EDX;
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
      uval_2 = CONCAT11(DAT_00536875,DAT_00536875) & 0xff0f;
      *(uint16_t *)unaff_EDI = CONCAT11((uint8_t)(uval_2 >> 0xc),(char)uval_2);
      unaff_EDI = unaff_EDI + 2;
    }
    _DAT_00536870 = _DAT_00536870 - 1;
    puVar4 = puVar5;
    if (_DAT_00536870 == 0) {
      DAT_0053687c = uval_3;
      LOCK();
      DAT_0053686c = (uint8_t *)puVar5;
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


int32_t __fastcall FUN_0070d392(int32_t arg_1,uint32_t arg_2,int32_t arg_3)

{
  int val_1;
  uint8_t flag_2;
  uint32_t uval_3;
  uint32_t extraout_ECX;
  uint32_t uval_4;
  uint16_t *unaff_ESI;
  uint16_t *puVar5;
  
  uval_3 = DAT_00536886;
  if (&stack0x00000000 == (uint8_t *)0x536c87) {
    uval_4 = DAT_00536880 >> (0x10 - DAT_00536884 & 0x1f);
    for (flag_2 = DAT_00536884; (char)flag_2 < DAT_00536876; flag_2 = flag_2 + 0x10) {
      puVar5 = unaff_ESI;
      if (PTR_DAT_005327b0 <= unaff_ESI) {
        (*DAT_0067f43c)();
        puVar5 = DAT_00706500;
      }
      unaff_ESI = puVar5 + 1;
      DAT_00536880 = (uint32_t)*puVar5;
      uval_4 = uval_4 | DAT_00536880 << (flag_2 & 0x1f);
    }
    DAT_00536884 = flag_2 - DAT_00536876;
    uval_4 = uval_4 & DAT_00536878;
    uval_3 = uval_4;
    if ((int)arg_2 <= (int)uval_4) {
      uval_4 = DAT_00536886;
      uval_3 = arg_2;
    }
    while( true ) {
      val_1 = uval_4 * 3;
      if (*(short *)((int)&DAT_00532860 + val_1) == -1) break;
      uval_4 = CONCAT22((short)(uval_4 >> 0x10),*(short *)((int)&DAT_00532860 + val_1));
      arg_3 = CONCAT31((int3)((uint32_t)val_1 >> 8),(&DAT_00532862)[val_1]);
    }
    DAT_0053688a = (&DAT_00532862)[val_1];
    (&DAT_00532862)[arg_2 * 3] = DAT_0053688a;
    *(short *)((int)&DAT_00532860 + arg_2 * 3) = (short)DAT_00536886;
    if ((int)DAT_00536878 < (int)(arg_2 + 1)) {
      DAT_00536876 = DAT_00536876 + '\x01';
      DAT_00536878 = DAT_00536878 << 1 | 1;
    }
    if (DAT_00536877 < DAT_00536876) {
      FUN_0070d2b5();
      uval_3 = extraout_ECX;
    }
  }
  DAT_00536886 = uval_3;
                    /* WARNING: Treating indirect jump as return */
  return arg_3;
}

/*
 * Decompiled function: Mem_AllocOrFree_0070d484
 * Entry Point: 0070d484
 * Size: 36 bytes
 */


void Mem_AllocOrFree_0070d484(int32_t arg1,uint32_t arg2)

{
  int32_t uval_1;
  
  uval_1 = DAT_00706500;
  FUN_0070d300(arg2);
  DAT_00706500 = uval_1;
  return;
}

