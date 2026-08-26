#include "magvid_unified.h"


uint8_t DAT_10010868;
uint8_t LAB_100023b6;
int32_t DAT_1001054c;
int DAT_10010584;
uint8_t *DAT_10032c84;
int32_t DAT_10010618;
int DAT_100275d0;
string s_vidsdraw,_vcmDraw(m_pvBuf),_rval_10010634;
uint8_t DAT_1001bf60;
uint8_t *PTR_s_magsnd_1001058c;
HMODULE DAT_10032c44;
int32_t DAT_10032c70;
int32_t DAT_10010588;
int32_t DAT_10010580;
uint8_t *DAT_10032cbc;
LPARAM DAT_1001053c;
uint8_t LAB_100032d7;
uint8_t LAB_1000aba6;
uint8_t *DAT_10032cd0;
uint8_t *PTR_LAB_1000f060;
uint8_t LAB_10007a6c;
string s_G:\NewMagic\tstvid\Videovcm.cpp_100106ec;
string s_m_pbiSrc_&&_m_pbiDst_1001070c;
string s_vidsCatchup(),_!m_bPlaying,_Draw_10010658;
string s_vidsCatchup(),_!m_bPlaying,_Draw_1001067c;
int DAT_10010530;
uint8_t DAT_10010878;
uint8_t DAT_1001087c;
uint8_t DAT_10010880;
uint8_t DAT_10010884;
int32_t DAT_10010888;
uint8_t DAT_1001088c;
uint8_t DAT_10010890;
uint8_t DAT_10010894;
uint8_t DAT_10010898;
uint8_t *PTR_s_VIDWINCLASS_10010534;
uint8_t DAT_1001089c;
uint8_t LAB_100010be;
uint8_t *DAT_10032c7c;
uint8_t *DAT_10032c8c;
uint8_t DAT_10010544;
HWND DAT_1001053c;
HINSTANCE DAT_1001054c;
uint8_t LAB_10002dae;
string s_GetLastError_10010564;
uint8_t LAB_10001005;
uint8_t *DAT_10032cb0;
uint8_t *DAT_10032c78;
int DAT_10010588;
int DAT_10010580;
uint8_t *DAT_10032c74;
HINSTANCE DAT_10010888;
uint8_t DAT_100108b0;
uint8_t DAT_10010850;
uint8_t FUN_10002850;
int DAT_10010550;
UINT DAT_10010554;
uint8_t DAT_100108a8;
uint8_t *DAT_10032c80;
uint8_t *DAT_10032c88;
uint8_t *DAT_10032c90;
uint8_t *DAT_10032c94;
uint8_t *DAT_10032c98;
uint8_t *DAT_10032c9c;
uint8_t *DAT_10032ca0;
uint8_t *DAT_10032ca4;
uint8_t *DAT_10032ca8;
uint8_t *DAT_10032cac;
uint8_t *DAT_10032cb4;
uint8_t *DAT_10032cb8;
uint8_t *DAT_10032cc0;
uint8_t *DAT_10032cc4;
uint8_t *DAT_10032cc8;
uint8_t *DAT_10032ccc;
uint8_t *DAT_10032cd4;
uint8_t *DAT_10032cd8;
int32_t _delay;
uint8_t LAB_100059d0;
uint32_t DAT_1001bf38;
int DAT_1001059c;
int DAT_100105a0;
uint8_t s_d:\avi\quant.pal_100105a4;
string s_Palette_Files_100105b8;
string s_Select_Palette_File_100105d0;
void *DAT_1001bf50;
uint8_t DAT_100105f8;
string s_IVIPLAY:_10010624;
uint8_t DAT_10010630;
string s_KPlay_error_100106c4;
string s_Not_a_Windows_DIB._100106d0;
uint8_t DAT_100275d8;
int DAT_10010730;
int DAT_10010734;
int32_t DAT_10032d04;
int32_t DAT_10032cf4;
int DAT_10010738;
uint8_t *PTR__adjust_fdiv_10033618;
uint8_t DAT_10032cdc;
int *DAT_10032d04;
int *DAT_10032cf4;
uint8_t DAT_10010000;
uint8_t DAT_1001021c;
uint8_t *DAT_10032ce8;

void __thiscall
thunk_FUN_100086b0(void *this,int32_t arg_2,int32_t arg_3,int32_t arg_4,int32_t arg_5)

{
  DWORD DVar1;
  
  DVar1 = timeGetTime();
  *(DWORD *)((int)this + 0x84) = DVar1;
  *(int32_t *)((int)this + 0x88) = arg_2;
  *(int32_t *)((int)this + 0x8c) = arg_3;
  *(int32_t *)((int)this + 0x90) = arg_4;
  *(int32_t *)((int)this + 0x94) = arg_5;
  return;
}



int32_t __thiscall thunk_FUN_10007eaf(void *this,int32_t arg_2)

{
  int32_t uval_1;
  
  uval_1 = AVIStreamTimeToSample(*(int32_t *)((int)this + 0xc),arg_2);
  return uval_1;
}



int32_t __thiscall thunk_FUN_1000b685(void *this,int *ptr_2)

{
  int32_t uval_1;
  
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *ptr_2 = *(int *)((int)this + 0x16c);
    ptr_2[1] = *(int *)((int)this + 0x170);
    ptr_2[2] = *(int *)((int)this + 0x174) + *ptr_2;
    ptr_2[3] = *(int *)((int)this + 0x178) + ptr_2[1];
    uval_1 = 0;
  }
  else {
    uval_1 = 0xffffffff;
  }
  return uval_1;
}



int32_t __fastcall thunk_FUN_1000ae35(int32_t *ptr_1)

{
  int32_t uval_1;
  
  uval_1 = ftol(1000000);
  ICDrawBegin(*ptr_1,0,0,0,0,0,0,0,0,0,0,0,0,0,uval_1);
  ICSendMessage(*ptr_1,0x4012,0,0);
  return 0;
}



int32_t __thiscall thunk_FUN_100089e8(void *this,int *ptr_2,int32_t arg_3)

{
  void *buf_ptr_1;
  int32_t uval_2;
  int val_3;
  
  if (*(int *)((int)this + 4) != 0) {
    free(*(void **)((int)this + 4));
  }
  if (*(short *)((int)ptr_2 + 0xe) == 8) {
    buf_ptr_1 = malloc(0x428);
    *(void **)((int)this + 4) = buf_ptr_1;
  }
  else {
    buf_ptr_1 = malloc(0x28);
    *(void **)((int)this + 4) = buf_ptr_1;
  }
  if (*(int *)((int)this + 4) == 0) {
    uval_2 = 0;
  }
  else {
    val_3 = FUN_10008ad5(ptr_2);
    memcpy(*(void **)((int)this + 4),ptr_2,val_3 * 4 + 0x28);
    if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 8) != 0)) {
      free(*(void **)((int)this + 8));
    }
    *(int32_t *)((int)this + 8) = arg_3;
    *(int32_t *)((int)this + 0xc) = 0;
    uval_2 = 1;
  }
  return uval_2;
}



int32_t __cdecl thunk_FUN_10004249(int arg1,int *arg2)

{
  int val_1;
  bool flag_2;
  int32_t uval_3;
  int iStack_8;
  
  iStack_8 = 0;
  do {
    if ((*(int *)(&DAT_10010868 + iStack_8 * 4) == 0) ||
       (*(int *)(*(int *)(&DAT_10010868 + iStack_8 * 4) + 0x10) == arg1)) break;
    val_1 = iStack_8 + 1;
    flag_2 = iStack_8 < 3;
    iStack_8 = val_1;
  } while (flag_2);
  if (iStack_8 < 3) {
    *arg2 = iStack_8;
    uval_3 = 0;
  }
  else {
    uval_3 = 2;
  }
  return uval_3;
}



int __thiscall thunk_FUN_100095cf(void *this,int arg_2,int arg_3)

{
  int val_1;
  uint32_t uval_2;
  int val_3;
  
  val_1 = CFontDialog::GetWeight(this);
  if ((arg_2 < val_1) && (val_1 = CFontDialog::GetWeight(this), arg_3 < val_1)) {
    uval_2 = thunk_FUN_1000a200((int)this);
    val_1 = CFontDialog::GetWeight(this);
    val_3 = (uint32_t)*(uint16_t *)(*(int *)((int)this + 4) + 0xe) * arg_2;
    return ((val_1 - arg_3) + -1) * uval_2 + ((int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3) +
           *(int *)((int)this + 8);
  }
  return 0;
}



int32_t __thiscall thunk_FUN_10002289(void *this,int arg_2)

{
  int32_t uval_1;
  CPrintPreviewState *this_00;
  uint32_t uval_2;
  HWND pHVar3;
  int val_4;
  int32_t *unaff_FS_OFFSET;
  int32_t uStack_40;
  uint8_t auStack_38 [14];
  uint16_t uStack_2a;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_100023b6;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    if (arg_2 != 0) {
      thunk_FUN_1000b759(*(void **)this,auStack_38);
      this_00 = operator_new(0x18);
      uStack_8 = 0;
      if (this_00 == (CPrintPreviewState *)0x0) {
        uStack_40 = 0;
      }
      else {
        uStack_40 = CPrintPreviewState::CPrintPreviewState(this_00);
      }
      uStack_8 = 0xffffffff;
      *(int32_t *)((int)this + 4) = uStack_40;
      uval_2 = (uint32_t)uStack_2a;
      pHVar3 = GetActiveWindow();
      val_4 = (**(code **)**(int32_t **)((int)this + 4))(pHVar3,arg_2,uval_2);
      if (val_4 == 0) {
        uval_1 = 0xfffffffb;
        goto LAB_100023c0;
      }
    }
    val_4 = thunk_FUN_1000bac7(*(void **)this,*(int **)((int)this + 4));
    if (val_4 == 0) {
      uval_1 = 0xfffffffb;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 0xfffffffc;
  }
LAB_100023c0:
  *unaff_FS_OFFSET = uStack_10;
  return uval_1;
}



void __thiscall thunk_FUN_10007bde(void *this,int arg_2)

{
  *(int *)((int)this + 0x34) = *(int *)((int)this + 0x34) + arg_2;
  return;
}



int __thiscall thunk_FUN_10001a02(void *this,int arg_2,int arg_3)

{
  int val_1;
  int32_t uStack_b4;
  int32_t uStack_b0;
  int32_t uStack_ac;
  int32_t uStack_a8;
  int32_t uStack_a4;
  int32_t uStack_a0;
  int32_t uStack_9c;
  int32_t uStack_98;
  uint8_t auStack_94 [20];
  uint32_t uStack_80;
  uint32_t uStack_7c;
  int iStack_8;
  
  if ((*(int *)((int)this + 0xc) != 0) || (*(int *)((int)this + 0x10) != 0)) {
    thunk_FUN_10001c16(this);
  }
  *(int32_t *)((int)this + 0x1c) = 0;
  *(int32_t *)((int)this + 0x18) = *(int32_t *)((int)this + 0x1c);
  *(int *)((int)this + 0x14) = arg_2;
  *(int32_t *)this = 0;
  *(int32_t *)((int)this + 0x74) = 0;
  iStack_8 = AVIFileGetStream(*(int32_t *)((int)this + 8),(int)this + 0xc,0x73646976,0);
  if (iStack_8 == -0x7ffbbf8d) {
    *(int32_t *)((int)this + 0xc) = 0;
    val_1 = -1;
  }
  else {
    iStack_8 = AVIFileGetStream(*(int32_t *)((int)this + 8),(int)this + 0x10,0x73647561,0);
    if (iStack_8 == -0x7ffbbf8d) {
      *(int32_t *)((int)this + 0x10) = 0;
    }
    else {
      uStack_b4 = 400;
      uStack_b0 = 0;
      uStack_ac = 0;
      uStack_a8 = 0;
      uStack_a4 = 0;
      uStack_a0 = 0;
      uStack_9c = 0;
      uStack_98 = 0x14;
      thunk_FUN_10004e65(*(int32_t *)((int)this + 0x10),arg_3 + 0x100,&uStack_b4);
    }
    AVIStreamInfoA(*(int32_t *)((int)this + 0xc),auStack_94,0x8c);
    *(float *)((int)this + 0x24) = (float)((float10)uStack_7c / (float10)uStack_80);
    *(int32_t *)((int)this + 0x20) = *(int32_t *)((int)this + 0x24);
    val_1 = thunk_FUN_1000785e(this);
    if (val_1 == 0) {
      val_1 = 0;
    }
  }
  return val_1;
}



int32_t __fastcall thunk_FUN_10007bff(int32_t *ptr_1)

{
  int32_t uval_1;
  
  if (ptr_1[0xc] == 0) {
    uval_1 = 0xffffffea;
  }
  else {
    thunk_FUN_1000aea5((int32_t *)*ptr_1);
    thunk_FUN_1000acaf((int32_t *)*ptr_1);
    ptr_1[0xd] = 0xffffffff;
    ptr_1[0xc] = 0;
    uval_1 = 0;
  }
  return uval_1;
}



int32_t thunk_FUN_1000286a(int32_t arg_1,int32_t arg_2)

{
  switch(arg_2) {
  case 0:
    break;
  case 1:
    DAT_1001054c = arg_1;
    break;
  case 2:
    break;
  case 3:
  }
  return 1;
}



void __fastcall thunk_FUN_100027a0(int arg_1)

{
  *(int32_t *)(arg_1 + 0x48) = 0xffffffff;
  return;
}



int32_t __fastcall thunk_FUN_10001d28(int32_t *ptr_1)

{
  ptr_1[6] = 0;
  ptr_1[7] = 0;
  thunk_FUN_1000735d();
  thunk_FUN_10007bff(ptr_1);
  timeEndPeriod(ptr_1[10]);
  return 0;
}



int32_t __cdecl thunk_FUN_10004f02(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c84)(arg_1,arg_2);
  }
  return uval_1;
}



uint32_t __fastcall thunk_FUN_1000a200(int arg_1)

{
  int val_1;
  
  val_1 = (uint32_t)*(uint16_t *)(*(int *)(arg_1 + 4) + 0xe) * *(int *)(*(int *)(arg_1 + 4) + 4);
  return ((int)(val_1 + (val_1 >> 0x1f & 7U)) >> 3) + 3U & 0xfffffffc;
}



void __thiscall
thunk_FUN_10008600(void *this,int32_t arg_2,int32_t arg_3,int32_t arg_4,int32_t arg_5)

{
  thunk_FUN_100086b0((void *)((int)this + *(int *)this * 0x98 + 4),arg_2,arg_3,arg_4,arg_5);
  return;
}



void __thiscall thunk_FUN_10008660(void *this,char *str_2)

{
  DWORD DVar1;
  
  strcpy(this,str_2);
  DVar1 = timeGetTime();
  *(DWORD *)((int)this + 0x80) = DVar1;
  return;
}



bool __thiscall thunk_FUN_1000b99f(void *this,int arg_2)

{
  int val_1;
  uint32_t uval_2;
  int iStack_18;
  int iStack_8;
  
  if (arg_2 == 0) {
    iStack_8 = ICSendMessage(*(int32_t *)this,0x401d,0,0);
  }
  else {
    val_1 = *(int *)((int)this + 0x18);
    uval_2 = (uint32_t)*(uint16_t *)(arg_2 + 2);
    if (0xeb < *(uint16_t *)(arg_2 + 2)) {
      uval_2 = 0xec;
    }
    for (iStack_18 = 0; iStack_18 < (int)uval_2; iStack_18 = iStack_18 + 1) {
      *(uint8_t *)(val_1 + 0x52 + iStack_18 * 4) = *(uint8_t *)(arg_2 + 4 + iStack_18 * 4);
      *(uint8_t *)(val_1 + 0x51 + iStack_18 * 4) = *(uint8_t *)(arg_2 + 5 + iStack_18 * 4);
      *(uint8_t *)(val_1 + 0x50 + iStack_18 * 4) = *(uint8_t *)(arg_2 + 6 + iStack_18 * 4);
    }
    *(int32_t *)(*(int *)((int)this + 0x18) + 0x20) = 0x100;
    iStack_8 = ICSendMessage(*(int32_t *)this,0x401d,*(int32_t *)((int)this + 0x18),0);
    if (iStack_8 != 0) {
      ICSendMessage(*(int32_t *)this,0x401d,0,0);
    }
  }
  return iStack_8 == 0;
}



int32_t thunk_FUN_1000735d(void)

{
  thunk_FUN_10004ea1(DAT_10010618);
  return 0;
}



int32_t __fastcall thunk_FUN_1000acaf(int32_t *ptr_1)

{
  int32_t uval_1;
  
  ptr_1[4] = 0;
  if (ptr_1[1] == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    ICSendMessage(*ptr_1,0x403f,0,0);
    if (ptr_1[0x5f] != 0) {
      if ((void *)ptr_1[0x5f] != (void *)0x0) {
        thunk_FUN_10004b70((void *)ptr_1[0x5f],1);
      }
    }
    if (DAT_100275d0 != 0) {
      DrawDibStop(ptr_1[2]);
      DrawDibEnd(ptr_1[2]);
    }
    if (ptr_1[0x6a] != 0) {
      SelectPalette((HDC)ptr_1[1],(HPALETTE)ptr_1[0x6a],0);
    }
    if (ptr_1[0x6b] != 0) {
      SelectPalette((HDC)ptr_1[0x68],(HPALETTE)ptr_1[0x6b],0);
    }
    if (ptr_1[99] != 0) {
      DeleteObject((HGDIOBJ)ptr_1[99]);
      ptr_1[99] = 0;
    }
    if (ptr_1[0x69] != 0) {
      SelectObject((HDC)ptr_1[0x68],(HGDIOBJ)ptr_1[0x69]);
    }
    if (ptr_1[0x68] != 0) {
      DeleteDC((HDC)ptr_1[0x68]);
    }
    ptr_1[1] = 0;
    uval_1 = 0;
  }
  return uval_1;
}



void __fastcall thunk_FUN_1000a2f1(int *ptr_1)

{
  thunk_FUN_1000a795(ptr_1);
  return;
}



void __cdecl thunk_FUN_10005c78(int arg1,int arg2)

{
  int *ptr_1;
  bool flag_1;
  undefined3 extraout_var;
  
  ptr_1 = *(int **)(arg1 + 8);
  flag_1 = thunk_FUN_10004c20((int)ptr_1);
  if (((CONCAT31(extraout_var,flag_1) != 0) && (ptr_1 != (int *)0x0)) && (*(int *)(arg1 + 0x38) == 0)
     ) {
    thunk_FUN_10007b00(ptr_1,arg2,-1);
    thunk_FUN_10007c85(ptr_1);
    thunk_FUN_10007bff(ptr_1);
  }
  return;
}



int32_t __cdecl PaintVid(int arg_1)

{
  int val_1;
  int *ptr_1;
  bool flag_2;
  int32_t uval_3;
  undefined3 extraout_var;
  
                    /* 0x10af  14  PaintVid */
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_3 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg_1 * 4);
    if (val_1 == 0) {
      uval_3 = 0;
    }
    else {
      ptr_1 = *(int **)(val_1 + 8);
      flag_2 = thunk_FUN_10004c20((int)ptr_1);
      if (CONCAT31(extraout_var,flag_2) == 0) {
        uval_3 = 1;
      }
      else {
        if (ptr_1 != (int *)0x0) {
          if (*(int *)(val_1 + 0x38) != 0) {
            return 0;
          }
          thunk_FUN_10007b00(ptr_1,*(int *)(val_1 + 0x1c),-1);
          thunk_FUN_10007c85(ptr_1);
          thunk_FUN_10007bff(ptr_1);
        }
        uval_3 = 0;
      }
    }
  }
  return uval_3;
}



int32_t __fastcall thunk_FUN_1000a795(int *ptr_1)

{
  if (ptr_1[5] != 0) {
    operator_delete((void *)ptr_1[5]);
  }
  if (ptr_1[6] != 0) {
    operator_delete((void *)ptr_1[6]);
  }
  ptr_1[6] = 0;
  ptr_1[5] = ptr_1[6];
  if (ptr_1[0x67] != 0) {
    free((void *)ptr_1[0x67]);
    ptr_1[0x67] = 0;
  }
  if (ptr_1[2] != 0) {
    DrawDibClose(ptr_1[2]);
    ptr_1[2] = 0;
  }
  if (*ptr_1 != 0) {
    ICClose(*ptr_1);
    *ptr_1 = 0;
  }
  if (ptr_1[0x5f] != 0) {
    ptr_1[0x5f] = 0;
  }
  if (ptr_1[0x60] != 0) {
    ptr_1[0x60] = 0;
  }
  *ptr_1 = 0;
  ptr_1[3] = 0;
  return 0;
}



void __fastcall thunk_FUN_10001926(int *ptr_1)

{
  thunk_FUN_10001c16(ptr_1);
  thunk_FUN_100019c7((int)ptr_1);
  AVIFileExit();
  return;
}



int32_t __fastcall thunk_FUN_10007c85(int *ptr_1)

{
  int32_t uval_1;
  DWORD DVar2;
  int val_3;
  int iStack_14;
  uint8_t auStack_10 [4];
  DWORD DStack_c;
  uint8_t auStack_8 [4];
  
  if (*ptr_1 == 0) {
    uval_1 = 0xffffffeb;
  }
  else {
    thunk_FUN_100051e4();
    if (ptr_1[0xd] < 0) {
      uval_1 = 0xffffffe9;
    }
    else {
      if (ptr_1[6] == 0) {
        if (ptr_1[0x16] < ptr_1[0x11]) {
          ptr_1[0x11] = ptr_1[0x16];
        }
        if (ptr_1[0x12] == ptr_1[0x11]) {
          thunk_FUN_100027a0((int)ptr_1);
        }
      }
      else {
        iStack_14 = thunk_FUN_100073d1();
        if (iStack_14 < 0) {
          DVar2 = timeGetTime();
          iStack_14 = (DVar2 - ptr_1[0xd]) + ptr_1[0xe];
        }
        val_3 = thunk_FUN_10007eaf(ptr_1,iStack_14);
        ptr_1[0x11] = val_3;
        if (ptr_1[0x16] < ptr_1[0x11]) {
          ptr_1[0x11] = ptr_1[0x16];
        }
        if (ptr_1[0x12] == ptr_1[0x11]) {
          thunk_FUN_100051e4();
          return 0;
        }
      }
      val_3 = thunk_FUN_10007f71(ptr_1);
      if (val_3 == 0) {
        uval_1 = 0;
      }
      else {
        DStack_c = AVIStreamRead(ptr_1[3],ptr_1[0x11],1,ptr_1[0x17],ptr_1[0x18],auStack_8,auStack_10
                                );
        if (DStack_c == 0) {
          thunk_FUN_100085b0(&DAT_1001bf60,s_vidsdraw__vcmDraw_m_pvBuf___rval_10010634);
          DStack_c = thunk_FUN_1000af14((void *)*ptr_1,ptr_1[0x17],0);
          if ((int)DStack_c < 2) {
            thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],DStack_c,0,0);
            thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
            ptr_1[0x12] = ptr_1[0x11];
            if (ptr_1[6] != 0) {
              ptr_1[0x10] = ptr_1[0x10] + (ptr_1[0x11] - ptr_1[0xf]) + -1;
              ptr_1[0xf] = ptr_1[0x11];
            }
            thunk_FUN_100051e4();
            uval_1 = 0;
          }
          else {
            thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],DStack_c,ptr_1[0xd],0);
            thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
            uval_1 = 0xffffffeb;
          }
        }
        else {
          uval_1 = 0xffffffe8;
        }
      }
    }
  }
  return uval_1;
}



void __thiscall thunk_FUN_1000b633(void *this,int *ptr_2)

{
  *(int *)((int)this + 0x4c) = *ptr_2;
  *(int *)((int)this + 0x50) = ptr_2[1];
  *(int *)((int)this + 0x54) = ptr_2[2] - *ptr_2;
  *(int *)((int)this + 0x58) = ptr_2[3] - ptr_2[1];
  return;
}



int __cdecl thunk_FUN_10004c90(int arg_1,int32_t arg_2,uint32_t arg_3)

{
  int val_1;
  FARPROC pFVar2;
  int iStack_c;
  
  if (DAT_10010584 == 0) {
    DAT_10032c44 = LoadLibraryA(PTR_s_magsnd_1001058c);
    if (DAT_10032c44 == (HMODULE)0x0) {
      val_1 = 4;
    }
    else {
      for (iStack_c = 0; iStack_c < 0x1b; iStack_c = iStack_c + 1) {
        pFVar2 = GetProcAddress(DAT_10032c44,(LPCSTR)(iStack_c + 1U & 0xffff));
        (&DAT_10032c70)[iStack_c] = pFVar2;
        if ((&DAT_10032c70)[iStack_c] == (code *)0x0) {
          FreeLibrary(DAT_10032c44);
          thunk_FUN_100054bc();
          return 4;
        }
      }
      if ((arg_1 == 0) && ((arg_3 & 2) == 0)) {
        FreeLibrary(DAT_10032c44);
        thunk_FUN_100054bc();
        val_1 = 5;
      }
      else {
        val_1 = (*DAT_10032c70)(arg_1,arg_2,arg_3);
        if (val_1 == 0) {
          DAT_10010588 = 1;
          if ((arg_3 & 2) != 0) {
            DAT_10010580 = 1;
          }
          DAT_10010584 = 1;
          val_1 = 0;
        }
        else {
          FreeLibrary(DAT_10032c44);
          thunk_FUN_100054bc();
        }
      }
    }
  }
  else {
    val_1 = 2;
  }
  return val_1;
}



DWORD __thiscall thunk_FUN_1000af14(void *this,int32_t arg_2,int32_t arg_3)

{
  DWORD DVar1;
  int32_t uval_2;
  BOOL BVar3;
  int val_4;
  int32_t uStack_14;
  
  if (*(int *)((int)this + 0x10) == 0) {
    DVar1 = 0;
  }
  else {
    if (DAT_100275d0 == 0) {
      uStack_14 = *(int32_t *)((int)this + 400);
    }
    else {
      uStack_14 = *(int32_t *)((int)this + 0x19c);
    }
    if ((*(int *)((int)this + 0x180) != 0) && (*(int *)((int)this + 0x188) != 0)) {
      (**(code **)(**(int **)((int)this + 0x180) + 0x18))
                (*(int32_t *)((int)this + 0x17c),*(int32_t *)((int)this + 0x16c),
                 *(int32_t *)((int)this + 0x170),*(int32_t *)((int)this + 0x174),
                 *(int32_t *)((int)this + 0x178),
                 *(int *)((int)this + 0x16c) + *(int *)((int)this + 0x3c),
                 *(int *)((int)this + 0x170) + *(int *)((int)this + 0x40));
    }
    DVar1 = FUN_1000b284(*(int32_t *)this,arg_3,*(int32_t *)((int)this + 0x14),arg_2,
                         *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                         *(int32_t *)((int)this + 0x18),uStack_14,0,0,
                         *(int32_t *)((int)this + 0x34),*(int32_t *)((int)this + 0x38));
    if (DVar1 == 0) {
      if ((*(int *)((int)this + 0x180) != 0) && (*(int *)((int)this + 0x188) != 0)) {
        memcpy((void *)((int)this + 0x16c),(void *)((int)this + 0x15c),0x10);
      }
      if (*(int *)((int)this + 0x184) != 0) {
        uval_2 = (**(code **)(**(int **)((int)this + 0x17c) + 0xc))(0,0);
        uval_2 = (**(code **)(**(int **)((int)this + 0x17c) + 8))(uval_2);
        (**(code **)(**(int **)((int)this + 0x184) + 0x18))
                  (*(int32_t *)((int)this + 0x17c),0,0,uval_2);
      }
      if (DAT_100275d0 == 0) {
        if ((*(int *)((int)this + 0x44) == *(int *)((int)this + 0x34)) &&
           (*(int *)((int)this + 0x48) == *(int *)((int)this + 0x38))) {
          BVar3 = BitBlt(*(HDC *)((int)this + 4),*(int *)((int)this + 0x4c),
                         *(int *)((int)this + 0x50),*(int *)((int)this + 0x54),
                         *(int *)((int)this + 0x58),*(HDC *)((int)this + 0x1a0),0,0,0xcc0020);
          if (BVar3 == 0) {
            DVar1 = GetLastError();
            return DVar1;
          }
        }
        else {
          BVar3 = StretchBlt(*(HDC *)((int)this + 4),*(int *)((int)this + 0x3c),
                             *(int *)((int)this + 0x40),*(int *)((int)this + 0x44),
                             *(int *)((int)this + 0x48),*(HDC *)((int)this + 0x1a0),
                             *(int *)((int)this + 0x2c),*(int *)((int)this + 0x30),
                             *(int *)((int)this + 0x34),*(int *)((int)this + 0x38),0xcc0020);
          if (BVar3 == 0) {
            DVar1 = GetLastError();
            return DVar1;
          }
        }
        GdiFlush();
      }
      else {
        val_4 = DrawDibDraw(*(int32_t *)((int)this + 8),*(int32_t *)((int)this + 4),
                            *(int32_t *)((int)this + 0x3c),*(int32_t *)((int)this + 0x40),
                            *(int32_t *)((int)this + 0x44),*(int32_t *)((int)this + 0x48),
                            *(int32_t *)((int)this + 0x18),uStack_14,0,0,
                            *(int32_t *)((int)this + 0x34),*(int32_t *)((int)this + 0x38),0);
        if (val_4 == 0) {
          return 0;
        }
      }
      DVar1 = 0;
    }
  }
  return DVar1;
}



void thunk_FUN_100054bc(void)

{
  int iStack_8;
  
  for (iStack_8 = 0; iStack_8 < 0x1b; iStack_8 = iStack_8 + 1) {
    (&DAT_10032c70)[iStack_8] = 0;
  }
  return;
}



int32_t __cdecl thunk_FUN_100052e9(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032cbc)(arg_1,arg_2);
  }
  return uval_1;
}



int16_t __fastcall thunk_FUN_1000a130(int arg_1)

{
  return *(int16_t *)(*(int *)(arg_1 + 4) + 0xe);
}



void __fastcall thunk_FUN_10004c60(int arg_1)

{
  *(int *)(arg_1 + 0x44) = *(int *)(arg_1 + 0x44) + 1;
  return;
}



int32_t __cdecl thunk_FUN_10005a5b(LPARAM *ptr_1,LPCSTR arg_2)

{
  void *this;
  bool flag_1;
  int32_t uval_2;
  HANDLE hFile;
  DWORD DVar3;
  undefined3 extraout_var;
  int val_4;
  
  if ((ptr_1 == (LPARAM *)0x0) || (ptr_1[2] == 0)) {
    uval_2 = 2;
  }
  else {
    this = (void *)ptr_1[2];
    hFile = (HANDLE)_lopen(arg_2,0);
    if (hFile == (HANDLE)0xffffffff) {
      uval_2 = 1;
    }
    else {
      DVar3 = GetFileSize(hFile,(LPDWORD)0x0);
      ptr_1[0x18] = DVar3;
      ptr_1[0x18] = (int)(ptr_1[0x18] + (ptr_1[0x18] >> 0x1f & 0x3ffU)) >> 10;
      _lclose((HFILE)hFile);
      flag_1 = thunk_FUN_10004c20((int)this);
      if (CONCAT31(extraout_var,flag_1) != 0) {
        thunk_FUN_10005b92(ptr_1);
      }
      val_4 = thunk_FUN_10001951(this,arg_2);
      if (val_4 == 0) {
        val_4 = thunk_FUN_10001a02(this,ptr_1[4],*ptr_1);
        if (val_4 == 0) {
          ptr_1[1] = ptr_1[1] | 1;
          PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
          InitializeCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
          uval_2 = 0;
        }
        else {
          uval_2 = 1;
        }
      }
      else {
        uval_2 = 1;
      }
    }
  }
  return uval_2;
}



int __thiscall CFontDialog::GetWeight(CFontDialog *this)

{
  return *(int *)(*(int *)(this + 4) + 8);
}



void __cdecl thunk_FUN_10005ce8(int arg1,int arg2)

{
  int *i_ptr_1;
  HPALETTE hPal;
  
  i_ptr_1 = *(int **)(arg1 + 8);
  if ((((i_ptr_1 != (int *)0x0) && (*i_ptr_1 != 0)) && (*(int *)(arg1 + 0x10) != arg2)) &&
     (*(int *)(*i_ptr_1 + 0x194) != 0)) {
    hPal = SelectPalette((HDC)i_ptr_1[0xc],*(HPALETTE *)(*i_ptr_1 + 0x194),0);
    RealizePalette((HDC)i_ptr_1[0xc]);
    if (hPal != (HPALETTE)0x0) {
      SelectPalette((HDC)i_ptr_1[0xc],hPal,0);
    }
  }
  return;
}



int32_t __cdecl SetVidPos(int arg1,short *arg2)

{
  int arg_1;
  int32_t uval_1;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int32_t *puStack_8;
  
                    /* 0x1113  15  SetVidPos */
  if ((arg1 < 0) || (2 < arg1)) {
    uval_1 = 2;
  }
  else {
    arg_1 = *(int *)(&DAT_10010868 + arg1 * 4);
    if (arg_1 == 0) {
      uval_1 = 0;
    }
    else {
      puStack_8 = *(int32_t **)(arg_1 + 8);
      if (puStack_8 == (int32_t *)0x0) {
        uval_1 = 2;
      }
      else if (*(int *)(arg_1 + 0x50) == 0) {
        uval_1 = 2;
      }
      else {
        thunk_FUN_100063e6(arg_1,(int)*arg2,(int)arg2[1]);
        iStack_18 = 0;
        iStack_14 = 0;
        iStack_10 = 0;
        iStack_c = 0;
        thunk_FUN_1000b4fb((void *)*puStack_8,&iStack_18);
        *arg2 = *arg2 + (short)*(int32_t *)(arg_1 + 0x58);
        arg2[1] = arg2[1] + (short)*(int32_t *)(arg_1 + 0x5c);
        iStack_18 = iStack_18 + *arg2;
        iStack_14 = iStack_14 + arg2[1];
        iStack_10 = iStack_10 + *arg2;
        iStack_c = iStack_c + arg2[1];
        thunk_FUN_1000b54e((void *)*puStack_8,&iStack_18);
        uval_1 = 0;
      }
    }
  }
  return uval_1;
}



int __thiscall thunk_FUN_1000743e(void *this,int arg_2)

{
  uint32_t uval_1;
  int val_2;
  uint32_t uval_3;
  int iStack_c;
  int iStack_8;
  
  iStack_8 = 0;
  while( true ) {
    if ((arg_2 <= iStack_8) || (*(int *)((int)this + 0x80) < *(int *)((int)this + 0x98))) {
      *(int *)((int)this + 0x98) = *(int *)((int)this + 0x98) + iStack_8;
      return iStack_8;
    }
    val_2 = AVIStreamRead(*(int32_t *)((int)this + 0x10),
                          (*(int *)((int)this + 0x98) + iStack_8) * *(int *)((int)this + 0x94),
                          *(int32_t *)((int)this + 0x94),
                          **(int32_t **)((int)this + *(int *)((int)this + 0x11c) * 4 + 0x9c),
                          *(int *)((int)this + 0x90) * *(int *)((int)this + 0x94),&iStack_c,0);
    if (val_2 != 0) {
      return iStack_8;
    }
    if (*(int *)((int)this + 0x90) * *(int *)((int)this + 0x94) - iStack_c != 0) break;
    *(int *)((int)this + 0x11c) = *(int *)((int)this + 0x11c) + 1;
    uval_1 = *(uint32_t *)((int)this + 0x11c);
    uval_3 = (int)uval_1 >> 0x1f;
    *(uint32_t *)((int)this + 0x11c) = ((uval_1 ^ uval_3) - uval_3 & 0x1f ^ uval_3) - uval_3;
    iStack_8 = iStack_8 + 1;
  }
  return iStack_8;
}



int32_t __cdecl SetVidBackground(int arg1,int arg2)

{
  LPARAM *ptr_1;
  int32_t uval_1;
  
                    /* 0x111d  8  SetVidBackground */
  if ((arg2 < 0) || (2 < arg2)) {
    uval_1 = 2;
  }
  else {
    ptr_1 = *(LPARAM **)(&DAT_10010868 + arg2 * 4);
    if (ptr_1 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      thunk_FUN_100065fe(ptr_1,arg1);
      thunk_FUN_10006467(ptr_1);
      thunk_FUN_10006a43(ptr_1);
      uval_1 = 0;
    }
  }
  return uval_1;
}



int32_t * __fastcall thunk_FUN_1000a250(int32_t *ptr_1)

{
  memset(ptr_1,0,0x1b0);
  ptr_1[4] = 0;
  ptr_1[5] = 0;
  ptr_1[6] = 0;
  ptr_1[100] = 0;
  ptr_1[0x67] = 0;
  ptr_1[0x62] = 0;
  ptr_1[0x5f] = 0;
  ptr_1[0x60] = 0;
  ptr_1[0x61] = 0;
  *ptr_1 = 0;
  return ptr_1;
}



void thunk_FUN_10005fee(void)

{
  return;
}



void __cdecl thunk_FUN_10005b92(LPARAM *ptr_1)

{
  int *ptr_1_00;
  bool flag_1;
  undefined3 extraout_var;
  
  if ((ptr_1 != (LPARAM *)0x0) && (ptr_1[2] != 0)) {
    ptr_1_00 = (int *)ptr_1[2];
    if (ptr_1_00 != (int *)0x0) {
      flag_1 = thunk_FUN_10004c20((int)ptr_1_00);
      if (CONCAT31(extraout_var,flag_1) == 0) {
        return;
      }
      if (((uint32_t)ptr_1[1] >> 1 & 1) != 0) {
        thunk_FUN_10005ef9((int)ptr_1);
      }
      if (ptr_1[0x10] != 0) {
        ptr_1[0x12] = 0;
        ptr_1[0x10] = 0;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
      thunk_FUN_10001c16(ptr_1_00);
      thunk_FUN_100019c7((int)ptr_1_00);
      LeaveCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
    PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
  }
  return;
}



int32_t __cdecl UnloadAVI(int arg_1)

{
  LPARAM *ptr_1;
  void *this;
  int32_t uval_1;
  
                    /* 0x1131  4  UnloadAVI */
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else {
    ptr_1 = *(LPARAM **)(&DAT_10010868 + arg_1 * 4);
    if (ptr_1 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      if (ptr_1[0x13] != 0) {
        StopAVI(arg_1);
      }
      this = (void *)ptr_1[2];
      if ((((uint32_t)ptr_1[1] >> 3 & 1) != 0) && (ptr_1[0x1a] != 0)) {
        ptr_1[0x12] = 0;
      }
      if (((*(uint8_t *)(ptr_1 + 1) & 1) != 0) && (this != (void *)0x0)) {
        thunk_FUN_10005b92(ptr_1);
        ptr_1[1] = ptr_1[1] & 0xfffffffe;
      }
      if (ptr_1[7] != 0) {
        ReleaseDC((HWND)ptr_1[4],(HDC)ptr_1[7]);
        if (ptr_1[0x19] != 0) {
          *(int32_t *)(ptr_1[0x19] + 0x1c) = 0;
        }
        ptr_1[0x19] = 0;
      }
      if ((ptr_1[4] != 0) && (ptr_1[5] != 0)) {
        DestroyWindow((HWND)ptr_1[4]);
        ptr_1[4] = 0;
        if (ptr_1[0x19] != 0) {
          *(int32_t *)(ptr_1[0x19] + 0x10) = 0;
        }
        ptr_1[5] = 0;
      }
      if (this != (void *)0x0) {
        if (this != (void *)0x0) {
          thunk_FUN_10004b20(this,1);
        }
      }
      if ((ptr_1[0x15] != 0) && (ptr_1[0x14] != 0)) {
        if ((void *)ptr_1[0x14] != (void *)0x0) {
          thunk_FUN_10004b70((void *)ptr_1[0x14],1);
        }
      }
      DAT_1001053c = ptr_1[6];
      operator_delete(ptr_1);
      *(int32_t *)(&DAT_10010868 + arg_1 * 4) = 0;
      uval_1 = 0;
    }
  }
  return uval_1;
}



bool __thiscall thunk_FUN_1000bd47(void *this,int arg_2)

{
  int val_1;
  bool flag_2;
  
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *(int32_t *)((int)this + 0x70) = 0x80000008;
    *(int32_t *)((int)this + 0x68) = 4;
    if (arg_2 == 1) {
      *(int32_t *)((int)this + 0x84) = 0;
    }
    else {
      *(int32_t *)((int)this + 0x84) = 1;
    }
    val_1 = ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0x5c,
                          *(int32_t *)((int)this + 0x5c));
    flag_2 = val_1 == 0;
  }
  else {
    flag_2 = false;
  }
  return flag_2;
}



int32_t __thiscall thunk_FUN_1000bc86(void *this,int *ptr_2)

{
  int val_1;
  
  if (((*(int *)((int)this + 0xc) != 0x31347669) ||
      (val_1 = (**(code **)(*ptr_2 + 8))(), val_1 < *(int *)((int)this + 0x44))) ||
     (val_1 = (**(code **)(*ptr_2 + 0xc))(), val_1 < *(int *)((int)this + 0x48))) {
    return 0;
  }
  if ((*(int *)((int)this + 0x184) != 0) && (*(void **)((int)this + 0x180) != (void *)0x0)) {
    thunk_FUN_10004b70(*(void **)((int)this + 0x180),1);
  }
  if (ptr_2 != (int *)0x0) {
    *(int **)((int)this + 0x184) = ptr_2;
    return 1;
  }
  return 0;
}



void __thiscall thunk_FUN_1000b54e(void *this,int *ptr_2)

{
  *(int *)((int)this + 0x3c) = *ptr_2;
  *(int *)((int)this + 0x40) = ptr_2[1];
  *(int *)((int)this + 0x44) = ptr_2[2] - *ptr_2;
  *(int *)((int)this + 0x48) = ptr_2[3] - ptr_2[1];
  if (*(int *)((int)this + 0x180) == 0) {
    *(int32_t *)((int)this + 0x4c) = *(int32_t *)((int)this + 0x3c);
    *(int32_t *)((int)this + 0x50) = *(int32_t *)((int)this + 0x40);
    *(int32_t *)((int)this + 0x54) = *(int32_t *)((int)this + 0x44);
    *(int32_t *)((int)this + 0x58) = *(int32_t *)((int)this + 0x48);
  }
  return;
}



int32_t __fastcall thunk_FUN_1000aea5(int32_t *ptr_1)

{
  ICSendMessage(*ptr_1,0x4013,0,0);
  ICSendMessage(*ptr_1,0x4015,0,0);
  return 0;
}



int32_t __fastcall thunk_FUN_100019c7(int arg_1)

{
  if (*(int *)(arg_1 + 8) != 0) {
    AVIFileRelease(*(int32_t *)(arg_1 + 8));
    *(int32_t *)(arg_1 + 8) = 0;
  }
  return 0;
}



void __thiscall thunk_FUN_1000b4fb(void *this,int32_t *ptr_2)

{
  *ptr_2 = *(int32_t *)((int)this + 0x3c);
  ptr_2[1] = *(int32_t *)((int)this + 0x40);
  ptr_2[2] = *(int *)((int)this + 0x3c) + *(int *)((int)this + 0x44);
  ptr_2[3] = *(int *)((int)this + 0x48) + *(int *)((int)this + 0x40);
  return;
}



int32_t __cdecl LinkVids(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
                    /* 0x1159  17  LinkVids */
  if ((arg1 < 0) || (2 < arg1)) {
    uval_2 = 2;
  }
  else if ((arg2 < 0) || (2 < arg2)) {
    uval_2 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg1 * 4) == 0) {
    uval_2 = 5;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg2 * 4);
    if (val_1 == 0) {
      uval_2 = 5;
    }
    else {
      *(int *)(*(int *)(&DAT_10010868 + arg1 * 4) + 100) = val_1;
      *(int32_t *)(val_1 + 0x68) = 1;
      uval_2 = 0;
    }
  }
  return uval_2;
}



int32_t __thiscall
thunk_FUN_10001f9d(void *this,float arg_2,uint32_t arg_3,int arg_4,int arg_5,int arg_6)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  undefined3 extraout_var;
  uint8_t auStack_74 [4];
  int iStack_70;
  int iStack_6c;
  uint8_t auStack_4c [4];
  int iStack_48;
  int iStack_44;
  uint16_t uStack_3e;
  int iStack_38;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_2 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    thunk_FUN_1000b6ff(*(void **)this,auStack_74);
    thunk_FUN_1000b759(*(void **)this,auStack_4c);
    thunk_FUN_1000b3b1(*(void **)this,&iStack_24);
    thunk_FUN_1000b456(*(void **)this,&iStack_14);
    if (arg_3 == 0) {
      arg_3 = (uint32_t)uStack_3e;
    }
    if ((((arg_3 == 8) || (arg_3 == 0x10)) || (arg_3 == 0x18)) || (arg_3 == 0x20)) {
      if (0.0 < arg_2) {
        arg_5 = ftol();
        arg_6 = ftol();
      }
      uStack_3e = (uint16_t)arg_3;
      iStack_48 = arg_5;
      iStack_44 = arg_6;
      val_3 = ((int)(arg_6 + 3 + (arg_6 + 3 >> 0x1f & 3U)) >> 2) * arg_5 * arg_3 * 4;
      iStack_38 = (int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3;
      iStack_14 = iStack_24;
      iStack_c = iStack_24 + arg_5;
      iStack_10 = iStack_20;
      iStack_8 = iStack_20 + arg_6;
      val_3 = thunk_FUN_1000b83e(*(void **)this,(int)auStack_4c,iStack_24,iStack_20,
                                 iStack_c + iStack_24,iStack_20 + iStack_8);
      if (val_3 == 0) {
        thunk_FUN_1000b786(*(void **)this,auStack_4c);
        thunk_FUN_1000b4a9(*(void **)this,&iStack_14);
        thunk_FUN_1000b54e(*(void **)this,&iStack_14);
        if ((arg_4 != 0) &&
           (flag_1 = thunk_FUN_1000bd47(*(void **)this,arg_4), CONCAT31(extraout_var,flag_1) == 0)) {
          return 0xfffffffb;
        }
      }
      else {
        iStack_48 = iStack_70;
        iStack_44 = iStack_6c;
        val_3 = ((int)(iStack_6c + 3 + (iStack_6c + 3 >> 0x1f & 3U)) >> 2) * iStack_70 * arg_3 * 4;
        iStack_38 = (int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3;
        val_3 = thunk_FUN_1000b83e(*(void **)this,(int)auStack_4c,iStack_24,iStack_20,
                                   iStack_1c + iStack_24,iStack_20 + iStack_18);
        if (val_3 != 0) {
          return 0xfffffffb;
        }
        thunk_FUN_1000b786(*(void **)this,auStack_4c);
        thunk_FUN_1000b4a9(*(void **)this,&iStack_24);
        thunk_FUN_1000b54e(*(void **)this,&iStack_14);
      }
      thunk_FUN_100027a0((int)this);
      uval_2 = 0;
    }
    else {
      uval_2 = 0xfffffffb;
    }
  }
  else {
    uval_2 = 0xfffffffc;
  }
  return uval_2;
}



int32_t __cdecl SetVidBackgroundToBMP(int *ptr_1,int32_t arg_2,int arg_3)

{
  LPARAM *ptr_1_00;
  int32_t uval_1;
  int val_2;
  CPrintPreviewState *this;
  int32_t *unaff_FS_OFFSET;
  LPARAM LStack_20;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
                    /* 0x1163  9  SetVidBackgroundToBMP */
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_100032d7;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if ((arg_3 < 0) || (2 < arg_3)) {
    uval_1 = 2;
  }
  else {
    ptr_1_00 = *(LPARAM **)(&DAT_10010868 + arg_3 * 4);
    if (ptr_1_00 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      if (ptr_1[2] < 0) {
        val_2 = abs(ptr_1[2]);
        ptr_1[2] = val_2;
      }
      this = operator_new(0x18);
      uStack_8 = 0;
      if (this == (CPrintPreviewState *)0x0) {
        LStack_20 = 0;
      }
      else {
        LStack_20 = CPrintPreviewState::CPrintPreviewState(this);
      }
      uStack_8 = 0xffffffff;
      ptr_1_00[0x14] = LStack_20;
      thunk_FUN_100089e8((void *)ptr_1_00[0x14],ptr_1,arg_2);
      thunk_FUN_100066d7(ptr_1_00);
      thunk_FUN_10006a43(ptr_1_00);
      uval_1 = 0;
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return uval_1;
}



int __thiscall thunk_FUN_1000a8d3(void *this,int arg_2)

{
  int val_1;
  HDC pHVar2;
  CPrintPreviewState *this_00;
  int32_t uval_3;
  int32_t *unaff_FS_OFFSET;
  int32_t uStack_24;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_1000aba6;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if ((*(int *)this == 0) || (arg_2 == 0)) {
    val_1 = -1;
  }
  else {
    *(int *)((int)this + 4) = arg_2;
    pHVar2 = CreateCompatibleDC(*(HDC *)((int)this + 4));
    *(HDC *)((int)this + 0x1a0) = pHVar2;
    val_1 = FUN_1000ac38(*(int32_t *)this,0,*(int32_t *)((int)this + 0x14),0,
                         *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                         *(int32_t *)((int)this + 0x18),0,*(int32_t *)((int)this + 0x2c),
                         *(int32_t *)((int)this + 0x30),*(int32_t *)((int)this + 0x34),
                         *(int32_t *)((int)this + 0x38));
    if (val_1 == 0) {
      DAT_100275d0 = 1;
      FUN_1000abc1(*(int32_t *)this,0,*(int32_t *)((int)this + 0x14),0,
                   *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                   *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                   *(int32_t *)((int)this + 0x18),0,*(int32_t *)((int)this + 0x2c),
                   *(int32_t *)((int)this + 0x30),*(int32_t *)((int)this + 0x34),
                   *(int32_t *)((int)this + 0x38));
      if (*(int *)((int)this + 0x180) != 0) {
        this_00 = operator_new(0x18);
        uStack_8 = 0;
        if (this_00 == (CPrintPreviewState *)0x0) {
          uStack_24 = 0;
        }
        else {
          uStack_24 = CPrintPreviewState::CPrintPreviewState(this_00);
        }
        uStack_8 = 0xffffffff;
        *(int32_t *)((int)this + 0x17c) = uStack_24;
        if ((*(int *)((int)this + 0x17c) == 0) || (DAT_100275d0 == 0)) {
          if (*(int *)((int)this + 0x17c) != 0) {
            thunk_FUN_100089e8(*(void **)((int)this + 0x17c),*(int **)((int)this + 0x18),
                               *(int32_t *)((int)this + 400));
          }
        }
        else {
          thunk_FUN_100089e8(*(void **)((int)this + 0x17c),*(int **)((int)this + 0x18),
                             *(int32_t *)((int)this + 0x19c));
        }
        (**(code **)(**(int **)((int)this + 0x180) + 0x18))
                  (*(int32_t *)((int)this + 0x17c),0,0,*(int32_t *)((int)this + 0x34),
                   *(int32_t *)((int)this + 0x38),*(int32_t *)((int)this + 0x3c),
                   *(int32_t *)((int)this + 0x40));
      }
      if (DAT_100275d0 != 0) {
        DrawDibBegin(*(int32_t *)((int)this + 8),0,*(int32_t *)((int)this + 0x44),
                     *(int32_t *)((int)this + 0x48),*(int32_t *)((int)this + 0x18),
                     *(int32_t *)((int)this + 0x34),*(int32_t *)((int)this + 0x38),0);
        uval_3 = ftol();
        DrawDibStart(*(int32_t *)((int)this + 8),uval_3);
      }
      SetStretchBltMode(*(HDC *)((int)this + 4),3);
      *(int32_t *)((int)this + 0x10) = 1;
      val_1 = 0;
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return val_1;
}



int __thiscall CFontDialog::GetWeight(CFontDialog *this)

{
  return *(int *)(*(int *)(this + 4) + 4);
}



void __thiscall thunk_FUN_1000b6ff(void *this,void *ptr_2)

{
  memcpy(ptr_2,*(void **)((int)this + 0x14),0x28);
  return;
}



int32_t thunk_FUN_100053fa(void)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_10032cd0)();
  }
  return uval_1;
}



void __fastcall thunk_FUN_1000a1b0(int arg_1)

{
  if (*(int *)(arg_1 + 0x10) != 0) {
    operator_delete(*(void **)(arg_1 + 0x10));
  }
  return;
}



int32_t __fastcall thunk_FUN_10004bf0(int arg_1)

{
  return *(int32_t *)(arg_1 + 8);
}



void __cdecl thunk_FUN_100059e8(int arg_1)

{
  if (*(int *)(arg_1 + 0x40) != 0) {
    *(int32_t *)(arg_1 + 0x48) = 0;
    *(int32_t *)(arg_1 + 0x40) = 0;
  }
  if (*(int *)(arg_1 + 8) != 0) {
    if (*(void **)(arg_1 + 8) != (void *)0x0) {
      thunk_FUN_10004b20(*(void **)(arg_1 + 8),1);
    }
    *(int32_t *)(arg_1 + 8) = 0;
  }
  return;
}



void __thiscall thunk_FUN_1000b3b1(void *this,int32_t *ptr_2)

{
  *ptr_2 = *(int32_t *)((int)this + 0x1c);
  ptr_2[1] = *(int32_t *)((int)this + 0x20);
  ptr_2[2] = *(int *)((int)this + 0x24) + *(int *)((int)this + 0x1c);
  ptr_2[3] = *(int *)((int)this + 0x28) + *(int *)((int)this + 0x20);
  return;
}



void __thiscall thunk_FUN_1000b786(void *this,void *ptr_2)

{
  int val_1;
  void *buf_ptr_2;
  
  if (*(int *)((int)this + 0x180) == 0) {
    memcpy(*(void **)((int)this + 0x18),ptr_2,0x28);
    if (*(uint32_t *)((int)this + 0x198) < *(uint32_t *)((int)ptr_2 + 0x14)) {
      val_1 = *(int *)(*(int *)((int)this + 0x18) + 4) + 3;
      val_1 = ((int)(val_1 + (val_1 >> 0x1f & 3U)) >> 2) *
              (uint32_t)*(uint16_t *)(*(int *)((int)this + 0x18) + 0xe) * *(int *)((int)ptr_2 + 8) * 4;
      *(int *)((int)this + 0x198) = (int)(val_1 + (val_1 >> 0x1f & 7U)) >> 3;
      buf_ptr_2 = realloc(*(void **)((int)this + 0x19c),*(size_t *)((int)this + 0x198));
      *(void **)((int)this + 0x19c) = buf_ptr_2;
    }
  }
  return;
}



int32_t __thiscall thunk_FUN_10007b00(void *this,int arg_2,int arg_3)

{
  int32_t uval_1;
  int val_2;
  DWORD DVar3;
  
  if (*(int *)this == 0) {
    uval_1 = 0xffffffeb;
  }
  else if (arg_2 == 0) {
    uval_1 = 0xffffffea;
  }
  else {
    *(int *)((int)this + 0x30) = arg_2;
    if (-1 < arg_3) {
      *(int *)((int)this + 0x44) = arg_3;
    }
    val_2 = thunk_FUN_1000a8d3(*(void **)this,arg_2);
    if (val_2 == 0) {
      if (*(int *)((int)this + 0x18) != 0) {
        thunk_FUN_1000ae35(*(int32_t **)this);
      }
      DVar3 = timeGetTime();
      *(DWORD *)((int)this + 0x34) = DVar3;
      uval_1 = AVIStreamSampleToTime
                        (*(int32_t *)((int)this + 0xc),*(int32_t *)((int)this + 0x44));
      *(int32_t *)((int)this + 0x38) = uval_1;
      *(int32_t *)((int)this + 0x3c) = *(int32_t *)((int)this + 0x44);
      uval_1 = 0;
    }
    else {
      thunk_FUN_10007bff(this);
      uval_1 = 0xffffffeb;
    }
  }
  return uval_1;
}



void __cdecl thunk_FUN_100063e6(int arg_1,int arg_2,int arg_3)

{
  int32_t *arg_1_00;
  bool flag_1;
  undefined3 extraout_var;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if ((arg_1 != 0) && (*(int *)(arg_1 + 8) != 0)) {
    arg_1_00 = *(int32_t **)(arg_1 + 8);
    flag_1 = thunk_FUN_10004c20((int)arg_1_00);
    if (CONCAT31(extraout_var,flag_1) != 0) {
      thunk_FUN_1000b456((void *)*arg_1_00,&iStack_14);
      iStack_10 = iStack_10 + arg_3;
      iStack_8 = iStack_8 + arg_3;
      iStack_c = iStack_c + arg_2;
      iStack_14 = iStack_14 + arg_2;
      thunk_FUN_1000b4a9((void *)*arg_1_00,&iStack_14);
    }
  }
  return;
}



void __fastcall thunk_FUN_10008774(int32_t *ptr_1)

{
  *ptr_1 = &PTR_LAB_1000f060;
  if (ptr_1[1] != 0) {
    free((void *)ptr_1[1]);
  }
  if ((ptr_1[3] != 0) && (ptr_1[2] != 0)) {
    free((void *)ptr_1[2]);
  }
  if (ptr_1[4] != 0) {
    operator_delete((void *)ptr_1[4]);
  }
  return;
}



void __thiscall thunk_FUN_1000b5e0(void *this,int32_t *ptr_2)

{
  *ptr_2 = *(int32_t *)((int)this + 0x4c);
  ptr_2[1] = *(int32_t *)((int)this + 0x50);
  ptr_2[2] = *(int *)((int)this + 0x4c) + *(int *)((int)this + 0x54);
  ptr_2[3] = *(int *)((int)this + 0x50) + *(int *)((int)this + 0x58);
  return;
}



int32_t __thiscall thunk_FUN_1000bbec(void *this,int arg_2)

{
  int32_t uval_1;
  
  if (*(int *)((int)this + 0x180) == 0) {
    uval_1 = 1;
  }
  else {
    if (arg_2 == 1) {
      *(int32_t *)((int)this + 0x80) = 0;
      *(int32_t *)((int)this + 0x188) = 1;
    }
    else {
      *(int32_t *)((int)this + 0x80) = 0;
      *(int32_t *)((int)this + 0x188) = 0;
    }
    *(int32_t *)((int)this + 0x70) = 0x80000004;
    ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0x5c,0x2c);
    uval_1 = 0;
  }
  return uval_1;
}



int32_t __thiscall thunk_FUN_1000bac7(void *this,int *ptr_2)

{
  int val_1;
  int32_t uval_2;
  
  if (((*(int *)((int)this + 0xc) != 0x31347669) ||
      (val_1 = (**(code **)(*ptr_2 + 8))(), val_1 < *(int *)((int)this + 0x44))) ||
     (val_1 = (**(code **)(*ptr_2 + 0xc))(), val_1 < *(int *)((int)this + 0x48))) {
    return 0;
  }
  if ((*(int *)((int)this + 0x180) != 0) && (*(void **)((int)this + 0x180) != (void *)0x0)) {
    thunk_FUN_10004b70(*(void **)((int)this + 0x180),1);
  }
  if (ptr_2 != (int *)0x0) {
    *(int **)((int)this + 0x180) = ptr_2;
    *(int32_t *)((int)this + 0x50) = 0;
    *(int32_t *)((int)this + 0x4c) = *(int32_t *)((int)this + 0x50);
    uval_2 = (**(code **)(**(int **)((int)this + 0x180) + 8))();
    *(int32_t *)((int)this + 0x54) = uval_2;
    uval_2 = (**(code **)(**(int **)((int)this + 0x180) + 0xc))();
    *(int32_t *)((int)this + 0x58) = uval_2;
    *(int32_t *)((int)this + 0x2c) = 0;
    *(int32_t *)((int)this + 0x30) = 0;
    return 1;
  }
  return 0;
}



int32_t thunk_FUN_10007383(void)

{
  thunk_FUN_10004f90(DAT_10010618);
  return 0;
}



int32_t __fastcall thunk_FUN_1000785e(int *ptr_1)

{
  int32_t uval_1;
  int32_t *ptr_1_00;
  int val_2;
  void *buf_ptr_3;
  int32_t *unaff_FS_OFFSET;
  int32_t *puStack_d4;
  uint8_t auStack_cc [4];
  int iStack_c8;
  int iStack_b0;
  int iStack_ac;
  int iStack_a4;
  int32_t uStack_40;
  uint8_t auStack_3c [40];
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10007a6c;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if (ptr_1[3] == 0) {
    uval_1 = 0xffffffec;
  }
  else {
    if (*ptr_1 != 0) {
      thunk_FUN_10007a85(ptr_1);
    }
    ptr_1[0xd] = -1;
    AVIStreamInfoA(ptr_1[3],auStack_cc,0x8c);
    ptr_1[0x11] = iStack_b0;
    ptr_1[0x15] = ptr_1[0x11];
    ptr_1[0x16] = iStack_b0 + iStack_ac + -1;
    ptr_1[0x12] = ptr_1[0x11] + -1;
    AVIStreamReadFormat(ptr_1[3],0,0,&iStack_14);
    if (iStack_14 == 0x28) {
      uStack_40 = AVIStreamReadFormat(ptr_1[3],0,auStack_3c,&iStack_14);
      ptr_1_00 = operator_new(0x1b0);
      uStack_8 = 0;
      if (ptr_1_00 == (int32_t *)0x0) {
        puStack_d4 = (int32_t *)0x0;
      }
      else {
        puStack_d4 = thunk_FUN_1000a250(ptr_1_00);
      }
      uStack_8 = 0xffffffff;
      *ptr_1 = (int)puStack_d4;
      val_2 = thunk_FUN_1000a30f((void *)*ptr_1,iStack_c8,auStack_3c);
      if (val_2 == 0) {
        ptr_1[0x18] = iStack_a4;
        buf_ptr_3 = malloc(ptr_1[0x18]);
        ptr_1[0x17] = (int)buf_ptr_3;
        if (ptr_1[0x17] == 0) {
          uval_1 = 3;
        }
        else {
          ptr_1[0x10] = 0;
          uval_1 = 0;
        }
      }
      else {
        thunk_FUN_10007a85(ptr_1);
        uval_1 = 0xffffffeb;
      }
    }
    else {
      uval_1 = 0xffffffff;
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return uval_1;
}



int32_t __cdecl thunk_FUN_100065fe(LPARAM *ptr_1,int arg_2)

{
  void *this;
  int val_1;
  bool flag_2;
  int32_t uval_3;
  undefined3 extraout_var;
  
  if ((ptr_1 == (LPARAM *)0x0) || (ptr_1[2] == 0)) {
    uval_3 = 2;
  }
  else {
    this = (void *)ptr_1[2];
    flag_2 = thunk_FUN_10004c20((int)this);
    if (CONCAT31(extraout_var,flag_2) == 0) {
      uval_3 = 1;
    }
    else if (arg_2 == 0) {
      uval_3 = 1;
    }
    else {
      val_1 = ptr_1[0xe];
      if (val_1 != 0) {
        thunk_FUN_10005ef9((int)ptr_1);
      }
      thunk_FUN_10002289(this,arg_2);
      if (val_1 != 0) {
        thunk_FUN_10005d8d(ptr_1);
      }
      PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
      uval_3 = 0;
    }
  }
  return uval_3;
}



int32_t __cdecl thunk_FUN_100066d7(LPARAM *ptr_1)

{
  void *this;
  int arg_2;
  int val_1;
  bool flag_2;
  int32_t uval_3;
  undefined3 extraout_var;
  
  if ((ptr_1 == (LPARAM *)0x0) || (ptr_1[2] == 0)) {
    uval_3 = 2;
  }
  else {
    this = (void *)ptr_1[2];
    arg_2 = ptr_1[0x14];
    if (arg_2 == 0) {
      uval_3 = 2;
    }
    else {
      flag_2 = thunk_FUN_10004c20((int)this);
      if (CONCAT31(extraout_var,flag_2) == 0) {
        uval_3 = 1;
      }
      else {
        val_1 = ptr_1[0xe];
        if (val_1 != 0) {
          thunk_FUN_10005ef9((int)ptr_1);
        }
        thunk_FUN_100023d1(this,arg_2);
        if (val_1 != 0) {
          thunk_FUN_10005d8d(ptr_1);
        }
        PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
        uval_3 = 0;
      }
    }
  }
  return uval_3;
}



void __thiscall thunk_FUN_1000b759(void *this,void *ptr_2)

{
  memcpy(ptr_2,*(void **)((int)this + 0x18),0x28);
  return;
}



int __fastcall thunk_FUN_10007080(int arg_1)

{
  int val_1;
  
  if (*(uint16_t *)(*(int *)(arg_1 + 4) + 0xe) < 9) {
    val_1 = *(int *)(arg_1 + 4) + 0x28;
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



int32_t __cdecl SetVidBackgroundToDIB(int *ptr_1,int arg_2)

{
  LPARAM *ptr_1_00;
  int32_t uval_1;
  tagRECT tStack_28;
  int32_t uStack_18;
  int32_t uStack_14;
  int iStack_10;
  int iStack_c;
  LPARAM LStack_8;
  
                    /* 0x11f4  10  SetVidBackgroundToDIB */
  if ((arg_2 < 0) || (2 < arg_2)) {
    uval_1 = 2;
  }
  else {
    ptr_1_00 = *(LPARAM **)(&DAT_10010868 + arg_2 * 4);
    if (ptr_1_00 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      LStack_8 = ptr_1_00[2];
      ptr_1_00[0x14] = (LPARAM)ptr_1;
      ptr_1_00[0x15] = 0;
      thunk_FUN_100066d7(ptr_1_00);
      tStack_28.left = 0;
      tStack_28.top = 0;
      tStack_28.right = 0;
      tStack_28.bottom = 0;
      uStack_18 = 0;
      uStack_14 = 0;
      iStack_10 = 0;
      iStack_c = 0;
      GetWindowRect((HWND)ptr_1_00[4],&tStack_28);
      (**(code **)(*ptr_1 + 0x14))(&uStack_18);
      if (iStack_10 < tStack_28.right) {
        ptr_1_00[0x16] = (tStack_28.right - iStack_10) / 2;
      }
      if (iStack_c < tStack_28.bottom) {
        ptr_1_00[0x17] = (tStack_28.bottom - iStack_c) / 2;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



void __thiscall thunk_FUN_1000a160(void *this,int32_t arg_2)

{
  void *buf_ptr_1;
  
  buf_ptr_1 = operator_new(4);
  *(void **)((int)this + 0x10) = buf_ptr_1;
  if (*(int *)((int)this + 0x10) != 0) {
    **(int32_t **)((int)this + 0x10) = arg_2;
  }
  return;
}



int32_t __fastcall thunk_FUN_1000715a(int arg_1)

{
  int32_t uval_1;
  uint8_t auStack_90 [28];
  int iStack_74;
  uint32_t uStack_70;
  int32_t uStack_6c;
  int iStack_68;
  int iStack_60;
  
  *(int32_t *)(arg_1 + 0x78) = 0xffffffff;
  if (*(int *)(arg_1 + 0x10) == 0) {
    uval_1 = 0xfffffff3;
  }
  else {
    AVIStreamInfoA(*(int32_t *)(arg_1 + 0x10),auStack_90,0x8c);
    *(int *)(arg_1 + 0x94) = iStack_68 * iStack_60;
    *(int *)(arg_1 + 0x90) = iStack_60;
    *(int *)(arg_1 + 0x7c) = iStack_74;
    *(uint32_t *)(arg_1 + 0x80) = iStack_74 + uStack_70 / *(uint32_t *)(arg_1 + 0x94);
    *(int32_t *)(arg_1 + 0x84) = uStack_6c;
    if (*(int *)(arg_1 + 0x84) < 0x20) {
      uval_1 = 0;
    }
    else {
      uval_1 = 0xfffffff5;
    }
  }
  return uval_1;
}



int32_t * __fastcall thunk_FUN_10001740(int32_t *ptr_1)

{
  int iStack_8;
  
  *ptr_1 = 0;
  ptr_1[1] = 0;
  ptr_1[2] = 0;
  ptr_1[3] = 0;
  ptr_1[4] = 0;
  ptr_1[5] = 0;
  ptr_1[6] = 0;
  ptr_1[7] = 0;
  ptr_1[8] = 0;
  ptr_1[9] = 0;
  ptr_1[10] = 0;
  ptr_1[0xb] = 0;
  ptr_1[0xc] = 0;
  ptr_1[0xd] = 0;
  ptr_1[0xe] = 0;
  ptr_1[0xf] = 0;
  ptr_1[0x10] = 0;
  ptr_1[0x11] = 0;
  ptr_1[0x12] = 0;
  ptr_1[0x13] = 0;
  ptr_1[0x14] = 0;
  ptr_1[0x15] = 0;
  ptr_1[0x16] = 0;
  ptr_1[0x17] = 0;
  ptr_1[0x18] = 0;
  ptr_1[0x1d] = 0;
  ptr_1[0x1e] = 0;
  ptr_1[0x1f] = 0;
  ptr_1[0x20] = 0;
  ptr_1[0x21] = 0;
  ptr_1[0x22] = 0;
  ptr_1[0x23] = 0;
  ptr_1[0x24] = 0;
  ptr_1[0x25] = 0;
  ptr_1[0x26] = 0;
  for (iStack_8 = 0; iStack_8 < 0x20; iStack_8 = iStack_8 + 1) {
    ptr_1[iStack_8 + 0x27] = 0;
  }
  ptr_1[0x47] = 0;
  ptr_1[0x48] = 0;
  ptr_1[0x49] = 0;
  AVIFileInit();
  return ptr_1;
}



void __cdecl thunk_FUN_10006a43(LPARAM *ptr_1)

{
  tagRECT tStack_34;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  GetWindowRect((HWND)ptr_1[4],&tStack_34);
  thunk_FUN_1000b5e0(*(void **)ptr_1[2],&iStack_14);
  iStack_24 = (tStack_34.right - tStack_34.left) / 2 - (iStack_c - iStack_14) / 2;
  iStack_1c = (iStack_c - iStack_14) + iStack_24;
  iStack_20 = (tStack_34.bottom - tStack_34.top) / 2 - (iStack_8 - iStack_10) / 2;
  iStack_18 = (iStack_8 - iStack_10) + iStack_20;
  thunk_FUN_1000b633(*(void **)ptr_1[2],&iStack_24);
  PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
  return;
}



void __thiscall thunk_FUN_100085b0(void *this,char *str_2)

{
  thunk_FUN_10008660((void *)((int)this + *(int *)this * 0x98 + 4),str_2);
  return;
}



int32_t __cdecl SetVidForeground(int *ptr_1,int arg_2)

{
  int32_t uval_1;
  
                    /* 0x123a  13  SetVidForeground */
  if ((arg_2 < 0) || (2 < arg_2)) {
    uval_1 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg_2 * 4) == 0) {
    uval_1 = 0;
  }
  else {
    thunk_FUN_1000bc86((void *)**(int32_t **)(*(int *)(&DAT_10010868 + arg_2 * 4) + 8),ptr_1);
    uval_1 = 0;
  }
  return uval_1;
}



int32_t __cdecl DrawVidBackground(int arg_1)

{
  int val_1;
  int *arg_1_00;
  int32_t uval_2;
  int32_t uval_3;
  int32_t uval_4;
  HDC hDC;
  int32_t uval_5;
  int32_t uval_6;
  int32_t uval_7;
  int32_t uval_8;
  
                    /* 0x123f  11  DrawVidBackground */
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_3 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg_1 * 4);
    if (val_1 == 0) {
      uval_3 = 0;
    }
    else {
      arg_1_00 = *(int **)(val_1 + 0x50);
      if (arg_1_00 == (int *)0x0) {
        uval_3 = 2;
      }
      else {
        if (*(int *)(val_1 + 0x10) != 0) {
          uval_4 = DrawDibOpen();
          hDC = GetDC(*(HWND *)(val_1 + 0x10));
          uval_5 = thunk_FUN_10004bc0((int)arg_1_00);
          uval_3 = *(int32_t *)(val_1 + 0x58);
          uval_2 = *(int32_t *)(val_1 + 0x5c);
          uval_6 = (**(code **)(*arg_1_00 + 8))();
          uval_7 = (**(code **)(*arg_1_00 + 0xc))();
          uval_8 = thunk_FUN_10004bf0((int)arg_1_00);
          DrawDibDraw(uval_4,hDC,uval_3,uval_2,uval_6,uval_7,uval_5,uval_8,0,0,uval_6,uval_7,0);
          ReleaseDC(*(HWND *)(val_1 + 0x10),hDC);
          DrawDibClose(uval_4);
        }
        uval_3 = 0;
      }
    }
  }
  return uval_3;
}



void __fastcall thunk_FUN_10008570(uint32_t *ptr_1)

{
  *ptr_1 = *ptr_1 + 1;
  *ptr_1 = *ptr_1 & 0xff;
  return;
}



int32_t __fastcall thunk_FUN_10004bc0(int arg_1)

{
  return *(int32_t *)(arg_1 + 4);
}



int __thiscall thunk_FUN_1000b2fb(void *this,int32_t arg_2,int32_t arg_3)

{
  int val_1;
  int32_t uStack_c;
  
  if (*(int *)((int)this + 0x10) == 0) {
    val_1 = 0;
  }
  else {
    if (DAT_100275d0 == 0) {
      uStack_c = *(int32_t *)((int)this + 0x19c);
    }
    else {
      uStack_c = *(int32_t *)((int)this + 400);
    }
    val_1 = FUN_1000b284(*(int32_t *)this,arg_3,*(int32_t *)((int)this + 0x14),arg_2,0,0,
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                         *(int32_t *)((int)this + 0x18),uStack_c,0,0,
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28));
    if (val_1 == 0) {
      val_1 = 0;
    }
  }
  return val_1;
}



int32_t __fastcall thunk_FUN_1000761c(void *ptr_1)

{
  int32_t uval_1;
  
  if (*(int *)((int)ptr_1 + 0x78) < 0) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)ptr_1 + 0x18) == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    thunk_FUN_1000743e(ptr_1,1);
    *(int *)((int)ptr_1 + 0x124) = *(int *)((int)ptr_1 + 0x124) + -1;
    thunk_FUN_1000755a((int)ptr_1);
    uval_1 = 0;
  }
  return uval_1;
}



int32_t __thiscall thunk_FUN_1000a30f(void *this,int arg_2,void *ptr_3)

{
  int32_t uval_1;
  void *buf_ptr_2;
  int val_3;
  
  *(int32_t *)((int)this + 0x10) = 0;
  if (*(int *)this != 0) {
    thunk_FUN_1000a795(this);
  }
  uval_1 = DrawDibOpen();
  *(int32_t *)((int)this + 8) = uval_1;
  *(int32_t *)((int)this + 0x18c) = 0;
  if (arg_2 == 0) {
    *(int32_t *)((int)this + 0xc) = *(int32_t *)((int)ptr_3 + 0x10);
  }
  else {
    *(int *)((int)this + 0xc) = arg_2;
  }
  if (*(int *)((int)this + 0xc) == 0x31345649) {
    *(int32_t *)((int)this + 0xc) = 0x31347669;
  }
  uval_1 = ICLocate(0x63646976,arg_2,ptr_3,0,2);
  *(int32_t *)this = uval_1;
  if (*(int *)this == 0) {
    uval_1 = 0x80044071;
  }
  else {
    ICSendMessage(*(int32_t *)this,0x401d,0,0);
    buf_ptr_2 = operator_new(0x428);
    *(void **)((int)this + 0x14) = buf_ptr_2;
    buf_ptr_2 = operator_new(0x428);
    *(void **)((int)this + 0x18) = buf_ptr_2;
    if ((*(int *)((int)this + 0x14) == 0) || (*(int *)((int)this + 0x18) == 0)) {
      assert(s_m_pbiSrc____m_pbiDst_1001070c,s_G__NewMagic_tstvid_Videovcm_cpp_100106ec,0x57);
    }
    if ((*(int *)((int)this + 0x14) == 0) || (*(int *)((int)this + 0x18) == 0)) {
      uval_1 = 3;
    }
    else {
      memset(*(void **)((int)this + 0x18),0,0x428);
      memset(*(void **)((int)this + 0x14),0,0x428);
      memcpy(*(void **)((int)this + 0x14),ptr_3,0x28);
      memcpy(*(void **)((int)this + 0x18),*(void **)((int)this + 0x14),0x28);
      *(int16_t *)(*(int *)((int)this + 0x18) + 0xe) = 0x18;
      *(int32_t *)(*(int *)((int)this + 0x18) + 0x10) = 0;
      *(int32_t *)(*(int *)((int)this + 0x18) + 0x14) = 0;
      *(int32_t *)((int)this + 0x20) = 0;
      *(int32_t *)((int)this + 0x1c) = *(int32_t *)((int)this + 0x20);
      *(int32_t *)((int)this + 0x24) = *(int32_t *)(*(int *)((int)this + 0x14) + 4);
      *(int32_t *)((int)this + 0x28) = *(int32_t *)(*(int *)((int)this + 0x14) + 8);
      *(int32_t *)((int)this + 0x30) = 0;
      *(int32_t *)((int)this + 0x2c) = *(int32_t *)((int)this + 0x30);
      *(int32_t *)((int)this + 0x34) = *(int32_t *)(*(int *)((int)this + 0x14) + 4);
      *(int32_t *)((int)this + 0x38) = *(int32_t *)(*(int *)((int)this + 0x14) + 8);
      *(int32_t *)((int)this + 0x40) = 0;
      *(int32_t *)((int)this + 0x3c) = *(int32_t *)((int)this + 0x40);
      *(int32_t *)((int)this + 0x44) = *(int32_t *)(*(int *)((int)this + 0x14) + 4);
      *(int32_t *)((int)this + 0x48) = *(int32_t *)(*(int *)((int)this + 0x14) + 8);
      *(int32_t *)((int)this + 0x50) = 0;
      *(int32_t *)((int)this + 0x4c) = *(int32_t *)((int)this + 0x50);
      *(int32_t *)((int)this + 0x54) = *(int32_t *)(*(int *)((int)this + 0x14) + 4);
      *(int32_t *)((int)this + 0x58) = *(int32_t *)(*(int *)((int)this + 0x14) + 8);
      if (*(int *)((int)this + 0xc) == 0x31347669) {
        *(int32_t *)((int)this + 0x88) = 0x2c;
        *(int32_t *)((int)this + 0x8c) = 0x31345649;
        *(int32_t *)((int)this + 0x90) = 0x10001;
        *(int32_t *)((int)this + 0x94) = 3;
        *(int32_t *)((int)this + 0x98) = 2;
        *(int32_t *)((int)this + 0x9c) = 0;
        ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0x88,0x2c);
        memcpy((void *)((int)this + 0x5c),(void *)((int)this + 0x88),0x2c);
        *(int32_t *)((int)this + 0x68) = 4;
        *(int32_t *)((int)this + 0x108) = 0x54;
        *(int32_t *)((int)this + 0x10c) = 0x31345649;
        *(int32_t *)((int)this + 0x110) = 0x10001;
        *(int32_t *)((int)this + 0x114) = 1;
        *(int32_t *)((int)this + 0x118) = 2;
        *(int32_t *)((int)this + 0x11c) = 0;
        ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0x108,0x54);
        memcpy((void *)((int)this + 0xb4),(void *)((int)this + 0x108),0x54);
        *(int32_t *)((int)this + 0xc0) = 2;
        *(int *)((int)this + 0xf0) = (int)this + 0x15c;
        *(int32_t *)((int)this + 200) = 0x80000008;
        ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0xb4,0x54);
      }
      val_3 = *(int *)(*(int *)((int)this + 0x14) + 4) + 3;
      val_3 = ((int)(val_3 + (val_3 >> 0x1f & 3U)) >> 2) *
              (uint32_t)*(uint16_t *)(*(int *)((int)this + 0x14) + 0xe) *
              *(int *)(*(int *)((int)this + 0x14) + 8) * 4;
      *(int *)((int)this + 0x198) = (int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3;
      buf_ptr_2 = malloc(*(size_t *)((int)this + 0x198));
      *(void **)((int)this + 0x19c) = buf_ptr_2;
      if (*(int *)((int)this + 0x19c) == 0) {
        uval_1 = 3;
      }
      else {
        uval_1 = 0;
      }
    }
  }
  return uval_1;
}



void __fastcall thunk_FUN_10008136(int32_t *ptr_1)

{
  int val_1;
  int iStack_8;
  
  if ((int)ptr_1[0x12] < (int)ptr_1[0x13]) {
    ptr_1[0x12] = ptr_1[0x13] + -1;
  }
  iStack_8 = ptr_1[0x12];
  while ((iStack_8 = iStack_8 + 1, iStack_8 < (int)ptr_1[0x11] &&
         (val_1 = AVIStreamRead(ptr_1[3],iStack_8,1,ptr_1[0x17],ptr_1[0x18],0,0), val_1 == 0))) {
    if (ptr_1[6] == 0) {
      thunk_FUN_100085b0(&DAT_1001bf60,s_vidsCatchup_____m_bPlaying__Draw_10010658);
      val_1 = thunk_FUN_1000b2fb((void *)*ptr_1,ptr_1[0x17],0);
      thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],val_1,0,0);
      thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
    }
    else {
      thunk_FUN_100085b0(&DAT_1001bf60,s_vidsCatchup_____m_bPlaying__Draw_1001067c);
      val_1 = thunk_FUN_1000b2fb((void *)*ptr_1,ptr_1[0x17],0x80000000);
      thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],val_1,0,0);
      thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
    }
    ptr_1[0x12] = iStack_8;
  }
  return;
}



int * __thiscall thunk_FUN_10008520(void *this,uint8_t arg_2)

{
  thunk_FUN_1000a2f1(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



int32_t __fastcall thunk_FUN_10001c16(int *ptr_1)

{
  thunk_FUN_10001d28(ptr_1);
  thunk_FUN_10007a85(ptr_1);
  thunk_FUN_10007238((int)ptr_1);
  if (ptr_1[3] != 0) {
    AVIStreamRelease(ptr_1[3]);
  }
  if (ptr_1[4] != 0) {
    AVIStreamRelease(ptr_1[4]);
  }
  ptr_1[4] = 0;
  ptr_1[3] = ptr_1[4];
  return 0;
}



void __cdecl thunk_FUN_10005ef9(int arg_1)

{
  int32_t *ptr_1;
  HDC hDC;
  bool flag_1;
  undefined3 extraout_var;
  HANDLE hProcess;
  
  ptr_1 = *(int32_t **)(arg_1 + 8);
  if ((ptr_1 != (int32_t *)0x0) &&
     (flag_1 = thunk_FUN_10004c20((int)ptr_1), CONCAT31(extraout_var,flag_1) != 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(arg_1 + 0x20));
    *(int32_t *)(arg_1 + 0x3c) = 0;
    *(int32_t *)(arg_1 + 0x38) = 0;
    hDC = (HDC)ptr_1[0xc];
    thunk_FUN_10001d28(ptr_1);
    if (*(int *)(arg_1 + 100) == 0) {
      hProcess = GetCurrentProcess();
      SetPriorityClass(hProcess,0x20);
      if (*(int *)(arg_1 + 0x48) != 0) {
        *(int32_t *)(arg_1 + 0x48) = 0;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(arg_1 + 0x20));
      CloseHandle(*(HANDLE *)(arg_1 + 0x40));
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)(arg_1 + 0x20));
    }
    thunk_FUN_10007050((int)ptr_1);
    if (hDC != (HDC)0x0) {
      ReleaseDC(*(HWND *)(arg_1 + 0x10),hDC);
    }
  }
  return;
}



int32_t __cdecl SetVidCallBack(int arg1,int32_t arg2)

{
  int32_t uval_1;
  
                    /* 0x128a  7  SetVidCallBack */
  if ((arg1 < 0) || (2 < arg1)) {
    uval_1 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg1 * 4) == 0) {
    uval_1 = 5;
  }
  else {
    *(int32_t *)(*(int *)(&DAT_10010868 + arg1 * 4) + 0x6c) = arg2;
    uval_1 = 0;
  }
  return uval_1;
}



int32_t __cdecl SetVidTransparency(int arg1,int arg2)

{
  int *i_ptr_1;
  int32_t uval_2;
  
                    /* 0x128f  19  SetVidTransparency */
  if ((arg1 < 0) || (2 < arg1)) {
    uval_2 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg1 * 4) == 0) {
    uval_2 = 0;
  }
  else {
    i_ptr_1 = *(int **)(*(int *)(&DAT_10010868 + arg1 * 4) + 8);
    if (i_ptr_1 == (int *)0x0) {
      uval_2 = 2;
    }
    else if (*i_ptr_1 == 0) {
      uval_2 = 2;
    }
    else {
      thunk_FUN_1000bbec((void *)*i_ptr_1,arg2);
      uval_2 = 0;
    }
  }
  return uval_2;
}



int32_t __fastcall thunk_FUN_10007238(int arg_1)

{
  *(int32_t *)(arg_1 + 0x78) = 0xffffffff;
  thunk_FUN_10004ea1(DAT_10010618);
  return 0;
}



void __fastcall thunk_FUN_10007050(int arg_1)

{
  *(int32_t *)(arg_1 + 0x40) = 0;
  return;
}



bool __fastcall thunk_FUN_10004c20(int arg_1)

{
  return *(int *)(arg_1 + 8) != 0;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t InitVid(void)

{
                    /* 0x12a3  1  InitVid */
  if (DAT_10010530 == 0) {
    _DAT_10010878 = 3;
    _DAT_1001087c = &LAB_100010be;
    _DAT_10010880 = 0;
    _DAT_10010884 = 0;
    DAT_10010888 = DAT_1001054c;
    _DAT_1001088c = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    _DAT_10010890 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    _DAT_10010894 = 0;
    _DAT_10010898 = 0;
    _DAT_1001089c = PTR_s_VIDWINCLASS_10010534;
    RegisterClassA((WNDCLASSA *)&DAT_10010878);
  }
  thunk_FUN_10004c90(0,0,3);
  DAT_10010530 = DAT_10010530 + 1;
  return 0;
}



int32_t __thiscall thunk_FUN_10002227(void *this,int arg_2)

{
  bool flag_1;
  int32_t uval_2;
  undefined3 extraout_var;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_2 = 0xffffffff;
  }
  else {
    flag_1 = thunk_FUN_1000b99f(*(void **)this,arg_2);
    if (CONCAT31(extraout_var,flag_1) == 0) {
      uval_2 = 0xfffffffb;
    }
    else {
      uval_2 = 0;
    }
  }
  return uval_2;
}



int32_t __cdecl thunk_FUN_10004ea1(int32_t arg_1)

{
  int32_t uval_1;
  
  if (DAT_10010584 == 0) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c7c)(arg_1);
  }
  return uval_1;
}



int32_t __cdecl thunk_FUN_10004f90(int32_t arg_1)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c8c)(arg_1);
  }
  return uval_1;
}



int32_t thunk_FUN_100073d1(void)

{
  int val_1;
  int32_t uval_2;
  uint8_t auStack_8 [4];
  
  val_1 = thunk_FUN_100052e9(DAT_10010618,auStack_8);
  if (val_1 == 0) {
    uval_2 = 0xffffffff;
  }
  else {
    uval_2 = 0xfffffff2;
  }
  return uval_2;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t __cdecl StopAVI(int arg_1)

{
  int arg_1_00;
  int32_t uval_1;
  
                    /* 0x12c1  6  StopAVI */
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else {
    arg_1_00 = *(int *)(&DAT_10010868 + arg_1 * 4);
    if (arg_1_00 == 0) {
      uval_1 = 0;
    }
    else if ((*(uint32_t *)(arg_1_00 + 4) >> 1 & 1) == 0) {
      if (*(int *)(arg_1_00 + 8) != 0) {
        thunk_FUN_10004f90(arg_1 + 0x100);
        thunk_FUN_10005ef9(arg_1_00);
      }
      _DAT_10010544 = _DAT_10010544 + -1;
      uval_1 = 0;
    }
    else {
      uval_1 = 0;
    }
  }
  return uval_1;
}



int32_t __cdecl PasteToVidBackground(int *x,short *y,int *width,int height)

{
  int val_1;
  int32_t uval_2;
  
                    /* 0x12cb  12  PasteToVidBackground */
  if (((x == (int *)0x0) || (y == (short *)0x0)) || (width == (int *)0x0)) {
    uval_2 = 2;
  }
  else if ((height < 0) || (2 < height)) {
    uval_2 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + height * 4);
    if ((val_1 == 0) || (*(int *)(val_1 + 0x50) == 0)) {
      uval_2 = 5;
    }
    else {
      (**(code **)(*x + 0x18))
                (*(int32_t *)(val_1 + 0x50),(int)*y,(int)y[1],width[2] - *width,
                 width[3] - width[1],*width,width[1]);
      uval_2 = 0;
    }
  }
  return uval_2;
}



int32_t __cdecl LoadAVI(LPCSTR x,int *y,short *width,uint32_t height)

{
  int32_t uval_1;
  void *buf_ptr_2;
  int32_t *ptr_1;
  HWND pHVar3;
  int val_4;
  int32_t *unaff_FS_OFFSET;
  int32_t *puStack_3c;
  LPCSTR pCStack_34;
  DWORD DStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int *piStack_18;
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
                    /* 0x12d0  3  LoadAVI */
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10002dae;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  iStack_1c = 0;
  iStack_2c = 0;
  iStack_20 = 0;
  iStack_24 = 0;
  for (iStack_28 = 0; (iStack_28 < 3 && (*(int *)(&DAT_10010868 + iStack_28 * 4) != 0));
      iStack_28 = iStack_28 + 1) {
  }
  if (iStack_28 == 3) {
    uval_1 = 3;
  }
  else {
    buf_ptr_2 = operator_new(0x70);
    *(void **)(&DAT_10010868 + iStack_28 * 4) = buf_ptr_2;
    piStack_18 = *(int **)(&DAT_10010868 + iStack_28 * 4);
    if (piStack_18 == (int *)0x0) {
      uval_1 = 3;
    }
    else {
      memset(piStack_18,0,0x70);
      ptr_1 = operator_new(0x128);
      uStack_8 = 0;
      if (ptr_1 == (int32_t *)0x0) {
        puStack_3c = (int32_t *)0x0;
      }
      else {
        puStack_3c = thunk_FUN_10001740(ptr_1);
      }
      uStack_8 = 0xffffffff;
      *(int32_t **)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 8) = puStack_3c;
      iStack_14 = *(int *)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 8);
      if (iStack_14 == 0) {
        operator_delete(*(void **)(&DAT_10010868 + iStack_28 * 4));
        *(int32_t *)(&DAT_10010868 + iStack_28 * 4) = 0;
        uval_1 = 3;
      }
      else {
        if (height == 0) {
          iStack_1c = -0x80000000;
          iStack_2c = -0x80000000;
          if (width == (short *)0x0) {
            iStack_20 = 0;
            piStack_18[0x16] = 0;
            iStack_24 = 0;
            piStack_18[0x16] = 0;
          }
          else {
            iStack_20 = (int)*width;
            piStack_18[0x16] = iStack_20;
            iStack_24 = (int)width[1];
            piStack_18[0x17] = iStack_24;
          }
        }
        else {
          iStack_1c = GetSystemMetrics(0);
          iStack_2c = GetSystemMetrics(1);
          iStack_20 = 0;
          piStack_18[0x16] = 0;
          iStack_24 = 0;
          piStack_18[0x17] = 0;
        }
        if ((height & 4) == 0) {
          DAT_1001053c = (HWND)thunk_FUN_100053fa();
          piStack_18[6] = (int)DAT_1001053c;
          pHVar3 = CreateWindowExA(0,PTR_s_VIDWINCLASS_10010534,(LPCSTR)0x0,0x90000000,iStack_20,
                                   iStack_24,iStack_1c,iStack_2c,DAT_1001053c,(HMENU)0x0,
                                   DAT_1001054c,(LPVOID)0x0);
          piStack_18[4] = (int)pHVar3;
          if (piStack_18[4] == 0) {
            DStack_30 = GetLastError();
            FormatMessageA(0x1100,(LPCVOID)0x0,DStack_30,0x400,(LPSTR)&pCStack_34,0,(va_list *)0x0);
            MessageBoxA((HWND)0x0,pCStack_34,s_GetLastError_10010564,0x40);
            LocalFree(pCStack_34);
          }
          piStack_18[5] = 1;
        }
        else if ((*(int *)(&DAT_10010868 + *y * 4) != 0) &&
                (*(int *)(*(int *)(&DAT_10010868 + *y * 4) + 0x10) != 0)) {
          piStack_18[4] = *(int *)(*(int *)(&DAT_10010868 + *y * 4) + 0x10);
          piStack_18[5] = 0;
        }
        *piStack_18 = iStack_28;
        if ((height & 4) == 0) {
          SetFocus(*(HWND *)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 0x10));
          SetForegroundWindow(*(HWND *)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 0x10));
          ShowWindow(*(HWND *)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 0x10),1);
        }
        val_4 = thunk_FUN_10005a5b(piStack_18,x);
        if (val_4 == 0) {
          *y = iStack_28;
          uval_1 = 0;
        }
        else {
          if ((height & 4) == 0) {
            DestroyWindow(*(HWND *)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 0x10));
          }
          operator_delete(*(void **)(&DAT_10010868 + iStack_28 * 4));
          *(int32_t *)(&DAT_10010868 + iStack_28 * 4) = 0;
          uval_1 = 1;
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return uval_1;
}



int __thiscall CArchive::IsBufferEmpty(CArchive *this)

{
  return (uint32_t)(*(int *)(this + 0x44) == *(int *)(this + 0x58));
}



void __cdecl thunk_FUN_10005d8d(LPVOID arg_1)

{
  void *this;
  bool flag_1;
  undefined3 extraout_var;
  HANDLE buf_ptr_2;
  HDC arg_2;
  
  if ((((arg_1 != (LPVOID)0x0) && (*(int *)((int)arg_1 + 8) != 0)) &&
      (this = *(void **)((int)arg_1 + 8), this != (void *)0x0)) &&
     ((flag_1 = thunk_FUN_10004c20((int)this), CONCAT31(extraout_var,flag_1) != 0 &&
      (*(int *)((int)arg_1 + 0x38) == 0)))) {
    *(int32_t *)((int)arg_1 + 0x48) = 1;
    if ((*(int *)((int)arg_1 + 0x3c) == 0) &&
       ((*(int *)((int)arg_1 + 0x40) == 0 && ((*(uint32_t *)((int)arg_1 + 4) >> 3 & 1) == 0)))) {
      buf_ptr_2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_10001005,arg_1
                            ,0,(LPDWORD)((int)arg_1 + 0x44));
      *(HANDLE *)((int)arg_1 + 0x40) = buf_ptr_2;
    }
    if (*(int *)((int)arg_1 + 100) != 0) {
      *(uint32_t *)(*(int *)((int)arg_1 + 100) + 4) = *(uint32_t *)(*(int *)((int)arg_1 + 100) + 4) | 8;
      *(int32_t *)(*(int *)((int)arg_1 + 100) + 0x40) = *(int32_t *)((int)arg_1 + 0x40);
      *(int32_t *)(*(int *)((int)arg_1 + 100) + 0x44) = *(int32_t *)((int)arg_1 + 0x44);
      *(int32_t *)(*(int *)((int)arg_1 + 100) + 0x48) = 1;
    }
    arg_2 = GetDC(*(HWND *)((int)arg_1 + 0x10));
    thunk_FUN_10001c8e(this,(int)arg_2);
    SetThreadPriority(*(HANDLE *)((int)arg_1 + 0x40),1);
    EnterCriticalSection((LPCRITICAL_SECTION)((int)arg_1 + 0x20));
    *(int32_t *)((int)arg_1 + 0x3c) = 0;
    *(int32_t *)((int)arg_1 + 0x38) = 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)arg_1 + 0x20));
  }
  return;
}



int __thiscall thunk_FUN_1000b83e(void *this,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  int val_1;
  int iStack_8;
  
  if (arg_3 == 0) {
    arg_3 = *(int *)((int)this + 0x2c);
  }
  if (arg_4 == 0) {
    arg_4 = *(int *)((int)this + 0x30);
  }
  if (arg_5 == 0) {
    arg_5 = *(int *)((int)this + 0x34);
  }
  if (arg_6 == 0) {
    arg_6 = *(int *)((int)this + 0x38);
  }
  if (arg_2 == 0) {
    iStack_8 = *(int *)((int)this + 0x18);
  }
  else {
    iStack_8 = arg_2;
  }
  if ((((arg_3 < 0) || (arg_4 < 0)) || (*(int *)(iStack_8 + 4) < arg_5 + arg_3)) ||
     (*(int *)(iStack_8 + 8) < arg_6 + arg_4)) {
    val_1 = -1;
  }
  else {
    val_1 = FUN_1000ac38(*(int32_t *)this,0,*(int32_t *)((int)this + 0x14),0,
                         *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                         iStack_8,0,arg_3,arg_4,arg_5,arg_6);
    if (val_1 == 0) {
      if ((*(int *)((int)this + 0x180) == 0) ||
         ((*(int *)(iStack_8 + 4) <= *(int *)((int)this + 0x54) &&
          (*(int *)(iStack_8 + 8) <= *(int *)((int)this + 0x58))))) {
        val_1 = 0;
      }
      else {
        val_1 = -1;
      }
    }
  }
  return val_1;
}



int32_t __thiscall thunk_FUN_100023d1(void *this,int arg_2)

{
  int32_t uval_1;
  int val_2;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    *(int *)((int)this + 4) = arg_2;
    val_2 = thunk_FUN_1000bac7(*(void **)this,*(int **)((int)this + 4));
    if (val_2 == 0) {
      uval_1 = 0xfffffffb;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 0xfffffffc;
  }
  return uval_1;
}



int32_t thunk_FUN_100051e4(void)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032cb0)();
  }
  return uval_1;
}



int32_t __cdecl thunk_FUN_10004e65(int32_t arg_1,int32_t arg_2,int32_t arg_3)

{
  int32_t uval_1;
  
  if (DAT_10010584 == 0) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c78)(arg_1,arg_2,arg_3);
  }
  return uval_1;
}



int32_t __thiscall thunk_FUN_10001c8e(void *this,int arg_2)

{
  int32_t uval_1;
  timecaps_tag tStack_c;
  
  if (*(int *)((int)this + 0xc) == 0) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    *(int32_t *)((int)this + 0x18) = 1;
    timeGetDevCaps(&tStack_c,8);
    if (tStack_c.wPeriodMin < 2) {
      tStack_c.wPeriodMin = 1;
    }
    *(UINT *)((int)this + 0x28) = tStack_c.wPeriodMin;
    timeBeginPeriod(*(UINT *)((int)this + 0x28));
    *(int32_t *)((int)this + 0x1c) = 0;
    thunk_FUN_10007b00(this,arg_2,-1);
    uval_1 = 0;
  }
  else {
    uval_1 = 0xfffffffc;
  }
  return uval_1;
}



int32_t * __thiscall thunk_FUN_10004b70(void *this,uint8_t arg_2)

{
  thunk_FUN_10008774(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



int32_t __fastcall thunk_FUN_10007f71(int32_t *ptr_1)

{
  int val_1;
  int32_t uval_2;
  int iStack_c;
  int iStack_8;
  
  if ((int)ptr_1[0x11] < (int)ptr_1[0x12]) {
    ptr_1[0x12] = 0xffffffff;
  }
  if (ptr_1[0x11] - ptr_1[0x12] != 1) {
    val_1 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11],0x14);
    if (val_1 == ptr_1[0x11]) {
      ptr_1[0x13] = ptr_1[0x11];
      uval_2 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11] + 1,0x11);
      ptr_1[0x14] = uval_2;
    }
    else if (ptr_1[0x11] - ptr_1[0x12] == 2) {
      thunk_FUN_10008136(ptr_1);
    }
    else {
      if (((int)ptr_1[0x14] < (int)ptr_1[0x11]) || ((int)ptr_1[0x11] < (int)ptr_1[0x13])) {
        uval_2 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11] + -1,0x14);
        ptr_1[0x13] = uval_2;
        uval_2 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11] + 1,0x11);
        ptr_1[0x14] = uval_2;
      }
      if ((int)(ptr_1[0x11] - ptr_1[0x13]) < 0) {
        iStack_8 = -(ptr_1[0x11] - ptr_1[0x13]);
      }
      else {
        iStack_8 = ptr_1[0x11] - ptr_1[0x13];
      }
      if ((int)(ptr_1[0x11] - ptr_1[0x14]) < 0) {
        iStack_c = -(ptr_1[0x11] - ptr_1[0x14]);
      }
      else {
        iStack_c = ptr_1[0x11] - ptr_1[0x14];
      }
      if (iStack_c < iStack_8) {
        if (ptr_1[6] != 0) {
          return 0;
        }
        thunk_FUN_10008136(ptr_1);
      }
      else {
        thunk_FUN_10008136(ptr_1);
      }
    }
  }
  return 1;
}



int32_t __cdecl VidStatus(int arg_1)

{
  int32_t uval_1;
  
                    /* 0x1325  16  VidStatus */
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg_1 * 4) == 0) {
    uval_1 = 0;
  }
  else {
    uval_1 = *(int32_t *)(*(int *)(&DAT_10010868 + arg_1 * 4) + 0x38);
  }
  return uval_1;
}



void __fastcall thunk_FUN_10009348(int arg_1)

{
  FUN_10008ad5(*(int **)(arg_1 + 4));
  return;
}



void __thiscall thunk_FUN_1000b456(void *this,int32_t *ptr_2)

{
  *ptr_2 = *(int32_t *)((int)this + 0x2c);
  ptr_2[1] = *(int32_t *)((int)this + 0x30);
  ptr_2[2] = *(int *)((int)this + 0x2c) + *(int *)((int)this + 0x34);
  ptr_2[3] = *(int *)((int)this + 0x38) + *(int *)((int)this + 0x30);
  return;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t __cdecl PlayAVI(int arg_1)

{
  LPVOID arg_1_00;
  int32_t uval_1;
  
                    /* 0x1334  5  PlayAVI */
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else {
    arg_1_00 = *(LPVOID *)(&DAT_10010868 + arg_1 * 4);
    if (arg_1_00 == (LPVOID)0x0) {
      uval_1 = 0;
    }
    else {
      if (*(int *)((int)arg_1_00 + 8) != 0) {
        thunk_FUN_10005d8d(arg_1_00);
      }
      _DAT_10010544 = _DAT_10010544 + 1;
      uval_1 = 0;
    }
  }
  return uval_1;
}



void thunk_FUN_10004def(void)

{
  if (DAT_10010584 != 0) {
    DAT_10010584 = 0;
    if ((DAT_10010588 != 0) && (DAT_10010580 == 0)) {
      (*DAT_10032c74)();
    }
    FreeLibrary(DAT_10032c44);
    thunk_FUN_100054bc();
    DAT_10032c44 = (HMODULE)0x0;
    DAT_10010580 = 0;
    DAT_10010588 = 0;
  }
  return;
}



int32_t __fastcall thunk_FUN_10007a85(int *ptr_1)

{
  if (ptr_1[0x17] != 0) {
    free((void *)ptr_1[0x17]);
    ptr_1[0x17] = 0;
  }
  if (*ptr_1 != 0) {
    if ((void *)*ptr_1 != (void *)0x0) {
      thunk_FUN_10008520((void *)*ptr_1,1);
    }
    *ptr_1 = 0;
  }
  return 0;
}



int * __thiscall thunk_FUN_10004b20(void *this,uint8_t arg_2)

{
  thunk_FUN_10001926(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



void __cdecl thunk_FUN_10006020(int arg_1)

{
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int *piStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if ((arg_1 != 0) && (*(int *)(arg_1 + 8) != 0)) {
    piStack_18 = *(int **)(arg_1 + 8);
    if (*piStack_18 == 0) {
      iStack_24 = 0;
      iStack_28 = 0;
      iStack_20 = 0x140;
      iStack_1c = 0;
    }
    else {
      thunk_FUN_1000b5e0((void *)*piStack_18,&iStack_28);
    }
    iStack_14 = iStack_28;
    iStack_c = iStack_20;
    iStack_8 = iStack_1c;
    iStack_10 = iStack_24;
    SetWindowPos(*(HWND *)(arg_1 + 0x10),(HWND)0x0,*(int *)(arg_1 + 0x58) + iStack_28,
                 *(int *)(arg_1 + 0x5c) + iStack_24,iStack_20 - iStack_28,iStack_1c - iStack_24,0x16
                );
  }
  return;
}



int __thiscall thunk_FUN_10001951(void *this,int32_t arg_2)

{
  int val_1;
  
  if (*(int *)((int)this + 8) != 0) {
    thunk_FUN_100019c7((int)this);
  }
  *(int32_t *)((int)this + 0x10) = 0;
  *(int32_t *)((int)this + 0xc) = *(int32_t *)((int)this + 0x10);
  val_1 = AVIFileOpenA((int)this + 8,arg_2,0x20,0);
  if (val_1 == 0) {
    val_1 = 0;
  }
  else {
    thunk_FUN_100019c7((int)this);
  }
  return val_1;
}



int32_t ReleaseVid(void)

{
                    /* 0x1370  2  ReleaseVid */
  if ((DAT_10010530 != 0) && (DAT_10010530 = DAT_10010530 + -1, DAT_10010530 == 0)) {
    UnregisterClassA(PTR_s_VIDWINCLASS_10010534,DAT_10010888);
    thunk_FUN_10004def();
  }
  return 0;
}



void __cdecl thunk_FUN_10006467(LPARAM *ptr_1)

{
  void *this;
  int val_1;
  bool flag_2;
  undefined3 extraout_var;
  int16_t *ptr_1_00;
  int val_3;
  uint8_t *puStack_18;
  int iStack_14;
  
  if ((ptr_1 != (LPARAM *)0x0) && (ptr_1[2] != 0)) {
    this = (void *)ptr_1[2];
    flag_2 = thunk_FUN_10004c20((int)this);
    if ((CONCAT31(extraout_var,flag_2) != 0) &&
       ((*(int *)((int)this + 4) != 0 &&
        (ptr_1_00 = operator_new(0x408), ptr_1_00 != (int16_t *)0x0)))) {
      puStack_18 = (uint8_t *)thunk_FUN_10007080(*(int *)((int)this + 4));
      for (iStack_14 = 0; iStack_14 < 0x100; iStack_14 = iStack_14 + 1) {
        *(uint8_t *)(ptr_1_00 + iStack_14 * 2 + 2) = puStack_18[2];
        *(uint8_t *)((int)ptr_1_00 + iStack_14 * 4 + 5) = puStack_18[1];
        *(uint8_t *)(ptr_1_00 + iStack_14 * 2 + 3) = *puStack_18;
        *(uint8_t *)((int)ptr_1_00 + iStack_14 * 4 + 7) = 4;
        puStack_18 = puStack_18 + 4;
      }
      *ptr_1_00 = 0x300;
      ptr_1_00[1] = 0x100;
      val_1 = ptr_1[0xe];
      if (val_1 != 0) {
        thunk_FUN_10005ef9((int)ptr_1);
      }
      val_3 = thunk_FUN_10002227(this,(int)ptr_1_00);
      if (val_3 == 0) {
        thunk_FUN_10005ce8((int)ptr_1,0);
      }
      if (val_1 != 0) {
        thunk_FUN_10005d8d(ptr_1);
      }
      PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
      if (ptr_1_00 != (int16_t *)0x0) {
        operator_delete(ptr_1_00);
      }
    }
  }
  return;
}



int __fastcall thunk_FUN_1000755a(int arg_1)

{
  uint32_t uval_1;
  uint32_t uval_2;
  int iStack_8;
  
  iStack_8 = 0;
  while (((iStack_8 < 0x20 && (*(int *)(arg_1 + 0x124) < 0x20)) &&
         (*(int *)(arg_1 + 0x11c) != *(int *)(arg_1 + 0x120)))) {
    waveOutWrite(*(HWAVEOUT *)(arg_1 + 0x74),
                 *(LPWAVEHDR *)(arg_1 + 0x9c + *(int *)(arg_1 + 0x120) * 4),0x20);
    *(int *)(arg_1 + 0x124) = *(int *)(arg_1 + 0x124) + 1;
    *(int *)(arg_1 + 0x120) = *(int *)(arg_1 + 0x120) + 1;
    uval_1 = *(uint32_t *)(arg_1 + 0x120);
    uval_2 = (int)uval_1 >> 0x1f;
    *(uint32_t *)(arg_1 + 0x120) = ((uval_1 ^ uval_2) - uval_2 & 0x1f ^ uval_2) - uval_2;
    iStack_8 = iStack_8 + 1;
  }
  return iStack_8;
}



int32_t __cdecl SetVidThreadPriority(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  int iStack_8;
  
                    /* 0x137f  18  SetVidThreadPriority */
  if ((arg1 < 0) || (2 < arg1)) {
    uval_2 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg1 * 4);
    if (val_1 == 0) {
      uval_2 = 0;
    }
    else {
      if (*(int *)(val_1 + 0x40) != 0) {
        iStack_8 = SetThreadPriority(*(HANDLE *)(val_1 + 0x40),arg2);
      }
      if (iStack_8 == 0) {
        uval_2 = 8;
      }
      else {
        uval_2 = 0;
      }
    }
  }
  return uval_2;
}



void __thiscall thunk_FUN_1000b4a9(void *this,int *ptr_2)

{
  *(int *)((int)this + 0x2c) = *ptr_2;
  *(int *)((int)this + 0x30) = ptr_2[1];
  *(int *)((int)this + 0x34) = ptr_2[2] - *ptr_2;
  *(int *)((int)this + 0x38) = ptr_2[3] - ptr_2[1];
  return;
}



CPrintPreviewState * __thiscall CPrintPreviewState::CPrintPreviewState(CPrintPreviewState *this)

{
  *(uint8_t ***)this = &PTR_LAB_1000f060;
  *(int32_t *)(this + 4) = 0;
  *(int32_t *)(this + 8) = 0;
  *(int32_t *)(this + 0xc) = 1;
  *(int32_t *)(this + 0x10) = 0;
  *(int32_t *)(this + 0x14) = 0;
  return this;
}



int32_t * __fastcall thunk_FUN_10004af0(int32_t *ptr_1)

{
  *ptr_1 = 0;
  return ptr_1;
}



int32_t * __fastcall AVI_InitializeSubsystem(int32_t *ptr_1)

{
  int local_8;
  
  *ptr_1 = 0;
  ptr_1[1] = 0;
  ptr_1[2] = 0;
  ptr_1[3] = 0;
  ptr_1[4] = 0;
  ptr_1[5] = 0;
  ptr_1[6] = 0;
  ptr_1[7] = 0;
  ptr_1[8] = 0;
  ptr_1[9] = 0;
  ptr_1[10] = 0;
  ptr_1[0xb] = 0;
  ptr_1[0xc] = 0;
  ptr_1[0xd] = 0;
  ptr_1[0xe] = 0;
  ptr_1[0xf] = 0;
  ptr_1[0x10] = 0;
  ptr_1[0x11] = 0;
  ptr_1[0x12] = 0;
  ptr_1[0x13] = 0;
  ptr_1[0x14] = 0;
  ptr_1[0x15] = 0;
  ptr_1[0x16] = 0;
  ptr_1[0x17] = 0;
  ptr_1[0x18] = 0;
  ptr_1[0x1d] = 0;
  ptr_1[0x1e] = 0;
  ptr_1[0x1f] = 0;
  ptr_1[0x20] = 0;
  ptr_1[0x21] = 0;
  ptr_1[0x22] = 0;
  ptr_1[0x23] = 0;
  ptr_1[0x24] = 0;
  ptr_1[0x25] = 0;
  ptr_1[0x26] = 0;
  for (local_8 = 0; local_8 < 0x20; local_8 = local_8 + 1) {
    ptr_1[local_8 + 0x27] = 0;
  }
  ptr_1[0x47] = 0;
  ptr_1[0x48] = 0;
  ptr_1[0x49] = 0;
  AVIFileInit();
  return ptr_1;
}



void __fastcall AVI_ShutdownSubsystem(int *ptr_1)

{
  thunk_FUN_10001c16(ptr_1);
  thunk_FUN_100019c7((int)ptr_1);
  AVIFileExit();
  return;
}



int __thiscall AVI_OpenFileStream(void *this,int32_t arg_2)

{
  int val_1;
  
  if (*(int *)((int)this + 8) != 0) {
    thunk_FUN_100019c7((int)this);
  }
  *(int32_t *)((int)this + 0x10) = 0;
  *(int32_t *)((int)this + 0xc) = *(int32_t *)((int)this + 0x10);
  val_1 = AVIFileOpenA((int)this + 8,arg_2,0x20,0);
  if (val_1 == 0) {
    val_1 = 0;
  }
  else {
    thunk_FUN_100019c7((int)this);
  }
  return val_1;
}



int32_t __fastcall AVI_ReleaseFileStream(int arg_1)

{
  if (*(int *)(arg_1 + 8) != 0) {
    AVIFileRelease(*(int32_t *)(arg_1 + 8));
    *(int32_t *)(arg_1 + 8) = 0;
  }
  return 0;
}



int __thiscall AVI_GetVideoStreamInfo(void *this,int arg_2,int arg_3)

{
  int val_1;
  int32_t local_b4;
  int32_t local_b0;
  int32_t local_ac;
  int32_t local_a8;
  int32_t local_a4;
  int32_t local_a0;
  int32_t local_9c;
  int32_t local_98;
  uint8_t local_94 [20];
  uint32_t local_80;
  uint32_t local_7c;
  int local_8;
  
  if ((*(int *)((int)this + 0xc) != 0) || (*(int *)((int)this + 0x10) != 0)) {
    thunk_FUN_10001c16(this);
  }
  *(int32_t *)((int)this + 0x1c) = 0;
  *(int32_t *)((int)this + 0x18) = *(int32_t *)((int)this + 0x1c);
  *(int *)((int)this + 0x14) = arg_2;
  *(int32_t *)this = 0;
  *(int32_t *)((int)this + 0x74) = 0;
  local_8 = AVIFileGetStream(*(int32_t *)((int)this + 8),(int)this + 0xc,0x73646976,0);
  if (local_8 == -0x7ffbbf8d) {
    *(int32_t *)((int)this + 0xc) = 0;
    val_1 = -1;
  }
  else {
    local_8 = AVIFileGetStream(*(int32_t *)((int)this + 8),(int)this + 0x10,0x73647561,0);
    if (local_8 == -0x7ffbbf8d) {
      *(int32_t *)((int)this + 0x10) = 0;
    }
    else {
      local_b4 = 400;
      local_b0 = 0;
      local_ac = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0x14;
      thunk_FUN_10004e65(*(int32_t *)((int)this + 0x10),arg_3 + 0x100,&local_b4);
    }
    AVIStreamInfoA(*(int32_t *)((int)this + 0xc),local_94,0x8c);
    *(float *)((int)this + 0x24) = (float)((float10)local_7c / (float10)local_80);
    *(int32_t *)((int)this + 0x20) = *(int32_t *)((int)this + 0x24);
    val_1 = thunk_FUN_1000785e(this);
    if (val_1 == 0) {
      val_1 = 0;
    }
  }
  return val_1;
}



int32_t __fastcall AVI_ReleaseVideoStream(int *ptr_1)

{
  thunk_FUN_10001d28(ptr_1);
  thunk_FUN_10007a85(ptr_1);
  thunk_FUN_10007238((int)ptr_1);
  if (ptr_1[3] != 0) {
    AVIStreamRelease(ptr_1[3]);
  }
  if (ptr_1[4] != 0) {
    AVIStreamRelease(ptr_1[4]);
  }
  ptr_1[4] = 0;
  ptr_1[3] = ptr_1[4];
  return 0;
}



int32_t __thiscall AVI_InitTimerPeriod(void *this,int arg_2)

{
  int32_t uval_1;
  timecaps_tag local_c;
  
  if (*(int *)((int)this + 0xc) == 0) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    *(int32_t *)((int)this + 0x18) = 1;
    timeGetDevCaps(&local_c,8);
    if (local_c.wPeriodMin < 2) {
      local_c.wPeriodMin = 1;
    }
    *(UINT *)((int)this + 0x28) = local_c.wPeriodMin;
    timeBeginPeriod(*(UINT *)((int)this + 0x28));
    *(int32_t *)((int)this + 0x1c) = 0;
    thunk_FUN_10007b00(this,arg_2,-1);
    uval_1 = 0;
  }
  else {
    uval_1 = 0xfffffffc;
  }
  return uval_1;
}



int32_t __fastcall AVI_EndTimerPeriod(int32_t *ptr_1)

{
  ptr_1[6] = 0;
  ptr_1[7] = 0;
  thunk_FUN_1000735d();
  thunk_FUN_10007bff(ptr_1);
  timeEndPeriod(ptr_1[10]);
  return 0;
}



int32_t __fastcall AVI_StopPlaybackTimer(int32_t *ptr_1)

{
  ptr_1[6] = 0;
  ptr_1[7] = 1;
  thunk_FUN_10007383();
  thunk_FUN_10007bff(ptr_1);
  timeEndPeriod(ptr_1[10]);
  return 0;
}



int32_t __thiscall AVI_SeekFrameToTime(void *this,int32_t arg_2)

{
  int32_t uval_1;
  int val_2;
  
  if (*(int *)((int)this + 0x18) == 0) {
    *(int32_t *)((int)this + 0x44) = arg_2;
    if (*(int *)((int)this + 0x44) < *(int *)((int)this + 0x54)) {
      *(int32_t *)((int)this + 0x44) = *(int32_t *)((int)this + 0x54);
    }
    else if (*(int *)((int)this + 0x58) < *(int *)((int)this + 0x44)) {
      *(int32_t *)((int)this + 0x44) = *(int32_t *)((int)this + 0x58);
    }
    if (*(int *)((int)this + 0x54) == *(int *)((int)this + 0x44)) {
      *(int32_t *)((int)this + 0x48) = 0xffffffff;
      *(int32_t *)((int)this + 0x4c) = 0xffffffff;
      *(int32_t *)((int)this + 0x50) = 0xffffffff;
    }
    if ((*(int *)((int)this + 0x10) != 0) && (*(int *)((int)this + 0x94) != 0)) {
      uval_1 = AVIStreamSampleToTime(*(int32_t *)((int)this + 0xc),arg_2);
      val_2 = AVIStreamTimeToSample(*(int32_t *)((int)this + 0x10),uval_1);
      *(int *)((int)this + 0x98) = val_2 / *(int *)((int)this + 0x94);
    }
    uval_1 = *(int32_t *)((int)this + 0x44);
  }
  else {
    uval_1 = 0xffffffff;
  }
  return uval_1;
}



int32_t __thiscall AVI_GetNextFrameSample(void *this,int arg_2)

{
  int32_t uval_1;
  int val_2;
  
  if (*(int *)((int)this + 0x18) == 0) {
    *(int *)((int)this + 0x44) = *(int *)((int)this + 0x44) + arg_2;
    if (*(int *)((int)this + 0x44) < *(int *)((int)this + 0x54)) {
      *(int32_t *)((int)this + 0x44) = *(int32_t *)((int)this + 0x54);
    }
    else if (*(int *)((int)this + 0x58) < *(int *)((int)this + 0x44)) {
      *(int32_t *)((int)this + 0x44) = *(int32_t *)((int)this + 0x58);
    }
    if ((*(int *)((int)this + 0x10) != 0) && (*(int *)((int)this + 0x94) != 0)) {
      uval_1 = AVIStreamSampleToTime
                        (*(int32_t *)((int)this + 0xc),*(int32_t *)((int)this + 0x44));
      val_2 = AVIStreamTimeToSample(*(int32_t *)((int)this + 0x10),uval_1);
      *(int *)((int)this + 0x98) = val_2 / *(int *)((int)this + 0x94);
    }
    uval_1 = *(int32_t *)((int)this + 0x44);
  }
  else {
    uval_1 = 0xffffffff;
  }
  return uval_1;
}



int32_t __thiscall FUN_10001f9d(void *this,float arg_2,uint32_t arg_3,int arg_4,int arg_5,int arg_6)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  undefined3 extraout_var;
  uint8_t local_74 [4];
  int local_70;
  int local_6c;
  uint8_t local_4c [4];
  int local_48;
  int local_44;
  uint16_t local_3e;
  int local_38;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_2 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    thunk_FUN_1000b6ff(*(void **)this,local_74);
    thunk_FUN_1000b759(*(void **)this,local_4c);
    thunk_FUN_1000b3b1(*(void **)this,&local_24);
    thunk_FUN_1000b456(*(void **)this,&local_14);
    if (arg_3 == 0) {
      arg_3 = (uint32_t)local_3e;
    }
    if ((((arg_3 == 8) || (arg_3 == 0x10)) || (arg_3 == 0x18)) || (arg_3 == 0x20)) {
      if (0.0 < arg_2) {
        arg_5 = ftol();
        arg_6 = ftol();
      }
      local_3e = (uint16_t)arg_3;
      local_48 = arg_5;
      local_44 = arg_6;
      val_3 = ((int)(arg_6 + 3 + (arg_6 + 3 >> 0x1f & 3U)) >> 2) * arg_5 * arg_3 * 4;
      local_38 = (int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3;
      local_14 = local_24;
      local_c = local_24 + arg_5;
      local_10 = local_20;
      local_8 = local_20 + arg_6;
      val_3 = thunk_FUN_1000b83e(*(void **)this,(int)local_4c,local_24,local_20,local_c + local_24,
                                 local_20 + local_8);
      if (val_3 == 0) {
        thunk_FUN_1000b786(*(void **)this,local_4c);
        thunk_FUN_1000b4a9(*(void **)this,&local_14);
        thunk_FUN_1000b54e(*(void **)this,&local_14);
        if ((arg_4 != 0) &&
           (flag_1 = thunk_FUN_1000bd47(*(void **)this,arg_4), CONCAT31(extraout_var,flag_1) == 0)) {
          return 0xfffffffb;
        }
      }
      else {
        local_48 = local_70;
        local_44 = local_6c;
        val_3 = ((int)(local_6c + 3 + (local_6c + 3 >> 0x1f & 3U)) >> 2) * local_70 * arg_3 * 4;
        local_38 = (int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3;
        val_3 = thunk_FUN_1000b83e(*(void **)this,(int)local_4c,local_24,local_20,
                                   local_1c + local_24,local_20 + local_18);
        if (val_3 != 0) {
          return 0xfffffffb;
        }
        thunk_FUN_1000b786(*(void **)this,local_4c);
        thunk_FUN_1000b4a9(*(void **)this,&local_24);
        thunk_FUN_1000b54e(*(void **)this,&local_14);
      }
      thunk_FUN_100027a0((int)this);
      uval_2 = 0;
    }
    else {
      uval_2 = 0xfffffffb;
    }
  }
  else {
    uval_2 = 0xfffffffc;
  }
  return uval_2;
}



int32_t __thiscall FUN_10002227(void *this,int arg_2)

{
  bool flag_1;
  int32_t uval_2;
  undefined3 extraout_var;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_2 = 0xffffffff;
  }
  else {
    flag_1 = thunk_FUN_1000b99f(*(void **)this,arg_2);
    if (CONCAT31(extraout_var,flag_1) == 0) {
      uval_2 = 0xfffffffb;
    }
    else {
      uval_2 = 0;
    }
  }
  return uval_2;
}



int32_t __thiscall FUN_10002289(void *this,int arg_2)

{
  int32_t uval_1;
  CPrintPreviewState *this_00;
  uint32_t uval_2;
  HWND pHVar3;
  int val_4;
  int32_t *unaff_FS_OFFSET;
  int32_t local_40;
  uint8_t local_38 [14];
  uint16_t local_2a;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100023b6;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    if (arg_2 != 0) {
      thunk_FUN_1000b759(*(void **)this,local_38);
      this_00 = operator_new(0x18);
      local_8 = 0;
      if (this_00 == (CPrintPreviewState *)0x0) {
        local_40 = 0;
      }
      else {
        local_40 = CPrintPreviewState::CPrintPreviewState(this_00);
      }
      local_8 = 0xffffffff;
      *(int32_t *)((int)this + 4) = local_40;
      uval_2 = (uint32_t)local_2a;
      pHVar3 = GetActiveWindow();
      val_4 = (**(code **)**(int32_t **)((int)this + 4))(pHVar3,arg_2,uval_2);
      if (val_4 == 0) {
        uval_1 = 0xfffffffb;
        goto LAB_100023c0;
      }
    }
    val_4 = thunk_FUN_1000bac7(*(void **)this,*(int **)((int)this + 4));
    if (val_4 == 0) {
      uval_1 = 0xfffffffb;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 0xfffffffc;
  }
LAB_100023c0:
  *unaff_FS_OFFSET = local_10;
  return uval_1;
}



int32_t __thiscall FUN_100023d1(void *this,int arg_2)

{
  int32_t uval_1;
  int val_2;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    *(int *)((int)this + 4) = arg_2;
    val_2 = thunk_FUN_1000bac7(*(void **)this,*(int **)((int)this + 4));
    if (val_2 == 0) {
      uval_1 = 0xfffffffb;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 0xfffffffc;
  }
  return uval_1;
}



void __fastcall FUN_100027a0(int arg_1)

{
  *(int32_t *)(arg_1 + 0x48) = 0xffffffff;
  return;
}



void FUN_100027d0(void)

{
  FUN_100027e5();
  return;
}



void FUN_100027e5(void)

{
  thunk_FUN_10004af0((int32_t *)&DAT_100108b0);
  return;
}



/* Library Function - Multiple Matches With Different Base Names
    _$E26
    _$E31
    _$E353
    _$E354
   
   Library: Visual Studio 1998 Debug */

void FID_conflict___E31(void)

{
  FUN_10002819();
  FUN_10002833();
  return;
}



void FUN_10002819(void)

{
  CPrintPreviewState::CPrintPreviewState((CPrintPreviewState *)&DAT_10010850);
  return;
}



void FUN_10002833(void)

{
  _atexit(FUN_10002850);
  return;
}



void FUN_10002850(void)

{
  thunk_FUN_10008774((int32_t *)&DAT_10010850);
  return;
}



int32_t FUN_1000286a(int32_t arg_1,int32_t arg_2)

{
  switch(arg_2) {
  case 0:
    break;
  case 1:
    DAT_1001054c = arg_1;
    break;
  case 2:
    break;
  case 3:
  }
  return 1;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t FUN_100028d4(void)

{
  if (DAT_10010530 == 0) {
    _DAT_10010878 = 3;
    _DAT_1001087c = &LAB_100010be;
    _DAT_10010880 = 0;
    _DAT_10010884 = 0;
    DAT_10010888 = DAT_1001054c;
    _DAT_1001088c = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    _DAT_10010890 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    _DAT_10010894 = 0;
    _DAT_10010898 = 0;
    _DAT_1001089c = PTR_s_VIDWINCLASS_10010534;
    RegisterClassA((WNDCLASSA *)&DAT_10010878);
  }
  thunk_FUN_10004c90(0,0,3);
  DAT_10010530 = DAT_10010530 + 1;
  return 0;
}



int32_t FUN_10002986(void)

{
  if ((DAT_10010530 != 0) && (DAT_10010530 = DAT_10010530 + -1, DAT_10010530 == 0)) {
    UnregisterClassA(PTR_s_VIDWINCLASS_10010534,DAT_10010888);
    thunk_FUN_10004def();
  }
  return 0;
}



int32_t __cdecl FUN_100029cf(LPCSTR x,int *y,short *width,uint32_t height)

{
  int32_t uval_1;
  void *buf_ptr_2;
  int32_t *ptr_1;
  HWND pHVar3;
  int val_4;
  int32_t *unaff_FS_OFFSET;
  int32_t *local_3c;
  LPCSTR local_34;
  DWORD local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10002dae;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  local_1c = 0;
  local_2c = 0;
  local_20 = 0;
  local_24 = 0;
  for (local_28 = 0; (local_28 < 3 && (*(int *)(&DAT_10010868 + local_28 * 4) != 0));
      local_28 = local_28 + 1) {
  }
  if (local_28 == 3) {
    uval_1 = 3;
  }
  else {
    buf_ptr_2 = operator_new(0x70);
    *(void **)(&DAT_10010868 + local_28 * 4) = buf_ptr_2;
    local_18 = *(int **)(&DAT_10010868 + local_28 * 4);
    if (local_18 == (int *)0x0) {
      uval_1 = 3;
    }
    else {
      memset(local_18,0,0x70);
      ptr_1 = operator_new(0x128);
      local_8 = 0;
      if (ptr_1 == (int32_t *)0x0) {
        local_3c = (int32_t *)0x0;
      }
      else {
        local_3c = thunk_FUN_10001740(ptr_1);
      }
      local_8 = 0xffffffff;
      *(int32_t **)(*(int *)(&DAT_10010868 + local_28 * 4) + 8) = local_3c;
      local_14 = *(int *)(*(int *)(&DAT_10010868 + local_28 * 4) + 8);
      if (local_14 == 0) {
        operator_delete(*(void **)(&DAT_10010868 + local_28 * 4));
        *(int32_t *)(&DAT_10010868 + local_28 * 4) = 0;
        uval_1 = 3;
      }
      else {
        if (height == 0) {
          local_1c = -0x80000000;
          local_2c = -0x80000000;
          if (width == (short *)0x0) {
            local_20 = 0;
            local_18[0x16] = 0;
            local_24 = 0;
            local_18[0x16] = 0;
          }
          else {
            local_20 = (int)*width;
            local_18[0x16] = local_20;
            local_24 = (int)width[1];
            local_18[0x17] = local_24;
          }
        }
        else {
          local_1c = GetSystemMetrics(0);
          local_2c = GetSystemMetrics(1);
          local_20 = 0;
          local_18[0x16] = 0;
          local_24 = 0;
          local_18[0x17] = 0;
        }
        if ((height & 4) == 0) {
          DAT_1001053c = (HWND)thunk_FUN_100053fa();
          local_18[6] = (int)DAT_1001053c;
          pHVar3 = CreateWindowExA(0,PTR_s_VIDWINCLASS_10010534,(LPCSTR)0x0,0x90000000,local_20,
                                   local_24,local_1c,local_2c,DAT_1001053c,(HMENU)0x0,DAT_1001054c,
                                   (LPVOID)0x0);
          local_18[4] = (int)pHVar3;
          if (local_18[4] == 0) {
            local_30 = GetLastError();
            FormatMessageA(0x1100,(LPCVOID)0x0,local_30,0x400,(LPSTR)&local_34,0,(va_list *)0x0);
            MessageBoxA((HWND)0x0,local_34,s_GetLastError_10010564,0x40);
            LocalFree(local_34);
          }
          local_18[5] = 1;
        }
        else if ((*(int *)(&DAT_10010868 + *y * 4) != 0) &&
                (*(int *)(*(int *)(&DAT_10010868 + *y * 4) + 0x10) != 0)) {
          local_18[4] = *(int *)(*(int *)(&DAT_10010868 + *y * 4) + 0x10);
          local_18[5] = 0;
        }
        *local_18 = local_28;
        if ((height & 4) == 0) {
          SetFocus(*(HWND *)(*(int *)(&DAT_10010868 + local_28 * 4) + 0x10));
          SetForegroundWindow(*(HWND *)(*(int *)(&DAT_10010868 + local_28 * 4) + 0x10));
          ShowWindow(*(HWND *)(*(int *)(&DAT_10010868 + local_28 * 4) + 0x10),1);
        }
        val_4 = thunk_FUN_10005a5b(local_18,x);
        if (val_4 == 0) {
          *y = local_28;
          uval_1 = 0;
        }
        else {
          if ((height & 4) == 0) {
            DestroyWindow(*(HWND *)(*(int *)(&DAT_10010868 + local_28 * 4) + 0x10));
          }
          operator_delete(*(void **)(&DAT_10010868 + local_28 * 4));
          *(int32_t *)(&DAT_10010868 + local_28 * 4) = 0;
          uval_1 = 1;
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_10;
  return uval_1;
}



int32_t __cdecl FUN_10002dc7(int arg_1)

{
  LPARAM *ptr_1;
  void *this;
  int32_t uval_1;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else {
    ptr_1 = *(LPARAM **)(&DAT_10010868 + arg_1 * 4);
    if (ptr_1 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      if (ptr_1[0x13] != 0) {
        StopAVI(arg_1);
      }
      this = (void *)ptr_1[2];
      if ((((uint32_t)ptr_1[1] >> 3 & 1) != 0) && (ptr_1[0x1a] != 0)) {
        ptr_1[0x12] = 0;
      }
      if (((*(uint8_t *)(ptr_1 + 1) & 1) != 0) && (this != (void *)0x0)) {
        thunk_FUN_10005b92(ptr_1);
        ptr_1[1] = ptr_1[1] & 0xfffffffe;
      }
      if (ptr_1[7] != 0) {
        ReleaseDC((HWND)ptr_1[4],(HDC)ptr_1[7]);
        if (ptr_1[0x19] != 0) {
          *(int32_t *)(ptr_1[0x19] + 0x1c) = 0;
        }
        ptr_1[0x19] = 0;
      }
      if ((ptr_1[4] != 0) && (ptr_1[5] != 0)) {
        DestroyWindow((HWND)ptr_1[4]);
        ptr_1[4] = 0;
        if (ptr_1[0x19] != 0) {
          *(int32_t *)(ptr_1[0x19] + 0x10) = 0;
        }
        ptr_1[5] = 0;
      }
      if (this != (void *)0x0) {
        if (this != (void *)0x0) {
          thunk_FUN_10004b20(this,1);
        }
      }
      if ((ptr_1[0x15] != 0) && (ptr_1[0x14] != 0)) {
        if ((void *)ptr_1[0x14] != (void *)0x0) {
          thunk_FUN_10004b70((void *)ptr_1[0x14],1);
        }
      }
      DAT_1001053c = ptr_1[6];
      operator_delete(ptr_1);
      *(int32_t *)(&DAT_10010868 + arg_1 * 4) = 0;
      uval_1 = 0;
    }
  }
  return uval_1;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t __cdecl FUN_10002fc8(int arg_1)

{
  LPVOID arg_1_00;
  int32_t uval_1;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else {
    arg_1_00 = *(LPVOID *)(&DAT_10010868 + arg_1 * 4);
    if (arg_1_00 == (LPVOID)0x0) {
      uval_1 = 0;
    }
    else {
      if (*(int *)((int)arg_1_00 + 8) != 0) {
        thunk_FUN_10005d8d(arg_1_00);
      }
      _DAT_10010544 = _DAT_10010544 + 1;
      uval_1 = 0;
    }
  }
  return uval_1;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t __cdecl FUN_1000303e(int arg_1)

{
  int arg_1_00;
  int32_t uval_1;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else {
    arg_1_00 = *(int *)(&DAT_10010868 + arg_1 * 4);
    if (arg_1_00 == 0) {
      uval_1 = 0;
    }
    else if ((*(uint32_t *)(arg_1_00 + 4) >> 1 & 1) == 0) {
      if (*(int *)(arg_1_00 + 8) != 0) {
        thunk_FUN_10004f90(arg_1 + 0x100);
        thunk_FUN_10005ef9(arg_1_00);
      }
      _DAT_10010544 = _DAT_10010544 + -1;
      uval_1 = 0;
    }
    else {
      uval_1 = 0;
    }
  }
  return uval_1;
}



int32_t __cdecl FUN_100030dd(int arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uval_1 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg1 * 4) == 0) {
    uval_1 = 5;
  }
  else {
    *(int32_t *)(*(int *)(&DAT_10010868 + arg1 * 4) + 0x6c) = arg2;
    uval_1 = 0;
  }
  return uval_1;
}



int32_t FUN_1000313a(void)

{
  return 0;
}



int32_t __cdecl FUN_1000314c(int arg1,int arg2)

{
  LPARAM *ptr_1;
  int32_t uval_1;
  
  if ((arg2 < 0) || (2 < arg2)) {
    uval_1 = 2;
  }
  else {
    ptr_1 = *(LPARAM **)(&DAT_10010868 + arg2 * 4);
    if (ptr_1 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      thunk_FUN_100065fe(ptr_1,arg1);
      thunk_FUN_10006467(ptr_1);
      thunk_FUN_10006a43(ptr_1);
      uval_1 = 0;
    }
  }
  return uval_1;
}



int32_t __cdecl FUN_100031ce(int *ptr_1,int32_t arg_2,int arg_3)

{
  LPARAM *ptr_1_00;
  int32_t uval_1;
  int val_2;
  CPrintPreviewState *this;
  int32_t *unaff_FS_OFFSET;
  LPARAM local_20;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100032d7;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  if ((arg_3 < 0) || (2 < arg_3)) {
    uval_1 = 2;
  }
  else {
    ptr_1_00 = *(LPARAM **)(&DAT_10010868 + arg_3 * 4);
    if (ptr_1_00 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      if (ptr_1[2] < 0) {
        val_2 = abs(ptr_1[2]);
        ptr_1[2] = val_2;
      }
      this = operator_new(0x18);
      local_8 = 0;
      if (this == (CPrintPreviewState *)0x0) {
        local_20 = 0;
      }
      else {
        local_20 = CPrintPreviewState::CPrintPreviewState(this);
      }
      local_8 = 0xffffffff;
      ptr_1_00[0x14] = local_20;
      thunk_FUN_100089e8((void *)ptr_1_00[0x14],ptr_1,arg_2);
      thunk_FUN_100066d7(ptr_1_00);
      thunk_FUN_10006a43(ptr_1_00);
      uval_1 = 0;
    }
  }
  *unaff_FS_OFFSET = local_10;
  return uval_1;
}



int32_t __cdecl FUN_100032f0(int *ptr_1,int arg_2)

{
  LPARAM *ptr_1_00;
  int32_t uval_1;
  tagRECT local_28;
  int32_t local_18;
  int32_t local_14;
  int local_10;
  int local_c;
  LPARAM local_8;
  
  if ((arg_2 < 0) || (2 < arg_2)) {
    uval_1 = 2;
  }
  else {
    ptr_1_00 = *(LPARAM **)(&DAT_10010868 + arg_2 * 4);
    if (ptr_1_00 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      local_8 = ptr_1_00[2];
      ptr_1_00[0x14] = (LPARAM)ptr_1;
      ptr_1_00[0x15] = 0;
      thunk_FUN_100066d7(ptr_1_00);
      local_28.left = 0;
      local_28.top = 0;
      local_28.right = 0;
      local_28.bottom = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      GetWindowRect((HWND)ptr_1_00[4],&local_28);
      (**(code **)(*ptr_1 + 0x14))(&local_18);
      if (local_10 < local_28.right) {
        ptr_1_00[0x16] = (local_28.right - local_10) / 2;
      }
      if (local_c < local_28.bottom) {
        ptr_1_00[0x17] = (local_28.bottom - local_c) / 2;
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



int32_t __cdecl FUN_10003401(int arg_1)

{
  int val_1;
  int *arg_1_00;
  int32_t uval_2;
  int32_t uval_3;
  int32_t uval_4;
  HDC hDC;
  int32_t uval_5;
  int32_t uval_6;
  int32_t uval_7;
  int32_t uval_8;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_3 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg_1 * 4);
    if (val_1 == 0) {
      uval_3 = 0;
    }
    else {
      arg_1_00 = *(int **)(val_1 + 0x50);
      if (arg_1_00 == (int *)0x0) {
        uval_3 = 2;
      }
      else {
        if (*(int *)(val_1 + 0x10) != 0) {
          uval_4 = DrawDibOpen();
          hDC = GetDC(*(HWND *)(val_1 + 0x10));
          uval_5 = thunk_FUN_10004bc0((int)arg_1_00);
          uval_3 = *(int32_t *)(val_1 + 0x58);
          uval_2 = *(int32_t *)(val_1 + 0x5c);
          uval_6 = (**(code **)(*arg_1_00 + 8))();
          uval_7 = (**(code **)(*arg_1_00 + 0xc))();
          uval_8 = thunk_FUN_10004bf0((int)arg_1_00);
          DrawDibDraw(uval_4,hDC,uval_3,uval_2,uval_6,uval_7,uval_5,uval_8,0,0,uval_6,uval_7,0);
          ReleaseDC(*(HWND *)(val_1 + 0x10),hDC);
          DrawDibClose(uval_4);
        }
        uval_3 = 0;
      }
    }
  }
  return uval_3;
}



int32_t __cdecl FUN_10003525(int *x,short *y,int *width,int height)

{
  int val_1;
  int32_t uval_2;
  
  if (((x == (int *)0x0) || (y == (short *)0x0)) || (width == (int *)0x0)) {
    uval_2 = 2;
  }
  else if ((height < 0) || (2 < height)) {
    uval_2 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + height * 4);
    if ((val_1 == 0) || (*(int *)(val_1 + 0x50) == 0)) {
      uval_2 = 5;
    }
    else {
      (**(code **)(*x + 0x18))
                (*(int32_t *)(val_1 + 0x50),(int)*y,(int)y[1],width[2] - *width,
                 width[3] - width[1],*width,width[1]);
      uval_2 = 0;
    }
  }
  return uval_2;
}



int32_t __cdecl FUN_100035f5(int *ptr_1,int arg_2)

{
  int32_t uval_1;
  
  if ((arg_2 < 0) || (2 < arg_2)) {
    uval_1 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg_2 * 4) == 0) {
    uval_1 = 0;
  }
  else {
    thunk_FUN_1000bc86((void *)**(int32_t **)(*(int *)(&DAT_10010868 + arg_2 * 4) + 8),ptr_1);
    uval_1 = 0;
  }
  return uval_1;
}



int32_t __cdecl FUN_1000365d(int arg_1)

{
  int32_t uval_1;
  DWORD dwStyle;
  BOOL bMenu;
  tagRECT local_3c;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  tagRECT local_14;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else {
    local_2c = *(int *)(&DAT_10010868 + arg_1 * 4);
    if (local_2c == 0) {
      uval_1 = 0;
    }
    else {
      local_18 = *(int **)(local_2c + 8);
      GetClientRect((HWND)local_18[5],&local_3c);
      if (*local_18 == 0) {
        local_24 = 0;
        local_28 = 0;
        local_20 = 0x140;
        local_1c = 0;
      }
      else {
        thunk_FUN_1000b5e0((void *)*local_18,&local_28);
      }
      local_14.top = 0;
      local_14.left = 0;
      local_14.right = local_20 - local_28;
      local_14.bottom = ((local_1c - local_24) - local_3c.top) + local_3c.bottom;
      bMenu = 1;
      dwStyle = GetWindowLongA((HWND)local_18[5],-0x10);
      AdjustWindowRect(&local_14,dwStyle,bMenu);
      SetWindowPos((HWND)local_18[5],(HWND)0x0,0,0,local_14.right - local_14.left,
                   local_14.bottom - local_14.top,0x16);
      uval_1 = 0;
    }
  }
  return uval_1;
}



int32_t __cdecl FUN_10003766(int arg_1)

{
  int val_1;
  int *ptr_1;
  bool flag_2;
  int32_t uval_3;
  undefined3 extraout_var;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_3 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg_1 * 4);
    if (val_1 == 0) {
      uval_3 = 0;
    }
    else {
      ptr_1 = *(int **)(val_1 + 8);
      flag_2 = thunk_FUN_10004c20((int)ptr_1);
      if (CONCAT31(extraout_var,flag_2) == 0) {
        uval_3 = 1;
      }
      else {
        if (ptr_1 != (int *)0x0) {
          if (*(int *)(val_1 + 0x38) != 0) {
            return 0;
          }
          thunk_FUN_10007b00(ptr_1,*(int *)(val_1 + 0x1c),-1);
          thunk_FUN_10007c85(ptr_1);
          thunk_FUN_10007bff(ptr_1);
        }
        uval_3 = 0;
      }
    }
  }
  return uval_3;
}



int32_t __cdecl FUN_1000381e(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  int local_8;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uval_2 = 2;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg1 * 4);
    if (val_1 == 0) {
      uval_2 = 0;
    }
    else {
      if (*(int *)(val_1 + 0x40) != 0) {
        local_8 = SetThreadPriority(*(HANDLE *)(val_1 + 0x40),arg2);
      }
      if (local_8 == 0) {
        uval_2 = 8;
      }
      else {
        uval_2 = 0;
      }
    }
  }
  return uval_2;
}



int32_t __cdecl FUN_100038a4(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uval_2 = 2;
  }
  else if ((arg2 < 0) || (2 < arg2)) {
    uval_2 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg1 * 4) == 0) {
    uval_2 = 5;
  }
  else {
    val_1 = *(int *)(&DAT_10010868 + arg2 * 4);
    if (val_1 == 0) {
      uval_2 = 5;
    }
    else {
      *(int *)(*(int *)(&DAT_10010868 + arg1 * 4) + 100) = val_1;
      *(int32_t *)(val_1 + 0x68) = 1;
      uval_2 = 0;
    }
  }
  return uval_2;
}



int32_t __cdecl FUN_1000394a(int arg1,short *arg2)

{
  int arg_1;
  int32_t uval_1;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int32_t *local_8;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uval_1 = 2;
  }
  else {
    arg_1 = *(int *)(&DAT_10010868 + arg1 * 4);
    if (arg_1 == 0) {
      uval_1 = 0;
    }
    else {
      local_8 = *(int32_t **)(arg_1 + 8);
      if (local_8 == (int32_t *)0x0) {
        uval_1 = 2;
      }
      else if (*(int *)(arg_1 + 0x50) == 0) {
        uval_1 = 2;
      }
      else {
        thunk_FUN_100063e6(arg_1,(int)*arg2,(int)arg2[1]);
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
        local_c = 0;
        thunk_FUN_1000b4fb((void *)*local_8,&local_18);
        *arg2 = *arg2 + (short)*(int32_t *)(arg_1 + 0x58);
        arg2[1] = arg2[1] + (short)*(int32_t *)(arg_1 + 0x5c);
        local_18 = local_18 + *arg2;
        local_14 = local_14 + arg2[1];
        local_10 = local_10 + *arg2;
        local_c = local_c + arg2[1];
        thunk_FUN_1000b54e((void *)*local_8,&local_18);
        uval_1 = 0;
      }
    }
  }
  return uval_1;
}



int32_t __cdecl FUN_10003a7e(int arg_1)

{
  int32_t uval_1;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg_1 * 4) == 0) {
    uval_1 = 0;
  }
  else {
    uval_1 = *(int32_t *)(*(int *)(&DAT_10010868 + arg_1 * 4) + 0x38);
  }
  return uval_1;
}



void FUN_10003ad3(HWND x,uint32_t y,WPARAM width,int height)

{
  int val_1;
  int local_14;
  LRESULT local_10;
  HDC local_c;
  HANDLE local_8;
  
  if (y < 0x15) {
    if (y == 0x14) {
      if (DAT_10010550 != 0) {
        local_10 = DefWindowProcA(x,0x14,width,height);
        local_c = GetDC(x);
        DAT_10010554 = SetSystemPaletteUse(local_c,1);
        ReleaseDC(x,local_c);
        DAT_10010550 = 0;
      }
      local_14 = -1;
      val_1 = thunk_FUN_10004249((int)x,&local_14);
      if (val_1 == 0) {
        DrawVidBackground(local_14);
      }
    }
    else {
      switch(y) {
      case 1:
        break;
      case 2:
        DAT_10010550 = 1;
        local_c = GetDC(x);
        SetSystemPaletteUse(local_c,DAT_10010554);
        ReleaseDC(x,local_c);
        DAT_10010550 = 1;
        break;
      case 5:
        InvalidateRect(x,(RECT *)0x0,0);
        break;
      case 7:
        local_8 = GetCurrentProcess();
        SetPriorityClass(local_8,0x80);
        break;
      case 8:
        local_8 = GetCurrentProcess();
        SetPriorityClass(local_8,0x20);
        break;
      case 0xf:
        InvalidateRect(x,(RECT *)0x0,0);
      }
    }
  }
  else if (y != 0x202) {
    if (y == 0x311) {
      InvalidateRect(x,(RECT *)0x0,0);
    }
    else if (((y == 0x401) && (*(int *)(&DAT_10010868 + height * 4) != 0)) &&
            (*(int *)(*(int *)(&DAT_10010868 + height * 4) + 0x50) == 0)) {
      thunk_FUN_10006020(*(int *)(&DAT_10010868 + height * 4));
    }
  }
  DefWindowProcA(x,y,width,height);
  return;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_10003d1b(HWND x,uint32_t y,uint32_t width,LPVOID height)

{
  int val_1;
  LRESULT LVar2;
  int local_58;
  LPVOID local_54;
  HDC local_50;
  tagPAINTSTRUCT local_4c;
  int local_c;
  uint32_t local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      val_1 = thunk_FUN_10004249((int)x,&local_58);
      if (val_1 == 0) {
        local_50 = BeginPaint(x,&local_4c);
        if (*(int *)(&DAT_10010868 + local_58 * 4) != 0) {
          thunk_FUN_10005c78(*(int *)(&DAT_10010868 + local_58 * 4),(int)local_50);
        }
        EndPaint(x,&local_4c);
        DrawVidBackground(local_58);
      }
    }
    else if (y == 1) {
      _DAT_100108a8 = 0;
    }
    else {
      if (y != 2) goto switchD_10004133_caseD_312;
      val_1 = thunk_FUN_10004249((int)x,&local_58);
      if ((val_1 == 0) &&
         (thunk_FUN_10005b92(*(LPARAM **)(&DAT_10010868 + local_58 * 4)),
         *(int *)(&DAT_10010868 + local_58 * 4) != 0)) {
        thunk_FUN_100059e8(*(int *)(&DAT_10010868 + local_58 * 4));
      }
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      local_8 = width & 0xffff;
      local_54 = height;
      switch(local_8) {
      case 0x9c43:
        thunk_FUN_10005d8d(height);
        break;
      case 0x9c44:
        if (*(int *)(&DAT_10010868 + (int)height * 4) != 0) {
          thunk_FUN_10005ef9(*(int *)(&DAT_10010868 + (int)height * 4));
        }
        break;
      default:
        LVar2 = DefWindowProcA(x,0x111,width,(LPARAM)height);
        return LVar2;
      case 0x9c66:
        break;
      case 0x9c67:
      }
    }
    else {
      if (y != 0x14) goto switchD_10004133_caseD_312;
      val_1 = thunk_FUN_10004249((int)x,&local_58);
      if (val_1 == 0) {
        DrawVidBackground(local_58);
      }
    }
  }
  else if (y < 0x310) {
    if (y != 0x30f) {
      if (y == 0x202) {
        for (local_c = 0; local_c < 3; local_c = local_c + 1) {
          if ((*(int *)(&DAT_10010868 + local_c * 4) != 0) &&
             (*(HWND *)(*(int *)(&DAT_10010868 + local_c * 4) + 0x10) == x)) {
            *(int32_t *)(*(int *)(&DAT_10010868 + local_c * 4) + 0x10) = 0;
          }
        }
        DestroyWindow(x);
      }
      else if (y != 0x204) goto switchD_10004133_caseD_312;
    }
  }
  else {
    switch(y) {
    case 0x311:
      val_1 = thunk_FUN_10004249((int)x,&local_58);
      if (((val_1 == 0) &&
          (thunk_FUN_10005ce8(*(int *)(&DAT_10010868 + local_58 * 4),width),
          *(int *)(*(int *)(&DAT_10010868 + local_58 * 4) + 0x38) == 0)) &&
         (*(uint32_t *)(*(int *)(&DAT_10010868 + local_58 * 4) + 0x10) != width)) {
        InvalidateRect(x,(RECT *)0x0,0);
      }
      break;
    default:
switchD_10004133_caseD_312:
      LVar2 = DefWindowProcA(x,y,width,(LPARAM)height);
      return LVar2;
    case 0x3bb:
    case 0x3bc:
    case 0x3bd:
      thunk_FUN_10005fee();
      break;
    case 0x401:
      if ((*(int *)(&DAT_10010868 + (int)height * 4) != 0) &&
         (*(int *)(*(int *)(&DAT_10010868 + (int)height * 4) + 0x50) == 0)) {
        thunk_FUN_10006020(*(int *)(&DAT_10010868 + (int)height * 4));
      }
      val_1 = thunk_FUN_10004249((int)x,&local_58);
      if (val_1 == 0) {
        DrawVidBackground(local_58);
      }
    }
  }
  return 0;
}



int32_t __cdecl FUN_10004249(int arg1,int *arg2)

{
  int val_1;
  bool flag_2;
  int32_t uval_3;
  int local_8;
  
  local_8 = 0;
  do {
    if ((*(int *)(&DAT_10010868 + local_8 * 4) == 0) ||
       (*(int *)(*(int *)(&DAT_10010868 + local_8 * 4) + 0x10) == arg1)) break;
    val_1 = local_8 + 1;
    flag_2 = local_8 < 3;
    local_8 = val_1;
  } while (flag_2);
  if (local_8 < 3) {
    *arg2 = local_8;
    uval_3 = 0;
  }
  else {
    uval_3 = 2;
  }
  return uval_3;
}



int32_t __cdecl FUN_100042c0(int arg_1)

{
  int arg_1_00;
  int32_t uval_1;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg_1 * 4) == 0) {
    uval_1 = 0;
  }
  else {
    arg_1_00 = *(int *)(*(int *)(&DAT_10010868 + arg_1 * 4) + 8);
    if (arg_1_00 == 0) {
      uval_1 = 2;
    }
    else {
      thunk_FUN_10004c60(arg_1_00);
      uval_1 = 0;
    }
  }
  return uval_1;
}



int32_t __cdecl FUN_10004344(int arg1,int arg2)

{
  int *i_ptr_1;
  int32_t uval_2;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uval_2 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg1 * 4) == 0) {
    uval_2 = 0;
  }
  else {
    i_ptr_1 = *(int **)(*(int *)(&DAT_10010868 + arg1 * 4) + 8);
    if (i_ptr_1 == (int *)0x0) {
      uval_2 = 2;
    }
    else if (*i_ptr_1 == 0) {
      uval_2 = 2;
    }
    else {
      thunk_FUN_1000bbec((void *)*i_ptr_1,arg2);
      uval_2 = 0;
    }
  }
  return uval_2;
}



int32_t * __fastcall FUN_10004af0(int32_t *ptr_1)

{
  *ptr_1 = 0;
  return ptr_1;
}



int * __thiscall DeckDll_SideboardWndProc(void *this,uint8_t arg_2)

{
  thunk_FUN_10001926(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



int32_t * __thiscall FUN_10004b70(void *this,uint8_t arg_2)

{
  thunk_FUN_10008774(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



int32_t __fastcall FUN_10004bc0(int arg_1)

{
  return *(int32_t *)(arg_1 + 4);
}



int32_t __fastcall FUN_10004bf0(int arg_1)

{
  return *(int32_t *)(arg_1 + 8);
}



bool __fastcall FUN_10004c20(int arg_1)

{
  return *(int *)(arg_1 + 8) != 0;
}



void __fastcall FUN_10004c60(int arg_1)

{
  *(int *)(arg_1 + 0x44) = *(int *)(arg_1 + 0x44) + 1;
  return;
}



int __cdecl FUN_10004c90(int arg_1,int32_t arg_2,uint32_t arg_3)

{
  int val_1;
  FARPROC pFVar2;
  int local_c;
  
  if (DAT_10010584 == 0) {
    DAT_10032c44 = LoadLibraryA(PTR_s_magsnd_1001058c);
    if (DAT_10032c44 == (HMODULE)0x0) {
      val_1 = 4;
    }
    else {
      for (local_c = 0; local_c < 0x1b; local_c = local_c + 1) {
        pFVar2 = GetProcAddress(DAT_10032c44,(LPCSTR)(local_c + 1U & 0xffff));
        (&DAT_10032c70)[local_c] = pFVar2;
        if ((&DAT_10032c70)[local_c] == (code *)0x0) {
          FreeLibrary(DAT_10032c44);
          thunk_FUN_100054bc();
          return 4;
        }
      }
      if ((arg_1 == 0) && ((arg_3 & 2) == 0)) {
        FreeLibrary(DAT_10032c44);
        thunk_FUN_100054bc();
        val_1 = 5;
      }
      else {
        val_1 = (*DAT_10032c70)(arg_1,arg_2,arg_3);
        if (val_1 == 0) {
          DAT_10010588 = 1;
          if ((arg_3 & 2) != 0) {
            DAT_10010580 = 1;
          }
          DAT_10010584 = 1;
          val_1 = 0;
        }
        else {
          FreeLibrary(DAT_10032c44);
          thunk_FUN_100054bc();
        }
      }
    }
  }
  else {
    val_1 = 2;
  }
  return val_1;
}



void FUN_10004def(void)

{
  if (DAT_10010584 != 0) {
    DAT_10010584 = 0;
    if ((DAT_10010588 != 0) && (DAT_10010580 == 0)) {
      (*DAT_10032c74)();
    }
    FreeLibrary(DAT_10032c44);
    thunk_FUN_100054bc();
    DAT_10032c44 = (HMODULE)0x0;
    DAT_10010580 = 0;
    DAT_10010588 = 0;
  }
  return;
}



int32_t __cdecl FUN_10004e65(int32_t arg_1,int32_t arg_2,int32_t arg_3)

{
  int32_t uval_1;
  
  if (DAT_10010584 == 0) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c78)(arg_1,arg_2,arg_3);
  }
  return uval_1;
}



int32_t __cdecl FUN_10004ea1(int32_t arg_1)

{
  int32_t uval_1;
  
  if (DAT_10010584 == 0) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c7c)(arg_1);
  }
  return uval_1;
}



int32_t FUN_10004ed5(void)

{
  int32_t uval_1;
  
  if (DAT_10010584 == 0) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c80)();
  }
  return uval_1;
}



int32_t __cdecl FUN_10004f02(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c84)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_10004f47(int32_t arg_1,int32_t arg_2,int32_t arg_3)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c88)(arg_1,arg_2,arg_3);
  }
  return uval_1;
}



int32_t __cdecl FUN_10004f90(int32_t arg_1)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c8c)(arg_1);
  }
  return uval_1;
}



void FUN_10004fd1(void)

{
  if ((DAT_10010584 != 0) && (DAT_10010584 != 2)) {
    (*DAT_10032c90)();
  }
  return;
}



int32_t __cdecl FUN_10005001(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c94)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_10005046(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c98)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_1000508b(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032c9c)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_100050d0(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032ca0)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_10005115(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032ca4)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_1000515a(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032ca8)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_1000519f(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032cac)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t FUN_100051e4(void)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032cb0)();
  }
  return uval_1;
}



int32_t __cdecl FUN_1000521e(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032cb4)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_10005263(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032cb8)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_100052a8(int32_t arg_1)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032cc0)(arg_1);
  }
  return uval_1;
}



int32_t __cdecl FUN_100052e9(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032cbc)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_1000532e(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032cc4)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_10005373(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_10032cc8)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_100053b5(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032ccc)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t FUN_100053fa(void)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_10032cd0)();
  }
  return uval_1;
}



int32_t __cdecl FUN_10005431(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_10032cd4)(arg_1,arg_2);
  }
  return uval_1;
}



int32_t __cdecl FUN_10005473(int32_t arg_1,int32_t arg_2,int32_t arg_3)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032cd8)(arg_1,arg_2,arg_3);
  }
  return uval_1;
}



void FUN_100054bc(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x1b; local_8 = local_8 + 1) {
    (&DAT_10032c70)[local_8] = 0;
  }
  return;
}



void __cdecl FUN_10005710(LPARAM *ptr_1)

{
  bool flag_1;
  bool flag_2;
  int val_3;
  LPARAM *local_18;
  
  flag_1 = false;
  flag_2 = false;
  if (ptr_1[2] != 0) {
    local_18 = ptr_1;
    ptr_1[0x13] = 1;
    while ((local_18 != (LPARAM *)0x0 && (local_18[0x12] != 0))) {
      EnterCriticalSection((LPCRITICAL_SECTION)(local_18 + 8));
      if (local_18[0xe] == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(local_18 + 8));
        Sleep(5);
      }
      else {
        val_3 = CArchive::IsBufferEmpty((CArchive *)local_18[2]);
        if (val_3 == 0) {
          thunk_FUN_10007c85((int *)local_18[2]);
          LeaveCriticalSection((LPCRITICAL_SECTION)(local_18 + 8));
          if (((!flag_1) || (flag_2)) || (_delay == 0)) {
            if (!flag_2) {
              thunk_FUN_10004f02(*ptr_1 + 0x100,0);
              flag_2 = true;
            }
          }
          else {
            thunk_FUN_10007bde((void *)local_18[2],1000);
            thunk_FUN_10004f02(*ptr_1 + 0x100,0);
            flag_2 = true;
            _delay = 0;
          }
          flag_1 = true;
          Sleep(1);
        }
        else {
          local_18[0xe] = 0;
          LeaveCriticalSection((LPCRITICAL_SECTION)(local_18 + 8));
          PostMessageA(*(HWND *)(local_18[2] + 0x14),0x111,0x9c44,*local_18);
          if (local_18[0x19] == 0) {
            local_18 = (LPARAM *)0x0;
          }
          else {
            PostMessageA(*(HWND *)(local_18[2] + 0x14),0x111,0x9c67,*(LPARAM *)local_18[0x19]);
            local_18 = (LPARAM *)local_18[0x19];
          }
        }
      }
    }
    thunk_FUN_10004f90(*ptr_1 + 0x100);
    thunk_FUN_10004ea1(*ptr_1 + 0x100);
    ptr_1[0x13] = 0;
  }
  return;
}



void __cdecl FUN_1000592b(int arg_1)

{
  int32_t *ptr_1;
  int32_t *unaff_FS_OFFSET;
  int32_t *local_18;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100059d0;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  *(int32_t *)(arg_1 + 0x3c) = 0;
  *(int32_t *)(arg_1 + 0x38) = *(int32_t *)(arg_1 + 0x3c);
  *(int32_t *)(arg_1 + 0x40) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(arg_1 + 0x20));
  ptr_1 = operator_new(0x128);
  local_8 = 0;
  if (ptr_1 == (int32_t *)0x0) {
    local_18 = (int32_t *)0x0;
  }
  else {
    local_18 = thunk_FUN_10001740(ptr_1);
  }
  *(int32_t **)(arg_1 + 8) = local_18;
  *unaff_FS_OFFSET = local_10;
  return;
}



void __cdecl FUN_100059e8(int arg_1)

{
  if (*(int *)(arg_1 + 0x40) != 0) {
    *(int32_t *)(arg_1 + 0x48) = 0;
    *(int32_t *)(arg_1 + 0x40) = 0;
  }
  if (*(int *)(arg_1 + 8) != 0) {
    if (*(void **)(arg_1 + 8) != (void *)0x0) {
      thunk_FUN_10004b20(*(void **)(arg_1 + 8),1);
    }
    *(int32_t *)(arg_1 + 8) = 0;
  }
  return;
}



int32_t __cdecl FUN_10005a5b(LPARAM *ptr_1,LPCSTR arg_2)

{
  void *this;
  bool flag_1;
  int32_t uval_2;
  HANDLE hFile;
  DWORD DVar3;
  undefined3 extraout_var;
  int val_4;
  
  if ((ptr_1 == (LPARAM *)0x0) || (ptr_1[2] == 0)) {
    uval_2 = 2;
  }
  else {
    this = (void *)ptr_1[2];
    hFile = (HANDLE)_lopen(arg_2,0);
    if (hFile == (HANDLE)0xffffffff) {
      uval_2 = 1;
    }
    else {
      DVar3 = GetFileSize(hFile,(LPDWORD)0x0);
      ptr_1[0x18] = DVar3;
      ptr_1[0x18] = (int)(ptr_1[0x18] + (ptr_1[0x18] >> 0x1f & 0x3ffU)) >> 10;
      _lclose((HFILE)hFile);
      flag_1 = thunk_FUN_10004c20((int)this);
      if (CONCAT31(extraout_var,flag_1) != 0) {
        thunk_FUN_10005b92(ptr_1);
      }
      val_4 = thunk_FUN_10001951(this,arg_2);
      if (val_4 == 0) {
        val_4 = thunk_FUN_10001a02(this,ptr_1[4],*ptr_1);
        if (val_4 == 0) {
          ptr_1[1] = ptr_1[1] | 1;
          PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
          InitializeCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
          uval_2 = 0;
        }
        else {
          uval_2 = 1;
        }
      }
      else {
        uval_2 = 1;
      }
    }
  }
  return uval_2;
}



void __cdecl FUN_10005b92(LPARAM *ptr_1)

{
  int *ptr_1_00;
  bool flag_1;
  undefined3 extraout_var;
  
  if ((ptr_1 != (LPARAM *)0x0) && (ptr_1[2] != 0)) {
    ptr_1_00 = (int *)ptr_1[2];
    if (ptr_1_00 != (int *)0x0) {
      flag_1 = thunk_FUN_10004c20((int)ptr_1_00);
      if (CONCAT31(extraout_var,flag_1) == 0) {
        return;
      }
      if (((uint32_t)ptr_1[1] >> 1 & 1) != 0) {
        thunk_FUN_10005ef9((int)ptr_1);
      }
      if (ptr_1[0x10] != 0) {
        ptr_1[0x12] = 0;
        ptr_1[0x10] = 0;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
      thunk_FUN_10001c16(ptr_1_00);
      thunk_FUN_100019c7((int)ptr_1_00);
      LeaveCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
    PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
  }
  return;
}



void __cdecl FUN_10005c78(int arg1,int arg2)

{
  int *ptr_1;
  bool flag_1;
  undefined3 extraout_var;
  
  ptr_1 = *(int **)(arg1 + 8);
  flag_1 = thunk_FUN_10004c20((int)ptr_1);
  if (((CONCAT31(extraout_var,flag_1) != 0) && (ptr_1 != (int *)0x0)) && (*(int *)(arg1 + 0x38) == 0)
     ) {
    thunk_FUN_10007b00(ptr_1,arg2,-1);
    thunk_FUN_10007c85(ptr_1);
    thunk_FUN_10007bff(ptr_1);
  }
  return;
}



void __cdecl FUN_10005ce8(int arg1,int arg2)

{
  int *i_ptr_1;
  HPALETTE hPal;
  
  i_ptr_1 = *(int **)(arg1 + 8);
  if ((((i_ptr_1 != (int *)0x0) && (*i_ptr_1 != 0)) && (*(int *)(arg1 + 0x10) != arg2)) &&
     (*(int *)(*i_ptr_1 + 0x194) != 0)) {
    hPal = SelectPalette((HDC)i_ptr_1[0xc],*(HPALETTE *)(*i_ptr_1 + 0x194),0);
    RealizePalette((HDC)i_ptr_1[0xc]);
    if (hPal != (HPALETTE)0x0) {
      SelectPalette((HDC)i_ptr_1[0xc],hPal,0);
    }
  }
  return;
}



void __cdecl FUN_10005d8d(LPVOID arg_1)

{
  void *this;
  bool flag_1;
  undefined3 extraout_var;
  HANDLE buf_ptr_2;
  HDC arg_2;
  
  if ((((arg_1 != (LPVOID)0x0) && (*(int *)((int)arg_1 + 8) != 0)) &&
      (this = *(void **)((int)arg_1 + 8), this != (void *)0x0)) &&
     ((flag_1 = thunk_FUN_10004c20((int)this), CONCAT31(extraout_var,flag_1) != 0 &&
      (*(int *)((int)arg_1 + 0x38) == 0)))) {
    *(int32_t *)((int)arg_1 + 0x48) = 1;
    if ((*(int *)((int)arg_1 + 0x3c) == 0) &&
       ((*(int *)((int)arg_1 + 0x40) == 0 && ((*(uint32_t *)((int)arg_1 + 4) >> 3 & 1) == 0)))) {
      buf_ptr_2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_10001005,arg_1
                            ,0,(LPDWORD)((int)arg_1 + 0x44));
      *(HANDLE *)((int)arg_1 + 0x40) = buf_ptr_2;
    }
    if (*(int *)((int)arg_1 + 100) != 0) {
      *(uint32_t *)(*(int *)((int)arg_1 + 100) + 4) = *(uint32_t *)(*(int *)((int)arg_1 + 100) + 4) | 8;
      *(int32_t *)(*(int *)((int)arg_1 + 100) + 0x40) = *(int32_t *)((int)arg_1 + 0x40);
      *(int32_t *)(*(int *)((int)arg_1 + 100) + 0x44) = *(int32_t *)((int)arg_1 + 0x44);
      *(int32_t *)(*(int *)((int)arg_1 + 100) + 0x48) = 1;
    }
    arg_2 = GetDC(*(HWND *)((int)arg_1 + 0x10));
    thunk_FUN_10001c8e(this,(int)arg_2);
    SetThreadPriority(*(HANDLE *)((int)arg_1 + 0x40),1);
    EnterCriticalSection((LPCRITICAL_SECTION)((int)arg_1 + 0x20));
    *(int32_t *)((int)arg_1 + 0x3c) = 0;
    *(int32_t *)((int)arg_1 + 0x38) = 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)arg_1 + 0x20));
  }
  return;
}



void __cdecl FUN_10005ef9(int arg_1)

{
  int32_t *ptr_1;
  HDC hDC;
  bool flag_1;
  undefined3 extraout_var;
  HANDLE hProcess;
  
  ptr_1 = *(int32_t **)(arg_1 + 8);
  if ((ptr_1 != (int32_t *)0x0) &&
     (flag_1 = thunk_FUN_10004c20((int)ptr_1), CONCAT31(extraout_var,flag_1) != 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(arg_1 + 0x20));
    *(int32_t *)(arg_1 + 0x3c) = 0;
    *(int32_t *)(arg_1 + 0x38) = 0;
    hDC = (HDC)ptr_1[0xc];
    thunk_FUN_10001d28(ptr_1);
    if (*(int *)(arg_1 + 100) == 0) {
      hProcess = GetCurrentProcess();
      SetPriorityClass(hProcess,0x20);
      if (*(int *)(arg_1 + 0x48) != 0) {
        *(int32_t *)(arg_1 + 0x48) = 0;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(arg_1 + 0x20));
      CloseHandle(*(HANDLE *)(arg_1 + 0x40));
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)(arg_1 + 0x20));
    }
    thunk_FUN_10007050((int)ptr_1);
    if (hDC != (HDC)0x0) {
      ReleaseDC(*(HWND *)(arg_1 + 0x10),hDC);
    }
  }
  return;
}



void FUN_10005fee(void)

{
  return;
}



void __cdecl FUN_10006020(int arg_1)

{
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((arg_1 != 0) && (*(int *)(arg_1 + 8) != 0)) {
    local_18 = *(int **)(arg_1 + 8);
    if (*local_18 == 0) {
      local_24 = 0;
      local_28 = 0;
      local_20 = 0x140;
      local_1c = 0;
    }
    else {
      thunk_FUN_1000b5e0((void *)*local_18,&local_28);
    }
    local_14 = local_28;
    local_c = local_20;
    local_8 = local_1c;
    local_10 = local_24;
    SetWindowPos(*(HWND *)(arg_1 + 0x10),(HWND)0x0,*(int *)(arg_1 + 0x58) + local_28,
                 *(int *)(arg_1 + 0x5c) + local_24,local_20 - local_28,local_1c - local_24,0x16);
  }
  return;
}



void __cdecl FUN_100060dd(HWND hwnd)

{
  HMENU pHVar1;
  
  DAT_1001bf38 = (uint32_t)(DAT_1001bf38 == 0);
  pHVar1 = GetMenu(hwnd);
  pHVar1 = GetSubMenu(pHVar1,1);
  CheckMenuItem(pHVar1,0x9c55,(DAT_1001bf38 == 0) - 1 & 8);
  return;
}



void __cdecl FUN_10006154(LPVOID arg_1,int arg_2)

{
  void *this;
  HWND hWnd;
  bool flag_1;
  HDC hdc;
  int val_2;
  undefined3 extraout_var;
  uint32_t local_14;
  
  if ((arg_1 != (LPVOID)0x0) && (*(int *)((int)arg_1 + 8) != 0)) {
    this = *(void **)((int)arg_1 + 8);
    hWnd = *(HWND *)((int)arg_1 + 0x10);
    if (DAT_1001059c == 0) {
      hdc = GetDC(hWnd);
      val_2 = GetDeviceCaps(hdc,0xc);
      if (val_2 == 0x10) {
        DAT_1001059c = 0x9c49;
      }
      else if (val_2 == 0x18) {
        DAT_1001059c = 0x9c4c;
      }
      else if (val_2 == 0x20) {
        DAT_1001059c = 0x9c4d;
      }
      else {
        DAT_1001059c = 0x9c48;
      }
      ReleaseDC(hWnd,hdc);
    }
    if (arg_2 == 0) {
      arg_2 = DAT_1001059c;
    }
    if (arg_2 < 0) {
      arg_2 = DAT_100105a0;
    }
    DAT_100105a0 = arg_2;
    flag_1 = thunk_FUN_10004c20((int)this);
    if (CONCAT31(extraout_var,flag_1) != 0) {
      if (arg_2 == 0x9c48) {
        local_14 = 8;
      }
      else if (arg_2 == 0x9c49) {
        local_14 = 0x10;
      }
      else if (arg_2 == 0x9c4c) {
        local_14 = 0x18;
      }
      else if (arg_2 == 0x9c4d) {
        local_14 = 0x20;
      }
      else {
        local_14 = 0;
      }
      flag_1 = *(int *)((int)arg_1 + 0x38) != 0;
      if (flag_1) {
        thunk_FUN_10005ef9((int)arg_1);
      }
      val_2 = thunk_FUN_10001f9d(this,1.0,local_14,0,0,0);
      if (val_2 != 0) {
        thunk_FUN_10001f9d(this,1.0,8,1,0,0);
      }
      if (flag_1) {
        thunk_FUN_10005d8d(arg_1);
      }
    }
  }
  return;
}



int32_t __cdecl FUN_1000634a(int arg_1,LONG arg_2,LONG arg_3)

{
  int32_t *arg_1_00;
  POINT pt;
  bool flag_1;
  int32_t uval_2;
  undefined3 extraout_var;
  int val_3;
  BOOL BVar4;
  RECT local_14;
  
  if ((arg_1 == 0) || (*(int *)(arg_1 + 8) == 0)) {
    uval_2 = 2;
  }
  else {
    arg_1_00 = *(int32_t **)(arg_1 + 8);
    flag_1 = thunk_FUN_10004c20((int)arg_1_00);
    if (CONCAT31(extraout_var,flag_1) == 0) {
      uval_2 = 0;
    }
    else {
      val_3 = thunk_FUN_1000b685((void *)*arg_1_00,&local_14.left);
      if ((val_3 == 0) && (pt.y = arg_3, pt.x = arg_2, BVar4 = PtInRect(&local_14,pt), BVar4 != 0))
      {
        return 1;
      }
      uval_2 = 0;
    }
  }
  return uval_2;
}



void __cdecl FUN_100063e6(int arg_1,int arg_2,int arg_3)

{
  int32_t *arg_1_00;
  bool flag_1;
  undefined3 extraout_var;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((arg_1 != 0) && (*(int *)(arg_1 + 8) != 0)) {
    arg_1_00 = *(int32_t **)(arg_1 + 8);
    flag_1 = thunk_FUN_10004c20((int)arg_1_00);
    if (CONCAT31(extraout_var,flag_1) != 0) {
      thunk_FUN_1000b456((void *)*arg_1_00,&local_14);
      local_10 = local_10 + arg_3;
      local_8 = local_8 + arg_3;
      local_c = local_c + arg_2;
      local_14 = local_14 + arg_2;
      thunk_FUN_1000b4a9((void *)*arg_1_00,&local_14);
    }
  }
  return;
}



void __cdecl FUN_10006467(LPARAM *ptr_1)

{
  void *this;
  int val_1;
  bool flag_2;
  undefined3 extraout_var;
  int16_t *ptr_1_00;
  int val_3;
  uint8_t *local_18;
  int local_14;
  
  if ((ptr_1 != (LPARAM *)0x0) && (ptr_1[2] != 0)) {
    this = (void *)ptr_1[2];
    flag_2 = thunk_FUN_10004c20((int)this);
    if ((CONCAT31(extraout_var,flag_2) != 0) &&
       ((*(int *)((int)this + 4) != 0 &&
        (ptr_1_00 = operator_new(0x408), ptr_1_00 != (int16_t *)0x0)))) {
      local_18 = (uint8_t *)thunk_FUN_10007080(*(int *)((int)this + 4));
      for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
        *(uint8_t *)(ptr_1_00 + local_14 * 2 + 2) = local_18[2];
        *(uint8_t *)((int)ptr_1_00 + local_14 * 4 + 5) = local_18[1];
        *(uint8_t *)(ptr_1_00 + local_14 * 2 + 3) = *local_18;
        *(uint8_t *)((int)ptr_1_00 + local_14 * 4 + 7) = 4;
        local_18 = local_18 + 4;
      }
      *ptr_1_00 = 0x300;
      ptr_1_00[1] = 0x100;
      val_1 = ptr_1[0xe];
      if (val_1 != 0) {
        thunk_FUN_10005ef9((int)ptr_1);
      }
      val_3 = thunk_FUN_10002227(this,(int)ptr_1_00);
      if (val_3 == 0) {
        thunk_FUN_10005ce8((int)ptr_1,0);
      }
      if (val_1 != 0) {
        thunk_FUN_10005d8d(ptr_1);
      }
      PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
      if (ptr_1_00 != (int16_t *)0x0) {
        operator_delete(ptr_1_00);
      }
    }
  }
  return;
}



int32_t __cdecl FUN_100065fe(LPARAM *ptr_1,int arg_2)

{
  void *this;
  int val_1;
  bool flag_2;
  int32_t uval_3;
  undefined3 extraout_var;
  
  if ((ptr_1 == (LPARAM *)0x0) || (ptr_1[2] == 0)) {
    uval_3 = 2;
  }
  else {
    this = (void *)ptr_1[2];
    flag_2 = thunk_FUN_10004c20((int)this);
    if (CONCAT31(extraout_var,flag_2) == 0) {
      uval_3 = 1;
    }
    else if (arg_2 == 0) {
      uval_3 = 1;
    }
    else {
      val_1 = ptr_1[0xe];
      if (val_1 != 0) {
        thunk_FUN_10005ef9((int)ptr_1);
      }
      thunk_FUN_10002289(this,arg_2);
      if (val_1 != 0) {
        thunk_FUN_10005d8d(ptr_1);
      }
      PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
      uval_3 = 0;
    }
  }
  return uval_3;
}



int32_t __cdecl FUN_100066d7(LPARAM *ptr_1)

{
  void *this;
  int arg_2;
  int val_1;
  bool flag_2;
  int32_t uval_3;
  undefined3 extraout_var;
  
  if ((ptr_1 == (LPARAM *)0x0) || (ptr_1[2] == 0)) {
    uval_3 = 2;
  }
  else {
    this = (void *)ptr_1[2];
    arg_2 = ptr_1[0x14];
    if (arg_2 == 0) {
      uval_3 = 2;
    }
    else {
      flag_2 = thunk_FUN_10004c20((int)this);
      if (CONCAT31(extraout_var,flag_2) == 0) {
        uval_3 = 1;
      }
      else {
        val_1 = ptr_1[0xe];
        if (val_1 != 0) {
          thunk_FUN_10005ef9((int)ptr_1);
        }
        thunk_FUN_100023d1(this,arg_2);
        if (val_1 != 0) {
          thunk_FUN_10005d8d(ptr_1);
        }
        PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
        uval_3 = 0;
      }
    }
  }
  return uval_3;
}



int32_t __cdecl FUN_100067b9(int32_t arg_1,HPSTR arg_2)

{
  BOOL BVar1;
  int32_t uval_2;
  MMRESULT MVar3;
  DWORD DVar4;
  int val_5;
  char *pcVar6;
  HWND *ppHVar7;
  CHAR *pCVar8;
  int32_t *puVar9;
  _MMCKINFO local_204;
  _MMCKINFO local_1f0;
  HMMIO local_1dc;
  CHAR local_1d8 [22];
  int32_t local_1c2 [26];
  DWORD local_158;
  char local_154 [4];
  char local_150 [4];
  char local_14c [4];
  char local_148 [4];
  char local_144;
  int32_t local_143;
  DWORD local_50;
  HWND local_4c [2];
  CHAR *local_44;
  char *local_34;
  DWORD local_30;
  char *local_20;
  DWORD local_1c;
  
  ppHVar7 = local_4c;
  for (val_5 = 0x12; val_5 != 0; val_5 = val_5 + -1) {
    *ppHVar7 = (HWND)0x0;
    ppHVar7 = ppHVar7 + 1;
  }
  local_154 = (char  [4])s_d__avi_quant_pal_100105a4._0_4_;
  local_150 = (char  [4])s_d__avi_quant_pal_100105a4._4_4_;
  local_14c = (char  [4])s_d__avi_quant_pal_100105a4._8_4_;
  local_148 = (char  [4])s_d__avi_quant_pal_100105a4._12_4_;
  local_144 = s_d__avi_quant_pal_100105a4[0x10];
  puVar9 = &local_143;
  for (val_5 = 0x3c; val_5 != 0; val_5 = val_5 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  *(int16_t *)puVar9 = 0;
  *(uint8_t *)((int)puVar9 + 2) = 0;
  pcVar6 = s_Palette_Files_100105b8;
  pCVar8 = local_1d8;
  for (val_5 = 5; val_5 != 0; val_5 = val_5 + -1) {
    *(int32_t *)pCVar8 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pCVar8 = pCVar8 + 4;
  }
  *(int16_t *)pCVar8 = *(int16_t *)pcVar6;
  puVar9 = local_1c2;
  for (val_5 = 0x1a; val_5 != 0; val_5 = val_5 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  *(int16_t *)puVar9 = 0;
  local_50 = 0x4c;
  local_4c[0] = (HWND)0x0;
  local_20 = s_Select_Palette_File_100105d0;
  local_44 = local_1d8;
  local_34 = local_154;
  local_30 = 0x104;
  local_1c = 0x806;
  BVar1 = GetOpenFileNameA((LPOPENFILENAMEA)&local_50);
  if (BVar1 == 0) {
    uval_2 = 1;
  }
  else {
    local_1dc = mmioOpenA(local_154,(LPMMIOINFO)0x0,0);
    if (local_1dc == (HMMIO)0x0) {
      uval_2 = 1;
    }
    else {
      local_204.fccType = 0x204c4150;
      MVar3 = mmioDescend(local_1dc,&local_204,(MMCKINFO *)0x0,0x20);
      if (MVar3 == 0) {
        local_1f0.ckid = 0x61746164;
        MVar3 = mmioDescend(local_1dc,&local_1f0,&local_204,0x10);
        if (MVar3 == 0) {
          local_158 = local_1f0.cksize;
          if (local_1f0.cksize == 0) {
            mmioClose(local_1dc,0);
            uval_2 = 1;
          }
          else {
            DVar4 = mmioRead(local_1dc,arg_2,local_1f0.cksize);
            if (DVar4 == local_158) {
              mmioClose(local_1dc,0);
              uval_2 = 0;
            }
            else {
              mmioClose(local_1dc,0);
              uval_2 = 1;
            }
          }
        }
        else {
          mmioClose(local_1dc,0);
          uval_2 = 1;
        }
      }
      else {
        mmioClose(local_1dc,0);
        uval_2 = 1;
      }
    }
  }
  return uval_2;
}



void __cdecl FUN_100069c9(LPARAM *ptr_1,short *ptr_2)

{
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  thunk_FUN_1000b5e0(*(void **)ptr_1[2],&local_24);
  local_14 = (int)*ptr_2;
  local_10 = (int)ptr_2[1];
  local_8 = (local_18 - local_20) + local_10;
  local_c = (local_1c - local_24) + local_14;
  thunk_FUN_1000b633(*(void **)ptr_1[2],&local_14);
  PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
  return;
}



void __cdecl FUN_10006a43(LPARAM *ptr_1)

{
  tagRECT local_34;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  GetWindowRect((HWND)ptr_1[4],&local_34);
  thunk_FUN_1000b5e0(*(void **)ptr_1[2],&local_14);
  local_24 = (local_34.right - local_34.left) / 2 - (local_c - local_14) / 2;
  local_1c = (local_c - local_14) + local_24;
  local_20 = (local_34.bottom - local_34.top) / 2 - (local_8 - local_10) / 2;
  local_18 = (local_8 - local_10) + local_20;
  thunk_FUN_1000b633(*(void **)ptr_1[2],&local_24);
  PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
  return;
}



/* Library Function - Single Match
    public: int __thiscall CArchive::IsBufferEmpty(void)const 
   
   Library: Visual Studio 1998 Debug */

int __thiscall CArchive::IsBufferEmpty(CArchive *this)

{
  return (uint32_t)(*(int *)(this + 0x44) == *(int *)(this + 0x58));
}



void __fastcall FUN_10007050(int arg_1)

{
  *(int32_t *)(arg_1 + 0x40) = 0;
  return;
}



int __fastcall FUN_10007080(int arg_1)

{
  int val_1;
  
  if (*(uint16_t *)(*(int *)(arg_1 + 4) + 0xe) < 9) {
    val_1 = *(int *)(arg_1 + 4) + 0x28;
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



void FUN_100070d0(int32_t arg_1,int arg_2,void *ptr_3)

{
  if (arg_2 == 0x3bb) {
    DAT_1001bf50 = ptr_3;
  }
  else if (arg_2 == 0x3bc) {
    DAT_1001bf50 = (void *)0x0;
  }
  else if ((arg_2 == 0x3bd) && (DAT_1001bf50 != (void *)0x0)) {
    thunk_FUN_1000761c(DAT_1001bf50);
  }
  return;
}



int32_t __fastcall FUN_1000715a(int arg_1)

{
  int32_t uval_1;
  uint8_t local_90 [28];
  int local_74;
  uint32_t local_70;
  int32_t local_6c;
  int local_68;
  int local_60;
  
  *(int32_t *)(arg_1 + 0x78) = 0xffffffff;
  if (*(int *)(arg_1 + 0x10) == 0) {
    uval_1 = 0xfffffff3;
  }
  else {
    AVIStreamInfoA(*(int32_t *)(arg_1 + 0x10),local_90,0x8c);
    *(int *)(arg_1 + 0x94) = local_68 * local_60;
    *(int *)(arg_1 + 0x90) = local_60;
    *(int *)(arg_1 + 0x7c) = local_74;
    *(uint32_t *)(arg_1 + 0x80) = local_74 + local_70 / *(uint32_t *)(arg_1 + 0x94);
    *(int32_t *)(arg_1 + 0x84) = local_6c;
    if (*(int *)(arg_1 + 0x84) < 0x20) {
      uval_1 = 0;
    }
    else {
      uval_1 = 0xfffffff5;
    }
  }
  return uval_1;
}



int32_t __fastcall FUN_10007238(int arg_1)

{
  *(int32_t *)(arg_1 + 0x78) = 0xffffffff;
  thunk_FUN_10004ea1(DAT_10010618);
  return 0;
}



int __thiscall FUN_10007268(void *this,int y,int32_t width,int height)

{
  int val_1;
  int32_t uval_2;
  
  if (*(int *)((int)this + 0x1c) == 0) {
    val_1 = thunk_FUN_1000715a((int)this);
    if (val_1 == 0) {
      if (height == 0) {
        *(int *)((int)this + 0x98) = y / *(int *)((int)this + 0x94);
      }
      else {
        *(int *)((int)this + 0x98) = y;
      }
      uval_2 = AVIStreamSampleToTime
                        (*(int32_t *)((int)this + 0x10),
                         *(int *)((int)this + 0x94) * *(int *)((int)this + 0x98));
      *(int32_t *)((int)this + 0x78) = uval_2;
      val_1 = thunk_FUN_10004e65(*(int32_t *)((int)this + 0x10),DAT_10010618,&DAT_100105f8);
      if (val_1 == 0) {
        thunk_FUN_10004f02(DAT_10010618,0);
        val_1 = 0;
      }
      else {
        val_1 = -0xd;
      }
    }
  }
  else {
    thunk_FUN_10004f02(DAT_10010618,0);
    val_1 = 0;
  }
  return val_1;
}



int32_t FUN_1000735d(void)

{
  thunk_FUN_10004ea1(DAT_10010618);
  return 0;
}



int32_t FUN_10007383(void)

{
  thunk_FUN_10004f90(DAT_10010618);
  return 0;
}



int32_t FUN_100073a9(void)

{
  thunk_FUN_10004f02(DAT_10010618,0);
  return 0;
}



int32_t FUN_100073d1(void)

{
  int val_1;
  int32_t uval_2;
  uint8_t local_8 [4];
  
  val_1 = thunk_FUN_100052e9(DAT_10010618,local_8);
  if (val_1 == 0) {
    uval_2 = 0xffffffff;
  }
  else {
    uval_2 = 0xfffffff2;
  }
  return uval_2;
}



int32_t __thiscall FUN_10007410(void *this,int32_t arg_2)

{
  int32_t uval_1;
  
  uval_1 = AVIStreamTimeToSample(*(int32_t *)((int)this + 0xc),arg_2);
  return uval_1;
}



int __thiscall FUN_1000743e(void *this,int arg_2)

{
  uint32_t uval_1;
  int val_2;
  uint32_t uval_3;
  int local_c;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if ((arg_2 <= local_8) || (*(int *)((int)this + 0x80) < *(int *)((int)this + 0x98))) {
      *(int *)((int)this + 0x98) = *(int *)((int)this + 0x98) + local_8;
      return local_8;
    }
    val_2 = AVIStreamRead(*(int32_t *)((int)this + 0x10),
                          (*(int *)((int)this + 0x98) + local_8) * *(int *)((int)this + 0x94),
                          *(int32_t *)((int)this + 0x94),
                          **(int32_t **)((int)this + *(int *)((int)this + 0x11c) * 4 + 0x9c),
                          *(int *)((int)this + 0x90) * *(int *)((int)this + 0x94),&local_c,0);
    if (val_2 != 0) {
      return local_8;
    }
    if (*(int *)((int)this + 0x90) * *(int *)((int)this + 0x94) - local_c != 0) break;
    *(int *)((int)this + 0x11c) = *(int *)((int)this + 0x11c) + 1;
    uval_1 = *(uint32_t *)((int)this + 0x11c);
    uval_3 = (int)uval_1 >> 0x1f;
    *(uint32_t *)((int)this + 0x11c) = ((uval_1 ^ uval_3) - uval_3 & 0x1f ^ uval_3) - uval_3;
    local_8 = local_8 + 1;
  }
  return local_8;
}



int __fastcall FUN_1000755a(int arg_1)

{
  uint32_t uval_1;
  uint32_t uval_2;
  int local_8;
  
  local_8 = 0;
  while (((local_8 < 0x20 && (*(int *)(arg_1 + 0x124) < 0x20)) &&
         (*(int *)(arg_1 + 0x11c) != *(int *)(arg_1 + 0x120)))) {
    waveOutWrite(*(HWAVEOUT *)(arg_1 + 0x74),
                 *(LPWAVEHDR *)(arg_1 + 0x9c + *(int *)(arg_1 + 0x120) * 4),0x20);
    *(int *)(arg_1 + 0x124) = *(int *)(arg_1 + 0x124) + 1;
    *(int *)(arg_1 + 0x120) = *(int *)(arg_1 + 0x120) + 1;
    uval_1 = *(uint32_t *)(arg_1 + 0x120);
    uval_2 = (int)uval_1 >> 0x1f;
    *(uint32_t *)(arg_1 + 0x120) = ((uval_1 ^ uval_2) - uval_2 & 0x1f ^ uval_2) - uval_2;
    local_8 = local_8 + 1;
  }
  return local_8;
}



int32_t __fastcall FUN_1000761c(void *ptr_1)

{
  int32_t uval_1;
  
  if (*(int *)((int)ptr_1 + 0x78) < 0) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)ptr_1 + 0x18) == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    thunk_FUN_1000743e(ptr_1,1);
    *(int *)((int)ptr_1 + 0x124) = *(int *)((int)ptr_1 + 0x124) + -1;
    thunk_FUN_1000755a((int)ptr_1);
    uval_1 = 0;
  }
  return uval_1;
}



void __cdecl FUN_100077f0(HWND hwnd,LPCSTR arg_2)

{
  int val_1;
  va_list arglist;
  CHAR local_104 [256];
  
  lstrcpyA(local_104,s_IVIPLAY__10010624);
  arglist = &stack0x0000000c;
  val_1 = lstrlenA(local_104);
  wvsprintfA(local_104 + val_1,arg_2,arglist);
  lstrcatA(local_104,&DAT_10010630);
  SetWindowTextA(hwnd,local_104);
  return;
}



int32_t __fastcall FUN_1000785e(int *ptr_1)

{
  int32_t uval_1;
  int32_t *ptr_1_00;
  int val_2;
  void *buf_ptr_3;
  int32_t *unaff_FS_OFFSET;
  int32_t *local_d4;
  uint8_t local_cc [4];
  int local_c8;
  int local_b0;
  int local_ac;
  int local_a4;
  int32_t local_40;
  uint8_t local_3c [40];
  int local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10007a6c;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  if (ptr_1[3] == 0) {
    uval_1 = 0xffffffec;
  }
  else {
    if (*ptr_1 != 0) {
      thunk_FUN_10007a85(ptr_1);
    }
    ptr_1[0xd] = -1;
    AVIStreamInfoA(ptr_1[3],local_cc,0x8c);
    ptr_1[0x11] = local_b0;
    ptr_1[0x15] = ptr_1[0x11];
    ptr_1[0x16] = local_b0 + local_ac + -1;
    ptr_1[0x12] = ptr_1[0x11] + -1;
    AVIStreamReadFormat(ptr_1[3],0,0,&local_14);
    if (local_14 == 0x28) {
      local_40 = AVIStreamReadFormat(ptr_1[3],0,local_3c,&local_14);
      ptr_1_00 = operator_new(0x1b0);
      local_8 = 0;
      if (ptr_1_00 == (int32_t *)0x0) {
        local_d4 = (int32_t *)0x0;
      }
      else {
        local_d4 = thunk_FUN_1000a250(ptr_1_00);
      }
      local_8 = 0xffffffff;
      *ptr_1 = (int)local_d4;
      val_2 = thunk_FUN_1000a30f((void *)*ptr_1,local_c8,local_3c);
      if (val_2 == 0) {
        ptr_1[0x18] = local_a4;
        buf_ptr_3 = malloc(ptr_1[0x18]);
        ptr_1[0x17] = (int)buf_ptr_3;
        if (ptr_1[0x17] == 0) {
          uval_1 = 3;
        }
        else {
          ptr_1[0x10] = 0;
          uval_1 = 0;
        }
      }
      else {
        thunk_FUN_10007a85(ptr_1);
        uval_1 = 0xffffffeb;
      }
    }
    else {
      uval_1 = 0xffffffff;
    }
  }
  *unaff_FS_OFFSET = local_10;
  return uval_1;
}



int32_t __fastcall FUN_10007a85(int *ptr_1)

{
  if (ptr_1[0x17] != 0) {
    free((void *)ptr_1[0x17]);
    ptr_1[0x17] = 0;
  }
  if (*ptr_1 != 0) {
    if ((void *)*ptr_1 != (void *)0x0) {
      thunk_FUN_10008520((void *)*ptr_1,1);
    }
    *ptr_1 = 0;
  }
  return 0;
}



int32_t __thiscall FUN_10007b00(void *this,int arg_2,int arg_3)

{
  int32_t uval_1;
  int val_2;
  DWORD DVar3;
  
  if (*(int *)this == 0) {
    uval_1 = 0xffffffeb;
  }
  else if (arg_2 == 0) {
    uval_1 = 0xffffffea;
  }
  else {
    *(int *)((int)this + 0x30) = arg_2;
    if (-1 < arg_3) {
      *(int *)((int)this + 0x44) = arg_3;
    }
    val_2 = thunk_FUN_1000a8d3(*(void **)this,arg_2);
    if (val_2 == 0) {
      if (*(int *)((int)this + 0x18) != 0) {
        thunk_FUN_1000ae35(*(int32_t **)this);
      }
      DVar3 = timeGetTime();
      *(DWORD *)((int)this + 0x34) = DVar3;
      uval_1 = AVIStreamSampleToTime
                        (*(int32_t *)((int)this + 0xc),*(int32_t *)((int)this + 0x44));
      *(int32_t *)((int)this + 0x38) = uval_1;
      *(int32_t *)((int)this + 0x3c) = *(int32_t *)((int)this + 0x44);
      uval_1 = 0;
    }
    else {
      thunk_FUN_10007bff(this);
      uval_1 = 0xffffffeb;
    }
  }
  return uval_1;
}



void __thiscall FUN_10007bde(void *this,int arg_2)

{
  *(int *)((int)this + 0x34) = *(int *)((int)this + 0x34) + arg_2;
  return;
}



int32_t __fastcall FUN_10007bff(int32_t *ptr_1)

{
  int32_t uval_1;
  
  if (ptr_1[0xc] == 0) {
    uval_1 = 0xffffffea;
  }
  else {
    thunk_FUN_1000aea5((int32_t *)*ptr_1);
    thunk_FUN_1000acaf((int32_t *)*ptr_1);
    ptr_1[0xd] = 0xffffffff;
    ptr_1[0xc] = 0;
    uval_1 = 0;
  }
  return uval_1;
}



void FUN_10007c56(void)

{
  FUN_10007c6b();
  return;
}



void FUN_10007c6b(void)

{
  thunk_FUN_10004af0((int32_t *)&DAT_1001bf60);
  return;
}



int32_t __fastcall FUN_10007c85(int *ptr_1)

{
  int32_t uval_1;
  DWORD DVar2;
  int val_3;
  int local_14;
  uint8_t local_10 [4];
  DWORD local_c;
  uint8_t local_8 [4];
  
  if (*ptr_1 == 0) {
    uval_1 = 0xffffffeb;
  }
  else {
    thunk_FUN_100051e4();
    if (ptr_1[0xd] < 0) {
      uval_1 = 0xffffffe9;
    }
    else {
      if (ptr_1[6] == 0) {
        if (ptr_1[0x16] < ptr_1[0x11]) {
          ptr_1[0x11] = ptr_1[0x16];
        }
        if (ptr_1[0x12] == ptr_1[0x11]) {
          thunk_FUN_100027a0((int)ptr_1);
        }
      }
      else {
        local_14 = thunk_FUN_100073d1();
        if (local_14 < 0) {
          DVar2 = timeGetTime();
          local_14 = (DVar2 - ptr_1[0xd]) + ptr_1[0xe];
        }
        val_3 = thunk_FUN_10007eaf(ptr_1,local_14);
        ptr_1[0x11] = val_3;
        if (ptr_1[0x16] < ptr_1[0x11]) {
          ptr_1[0x11] = ptr_1[0x16];
        }
        if (ptr_1[0x12] == ptr_1[0x11]) {
          thunk_FUN_100051e4();
          return 0;
        }
      }
      val_3 = thunk_FUN_10007f71(ptr_1);
      if (val_3 == 0) {
        uval_1 = 0;
      }
      else {
        local_c = AVIStreamRead(ptr_1[3],ptr_1[0x11],1,ptr_1[0x17],ptr_1[0x18],local_8,local_10);
        if (local_c == 0) {
          thunk_FUN_100085b0(&DAT_1001bf60,s_vidsdraw__vcmDraw_m_pvBuf___rval_10010634);
          local_c = thunk_FUN_1000af14((void *)*ptr_1,ptr_1[0x17],0);
          if ((int)local_c < 2) {
            thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],local_c,0,0);
            thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
            ptr_1[0x12] = ptr_1[0x11];
            if (ptr_1[6] != 0) {
              ptr_1[0x10] = ptr_1[0x10] + (ptr_1[0x11] - ptr_1[0xf]) + -1;
              ptr_1[0xf] = ptr_1[0x11];
            }
            thunk_FUN_100051e4();
            uval_1 = 0;
          }
          else {
            thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],local_c,ptr_1[0xd],0);
            thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
            uval_1 = 0xffffffeb;
          }
        }
        else {
          uval_1 = 0xffffffe8;
        }
      }
    }
  }
  return uval_1;
}



int32_t __thiscall FUN_10007eaf(void *this,int32_t arg_2)

{
  int32_t uval_1;
  
  uval_1 = AVIStreamTimeToSample(*(int32_t *)((int)this + 0xc),arg_2);
  return uval_1;
}



int32_t __thiscall FUN_10007edd(void *this,int32_t arg_2)

{
  int32_t uval_1;
  
  uval_1 = AVIStreamSampleToTime(*(int32_t *)((int)this + 0xc),arg_2);
  return uval_1;
}



bool __thiscall FUN_10007f0b(void *this,int arg_2)

{
  int val_1;
  bool flag_2;
  
  if (*(int *)((int)this + 0xc) == 0) {
    flag_2 = false;
  }
  else {
    if (arg_2 < 0) {
      arg_2 = *(int *)((int)this + 0x44);
    }
    val_1 = AVIStreamFindSample(*(int32_t *)((int)this + 0xc),arg_2,0x14);
    flag_2 = val_1 == arg_2;
  }
  return flag_2;
}



int32_t __fastcall FUN_10007f71(int32_t *ptr_1)

{
  int val_1;
  int32_t uval_2;
  int local_c;
  int local_8;
  
  if ((int)ptr_1[0x11] < (int)ptr_1[0x12]) {
    ptr_1[0x12] = 0xffffffff;
  }
  if (ptr_1[0x11] - ptr_1[0x12] != 1) {
    val_1 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11],0x14);
    if (val_1 == ptr_1[0x11]) {
      ptr_1[0x13] = ptr_1[0x11];
      uval_2 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11] + 1,0x11);
      ptr_1[0x14] = uval_2;
    }
    else if (ptr_1[0x11] - ptr_1[0x12] == 2) {
      thunk_FUN_10008136(ptr_1);
    }
    else {
      if (((int)ptr_1[0x14] < (int)ptr_1[0x11]) || ((int)ptr_1[0x11] < (int)ptr_1[0x13])) {
        uval_2 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11] + -1,0x14);
        ptr_1[0x13] = uval_2;
        uval_2 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11] + 1,0x11);
        ptr_1[0x14] = uval_2;
      }
      if ((int)(ptr_1[0x11] - ptr_1[0x13]) < 0) {
        local_8 = -(ptr_1[0x11] - ptr_1[0x13]);
      }
      else {
        local_8 = ptr_1[0x11] - ptr_1[0x13];
      }
      if ((int)(ptr_1[0x11] - ptr_1[0x14]) < 0) {
        local_c = -(ptr_1[0x11] - ptr_1[0x14]);
      }
      else {
        local_c = ptr_1[0x11] - ptr_1[0x14];
      }
      if (local_c < local_8) {
        if (ptr_1[6] != 0) {
          return 0;
        }
        thunk_FUN_10008136(ptr_1);
      }
      else {
        thunk_FUN_10008136(ptr_1);
      }
    }
  }
  return 1;
}



void __fastcall FUN_10008136(int32_t *ptr_1)

{
  int val_1;
  int local_8;
  
  if ((int)ptr_1[0x12] < (int)ptr_1[0x13]) {
    ptr_1[0x12] = ptr_1[0x13] + -1;
  }
  local_8 = ptr_1[0x12];
  while ((local_8 = local_8 + 1, local_8 < (int)ptr_1[0x11] &&
         (val_1 = AVIStreamRead(ptr_1[3],local_8,1,ptr_1[0x17],ptr_1[0x18],0,0), val_1 == 0))) {
    if (ptr_1[6] == 0) {
      thunk_FUN_100085b0(&DAT_1001bf60,s_vidsCatchup_____m_bPlaying__Draw_10010658);
      val_1 = thunk_FUN_1000b2fb((void *)*ptr_1,ptr_1[0x17],0);
      thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],val_1,0,0);
      thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
    }
    else {
      thunk_FUN_100085b0(&DAT_1001bf60,s_vidsCatchup_____m_bPlaying__Draw_1001067c);
      val_1 = thunk_FUN_1000b2fb((void *)*ptr_1,ptr_1[0x17],0x80000000);
      thunk_FUN_10008600(&DAT_1001bf60,ptr_1[0x11],val_1,0,0);
      thunk_FUN_10008570((uint32_t *)&DAT_1001bf60);
    }
    ptr_1[0x12] = local_8;
  }
  return;
}



int * __thiscall FUN_10008520(void *this,uint8_t arg_2)

{
  thunk_FUN_1000a2f1(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



void __fastcall FUN_10008570(uint32_t *ptr_1)

{
  *ptr_1 = *ptr_1 + 1;
  *ptr_1 = *ptr_1 & 0xff;
  return;
}



void __thiscall FUN_100085b0(void *this,char *str_2)

{
  thunk_FUN_10008660((void *)((int)this + *(int *)this * 0x98 + 4),str_2);
  return;
}



void __thiscall
FUN_10008600(void *this,int32_t arg_2,int32_t arg_3,int32_t arg_4,int32_t arg_5)

{
  thunk_FUN_100086b0((void *)((int)this + *(int *)this * 0x98 + 4),arg_2,arg_3,arg_4,arg_5);
  return;
}



void __thiscall FUN_10008660(void *this,char *str_2)

{
  DWORD DVar1;
  
  strcpy(this,str_2);
  DVar1 = timeGetTime();
  *(DWORD *)((int)this + 0x80) = DVar1;
  return;
}



void __thiscall
FUN_100086b0(void *this,int32_t arg_2,int32_t arg_3,int32_t arg_4,int32_t arg_5)

{
  DWORD DVar1;
  
  DVar1 = timeGetTime();
  *(DWORD *)((int)this + 0x84) = DVar1;
  *(int32_t *)((int)this + 0x88) = arg_2;
  *(int32_t *)((int)this + 0x8c) = arg_3;
  *(int32_t *)((int)this + 0x90) = arg_4;
  *(int32_t *)((int)this + 0x94) = arg_5;
  return;
}



/* Library Function - Single Match
    public: __thiscall CPrintPreviewState::CPrintPreviewState(void)
   
   Library: Visual Studio 1998 Debug */

CPrintPreviewState * __thiscall CPrintPreviewState::CPrintPreviewState(CPrintPreviewState *this)

{
  *(uint8_t ***)this = &PTR_LAB_1000f060;
  *(int32_t *)(this + 4) = 0;
  *(int32_t *)(this + 8) = 0;
  *(int32_t *)(this + 0xc) = 1;
  *(int32_t *)(this + 0x10) = 0;
  *(int32_t *)(this + 0x14) = 0;
  return this;
}



void __fastcall FUN_10008774(int32_t *ptr_1)

{
  *ptr_1 = &PTR_LAB_1000f060;
  if (ptr_1[1] != 0) {
    free((void *)ptr_1[1]);
  }
  if ((ptr_1[3] != 0) && (ptr_1[2] != 0)) {
    free((void *)ptr_1[2]);
  }
  if (ptr_1[4] != 0) {
    operator_delete((void *)ptr_1[4]);
  }
  return;
}



int32_t __thiscall FUN_10008802(void *this,int y,int width,int height)

{
  int32_t *u_ptr_1;
  void *buf_ptr_2;
  int32_t uval_3;
  size_t _Size;
  int local_14;
  uint8_t *local_10;
  
  if (*(int *)((int)this + 4) != 0) {
    free(*(void **)((int)this + 4));
  }
  if (*(int *)((int)this + 8) != 0) {
    free(*(void **)((int)this + 8));
  }
  if (height == 8) {
    buf_ptr_2 = malloc(0x428);
    *(void **)((int)this + 4) = buf_ptr_2;
  }
  else {
    buf_ptr_2 = malloc(0x28);
    *(void **)((int)this + 4) = buf_ptr_2;
  }
  if (*(int *)((int)this + 4) == 0) {
    uval_3 = 0;
  }
  else {
    _Size = (((int)(height * y + (height * y >> 0x1f & 7U)) >> 3) + 5U & 0xfffffffc) * width;
    buf_ptr_2 = malloc(_Size);
    *(void **)((int)this + 8) = buf_ptr_2;
    if (*(int *)((int)this + 8) == 0) {
      free(*(void **)((int)this + 4));
      *(int32_t *)((int)this + 4) = 0;
      uval_3 = 0;
    }
    else {
      u_ptr_1 = *(int32_t **)((int)this + 4);
      *u_ptr_1 = 0x28;
      u_ptr_1[1] = y;
      u_ptr_1[2] = width;
      *(int16_t *)(u_ptr_1 + 3) = 1;
      *(short *)((int)u_ptr_1 + 0xe) = (short)height;
      u_ptr_1[4] = 0;
      u_ptr_1[5] = 0;
      u_ptr_1[6] = 0;
      u_ptr_1[7] = 0;
      u_ptr_1[8] = 0;
      u_ptr_1[9] = 0;
      if (height < 9) {
        local_10 = (uint8_t *)thunk_FUN_10007080((int)this);
        for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
          local_10[2] = (uint8_t)local_14;
          local_10[1] = local_10[2];
          *local_10 = local_10[1];
          local_10[3] = 0;
          local_10 = local_10 + 4;
        }
      }
      memset(*(void **)((int)this + 8),0,_Size);
      uval_3 = 1;
    }
  }
  return uval_3;
}



int32_t __thiscall FUN_100089e8(void *this,int *ptr_2,int32_t arg_3)

{
  void *buf_ptr_1;
  int32_t uval_2;
  int val_3;
  
  if (*(int *)((int)this + 4) != 0) {
    free(*(void **)((int)this + 4));
  }
  if (*(short *)((int)ptr_2 + 0xe) == 8) {
    buf_ptr_1 = malloc(0x428);
    *(void **)((int)this + 4) = buf_ptr_1;
  }
  else {
    buf_ptr_1 = malloc(0x28);
    *(void **)((int)this + 4) = buf_ptr_1;
  }
  if (*(int *)((int)this + 4) == 0) {
    uval_2 = 0;
  }
  else {
    val_3 = FUN_10008ad5(ptr_2);
    memcpy(*(void **)((int)this + 4),ptr_2,val_3 * 4 + 0x28);
    if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 8) != 0)) {
      free(*(void **)((int)this + 8));
    }
    *(int32_t *)((int)this + 8) = arg_3;
    *(int32_t *)((int)this + 0xc) = 0;
    uval_2 = 1;
  }
  return uval_2;
}



int __cdecl FUN_10008ad5(int *ptr_1)

{
  uint16_t uval_1;
  bool flag_2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int local_18;
  int local_14;
  
  flag_2 = FUN_10008c4c(ptr_1);
  if (CONCAT31(extraout_var,flag_2) == 0) {
    uval_1 = *(uint16_t *)((int)ptr_1 + 10);
  }
  else {
    uval_1 = *(uint16_t *)((int)ptr_1 + 0xe);
  }
  if (uval_1 == 1) {
    local_18 = 2;
  }
  else if (uval_1 == 4) {
    local_18 = 0x10;
  }
  else if (uval_1 == 8) {
    local_18 = 0x100;
  }
  else {
    local_18 = 0;
  }
  flag_2 = FUN_10008c4c(ptr_1);
  if ((CONCAT31(extraout_var_00,flag_2) != 0) && (ptr_1[8] != 0)) {
    local_18 = ptr_1[8];
  }
  if (uval_1 == 1) {
    local_14 = 2;
  }
  else if (uval_1 == 4) {
    local_14 = 0x10;
  }
  else if (uval_1 == 8) {
    local_14 = 0x100;
  }
  else {
    local_14 = 0;
  }
  if ((local_14 != 0) && (local_14 < local_18)) {
    local_18 = local_14;
  }
  if (8 < uval_1) {
    local_18 = 0;
  }
  return local_18;
}



bool __cdecl FUN_10008c4c(int *ptr_1)

{
  return *ptr_1 != 0xc;
}



int32_t __thiscall FUN_10008c74(void *this,HWND y,LPCSTR width,uint32_t height)

{
  BOOL BVar1;
  uint16_t *local_78;
  int local_74;
  int local_70;
  uint16_t *local_6c;
  uint16_t *local_68;
  int local_60;
  int local_5c;
  int local_58;
  uint16_t local_52;
  int local_38;
  size_t local_34;
  size_t local_30;
  HANDLE local_2c;
  size_t local_28;
  void *local_24;
  uint16_t *local_20;
  size_t local_1c;
  short local_18;
  int16_t uStack_16;
  int16_t uStack_14;
  int local_e;
  uint16_t *local_8;
  
  local_24 = (void *)0x0;
  local_20 = (uint16_t *)0x0;
  local_8 = (uint16_t *)0x0;
  local_2c = CreateFileA(width,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x10000000,(HANDLE)0x0);
  if (local_2c != (HANDLE)0xffffffff) {
    BVar1 = ReadFile(local_2c,&local_18,0xe,&local_28,(LPOVERLAPPED)0x0);
    if ((BVar1 == 0) || (local_28 != 0xe)) {
      GetLastError();
      CloseHandle(local_2c);
    }
    else if (local_18 == 0x4d42) {
      BVar1 = ReadFile(local_2c,&local_60,0x28,&local_28,(LPOVERLAPPED)0x0);
      if ((BVar1 == 0) || (local_28 != 0x28)) {
        CloseHandle(local_2c);
      }
      else if (local_60 == 0x28) {
        local_38 = FUN_10008ad5(&local_60);
        local_1c = local_38 << 2;
        local_30 = 0x428;
        local_34 = CONCAT22(uStack_14,uStack_16) - local_e;
        local_24 = malloc(0x428);
        if (local_24 == (void *)0x0) {
          CloseHandle(local_2c);
        }
        else {
          memset(local_24,0,local_30);
          memcpy(local_24,&local_60,0x28);
          *(uint16_t *)((int)local_24 + 0xe) = (uint16_t)height;
          if ((local_38 == 0) ||
             ((BVar1 = ReadFile(local_2c,(LPVOID)((int)local_24 + 0x28),local_1c,&local_28,
                                (LPOVERLAPPED)0x0), BVar1 != 0 && (local_1c == local_28)))) {
            local_20 = malloc(local_34);
            local_8 = local_20;
            if (local_20 == (uint16_t *)0x0) {
              CloseHandle(local_2c);
            }
            else {
              BVar1 = ReadFile(local_2c,local_20,local_34,&local_28,(LPOVERLAPPED)0x0);
              if ((BVar1 != 0) && (local_34 == local_28)) {
                if (local_52 != height) {
                  local_34 = (((int)(local_5c * height + ((int)(local_5c * height) >> 0x1f & 7U)) >>
                              3) + 3U & 0xfffffffc) * local_58;
                  local_20 = malloc(local_34);
                  if (height == 0x10) {
                    local_6c = local_8;
                    local_68 = local_20;
                    for (local_74 = 0; local_74 < local_58; local_74 = local_74 + 1) {
                      for (local_70 = 0; local_70 < local_5c; local_70 = local_70 + 1) {
                        *local_68 = (*(uint8_t *)((int)local_24 + (uint32_t)(uint8_t)*local_6c * 4 + 0x29) &
                                    0xfff8) * 4 |
                                    (*(uint8_t *)((int)local_24 + (uint32_t)(uint8_t)*local_6c * 4 + 0x2a) &
                                    0xfff8) << 7 |
                                    (uint16_t)((int)(uint32_t)*(uint8_t *)((int)local_24 +
                                                                 (uint32_t)(uint8_t)*local_6c * 4 + 0x28)
                                            >> 3);
                        local_6c = (uint16_t *)((int)local_6c + 1);
                        local_68 = local_68 + 1;
                      }
                      local_6c = (uint16_t *)
                                 ((int)local_6c + ((local_5c + 3U & 0xfffffffc) - local_5c));
                      local_68 = (uint16_t *)
                                 ((int)local_68 +
                                 ((((int)(local_5c * 0x10 + (local_5c * 0x10 >> 0x1f & 7U)) >> 3) +
                                   3U & 0xfffffffc) -
                                 ((int)(local_5c * 0x10 + (local_5c * 0x10 >> 0x1f & 7U)) >> 3)));
                    }
                  }
                  else if (height == 0x18) {
                    local_6c = local_8;
                    local_78 = local_20;
                    for (local_74 = 0; local_74 < local_58; local_74 = local_74 + 1) {
                      for (local_70 = 0; local_70 < local_5c; local_70 = local_70 + 1) {
                        *(uint8_t *)(local_78 + 1) =
                             *(uint8_t *)((int)local_24 + (uint32_t)(uint8_t)*local_6c * 4 + 0x2a);
                        *(uint8_t *)((int)local_78 + 1) =
                             *(uint8_t *)((int)local_24 + (uint32_t)(uint8_t)*local_6c * 4 + 0x29);
                        *(uint8_t *)local_78 =
                             *(uint8_t *)((int)local_24 + (uint32_t)(uint8_t)*local_6c * 4 + 0x28);
                        local_6c = (uint16_t *)((int)local_6c + 1);
                        local_78 = (uint16_t *)((int)local_78 + 3);
                      }
                      local_6c = (uint16_t *)
                                 ((int)local_6c + ((local_5c + 3U & 0xfffffffc) - local_5c));
                      local_78 = (uint16_t *)
                                 ((int)local_78 +
                                 ((((int)(local_5c * 0x18 + (local_5c * 0x18 >> 0x1f & 7U)) >> 3) +
                                   3U & 0xfffffffc) -
                                 ((int)(local_5c * 0x18 + (local_5c * 0x18 >> 0x1f & 7U)) >> 3)));
                    }
                  }
                  free(local_8);
                  local_52 = (uint16_t)height;
                }
                if (*(int *)((int)this + 4) != 0) {
                  free(*(void **)((int)this + 4));
                }
                *(void **)((int)this + 4) = local_24;
                if (*(int *)((int)this + 8) != 0) {
                  free(*(void **)((int)this + 8));
                }
                *(uint16_t **)((int)this + 8) = local_20;
                *(int32_t *)((int)this + 0xc) = 1;
                CloseHandle(local_2c);
                return 1;
              }
            }
          }
          else {
            CloseHandle(local_2c);
          }
        }
      }
      else {
        CloseHandle(local_2c);
        MessageBoxA(y,s_Not_a_Windows_DIB__100106d0,s_KPlay_error_100106c4,0x30);
      }
    }
    else {
      CloseHandle(local_2c);
    }
  }
  if (local_24 != (void *)0x0) {
    free(local_24);
  }
  if (local_20 != (uint16_t *)0x0) {
    free(local_20);
  }
  return 0;
}



int32_t __thiscall FUN_100091ea(void *this,LPCSTR arg_2)

{
  int16_t uval_1;
  HANDLE hFile;
  int32_t uval_2;
  short extraout_var;
  LPCVOID buf_ptr_3;
  DWORD nNumberOfBytesToWrite;
  DWORD local_24;
  LPCVOID local_20;
  int local_1c;
  int16_t local_18;
  int local_16;
  int16_t local_12;
  int16_t local_10;
  int local_e;
  int32_t local_8;
  
  local_8 = 0;
  local_1c = 0;
  hFile = CreateFileA(arg_2,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    uval_2 = 2;
  }
  else {
    local_18 = 0x4d42;
    local_12 = 0;
    local_10 = 0;
    local_1c = thunk_FUN_10009348((int)this);
    uval_1 = thunk_FUN_1000a130((int)this);
    local_16 = local_1c * 4 + 0x36;
    local_e = local_16;
    buf_ptr_3 = (LPCVOID)thunk_FUN_10004bc0((int)this);
    nNumberOfBytesToWrite =
         *(int *)((int)buf_ptr_3 + 4) *
         ((int)(CONCAT22(extraout_var,uval_1) + ((int)extraout_var >> 0xf & 7U)) >> 3) *
         *(int *)((int)buf_ptr_3 + 8);
    local_16 = local_16 + nNumberOfBytesToWrite;
    WriteFile(hFile,&local_18,0xe,&local_24,(LPOVERLAPPED)0x0);
    *(DWORD *)((int)buf_ptr_3 + 0x14) = nNumberOfBytesToWrite;
    WriteFile(hFile,buf_ptr_3,0x28,&local_24,(LPOVERLAPPED)0x0);
    if (local_1c != 0) {
      buf_ptr_3 = (LPCVOID)thunk_FUN_10007080((int)this);
      WriteFile(hFile,buf_ptr_3,local_1c << 2,&local_24,(LPOVERLAPPED)0x0);
    }
    local_20 = (LPCVOID)thunk_FUN_10004bf0((int)this);
    WriteFile(hFile,local_20,nNumberOfBytesToWrite,&local_24,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
    uval_2 = 0;
  }
  return uval_2;
}



void __fastcall FUN_10009348(int arg_1)

{
  FUN_10008ad5(*(int **)(arg_1 + 4));
  return;
}



int32_t __thiscall FUN_1000936d(void *this,HPALETTE arg_2)

{
  int32_t uval_1;
  UINT UVar2;
  uint32_t uval_3;
  int val_4;
  tagPALETTEENTRY local_518 [256];
  uint32_t local_118;
  int local_114;
  uint8_t *local_110;
  uint8_t abStack_10c [256];
  int local_c;
  BYTE *local_8;
  
  if (arg_2 == (HPALETTE)0x0) {
    uval_1 = 0;
  }
  else if (*(short *)(*(int *)((int)this + 4) + 0xe) == 8) {
    if (*(int *)((int)this + 0x14) == 0) {
      local_8 = (BYTE *)thunk_FUN_10007080((int)this);
      local_c = 0;
      for (local_118 = 0; local_118 < 0x100; local_118 = local_118 + 1) {
        UVar2 = GetNearestPaletteIndex
                          (arg_2,(uint32_t)CONCAT12(*local_8,CONCAT11(local_8[1],local_8[2])));
        abStack_10c[local_118] = (uint8_t)UVar2;
        local_8 = local_8 + 4;
        if (abStack_10c[local_118] != local_118) {
          local_c = local_c + 1;
        }
        if ((*(int *)((int)this + 0x10) != 0) && (**(uint32_t **)((int)this + 0x10) == local_118)) {
          thunk_FUN_1000a1b0((int)this);
          thunk_FUN_1000a160(this,(uint32_t)abStack_10c[local_118]);
        }
      }
      local_110 = (uint8_t *)thunk_FUN_10004bf0((int)this);
      uval_3 = thunk_FUN_1000a200((int)this);
      val_4 = CFontDialog::GetWeight(this);
      local_114 = uval_3 * val_4;
      while( true ) {
        if (local_114 == 0) break;
        *local_110 = abStack_10c[*local_110];
        local_110 = local_110 + 1;
        local_114 = local_114 + -1;
      }
      local_114 = local_114 + -1;
      GetPaletteEntries(arg_2,0,0x100,local_518);
      local_8 = (BYTE *)thunk_FUN_10007080((int)this);
      for (local_118 = 0; local_118 < 0x100; local_118 = local_118 + 1) {
        local_8[2] = local_518[local_118].peRed;
        local_8[1] = local_518[local_118].peGreen;
        *local_8 = local_518[local_118].peBlue;
        local_8 = local_8 + 4;
      }
      *(int32_t *)((int)this + 0x14) = 1;
      uval_1 = 1;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



int __thiscall FUN_100095cf(void *this,int arg_2,int arg_3)

{
  int val_1;
  uint32_t uval_2;
  int val_3;
  
  val_1 = CFontDialog::GetWeight(this);
  if ((arg_2 < val_1) && (val_1 = CFontDialog::GetWeight(this), arg_3 < val_1)) {
    uval_2 = thunk_FUN_1000a200((int)this);
    val_1 = CFontDialog::GetWeight(this);
    val_3 = (uint32_t)*(uint16_t *)(*(int *)((int)this + 4) + 0xe) * arg_2;
    return ((val_1 - arg_3) + -1) * uval_2 + ((int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3) +
           *(int *)((int)this + 8);
  }
  return 0;
}



void __thiscall FUN_10009652(void *this,int32_t *ptr_2)

{
  int val_1;
  
  ptr_2[1] = 0;
  *ptr_2 = 0;
  val_1 = CFontDialog::GetWeight(this);
  ptr_2[3] = val_1;
  val_1 = CFontDialog::GetWeight(this);
  ptr_2[2] = val_1;
  return;
}



void __thiscall
FUN_10009699(void *this,CFontDialog *ptr_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,
            int arg_8)

{
  int16_t uval_1;
  int val_2;
  int16_t extraout_var;
  uint32_t local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int32_t local_20;
  int local_18;
  void *local_14;
  void *local_10;
  uint32_t local_c;
  uint32_t local_8;
  
  if (arg_7 < 0) {
    arg_5 = arg_5 + arg_7;
    arg_3 = arg_3 - arg_7;
    arg_7 = 0;
  }
  else {
    val_2 = CFontDialog::GetWeight(this);
    if (val_2 - arg_5 < arg_7) {
      val_2 = CFontDialog::GetWeight(this);
      if (val_2 <= arg_7) {
        return;
      }
      val_2 = CFontDialog::GetWeight(this);
      arg_5 = val_2 - arg_7;
    }
  }
  if (arg_3 < 0) {
    arg_5 = arg_5 + arg_3;
    arg_7 = arg_7 - arg_3;
    arg_3 = 0;
  }
  else if ((0 < arg_5) && (val_2 = CFontDialog::GetWeight(ptr_2), val_2 - arg_5 < arg_3)) {
    val_2 = CFontDialog::GetWeight(ptr_2);
    arg_5 = val_2 - arg_3;
  }
  if (arg_8 < 0) {
    arg_6 = arg_6 + arg_8;
    arg_4 = arg_4 - arg_8;
    arg_8 = 0;
  }
  else {
    val_2 = CFontDialog::GetWeight(this);
    if (val_2 - arg_6 < arg_8) {
      val_2 = CFontDialog::GetWeight(this);
      if (val_2 <= arg_8) {
        return;
      }
      val_2 = CFontDialog::GetWeight(this);
      arg_6 = val_2 - arg_8;
    }
  }
  if (arg_4 < 0) {
    arg_6 = arg_6 + arg_4;
    arg_8 = arg_8 - arg_4;
    arg_4 = 0;
  }
  else if ((0 < arg_6) && (val_2 = CFontDialog::GetWeight(ptr_2), val_2 - arg_6 < arg_4)) {
    val_2 = CFontDialog::GetWeight(ptr_2);
    arg_6 = val_2 - arg_4;
  }
  if ((0 < arg_5) && (0 < arg_6)) {
    val_2 = CFontDialog::GetWeight(this);
    if (val_2 - arg_8 <= arg_6) {
      val_2 = CFontDialog::GetWeight(this);
      arg_6 = val_2 - arg_8;
    }
    val_2 = CFontDialog::GetWeight(ptr_2);
    if (val_2 - arg_4 <= arg_6) {
      val_2 = CFontDialog::GetWeight(ptr_2);
      arg_6 = val_2 - arg_4;
    }
    local_14 = (void *)thunk_FUN_100095cf(this,arg_7,arg_8 + arg_6 + -1);
    local_10 = (void *)thunk_FUN_100095cf(ptr_2,arg_3,arg_6 + arg_4 + -1);
    local_8 = thunk_FUN_1000a200((int)this);
    local_c = thunk_FUN_1000a200((int)ptr_2);
    val_2 = CFontDialog::GetWeight(this);
    if (val_2 - arg_7 <= arg_5) {
      val_2 = CFontDialog::GetWeight(this);
      arg_5 = val_2 - arg_7;
    }
    val_2 = CFontDialog::GetWeight(ptr_2);
    if (val_2 - arg_3 <= arg_5) {
      val_2 = CFontDialog::GetWeight(ptr_2);
      arg_5 = val_2 - arg_3;
    }
    if (0 < arg_5) {
      uval_1 = thunk_FUN_1000a130((int)this);
      if (CONCAT22(extraout_var,uval_1) < 9) {
        val_2 = (uint32_t)*(uint16_t *)(*(int *)((int)this + 4) + 0xe) * arg_5;
        while (arg_6 != 0) {
          for (local_18 = 0; local_18 < (int)(val_2 + (val_2 >> 0x1f & 7U)) >> 3;
              local_18 = local_18 + 1) {
            if ((*(int *)((int)this + 0x10) == 0) ||
               ((uint32_t)*(uint8_t *)(local_18 + (int)local_14) != **(uint32_t **)((int)this + 0x10))) {
              *(uint8_t *)(local_18 + (int)local_10) = *(uint8_t *)(local_18 + (int)local_14);
            }
          }
          local_14 = (void *)((int)local_14 + local_8);
          local_10 = (void *)((int)local_10 + local_c);
          arg_6 = arg_6 + -1;
        }
      }
      else {
        val_2 = (int)(uint32_t)*(uint16_t *)(*(int *)((int)this + 4) + 0xe) >> 3;
        local_28 = val_2;
        local_20 = 0xffffff;
        if (*(int *)((int)this + 0x10) == 0) {
          while (arg_6 != 0) {
            memmove(local_10,local_14,val_2 * arg_5);
            local_14 = (void *)((int)local_14 + local_8);
            local_10 = (void *)((int)local_10 + local_c);
            arg_6 = arg_6 + -1;
          }
        }
        else {
          while (arg_6 != 0) {
            local_30 = 0;
            for (local_24 = 0; local_24 < arg_5; local_24 = local_24 + 1) {
              local_34 = *(uint32_t *)(local_30 + (int)local_14) & 0xffffff;
              if (**(uint32_t **)((int)this + 0x10) != local_34) {
                for (local_2c = 0; local_2c < val_2; local_2c = local_2c + 1) {
                  *(uint8_t *)(local_30 + local_2c + (int)local_10) =
                       *(uint8_t *)((int)&local_34 + local_2c);
                }
              }
              local_30 = local_30 + val_2;
            }
            local_14 = (void *)((int)local_14 + local_8);
            local_10 = (void *)((int)local_10 + local_c);
            arg_6 = arg_6 + -1;
          }
        }
      }
    }
  }
  return;
}



int32_t FUN_10009af2(int arg1,int arg2)

{
  int32_t uval_1;
  int32_t local_c;
  int32_t local_8;
  
  if ((arg2 < 0x101) && (-1 < arg2)) {
    for (local_c = 0; local_c < arg2; local_c = local_c + 1) {
      *(int32_t *)(local_8 + local_c * 4) = *(int32_t *)(arg1 + local_c * 4);
    }
    uval_1 = 0;
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}



void __fastcall FUN_1000a070(CFontDialog *ptr_1)

{
  CFontDialog::GetWeight(ptr_1);
  return;
}



void __fastcall FUN_1000a0a0(CFontDialog *ptr_1)

{
  CFontDialog::GetWeight(ptr_1);
  return;
}



/* Library Function - Single Match
    public: int __thiscall CFontDialog::GetWeight(void)const 
   
   Library: Visual Studio 1998 Debug */

int __thiscall CFontDialog::GetWeight(CFontDialog *this)

{
  return *(int *)(*(int *)(this + 4) + 4);
}



/* Library Function - Single Match
    public: int __thiscall CFontDialog::GetWeight(void)const 
   
   Library: Visual Studio 1998 Debug */

int __thiscall CFontDialog::GetWeight(CFontDialog *this)

{
  return *(int *)(*(int *)(this + 4) + 8);
}



int16_t __fastcall FUN_1000a130(int arg_1)

{
  return *(int16_t *)(*(int *)(arg_1 + 4) + 0xe);
}



void __thiscall FUN_1000a160(void *this,int32_t arg_2)

{
  void *buf_ptr_1;
  
  buf_ptr_1 = operator_new(4);
  *(void **)((int)this + 0x10) = buf_ptr_1;
  if (*(int *)((int)this + 0x10) != 0) {
    **(int32_t **)((int)this + 0x10) = arg_2;
  }
  return;
}



void __fastcall FUN_1000a1b0(int arg_1)

{
  if (*(int *)(arg_1 + 0x10) != 0) {
    operator_delete(*(void **)(arg_1 + 0x10));
  }
  return;
}



uint32_t __fastcall FUN_1000a200(int arg_1)

{
  int val_1;
  
  val_1 = (uint32_t)*(uint16_t *)(*(int *)(arg_1 + 4) + 0xe) * *(int *)(*(int *)(arg_1 + 4) + 4);
  return ((int)(val_1 + (val_1 >> 0x1f & 7U)) >> 3) + 3U & 0xfffffffc;
}



int32_t * __fastcall FUN_1000a250(int32_t *ptr_1)

{
  memset(ptr_1,0,0x1b0);
  ptr_1[4] = 0;
  ptr_1[5] = 0;
  ptr_1[6] = 0;
  ptr_1[100] = 0;
  ptr_1[0x67] = 0;
  ptr_1[0x62] = 0;
  ptr_1[0x5f] = 0;
  ptr_1[0x60] = 0;
  ptr_1[0x61] = 0;
  *ptr_1 = 0;
  return ptr_1;
}



void __fastcall FUN_1000a2f1(int *ptr_1)

{
  thunk_FUN_1000a795(ptr_1);
  return;
}



int32_t __thiscall FUN_1000a30f(void *this,int arg_2,void *ptr_3)

{
  int32_t uval_1;
  void *buf_ptr_2;
  int val_3;
  
  *(int32_t *)((int)this + 0x10) = 0;
  if (*(int *)this != 0) {
    thunk_FUN_1000a795(this);
  }
  uval_1 = DrawDibOpen();
  *(int32_t *)((int)this + 8) = uval_1;
  *(int32_t *)((int)this + 0x18c) = 0;
  if (arg_2 == 0) {
    *(int32_t *)((int)this + 0xc) = *(int32_t *)((int)ptr_3 + 0x10);
  }
  else {
    *(int *)((int)this + 0xc) = arg_2;
  }
  if (*(int *)((int)this + 0xc) == 0x31345649) {
    *(int32_t *)((int)this + 0xc) = 0x31347669;
  }
  uval_1 = ICLocate(0x63646976,arg_2,ptr_3,0,2);
  *(int32_t *)this = uval_1;
  if (*(int *)this == 0) {
    uval_1 = 0x80044071;
  }
  else {
    ICSendMessage(*(int32_t *)this,0x401d,0,0);
    buf_ptr_2 = operator_new(0x428);
    *(void **)((int)this + 0x14) = buf_ptr_2;
    buf_ptr_2 = operator_new(0x428);
    *(void **)((int)this + 0x18) = buf_ptr_2;
    if ((*(int *)((int)this + 0x14) == 0) || (*(int *)((int)this + 0x18) == 0)) {
      assert(s_m_pbiSrc____m_pbiDst_1001070c,s_G__NewMagic_tstvid_Videovcm_cpp_100106ec,0x57);
    }
    if ((*(int *)((int)this + 0x14) == 0) || (*(int *)((int)this + 0x18) == 0)) {
      uval_1 = 3;
    }
    else {
      memset(*(void **)((int)this + 0x18),0,0x428);
      memset(*(void **)((int)this + 0x14),0,0x428);
      memcpy(*(void **)((int)this + 0x14),ptr_3,0x28);
      memcpy(*(void **)((int)this + 0x18),*(void **)((int)this + 0x14),0x28);
      *(int16_t *)(*(int *)((int)this + 0x18) + 0xe) = 0x18;
      *(int32_t *)(*(int *)((int)this + 0x18) + 0x10) = 0;
      *(int32_t *)(*(int *)((int)this + 0x18) + 0x14) = 0;
      *(int32_t *)((int)this + 0x20) = 0;
      *(int32_t *)((int)this + 0x1c) = *(int32_t *)((int)this + 0x20);
      *(int32_t *)((int)this + 0x24) = *(int32_t *)(*(int *)((int)this + 0x14) + 4);
      *(int32_t *)((int)this + 0x28) = *(int32_t *)(*(int *)((int)this + 0x14) + 8);
      *(int32_t *)((int)this + 0x30) = 0;
      *(int32_t *)((int)this + 0x2c) = *(int32_t *)((int)this + 0x30);
      *(int32_t *)((int)this + 0x34) = *(int32_t *)(*(int *)((int)this + 0x14) + 4);
      *(int32_t *)((int)this + 0x38) = *(int32_t *)(*(int *)((int)this + 0x14) + 8);
      *(int32_t *)((int)this + 0x40) = 0;
      *(int32_t *)((int)this + 0x3c) = *(int32_t *)((int)this + 0x40);
      *(int32_t *)((int)this + 0x44) = *(int32_t *)(*(int *)((int)this + 0x14) + 4);
      *(int32_t *)((int)this + 0x48) = *(int32_t *)(*(int *)((int)this + 0x14) + 8);
      *(int32_t *)((int)this + 0x50) = 0;
      *(int32_t *)((int)this + 0x4c) = *(int32_t *)((int)this + 0x50);
      *(int32_t *)((int)this + 0x54) = *(int32_t *)(*(int *)((int)this + 0x14) + 4);
      *(int32_t *)((int)this + 0x58) = *(int32_t *)(*(int *)((int)this + 0x14) + 8);
      if (*(int *)((int)this + 0xc) == 0x31347669) {
        *(int32_t *)((int)this + 0x88) = 0x2c;
        *(int32_t *)((int)this + 0x8c) = 0x31345649;
        *(int32_t *)((int)this + 0x90) = 0x10001;
        *(int32_t *)((int)this + 0x94) = 3;
        *(int32_t *)((int)this + 0x98) = 2;
        *(int32_t *)((int)this + 0x9c) = 0;
        ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0x88,0x2c);
        memcpy((void *)((int)this + 0x5c),(void *)((int)this + 0x88),0x2c);
        *(int32_t *)((int)this + 0x68) = 4;
        *(int32_t *)((int)this + 0x108) = 0x54;
        *(int32_t *)((int)this + 0x10c) = 0x31345649;
        *(int32_t *)((int)this + 0x110) = 0x10001;
        *(int32_t *)((int)this + 0x114) = 1;
        *(int32_t *)((int)this + 0x118) = 2;
        *(int32_t *)((int)this + 0x11c) = 0;
        ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0x108,0x54);
        memcpy((void *)((int)this + 0xb4),(void *)((int)this + 0x108),0x54);
        *(int32_t *)((int)this + 0xc0) = 2;
        *(int *)((int)this + 0xf0) = (int)this + 0x15c;
        *(int32_t *)((int)this + 200) = 0x80000008;
        ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0xb4,0x54);
      }
      val_3 = *(int *)(*(int *)((int)this + 0x14) + 4) + 3;
      val_3 = ((int)(val_3 + (val_3 >> 0x1f & 3U)) >> 2) *
              (uint32_t)*(uint16_t *)(*(int *)((int)this + 0x14) + 0xe) *
              *(int *)(*(int *)((int)this + 0x14) + 8) * 4;
      *(int *)((int)this + 0x198) = (int)(val_3 + (val_3 >> 0x1f & 7U)) >> 3;
      buf_ptr_2 = malloc(*(size_t *)((int)this + 0x198));
      *(void **)((int)this + 0x19c) = buf_ptr_2;
      if (*(int *)((int)this + 0x19c) == 0) {
        uval_1 = 3;
      }
      else {
        uval_1 = 0;
      }
    }
  }
  return uval_1;
}



int32_t __fastcall FUN_1000a795(int *ptr_1)

{
  if (ptr_1[5] != 0) {
    operator_delete((void *)ptr_1[5]);
  }
  if (ptr_1[6] != 0) {
    operator_delete((void *)ptr_1[6]);
  }
  ptr_1[6] = 0;
  ptr_1[5] = ptr_1[6];
  if (ptr_1[0x67] != 0) {
    free((void *)ptr_1[0x67]);
    ptr_1[0x67] = 0;
  }
  if (ptr_1[2] != 0) {
    DrawDibClose(ptr_1[2]);
    ptr_1[2] = 0;
  }
  if (*ptr_1 != 0) {
    ICClose(*ptr_1);
    *ptr_1 = 0;
  }
  if (ptr_1[0x5f] != 0) {
    ptr_1[0x5f] = 0;
  }
  if (ptr_1[0x60] != 0) {
    ptr_1[0x60] = 0;
  }
  *ptr_1 = 0;
  ptr_1[3] = 0;
  return 0;
}



int __thiscall FUN_1000a8d3(void *this,int arg_2)

{
  int val_1;
  HDC pHVar2;
  CPrintPreviewState *this_00;
  int32_t uval_3;
  int32_t *unaff_FS_OFFSET;
  int32_t local_24;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000aba6;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  if ((*(int *)this == 0) || (arg_2 == 0)) {
    val_1 = -1;
  }
  else {
    *(int *)((int)this + 4) = arg_2;
    pHVar2 = CreateCompatibleDC(*(HDC *)((int)this + 4));
    *(HDC *)((int)this + 0x1a0) = pHVar2;
    val_1 = FUN_1000ac38(*(int32_t *)this,0,*(int32_t *)((int)this + 0x14),0,
                         *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                         *(int32_t *)((int)this + 0x18),0,*(int32_t *)((int)this + 0x2c),
                         *(int32_t *)((int)this + 0x30),*(int32_t *)((int)this + 0x34),
                         *(int32_t *)((int)this + 0x38));
    if (val_1 == 0) {
      DAT_100275d0 = 1;
      FUN_1000abc1(*(int32_t *)this,0,*(int32_t *)((int)this + 0x14),0,
                   *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                   *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                   *(int32_t *)((int)this + 0x18),0,*(int32_t *)((int)this + 0x2c),
                   *(int32_t *)((int)this + 0x30),*(int32_t *)((int)this + 0x34),
                   *(int32_t *)((int)this + 0x38));
      if (*(int *)((int)this + 0x180) != 0) {
        this_00 = operator_new(0x18);
        local_8 = 0;
        if (this_00 == (CPrintPreviewState *)0x0) {
          local_24 = 0;
        }
        else {
          local_24 = CPrintPreviewState::CPrintPreviewState(this_00);
        }
        local_8 = 0xffffffff;
        *(int32_t *)((int)this + 0x17c) = local_24;
        if ((*(int *)((int)this + 0x17c) == 0) || (DAT_100275d0 == 0)) {
          if (*(int *)((int)this + 0x17c) != 0) {
            thunk_FUN_100089e8(*(void **)((int)this + 0x17c),*(int **)((int)this + 0x18),
                               *(int32_t *)((int)this + 400));
          }
        }
        else {
          thunk_FUN_100089e8(*(void **)((int)this + 0x17c),*(int **)((int)this + 0x18),
                             *(int32_t *)((int)this + 0x19c));
        }
        (**(code **)(**(int **)((int)this + 0x180) + 0x18))
                  (*(int32_t *)((int)this + 0x17c),0,0,*(int32_t *)((int)this + 0x34),
                   *(int32_t *)((int)this + 0x38),*(int32_t *)((int)this + 0x3c),
                   *(int32_t *)((int)this + 0x40));
      }
      if (DAT_100275d0 != 0) {
        DrawDibBegin(*(int32_t *)((int)this + 8),0,*(int32_t *)((int)this + 0x44),
                     *(int32_t *)((int)this + 0x48),*(int32_t *)((int)this + 0x18),
                     *(int32_t *)((int)this + 0x34),*(int32_t *)((int)this + 0x38),0);
        uval_3 = ftol();
        DrawDibStart(*(int32_t *)((int)this + 8),uval_3);
      }
      SetStretchBltMode(*(HDC *)((int)this + 4),3);
      *(int32_t *)((int)this + 0x10) = 1;
      val_1 = 0;
    }
  }
  *unaff_FS_OFFSET = local_10;
  return val_1;
}



void FUN_1000abc1(int32_t arg_1,int32_t arg_2,int32_t arg_3,int32_t arg_4,
                 int32_t arg_5,int32_t arg_6,int32_t arg_7,int32_t arg_8,
                 int32_t arg_9,int32_t arg_10,int32_t arg_11,int32_t arg_12,
                 int32_t arg_13,int32_t arg_14)

{
  int32_t local_38;
  int32_t local_34;
  int32_t local_30;
  int32_t local_2c;
  int32_t local_28;
  int32_t local_24;
  int32_t local_20;
  int32_t local_1c;
  int32_t local_18;
  int32_t local_14;
  int32_t local_10;
  int32_t local_c;
  int32_t local_8;
  
  local_38 = arg_2;
  local_34 = arg_3;
  local_30 = arg_4;
  local_14 = arg_5;
  local_10 = arg_6;
  local_c = arg_7;
  local_8 = arg_8;
  local_2c = arg_9;
  local_28 = arg_10;
  local_24 = arg_11;
  local_20 = arg_12;
  local_1c = arg_13;
  local_18 = arg_14;
  ICSendMessage(arg_1,0x403c,&local_38,0x34);
  return;
}



void FUN_1000ac38(int32_t arg_1,int32_t arg_2,int32_t arg_3,int32_t arg_4,
                 int32_t arg_5,int32_t arg_6,int32_t arg_7,int32_t arg_8,
                 int32_t arg_9,int32_t arg_10,int32_t arg_11,int32_t arg_12,
                 int32_t arg_13,int32_t arg_14)

{
  int32_t local_38;
  int32_t local_34;
  int32_t local_30;
  int32_t local_2c;
  int32_t local_28;
  int32_t local_24;
  int32_t local_20;
  int32_t local_1c;
  int32_t local_18;
  int32_t local_14;
  int32_t local_10;
  int32_t local_c;
  int32_t local_8;
  
  local_38 = arg_2;
  local_34 = arg_3;
  local_30 = arg_4;
  local_14 = arg_5;
  local_10 = arg_6;
  local_c = arg_7;
  local_8 = arg_8;
  local_2c = arg_9;
  local_28 = arg_10;
  local_24 = arg_11;
  local_20 = arg_12;
  local_1c = arg_13;
  local_18 = arg_14;
  ICSendMessage(arg_1,0x403d,&local_38,0x34);
  return;
}



int32_t __fastcall FUN_1000acaf(int32_t *ptr_1)

{
  int32_t uval_1;
  
  ptr_1[4] = 0;
  if (ptr_1[1] == 0) {
    uval_1 = 0xffffffff;
  }
  else {
    ICSendMessage(*ptr_1,0x403f,0,0);
    if (ptr_1[0x5f] != 0) {
      if ((void *)ptr_1[0x5f] != (void *)0x0) {
        thunk_FUN_10004b70((void *)ptr_1[0x5f],1);
      }
    }
    if (DAT_100275d0 != 0) {
      DrawDibStop(ptr_1[2]);
      DrawDibEnd(ptr_1[2]);
    }
    if (ptr_1[0x6a] != 0) {
      SelectPalette((HDC)ptr_1[1],(HPALETTE)ptr_1[0x6a],0);
    }
    if (ptr_1[0x6b] != 0) {
      SelectPalette((HDC)ptr_1[0x68],(HPALETTE)ptr_1[0x6b],0);
    }
    if (ptr_1[99] != 0) {
      DeleteObject((HGDIOBJ)ptr_1[99]);
      ptr_1[99] = 0;
    }
    if (ptr_1[0x69] != 0) {
      SelectObject((HDC)ptr_1[0x68],(HGDIOBJ)ptr_1[0x69]);
    }
    if (ptr_1[0x68] != 0) {
      DeleteDC((HDC)ptr_1[0x68]);
    }
    ptr_1[1] = 0;
    uval_1 = 0;
  }
  return uval_1;
}



int32_t __fastcall FUN_1000ae35(int32_t *ptr_1)

{
  int32_t uval_1;
  
  uval_1 = ftol(1000000);
  ICDrawBegin(*ptr_1,0,0,0,0,0,0,0,0,0,0,0,0,0,uval_1);
  ICSendMessage(*ptr_1,0x4012,0,0);
  return 0;
}



int32_t __fastcall FUN_1000aea5(int32_t *ptr_1)

{
  ICSendMessage(*ptr_1,0x4013,0,0);
  ICSendMessage(*ptr_1,0x4015,0,0);
  return 0;
}



void FUN_1000aee5(void)

{
  FUN_1000aefa();
  return;
}



void FUN_1000aefa(void)

{
  thunk_FUN_10004af0((int32_t *)&DAT_100275d8);
  return;
}



DWORD __thiscall FUN_1000af14(void *this,int32_t arg_2,int32_t arg_3)

{
  DWORD DVar1;
  int32_t uval_2;
  BOOL BVar3;
  int val_4;
  int32_t local_14;
  
  if (*(int *)((int)this + 0x10) == 0) {
    DVar1 = 0;
  }
  else {
    if (DAT_100275d0 == 0) {
      local_14 = *(int32_t *)((int)this + 400);
    }
    else {
      local_14 = *(int32_t *)((int)this + 0x19c);
    }
    if ((*(int *)((int)this + 0x180) != 0) && (*(int *)((int)this + 0x188) != 0)) {
      (**(code **)(**(int **)((int)this + 0x180) + 0x18))
                (*(int32_t *)((int)this + 0x17c),*(int32_t *)((int)this + 0x16c),
                 *(int32_t *)((int)this + 0x170),*(int32_t *)((int)this + 0x174),
                 *(int32_t *)((int)this + 0x178),
                 *(int *)((int)this + 0x16c) + *(int *)((int)this + 0x3c),
                 *(int *)((int)this + 0x170) + *(int *)((int)this + 0x40));
    }
    DVar1 = FUN_1000b284(*(int32_t *)this,arg_3,*(int32_t *)((int)this + 0x14),arg_2,
                         *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                         *(int32_t *)((int)this + 0x18),local_14,0,0,
                         *(int32_t *)((int)this + 0x34),*(int32_t *)((int)this + 0x38));
    if (DVar1 == 0) {
      if ((*(int *)((int)this + 0x180) != 0) && (*(int *)((int)this + 0x188) != 0)) {
        memcpy((void *)((int)this + 0x16c),(void *)((int)this + 0x15c),0x10);
      }
      if (*(int *)((int)this + 0x184) != 0) {
        uval_2 = (**(code **)(**(int **)((int)this + 0x17c) + 0xc))(0,0);
        uval_2 = (**(code **)(**(int **)((int)this + 0x17c) + 8))(uval_2);
        (**(code **)(**(int **)((int)this + 0x184) + 0x18))
                  (*(int32_t *)((int)this + 0x17c),0,0,uval_2);
      }
      if (DAT_100275d0 == 0) {
        if ((*(int *)((int)this + 0x44) == *(int *)((int)this + 0x34)) &&
           (*(int *)((int)this + 0x48) == *(int *)((int)this + 0x38))) {
          BVar3 = BitBlt(*(HDC *)((int)this + 4),*(int *)((int)this + 0x4c),
                         *(int *)((int)this + 0x50),*(int *)((int)this + 0x54),
                         *(int *)((int)this + 0x58),*(HDC *)((int)this + 0x1a0),0,0,0xcc0020);
          if (BVar3 == 0) {
            DVar1 = GetLastError();
            return DVar1;
          }
        }
        else {
          BVar3 = StretchBlt(*(HDC *)((int)this + 4),*(int *)((int)this + 0x3c),
                             *(int *)((int)this + 0x40),*(int *)((int)this + 0x44),
                             *(int *)((int)this + 0x48),*(HDC *)((int)this + 0x1a0),
                             *(int *)((int)this + 0x2c),*(int *)((int)this + 0x30),
                             *(int *)((int)this + 0x34),*(int *)((int)this + 0x38),0xcc0020);
          if (BVar3 == 0) {
            DVar1 = GetLastError();
            return DVar1;
          }
        }
        GdiFlush();
      }
      else {
        val_4 = DrawDibDraw(*(int32_t *)((int)this + 8),*(int32_t *)((int)this + 4),
                            *(int32_t *)((int)this + 0x3c),*(int32_t *)((int)this + 0x40),
                            *(int32_t *)((int)this + 0x44),*(int32_t *)((int)this + 0x48),
                            *(int32_t *)((int)this + 0x18),local_14,0,0,
                            *(int32_t *)((int)this + 0x34),*(int32_t *)((int)this + 0x38),0);
        if (val_4 == 0) {
          return 0;
        }
      }
      DVar1 = 0;
    }
  }
  return DVar1;
}



void FUN_1000b284(int32_t arg_1,int32_t arg_2,int32_t arg_3,int32_t arg_4,
                 int32_t arg_5,int32_t arg_6,int32_t arg_7,int32_t arg_8,
                 int32_t arg_9,int32_t arg_10,int32_t arg_11,int32_t arg_12,
                 int32_t arg_13,int32_t arg_14)

{
  int32_t local_38;
  int32_t local_34;
  int32_t local_30;
  int32_t local_2c;
  int32_t local_28;
  int32_t local_24;
  int32_t local_20;
  int32_t local_1c;
  int32_t local_18;
  int32_t local_14;
  int32_t local_10;
  int32_t local_c;
  int32_t local_8;
  
  local_38 = arg_2;
  local_34 = arg_3;
  local_30 = arg_4;
  local_14 = arg_5;
  local_10 = arg_6;
  local_c = arg_7;
  local_8 = arg_8;
  local_2c = arg_9;
  local_28 = arg_10;
  local_24 = arg_11;
  local_20 = arg_12;
  local_1c = arg_13;
  local_18 = arg_14;
  ICSendMessage(arg_1,0x403e,&local_38,0x34);
  return;
}



int __thiscall FUN_1000b2fb(void *this,int32_t arg_2,int32_t arg_3)

{
  int val_1;
  int32_t local_c;
  
  if (*(int *)((int)this + 0x10) == 0) {
    val_1 = 0;
  }
  else {
    if (DAT_100275d0 == 0) {
      local_c = *(int32_t *)((int)this + 0x19c);
    }
    else {
      local_c = *(int32_t *)((int)this + 400);
    }
    val_1 = FUN_1000b284(*(int32_t *)this,arg_3,*(int32_t *)((int)this + 0x14),arg_2,0,0,
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                         *(int32_t *)((int)this + 0x18),local_c,0,0,
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28));
    if (val_1 == 0) {
      val_1 = 0;
    }
  }
  return val_1;
}



void __thiscall FUN_1000b3b1(void *this,int32_t *ptr_2)

{
  *ptr_2 = *(int32_t *)((int)this + 0x1c);
  ptr_2[1] = *(int32_t *)((int)this + 0x20);
  ptr_2[2] = *(int *)((int)this + 0x24) + *(int *)((int)this + 0x1c);
  ptr_2[3] = *(int *)((int)this + 0x28) + *(int *)((int)this + 0x20);
  return;
}



void __thiscall FUN_1000b404(void *this,int *ptr_2)

{
  *(int *)((int)this + 0x1c) = *ptr_2;
  *(int *)((int)this + 0x20) = ptr_2[1];
  *(int *)((int)this + 0x24) = ptr_2[2] - *ptr_2;
  *(int *)((int)this + 0x28) = ptr_2[3] - ptr_2[1];
  return;
}



void __thiscall FUN_1000b456(void *this,int32_t *ptr_2)

{
  *ptr_2 = *(int32_t *)((int)this + 0x2c);
  ptr_2[1] = *(int32_t *)((int)this + 0x30);
  ptr_2[2] = *(int *)((int)this + 0x2c) + *(int *)((int)this + 0x34);
  ptr_2[3] = *(int *)((int)this + 0x38) + *(int *)((int)this + 0x30);
  return;
}



void __thiscall FUN_1000b4a9(void *this,int *ptr_2)

{
  *(int *)((int)this + 0x2c) = *ptr_2;
  *(int *)((int)this + 0x30) = ptr_2[1];
  *(int *)((int)this + 0x34) = ptr_2[2] - *ptr_2;
  *(int *)((int)this + 0x38) = ptr_2[3] - ptr_2[1];
  return;
}



void __thiscall FUN_1000b4fb(void *this,int32_t *ptr_2)

{
  *ptr_2 = *(int32_t *)((int)this + 0x3c);
  ptr_2[1] = *(int32_t *)((int)this + 0x40);
  ptr_2[2] = *(int *)((int)this + 0x3c) + *(int *)((int)this + 0x44);
  ptr_2[3] = *(int *)((int)this + 0x48) + *(int *)((int)this + 0x40);
  return;
}



void __thiscall FUN_1000b54e(void *this,int *ptr_2)

{
  *(int *)((int)this + 0x3c) = *ptr_2;
  *(int *)((int)this + 0x40) = ptr_2[1];
  *(int *)((int)this + 0x44) = ptr_2[2] - *ptr_2;
  *(int *)((int)this + 0x48) = ptr_2[3] - ptr_2[1];
  if (*(int *)((int)this + 0x180) == 0) {
    *(int32_t *)((int)this + 0x4c) = *(int32_t *)((int)this + 0x3c);
    *(int32_t *)((int)this + 0x50) = *(int32_t *)((int)this + 0x40);
    *(int32_t *)((int)this + 0x54) = *(int32_t *)((int)this + 0x44);
    *(int32_t *)((int)this + 0x58) = *(int32_t *)((int)this + 0x48);
  }
  return;
}



void __thiscall FUN_1000b5e0(void *this,int32_t *ptr_2)

{
  *ptr_2 = *(int32_t *)((int)this + 0x4c);
  ptr_2[1] = *(int32_t *)((int)this + 0x50);
  ptr_2[2] = *(int *)((int)this + 0x4c) + *(int *)((int)this + 0x54);
  ptr_2[3] = *(int *)((int)this + 0x50) + *(int *)((int)this + 0x58);
  return;
}



void __thiscall FUN_1000b633(void *this,int *ptr_2)

{
  *(int *)((int)this + 0x4c) = *ptr_2;
  *(int *)((int)this + 0x50) = ptr_2[1];
  *(int *)((int)this + 0x54) = ptr_2[2] - *ptr_2;
  *(int *)((int)this + 0x58) = ptr_2[3] - ptr_2[1];
  return;
}



int32_t __thiscall FUN_1000b685(void *this,int *ptr_2)

{
  int32_t uval_1;
  
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *ptr_2 = *(int *)((int)this + 0x16c);
    ptr_2[1] = *(int *)((int)this + 0x170);
    ptr_2[2] = *(int *)((int)this + 0x174) + *ptr_2;
    ptr_2[3] = *(int *)((int)this + 0x178) + ptr_2[1];
    uval_1 = 0;
  }
  else {
    uval_1 = 0xffffffff;
  }
  return uval_1;
}



void __thiscall FUN_1000b6ff(void *this,void *ptr_2)

{
  memcpy(ptr_2,*(void **)((int)this + 0x14),0x28);
  return;
}



void __thiscall FUN_1000b72c(void *this,void *ptr_2)

{
  memcpy(*(void **)((int)this + 0x14),ptr_2,0x28);
  return;
}



void __thiscall FUN_1000b759(void *this,void *ptr_2)

{
  memcpy(ptr_2,*(void **)((int)this + 0x18),0x28);
  return;
}



void __thiscall FUN_1000b786(void *this,void *ptr_2)

{
  int val_1;
  void *buf_ptr_2;
  
  if (*(int *)((int)this + 0x180) == 0) {
    memcpy(*(void **)((int)this + 0x18),ptr_2,0x28);
    if (*(uint32_t *)((int)this + 0x198) < *(uint32_t *)((int)ptr_2 + 0x14)) {
      val_1 = *(int *)(*(int *)((int)this + 0x18) + 4) + 3;
      val_1 = ((int)(val_1 + (val_1 >> 0x1f & 3U)) >> 2) *
              (uint32_t)*(uint16_t *)(*(int *)((int)this + 0x18) + 0xe) * *(int *)((int)ptr_2 + 8) * 4;
      *(int *)((int)this + 0x198) = (int)(val_1 + (val_1 >> 0x1f & 7U)) >> 3;
      buf_ptr_2 = realloc(*(void **)((int)this + 0x19c),*(size_t *)((int)this + 0x198));
      *(void **)((int)this + 0x19c) = buf_ptr_2;
    }
  }
  return;
}



int __thiscall FUN_1000b83e(void *this,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  int val_1;
  int local_8;
  
  if (arg_3 == 0) {
    arg_3 = *(int *)((int)this + 0x2c);
  }
  if (arg_4 == 0) {
    arg_4 = *(int *)((int)this + 0x30);
  }
  if (arg_5 == 0) {
    arg_5 = *(int *)((int)this + 0x34);
  }
  if (arg_6 == 0) {
    arg_6 = *(int *)((int)this + 0x38);
  }
  if (arg_2 == 0) {
    local_8 = *(int *)((int)this + 0x18);
  }
  else {
    local_8 = arg_2;
  }
  if ((((arg_3 < 0) || (arg_4 < 0)) || (*(int *)(local_8 + 4) < arg_5 + arg_3)) ||
     (*(int *)(local_8 + 8) < arg_6 + arg_4)) {
    val_1 = -1;
  }
  else {
    val_1 = FUN_1000ac38(*(int32_t *)this,0,*(int32_t *)((int)this + 0x14),0,
                         *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),local_8
                         ,0,arg_3,arg_4,arg_5,arg_6);
    if (val_1 == 0) {
      if ((*(int *)((int)this + 0x180) == 0) ||
         ((*(int *)(local_8 + 4) <= *(int *)((int)this + 0x54) &&
          (*(int *)(local_8 + 8) <= *(int *)((int)this + 0x58))))) {
        val_1 = 0;
      }
      else {
        val_1 = -1;
      }
    }
  }
  return val_1;
}



bool __thiscall FUN_1000b99f(void *this,int arg_2)

{
  int val_1;
  uint32_t uval_2;
  int local_18;
  int local_8;
  
  if (arg_2 == 0) {
    local_8 = ICSendMessage(*(int32_t *)this,0x401d,0,0);
  }
  else {
    val_1 = *(int *)((int)this + 0x18);
    uval_2 = (uint32_t)*(uint16_t *)(arg_2 + 2);
    if (0xeb < *(uint16_t *)(arg_2 + 2)) {
      uval_2 = 0xec;
    }
    for (local_18 = 0; local_18 < (int)uval_2; local_18 = local_18 + 1) {
      *(uint8_t *)(val_1 + 0x52 + local_18 * 4) = *(uint8_t *)(arg_2 + 4 + local_18 * 4);
      *(uint8_t *)(val_1 + 0x51 + local_18 * 4) = *(uint8_t *)(arg_2 + 5 + local_18 * 4);
      *(uint8_t *)(val_1 + 0x50 + local_18 * 4) = *(uint8_t *)(arg_2 + 6 + local_18 * 4);
    }
    *(int32_t *)(*(int *)((int)this + 0x18) + 0x20) = 0x100;
    local_8 = ICSendMessage(*(int32_t *)this,0x401d,*(int32_t *)((int)this + 0x18),0);
    if (local_8 != 0) {
      ICSendMessage(*(int32_t *)this,0x401d,0,0);
    }
  }
  return local_8 == 0;
}



int32_t __thiscall FUN_1000bac7(void *this,int *ptr_2)

{
  int val_1;
  int32_t uval_2;
  
  if (((*(int *)((int)this + 0xc) != 0x31347669) ||
      (val_1 = (**(code **)(*ptr_2 + 8))(), val_1 < *(int *)((int)this + 0x44))) ||
     (val_1 = (**(code **)(*ptr_2 + 0xc))(), val_1 < *(int *)((int)this + 0x48))) {
    return 0;
  }
  if ((*(int *)((int)this + 0x180) != 0) && (*(void **)((int)this + 0x180) != (void *)0x0)) {
    thunk_FUN_10004b70(*(void **)((int)this + 0x180),1);
  }
  if (ptr_2 != (int *)0x0) {
    *(int **)((int)this + 0x180) = ptr_2;
    *(int32_t *)((int)this + 0x50) = 0;
    *(int32_t *)((int)this + 0x4c) = *(int32_t *)((int)this + 0x50);
    uval_2 = (**(code **)(**(int **)((int)this + 0x180) + 8))();
    *(int32_t *)((int)this + 0x54) = uval_2;
    uval_2 = (**(code **)(**(int **)((int)this + 0x180) + 0xc))();
    *(int32_t *)((int)this + 0x58) = uval_2;
    *(int32_t *)((int)this + 0x2c) = 0;
    *(int32_t *)((int)this + 0x30) = 0;
    return 1;
  }
  return 0;
}



int32_t __thiscall FUN_1000bbec(void *this,int arg_2)

{
  int32_t uval_1;
  
  if (*(int *)((int)this + 0x180) == 0) {
    uval_1 = 1;
  }
  else {
    if (arg_2 == 1) {
      *(int32_t *)((int)this + 0x80) = 0;
      *(int32_t *)((int)this + 0x188) = 1;
    }
    else {
      *(int32_t *)((int)this + 0x80) = 0;
      *(int32_t *)((int)this + 0x188) = 0;
    }
    *(int32_t *)((int)this + 0x70) = 0x80000004;
    ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0x5c,0x2c);
    uval_1 = 0;
  }
  return uval_1;
}



int32_t __thiscall FUN_1000bc86(void *this,int *ptr_2)

{
  int val_1;
  
  if (((*(int *)((int)this + 0xc) != 0x31347669) ||
      (val_1 = (**(code **)(*ptr_2 + 8))(), val_1 < *(int *)((int)this + 0x44))) ||
     (val_1 = (**(code **)(*ptr_2 + 0xc))(), val_1 < *(int *)((int)this + 0x48))) {
    return 0;
  }
  if ((*(int *)((int)this + 0x184) != 0) && (*(void **)((int)this + 0x180) != (void *)0x0)) {
    thunk_FUN_10004b70(*(void **)((int)this + 0x180),1);
  }
  if (ptr_2 != (int *)0x0) {
    *(int **)((int)this + 0x184) = ptr_2;
    return 1;
  }
  return 0;
}



bool __thiscall FUN_1000bd47(void *this,int arg_2)

{
  int val_1;
  bool flag_2;
  
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *(int32_t *)((int)this + 0x70) = 0x80000008;
    *(int32_t *)((int)this + 0x68) = 4;
    if (arg_2 == 1) {
      *(int32_t *)((int)this + 0x84) = 0;
    }
    else {
      *(int32_t *)((int)this + 0x84) = 1;
    }
    val_1 = ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0x5c,
                          *(int32_t *)((int)this + 0x5c));
    flag_2 = val_1 == 0;
  }
  else {
    flag_2 = false;
  }
  return flag_2;
}



void __thiscall
FUN_1000bdea(void *this,int32_t *ptr_2,int32_t *ptr_3,int32_t *ptr_4,int arg_5)

{
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *(int32_t *)((int)this + 200) = 0x800000e0;
    if (arg_5 == 0) {
      *(int32_t *)((int)this + 0xc0) = 2;
      ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
    else {
      *(int32_t *)((int)this + 0xc0) = 1;
      ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
    *ptr_2 = *(int32_t *)((int)this + 0xfc);
    *ptr_3 = *(int32_t *)((int)this + 0x100);
    *ptr_4 = *(int32_t *)((int)this + 0x104);
  }
  return;
}



void __thiscall FUN_1000bec3(void *this,int arg_2,int arg_3,int arg_4,int arg_5)

{
  if ((((*(int *)((int)this + 0xc) == 0x31347669) && (-0x100 < arg_2)) && (arg_2 < 0x100)) &&
     (((-0x100 < arg_3 && (arg_3 < 0x100)) && ((-0x100 < arg_4 && (arg_4 < 0x100)))))) {
    *(int32_t *)((int)this + 200) = 0x800000e0;
    if (arg_5 == 0) {
      *(int *)((int)this + 0xfc) = arg_2;
      *(int *)((int)this + 0x100) = arg_3;
      *(int *)((int)this + 0x104) = arg_4;
      *(int32_t *)((int)this + 0xc0) = 2;
      ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0xb4,0x54);
    }
    else {
      *(int32_t *)((int)this + 0xc0) = 1;
      ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
  }
  return;
}



void __thiscall FUN_1000bfe1(void *this,int32_t y,int32_t *width,int height)

{
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *(int32_t *)((int)this + 200) = 0x80000001;
    if (height == 0) {
      *(int32_t *)((int)this + 0xc0) = 2;
      ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
    else {
      *(int32_t *)((int)this + 0xc0) = 1;
      ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
    *width = *(int32_t *)((int)this + 0xcc);
  }
  return;
}



void __thiscall FUN_1000c0a4(void *this,int32_t y,int32_t width,int height)

{
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *(int32_t *)((int)this + 200) = 0x80000001;
    if (height == 0) {
      *(int32_t *)((int)this + 0xc0) = 2;
      *(int32_t *)((int)this + 0xcc) = width;
      ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
    else {
      *(int32_t *)((int)this + 0xc0) = 1;
      ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0xb4,*(int32_t *)((int)this + 0xb4));
    }
  }
  return;
}



void __thiscall FUN_1000c165(void *this,int32_t arg_2)

{
  if (*(int *)((int)this + 0xc) == 0x31347669) {
    *(int32_t *)((int)this + 0x68) = 4;
    *(int32_t *)((int)this + 0x70) = 0x80000001;
    ICSendMessage(*(int32_t *)this,0x5000,(int)this + 0x5c,*(int32_t *)((int)this + 0x5c));
    *(int32_t *)((int)this + 0x78) = 1;
    *(int32_t *)((int)this + 0x74) = arg_2;
    ICSendMessage(*(int32_t *)this,0x5001,(int)this + 0x5c,*(int32_t *)((int)this + 0x5c));
  }
  return;
}



BOOL GetOpenFileNameA(LPOPENFILENAMEA arg_1)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x1000cb84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetOpenFileNameA(arg_1);
  return BVar1;
}



void AVIFileInit(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cb8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIFileInit();
  return;
}



void AVIFileExit(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cb90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIFileExit();
  return;
}



void AVIFileOpenA(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cb96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIFileOpenA();
  return;
}



void AVIFileRelease(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cb9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIFileRelease();
  return;
}



void AVIStreamInfoA(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cba2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamInfoA();
  return;
}



void AVIFileGetStream(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cba8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIFileGetStream();
  return;
}



void AVIStreamRelease(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamRelease();
  return;
}



void AVIStreamTimeToSample(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamTimeToSample();
  return;
}



void AVIStreamSampleToTime(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamSampleToTime();
  return;
}



void DrawDibClose(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DrawDibClose();
  return;
}



void DrawDibDraw(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DrawDibDraw();
  return;
}



void DrawDibOpen(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DrawDibOpen();
  return;
}



void AVIStreamRead(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamRead();
  return;
}



void AVIStreamReadFormat(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamReadFormat();
  return;
}



void AVIStreamFindSample(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AVIStreamFindSample();
  return;
}



void ICSendMessage(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbe4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ICSendMessage();
  return;
}



void ICLocate(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ICLocate();
  return;
}



void ICClose(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ICClose();
  return;
}



void DrawDibStart(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbf6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DrawDibStart();
  return;
}



void DrawDibBegin(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cbfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DrawDibBegin();
  return;
}



void DrawDibEnd(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cc02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DrawDibEnd();
  return;
}



void DrawDibStop(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cc08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DrawDibStop();
  return;
}



void ICDrawBegin(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cc0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ICDrawBegin();
  return;
}



void __cdecl ftol(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000cc50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ftol();
  return;
}



void __cdecl operator_delete(void *ptr_1)

{
                    /* WARNING: Could not recover jumptable at 0x1000cc5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(ptr_1);
  return;
}



void * __cdecl operator_new(uint32_t arg_1)

{
  void *buf_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x1000cc62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  buf_ptr_1 = operator_new(arg_1);
  return buf_ptr_1;
}



/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Debug */

_onexit_t __cdecl __onexit(_onexit_t arg_1)

{
  DWORD DVar1;
  _onexit_t local_c;
  char local_8;
  
  if (DAT_10010730 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_10010730 = DAT_10010730 + 1;
    }
    else {
      DAT_10010730 = DAT_10010730 + -1;
    }
  }
  if (0 < DAT_10010730) {
    while (0 < DAT_10010734) {
      Sleep(0);
    }
    DAT_10010734 = DAT_10010734 + 1;
  }
  if (DAT_10032d04 == -1) {
    local_c = _onexit(arg_1);
  }
  else {
    local_c = (_onexit_t)__dllonexit(arg_1,&DAT_10032d04,&DAT_10032cf4);
  }
  if (0 < DAT_10010730) {
    DAT_10010734 = DAT_10010734 + -1;
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



void * __cdecl memset(void *ptr_1,int arg_2,size_t arg_3)

{
  void *buf_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x1000cd70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  buf_ptr_1 = memset(ptr_1,arg_2,arg_3);
  return buf_ptr_1;
}



int __cdecl abs(int arg_1)

{
  int val_1;
  
                    /* WARNING: Could not recover jumptable at 0x1000cd76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  val_1 = abs(arg_1);
  return val_1;
}



char * __cdecl strcpy(char *str_1,char *str_2)

{
  char *char_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x1000cd88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  char_ptr_1 = strcpy(str_1,str_2);
  return char_ptr_1;
}



void * __cdecl memcpy(void *ptr_1,void *ptr_2,size_t arg_3)

{
  void *buf_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x1000cd8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  buf_ptr_1 = memcpy(ptr_1,ptr_2,arg_3);
  return buf_ptr_1;
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
    if (DAT_10010738 < 1) {
      return 0;
    }
    DAT_10010738 = DAT_10010738 + -1;
  }
  if (DAT_10010730 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_10010730 = DAT_10010730 + 1;
    }
    else {
      DAT_10010730 = DAT_10010730 + -1;
    }
  }
  _DAT_10032cdc = *(int32_t *)_adjust_fdiv_exref;
  if (arg_2 == 1) {
    if ((DAT_10010730 < 0) || (DAT_10010738 == 0)) {
      if (DAT_10010730 < 0) {
        DAT_10032d04 = (int *)malloc_dbg(0x80,2,"crtdll.c",200);
        if (DAT_10032d04 == (int *)0x0) {
          return 0;
        }
      }
      else if ((DAT_10010738 == 0) &&
              (DAT_10032d04 = GlobalAlloc(0x2000,0x80), DAT_10032d04 == (int *)0x0)) {
        return 0;
      }
      *DAT_10032d04 = 0;
      DAT_10032cf4 = DAT_10032d04;
      initterm(&DAT_10010000,&DAT_1001021c);
      DAT_10010738 = DAT_10010738 + 1;
    }
  }
  else if ((arg_2 == 0) &&
          (((DAT_10010730 < 0 || (DAT_10010738 == 0)) && (DAT_10032d04 != (int *)0x0)))) {
    local_c = DAT_10032cf4;
    while (local_c = local_c + -1, DAT_10032d04 <= local_c) {
      if (*local_c != 0) {
        (*(code *)*local_c)();
      }
    }
    if (DAT_10010730 < 0) {
      free_dbg(DAT_10032d04,2);
    }
    else {
      GlobalFree(DAT_10032d04);
    }
    DAT_10032d04 = (int *)0x0;
  }
  return 1;
}



int entry(int32_t arg_1,int arg_2,int32_t arg_3)

{
  int val_1;
  int local_8;
  
  local_8 = 1;
  if ((arg_2 == 0) && (DAT_10010738 == 0)) {
    local_8 = 0;
  }
  else {
    if ((arg_2 == 1) || (arg_2 == 2)) {
      if (DAT_10032ce8 != (code *)0x0) {
        local_8 = (*DAT_10032ce8)(arg_1,arg_2,arg_3);
      }
      if (local_8 != 0) {
        local_8 = __CRT_INIT_12(arg_1,arg_2);
      }
      if (local_8 == 0) {
        return 0;
      }
    }
    local_8 = thunk_FUN_1000286a(arg_1,arg_2);
    if ((arg_2 == 1) && (local_8 == 0)) {
      __CRT_INIT_12(arg_1,0);
    }
    if ((arg_2 == 0) || (arg_2 == 3)) {
      val_1 = __CRT_INIT_12(arg_1,arg_2);
      if (val_1 == 0) {
        local_8 = 0;
      }
      if ((local_8 != 0) && (DAT_10032ce8 != (code *)0x0)) {
        local_8 = (*DAT_10032ce8)(arg_1,arg_2,arg_3);
      }
    }
  }
  return local_8;
}



void __dllonexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000d0ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __dllonexit();
  return;
}



void __cdecl initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000d0f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  initterm();
  return;
}


