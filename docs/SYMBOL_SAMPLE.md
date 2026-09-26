# How reliable are the semantic names? A 30-function sample

Question: of the functions that carry a meaningful-looking name in `MAGIC.EXE`, how many does the
code actually support? This is a **static** triage (reading the decompiled body, its strings, its
Win32 calls and its callees; `tools/verification_harness/label_digest.py` prints that digest). Only
the three functions in [SYMBOL_VERIFICATION.md](SYMBOL_VERIFICATION.md) were confirmed on the live
game, and they are excluded from the sample.

## Population

Of the 1,924 functions in `MAGIC.EXE`:

| Kind of name | Count |
|---|---|
| raw `FUN_<address>` (never renamed) | 581 |
| generic placeholder such as `Pic_Subsystem_<address>` | 983 |
| semantic-looking name (`Card_...`, `Ai_...`, `Sprite_...`) | 360 |

So the README's "1,650+ functions refactored" counts placeholders. Only 360 have a name that
claims to say what the function does. Sample: 30 drawn at random (seed 20260926) from the 316 of
those with a body of at least 60 bytes and not already verified.

## Results

Verdicts: **wrong** = the body contradicts the name; **misleading** = related but the name says
something the code does not do; **unsupported** = nothing in the code confirms the specific name,
and there are contradicting hints; **supported** = the name fits strong evidence (a string from the
game's own text, a matching API, a matching structure).

| Function | Verdict | Evidence |
|---|---|---|
| `Ai_EvaluateCreaturePower` `0x004ab28b` | wrong | Appends the current candidate (id, card id, score) to a 256-entry list; evaluates no power |
| `Magic_CombatPhase` `0x004751d7` | wrong | Queues an event (card id, event, slot) and clones a 0x120-byte card slot into a free slot; no combat logic |
| `SpellChain_UpdateTargetPositions` `0x004cf965` | wrong | Removes entry `y` from a table of 0x58-byte records, destroys its child windows, shifts the rest down |
| `Adventure_Audio_StopEffectChannel` `0x004ebe1a` | wrong (static) | Builds a volume/22050 Hz/pan struct and calls the play-sound function, the same callee the verified sound player uses to play |
| `Color_QuantizeRGBToPalette` `0x00494310` | misleading | Splits RGB into bytes, looks each up in a table and ORs them into a 64-bit key (octree path); returns no palette index |
| `Surface_GetPixelPtr` `0x0050da40` | misleading | Returns a pixel/palette index (GDI `GetPixel` plus a 256-entry palette search, or a byte read), never a pointer |
| `Card_IslandSanctuary_CheckActive` `0x004d328c` | unsupported | Event-code handler; calls the event dispatcher (`Card_TapForMana`, now `Magic_DispatchCardEvent`) and sets a "cancel" flag named `g_ActivePalette` |
| `Card_ClockworkBeast_ResetCounters` `0x004d683f` | unsupported | Calls `Card_RockHydra_UpdateStatsFromHeads`; several event codes; no counter reset visible |
| `Card_GenericCreature_CanRegenerate` `0x004d7e90` | unsupported | Scans both players for a tapped card matching two values; nothing about regeneration |
| `Card_PsionicEntity_EvaluateTarget` `0x004e0e60` | unsupported | Event-code branches on colour checks; no damage or self-damage logic |
| `Card_DragonWhelp_EndTurnCheck` `0x004d5c1e` | unsupported | Calls font drawing and life-advantage helpers; nothing card-specific |
| `Catalog_LoadPaletteMap` `0x00493e70` | supported | `fopen`/`fgets`/`sscanf` feeding `ColorOctree_*` and palette lookup tables |
| `Color_FindNearestPaletteIndex` `0x00494540` | supported | Uses the RGB key function and searches for the nearest entry (weak) |
| `SpellChain_UpdateLayout` `0x004cffda` | supported | `MoveWindow`, `AdjustWindowRect`, `GetWindowRect`, `ShowWindow` |
| `SpellChain_IsVisible` `0x004d0965` | supported | `IsWindowVisible` |
| `Card_AliFromCairo_PreventLethalDamage` `0x004d4762` | supported | Strings `ALI_FROM_CAIRO`, "Illegal target, prevent damage" |
| `Card_LivingWall_Regenerate` `0x004d7bb5` | supported | String "Regenerate Living Wall?" |
| `Card_RoyalAssassin_DestroyTapped` `0x004da858` | supported | `ROYAL_ASSASSIN` prompt, creature targeting |
| `Card_KingSuleiman_DestroyDjinn` `0x004dac11` | supported | `KING_SULEIMAN` prompt, creature targeting |
| `Card_BrothersOfFire_EvaluateTarget` `0x004df20c` | supported | Calls the direct-damage evaluators |
| `Card_PirateShip_HasIsland` `0x004dff88` | supported | Checks a per-player land-type count at index 2 and cancels the attack if the opponent has none (its callee `Card_UntapCard` is mislabelled: it returns a table index) |
| `Card_CosmicHorror_PayUpkeep` `0x004e268e` | supported | String "Cosmic Horror deals 7 damage" |
| `Card_Venom_DestroyCombatBlocker` `0x004e4807` | supported | `VENOM` prompt and filter |
| `CardTarget_HasValidPermanentTarget` `0x004e701f` | supported | Validates a target and plays the error sound |
| `Adventure_Audio_PlayFootstep` `0x004ec32f` | supported | Table of `*walkl/r.wav` names (the same walking sounds seen loading at startup) |
| `Adventure_PromptConfirmDialog` `0x004ecee0` | supported | "Yes, I'm sure" string, popup menu APIs |
| `Duel_GetHoveredCardSlot` `0x004ef970` | supported | Window-data lookup by hover target (weak) |
| `WinMain` `0x00500e80` | supported | `RegisterClassA`, `CreateWindowExA`, `timeSetEvent`, class name strings |
| `Sprite_LoadAll` `0x0050fcc0` | supported | "Could not open Sprite File %s", `fopen`/`fread` |
| `Sprite_DrawScaled` `0x00510650` | supported | Scanline and pixel put calls (weak) |

## Numbers

| | Sample | 95% interval | Scaled to the 316 |
|---|---|---|---|
| wrong or misleading | 6 / 30 = 20% | 10% to 37% | about 63 (30 to 118) |
| plus unsupported | 11 / 30 = 37% | 22% to 54% | about 116 (69 to 172) |
| supported | 19 / 30 = 63% | 46% to 78% | about 200 (144 to 247) |

With 30 samples the intervals are wide, and "supported" is a weak word: most of those rest on a
string or an API name, not on behaviour observed in the running game. Treat 63% as an upper bound.
Names that come from a game string (a card's `prompts.txt` key) are the most reliable; names for
generic engine code are the least.

## Systematic problems the sample exposed

1. **Global variable names were wrong in the card scripts (now fixed).** `g_OverworldMapGrid` and
   `g_OverworldPlayerCoordX` are used as the *card slot* and *player* index (multiplied by the
   card-slot strides `0x120` and `0x5b20`). They appear in 90 of the 178 `Card*`-named functions, and in 76
   functions with those strides. `g_ActivePalette` is used as an event result or "cancel" flag in
   61 of them. The card handlers read as nonsense with these names. They are now
   `g_EventSourceSlot`, `g_EventSourcePlayer` and `g_CardEventResult` (see
   [SYMBOL_VERIFICATION.md](SYMBOL_VERIFICATION.md)). `g_PlayerManaPool` looks like the current event
   code (assigned constants such as `0xda` and `-1`, compared with event codes) and is still misnamed.
2. **Callees inside plausible functions are mislabelled.** `Card_UntapCard` returns a table index,
   `Card_TapForMana` (now `Magic_DispatchCardEvent`) is the card-event dispatcher and has nothing to do
   with mana, and `Card_RockHydra_UpdateStatsFromHeads` is called from a Clockwork Beast handler.
3. **A later renaming pass made some names worse.** In `unified_engine_symbol_map.csv`, 92 rows have
   an earlier non-`FUN_` name, and in 76 of them a later pass replaced it. I first reported all 76
   as good names lost to generic ones; checking each against its code showed that was too strong.
   Only **30** were good names replaced by worse ones, and they are restored: 27 sound-driver
   thunks (`Sound_Init`, `InitSndTrack`, `PlaySnd`, `SetVol`, ... had become `Pic_Subsystem_*`),
   `CardTypeFromID`, `CardIDFromType` and `UI_Register_WINBK_ManaPool_004b9120`. The other 46 rows
   swap one address-suffixed placeholder for another; the code supports neither name, or the current
   one is better (dialog procedures that call `EndDialog` and never `DefWindowProc` are dialog
   procedures, not window procedures), so they are left alone.
4. **The `DUEL.EXE` names are not extra evidence.** The executables contain no symbol table and none
   of these names as strings. The `DUEL.EXE` names came from a script that copies names between
   binaries when functions look alike (`scripts/build_duel_symbol_sync.py`).

## What this means

- Roughly one in five of the meaningful-looking names is wrong or misleading, and about one in
  three is not supported by its code. Never rely on a name in this repo without checking the body.
- Names from the game's own strings, real Win32 APIs, and the earlier (pre-generic) sound names
  are the trustworthy layer.
- The two highest-value fixes from this sample are done: the three globals are renamed and the 30
  overwritten names are restored. Still open: `g_PlayerManaPool`, the mislabelled callees, and the
  ~200 names that are only weakly supported.

## Method

`python3 tools/verification_harness/label_digest.py magic <sample.json>` prints strings, API calls
and callees per function. Bodies were read for the ones the digest could not settle. Nothing here
was run in the emulator except the three functions in `SYMBOL_VERIFICATION.md`.
