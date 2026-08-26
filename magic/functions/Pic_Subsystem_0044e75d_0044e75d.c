/*
 * Decompiled function: Pic_Subsystem_0044e75d
 * Entry Point: 0044e75d
 * Size: 231 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044e75d(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  char local_10;
  
  Surface_PutPixel((int *)g_DisplaySurfaceWork,arg_1 + 0x40,arg_2,arg_3);
  if (1 < arg_3) {
    for (local_10 = '\x01'; local_10 < '\t'; local_10 = local_10 + '\x02') {
      cVar1 = (char)*(undefined4 *)(&DAT_00522378 + local_10 * 4) + (char)arg_1;
      cVar2 = (char)*(undefined4 *)(&DAT_005223e0 + local_10 * 4) + (char)arg_2;
      cVar3 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,cVar1 + 0x40,(int)cVar2);
      if ((cVar3 < arg_3) &&
         (iVar4 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,(int)cVar1,(int)cVar2), iVar4 != 0))
      {
        Pic_Subsystem_0044e75d((int)cVar1,(int)cVar2,arg_3 + -1);
      }
    }
  }
  return;
}


