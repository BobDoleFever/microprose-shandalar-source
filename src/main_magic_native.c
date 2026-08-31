#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shandalar/magic_native_runtime.h"


static int FileExists(const char *path)
{
    return path != NULL && access(path, R_OK) == 0;
}


int main(int argc, char **argv)
{
    const char *asset_directory = getenv("SHANDALAR_DATA_DIR");
    const char *image_path = "build/generated/magic_image.bin";
    const char *command_line = "/MTGshell /6";

    for (int index = 1; index < argc; ++index) {
        if (strcmp(argv[index], "--dir") == 0 && index + 1 < argc) {
            asset_directory = argv[++index];
        } else if (strcmp(argv[index], "--image") == 0 && index + 1 < argc) {
            image_path = argv[++index];
        } else if (strcmp(argv[index], "--cmd") == 0 && index + 1 < argc) {
            command_line = argv[++index];
        }
    }

    if (asset_directory == NULL && FileExists("ADVINTER.pic")) {
        asset_directory = ".";
    }
    if (asset_directory == NULL &&
        FileExists("/Users/ben/Downloads/shand-extract/program/ADVINTER.pic")) {
        asset_directory = "/Users/ben/Downloads/shand-extract/program";
    }
    if (asset_directory == NULL) {
        fprintf(stderr,
                "Set SHANDALAR_DATA_DIR or use --dir to select the game data directory.\n");
        return 2;
    }
    if (MagicNative_LoadImage(image_path) != 0) {
        return 2;
    }
    MagicNative_SetArguments(argc, argv);
    if (chdir(asset_directory) != 0) {
        perror(asset_directory);
        MagicNative_Shutdown();
        return 2;
    }

    printf("Starting the recovered MAGIC.EXE adventure game.\n");
    int result = MagicNative_Run(command_line);
    MagicNative_Shutdown();
    return result;
}
