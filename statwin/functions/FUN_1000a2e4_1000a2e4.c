/*
 * Decompiled function: FUN_1000a2e4
 * Entry Point: 1000a2e4
 * Size: 1348 bytes
 */
#include "statwin.h"


int32_t __thiscall FUN_1000a2e4(void *this,HWND y,LPCSTR width,uint32_t height)

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
        local_38 = FUN_1000a145(&local_60);
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
        MessageBoxA(y,s_Not_a_Windows_DIB__10013004,s_KPlay_error_10012ff8,0x30);
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


