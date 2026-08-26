/*
 * Decompiled function: thunk_FUN_1002d55f
 * Entry Point: 100016e5
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1002d55f(HWND hwnd,int32_t arg_2,uint32_t arg_3)

{
  uint32_t uval_1;
  BOOL BVar2;
  int val_3;
  int32_t uval_4;
  tagRECT tStack_24;
  tagRECT tStack_14;
  
  uval_1 = arg_3 >> 0x10;
  GetClientRect(hwnd,&tStack_24);
  thunk_FUN_1002c0c7(&tStack_24.left,0xe,&tStack_14);
  BVar2 = PtInRect(&tStack_14,(POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
  if (BVar2 == 0) {
    thunk_FUN_1002c0c7(&tStack_24.left,0x12,&tStack_14);
    BVar2 = PtInRect(&tStack_14,(POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
    if (BVar2 == 0) {
      thunk_FUN_1002c0c7(&tStack_24.left,0x11,&tStack_14);
      BVar2 = PtInRect(&tStack_14,(POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
      if (BVar2 == 0) {
        thunk_FUN_1002c0c7(&tStack_24.left,0x10,&tStack_14);
        BVar2 = PtInRect(&tStack_14,(POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
        if (BVar2 == 0) {
          thunk_FUN_1002c0c7(&tStack_24.left,0xf,&tStack_14);
          BVar2 = PtInRect(&tStack_14,(POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
          if (BVar2 == 0) {
            thunk_FUN_1002c0c7(&tStack_24.left,0xb,&tStack_14);
            BVar2 = PtInRect(&tStack_14,(POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
            if (BVar2 == 0) {
              thunk_FUN_1002c0c7(&tStack_24.left,5,&tStack_14);
              BVar2 = PtInRect(&tStack_14,(POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
              if (BVar2 == 0) {
                thunk_FUN_1002c0c7(&tStack_24.left,10,&tStack_14);
                BVar2 = PtInRect(&tStack_14,(POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
                if (BVar2 == 0) {
                  thunk_FUN_1002c0c7(&tStack_24.left,7,&tStack_14);
                  BVar2 = PtInRect(&tStack_14,(POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
                  if (BVar2 == 0) {
                    thunk_FUN_1002c0c7(&tStack_24.left,0xc,&tStack_14);
                    BVar2 = PtInRect(&tStack_14,(POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff))
                    ;
                    if (BVar2 == 0) {
                      thunk_FUN_1002c0c7(&tStack_24.left,0x15,&tStack_14);
                      BVar2 = PtInRect(&tStack_14,
                                       (POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
                      if (BVar2 == 0) {
                        thunk_FUN_1002c0c7(&tStack_24.left,0x16,&tStack_14);
                        BVar2 = PtInRect(&tStack_14,
                                         (POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
                        if (BVar2 == 0) {
                          thunk_FUN_1002c0c7(&tStack_24.left,0x17,&tStack_14);
                          BVar2 = PtInRect(&tStack_14,
                                           (POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
                          if (BVar2 == 0) {
                            thunk_FUN_1002c0c7(&tStack_24.left,0x18,&tStack_14);
                            BVar2 = PtInRect(&tStack_14,
                                             (POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
                            if (BVar2 == 0) {
                              thunk_FUN_1002c0c7(&tStack_24.left,0x19,&tStack_14);
                              BVar2 = PtInRect(&tStack_14,
                                               (POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff));
                              if (BVar2 == 0) {
                                thunk_FUN_1002c0c7(&tStack_24.left,0x1a,&tStack_14);
                                BVar2 = PtInRect(&tStack_14,
                                                 (POINT)(CONCAT44(uval_1,arg_3) & 0xffffffff0000ffff)
                                                );
                                if (BVar2 == 0) {
                                  thunk_FUN_1002c0c7(&tStack_24.left,0x1b,&tStack_14);
                                  BVar2 = PtInRect(&tStack_14,
                                                   (POINT)(CONCAT44(uval_1,arg_3) &
                                                          0xffffffff0000ffff));
                                  if (BVar2 == 0) {
                                    thunk_FUN_1002c0c7(&tStack_24.left,0x1d,&tStack_14);
                                    BVar2 = PtInRect(&tStack_14,
                                                     (POINT)(CONCAT44(uval_1,arg_3) &
                                                            0xffffffff0000ffff));
                                    if (BVar2 == 0) {
                                      thunk_FUN_1002c0c7(&tStack_24.left,0x1e,&tStack_14);
                                      BVar2 = PtInRect(&tStack_14,
                                                       (POINT)(CONCAT44(uval_1,arg_3) &
                                                              0xffffffff0000ffff));
                                      if (BVar2 == 0) {
                                        thunk_FUN_1002c0c7(&tStack_24.left,0x1f,&tStack_14);
                                        BVar2 = PtInRect(&tStack_14,
                                                         (POINT)(CONCAT44(uval_1,arg_3) &
                                                                0xffffffff0000ffff));
                                        if (BVar2 == 0) {
                                          thunk_FUN_1002c0c7(&tStack_24.left,0x20,&tStack_14);
                                          BVar2 = PtInRect(&tStack_14,
                                                           (POINT)(CONCAT44(uval_1,arg_3) &
                                                                  0xffffffff0000ffff));
                                          if (BVar2 == 0) {
                                            thunk_FUN_1002c0c7(&tStack_24.left,0x21,&tStack_14);
                                            BVar2 = PtInRect(&tStack_14,
                                                             (POINT)(CONCAT44(uval_1,arg_3) &
                                                                    0xffffffff0000ffff));
                                            if (BVar2 == 0) {
                                              thunk_FUN_1002c0c7(&tStack_24.left,0x22,&tStack_14);
                                              BVar2 = PtInRect(&tStack_14,
                                                               (POINT)(CONCAT44(uval_1,arg_3) &
                                                                      0xffffffff0000ffff));
                                              if (BVar2 == 0) {
                                                uval_4 = 0;
                                              }
                                              else {
                                                val_3 = thunk_FUN_10034b40(s_cuecards_1004632c,
                                                                           s_ARTIST_10046324);
                                                if (val_3 == -1) {
                                                  uval_4 = 0;
                                                }
                                                else if ((DAT_101cf803 & 1) == 0) {
                                                  uval_4 = 2;
                                                }
                                                else {
                                                  uval_4 = 1;
                                                }
                                              }
                                            }
                                            else {
                                              val_3 = thunk_FUN_10034b40(s_cuecards_10046318,
                                                                         s_RARITY_10046310);
                                              if (val_3 == -1) {
                                                uval_4 = 0;
                                              }
                                              else if ((DAT_101cf802 & 1) == 0) {
                                                uval_4 = 2;
                                              }
                                              else {
                                                uval_4 = 1;
                                              }
                                            }
                                          }
                                          else {
                                            val_3 = thunk_FUN_10034b40(s_cuecards_10046304,
                                                                       s_ABILITY_100462fc);
                                            if (val_3 == -1) {
                                              uval_4 = 0;
                                            }
                                            else if ((DAT_101cf800 & 1) == 0) {
                                              uval_4 = 2;
                                            }
                                            else {
                                              uval_4 = 1;
                                            }
                                          }
                                        }
                                        else {
                                          val_3 = thunk_FUN_10034b40(s_cuecards_100462f0,
                                                                     s_TOUGHNESS_100462e4);
                                          if (val_3 == -1) {
                                            uval_4 = 0;
                                          }
                                          else if ((DAT_101cf7fc & 1) == 0) {
                                            uval_4 = 2;
                                          }
                                          else {
                                            uval_4 = 1;
                                          }
                                        }
                                      }
                                      else {
                                        val_3 = thunk_FUN_10034b40(s_cuecards_100462d8,
                                                                   s_POWER_100462d0);
                                        if (val_3 == -1) {
                                          uval_4 = 0;
                                        }
                                        else if ((DAT_101cf7f8 & 1) == 0) {
                                          uval_4 = 2;
                                        }
                                        else {
                                          uval_4 = 1;
                                        }
                                      }
                                    }
                                    else {
                                      val_3 = thunk_FUN_10034b40(s_cuecards_100462c4,
                                                                 s_CASTCOST_100462b8);
                                      if (val_3 == -1) {
                                        uval_4 = 0;
                                      }
                                      else if ((DAT_101cf7f4 & 1) == 0) {
                                        uval_4 = 2;
                                      }
                                      else {
                                        uval_4 = 1;
                                      }
                                    }
                                  }
                                  else {
                                    val_3 = thunk_FUN_10034b40(s_cuecards_100462ac,
                                                               s_SORCERY_100462a4);
                                    if (val_3 == -1) {
                                      uval_4 = 0;
                                    }
                                    else if ((DAT_101cf7d4._2_1_ & 0x20) == 0) {
                                      uval_4 = 2;
                                    }
                                    else {
                                      uval_4 = 1;
                                    }
                                  }
                                }
                                else {
                                  val_3 = thunk_FUN_10034b40(s_cuecards_10046298,
                                                             s_INTERRUPT_1004628c);
                                  if (val_3 == -1) {
                                    uval_4 = 0;
                                  }
                                  else if ((DAT_101cf7d4._2_1_ & 0x10) == 0) {
                                    uval_4 = 2;
                                  }
                                  else {
                                    uval_4 = 1;
                                  }
                                }
                              }
                              else {
                                val_3 = thunk_FUN_10034b40(s_cuecards_10046280,s_INSTANT_10046278);
                                if (val_3 == -1) {
                                  uval_4 = 0;
                                }
                                else if ((DAT_101cf7d4._2_1_ & 8) == 0) {
                                  uval_4 = 2;
                                }
                                else {
                                  uval_4 = 1;
                                }
                              }
                            }
                            else {
                              val_3 = thunk_FUN_10034b40(s_cuecards_1004626c,s_ENCHANTMENT_10046260)
                              ;
                              if (val_3 == -1) {
                                uval_4 = 0;
                              }
                              else if ((DAT_101cf7d4._1_1_ & 0x10) == 0) {
                                uval_4 = 2;
                              }
                              else {
                                uval_4 = 1;
                              }
                            }
                          }
                          else {
                            val_3 = thunk_FUN_10034b40(s_cuecards_10046254,s_CREATURE_10046248);
                            if (val_3 == -1) {
                              uval_4 = 0;
                            }
                            else if (((uint8_t)DAT_101cf7d4 & 0x80) == 0) {
                              uval_4 = 2;
                            }
                            else {
                              uval_4 = 1;
                            }
                          }
                        }
                        else {
                          val_3 = thunk_FUN_10034b40(s_cuecards_1004623c,s_ARTIFACT_10046230);
                          if (val_3 == -1) {
                            uval_4 = 0;
                          }
                          else if (((uint8_t)DAT_101cf7d4 & 0x10) == 0) {
                            uval_4 = 2;
                          }
                          else {
                            uval_4 = 1;
                          }
                        }
                      }
                      else {
                        val_3 = thunk_FUN_10034b40(s_cuecards_10046224,&DAT_1004621c);
                        if (val_3 == -1) {
                          uval_4 = 0;
                        }
                        else if (((uint8_t)DAT_101cf7d4 & 1) == 0) {
                          uval_4 = 2;
                        }
                        else {
                          uval_4 = 1;
                        }
                      }
                    }
                    else {
                      val_3 = thunk_FUN_10034b40(s_cuecards_10046210,s_RESTRICTED_10046204);
                      if (val_3 == -1) {
                        uval_4 = 0;
                      }
                      else if ((DAT_101cf7d2 & 0x400) == 0) {
                        uval_4 = 2;
                      }
                      else {
                        uval_4 = 1;
                      }
                    }
                  }
                  else {
                    val_3 = thunk_FUN_10034b40(s_cuecards_100461f8,s_PROMO_100461f0);
                    if (val_3 == -1) {
                      uval_4 = 0;
                    }
                    else if ((DAT_101cf7d2 & 0x200) == 0) {
                      uval_4 = 2;
                    }
                    else {
                      uval_4 = 1;
                    }
                  }
                }
                else {
                  val_3 = thunk_FUN_10034b40(s_cuecards_100461e4,s_FOURTH_100461dc);
                  if (val_3 == -1) {
                    uval_4 = 0;
                  }
                  else if ((DAT_101cf7d2 & 2) == 0) {
                    uval_4 = 2;
                  }
                  else {
                    uval_4 = 1;
                  }
                }
              }
              else {
                val_3 = thunk_FUN_10034b40(s_cuecards_100461d0,s_LEGENDS_100461c8);
                if (val_3 == -1) {
                  uval_4 = 0;
                }
                else if ((DAT_101cf7d2 & 0x80) == 0) {
                  uval_4 = 2;
                }
                else {
                  uval_4 = 1;
                }
              }
            }
            else {
              val_3 = thunk_FUN_10034b40(s_cuecards_100461bc,s_ASTRAL_100461b4);
              if (val_3 == -1) {
                uval_4 = 0;
              }
              else if ((DAT_101cf7d2 & 4) == 0) {
                uval_4 = 2;
              }
              else {
                uval_4 = 1;
              }
            }
          }
          else {
            val_3 = thunk_FUN_10034b40(s_cuecards_100461a8,&DAT_100461a0);
            if (val_3 == -1) {
              uval_4 = 0;
            }
            else if ((DAT_101cf7d0 & 0x20) == 0) {
              uval_4 = 2;
            }
            else {
              uval_4 = 1;
            }
          }
        }
        else {
          val_3 = thunk_FUN_10034b40(s_cuecards_10046194,s_BLACK_1004618c);
          if (val_3 == -1) {
            uval_4 = 0;
          }
          else if ((DAT_101cf7d0 & 0x10) == 0) {
            uval_4 = 2;
          }
          else {
            uval_4 = 1;
          }
        }
      }
      else {
        val_3 = thunk_FUN_10034b40(s_cuecards_10046180,&DAT_1004617c);
        if (val_3 == -1) {
          uval_4 = 0;
        }
        else if ((DAT_101cf7d0 & 8) == 0) {
          uval_4 = 2;
        }
        else {
          uval_4 = 1;
        }
      }
    }
    else {
      val_3 = thunk_FUN_10034b40(s_cuecards_10046170,s_GREEN_10046168);
      if (val_3 == -1) {
        uval_4 = 0;
      }
      else if ((DAT_101cf7d0 & 4) == 0) {
        uval_4 = 2;
      }
      else {
        uval_4 = 1;
      }
    }
  }
  else {
    val_3 = thunk_FUN_10034b40(s_cuecards_1004615c,s_WHITE_10046154);
    if (val_3 == -1) {
      uval_4 = 0;
    }
    else if ((DAT_101cf7d0 & 2) == 0) {
      uval_4 = 2;
    }
    else {
      uval_4 = 1;
    }
  }
  return uval_4;
}


