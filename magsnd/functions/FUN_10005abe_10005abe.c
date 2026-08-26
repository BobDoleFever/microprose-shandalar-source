/*
 * Decompiled function: FUN_10005abe
 * Entry Point: 10005abe
 * Size: 652 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_10005abe(FILE *fp,int *ptr_2)

{
  int32_t uval_1;
  int val_2;
  void *buf_ptr_3;
  int32_t local_50 [4];
  int16_t local_40;
  void *local_3c;
  int local_38;
  uint32_t local_34;
  int local_30;
  int local_2c;
  int local_28;
  int32_t local_24;
  int32_t local_20;
  uint8_t local_1c [4];
  int32_t local_18;
  int local_14;
  size_t local_10;
  size_t local_c;
  int32_t local_8;
  
  local_3c = (void *)0x0;
  local_24 = 0;
  local_10 = 0;
  local_20 = 0;
  local_c = 0;
  local_8 = 0;
  local_34 = 0;
  local_38 = 0;
  fseek(fp,0,0);
  fread(&local_30,1,0xc,fp);
  local_34 = local_2c + local_38 + 8;
  if ((local_30 == 0x46464952) && (local_28 == 0x45564157)) {
    val_2 = thunk_FUN_10005dff(fp,0x20746d66,local_38,local_34);
    if (val_2 == 0) {
      uval_1 = 8;
    }
    else {
      fread(local_1c,1,8,fp);
      fread(local_50,1,0x10,fp);
      local_40 = 0;
      val_2 = thunk_FUN_10005dff(fp,0x61746164,local_38,local_34);
      if (val_2 == 0) {
        uval_1 = 8;
      }
      else {
        fread(local_1c,1,8,fp);
        local_8 = 0xea;
        buf_ptr_3 = thunk_FUN_10006540(DAT_1000ba90,local_18,local_50,0xea);
        *ptr_2 = (int)buf_ptr_3;
        if (*ptr_2 == 0) {
          uval_1 = 9;
        }
        else {
          local_14 = (**(code **)(**(int **)(*ptr_2 + 0xbc) + 0x2c))
                               (*(int32_t *)(*ptr_2 + 0xbc),0,local_18,&local_3c,&local_10,
                                &local_24,&local_20,0);
          if (local_14 == 0) {
            local_c = fread(local_3c,1,local_10,fp);
            if (local_10 == local_c) {
              local_14 = (**(code **)(**(int **)(*ptr_2 + 0xbc) + 0x4c))
                                   (*(int32_t *)(*ptr_2 + 0xbc),local_3c,local_10,local_24,
                                    local_20);
              if (local_14 == 0) {
                uval_1 = 0;
              }
              else {
                (**(code **)(**(int **)(*ptr_2 + 0xbc) + 8))(*(int32_t *)(*ptr_2 + 0xbc));
                operator_delete((void *)*ptr_2);
                uval_1 = 9;
              }
            }
            else {
              thunk_FUN_10006622((void *)*ptr_2);
              uval_1 = 9;
            }
          }
          else {
            thunk_FUN_10006622((void *)*ptr_2);
            uval_1 = 9;
          }
        }
      }
    }
  }
  else {
    uval_1 = 8;
  }
  return uval_1;
}


