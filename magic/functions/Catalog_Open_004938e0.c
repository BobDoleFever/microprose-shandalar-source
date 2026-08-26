/*
 * Decompiled function: Catalog_Open
 * Entry Point: 004938e0
 * Size: 588 bytes
 */
#include "magic.h"


int Catalog_Open(char *str_1)

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
LAB_00493934:
      AssertOrLog((uint)(local_c != -1),0x528bb8,0x43,s_Too_many_open_Catalogs__Max__d_00528b98);
      iVar1 = local_c * 0x114;
      *(undefined4 *)(&DAT_0067662c + iVar1) = 0;
      strcpy((char *)(iVar1 + 0x676630),str_1);
      pFVar2 = fopen(str_1,&DAT_00528be0);
      *(FILE **)(&DAT_00676620 + iVar1) = pFVar2;
      pFVar2 = *(FILE **)(&DAT_00676620 + iVar1);
      if (pFVar2 == (FILE *)0x0) {
        local_c = 0;
      }
      else {
        fread(&DAT_00676624 + iVar1,4,1,pFVar2);
        pvVar3 = malloc(*(int *)(&DAT_00676624 + iVar1) * 0xc);
        *(void **)(&DAT_00676628 + iVar1) = pvVar3;
        fread(*(void **)(&DAT_00676628 + iVar1),0xc,*(size_t *)(&DAT_00676624 + iVar1),pFVar2);
        if (DAT_00528b94 != 0) {
          for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
            if ((local_c != local_10) && (*(int *)(&DAT_00676620 + local_10 * 0x114) != 0)) {
              local_1c = 0;
              while (*(int *)(&DAT_00676624 + iVar1) != 0) {
                for (local_20 = 0; local_20 < *(int *)(&DAT_00676624 + local_10 * 0x114);
                    local_20 = local_20 + 1) {
                  AssertOrLog((uint)(*(int *)(*(int *)(&DAT_00676628 + iVar1) + local_1c * 0xc) !=
                                    *(int *)(*(int *)(&DAT_00676628 + local_10 * 0x114) +
                                            local_1c * 0xc)),0x528c40,0x69,
                              s_Duplicate_short_name_found_in_ca_00528be4);
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
    if (*(int *)(&DAT_00676620 + local_10 * 0x114) == 0) {
      local_c = local_10;
      goto LAB_00493934;
    }
    local_10 = local_10 + 1;
  } while( true );
}


