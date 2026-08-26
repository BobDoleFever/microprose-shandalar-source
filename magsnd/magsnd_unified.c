#include "magsnd_unified.h"


int DAT_1000a410;
int DAT_1000a414;
int *DAT_1000ba90;
int DAT_1000a41c;
int DAT_1000a418;
uint8_t DAT_1000a648;
uint8_t DAT_1000baa0;
int32_t DAT_1000a438;
string s_G:\NewMagic\tstvid\snd.cpp_1000a484;
string s_G:\NewMagic\tstvid\snd.cpp_1000a4a0;
string s_G:\NewMagic\tstvid\snd.cpp_1000a4bc;
string s_G:\NewMagic\tstvid\snd.cpp_1000a4d8;
int DAT_1000a428;
int DAT_1000a434;
int32_t DAT_1000ba90;
int32_t DAT_1000a640;
int DAT_1000ba88;
int DAT_1000a424;
int32_t DAT_1000a420;
uint8_t DAT_1000a440;
uint8_t DAT_1000a458;
HWND DAT_1000ba88;
uint32_t DAT_1000a438;
uint32_t DAT_1000a474;
uint8_t DAT_1000aa88;
uint8_t DAT_1000aa8c;
uint8_t DAT_1000a520;
UINT DAT_1000a480;
int32_t DAT_1000ba98;
MMRESULT DAT_1000ba94;
int32_t DAT_1000a424;
uint8_t LAB_1000110e;
int32_t DAT_1000ba88;
UINT DAT_1000ba94;
int DAT_1000a420;
int32_t DAT_1000a42c;
uint8_t DAT_1000a47c;
uint8_t DAT_1000a524;
int DAT_1000a46c;
int32_t *DAT_1000a418;
uint8_t DAT_1000a430;
int DAT_1000a530;
int DAT_1000a534;
uint8_t *PTR__adjust_fdiv_1000c33c;
uint8_t DAT_1000bf50;
int *DAT_1000bf6c;
int *DAT_1000bf5c;
uint8_t DAT_1000a000;
uint8_t DAT_1000a104;
uint8_t *DAT_1000bf70;
int DAT_1000a538;
int32_t DAT_1000bf6c;
int32_t DAT_1000bf5c;
int DAT_1000bf70;

void __cdecl thunk_FUN_10005a46(int32_t *ptr_1)

{
  mmioClose((HMMIO)ptr_1[0x72],0);
  if (ptr_1[0xd] != 0) {
    operator_delete((void *)ptr_1[0xd]);
  }
  if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
    operator_delete((void *)*ptr_1);
  }
  return;
}



void __cdecl thunk_FUN_1000460c(int arg_1)

{
  if (DAT_1000a410 == 0) {
    DAT_1000a410 = arg_1;
  }
  else {
    *(int *)(DAT_1000a414 + 0x200) = arg_1;
    *(int *)(arg_1 + 0x1fc) = DAT_1000a414;
  }
  DAT_1000a414 = arg_1;
  return;
}



int32_t __cdecl thunk_FUN_1000667b(int32_t arg_1,int *ptr_2)

{
  int32_t uval_1;
  void *buf_ptr_2;
  int val_3;
  int32_t *puVar4;
  int32_t *puVar5;
  int32_t uStack0000000c;
  int32_t auStack_fc [4];
  int16_t uStack_ec;
  int32_t auStack_e8 [18];
  uint8_t auStack_a0 [4];
  int iStack_9c;
  int iStack_98;
  int32_t uStack_94;
  int aiStack_90 [8];
  int iStack_70;
  int iStack_68;
  int iStack_60;
  
  uStack_94 = 0x12;
  AVIStreamInfoA(arg_1,aiStack_90,0x8c);
  if (aiStack_90[0] == 0x73647561) {
    AVIStreamRead(arg_1,0,1,0,0,auStack_a0,0);
    iStack_98 = iStack_60 * iStack_70;
    AVIStreamReadFormat(arg_1,0,auStack_fc,&uStack_94);
    uStack_ec = 0;
    uStack0000000c = 0xe8;
    iStack_9c = iStack_68 * 0xb;
    buf_ptr_2 = thunk_FUN_10006540(DAT_1000ba90,iStack_9c,auStack_fc,0xe8);
    *ptr_2 = (int)buf_ptr_2;
    if (*ptr_2 == 0) {
      uval_1 = 9;
    }
    else {
      *(int32_t *)(*ptr_2 + 0x1e0) = 0;
      *(int32_t *)(*ptr_2 + 0x1c8) = 0;
      puVar4 = auStack_e8;
      puVar5 = (int32_t *)(*ptr_2 + 0x180);
      for (val_3 = 0x12; val_3 != 0; val_3 = val_3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      *(int *)(*ptr_2 + 0x1cc) = iStack_98;
      *(int32_t *)*ptr_2 = arg_1;
      *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 0x20;
      *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 2;
      *(int *)(*ptr_2 + 0x8c) = iStack_68;
      *(int *)(*ptr_2 + 0x90) = iStack_60;
      *(int32_t *)(*ptr_2 + 0x94) = 0xb;
      *(int32_t *)(*ptr_2 + 0x1dc) = 0;
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 8;
  }
  return uval_1;
}



void __cdecl thunk_FUN_1000458d(int arg_1)

{
  int val_1;
  int val_2;
  int val_3;
  
  val_1 = *(int *)(arg_1 + 500);
  val_2 = *(int *)(arg_1 + 0x1f8);
  val_3 = val_2;
  if (val_1 != 0) {
    *(int *)(val_1 + 0x1f8) = val_2;
    val_3 = DAT_1000a418;
  }
  DAT_1000a418 = val_3;
  if (val_2 != 0) {
    *(int *)(val_2 + 500) = val_1;
    val_1 = DAT_1000a41c;
  }
  DAT_1000a41c = val_1;
  return;
}



int __cdecl SetSndMarker(int arg1,uint32_t arg2)

{
  int32_t *ptr_1;
  int iStack_8;
  
                    /* 0x1014  18  SetSndMarker */
  if ((arg1 < 0x100) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    ptr_1 = *(int32_t **)(&DAT_1000a648 + arg1 * 4);
    if (ptr_1 == (int32_t *)0x0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      iStack_8 = 1;
    }
    else if ((ptr_1[0xc] == 0) || ((uint32_t)ptr_1[0xc] < arg2)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      iStack_8 = 5;
    }
    else {
      if (ptr_1[arg2 + 0xd] == 0) {
        iStack_8 = thunk_FUN_1000207f(ptr_1,arg2);
      }
      else {
        iStack_8 = thunk_FUN_1000219c((int)ptr_1,arg2);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
  }
  else {
    iStack_8 = 5;
  }
  return iStack_8;
}



int32_t __cdecl GetSndState(int arg1,int32_t *arg2)

{
  int32_t uval_1;
  
                    /* 0x1019  22  GetSndState */
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      if ((*(uint8_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) & 1) == 0) {
        if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) >> 3 & 1) == 0) {
          *arg2 = 0;
        }
        else {
          *arg2 = 2;
        }
      }
      else {
        *arg2 = 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t __cdecl PlaySnd(int arg1,int *arg2)

{
  int32_t uval_1;
  
                    /* 0x101e  6  PlaySnd */
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      thunk_FUN_1000192c(*(int32_t **)(&DAT_1000a648 + arg1 * 4),arg2);
      *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xc) =
           *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xc) + 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int __cdecl thunk_FUN_1000394f(int32_t *ptr_1)

{
  int val_1;
  
  ptr_1[1] = ptr_1[1] & 0xfffffffe;
  ptr_1[1] = ptr_1[1] & 0xfffffffd;
  ptr_1[1] = ptr_1[1] & 0xffffffef;
  ptr_1[1] = ptr_1[1] & 0xfffffffb;
  ptr_1[0x74] = 0;
  ptr_1[0x75] = 0;
  ptr_1[0x76] = 0;
  ptr_1[0x77] = 0;
  DAT_1000a438 = 0;
  if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
    ptr_1[0x67] = ptr_1[0x68];
    mmioSetInfo((HMMIO)ptr_1[0x72],(LPCMMIOINFO)(ptr_1 + 0x60),0);
    val_1 = thunk_FUN_10005f0c(ptr_1,0);
    if (val_1 != 0) {
      return val_1;
    }
  }
  else {
    thunk_FUN_1000630c(ptr_1);
  }
  ptr_1[1] = ptr_1[1] | 0x20;
  return 0;
}



int32_t UnloadAllSnds(void)

{
                    /* 0x1028  5  UnloadAllSnds */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  while (DAT_1000a410 != 0) {
    UnloadSnd(*(int *)(DAT_1000a410 + 0x10));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  return 0;
}



int __cdecl thunk_FUN_1000219c(int arg1,int arg2)

{
  int32_t *ptr_1;
  int val_1;
  
  if (((*(uint32_t *)(arg1 + 4) >> 6 & 1) == 0) || (*(int *)(arg1 + 0x18) != arg2 + -1)) {
    ptr_1 = *(int32_t **)(arg1 + 0x34 + arg2 * 4);
    val_1 = thunk_FUN_10005f0c(ptr_1,*(int *)(*(int *)(arg1 + 0x34) + (arg2 * 3 + -3) * 8 + 0x14));
    if (val_1 == 0) {
      ptr_1[1] = ptr_1[1] | 0x20;
      ptr_1[1] = ptr_1[1] & 0xfffffffb;
      ptr_1[1] = ptr_1[1] & 0xffffffef;
      ptr_1[0x76] = 0;
      ptr_1[2] = *(uint32_t *)(arg1 + 8) & 1 | ptr_1[2] & 0xfffffffe;
      ptr_1[0x7c] = *(int32_t *)(arg1 + 0x1f0);
      ptr_1[0x7b] = *(int32_t *)(arg1 + 0x1ec);
      ptr_1[0x7a] = *(int32_t *)(arg1 + 0x1e8);
      val_1 = 0;
    }
  }
  else {
    val_1 = 0xd;
  }
  return val_1;
}



int32_t __cdecl GetAVISndBuff(int arg1,uint32_t arg2)

{
  code *char_ptr_1;
  int val_2;
  int32_t uval_3;
  int32_t uStack_28;
  int iStack_24;
  int32_t uStack_20;
  uint32_t uStack_1c;
  int iStack_18;
  int iStack_14;
  int32_t uStack_10;
  int32_t uStack_c;
  int iStack_8;
  
                    /* 0x1032  23  GetAVISndBuff */
  uStack_28 = 0;
  iStack_14 = 0;
  uStack_c = 0;
  uStack_10 = 0;
  uStack_20 = 0;
  if ((arg1 < 0x110) && (0xff < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    iStack_24 = *(int *)(&DAT_1000a648 + arg1 * 4);
    if (iStack_24 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uStack_28 = 0;
    }
    else {
      if ((*(uint32_t *)(iStack_24 + 4) >> 7 & 1) != 0) {
        val_2 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a484,0x484,0,0);
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_3 = (*char_ptr_1)();
          return uval_3;
        }
      }
      if ((*(uint32_t *)(iStack_24 + 4) >> 7 & 1) == 0) {
        uStack_1c = arg2 % *(uint32_t *)(iStack_24 + 0x94);
        iStack_8 = *(int *)(iStack_24 + 0x8c) * uStack_1c;
        iStack_18 = (**(code **)(**(int **)(iStack_24 + 0xbc) + 0x2c))
                              (*(int32_t *)(iStack_24 + 0xbc),iStack_8,
                               *(int32_t *)(iStack_24 + 0x8c),&uStack_28,&uStack_c,&iStack_14,
                               &uStack_10,0);
        if (iStack_18 == 0) {
          if (iStack_14 != 0) {
            val_2 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a4a0,0x496,0,0);
            if (val_2 == 1) {
              char_ptr_1 = (code *)swi(3);
              uval_3 = (*char_ptr_1)();
              return uval_3;
            }
          }
          if (iStack_14 == 0) {
            *(int32_t *)(iStack_24 + 0xa4) = uStack_28;
            *(uint32_t *)(iStack_24 + 4) = *(uint32_t *)(iStack_24 + 4) | 0x80;
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          }
          else {
            (**(code **)(**(int **)(iStack_24 + 0xbc) + 0x4c))
                      (*(int32_t *)(iStack_24 + 0xbc),uStack_28,uStack_c,iStack_14,uStack_10);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            uStack_28 = 0;
          }
        }
        else {
          uStack_28 = 0;
        }
      }
      else {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        uStack_28 = 0;
      }
    }
  }
  else {
    uStack_28 = 0;
  }
  return uStack_28;
}



int32_t __cdecl ReleaseAVISndBuff(int arg_1)

{
  int val_1;
  code *char_ptr_2;
  int32_t uval_3;
  int val_4;
  
                    /* 0x1037  24  ReleaseAVISndBuff */
  if ((arg_1 < 0x110) && (0xff < arg_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    val_1 = *(int *)(&DAT_1000a648 + arg_1 * 4);
    if (val_1 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_3 = 0;
    }
    else {
      if ((*(uint32_t *)(val_1 + 4) >> 7 & 1) == 0) {
        val_4 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a4bc,0x4b0,0,0);
        if (val_4 == 1) {
          char_ptr_2 = (code *)swi(3);
          uval_3 = (*char_ptr_2)();
          return uval_3;
        }
      }
      if ((*(uint32_t *)(val_1 + 4) >> 7 & 1) == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        uval_3 = 0xe;
      }
      else {
        if (*(int *)(val_1 + 0xa4) == 0) {
          val_4 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a4d8,0x4b5,0,0);
          if (val_4 == 1) {
            char_ptr_2 = (code *)swi(3);
            uval_3 = (*char_ptr_2)();
            return uval_3;
          }
        }
        if (*(int *)(val_1 + 0xa4) == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          uval_3 = 0xf;
        }
        else {
          (**(code **)(**(int **)(val_1 + 0xbc) + 0x4c))
                    (*(int32_t *)(val_1 + 0xbc),*(int32_t *)(val_1 + 0xa4),
                     *(int32_t *)(val_1 + 0x8c),0,0);
          *(uint32_t *)(val_1 + 4) = *(uint32_t *)(val_1 + 4) & 0xffffff7f;
          *(int32_t *)(val_1 + 0xa4) = 0;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          uval_3 = 0;
        }
      }
    }
  }
  else {
    uval_3 = 0;
  }
  return uval_3;
}



void StopAllSnds(void)

{
  int iStack_8;
  
                    /* 0x103c  9  StopAllSnds */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  for (iStack_8 = DAT_1000a410; iStack_8 != 0; iStack_8 = *(int *)(iStack_8 + 0x200)) {
    StopSnd(*(int *)(iStack_8 + 0x10));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  return;
}



int32_t ResetSnd(void)

{
                    /* 0x1041  21  ResetSnd */
  return 0;
}



int32_t __cdecl GetLRUSnd(int *ptr_1,int arg_2,int arg_3)

{
  int iStack_14;
  int iStack_10;
  uint32_t uStack_c;
  int32_t uStack_8;
  
                    /* 0x1046  27  GetLRUSnd */
  uStack_8 = 0;
  uStack_c = 0xffffffff;
  if (((arg_3 == 0) || (arg_3 <= arg_2)) || (0xff < arg_3)) {
    iStack_10 = 0;
    arg_3 = 0xff;
  }
  else {
    iStack_10 = arg_2;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  do {
    if (arg_3 <= iStack_10) {
LAB_100035b3:
      *ptr_1 = iStack_14;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      return uStack_8;
    }
    if (*(int *)(&DAT_1000a648 + iStack_10 * 4) == 0) {
      iStack_14 = iStack_10;
      uStack_8 = 1;
      goto LAB_100035b3;
    }
    if (*(uint32_t *)(*(int *)(&DAT_1000a648 + iStack_10 * 4) + 0xc) < uStack_c) {
      uStack_c = *(uint32_t *)(*(int *)(&DAT_1000a648 + iStack_10 * 4) + 0xc);
      iStack_14 = *(int *)(*(int *)(&DAT_1000a648 + iStack_10 * 4) + 0x10);
    }
    iStack_10 = iStack_10 + 1;
  } while( true );
}



int32_t __cdecl thunk_FUN_10002900(int arg_1)

{
  int32_t uval_1;
  int val_2;
  int *i_ptr_3;
  int val_4;
  int iStack_10;
  
  if ((arg_1 < 0x110) && (-1 < arg_1)) {
    if (*(int *)(&DAT_1000a648 + arg_1 * 4) == 0) {
      uval_1 = 1;
    }
    else {
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) >> 6 & 1) == 0) {
        val_4 = (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc) + 0x48))
                          (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc));
        if (val_4 != 0) {
          return 9;
        }
      }
      else {
        val_4 = *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 +
                        *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x18) * 4);
        if (val_4 == 0) {
          return 1;
        }
        val_2 = (**(code **)(**(int **)(val_4 + 0xbc) + 0x48))(*(int32_t *)(val_4 + 0xbc));
        if (val_2 != 0) {
          return 9;
        }
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xffffffbf;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) & 0xfffffffe;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) & 0xfffffffd;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) | 4;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) & 0xffffffdf;
      }
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) == 0) {
        iStack_10 = 0;
        while ((iStack_10 < 0x10 &&
               (i_ptr_3 = (int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + iStack_10 * 0xc + 0xc0),
               *i_ptr_3 != 0))) {
          val_4 = (**(code **)(*(int *)*i_ptr_3 + 0x48))(*i_ptr_3);
          if (val_4 != 0) {
            return 9;
          }
          iStack_10 = iStack_10 + 1;
        }
      }
      else if ((0 < DAT_1000a428) && (DAT_1000a428 = DAT_1000a428 + -1, DAT_1000a428 == 0)) {
        thunk_FUN_10004788();
      }
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xfffffffe;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xfffffffd;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) | 4;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xffffffdf;
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t __cdecl InitSnd(int arg_1,int32_t arg_2,uint8_t arg_3)

{
  int32_t uval_1;
  int val_2;
  uint8_t auStack_8 [4];
  
                    /* 0x1050  1  InitSnd */
  if (((arg_3 & 2) == 0) || (DAT_1000a434 != 0)) {
    if (((arg_3 & 2) == 0) || (DAT_1000a434 == 0)) {
      if ((DAT_1000a434 == 0) && (arg_1 != 0)) {
        val_2 = DirectSoundCreate(0,&DAT_1000ba90,0);
        if (val_2 != 0) {
          return 4;
        }
        val_2 = (**(code **)(*DAT_1000ba90 + 0x18))(DAT_1000ba90,arg_1,3);
        if (val_2 != 0) {
          ReleaseSnd();
          return 4;
        }
        val_2 = (**(code **)(*DAT_1000ba90 + 0xc))(DAT_1000ba90,&DAT_1000a440,&DAT_1000a640,0);
        if (val_2 != 0) {
          ReleaseSnd();
          return 4;
        }
        val_2 = (**(code **)(*DAT_1000a640 + 0x38))(DAT_1000a640,&DAT_1000a458);
        if (val_2 != 0) {
          (**(code **)(*DAT_1000a640 + 0x14))(DAT_1000a640,&DAT_1000a458,0x12,auStack_8);
        }
        DAT_1000ba88 = arg_1;
        DAT_1000a434 = DAT_1000a434 + 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      }
      if ((arg_3 & 1) != 0) {
        if (DAT_1000a424 != 0) {
          thunk_FUN_10004788();
        }
        DAT_1000a420 = 0;
      }
      uval_1 = 0;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 4;
  }
  return uval_1;
}



/* WARNING: Removing unreachable block (ram,0x10002ce6) */

int32_t __cdecl SetVol(int arg1,uint32_t arg2)

{
  int val_1;
  int32_t uval_2;
  int *i_ptr_3;
  int iStack_10;
  
                    /* 0x1055  13  SetVol */
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_2 = 1;
    }
    else {
      if (400 < arg2) {
        arg2 = 400;
      }
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) >> 6 & 1) == 0) {
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1f0) = arg2;
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1f0) = arg2;
        arg2 = (arg2 * 5 + -2000) * 2;
        (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc) + 0x3c))
                  (*(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc),arg2);
      }
      else {
        val_1 = *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x38 +
                        *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x18) * 4);
        if (val_1 == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return 1;
        }
        *(uint32_t *)(val_1 + 0x1f0) = arg2;
        arg2 = (arg2 * 5 + -2000) * 2;
        (**(code **)(**(int **)(val_1 + 0xbc) + 0x3c))(*(int32_t *)(val_1 + 0xbc),arg2);
      }
      iStack_10 = 0;
      while ((iStack_10 < 0x10 &&
             (i_ptr_3 = (int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + iStack_10 * 0xc + 0xc0),
             *i_ptr_3 != 0))) {
        (**(code **)(*(int *)*i_ptr_3 + 0x3c))(*i_ptr_3,arg2);
        iStack_10 = iStack_10 + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_2 = 0;
    }
  }
  else {
    uval_2 = 5;
  }
  return uval_2;
}



void __cdecl thunk_FUN_10004534(int arg_1)

{
  if (DAT_1000a418 == 0) {
    DAT_1000a418 = arg_1;
  }
  else {
    *(int *)(DAT_1000a41c + 0x1f8) = arg_1;
    *(int *)(arg_1 + 500) = DAT_1000a41c;
  }
  DAT_1000a41c = arg_1;
  return;
}



int32_t __cdecl GetSndTime(int arg1,uint32_t *arg2)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t uStack_20;
  int iStack_1c;
  uint32_t uStack_18;
  double dStack_14;
  uint32_t uStack_c;
  uint8_t auStack_8 [4];
  
                    /* 0x105f  20  GetSndTime */
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      iStack_1c = *(int *)(&DAT_1000a648 + arg1 * 4);
      (**(code **)(**(int **)(iStack_1c + 0xbc) + 0x10))
                (*(int32_t *)(iStack_1c + 0xbc),&uStack_20,auStack_8);
      uStack_18 = *(uint32_t *)(iStack_1c + 0x1dc) % *(uint32_t *)(iStack_1c + 0xb0);
      if (uStack_18 < uStack_20) {
        *(int *)(iStack_1c + 0x1dc) = *(int *)(iStack_1c + 0x1dc) + (uStack_20 - uStack_18);
      }
      else {
        *(int *)(iStack_1c + 0x1dc) =
             *(int *)(iStack_1c + 0x1dc) + (*(int *)(iStack_1c + 0xb0) - uStack_18);
        *(int *)(iStack_1c + 0x1dc) = *(int *)(iStack_1c + 0x1dc) + uStack_20;
      }
      if ((*(uint32_t *)(iStack_1c + 8) >> 5 & 1) != 0) {
        uStack_c = *(uint32_t *)(iStack_1c + 0x1dc) / *(uint32_t *)(iStack_1c + 0x8c);
        while (*(uint32_t *)(iStack_1c + 0xa0) < uStack_c) {
          PostMessageA(DAT_1000ba88,0x3bd,0,uStack_c);
          *(int *)(iStack_1c + 0xa0) = *(int *)(iStack_1c + 0xa0) + 1;
        }
      }
      dStack_14 = (double)*(uint32_t *)(iStack_1c + 0x1dc);
      if (*(int *)(iStack_1c + 0x80) == 0x15888) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else if (*(int *)(iStack_1c + 0x80) == 0xac44) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else if (*(int *)(iStack_1c + 0x80) == 0x5622) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else {
        if (*(int *)(iStack_1c + 0x80) != 0x2b11) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return 8;
        }
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      *(uint32_t *)(&DAT_1000aa88 + DAT_1000a474 * 0x10) = DAT_1000a438;
      *(uint32_t *)(&DAT_1000aa8c + DAT_1000a474 * 0x10) = *arg2;
      DAT_1000a474 = DAT_1000a474 + 1;
      DAT_1000a474 = DAT_1000a474 & 0xff;
      if (*arg2 < DAT_1000a438) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        uval_1 = 5;
      }
      else {
        DAT_1000a438 = *arg2;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        uval_1 = 0;
      }
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t __cdecl thunk_FUN_1000630c(int32_t *ptr_1)

{
  int32_t uval_1;
  int iStack_34;
  uint32_t uStack_30;
  uint8_t auStack_2c [4];
  uint32_t uStack_28;
  int iStack_24;
  uint8_t auStack_20 [4];
  int iStack_1c;
  int iStack_18;
  int32_t uStack_14;
  int iStack_10;
  int32_t uStack_c;
  int iStack_8;
  
  iStack_24 = ptr_1[0x25] * ptr_1[0x23];
  iStack_8 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                       (ptr_1[0x2f],0,iStack_24,&iStack_34,&uStack_c,&iStack_18,&uStack_14,0);
  if (iStack_8 == 0) {
    if (iStack_18 == 0) {
      ptr_1[0x76] = 0;
      ptr_1[0x74] = 0;
      ptr_1[0x75] = 0;
      iStack_1c = iStack_34;
      iStack_10 = 0;
      uStack_28 = (uint32_t)ptr_1[0x23] / (uint32_t)ptr_1[0x24];
      iStack_8 = 0;
      for (uStack_30 = 0; uStack_30 < (uint32_t)ptr_1[0x25]; uStack_30 = uStack_30 + 1) {
        AVIStreamRead(*ptr_1,iStack_10,uStack_28,iStack_1c,ptr_1[0x23],auStack_2c,auStack_20);
        ptr_1[0x76] = ptr_1[0x76] + ptr_1[0x23];
        ptr_1[0x76] = (uint32_t)ptr_1[0x76] % (uint32_t)ptr_1[0x2c];
        ptr_1[0x74] = ptr_1[0x74] + ptr_1[0x23];
        ptr_1[0x75] = ptr_1[0x75] + ptr_1[0x23];
        iStack_1c = iStack_1c + ptr_1[0x23];
        iStack_10 = iStack_10 + uStack_28;
      }
      iStack_8 = (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))
                           (ptr_1[0x2f],iStack_34,uStack_c,iStack_18,uStack_14);
      if (iStack_8 == 0) {
        uval_1 = 0;
      }
      else {
        thunk_FUN_10005a46(ptr_1);
        thunk_FUN_10006622(ptr_1);
        uval_1 = 9;
      }
    }
    else {
      (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))(ptr_1[0x2f],iStack_34,uStack_c,iStack_18,uStack_14);
      thunk_FUN_1000681e();
      thunk_FUN_10006622(ptr_1);
      uval_1 = 9;
    }
  }
  else {
    thunk_FUN_1000681e();
    thunk_FUN_10006622(ptr_1);
    uval_1 = 9;
  }
  return uval_1;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl thunk_FUN_10006830(int32_t *ptr_1,int32_t arg_2)

{
  int iStack_1c;
  int32_t uStack_c;
  size_t sStack_8;
  
  uStack_c = 0;
  sStack_8 = ptr_1[0x74] - ptr_1[0x75];
  if (ptr_1[0x68] - ptr_1[0x67] != sStack_8) {
    _DAT_1000a520 = _DAT_1000a520 + 1;
  }
  iStack_1c = ptr_1[0x65] - sStack_8;
  if ((int)(ptr_1[0x73] - ptr_1[0x74]) < (int)(ptr_1[0x65] - sStack_8)) {
    iStack_1c = ptr_1[0x73] - ptr_1[0x74];
  }
  if (sStack_8 != 0) {
    memmove((void *)ptr_1[0x66],(void *)ptr_1[0x67],sStack_8);
  }
  ptr_1[0x67] = ptr_1[0x66] + sStack_8;
  AVIStreamRead(*ptr_1,arg_2,iStack_1c / (int)(uint32_t)*(uint16_t *)(ptr_1 + 0x21),ptr_1[0x67],iStack_1c,
                &uStack_c,0);
  ptr_1[0x68] = ptr_1[0x65] + ptr_1[0x66];
  ptr_1[0x67] = ptr_1[0x66];
  mmioSetInfo((HMMIO)ptr_1[0x72],(LPCMMIOINFO)(ptr_1 + 0x60),0);
  return;
}



int32_t thunk_FUN_100046fb(void)

{
  MMRESULT MVar1;
  int32_t uval_2;
  
  MVar1 = timeGetDevCaps((LPTIMECAPS)&DAT_1000ba98,8);
  if (MVar1 == 0) {
    timeBeginPeriod(DAT_1000a480);
    DAT_1000ba94 = timeSetEvent(DAT_1000a480,DAT_1000ba98,&LAB_1000110e,0x1000ba88,1);
    if (DAT_1000ba94 == 0) {
      timeEndPeriod(DAT_1000a480);
      uval_2 = 0xc;
    }
    else {
      DAT_1000a424 = 1;
      uval_2 = 0;
    }
  }
  else {
    uval_2 = 0xc;
  }
  return uval_2;
}



int32_t thunk_FUN_1000681e(void)

{
  return 0;
}



int32_t PlayMidiFile(void)

{
                    /* 0x1078  10  PlayMidiFile */
  return 0;
}



int __cdecl PlaySndMarker(int arg1,uint32_t arg2)

{
  int32_t *ptr_1;
  int val_1;
  int iStack_24;
  int32_t uStack_20;
  int32_t uStack_1c;
  uint32_t uStack_8;
  
                    /* 0x107d  19  PlaySndMarker */
  if ((arg1 < 0x100) && (-1 < arg1)) {
    if (((int)arg2 < 0x11) && (-1 < (int)arg2)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      val_1 = *(int *)(&DAT_1000a648 + arg1 * 4);
      if (val_1 == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        val_1 = 1;
      }
      else if ((*(int *)(val_1 + 0x30) == 0) || (*(uint32_t *)(val_1 + 0x30) < arg2)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        val_1 = 5;
      }
      else {
        ptr_1 = *(int32_t **)(val_1 + 0x34 + arg2 * 4);
        if (ptr_1 == (int32_t *)0x0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          val_1 = 1;
        }
        else if (((uint32_t)ptr_1[1] >> 5 & 1) == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          val_1 = 1;
        }
        else {
          if ((*(uint8_t *)(val_1 + 4) & 1) != 0) {
            thunk_FUN_10002900(arg1);
          }
          ptr_1[0x7c] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1f0);
          iStack_24 = ptr_1[0x7c];
          ptr_1[0x7b] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1ec);
          uStack_20 = ptr_1[0x7b];
          ptr_1[0x7a] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1e8);
          uStack_1c = ptr_1[0x7a];
          uStack_8 = ptr_1[2] & 1 | uStack_8 & 0xfffffffe;
          val_1 = thunk_FUN_1000192c(ptr_1,&iStack_24);
          if (val_1 == 0) {
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) =
                 *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) | 0x40;
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x18) = arg2 - 1;
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) =
                 *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) | 1;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        }
      }
    }
    else {
      val_1 = 5;
    }
  }
  else {
    val_1 = 5;
  }
  return val_1;
}



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



int32_t GetSndHWND(void)

{
                    /* 0x1087  25  GetSndHWND */
  return DAT_1000ba88;
}



int32_t __cdecl thunk_FUN_1000405a(int32_t *ptr_1)

{
  uint32_t uval_1;
  uint32_t uval_2;
  uint32_t uStack_48;
  int32_t uStack_44;
  int32_t uStack_40;
  int32_t uStack_3c;
  int32_t uStack_38;
  uint32_t uStack_34;
  uint32_t uStack_30;
  uint8_t auStack_2c [4];
  int32_t uStack_28;
  int32_t uStack_24;
  uint32_t uStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  uint32_t uStack_c;
  uint32_t uStack_8;
  
  uStack_28 = 0;
  uStack_48 = 0;
  uStack_40 = 0;
  uStack_38 = 0;
  uStack_24 = 0;
  uStack_44 = 0;
  iStack_10 = 0;
  uStack_8 = 0;
  uStack_c = 0;
  uStack_3c = 0;
  (**(code **)(*(int *)ptr_1[0x2f] + 0x10))(ptr_1[0x2f],&uStack_48,&uStack_28);
  uStack_34 = (uint32_t)ptr_1[0x77] % (uint32_t)ptr_1[0x2c];
  if (uStack_34 < uStack_48) {
    ptr_1[0x77] = ptr_1[0x77] + (uStack_48 - uStack_34);
  }
  else {
    ptr_1[0x77] = ptr_1[0x77] + (ptr_1[0x2c] - uStack_34);
    ptr_1[0x77] = ptr_1[0x77] + uStack_48;
  }
  uStack_30 = uStack_48 / (uint32_t)ptr_1[0x23];
  uStack_20 = (uint32_t)ptr_1[0x76] / (uint32_t)ptr_1[0x23];
  if (uStack_20 != uStack_30) {
    if (((((uint32_t)ptr_1[1] >> 4 & 1) == 0) || ((uint32_t)ptr_1[0x75] < (uint32_t)ptr_1[0x2c])) &&
       ((((uint32_t)ptr_1[1] >> 1 & 1) == 0 || (ptr_1[0x7c] != 0)))) {
      iStack_18 = ptr_1[0x23];
      if (((uint32_t)ptr_1[1] >> 4 & 1) == 0) {
        uval_1 = ptr_1[0x74];
        uval_2 = ptr_1[0x24];
        iStack_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                              (ptr_1[0x2f],ptr_1[0x76],iStack_18,&uStack_44,&uStack_8,&iStack_10,
                               &uStack_c,0);
        if (iStack_14 != 0) {
          return 10;
        }
        AVIStreamRead(*ptr_1,uval_1 / uval_2,uStack_8 / (uint32_t)ptr_1[0x24],uStack_44,uStack_8,
                      auStack_2c,&iStack_1c);
        if (iStack_10 != 0) {
          AVIStreamRead(*ptr_1,iStack_1c + uval_1 / uval_2,uStack_c / (uint32_t)ptr_1[0x24],iStack_10,
                        uStack_c,auStack_2c,&iStack_1c);
        }
        ptr_1[0x76] = ptr_1[0x76] + iStack_18;
        ptr_1[0x76] = (uint32_t)ptr_1[0x76] % (uint32_t)ptr_1[0x2c];
        ptr_1[0x74] = ptr_1[0x74] + iStack_18;
        ptr_1[0x75] = ptr_1[0x75] + iStack_18;
        if ((uint32_t)ptr_1[0x73] <= (uint32_t)ptr_1[0x74]) {
          ptr_1[1] = ptr_1[1] | 0x10;
          ptr_1[0x75] = 0;
        }
        (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))(ptr_1[0x2f],uStack_44,uStack_8,iStack_10,uStack_c)
        ;
        ptr_1[1] = ptr_1[1] & 0xffffff7f;
      }
      else {
        ptr_1[0x75] = ptr_1[0x75] + iStack_18;
      }
    }
    else {
      (**(code **)(*(int *)ptr_1[0x2f] + 0x48))(ptr_1[0x2f]);
      if ((0 < DAT_1000a428) && (DAT_1000a428 = DAT_1000a428 + -1, DAT_1000a428 == 0)) {
        thunk_FUN_10004788();
      }
      ptr_1[1] = ptr_1[1] & 0xfffffffe;
      ptr_1[1] = ptr_1[1] & 0xfffffffd;
      ptr_1[1] = ptr_1[1] | 4;
      ptr_1[1] = ptr_1[1] & 0xffffffdf;
      ptr_1[0x77] = 0;
    }
  }
  return 0;
}



int32_t __cdecl thunk_FUN_10006622(void *ptr_1)

{
  int32_t uval_1;
  
  if (ptr_1 == (void *)0x0) {
    uval_1 = 5;
  }
  else {
    (**(code **)(**(int **)((int)ptr_1 + 0xbc) + 8))(*(int32_t *)((int)ptr_1 + 0xbc));
    operator_delete(ptr_1);
    uval_1 = 0;
  }
  return uval_1;
}



int32_t __cdecl thunk_FUN_10005d4a(int arg1,int arg2)

{
  uint16_t uval_1;
  int val_2;
  int val_3;
  
  mmioGetInfo(*(HMMIO *)(arg1 + 0x1c8),(LPMMIOINFO)(arg1 + 0x180),0);
  uval_1 = *(uint16_t *)(arg1 + 0x84);
  val_2 = *(int *)(arg1 + 0x1e0);
  val_3 = thunk_FUN_10006e80(arg1 + 0x180);
  mmioSeek(*(HMMIO *)(arg1 + 0x1c8),((uint32_t)uval_1 * arg2 + val_2) - val_3,1);
  mmioGetInfo(*(HMMIO *)(arg1 + 0x1c8),(LPMMIOINFO)(arg1 + 0x180),0);
  mmioAdvance(*(HMMIO *)(arg1 + 0x1c8),(LPMMIOINFO)(arg1 + 0x180),0);
  return 0;
}



int32_t GetPitch(void)

{
                    /* 0x10a0  12  GetPitch */
  return 0;
}



void thunk_FUN_10004788(void)

{
  if (DAT_1000a424 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    timeKillEvent(DAT_1000ba94);
    DAT_1000ba94 = 0;
    timeEndPeriod(DAT_1000a480);
    DAT_1000a424 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return;
}



int __cdecl PlaySndFile(LPSTR arg_1,int arg_2,int *ptr_3)

{
  uint8_t auStack_1c [4];
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int32_t uStack_8;
  
                    /* 0x10aa  7  PlaySndFile */
  uStack_8 = 0;
  iStack_18 = 0;
  iStack_10 = 0;
  if ((arg_2 < 0x100) && (-1 < arg_2)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_2 * 4) == 0) {
      iStack_c = thunk_FUN_1000560f(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
      if (iStack_c == 0) {
        thunk_FUN_1000460c(*(int *)(&DAT_1000a648 + arg_2 * 4));
        thunk_FUN_10004534(*(int *)(&DAT_1000a648 + arg_2 * 4));
        if (((DAT_1000a420 == 1) && (DAT_1000a424 == 0)) &&
           (iStack_c = thunk_FUN_100046fb(), iStack_c != 0)) {
          UnloadSnd(arg_2);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        }
        else {
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x10) = arg_2;
          if (ptr_3 == (int *)0x0) {
            iStack_18 = 0;
            *(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = 400;
            iStack_10 = *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x7c);
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = iStack_10;
            iStack_14 = 0;
            *(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = 0;
          }
          else {
            iStack_18 = *ptr_3;
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = iStack_18;
            if (400 < iStack_18) {
              iStack_18 = 400;
            }
            iStack_18 = (iStack_18 * 5 + -2000) * 2;
            if (ptr_3[1] == 0) {
              iStack_10 = *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x7c);
            }
            else {
              iStack_10 = ptr_3[1];
            }
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = iStack_10;
            if (ptr_3[2] == 0) {
              iStack_14 = 0;
            }
            else {
              iStack_14 = ptr_3[2];
            }
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = iStack_14;
            iStack_14 = iStack_14 * 10;
            if ((*(uint8_t *)(ptr_3 + 7) & 1) != 0) {
              *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
                   *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 1;
            }
            if (((uint32_t)ptr_3[7] >> 3 & 1) != 0) {
              *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
                   *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 4;
            }
          }
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 2;
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x3c))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),iStack_18);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = iStack_18;
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x44))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),iStack_10);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = iStack_10;
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x40))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),iStack_14);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = iStack_14;
          thunk_FUN_10005f0c(*(int32_t **)(&DAT_1000a648 + arg_2 * 4),0);
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x30))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),0,0,1);
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x10))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),
                     *(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1d8,auStack_1c);
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) | 1;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          iStack_c = 0;
        }
      }
      else {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      }
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      iStack_c = 2;
    }
  }
  else {
    iStack_c = 5;
  }
  return iStack_c;
}



int32_t GetVol(void)

{
                    /* 0x10af  14  GetVol */
  return 0;
}



int __cdecl thunk_FUN_10006e80(int arg_1)

{
  return *(int *)(arg_1 + 0x2c) - (*(int *)(arg_1 + 0x20) - *(int *)(arg_1 + 0x1c));
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl thunk_FUN_10003a41(int arg_1)

{
  uint32_t uval_1;
  int iStack_38;
  int iStack_34;
  void *pvStack_30;
  uint32_t uStack_2c;
  uint32_t uStack_28;
  uint32_t uStack_24;
  int32_t uStack_20;
  int iStack_1c;
  uint32_t uStack_18;
  int iStack_14;
  void *pvStack_10;
  size_t sStack_c;
  size_t sStack_8;
  
  uStack_20 = 0;
  iStack_34 = 0;
  uStack_18 = 0;
  uStack_2c = 0;
  uStack_24 = 0;
  iStack_1c = 0;
  pvStack_30 = (void *)0x0;
  pvStack_10 = (void *)0x0;
  sStack_8 = 0;
  sStack_c = 0;
  uStack_28 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  (**(code **)(**(int **)(arg_1 + 0xbc) + 0x10))
            (*(int32_t *)(arg_1 + 0xbc),&iStack_34,&uStack_20);
  *(int *)(arg_1 + 0x1dc) =
       *(int *)(arg_1 + 0x1dc) + (iStack_34 - *(int *)(arg_1 + 0x1dc) & 0xffffU);
  if (*(uint32_t *)(arg_1 + 0x1cc) < *(uint32_t *)(arg_1 + 0x1dc)) {
    *(int *)(arg_1 + 0x1dc) = *(int *)(arg_1 + 0x1dc) - *(int *)(arg_1 + 0x1cc);
  }
  if ((((*(uint32_t *)(arg_1 + 4) >> 4 & 1) == 0) || (*(uint32_t *)(arg_1 + 0x1d4) < 0x10000)) &&
     (((*(uint32_t *)(arg_1 + 4) >> 1 & 1) == 0 || (*(int *)(arg_1 + 0x1f0) != 0)))) {
    uval_1 = iStack_34 - *(int *)(arg_1 + 0x1d8) & 0xffff;
    uStack_24 = *(int *)(arg_1 + 0x1cc) - *(int *)(arg_1 + 0x1d0);
    if ((*(uint32_t *)(arg_1 + 4) >> 4 & 1) == 0) {
      uStack_2c = *(int *)(arg_1 + 0x1d0) - *(int *)(arg_1 + 0x1d4);
      if (0x10000 < uStack_2c) {
        _DAT_1000a47c = _DAT_1000a47c + 1;
      }
    }
    else {
      uStack_2c = 0;
    }
    iStack_1c = uStack_24 + uStack_2c;
    uStack_18 = uval_1;
    if (iStack_1c == 0) {
      uStack_18 = 0;
      uStack_28 = uval_1;
    }
    if ((uStack_18 == 0) && (uStack_28 == 0)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
    else {
      if (uStack_2c < uStack_18) {
        uStack_18 = uStack_2c;
      }
      if (uStack_18 + uStack_28 != 0) {
        iStack_14 = (**(code **)(**(int **)(arg_1 + 0xbc) + 0x2c))
                              (*(int32_t *)(arg_1 + 0xbc),*(int32_t *)(arg_1 + 0x1d8),
                               uStack_18 + uStack_28,&pvStack_30,&sStack_8,&pvStack_10,&sStack_c,0);
        if (iStack_14 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return;
        }
        *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) | 0x80;
        if (uStack_28 == 0) {
          mmioGetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
          memmove(pvStack_30,*(void **)(arg_1 + 0x19c),sStack_8);
          *(int *)(arg_1 + 0x19c) = *(int *)(arg_1 + 0x19c) + sStack_8;
          if (pvStack_10 != (void *)0x0) {
            memmove(pvStack_10,*(void **)(arg_1 + 0x19c),sStack_c);
            *(int *)(arg_1 + 0x19c) = *(int *)(arg_1 + 0x19c) + sStack_c;
          }
          mmioSetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPCMMIOINFO)(arg_1 + 0x180),0);
          uStack_2c = uStack_2c - uStack_18;
          iStack_1c = iStack_1c - uStack_18;
          *(int *)(arg_1 + 0x1d4) = *(int *)(arg_1 + 0x1d4) + uStack_18;
        }
        else {
          if (*(short *)(arg_1 + 0x86) == 8) {
            iStack_38 = 0x80;
          }
          else {
            iStack_38 = 0;
          }
          memset(pvStack_30,iStack_38,sStack_8);
          if (pvStack_10 != (void *)0x0) {
            memset(pvStack_10,iStack_38,sStack_c);
          }
          *(int *)(arg_1 + 0x1d4) = *(int *)(arg_1 + 0x1d4) + uStack_28;
        }
        *(uint32_t *)(arg_1 + 0x1d8) = *(int *)(arg_1 + 0x1d8) + uStack_18 + uStack_28 & 0xffff;
        (**(code **)(**(int **)(arg_1 + 0xbc) + 0x4c))
                  (*(int32_t *)(arg_1 + 0xbc),pvStack_30,sStack_8,pvStack_10,sStack_c);
        *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xffffff7f;
      }
      if (((iStack_1c != 0) && (uStack_24 != 0)) &&
         ((uStack_2c == 0 || (uStack_2c < uStack_18 * 2)))) {
        mmioAdvance(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
        if (uStack_24 < *(int *)(arg_1 + 0x194) - uStack_2c) {
          *(int *)(arg_1 + 0x1d0) = *(int *)(arg_1 + 0x1d0) + uStack_24;
        }
        else {
          *(int *)(arg_1 + 0x1d0) = *(int *)(arg_1 + 0x1d0) + (*(int *)(arg_1 + 0x194) - uStack_2c);
        }
      }
      if (iStack_1c == 0) {
        if ((*(uint8_t *)(arg_1 + 8) & 1) == 0) {
          if ((*(uint32_t *)(arg_1 + 4) >> 4 & 1) == 0) {
            *(int32_t *)(arg_1 + 0x1e4) = *(int32_t *)(arg_1 + 0x1d8);
            *(int32_t *)(arg_1 + 0x1d4) = 0;
            *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) | 0x10;
          }
        }
        else {
          *(int32_t *)(arg_1 + 0x19c) = *(int32_t *)(arg_1 + 0x1a0);
          mmioSetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPCMMIOINFO)(arg_1 + 0x180),0);
          mmioSeek(*(HMMIO *)(arg_1 + 0x1c8),*(LONG *)(arg_1 + 0x1e0),0);
          mmioGetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
          mmioAdvance(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
          *(int *)(arg_1 + 0x1d0) = *(int *)(arg_1 + 0x19c) - *(int *)(arg_1 + 0x198);
          if (*(uint32_t *)(arg_1 + 0x1cc) < *(uint32_t *)(arg_1 + 0x1d0)) {
            *(int32_t *)(arg_1 + 0x1d0) = *(int32_t *)(arg_1 + 0x1cc);
          }
          *(int32_t *)(arg_1 + 0x1d4) = 0;
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
  }
  else {
    (**(code **)(**(int **)(arg_1 + 0xbc) + 0x48))(*(int32_t *)(arg_1 + 0xbc));
    if ((0 < DAT_1000a428) && (DAT_1000a428 = DAT_1000a428 + -1, DAT_1000a428 == 0)) {
      thunk_FUN_10004788();
    }
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xfffffffe;
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xfffffffd;
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) | 4;
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xffffffdf;
    if ((*(uint32_t *)(arg_1 + 8) >> 4 & 1) != 0) {
      *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) & 0xffffffbf;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) & 0xfffffffe;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return;
}



void * __cdecl thunk_FUN_10006540(int *ptr_1,int32_t arg_2,int32_t *ptr_3,int32_t arg_4)

{
  void *ptr_1_00;
  int val_1;
  
  ptr_1_00 = operator_new(0x204);
  memset(ptr_1_00,0,0x204);
  *(int32_t *)((int)ptr_1_00 + 0xa8) = 0x14;
  *(int32_t *)((int)ptr_1_00 + 0xac) = arg_4;
  *(int32_t *)((int)ptr_1_00 + 0xb0) = arg_2;
  *(int32_t **)((int)ptr_1_00 + 0xb8) = ptr_3;
  *(int32_t *)((int)ptr_1_00 + 0x78) = *ptr_3;
  *(int32_t *)((int)ptr_1_00 + 0x7c) = ptr_3[1];
  *(int32_t *)((int)ptr_1_00 + 0x80) = ptr_3[2];
  *(int32_t *)((int)ptr_1_00 + 0x84) = ptr_3[3];
  *(int16_t *)((int)ptr_1_00 + 0x88) = *(int16_t *)(ptr_3 + 4);
  val_1 = (**(code **)(*ptr_1 + 0xc))(ptr_1,(int)ptr_1_00 + 0xa8,(int)ptr_1_00 + 0xbc,0);
  if (val_1 != 0) {
    operator_delete(ptr_1_00);
    ptr_1_00 = (void *)0x0;
  }
  return ptr_1_00;
}



int __cdecl thunk_FUN_1000207f(int32_t *ptr_1,int arg_2)

{
  int val_1;
  int *ptr_2;
  int val_2;
  
  val_1 = ptr_1[0xd];
  ptr_2 = ptr_1 + arg_2 + 0xd;
  val_2 = thunk_FUN_1000560f((LPSTR)*ptr_1,ptr_2);
  if ((val_2 == 0) &&
     (val_2 = thunk_FUN_10005f0c((int32_t *)*ptr_2,*(int *)(val_1 + (arg_2 * 3 + -3) * 8 + 0x14))
     , val_2 == 0)) {
    *(uint32_t *)(*ptr_2 + 4) = *(uint32_t *)(*ptr_2 + 4) | 0x20;
    thunk_FUN_10004534(*ptr_2);
    *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 2;
    *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 0x10;
    *(uint32_t *)(*ptr_2 + 8) = ptr_1[2] & 1 | *(uint32_t *)(*ptr_2 + 8) & 0xfffffffe;
    *(int32_t *)(*ptr_2 + 0x10) = ptr_1[4];
  }
  return val_2;
}



int32_t __cdecl UnloadSnd(int arg_1)

{
  int32_t uval_1;
  uint32_t uStack_8;
  
                    /* 0x10c8  4  UnloadSnd */
  if ((arg_1 < 0x110) && (-1 < arg_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      thunk_FUN_10002900(arg_1);
      thunk_FUN_10004665(*(int *)(&DAT_1000a648 + arg_1 * 4));
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) != 0) {
        thunk_FUN_1000458d(*(int *)(&DAT_1000a648 + arg_1 * 4));
        if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 5 & 1) == 0) {
          thunk_FUN_10005a46(*(int32_t **)(&DAT_1000a648 + arg_1 * 4));
          for (uStack_8 = 0; uStack_8 < *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x30);
              uStack_8 = uStack_8 + 1) {
            if (*(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 + uStack_8 * 4) != 0) {
              thunk_FUN_10005a46(*(int32_t **)
                                  (*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 + uStack_8 * 4));
            }
          }
        }
      }
      thunk_FUN_10006622(*(void **)(&DAT_1000a648 + arg_1 * 4));
      *(int32_t *)(&DAT_1000a648 + arg_1 * 4) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t __cdecl IsSndLoaded(int arg1,int32_t *arg2)

{
  int iStack_8;
  
                    /* 0x10cd  26  IsSndLoaded */
  if (0 < arg1) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    for (iStack_8 = DAT_1000a410; iStack_8 != 0; iStack_8 = *(int *)(iStack_8 + 0x200)) {
      if (*(int *)(iStack_8 + 0x14) == arg1) {
        *arg2 = *(int32_t *)(iStack_8 + 0x10);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        return 1;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return 0;
}



int32_t __cdecl StopSnd(int arg_1)

{
  int32_t uval_1;
  int *i_ptr_2;
  int val_3;
  int iStack_10;
  
                    /* 0x10d2  8  StopSnd */
  if ((arg_1 < 0x110) && (-1 < arg_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) >> 6 & 1) == 0) {
        if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) == 0) {
          val_3 = (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc) + 0x48))
                            (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc));
          if (val_3 != 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            return 9;
          }
        }
        else {
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) | 2;
        }
      }
      else {
        val_3 = *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 +
                        *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x18) * 4);
        if (val_3 == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return 1;
        }
        *(uint32_t *)(val_3 + 4) = *(uint32_t *)(val_3 + 4) | 2;
      }
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) == 0) {
        iStack_10 = 0;
        while ((iStack_10 < 0x10 &&
               (i_ptr_2 = (int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + iStack_10 * 0xc + 0xc0),
               *i_ptr_2 != 0))) {
          val_3 = (**(code **)(*(int *)*i_ptr_2 + 0x48))(*i_ptr_2);
          if (val_3 != 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            return 9;
          }
          iStack_10 = iStack_10 + 1;
        }
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xfffffffe;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int __cdecl thunk_FUN_1000192c(int32_t *ptr_1,int *ptr_2)

{
  int val_1;
  int iStack_1c;
  int *piStack_18;
  uint32_t uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  uStack_14 = 0;
  iStack_c = 0;
  if (((uint32_t)ptr_1[2] >> 1 & 1) == 0) {
    if ((ptr_2 == (int *)0x0) || (((uint32_t)ptr_2[7] >> 1 & 1) == 0)) {
      val_1 = thunk_FUN_100043c4((int)ptr_1,(int *)&piStack_18);
      if (val_1 != 0) {
        return val_1;
      }
      iStack_8 = 0;
    }
    else {
      piStack_18 = (int *)ptr_1[0x2f];
    }
  }
  else {
    if ((*(uint8_t *)(ptr_1 + 1) & 1) != 0) {
      thunk_FUN_10002900(ptr_1[4]);
    }
    if (((DAT_1000a420 == 1) && (DAT_1000a424 == 0)) &&
       (iStack_8 = thunk_FUN_100046fb(), iStack_8 != 0)) {
      UnloadSnd(ptr_1[4]);
      return iStack_8;
    }
    if (DAT_1000a420 != 0) {
      DAT_1000a428 = DAT_1000a428 + 1;
    }
    uStack_14 = uStack_14 | 1;
    piStack_18 = (int *)ptr_1[0x2f];
    if ((((uint32_t)ptr_1[1] >> 5 & 1) == 0) && (iStack_8 = thunk_FUN_1000394f(ptr_1), iStack_8 != 0)) {
      UnloadSnd(ptr_1[4]);
      return iStack_8;
    }
  }
  if (ptr_2 == (int *)0x0) {
    iStack_1c = 0;
    ptr_1[0x7c] = 400;
    iStack_c = ptr_1[0x1f];
    ptr_1[0x7b] = iStack_c;
    iStack_10 = 0;
    ptr_1[0x7a] = 0;
  }
  else {
    iStack_1c = *ptr_2;
    if (400 < iStack_1c) {
      iStack_1c = 400;
    }
    ptr_1[0x7c] = iStack_1c;
    iStack_1c = (iStack_1c * 5 + -2000) * 2;
    if (ptr_2[1] == 0) {
      iStack_c = ptr_1[0x1f];
    }
    else {
      iStack_c = ptr_2[1];
    }
    ptr_1[0x7b] = iStack_c;
    if (ptr_2[2] == 0) {
      iStack_10 = 0;
    }
    else {
      iStack_10 = ptr_2[2];
    }
    ptr_1[0x7a] = iStack_10;
    iStack_10 = iStack_10 * 10;
    if ((*(uint8_t *)(ptr_2 + 7) & 1) != 0) {
      uStack_14 = uStack_14 | 1;
      ptr_1[2] = ptr_1[2] | 1;
    }
    if (((uint32_t)ptr_2[7] >> 3 & 1) != 0) {
      ptr_1[2] = ptr_1[2] | 4;
    }
  }
  (**(code **)(*piStack_18 + 0x3c))(piStack_18,iStack_1c);
  (**(code **)(*piStack_18 + 0x44))(piStack_18,iStack_c);
  (**(code **)(*piStack_18 + 0x40))(piStack_18,iStack_10);
  (**(code **)(*piStack_18 + 0x34))(piStack_18,0);
  val_1 = (**(code **)(*piStack_18 + 0x30))(piStack_18,0,0,uStack_14);
  if (val_1 == 0) {
    ptr_1[1] = ptr_1[1] | 1;
    ptr_1[1] = ptr_1[1] & 0xffffffdf;
    val_1 = 0;
  }
  else {
    val_1 = 9;
  }
  return val_1;
}



int32_t __cdecl SetPan(int arg1,int arg2)

{
  int32_t uval_1;
  int *i_ptr_2;
  int iStack_8;
  
                    /* 0x10dc  15  SetPan */
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc) + 0x40))
                (*(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc),arg2 * 10);
      iStack_8 = 0;
      while ((iStack_8 < 0x10 &&
             (i_ptr_2 = (int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + iStack_8 * 0xc + 0xc0),
             *i_ptr_2 != 0))) {
        (**(code **)(*(int *)*i_ptr_2 + 0x40))(*i_ptr_2,arg2 * 10);
        iStack_8 = iStack_8 + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t __cdecl thunk_FUN_100055b0(char *str_1,int *ptr_2)

{
  FILE *fp;
  int32_t uval_1;
  
  fp = fopen(str_1,&DAT_1000a524);
  if (fp == (FILE *)0x0) {
    uval_1 = 7;
  }
  else {
    uval_1 = thunk_FUN_10005abe(fp,ptr_2);
    fclose(fp);
  }
  return uval_1;
}



int32_t __cdecl SetPitch(int arg1,int32_t arg2)

{
  int32_t uval_1;
  int *i_ptr_2;
  int iStack_8;
  
                    /* 0x10e6  11  SetPitch */
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc) + 0x44))
                (*(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc),arg2);
      iStack_8 = 0;
      while ((iStack_8 < 0x10 &&
             (i_ptr_2 = (int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + iStack_8 * 0xc + 0xc0),
             *i_ptr_2 != 0))) {
        (**(code **)(*(int *)*i_ptr_2 + 0x44))(*i_ptr_2,arg2);
        iStack_8 = iStack_8 + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t __cdecl thunk_FUN_10005f0c(int32_t *ptr_1,int arg_2)

{
  int32_t uval_1;
  int iStack_4c;
  int iStack_44;
  HPSTR pcStack_40;
  int iStack_3c;
  int iStack_38;
  int32_t uStack_34;
  size_t sStack_30;
  HPSTR pcStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int32_t uStack_1c;
  int32_t uStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int32_t uStack_8;
  
  pcStack_40 = (HPSTR)0x0;
  uStack_1c = 0;
  pcStack_2c = (HPSTR)0x0;
  uStack_8 = 0;
  uStack_18 = 0;
  uStack_34 = 0;
  iStack_38 = 0;
  if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
    thunk_FUN_10005d4a((int)ptr_1,arg_2);
  }
  iStack_3c = (uint32_t)*(uint16_t *)(ptr_1 + 0x21) * arg_2;
  iStack_28 = ptr_1[0x73];
  iStack_4c = iStack_28 - iStack_3c;
  sStack_30 = 0x10000;
  if ((iStack_3c < 0) || (iStack_28 < iStack_3c)) {
    uval_1 = 5;
  }
  else {
    iStack_20 = iStack_3c;
    iStack_c = iStack_3c;
    iStack_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                          (ptr_1[0x2f],0,0x10000,&pcStack_40,&uStack_8,&uStack_1c,&uStack_18,0);
    if (iStack_14 == 0) {
      pcStack_2c = pcStack_40;
      iStack_14 = 0;
      while (iStack_38 == 0) {
        if (iStack_4c < (int)sStack_30) {
          if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
            iStack_10 = mmioRead((HMMIO)ptr_1[0x72],pcStack_2c,iStack_4c);
          }
          else {
            AVIStreamRead(*ptr_1,arg_2,
                          (int)(0x10000 / (ulonglong)(longlong)(int)(uint32_t)*(uint16_t *)(ptr_1 + 0x21))
                          ,pcStack_2c,iStack_4c,&iStack_10,0);
          }
          pcStack_2c = pcStack_2c + iStack_10;
          sStack_30 = sStack_30 - iStack_10;
          iStack_4c = 0;
          iStack_20 = ptr_1[0x73];
          if ((*(uint8_t *)(ptr_1 + 2) & 1) == 0) {
            memset(pcStack_2c,0,sStack_30);
            iStack_38 = 1;
          }
          else {
            if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
              thunk_FUN_10005d4a((int)ptr_1,0);
            }
            iStack_20 = 0;
            iStack_4c = ptr_1[0x73];
            iStack_c = 0;
          }
        }
        else {
          if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
            iStack_10 = mmioRead((HMMIO)ptr_1[0x72],pcStack_2c,sStack_30);
          }
          else {
            AVIStreamRead(*ptr_1,arg_2,
                          (int)(0x10000 / (ulonglong)(longlong)(int)(uint32_t)*(uint16_t *)(ptr_1 + 0x21))
                          ,pcStack_2c,0x10000,&iStack_10,&iStack_44);
          }
          sStack_30 = sStack_30 - iStack_10;
          iStack_c = iStack_c + iStack_10;
          iStack_4c = iStack_4c - iStack_10;
          iStack_20 = iStack_20 + iStack_10;
          arg_2 = arg_2 + iStack_44;
          iStack_38 = 1;
        }
      }
      mmioGetInfo((HMMIO)ptr_1[0x72],(LPMMIOINFO)(ptr_1 + 0x60),0);
      if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
        mmioAdvance((HMMIO)ptr_1[0x72],(LPMMIOINFO)(ptr_1 + 0x60),0);
      }
      else {
        thunk_FUN_10006830(ptr_1,arg_2);
      }
      iStack_24 = iStack_4c;
      if (0xffff < iStack_4c) {
        iStack_24 = 0x10000;
      }
      ptr_1[0x74] = ptr_1[0x73] - (iStack_4c - iStack_24);
      ptr_1[0x75] = ptr_1[0x73] - iStack_4c;
      ptr_1[0x76] = 0;
      iStack_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))
                            (ptr_1[0x2f],pcStack_40,uStack_8,uStack_1c,uStack_18);
      if (iStack_14 == 0) {
        uval_1 = 0;
      }
      else {
        thunk_FUN_10005a46(ptr_1);
        thunk_FUN_10006622(ptr_1);
        uval_1 = 9;
      }
    }
    else {
      if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
        thunk_FUN_10005a46(ptr_1);
      }
      else {
        thunk_FUN_1000681e();
      }
      thunk_FUN_10006622(ptr_1);
      uval_1 = 9;
    }
  }
  return uval_1;
}



int32_t UpdateSnd(void)

{
  int32_t *u_ptr_1;
  int32_t uval_2;
  int32_t *puStack_c;
  
                    /* 0x10f0  17  UpdateSnd */
  if (DAT_1000a46c == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    puStack_c = DAT_1000a418;
    while (puStack_c != (int32_t *)0x0) {
      if ((*(uint8_t *)(puStack_c + 1) & 1) != 0) {
        if (((uint32_t)puStack_c[1] >> 1 & 1) != 0) {
          if ((uint32_t)puStack_c[0x7c] < 6) {
            puStack_c[0x7c] = 0;
          }
          else {
            puStack_c[0x7c] = puStack_c[0x7c] + -5;
          }
          SetVol(puStack_c[4],puStack_c[0x7c]);
        }
        if (((uint32_t)puStack_c[2] >> 5 & 1) == 0) {
          thunk_FUN_10003a41((int)puStack_c);
        }
        else if (((uint32_t)puStack_c[2] >> 6 & 1) == 0) {
          thunk_FUN_1000405a(puStack_c);
        }
      }
      if ((((uint32_t)puStack_c[1] >> 2 & 1) == 0) || (((uint32_t)puStack_c[2] >> 2 & 1) == 0)) {
        puStack_c = (int32_t *)puStack_c[0x7e];
      }
      else {
        u_ptr_1 = (int32_t *)puStack_c[0x80];
        UnloadSnd(puStack_c[4]);
        puStack_c = u_ptr_1;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    uval_2 = 0;
  }
  else {
    uval_2 = 0xd;
  }
  return uval_2;
}



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



int32_t __cdecl thunk_FUN_100043c4(int arg1,int *arg2)

{
  int val_1;
  int32_t uval_2;
  uint8_t abStack_1c [4];
  int32_t uStack_18;
  int32_t uStack_14;
  int *piStack_10;
  int iStack_c;
  int *piStack_8;
  
  piStack_10 = *(int **)(arg1 + 0xbc);
  piStack_8 = piStack_10;
  val_1 = (**(code **)(*piStack_10 + 0x24))(piStack_10,abStack_1c);
  if (val_1 == 0) {
    if ((abStack_1c[0] & 2) == 0) {
      if ((abStack_1c[0] & 1) == 0) {
        *arg2 = (int)piStack_8;
        uval_2 = 0;
      }
      else {
        for (iStack_c = 0; uStack_14 = 0, iStack_c < 0x10; iStack_c = iStack_c + 1) {
          piStack_10 = *(int **)(arg1 + 0xc0 + iStack_c * 0xc);
          if (piStack_10 == (int *)0x0) {
            val_1 = (**(code **)(*DAT_1000ba90 + 0x14))(DAT_1000ba90,piStack_8,&uStack_18);
            if (val_1 != 0) {
              return 9;
            }
            *(int32_t *)(arg1 + 0xc0 + iStack_c * 0xc) = uStack_18;
            *arg2 = *(int *)(arg1 + 0xc0 + iStack_c * 0xc);
            return 0;
          }
          val_1 = (**(code **)(*piStack_10 + 0x24))(piStack_10,abStack_1c);
          if (val_1 != 0) {
            return 9;
          }
          if ((abStack_1c[0] & 1) == 0) {
            *arg2 = (int)piStack_10;
            return 0;
          }
        }
        uval_2 = 9;
      }
    }
    else {
      uval_2 = 9;
    }
  }
  else {
    uval_2 = 9;
  }
  return uval_2;
}



int32_t __cdecl thunk_FUN_10005dff(FILE *x,int y,long width,uint32_t height)

{
  int32_t uval_1;
  int iStack_1c;
  uint32_t uStack_18;
  uint32_t uStack_14;
  int aiStack_10 [3];
  
  fseek(x,width,0);
  fread(aiStack_10,1,0xc,x);
  if (aiStack_10[0] == y) {
    fseek(x,width,0);
    uval_1 = 1;
  }
  else {
    while( true ) {
      uStack_14 = ftell(x);
      fread(&iStack_1c,1,8,x);
      if (height <= uStack_14) break;
      if (iStack_1c == y) {
        fseek(x,uStack_14,0);
        return 1;
      }
      uStack_14 = ftell(x);
      if ((uStack_18 & 1) != 0) {
        uStack_18 = uStack_18 + 1;
      }
      fseek(x,uStack_18,1);
    }
    fseek(x,width,0);
    uval_1 = 0;
  }
  return uval_1;
}



void ReleaseSnd(void)

{
                    /* 0x1104  2  ReleaseSnd */
  if (DAT_1000a434 != 0) {
    UnloadAllSnds();
    if (DAT_1000a424 != 0) {
      thunk_FUN_10004788();
    }
    (**(code **)(*DAT_1000ba90 + 8))(DAT_1000ba90);
    DAT_1000ba90 = (int *)0x0;
    DAT_1000ba88 = 0;
    DAT_1000a434 = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl LoadSnd(LPSTR arg_1,int arg_2,int arg_3)

{
  int val_1;
  
                    /* 0x1109  3  LoadSnd */
  if (((arg_3 == 0) || ((*(uint32_t *)(arg_3 + 0x1c) >> 4 & 1) == 0)) || (arg_2 == 0)) {
    if ((0x100 < arg_2) || (arg_2 < 0)) {
      return 5;
    }
    if (*(int *)(&DAT_1000a648 + arg_2 * 4) != 0) {
      return 0;
    }
  }
  else {
    if ((0x10f < arg_2) || (arg_2 < 0x100)) {
      return 5;
    }
    if (*(int *)(&DAT_1000a648 + arg_2 * 4) != 0) {
      return 0;
    }
  }
  if ((arg_3 == 0) || ((*(uint32_t *)(arg_3 + 0x1c) >> 2 & 1) == 0)) {
    val_1 = thunk_FUN_100055b0(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
    if (val_1 != 0) {
      *(int32_t *)(&DAT_1000a648 + arg_2 * 4) = 0;
      return val_1;
    }
  }
  else {
    if ((*(uint32_t *)(arg_3 + 0x1c) >> 4 & 1) == 0) {
      val_1 = thunk_FUN_1000560f(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
      if (val_1 != 0) {
        *(int32_t *)(&DAT_1000a648 + arg_2 * 4) = 0;
        return val_1;
      }
      thunk_FUN_10005f0c(*(int32_t **)(&DAT_1000a648 + arg_2 * 4),0);
    }
    else {
      val_1 = thunk_FUN_1000667b(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
      if (val_1 != 0) {
        *(int32_t *)(&DAT_1000a648 + arg_2 * 4) = 0;
        return val_1;
      }
      if ((*(uint32_t *)(arg_3 + 0x1c) >> 5 & 1) == 0) {
        thunk_FUN_1000630c(*(int32_t **)(&DAT_1000a648 + arg_2 * 4));
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) & 0xffffffbf;
      }
      else {
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 0x40;
      }
      _DAT_1000a430 = _DAT_1000a430 + 1;
    }
    *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) =
         *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) | 0x20;
    thunk_FUN_10004534(*(int *)(&DAT_1000a648 + arg_2 * 4));
    *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
         *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 2;
  }
  thunk_FUN_1000460c(*(int *)(&DAT_1000a648 + arg_2 * 4));
  *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x10) = arg_2;
  if ((arg_3 != 0) && (*(int *)(arg_3 + 0x18) != 0)) {
    *(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x14) = *(int32_t *)(arg_3 + 0x18);
  }
  return 0;
}



void __cdecl thunk_FUN_10004665(int arg_1)

{
  int val_1;
  int val_2;
  int val_3;
  
  val_1 = *(int *)(arg_1 + 0x1fc);
  val_2 = *(int *)(arg_1 + 0x200);
  val_3 = val_2;
  if (val_1 != 0) {
    *(int *)(val_1 + 0x200) = val_2;
    val_3 = DAT_1000a410;
  }
  DAT_1000a410 = val_3;
  if (val_2 != 0) {
    *(int *)(val_2 + 0x1fc) = val_1;
    val_1 = DAT_1000a414;
  }
  DAT_1000a414 = val_1;
  return;
}



int32_t GetPan(void)

{
                    /* 0x1118  16  GetPan */
  return 0;
}



int32_t __cdecl Sound_DirectSoundInit(int arg_1,int32_t arg_2,uint8_t arg_3)

{
  int32_t uval_1;
  int val_2;
  uint8_t local_8 [4];
  
  if (((arg_3 & 2) == 0) || (DAT_1000a434 != 0)) {
    if (((arg_3 & 2) == 0) || (DAT_1000a434 == 0)) {
      if ((DAT_1000a434 == 0) && (arg_1 != 0)) {
        val_2 = DirectSoundCreate(0,&DAT_1000ba90,0);
        if (val_2 != 0) {
          return 4;
        }
        val_2 = (**(code **)(*DAT_1000ba90 + 0x18))(DAT_1000ba90,arg_1,3);
        if (val_2 != 0) {
          ReleaseSnd();
          return 4;
        }
        val_2 = (**(code **)(*DAT_1000ba90 + 0xc))(DAT_1000ba90,&DAT_1000a440,&DAT_1000a640,0);
        if (val_2 != 0) {
          ReleaseSnd();
          return 4;
        }
        val_2 = (**(code **)(*DAT_1000a640 + 0x38))(DAT_1000a640,&DAT_1000a458);
        if (val_2 != 0) {
          (**(code **)(*DAT_1000a640 + 0x14))(DAT_1000a640,&DAT_1000a458,0x12,local_8);
        }
        DAT_1000ba88 = arg_1;
        DAT_1000a434 = DAT_1000a434 + 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      }
      if ((arg_3 & 1) != 0) {
        if (DAT_1000a424 != 0) {
          thunk_FUN_10004788();
        }
        DAT_1000a420 = 0;
      }
      uval_1 = 0;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 4;
  }
  return uval_1;
}



void Sound_DirectSoundShutdown(void)

{
  if (DAT_1000a434 != 0) {
    UnloadAllSnds();
    if (DAT_1000a424 != 0) {
      thunk_FUN_10004788();
    }
    (**(code **)(*DAT_1000ba90 + 8))(DAT_1000ba90);
    DAT_1000ba90 = (int *)0x0;
    DAT_1000ba88 = 0;
    DAT_1000a434 = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return;
}



int32_t FUN_10001428(void)

{
  return DAT_1000ba88;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_1000143d(LPSTR arg_1,int arg_2,int arg_3)

{
  int val_1;
  
  if (((arg_3 == 0) || ((*(uint32_t *)(arg_3 + 0x1c) >> 4 & 1) == 0)) || (arg_2 == 0)) {
    if ((0x100 < arg_2) || (arg_2 < 0)) {
      return 5;
    }
    if (*(int *)(&DAT_1000a648 + arg_2 * 4) != 0) {
      return 0;
    }
  }
  else {
    if ((0x10f < arg_2) || (arg_2 < 0x100)) {
      return 5;
    }
    if (*(int *)(&DAT_1000a648 + arg_2 * 4) != 0) {
      return 0;
    }
  }
  if ((arg_3 == 0) || ((*(uint32_t *)(arg_3 + 0x1c) >> 2 & 1) == 0)) {
    val_1 = thunk_FUN_100055b0(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
    if (val_1 != 0) {
      *(int32_t *)(&DAT_1000a648 + arg_2 * 4) = 0;
      return val_1;
    }
  }
  else {
    if ((*(uint32_t *)(arg_3 + 0x1c) >> 4 & 1) == 0) {
      val_1 = thunk_FUN_1000560f(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
      if (val_1 != 0) {
        *(int32_t *)(&DAT_1000a648 + arg_2 * 4) = 0;
        return val_1;
      }
      thunk_FUN_10005f0c(*(int32_t **)(&DAT_1000a648 + arg_2 * 4),0);
    }
    else {
      val_1 = thunk_FUN_1000667b(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
      if (val_1 != 0) {
        *(int32_t *)(&DAT_1000a648 + arg_2 * 4) = 0;
        return val_1;
      }
      if ((*(uint32_t *)(arg_3 + 0x1c) >> 5 & 1) == 0) {
        thunk_FUN_1000630c(*(int32_t **)(&DAT_1000a648 + arg_2 * 4));
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) & 0xffffffbf;
      }
      else {
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 0x40;
      }
      _DAT_1000a430 = _DAT_1000a430 + 1;
    }
    *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) =
         *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) | 0x20;
    thunk_FUN_10004534(*(int *)(&DAT_1000a648 + arg_2 * 4));
    *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
         *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 2;
  }
  thunk_FUN_1000460c(*(int *)(&DAT_1000a648 + arg_2 * 4));
  *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x10) = arg_2;
  if ((arg_3 != 0) && (*(int *)(arg_3 + 0x18) != 0)) {
    *(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x14) = *(int32_t *)(arg_3 + 0x18);
  }
  return 0;
}



int32_t __cdecl Sound_LockAudioBuffer(int arg_1)

{
  int32_t uval_1;
  uint32_t local_8;
  
  if ((arg_1 < 0x110) && (-1 < arg_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      thunk_FUN_10002900(arg_1);
      thunk_FUN_10004665(*(int *)(&DAT_1000a648 + arg_1 * 4));
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) != 0) {
        thunk_FUN_1000458d(*(int *)(&DAT_1000a648 + arg_1 * 4));
        if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 5 & 1) == 0) {
          thunk_FUN_10005a46(*(int32_t **)(&DAT_1000a648 + arg_1 * 4));
          for (local_8 = 0; local_8 < *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x30);
              local_8 = local_8 + 1) {
            if (*(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 + local_8 * 4) != 0) {
              thunk_FUN_10005a46(*(int32_t **)
                                  (*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 + local_8 * 4));
            }
          }
        }
      }
      thunk_FUN_10006622(*(void **)(&DAT_1000a648 + arg_1 * 4));
      *(int32_t *)(&DAT_1000a648 + arg_1 * 4) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t Sound_UnlockAudioBuffer(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  while (DAT_1000a410 != 0) {
    UnloadSnd(*(int *)(DAT_1000a410 + 0x10));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  return 0;
}



int32_t __cdecl Sound_SetChannelVolume(int arg1,int *arg2)

{
  int32_t uval_1;
  
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      thunk_FUN_1000192c(*(int32_t **)(&DAT_1000a648 + arg1 * 4),arg2);
      *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xc) =
           *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xc) + 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int __cdecl Sound_UnloadSample(int32_t *ptr_1,int *ptr_2)

{
  int val_1;
  int local_1c;
  int *local_18;
  uint32_t local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 0;
  local_c = 0;
  if (((uint32_t)ptr_1[2] >> 1 & 1) == 0) {
    if ((ptr_2 == (int *)0x0) || (((uint32_t)ptr_2[7] >> 1 & 1) == 0)) {
      val_1 = thunk_FUN_100043c4((int)ptr_1,(int *)&local_18);
      if (val_1 != 0) {
        return val_1;
      }
      local_8 = 0;
    }
    else {
      local_18 = (int *)ptr_1[0x2f];
    }
  }
  else {
    if ((*(uint8_t *)(ptr_1 + 1) & 1) != 0) {
      thunk_FUN_10002900(ptr_1[4]);
    }
    if (((DAT_1000a420 == 1) && (DAT_1000a424 == 0)) &&
       (local_8 = thunk_FUN_100046fb(), local_8 != 0)) {
      UnloadSnd(ptr_1[4]);
      return local_8;
    }
    if (DAT_1000a420 != 0) {
      DAT_1000a428 = DAT_1000a428 + 1;
    }
    local_14 = local_14 | 1;
    local_18 = (int *)ptr_1[0x2f];
    if ((((uint32_t)ptr_1[1] >> 5 & 1) == 0) && (local_8 = thunk_FUN_1000394f(ptr_1), local_8 != 0)) {
      UnloadSnd(ptr_1[4]);
      return local_8;
    }
  }
  if (ptr_2 == (int *)0x0) {
    local_1c = 0;
    ptr_1[0x7c] = 400;
    local_c = ptr_1[0x1f];
    ptr_1[0x7b] = local_c;
    local_10 = 0;
    ptr_1[0x7a] = 0;
  }
  else {
    local_1c = *ptr_2;
    if (400 < local_1c) {
      local_1c = 400;
    }
    ptr_1[0x7c] = local_1c;
    local_1c = (local_1c * 5 + -2000) * 2;
    if (ptr_2[1] == 0) {
      local_c = ptr_1[0x1f];
    }
    else {
      local_c = ptr_2[1];
    }
    ptr_1[0x7b] = local_c;
    if (ptr_2[2] == 0) {
      local_10 = 0;
    }
    else {
      local_10 = ptr_2[2];
    }
    ptr_1[0x7a] = local_10;
    local_10 = local_10 * 10;
    if ((*(uint8_t *)(ptr_2 + 7) & 1) != 0) {
      local_14 = local_14 | 1;
      ptr_1[2] = ptr_1[2] | 1;
    }
    if (((uint32_t)ptr_2[7] >> 3 & 1) != 0) {
      ptr_1[2] = ptr_1[2] | 4;
    }
  }
  (**(code **)(*local_18 + 0x3c))(local_18,local_1c);
  (**(code **)(*local_18 + 0x44))(local_18,local_c);
  (**(code **)(*local_18 + 0x40))(local_18,local_10);
  (**(code **)(*local_18 + 0x34))(local_18,0);
  val_1 = (**(code **)(*local_18 + 0x30))(local_18,0,0,local_14);
  if (val_1 == 0) {
    ptr_1[1] = ptr_1[1] | 1;
    ptr_1[1] = ptr_1[1] & 0xffffffdf;
    val_1 = 0;
  }
  else {
    val_1 = 9;
  }
  return val_1;
}



int __cdecl Sound_SetChannelPanning(LPSTR arg_1,int arg_2,int *ptr_3)

{
  uint8_t local_1c [4];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int32_t local_8;
  
  local_8 = 0;
  local_18 = 0;
  local_10 = 0;
  if ((arg_2 < 0x100) && (-1 < arg_2)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_2 * 4) == 0) {
      local_c = thunk_FUN_1000560f(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
      if (local_c == 0) {
        thunk_FUN_1000460c(*(int *)(&DAT_1000a648 + arg_2 * 4));
        thunk_FUN_10004534(*(int *)(&DAT_1000a648 + arg_2 * 4));
        if (((DAT_1000a420 == 1) && (DAT_1000a424 == 0)) &&
           (local_c = thunk_FUN_100046fb(), local_c != 0)) {
          UnloadSnd(arg_2);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        }
        else {
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x10) = arg_2;
          if (ptr_3 == (int *)0x0) {
            local_18 = 0;
            *(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = 400;
            local_10 = *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x7c);
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = local_10;
            local_14 = 0;
            *(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = 0;
          }
          else {
            local_18 = *ptr_3;
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = local_18;
            if (400 < local_18) {
              local_18 = 400;
            }
            local_18 = (local_18 * 5 + -2000) * 2;
            if (ptr_3[1] == 0) {
              local_10 = *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x7c);
            }
            else {
              local_10 = ptr_3[1];
            }
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = local_10;
            if (ptr_3[2] == 0) {
              local_14 = 0;
            }
            else {
              local_14 = ptr_3[2];
            }
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = local_14;
            local_14 = local_14 * 10;
            if ((*(uint8_t *)(ptr_3 + 7) & 1) != 0) {
              *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
                   *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 1;
            }
            if (((uint32_t)ptr_3[7] >> 3 & 1) != 0) {
              *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
                   *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 4;
            }
          }
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 2;
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x3c))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),local_18);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = local_18;
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x44))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),local_10);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = local_10;
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x40))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),local_14);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = local_14;
          thunk_FUN_10005f0c(*(int32_t **)(&DAT_1000a648 + arg_2 * 4),0);
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x30))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),0,0,1);
          (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x10))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),
                     *(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1d8,local_1c);
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) | 1;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          local_c = 0;
        }
      }
      else {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      }
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      local_c = 2;
    }
  }
  else {
    local_c = 5;
  }
  return local_c;
}



int __cdecl FUN_1000207f(int32_t *ptr_1,int arg_2)

{
  int val_1;
  int *ptr_2;
  int val_2;
  
  val_1 = ptr_1[0xd];
  ptr_2 = ptr_1 + arg_2 + 0xd;
  val_2 = thunk_FUN_1000560f((LPSTR)*ptr_1,ptr_2);
  if ((val_2 == 0) &&
     (val_2 = thunk_FUN_10005f0c((int32_t *)*ptr_2,*(int *)(val_1 + (arg_2 * 3 + -3) * 8 + 0x14))
     , val_2 == 0)) {
    *(uint32_t *)(*ptr_2 + 4) = *(uint32_t *)(*ptr_2 + 4) | 0x20;
    thunk_FUN_10004534(*ptr_2);
    *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 2;
    *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 0x10;
    *(uint32_t *)(*ptr_2 + 8) = ptr_1[2] & 1 | *(uint32_t *)(*ptr_2 + 8) & 0xfffffffe;
    *(int32_t *)(*ptr_2 + 0x10) = ptr_1[4];
  }
  return val_2;
}



int __cdecl FUN_1000219c(int arg1,int arg2)

{
  int32_t *ptr_1;
  int val_1;
  
  if (((*(uint32_t *)(arg1 + 4) >> 6 & 1) == 0) || (*(int *)(arg1 + 0x18) != arg2 + -1)) {
    ptr_1 = *(int32_t **)(arg1 + 0x34 + arg2 * 4);
    val_1 = thunk_FUN_10005f0c(ptr_1,*(int *)(*(int *)(arg1 + 0x34) + (arg2 * 3 + -3) * 8 + 0x14));
    if (val_1 == 0) {
      ptr_1[1] = ptr_1[1] | 0x20;
      ptr_1[1] = ptr_1[1] & 0xfffffffb;
      ptr_1[1] = ptr_1[1] & 0xffffffef;
      ptr_1[0x76] = 0;
      ptr_1[2] = *(uint32_t *)(arg1 + 8) & 1 | ptr_1[2] & 0xfffffffe;
      ptr_1[0x7c] = *(int32_t *)(arg1 + 0x1f0);
      ptr_1[0x7b] = *(int32_t *)(arg1 + 0x1ec);
      ptr_1[0x7a] = *(int32_t *)(arg1 + 0x1e8);
      val_1 = 0;
    }
  }
  else {
    val_1 = 0xd;
  }
  return val_1;
}



void __cdecl FUN_100022b9(int *ptr_1,int *ptr_2)

{
  int arg_1;
  int32_t local_c;
  
  arg_1 = *ptr_1;
  *ptr_1 = *ptr_2;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(arg_1 + 0x38 + local_c * 4) == *ptr_1) {
      *(int *)(*ptr_1 + 0x38 + local_c * 4) = arg_1;
    }
    else {
      *(int32_t *)(*ptr_1 + 0x38 + local_c * 4) = *(int32_t *)(arg_1 + 0x38 + local_c * 4);
    }
    *(int32_t *)(arg_1 + 0x38 + local_c * 4) = 0;
  }
  *(int32_t *)(*ptr_1 + 0x10) = *(int32_t *)(arg_1 + 0x10);
  *(uint32_t *)(arg_1 + 8) = *(uint32_t *)(arg_1 + 8) | 0x10;
  *(uint32_t *)(*ptr_1 + 8) = *(uint32_t *)(*ptr_1 + 8) & 0xffffffef;
  thunk_FUN_10004665(arg_1);
  thunk_FUN_1000460c(*ptr_1);
  return;
}



int __cdecl Sound_PlayWaveSample(int arg1,uint32_t arg2)

{
  int32_t *ptr_1;
  int local_8;
  
  if ((arg1 < 0x100) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    ptr_1 = *(int32_t **)(&DAT_1000a648 + arg1 * 4);
    if (ptr_1 == (int32_t *)0x0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      local_8 = 1;
    }
    else if ((ptr_1[0xc] == 0) || ((uint32_t)ptr_1[0xc] < arg2)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      local_8 = 5;
    }
    else {
      if (ptr_1[arg2 + 0xd] == 0) {
        local_8 = thunk_FUN_1000207f(ptr_1,arg2);
      }
      else {
        local_8 = thunk_FUN_1000219c((int)ptr_1,arg2);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
  }
  else {
    local_8 = 5;
  }
  return local_8;
}



int __cdecl Sound_StopWaveSample(int arg1,uint32_t arg2)

{
  int32_t *ptr_1;
  int val_1;
  int local_24;
  int32_t local_20;
  int32_t local_1c;
  uint32_t local_8;
  
  if ((arg1 < 0x100) && (-1 < arg1)) {
    if (((int)arg2 < 0x11) && (-1 < (int)arg2)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      val_1 = *(int *)(&DAT_1000a648 + arg1 * 4);
      if (val_1 == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        val_1 = 1;
      }
      else if ((*(int *)(val_1 + 0x30) == 0) || (*(uint32_t *)(val_1 + 0x30) < arg2)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        val_1 = 5;
      }
      else {
        ptr_1 = *(int32_t **)(val_1 + 0x34 + arg2 * 4);
        if (ptr_1 == (int32_t *)0x0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          val_1 = 1;
        }
        else if (((uint32_t)ptr_1[1] >> 5 & 1) == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          val_1 = 1;
        }
        else {
          if ((*(uint8_t *)(val_1 + 4) & 1) != 0) {
            thunk_FUN_10002900(arg1);
          }
          ptr_1[0x7c] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1f0);
          local_24 = ptr_1[0x7c];
          ptr_1[0x7b] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1ec);
          local_20 = ptr_1[0x7b];
          ptr_1[0x7a] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1e8);
          local_1c = ptr_1[0x7a];
          local_8 = ptr_1[2] & 1 | local_8 & 0xfffffffe;
          val_1 = thunk_FUN_1000192c(ptr_1,&local_24);
          if (val_1 == 0) {
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) =
                 *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) | 0x40;
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x18) = arg2 - 1;
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) =
                 *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) | 1;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        }
      }
    }
    else {
      val_1 = 5;
    }
  }
  else {
    val_1 = 5;
  }
  return val_1;
}



int32_t __cdecl Sound_GetChannelStatus(int arg_1)

{
  int32_t uval_1;
  int *i_ptr_2;
  int val_3;
  int local_10;
  
  if ((arg_1 < 0x110) && (-1 < arg_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) >> 6 & 1) == 0) {
        if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) == 0) {
          val_3 = (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc) + 0x48))
                            (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc));
          if (val_3 != 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            return 9;
          }
        }
        else {
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) | 2;
        }
      }
      else {
        val_3 = *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 +
                        *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x18) * 4);
        if (val_3 == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return 1;
        }
        *(uint32_t *)(val_3 + 4) = *(uint32_t *)(val_3 + 4) | 2;
      }
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) == 0) {
        local_10 = 0;
        while ((local_10 < 0x10 &&
               (i_ptr_2 = (int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + local_10 * 0xc + 0xc0),
               *i_ptr_2 != 0))) {
          val_3 = (**(code **)(*(int *)*i_ptr_2 + 0x48))(*i_ptr_2);
          if (val_3 != 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            return 9;
          }
          local_10 = local_10 + 1;
        }
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xfffffffe;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



void Sound_SetMasterVolume(void)

{
  int local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  for (local_8 = DAT_1000a410; local_8 != 0; local_8 = *(int *)(local_8 + 0x200)) {
    StopSnd(*(int *)(local_8 + 0x10));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  return;
}



int32_t __cdecl FUN_10002900(int arg_1)

{
  int32_t uval_1;
  int val_2;
  int *i_ptr_3;
  int val_4;
  int local_10;
  
  if ((arg_1 < 0x110) && (-1 < arg_1)) {
    if (*(int *)(&DAT_1000a648 + arg_1 * 4) == 0) {
      uval_1 = 1;
    }
    else {
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) >> 6 & 1) == 0) {
        val_4 = (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc) + 0x48))
                          (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc));
        if (val_4 != 0) {
          return 9;
        }
      }
      else {
        val_4 = *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 +
                        *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x18) * 4);
        if (val_4 == 0) {
          return 1;
        }
        val_2 = (**(code **)(**(int **)(val_4 + 0xbc) + 0x48))(*(int32_t *)(val_4 + 0xbc));
        if (val_2 != 0) {
          return 9;
        }
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xffffffbf;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) & 0xfffffffe;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) & 0xfffffffd;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) | 4;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) & 0xffffffdf;
      }
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) == 0) {
        local_10 = 0;
        while ((local_10 < 0x10 &&
               (i_ptr_3 = (int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + local_10 * 0xc + 0xc0),
               *i_ptr_3 != 0))) {
          val_4 = (**(code **)(*(int *)*i_ptr_3 + 0x48))(*i_ptr_3);
          if (val_4 != 0) {
            return 9;
          }
          local_10 = local_10 + 1;
        }
      }
      else if ((0 < DAT_1000a428) && (DAT_1000a428 = DAT_1000a428 + -1, DAT_1000a428 == 0)) {
        thunk_FUN_10004788();
      }
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xfffffffe;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xfffffffd;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) | 4;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xffffffdf;
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t FUN_10002b3c(void)

{
  return 0;
}



int32_t __cdecl FUN_10002b4e(int arg1,int32_t arg2)

{
  int32_t uval_1;
  int *i_ptr_2;
  int local_8;
  
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc) + 0x44))
                (*(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc),arg2);
      local_8 = 0;
      while ((local_8 < 0x10 &&
             (i_ptr_2 = (int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + local_8 * 0xc + 0xc0),
             *i_ptr_2 != 0))) {
        (**(code **)(*(int *)*i_ptr_2 + 0x44))(*i_ptr_2,arg2);
        local_8 = local_8 + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t FUN_10002c54(void)

{
  return 0;
}



/* WARNING: Removing unreachable block (ram,0x10002ce6) */

int32_t __cdecl FUN_10002c66(int arg1,uint32_t arg2)

{
  int val_1;
  int32_t uval_2;
  int *i_ptr_3;
  int local_10;
  
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_2 = 1;
    }
    else {
      if (400 < arg2) {
        arg2 = 400;
      }
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) >> 6 & 1) == 0) {
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1f0) = arg2;
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1f0) = arg2;
        arg2 = (arg2 * 5 + -2000) * 2;
        (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc) + 0x3c))
                  (*(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc),arg2);
      }
      else {
        val_1 = *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x38 +
                        *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x18) * 4);
        if (val_1 == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return 1;
        }
        *(uint32_t *)(val_1 + 0x1f0) = arg2;
        arg2 = (arg2 * 5 + -2000) * 2;
        (**(code **)(**(int **)(val_1 + 0xbc) + 0x3c))(*(int32_t *)(val_1 + 0xbc),arg2);
      }
      local_10 = 0;
      while ((local_10 < 0x10 &&
             (i_ptr_3 = (int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + local_10 * 0xc + 0xc0),
             *i_ptr_3 != 0))) {
        (**(code **)(*(int *)*i_ptr_3 + 0x3c))(*i_ptr_3,arg2);
        local_10 = local_10 + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_2 = 0;
    }
  }
  else {
    uval_2 = 5;
  }
  return uval_2;
}



int32_t FUN_10002e62(void)

{
  return 0;
}



int32_t __cdecl FUN_10002e74(int arg1,int arg2)

{
  int32_t uval_1;
  int *i_ptr_2;
  int local_8;
  
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc) + 0x40))
                (*(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xbc),arg2 * 10);
      local_8 = 0;
      while ((local_8 < 0x10 &&
             (i_ptr_2 = (int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + local_8 * 0xc + 0xc0),
             *i_ptr_2 != 0))) {
        (**(code **)(*(int *)*i_ptr_2 + 0x40))(*i_ptr_2,arg2 * 10);
        local_8 = local_8 + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t FUN_10002f85(void)

{
  return 0;
}



int32_t FUN_10002f97(void)

{
  int32_t *u_ptr_1;
  int32_t uval_2;
  int32_t *local_c;
  
  if (DAT_1000a46c == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    local_c = DAT_1000a418;
    while (local_c != (int32_t *)0x0) {
      if ((*(uint8_t *)(local_c + 1) & 1) != 0) {
        if (((uint32_t)local_c[1] >> 1 & 1) != 0) {
          if ((uint32_t)local_c[0x7c] < 6) {
            local_c[0x7c] = 0;
          }
          else {
            local_c[0x7c] = local_c[0x7c] + -5;
          }
          SetVol(local_c[4],local_c[0x7c]);
        }
        if (((uint32_t)local_c[2] >> 5 & 1) == 0) {
          thunk_FUN_10003a41((int)local_c);
        }
        else if (((uint32_t)local_c[2] >> 6 & 1) == 0) {
          thunk_FUN_1000405a(local_c);
        }
      }
      if ((((uint32_t)local_c[1] >> 2 & 1) == 0) || (((uint32_t)local_c[2] >> 2 & 1) == 0)) {
        local_c = (int32_t *)local_c[0x7e];
      }
      else {
        u_ptr_1 = (int32_t *)local_c[0x80];
        UnloadSnd(local_c[4]);
        local_c = u_ptr_1;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    uval_2 = 0;
  }
  else {
    uval_2 = 0xd;
  }
  return uval_2;
}



int32_t __cdecl FUN_100030e6(int arg1,uint32_t *arg2)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t local_20;
  int local_1c;
  uint32_t local_18;
  double local_14;
  uint32_t local_c;
  uint8_t local_8 [4];
  
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      local_1c = *(int *)(&DAT_1000a648 + arg1 * 4);
      (**(code **)(**(int **)(local_1c + 0xbc) + 0x10))
                (*(int32_t *)(local_1c + 0xbc),&local_20,local_8);
      local_18 = *(uint32_t *)(local_1c + 0x1dc) % *(uint32_t *)(local_1c + 0xb0);
      if (local_18 < local_20) {
        *(int *)(local_1c + 0x1dc) = *(int *)(local_1c + 0x1dc) + (local_20 - local_18);
      }
      else {
        *(int *)(local_1c + 0x1dc) =
             *(int *)(local_1c + 0x1dc) + (*(int *)(local_1c + 0xb0) - local_18);
        *(int *)(local_1c + 0x1dc) = *(int *)(local_1c + 0x1dc) + local_20;
      }
      if ((*(uint32_t *)(local_1c + 8) >> 5 & 1) != 0) {
        local_c = *(uint32_t *)(local_1c + 0x1dc) / *(uint32_t *)(local_1c + 0x8c);
        while (*(uint32_t *)(local_1c + 0xa0) < local_c) {
          PostMessageA(DAT_1000ba88,0x3bd,0,local_c);
          *(int *)(local_1c + 0xa0) = *(int *)(local_1c + 0xa0) + 1;
        }
      }
      local_14 = (double)*(uint32_t *)(local_1c + 0x1dc);
      if (*(int *)(local_1c + 0x80) == 0x15888) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else if (*(int *)(local_1c + 0x80) == 0xac44) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else if (*(int *)(local_1c + 0x80) == 0x5622) {
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      else {
        if (*(int *)(local_1c + 0x80) != 0x2b11) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return 8;
        }
        uval_2 = ftol();
        *arg2 = uval_2;
      }
      *(uint32_t *)(&DAT_1000aa88 + DAT_1000a474 * 0x10) = DAT_1000a438;
      *(uint32_t *)(&DAT_1000aa8c + DAT_1000a474 * 0x10) = *arg2;
      DAT_1000a474 = DAT_1000a474 + 1;
      DAT_1000a474 = DAT_1000a474 & 0xff;
      if (*arg2 < DAT_1000a438) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        uval_1 = 5;
      }
      else {
        DAT_1000a438 = *arg2;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        uval_1 = 0;
      }
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t __cdecl FUN_1000337e(int arg1,int32_t *arg2)

{
  int32_t uval_1;
  
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      if ((*(uint8_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) & 1) == 0) {
        if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) >> 3 & 1) == 0) {
          *arg2 = 0;
        }
        else {
          *arg2 = 2;
        }
      }
      else {
        *arg2 = 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}



int32_t FUN_1000343e(void)

{
  return 0;
}



int32_t __cdecl FUN_10003450(int arg1,int32_t *arg2)

{
  int local_8;
  
  if (0 < arg1) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    for (local_8 = DAT_1000a410; local_8 != 0; local_8 = *(int *)(local_8 + 0x200)) {
      if (*(int *)(local_8 + 0x14) == arg1) {
        *arg2 = *(int32_t *)(local_8 + 0x10);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        return 1;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return 0;
}



int32_t __cdecl FUN_100034de(int *ptr_1,int arg_2,int arg_3)

{
  int local_14;
  int local_10;
  uint32_t local_c;
  int32_t local_8;
  
  local_8 = 0;
  local_c = 0xffffffff;
  if (((arg_3 == 0) || (arg_3 <= arg_2)) || (0xff < arg_3)) {
    local_10 = 0;
    arg_3 = 0xff;
  }
  else {
    local_10 = arg_2;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  do {
    if (arg_3 <= local_10) {
LAB_100035b3:
      *ptr_1 = local_14;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      return local_8;
    }
    if (*(int *)(&DAT_1000a648 + local_10 * 4) == 0) {
      local_14 = local_10;
      local_8 = 1;
      goto LAB_100035b3;
    }
    if (*(uint32_t *)(*(int *)(&DAT_1000a648 + local_10 * 4) + 0xc) < local_c) {
      local_c = *(uint32_t *)(*(int *)(&DAT_1000a648 + local_10 * 4) + 0xc);
      local_14 = *(int *)(*(int *)(&DAT_1000a648 + local_10 * 4) + 0x10);
    }
    local_10 = local_10 + 1;
  } while( true );
}



int32_t __cdecl FUN_100035d3(int arg1,uint32_t arg2)

{
  code *char_ptr_1;
  int val_2;
  int32_t uval_3;
  int32_t local_28;
  int local_24;
  int32_t local_20;
  uint32_t local_1c;
  int local_18;
  int local_14;
  int32_t local_10;
  int32_t local_c;
  int local_8;
  
  local_28 = 0;
  local_14 = 0;
  local_c = 0;
  local_10 = 0;
  local_20 = 0;
  if ((arg1 < 0x110) && (0xff < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    local_24 = *(int *)(&DAT_1000a648 + arg1 * 4);
    if (local_24 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      local_28 = 0;
    }
    else {
      if ((*(uint32_t *)(local_24 + 4) >> 7 & 1) != 0) {
        val_2 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a484,0x484,0,0);
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          uval_3 = (*char_ptr_1)();
          return uval_3;
        }
      }
      if ((*(uint32_t *)(local_24 + 4) >> 7 & 1) == 0) {
        local_1c = arg2 % *(uint32_t *)(local_24 + 0x94);
        local_8 = *(int *)(local_24 + 0x8c) * local_1c;
        local_18 = (**(code **)(**(int **)(local_24 + 0xbc) + 0x2c))
                             (*(int32_t *)(local_24 + 0xbc),local_8,
                              *(int32_t *)(local_24 + 0x8c),&local_28,&local_c,&local_14,
                              &local_10,0);
        if (local_18 == 0) {
          if (local_14 != 0) {
            val_2 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a4a0,0x496,0,0);
            if (val_2 == 1) {
              char_ptr_1 = (code *)swi(3);
              uval_3 = (*char_ptr_1)();
              return uval_3;
            }
          }
          if (local_14 == 0) {
            *(int32_t *)(local_24 + 0xa4) = local_28;
            *(uint32_t *)(local_24 + 4) = *(uint32_t *)(local_24 + 4) | 0x80;
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          }
          else {
            (**(code **)(**(int **)(local_24 + 0xbc) + 0x4c))
                      (*(int32_t *)(local_24 + 0xbc),local_28,local_c,local_14,local_10);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            local_28 = 0;
          }
        }
        else {
          local_28 = 0;
        }
      }
      else {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        local_28 = 0;
      }
    }
  }
  else {
    local_28 = 0;
  }
  return local_28;
}



int32_t __cdecl FUN_100037be(int arg_1)

{
  int val_1;
  code *char_ptr_2;
  int32_t uval_3;
  int val_4;
  
  if ((arg_1 < 0x110) && (0xff < arg_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    val_1 = *(int *)(&DAT_1000a648 + arg_1 * 4);
    if (val_1 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_3 = 0;
    }
    else {
      if ((*(uint32_t *)(val_1 + 4) >> 7 & 1) == 0) {
        val_4 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a4bc,0x4b0,0,0);
        if (val_4 == 1) {
          char_ptr_2 = (code *)swi(3);
          uval_3 = (*char_ptr_2)();
          return uval_3;
        }
      }
      if ((*(uint32_t *)(val_1 + 4) >> 7 & 1) == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        uval_3 = 0xe;
      }
      else {
        if (*(int *)(val_1 + 0xa4) == 0) {
          val_4 = _CrtDbgReport(2,s_G__NewMagic_tstvid_snd_cpp_1000a4d8,0x4b5,0,0);
          if (val_4 == 1) {
            char_ptr_2 = (code *)swi(3);
            uval_3 = (*char_ptr_2)();
            return uval_3;
          }
        }
        if (*(int *)(val_1 + 0xa4) == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          uval_3 = 0xf;
        }
        else {
          (**(code **)(**(int **)(val_1 + 0xbc) + 0x4c))
                    (*(int32_t *)(val_1 + 0xbc),*(int32_t *)(val_1 + 0xa4),
                     *(int32_t *)(val_1 + 0x8c),0,0);
          *(uint32_t *)(val_1 + 4) = *(uint32_t *)(val_1 + 4) & 0xffffff7f;
          *(int32_t *)(val_1 + 0xa4) = 0;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          uval_3 = 0;
        }
      }
    }
  }
  else {
    uval_3 = 0;
  }
  return uval_3;
}



int __cdecl FUN_1000394f(int32_t *ptr_1)

{
  int val_1;
  
  ptr_1[1] = ptr_1[1] & 0xfffffffe;
  ptr_1[1] = ptr_1[1] & 0xfffffffd;
  ptr_1[1] = ptr_1[1] & 0xffffffef;
  ptr_1[1] = ptr_1[1] & 0xfffffffb;
  ptr_1[0x74] = 0;
  ptr_1[0x75] = 0;
  ptr_1[0x76] = 0;
  ptr_1[0x77] = 0;
  DAT_1000a438 = 0;
  if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
    ptr_1[0x67] = ptr_1[0x68];
    mmioSetInfo((HMMIO)ptr_1[0x72],(LPCMMIOINFO)(ptr_1 + 0x60),0);
    val_1 = thunk_FUN_10005f0c(ptr_1,0);
    if (val_1 != 0) {
      return val_1;
    }
  }
  else {
    thunk_FUN_1000630c(ptr_1);
  }
  ptr_1[1] = ptr_1[1] | 0x20;
  return 0;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10003a41(int arg_1)

{
  uint32_t uval_1;
  int local_38;
  int local_34;
  void *local_30;
  uint32_t local_2c;
  uint32_t local_28;
  uint32_t local_24;
  int32_t local_20;
  int local_1c;
  uint32_t local_18;
  int local_14;
  void *local_10;
  size_t local_c;
  size_t local_8;
  
  local_20 = 0;
  local_34 = 0;
  local_18 = 0;
  local_2c = 0;
  local_24 = 0;
  local_1c = 0;
  local_30 = (void *)0x0;
  local_10 = (void *)0x0;
  local_8 = 0;
  local_c = 0;
  local_28 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  (**(code **)(**(int **)(arg_1 + 0xbc) + 0x10))(*(int32_t *)(arg_1 + 0xbc),&local_34,&local_20);
  *(int *)(arg_1 + 0x1dc) = *(int *)(arg_1 + 0x1dc) + (local_34 - *(int *)(arg_1 + 0x1dc) & 0xffffU)
  ;
  if (*(uint32_t *)(arg_1 + 0x1cc) < *(uint32_t *)(arg_1 + 0x1dc)) {
    *(int *)(arg_1 + 0x1dc) = *(int *)(arg_1 + 0x1dc) - *(int *)(arg_1 + 0x1cc);
  }
  if ((((*(uint32_t *)(arg_1 + 4) >> 4 & 1) == 0) || (*(uint32_t *)(arg_1 + 0x1d4) < 0x10000)) &&
     (((*(uint32_t *)(arg_1 + 4) >> 1 & 1) == 0 || (*(int *)(arg_1 + 0x1f0) != 0)))) {
    uval_1 = local_34 - *(int *)(arg_1 + 0x1d8) & 0xffff;
    local_24 = *(int *)(arg_1 + 0x1cc) - *(int *)(arg_1 + 0x1d0);
    if ((*(uint32_t *)(arg_1 + 4) >> 4 & 1) == 0) {
      local_2c = *(int *)(arg_1 + 0x1d0) - *(int *)(arg_1 + 0x1d4);
      if (0x10000 < local_2c) {
        _DAT_1000a47c = _DAT_1000a47c + 1;
      }
    }
    else {
      local_2c = 0;
    }
    local_1c = local_24 + local_2c;
    local_18 = uval_1;
    if (local_1c == 0) {
      local_18 = 0;
      local_28 = uval_1;
    }
    if ((local_18 == 0) && (local_28 == 0)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
    else {
      if (local_2c < local_18) {
        local_18 = local_2c;
      }
      if (local_18 + local_28 != 0) {
        local_14 = (**(code **)(**(int **)(arg_1 + 0xbc) + 0x2c))
                             (*(int32_t *)(arg_1 + 0xbc),*(int32_t *)(arg_1 + 0x1d8),
                              local_18 + local_28,&local_30,&local_8,&local_10,&local_c,0);
        if (local_14 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return;
        }
        *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) | 0x80;
        if (local_28 == 0) {
          mmioGetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
          memmove(local_30,*(void **)(arg_1 + 0x19c),local_8);
          *(int *)(arg_1 + 0x19c) = *(int *)(arg_1 + 0x19c) + local_8;
          if (local_10 != (void *)0x0) {
            memmove(local_10,*(void **)(arg_1 + 0x19c),local_c);
            *(int *)(arg_1 + 0x19c) = *(int *)(arg_1 + 0x19c) + local_c;
          }
          mmioSetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPCMMIOINFO)(arg_1 + 0x180),0);
          local_2c = local_2c - local_18;
          local_1c = local_1c - local_18;
          *(int *)(arg_1 + 0x1d4) = *(int *)(arg_1 + 0x1d4) + local_18;
        }
        else {
          if (*(short *)(arg_1 + 0x86) == 8) {
            local_38 = 0x80;
          }
          else {
            local_38 = 0;
          }
          memset(local_30,local_38,local_8);
          if (local_10 != (void *)0x0) {
            memset(local_10,local_38,local_c);
          }
          *(int *)(arg_1 + 0x1d4) = *(int *)(arg_1 + 0x1d4) + local_28;
        }
        *(uint32_t *)(arg_1 + 0x1d8) = *(int *)(arg_1 + 0x1d8) + local_18 + local_28 & 0xffff;
        (**(code **)(**(int **)(arg_1 + 0xbc) + 0x4c))
                  (*(int32_t *)(arg_1 + 0xbc),local_30,local_8,local_10,local_c);
        *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xffffff7f;
      }
      if (((local_1c != 0) && (local_24 != 0)) && ((local_2c == 0 || (local_2c < local_18 * 2)))) {
        mmioAdvance(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
        if (local_24 < *(int *)(arg_1 + 0x194) - local_2c) {
          *(int *)(arg_1 + 0x1d0) = *(int *)(arg_1 + 0x1d0) + local_24;
        }
        else {
          *(int *)(arg_1 + 0x1d0) = *(int *)(arg_1 + 0x1d0) + (*(int *)(arg_1 + 0x194) - local_2c);
        }
      }
      if (local_1c == 0) {
        if ((*(uint8_t *)(arg_1 + 8) & 1) == 0) {
          if ((*(uint32_t *)(arg_1 + 4) >> 4 & 1) == 0) {
            *(int32_t *)(arg_1 + 0x1e4) = *(int32_t *)(arg_1 + 0x1d8);
            *(int32_t *)(arg_1 + 0x1d4) = 0;
            *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) | 0x10;
          }
        }
        else {
          *(int32_t *)(arg_1 + 0x19c) = *(int32_t *)(arg_1 + 0x1a0);
          mmioSetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPCMMIOINFO)(arg_1 + 0x180),0);
          mmioSeek(*(HMMIO *)(arg_1 + 0x1c8),*(LONG *)(arg_1 + 0x1e0),0);
          mmioGetInfo(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
          mmioAdvance(*(HMMIO *)(arg_1 + 0x1c8),(LPMMIOINFO)(arg_1 + 0x180),0);
          *(int *)(arg_1 + 0x1d0) = *(int *)(arg_1 + 0x19c) - *(int *)(arg_1 + 0x198);
          if (*(uint32_t *)(arg_1 + 0x1cc) < *(uint32_t *)(arg_1 + 0x1d0)) {
            *(int32_t *)(arg_1 + 0x1d0) = *(int32_t *)(arg_1 + 0x1cc);
          }
          *(int32_t *)(arg_1 + 0x1d4) = 0;
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
  }
  else {
    (**(code **)(**(int **)(arg_1 + 0xbc) + 0x48))(*(int32_t *)(arg_1 + 0xbc));
    if ((0 < DAT_1000a428) && (DAT_1000a428 = DAT_1000a428 + -1, DAT_1000a428 == 0)) {
      thunk_FUN_10004788();
    }
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xfffffffe;
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xfffffffd;
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) | 4;
    *(uint32_t *)(arg_1 + 4) = *(uint32_t *)(arg_1 + 4) & 0xffffffdf;
    if ((*(uint32_t *)(arg_1 + 8) >> 4 & 1) != 0) {
      *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) & 0xffffffbf;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + *(int *)(arg_1 + 0x10) * 4) + 4) & 0xfffffffe;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return;
}



int32_t __cdecl FUN_1000405a(int32_t *ptr_1)

{
  uint32_t uval_1;
  uint32_t uval_2;
  uint32_t local_48;
  int32_t local_44;
  int32_t local_40;
  int32_t local_3c;
  int32_t local_38;
  uint32_t local_34;
  uint32_t local_30;
  uint8_t local_2c [4];
  int32_t local_28;
  int32_t local_24;
  uint32_t local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint32_t local_c;
  uint32_t local_8;
  
  local_28 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_24 = 0;
  local_44 = 0;
  local_10 = 0;
  local_8 = 0;
  local_c = 0;
  local_3c = 0;
  (**(code **)(*(int *)ptr_1[0x2f] + 0x10))(ptr_1[0x2f],&local_48,&local_28);
  local_34 = (uint32_t)ptr_1[0x77] % (uint32_t)ptr_1[0x2c];
  if (local_34 < local_48) {
    ptr_1[0x77] = ptr_1[0x77] + (local_48 - local_34);
  }
  else {
    ptr_1[0x77] = ptr_1[0x77] + (ptr_1[0x2c] - local_34);
    ptr_1[0x77] = ptr_1[0x77] + local_48;
  }
  local_30 = local_48 / (uint32_t)ptr_1[0x23];
  local_20 = (uint32_t)ptr_1[0x76] / (uint32_t)ptr_1[0x23];
  if (local_20 != local_30) {
    if (((((uint32_t)ptr_1[1] >> 4 & 1) == 0) || ((uint32_t)ptr_1[0x75] < (uint32_t)ptr_1[0x2c])) &&
       ((((uint32_t)ptr_1[1] >> 1 & 1) == 0 || (ptr_1[0x7c] != 0)))) {
      local_18 = ptr_1[0x23];
      if (((uint32_t)ptr_1[1] >> 4 & 1) == 0) {
        uval_1 = ptr_1[0x74];
        uval_2 = ptr_1[0x24];
        local_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                             (ptr_1[0x2f],ptr_1[0x76],local_18,&local_44,&local_8,&local_10,&local_c
                              ,0);
        if (local_14 != 0) {
          return 10;
        }
        AVIStreamRead(*ptr_1,uval_1 / uval_2,local_8 / (uint32_t)ptr_1[0x24],local_44,local_8,local_2c,
                      &local_1c);
        if (local_10 != 0) {
          AVIStreamRead(*ptr_1,local_1c + uval_1 / uval_2,local_c / (uint32_t)ptr_1[0x24],local_10,local_c
                        ,local_2c,&local_1c);
        }
        ptr_1[0x76] = ptr_1[0x76] + local_18;
        ptr_1[0x76] = (uint32_t)ptr_1[0x76] % (uint32_t)ptr_1[0x2c];
        ptr_1[0x74] = ptr_1[0x74] + local_18;
        ptr_1[0x75] = ptr_1[0x75] + local_18;
        if ((uint32_t)ptr_1[0x73] <= (uint32_t)ptr_1[0x74]) {
          ptr_1[1] = ptr_1[1] | 0x10;
          ptr_1[0x75] = 0;
        }
        (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))(ptr_1[0x2f],local_44,local_8,local_10,local_c);
        ptr_1[1] = ptr_1[1] & 0xffffff7f;
      }
      else {
        ptr_1[0x75] = ptr_1[0x75] + local_18;
      }
    }
    else {
      (**(code **)(*(int *)ptr_1[0x2f] + 0x48))(ptr_1[0x2f]);
      if ((0 < DAT_1000a428) && (DAT_1000a428 = DAT_1000a428 + -1, DAT_1000a428 == 0)) {
        thunk_FUN_10004788();
      }
      ptr_1[1] = ptr_1[1] & 0xfffffffe;
      ptr_1[1] = ptr_1[1] & 0xfffffffd;
      ptr_1[1] = ptr_1[1] | 4;
      ptr_1[1] = ptr_1[1] & 0xffffffdf;
      ptr_1[0x77] = 0;
    }
  }
  return 0;
}



int32_t __cdecl FUN_100043c4(int arg1,int *arg2)

{
  int val_1;
  int32_t uval_2;
  uint8_t local_1c [4];
  int32_t local_18;
  int32_t local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  local_10 = *(int **)(arg1 + 0xbc);
  local_8 = local_10;
  val_1 = (**(code **)(*local_10 + 0x24))(local_10,local_1c);
  if (val_1 == 0) {
    if ((local_1c[0] & 2) == 0) {
      if ((local_1c[0] & 1) == 0) {
        *arg2 = (int)local_8;
        uval_2 = 0;
      }
      else {
        for (local_c = 0; local_14 = 0, local_c < 0x10; local_c = local_c + 1) {
          local_10 = *(int **)(arg1 + 0xc0 + local_c * 0xc);
          if (local_10 == (int *)0x0) {
            val_1 = (**(code **)(*DAT_1000ba90 + 0x14))(DAT_1000ba90,local_8,&local_18);
            if (val_1 != 0) {
              return 9;
            }
            *(int32_t *)(arg1 + 0xc0 + local_c * 0xc) = local_18;
            *arg2 = *(int *)(arg1 + 0xc0 + local_c * 0xc);
            return 0;
          }
          val_1 = (**(code **)(*local_10 + 0x24))(local_10,local_1c);
          if (val_1 != 0) {
            return 9;
          }
          if ((local_1c[0] & 1) == 0) {
            *arg2 = (int)local_10;
            return 0;
          }
        }
        uval_2 = 9;
      }
    }
    else {
      uval_2 = 9;
    }
  }
  else {
    uval_2 = 9;
  }
  return uval_2;
}



void __cdecl FUN_10004534(int arg_1)

{
  if (DAT_1000a418 == 0) {
    DAT_1000a418 = arg_1;
  }
  else {
    *(int *)(DAT_1000a41c + 0x1f8) = arg_1;
    *(int *)(arg_1 + 500) = DAT_1000a41c;
  }
  DAT_1000a41c = arg_1;
  return;
}



void __cdecl FUN_1000458d(int arg_1)

{
  int val_1;
  int val_2;
  int val_3;
  
  val_1 = *(int *)(arg_1 + 500);
  val_2 = *(int *)(arg_1 + 0x1f8);
  val_3 = val_2;
  if (val_1 != 0) {
    *(int *)(val_1 + 0x1f8) = val_2;
    val_3 = DAT_1000a418;
  }
  DAT_1000a418 = val_3;
  if (val_2 != 0) {
    *(int *)(val_2 + 500) = val_1;
    val_1 = DAT_1000a41c;
  }
  DAT_1000a41c = val_1;
  return;
}



void __cdecl FUN_1000460c(int arg_1)

{
  if (DAT_1000a410 == 0) {
    DAT_1000a410 = arg_1;
  }
  else {
    *(int *)(DAT_1000a414 + 0x200) = arg_1;
    *(int *)(arg_1 + 0x1fc) = DAT_1000a414;
  }
  DAT_1000a414 = arg_1;
  return;
}



void __cdecl FUN_10004665(int arg_1)

{
  int val_1;
  int val_2;
  int val_3;
  
  val_1 = *(int *)(arg_1 + 0x1fc);
  val_2 = *(int *)(arg_1 + 0x200);
  val_3 = val_2;
  if (val_1 != 0) {
    *(int *)(val_1 + 0x200) = val_2;
    val_3 = DAT_1000a410;
  }
  DAT_1000a410 = val_3;
  if (val_2 != 0) {
    *(int *)(val_2 + 0x1fc) = val_1;
    val_1 = DAT_1000a414;
  }
  DAT_1000a414 = val_1;
  return;
}



void FUN_100046e4(void)

{
  UpdateSnd();
  return;
}



int32_t FUN_100046fb(void)

{
  MMRESULT MVar1;
  int32_t uval_2;
  
  MVar1 = timeGetDevCaps((LPTIMECAPS)&DAT_1000ba98,8);
  if (MVar1 == 0) {
    timeBeginPeriod(DAT_1000a480);
    DAT_1000ba94 = timeSetEvent(DAT_1000a480,DAT_1000ba98,&LAB_1000110e,0x1000ba88,1);
    if (DAT_1000ba94 == 0) {
      timeEndPeriod(DAT_1000a480);
      uval_2 = 0xc;
    }
    else {
      DAT_1000a424 = 1;
      uval_2 = 0;
    }
  }
  else {
    uval_2 = 0xc;
  }
  return uval_2;
}



void FUN_10004788(void)

{
  if (DAT_1000a424 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    timeKillEvent(DAT_1000ba94);
    DAT_1000ba94 = 0;
    timeEndPeriod(DAT_1000a480);
    DAT_1000a424 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return;
}



int32_t __cdecl FUN_100055b0(char *str_1,int *ptr_2)

{
  FILE *fp;
  int32_t uval_1;
  
  fp = fopen(str_1,&DAT_1000a524);
  if (fp == (FILE *)0x0) {
    uval_1 = 7;
  }
  else {
    uval_1 = thunk_FUN_10005abe(fp,ptr_2);
    fclose(fp);
  }
  return uval_1;
}



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



void __cdecl FUN_10005a46(int32_t *ptr_1)

{
  mmioClose((HMMIO)ptr_1[0x72],0);
  if (ptr_1[0xd] != 0) {
    operator_delete((void *)ptr_1[0xd]);
  }
  if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
    operator_delete((void *)*ptr_1);
  }
  return;
}



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



int32_t __cdecl FUN_10005d4a(int arg1,int arg2)

{
  uint16_t uval_1;
  int val_2;
  int val_3;
  
  mmioGetInfo(*(HMMIO *)(arg1 + 0x1c8),(LPMMIOINFO)(arg1 + 0x180),0);
  uval_1 = *(uint16_t *)(arg1 + 0x84);
  val_2 = *(int *)(arg1 + 0x1e0);
  val_3 = thunk_FUN_10006e80(arg1 + 0x180);
  mmioSeek(*(HMMIO *)(arg1 + 0x1c8),((uint32_t)uval_1 * arg2 + val_2) - val_3,1);
  mmioGetInfo(*(HMMIO *)(arg1 + 0x1c8),(LPMMIOINFO)(arg1 + 0x180),0);
  mmioAdvance(*(HMMIO *)(arg1 + 0x1c8),(LPMMIOINFO)(arg1 + 0x180),0);
  return 0;
}



int32_t __cdecl FUN_10005dff(FILE *x,int y,long width,uint32_t height)

{
  int32_t uval_1;
  int local_1c;
  uint32_t local_18;
  uint32_t local_14;
  int local_10 [3];
  
  fseek(x,width,0);
  fread(local_10,1,0xc,x);
  if (local_10[0] == y) {
    fseek(x,width,0);
    uval_1 = 1;
  }
  else {
    while( true ) {
      local_14 = ftell(x);
      fread(&local_1c,1,8,x);
      if (height <= local_14) break;
      if (local_1c == y) {
        fseek(x,local_14,0);
        return 1;
      }
      local_14 = ftell(x);
      if ((local_18 & 1) != 0) {
        local_18 = local_18 + 1;
      }
      fseek(x,local_18,1);
    }
    fseek(x,width,0);
    uval_1 = 0;
  }
  return uval_1;
}



int32_t __cdecl FUN_10005f0c(int32_t *ptr_1,int arg_2)

{
  int32_t uval_1;
  int local_4c;
  int local_44;
  HPSTR local_40;
  int local_3c;
  int local_38;
  int32_t local_34;
  size_t local_30;
  HPSTR local_2c;
  int local_28;
  int local_24;
  int local_20;
  int32_t local_1c;
  int32_t local_18;
  int local_14;
  int local_10;
  int local_c;
  int32_t local_8;
  
  local_40 = (HPSTR)0x0;
  local_1c = 0;
  local_2c = (HPSTR)0x0;
  local_8 = 0;
  local_18 = 0;
  local_34 = 0;
  local_38 = 0;
  if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
    thunk_FUN_10005d4a((int)ptr_1,arg_2);
  }
  local_3c = (uint32_t)*(uint16_t *)(ptr_1 + 0x21) * arg_2;
  local_28 = ptr_1[0x73];
  local_4c = local_28 - local_3c;
  local_30 = 0x10000;
  if ((local_3c < 0) || (local_28 < local_3c)) {
    uval_1 = 5;
  }
  else {
    local_20 = local_3c;
    local_c = local_3c;
    local_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                         (ptr_1[0x2f],0,0x10000,&local_40,&local_8,&local_1c,&local_18,0);
    if (local_14 == 0) {
      local_2c = local_40;
      local_14 = 0;
      while (local_38 == 0) {
        if (local_4c < (int)local_30) {
          if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
            local_10 = mmioRead((HMMIO)ptr_1[0x72],local_2c,local_4c);
          }
          else {
            AVIStreamRead(*ptr_1,arg_2,
                          (int)(0x10000 / (ulonglong)(longlong)(int)(uint32_t)*(uint16_t *)(ptr_1 + 0x21))
                          ,local_2c,local_4c,&local_10,0);
          }
          local_2c = local_2c + local_10;
          local_30 = local_30 - local_10;
          local_4c = 0;
          local_20 = ptr_1[0x73];
          if ((*(uint8_t *)(ptr_1 + 2) & 1) == 0) {
            memset(local_2c,0,local_30);
            local_38 = 1;
          }
          else {
            if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
              thunk_FUN_10005d4a((int)ptr_1,0);
            }
            local_20 = 0;
            local_4c = ptr_1[0x73];
            local_c = 0;
          }
        }
        else {
          if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
            local_10 = mmioRead((HMMIO)ptr_1[0x72],local_2c,local_30);
          }
          else {
            AVIStreamRead(*ptr_1,arg_2,
                          (int)(0x10000 / (ulonglong)(longlong)(int)(uint32_t)*(uint16_t *)(ptr_1 + 0x21))
                          ,local_2c,0x10000,&local_10,&local_44);
          }
          local_30 = local_30 - local_10;
          local_c = local_c + local_10;
          local_4c = local_4c - local_10;
          local_20 = local_20 + local_10;
          arg_2 = arg_2 + local_44;
          local_38 = 1;
        }
      }
      mmioGetInfo((HMMIO)ptr_1[0x72],(LPMMIOINFO)(ptr_1 + 0x60),0);
      if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
        mmioAdvance((HMMIO)ptr_1[0x72],(LPMMIOINFO)(ptr_1 + 0x60),0);
      }
      else {
        thunk_FUN_10006830(ptr_1,arg_2);
      }
      local_24 = local_4c;
      if (0xffff < local_4c) {
        local_24 = 0x10000;
      }
      ptr_1[0x74] = ptr_1[0x73] - (local_4c - local_24);
      ptr_1[0x75] = ptr_1[0x73] - local_4c;
      ptr_1[0x76] = 0;
      local_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))
                           (ptr_1[0x2f],local_40,local_8,local_1c,local_18);
      if (local_14 == 0) {
        uval_1 = 0;
      }
      else {
        thunk_FUN_10005a46(ptr_1);
        thunk_FUN_10006622(ptr_1);
        uval_1 = 9;
      }
    }
    else {
      if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
        thunk_FUN_10005a46(ptr_1);
      }
      else {
        thunk_FUN_1000681e();
      }
      thunk_FUN_10006622(ptr_1);
      uval_1 = 9;
    }
  }
  return uval_1;
}



int32_t __cdecl FUN_1000630c(int32_t *ptr_1)

{
  int32_t uval_1;
  int local_34;
  uint32_t local_30;
  uint8_t local_2c [4];
  uint32_t local_28;
  int local_24;
  uint8_t local_20 [4];
  int local_1c;
  int local_18;
  int32_t local_14;
  int local_10;
  int32_t local_c;
  int local_8;
  
  local_24 = ptr_1[0x25] * ptr_1[0x23];
  local_8 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                      (ptr_1[0x2f],0,local_24,&local_34,&local_c,&local_18,&local_14,0);
  if (local_8 == 0) {
    if (local_18 == 0) {
      ptr_1[0x76] = 0;
      ptr_1[0x74] = 0;
      ptr_1[0x75] = 0;
      local_1c = local_34;
      local_10 = 0;
      local_28 = (uint32_t)ptr_1[0x23] / (uint32_t)ptr_1[0x24];
      local_8 = 0;
      for (local_30 = 0; local_30 < (uint32_t)ptr_1[0x25]; local_30 = local_30 + 1) {
        AVIStreamRead(*ptr_1,local_10,local_28,local_1c,ptr_1[0x23],local_2c,local_20);
        ptr_1[0x76] = ptr_1[0x76] + ptr_1[0x23];
        ptr_1[0x76] = (uint32_t)ptr_1[0x76] % (uint32_t)ptr_1[0x2c];
        ptr_1[0x74] = ptr_1[0x74] + ptr_1[0x23];
        ptr_1[0x75] = ptr_1[0x75] + ptr_1[0x23];
        local_1c = local_1c + ptr_1[0x23];
        local_10 = local_10 + local_28;
      }
      local_8 = (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))
                          (ptr_1[0x2f],local_34,local_c,local_18,local_14);
      if (local_8 == 0) {
        uval_1 = 0;
      }
      else {
        thunk_FUN_10005a46(ptr_1);
        thunk_FUN_10006622(ptr_1);
        uval_1 = 9;
      }
    }
    else {
      (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))(ptr_1[0x2f],local_34,local_c,local_18,local_14);
      thunk_FUN_1000681e();
      thunk_FUN_10006622(ptr_1);
      uval_1 = 9;
    }
  }
  else {
    thunk_FUN_1000681e();
    thunk_FUN_10006622(ptr_1);
    uval_1 = 9;
  }
  return uval_1;
}



void * __cdecl FUN_10006540(int *ptr_1,int32_t arg_2,int32_t *ptr_3,int32_t arg_4)

{
  void *ptr_1_00;
  int val_1;
  
  ptr_1_00 = operator_new(0x204);
  memset(ptr_1_00,0,0x204);
  *(int32_t *)((int)ptr_1_00 + 0xa8) = 0x14;
  *(int32_t *)((int)ptr_1_00 + 0xac) = arg_4;
  *(int32_t *)((int)ptr_1_00 + 0xb0) = arg_2;
  *(int32_t **)((int)ptr_1_00 + 0xb8) = ptr_3;
  *(int32_t *)((int)ptr_1_00 + 0x78) = *ptr_3;
  *(int32_t *)((int)ptr_1_00 + 0x7c) = ptr_3[1];
  *(int32_t *)((int)ptr_1_00 + 0x80) = ptr_3[2];
  *(int32_t *)((int)ptr_1_00 + 0x84) = ptr_3[3];
  *(int16_t *)((int)ptr_1_00 + 0x88) = *(int16_t *)(ptr_3 + 4);
  val_1 = (**(code **)(*ptr_1 + 0xc))(ptr_1,(int)ptr_1_00 + 0xa8,(int)ptr_1_00 + 0xbc,0);
  if (val_1 != 0) {
    operator_delete(ptr_1_00);
    ptr_1_00 = (void *)0x0;
  }
  return ptr_1_00;
}



int32_t __cdecl FUN_10006622(void *ptr_1)

{
  int32_t uval_1;
  
  if (ptr_1 == (void *)0x0) {
    uval_1 = 5;
  }
  else {
    (**(code **)(**(int **)((int)ptr_1 + 0xbc) + 8))(*(int32_t *)((int)ptr_1 + 0xbc));
    operator_delete(ptr_1);
    uval_1 = 0;
  }
  return uval_1;
}



int32_t __cdecl FUN_1000667b(int32_t arg_1,int *ptr_2)

{
  int32_t uval_1;
  void *buf_ptr_2;
  int val_3;
  int32_t *puVar4;
  int32_t *puVar5;
  int32_t uStack0000000c;
  int32_t local_fc [4];
  int16_t local_ec;
  int32_t local_e8 [18];
  uint8_t local_a0 [4];
  int local_9c;
  int local_98;
  int32_t local_94;
  int local_90 [8];
  int local_70;
  int local_68;
  int local_60;
  
  local_94 = 0x12;
  AVIStreamInfoA(arg_1,local_90,0x8c);
  if (local_90[0] == 0x73647561) {
    AVIStreamRead(arg_1,0,1,0,0,local_a0,0);
    local_98 = local_60 * local_70;
    AVIStreamReadFormat(arg_1,0,local_fc,&local_94);
    local_ec = 0;
    uStack0000000c = 0xe8;
    local_9c = local_68 * 0xb;
    buf_ptr_2 = thunk_FUN_10006540(DAT_1000ba90,local_9c,local_fc,0xe8);
    *ptr_2 = (int)buf_ptr_2;
    if (*ptr_2 == 0) {
      uval_1 = 9;
    }
    else {
      *(int32_t *)(*ptr_2 + 0x1e0) = 0;
      *(int32_t *)(*ptr_2 + 0x1c8) = 0;
      puVar4 = local_e8;
      puVar5 = (int32_t *)(*ptr_2 + 0x180);
      for (val_3 = 0x12; val_3 != 0; val_3 = val_3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      *(int *)(*ptr_2 + 0x1cc) = local_98;
      *(int32_t *)*ptr_2 = arg_1;
      *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 0x20;
      *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 2;
      *(int *)(*ptr_2 + 0x8c) = local_68;
      *(int *)(*ptr_2 + 0x90) = local_60;
      *(int32_t *)(*ptr_2 + 0x94) = 0xb;
      *(int32_t *)(*ptr_2 + 0x1dc) = 0;
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 8;
  }
  return uval_1;
}



int32_t FUN_1000681e(void)

{
  return 0;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10006830(int32_t *ptr_1,int32_t arg_2)

{
  int local_1c;
  int32_t local_c;
  size_t local_8;
  
  local_c = 0;
  local_8 = ptr_1[0x74] - ptr_1[0x75];
  if (ptr_1[0x68] - ptr_1[0x67] != local_8) {
    _DAT_1000a520 = _DAT_1000a520 + 1;
  }
  local_1c = ptr_1[0x65] - local_8;
  if ((int)(ptr_1[0x73] - ptr_1[0x74]) < (int)(ptr_1[0x65] - local_8)) {
    local_1c = ptr_1[0x73] - ptr_1[0x74];
  }
  if (local_8 != 0) {
    memmove((void *)ptr_1[0x66],(void *)ptr_1[0x67],local_8);
  }
  ptr_1[0x67] = ptr_1[0x66] + local_8;
  AVIStreamRead(*ptr_1,arg_2,local_1c / (int)(uint32_t)*(uint16_t *)(ptr_1 + 0x21),ptr_1[0x67],local_1c,
                &local_c,0);
  ptr_1[0x68] = ptr_1[0x65] + ptr_1[0x66];
  ptr_1[0x67] = ptr_1[0x66];
  mmioSetInfo((HMMIO)ptr_1[0x72],(LPCMMIOINFO)(ptr_1 + 0x60),0);
  return;
}



int __cdecl FUN_10006e80(int arg_1)

{
  return *(int *)(arg_1 + 0x2c) - (*(int *)(arg_1 + 0x20) - *(int *)(arg_1 + 0x1c));
}



void AVIStreamRead(void)

{
                    /* WARNING: Could not recover jumptable at 0x10006f20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamRead();
  return;
}



void AVIStreamReadFormat(void)

{
                    /* WARNING: Could not recover jumptable at 0x10006f26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamReadFormat();
  return;
}



void AVIStreamInfoA(void)

{
                    /* WARNING: Could not recover jumptable at 0x10006f2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamInfoA();
  return;
}



void DirectSoundCreate(void)

{
                    /* WARNING: Could not recover jumptable at 0x10006f32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectSoundCreate();
  return;
}



void __cdecl ftol(void)

{
                    /* WARNING: Could not recover jumptable at 0x10006f38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ftol();
  return;
}



void * __cdecl memset(void *ptr_1,int arg_2,size_t arg_3)

{
  void *buf_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x10006f46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  buf_ptr_1 = memset(ptr_1,arg_2,arg_3);
  return buf_ptr_1;
}



void __cdecl operator_delete(void *ptr_1)

{
                    /* WARNING: Could not recover jumptable at 0x10006f5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(ptr_1);
  return;
}



void * __cdecl operator_new(uint32_t arg_1)

{
  void *buf_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x10006f64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  buf_ptr_1 = operator_new(arg_1);
  return buf_ptr_1;
}



char * __cdecl strcpy(char *str_1,char *str_2)

{
  char *char_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x10006f6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  char_ptr_1 = strcpy(str_1,str_2);
  return char_ptr_1;
}



size_t __cdecl strlen(char *str_1)

{
  size_t len_1;
  
                    /* WARNING: Could not recover jumptable at 0x10006f70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  len_1 = strlen(str_1);
  return len_1;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __CRT_INIT@12
   
   Library: Visual Studio 1998 Debug */

int32_t __CRT_INIT_12(int32_t arg_1,int arg_2)

{
  DWORD DVar1;
  int *local_c;
  char local_8;
  
  if (arg_2 == 0) {
    if (DAT_1000a530 < 1) {
      return 0;
    }
    DAT_1000a530 = DAT_1000a530 + -1;
  }
  if (DAT_1000a534 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_1000a534 = DAT_1000a534 + 1;
    }
    else {
      DAT_1000a534 = DAT_1000a534 + -1;
    }
  }
  _DAT_1000bf50 = *(int32_t *)_adjust_fdiv_exref;
  if (arg_2 == 1) {
    if ((DAT_1000a534 < 0) || (DAT_1000a530 == 0)) {
      if (DAT_1000a534 < 0) {
        DAT_1000bf6c = (int *)malloc_dbg(0x80,2,"crtdll.c",200);
        if (DAT_1000bf6c == (int *)0x0) {
          return 0;
        }
      }
      else if ((DAT_1000a530 == 0) &&
              (DAT_1000bf6c = GlobalAlloc(0x2000,0x80), DAT_1000bf6c == (int *)0x0)) {
        return 0;
      }
      *DAT_1000bf6c = 0;
      DAT_1000bf5c = DAT_1000bf6c;
      initterm(&DAT_1000a000,&DAT_1000a104);
      DAT_1000a530 = DAT_1000a530 + 1;
    }
  }
  else if ((arg_2 == 0) &&
          (((DAT_1000a534 < 0 || (DAT_1000a530 == 0)) && (DAT_1000bf6c != (int *)0x0)))) {
    local_c = DAT_1000bf5c;
    while (local_c = local_c + -1, DAT_1000bf6c <= local_c) {
      if (*local_c != 0) {
        (*(code *)*local_c)();
      }
    }
    if (DAT_1000a534 < 0) {
      free_dbg(DAT_1000bf6c,2);
    }
    else {
      GlobalFree(DAT_1000bf6c);
    }
    DAT_1000bf6c = (int *)0x0;
  }
  return 1;
}



int entry(HMODULE arg_1,int arg_2,int32_t arg_3)

{
  int val_1;
  int local_8;
  
  local_8 = 1;
  if ((arg_2 == 0) && (DAT_1000a530 == 0)) {
    local_8 = 0;
  }
  else {
    if ((arg_2 == 1) || (arg_2 == 2)) {
      if (DAT_1000bf70 != (code *)0x0) {
        local_8 = (*DAT_1000bf70)(arg_1,arg_2,arg_3);
      }
      if (local_8 != 0) {
        local_8 = __CRT_INIT_12(arg_1,arg_2);
      }
      if (local_8 == 0) {
        return 0;
      }
    }
    local_8 = _DllMain_12(arg_1,arg_2);
    if ((arg_2 == 1) && (local_8 == 0)) {
      __CRT_INIT_12(arg_1,0);
    }
    if ((arg_2 == 0) || (arg_2 == 3)) {
      val_1 = __CRT_INIT_12(arg_1,arg_2);
      if (val_1 == 0) {
        local_8 = 0;
      }
      if ((local_8 != 0) && (DAT_1000bf70 != (code *)0x0)) {
        local_8 = (*DAT_1000bf70)(arg_1,arg_2,arg_3);
      }
    }
  }
  return local_8;
}



/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Debug */

_onexit_t __cdecl __onexit(_onexit_t arg_1)

{
  DWORD DVar1;
  _onexit_t local_c;
  char local_8;
  
  if (DAT_1000a534 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_1000a534 = DAT_1000a534 + 1;
    }
    else {
      DAT_1000a534 = DAT_1000a534 + -1;
    }
  }
  if (0 < DAT_1000a534) {
    while (0 < DAT_1000a538) {
      Sleep(0);
    }
    DAT_1000a538 = DAT_1000a538 + 1;
  }
  if (DAT_1000bf6c == -1) {
    local_c = _onexit(arg_1);
  }
  else {
    local_c = (_onexit_t)__dllonexit(arg_1,&DAT_1000bf6c,&DAT_1000bf5c);
  }
  if (0 < DAT_1000a534) {
    DAT_1000a538 = DAT_1000a538 + -1;
  }
  return local_c;
}



/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Debug */

int __cdecl _atexit(_func_4879 *ptr_1)

{
  _onexit_t p_Var1;
  int val_2;
  
  p_Var1 = __onexit((_onexit_t)ptr_1);
  if (p_Var1 == (_onexit_t)0x0) {
    val_2 = -1;
  }
  else {
    val_2 = 0;
  }
  return val_2;
}



void __cdecl initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x100073d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  initterm();
  return;
}



/* Library Function - Single Match
    _DllMain@12
   
   Library: Visual Studio 1998 Debug */

int32_t _DllMain_12(HMODULE arg_1,int arg_2)

{
  if ((arg_2 == 1) && (DAT_1000bf70 == 0)) {
    DisableThreadLibraryCalls(arg_1);
  }
  return 1;
}



void __dllonexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x10007428. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __dllonexit();
  return;
}


