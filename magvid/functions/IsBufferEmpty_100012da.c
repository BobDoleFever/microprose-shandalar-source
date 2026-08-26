/*
 * Decompiled function: IsBufferEmpty
 * Entry Point: 100012da
 * Size: 5 bytes
 */
#include "magvid.h"


int __thiscall CArchive::IsBufferEmpty(CArchive *this)

{
  return (uint32_t)(*(int *)(this + 0x44) == *(int *)(this + 0x58));
}


