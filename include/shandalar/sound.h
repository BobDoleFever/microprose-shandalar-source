/*
 * shandalar/sound.h - Sound & Audio Driver API
 */
#ifndef SHANDALAR_SOUND_H
#define SHANDALAR_SOUND_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Core Audio API */
int         Sound_Init(int param_1, void* param_2, uint32_t flags);
void        CloseSnd(void);
int32_t  PlaySnd(int32_t sound_id, int32_t flags);
int         PlaySndFile(const char* filename, int loop, int* out_handle);
int32_t  StopSnd(int32_t sound_id);
void        PauseSnd(void);
int32_t  ResumeSnd(int32_t param_1, int32_t param_2);
void        ResetSnd(void);
void        UpdateSnd(void);

/* Volume & Pitch Controls */
int32_t  SetVol(int32_t volume);
int32_t  GetVol(void);
int32_t  SetPan(int32_t pan);
int32_t  GetPan(void);
int32_t  SetPitch(int32_t pitch);
int32_t  GetPitch(void);

/* Track & Markers */
int32_t  InitSndTrack(int32_t track_id, int32_t param_2, int32_t param_3);
int32_t  CloseSndTrack(int32_t track_id);
int32_t  StopSndTrack(void);
int32_t  SetSndMarker(int32_t marker_id, int32_t param_2);
int32_t  PlaySndMarker(int32_t marker_id, uint32_t flags);
int32_t  GetSndTime(int32_t sound_id);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_SOUND_H */
