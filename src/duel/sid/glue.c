/*
 * sid/glue.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 303
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Glue_Timer_004cd63b
 * Entry Point: 004520a8
 * Size: 171 bytes
 */


int32_t Glue_Timer_004cd63b(void)

{
  int slot_idx;
  
  if (DAT_00693428 == (HANDLE)0x0) {
    DAT_00693428 = CreateFileA(s_____MPStime_VXD_004f8660,0,0,(LPSECURITY_ATTRIBUTES)0x0,0,0x4000000
                               ,(HANDLE)0x0);
    File_Load_Assertfile
              ((uint32_t)(DAT_00693428 != (HANDLE)0xffffffff),0x4f8698,0x2c4,
               s_Could_Not_Load_Dave_s_Extra_Cool_004f8670);
    DeviceIoControl(DAT_00693428,1,(LPVOID)0x0,0,&slot_idx,4,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
    File_Load_Assertfile
              ((uint32_t)(slot_idx == 0x100),0x4f86e8,0x2cb,s_Could_Not_Initialize_Dave_s_Extr_004f86b8);
  }
  return 1;
}



/*
 * Decompiled function: FUN_00452153
 * Entry Point: 00452153
 * Size: 50 bytes
 */


int32_t FUN_00452153(void)

{
  int32_t slot_idx;
  
  DeviceIoControl(DAT_00693428,2,(LPVOID)0x0,0,&slot_idx,4,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  return slot_idx;
}



/*
 * Decompiled function: Mem_AllocOrFree_00452185
 * Entry Point: 00452185
 * Size: 21 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Mem_AllocOrFree_00452185(void)

{
  _DAT_005221f8 = FUN_00452153();
  return;
}



/*
 * Decompiled function: FUN_0045219a
 * Entry Point: 0045219a
 * Size: 53 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0045219a(void)

{
  int val_1;
  
  val_1 = FUN_00452153();
  return ((val_1 - _DAT_005221f8) * 100) / 0x151d;
}



/*
 * Decompiled function: Mem_AllocOrFree_004521d0
 * Entry Point: 004521d0
 * Size: 18 bytes
 */


int32_t Mem_AllocOrFree_004521d0(void)

{
  return 0;
}



/*
 * Decompiled function: FUN_004521e2
 * Entry Point: 004521e2
 * Size: 645 bytes
 */


uint32_t FUN_004521e2(int arg1,int arg2)

{
  char cVar1;
  int val_2;
  uint32_t uval_3;
  int slot_idx;
  
  if (*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) == DAT_0068eee0) {
    slot_idx = *(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20);
  }
  else {
    slot_idx = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
  }
  if (((&DAT_004ff594)[slot_idx * 0x34] & 4) == 0) {
    if (((&DAT_004ff594)[slot_idx * 0x34] & 0x10) == 0) {
      if (((&DAT_004ff594)[slot_idx * 0x34] & 0x20) == 0) {
        if (((&DAT_004ff594)[slot_idx * 0x34] & 8) == 0) {
          val_2 = FUN_0048c367((&DAT_006826dd)[arg2 * 0x120 + arg1 * 0x5b20]);
          cVar1 = FUN_004af7bb(arg1,arg2,val_2);
          uval_3 = 0x800 << (cVar1 - 1U & 0x1f);
        }
        else {
          val_2 = FUN_0048c367((&DAT_006826dd)[arg2 * 0x120 + arg1 * 0x5b20]);
          cVar1 = FUN_004af7bb(arg1,arg2,val_2);
          uval_3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x100000;
        }
      }
      else {
        val_2 = FUN_0048c367((&DAT_006826dd)[arg2 * 0x120 + arg1 * 0x5b20]);
        cVar1 = FUN_004af7bb(arg1,arg2,val_2);
        uval_3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x80000;
      }
    }
    else {
      val_2 = FUN_0048c367((&DAT_006826dd)[arg2 * 0x120 + arg1 * 0x5b20]);
      cVar1 = FUN_004af7bb(arg1,arg2,val_2);
      uval_3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x40000;
    }
  }
  else {
    val_2 = FUN_0048c367((&DAT_006826dd)[arg2 * 0x120 + arg1 * 0x5b20]);
    cVar1 = FUN_004af7bb(arg1,arg2,val_2);
    uval_3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x20000;
  }
  return uval_3;
}



/*
 * Decompiled function: Glue_Subsystem_004d0cdb
 * Entry Point: 0045247b
 * Size: 959 bytes
 */


int32_t Glue_Subsystem_004d0cdb(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int val_2;
  uint32_t *u_ptr_3;
  int32_t uval_4;
  uint8_t slot_idx;
  
  if (((((DAT_0068f230 == 0xc9) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 && (arg_1 == DAT_00666458)))) && (DAT_00681ec4 == arg_1)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x29);
      }
      val_2 = FUN_00439892(5);
      slot_idx = (uint8_t)(val_2 + 1);
      (&DAT_006826dd)[arg_2 * 0x120 + arg_1 * 0x5b20] = (char)(1 << (slot_idx & 0x1f));
      Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_changes_color_to_004f8708);
      u_ptr_3 = (uint32_t *)Mem_AllocOrFree_0048c420(val_2 + 1);
      FUN_004d9640((uint32_t *)&DAT_005f6810,u_ptr_3);
      Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,0);
    }
  }
  if (arg_3 == 0x73) {
    if ((*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) &&
       (val_2 = FUN_0049b309(arg_1,7,2), val_2 != 0)) {
      uval_4 = 1;
    }
    else {
      uval_4 = 0;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (val_2 = FUN_0049b309(arg_1,7,2), val_2 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,2);
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x29);
        }
        val_2 = FUN_00439892(5);
        slot_idx = (uint8_t)(val_2 + 1);
        (&DAT_006826dd)
        [*(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20] =
             (char)(1 << (slot_idx & 0x1f));
        Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_changes_color_to_004f871c);
        u_ptr_3 = (uint32_t *)Mem_AllocOrFree_0048c420(val_2 + 1);
        FUN_004d9640((uint32_t *)&DAT_005f6810,u_ptr_3);
        Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,0);
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint32_t *)(&DAT_006826e4 +
                      *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) |
             1 << ((uint8_t)DAT_00666458 & 0x1f);
      }
    }
    if ((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) {
      flag_1 = true;
    }
    else {
      flag_1 = false;
    }
    if (flag_1) {
      *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uval_4 = 0;
  }
  return uval_4;
}



/*
 * Decompiled function: Glue_Subsystem_004d109a
 * Entry Point: 0045283a
 * Size: 3108 bytes
 */


int32_t Glue_Subsystem_004d109a(int player_id,int card_slot,int event_type)

{
  uint8_t flag_1;
  int val_2;
  int32_t uval_3;
  int val_4;
  uint32_t uval_5;
  uint32_t *arg2;
  int card_idx;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    flag_1 = FUN_00439892(5);
    *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0x800 << (flag_1 & 0x1f);
  }
  if (arg_3 == 0x71) {
    *(uint32_t *)(&DAT_006826fc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826fc + arg_2 * 0x120 + arg_1 * 0x5b20) |
         *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 0x73) {
    val_2 = FUN_0049b309(arg_1,5,2);
    if (val_2 == 0) {
      val_2 = FUN_0049b309(arg_1,7,1);
      if ((val_2 == 0) || (((&DAT_006826f1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
        uval_3 = 0;
      }
      else {
        uval_3 = 1;
      }
    }
    else {
      uval_3 = 1;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      val_2 = FUN_0049b309(arg_1,7,1);
      val_4 = FUN_0049b309(arg_1,5,2);
      *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffe;
      if ((val_4 != 0) ||
         ((val_2 != 0 && (((&DAT_006826f1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0)))) {
        if (val_4 == 0) {
          Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s__Add_random_power__004f8744);
        }
        else {
          Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Add_random_power__004f8730);
        }
        if ((val_2 == 0) || (((&DAT_006826f1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
          FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s__Gain_first_strike__004f8770);
        }
        else {
          FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Gain_first_strike__004f8758);
        }
        FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Cancel__004f8788);
        if ((DAT_006826b0 == 0) ||
           ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 8) == 0 &&
            ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) == 0 ||
             (((&DAT_006826cd)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) == 0)))))) {
          if (val_4 == 0) {
            if ((val_2 == 0) || (((&DAT_006826f1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
              card_idx = 2;
            }
            else {
              card_idx = 1;
            }
          }
          else {
            card_idx = 0;
          }
        }
        else if ((val_2 == 0) || (((&DAT_006826f1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
          if (val_4 == 0) {
            card_idx = 2;
          }
          else {
            card_idx = 0;
          }
        }
        else {
          card_idx = 1;
        }
        val_2 = Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,card_idx);
        if (val_2 == 0) {
          if ((val_4 != 0) && (Ai_CalcManaRequirement_004ba890(arg_1,5,2), DAT_00681ea4 != 1)) {
            *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
            *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
            (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
            if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
              *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
                   *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
            }
          }
        }
        else if (val_2 == 1) {
          Ai_CalcManaRequirement_004ba890(arg_1,0,1);
          if (DAT_00681ea4 != 1) {
            *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
            *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
            (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
            *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
          }
        }
        else if (val_2 == 2) {
          DAT_00681ea4 = 1;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else if (((&DAT_006826f0)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0) {
        uval_5 = FUN_00439892(3);
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (uval_5 & 0xff);
        Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Power_increased_by_004f8794);
        arg2 = (uint32_t *)__itoa(uval_5,&DAT_00522418,10);
        FUN_004d9640((uint32_t *)&DAT_005f6810,arg2);
        Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,0);
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x2e);
        }
        if ((uval_5 != 0) &&
           (((&DAT_006826e6)
             [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) != 0)) {
          *(uint32_t *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
               0xfff7ffff;
          val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (val_2 != -1) {
            *(short *)(&DAT_006826d8 + val_2 * 0x120 + arg_1 * 0x5b20) = (short)uval_5;
            *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
            *(int32_t *)(&DAT_006826f0 + val_2 * 0x120 + arg_1 * 0x5b20) = 1;
          }
        }
      }
      else if (((&DAT_006826f1)
                [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 1) == 0) {
        *(uint32_t *)(&DAT_006826f0 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint32_t *)(&DAT_006826f0 +
                      *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) & 0x1ff800;
        *(uint32_t *)(&DAT_006826f0 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint32_t *)(&DAT_006826f0 +
                      *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) | 0x100;
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,DAT_00690af0,DAT_0068efa0);
        if (val_2 != -1) {
          *(int32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) = 0x100;
          *(int32_t *)(&DAT_006826fc + val_2 * 0x120 + arg_1 * 0x5b20) = 0;
          *(int32_t *)(&DAT_006826f0 + val_2 * 0x120 + arg_1 * 0x5b20) = 2;
        }
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x2e);
        }
      }
    }
    if ((((arg_3 == 0x34) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
       (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0)) {
      DAT_0066642c = DAT_0066642c |
                     *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x1ff800;
      uval_5 = DAT_0066642c;
      uval_3 = FUN_0048c367((uint8_t)((*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) &
                                  0x1ff800) >> 10));
      FUN_00464d69(arg_1,arg_2,uval_3);
      DAT_0066642c = uval_5;
    }
    if (((arg_3 == 0x8c) && (arg_2 == DAT_00690c48)) &&
       ((arg_1 == DAT_0068ecb0 && (val_2 = FUN_0049b309(arg_1,7,1), val_2 != 0)))) {
      DAT_00693410 = DAT_00693410 | 0x100;
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffeff;
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: Palette_Subsystem_004a9137
 * Entry Point: 00453463
 * Size: 332 bytes
 */


bool Palette_Subsystem_004a9137(int player_id,int card_slot,int event_type)

{
  int arg_5;
  bool flag_1;
  
  if (arg_3 == 0x73) {
    flag_1 = (*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0;
  }
  else {
    if (arg_3 == 0x6d) {
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      arg_5 = FUN_00487ce1(arg_1);
      Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,arg_1,arg_5,s_Sinbad_draws____004f87a8,0);
      if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_5 * 0x120 + arg_1 * 0x5b20) * 0x34] & 1) ==
          0) {
        FUN_0046f02d(arg_1,arg_5);
        *(int32_t *)(&DAT_006826c4 + arg_5 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
        (&DAT_0068ee78)[arg_1] = (&DAT_0068ee78)[arg_1] + -1;
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x18);
        }
      }
    }
    flag_1 = false;
  }
  return flag_1;
}



/*
 * Decompiled function: FUN_004535af
 * Entry Point: 004535af
 * Size: 796 bytes
 */


int32_t FUN_004535af(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  int card_idx;
  int match_count;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    val_1 = FUN_004d7d5e(0x38f);
    val_1 = Deck_AddCardToDeck(1 - arg_1,val_1);
    if (val_1 != -1) {
      *(uint32_t *)(&DAT_006826cc + val_1 * 0x120 + (1 - arg_1) * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + val_1 * 0x120 + (1 - arg_1) * 0x5b20) | 2;
      *(int32_t *)(&DAT_00682704 + val_1 * 0x120 + (1 - arg_1) * 0x5b20) =
           *(int32_t *)
            (&DAT_004ff590 + *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34);
    }
    *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = val_1;
  }
  if (arg_3 == 0x73) {
    uval_2 = FUN_0049b309(arg_1,3,1);
  }
  else {
    if (arg_3 == 0x6d) {
      val_1 = FUN_0049b309(arg_1,3,1);
      if (val_1 != 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,3,1);
        *(int32_t *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = DAT_00681ea0;
      }
    }
    if ((arg_3 == 0x72) && (*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) != 0)) {
      Mem_AllocOrFree_004afd1c
                (1 - arg_1,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120),arg_1,arg_2);
      Mem_AllocOrFree_004afd1c
                (arg_1,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120),arg_1,arg_2);
      for (match_count = 0; match_count < 2; match_count = match_count + 1) {
        for (card_idx = 0; card_idx < (int)(&DAT_00666408)[match_count]; card_idx = card_idx + 1) {
          val_1 = FUN_0048a33f(match_count,card_idx);
          if (val_1 != 0) {
            uval_3 = FUN_0048b81a(match_count,card_idx,0x34,0xffffffff);
            if ((uval_3 & 0x20) != 0) {
              FUN_004af950(match_count,card_idx,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120)
                           ,arg_1,arg_2);
            }
          }
        }
      }
    }
    if (((arg_3 == 0x77) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      FUN_0046e571(1 - arg_1,*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120),4);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Glue_Subsystem_004d212c
 * Entry Point: 004538cb
 * Size: 1247 bytes
 */


void Glue_Subsystem_004d212c(int player_id,int card_slot,int event_type)

{
  int arg_4;
  int32_t uval_1;
  int val_2;
  int card_idx;
  
  if (arg_3 != 0x73) {
    if (arg_3 == 0x6d) {
      *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1 - arg_1;
      uval_1 = Ai_Subsystem_004cc56d
                        (*(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20),arg_1,arg_2,-1,-1,
                         s_Swap_cards__Lose_10_life__Conced_004f87b8,0);
      *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = uval_1;
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      arg_4 = *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
      val_2 = *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      if (val_2 == 0) {
        *(uint32_t *)(&DAT_006826cc +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) =
             *(uint32_t *)(&DAT_006826cc +
                      *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                      *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) ^ 0x1000;
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0xf);
        }
        FUN_0046e571(DAT_00690af0,DAT_0068efa0,3);
        if (arg_1 == DAT_00676510) {
          FUN_004d76dd(*(uint32_t *)(&DAT_006826c4 +
                                *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                                *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120));
        }
        else {
          Ai_Subsystem_004cc1e8
                    (*(uint32_t *)(&DAT_006826c4 +
                              *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120));
        }
        *(int32_t *)
         (&DAT_006826c4 +
         *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0xffffffff;
        card_idx = 0;
        do {
          do {
            val_2 = FUN_00439892((&DAT_00666408)[arg_4]);
          } while (*(int *)(&DAT_006826c4 + val_2 * 0x120 + arg_4 * 0x5b20) == -1);
        } while ((((&DAT_006826cc)[val_2 * 0x120 + arg_4 * 0x5b20] & 2) != 0) &&
                (card_idx = card_idx + 1, card_idx < 999));
        if (card_idx < 999) {
          Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,arg_4,val_2,s_randomly_chooses____004f87e4,0);
          *(uint32_t *)(&DAT_006826cc + val_2 * 0x120 + arg_4 * 0x5b20) =
               *(uint32_t *)(&DAT_006826cc + val_2 * 0x120 + arg_4 * 0x5b20) ^ 0x1000;
          FUN_0046f02d(arg_4,val_2);
          if (arg_1 == DAT_00676510) {
            Ai_Subsystem_004cc1e8(*(uint32_t *)(&DAT_006826c4 + val_2 * 0x120 + arg_4 * 0x5b20));
          }
          else {
            FUN_004d76dd(*(uint32_t *)(&DAT_006826c4 + val_2 * 0x120 + arg_4 * 0x5b20));
          }
          *(int32_t *)(&DAT_006826c4 + val_2 * 0x120 + arg_4 * 0x5b20) = 0xffffffff;
        }
      }
      else if (val_2 == 1) {
        (&DAT_00681ea8)[arg_4] = (&DAT_00681ea8)[arg_4] + -10;
        FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
      }
      else if (val_2 == 2) {
        (&DAT_00681ea8)[arg_4] = 0xffffff9d;
        FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
      }
    }
  }
  return;
}



/*
 * Decompiled function: Glue_Subsystem_004d2610
 * Entry Point: 00453daf
 * Size: 970 bytes
 */


int32_t Glue_Subsystem_004d2610(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int player_idx;
  int card_idx;
  int match_count;
  
  if (flags == 0x73) {
    if ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_1 = FUN_004521e2(spell_id,target_id);
      val_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0x40,2,0,uval_1,arg_11,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8810,s_XENIC_POLTERGEIST_004f87fc);
      arg_20 = &player_idx;
      uval_1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,spell_id,0x200,0x40,2,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = player_idx;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      player_idx = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      card_idx = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Rules_ParseFilter_0041c0ab
                        (player_idx,card_idx,(uint8_t *)0x0,spell_id,2,2,0x200,0x40,2,0,uval_3,uval_4
                         ,uval_5,val_2,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00666414,player_idx,card_idx);
        if ((match_count != -1) &&
           (val_2 = FUN_004af68f(*(int *)(&DAT_006826c4 + player_idx * 0x5b20 + card_idx * 0x120)),
           val_2 != -1)) {
          *(int *)(&DAT_006826c8 + match_count * 0x120 + spell_id * 0x5b20) = val_2;
          (&DAT_004ff594)[val_2 * 0x34] = 0x42;
          *(short *)(&DAT_004ff59c + val_2 * 0x34) =
               (short)(char)(&DAT_004ff598)
                            [*(int *)(&DAT_006826c4 + player_idx * 0x5b20 + card_idx * 0x120) * 0x34];
          *(int16_t *)(&DAT_004ff59a + val_2 * 0x34) =
               *(int16_t *)(&DAT_004ff59c + val_2 * 0x34);
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004d29da
 * Entry Point: 00454179
 * Size: 573 bytes
 */


int32_t Glue_Subsystem_004d29da(int spell_id,int target_id,int flags)

{
  int val_1;
  uint8_t match_count [4];
  int32_t slot_idx;
  
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    FUN_00434660(s_prompts_txt_004f8834,s_VESUVAN_DOPPELGANGER_004f881c);
    val_1 = Action_ValidateTarget_0041e2a2
                      (spell_id,2,2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                       &DAT_006679f0,1,(int *)match_count);
    if (val_1 == 0) {
      FUN_0046e571(spell_id,target_id,1);
      DAT_00681ea4 = 1;
    }
    else {
      (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] = match_count[0];
      *(int32_t *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
    }
  }
  if (flags == 0x71) {
    *(int32_t *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) =
         *(int32_t *)
          (&DAT_006826c4 +
          *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
          (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
    (&DAT_006826dc)[target_id * 0x120 + spell_id * 0x5b20] =
         (&DAT_004ff596)
         [*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) * 0x34];
    *(uint32_t *)(&DAT_006826f8 + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint32_t *)(&DAT_006826f8 + target_id * 0x120 + spell_id * 0x5b20) | 0x2000;
    FUN_0048c907(spell_id,target_id,0x6c,1 - spell_id,0xffffffff);
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004d2c17
 * Entry Point: 004543b6
 * Size: 273 bytes
 */


int32_t Glue_Subsystem_004d2c17(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0066642c = DAT_0066642c | 1;
  }
  if ((((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) || (arg_3 == 199)) {
    if (DAT_0066aaf4 != 1) {
      Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Mimic_004f8840);
      FUN_0044a5a4(arg_1,arg_2);
      FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s___Mimic_different_creature__004f8848);
    }
    val_1 = Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,0);
    if (val_1 != 0) {
      Glue_Subsystem_004d29da(arg_1,arg_2,0x6c);
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004544c7
 * Entry Point: 004544c7
 * Size: 258 bytes
 */


int32_t FUN_004544c7(int arg1,int arg2)

{
  if ((((*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104) &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg2)) &&
      ((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg1)) &&
     (*(int *)(&DAT_004ff590 +
              *(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34) ==
      0x197)) {
    *(int32_t *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: FUN_004545c9
 * Entry Point: 004545c9
 * Size: 322 bytes
 */


int32_t FUN_004545c9(int arg1,int arg2)

{
  if ((((*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104) &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg2)) &&
      ((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg1)) &&
     (((&DAT_004ff594)
       [*(int *)(&DAT_006826c4 +
                *(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x120 +
                (char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] * 0x5b20) * 0x34
       ] & 2) != 0)) {
    *(int32_t *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045470b
 * Entry Point: 0045470b
 * Size: 322 bytes
 */


int32_t FUN_0045470b(int arg1,int arg2)

{
  if ((((*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104) &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg2)) &&
      ((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg1)) &&
     (((&DAT_004ff594)
       [*(int *)(&DAT_006826c4 +
                *(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x120 +
                (char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] * 0x5b20) * 0x34
       ] & 0x40) != 0)) {
    *(int32_t *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045484d
 * Entry Point: 0045484d
 * Size: 150 bytes
 */


int32_t FUN_0045484d(int player_id,int card_slot,int event_type)

{
  FUN_0045470b(arg_1,arg_2);
  if ((((arg_3 == 0x78) && (DAT_0068ecfc == arg_2)) && (DAT_00690310 == arg_1)) &&
     (((&DAT_004ff594)
       [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] & 0x40) != 0)
     ) {
    DAT_0066642c = 1;
  }
  return 0;
}



/*
 * Decompiled function: FUN_004548e3
 * Entry Point: 004548e3
 * Size: 101 bytes
 */


int32_t FUN_004548e3(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x78) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    val_1 = FUN_0048b81a(DAT_00690310,DAT_0068ecfc,0x32,arg_2);
    if (1 < val_1) {
      DAT_0066642c = 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00454948
 * Entry Point: 00454948
 * Size: 128 bytes
 */


int32_t FUN_00454948(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x78) && (DAT_0068ecfc == arg_2)) && (DAT_00690310 == arg_1)) &&
     ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34]
      == '\0')) {
    DAT_0066642c = 1;
  }
  return 0;
}



/*
 * Decompiled function: FUN_004549c8
 * Entry Point: 004549c8
 * Size: 99 bytes
 */


int32_t FUN_004549c8(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x78) && (arg_2 == DAT_0068ecfc)) && (arg_1 == DAT_00690310)) {
    val_1 = FUN_0048b81a(DAT_0068ecb0,DAT_00690c48,0x32,0xffffffff);
    if (2 < val_1) {
      DAT_0066642c = 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00454a2b
 * Entry Point: 00454a2b
 * Size: 158 bytes
 */


int32_t FUN_00454a2b(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  
  if ((((arg_3 == 0x78) && (arg_2 == DAT_0068ecfc)) && (arg_1 == DAT_00690310)) &&
     ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34]
      != '\0')) {
    uval_1 = FUN_0048b81a(DAT_0068ecb0,DAT_00690c48,0x34,0xffffffff);
    if ((uval_1 & 0x20) == 0) {
      DAT_0066642c = 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00454ac9
 * Entry Point: 00454ac9
 * Size: 531 bytes
 */


int32_t FUN_00454ac9(int player_id,int card_slot,int event_type)

{
  if (((((arg_3 == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == -1)) &&
      (((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1 &&
       (*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2)))) &&
     (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) {
    (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)DAT_0068ecb0;
    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00690c48;
  }
  if (((DAT_0068f230 == 0xd7) && (DAT_00690c48 == arg_2)) &&
     ((DAT_0068ecb0 == arg_1 &&
      (((&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1 && (DAT_00681ec4 == arg_1)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      Palette_Color_0049ae00((int)(char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20],1,0);
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00454cdc
 * Entry Point: 00454cdc
 * Size: 528 bytes
 */


int32_t FUN_00454cdc(int player_id,int card_slot,int event_type)

{
  if (((((arg_3 == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == -1)) &&
      (((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1 &&
       (*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2)))) &&
     (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) {
    (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)DAT_0068ecb0;
    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00690c48;
  }
  if (((DAT_0068f230 == 0xd7) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1 && (arg_1 == DAT_00681ec4)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      (&DAT_006668f0)[(char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20]] =
           (&DAT_006668f0)[(char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20]] + 2;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
      FUN_0042afdb();
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00454eec
 * Entry Point: 00454eec
 * Size: 528 bytes
 */


int32_t FUN_00454eec(int player_id,int card_slot,int event_type)

{
  if (((((arg_3 == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == -1)) &&
      (((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1 &&
       (*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2)))) &&
     (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) {
    (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)DAT_0068ecb0;
    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00690c48;
  }
  if (((DAT_0068f230 == 0xd7) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1 && (DAT_00681ec4 == arg_1)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      (&DAT_006668f0)[(char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20]] =
           (&DAT_006668f0)[(char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20]] + 1;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
      FUN_0042afdb();
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004550fc
 * Entry Point: 004550fc
 * Size: 960 bytes
 */


int32_t FUN_004550fc(int player_id,int card_slot,int event_type)

{
  char cVar1;
  uint32_t uval_2;
  int arg1;
  int val_3;
  int val_4;
  
  if (((((arg_3 == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == -1)) &&
      (((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1 &&
       (*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2)))) &&
     (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) {
    (&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120] = (uint8_t)DAT_0068ecb0;
    *(int *)(&DAT_006826ec + arg_1 * 0x5b20 + arg_2 * 0x120) = DAT_00690c48;
  }
  if (((DAT_0068f230 == 0xd7) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1 && (arg_1 == DAT_00681ec4)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      cVar1 = (&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120];
      arg1 = (int)cVar1;
      val_3 = Deck_AddCardToDeck(arg1,DAT_0066aaf8);
      if (val_3 != -1) {
        *(uint32_t *)(&DAT_006826cc + arg1 * 0x5b20 + val_3 * 0x120) =
             *(uint32_t *)(&DAT_006826cc + arg1 * 0x5b20 + val_3 * 0x120) | 2;
        *(uint32_t *)(&DAT_006826f8 + arg1 * 0x5b20 + val_3 * 0x120) =
             *(uint32_t *)(&DAT_006826f8 + arg1 * 0x5b20 + val_3 * 0x120) | 8;
        (&DAT_006826dd)[arg1 * 0x5b20 + val_3 * 0x120] =
             (&DAT_006826dd)[arg_1 * 0x5b20 + arg_2 * 0x120];
        uval_2 = *(uint32_t *)(&DAT_004ff590 +
                         *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34);
        val_4 = FUN_00486c12(*(int *)(&DAT_004ff590 +
                                     *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34
                                     ),arg_1,arg_2);
        *(uint32_t *)(&DAT_00682704 + arg1 * 0x5b20 + val_3 * 0x120) = uval_2 | val_4 << 0x10;
        (&DAT_006826d3)[arg1 * 0x5b20 + val_3 * 0x120] = (uint8_t)arg_1;
        *(int *)(&DAT_006826ec + arg1 * 0x5b20 + val_3 * 0x120) = arg_2;
        (&DAT_006826d2)[arg1 * 0x5b20 + val_3 * 0x120] = cVar1;
        *(int32_t *)(&DAT_006826e8 + arg1 * 0x5b20 + val_3 * 0x120) = 0xffffffff;
      }
      (&DAT_006826d3)[arg_1 * 0x5b20 + arg_2 * 0x120] = 0xff;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004554bc
 * Entry Point: 004554bc
 * Size: 101 bytes
 */


int32_t FUN_004554bc(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x33) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
    DAT_0066642c = DAT_0066642c + 3;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00455521
 * Entry Point: 00455521
 * Size: 125 bytes
 */


int32_t FUN_00455521(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x33) || (arg_3 == 0x32)) && (arg_2 == DAT_00690c48)) &&
     (((arg_1 == DAT_0068ecb0 && (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 8) != 0)) &&
      (arg_1 != DAT_00666458)))) {
    DAT_0066642c = DAT_0066642c + 2;
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045559e
 * Entry Point: 0045559e
 * Size: 418 bytes
 */


int32_t FUN_0045559e(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x77) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) &&
     (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    arg_2 = Deck_AddCardToDeck(arg_1,*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20));
    if (arg_2 != -1) {
      *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      *(int32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) = 2;
      *(int32_t *)(&DAT_006826fc + arg_2 * 0x120 + arg_1 * 0x5b20) = 0x8000000;
    }
  }
  if (((DAT_00690c48 == arg_2) && (DAT_0068ecb0 == arg_1)) &&
     (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) {
    if (arg_3 == 0x34) {
      DAT_0066642c = DAT_0066642c | 0x20;
    }
    if (arg_3 == 0x32) {
      DAT_0066642c = DAT_0066642c + 4;
    }
    if (arg_3 == 0x33) {
      DAT_0066642c = DAT_0066642c + 1;
    }
    if (arg_3 == 0x22) {
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 2;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00455740
 * Entry Point: 00455740
 * Size: 248 bytes
 */


int32_t FUN_00455740(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x21) && (DAT_0068f2c4 == 0x1a)) &&
      (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0)) &&
     (((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1 &&
      (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == -1)))) {
    (&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] = (uint8_t)arg_1;
    *(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) = arg_2;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00455838
 * Entry Point: 00455838
 * Size: 373 bytes
 */


int32_t FUN_00455838(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x21) && (DAT_0068f2c4 == 0x1a)) &&
      (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) &&
     ((((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1 &&
       (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == -1)) &&
      (((&DAT_004ff594)
        [*(int *)(&DAT_006826c4 +
                 *(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x120 +
                 (char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] * 0x5b20) *
         0x34] & 0x40) != 0)))) {
    (&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] = (uint8_t)arg_1;
    *(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) = arg_2;
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004d420e
 * Entry Point: 004559ad
 * Size: 1364 bytes
 */


int32_t Glue_Subsystem_004d420e(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  INT_PTR loop_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((flags == 0x21) &&
      ((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == spell_id)) &&
     (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == target_id)) {
    *(uint32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) | 1;
  }
  if (flags == 0x73) {
    if ((((&DAT_006826e4)[target_id * 0x120 + spell_id * 0x5b20] & 1) == 0) ||
       (((uint8_t)DAT_00681eb0 & 4) == 0)) {
      uval_1 = 0;
    }
    else {
      uval_1 = 99;
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_1 = 0;
  }
  else {
    if (((flags == 0x6d) && (((&DAT_006826e4)[target_id * 0x120 + spell_id * 0x5b20] & 1) != 0)) &&
       (((uint8_t)DAT_00681eb0 & 4) != 0)) {
      if (((&DAT_006826cd)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) {
        target_idx = 0;
      }
      else {
        target_idx = 1;
      }
      do {
        FUN_00434660(s_prompts_txt_004f8880,s_PERSONAL_INCARNATION_004f8868);
        val_2 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,-1,0xffffffff,0xffffffff,0,0,
                           0,&DAT_006679f0,1,&player_idx);
        if (val_2 == 0) {
          DAT_00681ea4 = 1;
        }
        else if (((char)(&DAT_006826d2)[card_idx * 0x120 + player_idx * 0x5b20] == spell_id) &&
                (*(int *)(&DAT_006826e8 + card_idx * 0x120 + player_idx * 0x5b20) == target_id)) {
          if (*(int *)(&DAT_006826e4 + card_idx * 0x120 + player_idx * 0x5b20) +
              (int)*(short *)(&DAT_006826d0 + target_id * 0x120 + spell_id * 0x5b20) < 6) {
            loop_idx = 0;
          }
          else {
            loop_idx = *(int *)(&DAT_006826e4 + card_idx * 0x120 + player_idx * 0x5b20) -
                       (5 - *(short *)(&DAT_006826d0 + target_id * 0x120 + spell_id * 0x5b20));
          }
          slot_idx = FUN_0045139b(spell_id,s_How_much_damage_to_redirect_to_y_004f888c,loop_idx);
          match_count = FUN_004af950(target_idx,-1,slot_idx,
                                 (int)(char)(&DAT_006826d3)[card_idx * 0x120 + player_idx * 0x5b20],
                                 *(int *)(&DAT_006826ec + card_idx * 0x120 + player_idx * 0x5b20));
          if (match_count != -1) {
            *(int32_t *)(&DAT_00682704 + match_count * 0x120 + spell_id * 0x5b20) =
                 *(int32_t *)(&DAT_00682704 + card_idx * 0x120 + player_idx * 0x5b20);
            *(uint32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) & 0xfffffffe;
            *(int *)(&DAT_006826e4 + player_idx * 0x5b20 + card_idx * 0x120) =
                 *(int *)(&DAT_006826e4 + player_idx * 0x5b20 + card_idx * 0x120) - slot_idx;
          }
        }
      } while ((DAT_00681ea4 != 1) &&
              (((char)(&DAT_006826d2)[card_idx * 0x120 + player_idx * 0x5b20] != spell_id ||
               (*(int *)(&DAT_006826e8 + card_idx * 0x120 + player_idx * 0x5b20) != target_id))));
    }
    if (flags == 0x25) {
      *(uint32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) & 0xfffffffe;
    }
    if ((((flags == 0x77) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) &&
       (val_2 = Deck_AddCardToDeck(spell_id,DAT_0068f2d0), val_2 != -1)) {
      *(int32_t *)(&DAT_006826c0 + spell_id * 0x5b20 + val_2 * 0x120) =
           *(int32_t *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20);
      *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + val_2 * 0x120) =
           *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + val_2 * 0x120) |
           CONCAT31((uint3)((uint32_t)*(int32_t *)
                                   (&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) >> 8) &
                    0x10,2);
      *(int32_t *)(&DAT_00682704 + spell_id * 0x5b20 + val_2 * 0x120) = 0xb5;
      FUN_0048eb25(spell_id,val_2);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Glue_Subsystem_004d4762
 * Entry Point: 00455f01
 * Size: 1468 bytes
 */


int32_t Glue_Subsystem_004d4762(int spell_id,int target_id,int flags)

{
  int val_1;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((flags == 0x6c) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
  }
  if ((flags == 0x25) && (0 < (int)(&DAT_00681ea8)[spell_id])) {
    slot_idx = 0;
    player_idx = 0;
    while( true ) {
      val_1 = (&DAT_00666408)[DAT_00676504];
      if ((int)(&DAT_00666408)[DAT_00676504] <= (int)(&DAT_00666408)[DAT_00676510]) {
        val_1 = (&DAT_00666408)[DAT_00676510];
      }
      if (val_1 <= slot_idx) break;
      if ((((*(int *)(&DAT_006826c4 + DAT_00676510 * 0x5b20 + slot_idx * 0x120) == DAT_0068f104) &&
           (((&DAT_006826cc)[DAT_00676510 * 0x5b20 + slot_idx * 0x120] & 2) != 0)) &&
          ((char)(&DAT_006826d2)[DAT_00676510 * 0x5b20 + slot_idx * 0x120] == spell_id)) &&
         (*(int *)(&DAT_006826e8 + DAT_00676510 * 0x5b20 + slot_idx * 0x120) == -1)) {
        player_idx = player_idx + *(int *)(&DAT_006826e4 + DAT_00676510 * 0x5b20 + slot_idx * 0x120);
      }
      if (((*(int *)(&DAT_006826c4 + slot_idx * 0x120 + DAT_00676504 * 0x5b20) == DAT_0068f104) &&
          (((&DAT_006826cc)[slot_idx * 0x120 + DAT_00676504 * 0x5b20] & 2) != 0)) &&
         (((char)(&DAT_006826d2)[slot_idx * 0x120 + DAT_00676504 * 0x5b20] == spell_id &&
          (*(int *)(&DAT_006826e8 + slot_idx * 0x120 + DAT_00676504 * 0x5b20) == -1)))) {
        player_idx = player_idx + *(int *)(&DAT_006826e4 + slot_idx * 0x120 + DAT_00676504 * 0x5b20);
      }
      slot_idx = slot_idx + 1;
    }
    if ((0 < player_idx) && ((int)(&DAT_00681ea8)[spell_id] <= player_idx)) {
      Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,s_is_doin__his_thing__004f88b0,0);
      player_idx = player_idx + (1 - (&DAT_00681ea8)[spell_id]);
      *(int32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
      while (*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) < player_idx) {
        FUN_00434660(s_prompts_txt_004f88d8,s_ALI_FROM_CAIRO_004f88c8);
        _sprintf(&DAT_005f6810,&DAT_006679f0,
                 *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1,player_idx);
        Action_ValidateTarget_0041e2a2
                  (spell_id,2,spell_id,0x200,0,0,0,0,0,0,DAT_0068f104,-1,0xffffffff,0xffffffff,0,0,0
                   ,&DAT_005f6810,0,&card_idx);
        if (((char)(&DAT_006826d2)[card_idx * 0x5b20 + match_count * 0x120] == spell_id) &&
           (*(int *)(&DAT_006826e8 + card_idx * 0x5b20 + match_count * 0x120) == -1)) {
          *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
               *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
          if (*(int *)(&DAT_006826e4 + card_idx * 0x5b20 + match_count * 0x120) != 0) {
            *(int *)(&DAT_006826e4 + card_idx * 0x5b20 + match_count * 0x120) =
                 *(int *)(&DAT_006826e4 + card_idx * 0x5b20 + match_count * 0x120) + -1;
          }
          if (DAT_0066643c == 1) {
            while ((*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) < player_idx &&
                   (*(int *)(&DAT_006826e4 + card_idx * 0x5b20 + match_count * 0x120) != 0))) {
              *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
                   *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
              *(int *)(&DAT_006826e4 + card_idx * 0x5b20 + match_count * 0x120) =
                   *(int *)(&DAT_006826e4 + card_idx * 0x5b20 + match_count * 0x120) + -1;
            }
          }
          FUN_00451482(0,0x20);
        }
        else if (DAT_0066aaf4 != 1) {
          Mem_AllocOrFree_00450eed(s_Illegal_target__prevent_damage_t_004f88e4);
          Sleep(2000);
          Mem_AllocOrFree_00450eed(&DAT_004f891c);
        }
      }
    }
  }
  if (((flags == 0x8a) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    DAT_0069340c = DAT_0069340c + 0x18;
  }
  if (((flags == 0x8b) && (DAT_00690c48 == target_id)) && (DAT_0068ecb0 == spell_id)) {
    DAT_0069340c = DAT_0069340c + -0x18;
  }
  if ((flags == 199) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) {
    if (spell_id == DAT_00676504) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x1e0;
    }
    else {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x1e0;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004564bd
 * Entry Point: 004564bd
 * Size: 596 bytes
 */


int32_t FUN_004564bd(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x80) && ((DAT_00681eb0._1_1_ & 2) != 0)) &&
      ((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1)) &&
     ((*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2 &&
      (0 < *(short *)(&DAT_006826d0 + arg_2 * 0x120 + arg_1 * 0x5b20))))) {
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if (((DAT_0068f230 == 0xd7) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 && (0 < *(short *)(&DAT_006826d0 + arg_2 * 0x120 + arg_1 * 0x5b20)))))
  {
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if (((((DAT_0068f230 == 0xcd) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0))))
     && (DAT_00681ec4 == arg_1)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      FUN_00467f65(arg_1,arg_2,1);
      *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00456711
 * Entry Point: 00456711
 * Size: 1715 bytes
 */


int32_t FUN_00456711(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 0x73) {
    uval_1 = FUN_0049b309(arg_1,7,1);
  }
  else if (arg_3 == 0x90) {
    FUN_00430768(0);
    uval_1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_2 = FUN_0049b309(arg_1,7,1), val_2 != 0)) {
      if (DAT_00666458 == arg_1) {
        Ai_CalcManaRequirement_004ba890(arg_1,0,-1);
        if (DAT_00681ea0 < 1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00681ea0;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,0,1);
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      if (DAT_00681ea4 == 1) {
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      else {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
          *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff);
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff) * 0x100;
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (((&DAT_006826e6)
             [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) != 0) {
          *(uint32_t *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
               0xfff7ffff;
          val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (val_2 != -1) {
            *(int16_t *)(&DAT_006826d8 + val_2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(int16_t *)(&DAT_006826da + val_2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      uval_1 = FUN_0049b309(arg_1,7,1);
    }
    else if (arg_3 == 0x3a) {
      uval_1 = FUN_0049b309(arg_1,7,1);
    }
    else {
      if (arg_3 == 0x8f) {
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (arg_3 == 199) {
        if (arg_1 == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ef6c + arg_1 * 0x20) * 3 + 6) * 4;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ef6c + arg_1 * 0x20) * 3 + 6) * -4;
        }
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00456dc4
 * Entry Point: 00456dc4
 * Size: 1528 bytes
 */


int32_t FUN_00456dc4(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f330 + arg_1 * 0x20) = *(int *)(&DAT_0068f330 + arg_1 * 0x20) + 1;
  }
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(int32_t *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
    *(int32_t *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(int32_t *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120);
  }
  if (arg_3 == 0x73) {
    uval_1 = FUN_0049b309(arg_1,4,1);
  }
  else if (arg_3 == 0x90) {
    FUN_00430768(0);
    uval_1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_2 = FUN_0049b309(arg_1,4,1), val_2 != 0)) {
      if (arg_1 == DAT_00666458) {
        Ai_CalcManaRequirement_004ba890(arg_1,4,-1);
        if (DAT_00681ea0 < 1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) = DAT_00681ea0;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,4,1);
        *(int32_t *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
      }
      if (DAT_00681ea4 == 1) {
        *(int32_t *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
      }
      else {
        *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) = arg_1;
        *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) = arg_2;
        (&DAT_006827b8)[arg_1 * 0x5b20 + arg_2 * 0x120] = 1;
        if (*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) == 0) {
          *(uint32_t *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
               *(uint32_t *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x80000;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                  *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                 *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                     *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) +
             (*(uint32_t *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xff);
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
         *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20] = 0;
        if (((&DAT_006826e6)
             [*(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
              *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20] & 8) != 0) {
          *(uint32_t *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                   *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) =
               *(uint32_t *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) &
               0xfff7ffff;
          val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (val_2 != -1) {
            *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      uval_1 = FUN_0049b309(arg_1,4,1);
    }
    else {
      if ((arg_3 == 0x8f) && (*(int *)(&DAT_0068f2f0 + arg_1 * 0x20) != 0)) {
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (arg_3 == 199) {
        if (arg_1 == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ef60 + arg_1 * 0x20) * 3 + 3) * 4;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ef60 + arg_1 * 0x20) * 3 + 3) * -4;
        }
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(int32_t *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
        *(int32_t *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(int32_t *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004573bc
 * Entry Point: 004573bc
 * Size: 1907 bytes
 */


int FUN_004573bc(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int arg_2_00;
  int arg_3_00;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f330 + arg_1 * 0x20) = *(int *)(&DAT_0068f330 + arg_1 * 0x20) + 1;
  }
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 0x73) {
    val_2 = FUN_0049b309(arg_1,4,1);
  }
  else if (arg_3 == 0x90) {
    FUN_00430768(0);
    val_2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_2 = FUN_0049b309(arg_1,4,1), uval_1 = DAT_0068ed04, val_2 != 0)) {
      DAT_00681ea0 = 0;
      if (arg_1 == DAT_00666458) {
        if (((arg_1 == DAT_00676504) ||
            ((*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000) == 0x30000)) ||
           (DAT_0066643c != 1)) {
          DAT_0068ed04 = -1;
        }
        else {
          DAT_0068ed04 = 3 - ((*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000)
                             >> 0x10);
        }
        Ai_CalcManaRequirement_004ba890(arg_1,4,-1);
        DAT_0068ed04 = uval_1;
        if (DAT_00681ea0 < 1) {
          DAT_00681ea4 = 1;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,4,1);
        DAT_00681ea0 = 1;
      }
      *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000;
      if (DAT_00681ea4 == 1) {
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      else {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) + DAT_00681ea0 * 0x10001;
        if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
          *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff);
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (((&DAT_006826e6)
             [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) != 0) {
          *(uint32_t *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
               0xfff7ffff;
          val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (val_2 != -1) {
            *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      arg_3_00 = 3;
      arg_2_00 = 0;
      val_2 = FUN_0049b309(arg_1,4,1);
      val_2 = FUN_0049aa14(val_2,arg_2_00,arg_3_00);
      val_2 = val_2 - *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    else {
      if (((((DAT_0068f230 == 0xcd) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) &&
          ((arg_1 == DAT_0068ecb0 && ((&DAT_006826e4)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0')))) &&
         (arg_1 == DAT_00681ec4)) {
        if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) < 4) {
          *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
          *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
        }
        else {
          if (arg_3 == 0x7d) {
            DAT_0066642c = DAT_0066642c | 2;
          }
          if ((arg_3 == 0x7e) || (arg_3 == 199)) {
            FUN_0046e571(arg_1,arg_2,2);
          }
        }
      }
      if (arg_3 == 199) {
        if (arg_1 == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068ef60 + arg_1 * 0x20) * 0xc;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068ef60 + arg_1 * 0x20) * -0xc;
        }
      }
      val_2 = 0;
    }
  }
  return val_2;
}



/*
 * Decompiled function: FUN_00457b2f
 * Entry Point: 00457b2f
 * Size: 111 bytes
 */


int32_t FUN_00457b2f(int arg1,int arg2)

{
  if ((arg1 == DAT_0068ecb0) &&
     ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34]
      == '\x04')) {
    FUN_0046e571(arg1,arg2,1);
  }
  return 0;
}



/*
 * Decompiled function: FUN_00457b9e
 * Entry Point: 00457b9e
 * Size: 773 bytes
 */


int32_t FUN_00457b9e(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  
  if (arg_3 == 0x6c) {
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0x20;
  }
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f330 + arg_1 * 0x20) = *(int *)(&DAT_0068f330 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    if ((*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) ||
       (val_1 = FUN_0049b309(arg_1,4,1), val_1 == 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (val_1 = FUN_0049b309(arg_1,4,1), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,4,1), DAT_00681ea4 != 1)) {
      *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
      *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      if (arg_1 == DAT_00676504) {
        *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        *(int32_t *)
         (&DAT_006826e4 +
         *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0x20;
        val_1 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,DAT_00690af0,DAT_0068efa0);
        if (val_1 != -1) {
          *(int32_t *)(&DAT_006826e4 + val_1 * 0x120 + arg_1 * 0x5b20) = 0x20;
        }
      }
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00457ea3
 * Entry Point: 00457ea3
 * Size: 313 bytes
 */


int32_t FUN_00457ea3(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int arg_2_00;
  int arg_3_00;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f330 + arg_1 * 0x20) = *(int *)(&DAT_0068f330 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    if ((*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) == 0) &&
       (val_1 = FUN_0049b309(arg_1,4,1), val_1 != 0)) {
      uval_2 = 1;
    }
    else {
      uval_2 = 0;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (val_1 = FUN_0049b309(arg_1,4,1), val_1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,4,1);
    }
    if ((arg_3 == 0x72) && (val_1 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,arg_1,arg_2), val_1 != -1)
       ) {
      *(int16_t *)(&DAT_006826d8 + val_1 * 0x120 + arg_1 * 0x5b20) = 1;
    }
    if (arg_3 == 0x39) {
      arg_3_00 = 1;
      arg_2_00 = 0;
      val_1 = FUN_0049b309(arg_1,4,1);
      uval_2 = FUN_0049aa14(val_1,arg_2_00,arg_3_00);
    }
    else {
      uval_2 = 0;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00457fdc
 * Entry Point: 00457fdc
 * Size: 661 bytes
 */


int32_t FUN_00457fdc(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  char cVar2;
  
  if (((arg_3 == 0x34) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    cVar2 = FUN_004af7bb(arg_1,arg_2,1);
    DAT_0066642c = DAT_0066642c | 0x800 << (cVar2 - 1U & 0x1f);
    uval_1 = DAT_0066642c;
    FUN_00464d69(arg_1,arg_2,1);
    DAT_0066642c = uval_1;
  }
  if ((((arg_3 == 0x6e) &&
       (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
      ((*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == -1 &&
       (((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1 &&
        (*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2)))))) &&
     (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) {
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if (((((DAT_0068f230 == 0xcd) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0))))
     && (arg_1 == DAT_00681ec4)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      FUN_00467e37(arg_1,arg_2);
      *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00458271
 * Entry Point: 00458271
 * Size: 367 bytes
 */


int32_t FUN_00458271(int player_id,int card_slot,int event_type)

{
  char cVar1;
  uint8_t flag_2;
  int val_3;
  bool bVar4;
  int slot_idx;
  
  if (((arg_3 == 0x34) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    cVar1 = FUN_004af74c(arg_1,arg_2,4);
    DAT_0066642c = DAT_0066642c | 0x800 << (cVar1 - 1U & 0x1f);
  }
  if (((arg_3 == 0x32) || (arg_3 == 0x33)) && ((arg_2 == DAT_00690c48 && (arg_1 == DAT_0068ecb0))))
  {
    val_3 = FUN_004af7bb(arg_1,arg_2,5);
    bVar4 = *(int *)(&DAT_0068ef50 + val_3 * 4 + (1 - arg_1) * 0x20) != 0;
    if (!bVar4) {
      for (slot_idx = 0; slot_idx < 0x50; slot_idx = slot_idx + 1) {
        val_3 = FUN_0048a33f(1 - arg_1,slot_idx);
        if ((val_3 != 0) &&
           (cVar1 = (&DAT_006826dc)[slot_idx * 0x120 + (1 - arg_1) * 0x5b20],
           flag_2 = FUN_004af7bb(arg_1,arg_2,5), (1 << (flag_2 & 0x1f) & (int)cVar1) != 0)) {
          bVar4 = true;
          break;
        }
      }
    }
    if (bVar4) {
      DAT_0066642c = DAT_0066642c + 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004583e0
 * Entry Point: 004583e0
 * Size: 319 bytes
 */


int32_t FUN_004583e0(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f330 + arg_1 * 0x20) = *(int *)(&DAT_0068f330 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    uval_1 = FUN_0049b309(arg_1,4,1);
  }
  else {
    if (arg_3 == 0x6d) {
      val_2 = FUN_0049b309(arg_1,4,1);
      if (val_2 != 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,4,1);
        if (DAT_00681ea4 != 1) {
          *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
        }
      }
    }
    if (arg_3 == 0x72) {
      val_2 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,arg_1,arg_2);
      if (val_2 != -1) {
        *(short *)(&DAT_006826da + val_2 * 0x120 + arg_1 * 0x5b20) =
             (short)*(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
    }
    if (arg_3 == 0x3a) {
      uval_1 = FUN_0049b309(arg_1,4,1);
    }
    else {
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0045851f
 * Entry Point: 0045851f
 * Size: 247 bytes
 */


int32_t FUN_0045851f(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (arg_3 == 0x71) {
    val_1 = FUN_004a2b00(arg_1,arg_2,DAT_00690c40,arg_1,arg_2);
    if (val_1 != -1) {
      *(int32_t *)(&DAT_006826e4 + val_1 * 0x120 + arg_1 * 0x5b20) = 1;
      *(int32_t *)(&DAT_006826f0 + val_1 * 0x120 + arg_1 * 0x5b20) = 0x10d;
      *(int32_t *)(&DAT_006826f8 + val_1 * 0x120 + arg_1 * 0x5b20) = 0x10000;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)arg_1;
      *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = val_1;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00458616
 * Entry Point: 00458616
 * Size: 492 bytes
 */


int32_t FUN_00458616(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (arg_3 == 0x71) {
    val_1 = FUN_004a2b00(arg_1,arg_2,DAT_00690c40,arg_1,arg_2);
    if (val_1 != -1) {
      *(int32_t *)(&DAT_006826e4 + val_1 * 0x120 + arg_1 * 0x5b20) = 1;
      *(int32_t *)(&DAT_006826f0 + val_1 * 0x120 + arg_1 * 0x5b20) = 0x10e;
      *(int32_t *)(&DAT_006826f8 + val_1 * 0x120 + arg_1 * 0x5b20) = 0x10000;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)arg_1;
      *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = val_1;
    }
  }
  if ((((arg_3 == 0x32) || (arg_3 == 0x33)) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0))
  {
    if (arg_1 == DAT_00666458) {
      *(uint32_t *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) | 2;
    }
    else {
      *(uint32_t *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) & 0xfffffffd;
    }
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004d7065
 * Entry Point: 00458802
 * Size: 1727 bytes
 */


int32_t Glue_Subsystem_004d7065(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if ((flags == 0x71) &&
     (slot_idx = FUN_004a2b00(spell_id,target_id,DAT_00690c40,spell_id,target_id), slot_idx != -1)) {
    *(int32_t *)(&DAT_006826e4 + slot_idx * 0x120 + spell_id * 0x5b20) = 3;
    *(int32_t *)(&DAT_006826f0 + slot_idx * 0x120 + spell_id * 0x5b20) = 0x10d;
    *(int32_t *)(&DAT_006826f8 + slot_idx * 0x120 + spell_id * 0x5b20) = 0x10000;
    (&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] = (uint8_t)spell_id;
    *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
  }
  if ((((flags == 0x32) || (flags == 0x33)) && (target_id == DAT_00690c48)) &&
     (spell_id == DAT_0068ecb0)) {
    if (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 4) == 0) {
      *(uint32_t *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) | 1;
      *(uint32_t *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
           0xfffffffd;
    }
    else {
      *(uint32_t *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) | 2;
      *(uint32_t *)(&DAT_006826f0 +
               *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint32_t *)(&DAT_006826f0 +
                    *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) &
           0xfffffffe;
    }
  }
  if (flags == 0x73) {
    if ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_1 = FUN_004521e2(spell_id,target_id);
      val_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f892c,s_GAEAS_LIEGE_004f8920);
      arg_20 = &card_idx;
      uval_1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x200,1,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      card_idx = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      match_count = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Rules_ParseFilter_0041c0ab
                        (card_idx,match_count,(uint8_t *)0x0,spell_id,2,2,0x200,1,0,0,uval_3,uval_4,
                         uval_5,val_2,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int32_t *)
         (&DAT_006826e4 +
         *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
         *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) = 3;
        slot_idx = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00681ec8,card_idx,match_count);
        if (slot_idx != -1) {
          *(uint32_t *)(&DAT_006826f8 + slot_idx * 0x120 + spell_id * 0x5b20) =
               *(uint32_t *)(&DAT_006826f8 + slot_idx * 0x120 + spell_id * 0x5b20) | 0x11020;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
    if (((flags == 0x22) || (flags == 199)) &&
       ((target_id == DAT_00690c48 &&
        ((spell_id == DAT_0068ecb0 &&
         (((&DAT_006826e5)[target_id * 0x120 + spell_id * 0x5b20] & 0x40) != 0)))))) {
      *(uint32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) & 0xffffbfff;
      FUN_0048b81a(spell_id,target_id,0x32,0xffffffff);
      FUN_0048b81a(spell_id,target_id,0x33,0xffffffff);
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00458ec1
 * Entry Point: 00458ec1
 * Size: 87 bytes
 */


int32_t FUN_00458ec1(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x32) || (arg_3 == 0x33)) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0))
  {
    DAT_0066642c = DAT_0066642c + *(int *)(&DAT_0068ee70 + (7 - arg_1) * 4);
  }
  return 0;
}



/*
 * Decompiled function: FUN_00458f18
 * Entry Point: 00458f18
 * Size: 274 bytes
 */


int32_t FUN_00458f18(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (arg_3 == 0x71) {
    val_1 = FUN_004a2b00(arg_1,arg_2,DAT_00690c40,arg_1,arg_2);
    if (val_1 != -1) {
      *(int32_t *)(&DAT_006826e4 + val_1 * 0x120 + arg_1 * 0x5b20) =
           *(int32_t *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(int32_t *)(&DAT_006826f0 + val_1 * 0x120 + arg_1 * 0x5b20) = 0x20f;
      *(int32_t *)(&DAT_006826f8 + val_1 * 0x120 + arg_1 * 0x5b20) = 0x10000;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)arg_1;
      *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = val_1;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045902a
 * Entry Point: 0045902a
 * Size: 69 bytes
 */


int32_t FUN_0045902a(int32_t arg_1,int32_t arg_2,int event_type)

{
  if (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_3) {
    DAT_0066642c = DAT_0066642c + 1;
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045906f
 * Entry Point: 0045906f
 * Size: 212 bytes
 */


int32_t FUN_0045906f(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (arg_3 == 0x71) {
    val_1 = FUN_004a2b00(arg_1,arg_2,DAT_00690c40,arg_1,arg_2);
    if (val_1 != -1) {
      *(int32_t *)(&DAT_006826f0 + val_1 * 0x120 + arg_1 * 0x5b20) = 0x80d;
      *(int32_t *)(&DAT_006826f8 + val_1 * 0x120 + arg_1 * 0x5b20) = 0x10000;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)arg_1;
      *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = val_1;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00459143
 * Entry Point: 00459143
 * Size: 117 bytes
 */


int32_t FUN_00459143(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if ((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) {
    val_1 = FUN_004af74c(arg_1,arg_2,3);
    if (0 < *(int *)(&DAT_0068ef50 + val_1 * 4 + arg_1 * 0x20)) {
      if (arg_3 == 0x32) {
        DAT_0066642c = DAT_0066642c + 1;
      }
      if (arg_3 == 0x33) {
        DAT_0066642c = DAT_0066642c + 2;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004d7a1b
 * Entry Point: 004591b8
 * Size: 333 bytes
 */


int32_t Glue_Subsystem_004d7a1b(int player_id,int card_slot,int event_type)

{
  int val_1;
  uint32_t arg_2_00;
  int arg_3_00;
  
  if (((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) && (0 < (int)(&DAT_0068ef54)[arg_1 * 8]))
  {
    if (arg_3 == 0x32) {
      DAT_0066642c = DAT_0066642c + 1;
    }
    if (arg_3 == 0x33) {
      DAT_0066642c = DAT_0066642c + 1;
    }
  }
  if (arg_3 == 1) {
    val_1 = FUN_004af74c(arg_1,arg_2,1);
    *(int *)(&DAT_0068f320 + val_1 * 4 + arg_1 * 0x20) =
         *(int *)(&DAT_0068f320 + val_1 * 4 + arg_1 * 0x20) + 2;
  }
  if (((arg_3 == 0x70) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    val_1 = 1;
    arg_2_00 = FUN_004af74c(arg_1,arg_2,1);
    val_1 = FUN_0049b309(arg_1,arg_2_00,val_1);
    if (val_1 != 0) {
      val_1 = Ai_Subsystem_004cc56d
                        (arg_1,arg_1,arg_2,-1,-1,s_Regenerate_Sedge_Troll__Don_t_re_004f8938,0);
      if (val_1 == 0) {
        arg_3_00 = 1;
        val_1 = FUN_004af74c(arg_1,arg_2,1);
        Ai_CalcManaRequirement_004ba890(arg_1,val_1,arg_3_00);
        if (DAT_00681ea4 == 1) {
          DAT_00681ea4 = -1;
        }
        else {
          DAT_0066642c = DAT_0066642c + 1;
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00459305
 * Entry Point: 00459305
 * Size: 77 bytes
 */


int32_t FUN_00459305(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (((arg_3 == 0x73) || (arg_3 == 0x6d)) || (arg_3 == 0x72)) {
    uval_1 = FUN_004593fd(arg_1,arg_2,arg_3,2,3);
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Glue_Subsystem_004d7bb5
 * Entry Point: 00459352
 * Size: 171 bytes
 */


int32_t Glue_Subsystem_004d7bb5(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x70) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    val_1 = FUN_0049b309(arg_1,7,1);
    if (val_1 != 0) {
      val_1 = Ai_Subsystem_004cc56d
                        (arg_1,arg_1,arg_2,-1,-1,s_Regenerate_Living_Wall__Don_t_re_004f8964,0);
      if (val_1 == 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,0,1);
        if (DAT_00681ea4 == 1) {
          DAT_00681ea4 = -1;
        }
        else {
          DAT_0066642c = DAT_0066642c + 1;
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004593fd
 * Entry Point: 004593fd
 * Size: 560 bytes
 */


int32_t FUN_004593fd(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  bool flag_1;
  int val_2;
  int32_t uval_3;
  
  if (((arg_3 == 0x73) && ((DAT_00681eb0._1_1_ & 2) != 0)) &&
     (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    flag_1 = (&DAT_006826e0)[arg_2 * 0x120 + arg_1 * 0x5b20] == '\x02' &&
            (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0 &&
            ((&DAT_006826fd)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0);
    if ((flag_1) && (val_2 = FUN_0049b309(arg_1,arg_4,arg_5), val_2 == 0)) {
      flag_1 = false;
    }
    if (flag_1) {
      uval_3 = 99;
    }
    else {
      uval_3 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uval_3 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && ((DAT_00681eb0._1_1_ & 2) != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,arg_4,arg_5), DAT_00681ea4 != 1)) {
      DAT_006664ec = 1;
      *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
    }
    if ((arg_3 == 0x72) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
      *(int32_t *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0;
      FUN_0045962d(DAT_00690af0,DAT_0068efa0);
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: FUN_0045962d
 * Entry Point: 0045962d
 * Size: 579 bytes
 */


int32_t FUN_0045962d(int arg1,int arg2)

{
  bool flag_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  match_count = 0;
  flag_1 = false;
  while ((match_count < 2 && (!flag_1))) {
    slot_idx = 0;
    while ((slot_idx < (int)(&DAT_00666408)[match_count] && (!flag_1))) {
      val_2 = FUN_0048a33f(match_count,slot_idx);
      if ((((val_2 != 0) && ((char)(&DAT_006826d2)[slot_idx * 0x120 + match_count * 0x5b20] == arg1)) &&
          (*(int *)(&DAT_006826e8 + slot_idx * 0x120 + match_count * 0x5b20) == arg2)) &&
         (((*(int *)(&DAT_006826c4 + slot_idx * 0x120 + match_count * 0x5b20) == DAT_00681ec8 &&
           (((&DAT_006826fa)[slot_idx * 0x120 + match_count * 0x5b20] & 0x80) != 0)) ||
          (*(int *)(&DAT_006826c4 + slot_idx * 0x120 + match_count * 0x5b20) == DAT_00676514)))) {
        flag_1 = true;
      }
      slot_idx = slot_idx + 1;
    }
    match_count = match_count + 1;
  }
  if (!flag_1) {
    (&DAT_006826e0)[arg2 * 0x120 + arg1 * 0x5b20] = 0;
    *(int32_t *)(&DAT_00682710 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
    *(int16_t *)(&DAT_006826d0 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
    FUN_004a7b83(arg1,arg2);
    *(uint32_t *)(&DAT_006826f8 + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826f8 + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff7f;
    (&DAT_006826de)[arg2 * 0x120 + arg1 * 0x5b20] = 0xff;
    *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffffff3;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00459870
 * Entry Point: 00459870
 * Size: 168 bytes
 */


int32_t FUN_00459870(int player_id,int card_slot,int event_type)

{
  int arg_4;
  int32_t uval_1;
  
  arg_4 = FUN_0048c367((&DAT_004ff596)
                       [*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34]);
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f320 + arg_4 * 4 + arg_1 * 0x20) =
         *(int *)(&DAT_0068f320 + arg_4 * 4 + arg_1 * 0x20) + 2;
  }
  if (((arg_3 == 0x73) || (arg_3 == 0x6d)) || (arg_3 == 0x72)) {
    uval_1 = FUN_004593fd(arg_1,arg_2,arg_3,arg_4,1);
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00459918
 * Entry Point: 00459918
 * Size: 1616 bytes
 */


int32_t FUN_00459918(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f324 + arg_1 * 0x20) = *(int *)(&DAT_0068f324 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    if (((DAT_00676504 == arg_1) && (DAT_00666458 == arg_1)) &&
       ((*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0 && (DAT_0068f2c4 < 0x1a)))) {
      uval_1 = 0;
    }
    else {
      val_2 = FUN_0049b309(arg_1,1,1);
      if ((val_2 == 0) ||
         (0x1ffff < (int)(*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffff0000)))
      {
        uval_1 = 0;
      }
      else {
        uval_1 = 1;
      }
    }
  }
  else if (arg_3 == 0x90) {
    FUN_00430768(0);
    uval_1 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && (val_2 = FUN_0049b309(arg_1,1,1), uval_1 = DAT_0068ed04, val_2 != 0)) &&
       ((int)(*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffff0000) < 0x20000)) {
      if (((&DAT_006826f2)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0xf) == 0) {
        DAT_0068ed04 = 2;
      }
      else {
        DAT_0068ed04 = 1;
      }
      if (DAT_00666458 == arg_1) {
        Ai_CalcManaRequirement_004ba890(arg_1,1,-1);
        if (DAT_00681ea0 < 1) {
          DAT_00681ea4 = 1;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,1,1);
        DAT_00681ea0 = 1;
      }
      DAT_0068ed04 = uval_1;
      *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xf0000;
      if (DAT_00681ea4 != 1) {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) + DAT_00681ea0 * 0x10001;
        if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
          *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff);
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (((&DAT_006826e6)
             [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) != 0) {
          *(uint32_t *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
               0xfff7ffff;
          val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (val_2 != -1) {
            *(int16_t *)(&DAT_006826d8 + val_2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      uval_1 = FUN_0049aa14(*(int *)(&DAT_0068ed14 + arg_1 * 0x20),0,
                           2 - *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20));
    }
    else {
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00459f68
 * Entry Point: 00459f68
 * Size: 1665 bytes
 */


int32_t FUN_00459f68(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f324 + arg_1 * 0x20) = *(int *)(&DAT_0068f324 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    uval_1 = FUN_0049b309(arg_1,1,1);
  }
  else if (arg_3 == 0x90) {
    FUN_00430768(0);
    uval_1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_2 = FUN_0049b309(arg_1,1,1), val_2 != 0)) {
      if (arg_1 == DAT_00666458) {
        Ai_CalcManaRequirement_004ba890(arg_1,1,-1);
        if (DAT_00681ea0 < 1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00681ea0;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,1,1);
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      if (DAT_00681ea4 == 1) {
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      else {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
          *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff);
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff) * 0x100;
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (((&DAT_006826e6)
             [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) != 0) {
          *(uint32_t *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
               0xfff7ffff;
          val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (val_2 != -1) {
            *(int16_t *)(&DAT_006826d8 + val_2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(int16_t *)(&DAT_006826da + val_2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      uval_1 = FUN_0049b309(arg_1,1,1);
    }
    else if (arg_3 == 0x3a) {
      uval_1 = FUN_0049b309(arg_1,1,1);
    }
    else {
      if ((arg_3 == 0x8f) && (*(int *)(&DAT_0068f2e4 + arg_1 * 0x20) != 0)) {
        DAT_0066642c = DAT_0066642c | 1;
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0045a5e9
 * Entry Point: 0045a5e9
 * Size: 1685 bytes
 */


int32_t FUN_0045a5e9(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f32c + arg_1 * 0x20) = *(int *)(&DAT_0068f32c + arg_1 * 0x20) + 1;
  }
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 0x73) {
    uval_1 = FUN_0049b309(arg_1,3,1);
  }
  else if (arg_3 == 0x90) {
    FUN_00430768(0);
    uval_1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_2 = FUN_0049b309(arg_1,3,1), val_2 != 0)) {
      if (arg_1 == DAT_00666458) {
        Ai_CalcManaRequirement_004ba890(arg_1,3,-1);
        if (DAT_00681ea0 < 1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00681ea0;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,3,1);
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      if (DAT_00681ea4 == 1) {
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      else {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
          *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff);
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff) * 0x100;
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20] = 0;
        if (((&DAT_006826e6)
             [*(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
              *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20] & 8) != 0) {
          *(uint32_t *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
               0xfff7ffff;
          val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (val_2 != -1) {
            *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      uval_1 = FUN_0049b309(arg_1,3,1);
    }
    else if (arg_3 == 0x3a) {
      uval_1 = FUN_0049b309(arg_1,3,1);
    }
    else {
      if ((arg_3 == 0x8f) && (*(int *)(&DAT_0068f2ec + arg_1 * 0x20) != 0)) {
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (arg_3 == 199) {
        if (arg_1 == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ef5c + arg_1 * 0x20) * 3 + 6) * 4;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ef5c + arg_1 * 0x20) * 3 + 6) * -4;
        }
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0045ac7e
 * Entry Point: 0045ac7e
 * Size: 1564 bytes
 */


int32_t FUN_0045ac7e(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f328 + arg_1 * 0x20) = *(int *)(&DAT_0068f328 + arg_1 * 0x20) + 1;
  }
  if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 0x73) {
    uval_1 = FUN_0049b309(arg_1,2,1);
  }
  else if (arg_3 == 0x90) {
    FUN_00430768(0);
    uval_1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_2 = FUN_0049b309(arg_1,2,1), val_2 != 0)) {
      if (DAT_00666458 == arg_1) {
        Ai_CalcManaRequirement_004ba890(arg_1,2,-1);
        if (DAT_00681ea0 < 1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00681ea0;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,2,1);
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      if (DAT_00681ea4 == 1) {
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      else {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
          *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff);
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (((&DAT_006826e6)
             [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) != 0) {
          *(uint32_t *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
               0xfff7ffff;
          val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (val_2 != -1) {
            *(int16_t *)(&DAT_006826d8 + val_2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      uval_1 = FUN_0049b309(arg_1,2,1);
    }
    else {
      if ((arg_3 == 0x8f) && (*(int *)(&DAT_0068f2e8 + arg_1 * 0x20) != 0)) {
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (arg_3 == 199) {
        if (DAT_00676504 == arg_1) {
          DAT_0068f2d4 = DAT_0068f2d4 + (&DAT_0068ef58)[arg_1 * 8] * 0xc;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 + (&DAT_0068ef58)[arg_1 * 8] * -0xc;
        }
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: Glue_Subsystem_004d9afd
 * Entry Point: 0045b29a
 * Size: 1153 bytes
 */


void Glue_Subsystem_004d9afd(int player_id,int card_slot,int event_type)

{
  int arg_4;
  int local_94;
  int local_90;
  int local_88;
  int local_80 [30];
  int slot_idx;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f324 + arg_1 * 0x20) = *(int *)(&DAT_0068f324 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    FUN_0049b309(arg_1,1,3);
  }
  else {
    if (((arg_3 == 0x6d) &&
        ((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,1,3), DAT_00681ea4 != 1)) {
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      arg_4 = 1 - arg_1;
      if (((DAT_0066aaf4 != 1) && (arg_1 == 0)) && (DAT_0068f0b0 == 0)) {
        local_90 = 0;
        for (local_88 = 0; local_88 < DAT_0066640c; local_88 = local_88 + 1) {
          if ((*(int *)(&DAT_006881e4 + local_88 * 0x120) != -1) &&
             (((&DAT_006881ec)[local_88 * 0x120] & 2) == 0)) {
            local_80[local_90] = *(int *)(&DAT_006881e4 + local_88 * 0x120);
            local_90 = local_90 + 1;
          }
        }
        if (DAT_0066aaf4 != 1) {
          Palette_Subsystem_004a5722(0,local_80,local_90,s_Opponent_s_Hand_004f8998,0,&DAT_004f8990)
          ;
        }
      }
      local_90 = 0;
      do {
        local_94 = FUN_00439892((&DAT_00666408)[arg_4]);
        local_90 = local_90 + 1;
        if (0x3e6 < local_90) break;
      } while (((*(int *)(&DAT_006826c4 + arg_4 * 0x5b20 + local_94 * 0x120) == -1) ||
               (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_4 * 0x5b20 + local_94 * 0x120) * 0x34]
                & 2) == 0)) || (((&DAT_006826cc)[arg_4 * 0x5b20 + local_94 * 0x120] & 2) != 0));
      if (local_90 < 999) {
        slot_idx = 1;
      }
      else {
        slot_idx = 0;
        local_88 = 0;
        while ((local_88 < (int)(&DAT_00666408)[arg_4] && (slot_idx == 0))) {
          if ((*(int *)(&DAT_006826c4 + local_88 * 0x120 + arg_4 * 0x5b20) != -1) &&
             ((((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_88 * 0x120 + arg_4 * 0x5b20) * 0x34]
               & 2) != 0 && (((&DAT_006826cc)[local_88 * 0x120 + arg_4 * 0x5b20] & 2) == 0)))) {
            slot_idx = 1;
            local_94 = local_88;
          }
          local_88 = local_88 + 1;
        }
      }
      if (slot_idx != 0) {
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x19);
        }
        if (DAT_0066aaf4 != 1) {
          Ai_Subsystem_004cc56d
                    (arg_1,arg_1,arg_2,arg_4,local_94,s_Randomly_chose_this_creature_to_d_004f89a8,0
                    );
        }
        FUN_0046f02d(arg_4,local_94);
        *(int32_t *)(&DAT_006826c4 + arg_4 * 0x5b20 + local_94 * 0x120) = 0xffffffff;
        (&DAT_0068ee78)[arg_4] = (&DAT_0068ee78)[arg_4] + -1;
      }
    }
  }
  return;
}



/*
 * Decompiled function: Glue_Subsystem_004d9f7e
 * Entry Point: 0045b71b
 * Size: 1284 bytes
 */


int32_t Glue_Subsystem_004d9f7e(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  bool bVar4;
  uint32_t uval_5;
  uint32_t uval_6;
  int32_t arg_11;
  int val_7;
  int32_t arg_12;
  uint32_t uval_8;
  int32_t arg_13;
  uint32_t uVar9;
  int32_t arg_14;
  uint32_t uVar10;
  int32_t arg_15;
  uint32_t uVar11;
  int32_t arg_16;
  uint32_t uVar12;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (flags == 1) {
    *(int *)(&DAT_0068f334 + spell_id * 0x20) = *(int *)(&DAT_0068f334 + spell_id * 0x20) + 1;
  }
  if (flags == 0x73) {
    bVar4 = (*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
    if ((bVar4) && (val_1 = FUN_0049b309(spell_id,2,2), val_1 == 0)) {
      bVar4 = false;
    }
    if ((bVar4) && (val_1 = FUN_0049b309(spell_id,7,4), val_1 == 0)) {
      bVar4 = false;
    }
    uval_2 = 0;
    if (bVar4) {
      arg_19 = 0x40;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = FUN_004521e2(spell_id,target_id);
      uval_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0x1047,0,0,uval_2,arg_11,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_2 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      DAT_0068ece0 = 2;
      Ai_CalcManaRequirement_004ba890(spell_id,2,2);
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f89e4,s_TIME_ELEMENTAL_004f89d4);
        arg_20 = &match_count;
        uval_2 = 1;
        arg_18 = &DAT_006679f0;
        uVar12 = 0x40;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uval_8 = 0xffffffff;
        val_7 = -1;
        val_1 = -1;
        uval_6 = 0;
        uval_5 = 0;
        uval_3 = FUN_004521e2(spell_id,target_id);
        val_1 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,1 - spell_id,0x200,0x1047,0,0,uval_3,uval_5,uval_6,val_1,val_7,
                           uval_8,uVar9,uVar10,uVar11,uVar12,arg_18,uval_2,arg_20);
        if (val_1 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = match_count;
          *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
          *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        }
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      uVar12 = 0x40;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      val_1 = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_1 = Rules_ParseFilter_0041c0ab
                        (match_count,slot_idx,(uint8_t *)0x0,spell_id,2,2,0x200,0x1047,0,0,uval_3,uval_5
                         ,uval_6,val_1,val_7,uval_8,uVar9,uVar10,uVar11,uVar12);
      if (val_1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        Rules_CardLeavingPlay(match_count,slot_idx);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if (((flags == 0x15) || (flags == 199)) &&
       (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 4) != 0)) {
      FUN_004a2b00(spell_id,target_id,DAT_0066674c,spell_id,-1);
    }
    if (((flags == 0x1a) || (flags == 199)) &&
       ((DAT_0068f2c4 == 0x17 && ((&DAT_006826de)[target_id * 0x120 + spell_id * 0x5b20] != -1)))) {
      FUN_004a2b00(spell_id,target_id,DAT_0066674c,spell_id,-1);
    }
    if ((flags == 0x22) || (flags == 199)) {
      *(int32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0x78;
    }
    if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0x78;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Glue_Subsystem_004da482
 * Entry Point: 0045bc1f
 * Size: 982 bytes
 */


int32_t Glue_Subsystem_004da482(int spell_id,int target_id,int flags)

{
  uint8_t flag_1;
  int val_2;
  int32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  bool bVar6;
  uint32_t uval_7;
  int val_8;
  int32_t arg_12;
  uint32_t uVar9;
  int32_t arg_13;
  uint32_t uVar10;
  int32_t arg_14;
  uint32_t uVar11;
  int32_t arg_15;
  uint32_t uVar12;
  int32_t arg_16;
  uint32_t uVar13;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (flags == 1) {
    *(int *)(&DAT_0068f334 + spell_id * 0x20) = *(int *)(&DAT_0068f334 + spell_id * 0x20) + 1;
  }
  if (flags == 0x73) {
    bVar6 = (*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
    if ((bVar6) && (val_2 = FUN_0049b309(spell_id,5,2), val_2 == 0)) {
      bVar6 = false;
    }
    uval_3 = 0;
    if (bVar6) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      flag_1 = FUN_004af7bb(spell_id,target_id,1);
      val_2 = 1 << (flag_1 & 0x1f);
      uval_3 = FUN_004521e2(spell_id,target_id);
      uval_3 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0x1047,0,0,uval_3,val_2,arg_12,arg_13,
                           arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_3 = 0;
  }
  else {
    if ((((flags == 0x6d) && (val_2 = FUN_0049b309(spell_id,5,2), val_2 != 0)) &&
        ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,5,2), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f8a04,s_NORTHERN_PALADIN_004f89f0);
      arg_20 = &match_count;
      uval_3 = 1;
      arg_18 = &DAT_006679f0;
      uVar13 = 0;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0xffffffff;
      uVar9 = 0xffffffff;
      val_8 = -1;
      val_2 = -1;
      uval_7 = 0;
      flag_1 = FUN_004af7bb(spell_id,target_id,1);
      uval_5 = 1 << (flag_1 & 0x1f);
      uval_4 = FUN_004521e2(spell_id,target_id);
      val_2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,2,0x200,0x1047,0,0,uval_4,uval_5,uval_7,val_2,val_8,uVar9,uVar10,
                         uVar11,uVar12,uVar13,arg_18,uval_3,arg_20);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      uVar13 = 0;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0xffffffff;
      uVar9 = 0xffffffff;
      val_8 = -1;
      val_2 = -1;
      uval_7 = 0;
      flag_1 = FUN_004af7bb(spell_id,target_id,1);
      uval_5 = 1 << (flag_1 & 0x1f);
      uval_4 = FUN_004521e2(spell_id,target_id);
      val_2 = Rules_ParseFilter_0041c0ab
                        (match_count,slot_idx,(uint8_t *)0x0,spell_id,2,2,0x200,0x1047,0,0,uval_4,uval_5
                         ,uval_7,val_2,val_8,uVar9,uVar10,uVar11,uVar12,uVar13);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(match_count,slot_idx,2);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: Glue_Subsystem_004da858
 * Entry Point: 0045bff5
 * Size: 504 bytes
 */


int32_t Glue_Subsystem_004da858(int spell_id,int target_id,int flags)

{
  int card_id;
  int color_mask;
  uint32_t arg_11;
  uint32_t arg_12;
  uint32_t arg_13;
  int val_1;
  int arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint32_t arg_18;
  uint32_t arg_19;
  uint32_t arg_20;
  int32_t slot_idx;
  
  if ((flags == 0x73) || (flags == 0x6d)) {
    FUN_00434660(s_prompts_txt_004f8a20,s_ROYAL_ASSASSIN_004f8a10);
    slot_idx = FUN_0045c613(spell_id,target_id,flags,1 - spell_id);
  }
  if (flags == 0x90) {
    FUN_0043071d(0);
    slot_idx = 0;
  }
  else {
    if (flags == 0x72) {
      card_id = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 1;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_1 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(spell_id,target_id);
      val_1 = Rules_ParseFilter_0041c0ab
                        (card_id,color_mask,(uint8_t *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12
                         ,arg_13,val_1,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(card_id,color_mask,2);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      slot_idx = 0;
    }
    if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0x30;
    }
    if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0x30;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: Glue_Subsystem_004daa50
 * Entry Point: 0045c1ed
 * Size: 449 bytes
 */


int32_t Glue_Subsystem_004daa50(int spell_id,int target_id,int flags)

{
  int card_slot;
  int32_t slot_idx;
  
  if ((flags == 0x73) || (flags == 0x6d)) {
    FUN_00434660(s_prompts_txt_004f8a3c,s_DWARVEN_DTEAM_004f8a2c);
    slot_idx = FUN_0045c613(spell_id,target_id,flags,1 - spell_id);
  }
  if (flags == 0x90) {
    FUN_0043071d(0);
    slot_idx = 0;
  }
  else if ((flags == 0x72) &&
          (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
    arg_2 = *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20);
    DAT_0068eef0 = (int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20];
    *(int32_t *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff;
    *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0xffffffef;
    if ((arg_2 != -1) &&
       ((&DAT_004ff595)
        [*(int *)(&DAT_006826c4 +
                 *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                 *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) * 0x120) * 0x34] ==
        '\0')) {
      FUN_0046e571(DAT_0068eef0,arg_2,2);
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: Glue_Subsystem_004dac11
 * Entry Point: 0045c3ae
 * Size: 613 bytes
 */


int32_t Glue_Subsystem_004dac11(int spell_id,int target_id,int flags)

{
  int32_t slot_idx;
  
  if ((flags == 0x73) || (flags == 0x6d)) {
    FUN_00434660(s_prompts_txt_004f8a58,s_KING_SULEIMAN_004f8a48);
    slot_idx = FUN_0045c613(spell_id,target_id,flags,1 - spell_id);
  }
  if (flags == 0x90) {
    FUN_0043071d(0);
    slot_idx = 0;
  }
  else if ((flags == 0x72) &&
          (*(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
    if (((&DAT_004ff595)
         [*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) * 0x34] ==
         '\x05') ||
       ((&DAT_004ff595)
        [*(int *)(&DAT_006826c4 +
                 *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                 (char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) * 0x34] ==
        '\x06')) {
      FUN_0046e571((int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20],
                   *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20),2);
    }
    else {
      DAT_00681ea4 = 1;
    }
    (&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20] = 0xff;
    *(int *)(&DAT_006826e8 + target_id * 0x120 + spell_id * 0x5b20) =
         (int)(char)(&DAT_006826d2)[target_id * 0x120 + spell_id * 0x5b20];
    *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_0045c613
 * Entry Point: 0045c613
 * Size: 430 bytes
 */


int32_t FUN_0045c613(int x,int y,int width,uint32_t height)

{
  int32_t uval_1;
  uint32_t arg_8;
  uint32_t arg_9;
  uint32_t arg_10;
  int val_2;
  int32_t arg_11;
  int arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  uint32_t arg_14;
  int32_t arg_14_00;
  uint32_t arg_15;
  int32_t arg_15_00;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int32_t slot_idx;
  
  if (height == 0xffffffff) {
    height = 2;
  }
  if (width == 0x73) {
    uval_1 = 0;
    if ((*(uint32_t *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 1;
      arg_17_00 = 0;
      arg_16_00 = 0xffffffff;
      arg_15_00 = 0xffffffff;
      arg_14_00 = 0xffffffff;
      arg_13_00 = 0xffffffff;
      arg_12_00 = 0;
      arg_11 = 0;
      uval_1 = FUN_004521e2(x,y);
      uval_1 = FUN_0041bcf0((int *)0x0,0,x,2,2,0x200,2,0,0,uval_1,arg_11,arg_12_00,arg_13_00,arg_14_00
                           ,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19);
    }
  }
  else {
    if (width == 0x6d) {
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &DAT_006679f0;
      arg_17 = 0;
      arg_16 = 1;
      arg_15 = 0;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = -1;
      val_2 = -1;
      arg_10 = 0;
      arg_9 = 0;
      arg_8 = FUN_004521e2(x,y);
      val_2 = Action_ValidateTarget_0041e2a2
                        (x,2,height,0x200,2,0,0,arg_8,arg_9,arg_10,val_2,arg_12,arg_13,arg_14,arg_15
                         ,arg_16,arg_17,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20) = match_count;
        *(int32_t *)(&DAT_0068271c + y * 0x120 + x * 0x5b20) = slot_idx;
        (&DAT_006827b8)[y * 0x120 + x * 0x5b20] = 1;
        *(uint32_t *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) | 0x10;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Glue_Subsystem_004db024
 * Entry Point: 0045c7c1
 * Size: 989 bytes
 */


int32_t Glue_Subsystem_004db024(int spell_id,int target_id,int flags)

{
  int32_t slot_idx;
  
  if (flags == 0x73) {
    if ((*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0) {
      if ((spell_id == DAT_00666458) || (0x1a < DAT_0068f2c4)) {
        slot_idx = 0;
      }
      else {
        slot_idx = 1;
      }
    }
    else {
      slot_idx = 0;
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    slot_idx = 0;
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8a74,s_NETTLING_IMP_004f8a64);
      slot_idx = FUN_0045c613(spell_id,target_id,0x6d,1 - spell_id);
    }
    if (((flags == 0x72) && (*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) != -1))
       && ((&DAT_004ff595)
           [*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                    (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) * 0x34]
           == '\0')) {
      (&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] = 0xff;
      *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) =
           (int)(char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120];
      *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0xffffffef;
    }
    if (((flags == 0x15) && (*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) != -1))
       && (spell_id != DAT_00666458)) {
      *(uint32_t *)(&DAT_006826cc +
               *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
               (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc +
                    *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                    (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20) | 4;
      DAT_006826b0 = 1;
      (&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] = 0xff;
      *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) =
           (int)(char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120];
    }
    if (((flags == 0x1f) && (*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) != -1))
       && ((spell_id != DAT_00666458 &&
           (((&DAT_006826cc)
             [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
              (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] & 0x40) == 0)))
       ) {
      FUN_0046e571((int)(char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120],
                   *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120),2);
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_0045cb9e
 * Entry Point: 0045cb9e
 * Size: 1222 bytes
 */


bool FUN_0045cb9e(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int val_2;
  
  if (arg_3 == 0x73) {
    val_2 = FUN_004680fc(arg_1,arg_2);
    flag_1 = 1 < val_2;
  }
  else {
    if ((arg_3 == 0x6d) && (val_2 = FUN_004680fc(arg_1,arg_2), 1 < val_2)) {
      *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
      *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
        *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
      }
      FUN_0046801f(arg_1,arg_2,2);
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_006826e4 +
                *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) + 1;
        *(int *)(&DAT_006826e4 +
                *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) + 0x100;
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (((&DAT_006826e6)
             [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) != 0) {
          *(uint32_t *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
               0xfff7ffff;
          val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (val_2 != -1) {
            *(int16_t *)(&DAT_006826d8 + val_2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(int16_t *)(&DAT_006826da + val_2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826e4 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (((((DAT_0068f230 == 0xcd) || (arg_3 == 199)) && (DAT_00690c48 == arg_2)) &&
        ((arg_1 == DAT_0068ecb0 && (DAT_0068eeac != 0)))) && (arg_1 == DAT_00681ec4)) {
      if (arg_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        FUN_00467e37(arg_1,arg_2);
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    flag_1 = false;
  }
  return flag_1;
}



/*
 * Decompiled function: FUN_0045d064
 * Entry Point: 0045d064
 * Size: 339 bytes
 */


int32_t FUN_0045d064(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int val_2;
  int val_3;
  int slot_idx;
  
  if (((arg_3 == 0x1a) && (DAT_00666458 == arg_1)) &&
     (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
    val_2 = 1 - arg_1;
    flag_1 = true;
    for (slot_idx = 0; slot_idx < (int)(&DAT_00666408)[val_2]; slot_idx = slot_idx + 1) {
      val_3 = FUN_0048a33f(val_2,slot_idx);
      if ((val_3 != 0) && ((char)(&DAT_006826de)[slot_idx * 0x120 + val_2 * 0x5b20] == arg_2)) {
        flag_1 = false;
        break;
      }
    }
    if (flag_1) {
      val_2 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,arg_1,arg_2);
      if (val_2 != -1) {
        *(int16_t *)(&DAT_006826d8 + arg_1 * 0x5b20 + val_2 * 0x120) = 2;
        *(int16_t *)(&DAT_006826da + arg_1 * 0x5b20 + val_2 * 0x120) = 0;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004dba1c
 * Entry Point: 0045d1b7
 * Size: 1469 bytes
 */


int32_t Glue_Subsystem_004dba1c(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    uval_1 = 0;
    if ((*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_1 = FUN_004521e2(spell_id,target_id);
      uval_1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_1 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0)) {
      FUN_00434660(s_prompts_txt_004f8a90,s_SORCERESS_QUEEN_004f8a80);
      *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x100000;
      FUN_00451482(0,0x20);
      arg_20 = &player_idx;
      uval_1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = FUN_004521e2(spell_id,target_id);
      val_5 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = player_idx;
        *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = card_idx;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
      *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0xffefffff;
    }
    if (flags == 0x72) {
      player_idx = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
      card_idx = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = FUN_004521e2(spell_id,target_id);
      val_5 = Rules_ParseFilter_0041c0ab
                        (player_idx,card_idx,(uint8_t *)0x0,spell_id,2,2,0x200,2,0,0,uval_2,uval_3,
                         uval_4,val_5,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
          for (match_count = 0; match_count < (int)(&DAT_00666408)[slot_idx]; match_count = match_count + 1) {
            if ((((*(int *)(&DAT_006826c4 + match_count * 0x120 + slot_idx * 0x5b20) == DAT_0068eed0) &&
                 (((&DAT_006826cc)[match_count * 0x120 + slot_idx * 0x5b20] & 2) != 0)) &&
                ((char)(&DAT_006826d2)[match_count * 0x120 + slot_idx * 0x5b20] == player_idx)) &&
               (*(int *)(&DAT_006826e8 + match_count * 0x120 + slot_idx * 0x5b20) == card_idx)) {
              *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + slot_idx * 0x5b20) =
                   *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + slot_idx * 0x5b20) & 0xfeffffff;
            }
          }
        }
        val_5 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0068eed0,player_idx,card_idx);
        if (val_5 != -1) {
          *(uint32_t *)(&DAT_006826f8 + val_5 * 0x120 + spell_id * 0x5b20) =
               *(uint32_t *)(&DAT_006826f8 + val_5 * 0x120 + spell_id * 0x5b20) | 0x1000000;
          *(uint16_t *)(&DAT_006826d8 + val_5 * 0x120 + spell_id * 0x5b20) =
               -(*(uint16_t *)
                  (&DAT_004ff59a +
                  *(int *)(&DAT_006826c4 + player_idx * 0x5b20 + card_idx * 0x120) * 0x34) & 0xbfff);
          *(uint16_t *)(&DAT_006826da + val_5 * 0x120 + spell_id * 0x5b20) =
               2 - (*(uint16_t *)
                     (&DAT_004ff59c +
                     *(int *)(&DAT_006826c4 + player_idx * 0x5b20 + card_idx * 0x120) * 0x34) & 0xbfff
                   );
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
    if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0xc;
    }
    if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0xc;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0045d774
 * Entry Point: 0045d774
 * Size: 746 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045d774(int player_id,int card_slot,int event_type)

{
  short len_1;
  int val_2;
  int match_count;
  
  if (arg_3 != 0x73) {
    if (arg_3 == 0x90) {
      FUN_0043071d(0);
    }
    else {
      if ((arg_3 == 0x6d) &&
         ((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
        if (match_count == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)DAT_0068eef0;
          *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = match_count;
        }
      }
      if (arg_3 == 0x72) {
        val_2 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,
                             (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                             *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20));
        if (val_2 != -1) {
          len_1 = FUN_0048b81a((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                               *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),0x32,
                               0xffffffff);
          *(short *)(&DAT_006826d8 + val_2 * 0x120 + arg_1 * 0x5b20) = -len_1;
        }
        *(int32_t *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
        *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
    }
  }
  return;
}



/*
 * Decompiled function: Glue_Subsystem_004dc2ca
 * Entry Point: 0045da63
 * Size: 1021 bytes
 */


int32_t Glue_Subsystem_004dc2ca(int spell_id,int target_id,int flags)

{
  uint32_t uval_1;
  int32_t uval_2;
  int val_3;
  uint32_t uval_4;
  uint32_t uval_5;
  uint32_t uval_6;
  int32_t arg_11;
  int val_7;
  int32_t arg_12;
  uint32_t uval_8;
  int32_t arg_13;
  int32_t arg_14;
  uint32_t uVar9;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  
  if (flags == 0x73) {
    uval_2 = 0;
    if ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      uval_1 = (int)*(short *)(&DAT_006826d4 + target_id * 0x120 + spell_id * 0x5b20) - 1U | 0x2000;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = FUN_004521e2(spell_id,target_id);
      uval_2 = FUN_0041bcf0((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uval_2,arg_11,arg_12,
                           arg_13,arg_14,uval_1,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_2 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      FUN_00434660(s_prompts_txt_004f8aa8,s_STONE_GIANT_004f8a9c);
      arg_20 = &card_idx;
      uval_2 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      val_3 = FUN_0048b81a(spell_id,target_id,0x32,0xffffffff);
      uval_1 = val_3 - 1U | 0x2000;
      uval_8 = 0xffffffff;
      val_7 = -1;
      val_3 = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_4 = FUN_004521e2(spell_id,target_id);
      val_3 = Action_ValidateTarget_0041e2a2
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uval_4,uval_5,uval_6,val_3,val_7,uval_8,
                         uval_1,uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      card_idx = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      match_count = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_1 = (int)*(short *)(&DAT_006826d4 + target_id * 0x120 + spell_id * 0x5b20) - 1U | 0x2000;
      uval_8 = 0xffffffff;
      val_7 = -1;
      val_3 = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_4 = FUN_004521e2(spell_id,target_id);
      val_3 = Rules_ParseFilter_0041c0ab
                        (card_idx,match_count,(uint8_t *)0x0,spell_id,(uint8_t)spell_id,(uint8_t)spell_id,
                         0x200,2,0,0,uval_4,uval_5,uval_6,val_3,val_7,uval_8,uval_1,uVar9,uVar10,uVar11);
      if (val_3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        val_3 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,card_idx,match_count);
        if (val_3 != -1) {
          (&DAT_006826e0)[val_3 * 0x120 + spell_id * 0x5b20] = 5;
          *(int32_t *)(&DAT_006826e4 + val_3 * 0x120 + spell_id * 0x5b20) = 0x20;
          *(int32_t *)(&DAT_006826fc + card_idx * 0x5b20 + match_count * 0x120) = 0x8000000;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Glue_Subsystem_004dc6c7
 * Entry Point: 0045de60
 * Size: 806 bytes
 */


int32_t Glue_Subsystem_004dc6c7(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    uval_1 = 0;
    if ((*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0x2002;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_1 = FUN_004521e2(spell_id,target_id);
      uval_1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_1 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0)) {
      FUN_00434660(s_prompts_txt_004f8ac8,s_DWARVEN_WARRIORS_004f8ab4);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0x2002;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = FUN_004521e2(spell_id,target_id);
      val_5 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,spell_id,0x200,2,0,0,uval_2,uval_3,uval_4,val_5,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = match_count;
        *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = slot_idx;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
      slot_idx = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0x2002;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = FUN_004521e2(spell_id,target_id);
      val_5 = Rules_ParseFilter_0041c0ab
                        (match_count,slot_idx,(uint8_t *)0x0,spell_id,2,2,0x200,2,0,0,uval_2,uval_3,
                         uval_4,val_5,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_006667b0,match_count,slot_idx);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Glue_Subsystem_004dc9ed
 * Entry Point: 0045e186
 * Size: 1124 bytes
 */


int32_t Glue_Subsystem_004dc9ed(int spell_id,int target_id,int flags)

{
  char cVar1;
  int val_2;
  int32_t uval_3;
  uint32_t uval_4;
  bool bVar5;
  uint32_t uval_6;
  uint32_t uval_7;
  int32_t arg_11;
  int val_8;
  int32_t arg_12;
  uint32_t uVar9;
  int32_t arg_13;
  uint32_t uVar10;
  int32_t arg_14;
  uint32_t uVar11;
  int32_t arg_15;
  uint32_t uVar12;
  int32_t arg_16;
  uint32_t uVar13;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    bVar5 = (*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0;
    if ((bVar5) && (val_2 = FUN_0049b309(spell_id,4,2), val_2 == 0)) {
      bVar5 = false;
    }
    if ((bVar5) && (val_2 = FUN_0049b309(spell_id,7,3), val_2 == 0)) {
      bVar5 = false;
    }
    uval_3 = 0;
    if (bVar5) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      uval_3 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_3,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_3 = 0;
  }
  else {
    if (((target_id == DAT_00690c48) && (spell_id == DAT_0068ecb0)) &&
       (((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x44) != 0)) {
      if (flags == 0x32) {
        DAT_0066642c = DAT_0066642c + 1;
      }
      if (flags == 0x33) {
        DAT_0066642c = DAT_0066642c + -2;
      }
    }
    if ((flags == 0x6d) &&
       ((*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0)) {
      DAT_0068ece0 = 1;
      Ai_CalcManaRequirement_004ba890(spell_id,4,2);
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f8ae0,s_CAVE_PEOPLE_004f8ad4);
        arg_20 = &card_idx;
        uval_3 = 1;
        arg_18 = &DAT_006679f0;
        uVar13 = 0;
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0xffffffff;
        uVar9 = 0xffffffff;
        val_8 = -1;
        val_2 = -1;
        uval_7 = 0;
        uval_6 = 0;
        uval_4 = FUN_004521e2(spell_id,target_id);
        val_2 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,spell_id,0x200,2,0,0,uval_4,uval_6,uval_7,val_2,val_8,uVar9,
                           uVar10,uVar11,uVar12,uVar13,arg_18,uval_3,arg_20);
        if (val_2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = card_idx;
          *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = match_count;
          (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
          *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
               *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
        }
      }
    }
    if (flags == 0x72) {
      card_idx = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
      match_count = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
      uVar13 = 0;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0xffffffff;
      uVar9 = 0xffffffff;
      val_8 = -1;
      val_2 = -1;
      uval_7 = 0;
      uval_6 = 0;
      uval_4 = FUN_004521e2(spell_id,target_id);
      val_2 = Rules_ParseFilter_0041c0ab
                        (card_idx,match_count,(uint8_t *)0x0,spell_id,2,2,0x200,2,0,0,uval_4,uval_6,
                         uval_7,val_2,val_8,uVar9,uVar10,uVar11,uVar12,uVar13);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        slot_idx = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,card_idx,match_count);
        if (slot_idx != -1) {
          cVar1 = FUN_004af74c(spell_id,target_id,4);
          *(int *)(&DAT_006826e4 + slot_idx * 0x120 + spell_id * 0x5b20) = 1 << (cVar1 - 1U & 0x1f);
        }
        *(int32_t *)(&DAT_006826fc + card_idx * 0x5b20 + match_count * 0x120) = 0x8000000;
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
       *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20] = 0;
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: Glue_Subsystem_004dce51
 * Entry Point: 0045e5ea
 * Size: 1258 bytes
 */


int32_t Glue_Subsystem_004dce51(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  bool bVar4;
  uint32_t uval_5;
  uint32_t uval_6;
  int32_t arg_11;
  int val_7;
  int32_t arg_12;
  uint32_t uval_8;
  int32_t arg_13;
  uint32_t uVar9;
  int32_t arg_14;
  uint32_t uVar10;
  int32_t arg_15;
  uint32_t uVar11;
  int32_t arg_16;
  uint32_t uVar12;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    bVar4 = (*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
    if ((bVar4) && (val_1 = FUN_0049b309(spell_id,3,1), val_1 == 0)) {
      bVar4 = false;
    }
    if ((bVar4) && (val_1 = FUN_0049b309(spell_id,7,2), val_1 == 0)) {
      bVar4 = false;
    }
    uval_2 = 0;
    if (bVar4) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = FUN_004521e2(spell_id,target_id);
      uval_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_2 = 0;
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      DAT_0068ece0 = 1;
      Ai_CalcManaRequirement_004ba890(spell_id,3,1);
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f8afc,s_PRADESH_GYPSIES_004f8aec);
        arg_20 = &card_idx;
        uval_2 = 1;
        arg_18 = &DAT_006679f0;
        uVar12 = 0;
        uVar11 = 0;
        uVar10 = 0;
        uVar9 = 0xffffffff;
        uval_8 = 0xffffffff;
        val_7 = -1;
        val_1 = -1;
        uval_6 = 0;
        uval_5 = 0;
        uval_3 = FUN_004521e2(spell_id,target_id);
        val_1 = Action_ValidateTarget_0041e2a2
                          (spell_id,2,spell_id,0x200,2,0,0,uval_3,uval_5,uval_6,val_1,val_7,uval_8,uVar9
                           ,uVar10,uVar11,uVar12,arg_18,uval_2,arg_20);
        if (val_1 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
          *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = match_count;
          (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
          *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
               *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        }
      }
    }
    if (flags == 0x72) {
      card_idx = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      match_count = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      val_1 = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_1 = Rules_ParseFilter_0041c0ab
                        (card_idx,match_count,(uint8_t *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_5,
                         uval_6,val_1,val_7,uval_8,uVar9,uVar10,uVar11,uVar12);
      if (val_1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        slot_idx = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,card_idx,match_count);
        if (slot_idx != -1) {
          *(int16_t *)(&DAT_006826d8 + slot_idx * 0x120 + spell_id * 0x5b20) = 0xfffe;
          *(int16_t *)(&DAT_006826da + slot_idx * 0x120 + spell_id * 0x5b20) = 0;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if ((((flags == 0x3b) &&
         ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
        (val_1 = FUN_0049b309(spell_id,3,1), val_1 != 0)) &&
       (val_1 = FUN_0049b309(spell_id,7,2), val_1 != 0)) {
      *(int *)(&DAT_00666730 + (1 - spell_id) * 4) =
           *(int *)(&DAT_00666730 + (1 - spell_id) * 4) + -2;
    }
    if (((flags == 0x8a) && (target_id == DAT_00690c48)) &&
       ((spell_id == DAT_0068ecb0 && (val_1 = FUN_0049b309(spell_id,3,1), val_1 != 0)))) {
      DAT_0069340c = DAT_0069340c + 0xc;
    }
    if (((flags == 0x8b) && (target_id == DAT_00690c48)) &&
       ((spell_id == DAT_0068ecb0 && (val_1 = FUN_0049b309(spell_id,3,1), val_1 != 0)))) {
      DAT_0069340c = DAT_0069340c + -0xc;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_0045ead4
 * Entry Point: 0045ead4
 * Size: 753 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t FUN_0045ead4(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  
  if (arg_3 == 0x73) {
    if (arg_1 == DAT_00676510) {
      if (((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
         (((DAT_0066aad4 | _DAT_0066aad0) & 2) != 0)) {
        uval_1 = 1;
      }
      else {
        uval_1 = 0;
      }
    }
    else if (((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
            (((&DAT_0066aad0)[DAT_00676504 * 4] & 2) != 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uval_1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) &&
       ((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      if (match_count == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)DAT_0068eef0;
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = match_count;
      }
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      val_2 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,
                           (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                           *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20));
      if (val_2 != -1) {
        *(int16_t *)(&DAT_006826d8 + val_2 * 0x120 + arg_1 * 0x5b20) = 1;
        *(int16_t *)(&DAT_006826da + val_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      *(int32_t *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if ((arg_3 == 0x3b) &&
       ((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20014) == 0)) {
      *(int *)(&DAT_00666730 + arg_1 * 4) = *(int *)(&DAT_00666730 + arg_1 * 4) + 1;
      *(int *)(&DAT_00666738 + arg_1 * 4) = *(int *)(&DAT_00666738 + arg_1 * 4) + 1;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Glue_Subsystem_004dd632
 * Entry Point: 0045edca
 * Size: 861 bytes
 */


uint8_t Glue_Subsystem_004dd632(int spell_id,int target_id,int flags)

{
  uint8_t uval_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    uval_1 = 0;
    if ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0 &&
        ((uint8_t)DAT_00681eb0 & 4) != 0) {
      val_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff,
                           0xffffffff,0xffffffff,0,0,0);
      if (val_2 == 0) {
        uval_1 = 0;
      }
      else {
        uval_1 = 99;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_1 = 0;
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8b18,s_SAMITE_HEALER_004f8b08);
      val_2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,-1,0xffffffff,0xffffffff,0,0,0,
                         &DAT_006679f0,1,&match_count);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      val_2 = Rules_ParseFilter_0041c0ab
                        (match_count,slot_idx,(uint8_t *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,
                         DAT_0068f104,-1,0xffffffff,0xffffffff,0,0,0);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else if (*(int *)(&DAT_006826e4 + match_count * 0x5b20 + slot_idx * 0x120) != 0) {
        *(int *)(&DAT_006826e4 + match_count * 0x5b20 + slot_idx * 0x120) =
             *(int *)(&DAT_006826e4 + match_count * 0x5b20 + slot_idx * 0x120) + -1;
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if ((flags == 0x3b) &&
       ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      *(int *)(&DAT_00666738 + spell_id * 4) = *(int *)(&DAT_00666738 + spell_id * 4) + 1;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0045f127
 * Entry Point: 0045f127
 * Size: 869 bytes
 */


int32_t FUN_0045f127(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int slot_idx;
  
  if (arg_3 == 0x73) {
    if (((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (((uint8_t)DAT_00681eb0 & 4) != 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uval_1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      if ((slot_idx == -1) ||
         (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) != DAT_0068f104
         )) {
        DAT_00681ea4 = 1;
      }
      else if ((*(int *)(&DAT_006826e4 +
                        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) == 0) ||
              (((&DAT_004ff594)
                [*(int *)(&DAT_006826c4 +
                         *(int *)(&DAT_006826e8 +
                                 *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                 *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20)
                         * 0x120 + (char)(&DAT_006826d2)
                                         [*(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                          0x120 + *(int *)(&DAT_00682718 +
                                                          arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20]
                                   * 0x5b20) * 0x34] & 0x40) == 0)) {
        DAT_00681ea4 = 1;
      }
      else {
        uval_1 = FUN_0049aa14(*(int *)(&DAT_006826e4 +
                                     *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                     0x120 + *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20
                                                     ) * 0x5b20) + -2,0,99);
        *(int32_t *)
         (&DAT_006826e4 +
         *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) = uval_1;
        *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
      if (arg_1 == DAT_00676504) {
        *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0045f48c
 * Entry Point: 0045f48c
 * Size: 344 bytes
 */


int32_t FUN_0045f48c(int player_id,int card_slot,int event_type)

{
  int slot_idx;
  
  if (((((DAT_0068f230 == 0xd3) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) &&
      ((arg_1 == DAT_00681ec4 && (arg_1 == DAT_00666458)))) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((&DAT_004ff594)
        [*(int *)(&DAT_006826c4 + DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20) * 0x34] & 4) != 0)))
     ) {
    if (arg_3 == 0x7d) {
      if (arg_1 == DAT_00676510) {
        DAT_0066642c = DAT_0066642c | 1;
      }
      else {
        slot_idx = 0;
        while ((slot_idx < 500 && (*(int *)(&DAT_006669f0 + slot_idx * 4 + arg_1 * 2000) != -1))) {
          slot_idx = slot_idx + 1;
        }
        if (((int)(&DAT_0068ee78)[arg_1] < 8) && (5 < slot_idx)) {
          DAT_0066642c = DAT_0066642c | 2;
        }
        else {
          DAT_0066642c = DAT_0066642c | 1;
        }
      }
    }
    if (arg_3 == 0x7e) {
      FUN_00487ce1(arg_1);
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045f5e4
 * Entry Point: 0045f5e4
 * Size: 168 bytes
 */


int32_t FUN_0045f5e4(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x6c) &&
      (((&DAT_004ff594)
        [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] & 0x40) != 0
      )) && (arg_1 != DAT_0068ecb0)) {
    *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
    *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045f68c
 * Entry Point: 0045f68c
 * Size: 81 bytes
 */


int32_t FUN_0045f68c(int arg1,int arg2)

{
  if ((arg2 == DAT_00690c48) && (arg1 == DAT_0068ecb0)) {
    *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) | 0x2000;
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045f6dd
 * Entry Point: 0045f6dd
 * Size: 77 bytes
 */


int32_t FUN_0045f6dd(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x34) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     (arg_1 == DAT_00666458)) {
    DAT_0066642c = DAT_0066642c & 0xffffffdf;
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045f72a
 * Entry Point: 0045f72a
 * Size: 199 bytes
 */


int32_t FUN_0045f72a(int player_id,int card_slot,int event_type)

{
  char cVar1;
  
  if (((&DAT_004ff595)
       [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] == '\x02') &&
     (arg_3 == 0x34)) {
    cVar1 = FUN_004af74c(arg_1,arg_2,1);
    DAT_0066642c = DAT_0066642c | (1 << (cVar1 - 1U & 0x1f)) + 0x200U;
  }
  if (((arg_3 == 0x77) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    FUN_00467d65(FUN_0045f7f1,-1);
    FUN_00451482(0,0xff);
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045f7f1
 * Entry Point: 0045f7f1
 * Size: 84 bytes
 */


int32_t FUN_0045f7f1(int player_id,int card_slot,int event_type)

{
  if ((&DAT_004ff595)[arg_3 * 0x34] == '\x02') {
    *(uint32_t *)(&DAT_006826fc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826fc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x8000000;
  }
  return 1;
}



/*
 * Decompiled function: FUN_0045f845
 * Entry Point: 0045f845
 * Size: 77 bytes
 */


int32_t FUN_0045f845(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (((arg_3 == 0x73) || (arg_3 == 0x6d)) || (arg_3 == 0x72)) {
    uval_1 = FUN_004593fd(arg_1,arg_2,arg_3,1,1);
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0045f892
 * Entry Point: 0045f892
 * Size: 192 bytes
 */


int32_t FUN_0045f892(int player_id,int card_slot,int event_type)

{
  char cVar1;
  
  if (((&DAT_004ff595)
       [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] == '\x03') &&
     (((&DAT_006826cc)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] & 2) != 0)) {
    if (arg_3 == 0x34) {
      cVar1 = FUN_004af74c(arg_1,arg_2,4);
      DAT_0066642c = DAT_0066642c | 1 << (cVar1 - 1U & 0x1f);
    }
    if ((arg_3 == 0x32) || (arg_3 == 0x33)) {
      DAT_0066642c = DAT_0066642c + 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004de1c0
 * Entry Point: 0045f952
 * Size: 414 bytes
 */


int32_t Glue_Subsystem_004de1c0(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 199) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     ((arg_1 == DAT_00666458 &&
      ((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x30044) == 0)))) {
    if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
      Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Erg_Raiders_take_2_life__004f8b24,0);
    }
    Mem_AllocOrFree_004afd1c(arg_1,2,arg_1,arg_2);
  }
  if (((DAT_0068f230 == 0xcd) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((arg_1 == DAT_00666458 && (arg_1 == DAT_00681ec4)) &&
       ((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x30044) == 0)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
        Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Erg_Raiders_take_2_life__004f8b40,0);
      }
      Mem_AllocOrFree_004afd1c(arg_1,2,arg_1,arg_2);
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045faf0
 * Entry Point: 0045faf0
 * Size: 308 bytes
 */


int32_t FUN_0045faf0(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if ((((arg_3 == 0x78) && (arg_2 == DAT_0068ecfc)) && (arg_1 == DAT_00690310)) &&
     ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34]
      == '\0')) {
    DAT_0066642c = 1;
  }
  if ((arg_3 == 0x15) && (arg_1 == DAT_00666458)) {
    val_1 = FUN_0048ad82(arg_1,arg_2);
    if (val_1 != 0) {
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 4;
      DAT_006826b0 = DAT_006826b0 + 1;
    }
  }
  if (((arg_3 == 0x22) || (arg_3 == 199)) &&
     ((arg_1 == DAT_00666458 &&
      ((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20054) == 0)))) {
    FUN_0046e571(arg_1,arg_2,4);
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045fc24
 * Entry Point: 0045fc24
 * Size: 939 bytes
 */


int32_t FUN_0045fc24(int player_id,int card_slot,int event_type)

{
  int arg_3_00;
  int slot_idx;
  
  if ((((arg_3 == 0x6e) &&
       (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
      ((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1)) &&
     ((*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2 &&
      (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)))) {
    (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)DAT_0068ecb0;
    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00690c48;
  }
  if (((DAT_0068f230 == 0xd7) && (DAT_00690c48 == arg_2)) &&
     ((DAT_0068ecb0 == arg_1 &&
      (((&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1 && (DAT_00681ec4 == arg_1)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      slot_idx = *(int *)(&DAT_006826e4 +
                        *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20);
      if (*(int *)(&DAT_006826e8 +
                  *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) != -1) {
        arg_3_00 = FUN_0048b81a((int)(char)(&DAT_006826d2)
                                           [*(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20)
                                            * 0x120 + (char)(&DAT_006826d3)
                                                            [arg_2 * 0x120 + arg_1 * 0x5b20] *
                                                      0x5b20],
                                *(int *)(&DAT_006826e8 +
                                        *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                        0x120 + (char)(&DAT_006826d3)
                                                      [arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20),
                                0x33,0xffffffff);
        slot_idx = FUN_0049aa14(*(int *)(&DAT_006826e4 +
                                       *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                       0x120 + (char)(&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20]
                                               * 0x5b20),0,arg_3_00);
      }
      (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + slot_idx;
      (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_0045ffcf
 * Entry Point: 0045ffcf
 * Size: 967 bytes
 */


int32_t FUN_0045ffcf(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
  }
  if (((arg_3 == 0x82) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(uint32_t *)(&DAT_006827c8 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint32_t *)(&DAT_006827c8 + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffffffc;
  }
  if (((arg_3 == 0x84) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0 && (arg_1 == DAT_00666458))
       && (arg_1 == DAT_00681eb4)))))) {
    *(uint32_t *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint32_t *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
  }
  if ((arg_3 == 0x88) &&
     (val_1 = FUN_004af74c(arg_1,arg_2,2), *(int *)(&DAT_0068ef50 + val_1 * 4 + arg_1 * 0x20) < 2))
  {
    DAT_0066642c = DAT_0066642c | 1;
  }
  if (arg_3 == 1) {
    val_1 = Glue_Subsystem_004dec09(arg_1,arg_2,1);
    if (val_1 == 0) {
      DAT_0066642c = DAT_0066642c | 1;
    }
    else {
      *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffffffef;
    }
  }
  if ((arg_3 == 0x79) && (*(int *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) == 0)) {
    val_1 = FUN_004af74c(arg_1,arg_2,2);
    if (*(int *)(&DAT_0068ef50 + val_1 * 4 + arg_1 * 0x20) < 2) {
      DAT_0066642c = 1;
    }
  }
  else {
    if ((((DAT_0068f230 == 0xdc) &&
         ((((DAT_0068f2c4 == 0x15 && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
          ((DAT_00681ec4 == DAT_00666458 &&
           (*(int *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) == 0)))))) &&
        (arg_1 == DAT_00666754)) && (arg_2 == DAT_0068edd0)) {
      val_1 = FUN_004af74c(arg_1,arg_2,2);
      if (*(int *)(&DAT_0068ef50 + val_1 * 4 + arg_1 * 0x20) < 2) {
        DAT_00666428 = 1;
      }
      else {
        if (arg_3 == 0x7d) {
          DAT_0066642c = DAT_0066642c | 2;
        }
        if (arg_3 == 0x7e) {
          val_1 = Glue_Subsystem_004dec09(arg_1,arg_2,0);
          if (val_1 == 0) {
            DAT_00666428 = 1;
            DAT_00681ea4 = 0;
          }
          else {
            *(int32_t *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
          }
        }
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      *(int32_t *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
      *(int32_t *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(int32_t *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120);
    }
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004dec09
 * Entry Point: 00460396
 * Size: 610 bytes
 */


int32_t Glue_Subsystem_004dec09(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  int aiStack_20 [7];
  
  val_1 = FUN_004af74c(spell_id,target_id,2);
  aiStack_20[6] = val_1 + -1;
  aiStack_20[5] = 0;
  while ((aiStack_20[5] < 2 && (DAT_00681ea4 != 1))) {
    FUN_00434660(s_prompts_txt_004f8b68,s_LEVIATHAN_004f8b5c);
    if (aiStack_20[6] == 4) {
      FUN_004718de(&DAT_006679f0,s_island_004f8b7c,0,s_PLAINS_004f8b74);
    }
    else if (aiStack_20[6] == 0) {
      FUN_004718de(&DAT_006679f0,s_island_004f8b8c,0,s_SWAMP_004f8b84);
    }
    else if (aiStack_20[6] == 3) {
      FUN_004718de(&DAT_006679f0,s_island_004f8ba0,0,s_MOUNTAIN_004f8b94);
    }
    else if (aiStack_20[6] == 2) {
      FUN_004718de(&DAT_006679f0,s_island_004f8bb0,0,s_FOREST_004f8ba8);
    }
    val_1 = Action_ValidateTarget_0041e2a2
                      (spell_id,spell_id,spell_id,0x200,0,0,0,0,0,0,aiStack_20[6],-1,0xffffffff,
                       0xffffffff,0,0,0,&DAT_006679f0,(uint32_t)(flags != 0),
                       aiStack_20 + aiStack_20[5] * 2);
    if (val_1 == 0) {
      for (aiStack_20[4] = 0; aiStack_20[4] < aiStack_20[5]; aiStack_20[4] = aiStack_20[4] + 1) {
        *(uint32_t *)(&DAT_006826cc +
                 aiStack_20[aiStack_20[4] * 2] * 0x5b20 + aiStack_20[aiStack_20[4] * 2 + 1] * 0x120)
             = *(uint32_t *)(&DAT_006826cc +
                        aiStack_20[aiStack_20[4] * 2] * 0x5b20 +
                        aiStack_20[aiStack_20[4] * 2 + 1] * 0x120) & 0xffcfffff;
      }
      FUN_00451482(0,0x20);
      DAT_00681ea4 = 1;
    }
    else {
      *(uint32_t *)(&DAT_006826cc +
               aiStack_20[aiStack_20[5] * 2] * 0x5b20 + aiStack_20[aiStack_20[5] * 2 + 1] * 0x120) =
           *(uint32_t *)(&DAT_006826cc +
                    aiStack_20[aiStack_20[5] * 2] * 0x5b20 +
                    aiStack_20[aiStack_20[5] * 2 + 1] * 0x120) | 0x300000;
      FUN_00451482(0,0x20);
    }
    aiStack_20[5] = aiStack_20[5] + 1;
  }
  if (DAT_00681ea4 == 1) {
    DAT_00681ea4 = -1;
    uval_2 = 0;
  }
  else {
    for (aiStack_20[5] = 0; aiStack_20[5] < 2; aiStack_20[5] = aiStack_20[5] + 1) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0xf);
      }
      FUN_0046e571(aiStack_20[aiStack_20[5] * 2],aiStack_20[aiStack_20[5] * 2 + 1],3);
    }
    uval_2 = 1;
  }
  return uval_2;
}



/*
 * Decompiled function: Glue_Subsystem_004dee6b
 * Entry Point: 004605f8
 * Size: 343 bytes
 */


int32_t Glue_Subsystem_004dee6b(int player_id,int card_slot,int event_type)

{
  int val_1;
  int slot_idx;
  
  if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0066642c = DAT_0066642c | 2;
  }
  if ((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) {
    val_1 = FUN_00467cce(arg_1,1);
    if (val_1 == 0) {
      FUN_0046e571(arg_1,arg_2,2);
    }
  }
  if ((((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) || (arg_3 == 199)) {
    Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Pick_a_land__004f8bb8);
    do {
    } while (slot_idx == -1);
    if (slot_idx != -1) {
      if (((&DAT_006826dc)[slot_idx * 0x120 + arg_1 * 0x5b20] & 4) != 0) {
        Mem_AllocOrFree_004afd1c(arg_1,3,arg_1,arg_2);
      }
      FUN_0046e571(arg_1,slot_idx,3);
    }
    val_1 = FUN_00467cce(arg_1,1);
    if (val_1 == 0) {
      FUN_0046e571(arg_1,arg_2,2);
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_0046074f
 * Entry Point: 0046074f
 * Size: 136 bytes
 */


int32_t FUN_0046074f(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0066642c = DAT_0066642c | 2;
  }
  if ((((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) || (arg_3 == 199)) {
    Mem_AllocOrFree_004afd1c(arg_1,1,arg_1,arg_2);
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004df04a
 * Entry Point: 004607d7
 * Size: 450 bytes
 */


int32_t Glue_Subsystem_004df04a(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  
  if (flags == 0x73) {
    val_1 = FUN_0049b309(spell_id,4,2);
    if ((val_1 == 0) || (val_1 = FUN_0049b309(spell_id,7,3), val_1 == 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(1);
    uval_2 = 0;
  }
  else {
    if (flags == 0x6d) {
      DAT_0068ece0 = 1;
      Ai_CalcManaRequirement_004ba890(spell_id,4,2);
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f8bdc,s_BROTHERS_OF_FIRE_004f8bc8);
      }
      FUN_00461047(spell_id,target_id);
    }
    if (flags == 0x72) {
      val_1 = FUN_004612b0(spell_id,target_id,0x72,1);
      if (val_1 != 0) {
        *(uint32_t *)(&DAT_006826cc +
                 *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc +
                      *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                      *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20) &
             0xffffffef;
        Mem_AllocOrFree_004afd1c(spell_id,1,DAT_00690af0,DAT_0068efa0);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00460999
 * Entry Point: 00460999
 * Size: 264 bytes
 */


bool FUN_00460999(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  
  if (arg_3 == 0x73) {
    flag_1 = (*(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x20010) == 0;
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(1);
    flag_1 = false;
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_00461047(arg_1,arg_2);
    }
    if (arg_3 == 0x72) {
      FUN_004612b0(arg_1,arg_2,0x72,1);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120] = 0;
    }
    flag_1 = false;
  }
  return flag_1;
}



/*
 * Decompiled function: Glue_Subsystem_004df314
 * Entry Point: 00460aa1
 * Size: 868 bytes
 */


int32_t Glue_Subsystem_004df314(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  bool bVar4;
  uint32_t uval_5;
  uint32_t uval_6;
  int32_t arg_11;
  int val_7;
  int32_t arg_12;
  uint32_t uval_8;
  int32_t arg_13;
  uint32_t uVar9;
  int32_t arg_14;
  uint32_t uVar10;
  int32_t arg_15;
  uint32_t uVar11;
  int32_t arg_16;
  uint32_t uVar12;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    bVar4 = (*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
    if ((bVar4) && (val_1 = FUN_0049b309(spell_id,4,1), val_1 == 0)) {
      bVar4 = false;
    }
    uval_2 = 0;
    if (bVar4) {
      arg_19 = 0;
      arg_18_00 = 0x20;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = FUN_004521e2(spell_id,target_id);
      uval_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_2 = 0;
  }
  else {
    if (((flags == 0x6d) &&
        ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,4,1), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f8bfc,s_CRIMSON_MANTICORE_004f8be8);
      arg_20 = &match_count;
      uval_2 = 1;
      arg_18 = &DAT_006679f0;
      uVar12 = 0;
      uVar11 = 0x20;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      val_1 = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_1 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uval_3,uval_5,uval_6,val_1,val_7,uval_8,
                         uVar9,uVar10,uVar11,uVar12,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      uVar12 = 0;
      uVar11 = 0x20;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uval_8 = 0xffffffff;
      val_7 = -1;
      val_1 = -1;
      uval_6 = 0;
      uval_5 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_1 = Rules_ParseFilter_0041c0ab
                        (match_count,slot_idx,(uint8_t *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_5,
                         uval_6,val_1,val_7,uval_8,uVar9,uVar10,uVar11,uVar12);
      if (val_1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_004af950(match_count,slot_idx,1,DAT_00690af0,DAT_0068efa0);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Glue_Subsystem_004df678
 * Entry Point: 00460e05
 * Size: 578 bytes
 */


bool Glue_Subsystem_004df678(int spell_id,int target_id,int flags)

{
  bool flag_1;
  
  if (flags == 0x73) {
    flag_1 = (*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
  }
  else if (flags == 0x90) {
    FUN_0043071d(1);
    flag_1 = false;
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8c1c,s_PRODIGAL_SORCERER_004f8c08);
      FUN_00461047(spell_id,target_id);
      if (DAT_00681ea4 != 1) {
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      FUN_004612b0(spell_id,target_id,0x72,1);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if ((flags == 0x3b) &&
       ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20014) == 0)) {
      *(int *)(&DAT_00666738 + (1 - spell_id) * 4) =
           *(int *)(&DAT_00666738 + (1 - spell_id) * 4) + -1;
    }
    if ((((flags == 199) && (spell_id == DAT_00666458)) && (spell_id == DAT_00676504)) &&
       ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
    }
    if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0x30;
    }
    if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0x30;
    }
    flag_1 = false;
  }
  return flag_1;
}



/*
 * Decompiled function: FUN_00461047
 * Entry Point: 00461047
 * Size: 612 bytes
 */


bool FUN_00461047(int arg1,int arg2)

{
  uint32_t uval_1;
  bool flag_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int val_6;
  uint32_t uval_7;
  uint32_t uval_8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  uint8_t *puVar12;
  int32_t uVar13;
  int *piVar14;
  int32_t player_idx;
  int card_idx;
  int32_t match_count;
  int32_t slot_idx;
  
  slot_idx = 0;
  if (arg1 == DAT_00676510) {
    if (DAT_0066aaf4 == 1) {
      player_idx = 0xffffffff;
      DAT_0068eef0 = 1 - arg1;
    }
    else {
      piVar14 = &card_idx;
      uVar13 = 1;
      puVar12 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_1 = FUN_004521e2(arg1,arg2);
      val_5 = Action_ValidateTarget_0041e2a2
                        (arg1,2,1 - arg1,0x1200,2,0,0,uval_1,uval_3,uval_4,val_5,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,puVar12,uVar13,piVar14);
      if (val_5 == 0) {
        DAT_00681ea4 = 1;
        player_idx = 0xffffffff;
        DAT_0068eef0 = -1;
      }
      else {
        player_idx = match_count;
        DAT_0068eef0 = card_idx;
      }
    }
  }
  else {
    if (DAT_0066aaf4 == 1) {
      val_5 = FUN_00439892(3);
      DAT_0068f2c8 = (uint32_t)(val_5 == 0);
      FUN_0043064a();
    }
    else {
      FUN_004307b2();
    }
    if (DAT_0068f2c8 == 0) {
      piVar14 = &card_idx;
      uVar13 = 1;
      puVar12 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_1 = FUN_004521e2(arg1,arg2);
      Action_ValidateTarget_0041e2a2
                (arg1,2,1 - arg1,0x1200,2,0,0,uval_1,uval_3,uval_4,val_5,val_6,uval_7,uval_8,uVar9,uVar10
                 ,uVar11,puVar12,uVar13,piVar14);
      player_idx = match_count;
      DAT_0068eef0 = card_idx;
    }
    else {
      player_idx = 0xffffffff;
      DAT_0068eef0 = 1 - arg1;
      if (DAT_0066aaf4 == 1) {
        DAT_0068f2c8 = 0;
        DAT_0068f0bc = CONCAT31((uint3)((DAT_0068eef0 == 0) - 1 >> 8) & 1,0xff);
        FUN_0043064a();
      }
      else {
        FUN_004307b2();
      }
    }
  }
  flag_2 = DAT_00681ea4 != 1;
  if (flag_2) {
    *(int32_t *)(&DAT_0068271c + arg2 * 0x120 + arg1 * 0x5b20) = player_idx;
    *(int *)(&DAT_00682718 + arg2 * 0x120 + arg1 * 0x5b20) = DAT_0068eef0;
    (&DAT_006827b8)[arg2 * 0x120 + arg1 * 0x5b20] = 1;
  }
  return flag_2;
}



/*
 * Decompiled function: FUN_004612b0
 * Entry Point: 004612b0
 * Size: 529 bytes
 */


int32_t FUN_004612b0(int x,int y,int width,int arg_4)

{
  int32_t uval_1;
  uint32_t arg_11;
  uint32_t arg_12;
  uint32_t arg_13;
  int val_2;
  int arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint32_t arg_18;
  uint32_t arg_19;
  uint32_t arg_20;
  int match_count;
  int slot_idx;
  
  if ((&DAT_006827b8)[y * 0x120 + x * 0x5b20] == '\0') {
    uval_1 = 0;
  }
  else {
    if (width == 0x72) {
      match_count = DAT_00690af0;
      slot_idx = DAT_0068efa0;
    }
    else {
      match_count = x;
      slot_idx = y;
    }
    if ((*(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20) == -1) &&
       (*(int *)(&DAT_0068271c + y * 0x120 + x * 0x5b20) == -1)) {
      uval_1 = 0;
    }
    else {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(x,y);
      val_2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20),
                         *(int *)(&DAT_0068271c + y * 0x120 + x * 0x5b20),(uint8_t *)0x0,x,2,2,
                         0x1200,2,0,0,arg_11,arg_12,arg_13,val_2,arg_15,arg_16,arg_17,arg_18,arg_19,
                         arg_20);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
        uval_1 = 0;
      }
      else {
        if (*(int *)(&DAT_0068271c + y * 0x120 + x * 0x5b20) == -1) {
          Mem_AllocOrFree_004afd1c
                    (*(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20),arg_4,match_count,slot_idx);
        }
        else {
          FUN_004af950(*(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20),
                       *(int *)(&DAT_0068271c + y * 0x120 + x * 0x5b20),arg_4,match_count,slot_idx);
        }
        uval_1 = 1;
      }
    }
  }
  return uval_1;
}



/*
 * Decompiled function: Glue_Subsystem_004dfd39
 * Entry Point: 004614c6
 * Size: 347 bytes
 */


bool Glue_Subsystem_004dfd39(int spell_id,int target_id,int flags)

{
  bool flag_1;
  
  if (flags == 0x73) {
    flag_1 = (*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
  }
  else if (flags == 0x90) {
    FUN_0043071d(1);
    flag_1 = false;
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8c34,s_PIRATE_SHIP_004f8c28);
      FUN_00461047(spell_id,target_id);
      if (DAT_00681ea4 != 1) {
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      FUN_004612b0(spell_id,target_id,0x72,1);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    FUN_00461715(spell_id,target_id,flags);
    flag_1 = false;
  }
  return flag_1;
}



/*
 * Decompiled function: FUN_00461621
 * Entry Point: 00461621
 * Size: 244 bytes
 */


int32_t FUN_00461621(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int arg1;
  int val_2;
  int slot_idx;
  
  if ((arg_3 == 0x1a) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
    flag_1 = true;
    arg1 = 1 - arg_1;
    for (slot_idx = 0; slot_idx < (int)(&DAT_00666408)[arg1]; slot_idx = slot_idx + 1) {
      val_2 = FUN_0048a33f(arg1,slot_idx);
      if ((val_2 != 0) && ((char)(&DAT_006826de)[slot_idx * 0x120 + arg1 * 0x5b20] == arg_2)) {
        flag_1 = false;
        break;
      }
    }
    if (flag_1) {
      (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + 2;
    }
  }
  FUN_00461715(arg_1,arg_2,arg_3);
  return 0;
}



/*
 * Decompiled function: FUN_00461715
 * Entry Point: 00461715
 * Size: 175 bytes
 */


int32_t FUN_00461715(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0) {
    val_1 = FUN_004af74c(arg_1,arg_2,2);
    if (*(int *)(&DAT_0068ef50 + val_1 * 4 + arg_1 * 0x20) == 0) {
      FUN_0046e571(arg_1,arg_2,2);
    }
  }
  if (arg_3 == 0x79) {
    val_1 = FUN_004af74c(arg_1,arg_2,2);
    if (*(int *)(&DAT_0068ef50 + val_1 * 4 + (1 - arg_1) * 0x20) == 0) {
      DAT_0066642c = 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004617c4
 * Entry Point: 004617c4
 * Size: 176 bytes
 */


int32_t FUN_004617c4(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x1a) && (arg_1 != DAT_00666458)) &&
     ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if ((arg_3 == 0x79) && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    DAT_0066642c = 1;
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004e00e7
 * Entry Point: 00461874
 * Size: 718 bytes
 */


int32_t Glue_Subsystem_004e00e7(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((((arg_3 == 0x84) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
      ((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0 && (arg_1 == DAT_00666458))))
     && (arg_1 == DAT_00681eb4)) {
    *(uint32_t *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint32_t *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
    (&DAT_006827ce)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006827ce)[arg_1 * 0x5b20 + arg_2 * 0x120] + '\x03';
  }
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f328 + arg_1 * 0x20) = *(int *)(&DAT_0068f328 + arg_1 * 0x20) + 1;
  }
  FUN_00461715(arg_1,arg_2,arg_3);
  if (((arg_3 == 0x82) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(uint32_t *)(&DAT_006827c8 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint32_t *)(&DAT_006827c8 + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffffffc;
  }
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    (&DAT_006827ce)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006827ce)[arg_1 * 0x5b20 + arg_2 * 0x120] + '\x03';
  }
  if ((((DAT_0068f230 == 0xca) && (arg_1 == DAT_00666458)) &&
      ((arg_2 == DAT_00690c48 && ((arg_1 == DAT_0068ecb0 && (arg_1 == DAT_00681ec4)))))) &&
     (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0)) {
    val_1 = FUN_0049b309(arg_1,2,3);
    if (val_1 != 0) {
      if (arg_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (arg_3 == 0x7e) {
        val_1 = Ai_Subsystem_004cc56d
                          (arg_1,arg_1,arg_2,-1,-1,s_Untap_Island_Fish__Don_t_untap__004f8c40,0);
        if (val_1 == 0) {
          Ai_CalcManaRequirement_004ba890(arg_1,2,3);
          if (DAT_00681ea4 == 1) {
            DAT_00681ea4 = -1;
          }
          else {
            *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
                 *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffffffef;
          }
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00461b42
 * Entry Point: 00461b42
 * Size: 265 bytes
 */


int32_t FUN_00461b42(int player_id,int card_slot,int event_type)

{
  char cVar1;
  int val_2;
  
  val_2 = FUN_0048a33f(DAT_0068ecb0,DAT_00690c48);
  if ((val_2 != 0) &&
     ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34]
      == '\x01')) {
    if (arg_3 == 0x34) {
      cVar1 = FUN_004af74c(arg_1,arg_2,2);
      DAT_0066642c = DAT_0066642c | 1 << (cVar1 - 1U & 0x1f);
    }
    if ((arg_3 == 0x32) || (arg_3 == 0x33)) {
      DAT_0066642c = DAT_0066642c + 1;
    }
    if ((arg_3 == 0x77) && (((&DAT_006826f8)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0)) {
      *(uint32_t *)(&DAT_006826fc + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) =
           *(uint32_t *)(&DAT_006826fc + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) | 0xe000000;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00461c4b
 * Entry Point: 00461c4b
 * Size: 194 bytes
 */


int32_t FUN_00461c4b(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (arg_3 == 0x79) {
    val_1 = FUN_004af74c(arg_1,arg_2,4);
    if (*(int *)(&DAT_0068ef50 + val_1 * 4 + (1 - arg_1) * 0x20) == 0) {
      DAT_0066642c = 1;
    }
  }
  if ((arg_3 == 0x1a) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) {
    FUN_004a2b00(arg_1,arg_2,DAT_006664e8,arg_1,arg_2);
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00461d0d
 * Entry Point: 00461d0d
 * Size: 565 bytes
 */


uint32_t FUN_00461d0d(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x73) {
    uval_1 = *(uint32_t *)(&DAT_0066aad0 + arg_1 * 4) & 0x40;
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uval_1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      val_2 = FUN_00468a84(arg_1);
      if (val_2 != 0) {
        *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) + 2;
        *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) + 2;
        *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      }
    }
    if (((arg_3 == 0x22) || (arg_3 == 199)) &&
       (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) {
      *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) * -2;
      *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) * -2;
      *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00461f42
 * Entry Point: 00461f42
 * Size: 247 bytes
 */


int32_t FUN_00461f42(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int slot_idx;
  
  if (arg_3 == 0x73) {
    if (((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (((&DAT_0066aad0)[arg_1 * 4] & 0x40) != 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uval_1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      val_2 = FUN_00468a84(arg_1);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0049b235(arg_1,1,(int)(char)(&DAT_004ff598)[slot_idx * 0x34]);
      }
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00462039
 * Entry Point: 00462039
 * Size: 175 bytes
 */


int32_t FUN_00462039(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0066642c = DAT_0066642c | 2;
  }
  if (((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    val_1 = FUN_00468a84(arg_1);
    if (val_1 == 0) {
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      Mem_AllocOrFree_004afd1c(arg_1,2,arg_1,arg_2);
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004620e8
 * Entry Point: 004620e8
 * Size: 348 bytes
 */


int32_t FUN_004620e8(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x73) {
    if (((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (((&DAT_0066aad0)[arg_1 * 4] & 0x40) != 0)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(1);
    uval_1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      val_2 = FUN_00468a84(arg_1);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_00461047(arg_1,arg_2);
      }
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      FUN_004612b0(arg_1,arg_2,0x72,2);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20] = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Glue_Subsystem_004e0ab7
 * Entry Point: 00462244
 * Size: 357 bytes
 */


bool Glue_Subsystem_004e0ab7(int spell_id,int target_id,int flags)

{
  int val_1;
  bool flag_2;
  
  if (flags == 0x73) {
    flag_2 = (*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
  }
  else if (flags == 0x90) {
    FUN_0043071d(1);
    flag_2 = false;
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8c78,s_ORCISH_ARTILLERY_004f8c64);
      FUN_00461047(spell_id,target_id);
      if (DAT_00681ea4 != 1) {
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      val_1 = FUN_004612b0(spell_id,target_id,0x72,2);
      if (val_1 != 0) {
        Mem_AllocOrFree_004afd1c(spell_id,3,spell_id,target_id);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
    flag_2 = false;
  }
  return flag_2;
}



/*
 * Decompiled function: Glue_Subsystem_004e0c1c
 * Entry Point: 004623a9
 * Size: 580 bytes
 */


bool Glue_Subsystem_004e0c1c(int spell_id,int target_id,int flags)

{
  int val_1;
  bool flag_2;
  
  if (((flags == 199) && (val_1 = FUN_0048a33f(spell_id,target_id), val_1 != 0)) &&
     (3 < *(short *)(&DAT_006826d6 + target_id * 0x120 + spell_id * 0x5b20))) {
    if (spell_id == DAT_00676504) {
      DAT_0068f2d4 = DAT_0068f2d4 + 200;
    }
    else {
      DAT_0068f2d4 = DAT_0068f2d4 + -200;
    }
  }
  if (flags == 0x73) {
    flag_2 = (*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0;
  }
  else if (flags == 0x90) {
    FUN_0043071d(1);
    flag_2 = false;
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8c94,s_PSIONIC_ENTITY_004f8c84);
      FUN_00461047(spell_id,target_id);
      if (DAT_00681ea4 != 1) {
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      val_1 = FUN_004612b0(spell_id,target_id,0x72,2);
      if ((val_1 != 0) &&
         (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) != -1)) {
        FUN_004af950(DAT_00690af0,DAT_0068efa0,3,DAT_00690af0,DAT_0068efa0);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    flag_2 = false;
  }
  return flag_2;
}



/*
 * Decompiled function: FUN_004625ed
 * Entry Point: 004625ed
 * Size: 368 bytes
 */


int32_t FUN_004625ed(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int slot_idx;
  
  if (arg_3 == 0x73) {
    if (((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (val_1 = FUN_00467cce(arg_1,0x40), val_1 != 0)) {
      uval_2 = 1;
    }
    else {
      uval_2 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uval_2 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      val_1 = FUN_00468a84(arg_1);
      if (val_1 != 0) {
        if (slot_idx == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(short *)(&DAT_006826d8 + slot_idx * 0x120 + DAT_0068eef0 * 0x5b20) =
               *(short *)(&DAT_006826d8 + slot_idx * 0x120 + DAT_0068eef0 * 0x5b20) + 1;
          *(short *)(&DAT_006826da + slot_idx * 0x120 + DAT_0068eef0 * 0x5b20) =
               *(short *)(&DAT_006826da + slot_idx * 0x120 + DAT_0068eef0 * 0x5b20) + 1;
        }
      }
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_0046275d
 * Entry Point: 0046275d
 * Size: 382 bytes
 */


int32_t FUN_0046275d(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x77) &&
      (((&DAT_004ff594)
        [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] & 2) != 0))
     && (DAT_0066642c < 1)) {
    *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) +
         (short)*(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) +
         (short)*(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: FUN_004628db
 * Entry Point: 004628db
 * Size: 385 bytes
 */


int32_t FUN_004628db(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t slot_idx;
  
  if ((arg_3 == 0x73) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
    slot_idx = FUN_004593fd(arg_1,arg_2,0x73,0,0);
    val_1 = FUN_004680fc(arg_1,arg_2);
    if (val_1 == 0) {
      slot_idx = 0;
    }
  }
  else if ((arg_3 == 0x6d) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
    slot_idx = FUN_004593fd(arg_1,arg_2,0x6d,0,0);
    FUN_0046801f(arg_1,arg_2,1);
  }
  else if ((arg_3 == 0x72) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
    slot_idx = FUN_004593fd(arg_1,arg_2,0x72,0,0);
  }
  else {
    if (((DAT_0068f230 == 0xcd) || (arg_3 == 199)) &&
       ((((arg_2 == DAT_00690c48 && (arg_1 == DAT_0068ecb0)) && (DAT_0068eeac != 0)) &&
        (DAT_00681ec4 == arg_1)))) {
      if (arg_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        FUN_00467f65(arg_1,arg_2,DAT_0068eeac);
      }
    }
    slot_idx = 0;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_00462a5c
 * Entry Point: 00462a5c
 * Size: 1614 bytes
 */


int32_t FUN_00462a5c(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int match_count;
  int slot_idx;
  
  if (((((arg_3 == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == DAT_0068f104)) &&
       (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) &&
      ((*(int *)(&DAT_006826ec + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2 &&
       ((char)(&DAT_006826d3)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1)))) &&
     ((*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != -1 &&
      ((((&DAT_004ff594)
         [*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] * 0x5b20) *
          0x34] & 2) != 0 && (*(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) < 0x13))))))
  {
    *(int32_t *)
     (&DAT_0068271c +
     arg_2 * 0x120 + arg_1 * 0x5b20 + *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 8)
         = *(int32_t *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20);
    *(int *)(&DAT_00682718 +
            arg_2 * 0x120 +
            arg_1 * 0x5b20 + *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 8) =
         (int)(char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20];
    *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
  }
  if (arg_3 == 0x77) {
    flag_1 = false;
    for (slot_idx = 0; slot_idx < *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
        slot_idx = slot_idx + 1) {
      if (((*(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20 + slot_idx * 8) == DAT_00690c48)
          && (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20 + slot_idx * 8) == DAT_0068ecb0
             )) && ((&DAT_006826e0)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] != '\x04')) {
        match_count = slot_idx;
        if (!flag_1) {
          *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
          flag_1 = true;
        }
        while (match_count = match_count + 1,
              match_count < *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20)) {
          *(int32_t *)(&DAT_00682710 + arg_2 * 0x120 + arg_1 * 0x5b20 + match_count * 8) =
               *(int32_t *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20 + match_count * 8);
          *(int32_t *)(&DAT_00682714 + arg_2 * 0x120 + arg_1 * 0x5b20 + match_count * 8) =
               *(int32_t *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20 + match_count * 8);
        }
        *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) + -1;
      }
    }
  }
  if (((DAT_0068f230 == 0xd5) && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) &&
     ((DAT_00681ec4 == arg_1 && ((arg_2 == DAT_00690c48 && (arg_1 == DAT_0068ecb0)))))) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      FUN_00467f65(arg_1,arg_2,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20));
      *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826d8 + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(short *)(&DAT_006826da + arg_2 * 0x120 + arg_1 * 0x5b20) +
           (short)*(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    *(int32_t *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: FUN_004630aa
 * Entry Point: 004630aa
 * Size: 270 bytes
 */


int32_t FUN_004630aa(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x85) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     ((arg_1 == DAT_00666458 && (arg_1 == DAT_00681eb4)))) {
    *(uint32_t *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint32_t *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) | 1;
    (&DAT_006827d9)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006827d9)[arg_1 * 0x5b20 + arg_2 * 0x120] + '\x02';
  }
  if (arg_3 == 0x86) {
    FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
  }
  if ((arg_3 == 199) && ((int)(&DAT_0068ef54)[arg_1 * 8] < 2)) {
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}



/*
 * Decompiled function: FUN_004631b8
 * Entry Point: 004631b8
 * Size: 269 bytes
 */


int32_t FUN_004631b8(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x85) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     ((arg_1 == DAT_00666458 && (DAT_00681eb4 == arg_1)))) {
    *(uint32_t *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    (&DAT_006827da)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827da)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x01';
  }
  if (arg_3 == 0x86) {
    FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
  }
  if ((arg_3 == 199) && ((int)(&DAT_0068ef58)[arg_1 * 8] < 1)) {
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004e1b38
 * Entry Point: 004632c5
 * Size: 340 bytes
 */


int32_t Glue_Subsystem_004e1b38(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int val_2;
  
  if (((arg_3 == 0x15) && (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 4) != 0)) &&
     (*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) == 0)) {
    *(int32_t *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
    flag_1 = false;
    val_2 = FUN_0049b309(arg_1,7,2);
    if (val_2 != 0) {
      val_2 = Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Pay_2_mana__Lose_3_life__004f8ca0,0);
      if (val_2 == 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,0,2);
        if (DAT_00681ea4 == 1) {
          DAT_00681ea4 = -1;
        }
        else {
          flag_1 = true;
        }
      }
    }
    if (!flag_1) {
      Mem_AllocOrFree_004afd1c(arg_1,3,arg_1,arg_2);
    }
  }
  if (arg_3 == 0x22) {
    *(int32_t *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00463419
 * Entry Point: 00463419
 * Size: 266 bytes
 */


int32_t FUN_00463419(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x15) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) != 0)) &&
     (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
    val_1 = FUN_00439892(2);
    if (val_1 != 0) {
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffb;
    }
  }
  if (arg_3 == 0x22) {
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00463523
 * Entry Point: 00463523
 * Size: 213 bytes
 */


int32_t FUN_00463523(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x1a) && (arg_1 != DAT_00666458)) &&
     ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
    val_1 = FUN_00439892(2);
    if (val_1 != 0) {
      (&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
    }
  }
  if (arg_3 == 0x22) {
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: FUN_004635f8
 * Entry Point: 004635f8
 * Size: 161 bytes
 */


int32_t FUN_004635f8(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0066642c = DAT_0066642c | 2;
  }
  if (((((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) || (arg_3 == 199)) &&
     ((int)(&DAT_00681ea8)[arg_1] < (int)(&DAT_00681ea8)[1 - arg_1])) {
    FUN_004bf853(arg_1,arg_2);
  }
  return 0;
}



/*
 * Decompiled function: FUN_00463699
 * Entry Point: 00463699
 * Size: 190 bytes
 */


int32_t FUN_00463699(int arg1,int arg2)

{
  if (((char)(&DAT_006826d2)[arg2 * 0x120 + arg1 * 0x5b20] == DAT_00522424) &&
     (*(int *)(&DAT_006826e8 + arg2 * 0x120 + arg1 * 0x5b20) == DAT_00522414)) {
    *(int32_t *)(&DAT_006826e8 + arg2 * 0x120 + arg1 * 0x5b20) = DAT_00522410;
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004e1fcb
 * Entry Point: 00463757
 * Size: 310 bytes
 */


int32_t Glue_Subsystem_004e1fcb(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x85) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     ((arg_1 == DAT_00666458 && (DAT_00681eb4 == arg_1)))) {
    *(uint32_t *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    (&DAT_006827db)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827db)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x04';
  }
  if (arg_3 == 0x86) {
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Force_of_Nature_deals_8_damage__004f8cbc,0);
    Mem_AllocOrFree_004afd1c(arg_1,8,DAT_00690af0,DAT_0068efa0);
  }
  if ((arg_3 == 199) && (*(int *)(&DAT_0068ef5c + arg_1 * 0x20) < 4)) {
    Mem_AllocOrFree_004afd1c(arg_1,8,arg_1,arg_2);
  }
  return 0;
}



/*
 * Decompiled function: FUN_0046388d
 * Entry Point: 0046388d
 * Size: 433 bytes
 */


bool FUN_0046388d(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  
  if (arg_3 == 0x73) {
    flag_1 = (*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0;
  }
  else {
    if ((arg_3 == 0x6d) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      FUN_0049b2c1(arg_1,3,1);
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_0068f0f4 = 3;
    }
    if ((((arg_3 == 0x7f) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
       ((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      FUN_0049b1a9(arg_1,3,1);
    }
    if (((arg_3 == 0x8a) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c +
                     (int)(0x18 / (longlong)(*(int *)(&DAT_0068ef5c + arg_1 * 0x20) + 2));
    }
    if (((arg_3 == 0x8b) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c -
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0068ef5c + arg_1 * 0x20) + 2));
    }
    flag_1 = false;
  }
  return flag_1;
}



/*
 * Decompiled function: Glue_Subsystem_004e22b2
 * Entry Point: 00463a3e
 * Size: 988 bytes
 */


bool Glue_Subsystem_004e22b2(int spell_id,int target_id,int flags)

{
  int card_slot;
  uint32_t *arg2;
  bool flag_1;
  int card_idx;
  int match_count;
  
  if (flags == 0x73) {
    flag_1 = (*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0;
  }
  else {
    if ((flags == 0x6d) && (((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) {
      if ((spell_id == 1) || ((DAT_0066aaf4 == 1 || (DAT_0068f0b0 != 0)))) {
        card_idx = -1;
        match_count = 1;
        while ((match_count < 6 && (card_idx == -1))) {
          if ((0 < (&DAT_0068ece0)[match_count]) &&
             (((int)(char)(&DAT_006826dc)[spell_id * 0x5b20 + target_id * 0x120] &
              1 << ((uint8_t)match_count & 0x1f)) != 0)) {
            card_idx = match_count;
          }
          match_count = match_count + 1;
        }
        if ((card_idx == -1) && (0 < DAT_0068ece0)) {
          card_idx = 1;
        }
        if ((card_idx == -1) && (0 < DAT_0068ecf8)) {
          card_idx = 1;
        }
        if (card_idx == -1) {
          DAT_00681ea4 = 1;
        }
      }
      else {
        card_idx = -1;
      }
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f8cf0,s_BIRDS_OF_PARADISE_004f8cdc);
        arg_2 = FUN_004513fa(spell_id,&DAT_006679f0,1,card_idx,
                             (int)(char)(&DAT_006826dc)[spell_id * 0x5b20 + target_id * 0x120]);
        if (arg_2 == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_0049b235(spell_id,arg_2,1);
          FUN_0049b00c(spell_id,(int)(char)(&DAT_006826dc)[spell_id * 0x5b20 + target_id * 0x120],1)
          ;
          *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
               *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
          DAT_0068f0f4 = arg_2;
          if (spell_id != DAT_00676510) {
            Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_to_produce_004f8cfc);
            arg2 = (uint32_t *)Mem_AllocOrFree_0048c420(arg_2);
            FUN_004d9640((uint32_t *)&DAT_005f6810,arg2);
            FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_mana__004f8d08);
            Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&DAT_005f6810,0);
          }
        }
      }
    }
    if ((((flags == 0x7f) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) &&
       ((*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0)) {
      FUN_0049af5c(spell_id,(int)(char)(&DAT_006826dc)[spell_id * 0x5b20 + target_id * 0x120],1);
    }
    if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c +
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0068ef6c + spell_id * 0x20) + 2));
    }
    if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c -
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0068ef6c + spell_id * 0x20) + 2));
    }
    flag_1 = false;
  }
  return flag_1;
}



/*
 * Decompiled function: Glue_Subsystem_004e268e
 * Entry Point: 00463e1a
 * Size: 435 bytes
 */


int32_t Glue_Subsystem_004e268e(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x85) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     ((arg_1 == DAT_00666458 && (DAT_00681eb4 == arg_1)))) {
    *(uint32_t *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    (&DAT_006827d9)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827d9)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x03';
    (&DAT_006827d8)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827d8)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x03';
  }
  if (arg_3 == 0x86) {
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Cosmic_Horror_deals_7_damage__004f8d10,0);
    Mem_AllocOrFree_004afd1c(arg_1,7,DAT_00690af0,DAT_0068efa0);
    FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
  }
  if ((arg_3 == 199) &&
     (((int)(&DAT_0068ef54)[arg_1 * 8] < 3 || (*(int *)(&DAT_0068ef6c + arg_1 * 0x20) < 6)))) {
    Mem_AllocOrFree_004afd1c(arg_1,7,arg_1,arg_2);
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004e2841
 * Entry Point: 00463fcd
 * Size: 856 bytes
 */


int32_t Glue_Subsystem_004e2841(int spell_id,int target_id,int flags)

{
  int val_1;
  
  if ((((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) &&
     (*(int *)(&DAT_0068ee80 + spell_id * 4) < 2)) {
    DAT_0068f2d4 = DAT_0068f2d4 + -0xa8;
  }
  if (flags == 0x87) {
    val_1 = FUN_00464325(spell_id,target_id);
    if (val_1 == 0) {
      DAT_0066642c = DAT_0066642c | 1;
    }
  }
  if ((((flags == 0x85) && (target_id == DAT_00690c48)) &&
      ((spell_id == DAT_0068ecb0 &&
       ((*(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) == 0 &&
        (spell_id == DAT_00666458)))))) && (DAT_00681eb4 == spell_id)) {
    *(uint32_t *)(&DAT_006827d4 + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint32_t *)(&DAT_006827d4 + target_id * 0x120 + spell_id * 0x5b20) | 0x101;
    val_1 = FUN_00464325(spell_id,target_id);
    if (val_1 == 0) {
      DAT_0068f2c0 = DAT_0068f2c0 + 1;
    }
  }
  if (((flags == 4) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) =
         *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) + 1;
    val_1 = FUN_00464325(spell_id,target_id);
    if (val_1 == 0) {
      DAT_0066642c = DAT_0066642c | 1;
    }
    else {
      *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x100000;
      FUN_00451482(0,0x20);
      FUN_00434660(s_prompts_txt_004f8d40,s_LORD_OF_THE_PIT_004f8d30);
      val_1 = FUN_00468383(spell_id);
      *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0xffefffff;
      FUN_0046e571(spell_id,val_1,3);
    }
  }
  if (flags == 0x86) {
    Ai_Subsystem_004cc56d
              (spell_id,spell_id,target_id,-1,-1,s_Lord_of_the_Pit_deals_7_damage__004f8d4c,0);
    Mem_AllocOrFree_004afd1c(spell_id,7,DAT_00690af0,DAT_0068efa0);
  }
  if (flags == 199) {
    val_1 = FUN_00464325(spell_id,target_id);
    if (val_1 == 0) {
      Mem_AllocOrFree_004afd1c(spell_id,7,DAT_00690af0,DAT_0068efa0);
    }
  }
  if (((flags == 0x22) || (flags == 199)) &&
     ((target_id == DAT_00690c48 && (spell_id == DAT_0068ecb0)))) {
    *(int32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
  }
  if (((flags == 0x8a) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    DAT_0069340c = DAT_0069340c + -0x30;
  }
  if (((flags == 0x8b) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    DAT_0069340c = DAT_0069340c + 0x30;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00464325
 * Entry Point: 00464325
 * Size: 230 bytes
 */


int FUN_00464325(int arg1,int arg2)

{
  int match_count;
  int slot_idx;
  
  match_count = 0;
  slot_idx = 0;
  while ((match_count < (int)(&DAT_00666408)[arg1] && (slot_idx == 0))) {
    if ((((*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + match_count * 0x120) != -1) &&
         (((&DAT_006826cc)[arg1 * 0x5b20 + match_count * 0x120] & 2) != 0)) &&
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + match_count * 0x120) * 0x34] & 2) !=
         0)) && (match_count != arg2)) {
      slot_idx = 1;
    }
    match_count = match_count + 1;
  }
  return slot_idx;
}



/*
 * Decompiled function: Glue_Subsystem_004e2c7f
 * Entry Point: 0046440b
 * Size: 873 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Glue_Subsystem_004e2c7f(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  int match_count;
  
  if (arg_3 == 0x73) {
    if (((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (((*(uint32_t *)(&DAT_0066aad0 + (1 - arg_1) * 4) | _DAT_0066aad0) & 1) != 0)) {
      uval_2 = 1;
    }
    else {
      uval_2 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uval_2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) &&
       ((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      if (match_count == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)DAT_0068eef0;
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = match_count;
      }
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      FUN_0046e571((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      *(int32_t *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) || (arg_3 == 199)) {
      flag_1 = false;
      val_3 = FUN_0049b309(arg_1,1,3);
      if ((val_3 != 0) &&
         (val_3 = Ai_Subsystem_004cc56d
                            (arg_1,arg_1,arg_2,-1,-1,s_Pay_mana__Sacrifice_Land__004f8d6c,0),
         val_3 == 0)) {
        Ai_CalcManaRequirement_004ba890(arg_1,1,3);
        if (DAT_00681ea4 == 1) {
          DAT_00681ea4 = -1;
        }
        else {
          flag_1 = true;
        }
      }
      if ((arg_3 == 199) && (val_3 = FUN_0049b309(arg_1,1,3), val_3 != 0)) {
        flag_1 = true;
      }
      if ((!flag_1) && (val_3 = FUN_00467cce(arg_1,1), val_3 != 0)) {
        do {
        } while (match_count == -1);
        FUN_0046e571(DAT_0068eef0,match_count,3);
        *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00464774
 * Entry Point: 00464774
 * Size: 315 bytes
 */


int32_t FUN_00464774(int player_id,int card_slot,int event_type)

{
  if ((DAT_00690c48 == arg_2) && (arg_1 == DAT_0068ecb0)) {
    *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffcffff;
  }
  if (arg_3 == 199) {
    FUN_0046e571(arg_1,arg_2,1);
  }
  if ((((DAT_0068f230 == 0xcd) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) &&
     (arg_1 == DAT_00681ec4)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x7e) {
      FUN_0046e571(arg_1,arg_2,1);
    }
  }
  if (((arg_3 == 0x8a) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0069340c = DAT_0069340c + -0x3c;
  }
  if (((arg_3 == 0x8b) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0069340c = DAT_0069340c + 0x3c;
  }
  return 0;
}



/*
 * Decompiled function: FUN_004648af
 * Entry Point: 004648af
 * Size: 93 bytes
 */


int32_t FUN_004648af(int player_id,int card_slot,int event_type)

{
  if (((arg_3 == 0x77) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    (&DAT_006826e0)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] = 4;
  }
  return 0;
}



/*
 * Decompiled function: FUN_0046490c
 * Entry Point: 0046490c
 * Size: 364 bytes
 */


int32_t FUN_0046490c(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffcffff;
  }
  if ((arg_3 == 0x8d) ||
     (((arg_3 == 0x77 && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 &&
       ((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x20) == 0 &&
        ((&DAT_006826e0)[arg_1 * 0x5b20 + arg_2 * 0x120] != '\x04')))))))) {
    val_1 = Deck_AddCardToDeck(arg_1,DAT_0066aafc);
    if (val_1 != -1) {
      *(uint32_t *)(&DAT_006826cc + val_1 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + val_1 * 0x120 + arg_1 * 0x5b20) | 2;
      *(int32_t *)(&DAT_00682704 + val_1 * 0x120 + arg_1 * 0x5b20) =
           *(int32_t *)
            (&DAT_004ff590 + *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34);
    }
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004e32f3
 * Entry Point: 00464a78
 * Size: 497 bytes
 */


int32_t Glue_Subsystem_004e32f3(int player_id,int card_slot,int event_type)

{
  int val_1;
  int player_idx;
  int match_count;
  
  if (((((DAT_0068f230 == 0xcb) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 && (arg_1 == DAT_00666458)))) && (DAT_00681ec4 == arg_1)) {
    val_1 = FUN_004d7d5e(0xab);
    player_idx = 0;
    for (match_count = 499; -1 < match_count; match_count = match_count + -1) {
      if (((*(int *)(&DAT_0068f370 + match_count * 4 + arg_1 * 2000) != -1) &&
          (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + match_count * 4 + arg_1 * 2000) * 0x34] & 2) != 0))
         && ((player_idx = player_idx + 1, *(int *)(&DAT_0068f370 + match_count * 4 + arg_1 * 2000) == val_1
             && (3 < player_idx)))) {
        if (arg_3 == 0x7d) {
          DAT_0066642c = DAT_0066642c | 1;
        }
        if ((arg_3 != 0x7e) && (arg_3 != 199)) {
          return 0;
        }
        val_1 = Deck_AddCardToDeck(arg_1,val_1);
        if (val_1 == -1) {
          return 0;
        }
        Pic_Subsystem_0042ac1f(arg_1,val_1);
        *(uint32_t *)(&DAT_006826cc + val_1 * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + val_1 * 0x120 + arg_1 * 0x5b20) & 0xfffcffff;
        FUN_0046f116(arg_1,match_count);
        FUN_0046e571(arg_1,arg_2,4);
        FUN_00451482(0,0x30);
        Ai_Subsystem_004cc56d(arg_1,arg_1,val_1,-1,-1,s_is_returning_from_the_grave__004f8d88,0);
        return 0;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00464c69
 * Entry Point: 00464c69
 * Size: 127 bytes
 */


int32_t FUN_00464c69(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  char cVar2;
  
  if (((arg_3 == 0x34) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    cVar2 = FUN_004af7bb(arg_1,arg_2,1);
    DAT_0066642c = DAT_0066642c | 0x800 << (cVar2 - 1U & 0x1f);
    uval_1 = DAT_0066642c;
    FUN_00464d69(arg_1,arg_2,1);
    DAT_0066642c = uval_1;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00464ce8
 * Entry Point: 00464ce8
 * Size: 129 bytes
 */


int32_t FUN_00464ce8(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  char cVar2;
  
  if (((arg_3 == 0x34) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    cVar2 = FUN_004af7bb(arg_1,arg_2,5);
    DAT_0066642c = DAT_0066642c | 0x800 << (cVar2 - 1U & 0x1f);
    uval_1 = DAT_0066642c;
    FUN_00464d69(arg_1,arg_2,5);
    DAT_0066642c = uval_1;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00464d69
 * Entry Point: 00464d69
 * Size: 332 bytes
 */


void FUN_00464d69(int player_id,int card_slot,int event_type)

{
  char cVar1;
  uint8_t flag_2;
  int val_3;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < (int)(&DAT_00666408)[slot_idx]; match_count = match_count + 1) {
      val_3 = FUN_0048a33f(slot_idx,match_count);
      if (((val_3 != 0) && ((char)(&DAT_006826d2)[match_count * 0x120 + slot_idx * 0x5b20] == arg_1)) &&
         (*(int *)(&DAT_006826e8 + match_count * 0x120 + slot_idx * 0x5b20) == arg_2)) {
        cVar1 = (&DAT_006826dd)[match_count * 0x120 + slot_idx * 0x5b20];
        flag_2 = FUN_004af7bb(arg_1,arg_2,arg_3);
        if (((1 << (flag_2 & 0x1f) & (int)cVar1) != 0) &&
           (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] &
            4) != 0)) {
          FUN_0046e571(slot_idx,match_count,1);
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00464eb5
 * Entry Point: 00464eb5
 * Size: 90 bytes
 */


int32_t FUN_00464eb5(int player_id,int card_slot,int event_type)

{
  char cVar1;
  
  if (((arg_3 == 0x34) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    cVar1 = FUN_004af7bb(arg_1,arg_2,4);
    DAT_0066642c = DAT_0066642c | 0x800 << (cVar1 - 1U & 0x1f);
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004e378b
 * Entry Point: 00464f0f
 * Size: 970 bytes
 */


int32_t Glue_Subsystem_004e378b(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  int val_2;
  int slot_idx;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00681ea0;
  }
  if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 && (val_2 = FUN_0049b309(arg_1,4,3), val_2 != 0)))) {
    DAT_0066642c = DAT_0066642c | 1;
  }
  if ((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) {
    if ((arg_3 == 0x32) || (arg_3 == 0x33)) {
      DAT_0066642c = DAT_0066642c + *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    if ((((arg_3 == 0x6e) &&
         ((char)(&DAT_006826d2)[DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20] == arg_1)) &&
        (*(int *)(&DAT_006826e8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) == arg_2)) &&
       (*(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) != 0)) {
      for (slot_idx = 0;
          slot_idx < *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20);
          slot_idx = slot_idx + 1) {
        flag_1 = false;
        val_2 = FUN_0049b309(arg_1,4,1);
        if ((val_2 != 0) &&
           (val_2 = Ai_Subsystem_004cc56d
                              (arg_1,arg_1,arg_2,-1,-1,s_Restore_Hydra_Head__Never_mind__004f8da8,0)
           , val_2 == 0)) {
          Ai_CalcManaRequirement_004ba890(arg_1,4,1);
          if (DAT_00681ea4 == 1) {
            DAT_00681ea4 = -1;
          }
          else {
            flag_1 = true;
          }
        }
        if (!flag_1) break;
        *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) =
             *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) + -1;
      }
      val_2 = FUN_0049aa14(*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20),0,
                           *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20));
      *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) - val_2;
      *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) =
           *(int *)(&DAT_006826e4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) - val_2;
    }
    if (((arg_3 == 4) && (arg_2 == DAT_00690c48)) &&
       ((arg_1 == DAT_0068ecb0 &&
        ((val_2 = FUN_0049b309(arg_1,4,3), val_2 != 0 &&
         (val_2 = Ai_Subsystem_004cc56d
                            (arg_1,arg_1,arg_2,-1,-1,s_Grow_new_Hydra_head__Never_mind__004f8dcc,0),
         val_2 == 0)))))) {
      Ai_CalcManaRequirement_004ba890(arg_1,4,3);
      if (DAT_00681ea4 == 1) {
        DAT_00681ea4 = -1;
      }
      else {
        *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004e3b55
 * Entry Point: 004652d9
 * Size: 753 bytes
 */


int32_t Glue_Subsystem_004e3b55(int spell_id,int target_id,int flags)

{
  int val_1;
  int32_t uval_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    val_1 = FUN_0049b309(spell_id,4,1);
    if (val_1 != 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 1;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_2 = FUN_004521e2(spell_id,target_id);
      val_1 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_1 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (((flags == 0x6d) && (val_1 = FUN_0049b309(spell_id,4,1), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,4,1), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f8df8,s_ALIBABA_004f8df0);
      arg_20 = &match_count;
      uval_2 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_1 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_1,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_2,arg_20);
      if (val_1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 1;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_1 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_1 = Rules_ParseFilter_0041c0ab
                        (match_count,slot_idx,(uint8_t *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_4,
                         uval_5,val_1,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826cc + match_count * 0x5b20 + slot_idx * 0x120) =
             *(uint32_t *)(&DAT_006826cc + match_count * 0x5b20 + slot_idx * 0x120) | 0x10;
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004e3e46
 * Entry Point: 004655ca
 * Size: 766 bytes
 */


int32_t Glue_Subsystem_004e3e46(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    if ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_1 = FUN_004521e2(spell_id,target_id);
      val_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,1,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if (flags == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8e10,s_LEY_DRUID_004f8e04);
      arg_20 = &match_count;
      uval_1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,spell_id,0x200,1,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,uval_8,
                         uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = match_count;
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x72) {
      match_count = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      slot_idx = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Rules_ParseFilter_0041c0ab
                        (match_count,slot_idx,(uint8_t *)0x0,spell_id,2,2,0x200,1,0,0,uval_3,uval_4,
                         uval_5,val_2,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826cc + match_count * 0x5b20 + slot_idx * 0x120) =
             *(uint32_t *)(&DAT_006826cc + match_count * 0x5b20 + slot_idx * 0x120) & 0xffffffef;
        FUN_0048c907(match_count,slot_idx,1,0xffffffff,0xffffffff);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004658c8
 * Entry Point: 004658c8
 * Size: 355 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t FUN_004658c8(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  int slot_idx;
  
  if (arg_3 == 0x73) {
    if ((*(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x20010) == 0) {
      if (arg_1 == DAT_00676510) {
        uval_1 = (DAT_0066aad4 | _DAT_0066aad0) & 0x40;
      }
      else {
        uval_1 = *(uint32_t *)(&DAT_0066aad0 + DAT_00676510 * 4) & 0x40;
      }
    }
    else {
      uval_1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uval_1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      if (slot_idx == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826cc +
                 *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                 *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) =
             *(uint32_t *)(&DAT_006826cc +
                      *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                      *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) | 0x10;
        (&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] = (uint8_t)DAT_0068eef0;
        *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) = slot_idx;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00465a30
 * Entry Point: 00465a30
 * Size: 604 bytes
 */


int32_t FUN_00465a30(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    val_1 = FUN_00468130(arg_1,0xffffffff,arg_2);
    if (val_1 == 0) {
      FUN_0046e571(arg_1,arg_2,1);
      DAT_00681ea4 = 1;
    }
  }
  if ((arg_3 == 0x71) && (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
    (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_00682718)[arg_2 * 0x120 + arg_1 * 0x5b20];
    *(int32_t *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int32_t *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(int32_t *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int32_t *)
          (&DAT_006826c4 +
          *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
          (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20);
    (&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_004ff596)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34];
    *(int32_t *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
    (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
    FUN_0048c907(arg_1,arg_2,0x6c,1 - arg_1,0xffffffff);
  }
  return 0;
}



/*
 * Decompiled function: Pic_Load_0042a1c9
 * Entry Point: 00465c8c
 * Size: 582 bytes
 */


void Pic_Load_0042a1c9(int player_id,int card_slot,int event_type)

{
  int val_1;
  int slot_idx;
  
  if (arg_3 == 0x73) {
    if ((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) {
      FUN_0049b309(arg_1,5,2);
    }
  }
  else if (((arg_3 == 0x6d) && (val_1 = FUN_0049b309(arg_1,5,2), val_1 != 0)) &&
          (Ai_CalcManaRequirement_004ba890(arg_1,5,2), DAT_00681ea4 != 1)) {
    if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
      do {
        slot_idx = Palette_Subsystem_004a5722
                            (arg_1,(int *)(&DAT_0068f370 + arg_1 * 2000),500,
                             s_Pick_an_artifact_004f8e24,0,s_Cancel_004f8e1c);
        if (slot_idx == -1) break;
      } while (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + slot_idx * 4 + arg_1 * 2000) * 0x34] & 0x40)
               == 0);
    }
    else {
      slot_idx = FUN_0040800f(arg_1,0x40);
    }
    if (((slot_idx == -1) || (*(int *)(&DAT_0068f370 + slot_idx * 4 + arg_1 * 2000) == -1)) ||
       (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + slot_idx * 4 + arg_1 * 2000) * 0x34] & 0x40) == 0))
    {
      DAT_00681ea4 = 1;
    }
    else {
      val_1 = Deck_AddCardToDeck(arg_1,*(int *)(&DAT_0068f370 + slot_idx * 4 + arg_1 * 2000));
      if (val_1 != -1) {
        *(int32_t *)(&DAT_0068f370 + slot_idx * 4 + arg_1 * 2000) = 0xffffffff;
      }
    }
    if (DAT_00681ea4 != 1) {
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00465ed2
 * Entry Point: 00465ed2
 * Size: 185 bytes
 */


void FUN_00465ed2(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if ((arg_3 != 0x73) && (arg_3 == 0x6d)) {
    val_1 = FUN_00468a84(arg_1);
    if (val_1 == 0) {
      DAT_00681ea4 = 1;
    }
    else {
      FUN_00487ce1(arg_1);
    }
    *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
  }
  return;
}



/*
 * Decompiled function: Glue_Subsystem_004e4807
 * Entry Point: 00465f8b
 * Size: 1959 bytes
 */


int32_t Glue_Subsystem_004e4807(int spell_id,int target_id,int flags)

{
  char cVar1;
  int32_t uval_2;
  int val_3;
  uint32_t arg_11;
  int32_t arg_11_00;
  uint32_t arg_12;
  int32_t arg_12_00;
  uint32_t arg_13;
  int32_t arg_13_00;
  int32_t arg_14;
  int val_4;
  int32_t arg_15;
  uint32_t arg_16;
  int32_t arg_16_00;
  uint32_t arg_17;
  int32_t arg_17_00;
  uint32_t arg_18;
  int32_t arg_18_00;
  uint32_t arg_19;
  int32_t arg_19_00;
  uint32_t arg_20;
  int target_idx;
  int card_idx;
  
  if (((flags == 0x3c) && (*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) != -1))
     && ((&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] != -1)) {
    (&DAT_006827df)
    [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
     (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] =
         (&DAT_006827df)
         [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
          (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] | 0x3f;
  }
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uval_2 = FUN_004521e2(spell_id,target_id);
    uval_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_2,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_2 = 0;
  }
  else {
    if (((flags == 0x6c) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_004f8e40,s_VENOM_004f8e38);
      val_3 = FUN_00468130(spell_id,spell_id,target_id);
      if (val_3 == 0) {
        DAT_00681ea4 = 1;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      val_4 = -1;
      val_3 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(spell_id,target_id);
      val_3 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120),
                         (uint8_t *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_3,val_4
                         ,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] =
             (&DAT_00682718)[spell_id * 0x5b20 + target_id * 0x120];
        *(int32_t *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) =
             *(int32_t *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (flags == 0x1a) {
      val_3 = 1 - (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120];
      if (((char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] == DAT_00666458) &&
         (((&DAT_006826cc)
           [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
            (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] & 0x44) != 0)) {
        if ((&DAT_006826de)
            [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
             (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] == -1) {
          target_idx = *(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120);
        }
        else {
          target_idx = (int)(char)(&DAT_006826de)
                                [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) *
                                 0x120 + (char)(&DAT_006826d2)
                                               [spell_id * 0x5b20 + target_id * 0x120] * 0x5b20];
        }
        for (card_idx = 0; card_idx < (int)(&DAT_00666408)[val_3]; card_idx = card_idx + 1) {
          if ((((char)(&DAT_006826de)[val_3 * 0x5b20 + card_idx * 0x120] == target_idx) &&
              ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + val_3 * 0x5b20 + card_idx * 0x120) * 0x34]
               != '\0')) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + val_3 * 0x5b20 + card_idx * 0x120) * 0x34] &
              2) != 0)) {
            FUN_004a2b00(spell_id,target_id,DAT_006764c0,val_3,card_idx);
          }
        }
      }
      if (((char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] != DAT_00666458) &&
         ((&DAT_006826de)
          [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
           (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] != -1)) {
        cVar1 = (&DAT_006826de)
                [val_3 * 0x5b20 +
                 (char)(&DAT_006826de)
                       [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                        (char)(&DAT_006826d2)[spell_id * 0x5b20 + target_id * 0x120] * 0x5b20] *
                 0x120];
        if (cVar1 == -1) {
          FUN_004a2b00(spell_id,target_id,DAT_006764c0,val_3,
                       (int)(char)(&DAT_006826de)
                                  [*(int *)(&DAT_006826e8 + spell_id * 0x5b20 + target_id * 0x120) *
                                   0x120 + (char)(&DAT_006826d2)
                                                 [spell_id * 0x5b20 + target_id * 0x120] * 0x5b20]);
        }
        else {
          for (card_idx = 0; card_idx < (int)(&DAT_00666408)[val_3]; card_idx = card_idx + 1) {
            val_4 = FUN_0048a33f(val_3,card_idx);
            if ((val_4 != 0) && ((&DAT_006826de)[val_3 * 0x5b20 + card_idx * 0x120] == cVar1)) {
              FUN_004a2b00(spell_id,target_id,DAT_006764c0,val_3,card_idx);
            }
          }
        }
      }
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00466732
 * Entry Point: 00466732
 * Size: 992 bytes
 */


int32_t FUN_00466732(int player_id,int card_slot,int event_type)

{
  char cVar1;
  int arg1;
  int val_2;
  int target_idx;
  int card_idx;
  
  if (arg_3 == 0x3c) {
    (&DAT_006827df)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827df)[arg_2 * 0x120 + arg_1 * 0x5b20] | 0x3f;
  }
  if (arg_3 == 0x1a) {
    arg1 = 1 - arg_1;
    if ((arg_1 == DAT_00666458) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x44) != 0))
    {
      if ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] == -1) {
        target_idx = arg_2;
      }
      else {
        target_idx = (int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20];
      }
      for (card_idx = 0; card_idx < (int)(&DAT_00666408)[arg1]; card_idx = card_idx + 1) {
        if ((((char)(&DAT_006826de)[arg1 * 0x5b20 + card_idx * 0x120] == target_idx) &&
            ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + card_idx * 0x120) * 0x34] !=
             '\0')) &&
           (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + card_idx * 0x120) * 0x34] & 2)
            != 0)) {
          FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,card_idx);
        }
      }
    }
    if ((arg_1 != DAT_00666458) && ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
      cVar1 = (&DAT_006826de)
              [arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120];
      if (cVar1 == -1) {
        if (((&DAT_004ff595)
             [*(int *)(&DAT_006826c4 +
                      arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120)
              * 0x34] != '\0') &&
           (((&DAT_004ff594)
             [*(int *)(&DAT_006826c4 +
                      arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120)
              * 0x34] & 2) != 0)) {
          FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,
                       (int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20]);
        }
      }
      else {
        for (card_idx = 0; card_idx < (int)(&DAT_00666408)[arg1]; card_idx = card_idx + 1) {
          val_2 = FUN_0048a33f(arg1,card_idx);
          if (((val_2 != 0) && ((&DAT_006826de)[arg1 * 0x5b20 + card_idx * 0x120] == cVar1)) &&
             (((&DAT_004ff595)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + card_idx * 0x120) * 0x34] !=
               '\0' && (((&DAT_004ff594)
                         [*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + card_idx * 0x120) * 0x34] & 2) !=
                        0)))) {
            FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,card_idx);
          }
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00466b12
 * Entry Point: 00466b12
 * Size: 583 bytes
 */


int32_t FUN_00466b12(int player_id,int card_slot,int event_type)

{
  char cVar1;
  int arg1;
  int val_2;
  int match_count;
  
  if ((((arg_3 == 0x1a) && (arg1 = 1 - arg_1, arg_1 != DAT_00666458)) &&
      ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) &&
     (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    cVar1 = (&DAT_006826de)
            [arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120];
    if (cVar1 == -1) {
      FUN_004a2b00(arg_1,arg_2,DAT_0068ed08,arg1,
                   (int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20]);
      *(uint32_t *)(&DAT_006826f8 +
               arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120) =
           *(uint32_t *)(&DAT_006826f8 +
                    arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120) |
           0x8000;
    }
    else {
      for (match_count = 0; match_count < (int)(&DAT_00666408)[arg1]; match_count = match_count + 1) {
        val_2 = FUN_0048a33f(arg1,match_count);
        if ((val_2 != 0) && ((&DAT_006826de)[match_count * 0x120 + arg1 * 0x5b20] == cVar1)) {
          FUN_004a2b00(arg_1,arg_2,DAT_0068ed08,arg1,match_count);
          *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + arg1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + arg1 * 0x5b20) | 0x8000;
        }
      }
    }
  }
  if (arg_3 == 0x22) {
    *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00466d59
 * Entry Point: 00466d59
 * Size: 568 bytes
 */


int32_t FUN_00466d59(int player_id,int card_slot,int event_type)

{
  char cVar1;
  int arg1;
  int val_2;
  int card_idx;
  
  arg1 = 1 - arg_1;
  if (((arg_3 == 0x77) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    if ((arg_1 == DAT_00666458) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x44) != 0))
    {
      for (card_idx = 0; card_idx < 0x50; card_idx = card_idx + 1) {
        if (((char)(&DAT_006826de)[card_idx * 0x120 + arg1 * 0x5b20] == arg_2) &&
           (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + card_idx * 0x120 + arg1 * 0x5b20) * 0x34] & 2)
            != 0)) {
          FUN_0046e571(arg1,card_idx,4);
        }
      }
    }
    if ((arg_1 != DAT_00666458) && ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
      cVar1 = (&DAT_006826de)
              [arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120];
      if (cVar1 == -1) {
        FUN_0046e571(arg1,(int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20],4);
      }
      else {
        for (card_idx = 0; card_idx < 0x50; card_idx = card_idx + 1) {
          val_2 = FUN_0048a33f(arg1,card_idx);
          if ((val_2 != 0) && ((&DAT_006826de)[card_idx * 0x120 + arg1 * 0x5b20] == cVar1)) {
            FUN_0046e571(arg1,card_idx,4);
          }
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00466f91
 * Entry Point: 00466f91
 * Size: 287 bytes
 */


bool FUN_00466f91(int player_id,int card_slot,int event_type)

{
  bool flag_1;
  
  if (arg_3 == 0x73) {
    flag_1 = (*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0;
  }
  else {
    if ((arg_3 == 0x6d) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      FUN_0049b2c1(arg_1,4,1);
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_0068f0f4 = 4;
    }
    if ((((arg_3 == 0x7f) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
       ((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      FUN_0049b1a9(arg_1,4,1);
    }
    flag_1 = false;
  }
  return flag_1;
}



/*
 * Decompiled function: FUN_004670b0
 * Entry Point: 004670b0
 * Size: 269 bytes
 */


int32_t FUN_004670b0(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  
  if (arg_3 == 0x73) {
    if (((*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (val_1 = FUN_0049b309(arg_1,2,1), val_1 != 0)) {
      uval_2 = 1;
    }
    else {
      uval_2 = 0;
    }
  }
  else {
    if ((((arg_3 == 0x6d) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) &&
        (val_1 = FUN_0049b309(arg_1,2,1), val_1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,2,1), DAT_00681ea4 != 1)) {
      FUN_0049b2c1(arg_1,0,3);
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_0068f0f4 = 0;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_004671bd
 * Entry Point: 004671bd
 * Size: 1026 bytes
 */


int32_t FUN_004671bd(int player_id,int card_slot,int event_type)

{
  char cVar1;
  uint8_t flag_2;
  uint8_t flag_3;
  uint8_t bVar4;
  int arg1;
  int val_5;
  uint32_t uval_6;
  int color_idx;
  int player_idx;
  
  arg1 = 1 - arg_1;
  if (arg_3 == 0x3c) {
    bVar4 = (&DAT_006827df)[arg_2 * 0x120 + arg_1 * 0x5b20];
    flag_2 = FUN_004af7bb(arg_1,arg_2,3);
    flag_3 = FUN_004af7bb(arg_1,arg_2,5);
    (&DAT_006827df)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         bVar4 | (uint8_t)(1 << (flag_2 & 0x1f)) | (uint8_t)(1 << (flag_3 & 0x1f)) | 0x80;
  }
  if (arg_3 == 0x1a) {
    bVar4 = FUN_004af7bb(arg_1,arg_2,3);
    flag_2 = FUN_004af7bb(arg_1,arg_2,5);
    uval_6 = 1 << (bVar4 & 0x1f) | 1 << (flag_2 & 0x1f);
    if ((arg_1 == DAT_00666458) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x44) != 0))
    {
      if ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] == -1) {
        color_idx = arg_2;
      }
      else {
        color_idx = (int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20];
      }
      for (player_idx = 0; player_idx < (int)(&DAT_00666408)[arg1]; player_idx = player_idx + 1) {
        if ((((char)(&DAT_006826de)[player_idx * 0x120 + arg1 * 0x5b20] == color_idx) &&
            (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + player_idx * 0x120 + arg1 * 0x5b20) * 0x34] & 2
             ) != 0)) &&
           ((uval_6 & (int)(char)(&DAT_006826dd)[player_idx * 0x120 + arg1 * 0x5b20]) != 0)) {
          FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,player_idx);
        }
      }
    }
    if ((arg_1 != DAT_00666458) && ((&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
      cVar1 = (&DAT_006826de)
              [arg1 * 0x5b20 + (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120];
      if (cVar1 == -1) {
        if ((uval_6 & (int)(char)(&DAT_006826dd)
                                [arg1 * 0x5b20 +
                                 (char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120]) !=
            0) {
          FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,
                       (int)(char)(&DAT_006826de)[arg_2 * 0x120 + arg_1 * 0x5b20]);
        }
      }
      else {
        for (player_idx = 0; player_idx < (int)(&DAT_00666408)[arg1]; player_idx = player_idx + 1) {
          val_5 = FUN_0048a33f(arg1,player_idx);
          if (((val_5 != 0) && ((&DAT_006826de)[player_idx * 0x120 + arg1 * 0x5b20] == cVar1)) &&
             ((uval_6 & (int)(char)(&DAT_006826dd)[player_idx * 0x120 + arg1 * 0x5b20]) != 0)) {
            FUN_004a2b00(arg_1,arg_2,DAT_006764c0,arg1,player_idx);
          }
        }
      }
    }
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004e5e3b
 * Entry Point: 004675bf
 * Size: 875 bytes
 */


int32_t Glue_Subsystem_004e5e3b(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  
  if (flags == 0x73) {
    if ((*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_1 = FUN_004521e2(spell_id,target_id);
      val_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0)) {
      FUN_00434660(s_prompts_txt_004f8e5c,s_RADJAN_SPIRIT_004f8e4c);
      arg_20 = &card_idx;
      uval_1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = card_idx;
        *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = match_count;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
    }
    if (flags == 0x72) {
      card_idx = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
      match_count = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Rules_ParseFilter_0041c0ab
                        (card_idx,match_count,(uint8_t *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_4,
                         uval_5,val_2,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066ab00,card_idx,match_count);
        if (val_2 != -1) {
          *(int32_t *)(&DAT_006826e4 + val_2 * 0x120 + spell_id * 0x5b20) = 0x20;
        }
        *(int32_t *)(&DAT_006826fc + card_idx * 0x5b20 + match_count * 0x120) = 0x8000000;
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: Glue_Subsystem_004e61a6
 * Entry Point: 0046792a
 * Size: 932 bytes
 */


int32_t Glue_Subsystem_004e61a6(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int card_idx;
  int match_count;
  
  if (flags == 0x73) {
    if ((*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      uval_1 = FUN_004521e2(spell_id,target_id);
      val_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uval_1,arg_11,arg_12,arg_13,arg_14,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if ((flags == 0x6d) &&
       ((*(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0x20010) == 0)) {
      FUN_00434660(s_prompts_txt_004f8e74,s_HURR_JACKAL_004f8e68);
      arg_20 = &card_idx;
      uval_1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = card_idx;
        *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = match_count;
        (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
        *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
        if (((&DAT_006826fd)[card_idx * 0x5b20 + match_count * 0x120] & 2) == 0) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x30;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
        }
      }
    }
    if (flags == 0x72) {
      card_idx = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
      match_count = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_2 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Rules_ParseFilter_0041c0ab
                        (card_idx,match_count,(uint8_t *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_4,
                         uval_5,val_2,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        val_2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00681ec8,card_idx,match_count);
        if (val_2 != -1) {
          *(uint32_t *)(&DAT_006826f8 + val_2 * 0x120 + spell_id * 0x5b20) =
               *(uint32_t *)(&DAT_006826f8 + val_2 * 0x120 + spell_id * 0x5b20) | 0x800000;
          *(int32_t *)(&DAT_006826fc + card_idx * 0x5b20 + match_count * 0x120) = 0x8000000;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_00467cce
 * Entry Point: 00467cce
 * Size: 151 bytes
 */


int32_t FUN_00467cce(int arg1,uint8_t arg2)

{
  int val_1;
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if ((int)(&DAT_00666408)[arg1] <= slot_idx) {
      return 0;
    }
    val_1 = FUN_0048a33f(arg1,slot_idx);
    if ((val_1 != 0) &&
       ((arg2 & (&DAT_004ff594)[*(int *)(&DAT_006826c4 + slot_idx * 0x120 + arg1 * 0x5b20) * 0x34])
        != 0)) break;
    slot_idx = slot_idx + 1;
  }
  return 1;
}



/*
 * Decompiled function: FUN_00467d65
 * Entry Point: 00467d65
 * Size: 210 bytes
 */


void FUN_00467d65(uint8_t *arg1,int arg2)

{
  int card_idx;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    if ((arg2 == -1) || (slot_idx == arg2)) {
      for (card_idx = 0; card_idx < (int)(&DAT_00666408)[slot_idx]; card_idx = card_idx + 1) {
        if ((*(int *)(&DAT_006826c4 + card_idx * 0x120 + slot_idx * 0x5b20) != -1) &&
           (((&DAT_006826cc)[card_idx * 0x120 + slot_idx * 0x5b20] & 2) != 0)) {
          (*(code *)arg1)(slot_idx,card_idx,
                          *(int *)(&DAT_006826c4 + card_idx * 0x120 + slot_idx * 0x5b20));
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00467e37
 * Entry Point: 00467e37
 * Size: 184 bytes
 */


void FUN_00467e37(int arg1,int arg2)

{
  if (((&DAT_0068270c)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
     (*(uint32_t *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) =
           *(int *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) + 1U & 0xff |
           *(uint32_t *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff00, DAT_0066aaf4 != 1))
  {
    FUN_0048d00c(0x1b);
  }
  return;
}



/*
 * Decompiled function: FUN_00467eef
 * Entry Point: 00467eef
 * Size: 118 bytes
 */


void FUN_00467eef(int arg1,int arg2)

{
  *(uint32_t *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) =
       *(int *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) - 1U & 0xff |
       *(uint32_t *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff00;
  return;
}



/*
 * Decompiled function: FUN_00467f65
 * Entry Point: 00467f65
 * Size: 186 bytes
 */


void FUN_00467f65(int player_id,int card_slot,int event_type)

{
  if (((&DAT_0068270c)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1) &&
     (*(uint32_t *)(&DAT_0068270c + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(int *)(&DAT_0068270c + arg_1 * 0x5b20 + arg_2 * 0x120) + arg_3 & 0xffU |
           *(uint32_t *)(&DAT_0068270c + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffffff00, DAT_0066aaf4 != 1
     )) {
    FUN_0048d00c(0x1b);
  }
  return;
}



/*
 * Decompiled function: FUN_0046801f
 * Entry Point: 0046801f
 * Size: 120 bytes
 */


void FUN_0046801f(int player_id,int card_slot,int event_type)

{
  *(uint32_t *)(&DAT_0068270c + arg_2 * 0x120 + arg_1 * 0x5b20) =
       *(int *)(&DAT_0068270c + arg_2 * 0x120 + arg_1 * 0x5b20) - arg_3 & 0xffU |
       *(uint32_t *)(&DAT_0068270c + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffffff00;
  return;
}



/*
 * Decompiled function: FUN_00468097
 * Entry Point: 00468097
 * Size: 101 bytes
 */


void FUN_00468097(int player_id,int card_slot,int event_type)

{
  if (0xff < arg_3) {
    arg_3 = 0xff;
  }
  *(uint32_t *)(&DAT_0068270c + arg_2 * 0x120 + arg_1 * 0x5b20) =
       CONCAT31((int3)((uint32_t)*(int32_t *)(&DAT_0068270c + arg_2 * 0x120 + arg_1 * 0x5b20) >> 8),
                (uint8_t)arg_3);
  return;
}



/*
 * Decompiled function: FUN_004680fc
 * Entry Point: 004680fc
 * Size: 52 bytes
 */


uint32_t FUN_004680fc(int arg1,int arg2)

{
  return *(uint32_t *)(&DAT_0068270c + arg2 * 0x120 + arg1 * 0x5b20) & 0xff;
}



/*
 * Decompiled function: FUN_00468130
 * Entry Point: 00468130
 * Size: 300 bytes
 */


bool FUN_00468130(int player_id,uint32_t arg_2,int event_type)

{
  uint32_t arg_8;
  uint32_t arg_9;
  uint32_t arg_10;
  int val_1;
  int arg_12;
  uint32_t arg_13;
  uint32_t arg_14;
  uint32_t arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int32_t slot_idx;
  
  if (arg_2 == 0xffffffff) {
    arg_2 = 2;
  }
  arg_20 = &match_count;
  arg_19 = 1;
  arg_18 = &DAT_006679f0;
  arg_17 = 0;
  arg_16 = 0;
  arg_15 = 0;
  arg_14 = 0xffffffff;
  arg_13 = 0xffffffff;
  arg_12 = -1;
  val_1 = -1;
  arg_10 = 0;
  arg_9 = 0;
  arg_8 = FUN_004521e2(arg_1,arg_3);
  val_1 = Action_ValidateTarget_0041e2a2
                    (arg_1,2,arg_2,0x200,2,0,0,arg_8,arg_9,arg_10,val_1,arg_12,arg_13,arg_14,arg_15,
                     arg_16,arg_17,arg_18,arg_19,arg_20);
  if (val_1 != 0) {
    *(int32_t *)
     (&DAT_0068271c +
     arg_1 * 0x5b20 + arg_3 * 0x120 + (char)(&DAT_006827b8)[arg_1 * 0x5b20 + arg_3 * 0x120] * 8) =
         slot_idx;
    *(int *)(&DAT_00682718 +
            arg_1 * 0x5b20 +
            arg_3 * 0x120 + (char)(&DAT_006827b8)[arg_1 * 0x5b20 + arg_3 * 0x120] * 8) = match_count;
    (&DAT_006827b8)[arg_1 * 0x5b20 + arg_3 * 0x120] =
         (&DAT_006827b8)[arg_1 * 0x5b20 + arg_3 * 0x120] + '\x01';
  }
  return val_1 != 0;
}



/*
 * Decompiled function: FUN_00468261
 * Entry Point: 00468261
 * Size: 285 bytes
 */


bool FUN_00468261(int player_id,uint32_t arg_2,int event_type)

{
  int val_1;
  int match_count;
  int32_t slot_idx;
  
  if (arg_2 == 0xffffffff) {
    arg_2 = 2;
  }
  val_1 = Action_ValidateTarget_0041e2a2
                    (arg_1,2,arg_2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,&DAT_006679f0
                     ,1,&match_count);
  if (val_1 != 0) {
    *(int *)(&DAT_00682718 +
            arg_3 * 0x120 +
            arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) = match_count;
    *(int32_t *)
     (&DAT_0068271c +
     arg_3 * 0x120 + arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) =
         slot_idx;
    (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] + '\x01';
  }
  return val_1 != 0;
}



/*
 * Decompiled function: FUN_00468383
 * Entry Point: 00468383
 * Size: 461 bytes
 */


int FUN_00468383(int player_id)

{
  int val_1;
  int val_2;
  int loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if ((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) {
    val_1 = Action_ValidateTarget_0041e2a2
                      (arg_1,arg_1,arg_1,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                       &DAT_006679f0,0,&color_idx);
    if (val_1 == 0) {
      loop_idx = -1;
    }
    else {
      loop_idx = target_idx;
    }
  }
  else {
    loop_idx = -1;
    player_idx = 0x7fff;
    for (card_idx = 0; card_idx < (int)(&DAT_00666408)[arg_1]; card_idx = card_idx + 1) {
      match_count = *(int *)(&DAT_006826c4 + card_idx * 0x120 + arg_1 * 0x5b20);
      if ((((match_count != -1) && (((&DAT_006826cc)[card_idx * 0x120 + arg_1 * 0x5b20] & 2) != 0)) &&
          (((&DAT_004ff594)[match_count * 0x34] & 2) != 0)) &&
         ((&DAT_006826e0)[card_idx * 0x120 + arg_1 * 0x5b20] != '\x03')) {
        val_1 = FUN_0048b81a(arg_1,card_idx,0x32,0xffffffff);
        val_2 = FUN_0048b81a(arg_1,card_idx,0x33,0xffffffff);
        slot_idx = (val_1 + 2) * (val_2 + 2);
        if (slot_idx < player_idx) {
          loop_idx = card_idx;
          player_idx = slot_idx;
        }
      }
    }
  }
  if ((loop_idx != -1) && (DAT_0066aaf4 != 1)) {
    FUN_0048d00c(0xf);
  }
  return loop_idx;
}



/*
 * Decompiled function: FUN_00468550
 * Entry Point: 00468550
 * Size: 300 bytes
 */


bool FUN_00468550(int player_id,uint32_t arg_2,int event_type)

{
  uint32_t arg_8;
  uint32_t arg_9;
  uint32_t arg_10;
  int val_1;
  int arg_12;
  uint32_t arg_13;
  uint32_t arg_14;
  uint32_t arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int32_t slot_idx;
  
  if (arg_2 == 0xffffffff) {
    arg_2 = 2;
  }
  arg_20 = &match_count;
  arg_19 = 1;
  arg_18 = &DAT_006679f0;
  arg_17 = 0;
  arg_16 = 0;
  arg_15 = 0;
  arg_14 = 0xffffffff;
  arg_13 = 0xffffffff;
  arg_12 = -1;
  val_1 = -1;
  arg_10 = 0;
  arg_9 = 0;
  arg_8 = FUN_004521e2(arg_1,arg_3);
  val_1 = Action_ValidateTarget_0041e2a2
                    (arg_1,2,arg_2,0x200,1,0,0,arg_8,arg_9,arg_10,val_1,arg_12,arg_13,arg_14,arg_15,
                     arg_16,arg_17,arg_18,arg_19,arg_20);
  if (val_1 != 0) {
    *(int *)(&DAT_00682718 +
            arg_1 * 0x5b20 +
            arg_3 * 0x120 + (char)(&DAT_006827b8)[arg_1 * 0x5b20 + arg_3 * 0x120] * 8) = match_count;
    *(int32_t *)
     (&DAT_0068271c +
     arg_1 * 0x5b20 + arg_3 * 0x120 + (char)(&DAT_006827b8)[arg_1 * 0x5b20 + arg_3 * 0x120] * 8) =
         slot_idx;
    (&DAT_006827b8)[arg_1 * 0x5b20 + arg_3 * 0x120] =
         (&DAT_006827b8)[arg_1 * 0x5b20 + arg_3 * 0x120] + '\x01';
  }
  return val_1 != 0;
}



/*
 * Decompiled function: FUN_00468681
 * Entry Point: 00468681
 * Size: 285 bytes
 */


bool FUN_00468681(int player_id,uint32_t arg_2,int event_type)

{
  int val_1;
  int match_count;
  int32_t slot_idx;
  
  if (arg_2 == 0xffffffff) {
    arg_2 = 2;
  }
  val_1 = Action_ValidateTarget_0041e2a2
                    (arg_1,2,arg_2,0x200,1,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,&DAT_006679f0
                     ,1,&match_count);
  if (val_1 != 0) {
    *(int *)(&DAT_00682718 +
            arg_3 * 0x120 +
            arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) = match_count;
    *(int32_t *)
     (&DAT_0068271c +
     arg_3 * 0x120 + arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) =
         slot_idx;
    (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] + '\x01';
  }
  return val_1 != 0;
}



/*
 * Decompiled function: FUN_004687a3
 * Entry Point: 004687a3
 * Size: 142 bytes
 */


int32_t FUN_004687a3(int player_id)

{
  int val_1;
  int32_t uval_2;
  int match_count;
  int slot_idx;
  
  val_1 = Action_ValidateTarget_0041e2a2
                    (arg_1,arg_1,arg_1,0x200,1,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                     &DAT_006679f0,0,&match_count);
  if (val_1 == 0) {
    uval_2 = 0;
  }
  else {
    if (DAT_0066aaf4 != 1) {
      FUN_0048d00c(0xf);
    }
    FUN_0046e571(match_count,slot_idx,3);
    uval_2 = 1;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00468831
 * Entry Point: 00468831
 * Size: 300 bytes
 */


bool FUN_00468831(int player_id,uint32_t arg_2,int event_type)

{
  uint32_t arg_8;
  uint32_t arg_9;
  uint32_t arg_10;
  int val_1;
  int arg_12;
  uint32_t arg_13;
  uint32_t arg_14;
  uint32_t arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_19;
  int *arg_20;
  int match_count;
  int32_t slot_idx;
  
  if (arg_2 == 0xffffffff) {
    arg_2 = 2;
  }
  arg_20 = &match_count;
  arg_19 = 1;
  arg_18 = &DAT_006679f0;
  arg_17 = 0;
  arg_16 = 0;
  arg_15 = 0;
  arg_14 = 0xffffffff;
  arg_13 = 0xffffffff;
  arg_12 = -1;
  val_1 = -1;
  arg_10 = 0;
  arg_9 = 0;
  arg_8 = FUN_004521e2(arg_1,arg_3);
  val_1 = Action_ValidateTarget_0041e2a2
                    (arg_1,2,arg_2,0x200,0x40,0,0,arg_8,arg_9,arg_10,val_1,arg_12,arg_13,arg_14,
                     arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
  if (val_1 != 0) {
    *(int *)(&DAT_00682718 +
            arg_3 * 0x120 +
            arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) = match_count;
    *(int32_t *)
     (&DAT_0068271c +
     arg_3 * 0x120 + arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) =
         slot_idx;
    (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] + '\x01';
  }
  return val_1 != 0;
}



/*
 * Decompiled function: FUN_00468962
 * Entry Point: 00468962
 * Size: 285 bytes
 */


bool FUN_00468962(int player_id,uint32_t arg_2,int event_type)

{
  int val_1;
  int match_count;
  int32_t slot_idx;
  
  if (arg_2 == 0xffffffff) {
    arg_2 = 2;
  }
  val_1 = Action_ValidateTarget_0041e2a2
                    (arg_1,2,arg_2,0x200,0x40,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                     &DAT_006679f0,1,&match_count);
  if (val_1 != 0) {
    *(int *)(&DAT_00682718 +
            arg_3 * 0x120 +
            arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) = match_count;
    *(int32_t *)
     (&DAT_0068271c +
     arg_3 * 0x120 + arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) =
         slot_idx;
    (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827b8)[arg_3 * 0x120 + arg_1 * 0x5b20] + '\x01';
  }
  return val_1 != 0;
}



/*
 * Decompiled function: FUN_00468a84
 * Entry Point: 00468a84
 * Size: 142 bytes
 */


int32_t FUN_00468a84(int player_id)

{
  int val_1;
  int32_t uval_2;
  int match_count;
  int slot_idx;
  
  val_1 = Action_ValidateTarget_0041e2a2
                    (arg_1,arg_1,arg_1,0x200,0x40,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                     &DAT_006679f0,0,&match_count);
  if (val_1 == 0) {
    uval_2 = 0;
  }
  else {
    if (DAT_0066aaf4 != 1) {
      FUN_0048d00c(0xf);
    }
    FUN_0046e571(match_count,slot_idx,3);
    uval_2 = 1;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00468b20
 * Entry Point: 00468b20
 * Size: 408 bytes
 */


int FUN_00468b20(int player_id,int card_slot,int event_type)

{
  int val_1;
  uint32_t uval_2;
  int player_idx;
  int card_idx;
  int slot_idx;
  
  card_idx = 0;
  slot_idx = 0;
  do {
    if ((1 < slot_idx) || (card_idx != 0)) {
      return card_idx;
    }
    player_idx = 0;
    while ((player_idx < (int)(&DAT_00666408)[slot_idx] && (card_idx == 0))) {
      if ((*(int *)(&DAT_006826c4 + player_idx * 0x120 + slot_idx * 0x5b20) != -1) &&
         (((&DAT_006826cc)[player_idx * 0x120 + slot_idx * 0x5b20] & 2) != 0)) {
        if (*(int *)(&DAT_00618ad8 +
                    *(int *)(&DAT_004ff590 +
                            *(int *)(&DAT_006826c4 + player_idx * 0x120 + slot_idx * 0x5b20) * 0x34) *
                    0x98) != arg_3) {
          val_1 = FUN_00468cb8(*(int *)(&DAT_00618ad8 +
                                       *(int *)(&DAT_004ff590 +
                                               *(int *)(&DAT_006826c4 +
                                                       player_idx * 0x120 + slot_idx * 0x5b20) * 0x34)
                                       * 0x98));
          if (val_1 != arg_3) goto LAB_00468b5f;
        }
        if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + player_idx * 0x120 + slot_idx * 0x5b20) * 0x34] &
            2) != 0) {
          uval_2 = FUN_004521e2(arg_1,arg_2);
          if ((*(uint32_t *)(&DAT_006826fc + player_idx * 0x120 + slot_idx * 0x5b20) & uval_2) == 0) {
            card_idx = 1;
          }
        }
      }
LAB_00468b5f:
      player_idx = player_idx + 1;
    }
    slot_idx = slot_idx + 1;
  } while( true );
}



/*
 * Decompiled function: FUN_00468cb8
 * Entry Point: 00468cb8
 * Size: 104 bytes
 */


int FUN_00468cb8(int player_id)

{
  int slot_idx;
  
  slot_idx = -1;
  switch(arg_1) {
  case 8:
  case 0x11:
  case 0x4a:
  case 0x57:
  case 0x5a:
  case 0x6a:
  case 0x94:
    slot_idx = arg_1 + 1;
    break;
  case 9:
  case 0x12:
  case 0x4b:
  case 0x58:
  case 0x5b:
  case 0x6b:
  case 0x95:
    slot_idx = arg_1 + -1;
    break;
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x59:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x85:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
  case 0x90:
  case 0x91:
  case 0x92:
  case 0x93:
  }
  return slot_idx;
}



/*
 * Decompiled function: Palette_Subsystem_004a6fef
 * Entry Point: 00468def
 * Size: 1486 bytes
 */


int32_t Palette_Subsystem_004a6fef(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int32_t arg_10;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int val_6;
  int32_t arg_11;
  int32_t arg_12;
  uint32_t uval_7;
  int32_t arg_13;
  uint32_t uval_8;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int player_idx;
  int card_idx;
  int32_t match_count;
  int32_t slot_idx;
  
  if (flags == 0x71) {
    slot_idx = DAT_0066642c;
    uval_1 = FUN_004693bd(1 - spell_id);
    FUN_0046951b(spell_id,target_id,uval_1);
    DAT_0066642c = slot_idx;
  }
  if (flags == 0x73) {
    if (((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
         2) == 0)) &&
       ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0 &&
        (val_2 = FUN_0049b309(spell_id,3,2), val_2 != 0)))) {
      arg_19 = 0;
      arg_18_00 = 0;
      arg_17 = 0x10;
      arg_16 = 0xffffffff;
      arg_15 = 0xffffffff;
      uval_1 = *(int32_t *)
               (&DAT_006826e4 +
               *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
               (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      arg_13 = 0xffffffff;
      arg_12 = 0;
      arg_11 = 0;
      arg_10 = FUN_004521e2(spell_id,target_id);
      val_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,2,0,0,arg_10,arg_11,arg_12,arg_13,uval_1,
                           arg_15,arg_16,arg_17,arg_18_00,arg_19);
      if (val_2 != 0) {
        return 1;
      }
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
  }
  else {
    if ((((flags == 0x6d) &&
         ((*(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) &&
        (val_2 = FUN_00468b20(spell_id,target_id,
                              *(int *)(&DAT_006826e4 +
                                      *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20
                                              ) * 0x120 +
                                      (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] *
                                      0x5b20)), val_2 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(spell_id,3,2), DAT_00681ea4 != 1)) {
      FUN_00434660(s_prompts_txt_004f9390,s_ASWANJAGUAR_004f9384);
      arg_20 = &player_idx;
      uval_1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0x10;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_2 = *(int *)(&DAT_006826e4 +
                      *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                      (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      val_6 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Action_ValidateTarget_0041e2a2
                        (spell_id,2,1 - spell_id,0x200,2,0,0,uval_3,uval_4,uval_5,val_6,val_2,uval_7,
                         uval_8,uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
        *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = player_idx;
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        match_count = *(int32_t *)
                   (&DAT_00618ad8 +
                   *(int *)(&DAT_004ff590 +
                           *(int *)(&DAT_006826c4 + player_idx * 0x5b20 + card_idx * 0x120) * 0x34) *
                   0x98);
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0x10;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_2 = *(int *)(&DAT_006826e4 +
                      *(int *)(&DAT_006826ec + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
                      (char)(&DAT_006826d3)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20);
      val_6 = -1;
      uval_5 = 0;
      uval_4 = 0;
      uval_3 = FUN_004521e2(spell_id,target_id);
      val_2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),
                         (uint8_t *)0x0,spell_id,2,2,0x200,2,0,0,uval_3,uval_4,uval_5,val_6,val_2,
                         uval_7,uval_8,uVar9,uVar10,uVar11);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x22);
        }
        FUN_0046e571(*(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20),
                     *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20),1);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20] = 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004693bd
 * Entry Point: 004693bd
 * Size: 147 bytes
 */


int FUN_004693bd(int player_id)

{
  int arg2;
  int match_count;
  int slot_idx;
  
  slot_idx = 0;
  while ((slot_idx < 500 && (*(int *)(&DAT_006669f0 + slot_idx * 4 + arg_1 * 2000) != -1))) {
    slot_idx = slot_idx + 1;
  }
  arg2 = FUN_00439892(slot_idx);
  match_count = FUN_00469450(arg_1,arg2);
  if (match_count == 0) {
    match_count = FUN_00469450(arg_1,0);
  }
  return match_count;
}



/*
 * Decompiled function: FUN_00469450
 * Entry Point: 00469450
 * Size: 203 bytes
 */


int FUN_00469450(int arg1,int arg2)

{
  int val_1;
  int card_idx;
  int match_count;
  
  match_count = arg2;
  card_idx = 0;
  DAT_0066642c = -1;
  while ((match_count < 500 && (card_idx == 0))) {
    val_1 = *(int *)(&DAT_006669f0 + match_count * 4 + arg1 * 2000);
    if ((val_1 != -1) &&
       (*(int *)(&DAT_00618ad4 + *(int *)(&DAT_004ff590 + val_1 * 0x34) * 0x98) == 7)) {
      card_idx = *(int *)(&DAT_00618ad8 + *(int *)(&DAT_004ff590 + val_1 * 0x34) * 0x98);
      DAT_0066642c = val_1;
    }
    match_count = match_count + 1;
  }
  return card_idx;
}



/*
 * Decompiled function: FUN_0046951b
 * Entry Point: 0046951b
 * Size: 249 bytes
 */


int FUN_0046951b(int player_id,int card_slot,int32_t arg_3)

{
  int val_1;
  
  val_1 = FUN_004a2b00(arg_1,arg_2,DAT_0068f0c4,arg_1,arg_2);
  if (val_1 != -1) {
    *(uint32_t *)(&DAT_006826f8 + val_1 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826f8 + val_1 * 0x120 + arg_1 * 0x5b20) | 0x20;
    *(int32_t *)(&DAT_006826e4 + val_1 * 0x120 + arg_1 * 0x5b20) = arg_3;
    if (arg_1 != 0) {
      *(uint32_t *)(&DAT_006826cc + val_1 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + val_1 * 0x120 + arg_1 * 0x5b20) | 0x1000;
    }
    (&DAT_006826d3)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)arg_1;
    *(int *)(&DAT_006826ec + arg_2 * 0x120 + arg_1 * 0x5b20) = val_1;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00469614
 * Entry Point: 00469614
 * Size: 529 bytes
 */


int32_t FUN_00469614(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  
  if (arg_3 == 0x73) {
    val_1 = FUN_0049b309(arg_1,7,2);
    if ((val_1 == 0) || ((*(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x20014) != 0)
       ) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(1);
    FUN_00430768(0);
    uval_2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (val_1 = FUN_00469b05(arg_1,arg_2), val_1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,2);
      if (DAT_00681ea4 != 1) {
        Ai_CalcManaRequirement_004ba890(arg_1,4,-1);
      }
      if (DAT_00681ea4 != 1) {
        *(int32_t *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = DAT_00681ea0;
        *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
      }
    }
    if ((arg_3 == 0x72) && (0 < *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120))) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x27);
      }
      FUN_00469825(DAT_00690af0,DAT_0068efa0,
                   *(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120));
      *(int32_t *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) = 0;
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00469825
 * Entry Point: 00469825
 * Size: 424 bytes
 */


int FUN_00469825(int player_id,int card_slot,int event_type)

{
  int local_514;
  int local_50c;
  int local_508;
  int local_504 [320];
  
  local_514 = FUN_004699cd(arg_1,arg_2,(int)local_504);
  local_508 = 0;
  for (; (local_508 < arg_3 && (local_514 != 0)); local_514 = local_514 + -1) {
    local_50c = FUN_00439892(local_514);
    FUN_004a7b83(local_504[local_50c * 2],local_504[local_50c * 2 + 1]);
    if ((*(int *)(&DAT_00618ad8 +
                 *(int *)(&DAT_004ff590 +
                         *(int *)(&DAT_006826c4 +
                                 local_504[local_50c * 2] * 0x5b20 +
                                 local_504[local_50c * 2 + 1] * 0x120) * 0x34) * 0x98) == 0x58) ||
       (*(int *)(&DAT_00618ad8 +
                *(int *)(&DAT_004ff590 +
                        *(int *)(&DAT_006826c4 +
                                local_504[local_50c * 2] * 0x5b20 +
                                local_504[local_50c * 2 + 1] * 0x120) * 0x34) * 0x98) == 0x57)) {
      FUN_004a2b00(arg_1,arg_2,DAT_006664e8,local_504[local_50c * 2],local_504[local_50c * 2 + 1]);
    }
    for (; local_50c < local_514; local_50c = local_50c + 1) {
      local_504[local_50c * 2] = local_504[local_50c * 2 + 2];
      local_504[local_50c * 2 + 1] = local_504[local_50c * 2 + 3];
    }
    local_508 = local_508 + 1;
  }
  return local_508;
}



/*
 * Decompiled function: FUN_004699cd
 * Entry Point: 004699cd
 * Size: 312 bytes
 */


int FUN_004699cd(int player_id,int card_slot,int event_type)

{
  uint32_t uval_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  match_count = 0;
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (card_idx = 0; card_idx < (int)(&DAT_00666408)[slot_idx]; card_idx = card_idx + 1) {
      if (((*(int *)(&DAT_006826c4 + slot_idx * 0x5b20 + card_idx * 0x120) != -1) &&
          (((&DAT_006826cc)[slot_idx * 0x5b20 + card_idx * 0x120] & 2) != 0)) &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + slot_idx * 0x5b20 + card_idx * 0x120) * 0x34] & 2
          ) != 0)) {
        uval_1 = FUN_004521e2(arg_1,arg_2);
        if ((*(uint32_t *)(&DAT_006826fc + slot_idx * 0x5b20 + card_idx * 0x120) & uval_1) == 0) {
          *(int *)(arg_3 + match_count * 8) = slot_idx;
          *(int *)(arg_3 + 4 + match_count * 8) = card_idx;
          match_count = match_count + 1;
        }
      }
    }
  }
  return match_count;
}



/*
 * Decompiled function: FUN_00469b05
 * Entry Point: 00469b05
 * Size: 311 bytes
 */


int FUN_00469b05(int arg1,int arg2)

{
  uint32_t uval_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  match_count = 0;
  slot_idx = 0;
  while ((slot_idx < 2 && (match_count == 0))) {
    card_idx = 0;
    while ((card_idx < (int)(&DAT_00666408)[slot_idx] && (match_count == 0))) {
      if (((*(int *)(&DAT_006826c4 + card_idx * 0x120 + slot_idx * 0x5b20) != -1) &&
          (((&DAT_006826cc)[card_idx * 0x120 + slot_idx * 0x5b20] & 2) != 0)) &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + card_idx * 0x120 + slot_idx * 0x5b20) * 0x34] & 2
          ) != 0)) {
        uval_1 = FUN_004521e2(arg1,arg2);
        if ((*(uint32_t *)(&DAT_006826fc + card_idx * 0x120 + slot_idx * 0x5b20) & uval_1) == 0) {
          match_count = 1;
        }
      }
      card_idx = card_idx + 1;
    }
    slot_idx = slot_idx + 1;
  }
  return match_count;
}



/*
 * Decompiled function: FUN_00469c3c
 * Entry Point: 00469c3c
 * Size: 238 bytes
 */


int32_t FUN_00469c3c(int player_id,int card_slot,int event_type)

{
  if ((((arg_3 == 0x82) &&
       (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
      ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0)) &&
     (DAT_00690c48 != -1)) {
    *(uint32_t *)(&DAT_006827c8 +
             *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
             (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
         *(uint32_t *)(&DAT_006827c8 +
                  *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) & 0xfffffffc;
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}



/*
 * Decompiled function: FUN_00469d2a
 * Entry Point: 00469d2a
 * Size: 487 bytes
 */


int32_t FUN_00469d2a(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int32_t local_504 [320];
  
  if (arg_3 == 0x73) {
    val_1 = FUN_0049b309(arg_1,3,2);
    if ((val_1 == 0) || (val_1 = FUN_0049b309(arg_1,7,3), val_1 == 0)) {
      uval_2 = 0;
    }
    else {
      uval_2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uval_2 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      DAT_0068ece0 = 1;
      Ai_CalcManaRequirement_004ba890(arg_1,3,2);
      if (DAT_00681ea4 != 1) {
        uval_2 = FUN_00439892(0x14);
        *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = uval_2;
        val_1 = FUN_004699cd(arg_1,arg_2,(int)local_504);
        val_1 = FUN_00439892(val_1);
        *(int32_t *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_504[val_1 * 2];
        *(int32_t *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = local_504[val_1 * 2 + 1];
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      }
    }
    if ((arg_3 == 0x72) && ((&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0')) {
      Palette_Subsystem_004a8111
                (arg_1,arg_2,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20));
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: Palette_Subsystem_004a8111
 * Entry Point: 00469f11
 * Size: 3040 bytes
 */


int32_t Palette_Subsystem_004a8111(int player_id,int card_slot,int event_type)

{
  uint8_t flag_1;
  short len_2;
  uint32_t arg_11;
  int val_3;
  uint32_t arg_12;
  uint32_t arg_13;
  int val_4;
  int val_5;
  uint32_t arg_16;
  uint32_t arg_17;
  uint32_t arg_18;
  uint32_t arg_19;
  uint32_t arg_20;
  int match_count;
  int slot_idx;
  
  arg_20 = 0;
  arg_19 = 0;
  arg_18 = 0;
  arg_17 = 0xffffffff;
  arg_16 = 0xffffffff;
  val_5 = -1;
  val_4 = -1;
  arg_13 = 0;
  arg_12 = 0;
  arg_11 = FUN_004521e2(arg_1,arg_2);
  val_4 = Rules_ParseFilter_0041c0ab
                    (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                     *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),(uint8_t *)0x0,
                     arg_1,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,val_4,val_5,arg_16,arg_17,arg_18,
                     arg_19,arg_20);
  if (val_4 == 0) {
    DAT_00681ea4 = 1;
  }
  else {
    val_4 = *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20);
    val_5 = *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20);
    match_count = -1;
    if ((((-1 < arg_3) && (arg_3 < 0x14)) && (arg_3 != 0xd)) && (arg_3 != 1)) {
      Mem_AllocOrFree_004d9630
                ((uint32_t *)&DAT_005f6810,(uint32_t *)(s_casts_Berserk__004f8ed8 + arg_3 * 0x32));
      Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_4,val_5,&DAT_005f6810,0);
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x24);
      }
    }
    switch(arg_3) {
    case 0:
      match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00681ec8,val_4,val_5);
      if (match_count != -1) {
        *(int32_t *)(&DAT_006826e4 + match_count * 0x120 + arg_1 * 0x5b20) = 0x80;
        *(int16_t *)(&DAT_006826d8 + match_count * 0x120 + arg_1 * 0x5b20) =
             *(int16_t *)(&DAT_006826d4 + val_4 * 0x5b20 + val_5 * 0x120);
        *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + arg_1 * 0x5b20) | 0x4000;
      }
      break;
    case 1:
      if (*(short *)(&DAT_006826d4 + val_4 * 0x5b20 + val_5 * 0x120) < 3) {
        Ai_Subsystem_004cc56d
                  (arg_1,arg_1,arg_2,val_4,val_5,s_activates_Tawnos_s_Wand_effect__004f93bc,0);
        match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_006667b0,val_4,val_5);
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x24);
        }
      }
      else {
        DAT_00681ea4 = 1;
        Ai_Subsystem_004cc56d
                  (arg_1,arg_1,arg_2,val_4,val_5,s_fizzles_attempting_Tawnos_s_Wand_004f93e0,0);
      }
      break;
    case 2:
      match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,val_4,val_5);
      if (match_count != -1) {
        *(int16_t *)(&DAT_006826d8 + match_count * 0x120 + arg_1 * 0x5b20) = 4;
        len_2 = FUN_0049aa14(4,0,*(short *)(&DAT_006826d6 + val_4 * 0x5b20 + val_5 * 0x120) + -1);
        *(short *)(&DAT_006826da + match_count * 0x120 + arg_1 * 0x5b20) = -len_2;
      }
      break;
    case 3:
      flag_1 = FUN_004af7bb(arg_1,arg_2,3);
      (&DAT_006826dd)[val_4 * 0x5b20 + val_5 * 0x120] = (char)(1 << (flag_1 & 0x1f));
      break;
    case 4:
      flag_1 = FUN_004af7bb(arg_1,arg_2,5);
      (&DAT_006826dd)[val_4 * 0x5b20 + val_5 * 0x120] = (char)(1 << (flag_1 & 0x1f));
      break;
    case 5:
      flag_1 = FUN_004af7bb(arg_1,arg_2,4);
      (&DAT_006826dd)[val_4 * 0x5b20 + val_5 * 0x120] = (char)(1 << (flag_1 & 0x1f));
      break;
    case 6:
      FUN_004af950(val_4,val_5,3,DAT_00690af0,DAT_0068efa0);
      break;
    case 7:
      match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,val_4,val_5);
      if (match_count != -1) {
        *(int32_t *)(&DAT_006826fc + match_count * 0x120 + arg_1 * 0x5b20) = 0;
        *(int32_t *)(&DAT_006826e4 + match_count * 0x120 + arg_1 * 0x5b20) = 0x20;
      }
      break;
    case 8:
      match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,val_4,val_5);
      if (match_count != -1) {
        *(int16_t *)(&DAT_006826d8 + match_count * 0x120 + arg_1 * 0x5b20) = 3;
        *(int16_t *)(&DAT_006826da + match_count * 0x120 + arg_1 * 0x5b20) = 3;
      }
      break;
    case 9:
      match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,val_4,val_5);
      if (match_count != -1) {
        *(int32_t *)(&DAT_006826e4 + match_count * 0x120 + arg_1 * 0x5b20) = 0x40;
      }
      *(int32_t *)(&DAT_006826fc + val_4 * 0x5b20 + val_5 * 0x120) = 0x8000000;
      break;
    case 10:
      flag_1 = FUN_004af7bb(arg_1,arg_2,1);
      (&DAT_006826dd)[val_4 * 0x5b20 + val_5 * 0x120] = (char)(1 << (flag_1 & 0x1f));
      break;
    case 0xb:
      flag_1 = FUN_004af7bb(arg_1,arg_2,2);
      (&DAT_006826dd)[val_4 * 0x5b20 + val_5 * 0x120] = (char)(1 << (flag_1 & 0x1f));
      break;
    case 0xc:
      match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00681ec8,val_4,val_5);
      if (match_count != -1) {
        *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + arg_1 * 0x5b20) | 0x800000;
      }
      *(int32_t *)(&DAT_006826fc + val_4 * 0x5b20 + val_5 * 0x120) = 0x8000000;
      break;
    case 0xd:
      val_3 = Ai_Subsystem_004cc56d
                        (arg_1,arg_1,arg_2,val_4,val_5,s_casts_Twiddle__Tap__Untap__004f939c,
                         (*(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x10) >> 4);
      if (val_3 == 0) {
        FUN_004a7b83(val_4,val_5);
      }
      else {
        *(uint32_t *)(&DAT_006826cc + val_4 * 0x5b20 + val_5 * 0x120) =
             *(uint32_t *)(&DAT_006826cc + val_4 * 0x5b20 + val_5 * 0x120) & 0xffffffef;
      }
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x24);
      }
      break;
    case 0xe:
      match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,val_4,val_5);
      if (match_count != -1) {
        *(int16_t *)(&DAT_006826d8 + match_count * 0x120 + arg_1 * 0x5b20) = 0xfffe;
        *(int16_t *)(&DAT_006826da + match_count * 0x120 + arg_1 * 0x5b20) = 0;
      }
      break;
    case 0xf:
      Rules_CardLeavingPlay(val_4,val_5);
      break;
    case 0x10:
      FUN_004af950(val_4,val_5,1,DAT_00690af0,DAT_0068efa0);
      break;
    case 0x11:
      for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
        for (match_count = 0; match_count < (int)(&DAT_00666408)[slot_idx]; match_count = match_count + 1) {
          if (((*(int *)(&DAT_006826c4 + match_count * 0x120 + slot_idx * 0x5b20) == DAT_0068eed0) &&
              (((&DAT_006826cc)[match_count * 0x120 + slot_idx * 0x5b20] & 2) != 0)) &&
             (((char)(&DAT_006826d2)[match_count * 0x120 + slot_idx * 0x5b20] == val_4 &&
              (*(int *)(&DAT_006826e8 + match_count * 0x120 + slot_idx * 0x5b20) == val_5)))) {
            *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + slot_idx * 0x5b20) =
                 *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + slot_idx * 0x5b20) & 0xfeffffff;
          }
        }
      }
      match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0068eed0,val_4,val_5);
      if (match_count != -1) {
        *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + arg_1 * 0x5b20) | 0x1000000;
        *(uint16_t *)(&DAT_006826d8 + match_count * 0x120 + arg_1 * 0x5b20) =
             -(*(uint16_t *)
                (&DAT_004ff59a + *(int *)(&DAT_006826c4 + val_4 * 0x5b20 + val_5 * 0x120) * 0x34) &
              0xbfff);
        *(uint16_t *)(&DAT_006826da + match_count * 0x120 + arg_1 * 0x5b20) =
             2 - (*(uint16_t *)
                   (&DAT_004ff59c + *(int *)(&DAT_006826c4 + val_4 * 0x5b20 + val_5 * 0x120) * 0x34)
                 & 0xbfff);
      }
      break;
    case 0x12:
      val_3 = FUN_0048b81a(val_4,val_5,0x32,0xffffffff);
      (&DAT_00681ea8)[val_4] = (&DAT_00681ea8)[val_4] + val_3;
      FUN_0046e571(val_4,val_5,4);
      break;
    case 0x13:
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x2c);
        Sleep(0xdac);
      }
      *(short *)(&DAT_006826da + val_4 * 0x5b20 + val_5 * 0x120) =
           *(short *)(&DAT_006826da + val_4 * 0x5b20 + val_5 * 0x120) + -1;
      *(int *)(&DAT_0068270c + val_4 * 0x5b20 + val_5 * 0x120) =
           *(int *)(&DAT_0068270c + val_4 * 0x5b20 + val_5 * 0x120) + 0x1000000;
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x2b);
      }
      break;
    default:
      Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_4,val_5,s_made_an_error__004f940c,0);
    }
    if (match_count != -1) {
      val_4 = FUN_00486c12(*(int *)(&DAT_004f8e80 + arg_3 * 4),arg_1,arg_2);
      *(uint32_t *)(&DAT_00682704 + match_count * 0x120 + arg_1 * 0x5b20) =
           val_4 << 0x10 | *(uint32_t *)(&DAT_004f8e80 + arg_3 * 4);
    }
  }
  (&DAT_006827b8)
  [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
  return 0;
}



/*
 * Decompiled function: Palette_Subsystem_004a8d46
 * Entry Point: 0046ab46
 * Size: 658 bytes
 */


int32_t Palette_Subsystem_004a8d46(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  int arg_1_00;
  int local_50c;
  int32_t local_508 [320];
  int slot_idx;
  
  if (arg_3 == 0x74) {
    if ((DAT_00676504 == arg_1) && (val_1 = FUN_0049b309(arg_1,7,3), val_1 == 0)) {
      return 0;
    }
    uval_2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00681ea0;
    }
    if (arg_3 == 0x71) {
      for (local_50c = 0; local_50c < *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
          local_50c = local_50c + 1) {
        val_1 = FUN_00439892(0x10);
        if (*(int *)(&DAT_004f9340 + val_1 * 4) != 0) {
          arg_1_00 = FUN_0046add8(arg_1,arg_2,(int)local_508,*(uint32_t *)(&DAT_004f9340 + val_1 * 4));
          if (arg_1_00 == 0) {
            DAT_00681ea4 = 1;
          }
          else {
            slot_idx = FUN_00439892(arg_1_00);
            *(int32_t *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_508[slot_idx * 2]
            ;
            *(int32_t *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) =
                 local_508[slot_idx * 2 + 1];
            (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
          }
        }
        if (DAT_00681ea4 == 1) {
          if (DAT_0066aaf4 != 1) {
            Mem_AllocOrFree_00450eed(s_fizzle_004f941c);
            Sleep(0x5dc);
            Mem_AllocOrFree_00450eed(&DAT_004f9424);
          }
          DAT_00681ea4 = 0;
        }
        else {
          Palette_Subsystem_004a9137(arg_1,arg_2,val_1);
        }
      }
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x2d);
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      FUN_0046e571(arg_1,arg_2,1);
    }
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_0046add8
 * Entry Point: 0046add8
 * Size: 351 bytes
 */


int FUN_0046add8(int x,int y,int width,uint32_t height)

{
  uint32_t uval_1;
  int card_idx;
  int match_count;
  int slot_idx;
  
  match_count = 0;
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (card_idx = 0; card_idx < (int)(&DAT_00666408)[slot_idx]; card_idx = card_idx + 1) {
      if (((*(int *)(&DAT_006826c4 + slot_idx * 0x5b20 + card_idx * 0x120) != -1) &&
          (((&DAT_006826cc)[slot_idx * 0x5b20 + card_idx * 0x120] & 2) != 0)) &&
         ((height & (uint8_t)(&DAT_004ff594)
                          [*(int *)(&DAT_006826c4 + slot_idx * 0x5b20 + card_idx * 0x120) * 0x34]) !=
          0)) {
        uval_1 = FUN_004521e2(x,y);
        if ((*(uint32_t *)(&DAT_006826fc + slot_idx * 0x5b20 + card_idx * 0x120) & uval_1) == 0) {
          *(int *)(width + match_count * 8) = slot_idx;
          *(int *)(width + 4 + match_count * 8) = card_idx;
          match_count = match_count + 1;
        }
      }
    }
    if ((height & 0x100) != 0) {
      *(int *)(width + match_count * 8) = slot_idx;
      *(int32_t *)(width + 4 + match_count * 8) = 0xffffffff;
      match_count = match_count + 1;
    }
  }
  return match_count;
}



/*
 * Decompiled function: Palette_Subsystem_004a9137
 * Entry Point: 0046af37
 * Size: 2076 bytes
 */


int32_t Palette_Subsystem_004a9137(int player_id,int card_slot,int32_t arg_3)

{
  char cVar1;
  int val_2;
  int val_3;
  int val_4;
  int player_idx;
  
  val_3 = *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20);
  val_4 = *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20);
  switch(arg_3) {
  case 0:
    Ai_Subsystem_004cc56d
              (arg_1,arg_1,arg_2,val_3,val_4,s_activates_Time_Elemental_effect__004f9428,0);
    Rules_CardLeavingPlay(val_3,val_4);
    break;
  case 1:
    val_2 = FUN_00439892(2);
    Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_casts_Twiddle_to_004f944c);
    if (val_2 == 0) {
      FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)&DAT_004f9468);
    }
    else {
      FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_untap__004f9460);
    }
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_3,val_4,&DAT_005f6810,0);
    if (val_2 == 0) {
      if (((&DAT_006826cc)[val_3 * 0x5b20 + val_4 * 0x120] & 0x10) == 0) {
        *(uint32_t *)(&DAT_006826cc + val_3 * 0x5b20 + val_4 * 0x120) =
             *(uint32_t *)(&DAT_006826cc + val_3 * 0x5b20 + val_4 * 0x120) | 0x10;
        if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + val_3 * 0x5b20 + val_4 * 0x120) * 0x34] & 1)
            != 0) {
          DAT_0068f0f4 = 0xffffffff;
        }
        FUN_0048c50b(val_3,val_4,0x81);
      }
    }
    else {
      *(uint32_t *)(&DAT_006826cc + val_3 * 0x5b20 + val_4 * 0x120) =
           *(uint32_t *)(&DAT_006826cc + val_3 * 0x5b20 + val_4 * 0x120) & 0xffffffef;
    }
    break;
  case 2:
    Ai_Subsystem_004cc56d
              (arg_1,arg_1,arg_2,val_3,val_4,s_activates_Aladdin_s_Ring_effect__004f9470,0);
    FUN_004612b0(arg_1,arg_2,0x71,4);
    break;
  case 3:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_3,val_4,s_casts_Ancestral_Recall__004f9494,0);
    FUN_00487ce1(val_3);
    FUN_00487ce1(val_3);
    FUN_00487ce1(val_3);
    break;
  case 4:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_Pandora_s_Box_effect__004f95c0,0);
    FUN_0041a30b();
    break;
  case 5:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_3,val_4,s_casts_Crumble__004f94b0,0);
    cVar1 = (&DAT_004ff597)[*(int *)(&DAT_006826c4 + val_3 * 0x5b20 + val_4 * 0x120) * 0x34];
    val_2 = FUN_0049aa14((int)(char)(&DAT_004ff598)
                                    [*(int *)(&DAT_006826c4 + val_3 * 0x5b20 + val_4 * 0x120) * 0x34
                                    ],0,99);
    (&DAT_00681ea8)[val_3] = (&DAT_00681ea8)[val_3] + cVar1 + val_2;
    FUN_0046e571(val_3,val_4,2);
    break;
  case 6:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_Bottle_of_Suleiman_eff_004f9560,0);
    val_3 = Ai_Subsystem_004cc56d
                      (arg_1,arg_1,arg_2,-1,-1,s_Call_the_coin_flip__Heads_Tails_004f9588,1);
    val_4 = FUN_004491fe(s_Bottle_of_Suleiman_004f95ac);
    if (val_4 == val_3) {
      val_3 = FUN_004d7d5e(0x37a);
      val_3 = Deck_AddCardToDeck(arg_1,val_3);
      if (val_3 != -1) {
        Pic_Subsystem_0042ac1f(arg_1,val_3);
        *(uint32_t *)(&DAT_006826f8 + arg_1 * 0x5b20 + val_3 * 0x120) =
             *(uint32_t *)(&DAT_006826f8 + arg_1 * 0x5b20 + val_3 * 0x120) | 0x10;
      }
    }
    else {
      Mem_AllocOrFree_004afd1c(arg_1,5,arg_1,arg_2);
    }
    break;
  case 7:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_3,val_4,s_casts_Disenchant__004f94c0,0);
    FUN_0046e571(val_3,val_4,1);
    break;
  case 8:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_3,val_4,s_casts_Healing_Salve__004f94d4,0);
    (&DAT_00681ea8)[val_3] = (&DAT_00681ea8)[val_3] + 3;
    break;
  case 9:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_3,val_4,s_casts_Fissure__004f94ec,0);
    FUN_0046e571(val_3,val_4,1);
    break;
  case 10:
    Ai_Subsystem_004cc56d
              (arg_1,arg_1,arg_2,val_3,val_4,s_activates_Disrupting_Sceptre_eff_004f95e4,0);
    Palette_Color_0049ae00(val_3,0,0);
    break;
  case 0xb:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_3,val_4,s_activates_Millstone_effect__004f94fc,0);
    for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
      val_4 = *(int *)(&DAT_006669f0 + val_3 * 2000);
      if (val_4 != -1) {
        FUN_004d7acc(val_3,0);
        val_4 = Deck_AddCardToDeck(val_3,val_4);
        if (val_4 != -1) {
          FUN_0046f02d(val_3,val_4);
          *(int32_t *)(&DAT_006826c4 + val_4 * 0x120 + val_3 * 0x5b20) = 0xffffffff;
        }
      }
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x18);
      }
    }
    break;
  case 0xc:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_The_Hive_effect__004f951c,0);
    val_3 = FUN_00439892(2);
    val_4 = FUN_004d7d5e(0x375);
    val_4 = Deck_AddCardToDeck(val_3,val_4);
    if (val_4 != -1) {
      Pic_Subsystem_0042ac1f(val_3,val_4);
      *(uint32_t *)(&DAT_006826f8 + val_4 * 0x120 + val_3 * 0x5b20) =
           *(uint32_t *)(&DAT_006826f8 + val_4 * 0x120 + val_3 * 0x5b20) | 0x10;
    }
    break;
  case 0xd:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_activates_Nevinyrral_s_Disk_effe_004f9538,0);
    FUN_00467d65(FUN_0041698a,-1);
    break;
  case 0xe:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_casts_Fog_effect__004f960c,0);
    val_3 = FUN_004a2b00(arg_1,arg_2,DAT_00666438,-1,-1);
    if (val_3 != -1) {
      *(int32_t *)(&DAT_00682704 + arg_1 * 0x5b20 + val_3 * 0x120) = DAT_004f9330;
    }
    break;
  case 0xf:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_3,val_4,s_activates_Sinbad_effect__004f9620,0);
    val_4 = FUN_00487ce1(val_3);
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_3,val_4,s_Sinbad_draws____004f963c,0);
    if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + val_4 * 0x120 + val_3 * 0x5b20) * 0x34] & 1) == 0)
    {
      FUN_0046f02d(val_3,val_4);
      *(int32_t *)(&DAT_006826c4 + val_4 * 0x120 + val_3 * 0x5b20) = 0xffffffff;
      (&DAT_0068ee78)[val_3] = (&DAT_0068ee78)[val_3] + -1;
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x18);
      }
    }
    break;
  default:
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,val_3,val_4,s_made_an_error__004f964c,0);
  }
  return 0;
}



/*
 * Decompiled function: UI_PromptFastEffectsDialog
 * Entry Point: 0046b7a0
 * Size: 4139 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t UI_PromptFastEffectsDialog(int arg1,uint32_t *arg2)

{
  bool flag_1;
  uint32_t uval_2;
  int32_t uval_3;
  int val_4;
  uint32_t uval_5;
  int local_84;
  int local_7c;
  int local_78;
  uint8_t local_74;
  int local_70;
  uint32_t local_68 [16];
  uint32_t local_28;
  int local_24;
  uint32_t loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if ((int)(&DAT_00681ea8)[DAT_00676510] < 1) {
    *(uint32_t *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) =
         *(uint32_t *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) | 2;
  }
  target_idx = 0;
  if (((DAT_0066aaf4 != 1) && (DAT_00666458 == DAT_0066aac4)) && (DAT_0066ab04 == DAT_0068f2c4)) {
    DAT_0068eee4 = 0;
  }
  if (arg1 == 1) {
    card_idx = 0;
  }
  else {
    card_idx = FUN_0042aa48(DAT_0068f2c4);
  }
  Mem_AllocOrFree_004d9630(local_68,arg2);
  uval_3 = DAT_00681eb4;
  uval_2 = DAT_00681eb0;
  player_idx = arg1;
  DAT_00681eb4 = arg1;
  local_24 = arg1;
  DAT_0068edd4 = 1;
  DAT_006826b4 = DAT_0068ef98 & 0x30;
  _DAT_0068f368 = 0;
  DAT_00666740 = DAT_00666740 + 1;
  if (DAT_00666740 < DAT_00681ed0) {
    DAT_00681ed0 = 0;
  }
  _DAT_0052243c = 2;
  _DAT_00522440 = 0x20;
  if (0x16 < DAT_0068f2c4) {
    _DAT_0052243c = 4;
    _DAT_00522440 = 0x40;
  }
  if (DAT_0068f2c4 < 0x15) {
    _DAT_0052243c = 1;
    _DAT_00522440 = 0x10;
  }
  if (0x1d < DAT_0068f2c4) {
    _DAT_0052243c = 8;
    _DAT_00522440 = 0xffffff80;
  }
  if (DAT_0068f2c4 == 0x1f) {
    _DAT_0052243c = 0xf;
    _DAT_00522440 = 0xfffffff0;
  }
  if ((DAT_00676504 == arg1) && (DAT_0068efb0 == DAT_00676510)) {
    _DAT_0052243c = 0xf;
    _DAT_00522440 = 0xfffffff0;
  }
  if (((((DAT_0066aaf4 == 1) || (DAT_0067650c != 0)) ||
       ((DAT_0068f230 != -1 && (DAT_00676504 == DAT_00681ec4)))) || (DAT_00666744 == 4)) ||
     ((DAT_00676504 == arg1 && ((DAT_00681eb0 & 0x200) != 0)))) {
    local_84 = FUN_0046c7d0(arg1);
    player_idx = DAT_0068eef0;
  }
  else {
    local_84 = -1;
  }
  loop_idx = 0;
  if ((local_84 != -1) && (val_4 = FUN_0046e4c9(player_idx,local_84,0x7d,local_24), val_4 == 2)) {
    FUN_0048a1c7(player_idx,local_84,local_24);
    local_84 = -1;
    FUN_00451482(0,0xff);
  }
  if (local_84 != -1) {
    _DAT_0068f0d4 = *(int *)(&DAT_006826c4 + local_84 * 0x120 + player_idx * 0x5b20);
    color_idx = _DAT_0068f0d4;
    if (((&DAT_006826cc)[local_84 * 0x120 + player_idx * 0x5b20] & 2) == 0) {
      val_4 = FUN_00488598(player_idx,local_84);
      if (val_4 != 0) {
        if ((&DAT_004ff594)[color_idx * 0x34] == ' ') {
          DAT_006826b4 = DAT_0068ef98 & 0x20;
        }
        loop_idx = 1;
        FUN_00451482(0,0xff);
        if ((DAT_0066aaf4 != 1) && (val_4 = FUN_00439892(3), val_4 == 0)) {
          FUN_004d7e29(s_Didn_t_expect_that__did_ya__004f9660);
        }
      }
    }
    else {
      if (((*(int *)(&DAT_00682710 + local_84 * 0x120 + player_idx * 0x5b20) == DAT_0068f230) &&
          (DAT_00666760 != (code *)0x0)) && (DAT_0068f230 != -1)) {
        if (DAT_00666760 != (code *)0x0) {
          (*DAT_00666760)(player_idx,local_84);
        }
      }
      else {
        FUN_0048c907(player_idx,local_84,0x73,1 - player_idx,0xffffffff);
        val_4 = FUN_0048974c(player_idx,local_84);
        if (val_4 != 0) {
          FUN_0048a07d(player_idx,local_84);
        }
        DAT_00681ea4 = 0;
      }
      loop_idx = 1;
      FUN_00451482(0,0xff);
    }
  }
  local_28 = 0;
  slot_idx = 0;
  local_7c = -1;
  if ((DAT_0066aaf4 != 1) || ((DAT_0068f230 != -1 && (DAT_00676510 == DAT_00681ec4)))) {
    if ((DAT_00676510 == DAT_00681ec4) && (DAT_0068f230 != -1)) {
      for (local_24 = 0; local_24 < 2; local_24 = local_24 + 1) {
        for (local_70 = 0; local_70 < (int)(&DAT_00666408)[local_24]; local_70 = local_70 + 1) {
          if ((((&DAT_006826cc)[local_24 * 0x5b20 + local_70 * 0x120] & 2) != 0) &&
             (val_4 = FUN_0046e4c9(local_24,local_70,0x7d,arg1), val_4 != 0)) {
            if (val_4 == 2) {
              local_7c = local_70;
              match_count = local_24;
              player_idx = local_24;
              slot_idx = slot_idx + 1;
            }
            else {
              local_74 = (uint8_t)val_4;
              local_28 = local_28 | 1 << (local_74 & 0x1f);
            }
          }
          if (((((DAT_00666440 & 1) != 0) &&
               (*(int *)(&DAT_00682710 + local_24 * 0x5b20 + local_70 * 0x120) == DAT_0068f230)) &&
              (local_24 == DAT_00681ec4)) && (DAT_0068f230 != -1)) {
            local_28 = local_28 | 4;
            local_7c = local_70;
            match_count = local_24;
            player_idx = local_24;
            slot_idx = slot_idx + 1;
          }
        }
      }
    }
    if (local_7c == -1) {
      if (DAT_0066aaf4 == 1) goto LAB_0046c78c;
      if ((DAT_0068f230 == 0xca) && (*(int *)(&DAT_006667d0 + DAT_00666458 * 0x98) == 0)) {
        DAT_00666440 = 0;
      }
      if ((DAT_0068f230 == 0xce) && (*(int *)(&DAT_006667e8 + DAT_00666458 * 0x98) == 0)) {
        DAT_00666440 = 0;
      }
    }
    if (((local_7c != -1) || (local_28 != 0)) || (((DAT_00666440 & 1) != 0 && (DAT_0068ef98 != 0))))
    {
      DAT_00676500 = 0;
      DAT_00666440 = 0;
      local_78 = 0;
      for (local_70 = 0; local_70 < (int)(&DAT_00666408)[DAT_00676510]; local_70 = local_70 + 1) {
        if (((*(int *)(&DAT_006826c4 + local_70 * 0x120 + DAT_00676510 * 0x5b20) != -1) &&
            (((((&DAT_006827d4)[local_70 * 0x120 + DAT_00676510 * 0x5b20] & 1) != 0 ||
              (((&DAT_006827d4)[local_70 * 0x120 + DAT_00676510 * 0x5b20] & 0x10) != 0)) ||
             ((val_4 = FUN_0048ca2a(DAT_00676510,local_70), val_4 == 0 &&
              (DAT_00676510 == DAT_00681eb4)))))) &&
           (((uval_5 = FUN_0046cc45(DAT_00676510,local_70), 1 < (int)uval_5 ||
             ((((DAT_00666404 != 0 || (DAT_00666458 != DAT_00676510)) && ((uval_5 & 2) != 0)) ||
              ((DAT_00676500 & 2) != 0)))) &&
            (((DAT_00676510 != DAT_00681ec4 || (DAT_0068f230 == -1)) ||
             ((uval_5 != 2 || ((DAT_00676500 & 2) != 0)))))))) {
          if (((DAT_00676500 & 2) == 0) && (uval_5 != 2)) {
            if (uval_5 == 2) {
              local_28 = local_28 | 4;
            }
            else {
              local_28 = local_28 | 2;
            }
          }
          else {
            local_7c = local_70;
            match_count = DAT_00676510;
            slot_idx = slot_idx + 1;
          }
          DAT_00676500 = DAT_00676500 & 0xfffffffd;
        }
      }
      if (DAT_00666744 == 4) {
        for (local_70 = 0; local_70 < (int)(&DAT_00666408)[1 - DAT_00676510];
            local_70 = local_70 + 1) {
          if (((*(int *)(&DAT_006826c4 + local_70 * 0x120 + (1 - DAT_00676510) * 0x5b20) != -1) &&
              (((((&DAT_006827d4)[local_70 * 0x120 + (1 - DAT_00676510) * 0x5b20] & 1) != 0 ||
                (((&DAT_006827d4)[local_70 * 0x120 + (1 - DAT_00676510) * 0x5b20] & 0x10) != 0)) ||
               (val_4 = FUN_0048ca2a(1 - DAT_00676510,local_70), val_4 == 0)))) &&
             (val_4 = FUN_0046cc45(1 - DAT_00676510,local_70), (DAT_00676500 & 2) != 0)) {
            local_7c = local_70;
            match_count = 1 - DAT_00676510;
            slot_idx = slot_idx + 1;
            DAT_00676500 = DAT_00676500 & 0xfffffffd;
            if (val_4 == 2) {
              local_28 = local_28 | 4;
            }
            else {
              local_28 = local_28 | 2;
            }
            break;
          }
        }
      }
      if ((local_28 & 2) != 0) {
        target_idx = 1;
      }
    }
  }
  if (((target_idx != 0) || (card_idx != 0)) || (slot_idx != 0)) {
    Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Triggered_effects_____004f967c);
    if (((DAT_006826b4 & 0x10) == 0) || (DAT_0068ecd0 != -1)) {
      if ((DAT_006826b4 & 0x20) != 0) {
        Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Interrupts_____004f96a8);
      }
    }
    else {
      Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Fast_Effects_____004f9694);
    }
    if (DAT_0068f230 != -1) {
      Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Triggered_effects_____004f96b8);
    }
    FUN_004d9640((uint32_t *)&DAT_005f6810,local_68);
    if ((DAT_0068eee4 == 0) || ((local_28 & 2) != 0)) {
      if (((((card_idx == 0) && ((DAT_00666404 == 0 || (DAT_0068f230 != -1)))) &&
           ((target_idx == 0 || (DAT_0068f230 == -1)))) &&
          ((DAT_004fac20 == 0 || ((local_28 & 6) == 0)))) &&
         (((slot_idx <= (int)(uint32_t)((local_28 & 2) == 0) && ((local_28 & 4) == 0)) ||
          ((((local_78 == 0 && (val_4 = FUN_0042a99c(), val_4 != 0)) || (DAT_0068f230 == 0xd6)) ||
           ((local_7c != -1 && (DAT_00666740 == DAT_00681ed0)))))))) {
        local_84 = local_7c;
        player_idx = match_count;
        _DAT_0068f368 = 1;
      }
      else {
        DAT_00690314 = 1;
        DAT_0066aac4 = -1;
        DAT_00681ed0 = 0;
        flag_1 = false;
        while (!flag_1) {
          if (DAT_0066aaf4 == 1) {
            local_84 = local_7c;
            flag_1 = true;
            DAT_0068f2cc = -1;
          }
          else {
            local_84 = Ai_Subsystem_004bc029(DAT_00676510,-1,DAT_00676510,0xff,0,0x5f6810,2);
            player_idx = DAT_0068eef0;
            if (-1 < local_84) {
              *(uint32_t *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) =
                   *(uint32_t *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) | 2;
            }
          }
          if (DAT_0068f2cc == -3) {
            flag_1 = false;
          }
          else if (DAT_0068f2cc == -2) {
            flag_1 = true;
            local_84 = -1;
            DAT_00666758 = DAT_00666758 & 0xfffffffd;
            if (DAT_0068f230 != -1) {
              DAT_0066aac4 = DAT_00666458;
              DAT_0066ab04 = DAT_0068f2c4;
              DAT_0068f2cc = 0;
            }
            if (slot_idx != 0) {
              DAT_00681ed0 = DAT_00666740;
              DAT_0068eee4 = 1;
              _DAT_0068f368 = 1;
              DAT_0066ab04 = -1;
              DAT_0066aac4 = -1;
            }
          }
          else if (DAT_0068f2cc == 0) {
            if ((player_idx == -1) || (local_84 == -1)) {
              if ((player_idx != -1) && (local_84 == -1)) {
                flag_1 = false;
              }
            }
            else {
              flag_1 = true;
            }
          }
        }
      }
    }
    else {
      local_84 = local_7c;
      player_idx = match_count;
      if (local_7c != -1) {
        _DAT_0068f368 = 1;
      }
    }
    DAT_005f6810 = 0;
    if ((local_84 != -1) &&
       ((DAT_00676510 == player_idx ||
        (((((&DAT_006826cc)[local_84 * 0x120 + player_idx * 0x5b20] & 2) != 0 &&
          (val_4 = FUN_0046e4c9(player_idx,local_84,0x7d,DAT_00676510), val_4 != 0)) ||
         (DAT_00666744 == 4)))))) {
      color_idx = *(int *)(&DAT_006826c4 + local_84 * 0x120 + player_idx * 0x5b20);
      val_4 = FUN_0046cc45(player_idx,local_84);
      if (val_4 == 0) {
        val_4 = FUN_0042b120(player_idx,local_84);
        if (val_4 != 0) {
          FUN_0042b213(player_idx,local_84);
        }
      }
      else {
        if (((&DAT_006826cc)[local_84 * 0x120 + player_idx * 0x5b20] & 2) == 0) {
          FUN_00488598(player_idx,local_84);
          if ((&DAT_004ff594)[color_idx * 0x34] == ' ') {
            DAT_006826b4 = DAT_0068ef98 & 0x20;
          }
          val_4 = FUN_00439892(3);
          if (val_4 == 0) {
            FUN_004d7e29(s_I_knew_that_was_coming__004f96d0);
          }
        }
        else {
          val_4 = FUN_0046e4c9(player_idx,local_84,0x7d,DAT_00676510);
          if (val_4 == 0) {
            if (((*(int *)(&DAT_00682710 + local_84 * 0x120 + player_idx * 0x5b20) == DAT_0068f230) &&
                (DAT_00666760 != (code *)0x0)) && (DAT_0068f230 != -1)) {
              if (DAT_00666760 != (code *)0x0) {
                (*DAT_00666760)(player_idx,local_84);
              }
            }
            else {
              val_4 = FUN_0048974c(player_idx,local_84);
              if (((val_4 != 0) && (FUN_0048a07d(player_idx,local_84), DAT_00681ea4 != 1)) &&
                 (DAT_0066aaf4 != 1)) {
                FUN_0048d00c(0x1c);
              }
              DAT_00681ea4 = 0;
            }
          }
          else {
            FUN_0048a1c7(player_idx,local_84,DAT_00676510);
          }
        }
        FUN_00451482(0,0xff);
        loop_idx = loop_idx | 2;
      }
      loop_idx = loop_idx | 2;
    }
    DAT_00666440 = 1;
    _DAT_0068f368 = 0;
  }
LAB_0046c78c:
  if (loop_idx == 0) {
    DAT_006826b4 = DAT_0068ef98 & 0x30;
  }
  DAT_0068edd4 = 0;
  DAT_00681eb4 = uval_3;
  DAT_00681eb0 = uval_2;
  DAT_00666740 = DAT_00666740 + -1;
  return loop_idx;
}



/*
 * Decompiled function: FUN_0046c7d0
 * Entry Point: 0046c7d0
 * Size: 1141 bytes
 */


uint32_t FUN_0046c7d0(int player_id)

{
  int val_1;
  uint32_t uval_2;
  uint32_t auStack_68 [20];
  int target_idx;
  uint32_t player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  slot_idx = 0;
  if ((DAT_0068f230 != -1) && (DAT_00676504 == DAT_00681ec4)) {
    for (card_idx = 0; card_idx < 2; card_idx = card_idx + 1) {
      for (player_idx = 0; (int)player_idx < (int)(&DAT_00666408)[card_idx]; player_idx = player_idx + 1) {
        if ((((&DAT_006826cc)[card_idx * 0x5b20 + player_idx * 0x120] & 2) != 0) &&
           (val_1 = FUN_0046e4c9(card_idx,player_idx,0x7d,arg_1), val_1 == 2)) {
          DAT_00666758 = 4;
          DAT_0068eef0 = card_idx;
          return player_idx;
        }
        if ((((arg_1 == card_idx) &&
             (*(int *)(&DAT_00682710 + card_idx * 0x5b20 + player_idx * 0x120) == DAT_0068f230)) &&
            (card_idx == DAT_00681ec4)) && (DAT_0068f230 != -1)) {
          DAT_00666758 = DAT_00666758 | 4;
          DAT_00666454 = DAT_00666454 + 1;
          DAT_0068eef0 = card_idx;
          return player_idx;
        }
      }
    }
  }
  if (((((uint8_t)DAT_00666440 & 2) == 0) || (arg_1 == DAT_00676510)) || (DAT_0068ef98 == 0)) {
    uval_2 = 0xffffffff;
  }
  else {
    DAT_0068eef0 = arg_1;
    for (player_idx = 0; (int)player_idx < (int)(&DAT_00666408)[arg_1]; player_idx = player_idx + 1) {
      match_count = *(int *)(&DAT_006826c4 + player_idx * 0x120 + arg_1 * 0x5b20);
      if ((match_count != -1) && (target_idx = FUN_0046cc45(arg_1,player_idx), target_idx != 0)) {
        auStack_68[slot_idx] = player_idx;
        slot_idx = slot_idx + 1;
        if (target_idx == 2) {
          return player_idx;
        }
      }
    }
    if (DAT_00666744 == 4) {
      for (player_idx = 0; (int)player_idx < (int)(&DAT_00666408)[1 - arg_1]; player_idx = player_idx + 1) {
        match_count = *(int *)(&DAT_006826c4 + player_idx * 0x120 + (1 - arg_1) * 0x5b20);
        if (((match_count != -1) && (target_idx = FUN_0046cc45(1 - arg_1,player_idx), target_idx != 0)) &&
           (target_idx == 2)) {
          DAT_0068eef0 = 1 - arg_1;
          return player_idx;
        }
      }
    }
    if (DAT_00666744 == 4) {
      uval_2 = 0xffffffff;
    }
    else {
      auStack_68[slot_idx] = 0xffffffff;
      slot_idx = slot_idx + 1;
      if (DAT_0066aaf4 == 1) {
        val_1 = FUN_00439892(2);
        if ((val_1 == 0) || (val_1 = Mem_AllocOrFree_004308cf(), val_1 == 0)) {
          DAT_0068f2c8 = FUN_00439892(slot_idx);
        }
        else {
          DAT_0068f2c8 = slot_idx + -1;
        }
        if ((DAT_0066aadc != 0) && (DAT_0068f2c8 = slot_idx + -1, DAT_0066aadc == 1)) {
          DAT_0066aadc = -1;
        }
        DAT_0068f0bc = (-(uint32_t)((*(uint32_t *)(&DAT_006826cc +
                                          arg_1 * 0x5b20 + auStack_68[DAT_0068f2c8] * 0x120) & 2) ==
                               0) & 0xfffff000) + 0x2000 | auStack_68[DAT_0068f2c8] |
                       (arg_1 == 0) - 1 & 0x100;
        DAT_004f3c6c = 4;
        FUN_0043064a();
      }
      else {
        DAT_004f3c6c = 4;
        FUN_004307b2();
        if (slot_idx <= DAT_0068f2c8) {
          DAT_0068f2c8 = slot_idx + -1;
        }
      }
      if (auStack_68[DAT_0068f2c8] != 0xffffffff) {
        if (0xf < DAT_0066aae4) {
          DAT_0066aae4 = DAT_0066aae4 + -1;
        }
        *(int32_t *)(&DAT_0068ef00 + DAT_0066aae4 * 4) =
             *(int32_t *)(&DAT_006826c4 + arg_1 * 0x5b20 + auStack_68[DAT_0068f2c8] * 0x120);
        *(uint32_t *)(&DAT_00666770 + DAT_0066aae4 * 4) = auStack_68[DAT_0068f2c8];
        DAT_0066aae4 = DAT_0066aae4 + 1;
      }
      uval_2 = auStack_68[DAT_0068f2c8];
    }
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_0046cc45
 * Entry Point: 0046cc45
 * Size: 1260 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t FUN_0046cc45(int arg1,int arg2)

{
  int val_1;
  int val_2;
  uint8_t match_count;
  
  val_1 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
  if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
    if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0xa0) != 0) {
      return 0;
    }
    if ((DAT_0068f230 != -1) && (*(code **)(&DAT_004ff5a0 + val_1 * 0x34) != Palette_Color_0049ae00)
       ) {
      return 0;
    }
    if ((DAT_004fab48 != 0) && (((&DAT_004ff594)[val_1 * 0x34] & 0x20) == 0)) {
      return 0;
    }
    if (((((DAT_006826b4 & (uint8_t)(&DAT_004ff594)[val_1 * 0x34]) != 0) &&
         (val_2 = FUN_004895b4(arg1,arg1,arg2), val_2 != 0)) &&
        ((((uint8_t)DAT_00681eb0 & 4) == 0 || ((*(uint32_t *)(&DAT_004ff5a8 + val_1 * 0x34) & 0x3004) != 0)
         ))) && (((DAT_00676510 == arg1 ||
                  ((_DAT_0052243c & (int)(char)(&DAT_004ff5ad)[val_1 * 0x34]) != 0)) &&
                 (val_1 = FUN_0048c907(arg1,arg2,0x74,1 - arg1,0xffffffff), val_1 != 0)))) {
      return 3;
    }
  }
  else {
    if ((*(int *)(&DAT_00682710 + arg2 * 0x120 + arg1 * 0x5b20) == DAT_0068f230) &&
       (DAT_0068f230 != -1)) {
      if (arg1 == DAT_00681ec4) {
        DAT_00666758 = DAT_00666758 | 4;
        DAT_00666454 = DAT_00666454 + 1;
        return 2;
      }
      return 0;
    }
    if (DAT_0068f230 != -1) {
      val_1 = FUN_0046e4c9(arg1,arg2,0x7d,arg1);
      if (val_1 == 0) {
        return 0;
      }
      match_count = (uint8_t)val_1;
      DAT_00666758 = DAT_00666758 | 1 << (match_count & 0x1f);
      DAT_00666454 = DAT_00666454 + 1;
      if (1 < val_1) {
        return 2;
      }
      return 3;
    }
    if ((((((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 1) == 0) &&
         (((&DAT_004ff5a8)[val_1 * 0x34] & 1) != 0)) && ((DAT_006826b4 & 0x10) != 0)) ||
       ((((&DAT_004ff5a8)[val_1 * 0x34] & 2) != 0 && ((DAT_006826b4 & 0x20) != 0)))) {
      if ((DAT_004fab48 != 0) && (((&DAT_004ff5a8)[val_1 * 0x34] & 2) == 0)) {
        return 0;
      }
      if (((((uint8_t)DAT_00681eb0 & 4) == 0) ||
          ((*(uint32_t *)(&DAT_004ff5a8 + val_1 * 0x34) & 0x5004) != 0)) &&
         (((DAT_00676500 = DAT_00676500 & 0xfffffffd, DAT_00676510 == arg1 ||
           ((_DAT_00522440 & (int)(char)(&DAT_004ff5ad)[val_1 * 0x34]) != 0)) &&
          ((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0 &&
           (val_1 = FUN_0048c907(arg1,arg2,0x73,1 - arg1,0xffffffff), val_1 != 0)))))) {
        if ((DAT_00676500 & 2) != 0) {
          DAT_00666758 = DAT_00666758 | 4;
          return 2;
        }
        DAT_00666758 = DAT_00666758 | 2;
        return 3;
      }
    }
    if ((DAT_00666744 == 4) && (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0)) {
      DAT_00676500 = DAT_00676500 | 3;
      DAT_00666758 = DAT_00666758 | 4;
      return 2;
    }
    if ((((DAT_00666744 == 4) && (arg1 == DAT_00681eb4)) &&
        (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) &&
       ((((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 0x88) == 0 &&
        (val_1 = FUN_0048ed18(arg1,arg2), val_1 != 0)))) {
      DAT_00666758 = DAT_00666758 | 2;
      if (DAT_00676504 == arg1) {
        return 2;
      }
      return 3;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_0046d140
 * Entry Point: 0046d140
 * Size: 840 bytes
 */


int32_t FUN_0046d140(void)

{
  int32_t uval_1;
  
  if (DAT_00666744 == 0x8e) {
    if (DAT_006826b0 == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else if (((((DAT_00666744 == 0x6a) || (DAT_00666744 == 0x6b)) || (DAT_00666744 == 0x6c)) ||
           ((((DAT_00666744 == 0x6d || (DAT_00666744 == 0x6e)) ||
             ((DAT_00666744 == 0x6f || ((DAT_00666744 == 0x70 || (DAT_00666744 == 0x71)))))) ||
            ((DAT_00666744 == 0x72 ||
             ((((DAT_00666744 == 0x73 || (DAT_00666744 == 0x74)) || (DAT_00666744 == 0x75)) ||
              ((DAT_00666744 == 0x76 || (DAT_00666744 == 0x77)))))))))) ||
          (((DAT_00666744 == 0x78 || ((DAT_00666744 == 0x79 || (DAT_00666744 == 0x7a)))) ||
           (((DAT_00666744 == 0x7b ||
             ((((DAT_00666744 == 0x7c || (DAT_00666744 == 0x7d)) || (DAT_00666744 == 0x7e)) ||
              (((DAT_00666744 == 0x7f || (DAT_00666744 == 0x80)) ||
               ((DAT_00666744 == 0x81 || ((DAT_00666744 == 0x82 || (DAT_00666744 == 0x83))))))))))
            || ((((DAT_00666744 == 0x84 ||
                  ((((((DAT_00666744 == 0x85 || (DAT_00666744 == 0x86)) || (DAT_00666744 == 0x87))
                     || (((DAT_00666744 == 0x88 || (DAT_00666744 == 0x89)) ||
                         ((DAT_00666744 == 0x8e || ((DAT_00666744 == 199 || (DAT_00666744 == 200))))
                         )))) || (DAT_00666744 == 0xc9)) ||
                   ((((((DAT_00666744 == 0xca || (DAT_00666744 == 0xcb)) || (DAT_00666744 == 0xcc))
                      || ((DAT_00666744 == 0xcd || (DAT_00666744 == 0xce)))) ||
                     (DAT_00666744 == 0xcf)) || ((DAT_00666744 == 0xd2 || (DAT_00666744 == 0xd3)))))
                   ))) || (((DAT_00666744 == 0xd4 ||
                            (((DAT_00666744 == 0xd5 || (DAT_00666744 == 0xd6)) ||
                             (DAT_00666744 == 0xd7)))) ||
                           (((DAT_00666744 == 0xd8 || (DAT_00666744 == 0xd9)) ||
                            (DAT_00666744 == 0xdc)))))) || (DAT_00666744 == 0xdb)))))))) {
    uval_1 = 0;
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: Rules_ProcessDamagePrevention
 * Entry Point: 0046d497
 * Size: 1142 bytes
 */


void Rules_ProcessDamagePrevention(void)

{
  bool flag_1;
  int val_2;
  int target_idx;
  int player_idx;
  int card_idx;
  int32_t match_count;
  
  if ((DAT_00681eb0 & 2) == 0) {
    return;
  }
  DAT_00681eb0 = DAT_00681eb0 & 0xfffffffd;
  DAT_00681eb0 = DAT_00681eb0 | 4;
  FUN_00451482(0,0xff);
  for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
    for (target_idx = 0; target_idx < (int)(&DAT_00666408)[player_idx]; target_idx = target_idx + 1) {
      if (((*(int *)(&DAT_006826c4 + target_idx * 0x120 + player_idx * 0x5b20) == DAT_0068f104) &&
          (((&DAT_006826cc)[target_idx * 0x120 + player_idx * 0x5b20] & 2) != 0)) &&
         (((&DAT_006826cc)[target_idx * 0x120 + player_idx * 0x5b20] & 0x10) == 0)) {
        FUN_0048c50b(player_idx,target_idx,0x21);
      }
    }
  }
  flag_1 = false;
  do {
    if ((DAT_0066aaf4 != 1) && (DAT_0067650c == 0)) {
      FUN_0048b5c9(9,0xf);
      card_idx = -99999;
      flag_1 = true;
    }
    while( true ) {
      if ((DAT_00666400 == 9) && (flag_1)) {
        FUN_004305d3();
        DAT_0068ecbc = 0;
        DAT_0068ecb8 = 0;
        DAT_0066aae4 = 0;
        DAT_0068f2d4 = 0;
      }
      val_2 = FUN_0048e32b(-2,0xffffffff,s_Damage_prevention_004f96e8,0x8e);
      if (val_2 != 0) break;
      Magic_ScanCards(0x25);
      for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
        for (target_idx = 0; target_idx < (int)(&DAT_00666408)[player_idx]; target_idx = target_idx + 1) {
          if (((*(int *)(&DAT_006826c4 + target_idx * 0x120 + player_idx * 0x5b20) == DAT_0068f104) &&
              (((&DAT_006826cc)[target_idx * 0x120 + player_idx * 0x5b20] & 2) != 0)) &&
             (((&DAT_006826cc)[target_idx * 0x120 + player_idx * 0x5b20] & 0x10) == 0)) {
            FUN_0048c50b(player_idx,target_idx,0x6e);
          }
        }
      }
      FUN_0048e8a8(DAT_00666458,0xd7,s_Damage_Dealing_004f96fc,0);
      for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
        for (target_idx = 0; target_idx < (int)(&DAT_00666408)[player_idx]; target_idx = target_idx + 1) {
          if ((*(int *)(&DAT_006826c4 + target_idx * 0x120 + player_idx * 0x5b20) == DAT_0068f104) &&
             (((&DAT_006826cc)[target_idx * 0x120 + player_idx * 0x5b20] & 2) != 0)) {
            if (((&DAT_006826cc)[target_idx * 0x120 + player_idx * 0x5b20] & 0x10) == 0) {
              DAT_00681eb0 = DAT_00681eb0 | 2;
            }
            else {
              FUN_0046e571(player_idx,target_idx,1);
            }
          }
        }
      }
      FUN_0046d90d();
      DAT_00681eb0 = DAT_00681eb0 & 0xfffffffb;
      if (((DAT_0066aaf4 != 1) || (!flag_1)) || (DAT_00666400 != 9)) {
        if (DAT_0066aaf4 == 1) {
          return;
        }
        if (!flag_1) {
          return;
        }
        DAT_0067650c = 0;
        return;
      }
      Rules_SendCardsToGraveyard();
      val_2 = FUN_00430911(DAT_00676504);
      val_2 = DAT_0068f2d4 + val_2;
      if (card_idx < val_2) {
        FUN_0043081e();
        match_count = DAT_006663f8;
        card_idx = val_2;
      }
      if (DAT_0066aae0 == 999) {
        DAT_0066aae0 = -1;
      }
      DAT_0066aadc = 0;
      val_2 = Mem_AllocOrFree_0049f553();
      if ((DAT_0068ef94 * DAT_005071bc) / 5 < val_2) {
        DAT_0066aaf4 = 0;
        DAT_0066aae0 = -1;
        DAT_006663f8 = match_count;
      }
      DAT_00681eb0 = DAT_00681eb0 | 4;
    }
  } while( true );
}



/*
 * Decompiled function: FUN_0046d90d
 * Entry Point: 0046d90d
 * Size: 317 bytes
 */


void FUN_0046d90d(void)

{
  short len_1;
  int val_2;
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 2; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < (int)(&DAT_00666408)[slot_idx]; match_count = match_count + 1) {
      if (((*(int *)(&DAT_006826c4 + match_count * 0x120 + slot_idx * 0x5b20) != -1) &&
          (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + match_count * 0x120 + slot_idx * 0x5b20) * 0x34] & 2
           ) != 0)) && (((&DAT_006826cc)[match_count * 0x120 + slot_idx * 0x5b20] & 2) != 0)) {
        len_1 = *(short *)(&DAT_006826d0 + match_count * 0x120 + slot_idx * 0x5b20);
        val_2 = FUN_0048b81a(slot_idx,match_count,0x33,0xffffffff);
        if (val_2 <= len_1) {
          if (DAT_0066aaf4 != 1) {
            FUN_0048d00c(0x19);
          }
          FUN_0046e571(slot_idx,match_count,2);
        }
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_0046da4a
 * Entry Point: 0046da4a
 * Size: 2677 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0046da4a(int arg1,int arg2)

{
  int val_1;
  int val_2;
  int event_type;
  int player_idx;
  int match_count;
  
  DAT_0068f100 = 1;
  *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
       *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) | 0x800;
  val_1 = FUN_0048a33f(arg1,arg2);
  if (((((val_1 == 0) || (DAT_0068f2c4 != 0x15)) || (DAT_00666458 != arg1)) ||
      ((((&DAT_006826cd)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) == 0 ||
       (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0)))) ||
     (val_1 = FUN_0048ad82(arg1,arg2), val_1 == 0)) {
    if ((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) || (DAT_0068f230 == -1)) {
      if ((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) &&
         ((DAT_0068f230 != -1 &&
          (*(code **)(&DAT_004ff5a0 + *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34)
           != Palette_Color_0049ae00)))) {
        match_count = 0;
      }
      else if ((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) || (DAT_0068f2c4 != 1)) {
        if (DAT_00676510 == arg1) {
          val_1 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
          if ((DAT_0068edd4 == 0) && ((DAT_0068f2c4 == 0x15 || (DAT_0068f2c4 == 0x17)))) {
            if (((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) != 0) &&
                (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0)) &&
               (((&DAT_004ff594)[val_1 * 0x34] & 2) != 0)) {
              if (((DAT_00666458 == arg1) && (val_1 = FUN_0048ad82(arg1,arg2), val_1 != 0)) &&
                 (((&DAT_006826ce)[arg2 * 0x120 + arg1 * 0x5b20] & 1) == 0)) {
                DAT_0068f100 = 0;
                return 0x10;
              }
              if ((DAT_00666458 != arg1) && (DAT_006826b0 != 0)) {
                DAT_0068f100 = 0;
                return 0x20;
              }
            }
            *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
            match_count = 0;
          }
          else {
            if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 2) == 0) {
              if (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0xa0) != 0) {
                *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
                     *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
                DAT_0068f100 = 0;
                return 0;
              }
              FUN_0048c367((&DAT_004ff596)[val_1 * 0x34]);
              if ((DAT_0068edd4 == 0) || ((DAT_006826b4 & (uint8_t)(&DAT_004ff594)[val_1 * 0x34]) != 0)
                 ) {
                if (((&DAT_004ff594)[val_1 * 0x34] & 1) != 0) {
                  if (((DAT_00666458 == arg1) && (((uint8_t)DAT_00681eb0 & 1) == 0)) &&
                     ((DAT_0068f2c4 == 0x14 || (DAT_0068f2c4 == 0x1e)))) {
                    DAT_0068f100 = 0;
                    return 4;
                  }
                  *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
                       *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
                  DAT_0068f100 = 0;
                  return 0;
                }
                if (((DAT_00666458 == DAT_00676510) ||
                    (((DAT_00666458 != DAT_00676510 && (DAT_0068edd4 != 0)) &&
                     ((((&DAT_004ff594)[val_1 * 0x34] & 0x10) != 0 ||
                      (((&DAT_004ff594)[val_1 * 0x34] & 0x20) != 0)))))) &&
                   ((val_2 = FUN_004895b4(arg1,arg1,arg2), val_2 != 0 &&
                    (((((uint8_t)DAT_00681eb0 & 4) == 0 ||
                      ((*(uint32_t *)(&DAT_004ff5a8 + val_1 * 0x34) & 0x3004) != 0)) &&
                     ((((&DAT_004ff594)[val_1 * 0x34] & 0x42) != 0 ||
                      (val_1 = FUN_0048c907(arg1,arg2,0x74,1 - arg1,0xffffffff), val_1 != 0))))))))
                {
                  DAT_0068f100 = 0;
                  return 4;
                }
              }
            }
            else {
              if ((DAT_00666744 == 4) && (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0))
              {
                DAT_00676500 = DAT_00676500 | 3;
                DAT_00666758 = DAT_00666758 | 4;
                DAT_0068f100 = 0;
                return 2;
              }
              if ((((DAT_00666744 == 4) &&
                   (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) &&
                  (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 0x88) == 0)) &&
                 (val_2 = FUN_0048ed18(arg1,arg2), val_2 != 0)) {
                DAT_00666758 = DAT_00666758 | 2;
                DAT_0068f100 = 0;
                return 8;
              }
              if (((((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) &&
                    (((&DAT_004ff594)[val_1 * 0x34] & 2) != 0)) &&
                   ((DAT_0068edd4 == 0 && ((DAT_00666458 == arg1 && (DAT_0068f2c4 < 0x1b)))))) &&
                  (val_2 = FUN_0048ad82(arg1,arg2), val_2 != 0)) &&
                 ((((&DAT_006826ce)[arg2 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
                  (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] &
                   2) == 0)))) {
                _DAT_0068f0b4 = 1;
              }
              if (((((((&DAT_004ff5a9)[val_1 * 0x34] & 0x10) != 0) &&
                    (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0)) &&
                   ((((&DAT_006826ce)[arg2 * 0x120 + arg1 * 0x5b20] & 3) == 0 ||
                    (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34]
                     & 2) == 0)))) ||
                  (((((&DAT_004ff5a8)[val_1 * 0x34] & 1) != 0 && ((DAT_006826b4 & 0x10) != 0)) ||
                   ((((&DAT_004ff5a8)[val_1 * 0x34] & 2) != 0 && ((DAT_006826b4 & 0x20) != 0))))))
                 && ((((((uint8_t)DAT_00681eb0 & 4) == 0 ||
                       ((*(uint32_t *)(&DAT_004ff5a8 + val_1 * 0x34) & 0x5004) != 0)) &&
                      (DAT_00676500 = DAT_00676500 & 0xfffffffd,
                      ((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0)) &&
                     (val_1 = FUN_0048c907(arg1,arg2,0x73,1 - arg1,0xffffffff), val_1 != 0)))) {
                if ((DAT_00676500 & 2) != 0) {
                  DAT_00666758 = DAT_00666758 | 4;
                  DAT_0068f100 = 0;
                  return 2;
                }
                DAT_00666758 = DAT_00666758 | 2;
                DAT_0068f100 = 0;
                return 8;
              }
            }
            *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
            match_count = 0;
          }
        }
        else if ((DAT_00666744 == 4) && (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0))
        {
          DAT_00676500 = DAT_00676500 | 3;
          DAT_00666758 = DAT_00666758 | 4;
          match_count = 2;
        }
        else {
          *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffff7ff;
          match_count = 0;
        }
      }
      else {
        DAT_0068ecb0 = arg1;
        DAT_00690c48 = arg2;
        DAT_0066642c = 0;
        Magic_ScanCards(0x7d);
        match_count = DAT_0066642c;
      }
    }
    else {
      if (*(int *)(&DAT_00682710 + arg2 * 0x120 + arg1 * 0x5b20) == DAT_0068f230) {
        if (arg1 == DAT_00681ec4) {
          player_idx = 2;
        }
        else {
          player_idx = 0;
        }
      }
      else {
        arg_3 = 2;
        val_2 = 0;
        val_1 = FUN_0046e4c9(arg1,arg2,0x7d,arg1);
        player_idx = FUN_0049aa14(val_1,val_2,arg_3);
      }
      if (player_idx == 0) {
        match_count = 0;
      }
      else {
        DAT_00666758 = DAT_00666758 | 1 << ((uint8_t)player_idx & 0x1f);
        DAT_00666454 = DAT_00666454 + 1;
        match_count = player_idx;
      }
    }
  }
  else {
    match_count = 2;
  }
  DAT_0068f100 = 0;
  return match_count;
}



/*
 * Decompiled function: FUN_0046e4c9
 * Entry Point: 0046e4c9
 * Size: 168 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t FUN_0046e4c9(int x,int y,int width,int32_t arg_4)

{
  int32_t uval_1;
  
  if ((width == 0x7d) &&
     ((((&DAT_006826cd)[y * 0x120 + x * 0x5b20] & 1) != 0 || (DAT_006663f4 != 0)))) {
    uval_1 = 0;
  }
  else if (DAT_0068f230 < 200) {
    uval_1 = 0;
  }
  else {
    DAT_0066642c = 0;
    DAT_0068ecb0 = x;
    DAT_00690c48 = y;
    _DAT_0068ee68 = arg_4;
    DAT_0068ecfc = 0xffffffff;
    Magic_ScanCards(width);
    uval_1 = DAT_0066642c;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0046e571
 * Entry Point: 0046e571
 * Size: 546 bytes
 */


void FUN_0046e571(int player_id,int card_slot,int event_type)

{
  int val_1;
  
  if (((arg_1 != -1) && (arg_2 != -1)) &&
     (((&DAT_006826f8)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x80) == 0)) {
    *(uint32_t *)(&DAT_006826f8 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint32_t *)(&DAT_006826f8 + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x80;
    val_1 = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120);
    if (val_1 != -1) {
      if (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) == 0) {
        arg_3 = 3;
      }
      if (((((&DAT_006826f8)[arg_1 * 0x5b20 + arg_2 * 0x120] & 8) == 0) && (arg_3 != 3)) &&
         ((arg_3 != 4 &&
          ((((&DAT_004ff594)[val_1 * 0x34] & 3) != 0 && ((&DAT_004ff594)[val_1 * 0x34] != -0x80)))))
         ) {
        (&DAT_006826e0)[arg_1 * 0x5b20 + arg_2 * 0x120] = (uint8_t)arg_3;
        *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) | 2;
        if (((&DAT_004ff594)[val_1 * 0x34] & 2) == 0) {
          Rules_CardLeavingPlay(arg_1,arg_2);
        }
        else {
          *(int32_t *)(&DAT_00682710 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0xd6;
        }
        DAT_00666760 = Rules_CardLeavingPlay;
      }
      else {
        (&DAT_006826e0)[arg_1 * 0x5b20 + arg_2 * 0x120] = (uint8_t)arg_3;
        Rules_CardLeavingPlay(arg_1,arg_2);
      }
    }
  }
  return;
}



/*
 * Decompiled function: Rules_SendCardsToGraveyard
 * Entry Point: 0046e793
 * Size: 191 bytes
 */


int32_t Rules_SendCardsToGraveyard(void)

{
  if ((DAT_00666760 != 0) && (DAT_004f965c == 0)) {
    DAT_004f965c = 1;
    DAT_00681eb0 = DAT_00681eb0 | 0x200;
    FUN_0048e32b(-2,DAT_0068f2c4,s_Use_Regeneration_Effects_004f970c,0x70);
    DAT_00681eb0 = DAT_00681eb0 & 0xfffffdff;
    FUN_0048e8a8(DAT_00666458,0xd6,s_Graveyard_order_004f9728,0);
    FUN_0048e8a8(DAT_00666458,0xd5,s_Card_s__to_Graveyard_004f9738,0);
    DAT_00666760 = 0;
    DAT_004f965c = 0;
    FUN_00451482(0,0xff);
  }
  return 0;
}



/*
 * Decompiled function: Rules_CardLeavingPlay
 * Entry Point: 0046e852
 * Size: 1226 bytes
 */


int32_t Rules_CardLeavingPlay(int arg1,int arg2)

{
  char cVar1;
  int val_2;
  int32_t uval_3;
  int32_t uval_4;
  
  val_2 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
  cVar1 = (&DAT_006826e0)[arg2 * 0x120 + arg1 * 0x5b20];
  if (cVar1 != '\0') {
    if ((((&DAT_006826f8)[arg2 * 0x120 + arg1 * 0x5b20] & 8) == 0) &&
       ((&DAT_004ff594)[val_2 * 0x34] != -0x80)) {
      if ((cVar1 != '\x04') &&
         ((((&DAT_004ff594)[val_2 * 0x34] & 2) != 0 &&
          (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) == 0)))) {
        DAT_0068eeac = DAT_0068eeac + 1;
      }
      if (((&DAT_004ff594)[val_2 * 0x34] & 0x47) != 0) {
        FUN_0048cac9();
        DAT_0066642c = 0;
        DAT_0068ecb0 = arg1;
        DAT_00690c48 = arg2;
        DAT_00690310 = 1 - arg1;
        DAT_0068ecfc = 0xffffffff;
        Magic_ScanCards(0x77);
        if (0 < DAT_0066642c) {
          *(uint32_t *)(&DAT_006826f8 + arg2 * 0x120 + arg1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826f8 + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff7f;
          FUN_0048cb7f();
          return 0;
        }
        cVar1 = (&DAT_006826e0)[arg2 * 0x120 + arg1 * 0x5b20];
        FUN_0048cb7f();
      }
      if (((&DAT_006826f8)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) {
        if (cVar1 == '\x04') {
          FUN_0046f18f((*(uint32_t *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0x1000) >> 0xc,
                       *(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20));
        }
        else {
          if ((cVar1 != '\x03') && (DAT_0066aaf4 != 1)) {
            if (((&DAT_004ff594)[*(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2)
                == 0) {
              if (((&DAT_004ff594)[*(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] &
                  0x38) == 0) {
                FUN_0048d00c(1);
              }
            }
            else {
              FUN_0048d00c(0x19);
            }
          }
          FUN_0046f02d(arg1,arg2);
          if (cVar1 == '\x03') {
            FUN_0048e8a8(DAT_00666458,0xd5,s_Card_s__to_Graveyard_004f9750,0);
          }
        }
      }
    }
    FUN_0048cac9();
    uval_4 = DAT_0068edd0;
    uval_3 = DAT_00666754;
    DAT_00666754 = arg1;
    DAT_0068edd0 = arg2;
    if (((&DAT_004ff594)[val_2 * 0x34] & 0x47) != 0) {
      FUN_0048e8a8(DAT_00666458,0xd4,s_Card_leaving_play_004f9768,0);
    }
    DAT_00666754 = uval_3;
    DAT_0068edd0 = uval_4;
    FUN_0048cb7f();
    if (((&DAT_004ff594)[val_2 * 0x34] & 2) != 0) {
      *(int *)(&DAT_0068ee80 + arg1 * 4) = *(int *)(&DAT_0068ee80 + arg1 * 4) + -1;
    }
    if (((&DAT_004ff594)[val_2 * 0x34] & 0x40) != 0) {
      (&DAT_0068ee88)[arg1] = (&DAT_0068ee88)[arg1] + -1;
    }
    if (((&DAT_004ff594)[val_2 * 0x34] & 4) != 0) {
      *(int *)(&DAT_0068ee90 + arg1 * 4) = *(int *)(&DAT_0068ee90 + arg1 * 4) + -1;
    }
    *(int32_t *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) = 0xffffffff;
    (&DAT_006826e0)[arg2 * 0x120 + arg1 * 0x5b20] = 0;
    *(int32_t *)(&DAT_00682710 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
    if (DAT_0066aaf4 != 1) {
      FUN_00450eb8(arg1,arg2,7,2);
    }
    FUN_0046ed1c(arg1,arg2);
    if (((&DAT_004ff594)[val_2 * 0x34] & 0x47) != 0) {
      FUN_0048b64f();
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_0046ed1c
 * Entry Point: 0046ed1c
 * Size: 785 bytes
 */


void FUN_0046ed1c(int arg1,int arg2)

{
  int local_514;
  int local_510;
  int local_508;
  int aiStack_504 [320];
  
  local_510 = 0;
  for (local_508 = 0; local_508 < 2; local_508 = local_508 + 1) {
    for (local_514 = 0; local_514 < (int)(&DAT_00666408)[local_508]; local_514 = local_514 + 1) {
      if ((((*(int *)(&DAT_006826c4 + local_514 * 0x120 + local_508 * 0x5b20) != -1) &&
           (((&DAT_006826cc)[local_514 * 0x120 + local_508 * 0x5b20] & 2) != 0)) &&
          ((char)(&DAT_006826d2)[local_514 * 0x120 + local_508 * 0x5b20] == arg1)) &&
         ((*(int *)(&DAT_006826e8 + local_514 * 0x120 + local_508 * 0x5b20) == arg2 &&
          ((local_508 != arg1 || (local_514 != arg2)))))) {
        if (((&DAT_004ff594)
             [*(int *)(&DAT_006826c4 + local_514 * 0x120 + local_508 * 0x5b20) * 0x34] & 0x43) == 0)
        {
          aiStack_504[local_510 * 2] = local_508;
          aiStack_504[local_510 * 2 + 1] = local_514;
          local_510 = local_510 + 1;
        }
        else {
          (&DAT_006826d2)[local_514 * 0x120 + local_508 * 0x5b20] = 0xff;
          *(int32_t *)(&DAT_006826e8 + local_514 * 0x120 + local_508 * 0x5b20) = 0xffffffff;
        }
      }
    }
  }
  while (local_510 != 0) {
    local_510 = local_510 + -1;
    FUN_0046e571(aiStack_504[local_510 * 2],aiStack_504[local_510 * 2 + 1],2);
  }
  *(int16_t *)(&DAT_006826d0 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
  *(int16_t *)(&DAT_006826da + arg2 * 0x120 + arg1 * 0x5b20) =
       *(int16_t *)(&DAT_006826d0 + arg2 * 0x120 + arg1 * 0x5b20);
  *(int16_t *)(&DAT_006826d8 + arg2 * 0x120 + arg1 * 0x5b20) =
       *(int16_t *)(&DAT_006826da + arg2 * 0x120 + arg1 * 0x5b20);
  (&DAT_006826de)[arg2 * 0x120 + arg1 * 0x5b20] = 0xff;
  return;
}



/*
 * Decompiled function: FUN_0046f02d
 * Entry Point: 0046f02d
 * Size: 233 bytes
 */


void FUN_0046f02d(int arg1,int arg2)

{
  int val_1;
  int card_idx;
  uint32_t match_count;
  
  val_1 = *(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20);
  match_count = (uint32_t)(((&DAT_006826cd)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0);
  *(uint32_t *)(&DAT_006664f0 + match_count * 4) =
       *(uint32_t *)(&DAT_006664f0 + match_count * 4) | (uint32_t)(uint8_t)(&DAT_004ff594)[val_1 * 0x34];
  card_idx = 0;
  while( true ) {
    if (499 < card_idx) {
      return;
    }
    if (*(int *)(&DAT_0068f370 + card_idx * 4 + match_count * 2000) == -1) break;
    card_idx = card_idx + 1;
  }
  *(int *)(&DAT_0068f370 + card_idx * 4 + match_count * 2000) = val_1;
  return;
}



/*
 * Decompiled function: FUN_0046f116
 * Entry Point: 0046f116
 * Size: 121 bytes
 */


void FUN_0046f116(int arg1,int arg2)

{
  int slot_idx;
  
  for (slot_idx = arg2; slot_idx < 499; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_0068f370 + slot_idx * 4 + arg1 * 2000) =
         *(int32_t *)(&DAT_0068f374 + slot_idx * 4 + arg1 * 2000);
  }
  *(int32_t *)(&DAT_0068fb3c + arg1 * 2000) = 0xffffffff;
  return;
}



/*
 * Decompiled function: FUN_0046f18f
 * Entry Point: 0046f18f
 * Size: 164 bytes
 */


void FUN_0046f18f(int arg1,int arg2)

{
  int slot_idx;
  
  if ((DAT_0066aaf4 != 1) && (((&DAT_004ff594)[arg2 * 0x34] & 2) != 0)) {
    FUN_0048d00c(0x17);
  }
  slot_idx = 0;
  while( true ) {
    if (499 < slot_idx) {
      return;
    }
    if (*(int *)(&DAT_0068dd10 + slot_idx * 4 + arg1 * 2000) == -1) break;
    slot_idx = slot_idx + 1;
  }
  *(int *)(&DAT_0068dd10 + slot_idx * 4 + arg1 * 2000) = arg2;
  return;
}



/*
 * Decompiled function: UI_RegisterClass_0046f240
 * Entry Point: 0046f240
 * Size: 181 bytes
 */


uint8_t UI_RegisterClass_0046f240(LPCSTR str_1)

{
  uint8_t flag_1;
  ATOM AVar2;
  int val_3;
  int32_t *arg_3;
  BITMAPINFO *arg_4;
  int32_t *arg_5;
  int32_t *arg_6;
  int *arg_7;
  WNDCLASSA local_2c;
  
  local_2c.style = 1;
  local_2c.lpfnWndProc = UI_WndProc_0046f328;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0x28;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar2 = RegisterClassA(&local_2c);
  arg_7 = (int *)0x0;
  arg_6 = (int32_t *)0x0;
  arg_5 = &g_AiManaColorCost_Red;
  arg_4 = (BITMAPINFO *)0x0;
  arg_3 = &DAT_00522448;
  val_3 = GetSystemMetrics(3);
  flag_1 = FUN_004707f3(1000,val_3 * 5,arg_3,arg_4,arg_5,arg_6,arg_7);
  return AVar2 != 0 & flag_1;
}



/*
 * Decompiled function: FUN_0046f2f5
 * Entry Point: 0046f2f5
 * Size: 51 bytes
 */


void FUN_0046f2f5(void)

{
  FUN_0047097b(DAT_00522448,g_AiManaColorCost_Red);
  DAT_00522448 = (HDC)0x0;
  g_AiManaColorCost_Red = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: UI_WndProc_0046f328
 * Entry Point: 0046f328
 * Size: 4272 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t UI_WndProc_0046f328(HWND hwnd,uint32_t uMsg,uint32_t *wParam,LONG *lParam)

{
  short len_1;
  LONG *pLVar2;
  LONG LVar3;
  uint32_t *puVar4;
  HWND pHVar5;
  HWND pHVar6;
  int val_7;
  HBRUSH pHVar8;
  uint32_t uVar9;
  WPARAM WVar10;
  tagRECT *lpPoints;
  HDC wParam_00;
  UINT UVar11;
  LPARAM lParam_00;
  uint8_t local_174 [4];
  int local_170;
  int local_16c;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  tagRECT local_138;
  HDC local_128;
  uint8_t local_124 [4];
  int local_120;
  int local_11c;
  int local_10c;
  tagPAINTSTRUCT local_108;
  int local_c8;
  tagRECT local_c4;
  int local_b4;
  int local_b0;
  int local_ac;
  tagRECT local_a8;
  tagRECT local_98;
  tagRECT local_88;
  int local_78;
  int local_74;
  tagRECT local_70;
  int local_60;
  int local_5c;
  tagRECT local_58;
  int local_48;
  int local_44;
  int local_40;
  tagRECT local_3c;
  uint32_t *local_2c;
  LONG *local_28;
  uint32_t *local_24;
  uint32_t *loop_idx;
  uint32_t *color_idx;
  int target_idx;
  LONG player_idx;
  uint32_t *card_idx;
  LONG *match_count;
  LONG *slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_2c = (uint32_t *)GetWindowLongA(hwnd,0);
      player_idx = GetWindowLongA(hwnd,0x20);
      target_idx = GetWindowLongA(hwnd,0xc);
      color_idx = (uint32_t *)GetWindowLongA(hwnd,0x10);
      slot_idx = (LONG *)GetWindowLongA(hwnd,0x14);
      card_idx = (uint32_t *)GetWindowLongA(hwnd,0x18);
      local_28 = (LONG *)GetWindowLongA(hwnd,0x1c);
      loop_idx = (uint32_t *)GetWindowLongA(hwnd,0x24);
      local_24 = (uint32_t *)GetWindowLongA(hwnd,4);
      match_count = (LONG *)GetWindowLongA(hwnd,8);
      local_128 = BeginPaint(hwnd,&local_108);
      if (local_128 != (HDC)0x0) {
        FUN_004707a4(local_128);
        GetClientRect(hwnd,&local_88);
        local_b0 = SaveDC(DAT_00522448);
        IntersectClipRect(DAT_00522448,0,0,local_88.right,local_88.bottom);
        GetWindowRect(hwnd,&local_98);
        UVar11 = 2;
        lpPoints = &local_98;
        pHVar6 = GetParent(hwnd);
        MapWindowPoints((HWND)0x0,pHVar6,(LPPOINT)lpPoints,UVar11);
        OffsetViewportOrgEx(DAT_00522448,-local_98.left,-local_98.top,(LPPOINT)0x0);
        lParam_00 = 0;
        UVar11 = 0x14;
        wParam_00 = DAT_00522448;
        pHVar6 = GetParent(hwnd);
        SendMessageA(pHVar6,UVar11,(WPARAM)wParam_00,lParam_00);
        OffsetViewportOrgEx(DAT_00522448,local_98.left,local_98.top,(LPPOINT)0x0);
        if (color_idx == (HANDLE)0x0) {
          pHVar8 = GetStockObject(2);
          FillRect(DAT_00522448,&local_88,pHVar8);
        }
        else {
          CopyRect(&local_138,&local_88);
          GetObjectA(color_idx,0x18,local_124);
          local_138.left = -((int)local_2c % local_120);
          local_10c = local_88.bottom;
          local_ac = local_138.left;
          if (slot_idx == (LONG *)0x0) {
            local_c8 = ((local_120 / 2) * local_88.bottom) / local_11c;
            local_13c = local_120 / 2;
            local_140 = local_11c;
          }
          else {
            local_c8 = (local_120 * local_88.bottom) / (local_11c / 2);
            local_13c = local_120;
            local_140 = local_11c / 2;
          }
          for (; local_ac < local_138.right; local_ac = local_ac + local_13c) {
            for (local_b4 = local_138.top; local_b4 < local_138.bottom;
                local_b4 = local_b4 + local_140) {
              SetRect(&local_c4,local_ac,local_b4,local_ac + local_c8,local_b4 + local_10c);
              if (slot_idx == (LONG *)0x0) {
                FUN_00470c78(DAT_00522448,&local_c4,color_idx);
              }
              else {
                FUN_00470cfa(DAT_00522448,&local_c4.left,color_idx,local_120,local_11c / 2,0,0,0,
                             local_11c / 2);
              }
            }
          }
        }
        if (loop_idx != (uint32_t *)0x0) {
          local_150 = player_idx % (int)local_28;
          val_7 = FUN_00470437(hwnd,player_idx);
          if ((uint32_t *)val_7 != local_2c) {
            player_idx = FUN_004704cd(hwnd,(int)local_2c);
            SetWindowLongA(hwnd,0x20,player_idx);
          }
          if ((card_idx == (HANDLE)0x0) || (local_28 == (LONG *)0x0)) {
            SetRect(&local_a8,player_idx - local_88.right / 0x14,0,player_idx + local_88.right / 0x14,
                    local_88.bottom);
            pHVar8 = GetStockObject(4);
            FillRect(DAT_00522448,&local_a8,pHVar8);
          }
          else {
            GetObjectA(card_idx,0x18,local_174);
            local_158 = local_170 / 2;
            local_15c = local_16c / (int)local_28;
            local_14c = 0;
            local_154 = local_150 * local_15c;
            local_148 = local_154;
            local_144 = local_158;
            FUN_00470560(hwnd,&local_a8);
            if (target_idx == 0) {
              SetMapMode(DAT_00522448,8);
              SetWindowExtEx(DAT_00522448,1,1,(LPSIZE)0x0);
              SetViewportExtEx(DAT_00522448,-1,1,(LPSIZE)0x0);
              SetWindowOrgEx(DAT_00522448,0,0,(LPPOINT)0x0);
              SetViewportOrgEx(DAT_00522448,local_88.right,0,(LPPOINT)0x0);
              val_7 = local_88.right - local_a8.left;
              local_a8.left = local_88.right - local_a8.right;
              local_a8.right = val_7;
            }
            FUN_00470cfa(DAT_00522448,&local_a8.left,card_idx,local_158,local_15c,local_14c,
                         local_148,local_144,local_154);
            if (target_idx == 0) {
              SetMapMode(DAT_00522448,1);
              SetWindowOrgEx(DAT_00522448,0,0,(LPPOINT)0x0);
              SetViewportOrgEx(DAT_00522448,0,0,(LPPOINT)0x0);
            }
          }
        }
        RestoreDC(DAT_00522448,local_b0);
        BitBlt(local_128,0,0,local_88.right,local_88.bottom,DAT_00522448,0,0,0xcc0020);
        EndPaint(hwnd,&local_108);
      }
      return 0;
    }
    if (uMsg == 1) {
      local_2c = (uint32_t *)0x0;
      local_24 = (uint32_t *)0x0;
      match_count = (LONG *)0x0;
      SetWindowLongA(hwnd,0,0);
      SetWindowLongA(hwnd,4,(LONG)local_24);
      SetWindowLongA(hwnd,8,(LONG)match_count);
      target_idx = 1;
      SetWindowLongA(hwnd,0xc,1);
      color_idx = (uint32_t *)0x0;
      slot_idx = (LONG *)0x0;
      SetWindowLongA(hwnd,0x10,0);
      SetWindowLongA(hwnd,0x14,(LONG)slot_idx);
      card_idx = (uint32_t *)0x0;
      local_28 = (LONG *)0x0;
      SetWindowLongA(hwnd,0x18,0);
      SetWindowLongA(hwnd,0x1c,(LONG)local_28);
      player_idx = 0;
      SetWindowLongA(hwnd,0x20,0);
      loop_idx = (uint32_t *)0x0;
      SetWindowLongA(hwnd,0x24,0);
      return 0;
    }
  }
  else if (uMsg < 0xe1) {
    if (uMsg == 0xe0) {
      puVar4 = (uint32_t *)GetWindowLongA(hwnd,0);
      if (puVar4 != wParam) {
        local_2c = wParam;
        SetWindowLongA(hwnd,0,(LONG)wParam);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else {
    len_1 = (short)((uint32_t)lParam >> 0x10);
    if (uMsg < 0x201) {
      if (uMsg == 0x200) {
        pHVar6 = GetCapture();
        if (pHVar6 == hwnd) {
          target_idx = GetWindowLongA(hwnd,0xc);
          local_2c = (uint32_t *)GetWindowLongA(hwnd,0);
          local_24 = (uint32_t *)GetWindowLongA(hwnd,4);
          match_count = (LONG *)GetWindowLongA(hwnd,8);
          player_idx = GetWindowLongA(hwnd,0);
          local_44 = (int)(short)lParam;
          local_40 = (int)len_1;
          GetClientRect(hwnd,&local_3c);
          if (local_44 < 0) {
            local_44 = 0;
          }
          if (local_3c.right < local_44) {
            local_44 = local_3c.right;
          }
          if (local_40 < 0) {
            local_40 = 0;
          }
          if (local_3c.bottom < local_40) {
            local_40 = local_3c.bottom;
          }
          if (g_AiManaColorCost_White < local_44) {
            if (target_idx == 0) {
              target_idx = 1;
              SetWindowLongA(hwnd,0xc,1);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
          }
          else if ((local_44 < g_AiManaColorCost_White) && (target_idx != 0)) {
            target_idx = 0;
            SetWindowLongA(hwnd,0xc,0);
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          local_48 = local_44;
          if (local_44 < (int)local_24) {
            local_48 = (int)local_24;
          }
          else if ((int)match_count < local_44) {
            local_48 = (int)match_count;
          }
          if (local_48 != player_idx) {
            player_idx = local_48;
            SetWindowLongA(hwnd,0x20,local_48);
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          val_7 = FUN_00470437(hwnd,local_44);
          if ((uint32_t *)val_7 != local_2c) {
            pHVar6 = hwnd;
            val_7 = FUN_00470437(hwnd,local_44);
            WVar10 = CONCAT31((int3)((uint32_t)(val_7 << 0x10) >> 8),5);
            UVar11 = 0x114;
            pHVar5 = GetParent(hwnd);
            SendMessageA(pHVar5,UVar11,WVar10,(LPARAM)pHVar6);
          }
          UpdateWindow(hwnd);
          g_AiManaColorCost_White = local_44;
          g_AiManaColorCost_Blue = local_40;
        }
        return 0;
      }
      if (uMsg == 0xe1) {
        uVar9 = GetWindowLongA(hwnd,0);
        return uVar9;
      }
      if (uMsg == 0xe2) {
        local_24 = (uint32_t *)GetWindowLongA(hwnd,4);
        pLVar2 = (LONG *)GetWindowLongA(hwnd,8);
        if ((local_24 != wParam) || (pLVar2 != lParam)) {
          local_24 = wParam;
          match_count = lParam;
          SetWindowLongA(hwnd,4,(LONG)wParam);
          SetWindowLongA(hwnd,8,(LONG)match_count);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      }
      if (uMsg == 0xe3) {
        local_24 = (uint32_t *)GetWindowLongA(hwnd,4);
        LVar3 = GetWindowLongA(hwnd,8);
        if (wParam != (uint32_t *)0x0) {
          *wParam = (uint32_t)local_24;
        }
        if (lParam != (LONG *)0x0) {
          *lParam = LVar3;
        }
        return LVar3 << 0x10 | (uint32_t)local_24 & 0xffff;
      }
    }
    else if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        uVar9 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
        return uVar9;
      }
      if (uMsg == 0x201) {
        UpdateWindow(hwnd);
        player_idx = GetWindowLongA(hwnd,0x20);
        target_idx = GetWindowLongA(hwnd,0xc);
        loop_idx = (uint32_t *)GetWindowLongA(hwnd,0x24);
        local_60 = (int)(short)lParam;
        local_5c = (int)len_1;
        if (loop_idx == (uint32_t *)0x0) {
          return 0;
        }
        FUN_00470560(hwnd,&local_58);
        if ((local_60 < local_58.left) || (local_58.right < local_60)) {
          if (local_58.right < local_60) {
            if (target_idx == 0) {
              target_idx = 1;
              SetWindowLongA(hwnd,0xc,1);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
            WVar10 = 1;
            UVar11 = 0x114;
            pHVar6 = GetParent(hwnd);
            SendMessageA(pHVar6,UVar11,WVar10,(LPARAM)hwnd);
          }
          else if (local_60 < local_58.left) {
            if (target_idx != 0) {
              target_idx = 0;
              SetWindowLongA(hwnd,0xc,0);
              InvalidateRect(hwnd,(RECT *)0x0,1);
            }
            WVar10 = 0;
            UVar11 = 0x114;
            pHVar6 = GetParent(hwnd);
            SendMessageA(pHVar6,UVar11,WVar10,(LPARAM)hwnd);
          }
        }
        else {
          SetCapture(hwnd);
        }
        g_AiManaColorCost_White = local_60;
        g_AiManaColorCost_Blue = local_5c;
        return 0;
      }
      if (uMsg == 0x202) {
        pHVar6 = GetCapture();
        if (pHVar6 == hwnd) {
          ReleaseCapture();
          player_idx = GetWindowLongA(hwnd,0x20);
          local_78 = (int)(short)lParam;
          local_74 = (int)len_1;
          GetClientRect(hwnd,&local_70);
          if (local_78 < 0) {
            local_78 = 0;
          }
          if (local_70.right < local_78) {
            local_78 = local_70.right;
          }
          if (local_74 < 0) {
            local_74 = 0;
          }
          if (local_70.bottom < local_74) {
            local_74 = local_70.bottom;
          }
          player_idx = local_78;
          SetWindowLongA(hwnd,0x20,local_78);
          InvalidateRect(hwnd,(RECT *)0x0,1);
          pHVar6 = hwnd;
          val_7 = FUN_00470437(hwnd,local_78);
          WVar10 = CONCAT31((int3)((uint32_t)(val_7 << 0x10) >> 8),4);
          UVar11 = 0x114;
          pHVar5 = GetParent(hwnd);
          SendMessageA(pHVar5,UVar11,WVar10,(LPARAM)pHVar6);
        }
        return 0;
      }
    }
    else {
      switch(uMsg) {
      case 0x432:
        InvalidateRect(hwnd,(RECT *)0x0,1);
        return 0;
      case 0x464:
        puVar4 = (uint32_t *)GetWindowLongA(hwnd,0x10);
        if (puVar4 != wParam) {
          color_idx = wParam;
          slot_idx = lParam;
          SetWindowLongA(hwnd,0x10,(LONG)wParam);
          SetWindowLongA(hwnd,0x14,(LONG)slot_idx);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      case 0x465:
        uVar9 = GetWindowLongA(hwnd,0x10);
        if (wParam == (uint32_t *)0x0) {
          return uVar9;
        }
        *wParam = uVar9;
        return uVar9;
      case 0x466:
        card_idx = (uint32_t *)GetWindowLongA(hwnd,0x18);
        GetWindowLongA(hwnd,0x1c);
        if (wParam != card_idx) {
          card_idx = wParam;
          local_28 = lParam;
          SetWindowLongA(hwnd,0x18,(LONG)wParam);
          SetWindowLongA(hwnd,0x1c,(LONG)local_28);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      case 0x467:
        card_idx = (uint32_t *)GetWindowLongA(hwnd,0x18);
        LVar3 = GetWindowLongA(hwnd,0x1c);
        if (wParam != (uint32_t *)0x0) {
          *wParam = (uint32_t)card_idx;
        }
        if (lParam == (LONG *)0x0) {
          return (uint32_t)card_idx;
        }
        *lParam = LVar3;
        return (uint32_t)card_idx;
      case 0x468:
        puVar4 = (uint32_t *)GetWindowLongA(hwnd,0x24);
        if (wParam != puVar4) {
          loop_idx = wParam;
          SetWindowLongA(hwnd,0x24,(LONG)wParam);
          InvalidateRect(hwnd,(RECT *)0x0,1);
        }
        return 0;
      }
    }
  }
  uVar9 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,(LPARAM)lParam);
  return uVar9;
}



/*
 * Decompiled function: FUN_00470437
 * Entry Point: 00470437
 * Size: 150 bytes
 */


int FUN_00470437(HWND hwnd,int arg2)

{
  int val_1;
  LONG LVar2;
  tagRECT target_idx;
  int slot_idx;
  
  if (hwnd == (HWND)0x0) {
    val_1 = 0;
  }
  else {
    LVar2 = GetWindowLongA(hwnd,4);
    slot_idx = GetWindowLongA(hwnd,8);
    GetClientRect(hwnd,&target_idx);
    if (arg2 < target_idx.left) {
      arg2 = target_idx.left;
    }
    if (target_idx.right < arg2) {
      arg2 = target_idx.right;
    }
    val_1 = LVar2 + (((slot_idx - LVar2) + 1) * arg2) / target_idx.right;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_004704cd
 * Entry Point: 004704cd
 * Size: 147 bytes
 */


int FUN_004704cd(HWND hwnd,int arg2)

{
  int val_1;
  LONG LVar2;
  tagRECT target_idx;
  int slot_idx;
  
  if (hwnd == (HWND)0x0) {
    val_1 = 0;
  }
  else {
    LVar2 = GetWindowLongA(hwnd,4);
    slot_idx = GetWindowLongA(hwnd,8);
    GetClientRect(hwnd,&target_idx);
    if (arg2 < LVar2) {
      arg2 = LVar2;
    }
    if (slot_idx < arg2) {
      arg2 = slot_idx;
    }
    val_1 = (target_idx.right * arg2) / ((slot_idx - LVar2) + 1);
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00470560
 * Entry Point: 00470560
 * Size: 365 bytes
 */


void FUN_00470560(HWND hwnd,LPRECT arg2)

{
  LONG LVar1;
  uint8_t local_3c [4];
  int local_38;
  int local_34;
  int local_24;
  int loop_idx;
  LONG color_idx;
  HANDLE target_idx;
  tagRECT player_idx;
  
  if ((hwnd != (HWND)0x0) && (arg2 != (LPRECT)0x0)) {
    color_idx = GetWindowLongA(hwnd,0x20);
    target_idx = (HANDLE)GetWindowLongA(hwnd,0x18);
    LVar1 = GetWindowLongA(hwnd,0x1c);
    GetClientRect(hwnd,&player_idx);
    if ((target_idx == (HANDLE)0x0) || (LVar1 == 0)) {
      SetRect(arg2,color_idx - player_idx.right / 0x14,0,color_idx + player_idx.right / 0x14,
              player_idx.bottom);
    }
    else {
      GetObjectA(target_idx,0x18,local_3c);
      local_24 = player_idx.bottom;
      loop_idx = ((local_38 / 2) * player_idx.bottom) / (local_34 / LVar1);
      SetRect(arg2,color_idx - loop_idx / 2,0,(color_idx - loop_idx / 2) + loop_idx,player_idx.bottom);
    }
    if (arg2->left < player_idx.left) {
      OffsetRect(arg2,player_idx.left - arg2->left,0);
    }
    else if (player_idx.right < arg2->right) {
      OffsetRect(arg2,player_idx.right - arg2->right,0);
    }
  }
  return;
}



/*
 * Decompiled function: FUN_004706d0
 * Entry Point: 004706d0
 * Size: 93 bytes
 */


bool FUN_004706d0(void)

{
  if (DAT_004f9780 == 0) {
    FUN_004707f3(10,10,&DAT_004f9780,(BITMAPINFO *)0x0,&DAT_00522460,(int32_t *)0x0,(int *)0x0);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_005224a8);
  }
  return DAT_004f9780 != 0;
}



/*
 * Decompiled function: FUN_0047072d
 * Entry Point: 0047072d
 * Size: 65 bytes
 */


void FUN_0047072d(void)

{
  if (DAT_004f9780 != (HDC)0x0) {
    FUN_0047097b(DAT_004f9780,DAT_00522460);
    DAT_004f9780 = (HDC)0x0;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_005224a8);
  }
  return;
}



/*
 * Decompiled function: FUN_0047076e
 * Entry Point: 0047076e
 * Size: 54 bytes
 */


void FUN_0047076e(char *filepath)

{
  char *char_ptr_1;
  
  GetModuleFileNameA((HMODULE)0x0,str_1,0x105);
  char_ptr_1 = _strrchr(str_1,0x5c);
  *char_ptr_1 = '\0';
  return;
}



/*
 * Decompiled function: FUN_004707a4
 * Entry Point: 004707a4
 * Size: 79 bytes
 */


void FUN_004707a4(HDC hdc)

{
  SelectPalette(hdc,DAT_005f76d0,0);
  RealizePalette(hdc);
  GdiFlush();
  SetDIBColorTable(hdc,0,0x100,(RGBQUAD *)&DAT_00617580);
  SetStretchBltMode(hdc,3);
  return;
}



/*
 * Decompiled function: FUN_004707f3
 * Entry Point: 004707f3
 * Size: 387 bytes
 */


int32_t
FUN_004707f3(int32_t arg_1,int card_slot,int32_t *arg_3,BITMAPINFO *arg_4,int32_t *arg_5,
            int32_t *arg_6,int *arg_7)

{
  int32_t uval_1;
  HDC hdc;
  HBITMAP local_44;
  HDC local_3c;
  BITMAPINFO local_38;
  HGDIOBJ match_count;
  void *slot_idx;
  
  local_3c = (HDC)0x0;
  local_44 = (HBITMAP)0x0;
  slot_idx = (void *)0x0;
  if ((arg_3 == (int32_t *)0x0) || (arg_5 == (int32_t *)0x0)) {
    uval_1 = 0;
  }
  else {
    if (arg_4 == (BITMAPINFO *)0x0) {
      arg_4 = &local_38;
    }
    hdc = GetDC((HWND)0x0);
    if (hdc != (HDC)0x0) {
      FUN_004707a4(hdc);
      local_3c = CreateCompatibleDC(hdc);
      if (local_3c != (HDC)0x0) {
        FUN_00491750((int32_t *)arg_4,arg_1,arg_2);
        local_38.bmiHeader.biBitCount = 0x20;
        local_44 = CreateDIBSection(hdc,arg_4,0,&slot_idx,(HANDLE)0x0,0);
        match_count = SelectObject(local_3c,local_44);
        FUN_004707a4(local_3c);
      }
      ReleaseDC((HWND)0x0,hdc);
    }
    if (((local_3c == (HDC)0x0) || (local_44 == (HBITMAP)0x0)) || (slot_idx == (void *)0x0)) {
      if (local_3c != (HDC)0x0) {
        DeleteDC(local_3c);
      }
      if (local_44 != (HBITMAP)0x0) {
        DeleteObject(local_44);
      }
      uval_1 = 0;
    }
    else {
      if (arg_3 != (int32_t *)0x0) {
        *arg_3 = local_3c;
      }
      if (arg_5 != (int32_t *)0x0) {
        *arg_5 = local_44;
      }
      if (arg_6 != (int32_t *)0x0) {
        *arg_6 = match_count;
      }
      if (arg_7 != (int *)0x0) {
        *arg_7 = (int)slot_idx;
      }
      uval_1 = 1;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0047097b
 * Entry Point: 0047097b
 * Size: 51 bytes
 */


void FUN_0047097b(HDC hdc,HGDIOBJ arg2)

{
  if (hdc != (HDC)0x0) {
    DeleteDC(hdc);
  }
  if (arg2 != (HGDIOBJ)0x0) {
    DeleteObject(arg2);
  }
  return;
}



/*
 * Decompiled function: FUN_004709ae
 * Entry Point: 004709ae
 * Size: 104 bytes
 */


int32_t FUN_004709ae(int player_id,int card_slot,HANDLE arg_3)

{
  int32_t uval_1;
  uint8_t color_idx [4];
  int target_idx;
  int player_idx;
  
  if (((arg_1 == 0) || (arg_2 == 0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    GetObjectA(arg_3,0x18,color_idx);
    uval_1 = FUN_00470a16((HDC)arg_1,(int *)arg_2,arg_3,0,0,target_idx,player_idx);
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00470a16
 * Entry Point: 00470a16
 * Size: 330 bytes
 */


int32_t FUN_00470a16(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  int32_t uval_1;
  HGDIOBJ h;
  int local_2c;
  uint8_t local_28 [4];
  int local_24;
  int loop_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_005224a8);
    h = SelectObject(DAT_004f9780,arg_3);
    GetObjectA(arg_3,0x18,local_28);
    slot_idx = *arg_2;
    match_count = arg_2[1];
    if (arg_2[2] < *arg_2) {
      card_idx = local_24;
    }
    else {
      card_idx = arg_2[2] - *arg_2;
    }
    if (arg_2[3] < arg_2[1]) {
      local_2c = loop_idx;
    }
    else {
      local_2c = arg_2[3] - arg_2[1];
    }
    FUN_004707a4(DAT_004f9780);
    if (arg_7 <= loop_idx) {
      loop_idx = arg_7;
    }
    if (arg_6 <= local_24) {
      local_24 = arg_6;
    }
    StretchBlt(hdc,slot_idx,match_count,card_idx,local_2c,DAT_004f9780,arg_4,arg_5,local_24,loop_idx,
               0xcc0020);
    SelectObject(DAT_004f9780,h);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005224a8);
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00470b60
 * Entry Point: 00470b60
 * Size: 280 bytes
 */


int32_t FUN_00470b60(HDC hdc,int *arg_2,HANDLE arg_3)

{
  int32_t uval_1;
  uint8_t local_38 [4];
  int local_34;
  int local_30;
  tagRECT loop_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    match_count = SaveDC(hdc);
    IntersectClipRect(hdc,*arg_2,arg_2[1],arg_2[2],arg_2[3]);
    GetObjectA(arg_3,0x18,local_38);
    for (slot_idx = *arg_2; slot_idx < arg_2[2]; slot_idx = slot_idx + local_34) {
      for (card_idx = arg_2[1]; card_idx < arg_2[3]; card_idx = card_idx + local_30) {
        SetRect(&loop_idx,slot_idx,card_idx,slot_idx + -1,card_idx + -1);
        FUN_00470a16(hdc,&loop_idx.left,arg_3,0,0,local_34,local_30);
      }
    }
    RestoreDC(hdc,match_count);
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00470c78
 * Entry Point: 00470c78
 * Size: 130 bytes
 */


int32_t FUN_00470c78(HDC arg_1,int *arg_2,HANDLE arg_3)

{
  int32_t uval_1;
  uint8_t local_34 [4];
  int local_30;
  int local_2c;
  int color_idx;
  int target_idx;
  int32_t player_idx;
  int32_t card_idx;
  int32_t match_count;
  int slot_idx;
  
  GetObjectA(arg_3,0x18,local_34);
  target_idx = local_30 / 2;
  color_idx = local_2c;
  card_idx = 0;
  match_count = 0;
  player_idx = 0;
  slot_idx = target_idx;
  uval_1 = FUN_00470cfa(arg_1,arg_2,arg_3,target_idx,local_2c,0,0,target_idx,0);
  return uval_1;
}



/*
 * Decompiled function: FUN_00470cfa
 * Entry Point: 00470cfa
 * Size: 379 bytes
 */


int32_t
FUN_00470cfa(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
            int arg_9)

{
  int32_t uval_1;
  int local_30;
  uint8_t local_2c [24];
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_005224a8);
    card_idx = SaveDC(hdc);
    SelectObject(DAT_004f9780,arg_3);
    GetObjectA(arg_3,0x18,local_2c);
    slot_idx = *arg_2;
    match_count = arg_2[1];
    if (arg_2[2] < *arg_2) {
      player_idx = arg_4;
    }
    else {
      player_idx = arg_2[2] - *arg_2;
    }
    if (arg_2[3] < arg_2[1]) {
      local_30 = arg_5;
    }
    else {
      local_30 = arg_2[3] - arg_2[1];
    }
    FUN_004707a4(DAT_004f9780);
    StretchBlt(hdc,slot_idx,match_count,player_idx,local_30,DAT_004f9780,arg_8,arg_9,arg_4,arg_5,0x8800c6);
    FUN_004707a4(DAT_004f9780);
    StretchBlt(hdc,slot_idx,match_count,player_idx,local_30,DAT_004f9780,arg_6,arg_7,arg_4,arg_5,0xee0086);
    RestoreDC(hdc,card_idx);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005224a8);
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00470e75
 * Entry Point: 00470e75
 * Size: 192 bytes
 */


int32_t FUN_00470e75(int32_t arg_1,LPCSTR str_2,void *arg_3,int32_t arg_4)

{
  char local_208 [500];
  int32_t player_idx;
  HGLOBAL card_idx;
  BITMAPINFO *match_count;
  HRSRC slot_idx;
  
  player_idx = 0;
  slot_idx = FindResourceA(DAT_00664680,str_2,(LPCSTR)0x2);
  if (slot_idx != (HRSRC)0x0) {
    card_idx = LoadResource(DAT_00664680,slot_idx);
    if (card_idx != (HGLOBAL)0x0) {
      match_count = LockResource(card_idx);
      if (match_count != (BITMAPINFO *)0x0) {
        player_idx = FUN_00471035(match_count,arg_3);
      }
    }
  }
  if (DAT_0061815c != 0) {
    _sprintf(local_208,s__08X_LoadDIBSection___s__004f97c4,player_idx,str_2);
    OutputDebugStringA(local_208);
  }
  return player_idx;
}



/*
 * Decompiled function: FUN_00470f35
 * Entry Point: 00470f35
 * Size: 256 bytes
 */


int32_t FUN_00470f35(LPCSTR str_1,void *arg_2,int32_t arg_3)

{
  char local_20c [500];
  int32_t target_idx;
  HANDLE player_idx;
  HANDLE card_idx;
  LPVOID match_count;
  BITMAPINFO *slot_idx;
  
  target_idx = 0;
  player_idx = CreateFileA(str_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,(HANDLE)0x0);
  if (player_idx != (HANDLE)0xffffffff) {
    card_idx = CreateFileMappingA(player_idx,(LPSECURITY_ATTRIBUTES)0x0,0x8000000,0,0,(LPCSTR)0x0);
    if (card_idx != (HANDLE)0x0) {
      match_count = MapViewOfFile(card_idx,4,0,0,0);
      if (match_count != (LPVOID)0x0) {
        slot_idx = (BITMAPINFO *)((int)match_count + 0xe);
        target_idx = FUN_00471035(slot_idx,arg_2);
        UnmapViewOfFile(slot_idx);
      }
      CloseHandle(card_idx);
    }
    CloseHandle(player_idx);
  }
  if (DAT_0061815c != 0) {
    _sprintf(local_20c,s__08X_LoadDIBSectionFromFile___s__004f97e0,target_idx,str_1);
    OutputDebugStringA(local_20c);
  }
  return target_idx;
}



/*
 * Decompiled function: FUN_00471035
 * Entry Point: 00471035
 * Size: 794 bytes
 */


HBITMAP FUN_00471035(BITMAPINFO *arg1,void *arg2)

{
  WORD WVar1;
  BYTE *lpBits;
  BITMAPINFO *lpbmi;
  DWORD DVar2;
  HANDLE hSection;
  HDC hdc;
  int local_30;
  HBITMAP local_2c;
  DWORD local_28;
  void *card_idx;
  DWORD match_count;
  int slot_idx;
  
  local_2c = (HBITMAP)0x0;
  WVar1 = (arg1->bmiHeader).biBitCount;
  if (WVar1 == 1) {
    slot_idx = 2;
  }
  else if (WVar1 == 4) {
    slot_idx = 0x10;
  }
  else if (WVar1 == 8) {
    slot_idx = 0x100;
  }
  else {
    slot_idx = 0;
  }
  lpBits = &arg1->bmiColors[slot_idx + -10].rgbBlue + (arg1->bmiHeader).biSize;
  lpbmi = _malloc(slot_idx * 4 + 0x28);
  if (lpbmi != (BITMAPINFO *)0x0) {
    FID_conflict__memcpy(lpbmi,arg1,0x28);
    FID_conflict__memcpy(lpbmi->bmiColors,arg1->bmiColors,slot_idx << 2);
    if ((arg1->bmiHeader).biWidth % 3 == 0) {
      local_30 = 0;
    }
    else {
      local_30 = 4 - (arg1->bmiHeader).biWidth % 3;
    }
    local_28 = ((arg1->bmiHeader).biWidth + local_30) * (arg1->bmiHeader).biHeight;
    switch((arg1->bmiHeader).biBitCount) {
    case 1:
      break;
    case 4:
      break;
    case 8:
      break;
    case 0x10:
      local_28 = local_28 * 2;
      break;
    case 0x18:
      local_28 = local_28 * 3;
      break;
    case 0x20:
      local_28 = local_28 * 4;
    }
    match_count = (arg1->bmiHeader).biSizeImage;
    DVar2 = match_count;
    if ((int)match_count <= (int)local_28) {
      DVar2 = local_28;
    }
    hSection = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,
                                  DVar2 + 1000,(LPCSTR)0x0);
    if (hSection != (HANDLE)0x0) {
      hdc = GetDC((HWND)0x0);
      FUN_004707a4(hdc);
      (lpbmi->bmiHeader).biSizeImage = local_28;
      (lpbmi->bmiHeader).biCompression = 0;
      if (slot_idx == 0) {
        local_2c = CreateDIBSection(hdc,lpbmi,0,&card_idx,hSection,0);
      }
      else {
        local_2c = CreateDIBSection(hdc,lpbmi,0,&card_idx,hSection,0);
      }
      (lpbmi->bmiHeader).biSizeImage = match_count;
      if (local_2c == (HBITMAP)0x0) {
        CloseHandle(hSection);
      }
      else {
        if (slot_idx == 0) {
          SetDIBits(hdc,local_2c,0,(arg1->bmiHeader).biHeight,lpBits,arg1,0);
        }
        else {
          SetDIBits(hdc,local_2c,0,(arg1->bmiHeader).biHeight,lpBits,arg1,0);
        }
        if (arg2 != (void *)0x0) {
          FID_conflict__memcpy(arg2,arg1,0x28);
          FID_conflict__memcpy((void *)((int)arg2 + 0x28),arg1->bmiColors,slot_idx << 2);
        }
        SetBitmapDimensionEx(local_2c,(int)hSection,0,(LPSIZE)0x0);
      }
      ReleaseDC((HWND)0x0,hdc);
    }
    FUN_004db150(lpbmi);
  }
  return local_2c;
}



/*
 * Decompiled function: FUN_00471395
 * Entry Point: 00471395
 * Size: 145 bytes
 */


void FUN_00471395(HANDLE arg_1)

{
  char local_254 [500];
  HANDLE local_60;
  uint8_t local_5c [20];
  int local_48;
  HANDLE card_idx;
  int match_count;
  int slot_idx;
  
  if (arg_1 != (HANDLE)0x0) {
    GetObjectA(arg_1,0x54,local_5c);
    local_60 = card_idx;
    slot_idx = local_48 + match_count;
    DeleteObject(arg_1);
    if (local_60 != (HANDLE)0x0) {
      CloseHandle(local_60);
    }
  }
  if (DAT_0061815c != 0) {
    _sprintf(local_254,s__08x_DestroyDIBSection__file_map_004f9804,arg_1,local_60);
    OutputDebugStringA(local_254);
  }
  return;
}



/*
 * Decompiled function: FUN_00471426
 * Entry Point: 00471426
 * Size: 753 bytes
 */


int32_t FUN_00471426(void)

{
  UINT UVar1;
  PALETTEENTRY local_628;
  uint32_t local_624 [66];
  int32_t local_51c;
  UINT local_514;
  uint32_t local_510 [66];
  LOGPALETTE *local_408;
  tagPALETTEENTRY local_404 [256];
  
  local_51c = 1;
  Mem_AllocOrFree_004d9630(local_624,(uint32_t *)&DAT_005f76e0);
  FUN_004d9640(local_624,(uint32_t *)s__DUELPALall_TR_004f9834);
  Mem_AllocOrFree_004d9630(local_510,(uint32_t *)&DAT_005f76e0);
  FUN_004d9640(local_510,(uint32_t *)s__DUEL_plogpal_004f9844);
  local_408 = (LOGPALETTE *)Catalog_LoadPaletteMap((char *)local_624,(char *)local_510);
  if (local_408 == (LOGPALETTE *)0x0) {
    local_51c = 0;
  }
  else {
    for (local_514 = 1; (int)local_514 < 0xff; local_514 = local_514 + 1) {
      local_408->palPalEntry[local_514].peFlags = '\x04';
    }
    DAT_005f76d0 = CreatePalette(local_408);
    if (DAT_005f76d0 == (HPALETTE)0x0) {
      local_51c = 0;
    }
    else {
      local_628.peRed = 0xff;
      local_628.peGreen = 0xff;
      local_628.peBlue = 0xff;
      local_628.peFlags = '\0';
      SetPaletteEntries(DAT_005f76d0,0xff,1,&local_628);
      local_628.peRed = 0xfe;
      local_628.peGreen = 0xfe;
      local_628.peBlue = 0xfe;
      local_628.peFlags = '\x04';
      SetPaletteEntries(DAT_005f76d0,0xbf,1,&local_628);
      for (local_514 = 0xec; (int)local_514 < 0xff; local_514 = local_514 + 1) {
        local_628.peRed = '\x01';
        local_628.peGreen = '\x01';
        local_628.peBlue = '\x01';
        local_628.peFlags = '\x04';
        SetPaletteEntries(DAT_005f76d0,local_514,1,&local_628);
      }
      UVar1 = GetPaletteEntries(DAT_005f76d0,0,0x100,local_404);
      for (local_514 = 0; (int)local_514 < (int)UVar1; local_514 = local_514 + 1) {
        (&DAT_00617580)[local_514 * 4] = local_404[local_514].peBlue;
        (&DAT_00617581)[local_514 * 4] = local_404[local_514].peGreen;
        (&DAT_00617582)[local_514 * 4] = local_404[local_514].peRed;
        (&DAT_00617583)[local_514 * 4] = 0;
      }
      while (local_514 = UVar1, (int)local_514 < 0x100) {
        (&DAT_00617580)[local_514 * 4] = 0;
        (&DAT_00617581)[local_514 * 4] = 0;
        (&DAT_00617582)[local_514 * 4] = 0;
        (&DAT_00617583)[local_514 * 4] = 0;
        UVar1 = local_514 + 1;
      }
    }
  }
  return local_51c;
}



/*
 * Decompiled function: FUN_00471717
 * Entry Point: 00471717
 * Size: 38 bytes
 */


void FUN_00471717(void)

{
  DeleteObject(DAT_005f76d0);
  DAT_005f76d0 = (HGDIOBJ)0x0;
  Mem_AllocOrFree_004367d4();
  return;
}



/*
 * Decompiled function: FUN_0047173d
 * Entry Point: 0047173d
 * Size: 417 bytes
 */


void FUN_0047173d(int player_id,int card_slot,RECT *arg_3)

{
  int arg_3_00;
  int val_1;
  int32_t arg_6;
  int32_t uval_2;
  uint32_t arg_2_00;
  int local_28;
  tagRECT player_idx;
  
  if (((arg_1 != 0) && (arg_2 != 0)) && (arg_3 != (RECT *)0x0)) {
    CopyRect(&player_idx,arg_3);
    arg_3_00 = *(int *)(arg_1 + 4);
    arg_2_00 = (uint32_t)*(uint16_t *)(arg_1 + 0xe);
    while( true ) {
      player_idx.bottom = player_idx.bottom + -1;
      player_idx.right = player_idx.right + -1;
      if (player_idx.right <= player_idx.left) break;
      for (local_28 = player_idx.left; local_28 < player_idx.right; local_28 = local_28 + 1) {
        val_1 = local_28 - player_idx.left;
        arg_6 = FUN_00472d60(arg_2,arg_2_00,arg_3_00,player_idx.left + val_1,player_idx.top);
        uval_2 = FUN_00472d60(arg_2,arg_2_00,arg_3_00,player_idx.left,player_idx.bottom - val_1);
        FUN_00472ea0(arg_2,arg_2_00,arg_3_00,player_idx.left + val_1,player_idx.top,uval_2);
        uval_2 = FUN_00472d60(arg_2,arg_2_00,arg_3_00,player_idx.right - val_1,player_idx.bottom);
        FUN_00472ea0(arg_2,arg_2_00,arg_3_00,player_idx.left,player_idx.bottom - val_1,uval_2);
        uval_2 = FUN_00472d60(arg_2,arg_2_00,arg_3_00,player_idx.right,player_idx.top + val_1);
        FUN_00472ea0(arg_2,arg_2_00,arg_3_00,player_idx.right - val_1,player_idx.bottom,uval_2);
        FUN_00472ea0(arg_2,arg_2_00,arg_3_00,player_idx.right,player_idx.top + val_1,arg_6);
      }
      player_idx.left = player_idx.left + 1;
      player_idx.top = player_idx.top + 1;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_004718de
 * Entry Point: 004718de
 * Size: 584 bytes
 */


void FUN_004718de(char *filepath,char *mode_str,int width,char *str_4)

{
  size_t len_1;
  int val_2;
  uint32_t local_20c;
  int local_208;
  int32_t local_204;
  size_t card_idx;
  int match_count;
  char *slot_idx;
  
  if (((((str_1 != (char *)0x0) && (str_2 != (char *)0x0)) && (str_4 != (char *)0x0)) &&
      ((len_1 = _strlen(str_1), len_1 != 0 && (len_1 = _strlen(str_2), len_1 != 0)))) &&
     (len_1 = _strlen(str_4), len_1 != 0)) {
    card_idx = _strlen(str_2);
    slot_idx = str_1;
    local_204._0_1_ = 0;
    local_208 = 0;
    while (*slot_idx != '\0') {
      match_count = 0;
      if (((width != 0) && (val_2 = _strncmp(slot_idx,str_2,card_idx), val_2 == 0)) ||
         ((width == 0 && (val_2 = __strnicmp(slot_idx,str_2,card_idx), val_2 == 0)))) {
        if (slot_idx[card_idx] == '\0') {
          match_count = 1;
        }
        else if (slot_idx[card_idx] == 's') {
          match_count = 1;
        }
        else if (slot_idx[card_idx] == '.') {
          match_count = 1;
        }
        else if (slot_idx[card_idx] == ' ') {
          if (DAT_005096ac < 2) {
            local_20c = *(uint16_t *)(PTR_DAT_005094a0 + slot_idx[card_idx + 1] * 2) & 1;
          }
          else {
            local_20c = __isctype((int)slot_idx[card_idx + 1],1);
          }
          if (local_20c == 0) {
            match_count = 1;
          }
        }
      }
      if (match_count == 0) {
        *(char *)((int)&local_204 + local_208) = *slot_idx;
        slot_idx = slot_idx + 1;
        *(uint8_t *)((int)&local_204 + local_208 + 1) = 0;
        local_208 = local_208 + 1;
      }
      else {
        FUN_004d9640(&local_204,(uint32_t *)str_4);
        len_1 = _strlen(str_4);
        slot_idx = slot_idx + card_idx;
        local_208 = local_208 + len_1;
      }
    }
    Mem_AllocOrFree_004d9630((uint32_t *)str_1,&local_204);
  }
  return;
}



/*
 * Decompiled function: FUN_00471b26
 * Entry Point: 00471b26
 * Size: 454 bytes
 */


int FUN_00471b26(char *filepath,char *mode_str,int event_type)

{
  bool flag_1;
  size_t len_2;
  int val_3;
  uint32_t target_idx;
  int player_idx;
  char *slot_idx;
  
  if ((((str_1 == (char *)0x0) || (str_2 == (char *)0x0)) || (len_2 = _strlen(str_1), len_2 == 0))
     || (len_2 = _strlen(str_2), len_2 == 0)) {
    return -1;
  }
  len_2 = _strlen(str_2);
  slot_idx = str_1;
  player_idx = 0;
  flag_1 = false;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            if ((*slot_idx == '\0') || (flag_1)) {
              if (!flag_1) {
                return -1;
              }
              return player_idx;
            }
            if (((arg_3 != 0) && (val_3 = _strncmp(slot_idx,str_2,len_2), val_3 == 0)) ||
               ((arg_3 == 0 && (val_3 = __strnicmp(slot_idx,str_2,len_2), val_3 == 0)))) break;
            slot_idx = slot_idx + 1;
            player_idx = player_idx + 1;
          }
          if (slot_idx[len_2] != 's') break;
          flag_1 = true;
        }
        if (slot_idx[len_2] != '.') break;
        flag_1 = true;
      }
      if (slot_idx[len_2] == ' ') break;
LAB_00471cb5:
      slot_idx = slot_idx + 1;
      player_idx = player_idx + 1;
    }
    if (DAT_005096ac < 2) {
      target_idx = *(uint16_t *)(PTR_DAT_005094a0 + slot_idx[len_2 + 1] * 2) & 1;
    }
    else {
      target_idx = __isctype((int)slot_idx[len_2 + 1],1);
    }
    if (target_idx != 0) goto LAB_00471cb5;
    flag_1 = true;
  } while( true );
}



/*
 * Decompiled function: FUN_00471cf1
 * Entry Point: 00471cf1
 * Size: 261 bytes
 */


int FUN_00471cf1(HWND hwnd,int arg2)

{
  int val_1;
  HGDIOBJ h;
  HDC hdc;
  uint32_t local_104 [50];
  tagTEXTMETRICA local_3c;
  
  if (hwnd == (HWND)0x0) {
    val_1 = 0;
  }
  else {
    h = (HGDIOBJ)SendMessageA(hwnd,0x31,0,0);
    if (arg2 == 0) {
      GetWindowTextA(hwnd,(LPSTR)local_104,200);
    }
    else {
      Mem_AllocOrFree_004d9630(local_104,(uint32_t *)arg2);
    }
    hdc = GetDC(hwnd);
    FUN_004707a4(hdc);
    if (h != (HGDIOBJ)0x0) {
      SelectObject(hdc,h);
    }
    val_1 = FUN_00421a54(hdc,(char *)local_104);
    GetTextMetricsA(hdc,&local_3c);
    val_1 = val_1 + local_3c.tmHeight * 3;
    ReleaseDC(hwnd,hdc);
  }
  return val_1;
}



/*
 * Decompiled function: UI_WndProc_00471df6
 * Entry Point: 00471df6
 * Size: 134 bytes
 */


LRESULT UI_WndProc_00471df6(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)

{
  HCURSOR hCursor;
  LRESULT LVar1;
  
  if (uMsg == 0x20) {
    if (DAT_00618158 == 0) {
      hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f8a);
      SetCursor(hCursor);
      LVar1 = 0;
    }
    else {
      LVar1 = DefWindowProcA(hwnd,0x20,wParam,lParam);
    }
  }
  else {
    LVar1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  }
  return LVar1;
}



/*
 * Decompiled function: FUN_00471e86
 * Entry Point: 00471e86
 * Size: 191 bytes
 */


int32_t FUN_00471e86(char *filepath,COLORREF arg_2,HBRUSH arg_3)

{
  HDC hdc;
  size_t c;
  tagRECT player_idx;
  
  SetRect(&player_idx,0,0x23f,0x8c,0x26c);
  if (DAT_004f9784 != 0xffffffff) {
    hdc = CreateDCA(s_DISPLAY_004f9854,(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
    SetTextColor(hdc,arg_2);
    SetBkMode(hdc,1);
    FillRect(hdc,&player_idx,arg_3);
    c = _strlen(str_1);
    TextOutA(hdc,player_idx.left + 5,player_idx.top + 5,str_1,c);
    DeleteDC(hdc);
    Sleep(DAT_004f9784);
  }
  return 1;
}



/*
 * Decompiled function: FUN_00471f45
 * Entry Point: 00471f45
 * Size: 978 bytes
 */


void FUN_00471f45(int player_id,HBRUSH arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4,COLORREF arg_5,int arg_6)

{
  HDC hdc;
  HGDIOBJ h;
  size_t c;
  tagSIZE *psizl;
  RECT local_64;
  HGDIOBJ local_54;
  tagRECT local_50;
  CHAR local_40 [52];
  tagSIZE match_count;
  
  hdc = *(HDC *)(arg_1 + 0x18);
  CopyRect(&local_50,(RECT *)(arg_1 + 0x1c));
  GetWindowTextA(*(HWND *)(arg_1 + 0x14),local_40,0x32);
  FUN_004707a4(hdc);
  OffsetRect(&local_50,-*(int *)(arg_1 + 0x1c),-*(int *)(arg_1 + 0x20));
  if ((*(uint8_t *)(arg_1 + 0x10) & 1) == 0) {
    FillRect(hdc,&local_50,arg_2);
    SelectObject(hdc,arg_3);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,0);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,0,local_50.bottom);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,1);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,1,local_50.bottom + -1);
    SelectObject(hdc,arg_4);
    MoveToEx(hdc,local_50.right + -1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,local_50.bottom);
    MoveToEx(hdc,1,local_50.bottom + -1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,local_50.bottom + -1);
    MoveToEx(hdc,local_50.right + -2,2,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -2,local_50.bottom + -1);
    MoveToEx(hdc,2,local_50.bottom + -2,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,local_50.bottom + -2);
  }
  else {
    FillRect(hdc,&local_50,arg_2);
    h = GetStockObject(7);
    SelectObject(hdc,h);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,0);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,0,local_50.bottom);
    SelectObject(hdc,arg_4);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,1);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,1,local_50.bottom + -1);
    SelectObject(hdc,arg_3);
    MoveToEx(hdc,local_50.right + -1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,local_50.bottom);
    MoveToEx(hdc,1,local_50.bottom + -1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,local_50.bottom + -1);
    OffsetRect(&local_50,2,2);
  }
  SetBkMode(hdc,1);
  SetTextColor(hdc,arg_5);
  local_54 = (HGDIOBJ)SendMessageA(*(HWND *)(arg_1 + 0x14),0x31,0,0);
  SelectObject(hdc,local_54);
  DrawTextA(hdc,local_40,-1,&local_50,0x25);
  if ((arg_6 != 0) && ((*(uint8_t *)(arg_1 + 0x10) & 0x10) != 0)) {
    psizl = &match_count;
    c = _strlen(local_40);
    GetTextExtentPoint32A(hdc,local_40,c,psizl);
    local_64.left = ((local_50.right - local_50.left) / 2 - match_count.cx / 2) + -3;
    local_64.right = match_count.cx + local_64.left + 6;
    local_64.top = ((local_50.bottom - local_50.top) / 2 - match_count.cy / 2) + -3;
    local_64.bottom = match_count.cy + local_64.top + 6;
    DrawFocusRect(hdc,&local_64);
  }
  return;
}



/*
 * Decompiled function: FUN_00472317
 * Entry Point: 00472317
 * Size: 571 bytes
 */


void FUN_00472317(int player_id,HANDLE arg_2,HANDLE arg_3,HANDLE arg_4,COLORREF arg_5,int arg_6)

{
  HDC hdc;
  size_t c;
  tagSIZE *psizl;
  RECT local_f8;
  HGDIOBJ local_e8;
  tagRECT local_e4;
  CHAR local_d4 [200];
  tagSIZE match_count;
  
  hdc = *(HDC *)(arg_1 + 0x18);
  CopyRect(&local_e4,(RECT *)(arg_1 + 0x1c));
  GetWindowTextA(*(HWND *)(arg_1 + 0x14),local_d4,200);
  FUN_004707a4(hdc);
  OffsetRect(&local_e4,-*(int *)(arg_1 + 0x1c),-*(int *)(arg_1 + 0x20));
  if ((*(uint8_t *)(arg_1 + 0x10) & 1) == 0) {
    if (((*(uint8_t *)(arg_1 + 0x10) & 4) == 0) && ((*(uint8_t *)(arg_1 + 0x10) & 2) == 0)) {
      FUN_004709ae((int)hdc,(int)&local_e4,arg_2);
    }
    else {
      FUN_004709ae((int)hdc,(int)&local_e4,arg_4);
    }
  }
  else {
    FUN_004709ae((int)hdc,(int)&local_e4,arg_3);
    OffsetRect(&local_e4,2,2);
  }
  SetBkMode(hdc,1);
  SetTextColor(hdc,arg_5);
  local_e8 = (HGDIOBJ)SendMessageA(*(HWND *)(arg_1 + 0x14),0x31,0,0);
  SelectObject(hdc,local_e8);
  DrawTextA(hdc,local_d4,-1,&local_e4,0x25);
  if ((arg_6 != 0) && ((*(uint8_t *)(arg_1 + 0x10) & 0x10) != 0)) {
    psizl = &match_count;
    c = _strlen(local_d4);
    GetTextExtentPoint32A(hdc,local_d4,c,psizl);
    local_f8.left = ((local_e4.right - local_e4.left) / 2 - match_count.cx / 2) + -3;
    local_f8.right = match_count.cx + local_f8.left + 6;
    local_f8.top = ((local_e4.bottom - local_e4.top) / 2 - match_count.cy / 2) + -3;
    local_f8.bottom = match_count.cy + local_f8.top + 6;
    DrawFocusRect(hdc,&local_f8);
  }
  return;
}



/*
 * Decompiled function: FUN_00472552
 * Entry Point: 00472552
 * Size: 28 bytes
 */


void FUN_00472552(HWND hwnd)

{
  EnumChildWindows(hwnd,FUN_0047256e,0);
  return;
}



/*
 * Decompiled function: FUN_0047256e
 * Entry Point: 0047256e
 * Size: 65 bytes
 */


int32_t FUN_0047256e(HWND hwnd)

{
  int val_1;
  
  val_1 = FUN_004726e4(hwnd);
  if (val_1 != 0) {
    DAT_00693418 = SetWindowLongA(hwnd,-4,0x4725af);
  }
  return 1;
}



/*
 * Decompiled function: FUN_004725af
 * Entry Point: 004725af
 * Size: 309 bytes
 */


LRESULT FUN_004725af(HWND hwnd,UINT y,HWND param_3,LPARAM arg_4)

{
  int val_1;
  HWND hWnd;
  UINT Msg;
  int32_t card_idx;
  int32_t match_count;
  int32_t slot_idx;
  
  if ((y == 7) || (y == 8)) {
    if (y == 7) {
      match_count = hwnd;
      card_idx = param_3;
    }
    else {
      card_idx = hwnd;
      match_count = param_3;
    }
    val_1 = FUN_004726e4(match_count);
    if (val_1 == 0) {
      match_count = (HWND)0x0;
    }
    val_1 = FUN_004726e4(card_idx);
    if (val_1 == 0) {
      card_idx = (HWND)0x0;
    }
    Msg = 0x4c8;
    hWnd = GetParent(hwnd);
    SendMessageA(hWnd,Msg,(WPARAM)match_count,(LPARAM)card_idx);
    slot_idx = 0;
  }
  else if ((y == 0x311) || ((y == 0x310 || (y == 0x30f)))) {
    slot_idx = CallWindowProcA(DAT_00693418,hwnd,y,(WPARAM)param_3,arg_4);
    FUN_00472b60(hwnd,y,param_3,arg_4);
  }
  else {
    slot_idx = CallWindowProcA(DAT_00693418,hwnd,y,(WPARAM)param_3,arg_4);
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_004726e4
 * Entry Point: 004726e4
 * Size: 72 bytes
 */


bool FUN_004726e4(HWND hwnd)

{
  int val_1;
  CHAR local_68 [100];
  
  GetClassNameA(hwnd,local_68,100);
  val_1 = _strcmp(local_68,s_Button_004f985c);
  return val_1 == 0;
}



/*
 * Decompiled function: FUN_00472731
 * Entry Point: 00472731
 * Size: 268 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint8_t * FUN_00472731(uint32_t *arg1,int arg2)

{
  uint32_t local_6c [25];
  UINT slot_idx;
  
  FID_conflict__memcpy(&DAT_00522468,&DAT_004f9788,0x3c);
  Mem_AllocOrFree_004d9630(local_6c,(uint32_t *)&DAT_004f9864);
  FUN_004d9640(local_6c,arg1);
  _DAT_00522468 = GetPrivateProfileIntA(s_Fonts_004f986c,(LPCSTR)local_6c,0x14,&DAT_00664c40);
  Mem_AllocOrFree_004d9630(local_6c,(uint32_t *)&DAT_004f9874);
  FUN_004d9640(local_6c,arg1);
  slot_idx = GetPrivateProfileIntA(s_Fonts_004f987c,(LPCSTR)local_6c,0,&DAT_00664c40);
  if (slot_idx != 0) {
    _DAT_00522478 = 700;
  }
  if (arg2 != 0) {
    DAT_0052247c = 1;
  }
  Mem_AllocOrFree_004d9630(local_6c,(uint32_t *)&DAT_004f9884);
  FUN_004d9640(local_6c,arg1);
  GetPrivateProfileStringA
            (s_Fonts_004f989c,(LPCSTR)local_6c,s_MS_Sans_Serif_004f988c,&DAT_00522484,0x20,
             &DAT_00664c40);
  return &DAT_00522468;
}



/*
 * Decompiled function: FUN_0047283d
 * Entry Point: 0047283d
 * Size: 383 bytes
 */


/* WARNING: Type propagation algorithm not settling */

void FUN_0047283d(void)

{
  bool flag_1;
  BOOL BVar2;
  int val_3;
  int local_3c;
  int local_34;
  int local_30;
  HWND local_2c;
  int local_28;
  int loop_idx;
  int32_t color_idx;
  int32_t target_idx;
  int32_t player_idx;
  int32_t card_idx;
  int32_t match_count;
  int32_t slot_idx;
  
  slot_idx = DAT_0060cc6c;
  match_count = DAT_00664d90;
  card_idx = DAT_00663df0;
  player_idx = DAT_00618ab0;
  target_idx = DAT_00694748;
  color_idx = DAT_006152b0;
  loop_idx = DAT_00663df4;
  flag_1 = false;
  local_2c = DAT_00618990;
  local_34 = -1;
  while (local_2c != (HWND)0x0) {
    local_2c = GetWindow(local_2c,3);
    local_30 = 0;
    local_28 = -1;
    while ((local_30 < 7 && (local_28 == -1))) {
      if ((HWND)(&loop_idx)[local_30] == local_2c) {
        local_28 = local_30;
      }
      local_30 = local_30 + 1;
    }
    if ((local_28 != -1) && (BVar2 = IsWindowVisible(local_2c), BVar2 != 0)) {
      if (local_28 < local_34) {
        flag_1 = true;
      }
      local_34 = local_28;
    }
  }
  if ((flag_1) && (val_3 = FUN_004729bc((int)&loop_idx,7), val_3 != -1)) {
    SetWindowPos((HWND)(&loop_idx)[val_3],(HWND)0x1,0,0,0,0,3);
    if (val_3 + 1 < 7) {
      local_3c = (int)&color_idx + val_3 * 4;
    }
    else {
      local_3c = 0;
    }
    FUN_00472a3f((HWND)(&loop_idx)[val_3],local_3c,7 - (val_3 + 1));
  }
  return;
}



/*
 * Decompiled function: FUN_004729bc
 * Entry Point: 004729bc
 * Size: 131 bytes
 */


int FUN_004729bc(int arg1,int arg2)

{
  BOOL BVar1;
  int match_count;
  int slot_idx;
  
  slot_idx = -1;
  if ((arg1 == 0) || (arg2 == 0)) {
    slot_idx = -1;
  }
  else {
    match_count = 0;
    while ((match_count < arg2 && (slot_idx == -1))) {
      BVar1 = IsWindowVisible(*(HWND *)(arg1 + match_count * 4));
      if (BVar1 != 0) {
        slot_idx = match_count;
      }
      match_count = match_count + 1;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_00472a3f
 * Entry Point: 00472a3f
 * Size: 190 bytes
 */


int32_t FUN_00472a3f(HWND hwnd,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int32_t match_count;
  
  if ((arg_2 == 0) || (arg_3 < 1)) {
    uval_1 = 0;
  }
  else {
    val_2 = FUN_004729bc(arg_2,arg_3);
    if (val_2 == -1) {
      uval_1 = 0;
    }
    else {
      SetWindowPos(*(HWND *)(arg_2 + val_2 * 4),hwnd,0,0,0,0,3);
      if (val_2 + 1 < arg_3) {
        match_count = val_2 * 4 + 4 + arg_2;
      }
      else {
        match_count = 0;
      }
      FUN_00472a3f(*(HWND *)(arg_2 + val_2 * 4),match_count,arg_3 - (val_2 + 1));
      uval_1 = 1;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00472b02
 * Entry Point: 00472b02
 * Size: 94 bytes
 */


uint32_t FUN_00472b02(int player_id)

{
  return CONCAT12((&DAT_00617580)[arg_1 * 4],
                  CONCAT11((&DAT_00617581)[arg_1 * 4],(&DAT_00617582)[arg_1 * 4])) | 0x2000000;
}



/*
 * Decompiled function: FUN_00472b60
 * Entry Point: 00472b60
 * Size: 421 bytes
 */


int32_t FUN_00472b60(HWND hwnd,uint32_t y,HWND param_3,int32_t arg_4)

{
  uint32_t uval_1;
  UINT UVar2;
  HDC hdc;
  int32_t uval_3;
  HWND local_38;
  uint32_t local_34;
  HWND local_30;
  int32_t local_2c;
  DWORD color_idx;
  HDC target_idx;
  DWORD player_idx;
  DWORD card_idx;
  HWND match_count;
  DWORD slot_idx;
  
  if (y == 0x30f) {
    UnrealizeObject(DAT_005f76d0);
    hdc = GetDC(hwnd);
    SelectPalette(hdc,DAT_005f76d0,0);
    UVar2 = RealizePalette(hdc);
    if (UVar2 != 0) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
    }
    ReleaseDC(hwnd,hdc);
    uval_3 = 1;
  }
  else if ((y < 0x310) || (0x311 < y)) {
    uval_3 = 0;
  }
  else {
    match_count = param_3;
    if (hwnd != param_3) {
      player_idx = GetWindowThreadProcessId(param_3,&slot_idx);
      color_idx = GetWindowThreadProcessId(hwnd,&card_idx);
      if (card_idx == slot_idx) {
        uval_1 = GetWindowLongA(hwnd,-0x10);
        if ((uval_1 & 0x40000000) == 0) {
          target_idx = GetDC(hwnd);
          SelectPalette(target_idx,DAT_005f76d0,1);
          UVar2 = RealizePalette(target_idx);
          if (UVar2 != 0) {
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          ReleaseDC(hwnd,target_idx);
        }
      }
      else {
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
    }
    if (y == 0x311) {
      local_38 = hwnd;
      local_34 = y;
      local_30 = param_3;
      local_2c = arg_4;
      EnumChildWindows(hwnd,FUN_00472d0a,(LPARAM)&local_38);
    }
    uval_3 = 0;
  }
  return uval_3;
}



/*
 * Decompiled function: FUN_00472d0a
 * Entry Point: 00472d0a
 * Size: 84 bytes
 */


int32_t FUN_00472d0a(HWND hwnd,int *arg2)

{
  HWND pHVar1;
  
  pHVar1 = GetParent(hwnd);
  if (pHVar1 == (HWND)*arg2) {
    SendMessageA(hwnd,arg2[1],arg2[2],arg2[3]);
  }
  return 1;
}



/*
 * Decompiled function: FUN_00472d60
 * Entry Point: 00472d60
 * Size: 305 bytes
 */


uint32_t FUN_00472d60(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  int val_1;
  uint32_t *u_ptr_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int32_t card_idx;
  
  if (arg_1 == 0) {
    card_idx = 0;
  }
  else if ((((arg_2 == 0x20) || (arg_2 == 0x18)) || (arg_2 == 0x10)) || (arg_2 == 8)) {
    val_1 = (int)(arg_2 + (arg_2 >> 0x1f & 7U)) >> 3;
    uval_3 = val_1 * arg_3 >> 0x1f;
    uval_3 = 4 - (((val_1 * arg_3 ^ uval_3) - uval_3 & 3 ^ uval_3) - uval_3);
    uval_4 = (int)uval_3 >> 0x1f;
    u_ptr_2 = (uint32_t *)((val_1 * arg_3 + (((uval_3 ^ uval_4) - uval_4 & 3 ^ uval_4) - uval_4)) * arg_5 +
                      val_1 * arg_4 + arg_1);
    if (arg_2 == 0x20) {
      card_idx = *u_ptr_2;
    }
    else if (arg_2 == 0x18) {
      card_idx = (uint32_t)(uint8_t)*u_ptr_2 << 0x10 | (uint32_t)*(uint8_t *)((int)u_ptr_2 + 1) << 8 |
                 (uint32_t)*(uint8_t *)((int)u_ptr_2 + 2);
    }
    else if (arg_2 == 0x10) {
      card_idx = (uint32_t)CONCAT11((uint8_t)*u_ptr_2,*(uint8_t *)((int)u_ptr_2 + 1));
    }
    else if (arg_2 == 8) {
      card_idx = (uint32_t)(uint8_t)*u_ptr_2;
    }
  }
  else {
    card_idx = 0;
  }
  return card_idx;
}



/*
 * Decompiled function: FUN_00472ea0
 * Entry Point: 00472ea0
 * Size: 278 bytes
 */


void FUN_00472ea0(int player_id,int card_slot,int event_type,int arg_4,int arg_5,int32_t arg_6)

{
  uint8_t uval_3;
  int val_1;
  int32_t *u_ptr_2;
  uint32_t uval_4;
  uint32_t uval_5;
  
  if ((arg_1 != 0) && ((((arg_2 == 0x20 || (arg_2 == 0x18)) || (arg_2 == 0x10)) || (arg_2 == 8)))) {
    val_1 = (int)(arg_2 + (arg_2 >> 0x1f & 7U)) >> 3;
    uval_4 = arg_3 * val_1 >> 0x1f;
    uval_4 = 4 - (((arg_3 * val_1 ^ uval_4) - uval_4 & 3 ^ uval_4) - uval_4);
    uval_5 = (int)uval_4 >> 0x1f;
    u_ptr_2 = (int32_t *)
             ((arg_3 * val_1 + (((uval_4 ^ uval_5) - uval_5 & 3 ^ uval_5) - uval_5)) * arg_5 +
              arg_4 * val_1 + arg_1);
    if (arg_2 == 0x20) {
      *u_ptr_2 = arg_6;
    }
    else {
      uval_3 = (uint8_t)((uint32_t)arg_6 >> 8);
      if (arg_2 == 0x18) {
        *(char *)u_ptr_2 = (char)((uint32_t)arg_6 >> 0x10);
        *(uint8_t *)((int)u_ptr_2 + 1) = uval_3;
        *(uint8_t *)((int)u_ptr_2 + 2) = (uint8_t)arg_6;
      }
      else if (arg_2 == 0x10) {
        *(uint8_t *)u_ptr_2 = uval_3;
        *(uint8_t *)((int)u_ptr_2 + 1) = (uint8_t)arg_6;
      }
      else if (arg_2 == 8) {
        *(uint8_t *)u_ptr_2 = (uint8_t)arg_6;
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00472fc0
 * Entry Point: 00472fc0
 * Size: 2674 bytes
 */


void FUN_00472fc0(int player_id)

{
  int val_1;
  int32_t uval_2;
  int arg_1_00;
  int val_3;
  int val_4;
  uint32_t uval_5;
  int val_6;
  int player_idx;
  
  arg_1_00 = 1 - arg_1;
  _memset(&DAT_00692c80,0,0x780);
  for (player_idx = 0; player_idx < (int)(&DAT_00666408)[arg_1]; player_idx = player_idx + 1) {
    if ((*(int *)(&DAT_006826c4 + player_idx * 0x120 + arg_1 * 0x5b20) != -1) &&
       (((&DAT_006826cc)[player_idx * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
      val_6 = *(int *)(&DAT_006826c4 + player_idx * 0x120 + arg_1 * 0x5b20);
      val_3 = (int)(char)(&DAT_006826d2)[player_idx * 0x120 + arg_1 * 0x5b20];
      val_1 = *(int *)(&DAT_006826e8 + player_idx * 0x120 + arg_1 * 0x5b20);
      if ((*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == CardScript_Regeneration) &&
         (val_4 = FUN_0049b309(val_3,3,1), val_4 != 0)) {
        *(uint32_t *)(&DAT_00692c88 + val_1 * 0xc + val_3 * 0x3c0) =
             *(uint32_t *)(&DAT_00692c88 + val_1 * 0xc + val_3 * 0x3c0) | 0x200;
        *(uint32_t *)(&DAT_006826fc + val_1 * 0x120 + val_3 * 0x5b20) =
             *(uint32_t *)(&DAT_006826fc + val_1 * 0x120 + val_3 * 0x5b20) | 0x200;
      }
      else if ((*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == CardScript_TheBrute) &&
              (val_4 = FUN_0049b309(val_3,4,3), val_4 != 0)) {
        *(uint32_t *)(&DAT_00692c88 + val_1 * 0xc + val_3 * 0x3c0) =
             *(uint32_t *)(&DAT_00692c88 + val_1 * 0xc + val_3 * 0x3c0) | 0x200;
        *(uint32_t *)(&DAT_006826fc + val_1 * 0x120 + val_3 * 0x5b20) =
             *(uint32_t *)(&DAT_006826fc + val_1 * 0x120 + val_3 * 0x5b20) | 0x200;
      }
      if (*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == CardScript_HolyArmor) {
        val_4 = FUN_0049b309(val_3,5,1);
        *(int *)(&DAT_00692c84 + val_1 * 0xc + val_3 * 0x3c0) =
             *(int *)(&DAT_00692c84 + val_1 * 0xc + val_3 * 0x3c0) + val_4;
      }
      else if (*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == CardScript_Firebreathing) {
        val_4 = FUN_0049b309(val_3,4,1);
        *(int *)(&DAT_00692c80 + val_1 * 0xc + val_3 * 0x3c0) =
             *(int *)(&DAT_00692c80 + val_1 * 0xc + val_3 * 0x3c0) + val_4;
      }
      else if (*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == CardScript_Blessing) {
        val_4 = FUN_0049b309(val_3,5,1);
        *(int *)(&DAT_00692c80 + val_1 * 0xc + val_3 * 0x3c0) =
             *(int *)(&DAT_00692c80 + val_1 * 0xc + val_3 * 0x3c0) + val_4;
        val_4 = FUN_0049b309(val_3,5,1);
        *(int *)(&DAT_00692c84 + val_1 * 0xc + val_3 * 0x3c0) =
             *(int *)(&DAT_00692c84 + val_1 * 0xc + val_3 * 0x3c0) + val_4;
      }
      *(uint32_t *)(&DAT_006826fc + player_idx * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826fc + player_idx * 0x120 + arg_1 * 0x5b20) | 0xe000000;
      uval_2 = *(int32_t *)(&DAT_006826cc + player_idx * 0x120 + arg_1 * 0x5b20);
      if (arg_1 == DAT_00676504) {
        if (((&DAT_006826cd)[player_idx * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) {
          *(uint32_t *)(&DAT_006826cc + player_idx * 0x120 + arg_1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826cc + player_idx * 0x120 + arg_1 * 0x5b20) | 0x14;
        }
        else {
          *(uint32_t *)(&DAT_006826cc + player_idx * 0x120 + arg_1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826cc + player_idx * 0x120 + arg_1 * 0x5b20) | 4;
        }
      }
      DAT_00693404 = FUN_0048b81a(arg_1,player_idx,0x32,0xffffffff);
      DAT_00693414 = FUN_0048b81a(arg_1,player_idx,0x33,0xffffffff);
      DAT_00693410 = FUN_0048b81a(arg_1,player_idx,0x34,0xffffffff);
      uval_5 = FUN_0048c367((&DAT_004ff596)[val_6 * 0x34]);
      if (((DAT_00693410 & 0x200) != 0) && (val_6 = FUN_0049b309(arg_1,uval_5,1), val_6 == 0)) {
        DAT_00693410 = DAT_00693410 & 0xfffffdff;
      }
      if (arg_1 == DAT_00676510) {
        FUN_0048c50b(arg_1,player_idx,0x8c);
      }
      *(int *)(&DAT_00692c80 + player_idx * 0xc + arg_1 * 0x3c0) =
           *(int *)(&DAT_00692c80 + player_idx * 0xc + arg_1 * 0x3c0) + DAT_00693404;
      *(int *)(&DAT_00692c84 + player_idx * 0xc + arg_1 * 0x3c0) =
           *(int *)(&DAT_00692c84 + player_idx * 0xc + arg_1 * 0x3c0) + DAT_00693414;
      *(uint32_t *)(&DAT_00692c88 + player_idx * 0xc + arg_1 * 0x3c0) =
           *(uint32_t *)(&DAT_00692c88 + player_idx * 0xc + arg_1 * 0x3c0) | DAT_00693410;
      *(int32_t *)(&DAT_006826cc + player_idx * 0x120 + arg_1 * 0x5b20) = uval_2;
    }
  }
  DAT_00693400 = 0;
  for (player_idx = 0; player_idx < (int)(&DAT_00666408)[arg_1_00]; player_idx = player_idx + 1) {
    if ((*(int *)(&DAT_006826c4 + player_idx * 0x120 + arg_1_00 * 0x5b20) != -1) &&
       (((&DAT_006826cc)[player_idx * 0x120 + arg_1_00 * 0x5b20] & 2) != 0)) {
      val_6 = *(int *)(&DAT_006826c4 + player_idx * 0x120 + arg_1_00 * 0x5b20);
      val_3 = (int)(char)(&DAT_006826d2)[player_idx * 0x120 + arg_1_00 * 0x5b20];
      val_1 = *(int *)(&DAT_006826e8 + player_idx * 0x120 + arg_1_00 * 0x5b20);
      if ((*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == CardScript_Regeneration) &&
         (val_4 = FUN_0049b309(val_3,3,1), val_4 != 0)) {
        *(uint32_t *)(&DAT_00692c88 + val_1 * 0xc + val_3 * 0x3c0) =
             *(uint32_t *)(&DAT_00692c88 + val_1 * 0xc + val_3 * 0x3c0) | 0x200;
        *(uint32_t *)(&DAT_006826fc + val_1 * 0x120 + val_3 * 0x5b20) =
             *(uint32_t *)(&DAT_006826fc + val_1 * 0x120 + val_3 * 0x5b20) | 0x200;
      }
      else if ((*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == CardScript_TheBrute) &&
              (val_4 = FUN_0049b309(val_3,4,3), val_4 != 0)) {
        *(uint32_t *)(&DAT_00692c88 + val_1 * 0xc + val_3 * 0x3c0) =
             *(uint32_t *)(&DAT_00692c88 + val_1 * 0xc + val_3 * 0x3c0) | 0x200;
        *(uint32_t *)(&DAT_006826fc + val_1 * 0x120 + val_3 * 0x5b20) =
             *(uint32_t *)(&DAT_006826fc + val_1 * 0x120 + val_3 * 0x5b20) | 0x200;
      }
      if (*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == CardScript_HolyArmor) {
        val_4 = FUN_0049b309(val_3,5,1);
        *(int *)(&DAT_00692c84 + val_1 * 0xc + val_3 * 0x3c0) =
             *(int *)(&DAT_00692c84 + val_1 * 0xc + val_3 * 0x3c0) + val_4;
      }
      else if (*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == CardScript_Firebreathing) {
        val_4 = FUN_0049b309(val_3,4,1);
        *(int *)(&DAT_00692c80 + val_1 * 0xc + val_3 * 0x3c0) =
             *(int *)(&DAT_00692c80 + val_1 * 0xc + val_3 * 0x3c0) + val_4;
      }
      else if (*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == CardScript_Blessing) {
        val_4 = FUN_0049b309(val_3,5,1);
        *(int *)(&DAT_00692c80 + val_1 * 0xc + val_3 * 0x3c0) =
             *(int *)(&DAT_00692c80 + val_1 * 0xc + val_3 * 0x3c0) + val_4;
        val_4 = FUN_0049b309(val_3,5,1);
        *(int *)(&DAT_00692c84 + val_1 * 0xc + val_3 * 0x3c0) =
             *(int *)(&DAT_00692c84 + val_1 * 0xc + val_3 * 0x3c0) + val_4;
      }
      *(uint32_t *)(&DAT_006826fc + player_idx * 0x120 + arg_1_00 * 0x5b20) =
           *(uint32_t *)(&DAT_006826fc + player_idx * 0x120 + arg_1_00 * 0x5b20) | 0xe000000;
      uval_2 = *(int32_t *)(&DAT_006826cc + player_idx * 0x120 + arg_1_00 * 0x5b20);
      *(uint32_t *)(&DAT_006826cc + player_idx * 0x120 + arg_1_00 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + player_idx * 0x120 + arg_1_00 * 0x5b20) | 8;
      DAT_00693404 = FUN_0048b81a(arg_1_00,player_idx,0x32,0xffffffff);
      DAT_00693414 = FUN_0048b81a(arg_1_00,player_idx,0x33,0xffffffff);
      DAT_00693410 = FUN_0048b81a(arg_1_00,player_idx,0x34,0xffffffff);
      uval_5 = FUN_0048c367((&DAT_004ff596)[val_6 * 0x34]);
      if (((DAT_00693410 & 0x200) != 0) && (val_6 = FUN_0049b309(arg_1_00,uval_5,1), val_6 == 0)) {
        DAT_00693410 = DAT_00693410 & 0xfffffdff;
      }
      if (DAT_00676510 == arg_1_00) {
        FUN_0048c50b(arg_1_00,player_idx,0x8c);
      }
      *(int *)(&DAT_00692c80 + player_idx * 0xc + arg_1_00 * 0x3c0) =
           *(int *)(&DAT_00692c80 + player_idx * 0xc + arg_1_00 * 0x3c0) + DAT_00693404;
      *(int *)(&DAT_00692c84 + player_idx * 0xc + arg_1_00 * 0x3c0) =
           *(int *)(&DAT_00692c84 + player_idx * 0xc + arg_1_00 * 0x3c0) + DAT_00693414;
      *(uint32_t *)(&DAT_00692c88 + player_idx * 0xc + arg_1_00 * 0x3c0) =
           *(uint32_t *)(&DAT_00692c88 + player_idx * 0xc + arg_1_00 * 0x3c0) | DAT_00693410;
      *(int32_t *)(&DAT_006826cc + player_idx * 0x120 + arg_1_00 * 0x5b20) = uval_2;
      val_6 = *(int *)(&DAT_006826c4 + player_idx * 0x120 + arg_1_00 * 0x5b20);
      if (*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == FUN_004d2b76) {
        DAT_00693400 = DAT_00693400 | 2;
      }
      if (*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == FUN_004d2c1b) {
        DAT_00693400 = DAT_00693400 | 4;
      }
      if (*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == FUN_004d2c52) {
        DAT_00693400 = DAT_00693400 | 8;
      }
      if (*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == FUN_004d2be4) {
        DAT_00693400 = DAT_00693400 | 0x10;
      }
      if (*(code **)(&DAT_004ff5a0 + val_6 * 0x34) == FUN_004d2bad) {
        DAT_00693400 = DAT_00693400 | 0x20;
      }
    }
  }
  if (DAT_00693400 == 0) {
    DAT_00693408 = 0;
  }
  else {
    DAT_00693408 = FUN_0049b309(arg_1_00,7,0);
  }
  FUN_0048b64f();
  return;
}



/*
 * Decompiled function: FUN_00473a32
 * Entry Point: 00473a32
 * Size: 4945 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00473a32(int player_id)

{
  int val_1;
  int val_2;
  int val_3;
  uint32_t uval_4;
  int aiStack_cc [16];
  uint32_t local_8c;
  int local_88;
  int local_84;
  uint32_t local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int32_t local_6c;
  int local_68;
  int32_t local_64;
  int local_60;
  int local_5c;
  int aiStack_58 [16];
  uint32_t target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  uint32_t slot_idx;
  
  DAT_00522908 = 1 - arg_1;
  if (DAT_00522a00 == 0) {
    FUN_00431f41(&slot_idx,&target_idx);
    if (DAT_00522908 == 1) {
      DAT_00522f7c = slot_idx;
    }
    else {
      DAT_00522f7c = target_idx;
    }
    DAT_00522f78 = 0;
    DAT_0052297c = 0;
    local_6c = DAT_0066aaf4;
    DAT_0066aaf4 = 1;
    DAT_006c121c = 1;
    FUN_00479952();
    FUN_00430120();
    local_64 = DAT_0068f2d4;
    DAT_0068f2d4 = 0;
    DAT_00522884 = 0;
    _DAT_005226e8 = 0;
    Magic_ScanCards(199);
    Rules_ProcessDamagePrevention(arg_1);
    local_88 = FUN_00430911(arg_1);
    local_88 = DAT_0068f2d4 + local_88;
    FUN_00430367();
    DAT_0068f2d4 = local_64;
    for (local_70 = 0; local_70 < (int)(&DAT_00666408)[arg_1]; local_70 = local_70 + 1) {
      local_68 = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_70 * 0x120);
      if (((local_68 != -1) && (((&DAT_006826cc)[arg_1 * 0x5b20 + local_70 * 0x120] & 4) != 0)) &&
         (((&DAT_006826de)[arg_1 * 0x5b20 + local_70 * 0x120] == -1 ||
          ((char)(&DAT_006826de)[arg_1 * 0x5b20 + local_70 * 0x120] == local_70)))) {
        local_80 = FUN_0048c367((&DAT_004ff596)[local_68 * 0x34]);
        local_78 = *(int *)(&DAT_00692c80 + local_70 * 0xc + arg_1 * 0x3c0);
        (&DAT_005225a0)[DAT_0052297c] = local_70;
        (&DAT_00522e70)[DAT_0052297c] = *(int *)(&DAT_00666730 + arg_1 * 4) + local_78;
        (&DAT_005226f0)[DAT_0052297c] =
             *(int *)(&DAT_00692c84 + local_70 * 0xc + arg_1 * 0x3c0) +
             *(int *)(&DAT_00666738 + arg_1 * 4);
        (&DAT_005224e0)[DAT_0052297c] =
             *(int32_t *)(&DAT_00692c88 + local_70 * 0xc + arg_1 * 0x3c0);
        val_2 = FUN_0049b309(arg_1,local_80,1);
        if (val_2 == 0) {
          (&DAT_005224e0)[DAT_0052297c] = (&DAT_005224e0)[DAT_0052297c] & 0xfffffdff;
        }
        DAT_0069340c = 0;
        FUN_0048c50b(arg_1,local_70,0x8a);
        (&DAT_00522980)[DAT_0052297c] = DAT_0069340c;
        if (((&DAT_004ff5a8)[local_68 * 0x34] & 8) != 0) {
          val_2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(arg_1,local_70,0x39);
          (&DAT_00522e70)[DAT_0052297c] = (&DAT_00522e70)[DAT_0052297c] + val_2;
        }
        if (((&DAT_004ff5a8)[local_68 * 0x34] & 0x10) != 0) {
          val_2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(arg_1,local_70,0x3a);
          (&DAT_005226f0)[DAT_0052297c] = (&DAT_005226f0)[DAT_0052297c] + val_2;
        }
        FUN_00430120();
        local_64 = DAT_0068f2d4;
        DAT_0068f2d4 = 0;
        *(uint32_t *)(&DAT_006826f8 + arg_1 * 0x5b20 + local_70 * 0x120) =
             *(uint32_t *)(&DAT_006826f8 + arg_1 * 0x5b20 + local_70 * 0x120) | 8;
        FUN_0046e571(arg_1,local_70,2);
        Magic_ScanCards(199);
        Rules_ProcessDamagePrevention(arg_1);
        match_count = FUN_00430911(arg_1);
        match_count = DAT_0068f2d4 + match_count;
        FUN_00430367();
        DAT_0068f2d4 = local_64;
        val_2 = Mem_AllocOrFree_004d9810((int)(char)(&DAT_004ff598)[local_68 * 0x34]);
        card_idx = ((val_2 + (char)(&DAT_004ff597)[local_68 * 0x34]) - match_count) + local_88;
        if ((*(uint8_t *)((int)&DAT_005224e0 + DAT_0052297c * 4 + 1) & 2) != 0) {
          val_2 = FUN_0049b309(arg_1,local_80,1);
          if (val_2 == 0) {
            card_idx = card_idx << 1;
          }
          else {
            card_idx = card_idx / 3;
          }
        }
        *(int *)(&DAT_00682700 + arg_1 * 0x5b20 + local_70 * 0x120) = card_idx;
        (&DAT_00522eb0)[DAT_0052297c] = card_idx;
        (&DAT_005226f0)[DAT_0052297c] =
             (&DAT_005226f0)[DAT_0052297c] -
             (int)*(short *)(&DAT_006826d0 + arg_1 * 0x5b20 + local_70 * 0x120);
        (&DAT_00522778)[DAT_0052297c] = 0;
        if ((&DAT_006827df)[arg_1 * 0x5b20 + local_70 * 0x120] != '\0') {
          _DAT_005226e8 = _DAT_005226e8 | 1 << ((uint8_t)DAT_0052297c & 0x1f);
        }
        DAT_0052297c = DAT_0052297c + 1;
        if ((DAT_0066aaf4 == 1) && (6 < DAT_0052297c)) break;
      }
    }
    for (local_70 = 0; local_70 < (int)(&DAT_00666408)[arg_1]; local_70 = local_70 + 1) {
      local_68 = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_70 * 0x120);
      if ((((local_68 != -1) && (((&DAT_006826cc)[arg_1 * 0x5b20 + local_70 * 0x120] & 4) != 0)) &&
          ((&DAT_006826de)[arg_1 * 0x5b20 + local_70 * 0x120] != -1)) &&
         ((char)(&DAT_006826de)[arg_1 * 0x5b20 + local_70 * 0x120] != local_70)) {
        local_5c = -1;
        for (local_74 = 0; local_74 < DAT_0052297c; local_74 = local_74 + 1) {
          if ((int)(char)(&DAT_006826de)[arg_1 * 0x5b20 + local_70 * 0x120] ==
              (&DAT_005225a0)[local_74]) {
            local_5c = local_74;
            break;
          }
        }
        if (local_5c != -1) {
          local_80 = FUN_0048c367((&DAT_004ff596)[local_68 * 0x34]);
          (&DAT_005229c0)[DAT_00522f78] = local_70;
          local_78 = *(int *)(&DAT_00692c80 + local_70 * 0xc + arg_1 * 0x3c0);
          (&DAT_00522e70)[local_5c] = (&DAT_00522e70)[local_5c] + local_78;
          (&DAT_005226f0)[local_5c] =
               (&DAT_005226f0)[local_5c] + *(int *)(&DAT_00692c84 + local_70 * 0xc + arg_1 * 0x3c0);
          local_8c = *(uint32_t *)(&DAT_00692c88 + local_70 * 0xc + arg_1 * 0x3c0) & 0x200 |
                     (&DAT_005224e0)[local_5c] & 0x200;
          (&DAT_005224e0)[local_5c] =
               (&DAT_005224e0)[local_5c] & *(uint32_t *)(&DAT_00692c88 + local_70 * 0xc + arg_1 * 0x3c0)
          ;
          (&DAT_005224e0)[local_5c] = (&DAT_005224e0)[local_5c] | local_8c;
          if (((&DAT_004ff5a8)[local_68 * 0x34] & 8) != 0) {
            val_2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(arg_1,local_70,0x39);
            (&DAT_00522e70)[local_5c] = (&DAT_00522e70)[local_5c] + val_2;
          }
          if (((&DAT_004ff5a8)[local_68 * 0x34] & 0x10) != 0) {
            val_2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(arg_1,local_70,0x3a);
            (&DAT_005226f0)[local_5c] = (&DAT_005226f0)[local_5c] + val_2;
          }
          FUN_00430120();
          local_64 = DAT_0068f2d4;
          DAT_0068f2d4 = 0;
          *(uint32_t *)(&DAT_006826f8 + arg_1 * 0x5b20 + local_70 * 0x120) =
               *(uint32_t *)(&DAT_006826f8 + arg_1 * 0x5b20 + local_70 * 0x120) | 8;
          FUN_0046e571(arg_1,local_70,2);
          Magic_ScanCards(199);
          Rules_ProcessDamagePrevention(arg_1);
          match_count = FUN_00430911(arg_1);
          match_count = DAT_0068f2d4 + match_count;
          FUN_00430367();
          DAT_0068f2d4 = local_64;
          val_2 = Mem_AllocOrFree_004d9810((int)(char)(&DAT_004ff598)[local_68 * 0x34]);
          card_idx = ((val_2 + (char)(&DAT_004ff597)[local_68 * 0x34]) - match_count) + local_88;
          if ((*(uint8_t *)((int)&DAT_005224e0 + local_5c * 4 + 1) & 2) != 0) {
            val_2 = FUN_0049b309(arg_1,local_80,1);
            if (val_2 == 0) {
              card_idx = card_idx << 1;
            }
            else {
              card_idx = card_idx / 3;
            }
          }
          *(int *)(&DAT_00682700 + arg_1 * 0x5b20 + local_70 * 0x120) = card_idx;
          if (card_idx < (int)(&DAT_00522eb0)[local_5c]) {
            (&DAT_00522eb0)[local_5c] = card_idx;
          }
          (&DAT_005226f0)[local_5c] =
               (&DAT_005226f0)[local_5c] -
               (int)*(short *)(&DAT_006826d0 + arg_1 * 0x5b20 + local_70 * 0x120);
          (&DAT_00522778)[local_5c] = 0;
          if ((&DAT_006827df)[arg_1 * 0x5b20 + local_70 * 0x120] != '\0') {
            _DAT_005226e8 = _DAT_005226e8 | 1 << ((uint8_t)local_5c & 0x1f);
          }
          DAT_00522f78 = DAT_00522f78 + 1;
        }
      }
    }
    local_60 = 0;
    for (local_70 = 0; local_70 < (int)(&DAT_00666408)[DAT_00522908]; local_70 = local_70 + 1) {
      local_68 = *(int *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_70 * 0x120);
      if (((local_68 != -1) && (((&DAT_004ff594)[local_68 * 0x34] & 2) != 0)) &&
         ((((uint8_t)*(int32_t *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) & 0x12)
           == 2 && ((&DAT_006826de)[DAT_00522908 * 0x5b20 + local_70 * 0x120] == -1)))) {
        aiStack_58[local_60] = local_70;
        local_60 = local_60 + 1;
      }
      if ((DAT_0066aaf4 == 1) && (0xf < local_60)) break;
    }
    if ((DAT_0066aaf4 == 1) && (6 < local_60)) {
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        val_2 = FUN_00479e13(DAT_00522908,aiStack_58[local_70]);
        aiStack_cc[local_70] = val_2;
      }
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        for (local_74 = local_70; local_74 < local_60; local_74 = local_74 + 1) {
          if (aiStack_cc[local_70] < aiStack_cc[local_74]) {
            val_2 = aiStack_cc[local_70];
            aiStack_cc[local_70] = aiStack_cc[local_74];
            aiStack_cc[local_74] = val_2;
            val_2 = aiStack_58[local_70];
            aiStack_58[local_70] = aiStack_58[local_74];
            aiStack_58[local_74] = val_2;
          }
        }
      }
      if (6 < local_60) {
        local_60 = 7;
      }
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        for (local_74 = local_70; local_74 < local_60; local_74 = local_74 + 1) {
          if (aiStack_58[local_74] < aiStack_58[local_70]) {
            val_2 = aiStack_58[local_70];
            aiStack_58[local_70] = aiStack_58[local_74];
            aiStack_58[local_74] = val_2;
          }
        }
      }
    }
    DAT_00522a04 = 0;
    for (local_84 = 0; local_84 < local_60; local_84 = local_84 + 1) {
      local_70 = aiStack_58[local_84];
      local_68 = *(int *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_70 * 0x120);
      local_80 = FUN_0048c367((&DAT_004ff596)[local_68 * 0x34]);
      *(uint32_t *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) =
           *(uint32_t *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) | 8;
      local_78 = *(int *)(&DAT_00692c80 + local_70 * 0xc + DAT_00522908 * 0x3c0);
      (&DAT_00522f38)[DAT_00522a04] = local_70;
      (&DAT_00522ef8)[DAT_00522a04] = *(int *)(&DAT_00666730 + DAT_00522908 * 4) + local_78;
      (&DAT_00522730)[DAT_00522a04] =
           *(int *)(&DAT_00692c84 + local_70 * 0xc + DAT_00522908 * 0x3c0) +
           *(int *)(&DAT_00666738 + DAT_00522908 * 4);
      (&DAT_00522520)[DAT_00522a04] =
           *(int32_t *)(&DAT_00692c88 + local_70 * 0xc + DAT_00522908 * 0x3c0);
      val_2 = FUN_0049b309(DAT_00522908,local_80,1);
      if (val_2 == 0) {
        (&DAT_00522520)[DAT_00522a04] = (&DAT_00522520)[DAT_00522a04] & 0xfffffdff;
      }
      DAT_0069340c = 0;
      FUN_0048c50b(DAT_00522908,local_70,0x8b);
      (&DAT_00522910)[DAT_0052297c] = DAT_0069340c;
      if (DAT_00676510 == DAT_00522908) {
        if (((&DAT_004ff5a8)[local_68 * 0x34] & 8) != 0) {
          val_2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(DAT_00522908,local_70,0x39);
          (&DAT_00522ef8)[DAT_00522a04] = (&DAT_00522ef8)[DAT_00522a04] + val_2;
        }
        if (((&DAT_004ff5a8)[local_68 * 0x34] & 0x10) != 0) {
          val_2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(DAT_00522908,local_70,0x3a);
          (&DAT_00522730)[DAT_00522a04] = (&DAT_00522730)[DAT_00522a04] + val_2;
        }
      }
      FUN_00430120();
      local_64 = DAT_0068f2d4;
      DAT_0068f2d4 = 0;
      *(uint32_t *)(&DAT_006826f8 + DAT_00522908 * 0x5b20 + local_70 * 0x120) =
           *(uint32_t *)(&DAT_006826f8 + DAT_00522908 * 0x5b20 + local_70 * 0x120) | 8;
      FUN_0046e571(DAT_00522908,local_70,2);
      Magic_ScanCards(199);
      Rules_ProcessDamagePrevention(arg_1);
      match_count = FUN_00430911(arg_1);
      match_count = DAT_0068f2d4 + match_count;
      FUN_00430367();
      DAT_0068f2d4 = 0;
      *(int32_t *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_70 * 0x120) = 0xffffffff;
      player_idx = FUN_00430911(arg_1);
      player_idx = DAT_0068f2d4 + player_idx;
      FUN_00430367();
      DAT_0068f2d4 = local_64;
      card_idx = match_count - local_88;
      if ((*(uint8_t *)((int)&DAT_00522520 + DAT_00522a04 * 4 + 1) & 2) != 0) {
        val_2 = FUN_0049b309(DAT_00522908,local_80,1);
        if (val_2 == 0) {
          card_idx = card_idx << 1;
        }
        else {
          card_idx = card_idx / 5;
        }
      }
      (&DAT_00522f80)[DAT_00522a04] = card_idx;
      *(int *)(&DAT_00682700 + DAT_00522908 * 0x5b20 + local_70 * 0x120) = card_idx;
      (&DAT_00522730)[DAT_00522a04] =
           (&DAT_00522730)[DAT_00522a04] -
           (int)*(short *)(&DAT_006826d0 + DAT_00522908 * 0x5b20 + local_70 * 0x120);
      *(uint32_t *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) =
           *(uint32_t *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) & 0xfffffff7;
      for (local_74 = 0; local_74 < DAT_0052297c; local_74 = local_74 + 1) {
        val_2 = FUN_0048b2c9(DAT_00522908,local_70,arg_1,(&DAT_005225a0)[local_74],
                             (&DAT_005224e0)[local_74],DAT_00522f7c);
        if (val_2 == 0) {
          if (DAT_00522f78 != 0) {
            for (local_7c = 0; local_7c < DAT_00522f78; local_7c = local_7c + 1) {
              if (((int)(char)(&DAT_006826de)[arg_1 * 0x5b20 + (&DAT_005229c0)[local_7c] * 0x120] ==
                   (&DAT_005225a0)[local_70]) &&
                 (val_2 = FUN_0048b2c9(DAT_00522908,local_70,arg_1,(&DAT_005229c0)[local_7c],
                                       (&DAT_005224e0)[local_74],DAT_00522f7c), val_2 != 0)) {
                (&DAT_00522778)[local_74] =
                     (&DAT_00522778)[local_74] | 1 << ((uint8_t)DAT_00522a04 & 0x1f);
              }
            }
          }
        }
        else {
          (&DAT_00522778)[local_74] = (&DAT_00522778)[local_74] | 1 << ((uint8_t)DAT_00522a04 & 0x1f);
        }
      }
      if ((&DAT_006827df)[DAT_00522908 * 0x5b20 + local_70 * 0x120] != '\0') {
        DAT_00522884 = DAT_00522884 | 1 << ((uint8_t)DAT_00522a04 & 0x1f);
      }
      *(uint32_t *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) =
           *(uint32_t *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) & 0xfffffff7;
      val_2 = *(int *)(&DAT_00666718 + DAT_00522908 * 4);
      val_1 = (&DAT_00522f80)[DAT_00522a04];
      val_3 = FUN_0049aa14((&DAT_00522730)[DAT_00522a04] + 1,1,99);
      (&DAT_00522560)[DAT_00522a04] = (val_2 * val_1) / val_3;
      DAT_00522a04 = DAT_00522a04 + 1;
      if ((DAT_0066aaf4 == 1) && (6 < DAT_00522a04)) break;
    }
    _memset(&DAT_00522950,0,0x1c);
    _memset(&DAT_00522a08,0,0x1c);
    for (local_70 = 0; local_70 < DAT_0052297c; local_70 = local_70 + 1) {
      for (local_74 = 0; local_74 < DAT_00522a04; local_74 = local_74 + 1) {
        uval_4 = FUN_0048f31a(arg_1,(&DAT_005225a0)[local_70],DAT_00522908,(&DAT_00522f38)[local_74])
        ;
        if ((uval_4 & 1) != 0) {
          *(uint32_t *)(&DAT_00522950 + local_70 * 4) =
               *(uint32_t *)(&DAT_00522950 + local_70 * 4) | 1 << ((uint8_t)local_74 & 0x1f);
        }
        if ((uval_4 & 2) != 0) {
          *(uint32_t *)(&DAT_00522a08 + local_74 * 4) =
               *(uint32_t *)(&DAT_00522a08 + local_74 * 4) | 1 << ((uint8_t)local_70 & 0x1f);
        }
      }
    }
    DAT_0066aaf4 = local_6c;
  }
  DAT_00522a00 = 0;
  DAT_006c121c = 0;
  DAT_00522770 = (&DAT_004f98a8)[DAT_0052297c];
  return;
}



/*
 * Decompiled function: FUN_00474d83
 * Entry Point: 00474d83
 * Size: 6885 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t FUN_00474d83(int player_id)

{
  uint32_t uval_1;
  int val_2;
  uint32_t uval_3;
  int val_4;
  int local_47c;
  int local_478;
  int local_474;
  int local_470;
  int local_46c [7];
  int local_450 [9];
  uint32_t local_42c;
  int local_428;
  int local_424;
  int local_420;
  int aiStack_41c [16];
  int aiStack_3dc [16];
  int32_t local_39c [16];
  char acStack_35c [84];
  uint32_t local_308 [16];
  int local_2c8;
  uint32_t local_2c4;
  uint32_t local_2c0;
  int local_2bc;
  int local_2b8;
  uint32_t local_2b4;
  int local_2b0;
  int local_2ac;
  int local_2a8;
  uint32_t local_2a4;
  int32_t local_2a0;
  int local_29c;
  int32_t local_298 [16];
  int local_258;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  int aiStack_244 [16];
  int local_204;
  uint32_t local_200;
  int aiStack_1fc [14];
  int aiStack_1c4 [18];
  int local_17c;
  int aiStack_178 [16];
  int local_138;
  char acStack_134 [80];
  int local_e4;
  int aiStack_e0 [16];
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  uint32_t local_8c;
  int local_88 [16];
  int32_t local_48 [16];
  uint32_t slot_idx;
  
  FUN_00472fc0(arg_1);
  local_2a0 = DAT_005ef980;
  DAT_005ef980 = 2;
  local_24c = DAT_0066aaf4;
  if (DAT_0066aaf4 == 1) {
    DAT_006663f8 = DAT_006663f8 ^ 2;
  }
  for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[arg_1]; local_2a8 = local_2a8 + 1) {
    *(uint32_t *)(&DAT_006826cc + local_2a8 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826cc + local_2a8 * 0x120 + arg_1 * 0x5b20) & 0xfffffffb;
  }
  Magic_ScanCards(0x15);
  local_2c4 = 0;
  local_29c = 0;
  local_248 = 0;
  local_8c = 0;
  local_254 = 0;
  slot_idx = 0xffffffff;
  _memset(local_46c,0,0x40);
  for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[arg_1]; local_2a8 = local_2a8 + 1) {
    local_204 = *(int *)(&DAT_006826c4 + local_2a8 * 0x120 + arg_1 * 0x5b20);
    if ((((local_204 != -1) && (((&DAT_004ff594)[local_204 * 0x34] & 2) != 0)) &&
        ((*(uint32_t *)(&DAT_006826cc + local_2a8 * 0x120 + arg_1 * 0x5b20) & 0x20012) == 2)) &&
       (val_2 = FUN_0048ad82(arg_1,local_2a8), val_2 != 0)) {
      if (((&DAT_006826cd)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0) {
        local_8c = local_8c | 1 << ((uint8_t)local_254 & 0x1f);
      }
      if ((((DAT_006663f8 & 2) == 0) ||
          (((&DAT_006826cd)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0)) ||
         (((&DAT_00692c88)[local_2a8 * 0xc + arg_1 * 0x3c0] & 0x40) == 0)) {
        val_2 = FUN_00479c07(arg_1,local_2a8);
        aiStack_e0[local_254] = val_2;
        local_46c[local_254] = local_2a8;
        local_254 = local_254 + 1;
        *(uint32_t *)(&DAT_006826cc + local_2a8 * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + local_2a8 * 0x120 + arg_1 * 0x5b20) | 4;
      }
      else {
        local_29c = local_29c + *(int *)(&DAT_00692c80 + local_2a8 * 0xc + arg_1 * 0x3c0);
        slot_idx = slot_idx & *(uint32_t *)(&DAT_00692c88 + local_2a8 * 0xc + arg_1 * 0x3c0);
        local_2c4 = local_2c4 | *(uint32_t *)(&DAT_00692c88 + local_2a8 * 0xc + arg_1 * 0x3c0) & 0x200;
        aiStack_244[local_248] = local_2a8;
        local_248 = local_248 + 1;
      }
    }
  }
  slot_idx = slot_idx | local_2c4;
  if (7 < local_254) {
    local_470 = 0;
    for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[DAT_00522908]; local_2a8 = local_2a8 + 1) {
      local_204 = *(int *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_2a8 * 0x120);
      if (((local_204 != -1) && (((&DAT_004ff594)[local_204 * 0x34] & 2) != 0)) &&
         (((&DAT_006826cc)[DAT_00522908 * 0x5b20 + local_2a8 * 0x120] & 0x12) != 0)) {
        local_470 = local_470 + 1;
      }
    }
    for (local_2a8 = 0; local_2a8 < 0x10; local_2a8 = local_2a8 + 1) {
      aiStack_178[local_2a8] = 0;
    }
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      aiStack_178[local_2a8] = *(int *)(&DAT_00692c80 + local_46c[local_2a8] * 0xc + arg_1 * 0x3c0);
    }
    while (local_470 != 0) {
      local_47c = 0;
      local_478 = 0;
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        if (local_47c < aiStack_178[local_2a8]) {
          local_47c = aiStack_178[local_2a8];
          local_478 = local_2a8;
        }
      }
      aiStack_178[local_478] = 0;
      local_470 = local_470 + -1;
    }
    local_474 = 0;
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      local_474 = local_474 + aiStack_178[local_2a8];
    }
    if ((int)(&DAT_00681ea8)[1 - arg_1] <= local_474) {
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
      }
      DAT_006826b0 = (1 << ((uint8_t)local_254 & 0x1f)) - 1;
      return DAT_006826b0;
    }
  }
  if (7 < local_254) {
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      for (local_2b8 = local_2a8; local_2b8 < local_254; local_2b8 = local_2b8 + 1) {
        if (aiStack_e0[local_2a8] < aiStack_e0[local_2b8]) {
          val_2 = aiStack_e0[local_2a8];
          aiStack_e0[local_2a8] = aiStack_e0[local_2b8];
          aiStack_e0[local_2b8] = val_2;
          val_2 = local_46c[local_2a8];
          local_46c[local_2a8] = local_46c[local_2b8];
          local_46c[local_2b8] = val_2;
          uval_3 = 1 << ((uint8_t)local_2a8 & 0x1f) & local_8c;
          uval_1 = local_8c & ~(1 << ((uint8_t)local_2a8 & 0x1f));
          local_8c = uval_1 & ~(1 << ((uint8_t)local_2b8 & 0x1f));
          if (uval_3 != 0) {
            local_8c = local_8c | 1 << ((uint8_t)local_2b8 & 0x1f);
          }
          if ((1 << ((uint8_t)local_2b8 & 0x1f) & uval_1) != 0) {
            local_8c = local_8c | 1 << ((uint8_t)local_2a8 & 0x1f);
          }
        }
      }
    }
    if (6 < local_254) {
      local_254 = 7;
    }
    for (local_2a8 = 7; local_2a8 < 0x10; local_2a8 = local_2a8 + 1) {
      *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
           *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) & 0xfffffffb;
    }
    _memset(local_450,0,0x24);
    local_8c = 0;
    local_254 = 0;
    for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[arg_1]; local_2a8 = local_2a8 + 1) {
      if (((&DAT_006826cc)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 4) != 0) {
        if (((&DAT_006826cd)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0) {
          local_8c = local_8c | 1 << ((uint8_t)local_254 & 0x1f);
        }
        local_46c[local_254] = local_2a8;
        local_254 = local_254 + 1;
      }
    }
  }
  FUN_00473a32(arg_1);
  FID_conflict__memcpy(local_88,&DAT_00522e70,0x40);
  FID_conflict__memcpy(local_48,&DAT_005226f0,0x40);
  FID_conflict__memcpy(local_308,&DAT_005224e0,0x40);
  FID_conflict__memcpy(local_298,&DAT_00522eb0,0x40);
  FID_conflict__memcpy(local_39c,&DAT_00522778,0x40);
  FID_conflict__memcpy(&DAT_005227c0,&DAT_00522980,0x40);
  FID_conflict__memcpy(&DAT_00522660,&DAT_00522910,0x40);
  FUN_00430120();
  DAT_0066aaf4 = 1;
  Magic_ScanCards(199);
  DAT_0066aaf4 = local_24c;
  for (local_2a8 = 0; local_2a8 < 8; local_2a8 = local_2a8 + 1) {
    *(int32_t *)(&DAT_0068ed10 + local_2a8 * 4 + DAT_00522908 * 0x20) =
         *(int32_t *)(&DAT_0068ef50 + local_2a8 * 4 + DAT_00522908 * 0x20);
  }
  local_e4 = 0;
  local_90 = 0;
  for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[DAT_00522908]; local_2a8 = local_2a8 + 1) {
    local_204 = *(int *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_2a8 * 0x120);
    if (((local_204 != -1) && (((&DAT_004ff594)[local_204 * 0x34] & 2) != 0)) &&
       (((&DAT_006826cc)[DAT_00522908 * 0x5b20 + local_2a8 * 0x120] & 2) != 0)) {
      aiStack_41c[local_90] = *(int *)(&DAT_00692c80 + local_2a8 * 0xc + DAT_00522908 * 0x3c0);
      aiStack_3dc[local_90] = *(int *)(&DAT_00692c84 + local_2a8 * 0xc + DAT_00522908 * 0x3c0);
      if (((&DAT_004ff5a8)[local_204 * 0x34] & 8) != 0) {
        val_2 = (**(code **)(&DAT_004ff5a0 + local_204 * 0x34))(DAT_00522908,local_2a8,0x39);
        aiStack_41c[local_90] = aiStack_41c[local_90] + val_2;
      }
      if (((&DAT_004ff5a8)[local_204 * 0x34] & 0x10) != 0) {
        val_2 = (**(code **)(&DAT_004ff5a0 + local_204 * 0x34))(DAT_00522908,local_2a8,0x3a);
        aiStack_3dc[local_90] = aiStack_3dc[local_90] + val_2;
      }
      if (local_e4 < aiStack_3dc[local_90]) {
        local_e4 = aiStack_3dc[local_90];
      }
      acStack_35c[local_2a8] = (char)local_90;
      local_90 = local_90 + 1;
    }
  }
  local_420 = -1;
  for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
    if (((local_420 == -1) && (local_88[local_2a8] < local_e4)) &&
       ((local_e4 <= local_88[local_2a8] + local_29c &&
        ((local_308[local_2a8] & slot_idx) == local_308[local_2a8])))) {
      local_88[local_2a8] = local_88[local_2a8] + local_29c;
      local_420 = local_46c[local_2a8];
    }
  }
  local_17c = 0;
  for (local_2b8 = 0; local_2b8 < (int)(&DAT_00666408)[arg_1]; local_2b8 = local_2b8 + 1) {
    if (((*(int *)(&DAT_006826c4 + local_2b8 * 0x120 + arg_1 * 0x5b20) != -1) &&
        (((&DAT_006826cc)[local_2b8 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) &&
       (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_2b8 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2)
        != 0)) {
      aiStack_178[local_17c] = *(int *)(&DAT_00692c80 + local_2b8 * 0xc + arg_1 * 0x3c0);
      aiStack_1fc[local_17c] = *(int *)(&DAT_00692c84 + local_2b8 * 0xc + arg_1 * 0x3c0);
      aiStack_e0[local_17c] = (aiStack_178[local_17c] + 1) * (aiStack_1fc[local_17c] + 1);
      for (local_2c0 = 0; (int)local_2c0 < DAT_0052297c; local_2c0 = local_2c0 + 1) {
        if ((&DAT_005225a0)[local_2c0] == local_2b8) {
          aiStack_e0[local_17c] = (&DAT_00522eb0)[local_2c0];
        }
      }
      acStack_134[local_2b8] = (char)local_17c;
      local_17c = local_17c + 1;
    }
  }
  FUN_00430367();
  local_258 = 9999;
  FUN_00431f41(&local_2b4,(uint32_t *)0x0);
  local_2c0 = 0;
  do {
    if (1 << ((uint8_t)local_254 & 0x1f) <= (int)local_2c0) {
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) & 0xfffffffb;
        if ((local_2a4 & 1 << ((uint8_t)local_2a8 & 0x1f)) != 0) {
          *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
               *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
          FUN_0048ad82(arg_1,local_46c[local_2a8]);
          if (((local_248 != 0) && (local_420 == -1)) &&
             ((local_308[local_2a8] & slot_idx) == local_308[local_2a8])) {
            local_420 = local_46c[local_2a8];
          }
        }
      }
      if (((local_248 == 0) || (local_420 == -1)) ||
         (((&DAT_006826cc)[local_420 * 0x120 + arg_1 * 0x5b20] & 4) == 0)) {
        if ((local_248 != 0) && (local_e4 == 0)) {
          for (local_2a8 = 0; local_2a8 < local_248; local_2a8 = local_2a8 + 1) {
            *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) =
                 *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) | 4;
            FUN_0048ad82(arg_1,aiStack_244[local_2a8]);
          }
          local_2a4 = 1;
        }
      }
      else {
        for (local_2a8 = 0; local_2a8 < local_248; local_2a8 = local_2a8 + 1) {
          (&DAT_006826de)[arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120] = (uint8_t)local_420;
          *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) =
               *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) | 4;
          FUN_0048ad82(arg_1,aiStack_244[local_2a8]);
        }
        (&DAT_006826de)[local_420 * 0x120 + arg_1 * 0x5b20] = (uint8_t)local_420;
      }
      DAT_005ef980 = local_2a0;
      DAT_006826b0 = local_2a4;
      return local_2a4;
    }
    local_2bc = 1;
    DAT_0052297c = 0;
    _DAT_005226e8 = 0;
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
           *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) & 0xfffffffb;
      local_2b0 = *(int *)(&DAT_004ff590 +
                          *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) *
                          0x34);
      if ((local_2c0 & 1 << ((uint8_t)local_2a8 & 0x1f)) == 0) {
        if ((local_2b0 == 0x19f) || (local_2b0 == 0x84)) {
          local_2bc = 0;
        }
        if ((local_8c & 1 << ((uint8_t)local_2a8 & 0x1f)) != 0) {
          local_2bc = 0;
        }
      }
      else {
        *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
        (&DAT_005225a0)[DAT_0052297c] = local_46c[local_2a8];
        (&DAT_00522e70)[DAT_0052297c] = local_88[local_2a8];
        (&DAT_005226f0)[DAT_0052297c] = local_48[local_2a8];
        (&DAT_005224e0)[DAT_0052297c] = local_308[local_2a8];
        (&DAT_00522eb0)[DAT_0052297c] = local_298[local_2a8];
        (&DAT_00522778)[DAT_0052297c] = local_39c[local_2a8];
        (&DAT_00522980)[DAT_0052297c] = *(int32_t *)(&DAT_005227c0 + local_2a8 * 4);
        (&DAT_00522910)[DAT_0052297c] = *(int32_t *)(&DAT_00522660 + local_2a8 * 4);
        if ((local_2b0 == 0x28) || (local_2b0 == 0x98)) {
          _DAT_005226e8 = _DAT_005226e8 | 1 << ((uint8_t)DAT_0052297c & 0x1f);
        }
        DAT_0052297c = DAT_0052297c + 1;
      }
    }
    if (local_2bc != 0) {
      DAT_00522a00 = 1;
      FUN_00476868(arg_1);
      FUN_00430120();
      DAT_0066aaf4 = 1;
      Magic_ScanCards(199);
      DAT_0066aaf4 = local_24c;
      local_2ac = 0;
      for (local_98 = 0; local_98 < 8; local_98 = local_98 + 1) {
        aiStack_1c4[local_98 * 2 + 3] = -1;
      }
      for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[DAT_00522908]; local_2a8 = local_2a8 + 1)
      {
        local_204 = *(int *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_2a8 * 0x120);
        if (((local_204 != -1) && (((&DAT_004ff594)[local_204 * 0x34] & 2) != 0)) &&
           ((*(uint32_t *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_2a8 * 0x120) & 0x402) != 0)) {
          local_90 = (int)acStack_35c[local_2a8];
          local_428 = aiStack_41c[acStack_35c[local_2a8]];
          local_2b8 = 0;
LAB_00476070:
          if (local_2b8 < 8) {
            if (local_428 <= aiStack_1c4[local_2b8 * 2 + 3]) goto LAB_0047606a;
            for (local_98 = 7; local_2b8 < local_98; local_98 = local_98 + -1) {
              aiStack_1c4[local_98 * 2 + 2] = aiStack_1c4[local_98 * 2];
              aiStack_1c4[local_98 * 2 + 3] = aiStack_1c4[local_98 * 2 + 1];
            }
            aiStack_1c4[local_2b8 * 2 + 2] = local_2a8;
            aiStack_1c4[local_2b8 * 2 + 3] = local_428;
          }
        }
      }
      local_98 = 0;
      while ((local_98 < 8 && (aiStack_1c4[local_98 * 2 + 3] != -1))) {
        local_2a8 = aiStack_1c4[local_98 * 2 + 2];
        local_200 = FUN_0048b81a(DAT_00522908,local_2a8,0x34,0xffffffff);
        local_90 = (int)acStack_35c[local_2a8];
        local_428 = aiStack_41c[local_90];
        local_424 = aiStack_3dc[local_90];
        local_2c8 = 0;
        local_42c = 0;
        local_17c = 0;
        local_9c = 0x7fff;
        for (local_2b8 = 0; local_2b8 < (int)(&DAT_00666408)[arg_1]; local_2b8 = local_2b8 + 1) {
          if (((*(int *)(&DAT_006826c4 + local_2b8 * 0x120 + arg_1 * 0x5b20) != -1) &&
              ((*(uint32_t *)(&DAT_006826cc + local_2b8 * 0x120 + arg_1 * 0x5b20) & 0x402) != 0)) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_2b8 * 0x120 + arg_1 * 0x5b20) * 0x34]
              & 2) != 0)) {
            local_17c = (int)acStack_134[local_2b8];
            local_a0 = aiStack_178[local_17c];
            local_138 = aiStack_1fc[local_17c];
            val_4 = local_2b8 * 0x120;
            val_2 = FUN_0048af80(arg_1,local_2b8);
            if (((*(uint32_t *)(&DAT_006826cc + val_4 + arg_1 * 0x5b20) & (-(uint32_t)(val_2 == 0) & 4) + 8)
                 == 0) &&
               (val_2 = FUN_0048b2c9(arg_1,local_2b8,DAT_00522908,local_2a8,local_200,local_2b4),
               uval_1 = local_42c, val_2 != 0)) {
              local_42c = local_42c | 1;
              if ((local_428 < local_138) || (local_424 <= local_a0)) {
                local_42c = uval_1 | 3;
                *(uint32_t *)(&DAT_006826cc + local_2b8 * 0x120 + arg_1 * 0x5b20) =
                     *(uint32_t *)(&DAT_006826cc + local_2b8 * 0x120 + arg_1 * 0x5b20) | 8;
                break;
              }
              if (aiStack_e0[local_17c] < local_9c) {
                local_9c = aiStack_e0[local_17c];
                local_2c8 = local_2b8;
              }
            }
          }
        }
        if ((local_42c & 2) == 0) {
          val_2 = *(int *)(&DAT_00666710 + arg_1 * 4) * local_428 * 0x18;
          val_2 = val_2 + (val_2 >> 0x1f & 3U);
          val_4 = FUN_0049aa14((&DAT_00681ea8)[arg_1] + 1,1,99);
          local_250 = (int)(CONCAT44(val_2 >> 0x1f,val_2 >> 2) / (longlong)val_4);
          if (local_42c != 0) {
            local_94 = (int)(*(int *)(&DAT_00666718 + arg_1 * 4) * local_9c +
                            (*(int *)(&DAT_00666718 + arg_1 * 4) * local_9c >> 0x1f & 7U)) >> 3;
            if (local_94 <= local_250) {
              DAT_00522ef0 = DAT_00522ef0 + local_94;
              *(uint32_t *)(&DAT_006826cc + local_2c8 * 0x120 + arg_1 * 0x5b20) =
                   *(uint32_t *)(&DAT_006826cc + local_2c8 * 0x120 + arg_1 * 0x5b20) | 8;
              goto LAB_0047613a;
            }
          }
          local_2ac = local_2ac + local_428;
          DAT_00522ef0 = DAT_00522ef0 + local_250;
        }
LAB_0047613a:
        local_98 = local_98 + 1;
      }
      FUN_00430367();
      if ((((int)(&DAT_00681ea8)[arg_1] <= local_2ac) && (0 < (int)(&DAT_00681ea8)[arg_1])) &&
         (0 < (int)(&DAT_00681ea8)[1 - arg_1])) {
        DAT_00522ef0 = DAT_00522ef0 + ((local_2ac - (&DAT_00681ea8)[arg_1]) + 2) * 0x80;
        DAT_00522ef0 = DAT_00522ef0 + DAT_00522880;
      }
      if (DAT_00522ef0 < local_258) {
        local_258 = DAT_00522ef0;
        local_2a4 = local_2c0;
      }
    }
    local_2c0 = local_2c0 + 1;
  } while( true );
LAB_0047606a:
  local_2b8 = local_2b8 + 1;
  goto LAB_00476070;
}



/*
 * Decompiled function: FUN_00476868
 * Entry Point: 00476868
 * Size: 317 bytes
 */


void FUN_00476868(int player_id)

{
  int32_t uval_1;
  int match_count;
  
  uval_1 = DAT_005ef980;
  DAT_005ef980 = 2;
  FUN_00473a32(arg_1);
  DAT_005226a0 = (uint32_t)(DAT_00676510 != arg_1);
  DAT_00522ef0 = 0xffffd8f1;
  for (match_count = 0; match_count < 0x10; match_count = match_count + 1) {
    *(int32_t *)(&DAT_00522620 + match_count * 4) = 0;
  }
  FUN_004769a5(arg_1,0);
  if ((DAT_0066aaf4 == 1) || (DAT_00666458 == DAT_00676510)) {
    for (match_count = 0; match_count < DAT_00522a04; match_count = match_count + 1) {
      (&DAT_006826de)[DAT_00522908 * 0x5b20 + (&DAT_00522f38)[match_count] * 0x120] =
           (&DAT_005226a8)[match_count * 4];
      if (DAT_0066aaf4 != 1) {
        FUN_00450eb8(DAT_00522908,(&DAT_00522f38)[match_count],5,2);
      }
    }
  }
  DAT_005ef980 = uval_1;
  return;
}



/*
 * Decompiled function: FUN_004769a5
 * Entry Point: 004769a5
 * Size: 388 bytes
 */


void FUN_004769a5(int32_t arg1,int arg2)

{
  int val_1;
  int match_count;
  
  if (arg2 == DAT_00522a04) {
    val_1 = FUN_00476b29();
    if (DAT_00522ef0 < val_1) {
      DAT_00522ef0 = val_1;
      FID_conflict__memcpy(&DAT_005226a8,&DAT_00522840,0x1c);
      DAT_00522880 = DAT_00522e68;
    }
  }
  else {
    val_1 = (&DAT_00522f38)[arg2] * 0x120 + DAT_00522908 * 0x5b20;
    if ((((&DAT_006826cd)[val_1] & 0x80) == 0) || ((&DAT_006826de)[val_1] == -1)) {
      *(int32_t *)(&DAT_00522840 + arg2 * 4) = 0xffffffff;
      FUN_004769a5(arg1,arg2 + 1);
    }
    for (match_count = 0; match_count < DAT_0052297c; match_count = match_count + 1) {
      if (((*(int *)(&DAT_00522a28 + match_count * 4) < DAT_00522770) &&
          (((&DAT_00522778)[match_count] & 1 << ((uint8_t)arg2 & 0x1f)) != 0)) &&
         ((((&DAT_006826cd)[val_1] & 0x80) == 0 ||
          ((int)(char)(&DAT_006826de)[val_1] == (&DAT_005225a0)[match_count])))) {
        *(int *)(&DAT_00522a28 + match_count * 4) = *(int *)(&DAT_00522a28 + match_count * 4) + 1;
        *(int32_t *)(&DAT_00522840 + arg2 * 4) = (&DAT_005225a0)[match_count];
        FUN_004769a5(arg1,arg2 + 1);
        *(int *)(&DAT_00522a28 + match_count * 4) = *(int *)(&DAT_00522a28 + match_count * 4) + -1;
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00476b29
 * Entry Point: 00476b29
 * Size: 2276 bytes
 */


int FUN_00476b29(void)

{
  int val_1;
  bool flag_2;
  int val_3;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  uint32_t local_c0;
  int local_bc;
  int local_b4;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_98;
  int local_94;
  int aiStack_90 [16];
  uint32_t local_50;
  int aiStack_4c [16];
  int match_count;
  int slot_idx;
  
  local_a0 = 0;
  DAT_0069340c = 0;
  match_count = 0;
  local_94 = (&DAT_00681ea8)[DAT_00522908];
  local_98 = 0;
  DAT_00522e68 = 0;
  if (DAT_00693400 != 0) {
    local_a0 = DAT_00693408;
  }
  local_a8 = 0;
  do {
    val_3 = local_94;
    if (DAT_0052297c <= local_a8) {
      match_count = match_count + DAT_0069340c;
      if (local_98 != 0) {
        while (local_a0 != 0) {
          local_e4 = 0;
          for (local_a8 = 0; local_a8 < local_98; local_a8 = local_a8 + 1) {
            if (local_e4 < aiStack_90[local_a8]) {
              local_e4 = aiStack_90[local_a8];
              local_e0 = local_a8;
            }
          }
          if (local_e4 == 0) {
            local_a0 = 0;
          }
          else {
            local_94 = local_94 + aiStack_90[local_e0];
            aiStack_90[local_e0] = 0;
            local_a0 = local_a0 + -1;
          }
        }
      }
      if (local_94 < 1) {
        match_count = match_count - (local_94 * -0x60 + 999);
      }
      else {
        val_3 = ((&DAT_00681ea8)[DAT_00522908] - local_94) *
                *(int *)(&DAT_00666710 + DAT_00522908 * 4) * 0x18;
        val_3 = val_3 + (val_3 >> 0x1f & 3U);
        match_count = match_count - (int)(CONCAT44(val_3 >> 0x1f,val_3 >> 2) / (longlong)local_94);
        if (DAT_005226a0 != 0) {
          DAT_00522e68 = (((&DAT_00681ea8)[DAT_00522908] - local_94) * 700) /
                         (int)(&DAT_00681ea8)[DAT_00522908];
          match_count = match_count - DAT_00522e68;
        }
      }
      return match_count;
    }
    val_1 = (&DAT_00522e70)[local_a8];
    local_dc = 0;
    local_d0 = -1;
    local_bc = -1;
    local_c8 = 0;
    flag_2 = false;
    local_50 = 0;
    local_cc = 0;
    DAT_0069340c = DAT_0069340c + (&DAT_00522980)[local_a8];
    for (local_d4 = 0; local_d4 < DAT_00522a04; local_d4 = local_d4 + 1) {
      if ((&DAT_005225a0)[local_a8] == *(int *)(&DAT_00522840 + local_d4 * 4)) {
        local_cc = local_cc + 1;
        DAT_0069340c = DAT_0069340c + (&DAT_00522910)[local_d4];
        local_dc = local_dc + (&DAT_00522ef8)[local_d4];
        local_d0 = local_d4;
        if ((*(uint8_t *)(&DAT_00522520 + local_d4) & 0x40) != 0) {
          flag_2 = true;
        }
        if ((*(uint32_t *)(&DAT_00522a08 + local_d4 * 4) & 1 << ((uint8_t)local_a8 & 0x1f)) != 0) {
          local_dc = local_dc + 99;
        }
        if ((*(uint32_t *)(&DAT_00522950 + local_a8 * 4) & 1 << ((uint8_t)local_d4 & 0x1f)) != 0) {
          local_50 = local_50 | 1 << ((uint8_t)local_d4 & 0x1f);
        }
        if ((((int)(&DAT_00522730)[local_d4] <= val_1) || (local_50 != 0)) &&
           ((*(uint8_t *)((int)&DAT_00522520 + local_d4 * 4 + 1) & 2) == 0)) {
          aiStack_4c[local_c8] = local_d4;
          local_c8 = local_c8 + 1;
        }
        if (local_bc < (int)(&DAT_00522560)[local_d4]) {
          slot_idx = local_d4;
          local_bc = (&DAT_00522560)[local_d4];
        }
      }
    }
    if (local_d0 == -1) {
      local_94 = local_94 - val_1;
    }
    else if (((*(uint8_t *)(&DAT_005224e0 + local_a8) & 0x80) != 0) && (local_dc < val_1)) {
      local_94 = local_94 - (val_1 - local_dc);
    }
    if (((DAT_00693400 != 0) && (local_94 < val_3)) &&
       ((DAT_00693400 &
        (int)(char)(&DAT_006826dd)[(1 - DAT_00522908) * 0x5b20 + (&DAT_005225a0)[local_a8] * 0x120])
        != 0)) {
      aiStack_90[local_98] = val_3 - local_94;
      local_98 = local_98 + 1;
    }
    if (((local_d0 != -1) && ((int)(&DAT_005226f0)[local_a8] <= local_dc)) &&
       (((*(uint8_t *)((int)&DAT_005224e0 + local_a8 * 4 + 1) & 3) == 0 || (local_c8 == 0)))) {
      match_count = match_count + ((int)(*(int *)(&DAT_00666710 + (3 - DAT_00522908) * 4) *
                                 (&DAT_00522eb0)[local_a8] +
                                (*(int *)(&DAT_00666710 + (3 - DAT_00522908) * 4) *
                                 (&DAT_00522eb0)[local_a8] >> 0x1f & 7U)) >> 3);
    }
    local_c4 = -1;
    for (local_c0 = 0; (int)local_c0 < 1 << ((uint8_t)local_c8 & 0x1f); local_c0 = local_c0 + 1) {
      if (local_50 == 0) {
        local_d8 = val_1;
        if (!flag_2) goto LAB_004770d1;
        if (local_dc - local_cc < val_1) {
          if (local_c0 == 0) {
            local_a4 = 0;
          }
          else {
            local_a4 = 9999;
          }
          for (local_b4 = 0; local_b4 < local_c8; local_b4 = local_b4 + 1) {
            if ((local_c0 & 1 << ((uint8_t)local_b4 & 0x1f)) != 0) {
              val_3 = aiStack_4c[local_b4];
              if ((int)(&DAT_00522f80)[val_3] < local_a4) {
                local_a4 = (&DAT_00522f80)[val_3];
              }
              if (val_1 < (int)(&DAT_00522730)[val_3]) {
                local_a4 = 0;
              }
              else if ((((&DAT_00522520)[val_3] & 0x1ff800) != 0) &&
                      (((int)(char)(&DAT_006826dd)
                                   [(1 - DAT_00522908) * 0x5b20 + (&DAT_005225a0)[local_a8] * 0x120]
                        << 10 & (&DAT_00522520)[val_3] & 0x1ff800U) != 0)) {
                local_a4 = 0;
              }
            }
          }
        }
        else {
          local_a4 = 0;
        }
      }
      else {
        local_d8 = 99;
LAB_004770d1:
        local_a4 = 0;
        for (local_b4 = 0; local_b4 < local_c8; local_b4 = local_b4 + 1) {
          if ((local_c0 & 1 << ((uint8_t)local_b4 & 0x1f)) != 0) {
            val_3 = aiStack_4c[local_b4];
            if ((((*(uint8_t *)((int)&DAT_00522520 + val_3 * 4 + 1) & 1) == 0) ||
                ((int)(&DAT_00522ef8)[val_3] < (int)(&DAT_005226f0)[local_a8])) &&
               (((int)(char)(&DAT_006826dd)
                            [(1 - DAT_00522908) * 0x5b20 + (&DAT_005225a0)[local_a8] * 0x120] << 10
                 & (&DAT_00522520)[val_3] & 0x1ff800U) == 0)) {
              local_a4 = local_a4 + (&DAT_00522f80)[val_3];
            }
            local_d8 = local_d8 - (&DAT_00522730)[val_3];
            if (local_d8 < 0) break;
          }
        }
      }
      if ((-1 < local_d8) && (local_c4 < local_a4)) {
        local_c4 = local_a4;
        DAT_005224c0 = local_c0;
      }
    }
    if (local_c8 == 0) {
      *(int *)(&DAT_00522620 + local_a8 * 4) = -slot_idx;
    }
    else {
      *(uint32_t *)(&DAT_00522620 + local_a8 * 4) = DAT_005224c0;
    }
    match_count = match_count - local_c4;
    local_a8 = local_a8 + 1;
  } while( true );
}



/*
 * Decompiled function: Ai_EvalAttackCandidate_004c864d
 * Entry Point: 0047740d
 * Size: 6381 bytes
 */


void Ai_EvalAttackCandidate_004c864d(uint32_t spell_id)

{
  int32_t uval_1;
  int val_2;
  char *char_ptr_3;
  int local_e4 [9];
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac [16];
  uint32_t local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_54;
  int local_50 [16];
  int card_idx;
  int match_count;
  int slot_idx;
  
  local_6c = 1 - spell_id;
  local_bc = 0;
  local_64 = 0;
  do {
    if (1 < local_64) {
      return;
    }
    if (local_64 == 0) {
      DAT_0068f2c4 = 0x19;
    }
    else {
      DAT_0068f2c4 = 0x1a;
    }
    FUN_0048cfda(spell_id,DAT_0068f2c4);
    for (local_60 = 0; local_60 < (int)(&DAT_00666408)[spell_id]; local_60 = local_60 + 1) {
      if (((&DAT_006826de)[local_60 * 0x120 + spell_id * 0x5b20] == -1) ||
         ((char)(&DAT_006826de)[local_60 * 0x120 + spell_id * 0x5b20] == local_60)) {
        if ((local_bc == 0) && (DAT_0066aaf4 != 1)) {
          FUN_0048d00c(0x14);
          local_bc = 1;
        }
        local_54 = 0;
        card_idx = 0;
        DAT_0052297c = 0;
        local_e4[6] = 0;
        for (local_e4[7] = 0; local_e4[7] < (int)(&DAT_00666408)[spell_id];
            local_e4[7] = local_e4[7] + 1) {
          if ((((local_e4[7] == local_60) ||
               ((char)(&DAT_006826de)[spell_id * 0x5b20 + local_e4[7] * 0x120] == local_60)) &&
              (*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + local_e4[7] * 0x120) != -1)) &&
             (((uint8_t)*(int32_t *)(&DAT_006826cc + spell_id * 0x5b20 + local_e4[7] * 0x120) & 6)
              == 6)) {
            (&DAT_005225a0)[DAT_0052297c] = local_e4[7];
            uval_1 = FUN_0048b81a(spell_id,local_e4[7],0x33,0xffffffff);
            (&DAT_005226f0)[DAT_0052297c] = uval_1;
            uval_1 = FUN_0048b81a(spell_id,local_e4[7],0x34,0xffffffff);
            (&DAT_005224e0)[DAT_0052297c] = uval_1;
            local_b4 = 0;
            (&DAT_00522e70)[DAT_0052297c] = 0;
            val_2 = FUN_00478cfa(local_64,(&DAT_005224e0)[DAT_0052297c]);
            if (val_2 != 0) {
              local_b4 = FUN_0048b81a(spell_id,local_e4[7],0x32,0xffffffff);
              if (local_b4 < 0) {
                local_b4 = 0;
              }
              (&DAT_00522e70)[DAT_0052297c] = local_b4;
              card_idx = card_idx + local_b4;
              if ((*(uint8_t *)(&DAT_005224e0 + DAT_0052297c) & 0x80) != 0) {
                local_54 = local_54 + local_b4;
              }
            }
            DAT_0052297c = DAT_0052297c + 1;
            if (DAT_0052297c == 0x10) break;
          }
        }
        if (1 < DAT_0052297c) {
          local_e4[6] = 1;
        }
        local_5c = 0;
        DAT_00522a04 = 0;
        local_b0 = 0;
        for (local_e4[7] = 0; local_e4[7] < (int)(&DAT_00666408)[local_6c];
            local_e4[7] = local_e4[7] + 1) {
          if (((*(int *)(&DAT_006826c4 + local_e4[7] * 0x120 + local_6c * 0x5b20) != -1) &&
              ((char)(&DAT_006826de)[local_e4[7] * 0x120 + local_6c * 0x5b20] == local_60)) &&
             (((&DAT_006826cc)[local_e4[7] * 0x120 + local_6c * 0x5b20] & 2) != 0)) {
            (&DAT_00522f38)[DAT_00522a04] = local_e4[7];
            val_2 = FUN_0048b81a(local_6c,local_e4[7],0x33,local_60);
            (&DAT_00522730)[DAT_00522a04] =
                 val_2 - *(short *)(&DAT_006826d0 + local_e4[7] * 0x120 + local_6c * 0x5b20);
            uval_1 = FUN_0048b81a(local_6c,local_e4[7],0x34,0xffffffff);
            (&DAT_00522520)[DAT_00522a04] = uval_1;
            local_e4[4] = 0;
            (&DAT_00522ef8)[DAT_00522a04] = 0;
            if ((((&DAT_006826cc)[local_e4[7] * 0x120 + local_6c * 0x5b20] & 0x10) == 0) &&
               (val_2 = FUN_00478cfa(local_64,(&DAT_00522520)[DAT_00522a04]), val_2 != 0)) {
              local_e4[4] = FUN_0048b81a(local_6c,local_e4[7],0x32,local_60);
              if (local_e4[4] < 0) {
                local_e4[4] = 0;
              }
              (&DAT_00522ef8)[DAT_00522a04] = local_e4[4];
              local_5c = local_5c + local_e4[4];
            }
            if ((*(uint8_t *)(&DAT_00522520 + DAT_00522a04) & 0x40) != 0) {
              local_b0 = 1;
            }
            DAT_00522a04 = DAT_00522a04 + 1;
            if (DAT_00522a04 == 0x10) break;
          }
        }
        if (DAT_00522a04 != 0) {
          for (local_b8 = 0; local_b8 < DAT_0052297c; local_b8 = local_b8 + 1) {
            *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + (&DAT_005225a0)[local_b8] * 0x120) =
                 *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + (&DAT_005225a0)[local_b8] * 0x120) |
                 0x200;
          }
        }
        if ((DAT_0052297c != 0) || (DAT_00522a04 != 0)) {
          if (DAT_00522a04 < 2) {
            if (DAT_00522a04 == 1) {
              for (local_b8 = 0; local_b8 < DAT_0052297c; local_b8 = local_b8 + 1) {
                val_2 = FUN_00478cfa(local_64,(&DAT_005224e0)[local_b8]);
                if ((val_2 != 0) &&
                   (local_50[0] = FUN_004af950(local_6c,DAT_00522f38,(&DAT_00522e70)[local_b8],
                                               spell_id,(&DAT_005225a0)[local_b8]),
                   match_count = local_50[0], local_50[0] != -1)) {
                  *(uint32_t *)(&DAT_006826f8 + local_50[0] * 0x120 + spell_id * 0x5b20) =
                       *(uint32_t *)(&DAT_006826f8 + local_50[0] * 0x120 + spell_id * 0x5b20) | 0x40000;
                  if ((*(uint8_t *)(&DAT_005224e0 + local_b8) & 0x80) != 0) {
                    *(uint32_t *)(&DAT_006826f8 + local_50[0] * 0x120 + spell_id * 0x5b20) =
                         *(uint32_t *)(&DAT_006826f8 + local_50[0] * 0x120 + spell_id * 0x5b20) |
                         0x80000;
                  }
                  if (local_64 == 0) {
                    *(uint32_t *)(&DAT_006826f8 + local_50[0] * 0x120 + spell_id * 0x5b20) =
                         *(uint32_t *)(&DAT_006826f8 + local_50[0] * 0x120 + spell_id * 0x5b20) |
                         0x100000;
                  }
                }
              }
            }
            else {
              for (local_b8 = 0; local_b8 < DAT_0052297c; local_b8 = local_b8 + 1) {
                val_2 = FUN_00478cfa(local_64,(&DAT_005224e0)[local_b8]);
                if ((val_2 != 0) &&
                   ((((&DAT_006826cd)[spell_id * 0x5b20 + (&DAT_005225a0)[local_b8] * 0x120] & 2) ==
                     0 || ((*(uint8_t *)(&DAT_005224e0 + local_b8) & 0x80) != 0)))) {
                  Mem_AllocOrFree_004afd1c
                            (local_6c,(&DAT_00522e70)[local_b8],spell_id,(&DAT_005225a0)[local_b8]);
                }
              }
            }
          }
          else if (((DAT_0066aaf4 == 1) || ((local_b0 == 0 && (DAT_00676510 != spell_id)))) ||
                  ((local_b0 != 0 && (DAT_00676510 != local_6c)))) {
            local_e4[2] = 0x7fffffff;
            local_e4[3] = 0xffff8001;
            FUN_00478e3b();
            for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
              local_50[local_68] = -1;
            }
            FUN_00478e99(spell_id,0,local_b0,(int)local_50,local_64,0,local_e4 + 2,local_e4 + 3);
            FUN_00478e99(spell_id,0,local_b0,(int)local_50,local_64,1,local_e4 + 2,local_e4 + 3);
          }
          else {
            for (local_b8 = 0; local_b8 < DAT_0052297c; local_b8 = local_b8 + 1) {
              for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
                local_50[local_68] = -1;
              }
              local_b4 = (&DAT_00522e70)[local_b8];
              while (local_b4 != 0) {
                if (DAT_00663e24 == 2) {
                  _sprintf(&DAT_005f6810,s_Assign__d__sdamage_004f993c,local_b4,
                           s_trample_004f992c +
                           (((*(uint8_t *)(&DAT_005224e0 + local_b8) & 0x80) != 0) - 1 & 0xc));
                }
                else {
                  char_ptr_3 = s_trample_004f98ec +
                           (((*(uint8_t *)(&DAT_005224e0 + local_b8) & 0x80) != 0) - 1 & 0xc);
                  val_2 = local_b4;
                  uval_1 = Ai_Subsystem_004b8e4d(spell_id,(&DAT_005225a0)[local_b8]);
                  _sprintf(&DAT_005f6810,s__s__Assign__sdamage_to_blockers__004f98fc,uval_1,char_ptr_3,
                           val_2);
                }
                FUN_00479b25(spell_id,(&DAT_005225a0)[local_b8],1);
                slot_idx = 0;
                while (slot_idx == 0) {
                  Action_ValidateTarget_0041e2a2
                            (DAT_00676510,local_6c,local_6c,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,
                             0xffffffff,0,0x10,0,&DAT_005f6810,0,local_e4 + 8);
                  for (local_68 = 0; local_68 < DAT_00522a04; local_68 = local_68 + 1) {
                    if ((&DAT_00522f38)[local_68] == local_c0) {
                      slot_idx = 1;
                    }
                  }
                  if ((slot_idx == 0) && (DAT_0066aaf4 != 1)) {
                    Mem_AllocOrFree_00450eed(s_Illegal_target__wrong_attack_gro_004f9950);
                    Sleep(0x5dc);
                    Mem_AllocOrFree_00450eed(&DAT_004f9974);
                  }
                  if (((slot_idx == 1) && (val_2 = FUN_00479f9f(local_e4[8],local_c0), val_2 != 0))
                     && (slot_idx = 0, DAT_0066aaf4 != 1)) {
                    Mem_AllocOrFree_00450eed(s_Illegal_target__gasseous_form__004f9978);
                    Sleep(0x5dc);
                    Mem_AllocOrFree_00450eed(&DAT_004f9998);
                  }
                }
                DAT_005f6810 = 0;
                FUN_00479b25(spell_id,(&DAT_005225a0)[local_b8],0);
                if (((local_e4[8] != -1) && (local_c0 != -1)) && (local_c0 != -2)) {
                  for (local_68 = 0; local_68 < DAT_00522a04; local_68 = local_68 + 1) {
                    if ((&DAT_00522f38)[local_68] == local_c0) {
                      if (DAT_0066643c == 0) {
                        local_e4[5] = 1;
                      }
                      else {
                        local_e4[5] = local_b4;
                      }
                      if (local_50[local_68] == -1) {
                        match_count = FUN_004af950(local_e4[8],local_c0,local_e4[5],spell_id,
                                               (&DAT_005225a0)[local_b8]);
                        local_50[local_68] = match_count;
                        if (match_count != -1) {
                          *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + spell_id * 0x5b20) =
                               *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + spell_id * 0x5b20) |
                               0x40000;
                          if ((*(uint8_t *)(&DAT_005224e0 + local_b8) & 0x80) != 0) {
                            *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + spell_id * 0x5b20) =
                                 *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + spell_id * 0x5b20) |
                                 0x80000;
                          }
                          if (local_64 == 0) {
                            *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + spell_id * 0x5b20) =
                                 *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + spell_id * 0x5b20) |
                                 0x100000;
                          }
                        }
                      }
                      else {
                        *(int *)(&DAT_006826e4 + spell_id * 0x5b20 + local_50[local_68] * 0x120) =
                             *(int *)(&DAT_006826e4 + spell_id * 0x5b20 + local_50[local_68] * 0x120
                                     ) + local_e4[5];
                      }
                      local_b4 = local_b4 - local_e4[5];
                    }
                  }
                }
              }
            }
          }
          if (DAT_0052297c < 2) {
            if (DAT_0052297c == 1) {
              for (local_b8 = 0; local_b8 < DAT_00522a04; local_b8 = local_b8 + 1) {
                val_2 = FUN_00478cfa(local_64,(&DAT_00522520)[local_b8]);
                if (((val_2 != 0) &&
                    (local_ac[0] = FUN_004af950(spell_id,DAT_005225a0,(&DAT_00522ef8)[local_b8],
                                                local_6c,(&DAT_00522f38)[local_b8]),
                    match_count = local_ac[0], local_ac[0] != -1)) &&
                   (*(uint32_t *)(&DAT_006826f8 + local_ac[0] * 0x120 + local_6c * 0x5b20) =
                         *(uint32_t *)(&DAT_006826f8 + local_ac[0] * 0x120 + local_6c * 0x5b20) |
                         0x40000, local_64 == 0)) {
                  *(uint32_t *)(&DAT_006826f8 + local_ac[0] * 0x120 + local_6c * 0x5b20) =
                       *(uint32_t *)(&DAT_006826f8 + local_ac[0] * 0x120 + local_6c * 0x5b20) | 0x100000
                  ;
                }
              }
            }
          }
          else if (((DAT_0066aaf4 == 1) || ((local_e4[6] == 0 && (DAT_00676510 != local_6c)))) ||
                  ((local_e4[6] != 0 && (DAT_00676510 != spell_id)))) {
            local_e4[0] = 0x7fffffff;
            local_e4[1] = 0xffffffff;
            FUN_00478e3b();
            for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
              local_ac[local_68] = -1;
            }
            FUN_004794d4(spell_id,0,local_e4[6],(int)local_ac,local_64,0,local_e4,local_e4 + 1);
            FUN_004794d4(spell_id,0,local_e4[6],(int)local_ac,local_64,1,local_e4,local_e4 + 1);
          }
          else {
            for (local_b8 = 0; local_b8 < DAT_00522a04; local_b8 = local_b8 + 1) {
              for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
                local_ac[local_68] = -1;
              }
              local_e4[4] = (&DAT_00522ef8)[local_b8];
              while (local_e4[4] != 0) {
                if (DAT_00663e24 == 2) {
                  _sprintf(&DAT_005f6810,s_Assign__d_damage_004f99cc,local_e4[4]);
                }
                else {
                  val_2 = local_e4[4];
                  uval_1 = Ai_Subsystem_004b8e4d(local_6c,(&DAT_00522f38)[local_b8]);
                  _sprintf(&DAT_005f6810,s__s__Assign_damage_to_attackers____004f999c,uval_1,val_2);
                }
                FUN_00479b85(local_6c,(&DAT_00522f38)[local_b8],1);
                slot_idx = 0;
                while (slot_idx == 0) {
                  Action_ValidateTarget_0041e2a2
                            (DAT_00676510,spell_id,spell_id,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,
                             0xffffffff,0,2,0,&DAT_005f6810,0,local_e4 + 8);
                  for (local_68 = 0; local_68 < DAT_0052297c; local_68 = local_68 + 1) {
                    if ((&DAT_005225a0)[local_68] == local_c0) {
                      slot_idx = 1;
                    }
                  }
                  if ((slot_idx == 0) && (DAT_0066aaf4 != 1)) {
                    Mem_AllocOrFree_00450eed(s_Illegal_target__wrong_attack_gro_004f99e0);
                    Sleep(0x5dc);
                    Mem_AllocOrFree_00450eed(&DAT_004f9a04);
                  }
                  if (((slot_idx == 1) && (val_2 = FUN_00479f9f(local_e4[8],local_c0), val_2 != 0))
                     && (slot_idx = 0, DAT_0066aaf4 != 1)) {
                    Mem_AllocOrFree_00450eed(s_Illegal_target__gasseous_form__004f9a08);
                    Sleep(0x5dc);
                    Mem_AllocOrFree_00450eed(&DAT_004f9a28);
                  }
                }
                DAT_005f6810 = 0;
                FUN_00479b85(local_6c,(&DAT_00522f38)[local_b8],0);
                if (((local_e4[8] != -1) && (local_c0 != -1)) && (local_c0 != -2)) {
                  for (local_68 = 0; local_68 < DAT_0052297c; local_68 = local_68 + 1) {
                    if ((&DAT_005225a0)[local_68] == local_c0) {
                      if (DAT_0066643c == 0) {
                        local_e4[5] = 1;
                      }
                      else {
                        local_e4[5] = local_e4[4];
                      }
                      if (local_ac[local_68] == -1) {
                        match_count = FUN_004af950(spell_id,local_c0,local_e4[5],local_6c,
                                               (&DAT_00522f38)[local_b8]);
                        local_ac[local_68] = match_count;
                        if ((match_count != -1) &&
                           (*(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + local_6c * 0x5b20) =
                                 *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + local_6c * 0x5b20) |
                                 0x40000, local_64 == 0)) {
                          *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + local_6c * 0x5b20) =
                               *(uint32_t *)(&DAT_006826f8 + match_count * 0x120 + local_6c * 0x5b20) |
                               0x100000;
                        }
                      }
                      else {
                        *(int *)(&DAT_006826e4 + local_6c * 0x5b20 + local_ac[local_68] * 0x120) =
                             *(int *)(&DAT_006826e4 + local_6c * 0x5b20 + local_ac[local_68] * 0x120
                                     ) + local_e4[5];
                      }
                      local_e4[4] = local_e4[4] - local_e4[5];
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    DAT_00522a04 = 0;
    for (local_e4[7] = 0; local_e4[7] < (int)(&DAT_00666408)[local_6c];
        local_e4[7] = local_e4[7] + 1) {
      if ((*(int *)(&DAT_006826c4 + local_e4[7] * 0x120 + local_6c * 0x5b20) != -1) &&
         ((&DAT_006826de)[local_e4[7] * 0x120 + local_6c * 0x5b20] != -1)) {
        (&DAT_00522f38)[DAT_00522a04] = local_e4[7];
        val_2 = FUN_0048b81a(local_6c,local_e4[7],0x33,local_60);
        (&DAT_00522730)[DAT_00522a04] =
             val_2 - *(short *)(&DAT_006826d0 + local_e4[7] * 0x120 + local_6c * 0x5b20);
        val_2 = FUN_00479f9f(local_6c,local_e4[7]);
        if (val_2 != 0) {
          (&DAT_00522730)[DAT_00522a04] = 0;
        }
        DAT_00522a04 = DAT_00522a04 + 1;
        if (DAT_00522a04 == 0x10) break;
      }
    }
    DAT_00690314 = 0;
    DAT_00666424 = 0;
    if (DAT_0066aaf4 != 1) {
      DAT_0068eee4 = 0;
    }
    Rules_ProcessDamagePrevention(spell_id);
    if (DAT_00690314 == 0) {
      FUN_0042abcf(DAT_0068f2c4);
      DAT_00690314 = 1;
    }
    for (local_68 = 0; local_68 < DAT_00522a04; local_68 = local_68 + 1) {
      local_e4[7] = (&DAT_00522f38)[local_68];
      local_e4[4] = (&DAT_00522730)[local_68];
      for (local_60 = 0; local_60 < (int)(&DAT_00666408)[spell_id]; local_60 = local_60 + 1) {
        if (((((*(int *)(&DAT_006826c0 + local_60 * 0x120 + spell_id * 0x5b20) == DAT_0068f104) &&
              ((int)(char)(&DAT_006826d2)[local_60 * 0x120 + spell_id * 0x5b20] == local_6c)) &&
             (*(int *)(&DAT_006826e8 + local_60 * 0x120 + spell_id * 0x5b20) == local_e4[7])) &&
            (((local_64 == 0 &&
              (((&DAT_006826fa)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) ||
             ((local_64 == 1 &&
              (((&DAT_006826fa)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) == 0)))))) &&
           ((((&DAT_006826fa)[local_60 * 0x120 + spell_id * 0x5b20] & 4) != 0 &&
            (((&DAT_006826fa)[local_60 * 0x120 + spell_id * 0x5b20] & 8) == 0)))) {
          local_e4[4] = local_e4[4] - *(int *)(&DAT_006826e4 + local_60 * 0x120 + spell_id * 0x5b20)
          ;
        }
      }
      for (local_60 = 0; local_60 < (int)(&DAT_00666408)[spell_id]; local_60 = local_60 + 1) {
        if ((((*(int *)(&DAT_006826c0 + local_60 * 0x120 + spell_id * 0x5b20) == DAT_0068f104) &&
             ((int)(char)(&DAT_006826d2)[local_60 * 0x120 + spell_id * 0x5b20] == local_6c)) &&
            (*(int *)(&DAT_006826e8 + local_60 * 0x120 + spell_id * 0x5b20) == local_e4[7])) &&
           ((((local_64 == 0 &&
              (((&DAT_006826fa)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) ||
             ((local_64 == 1 &&
              (((&DAT_006826fa)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) == 0)))) &&
            ((((&DAT_006826fa)[local_60 * 0x120 + spell_id * 0x5b20] & 8) != 0 &&
             (local_e4[4] -
              ((int)(char)(&DAT_006826df)[local_60 * 0x120 + spell_id * 0x5b20] +
              *(int *)(&DAT_006826e4 + local_60 * 0x120 + spell_id * 0x5b20)) < 0)))))) {
          val_2 = -(local_e4[4] -
                   ((int)(char)(&DAT_006826df)[local_60 * 0x120 + spell_id * 0x5b20] +
                   *(int *)(&DAT_006826e4 + local_60 * 0x120 + spell_id * 0x5b20)));
          if ((int)(char)(&DAT_006826df)[local_60 * 0x120 + spell_id * 0x5b20] +
              *(int *)(&DAT_006826e4 + local_60 * 0x120 + spell_id * 0x5b20) <= val_2) {
            val_2 = (int)(char)(&DAT_006826df)[local_60 * 0x120 + spell_id * 0x5b20] +
                    *(int *)(&DAT_006826e4 + local_60 * 0x120 + spell_id * 0x5b20);
          }
          Mem_AllocOrFree_004afd1c
                    (local_6c,val_2,(int)(char)(&DAT_006826d3)[local_60 * 0x120 + spell_id * 0x5b20]
                     ,*(int *)(&DAT_006826ec + local_60 * 0x120 + spell_id * 0x5b20));
          local_e4[4] = local_e4[4] -
                        ((int)(char)(&DAT_006826df)[local_60 * 0x120 + spell_id * 0x5b20] +
                        *(int *)(&DAT_006826e4 + local_60 * 0x120 + spell_id * 0x5b20));
        }
      }
    }
    Rules_SendCardsToGraveyard();
    Rules_ProcessDamagePrevention(spell_id);
    DAT_00666424 = 0;
    DAT_0068eee4 = 0;
    if (DAT_00690314 == 0) {
      FUN_0042abcf(DAT_0068f2c4);
    }
    local_64 = local_64 + 1;
  } while( true );
}



/*
 * Decompiled function: FUN_00478cfa
 * Entry Point: 00478cfa
 * Size: 78 bytes
 */


int32_t FUN_00478cfa(int arg1,uint32_t arg2)

{
  int32_t uval_1;
  
  if ((arg1 == 0) && ((arg2 & 0x100) != 0)) {
    uval_1 = 1;
  }
  else if ((arg1 == 0) || ((arg2 & 0x100) != 0)) {
    uval_1 = 0;
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00478d48
 * Entry Point: 00478d48
 * Size: 243 bytes
 */


int32_t FUN_00478d48(int player_id)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < DAT_00522a04; slot_idx = slot_idx + 1) {
    *(uint32_t *)(&DAT_006826cc + (1 - arg_1) * 0x5b20 + (&DAT_00522f38)[slot_idx] * 0x120) =
         *(uint32_t *)(&DAT_006826cc + (1 - arg_1) * 0x5b20 + (&DAT_00522f38)[slot_idx] * 0x120) &
         0xfffffff7;
  }
  for (slot_idx = 0; slot_idx < (int)(&DAT_00666408)[arg_1]; slot_idx = slot_idx + 1) {
    if (((&DAT_006826cc)[slot_idx * 0x120 + arg_1 * 0x5b20] & 4) != 0) {
      *(uint32_t *)(&DAT_006826cc + slot_idx * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + slot_idx * 0x120 + arg_1 * 0x5b20) & 0xfffffffb;
      *(uint32_t *)(&DAT_006826cc + slot_idx * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + slot_idx * 0x120 + arg_1 * 0x5b20) | 0x40;
    }
  }
  return 1;
}



/*
 * Decompiled function: FUN_00478e3b
 * Entry Point: 00478e3b
 * Size: 94 bytes
 */


void FUN_00478e3b(void)

{
  int match_count;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0x10; slot_idx = slot_idx + 1) {
    for (match_count = 0; match_count < 0x10; match_count = match_count + 1) {
      *(int32_t *)(&DAT_00522a68 + match_count * 4 + slot_idx * 0x40) = 0;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00478e99
 * Entry Point: 00478e99
 * Size: 1595 bytes
 */


/* WARNING: Removing unreachable block (ram,0x0047943e) */
/* WARNING: Removing unreachable block (ram,0x00479448) */

void FUN_00478e99(int player_id,int card_slot,int event_type,int arg_4,int arg_5,int arg_6,int *arg_7,int *arg_8)

{
  int val_1;
  int val_2;
  int val_3;
  int local_40;
  int local_3c;
  int local_38;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int color_idx;
  int card_idx;
  int match_count;
  
  val_1 = 1 - arg_1;
  if (arg_2 < DAT_0052297c) {
    val_2 = (&DAT_00522e70)[arg_2];
    val_3 = val_2 + 1;
    local_3c = 1;
    for (local_28 = 0; local_28 < DAT_00522a04; local_28 = local_28 + 1) {
      local_3c = local_3c * val_3;
    }
    if (arg_6 == 0) {
      if ((DAT_005f2f50 + 1) * 0x100 < local_3c) {
        local_2c = 0;
        local_38 = val_2;
        local_28 = DAT_00522a04;
        while (local_28 = local_28 + -1, 0 < local_28) {
          if (((int)(&DAT_00522730)[local_28] < local_38) &&
             ((*(uint8_t *)((int)&DAT_00522520 + local_28 * 4 + 1) & 2) == 0)) {
            local_2c = local_2c + (&DAT_00522730)[local_28];
            *(int32_t *)(&DAT_00522a68 + local_28 * 4 + arg_2 * 0x40) = (&DAT_00522730)[local_28]
            ;
            local_38 = local_38 - (&DAT_00522730)[local_28];
          }
          local_2c = local_2c * val_3;
        }
        if (local_38 != 0) {
          local_2c = local_2c + local_38;
        }
        *(int *)(&DAT_005228c8 + arg_2 * 4) = local_2c;
        FUN_00478e99(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,0,arg_7,arg_8);
      }
      else {
        if (4999999 < local_3c) {
          local_3c = 5000000;
        }
        for (local_28 = 0; local_28 < local_3c; local_28 = local_28 + 1) {
          local_2c = local_28;
          _memset(&DAT_00522a68 + arg_2 * 0x40,0,0x40);
          local_30 = 0;
          for (local_38 = val_2; (local_30 < DAT_00522a04 && (0 < local_38));
              local_38 = local_38 - val_1) {
            val_1 = local_2c % val_3;
            *(int *)(&DAT_00522a68 + local_30 * 4 + arg_2 * 0x40) = val_1;
            local_2c = local_2c / val_3;
            local_30 = local_30 + 1;
          }
          if (local_38 == 0) {
            *(int *)(&DAT_005228c8 + arg_2 * 4) = local_28;
            FUN_00478e99(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,0,arg_7,arg_8);
          }
        }
      }
    }
    else {
      local_2c = *(int *)(&DAT_00522800 + arg_2 * 4);
      for (local_30 = 0; local_30 < DAT_00522a04; local_30 = local_30 + 1) {
        local_24 = local_2c % val_3;
        val_2 = FUN_00479f9f(val_1,(&DAT_00522f38)[local_30]);
        if (val_2 != 0) {
          local_24 = 0;
        }
        if (local_24 != 0) {
          val_2 = FUN_004af950(val_1,(&DAT_00522f38)[local_30],local_24,arg_1,(&DAT_005225a0)[arg_2]
                              );
          *(int *)(arg_4 + local_30 * 4) = val_2;
          if (val_2 != -1) {
            *(uint32_t *)(&DAT_006826f8 + val_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint32_t *)(&DAT_006826f8 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x40000;
            if ((*(uint8_t *)(&DAT_005224e0 + arg_2) & 0x80) != 0) {
              *(uint32_t *)(&DAT_006826f8 + val_2 * 0x120 + arg_1 * 0x5b20) =
                   *(uint32_t *)(&DAT_006826f8 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
            }
            if (arg_5 == 0) {
              *(uint32_t *)(&DAT_006826f8 + val_2 * 0x120 + arg_1 * 0x5b20) =
                   *(uint32_t *)(&DAT_006826f8 + val_2 * 0x120 + arg_1 * 0x5b20) | 0x100000;
            }
          }
        }
        *(int *)(&DAT_00522a68 + local_30 * 4 + arg_2 * 0x40) = local_24;
        local_2c = local_2c / val_3;
      }
      FUN_00478e99(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,arg_6,arg_7,arg_8);
    }
  }
  else {
    match_count = 0;
    card_idx = (&DAT_00681ea8)[val_1];
    for (local_28 = 0; local_28 < DAT_00522a04; local_28 = local_28 + 1) {
      color_idx = 0;
      local_40 = 0;
      for (local_30 = 0; local_30 < DAT_0052297c; local_30 = local_30 + 1) {
        local_40 = local_40 + *(int *)(&DAT_00522a68 + local_28 * 4 + local_30 * 0x40);
        if ((*(uint8_t *)(&DAT_005224e0 + local_30) & 0x80) != 0) {
          color_idx = color_idx + *(int *)(&DAT_00522a68 + local_28 * 4 + local_30 * 0x40);
        }
      }
      if (local_40 < (int)(&DAT_00522730)[local_28]) {
        match_count = match_count + local_40 * 2;
      }
      else {
        match_count = match_count + *(int *)(&DAT_00682700 +
                                    val_1 * 0x5b20 + (&DAT_00522f38)[local_28] * 0x120) +
                  (local_40 - (&DAT_00522730)[local_28]);
        val_2 = FUN_0049aa14(local_40 - (&DAT_00522730)[local_28],0,color_idx);
        card_idx = card_idx - val_2;
      }
    }
    if (card_idx < 1) {
      card_idx = card_idx * -0x18 + 999;
    }
    else {
      card_idx = (((&DAT_00681ea8)[val_1] - card_idx) * 0x30) / card_idx;
    }
    match_count = match_count + card_idx;
    if (arg_3 == 0) {
      if (*arg_8 < match_count) {
        *arg_8 = match_count;
        for (local_28 = 0; local_28 < 0x10; local_28 = local_28 + 1) {
          *(int32_t *)(&DAT_00522800 + local_28 * 4) =
               *(int32_t *)(&DAT_005228c8 + local_28 * 4);
        }
      }
    }
    else if (match_count < *arg_7) {
      *arg_7 = match_count;
      for (local_28 = 0; local_28 < 0x10; local_28 = local_28 + 1) {
        *(int32_t *)(&DAT_00522800 + local_28 * 4) =
             *(int32_t *)(&DAT_005228c8 + local_28 * 4);
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_004794d4
 * Entry Point: 004794d4
 * Size: 1150 bytes
 */


void FUN_004794d4(int player_id,int card_slot,int event_type,int arg_4,int arg_5,int arg_6,int *arg_7,int *arg_8)

{
  int val_1;
  int val_2;
  int val_3;
  int local_30;
  int local_2c;
  int local_28;
  int loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int slot_idx;
  
  val_1 = 1 - arg_1;
  if (arg_2 < DAT_00522a04) {
    if (((&DAT_006826cc)[val_1 * 0x5b20 + (&DAT_00522f38)[arg_2] * 0x120] & 0x10) == 0) {
      val_3 = (&DAT_00522ef8)[arg_2];
      val_2 = val_3 + 1;
      local_2c = 1;
      for (target_idx = 0; target_idx < DAT_0052297c; target_idx = target_idx + 1) {
        local_2c = val_2 * local_2c;
      }
      if (arg_6 == 0) {
        for (target_idx = 0; target_idx < local_2c; target_idx = target_idx + 1) {
          color_idx = target_idx;
          local_28 = val_3;
          for (loop_idx = 0; loop_idx < DAT_0052297c; loop_idx = loop_idx + 1) {
            val_1 = color_idx % val_2;
            if (((local_2c < 0x101) || (val_1 < 2)) || (local_28 <= val_1)) {
              *(int *)(&DAT_00522a68 + loop_idx * 4 + arg_2 * 0x40) = val_1;
              color_idx = color_idx / val_2;
              local_28 = local_28 - val_1;
            }
          }
          if (local_28 == 0) {
            *(int *)(&DAT_005228c8 + arg_2 * 4) = target_idx;
            FUN_004794d4(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,0,arg_7,arg_8);
          }
        }
      }
      else {
        color_idx = *(int *)(&DAT_00522800 + arg_2 * 4);
        for (loop_idx = 0; loop_idx < DAT_0052297c; loop_idx = loop_idx + 1) {
          player_idx = color_idx % val_2;
          val_3 = FUN_00479f9f(val_1,(&DAT_00522f38)[loop_idx]);
          if (val_3 != 0) {
            player_idx = 0;
          }
          if (player_idx != 0) {
            val_3 = FUN_004af950(arg_1,(&DAT_005225a0)[loop_idx],player_idx,val_1,
                                 (&DAT_00522f38)[arg_2]);
            *(int *)(arg_4 + loop_idx * 4) = val_3;
            if ((val_3 != -1) &&
               (*(uint32_t *)(&DAT_006826f8 + val_3 * 0x120 + val_1 * 0x5b20) =
                     *(uint32_t *)(&DAT_006826f8 + val_3 * 0x120 + val_1 * 0x5b20) | 0x40000, arg_5 == 0
               )) {
              *(uint32_t *)(&DAT_006826f8 + val_3 * 0x120 + val_1 * 0x5b20) =
                   *(uint32_t *)(&DAT_006826f8 + val_3 * 0x120 + val_1 * 0x5b20) | 0x100000;
            }
          }
          color_idx = color_idx / val_2;
        }
        FUN_004794d4(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,arg_6,arg_7,arg_8);
      }
    }
    else {
      FUN_004794d4(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,arg_6,arg_7,arg_8);
    }
  }
  else {
    slot_idx = 0;
    for (target_idx = 0; target_idx < DAT_0052297c; target_idx = target_idx + 1) {
      local_30 = 0;
      for (loop_idx = 0; loop_idx < DAT_00522a04; loop_idx = loop_idx + 1) {
        local_30 = local_30 + *(int *)(&DAT_00522a68 + target_idx * 4 + loop_idx * 0x40);
      }
      if (local_30 < (int)(&DAT_005226f0)[target_idx]) {
        slot_idx = slot_idx + local_30 * 2;
      }
      else {
        slot_idx = slot_idx + *(int *)(&DAT_00682700 +
                                    arg_1 * 0x5b20 + (&DAT_005225a0)[target_idx] * 0x120) +
                  (local_30 - (&DAT_005226f0)[target_idx]);
      }
    }
    if (arg_3 == 0) {
      if (*arg_8 < slot_idx) {
        *arg_8 = slot_idx;
        for (target_idx = 0; target_idx < 0x10; target_idx = target_idx + 1) {
          *(int32_t *)(&DAT_00522800 + target_idx * 4) =
               *(int32_t *)(&DAT_005228c8 + target_idx * 4);
        }
      }
    }
    else if (slot_idx < *arg_7) {
      *arg_7 = slot_idx;
      for (target_idx = 0; target_idx < 0x10; target_idx = target_idx + 1) {
        *(int32_t *)(&DAT_00522800 + target_idx * 4) =
             *(int32_t *)(&DAT_005228c8 + target_idx * 4);
      }
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00479952
 * Entry Point: 00479952
 * Size: 467 bytes
 */


void FUN_00479952(void)

{
  int val_1;
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 4; slot_idx = slot_idx + 1) {
    *(int32_t *)(&DAT_00666730 + slot_idx * 4) = 0;
  }
  slot_idx = 0;
  while( true ) {
    val_1 = (&DAT_00666408)[DAT_00676504];
    if ((int)(&DAT_00666408)[DAT_00676504] <= (int)(&DAT_00666408)[DAT_00676510]) {
      val_1 = (&DAT_00666408)[DAT_00676510];
    }
    if (val_1 <= slot_idx) break;
    if ((*(int *)(&DAT_006826c4 + slot_idx * 0x120 + DAT_00676510 * 0x5b20) != -1) &&
       (((&DAT_006826cc)[slot_idx * 0x120 + DAT_00676510 * 0x5b20] & 2) != 0)) {
      (**(code **)(&DAT_004ff5a0 +
                  *(int *)(&DAT_006826c4 + slot_idx * 0x120 + DAT_00676510 * 0x5b20) * 0x34))
                (DAT_00676510,slot_idx,0x3b);
    }
    if ((*(int *)(&DAT_006826c4 + slot_idx * 0x120 + DAT_00676504 * 0x5b20) != -1) &&
       ((((&DAT_006826cc)[slot_idx * 0x120 + DAT_00676510 * 0x5b20] & 2) != 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + slot_idx * 0x120 + DAT_00676504 * 0x5b20) * 0x34]
         & 0x10) != 0)))) {
      (**(code **)(&DAT_004ff5a0 +
                  *(int *)(&DAT_006826c4 + slot_idx * 0x120 + DAT_00676504 * 0x5b20) * 0x34))
                (DAT_00676504,slot_idx,0x3b);
    }
    slot_idx = slot_idx + 1;
  }
  return;
}



/*
 * Decompiled function: FUN_00479b25
 * Entry Point: 00479b25
 * Size: 96 bytes
 */


void FUN_00479b25(int player_id,int card_slot,int event_type)

{
  if (arg_3 == 0) {
    *(uint32_t *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffdffff;
  }
  else {
    *(uint32_t *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x20000;
  }
  return;
}



/*
 * Decompiled function: FUN_00479b85
 * Entry Point: 00479b85
 * Size: 96 bytes
 */


void FUN_00479b85(int player_id,int card_slot,int event_type)

{
  if (arg_3 == 0) {
    *(uint32_t *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffdffff;
  }
  else {
    *(uint32_t *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826f8 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x20000;
  }
  return;
}



/*
 * Decompiled function: FUN_00479be5
 * Entry Point: 00479be5
 * Size: 34 bytes
 */


void FUN_00479be5(WPARAM arg_1)

{
  PostMessageA(DAT_00618ab0,0x464,arg_1,0);
  return;
}



/*
 * Decompiled function: FUN_00479c07
 * Entry Point: 00479c07
 * Size: 524 bytes
 */


int FUN_00479c07(int arg1,int arg2)

{
  int val_1;
  int val_2;
  int local_24;
  int loop_idx;
  int slot_idx;
  
  val_1 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
  loop_idx = FUN_0048b81a(arg1,arg2,0x32,0xffffffff);
  local_24 = FUN_0048b81a(arg1,arg2,0x33,0xffffffff);
  if (loop_idx == 0) {
    loop_idx = 0;
  }
  else {
    loop_idx = loop_idx + 5;
  }
  if (local_24 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = local_24 + 3;
  }
  val_2 = (*(int *)(&DAT_004ff5b0 + val_1 * 0x34) + loop_idx + 2) * (local_24 + 2);
  slot_idx = val_2 * 5;
  if (((&DAT_004ff5a4)[val_1 * 0x34] & 0x1f) != 0) {
    slot_idx = (val_2 * 0xf) / 2;
  }
  if (((&DAT_004ff5a5)[val_1 * 0x34] & 2) != 0) {
    slot_idx = (slot_idx * 3) / 2;
  }
  if (((&DAT_004ff5a8)[val_1 * 0x34] & 3) != 0) {
    slot_idx = slot_idx / 2;
  }
  if (*(code **)(&DAT_004ff5a0 + val_1 * 0x34) != Mem_AllocOrFree_004521d0) {
    slot_idx = (slot_idx * 3) / 2;
  }
  if ((*(uint32_t *)(&DAT_004ff5a4 + val_1 * 0x34) & 0x1c0) != 0) {
    slot_idx = (slot_idx * 3) / 2;
  }
  if (((&DAT_004ff5a8)[val_1 * 0x34] & 8) != 0) {
    slot_idx = slot_idx * 3;
  }
  if (((&DAT_004ff5a8)[val_1 * 0x34] & 0x10) != 0) {
    slot_idx = slot_idx * 3;
  }
  if (((&DAT_006826cd)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) != 0) {
    slot_idx = slot_idx << 1;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_00479e13
 * Entry Point: 00479e13
 * Size: 396 bytes
 */


int FUN_00479e13(int arg1,int arg2)

{
  int val_1;
  int val_2;
  int local_24;
  int loop_idx;
  int slot_idx;
  
  val_1 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
  loop_idx = FUN_0048b81a(arg1,arg2,0x32,0xffffffff);
  local_24 = FUN_0048b81a(arg1,arg2,0x33,0xffffffff);
  if (loop_idx == 0) {
    loop_idx = 0;
  }
  else {
    loop_idx = loop_idx + 5;
  }
  if (local_24 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = local_24 + 5;
  }
  val_2 = (*(int *)(&DAT_004ff5b0 + val_1 * 0x34) + loop_idx + 2) * (local_24 + 2);
  slot_idx = val_2 * 5;
  if (((&DAT_004ff5a5)[val_1 * 0x34] & 2) != 0) {
    slot_idx = (val_2 * 0xf) / 2;
  }
  if (((&DAT_004ff5a8)[val_1 * 0x34] & 3) != 0) {
    slot_idx = slot_idx / 2;
  }
  if (((&DAT_004ff5a4)[val_1 * 0x34] & 0x20) != 0) {
    slot_idx = (slot_idx * 3) / 2;
  }
  if (((&DAT_004ff5a8)[val_1 * 0x34] & 8) != 0) {
    slot_idx = slot_idx * 3;
  }
  if (((&DAT_004ff5a8)[val_1 * 0x34] & 0x10) != 0) {
    slot_idx = slot_idx * 3;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_00479f9f
 * Entry Point: 00479f9f
 * Size: 237 bytes
 */


int32_t FUN_00479f9f(int arg1,int arg2)

{
  int match_count;
  int slot_idx;
  
  match_count = 0;
  do {
    if (1 < match_count) {
      return 0;
    }
    for (slot_idx = 0; slot_idx < (int)(&DAT_00666408)[match_count]; slot_idx = slot_idx + 1) {
      if ((((char)(&DAT_006826d2)[slot_idx * 0x120 + match_count * 0x5b20] == arg1) &&
          (*(int *)(&DAT_006826e8 + slot_idx * 0x120 + match_count * 0x5b20) == arg2)) &&
         (*(int *)(&DAT_004ff590 +
                  *(int *)(&DAT_006826c4 + slot_idx * 0x120 + match_count * 0x5b20) * 0x34) == 0x285)) {
        return 1;
      }
    }
    match_count = match_count + 1;
  } while( true );
}



/*
 * Decompiled function: FUN_0047a090
 * Entry Point: 0047a090
 * Size: 494 bytes
 */


int32_t FUN_0047a090(int x,int y,int width,int height)

{
  int32_t uval_1;
  
  if ((width == 0x71) && (DAT_0066aaf4 != 1)) {
    FUN_0048d00c(height + 8);
  }
  if (width == 0x73) {
    if ((((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[y * 0x120 + x * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) * 0x34] & 2) == 0)))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (width == 0x6d) {
      FUN_0049b2c1(x,height,1);
      *(uint32_t *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) | 0x10;
      DAT_0068f0f4 = height;
    }
    if (((width == 0x7f) && (DAT_00690c48 == y)) && (x == DAT_0068ecb0)) {
      if (((((&DAT_006826ce)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
          (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) * 0x34] & 2) == 0)) &&
         (((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
        FUN_0049b1a9(x,height,1);
      }
      *(uint32_t *)(&DAT_0068f360 + x * 4) =
           *(uint32_t *)(&DAT_0068f360 + x * 4) | 1 << ((uint8_t)height & 0x1f);
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a283
 * Entry Point: 0047a283
 * Size: 38 bytes
 */


void Mem_AllocOrFree_0047a283(int player_id,int card_slot,int event_type)

{
  FUN_0047a090(arg_1,arg_2,arg_3,1);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a2a9
 * Entry Point: 0047a2a9
 * Size: 38 bytes
 */


void Mem_AllocOrFree_0047a2a9(int player_id,int card_slot,int event_type)

{
  FUN_0047a090(arg_1,arg_2,arg_3,2);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a2cf
 * Entry Point: 0047a2cf
 * Size: 38 bytes
 */


void Mem_AllocOrFree_0047a2cf(int player_id,int card_slot,int event_type)

{
  FUN_0047a090(arg_1,arg_2,arg_3,3);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a2f5
 * Entry Point: 0047a2f5
 * Size: 38 bytes
 */


void Mem_AllocOrFree_0047a2f5(int player_id,int card_slot,int event_type)

{
  FUN_0047a090(arg_1,arg_2,arg_3,4);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a31b
 * Entry Point: 0047a31b
 * Size: 38 bytes
 */


void Mem_AllocOrFree_0047a31b(int player_id,int card_slot,int event_type)

{
  FUN_0047a090(arg_1,arg_2,arg_3,5);
  return;
}



/*
 * Decompiled function: Mana_Init_00452b71
 * Entry Point: 0047a341
 * Size: 779 bytes
 */


void Mana_Init_00452b71(int player_id,int card_slot,int event_type,int arg_4,int arg_5)

{
  uint32_t *u_ptr_1;
  char *str_5;
  char *str_4;
  int val_2;
  char *str_6;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 1) {
    for (slot_idx = 0; slot_idx < 7; slot_idx = slot_idx + 1) {
      if ((1 << ((uint8_t)slot_idx & 0x1f) & (int)(char)(&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20])
          != 0) {
        FUN_0049b1a9(arg_1,slot_idx,1);
      }
    }
  }
  if (arg_3 == 0x71) {
    for (slot_idx = 0; slot_idx < 7; slot_idx = slot_idx + 1) {
      if ((1 << ((uint8_t)slot_idx & 0x1f) & (int)(char)(&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20])
          != 0) {
        FUN_0049aed0(arg_1,slot_idx,1);
      }
    }
  }
  if ((arg_3 != 0x73) && (arg_3 == 0x6d)) {
    if ((arg_4 == DAT_00666748) || (DAT_00666748 == 0)) {
      match_count = arg_4;
    }
    else if (arg_5 == DAT_00666748) {
      match_count = arg_5;
    }
    else {
      Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Which_mana__1__004f9a2c);
      u_ptr_1 = (uint32_t *)Mem_AllocOrFree_0048c420(arg_4);
      FUN_004d9640((uint32_t *)&DAT_005f6810,u_ptr_1);
      FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)&DAT_004f9a3c);
      u_ptr_1 = (uint32_t *)Mem_AllocOrFree_0048c420(arg_5);
      FUN_004d9640((uint32_t *)&DAT_005f6810,u_ptr_1);
      str_6 = (char *)0x0;
      str_5 = (char *)Mem_AllocOrFree_0048c420(arg_5);
      str_4 = (char *)Mem_AllocOrFree_0048c420(arg_4);
      val_2 = FUN_004512d1(arg_1,s_Which_type_of_mana_to_produce__004f9a44,0,str_4,str_5,str_6);
      if (val_2 == 0) {
        match_count = arg_4;
      }
      else {
        match_count = arg_5;
      }
    }
    FUN_0049b235(arg_1,match_count,1);
    for (slot_idx = 0; slot_idx < 7; slot_idx = slot_idx + 1) {
      if ((1 << ((uint8_t)slot_idx & 0x1f) & (int)(char)(&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20])
          != 0) {
        FUN_0049b1eb(arg_1,slot_idx,1);
      }
    }
    *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    DAT_0068f0f4 = match_count;
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a651
 * Entry Point: 0047a651
 * Size: 42 bytes
 */


int32_t Mem_AllocOrFree_0047a651(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(arg_1,arg_2,arg_3,4,1);
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a67b
 * Entry Point: 0047a67b
 * Size: 42 bytes
 */


int32_t Mem_AllocOrFree_0047a67b(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(arg_1,arg_2,arg_3,1,3);
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a6a5
 * Entry Point: 0047a6a5
 * Size: 42 bytes
 */


int32_t Mem_AllocOrFree_0047a6a5(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(arg_1,arg_2,arg_3,4,5);
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a6cf
 * Entry Point: 0047a6cf
 * Size: 42 bytes
 */


int32_t Mem_AllocOrFree_0047a6cf(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(arg_1,arg_2,arg_3,5,3);
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a6f9
 * Entry Point: 0047a6f9
 * Size: 42 bytes
 */


int32_t Mem_AllocOrFree_0047a6f9(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(arg_1,arg_2,arg_3,5,1);
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a723
 * Entry Point: 0047a723
 * Size: 42 bytes
 */


int32_t Mem_AllocOrFree_0047a723(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(arg_1,arg_2,arg_3,3,4);
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a74d
 * Entry Point: 0047a74d
 * Size: 42 bytes
 */


int32_t Mem_AllocOrFree_0047a74d(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(arg_1,arg_2,arg_3,3,2);
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a777
 * Entry Point: 0047a777
 * Size: 42 bytes
 */


int32_t Mem_AllocOrFree_0047a777(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(arg_1,arg_2,arg_3,2,5);
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a7a1
 * Entry Point: 0047a7a1
 * Size: 42 bytes
 */


int32_t Mem_AllocOrFree_0047a7a1(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(arg_1,arg_2,arg_3,1,2);
  return 0;
}



/*
 * Decompiled function: Mem_AllocOrFree_0047a7cb
 * Entry Point: 0047a7cb
 * Size: 42 bytes
 */


int32_t Mem_AllocOrFree_0047a7cb(int player_id,int card_slot,int event_type)

{
  Mana_Init_00452b71(arg_1,arg_2,arg_3,2,4);
  return 0;
}



/*
 * Decompiled function: FUN_0047a7f5
 * Entry Point: 0047a7f5
 * Size: 716 bytes
 */


int32_t FUN_0047a7f5(int player_id,int card_slot,int event_type)

{
  char cVar1;
  int val_2;
  int32_t uval_3;
  
  if (arg_3 == 1) {
    val_2 = FUN_0048c367((&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20]);
    uval_3 = FUN_0047a090(arg_1,arg_2,1,val_2);
  }
  else {
    if (arg_3 == 0x71) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x25);
      }
      if (arg_1 == DAT_00676510) {
        cVar1 = FUN_00439892(5);
        (&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20] = (char)(1 << (cVar1 + 1U & 0x1f));
      }
      else {
        (&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_00692c74;
      }
    }
    if (arg_3 == 0x73) {
      val_2 = FUN_0048c367((&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20]);
      uval_3 = FUN_0047a090(arg_1,arg_2,0x73,val_2);
    }
    else if (arg_3 == 0x6d) {
      val_2 = FUN_0048c367((&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20]);
      uval_3 = FUN_0047a090(arg_1,arg_2,0x6d,val_2);
    }
    else {
      if (arg_3 == 0x72) {
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x25);
        }
        if (arg_1 == DAT_00676510) {
          cVar1 = FUN_00439892(5);
          (&DAT_006826dc)
          [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] =
               (char)(1 << (cVar1 + 1U & 0x1f));
        }
        else {
          (&DAT_006826dc)
          [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = DAT_00692c74;
        }
      }
      if (arg_3 == 0x7f) {
        val_2 = FUN_0048c367((&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20]);
        uval_3 = FUN_0047a090(arg_1,arg_2,0x7f,val_2);
      }
      else {
        uval_3 = 0;
      }
    }
  }
  return uval_3;
}



/*
 * Decompiled function: Mana_Init_004532f1
 * Entry Point: 0047aac1
 * Size: 514 bytes
 */


int32_t Mana_Init_004532f1(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (arg_3 == 1) {
    uval_1 = FUN_0047a090(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (arg_1 == DAT_00676510) {
        val_2 = FUN_00439892(5);
        card_idx = val_2 + 1;
      }
      else {
        slot_idx = -1;
        for (match_count = 1; match_count < 7; match_count = match_count + 1) {
          if (slot_idx < *(int *)(&DAT_0068f320 + match_count * 4 + arg_1 * 0x20)) {
            slot_idx = *(int *)(&DAT_0068f320 + match_count * 4 + arg_1 * 0x20);
            card_idx = match_count;
          }
        }
      }
      if (arg_1 == 1) {
        player_idx = card_idx;
      }
      else {
        player_idx = -1;
      }
      val_2 = FUN_004513fa(arg_1,s_What_kind_of_mana__004f9a64,1,player_idx,0xffffffff);
      if (val_2 == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0049b235(arg_1,val_2,1);
        Mem_AllocOrFree_004afd1c(arg_1,1,arg_1,arg_2);
        *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
        DAT_0068f0f4 = val_2;
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Ai_Subsystem_004b8e4d
 * Entry Point: 0047acdd
 * Size: 670 bytes
 */


int32_t Ai_Subsystem_004b8e4d(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 1) {
    uval_1 = FUN_0047a090(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      if (((DAT_0068f2c4 < 0x1a) || (0x1d < DAT_0068f2c4)) ||
         (val_2 = FUN_004512d1(arg_1,s_Desert__004f9a88,1,s_Damage_004f9a80,&DAT_004f9a78,
                               (char *)0x0), val_2 != 0)) {
        FUN_0049b235(arg_1,0,1);
        DAT_0068f0f4 = 0;
      }
      else {
        val_2 = FUN_00468130(arg_1,1 - arg_1,arg_2);
        if (val_2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          if (((&DAT_006826cc)
               [*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 0x44) != 0) {
            FUN_004af950(*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),1,arg_1,arg_2);
          }
          (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
          FUN_0049b1eb(arg_1,0,1);
          *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
        }
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Oasis
 * Entry Point: 0047af80
 * Size: 1200 bytes
 */


int32_t CardScript_Oasis(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  uint32_t player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x73) {
    player_idx = (uint32_t)(((uint8_t)DAT_00681eb0 & 4) != 0);
    if (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0) {
      player_idx = 0;
    }
    if (((player_idx != 0) && (((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0)) &&
       (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2
        ) != 0)) {
      player_idx = 0;
    }
    if (player_idx != 0) {
      player_idx = FUN_0041bcf0((int *)0x0,1,spell_id,2,2,0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,
                              0xffffffff,0xffffffff,0,0,0);
    }
    if (player_idx == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 99;
    }
  }
  else if (flags == 0x90) {
    FUN_0043071d(0);
    uval_1 = 0;
  }
  else {
    if ((flags == 0x6d) && (((uint8_t)DAT_00681eb0 & 4) != 0)) {
      if (DAT_0068f220 == 0) {
        slot_idx = 0;
        while (slot_idx == 0) {
          FUN_00434660(s_prompts_txt_004f9a98,s_OASIS_004f9a90);
          val_2 = Action_ValidateTarget_0041e2a2
                            (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_0068f104,-1,0xffffffff,0xffffffff,0,
                             0,0,&DAT_006679f0,1,&card_idx);
          if (val_2 == 0) {
            DAT_00681ea4 = 1;
            slot_idx = 1;
          }
          else if (*(int *)(&DAT_006826e8 + card_idx * 0x5b20 + match_count * 0x120) == -1) {
            if (DAT_0066aaf4 != 1) {
              Mem_AllocOrFree_00450eed(s_Illegal_target__damage_type___004f9aa4);
              Sleep(2000);
              Mem_AllocOrFree_00450eed(&DAT_004f9ac4);
            }
          }
          else {
            slot_idx = 1;
            *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
            *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = match_count;
            (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
            *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
          }
        }
      }
      else {
        (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        DAT_00681ea4 = 1;
      }
    }
    if ((flags == 0x72) && ((&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] != '\0')) {
      card_idx = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      match_count = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      val_2 = Rules_ParseFilter_0041c0ab
                        (card_idx,match_count,(uint8_t *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,
                         DAT_0068f104,-1,0xffffffff,0xffffffff,0,0,0);
      if (val_2 != 0) {
        if (*(int *)(&DAT_006826e4 + card_idx * 0x5b20 + match_count * 0x120) < 1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_006826e4 + card_idx * 0x5b20 + match_count * 0x120) =
               *(int *)(&DAT_006826e4 + card_idx * 0x5b20 + match_count * 0x120) + -1;
        }
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if ((flags == 0x3b) && (((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) {
      *(int *)(&DAT_00666738 + spell_id * 4) = *(int *)(&DAT_00666738 + spell_id * 4) + 1;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_ElephantsGraveyard
 * Entry Point: 0047b430
 * Size: 886 bytes
 */


int32_t CardScript_ElephantsGraveyard(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  int match_count;
  
  if (arg_3 == 1) {
    uval_1 = FUN_0047a090(arg_1,arg_2,1,0);
    return uval_1;
  }
  if (arg_3 != 0x73) {
    if (arg_3 == 0x6d) {
      if ((((uint8_t)DAT_00681eb0 & 4) == 0) ||
         (val_2 = FUN_004512d1(arg_1,s_Elephant_s_Graveyard__004f9adc,1,s_Regenerate_004f9ad0,
                               &DAT_004f9ac8,(char *)0x0), val_2 != 0)) {
        FUN_0049b235(arg_1,0,1);
        DAT_0068f0f4 = 0;
      }
      else {
        if ((match_count != -1) &&
           (((&DAT_004ff595)
             [*(int *)(&DAT_006826c4 +
                      *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) * 0x34] ==
             '\n' || ((&DAT_004ff595)
                      [*(int *)(&DAT_006826c4 +
                               *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                               *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) *
                       0x34] == '\v')))) {
          (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (uint8_t)DAT_0068eef0;
          *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = match_count;
          *(uint32_t *)(&DAT_006826fc +
                   *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint32_t *)(&DAT_006826fc +
                        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) | 0x200;
        }
        FUN_0049b1eb(arg_1,0,1);
      }
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (((uint8_t)DAT_00681eb0 & 4) == 0) {
      *(int32_t *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if ((((arg_3 == 0x34) &&
         (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
        ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0)) &&
       (DAT_00690c48 != -1)) {
      DAT_0066642c = DAT_0066642c | 0x200;
    }
    return 0;
  }
  if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0))
     )) {
    return 1;
  }
  return 0;
}



/*
 * Decompiled function: Mana_Init_00453fdb
 * Entry Point: 0047b7ab
 * Size: 1016 bytes
 */


int32_t Mana_Init_00453fdb(int spell_id,int target_id,int flags)

{
  int color_mask;
  int val_1;
  uint32_t arg_11;
  uint32_t arg_12;
  uint32_t arg_13;
  int val_2;
  int arg_15;
  uint32_t arg_16;
  uint32_t arg_17;
  uint32_t arg_18;
  uint32_t arg_19;
  uint32_t arg_20;
  int32_t player_idx;
  int slot_idx;
  
  if (flags == 1) {
    player_idx = FUN_0047a090(spell_id,target_id,1,0);
  }
  else if (flags == 0x71) {
    player_idx = FUN_0047a090(spell_id,target_id,0x71,0);
  }
  else if (flags == 0x73) {
    player_idx = FUN_0047a090(spell_id,target_id,0x73,0);
  }
  else if (flags == 0x6d) {
    player_idx = 0;
    Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Get_mana__004f9af4);
    FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Sacrifice_to_destroy_a_land__004f9b00);
    FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Cancel__004f9b20);
    (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    if (DAT_00666748 == 0) {
      slot_idx = 0;
    }
    else if (DAT_0068f220 == 0) {
      if (spell_id == DAT_00676510) {
        slot_idx = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&DAT_005f6810,1);
      }
      else {
        slot_idx = 1;
      }
    }
    else {
      slot_idx = 0;
    }
    if (slot_idx == 0) {
      player_idx = FUN_0047a090(spell_id,target_id,0x6d,0);
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    else if (slot_idx == 1) {
      DAT_0068f0f4 = 0xffffffff;
      FUN_00434660(s_prompts_txt_004f9b38,s_STRIPMINE_004f9b2c);
      val_1 = FUN_00468550(spell_id,1 - spell_id,target_id);
      if (val_1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0xf);
        }
        FUN_0046e571(spell_id,target_id,3);
        FUN_0049b1eb(spell_id,0,1);
      }
    }
    else {
      DAT_00681ea4 = 1;
    }
    if (DAT_00681ea4 == 1) {
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
  }
  else {
    if ((flags == 0x72) && ((&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] != '\0')) {
      val_1 = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
      color_mask = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      val_2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(spell_id,target_id);
      val_2 = Rules_ParseFilter_0041c0ab
                        (val_1,color_mask,(uint8_t *)0x0,spell_id,2,2,0x200,1,0,0,arg_11,arg_12,
                         arg_13,val_2,arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(val_1,color_mask,2);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if (flags == 0x7f) {
      player_idx = FUN_0047a090(spell_id,target_id,0x7f,0);
    }
    else {
      player_idx = 0;
    }
  }
  return player_idx;
}



/*
 * Decompiled function: FUN_0047bba3
 * Entry Point: 0047bba3
 * Size: 495 bytes
 */


int32_t FUN_0047bba3(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      val_2 = FUN_00468130(arg_1,arg_1,arg_2);
      if (val_2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) == arg_1) {
          val_2 = FUN_0048b81a(*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                               *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),0x33,
                               0xffffffff);
          (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + val_2;
          FUN_0046e571(*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                       *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),3);
        }
        *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0047bd97
 * Entry Point: 0047bd97
 * Size: 310 bytes
 */


int32_t FUN_0047bd97(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  int slot_idx;
  
  if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_00487ce1(arg_1);
      FUN_00487ce1(arg_1);
      for (slot_idx = 0; slot_idx < 3; slot_idx = slot_idx + 1) {
        if (0 < (int)(&DAT_0068ee78)[arg_1]) {
          Palette_Color_0049ae00(arg_1,0,0);
        }
      }
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Mana_Init_00453fdb
 * Entry Point: 0047bed2
 * Size: 739 bytes
 */


int32_t Mana_Init_00453fdb(int player_id,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  uint32_t match_count;
  uint32_t slot_idx;
  
  if (arg_3 == 1) {
    uval_2 = FUN_0047a090(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x71) {
    uval_2 = FUN_0047a090(arg_1,arg_2,0x71,0);
  }
  else if (arg_3 == 0x73) {
    uval_2 = FUN_0047a090(arg_1,arg_2,0x73,0);
  }
  else {
    if (arg_3 == 0x6d) {
      Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Get_mana__004f9b44);
      val_1 = (&DAT_0068ee78)[arg_1];
      if (val_1 != 7) {
        FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s___Draw_a_card__004f9b60);
      }
      else {
        FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Draw_a_card__004f9b50);
      }
      match_count = (uint32_t)(val_1 == 7);
      FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Cancel__004f9b70);
      if (DAT_00666748 == 0) {
        slot_idx = 0;
      }
      else if (DAT_0068f220 == 0) {
        if (arg_1 == DAT_00676510) {
          slot_idx = Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,match_count);
        }
        else {
          slot_idx = match_count;
        }
      }
      else {
        slot_idx = 0;
      }
      *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      if (slot_idx == 0) {
        uval_2 = FUN_0047a090(arg_1,arg_2,0x6d,0);
        return uval_2;
      }
      if (slot_idx == 1) {
        *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
        FUN_0049b1eb(arg_1,0,1);
        *(int32_t *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
        DAT_0068f0f4 = 0xffffffff;
      }
      else {
        DAT_00681ea4 = 1;
      }
    }
    if ((arg_3 == 0x72) && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 1)) {
      *(int32_t *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0;
      FUN_00487ce1(arg_1);
    }
    if (arg_3 == 0x7f) {
      uval_2 = FUN_0047a090(arg_1,arg_2,0x7f,0);
    }
    else {
      uval_2 = 0;
    }
  }
  return uval_2;
}



/*
 * Decompiled function: Mana_Init_00453fdb
 * Entry Point: 0047c1ba
 * Size: 3033 bytes
 */


int32_t Mana_Init_00453fdb(int spell_id,int target_id,int flags)

{
  bool flag_1;
  int32_t uval_2;
  int val_3;
  int32_t uval_4;
  int32_t arg_10;
  uint32_t uval_5;
  uint32_t uval_6;
  uint32_t uval_7;
  int32_t arg_11;
  int val_8;
  int32_t arg_12;
  uint32_t uVar9;
  uint32_t uVar10;
  int32_t arg_14;
  uint32_t uVar11;
  int32_t arg_15;
  uint32_t uVar12;
  int32_t arg_16;
  uint32_t uVar13;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int local_24;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 1) {
    uval_2 = FUN_0047a090(spell_id,target_id,1,0);
    return uval_2;
  }
  if (flags == 0x6c) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
  }
  if (flags == 0x71) {
    uval_2 = FUN_0047a090(spell_id,target_id,0x71,0);
    return uval_2;
  }
  if (flags == 0x73) {
    flag_1 = false;
    if ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
         2) == 0)))) {
      flag_1 = true;
    }
    val_3 = FUN_0049b309(spell_id,7,1);
    if (val_3 != 0) {
      flag_1 = true;
    }
    if (flag_1) {
      if ((spell_id == DAT_00676504) && (0 < DAT_0068f2c0)) {
        DAT_00676500 = DAT_00676500 | 3;
      }
      return 1;
    }
    return 0;
  }
  if (flags != 0x6d) {
    if (flags == 0x72) {
      slot_idx = *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20);
      if (slot_idx != 0) {
        if (slot_idx == 1) {
          uval_2 = FUN_004d7d5e(0x38e);
          *(int32_t *)
           (&DAT_006826c4 +
           *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = uval_2;
          *(int32_t *)
           (&DAT_006826c8 +
           *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               *(int32_t *)
                (&DAT_006826c4 +
                *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120);
          *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) =
               *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) + 1;
          (&DAT_0068ee88)[DAT_00690af0] = (&DAT_0068ee88)[DAT_00690af0] + 1;
          *(uint32_t *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               *(uint32_t *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) | 2
          ;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x6c,1 - DAT_00690af0,0xffffffff);
          *(uint32_t *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                   *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) =
               *(uint32_t *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) |
               0x80;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x71,1 - DAT_00690af0,0xffffffff);
        }
        else if ((slot_idx == 2) && ((&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] != '\0'))
        {
          player_idx = *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20);
          card_idx = *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20);
          uVar13 = 0;
          uVar12 = 0;
          uVar11 = 0;
          uVar10 = 0xffffffff;
          uVar9 = 0xffffffff;
          val_8 = -1;
          val_3 = FUN_004d7d5e(0x38e);
          uval_7 = 0;
          uval_6 = 0;
          uval_5 = FUN_004521e2(spell_id,target_id);
          val_3 = Rules_ParseFilter_0041c0ab
                            (player_idx,card_idx,(uint8_t *)0x0,spell_id,2,2,0x200,0,0,0,uval_5,
                             uval_6,uval_7,val_3,val_8,uVar9,uVar10,uVar11,uVar12,uVar13);
          if (val_3 == 0) {
            DAT_00681ea4 = 1;
          }
          else {
            match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,player_idx,card_idx);
            if (match_count != -1) {
              *(int16_t *)(&DAT_006826d8 + match_count * 0x120 + spell_id * 0x5b20) = 1;
              *(int16_t *)(&DAT_006826da + match_count * 0x120 + spell_id * 0x5b20) = 1;
            }
          }
          (&DAT_006827b8)
          [*(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
        }
      }
      *(int32_t *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + target_id * 0x120 + spell_id * 0x5b20) * 0x120) = 0;
    }
    if (flags == 0x7f) {
      uval_2 = FUN_0047a090(spell_id,target_id,0x7f,0);
      return uval_2;
    }
    if (((((flags == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) && (target_id == DAT_00690c48)) &&
        ((spell_id == DAT_0068ecb0 && (val_3 = FUN_0048a33f(spell_id,target_id), val_3 != 0)))) &&
       (*(int *)(&DAT_006826c8 + target_id * 0x120 + spell_id * 0x5b20) != 0)) {
      DAT_0066642c = *(int32_t *)(&DAT_006826c8 + target_id * 0x120 + spell_id * 0x5b20);
    }
    if (flags == 199) {
      if (spell_id == DAT_00676504) {
        DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x30;
      }
    }
    return 0;
  }
  uval_2 = 0;
  local_24 = 3;
  if ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2)
       == 0)))) {
    Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Get_mana__004f9b7c);
    local_24 = 0;
  }
  else {
    Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s__Get_mana__004f9b88);
  }
  val_3 = FUN_0049b309(spell_id,7,1);
  if (val_3 == 0) {
    FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s__Change_to_Assembly_Worker__004f9bb8);
  }
  else {
    FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Change_to_Assembly_Worker__004f9b98);
    if (DAT_0068f2c4 < 0x17) {
      local_24 = 1;
    }
  }
  if ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
     ((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2)
       == 0)))) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    uval_4 = FUN_004d7d5e(0x38e);
    arg_12 = 0;
    arg_11 = 0;
    arg_10 = FUN_004521e2(spell_id,target_id);
    val_3 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0,0,0,arg_10,arg_11,arg_12,uval_4,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (val_3 != 0) {
      FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Pump_Assembly_Worker__004f9bd8);
      if ((DAT_0068f2c4 < 0x1e) && (0x16 < DAT_0068f2c4)) {
        local_24 = 2;
      }
      goto LAB_0047c563;
    }
  }
  FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s__Pump_Assembly_Worker__004f9bf0);
LAB_0047c563:
  FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Cancel__004f9c0c);
  if (DAT_0068f220 == 0) {
    slot_idx = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&DAT_005f6810,local_24);
  }
  else {
    slot_idx = 0;
  }
  *(int *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = slot_idx;
  if (slot_idx == 0) {
    uval_2 = FUN_0047a090(spell_id,target_id,0x6d,0);
    (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
  }
  else if (slot_idx == 1) {
    uval_5 = *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20);
    *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x40000;
    Ai_CalcManaRequirement_004ba890(spell_id,0,1);
    if ((uval_5 & 0x40000) == 0) {
      *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) & 0xfffbffff;
    }
    (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    DAT_0068f0f4 = 0xffffffff;
  }
  else if (slot_idx == 2) {
    FUN_00434660(s_prompts_txt_004f9c28,s_MISHRAS_FACTORY_004f9c18);
    arg_20 = &player_idx;
    uval_4 = 1;
    arg_18 = &DAT_006679f0;
    uVar13 = 0;
    uVar12 = 0;
    uVar11 = 0;
    uVar10 = 0xffffffff;
    uVar9 = 0xffffffff;
    val_8 = -1;
    val_3 = FUN_004d7d5e(0x38e);
    uval_7 = 0;
    uval_6 = 0;
    uval_5 = FUN_004521e2(spell_id,target_id);
    val_3 = Action_ValidateTarget_0041e2a2
                      (spell_id,2,spell_id,0x200,0,0,0,uval_5,uval_6,uval_7,val_3,val_8,uVar9,uVar10,
                       uVar11,uVar12,uVar13,arg_18,uval_4,arg_20);
    if (val_3 == 0) {
      DAT_00681ea4 = 1;
    }
    else {
      *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      FUN_0049b1eb(spell_id,0,1);
      *(int *)(&DAT_00682718 + target_id * 0x120 + spell_id * 0x5b20) = player_idx;
      *(int *)(&DAT_0068271c + target_id * 0x120 + spell_id * 0x5b20) = card_idx;
      (&DAT_006827b8)[target_id * 0x120 + spell_id * 0x5b20] = 1;
    }
    DAT_0068f0f4 = 0xffffffff;
  }
  else {
    DAT_00681ea4 = 1;
  }
  if (0 < DAT_0068f2c0) {
    DAT_0068f2c0 = DAT_0068f2c0 + -1;
  }
  return uval_2;
}



/*
 * Decompiled function: Mana_Init_004555c8
 * Entry Point: 0047cd98
 * Size: 2960 bytes
 */


int32_t Mana_Init_004555c8(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  int val_2;
  int32_t arg_10;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  int32_t arg_11;
  int val_6;
  int32_t arg_12;
  uint32_t uval_7;
  uint32_t uval_8;
  int32_t arg_14;
  uint32_t uVar9;
  int32_t arg_15;
  uint32_t uVar10;
  int32_t arg_16;
  uint32_t uVar11;
  int32_t arg_17;
  uint8_t *arg_18;
  int32_t arg_18_00;
  int32_t arg_19;
  int *arg_20;
  int local_24;
  int32_t loop_idx;
  int32_t target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  if (flags == 0x22) {
    uval_1 = FUN_004d7d5e(0x1fc);
    *(int32_t *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) = uval_1;
    *(int32_t *)(&DAT_006826c8 + spell_id * 0x5b20 + target_id * 0x120) = 0;
    (&DAT_0068ee88)[spell_id] = (&DAT_0068ee88)[spell_id] + -1;
    *(int *)(&DAT_0068ee80 + spell_id * 4) = *(int *)(&DAT_0068ee80 + spell_id * 4) + -1;
    DAT_00692c6c = spell_id;
    DAT_00692c68 = target_id;
    FUN_00467d65(FUN_0047d928,spell_id);
  }
  if (((flags == 0x77) && (target_id == DAT_00690c48)) && (spell_id == DAT_0068ecb0)) {
    uval_1 = FUN_004d7d5e(0x1fc);
    *(int32_t *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) = uval_1;
    return 0;
  }
  if (flags == 1) {
    uval_1 = FUN_0047a090(spell_id,target_id,1,0);
    return uval_1;
  }
  if (flags == 0x71) {
    uval_1 = FUN_0047a090(spell_id,target_id,0x71,0);
    return uval_1;
  }
  if (flags == 0x73) {
    target_idx = 0;
    if ((((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
       ((((&DAT_006826ce)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) * 0x34] &
         2) == 0)))) {
      target_idx = 1;
    }
    val_2 = FUN_0049b309(spell_id,7,1);
    if (val_2 == 0) {
      return target_idx;
    }
    return 1;
  }
  if (flags != 0x6d) {
    if (flags == 0x72) {
      slot_idx = *(int *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120);
      if (slot_idx != 0) {
        if (slot_idx == 1) {
          uval_1 = FUN_004d7d5e(0x38e);
          *(int32_t *)
           (&DAT_006826c4 +
           *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = uval_1;
          *(int32_t *)
           (&DAT_006826c8 +
           *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) =
               *(int32_t *)
                (&DAT_006826c4 +
                *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
                *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120);
          *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) =
               *(int *)(&DAT_0068ee80 + DAT_00690af0 * 4) + 1;
          (&DAT_0068ee88)[DAT_00690af0] = (&DAT_0068ee88)[DAT_00690af0] + 1;
          *(uint32_t *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                   *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
               *(uint32_t *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                        *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) |
               2;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x6c,1 - DAT_00690af0,0xffffffff);
          *(uint32_t *)(&DAT_006826cc +
                   *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                   *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
               *(uint32_t *)(&DAT_006826cc +
                        *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                        *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) |
               0x80;
          FUN_0048c907(DAT_00690af0,DAT_0068efa0,0x71,1 - DAT_00690af0,0xffffffff);
        }
        else if ((slot_idx == 2) && ((&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] != '\0'))
        {
          player_idx = *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120);
          card_idx = *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120);
          uVar11 = 0;
          uVar10 = 0;
          uVar9 = 0;
          uval_8 = 0xffffffff;
          uval_7 = 0xffffffff;
          val_6 = -1;
          val_2 = FUN_004d7d5e(0x38e);
          uval_5 = 0;
          uval_4 = 0;
          uval_3 = FUN_004521e2(spell_id,target_id);
          val_2 = Rules_ParseFilter_0041c0ab
                            (player_idx,card_idx,(uint8_t *)0x0,spell_id,2,2,0x200,0,0,0,uval_3,
                             uval_4,uval_5,val_2,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
          if (val_2 == 0) {
            DAT_00681ea4 = 1;
          }
          else {
            match_count = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,player_idx,card_idx);
            if (match_count != -1) {
              *(int16_t *)(&DAT_006826d8 + match_count * 0x120 + spell_id * 0x5b20) = 1;
              *(int16_t *)(&DAT_006826da + match_count * 0x120 + spell_id * 0x5b20) = 1;
            }
          }
          (&DAT_006827b8)
          [*(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
           *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120] = 0;
        }
      }
      *(int32_t *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&DAT_006827b4 + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = 0;
    }
    if (flags == 0x7f) {
      uval_1 = FUN_0047a090(spell_id,target_id,0x7f,0);
      return uval_1;
    }
    return 0;
  }
  loop_idx = 0;
  local_24 = 3;
  if ((((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
     ((((&DAT_006826ce)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2)
       == 0)))) {
    Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s_Get_mana__004f9c34);
    local_24 = 0;
  }
  else {
    Mem_AllocOrFree_004d9630((uint32_t *)&DAT_005f6810,(uint32_t *)s__Get_mana__004f9c40);
  }
  val_2 = FUN_0049b309(spell_id,7,1);
  if (val_2 == 0) {
    FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s__Re_change_to_Assembly_Worker__004f9c70);
  }
  else {
    FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Re_change_to_Assembly_Worker__004f9c50);
  }
  if ((((&DAT_006826cc)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0) &&
     ((((&DAT_006826ce)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2)
       == 0)))) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    uval_1 = FUN_004d7d5e(0x38e);
    arg_12 = 0;
    arg_11 = 0;
    arg_10 = FUN_004521e2(spell_id,target_id);
    val_2 = FUN_0041bcf0((int *)0x0,0,spell_id,2,2,0x200,0,0,0,arg_10,arg_11,arg_12,uval_1,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
    if (val_2 != 0) {
      FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Pump_Assembly_Worker__004f9c94);
      if ((DAT_0068f2c4 < 0x1e) && (0x16 < DAT_0068f2c4)) {
        local_24 = 2;
      }
      goto LAB_0047d1c9;
    }
  }
  FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s__Pump_Assembly_Worker__004f9cac);
LAB_0047d1c9:
  FUN_004d9640((uint32_t *)&DAT_005f6810,(uint32_t *)s_Cancel__004f9cc8);
  if (DAT_0068f220 == 0) {
    slot_idx = Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&DAT_005f6810,local_24);
  }
  else {
    slot_idx = 0;
  }
  *(int *)(&DAT_006826e4 + spell_id * 0x5b20 + target_id * 0x120) = slot_idx;
  if (slot_idx == 0) {
    loop_idx = FUN_0047a090(spell_id,target_id,0x6d,0);
    (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
  }
  else if (slot_idx == 1) {
    uval_3 = *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120);
    *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x40000;
    Ai_CalcManaRequirement_004ba890(spell_id,0,1);
    if ((uval_3 & 0x40000) == 0) {
      *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) & 0xfffbffff;
    }
    (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    DAT_0068f0f4 = 0xffffffff;
  }
  else if (slot_idx == 2) {
    FUN_00434660(s_prompts_txt_004f9ce4,s_ASSEMBLY_WORKER_004f9cd4);
    arg_20 = &player_idx;
    uval_1 = 1;
    arg_18 = &DAT_006679f0;
    uVar11 = 0;
    uVar10 = 0;
    uVar9 = 0;
    uval_8 = 0xffffffff;
    uval_7 = 0xffffffff;
    val_6 = -1;
    val_2 = FUN_004d7d5e(0x38e);
    uval_5 = 0;
    uval_4 = 0;
    uval_3 = FUN_004521e2(spell_id,target_id);
    val_2 = Action_ValidateTarget_0041e2a2
                      (spell_id,2,spell_id,0x200,0,0,0,uval_3,uval_4,uval_5,val_2,val_6,uval_7,uval_8,
                       uVar9,uVar10,uVar11,arg_18,uval_1,arg_20);
    if (val_2 == 0) {
      DAT_00681ea4 = 1;
    }
    else {
      *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint32_t *)(&DAT_006826cc + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      FUN_0049b1eb(spell_id,0,1);
      *(int *)(&DAT_00682718 + spell_id * 0x5b20 + target_id * 0x120) = player_idx;
      *(int *)(&DAT_0068271c + spell_id * 0x5b20 + target_id * 0x120) = card_idx;
      (&DAT_006827b8)[spell_id * 0x5b20 + target_id * 0x120] = 1;
    }
    DAT_0068f0f4 = 0xffffffff;
  }
  else {
    DAT_00681ea4 = 1;
  }
  return loop_idx;
}



/*
 * Decompiled function: FUN_0047d928
 * Entry Point: 0047d928
 * Size: 192 bytes
 */


int32_t FUN_0047d928(int player_id,int card_slot,int event_type)

{
  if (((((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_00692c6c) &&
       (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00692c68)) &&
      (((&DAT_004ff594)[arg_3 * 0x34] & 4) != 0)) &&
     (*(int *)(&DAT_00618ad8 + *(int *)(&DAT_004ff590 + arg_3 * 0x34) * 0x98) != 0x6d)) {
    FUN_0046e571(arg_1,arg_2,2);
  }
  return 0;
}



/*
 * Decompiled function: FUN_0047d9e8
 * Entry Point: 0047d9e8
 * Size: 477 bytes
 */


int32_t FUN_0047d9e8(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if ((arg_3 == 0x71) && (DAT_0066aaf4 != 1)) {
    FUN_0048d00c(8);
  }
  if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0049b2c1(arg_1,6,3);
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_0068f0f4 = 6;
    }
    if (((arg_3 == 0x7f) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      if (((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0) ||
          (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) ==
           0)) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
        FUN_0049b1a9(arg_1,6,3);
      }
      *(uint32_t *)(&DAT_0068f360 + arg_1 * 4) = *(uint32_t *)(&DAT_0068f360 + arg_1 * 4) | 0x40;
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0047dbca
 * Entry Point: 0047dbca
 * Size: 339 bytes
 */


int32_t FUN_0047dbca(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 1) {
    uval_1 = FUN_0047a090(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0049b235(arg_1,0,1);
      *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint32_t *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_0068f0f4 = 0;
      DAT_00692c70 = 0;
      FUN_00467d65(FUN_0047dd22,arg_1);
      if (DAT_00692c70 == 7) {
        FUN_0049b235(arg_1,0,1);
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0047dd22
 * Entry Point: 0047dd22
 * Size: 133 bytes
 */


int32_t FUN_0047dd22(int32_t arg_1,int32_t arg_2,int event_type)

{
  int val_1;
  
  if ((&DAT_004ff595)[arg_3 * 0x34] == '\b') {
    val_1 = FUN_004d7d5e(0x21d);
    if (val_1 == arg_3) {
      DAT_00692c70 = DAT_00692c70 | 1;
    }
    val_1 = FUN_004d7d5e(0x21f);
    if (val_1 == arg_3) {
      DAT_00692c70 = DAT_00692c70 | 2;
    }
    val_1 = FUN_004d7d5e(0x220);
    if (val_1 == arg_3) {
      DAT_00692c70 = DAT_00692c70 | 4;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_0047dda7
 * Entry Point: 0047dda7
 * Size: 339 bytes
 */


int32_t FUN_0047dda7(int player_id,int card_slot,int event_type)

{
  int32_t uval_1;
  
  if (arg_3 == 1) {
    uval_1 = FUN_0047a090(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_1 * 0x5b20 + arg_2 * 0x120] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] & 2) == 0
        )))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0049b235(arg_1,0,1);
      *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint32_t *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
      DAT_0068f0f4 = 0;
      DAT_00692c70 = 0;
      FUN_00467d65(FUN_0047dd22,arg_1);
      if (DAT_00692c70 == 7) {
        FUN_0049b235(arg_1,0,2);
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: CardScript_Arena
 * Entry Point: 0047deff
 * Size: 1366 bytes
 */


int32_t CardScript_Arena(int spell_id,int target_id,int flags)

{
  int32_t uval_1;
  uint32_t uval_2;
  int *arg_20;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int val_6;
  int arg_15;
  uint32_t uval_7;
  uint32_t arg_17;
  uint32_t uval_8;
  uint8_t *arg_18;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  int target_idx;
  uint32_t player_idx [2];
  uint32_t match_count;
  uint32_t slot_idx;
  
  if (flags == 0x73) {
    if ((((&DAT_006826cc)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[target_id * 0x120 + spell_id * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + target_id * 0x120 + spell_id * 0x5b20) * 0x34] &
         2) == 0)))) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    if (flags == 0x6d) {
      if (DAT_0068f220 == 0) {
        Ai_CalcManaRequirement_004ba890(spell_id,0,3);
        if (DAT_00681ea4 != 1) {
          FUN_00434660(s_prompts_txt_004f9cf8,s_ARENA_004f9cf0);
          for (target_idx = 0; target_idx < 2; target_idx = target_idx + 1) {
            arg_20 = (int *)(((spell_id == 0) - 1 & (int)&match_count - (int)player_idx) + (int)player_idx);
            uval_2 = (uint32_t)(spell_id == target_idx);
            arg_18 = &DAT_006679f0;
            arg_17 = 0;
            uVar11 = 0;
            uVar10 = 0;
            uVar9 = 0xffffffff;
            uval_8 = 0xffffffff;
            val_6 = -1;
            val_5 = -1;
            uval_7 = 0;
            uval_4 = 0;
            uval_3 = FUN_004521e2(spell_id,target_id);
            val_5 = Action_ValidateTarget_0041e2a2
                              (spell_id,spell_id,spell_id,0x200,2,0,0,uval_3,uval_4,uval_7,val_5,val_6,
                               uval_8,uVar9,uVar10,uVar11,arg_17,arg_18,uval_2,arg_20);
            if (val_5 == 0) {
              DAT_00681ea4 = 1;
            }
          }
          if (DAT_00681ea4 != 1) {
            if (((((char)match_count == '\0') && ((slot_idx & 0xffff) == 0)) &&
                ((player_idx[0] & 0xffffff) == 0)) && (player_idx[1] == 0)) {
              *(int32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 0;
            }
            else {
              *(int32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) = 1;
            }
          }
        }
      }
      else {
        DAT_00681ea4 = 1;
      }
    }
    if (flags == 0x72) {
      match_count = *(uint32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) >> 0x18;
      slot_idx = (*(uint32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) & 0xff0000) >>
                0x10;
      player_idx[0] = (uint32_t)(uint8_t)(&DAT_006826e5)[target_id * 0x120 + spell_id * 0x5b20];
      player_idx[1] = *(uint32_t *)(&DAT_006826e4 + target_id * 0x120 + spell_id * 0x5b20) & 0xff;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      val_6 = -1;
      val_5 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = FUN_004521e2(spell_id,target_id);
      val_5 = Rules_ParseFilter_0041c0ab
                        (match_count,slot_idx,(uint8_t *)0x0,1,1,1,0x200,2,0,0,uval_2,uval_3,uval_4,val_5
                         ,val_6,uval_7,uval_8,uVar9,uVar10,uVar11);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uval_8 = 0xffffffff;
      uval_7 = 0xffffffff;
      arg_15 = -1;
      val_6 = -1;
      uval_4 = 0;
      uval_3 = 0;
      uval_2 = FUN_004521e2(spell_id,target_id);
      val_6 = Rules_ParseFilter_0041c0ab
                        (player_idx[0],player_idx[1],(uint8_t *)0x0,0,0,0,0x200,2,0,0,uval_2,uval_3,
                         uval_4,val_6,arg_15,uval_7,uval_8,uVar9,uVar10,uVar11);
      if ((val_5 == 0) || (val_6 == 0)) {
        if ((val_5 == 0) || (val_6 != 0)) {
          if (((val_5 == 0) && (val_6 != 0)) &&
             (*(uint32_t *)(&DAT_006826cc + player_idx[0] * 0x5b20 + player_idx[1] * 0x120) =
                   *(uint32_t *)(&DAT_006826cc + player_idx[0] * 0x5b20 + player_idx[1] * 0x120) | 0x10,
             *(int *)(&DAT_006826c4 + slot_idx * 0x120 + match_count * 0x5b20) != -1)) {
            val_5 = FUN_0048b81a(match_count,slot_idx,0x32,0xffffffff);
            FUN_004af950(player_idx[0],player_idx[1],val_5,match_count,slot_idx);
          }
        }
        else {
          *(uint32_t *)(&DAT_006826cc + match_count * 0x5b20 + slot_idx * 0x120) =
               *(uint32_t *)(&DAT_006826cc + match_count * 0x5b20 + slot_idx * 0x120) | 0x10;
          if (*(int *)(&DAT_006826c4 + player_idx[1] * 0x120 + player_idx[0] * 0x5b20) != -1) {
            val_5 = FUN_0048b81a(player_idx[0],player_idx[1],0x32,0xffffffff);
            FUN_004af950(match_count,slot_idx,val_5,player_idx[0],player_idx[1]);
          }
        }
      }
      else {
        *(uint32_t *)(&DAT_006826cc + match_count * 0x5b20 + slot_idx * 0x120) =
             *(uint32_t *)(&DAT_006826cc + match_count * 0x5b20 + slot_idx * 0x120) | 0x10;
        *(uint32_t *)(&DAT_006826cc + player_idx[0] * 0x5b20 + player_idx[1] * 0x120) =
             *(uint32_t *)(&DAT_006826cc + player_idx[0] * 0x5b20 + player_idx[1] * 0x120) | 0x10;
        val_5 = FUN_0048b81a(match_count,slot_idx,0x32,0xffffffff);
        val_6 = FUN_0048b81a(player_idx[0],player_idx[1],0x32,0xffffffff);
        FUN_004af950(match_count,slot_idx,val_6,player_idx[0],player_idx[1]);
        FUN_004af950(player_idx[0],player_idx[1],val_5,match_count,slot_idx);
      }
    }
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: Glue_Subsystem_004f15c0
 * Entry Point: 0047e4e0
 * Size: 709 bytes
 */


int * Glue_Subsystem_004f15c0(int player_id,char *mode_str,int event_type)

{
  size_t len_1;
  int val_2;
  uint32_t local_41c [66];
  uint32_t local_314 [65];
  uint32_t local_210 [64];
  uint32_t local_110 [64];
  int card_idx;
  int *match_count;
  int slot_idx;
  
  match_count = (int *)&DAT_005237d0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664c10);
  __splitpath(str_2,(char *)0x0,(char *)local_314,(char *)local_210,(char *)local_110);
  if (DAT_005237c4 == 0) {
    Mem_AllocOrFree_004d9630(local_41c,local_314);
    FUN_004d9640(local_41c,(uint32_t *)s_SmallArt_cat_004f9d54);
    DAT_004f9d44 = Catalog_Open((char *)local_41c);
    Mem_AllocOrFree_004d9630(local_41c,local_314);
    FUN_004d9640(local_41c,(uint32_t *)s_MedArt_cat_004f9d64);
    DAT_004f9d48 = Catalog_Open((char *)local_41c);
    DAT_005237c4 = 1;
  }
  len_1 = _strlen((char *)local_314);
  slot_idx = (int)local_314 + len_1;
  if (arg_1 == 0) {
    DAT_005dad80 = DAT_004f9d44;
  }
  else {
    if (arg_1 != 1) {
      return (int *)0x0;
    }
    DAT_005dad80 = DAT_004f9d48;
  }
  Mem_AllocOrFree_004d9630(local_314,local_210);
  FUN_004d9640(local_314,local_110);
  __strlwr((char *)local_314);
  if (match_count != (int *)0x0) {
    _memset(match_count,0,0x1b0);
    Mem_AllocOrFree_004d9630((uint32_t *)(match_count + 0x27),(uint32_t *)str_2);
    match_count[0x68] = (int)&DAT_0059e180;
    card_idx = FUN_004344c1(DAT_005dad80,local_314,match_count + 0x68);
    if (card_idx == -1) {
      FUN_004d9640((uint32_t *)str_2,(uint32_t *)&DAT_004f9d70);
      OutputDebugStringA(str_2);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664c10);
      match_count = (int *)0x0;
    }
    else {
      match_count[0x69] = card_idx + -0x9c;
      FID_conflict__memcpy(match_count,(void *)match_count[0x68],0x9c);
      match_count[0x68] = match_count[0x68] + 0x9c;
      if (match_count[10] == 4) {
        match_count[7] = match_count[7] << 1;
        match_count[8] = match_count[8] << 1;
      }
      if (arg_3 != 0) {
        val_2 = Haar_DecompressWaveletImage(match_count,(void *)0x0);
        match_count[0x6b] = val_2;
        if (match_count[0x6b] == 0) {
          FUN_0047e7a5(match_count);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664c10);
          match_count = (int *)0x0;
        }
        else {
          match_count[0x6a] = 1;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664c10);
        }
      }
    }
  }
  return match_count;
}



/*
 * Decompiled function: FUN_0047e7a5
 * Entry Point: 0047e7a5
 * Size: 46 bytes
 */


int32_t FUN_0047e7a5(void)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664c10);
  return 0;
}



