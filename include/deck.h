/*
 * deck.h - Function Prototypes and Header for DECK.EXE
 * Decompiled using Ghidra on 2026-08-24 21:43:55
 */
#ifndef DECK_H
#define DECK_H

#include "windows_types.h"
#include "deck_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function at 00401000 (Size: 5 bytes) */
int32_t thunk_FUN_00401010(int32_t arg_1,int32_t arg_2,char *str_3);;

/* Function at 00401010 (Size: 113 bytes) */
int32_t DeckBuilder_CheckExistingInstance(int32_t arg_1,int32_t arg_2,char *str_3);;

/* Function at 004010aa (Size: 6 bytes) */
void DeckBuilderMain(void);;

/* Function at 004010b0 (Size: 494 bytes) */
void entry(void);;

/* Function at 00401300 (Size: 55 bytes) */
void __cdecl __amsg_exit(int arg_1);;

/* Function at 00401340 (Size: 66 bytes) */
int __cdecl __cinit(int arg_1);;

/* Function at 00401390 (Size: 27 bytes) */
void __cdecl _exit(int arg_1);;

/* Function at 004013b0 (Size: 27 bytes) */
void __cdecl __exit(UINT arg_1);;

/* Function at 004013d0 (Size: 25 bytes) */
void __cdecl __cexit(void);;

/* Function at 004013f0 (Size: 25 bytes) */
void __cdecl __c_exit(void);;

/* Function at 00401410 (Size: 251 bytes) */
void __cdecl doexit(UINT arg_1,int arg_2,int arg_3);;

/* Function at 00401510 (Size: 49 bytes) */
void __cdecl __initterm(int *ptr_1,int *ptr_2);;

/* Function at 00401544 (Size: 32 bytes) */
void __cdecl __global_unwind2(PVOID arg_1);;

/* Function at 00401586 (Size: 104 bytes) */
void __cdecl __local_unwind2(int arg1,int arg2);;

/* Function at 0040161a (Size: 24 bytes) */
void DeckBuilder_InitSubsystems(void);;

/* Function at 00401640 (Size: 500 bytes) */
int __cdecl __XcptFilter(uint32_t card_id,_EXCEPTION_POINTERS *out_filter);;

/* Function at 00401840 (Size: 97 bytes) */
int * __cdecl xcptlookup(int arg_1);;

/* Function at 004018b0 (Size: 32 bytes) */
int __cdecl __ismbbkalnum(uint32_t arg_1);;

/* Function at 004018d0 (Size: 32 bytes) */
int __cdecl __ismbbkprint(uint32_t arg_1);;

/* Function at 004018f0 (Size: 32 bytes) */
int __cdecl __ismbbkpunct(uint32_t arg_1);;

/* Function at 00401910 (Size: 35 bytes) */
int __cdecl __ismbbalnum(uint32_t arg_1);;

/* Function at 00401940 (Size: 35 bytes) */
int __cdecl __ismbbalpha(uint32_t arg_1);;

/* Function at 00401970 (Size: 35 bytes) */
int __cdecl __ismbbgraph(uint32_t arg_1);;

/* Function at 004019a0 (Size: 35 bytes) */
int __cdecl __ismbbprint(uint32_t arg_1);;

/* Function at 004019d0 (Size: 32 bytes) */
int __cdecl __ismbbpunct(uint32_t arg_1);;

/* Function at 004019f0 (Size: 32 bytes) */
int __cdecl __ismbblead(uint32_t arg_1);;

/* Function at 00401a10 (Size: 32 bytes) */
int __cdecl __ismbbtrail(uint32_t arg_1);;

/* Function at 00401a30 (Size: 68 bytes) */
int __cdecl __ismbbkana(uint32_t arg_1);;

/* Function at 00401a80 (Size: 110 bytes) */
int32_t __cdecl x_ismbbtype(uint8_t arg_1,uint32_t arg_2,uint8_t arg_3);;

/* Function at 00401af0 (Size: 318 bytes) */
int __cdecl __setenvp(void);;

/* Function at 00401c30 (Size: 204 bytes) */
int __cdecl __setargv(void);;

/* Function at 00401d00 (Size: 958 bytes) */
void __cdecl parse_cmdline(uint8_t *ptr_1,int32_t *ptr_2,uint8_t *ptr_3,int *ptr_4,int *ptr_5);;

/* Function at 004020c0 (Size: 689 bytes) */
LPVOID __cdecl ___crtGetEnvironmentStringsW(void);;

/* Function at 00402380 (Size: 602 bytes) */
LPVOID __cdecl ___crtGetEnvironmentStringsA(void);;

/* Function at 004025e0 (Size: 815 bytes) */
int __cdecl __setmbcp(int arg_1);;

/* Function at 00402910 (Size: 121 bytes) */
UINT __cdecl getSystemCP(UINT arg_1);;

/* Function at 004029a0 (Size: 107 bytes) */
int32_t __cdecl _CPtoLCID(int32_t arg_1);;

/* Function at 00402a40 (Size: 120 bytes) */
void __cdecl setSBCS(void);;

/* Function at 00402ac0 (Size: 21 bytes) */
int32_t FUN_00402ac0(void);;

/* Function at 00402ae0 (Size: 21 bytes) */
void ___initmbctable(void);;

/* Function at 00402b00 (Size: 808 bytes) */
int __cdecl __ioinit(void);;

/* Function at 00402e30 (Size: 104 bytes) */
void __cdecl __ioterm(void);;

/* Function at 00402ea0 (Size: 93 bytes) */
int __cdecl __heap_init(void);;

/* Function at 00402f00 (Size: 93 bytes) */
void __cdecl __heap_term(void);;

/* Function at 00403025 (Size: 27 bytes) */
void FUN_00403025(int arg_1);;

/* Function at 00403040 (Size: 95 bytes) */
void __cdecl __FF_MSGBANNER(void);;

/* Function at 004030a0 (Size: 537 bytes) */
void __cdecl __NMSG_WRITE(int arg_1);;

/* Function at 004032c0 (Size: 109 bytes) */
wchar_t * __cdecl __GET_RTERRMSG(int arg_1);;

/* Function at 00403340 (Size: 40 bytes) */
void * __cdecl _malloc(size_t arg_1);;

/* Function at 00403370 (Size: 46 bytes) */
void __cdecl __malloc_dbg(uint32_t x,uint32_t y,int width,int32_t height);;

/* Function at 004033a0 (Size: 38 bytes) */
void * __cdecl __nh_malloc(size_t arg_1,int arg_2);;

/* Function at 004033d0 (Size: 101 bytes) */
int32_t * __cdecl __nh_malloc_dbg(uint32_t arg_1,int arg_2,uint32_t arg_3,int arg_4,int32_t arg_5);;

/* Function at 00403440 (Size: 34 bytes) */
void * __cdecl __heap_alloc(size_t arg_1);;

/* Function at 00403470 (Size: 818 bytes) */
int32_t * __cdecl __heap_alloc_dbg(uint32_t x,uint32_t y,int width,int32_t height);;

/* Function at 004037b0 (Size: 38 bytes) */
void * __cdecl _calloc(size_t arg_1,size_t arg_2);;

/* Function at 004037e0 (Size: 110 bytes) */
uint8_t * __cdecl __calloc_dbg(int arg_1,int arg_2,uint32_t arg_3,int arg_4,int32_t arg_5);;

/* Function at 00403850 (Size: 38 bytes) */
void * __cdecl FID_conflict:__expand(void *ptr_1,size_t arg_2);;

/* Function at 00403880 (Size: 55 bytes) */
int * __cdecl __realloc_dbg(void *ptr_1,uint32_t arg_2,uint32_t arg_3,int arg_4,int arg_5);;

/* Function at 004038c0 (Size: 1409 bytes) */
int * __cdecl realloc_help(void *ptr_1,uint32_t arg_2,uint32_t arg_3,int arg_4,int arg_5,int arg_6);;

/* Function at 00403e50 (Size: 38 bytes) */
void * __cdecl FID_conflict:__expand(void *ptr_1,size_t arg_2);;

/* Function at 00403e80 (Size: 55 bytes) */
int * __cdecl __expand_dbg(void *ptr_1,uint32_t arg_2,uint32_t arg_3,int arg_4,int arg_5);;

/* Function at 00403ec0 (Size: 25 bytes) */
void __cdecl FUN_00403ec0(void *ptr_1);;

/* Function at 00403ee0 (Size: 1057 bytes) */
void __cdecl __free_dbg(void *ptr_1,int arg_2);;

/* Function at 00404310 (Size: 30 bytes) */
size_t __cdecl __msize(void *ptr_1);;

/* Function at 00404330 (Size: 358 bytes) */
int32_t __cdecl __msize_dbg(int arg1,int arg2);;

/* Function at 004044a0 (Size: 38 bytes) */
int32_t __cdecl FUN_004044a0(int32_t arg_1);;

/* Function at 004044d0 (Size: 160 bytes) */
void __cdecl __CrtSetDbgBlockType(int arg1,int32_t arg2);;

/* Function at 00404570 (Size: 38 bytes) */
uint8_t * __cdecl FUN_00404570(uint8_t *ptr_1);;

/* Function at 004045a0 (Size: 140 bytes) */
int32_t __cdecl _CheckBytes(char *str_1,char arg_2,int arg_3);;

/* Function at 00404630 (Size: 873 bytes) */
int32_t __CrtCheckMemory(void);;

/* Function at 004049b0 (Size: 48 bytes) */
int __cdecl __CrtSetDbgFlag(int arg_1);;

/* Function at 004049e0 (Size: 105 bytes) */
void __cdecl __CrtDoForAllClientObjects(uint8_t *ptr_1,int32_t arg_2);;

/* Function at 00404a50 (Size: 92 bytes) */
int32_t __cdecl __CrtIsValidPointer(void *ptr_1,UINT_PTR arg_2,int arg_3);;

/* Function at 00404ab0 (Size: 182 bytes) */
BOOL __cdecl __CrtIsValidHeapPointer(int arg_1);;

/* Function at 00404b80 (Size: 255 bytes) */
int32_t __cdecl __CrtIsMemoryBlock(void *ptr_1,UINT_PTR arg_2,int32_t *ptr_3,int32_t *ptr_4,int32_t *ptr_5);;

/* Function at 00404c80 (Size: 38 bytes) */
int32_t __cdecl FUN_00404c80(int32_t arg_1);;

/* Function at 00404cb0 (Size: 316 bytes) */
void __cdecl __CrtMemCheckpoint(int32_t *ptr_1);;

/* Function at 00404df0 (Size: 312 bytes) */
int32_t __cdecl __CrtMemDifference(int32_t *ptr_1,int arg_2,int arg_3);;

/* Function at 00404f30 (Size: 704 bytes) */
void __cdecl __CrtMemDumpAllObjectsSince(int32_t *ptr_1);;

/* Function at 004051f0 (Size: 252 bytes) */
void __cdecl __printMemBlockData(int arg_1);;

/* Function at 004052f0 (Size: 132 bytes) */
int32_t __CrtDumpMemoryLeaks(void);;

/* Function at 00405380 (Size: 199 bytes) */
void __cdecl __CrtMemDumpStatistics(int arg_1);;

/* Function at 00405450 (Size: 7 bytes) */
uint32_t * __cdecl FUN_00405450(uint32_t *ptr_1,uint32_t *ptr_2);;

/* Function at 00405460 (Size: 224 bytes) */
uint32_t * __cdecl FUN_00405460(uint32_t *ptr_1,uint32_t *ptr_2);;

/* Function at 00405540 (Size: 123 bytes) */
size_t __cdecl _strlen(char *str_1);;

/* Function at 004055c0 (Size: 66 bytes) */
size_t __cdecl _wcslen(wchar_t *str_1);;

/* Function at 00405610 (Size: 285 bytes) */
void * __cdecl FID_conflict:_memcpy(void *ptr_1,void *ptr_2,size_t arg_3);;

/* Function at 00405760 (Size: 21 bytes) */
int32_t FUN_00405760(void);;

/* Function at 00405780 (Size: 61 bytes) */
bool __cdecl __set_sbh_threshold(int arg_1);;

/* Function at 004057d0 (Size: 508 bytes) */
uint8_t ** ___sbh_new_region(void);;

/* Function at 004059e0 (Size: 132 bytes) */
void __cdecl ___sbh_release_region(uint8_t **ptr_1);;

/* Function at 00405a70 (Size: 376 bytes) */
void __cdecl ___sbh_decommit_pages(int arg_1);;

/* Function at 00405bf0 (Size: 162 bytes) */
int __cdecl ___sbh_find_block(uint8_t *ptr_1,int32_t *ptr_2,uint32_t *ptr_3);;

/* Function at 00405ca0 (Size: 136 bytes) */
void __cdecl ___sbh_free_block(int arg_1,int arg_2,char *str_3);;

/* Function at 00405d30 (Size: 1207 bytes) */
uint8_t * __cdecl ___sbh_alloc_block(uint32_t arg_1);;

/* Function at 00406200 (Size: 763 bytes) */
int __cdecl ___sbh_alloc_block_from_page(int *ptr_1,uint32_t arg_2,uint32_t arg_3);;

/* Function at 00406500 (Size: 439 bytes) */
int32_t __cdecl ___sbh_resize_block(int x,int32_t *y,uint8_t *width,uint32_t height);;

/* Function at 004066c0 (Size: 617 bytes) */
int32_t ___sbh_heap_check(void);;

/* Function at 00406930 (Size: 223 bytes) */
int __cdecl ___crtMessageBoxA(LPCSTR arg_1,LPCSTR arg_2,UINT arg_3);;

/* Function at 00406a10 (Size: 254 bytes) */
char * __cdecl _strncpy(char *str_1,char *str_2,size_t arg_3);;

/* Function at 00406b10 (Size: 17 bytes) */
void __CrtDbgBreak(void);;

/* Function at 00406b30 (Size: 126 bytes) */
int32_t __cdecl __CrtSetReportMode(int arg1,uint32_t arg2);;

/* Function at 00406bb0 (Size: 169 bytes) */
int32_t __cdecl __CrtSetReportFile(int arg1,int arg2);;

/* Function at 00406c60 (Size: 38 bytes) */
int32_t __cdecl FUN_00406c60(int32_t arg_1);;

/* Function at 00406c90 (Size: 998 bytes) */
int32_t __cdecl __CrtDbgReport(int arg_1,int arg_2,int arg_3,int32_t arg_4,char *str_5);;

/* Function at 00407080 (Size: 813 bytes) */
bool _CrtMessageWindow(void);;

/* Function at 004073b0 (Size: 38 bytes) */
int32_t __cdecl FUN_004073b0(int32_t arg_1);;

/* Function at 004073e0 (Size: 21 bytes) */
int32_t FUN_004073e0(void);;

/* Function at 00407400 (Size: 62 bytes) */
int __cdecl __callnewh(size_t arg_1);;

/* Function at 00407440 (Size: 88 bytes) */
void * __cdecl _memset(void *ptr_1,int arg_2,size_t arg_3);;

/* Function at 004074a0 (Size: 34 bytes) */
void __cdecl __malloc_base(uint32_t arg_1);;

/* Function at 004074d0 (Size: 150 bytes) */
uint8_t * __cdecl __nh_malloc_base(uint32_t arg1,int arg2);;

/* Function at 00407570 (Size: 99 bytes) */
uint8_t * __cdecl __heap_alloc_base(int arg_1);;

/* Function at 004075e0 (Size: 21 bytes) */
int32_t FUN_004075e0(void);;

/* Function at 00407600 (Size: 195 bytes) */
uint8_t * __cdecl __expand_base(uint8_t *ptr_1,uint32_t arg_2);;

/* Function at 004076d0 (Size: 518 bytes) */
uint8_t * __cdecl __realloc_base(uint8_t *ptr_1,uint32_t arg_2);;

/* Function at 004078e0 (Size: 105 bytes) */
void __cdecl __free_base(uint8_t *ptr_1);;

/* Function at 00407950 (Size: 120 bytes) */
int __cdecl __heapchk(void);;

/* Function at 004079d0 (Size: 21 bytes) */
int __cdecl __heapset(uint32_t arg_1);;

/* Function at 004079f0 (Size: 236 bytes) */
int __cdecl _sprintf(char *str_1,char *str_2,...);;

/* Function at 00407ae0 (Size: 182 bytes) */
int __cdecl __isctype(int arg1,int arg2);;

/* Function at 00407ba0 (Size: 88 bytes) */
char * __cdecl __itoa(int arg_1,char *str_2,int arg_3);;

/* Function at 00407c00 (Size: 181 bytes) */
void __cdecl xtoa(uint32_t x,char *y,uint32_t width,int height);;

/* Function at 00407cc0 (Size: 85 bytes) */
char * __cdecl __ltoa(long arg_1,char *str_2,int arg_3);;

/* Function at 00407d20 (Size: 41 bytes) */
char * __cdecl __ultoa(uint32_t arg_1,char *str_2,int arg_3);;

/* Function at 00407d50 (Size: 102 bytes) */
char * __cdecl __i64toa(longlong arg_1,char *str_2,int arg_3);;

/* Function at 00407dc0 (Size: 216 bytes) */
void x64toa(undefined8 x,char *y,uint32_t width,int height);;

/* Function at 00407ea0 (Size: 42 bytes) */
char * __cdecl __ui64toa(ulonglong arg_1,char *str_2,int arg_3);;

/* Function at 00407ed0 (Size: 235 bytes) */
int __cdecl __snprintf(char *str_1,size_t arg_2,char *str_3,...);;

/* Function at 00407fc0 (Size: 229 bytes) */
int __cdecl __vsnprintf(char *str_1,size_t arg_2,char *str_3,va_list arg_4);;

/* Function at 004080b0 (Size: 47 bytes) */
void FUN_004080b0(void);;

/* Function at 004080e0 (Size: 432 bytes) */
void __cdecl _signal(int arg_1);;

/* Function at 004082c0 (Size: 136 bytes) */
int32_t ctrlevent_capture(int arg_1);;

/* Function at 00408350 (Size: 475 bytes) */
int __cdecl _raise(int arg_1);;

/* Function at 00408570 (Size: 99 bytes) */
int32_t * __cdecl siglookup(int arg_1);;

/* Function at 004085e0 (Size: 660 bytes) */
int __cdecl __flsbuf(int arg1,FILE *arg2);;

/* Function at 00408880 (Size: 3177 bytes) */
int __cdecl __output(FILE *fp,uint8_t *ptr_2,int32_t *ptr_3);;

/* Function at 00409610 (Size: 117 bytes) */
void __cdecl write_char(int arg_1,FILE *fp,int *ptr_3);;

/* Function at 00409690 (Size: 75 bytes) */
void __cdecl write_multi_char(int x,int y,FILE *width,int *height);;

/* Function at 004096e0 (Size: 87 bytes) */
void __cdecl write_string(char *x,int y,FILE *width,int *height);;

/* Function at 00409740 (Size: 30 bytes) */
int32_t __cdecl get_int_arg(int *ptr_1);;

/* Function at 00409760 (Size: 35 bytes) */
undefined8 __cdecl get_int64_arg(int *ptr_1);;

/* Function at 00409790 (Size: 31 bytes) */
int32_t __cdecl get_short_arg(int *ptr_1);;

/* Function at 004097b0 (Size: 607 bytes) */
void __cdecl ___crtGetStringTypeW(DWORD arg_1,LPCWSTR arg_2,int arg_3,LPWORD arg_4,UINT arg_5,LCID arg_6);;

/* Function at 00409a10 (Size: 406 bytes) */
BOOL __cdecl ___crtGetStringTypeA(_locale_t arg_1,DWORD arg_2,LPCSTR arg_3,int arg_4,LPWORD arg_5,int arg_6,BOOL arg_7);;

/* Function at 00409bb0 (Size: 104 bytes) */
undefined8 __aulldiv(uint32_t x,uint32_t y,uint32_t width,uint32_t height);;

/* Function at 00409c20 (Size: 117 bytes) */
undefined8 __aullrem(uint32_t x,uint32_t y,uint32_t width,uint32_t height);;

/* Function at 00409ca0 (Size: 744 bytes) */
int __cdecl __write(int arg_1,void *ptr_2,uint32_t arg_3);;

/* Function at 00409fa0 (Size: 285 bytes) */
long __cdecl __lseek(int arg_1,long arg_2,int arg_3);;

/* Function at 0040a0c0 (Size: 188 bytes) */
void __cdecl __getbuf(FILE *fp);;

/* Function at 0040a180 (Size: 66 bytes) */
int __cdecl __isatty(int arg_1);;

/* Function at 0040a1d0 (Size: 338 bytes) */
void ___initstdio(void);;

/* Function at 0040a330 (Size: 36 bytes) */
void ___endstdio(void);;

/* Function at 0040a360 (Size: 198 bytes) */
int __cdecl _wctomb(char *str_1,wchar_t arg_2);;

/* Function at 0040a430 (Size: 285 bytes) */
void * __cdecl FID_conflict:_memcpy(void *ptr_1,void *ptr_2,size_t arg_3);;

/* Function at 0040a580 (Size: 177 bytes) */
void __cdecl __dosmaperr(uint32_t arg_1);;

/* Function at 0040a640 (Size: 333 bytes) */
int __cdecl __alloc_osfhnd(void);;

/* Function at 0040a790 (Size: 234 bytes) */
int __cdecl __set_osfhnd(int arg1,intptr_t arg2);;

/* Function at 0040a890 (Size: 263 bytes) */
int __cdecl __free_osfhnd(int arg_1);;

/* Function at 0040a9b0 (Size: 118 bytes) */
intptr_t __cdecl __get_osfhandle(int arg_1);;

/* Function at 0040aa30 (Size: 256 bytes) */
int __cdecl __open_osfhandle(intptr_t arg1,int arg2);;

/* Function at 0040ab30 (Size: 187 bytes) */
int __cdecl __fcloseall(void);;

/* Function at 0040abf0 (Size: 126 bytes) */
int __cdecl _fflush(FILE *fp);;

/* Function at 0040ac70 (Size: 186 bytes) */
int __cdecl __flush(FILE *fp);;

/* Function at 0040ad30 (Size: 26 bytes) */
int __cdecl __flushall(void);;

/* Function at 0040ad50 (Size: 247 bytes) */
int __cdecl flsall(int arg_1);;

/* Function at 0040ae50 (Size: 21 bytes) */
void __cdecl __fptrap(void);;

/* Function at 0040ae70 (Size: 237 bytes) */
int __cdecl _fclose(FILE *fp);;

/* Function at 0040af60 (Size: 217 bytes) */
int __cdecl __commit(int arg_1);;

/* Function at 0040b040 (Size: 267 bytes) */
int __cdecl __close(int arg_1);;

/* Function at 0040b150 (Size: 138 bytes) */
void __cdecl __freebuf(FILE *fp);;

/* Function at 0040b20a (Size: 6 bytes) */
void RtlUnwind(PVOID arg_1,PVOID arg_2,PEXCEPTION_RECORD arg_3,PVOID arg_4);;

/* Function at 0040b300 (Size: 173 bytes) */
int __cdecl __strnicmp(char *str_1,char *str_2,size_t arg_3);;

/* Function at 0040b3b0 (Size: 22 bytes) */
int __cdecl FUN_0040b3b0(int arg_1);;

/* Function at 0040b3d0 (Size: 313 bytes) */
int __cdecl _tolower(int arg_1);;

/* Function at 0040b510 (Size: 760 bytes) */
int __cdecl ___crtLCMapStringW(LPCWSTR arg_1,DWORD arg_2,LPCWSTR arg_3,int arg_4,LPWSTR arg_5,int arg_6);;

/* Function at 0040b810 (Size: 108 bytes) */
int __cdecl wcsncnt(short *ptr_1,int arg_2);;

/* Function at 0040b880 (Size: 791 bytes) */
int __cdecl ___crtLCMapStringA(_locale_t arg_1,LPCWSTR arg_2,DWORD arg_3,LPCSTR arg_4,int arg_5,LPSTR arg_6,int arg_7,int arg_8,BOOL arg_9);;

/* Function at 0040bba0 (Size: 100 bytes) */
size_t __cdecl _strncnt(char *str_1,size_t arg_2);;


#ifdef __cplusplus
}
#endif

#endif /* DECK_H */
