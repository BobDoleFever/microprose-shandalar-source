/*
 * Decompiled function: FUN_004421e2
 * Entry Point: 004421e2
 * Size: 237 bytes
 */
#include "duel.h"


void FUN_004421e2(int *arg_1,int *arg_2,int *arg_3,int *arg_4,int *arg_5,undefined4 *arg_6)

{
  HBRUSH pHVar1;
  HPEN pHVar2;
  HGDIOBJ pvVar3;
  
  pHVar1 = CreateSolidBrush(0x10000c7);
  *arg_1 = (int)pHVar1;
  pHVar2 = CreatePen(0,0,0x1000086);
  *arg_2 = (int)pHVar2;
  pHVar2 = CreatePen(0,0,0x100001d);
  *arg_3 = (int)pHVar2;
  pHVar2 = CreatePen(0,0,0x10000c9);
  *arg_4 = (int)pHVar2;
  pHVar1 = CreateSolidBrush(0x100000f);
  *arg_5 = (int)pHVar1;
  *arg_6 = 0x1000090;
  if (*arg_1 == 0) {
    pvVar3 = GetStockObject(2);
    *arg_1 = (int)pvVar3;
  }
  if (*arg_2 == 0) {
    pvVar3 = GetStockObject(6);
    *arg_2 = (int)pvVar3;
  }
  if (*arg_3 == 0) {
    pvVar3 = GetStockObject(6);
    *arg_3 = (int)pvVar3;
  }
  if (*arg_4 == 0) {
    pvVar3 = GetStockObject(7);
    *arg_4 = (int)pvVar3;
  }
  if (*arg_5 == 0) {
    pvVar3 = GetStockObject(2);
    *arg_5 = (int)pvVar3;
  }
  return;
}


