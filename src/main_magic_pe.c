#include <stdio.h>
#include <string.h>

#include "shandalar/magic_pe_runtime.h"


int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous_instance,
                   LPSTR command_line, int show_state)
{
    (void)previous_instance;
    char default_command[] = "/MTGshell /6";
    LPSTR recovered_command = command_line;
    if (recovered_command == NULL || recovered_command[0] == '\0') {
        recovered_command = default_command;
    }

    if (MagicPe_Initialize(instance) != 0) {
        return 2;
    }
    if (MagicPe_EnterDataDirectory() != 0) {
        MagicPe_Shutdown();
        return 2;
    }

    fprintf(stderr, "MAGIC PE: starting recovered adventure game.\n");
    int result = MagicPe_RunRecoveredWinMain(recovered_command, show_state);
    MagicPe_Shutdown();
    return result;
}
