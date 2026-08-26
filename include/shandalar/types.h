/*
 * shandalar/types.h - Standard ANSI C Win32 & Engine Type Definitions
 */
#ifndef SHANDALAR_TYPES_H
#define SHANDALAR_TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "../windows_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Game Constants */
#define MAX_CARDS_IN_DECK     60
#define MAX_PLAYERS           2
#define MAX_HAND_SIZE         7
#define MAX_COLORS            5

/* Game Primitives */
typedef uint16_t CardID;
typedef uint8_t  PlayerID;
typedef uint8_t  ColorID;

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_TYPES_H */
