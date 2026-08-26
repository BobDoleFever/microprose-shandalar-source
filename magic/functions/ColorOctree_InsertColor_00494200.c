/*
 * Decompiled function: ColorOctree_InsertColor
 * Entry Point: 00494200
 * Size: 153 bytes
 */
#include "magic.h"


undefined4 ColorOctree_InsertColor(undefined4 *arg_1,char *str_2,undefined4 arg_3)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  size_t sVar6;
  char *_Str;
  char *_Control;
  
  sVar2 = strspn(str_2,&DAT_0052afdc);
  _Str = str_2 + sVar2;
  cVar1 = *_Str;
  while (cVar1 != '\0') {
    iVar3 = atoi(_Str);
    if (arg_1[iVar3 + 2] == 0) {
      uVar4 = ColorOctree_AllocNode();
      arg_1[iVar3 + 2] = uVar4;
    }
    arg_1 = (undefined4 *)arg_1[iVar3 + 2];
    _Control = &DAT_0052afdc;
    sVar2 = strspn(_Str,&DAT_0052afdc);
    sVar2 = strcspn(_Str + sVar2,_Control);
    sVar5 = strspn(_Str,&DAT_0052afdc);
    sVar6 = strspn(_Str + sVar2 + sVar5,&DAT_0052afdc);
    _Str = _Str + sVar2 + sVar5 + sVar6;
    cVar1 = *_Str;
  }
  *arg_1 = 1;
  arg_1[1] = arg_3;
  return 0;
}


