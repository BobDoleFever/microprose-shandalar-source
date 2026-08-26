/*
 * src/platform/sound_shim.c - Modern SDL2 Audio Subsystem Implementation
 * Reconstructed sound engine for MicroProse Magic: The Gathering (1997)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <SDL.h>

#include "shandalar/shandalar.h"
#include "shandalar/sound.h"

static bool g_SoundInitialized = false;

/* ==========================================================================
 * Sound Subsystem API
 * ========================================================================== */

int Sound_Init(int param_1, void* param_2, uint32_t flags)
{
    (void)param_1;
    (void)param_2;
    (void)flags;

    if (g_SoundInitialized) return 1;

    if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "[SoundShim] SDL_InitSubSystem(AUDIO) failed: %s\n", SDL_GetError());
        return 0;
    }

    g_SoundInitialized = true;
    printf("[SoundShim] Initialized modern audio subsystem (SDL2 Audio backend).\n");
    return 1;
}

void CloseSnd(void)
{
    if (!g_SoundInitialized) return;
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
    g_SoundInitialized = false;
    printf("[SoundShim] Shut down audio subsystem.\n");
}

int32_t PlaySnd(int32_t sound_id, int32_t flags)
{
    (void)flags;
    printf("[SoundShim] Playing sound ID: %u\n", (uint32_t)sound_id);
    return 1;
}

int PlaySndFile(const char* filename, int loop, int* out_handle)
{
    (void)loop;
    if (!filename) return 0;

    printf("[SoundShim] Playing sound file: %s\n", filename);
    if (out_handle) *out_handle = 1;
    return 1;
}

int32_t StopSnd(int32_t sound_id)
{
    (void)sound_id;
    return 1;
}

void PauseSnd(void) {}
int32_t ResumeSnd(int32_t param_1, int32_t param_2) { (void)param_1; (void)param_2; return 1; }
void ResetSnd(void) {}
void UpdateSnd(void) {}

int32_t SetVol(int32_t volume) { (void)volume; return 1; }
int32_t GetVol(void) { return 100; }
int32_t SetPan(int32_t pan) { (void)pan; return 0; }
int32_t GetPan(void) { return 0; }
int32_t SetPitch(int32_t pitch) { (void)pitch; return 100; }
int32_t GetPitch(void) { return 100; }

int32_t InitSndTrack(int32_t track_id, int32_t param_2, int32_t param_3) { (void)track_id; (void)param_2; (void)param_3; return 1; }
int32_t CloseSndTrack(int32_t track_id) { (void)track_id; return 1; }
int32_t StopSndTrack(void) { return 1; }
int32_t SetSndMarker(int32_t marker_id, int32_t param_2) { (void)marker_id; (void)param_2; return 1; }
int32_t PlaySndMarker(int32_t marker_id, uint32_t flags) { (void)marker_id; (void)flags; return 1; }
int32_t GetSndTime(int32_t sound_id) { (void)sound_id; return 0; }
