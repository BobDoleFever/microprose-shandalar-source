/*
 * Decompiled function: Ai_Subsystem_004b8e4d
 * Entry Point: 004b8e4d
 * Size: 657 bytes
 */
#include "magic.h"


char * Ai_Subsystem_004b8e4d(int arg1,int arg2)

{
  uint arg_1;
  int iVar1;
  char local_4c [52];
  int local_18;
  int local_14;
  uint local_10;
  char *local_c;
  int local_8;
  
  local_c = (char *)0x0;
  local_8 = Ai_Subsystem_004cbc65(arg1,arg2);
  if (local_8 != -1) {
    if (local_8 == DAT_006ff2dc) {
      arg_1 = Ai_Util_004cbc07(arg1,arg2);
      local_8 = Ai_Subsystem_004cbd67(arg_1);
    }
    local_10 = (uint)*(ushort *)(&DAT_006a5f74 + arg2 * 0x120 + arg1 * 0x5b20);
    local_14 = (int)(char)(&g_CardSlot_DamageReceived)[arg2 * 0x120 + arg1 * 0x5b20];
    local_18 = *(int *)(&g_CardSlot_TypeFlags + arg2 * 0x120 + arg1 * 0x5b20);
    if (local_8 == DAT_00695e94) {
      strcpy(&DAT_005569d8,s_Damage_0052d4c0);
    }
    else if (local_8 == DAT_0068a70c) {
      sprintf(&DAT_005569d8,s_Hunting___s_0052d4c8,
              (&PTR_DAT_00528cc8)
              [*(int *)(&g_CardSlot_ConvertedManaCost + arg2 * 0x120 + arg1 * 0x5b20)]);
    }
    else if (local_8 == DAT_0068a694) {
      strcpy(&DAT_005569d8,*(char **)(&DAT_006809e4 + local_10 * 0x14));
    }
    else if (local_8 == DAT_006a2848) {
      strcpy(&DAT_005569d8,*(char **)(&DAT_006809ec + local_10 * 0x14));
    }
    else {
      DAT_005569d8 = '\0';
    }
    if ((local_8 == DAT_0068a694) &&
       (0 < *(int *)(&g_CardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20))) {
      strcpy(local_4c,&DAT_005569d8);
      Palette_Subsystem_004a2dce
                (&DAT_005569d8,local_4c,
                 *(int *)(&g_CardSlot_TargetSlot + arg2 * 0x120 + arg1 * 0x5b20));
    }
    iVar1 = Ai_Subsystem_004cbc65(local_14,local_18);
    if ((iVar1 == 0x361) || (iVar1 == 0x360)) {
      strcpy(&DAT_005569d8,*(char **)(&DAT_006809e4 + iVar1 * 0x14));
    }
    if (DAT_005569d8 == '\0') {
      local_c = *(char **)(&DAT_006b3074 + local_8 * 0x98);
    }
    else {
      local_c = &DAT_005569d8;
    }
  }
  return local_c;
}


