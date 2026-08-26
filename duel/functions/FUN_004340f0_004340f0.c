/*
 * Decompiled function: FUN_004340f0
 * Entry Point: 004340f0
 * Size: 586 bytes
 */
#include "duel.h"


int FUN_004340f0(char *str_1)

{
  int iVar1;
  FILE *pFVar2;
  void *pvVar3;
  int local_20;
  int local_1c;
  int local_10;
  int local_c;
  
  local_c = -1;
  local_10 = 0;
  do {
    if (4 < local_10) {
LAB_00434144:
      Assert_Handler_00499950
                ((uint)(local_c != -1),0x4f4548,0x43,s_Too_many_open_Catalogs__Max__d_004f4528);
      iVar1 = local_c * 0x114;
      *(undefined4 *)(&DAT_006c0cbc + iVar1) = 0;
      Mem_AllocOrFree_004d9630((uint *)(iVar1 + 0x6c0cc0),(uint *)str_1);
      pFVar2 = _fopen(str_1,&DAT_004f4570);
      *(FILE **)(&DAT_006c0cb0 + iVar1) = pFVar2;
      pFVar2 = *(FILE **)(&DAT_006c0cb0 + iVar1);
      if (pFVar2 == (FILE *)0x0) {
        local_c = 0;
      }
      else {
        _fread(&DAT_006c0cb4 + iVar1,4,1,pFVar2);
        pvVar3 = _malloc(*(int *)(&DAT_006c0cb4 + iVar1) * 0xc);
        *(void **)(&DAT_006c0cb8 + iVar1) = pvVar3;
        _fread(*(void **)(&DAT_006c0cb8 + iVar1),0xc,*(size_t *)(&DAT_006c0cb4 + iVar1),pFVar2);
        if (DAT_004f4524 != 0) {
          for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
            if ((local_c != local_10) && (*(int *)(&DAT_006c0cb0 + local_10 * 0x114) != 0)) {
              local_1c = 0;
              while (*(int *)(&DAT_006c0cb4 + iVar1) != 0) {
                for (local_20 = 0; local_20 < *(int *)(&DAT_006c0cb4 + local_10 * 0x114);
                    local_20 = local_20 + 1) {
                  Assert_Handler_00499950
                            ((uint)(*(int *)(*(int *)(&DAT_006c0cb8 + local_10 * 0x114) +
                                            local_1c * 0xc) !=
                                   *(int *)(*(int *)(&DAT_006c0cb8 + iVar1) + local_1c * 0xc)),
                             0x4f45d0,0x69,s_Duplicate_short_name_found_in_ca_004f4574);
                }
                local_1c = local_1c + 1;
              }
            }
          }
        }
        local_c = local_c + 1;
      }
      return local_c;
    }
    if (*(int *)(&DAT_006c0cb0 + local_10 * 0x114) == 0) {
      local_c = local_10;
      goto LAB_00434144;
    }
    local_10 = local_10 + 1;
  } while( true );
}


