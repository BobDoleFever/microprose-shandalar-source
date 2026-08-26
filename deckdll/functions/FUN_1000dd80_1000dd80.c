/*
 * Decompiled function: FUN_1000dd80
 * Entry Point: 1000dd80
 * Size: 588 bytes
 */
#include "deckdll.h"


int FUN_1000dd80(char *str_1)

{
  int val_1;
  FILE *pFVar2;
  void *buf_ptr_3;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  
  local_10 = -1;
  local_c = 0;
  do {
    if (4 < local_c) {
LAB_1000ddd4:
      thunk_FUN_10016850((uint32_t)(local_10 != -1),0x10041490,0x43,
                         s_Too_many_open_Catalogs__Max__d_10041470);
      val_1 = local_10 * 0x114;
      *(int32_t *)(&DAT_102050bc + val_1) = 0;
      strcpy((char *)(val_1 + 0x102050c0),str_1);
      pFVar2 = fopen(str_1,&DAT_100414b8);
      *(FILE **)(&DAT_102050b0 + val_1) = pFVar2;
      pFVar2 = *(FILE **)(&DAT_102050b0 + val_1);
      if (pFVar2 == (FILE *)0x0) {
        local_10 = 0;
      }
      else {
        fread(&DAT_102050b4 + val_1,4,1,pFVar2);
        buf_ptr_3 = malloc(*(int *)(&DAT_102050b4 + val_1) * 0xc);
        *(void **)(&DAT_102050b8 + val_1) = buf_ptr_3;
        fread(*(void **)(&DAT_102050b8 + val_1),0xc,*(size_t *)(&DAT_102050b4 + val_1),pFVar2);
        if (DAT_1004146c != 0) {
          for (local_c = 0; local_c < 5; local_c = local_c + 1) {
            if ((local_10 != local_c) && (*(int *)(&DAT_102050b0 + local_c * 0x114) != 0)) {
              local_18 = 0;
              while (*(int *)(&DAT_102050b4 + val_1) != 0) {
                for (local_1c = 0; local_1c < *(int *)(&DAT_102050b4 + local_c * 0x114);
                    local_1c = local_1c + 1) {
                  thunk_FUN_10016850((uint32_t)(*(int *)(*(int *)(&DAT_102050b8 + val_1) +
                                                    local_18 * 0xc) !=
                                           *(int *)(*(int *)(&DAT_102050b8 + local_c * 0x114) +
                                                   local_18 * 0xc)),0x10041518,0x69,
                                     s_Duplicate_short_name_found_in_ca_100414bc);
                }
                local_18 = local_18 + 1;
              }
            }
          }
        }
        local_10 = local_10 + 1;
      }
      return local_10;
    }
    if (*(int *)(&DAT_102050b0 + local_c * 0x114) == 0) {
      local_10 = local_c;
      goto LAB_1000ddd4;
    }
    local_c = local_c + 1;
  } while( true );
}


