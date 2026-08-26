/*
 * Decompiled function: FUN_10002900
 * Entry Point: 10002900
 * Size: 572 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_10002900(int arg_1)

{
  int32_t uval_1;
  int val_2;
  int *i_ptr_3;
  int val_4;
  int local_10;
  
  if ((arg_1 < 0x110) && (-1 < arg_1)) {
    if (*(int *)(&DAT_1000a648 + arg_1 * 4) == 0) {
      uval_1 = 1;
    }
    else {
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) >> 6 & 1) == 0) {
        val_4 = (**(code **)(**(int **)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc) + 0x48))
                          (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc));
        if (val_4 != 0) {
          return 9;
        }
      }
      else {
        val_4 = *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 +
                        *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x18) * 4);
        if (val_4 == 0) {
          return 1;
        }
        val_2 = (**(code **)(**(int **)(val_4 + 0xbc) + 0x48))(*(int32_t *)(val_4 + 0xbc));
        if (val_2 != 0) {
          return 9;
        }
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xffffffbf;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) & 0xfffffffe;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) & 0xfffffffd;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) | 4;
        *(uint32_t *)(val_4 + 4) = *(uint32_t *)(val_4 + 4) & 0xffffffdf;
      }
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) == 0) {
        local_10 = 0;
        while ((local_10 < 0x10 &&
               (i_ptr_3 = (int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + local_10 * 0xc + 0xc0),
               *i_ptr_3 != 0))) {
          val_4 = (**(code **)(*(int *)*i_ptr_3 + 0x48))(*i_ptr_3);
          if (val_4 != 0) {
            return 9;
          }
          local_10 = local_10 + 1;
        }
      }
      else if ((0 < DAT_1000a428) && (DAT_1000a428 = DAT_1000a428 + -1, DAT_1000a428 == 0)) {
        thunk_FUN_10004788();
      }
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xfffffffe;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xfffffffd;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) | 4;
      *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
           *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xffffffdf;
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}


