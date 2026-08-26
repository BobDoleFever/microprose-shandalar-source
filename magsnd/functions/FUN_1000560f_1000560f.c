/*
 * Decompiled function: FUN_1000560f
 * Entry Point: 1000560f
 * Size: 1079 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_1000560f(LPSTR arg_1,int *ptr_2)

{
  int32_t uval_1;
  MMRESULT MVar2;
  DWORD DVar3;
  void *pvVar4;
  size_t sVar5;
  LONG LVar6;
  int val_7;
  int val_8;
  _MMIOINFO *p_Var9;
  _MMCKINFO *p_Var10;
  DWORD *pDVar11;
  FOURCC *pFVar12;
  int32_t uStack0000000c;
  _MMCKINFO local_98;
  char local_84 [16];
  int16_t local_74;
  _MMIOINFO local_70;
  int32_t local_28;
  DWORD local_24;
  LONG local_20;
  _MMCKINFO local_1c;
  HMMIO local_8;
  
  local_28 = 0;
  memset(&local_70,0,0x48);
  local_70.cchBuffer = 0x10000;
  local_8 = mmioOpenA(arg_1,&local_70,0x10000);
  if (local_8 == (HMMIO)0x0) {
    uval_1 = 7;
  }
  else {
    local_1c.fccType = 0x45564157;
    MVar2 = mmioDescend(local_8,&local_1c,(MMCKINFO *)0x0,0x20);
    if (MVar2 == 0) {
      local_98.ckid = 0x20746d66;
      MVar2 = mmioDescend(local_8,&local_98,&local_1c,0x10);
      if (MVar2 == 0) {
        local_24 = local_98.cksize;
        DVar3 = mmioRead(local_8,local_84,local_98.cksize);
        if (DVar3 == local_24) {
          local_74 = 0;
          mmioAscend(local_8,&local_98,0);
          local_98.ckid = 0x61746164;
          MVar2 = mmioDescend(local_8,&local_98,&local_1c,0x10);
          if (MVar2 == 0) {
            mmioGetInfo(local_8,&local_70,0);
            mmioAdvance(local_8,&local_70,0);
            local_20 = local_70.lBufOffset;
            uStack0000000c = 0xe8;
            pvVar4 = thunk_FUN_10006540(DAT_1000ba90,0x10000,(int32_t *)local_84,0xe8);
            *ptr_2 = (int)pvVar4;
            if (*ptr_2 == 0) {
              mmioClose(local_8,0);
              uval_1 = 9;
            }
            else {
              *(LONG *)(*ptr_2 + 0x1e0) = local_20;
              *(HMMIO *)(*ptr_2 + 0x1c8) = local_8;
              p_Var9 = &local_70;
              pDVar11 = (DWORD *)(*ptr_2 + 0x180);
              for (val_7 = 0x12; val_7 != 0; val_7 = val_7 + -1) {
                *pDVar11 = p_Var9->dwFlags;
                p_Var9 = (_MMIOINFO *)&p_Var9->fccIOProc;
                pDVar11 = pDVar11 + 1;
              }
              *(DWORD *)(*ptr_2 + 0x1cc) = local_98.cksize;
              sVar5 = strlen(arg_1);
              pvVar4 = operator_new(sVar5 + 1);
              *(void **)*ptr_2 = pvVar4;
              if (*(int *)*ptr_2 == 0) {
                mmioClose(local_8,0);
                uval_1 = 3;
              }
              else {
                strcpy(*(char **)*ptr_2,arg_1);
                *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) & 0xffffffdf;
                *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 2;
                *(int32_t *)(*ptr_2 + 0x8c) = 0;
                *(int32_t *)(*ptr_2 + 0x90) = 0;
                *(int32_t *)(*ptr_2 + 0x94) = 0;
                mmioAscend(local_8,&local_98,0);
                local_98.ckid = 0x20657563;
                MVar2 = mmioDescend(local_8,&local_98,&local_1c,0x10);
                if (MVar2 == 0) {
                  val_7 = *ptr_2;
                  p_Var10 = &local_98;
                  pFVar12 = (FOURCC *)(val_7 + 0x1c);
                  for (val_8 = 5; val_8 != 0; val_8 = val_8 + -1) {
                    *pFVar12 = p_Var10->ckid;
                    p_Var10 = (_MMCKINFO *)&p_Var10->cksize;
                    pFVar12 = pFVar12 + 1;
                  }
                  LVar6 = mmioRead(local_8,(HPSTR)(val_7 + 0x30),4);
                  if (LVar6 != 4) {
                    thunk_FUN_10006622((void *)*ptr_2);
                    mmioClose(local_8,0);
                    return 8;
                  }
                  pvVar4 = operator_new(*(int *)(val_7 + 0x30) * 0x18);
                  *(void **)(val_7 + 0x34) = pvVar4;
                  if (*(int *)(val_7 + 0x34) == 0) {
                    thunk_FUN_10006622((void *)*ptr_2);
                    mmioClose(local_8,0);
                    return 3;
                  }
                  local_24 = *(int *)(val_7 + 0x30) * 0x18;
                  LVar6 = mmioRead(local_8,*(HPSTR *)(val_7 + 0x34),local_24);
                  if (LVar6 != local_24) {
                    thunk_FUN_10006622((void *)*ptr_2);
                    mmioClose(local_8,0);
                    operator_delete(*(void **)(val_7 + 0x34));
                    return 8;
                  }
                }
                uval_1 = 0;
              }
            }
          }
          else {
            mmioClose(local_8,0);
            uval_1 = 8;
          }
        }
        else {
          mmioClose(local_8,0);
          uval_1 = 8;
        }
      }
      else {
        mmioClose(local_8,0);
        uval_1 = 8;
      }
    }
    else {
      mmioClose(local_8,0);
      uval_1 = 8;
    }
  }
  return uval_1;
}


