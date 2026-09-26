/*
 * src/main_game_entry.c - Full Game Authentic Entry Point Runner
 * Boots MicroProse Magic: The Gathering (Shandalar 1997) via its original WinMain!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/display_shim.h"

/* Forward declaration of the original game WinMain from sid/Test.c */
extern int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
extern void SetProgramArgv(char **argv);

int main(int argc, char *argv[])
{
    printf("=========================================================\n");
    printf(" MicroProse Magic: The Gathering (Shandalar 1997)\n");
    printf(" Launching Game From Original WinMain Entry Point\n");
    printf("=========================================================\n");

    /* Directory holding the original game files (ICONS.SPR, *.PIC, ...). Override with
     * --dir or the SHANDALAR_PROGRAM_DIR environment variable. */
    const char *program_dir = getenv("SHANDALAR_PROGRAM_DIR");
    if (program_dir == NULL || program_dir[0] == '\0') {
        program_dir = "sources/installed/Magic/Program";
    }
    char cmd_line[512] = "/MTGshell /6"; /* 640x480 resolution mode */

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--dir") == 0 && i + 1 < argc) {
            program_dir = argv[++i];
        } else if (strcmp(argv[i], "--cmd") == 0 && i + 1 < argc) {
            strncpy(cmd_line, argv[++i], sizeof(cmd_line) - 1);
        } else {
            strncat(cmd_line, " ", sizeof(cmd_line) - strlen(cmd_line) - 1);
            strncat(cmd_line, argv[i], sizeof(cmd_line) - strlen(cmd_line) - 1);
        }
    }

    /* Change working directory to the game asset directory */
    printf("[Entry] Setting game working directory: %s\n", program_dir);
    if (chdir(program_dir) != 0) {
        fprintf(stderr, "[Entry] Warning: Could not change directory to %s\n", program_dir);
    }

    SetProgramArgv(argv);

    HINSTANCE hInstance = (HINSTANCE)(uintptr_t)1;
    HINSTANCE hPrevInstance = (HINSTANCE)0;
    int nCmdShow = 1;

    printf("[Entry] Invoking authentic WinMain(hInstance, hPrevInstance, \"%s\", %d)...\n",
           cmd_line, nCmdShow);

    /* Direct call to the authentic MicroProse WinMain function */
    int result = WinMain(hInstance, hPrevInstance, cmd_line, nCmdShow);

    printf("=========================================================\n");
    printf(" Game WinMain exited with return code: %d\n", result);
    printf("=========================================================\n");

    return result;
}
