/*
 * Decompiled function: thunk_FUN_1000560f
 * Entry Point: 100010f5
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl thunk_FUN_1000560f(LPSTR arg_1,int *ptr_2)

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
  _MMCKINFO _Stack_98;
  char acStack_84 [16];
  int16_t uStack_74;
  _MMIOINFO _Stack_70;
  int32_t uStack_28;
  DWORD DStack_24;
  LONG LStack_20;
  _MMCKINFO _Stack_1c;
  HMMIO pHStack_8;
  
  uStack_28 = 0;
  memset(&_Stack_70,0,0x48);
  _Stack_70.cchBuffer = 0x10000;
  pHStack_8 = mmioOpenA(arg_1,&_Stack_70,0x10000);
  if (pHStack_8 == (HMMIO)0x0) {
    uval_1 = 7;
  }
  else {
    _Stack_1c.fccType = 0x45564157;
    MVar2 = mmioDescend(pHStack_8,&_Stack_1c,(MMCKINFO *)0x0,0x20);
    if (MVar2 == 0) {
      _Stack_98.ckid = 0x20746d66;
      MVar2 = mmioDescend(pHStack_8,&_Stack_98,&_Stack_1c,0x10);
      if (MVar2 == 0) {
        DStack_24 = _Stack_98.cksize;
        DVar3 = mmioRead(pHStack_8,acStack_84,_Stack_98.cksize);
        if (DVar3 == DStack_24) {
          uStack_74 = 0;
          mmioAscend(pHStack_8,&_Stack_98,0);
          _Stack_98.ckid = 0x61746164;
          MVar2 = mmioDescend(pHStack_8,&_Stack_98,&_Stack_1c,0x10);
          if (MVar2 == 0) {
            mmioGetInfo(pHStack_8,&_Stack_70,0);
            mmioAdvance(pHStack_8,&_Stack_70,0);
            LStack_20 = _Stack_70.lBufOffset;
            uStack0000000c = 0xe8;
            pvVar4 = thunk_FUN_10006540(DAT_1000ba90,0x10000,(int32_t *)acStack_84,0xe8);
            *ptr_2 = (int)pvVar4;
            if (*ptr_2 == 0) {
              mmioClose(pHStack_8,0);
              uval_1 = 9;
            }
            else {
              *(LONG *)(*ptr_2 + 0x1e0) = LStack_20;
              *(HMMIO *)(*ptr_2 + 0x1c8) = pHStack_8;
              p_Var9 = &_Stack_70;
              pDVar11 = (DWORD *)(*ptr_2 + 0x180);
              for (val_7 = 0x12; val_7 != 0; val_7 = val_7 + -1) {
                *pDVar11 = p_Var9->dwFlags;
                p_Var9 = (_MMIOINFO *)&p_Var9->fccIOProc;
                pDVar11 = pDVar11 + 1;
              }
              *(DWORD *)(*ptr_2 + 0x1cc) = _Stack_98.cksize;
              sVar5 = strlen(arg_1);
              pvVar4 = operator_new(sVar5 + 1);
              *(void **)*ptr_2 = pvVar4;
              if (*(int *)*ptr_2 == 0) {
                mmioClose(pHStack_8,0);
                uval_1 = 3;
              }
              else {
                strcpy(*(char **)*ptr_2,arg_1);
                *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) & 0xffffffdf;
                *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 2;
                *(int32_t *)(*ptr_2 + 0x8c) = 0;
                *(int32_t *)(*ptr_2 + 0x90) = 0;
                *(int32_t *)(*ptr_2 + 0x94) = 0;
                mmioAscend(pHStack_8,&_Stack_98,0);
                _Stack_98.ckid = 0x20657563;
                MVar2 = mmioDescend(pHStack_8,&_Stack_98,&_Stack_1c,0x10);
                if (MVar2 == 0) {
                  val_7 = *ptr_2;
                  p_Var10 = &_Stack_98;
                  pFVar12 = (FOURCC *)(val_7 + 0x1c);
                  for (val_8 = 5; val_8 != 0; val_8 = val_8 + -1) {
                    *pFVar12 = p_Var10->ckid;
                    p_Var10 = (_MMCKINFO *)&p_Var10->cksize;
                    pFVar12 = pFVar12 + 1;
                  }
                  LVar6 = mmioRead(pHStack_8,(HPSTR)(val_7 + 0x30),4);
                  if (LVar6 != 4) {
                    thunk_FUN_10006622((void *)*ptr_2);
                    mmioClose(pHStack_8,0);
                    return 8;
                  }
                  pvVar4 = operator_new(*(int *)(val_7 + 0x30) * 0x18);
                  *(void **)(val_7 + 0x34) = pvVar4;
                  if (*(int *)(val_7 + 0x34) == 0) {
                    thunk_FUN_10006622((void *)*ptr_2);
                    mmioClose(pHStack_8,0);
                    return 3;
                  }
                  DStack_24 = *(int *)(val_7 + 0x30) * 0x18;
                  LVar6 = mmioRead(pHStack_8,*(HPSTR *)(val_7 + 0x34),DStack_24);
                  if (LVar6 != DStack_24) {
                    thunk_FUN_10006622((void *)*ptr_2);
                    mmioClose(pHStack_8,0);
                    operator_delete(*(void **)(val_7 + 0x34));
                    return 8;
                  }
                }
                uval_1 = 0;
              }
            }
          }
          else {
            mmioClose(pHStack_8,0);
            uval_1 = 8;
          }
        }
        else {
          mmioClose(pHStack_8,0);
          uval_1 = 8;
        }
      }
      else {
        mmioClose(pHStack_8,0);
        uval_1 = 8;
      }
    }
    else {
      mmioClose(pHStack_8,0);
      uval_1 = 8;
    }
  }
  return uval_1;
}


