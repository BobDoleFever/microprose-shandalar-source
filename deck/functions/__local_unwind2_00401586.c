/*
 * Decompiled function: __local_unwind2
 * Entry Point: 00401586
 * Size: 104 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int arg1,int arg2)

{
  int val_1;
  int val_2;
  int32_t *unaff_FS_OFFSET;
  int32_t uStack_1c;
  uint8_t *puStack_18;
  int32_t local_14;
  int iStack_10;
  
  iStack_10 = arg1;
  puStack_18 = &LAB_00401564;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    val_1 = *(int *)(arg1 + 8);
    val_2 = *(int *)(arg1 + 0xc);
    if ((val_2 == -1) || (val_2 == arg2)) break;
    local_14 = *(int32_t *)(val_1 + val_2 * 0xc);
    *(int32_t *)(arg1 + 0xc) = local_14;
    if (*(int *)(val_1 + 4 + val_2 * 0xc) == 0) {
      DeckBuilder_InitSubsystems();
      (**(code **)(val_1 + 8 + val_2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}


