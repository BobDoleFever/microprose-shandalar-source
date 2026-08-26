/*
 * Decompiled function: FUN_004a36e8
 * Entry Point: 004a36e8
 * Size: 1774 bytes
 */
#include "duel.h"


undefined4 FUN_004a36e8(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if ((((DAT_00690c48 == arg_2) && (DAT_0068ecb0 == arg_1)) &&
      (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) &&
     (((byte)DAT_00681eb0 & 4) != 0)) {
    uVar2 = FUN_0048b81a((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                         *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),0x34,0xffffffff);
    if ((uVar2 & 0x1ff800) != 0) {
      cVar1 = FUN_0048c367((&DAT_006826dd)
                           [*(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                            (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20]);
      if ((uVar2 & 0x800 << (cVar1 - 1U & 0x1f)) != 0) {
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        FUN_0046e571(arg_1,arg_2,1);
      }
    }
  }
  if (((arg_3 == 0x6e) && (DAT_00690c48 == arg_2)) &&
     ((DAT_0068ecb0 == arg_1 && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)))) {
    *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    if (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0xe);
      }
      if (*(int *)(&DAT_004ff590 +
                  *(int *)(&DAT_006826c4 +
                          *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                          (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 0x34) ==
          DAT_0066aae8) {
        (&DAT_00690b00)
        [*(int *)(&DAT_006826ec +
                 *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 2 +
         (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] +
         (char)(&DAT_006826d3)
               [*(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] * 0xa0] =
             (&DAT_00690b00)
             [*(int *)(&DAT_006826ec +
                      *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 2 +
              (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] +
              (char)(&DAT_006826d3)
                    [*(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20] * 0xa0] +
             (char)*(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      else {
        (&DAT_00690b00)
        [*(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 2 +
         (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0xa0 +
         (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20]] =
             (&DAT_00690b00)
             [*(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 2 +
              (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0xa0 +
              (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20]] +
             (char)*(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      (&DAT_00681ea8)[(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20]] =
           (&DAT_00681ea8)[(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20]] -
           *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(int *)(&DAT_0068eea0 + (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 4) =
           *(int *)(&DAT_0068eea0 + (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 4) +
           *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    else {
      iVar3 = FUN_0048a33f((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                           *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20));
      if ((iVar3 != 0) &&
         (*(short *)(&DAT_006826d0 +
                    *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
               *(short *)(&DAT_006826d0 +
                         *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                         (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) +
               (short)*(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20),
         DAT_0066aaf4 != 1)) {
        FUN_0048d00c(0x16);
        FUN_00450eb8((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                     *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),6,2);
      }
    }
  }
  return 0;
}


