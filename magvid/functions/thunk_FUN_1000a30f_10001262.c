/*
 * Decompiled function: thunk_FUN_1000a30f
 * Entry Point: 10001262
 * Size: 5 bytes
 */
#include "magvid.h"


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


