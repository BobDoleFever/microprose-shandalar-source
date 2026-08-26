/*
 * Decompiled function: AVI_ReleaseFileStream
 * Entry Point: 100019c7
 * Size: 59 bytes
 */
#include "magvid.h"


int32_t __fastcall AVI_ReleaseFileStream(int arg_1)

{
  if (*(int *)(arg_1 + 8) != 0) {
    AVIFileRelease(*(int32_t *)(arg_1 + 8));
    *(int32_t *)(arg_1 + 8) = 0;
  }
  return 0;
}


