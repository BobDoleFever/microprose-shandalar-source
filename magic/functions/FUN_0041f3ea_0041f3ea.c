/*
 * Decompiled function: FUN_0041f3ea
 * Entry Point: 0041f3ea
 * Size: 2675 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0041f3ea(undefined4 arg_1,undefined4 arg_2,int arg_3)

{
  uint _Val;
  bool bVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int local_1c;
  int local_14;
  int local_c;
  
  _DAT_00538748 = 1;
  iVar2 = Mem_AllocOrFree_00408089();
  if (iVar2 != 0) {
    uVar3 = Mem_AllocOrFree_0040813d();
    if (((uVar3 == 0xf09) || (uVar3 == 0xf0f)) ||
       ((*(int *)(&DAT_00538750 + DAT_00519c24 * 4) != 0 && ((uVar3 == 0x4800 || (uVar3 == 0x5000)))
        ))) {
      FUN_004080b2();
      if ((int)uVar3 < 0xf10) {
        if (uVar3 == 0xf0f) {
          local_1c = -1;
        }
        else if (uVar3 == 0xf09) {
          local_1c = 1;
        }
      }
      else if (uVar3 == 0x4800) {
        local_1c = -1;
      }
      else if (uVar3 == 0x5000) {
        local_1c = 1;
      }
      if (DAT_00519ff4 == -1) {
        if (local_1c < 1) {
          DAT_00519ff4 = *(int *)(&DAT_0067f780 + DAT_00519c24 * 4) + -1;
        }
        else {
          DAT_00519ff4 = 0;
        }
      }
      else {
        DAT_00519ff4 = (*(int *)(&DAT_0067f780 + DAT_00519c24 * 4) + DAT_00519ff4 + local_1c) %
                       *(int *)(&DAT_0067f780 + DAT_00519c24 * 4);
      }
      while (*(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x40) == 3)
      {
        DAT_00519ff4 = (*(int *)(&DAT_0067f780 + DAT_00519c24 * 4) + DAT_00519ff4 + local_1c) %
                       *(int *)(&DAT_0067f780 + DAT_00519c24 * 4);
      }
      if (DAT_00519ff8 != -1) {
        (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x24))
                  (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200),0);
      }
      if (*(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x10) != -1) {
        SetCursorPos(*(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x10
                             ) +
                     *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x18
                             ) / 2,
                     *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x14
                             ) +
                     *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x1c
                             ) / 2);
      }
      (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
                (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),1);
    }
    _Val = uVar3 & 0xff;
    if ((_Val != 0) || (*(int *)(&DAT_00538750 + DAT_00519c24 * 4) == 0)) {
      local_c = 0;
      if (DAT_00519ff4 == -1) {
        local_14 = 0;
      }
      else {
        local_14 = DAT_00519ff4 + 1;
      }
      for (; local_c < *(int *)(&DAT_0067f780 + DAT_00519c24 * 4); local_c = local_c + 1) {
        iVar2 = (local_14 + local_c) % *(int *)(&DAT_0067f780 + DAT_00519c24 * 4);
        if ((*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x40) != 3) &&
           ((*(uint *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x3c) == uVar3 ||
            (((_Val != 0 &&
              (*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x34) != 0)) &&
             (pcVar4 = strchr(*(char **)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) +
                                        0x34),_Val), pcVar4 != (char *)0x0)))))) {
          DAT_00519ff4 = iVar2;
          if (*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x10) != -1) {
            SetCursorPos(*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x10) +
                         *(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x18) /
                         2,*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x14)
                           + *(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) +
                                     0x1c) / 2);
          }
          if (DAT_00519ff8 != -1) {
            (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x24))
                      (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200),0);
          }
          (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
                    (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),1);
          if ((*(uint *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x3c) == uVar3)
             || (((_Val != 0 &&
                  (*(int *)(*(int *)(&DAT_0067f7d0 + iVar2 * 4 + DAT_00519c24 * 200) + 0x38) != 0))
                 && (pcVar4 = strchr(*(char **)(*(int *)(&DAT_0067f7d0 +
                                                        iVar2 * 4 + DAT_00519c24 * 200) + 0x38),_Val
                                    ), pcVar4 != (char *)0x0)))) {
            DAT_00680770 = 1;
            (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
                      (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),2);
            DAT_00680770 = 0;
            DAT_00519ff8 = DAT_00519ff4;
            FUN_004080b2();
            _DAT_00538748 = 0;
            return DAT_00519ff4;
          }
          FUN_004080b2();
          break;
        }
      }
      if ((_Val == 0xd) && (DAT_00519ff4 != -1)) {
        if (DAT_00519ff8 != -1) {
          (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
                    (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200),0);
        }
        (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
                  (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),2);
        DAT_00519ff8 = DAT_00519ff4;
        FUN_004080b2();
        _DAT_00538748 = 0;
        return DAT_00519ff4;
      }
      DAT_00519ff8 = DAT_00519ff4;
    }
  }
  FUN_004080b2();
  if (-1 < DAT_00519ff8) {
    if ((DAT_007039cc <
         *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x10)) ||
       (*(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x18) +
        *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x10) <
        DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 <
              *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x14)) ||
            (*(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x14) +
             *(int *)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x1c) <
             DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_00680770 = 1;
      (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x24))
                (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200),0);
      DAT_00519ff8 = -1;
      DAT_00519ff4 = -1;
      DAT_00680770 = 0;
    }
  }
  for (local_c = 0; local_c < *(int *)(&DAT_0067f780 + DAT_00519c24 * 4); local_c = local_c + 1) {
    if ((local_c != DAT_00519ff8) &&
       (iVar2 = (**(code **)(*(int *)(&DAT_0067f7d0 + local_c * 4 + DAT_00519c24 * 200) + 0x24))
                          (*(undefined4 *)(&DAT_0067f7d0 + local_c * 4 + DAT_00519c24 * 200),0),
       iVar2 != 0)) {
      DAT_00519ff4 = local_c;
    }
  }
  if (DAT_00519ff8 != DAT_00519ff4) {
    if (-1 < DAT_00519ff8) {
      DAT_00680770 = 1;
      (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200) + 0x24))
                (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff8 * 4 + DAT_00519c24 * 200),0);
      DAT_00680770 = 0;
    }
    (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
              (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),1);
  }
  if ((arg_3 == 1) && (-1 < DAT_00519ff4)) {
    (**(code **)(*(int *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200) + 0x24))
              (*(undefined4 *)(&DAT_0067f7d0 + DAT_00519ff4 * 4 + DAT_00519c24 * 200),2);
  }
  DAT_00519ff8 = DAT_00519ff4;
  _DAT_00538748 = 0;
  return DAT_00519ff4;
}


