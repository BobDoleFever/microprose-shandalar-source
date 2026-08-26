/*
 * Decompiled function: Pic_Load_004450c3
 * Entry Point: 004450c3
 * Size: 1243 bytes
 */
#include "magic.h"


void Pic_Load_004450c3(int arg_1,int arg_2,int arg_3)

{
  HWND local_17c;
  HWND local_178;
  HWND local_174;
  HWND local_170;
  char local_16c [264];
  HANDLE local_64;
  char local_60 [52];
  undefined1 local_2c [8];
  int local_24;
  int local_14 [4];
  
  if (arg_2 == 1) {
    strcpy(local_60,s_TERR_BLACK_00521f74);
  }
  else if (arg_2 == 5) {
    strcpy(local_60,s_TERR_WHITE_00521f80);
  }
  else if (arg_2 == 3) {
    strcpy(local_60,s_TERR_GREEN_00521f8c);
  }
  else if (arg_2 == 2) {
    strcpy(local_60,s_TERR_BLUE_00521f98);
  }
  else {
    strcpy(local_60,s_TERR_RED_00521fa4);
  }
  if (arg_3 == 0) {
    strcat(local_60,&DAT_00521fb0);
  }
  else if (arg_3 == 1) {
    strcat(local_60,&DAT_00521fb8);
  }
  else {
    strcat(local_60,&DAT_00521fc0);
  }
  sprintf(local_16c,s__s__s_pic_00521fc8,&DAT_006b2e90,local_60);
  local_64 = (HANDLE)Pic_Load_00423833(local_16c);
  if (arg_1 == 0) {
    local_170 = DAT_006a4924;
  }
  else {
    local_170 = DAT_006b2e2c;
  }
  SendMessageA(local_170,0x439,(WPARAM)local_64,0);
  if (arg_2 == 1) {
    strcpy(local_60,s_LIFE_BLACK_00521fd4);
  }
  else if (arg_2 == 5) {
    strcpy(local_60,s_LIFE_WHITE_00521fe0);
  }
  else if (arg_2 == 3) {
    strcpy(local_60,s_LIFE_GREEN_00521fec);
  }
  else if (arg_2 == 2) {
    strcpy(local_60,s_LIFE_BLUE_00521ff8);
  }
  else {
    strcpy(local_60,s_LIFE_RED_00522004);
  }
  if (arg_3 == 0) {
    strcat(local_60,&DAT_00522010);
  }
  else if (arg_3 == 1) {
    strcat(local_60,&DAT_00522018);
  }
  else {
    strcat(local_60,&DAT_00522020);
  }
  sprintf(local_16c,s__s__s_pic_00522028,&DAT_006b2e90,local_60);
  local_64 = (HANDLE)Pic_Load_00423833(local_16c);
  if (arg_1 == 0) {
    local_174 = DAT_006b2530;
  }
  else {
    local_174 = DAT_006ff4a8;
  }
  SendMessageA(local_174,0x439,(WPARAM)local_64,0);
  if (arg_2 == 1) {
    strcpy(local_60,s_GRAVE_BLACK_00522034);
  }
  else if (arg_2 == 5) {
    strcpy(local_60,s_GRAVE_WHITE_00522040);
  }
  else if (arg_2 == 3) {
    strcpy(local_60,s_GRAVE_GREEN_0052204c);
  }
  else if (arg_2 == 2) {
    strcpy(local_60,s_GRAVE_BLUE_00522058);
  }
  else {
    strcpy(local_60,s_GRAVE_RED_00522064);
  }
  sprintf(local_16c,s__s__s_pic_00522070,&DAT_006b2e90,local_60);
  local_64 = (HANDLE)Pic_Load_00423833(local_16c);
  if (arg_1 == 0) {
    local_178 = DAT_006b2e10;
  }
  else {
    local_178 = DAT_006a4928;
  }
  SendMessageA(local_178,0x439,(WPARAM)local_64,0);
  if (arg_2 == 1) {
    strcpy(local_60,s_HAND_BLACK_0052207c);
  }
  else if (arg_2 == 5) {
    strcpy(local_60,s_HAND_WHITE_00522088);
  }
  else if (arg_2 == 3) {
    strcpy(local_60,s_HAND_GREEN_00522094);
  }
  else if (arg_2 == 2) {
    strcpy(local_60,s_HAND_BLUE_005220a0);
  }
  else {
    strcpy(local_60,s_HAND_RED_005220ac);
  }
  sprintf(local_16c,s__s__s_pic_005220b8,&DAT_006b2e90,local_60);
  local_64 = (HANDLE)Pic_Load_00423833(local_16c);
  GetObjectA(local_64,0x18,local_2c);
  local_14[1] = 0xb;
  local_14[0] = local_24 + -0xb;
  local_14[2] = 7;
  local_14[3] = 4;
  if (arg_1 == 0) {
    local_17c = DAT_0069e720;
  }
  else {
    local_17c = DAT_006fe400;
  }
  SendMessageA(local_17c,0x439,(WPARAM)local_64,(LPARAM)local_14);
  return;
}


