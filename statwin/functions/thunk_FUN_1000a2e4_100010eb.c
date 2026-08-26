/*
 * Decompiled function: thunk_FUN_1000a2e4
 * Entry Point: 100010eb
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __thiscall thunk_FUN_1000a2e4(void *this,HWND y,LPCSTR width,uint32_t height)

{
  BOOL BVar1;
  uint16_t *puStack_78;
  int iStack_74;
  int iStack_70;
  uint16_t *puStack_6c;
  uint16_t *puStack_68;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  uint16_t uStack_52;
  int iStack_38;
  size_t sStack_34;
  size_t sStack_30;
  HANDLE pvStack_2c;
  size_t sStack_28;
  void *pvStack_24;
  uint16_t *puStack_20;
  size_t sStack_1c;
  short sStack_18;
  int16_t uStack_16;
  int16_t uStack_14;
  int iStack_e;
  uint16_t *puStack_8;
  
  pvStack_24 = (void *)0x0;
  puStack_20 = (uint16_t *)0x0;
  puStack_8 = (uint16_t *)0x0;
  pvStack_2c = CreateFileA(width,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x10000000,(HANDLE)0x0);
  if (pvStack_2c != (HANDLE)0xffffffff) {
    BVar1 = ReadFile(pvStack_2c,&sStack_18,0xe,&sStack_28,(LPOVERLAPPED)0x0);
    if ((BVar1 == 0) || (sStack_28 != 0xe)) {
      GetLastError();
      CloseHandle(pvStack_2c);
    }
    else if (sStack_18 == 0x4d42) {
      BVar1 = ReadFile(pvStack_2c,&iStack_60,0x28,&sStack_28,(LPOVERLAPPED)0x0);
      if ((BVar1 == 0) || (sStack_28 != 0x28)) {
        CloseHandle(pvStack_2c);
      }
      else if (iStack_60 == 0x28) {
        iStack_38 = FUN_1000a145(&iStack_60);
        sStack_1c = iStack_38 << 2;
        sStack_30 = 0x428;
        sStack_34 = CONCAT22(uStack_14,uStack_16) - iStack_e;
        pvStack_24 = malloc(0x428);
        if (pvStack_24 == (void *)0x0) {
          CloseHandle(pvStack_2c);
        }
        else {
          memset(pvStack_24,0,sStack_30);
          memcpy(pvStack_24,&iStack_60,0x28);
          *(uint16_t *)((int)pvStack_24 + 0xe) = (uint16_t)height;
          if ((iStack_38 == 0) ||
             ((BVar1 = ReadFile(pvStack_2c,(LPVOID)((int)pvStack_24 + 0x28),sStack_1c,&sStack_28,
                                (LPOVERLAPPED)0x0), BVar1 != 0 && (sStack_1c == sStack_28)))) {
            puStack_20 = malloc(sStack_34);
            puStack_8 = puStack_20;
            if (puStack_20 == (uint16_t *)0x0) {
              CloseHandle(pvStack_2c);
            }
            else {
              BVar1 = ReadFile(pvStack_2c,puStack_20,sStack_34,&sStack_28,(LPOVERLAPPED)0x0);
              if ((BVar1 != 0) && (sStack_34 == sStack_28)) {
                if (uStack_52 != height) {
                  sStack_34 = (((int)(iStack_5c * height + ((int)(iStack_5c * height) >> 0x1f & 7U))
                               >> 3) + 3U & 0xfffffffc) * iStack_58;
                  puStack_20 = malloc(sStack_34);
                  if (height == 0x10) {
                    puStack_6c = puStack_8;
                    puStack_68 = puStack_20;
                    for (iStack_74 = 0; iStack_74 < iStack_58; iStack_74 = iStack_74 + 1) {
                      for (iStack_70 = 0; iStack_70 < iStack_5c; iStack_70 = iStack_70 + 1) {
                        *puStack_68 = (*(uint8_t *)((int)pvStack_24 +
                                                (uint32_t)(uint8_t)*puStack_6c * 4 + 0x29) & 0xfff8) * 4 |
                                      (*(uint8_t *)((int)pvStack_24 +
                                                (uint32_t)(uint8_t)*puStack_6c * 4 + 0x2a) & 0xfff8) << 7 |
                                      (uint16_t)((int)(uint32_t)*(uint8_t *)((int)pvStack_24 +
                                                                   (uint32_t)(uint8_t)*puStack_6c * 4 +
                                                                   0x28) >> 3);
                        puStack_6c = (uint16_t *)((int)puStack_6c + 1);
                        puStack_68 = puStack_68 + 1;
                      }
                      puStack_6c = (uint16_t *)
                                   ((int)puStack_6c + ((iStack_5c + 3U & 0xfffffffc) - iStack_5c));
                      puStack_68 = (uint16_t *)
                                   ((int)puStack_68 +
                                   ((((int)(iStack_5c * 0x10 + (iStack_5c * 0x10 >> 0x1f & 7U)) >> 3
                                     ) + 3U & 0xfffffffc) -
                                   ((int)(iStack_5c * 0x10 + (iStack_5c * 0x10 >> 0x1f & 7U)) >> 3))
                                   );
                    }
                  }
                  else if (height == 0x18) {
                    puStack_6c = puStack_8;
                    puStack_78 = puStack_20;
                    for (iStack_74 = 0; iStack_74 < iStack_58; iStack_74 = iStack_74 + 1) {
                      for (iStack_70 = 0; iStack_70 < iStack_5c; iStack_70 = iStack_70 + 1) {
                        *(uint8_t *)(puStack_78 + 1) =
                             *(uint8_t *)((int)pvStack_24 + (uint32_t)(uint8_t)*puStack_6c * 4 + 0x2a);
                        *(uint8_t *)((int)puStack_78 + 1) =
                             *(uint8_t *)((int)pvStack_24 + (uint32_t)(uint8_t)*puStack_6c * 4 + 0x29);
                        *(uint8_t *)puStack_78 =
                             *(uint8_t *)((int)pvStack_24 + (uint32_t)(uint8_t)*puStack_6c * 4 + 0x28);
                        puStack_6c = (uint16_t *)((int)puStack_6c + 1);
                        puStack_78 = (uint16_t *)((int)puStack_78 + 3);
                      }
                      puStack_6c = (uint16_t *)
                                   ((int)puStack_6c + ((iStack_5c + 3U & 0xfffffffc) - iStack_5c));
                      puStack_78 = (uint16_t *)
                                   ((int)puStack_78 +
                                   ((((int)(iStack_5c * 0x18 + (iStack_5c * 0x18 >> 0x1f & 7U)) >> 3
                                     ) + 3U & 0xfffffffc) -
                                   ((int)(iStack_5c * 0x18 + (iStack_5c * 0x18 >> 0x1f & 7U)) >> 3))
                                   );
                    }
                  }
                  free(puStack_8);
                  uStack_52 = (uint16_t)height;
                }
                if (*(int *)((int)this + 4) != 0) {
                  free(*(void **)((int)this + 4));
                }
                *(void **)((int)this + 4) = pvStack_24;
                if (*(int *)((int)this + 8) != 0) {
                  free(*(void **)((int)this + 8));
                }
                *(uint16_t **)((int)this + 8) = puStack_20;
                *(int32_t *)((int)this + 0xc) = 1;
                CloseHandle(pvStack_2c);
                return 1;
              }
            }
          }
          else {
            CloseHandle(pvStack_2c);
          }
        }
      }
      else {
        CloseHandle(pvStack_2c);
        MessageBoxA(y,s_Not_a_Windows_DIB__10013004,s_KPlay_error_10012ff8,0x30);
      }
    }
    else {
      CloseHandle(pvStack_2c);
    }
  }
  if (pvStack_24 != (void *)0x0) {
    free(pvStack_24);
  }
  if (puStack_20 != (uint16_t *)0x0) {
    free(puStack_20);
  }
  return 0;
}


