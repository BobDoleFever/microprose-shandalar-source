/*
 * Decompiled function: thunk_FUN_1003c467
 * Entry Point: 1000122b
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1003c467(HDC hdc,int arg_2,int arg_3,int *arg_4,int *arg_5,int *arg_6,int *arg_7)

{
  size_t len_1;
  int val_2;
  CHAR aCStack_114 [264];
  int iStack_c;
  int iStack_8;
  
  SetTextColor(hdc,DAT_1013ee4c);
  iStack_8 = 0x14;
  iStack_c = 0x14;
  wsprintfA(aCStack_114,s_Card_Type_1004bc3c);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  val_2 = 1000 - (iStack_8 + arg_2);
  *arg_4 = (int)(val_2 + (val_2 >> 0x1f & 7U)) >> 3;
  iStack_8 = iStack_8 + arg_2 + 0x28;
  *arg_6 = iStack_8;
  wsprintfA(aCStack_114,s_Black_1004bc48);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_8 = iStack_8 + *arg_4;
  wsprintfA(aCStack_114,&DAT_1004bc50);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_8 = iStack_8 + *arg_4;
  wsprintfA(aCStack_114,s_Green_1004bc58);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_8 = iStack_8 + *arg_4;
  wsprintfA(aCStack_114,&DAT_1004bc60);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_8 = iStack_8 + *arg_4;
  wsprintfA(aCStack_114,s_White_1004bc64);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_8 = iStack_8 + *arg_4;
  wsprintfA(aCStack_114,s_Colorless_1004bc6c);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_8 = iStack_8 + *arg_4;
  wsprintfA(aCStack_114,s_Total_1004bc78);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  *arg_5 = 0x41;
  *arg_7 = *arg_5 + 0x14;
  SetTextColor(hdc,DAT_1013ee5c);
  iStack_8 = 0x14;
  iStack_c = *arg_7;
  wsprintfA(aCStack_114,s_Mana_Sources_1004bc80);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  SetTextColor(hdc,DAT_1013ee4c);
  iStack_c = iStack_c + arg_3 / 2 + *arg_5;
  wsprintfA(aCStack_114,s_Creatures_1004bc90);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_c = iStack_c + *arg_5;
  wsprintfA(aCStack_114,s_Enchantments_1004bc9c);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_c = iStack_c + *arg_5;
  wsprintfA(aCStack_114,s_Sorceries_1004bcac);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_c = iStack_c + *arg_5;
  wsprintfA(aCStack_114,s_Instants_1004bcb8);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_c = iStack_c + *arg_5;
  wsprintfA(aCStack_114,s_Interrupts_1004bcc4);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_c = iStack_c + *arg_5;
  wsprintfA(aCStack_114,&DAT_1004bcd0);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_c = iStack_c + *arg_5;
  wsprintfA(aCStack_114,s_Non_Creature_1004bcd8);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_c = iStack_c + arg_3;
  wsprintfA(aCStack_114,s_Artifacts_1004bce8);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  iStack_c = iStack_c + *arg_5;
  wsprintfA(aCStack_114,s_Total_1004bcf4);
  len_1 = strlen(aCStack_114);
  TextOutA(hdc,iStack_8,iStack_c,aCStack_114,len_1);
  return;
}


