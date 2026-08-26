/*
 * Decompiled function: thunk_FUN_10005abe
 * Entry Point: 10001082
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl thunk_FUN_10005abe(FILE *fp,int *ptr_2)

{
  int32_t uval_1;
  int val_2;
  void *buf_ptr_3;
  int32_t auStack_50 [4];
  int16_t uStack_40;
  void *pvStack_3c;
  int iStack_38;
  uint32_t uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int32_t uStack_24;
  int32_t uStack_20;
  uint8_t auStack_1c [4];
  int32_t uStack_18;
  int iStack_14;
  size_t sStack_10;
  size_t sStack_c;
  int32_t uStack_8;
  
  pvStack_3c = (void *)0x0;
  uStack_24 = 0;
  sStack_10 = 0;
  uStack_20 = 0;
  sStack_c = 0;
  uStack_8 = 0;
  uStack_34 = 0;
  iStack_38 = 0;
  fseek(fp,0,0);
  fread(&iStack_30,1,0xc,fp);
  uStack_34 = iStack_2c + iStack_38 + 8;
  if ((iStack_30 == 0x46464952) && (iStack_28 == 0x45564157)) {
    val_2 = thunk_FUN_10005dff(fp,0x20746d66,iStack_38,uStack_34);
    if (val_2 == 0) {
      uval_1 = 8;
    }
    else {
      fread(auStack_1c,1,8,fp);
      fread(auStack_50,1,0x10,fp);
      uStack_40 = 0;
      val_2 = thunk_FUN_10005dff(fp,0x61746164,iStack_38,uStack_34);
      if (val_2 == 0) {
        uval_1 = 8;
      }
      else {
        fread(auStack_1c,1,8,fp);
        uStack_8 = 0xea;
        buf_ptr_3 = thunk_FUN_10006540(DAT_1000ba90,uStack_18,auStack_50,0xea);
        *ptr_2 = (int)buf_ptr_3;
        if (*ptr_2 == 0) {
          uval_1 = 9;
        }
        else {
          iStack_14 = (**(code **)(**(int **)(*ptr_2 + 0xbc) + 0x2c))
                                (*(int32_t *)(*ptr_2 + 0xbc),0,uStack_18,&pvStack_3c,&sStack_10,
                                 &uStack_24,&uStack_20,0);
          if (iStack_14 == 0) {
            sStack_c = fread(pvStack_3c,1,sStack_10,fp);
            if (sStack_10 == sStack_c) {
              iStack_14 = (**(code **)(**(int **)(*ptr_2 + 0xbc) + 0x4c))
                                    (*(int32_t *)(*ptr_2 + 0xbc),pvStack_3c,sStack_10,uStack_24,
                                     uStack_20);
              if (iStack_14 == 0) {
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


