/*
 * Decompiled function: FUN_00434660
 * Entry Point: 00434660
 * Size: 589 bytes
 */
#include "duel.h"


int FUN_00434660(uint *arg1,uint *arg2)

{
  FILE *fp;
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  int local_310;
  char local_30c [252];
  uint local_210 [66];
  uint local_108 [63];
  int local_c;
  int local_8;
  
  if (DAT_0066aaf4 != 1) {
    Mem_AllocOrFree_004d9630(local_108,(uint *)&DAT_004f45f8);
    FUN_004d9640(local_108,arg2);
    FUN_004d9640(local_108,(uint *)&DAT_004f45fc);
    Mem_AllocOrFree_004d9630(local_210,(uint *)&DAT_005f76e0);
    FUN_004d9640(local_210,(uint *)&DAT_004f4600);
    Mem_AllocOrFree_004d9630(local_210,arg1);
    fp = _fopen((char *)local_210,&DAT_004f4604);
    if (fp != (FILE *)0x0) {
      do {
        iVar1 = _strcmp((char *)local_108,local_30c);
        if (iVar1 == 0) {
          _fscanf(fp,&DAT_004f4608,&local_8);
          _fgets(local_30c,0x50,fp);
          local_c = 0;
          for (local_310 = 0; (local_310 < local_8 && (local_310 < 0x32)); local_310 = local_310 + 1
              ) {
            pcVar2 = _fgets(&DAT_006679f0 + local_310 * 0xfa,0xfa,fp);
            if (pcVar2 == (char *)0x0) {
              _fclose(fp);
              return -local_c;
            }
            sVar3 = _strlen(&DAT_006679f0 + local_310 * 0xfa);
            (&DAT_006679ef)[local_310 * 0xfa + sVar3] = 0;
            local_c = local_c + 1;
          }
          _fclose(fp);
          if (local_c < local_8) {
            return -local_c;
          }
          return local_c;
        }
        pcVar2 = _fgets(local_30c,0x50,fp);
      } while (pcVar2 != (char *)0x0);
      _fclose(fp);
    }
  }
  return 0;
}


