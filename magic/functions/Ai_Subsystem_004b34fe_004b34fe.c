/*
 * Decompiled function: Ai_Subsystem_004b34fe
 * Entry Point: 004b34fe
 * Size: 182 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b34fe(int arg_1,int arg_2,int arg_3,HGDIOBJ arg_4,HGDIOBJ arg_5,HGDIOBJ arg_6)

{
  undefined4 local_8;
  
  if (arg_1 != 0) {
    FUN_004f4548((HANDLE)arg_1);
  }
  if (arg_2 != 0) {
    FUN_004f4548((HANDLE)arg_2);
  }
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    if (*(int *)(arg_3 + local_8 * 4) != 0) {
      FUN_004f4548(*(HANDLE *)(arg_3 + local_8 * 4));
    }
  }
  if (arg_4 != (HGDIOBJ)0x0) {
    DeleteObject(arg_4);
  }
  if (arg_5 != (HGDIOBJ)0x0) {
    DeleteObject(arg_5);
  }
  if (arg_6 != (HGDIOBJ)0x0) {
    DeleteObject(arg_6);
  }
  return;
}


