/*
 * Decompiled function: Pic_Load_s_s_004b6466
 * Entry Point: 004b6466
 * Size: 1239 bytes
 */
#include "duel.h"


void Pic_Load_s_s_004b6466(int arg_1,int arg_2,int arg_3)

{
  HWND local_17c;
  HWND local_178;
  HWND local_174;
  HWND local_170;
  char local_16c [264];
  HANDLE local_64;
  uint local_60 [13];
  undefined1 local_2c [8];
  int local_24;
  int local_14 [4];
  
  if (arg_2 == 1) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_TERR_BLACK_00506ea0);
  }
  else if (arg_2 == 5) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_TERR_WHITE_00506eac);
  }
  else if (arg_2 == 3) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_TERR_GREEN_00506eb8);
  }
  else if (arg_2 == 2) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_TERR_BLUE_00506ec4);
  }
  else {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_TERR_RED_00506ed0);
  }
  if (arg_3 == 0) {
    FUN_004d9640(local_60,(uint *)&DAT_00506edc);
  }
  else if (arg_3 == 1) {
    FUN_004d9640(local_60,(uint *)&DAT_00506ee4);
  }
  else {
    FUN_004d9640(local_60,(uint *)&DAT_00506eec);
  }
  _sprintf(local_16c,s__s__s_pic_00506ef4,&DAT_006189a0,local_60);
  local_64 = (HANDLE)FUN_0043d713(local_16c);
  if (arg_1 == 0) {
    local_170 = DAT_00617378;
  }
  else {
    local_170 = DAT_00618988;
  }
  SendMessageA(local_170,0x439,(WPARAM)local_64,0);
  if (arg_2 == 1) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_LIFE_BLACK_00506f00);
  }
  else if (arg_2 == 5) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_LIFE_WHITE_00506f0c);
  }
  else if (arg_2 == 3) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_LIFE_GREEN_00506f18);
  }
  else if (arg_2 == 2) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_LIFE_BLUE_00506f24);
  }
  else {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_LIFE_RED_00506f30);
  }
  if (arg_3 == 0) {
    FUN_004d9640(local_60,(uint *)&DAT_00506f3c);
  }
  else if (arg_3 == 1) {
    FUN_004d9640(local_60,(uint *)&DAT_00506f44);
  }
  else {
    FUN_004d9640(local_60,(uint *)&DAT_00506f4c);
  }
  _sprintf(local_16c,s__s__s_pic_00506f54,&DAT_006189a0,local_60);
  local_64 = (HANDLE)FUN_0043d713(local_16c);
  if (arg_1 == 0) {
    local_174 = DAT_00618160;
  }
  else {
    local_174 = DAT_00664c28;
  }
  SendMessageA(local_174,0x439,(WPARAM)local_64,0);
  if (arg_2 == 1) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_GRAVE_BLACK_00506f60);
  }
  else if (arg_2 == 5) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_GRAVE_WHITE_00506f6c);
  }
  else if (arg_2 == 3) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_GRAVE_GREEN_00506f78);
  }
  else if (arg_2 == 2) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_GRAVE_BLUE_00506f84);
  }
  else {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_GRAVE_RED_00506f90);
  }
  _sprintf(local_16c,s__s__s_pic_00506f9c,&DAT_006189a0,local_60);
  local_64 = (HANDLE)FUN_0043d713(local_16c);
  if (arg_1 == 0) {
    local_178 = DAT_00618978;
  }
  else {
    local_178 = DAT_0061737c;
  }
  SendMessageA(local_178,0x439,(WPARAM)local_64,0);
  if (arg_2 == 1) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_HAND_BLACK_00506fa8);
  }
  else if (arg_2 == 5) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_HAND_WHITE_00506fb4);
  }
  else if (arg_2 == 3) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_HAND_GREEN_00506fc0);
  }
  else if (arg_2 == 2) {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_HAND_BLUE_00506fcc);
  }
  else {
    Mem_AllocOrFree_004d9630(local_60,(uint *)s_HAND_RED_00506fd8);
  }
  _sprintf(local_16c,s__s__s_pic_00506fe4,&DAT_006189a0,local_60);
  local_64 = (HANDLE)FUN_0043d713(local_16c);
  GetObjectA(local_64,0x18,local_2c);
  local_14[1] = 0xb;
  local_14[0] = local_24 + -0xb;
  local_14[2] = 7;
  local_14[3] = 4;
  if (arg_1 == 0) {
    local_17c = DAT_006152b0;
  }
  else {
    local_17c = DAT_00663df4;
  }
  SendMessageA(local_17c,0x439,(WPARAM)local_64,(LPARAM)local_14);
  return;
}


