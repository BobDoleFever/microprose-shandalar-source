/*
 * Decompiled function: WinMain
 * Entry Point: 00500e80
 * Size: 1337 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WinMain(HINSTANCE x,HINSTANCE y,LPSTR width,int height)

{
  ATOM AVar1;
  HWND pHVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  HDC hdc;
  HANDLE hTargetProcessHandle;
  HANDLE hSourceProcessHandle;
  HANDLE hSourceHandle;
  HANDLE *lpTargetHandle;
  char *pcVar5;
  int iVar6;
  BOOL BVar7;
  char *str_4;
  DWORD dwOptions;
  DWORD local_164;
  int local_160;
  uint local_15c;
  char local_150 [256];
  tagMSG local_50;
  WNDCLASSA local_34;
  HWND local_c;
  HWND local_8;
  
  str_4 = s_Magic__The_Gathering_Shandalar_a_00530db4;
  iVar6 = 0x4f;
  pcVar5 = s_G__NewMagic_sources_sid_Test_c_00530de4;
  pHVar2 = FindWindowA((LPCSTR)0x0,s_Magic__Shandalar_00530e04);
  AssertOrLog((uint)(pHVar2 == (HWND)0x0),(int)pcVar5,iVar6,str_4);
  local_8 = FindWindowA((LPCSTR)0x0,s_Magic__The_Gathering_00530e18);
  if ((local_8 == (HWND)0x0) || (iVar6 = _strnicmp(width,s__MTGshell_00530e30,9), iVar6 == 0)) {
    DVar3 = GetTickCount();
    srand(DVar3);
    Ai_Subsystem_004cd3eb();
    puVar4 = (undefined4 *)__p___argv();
    strcpy(local_150,*(char **)*puVar4);
    pcVar5 = strrchr(local_150,0x5c);
    *pcVar5 = '\0';
    _chdir(local_150);
    DAT_00532550 = 0;
    g_AppHInstance = x;
    local_34.style = 0x23;
    local_34.lpfnWndProc = UI_WndProc_ShowPaletteClass_005013be;
    local_34.cbClsExtra = 0;
    local_34.cbWndExtra = 0;
    local_34.hInstance = x;
    local_34.hIcon = LoadIconA(x,(LPCSTR)0x65);
    local_34.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_34.hbrBackground = GetStockObject(4);
    local_34.lpszMenuName = (LPCSTR)0x0;
    local_34.lpszClassName = s_ShandalarMainClass_00530e3c;
    AVar1 = RegisterClassA(&local_34);
    if (AVar1 == 0) {
      MessageBoxA((HWND)0x0,s_Couldn_t_register_the_classes_00530e50,(LPCSTR)0x0,0x1010);
      local_50.wParam = 0;
    }
    else {
      while ((*width != '\0' && (width[1] != '\0'))) {
        if (width[1] == '6') {
          DAT_00522458 = 0x280;
          DAT_0052245c = 0x1e0;
          PTR_s_advinter800_pic_00530d98 = s_advinter_pic_00530e70;
        }
        local_15c = (uint)(width[1] == '6');
        if (width[1] == '8') {
          DAT_00522458 = 800;
          DAT_0052245c = 600;
          PTR_s_advinter800_pic_00530d98 = s_advinter800_pic_00530e80;
          local_15c = 1;
        }
        if (width[1] == '1') {
          DAT_00522458 = 0x400;
          DAT_0052245c = 0x300;
          PTR_s_advinter800_pic_00530d98 = s_advinter1024_pic_00530e90;
          local_15c = 1;
        }
        if (local_15c != 0) {
          *(int *)(g_DisplaySurfaceScreen + 0xc) = DAT_00522458 + -1;
          *(int *)(g_DisplaySurfaceScreen + 0x10) = DAT_0052245c + -1;
          goto LAB_005011f5;
        }
        *width = '\0';
      }
      iVar6 = 8;
      hdc = GetDC((HWND)0x0);
      local_160 = GetDeviceCaps(hdc,iVar6);
      if (local_160 == 0x280) {
        DAT_00522458 = 0x280;
        DAT_0052245c = 0x1e0;
        PTR_s_advinter800_pic_00530d98 = s_advinter_pic_00530ea4;
      }
      else if (local_160 == 800) {
        DAT_00522458 = 800;
        DAT_0052245c = 600;
        PTR_s_advinter800_pic_00530d98 = s_advinter800_pic_00530eb4;
      }
      else if (local_160 == 0x400) {
        DAT_00522458 = 0x400;
        DAT_0052245c = 0x300;
        PTR_s_advinter800_pic_00530d98 = s_advinter1024_pic_00530ec4;
      }
      *(int *)(g_DisplaySurfaceScreen + 0xc) = DAT_00522458 + -1;
      *(int *)(g_DisplaySurfaceScreen + 0x10) = DAT_0052245c + -1;
LAB_005011f5:
      _hwndScreen = CreateWindowExA(8,s_ShandalarMainClass_00530eec,s_Magic__Shandalar_00530ed8,
                                    0x80000000,0,0,DAT_00522458,DAT_0052245c,(HWND)0x0,(HMENU)0x0,x,
                                    (LPVOID)0x0);
      local_c = _hwndScreen;
      ShowWindow(_hwndScreen,height);
      _hdcScreen = GetDC(local_c);
      Sound_LoadWav_sound_locmus1_005017a6();
      Pic_Subsystem_00423980((int)local_c,0,1);
      if (DAT_0052f008 == 0) {
        Adventure_Audio_PlayFootstep();
      }
      timeBeginPeriod(DAT_00626838);
      DAT_00626818 = timeSetEvent(DAT_00530d94,DAT_00626838,FUN_00501671,0,1);
      if (DAT_00626818 == 0) {
        AssertOrLog(0,0x530f20,0x110,s_Timer_failed_to_initialize__00530f00);
      }
      _atexit(FUN_0050176a);
      AssertOrLog((uint)(DAT_00626818 != 0xffffffff),0x530f58,0x112,s_Could_not_start_timer_00530f40
                 );
      SetSystemPaletteUse(_hdcScreen,2);
      _atexit(FUN_0050178d);
      DAT_00626820 = GetCurrentThread();
      dwOptions = 0;
      BVar7 = 0;
      DVar3 = 0x1f03ff;
      lpTargetHandle = &DAT_00626820;
      hTargetProcessHandle = GetCurrentProcess();
      hSourceHandle = DAT_00626820;
      hSourceProcessHandle = GetCurrentProcess();
      DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,lpTargetHandle,DVar3,
                      BVar7,dwOptions);
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
      _DAT_00626830 =
           CreateThread((LPSECURITY_ATTRIBUTES)0x0,0x2000,Pic_Subsystem_0044b460,(LPVOID)0x0,0,
                        &local_164);
      while (BVar7 = GetMessageA(&local_50,(HWND)0x0,0,0), BVar7 != 0) {
        TranslateMessage(&local_50);
        DispatchMessageA(&local_50);
      }
      DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
    }
  }
  else {
    PostMessageA(local_8,0x400,2,0);
    local_50.wParam = 0;
  }
  return local_50.wParam;
}


