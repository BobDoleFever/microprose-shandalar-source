/*
 * Decompiled function: IsBufferEmpty
 * Entry Point: 10007000
 * Size: 52 bytes
 */
#include "magvid.h"


/* Library Function - Single Match
    public: int __thiscall CArchive::IsBufferEmpty(void)const 
   
   Library: Visual Studio 1998 Debug */

int __thiscall CArchive::IsBufferEmpty(CArchive *this)

{
  return (uint32_t)(*(int *)(this + 0x44) == *(int *)(this + 0x58));
}


