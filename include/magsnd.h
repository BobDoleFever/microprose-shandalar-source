/*
 * magsnd.h - Function Prototypes and Header for MAGSND.DLL
 * Decompiled using Ghidra on 2026-08-24 21:44:52
 */
#ifndef MAGSND_H
#define MAGSND_H

#include "windows_types.h"
#include "magsnd_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function at 10001000 (Size: 5 bytes) */
void __cdecl thunk_FUN_10005a46(int32_t *ptr_1);;

/* Function at 10001005 (Size: 5 bytes) */
void __cdecl thunk_FUN_1000460c(int arg_1);;

/* Function at 1000100a (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_1000667b(int32_t arg_1,int *ptr_2);;

/* Function at 1000100f (Size: 5 bytes) */
void __cdecl thunk_FUN_1000458d(int arg_1);;

/* Function at 10001014 (Size: 5 bytes) */
int __cdecl SetSndMarker(int arg1,uint32_t arg2);;

/* Function at 10001019 (Size: 5 bytes) */
int32_t __cdecl GetSndState(int arg1,int32_t *arg2);;

/* Function at 1000101e (Size: 5 bytes) */
int32_t __cdecl PlaySnd(int arg1,int *arg2);;

/* Function at 10001023 (Size: 5 bytes) */
int __cdecl thunk_FUN_1000394f(int32_t *ptr_1);;

/* Function at 10001028 (Size: 5 bytes) */
int32_t UnloadAllSnds(void);;

/* Function at 1000102d (Size: 5 bytes) */
int __cdecl thunk_FUN_1000219c(int arg1,int arg2);;

/* Function at 10001032 (Size: 5 bytes) */
int32_t __cdecl GetAVISndBuff(int arg1,uint32_t arg2);;

/* Function at 10001037 (Size: 5 bytes) */
int32_t __cdecl ReleaseAVISndBuff(int arg_1);;

/* Function at 1000103c (Size: 5 bytes) */
void StopAllSnds(void);;

/* Function at 10001041 (Size: 5 bytes) */
int32_t ResetSnd(void);;

/* Function at 10001046 (Size: 5 bytes) */
int32_t __cdecl GetLRUSnd(int *ptr_1,int arg_2,int arg_3);;

/* Function at 1000104b (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_10002900(int arg_1);;

/* Function at 10001050 (Size: 5 bytes) */
int32_t __cdecl InitSnd(int arg_1,int32_t arg_2,uint8_t arg_3);;

/* Function at 10001055 (Size: 5 bytes) */
int32_t __cdecl SetVol(int arg1,uint32_t arg2);;

/* Function at 1000105a (Size: 5 bytes) */
void __cdecl thunk_FUN_10004534(int arg_1);;

/* Function at 1000105f (Size: 5 bytes) */
int32_t __cdecl GetSndTime(int arg1,uint32_t *arg2);;

/* Function at 10001064 (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_1000630c(int32_t *ptr_1);;

/* Function at 10001069 (Size: 5 bytes) */
void __cdecl thunk_FUN_10006830(int32_t *ptr_1,int32_t arg_2);;

/* Function at 1000106e (Size: 5 bytes) */
int32_t thunk_FUN_100046fb(void);;

/* Function at 10001073 (Size: 5 bytes) */
int32_t thunk_FUN_1000681e(void);;

/* Function at 10001078 (Size: 5 bytes) */
int32_t PlayMidiFile(void);;

/* Function at 1000107d (Size: 5 bytes) */
int __cdecl PlaySndMarker(int arg1,uint32_t arg2);;

/* Function at 10001082 (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_10005abe(FILE *fp,int *ptr_2);;

/* Function at 10001087 (Size: 5 bytes) */
int32_t GetSndHWND(void);;

/* Function at 1000108c (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_1000405a(int32_t *ptr_1);;

/* Function at 10001091 (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_10006622(void *ptr_1);;

/* Function at 1000109b (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_10005d4a(int arg1,int arg2);;

/* Function at 100010a0 (Size: 5 bytes) */
int32_t GetPitch(void);;

/* Function at 100010a5 (Size: 5 bytes) */
void thunk_FUN_10004788(void);;

/* Function at 100010aa (Size: 5 bytes) */
int __cdecl PlaySndFile(LPSTR arg_1,int arg_2,int *ptr_3);;

/* Function at 100010af (Size: 5 bytes) */
int32_t GetVol(void);;

/* Function at 100010b4 (Size: 5 bytes) */
int __cdecl thunk_FUN_10006e80(int arg_1);;

/* Function at 100010b9 (Size: 5 bytes) */
void __cdecl thunk_FUN_10003a41(int arg_1);;

/* Function at 100010be (Size: 5 bytes) */
void * __cdecl thunk_FUN_10006540(int *ptr_1,int32_t arg_2,int32_t *ptr_3,int32_t arg_4);;

/* Function at 100010c3 (Size: 5 bytes) */
int __cdecl thunk_FUN_1000207f(int32_t *ptr_1,int arg_2);;

/* Function at 100010c8 (Size: 5 bytes) */
int32_t __cdecl UnloadSnd(int arg_1);;

/* Function at 100010cd (Size: 5 bytes) */
int32_t __cdecl IsSndLoaded(int arg1,int32_t *arg2);;

/* Function at 100010d2 (Size: 5 bytes) */
int32_t __cdecl StopSnd(int arg_1);;

/* Function at 100010d7 (Size: 5 bytes) */
int __cdecl thunk_FUN_1000192c(int32_t *ptr_1,int *ptr_2);;

/* Function at 100010dc (Size: 5 bytes) */
int32_t __cdecl SetPan(int arg1,int arg2);;

/* Function at 100010e1 (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_100055b0(char *str_1,int *ptr_2);;

/* Function at 100010e6 (Size: 5 bytes) */
int32_t __cdecl SetPitch(int arg1,int32_t arg2);;

/* Function at 100010eb (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_10005f0c(int32_t *ptr_1,int arg_2);;

/* Function at 100010f0 (Size: 5 bytes) */
int32_t UpdateSnd(void);;

/* Function at 100010f5 (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_1000560f(LPSTR arg_1,int *ptr_2);;

/* Function at 100010fa (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_100043c4(int arg1,int *arg2);;

/* Function at 100010ff (Size: 5 bytes) */
int32_t __cdecl thunk_FUN_10005dff(FILE *x,int y,long width,uint32_t height);;

/* Function at 10001104 (Size: 5 bytes) */
void ReleaseSnd(void);;

/* Function at 10001109 (Size: 5 bytes) */
int __cdecl LoadSnd(LPSTR arg_1,int arg_2,int arg_3);;

/* Function at 10001113 (Size: 5 bytes) */
void __cdecl thunk_FUN_10004665(int arg_1);;

/* Function at 10001118 (Size: 5 bytes) */
int32_t GetPan(void);;

/* Function at 10001240 (Size: 374 bytes) */
int32_t __cdecl Sound_DirectSoundInit(int arg_1,int32_t arg_2,uint8_t arg_3);;

/* Function at 100013b6 (Size: 114 bytes) */
void Sound_DirectSoundShutdown(void);;

/* Function at 10001428 (Size: 21 bytes) */
int32_t FUN_10001428(void);;

/* Function at 1000143d (Size: 679 bytes) */
int __cdecl FUN_1000143d(LPSTR arg_1,int arg_2,int arg_3);;

/* Function at 100016e4 (Size: 356 bytes) */
int32_t __cdecl Sound_LockAudioBuffer(int arg_1);;

/* Function at 10001848 (Size: 75 bytes) */
int32_t Sound_UnlockAudioBuffer(void);;

/* Function at 10001893 (Size: 153 bytes) */
int32_t __cdecl Sound_SetChannelVolume(int arg1,int *arg2);;

/* Function at 1000192c (Size: 800 bytes) */
int __cdecl Sound_UnloadSample(int32_t *ptr_1,int *ptr_2);;

/* Function at 10001c4c (Size: 1075 bytes) */
int __cdecl Sound_SetChannelPanning(LPSTR arg_1,int arg_2,int *ptr_3);;

/* Function at 1000207f (Size: 285 bytes) */
int __cdecl FUN_1000207f(int32_t *ptr_1,int arg_2);;

/* Function at 1000219c (Size: 285 bytes) */
int __cdecl FUN_1000219c(int arg1,int arg2);;

/* Function at 100022b9 (Size: 208 bytes) */
void __cdecl FUN_100022b9(int *ptr_1,int *ptr_2);;

/* Function at 10002389 (Size: 237 bytes) */
int __cdecl Sound_PlayWaveSample(int arg1,uint32_t arg2);;

/* Function at 10002476 (Size: 549 bytes) */
int __cdecl Sound_StopWaveSample(int arg1,uint32_t arg2);;

/* Function at 1000269b (Size: 522 bytes) */
int32_t __cdecl Sound_GetChannelStatus(int arg_1);;

/* Function at 100028a5 (Size: 91 bytes) */
void Sound_SetMasterVolume(void);;

/* Function at 10002900 (Size: 572 bytes) */
int32_t __cdecl FUN_10002900(int arg_1);;

/* Function at 10002b3c (Size: 18 bytes) */
int32_t FUN_10002b3c(void);;

/* Function at 10002b4e (Size: 262 bytes) */
int32_t __cdecl FUN_10002b4e(int arg1,int32_t arg2);;

/* Function at 10002c54 (Size: 18 bytes) */
int32_t FUN_10002c54(void);;

/* Function at 10002c66 (Size: 503 bytes) */
int32_t __cdecl FUN_10002c66(int arg1,uint32_t arg2);;

/* Function at 10002e62 (Size: 18 bytes) */
int32_t FUN_10002e62(void);;

/* Function at 10002e74 (Size: 273 bytes) */
int32_t __cdecl FUN_10002e74(int arg1,int arg2);;

/* Function at 10002f85 (Size: 18 bytes) */
int32_t FUN_10002f85(void);;

/* Function at 10002f97 (Size: 335 bytes) */
int32_t FUN_10002f97(void);;

/* Function at 100030e6 (Size: 664 bytes) */
int32_t __cdecl FUN_100030e6(int arg1,uint32_t *arg2);;

/* Function at 1000337e (Size: 192 bytes) */
int32_t __cdecl FUN_1000337e(int arg1,int32_t *arg2);;

/* Function at 1000343e (Size: 18 bytes) */
int32_t FUN_1000343e(void);;

/* Function at 10003450 (Size: 142 bytes) */
int32_t __cdecl FUN_10003450(int arg1,int32_t *arg2);;

/* Function at 100034de (Size: 245 bytes) */
int32_t __cdecl FUN_100034de(int *ptr_1,int arg_2,int arg_3);;

/* Function at 100035d3 (Size: 491 bytes) */
int32_t __cdecl FUN_100035d3(int arg1,uint32_t arg2);;

/* Function at 100037be (Size: 401 bytes) */
int32_t __cdecl FUN_100037be(int arg_1);;

/* Function at 1000394f (Size: 242 bytes) */
int __cdecl FUN_1000394f(int32_t *ptr_1);;

/* Function at 10003a41 (Size: 1561 bytes) */
void __cdecl FUN_10003a41(int arg_1);;

/* Function at 1000405a (Size: 874 bytes) */
int32_t __cdecl FUN_1000405a(int32_t *ptr_1);;

/* Function at 100043c4 (Size: 348 bytes) */
int32_t __cdecl FUN_100043c4(int arg1,int *arg2);;

/* Function at 10004534 (Size: 89 bytes) */
void __cdecl FUN_10004534(int arg_1);;

/* Function at 1000458d (Size: 127 bytes) */
void __cdecl FUN_1000458d(int arg_1);;

/* Function at 1000460c (Size: 89 bytes) */
void __cdecl FUN_1000460c(int arg_1);;

/* Function at 10004665 (Size: 127 bytes) */
void __cdecl FUN_10004665(int arg_1);;

/* Function at 100046e4 (Size: 23 bytes) */
void FUN_100046e4(void);;

/* Function at 100046fb (Size: 141 bytes) */
int32_t FUN_100046fb(void);;

/* Function at 10004788 (Size: 95 bytes) */
void FUN_10004788(void);;

/* Function at 100055b0 (Size: 95 bytes) */
int32_t __cdecl FUN_100055b0(char *str_1,int *ptr_2);;

/* Function at 1000560f (Size: 1079 bytes) */
int32_t __cdecl FUN_1000560f(LPSTR arg_1,int *ptr_2);;

/* Function at 10005a46 (Size: 120 bytes) */
void __cdecl FUN_10005a46(int32_t *ptr_1);;

/* Function at 10005abe (Size: 652 bytes) */
int32_t __cdecl FUN_10005abe(FILE *fp,int *ptr_2);;

/* Function at 10005d4a (Size: 181 bytes) */
int32_t __cdecl FUN_10005d4a(int arg1,int arg2);;

/* Function at 10005dff (Size: 269 bytes) */
int32_t __cdecl FUN_10005dff(FILE *x,int y,long width,uint32_t height);;

/* Function at 10005f0c (Size: 1024 bytes) */
int32_t __cdecl FUN_10005f0c(int32_t *ptr_1,int arg_2);;

/* Function at 1000630c (Size: 564 bytes) */
int32_t __cdecl FUN_1000630c(int32_t *ptr_1);;

/* Function at 10006540 (Size: 221 bytes) */
void * __cdecl FUN_10006540(int *ptr_1,int32_t arg_2,int32_t *ptr_3,int32_t arg_4);;

/* Function at 10006622 (Size: 89 bytes) */
int32_t __cdecl FUN_10006622(void *ptr_1);;

/* Function at 1000667b (Size: 419 bytes) */
int32_t __cdecl FUN_1000667b(int32_t arg_1,int *ptr_2);;

/* Function at 1000681e (Size: 18 bytes) */
int32_t FUN_1000681e(void);;

/* Function at 10006830 (Size: 345 bytes) */
void __cdecl FUN_10006830(int32_t *ptr_1,int32_t arg_2);;

/* Function at 10006e80 (Size: 36 bytes) */
int __cdecl FUN_10006e80(int arg_1);;

/* Function at 10006f20 (Size: 6 bytes) */
void AVIStreamRead(void);;

/* Function at 10006f26 (Size: 6 bytes) */
void AVIStreamReadFormat(void);;

/* Function at 10006f2c (Size: 6 bytes) */
void AVIStreamInfoA(void);;

/* Function at 10006f32 (Size: 6 bytes) */
void DirectSoundCreate(void);;

/* Function at 10006f38 (Size: 6 bytes) */
void __cdecl ftol(void);;

/* Function at 10006f46 (Size: 6 bytes) */
void * __cdecl memset(void *ptr_1,int arg_2,size_t arg_3);;

/* Function at 10006f5e (Size: 6 bytes) */
void __cdecl operator_delete(void *ptr_1);;

/* Function at 10006f64 (Size: 6 bytes) */
void * __cdecl operator_new(uint32_t arg_1);;

/* Function at 10006f6a (Size: 6 bytes) */
char * __cdecl strcpy(char *str_1,char *str_2);;

/* Function at 10006f70 (Size: 6 bytes) */
size_t __cdecl strlen(char *str_1);;

/* Function at 10006f90 (Size: 505 bytes) */
int32_t __CRT_INIT@12(int32_t arg_1,int arg_2);;

/* Function at 10007190 (Size: 313 bytes) */
int entry(HMODULE arg_1,int arg_2,int32_t arg_3);;

/* Function at 100072d0 (Size: 208 bytes) */
_onexit_t __cdecl __onexit(_onexit_t arg_1);;

/* Function at 100073a0 (Size: 48 bytes) */
int __cdecl _atexit(_func_4879 *ptr_1);;

/* Function at 100073d6 (Size: 6 bytes) */
void __cdecl initterm(void);;

/* Function at 100073f0 (Size: 56 bytes) */
int32_t _DllMain@12(HMODULE arg_1,int arg_2);;

/* Function at 10007428 (Size: 6 bytes) */
void __dllonexit(void);;


#ifdef __cplusplus
}
#endif

#endif /* MAGSND_H */
