#!/usr/bin/env python3
import re

def process_magic_c():
    filepath = "/Users/ben/decomp/src/magic/sid/Magic.c"
    with open(filepath, "r") as f:
        content = f.read()

    comments = {
        "Magic_ScanCards": """/*
 * Magic_ScanCards
 * Purpose: Scan all active cards on the battlefield for triggers and state changes.
 * Procedure:
 * 1. Increment the scan depth counter and check that depth is less than 10.
 * 2. Count active card slots for both players.
 * 3. Call the card script action callback for each active card.
 * 4. Update status flags and trigger pending continuous effects.
 */""",
        "Magic_TriggerCardEvent": """/*
 * Magic_TriggerCardEvent
 * Purpose: Execute a card script function with the specified event code.
 * Procedure:
 * 1. Read the card definition pointer from the master table.
 * 2. Execute the script event handler.
 * 3. Return the result code to the calling function.
 */""",
        "Magic_IsManaSource": """/*
 * Magic_IsManaSource
 * Purpose: Resolve the top spell or activated ability on the resolution stack.
 * Procedure:
 * 1. Check if the spell stack contains active entries.
 * 2. Execute the top spell effect function.
 * 3. Move the card to the graveyard or battlefield.
 * 4. Decrement the stack depth counter.
 */""",
        "Magic_PushEventContext": """/*
 * Magic_PushEventContext
 * Purpose: Save the current card-event context onto a stack (32 frames, depth in
 *   DAT_0052577c) so events can nest. Saves g_EventSourcePlayer, g_EventSourceSlot,
 *   g_EventCardId, g_EventCardColorMask, g_EventTargetPlayer, g_EventTargetSlot and g_CardEventResult.
 * Verified against the running game; the original label "pay mana cost" was wrong.
 *   See docs/SYMBOL_VERIFICATION.md.
 */""",
        "Magic_PopEventContext": """/*
 * Magic_PopEventContext
 * Purpose: Restore the card-event context saved by Magic_PushEventContext (drop one
 *   stack frame and reload the seven event globals).
 * Verified against the running game (98 pops, restoring outer contexts); the original label
 *   "tap card for mana" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */""",
        "Magic_UntapTurnPhase": """/*
 * Magic_UntapTurnPhase
 * Purpose: Execute the Untap step for the active player.
 * Procedure:
 * 1. Iterate through all cards controlled by the active player.
 * 2. Clear the STATUS_TAPPED flag on cards that can untap.
 * 3. Remove summoning sickness from creatures played on previous turns.
 */""",
        "Duel_PlaySoundById": """/*
 * Duel_PlaySoundById
 * Purpose: Play one duel sound effect by id (0x00 to 0x2f). Ids below 0x14 index the table of
 *   20 sound names (artifact, buried, draw, enchant, ... untap); higher ids use further tables.
 * Procedure:
 * 1. If the id is not loaded yet, evict a least-recently-used track and load its .wav.
 * 2. Start playback of the track.
 * Verified on the live game (called with id 2, draw.wav, from the draw function). The original
 * label "Upkeep phase" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */""",
        "Duel_PreloadSoundEffects": """/*
 * Duel_PreloadSoundEffects
 * Purpose: Preload the 20 duel sound effects (artifact, buried, draw, enchant, endphase,
 *   endturn, instant, interupt, five mana colours plus grey, lifeloss, sacrfice, sorcery,
 *   summon, tap, untap).
 * Procedure:
 * 1. Stop any sound track that is playing.
 * 2. For each of the 20 names, build the path from the duel sounds directory and register
 *    the .wav.
 * Verified on the live game: runs once when a duel starts. The original label "draw card
 * phase" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */""",
        "Magic_MainTurnPhase": """/*
 * Magic_MainTurnPhase
 * Purpose: Execute the Main phase.
 * Procedure:
 * 1. Grant priority to the active player.
 * 2. Process land drops and spell casts.
 */""",
        "Magic_PushSpellStack": """/*
 * Magic_PushSpellStack
 * Purpose: Push one card event (a spell, ability or trigger) onto the spell stack, a table of up to
 *   32 entries counted by g_SpellStackCount. Each entry packs the card id, the event code (bits 16-23)
 *   and the target slot (bits 24-31) into g_SpellStackEntries and records the owner and slot in
 *   g_SpellStackObjects. For cards with an id of 5 or more it also copies the card into a free slot as a
 *   stand-in object marked with g_StackObjectCardId.
 * Static evidence only; the original label "combat phase" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */""",
        "Magic_ResolveTopSpell": """/*
 * Magic_ResolveTopSpell
 * Purpose: Pop the top entry of the spell stack and run it: the card's own handler through
 *   Magic_TriggerCardEvent, or the in-step broadcast for event 0x7e, with extra handling for stand-in
 *   objects.
 * Static evidence only; the original label "end of turn" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */""",
        "Magic_DropTopSpell": """/*
 * Magic_DropTopSpell
 * Purpose: Pop the top entry of the spell stack without running it, clearing its stand-in card slot.
 * Static evidence only; the original label "discard to hand size" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */""",
        "Magic_CleanupPhase": """/*
 * Magic_CleanupPhase
 * Purpose: Remove temporary damage from creatures and reset until-end-of-turn effects.
 */"""
    }

    for func_name, ste_comment in comments.items():
        pattern = r"(/\*\s+\*\s+Decompiled function:\s+" + re.escape(func_name) + r"\s+\*\s+Entry Point:[^\n]+\n\s+\*\s+Size:[^\n]+\n\s+\*/)"
        replacement = ste_comment + "\n\\1"
        if re.search(pattern, content):
            content = re.sub(pattern, replacement, content, count=1)
            print(f"Added STE comment to Magic.c: {func_name}")

    with open(filepath, "w") as f:
        f.write(content)

def process_catalog_c():
    filepath = "/Users/ben/decomp/src/magic/NedCard/Catalog.c"
    with open(filepath, "r") as f:
        content = f.read()

    comments = {
        "Catalog_Open": """/*
 * Catalog_Open
 * Purpose: Open a .CAT card catalog file and read the entry table.
 * Procedure:
 * 1. Find an empty catalog slot in the global catalog array (max 5 open).
 * 2. Open the file in binary read mode.
 * 3. Read the total entry count from the header.
 * 4. Allocate memory for the entry array and read all file descriptors.
 * Returns: A catalog handle index (1 to 5), or 0 on error.
 */""",
        "Catalog_Close": """/*
 * Catalog_Close
 * Purpose: Close an open catalog file and free its memory buffers.
 * Procedure:
 * 1. Free the allocated catalog entry array.
 * 2. Close the stdio file handle.
 * 3. Clear the catalog slot descriptor.
 * Returns: True on success, or false on error.
 */""",
        "Catalog_CompareEntryHash": """/*
 * Catalog_CompareEntryHash
 * Purpose: Compare two 32-bit hash keys for binary search sorting.
 * Returns: -1 if a < b, 1 if a > b, or 0 if a == b.
 */""",
        "Catalog_FindEntry": """/*
 * Catalog_FindEntry
 * Purpose: Search for a file entry inside a catalog using binary search.
 * Procedure:
 * 1. Calculate the 32-bit hash value of the target filename.
 * 2. Check the cached entry pointer for a rapid match.
 * 3. Execute bsearch over the sorted catalog entry array.
 * Returns: Pointer to the CatalogEntry if found, or NULL if not found.
 */""",
        "Catalog_ReadFile": """/*
 * Catalog_ReadFile
 * Purpose: Read file contents from a catalog archive into memory.
 * Procedure:
 * 1. Locate the file entry with Catalog_FindEntry.
 * 2. Allocate output memory buffer if necessary.
 * 3. Seek to the file offset in the archive.
 * 4. Read the uncompressed bytes into the destination buffer.
 * Returns: Total byte count read, or -1 on failure.
 */""",
        "Catalog_ComputeFilenameHash": """/*
 * Catalog_ComputeFilenameHash
 * Purpose: Calculate a 32-bit hash value from a file path string.
 * Uses Ned Way's dual-multiplier polynomial hash algorithm.
 */""",
        "ColorOctree_AllocNode": """/*
 * ColorOctree_AllocNode
 * Purpose: Allocate and clear a new 8-child color octree node.
 */""",
        "Catalog_LoadPaletteMap": """/*
 * Catalog_LoadPaletteMap
 * Purpose: Load a palette mapping CSV file and build color octree clusters.
 */""",
        "Palette_InitSquareDistanceTable": """/*
 * Palette_InitSquareDistanceTable
 * Purpose: Initialize the square-difference lookup table for Euclidean RGB distance.
 */""",
        "ColorOctree_CollectLeaves": """/*
 * ColorOctree_CollectLeaves
 * Purpose: Traverse an octree node and collect all child leaf color indices.
 */""",
        "ColorOctree_BuildClusters": """/*
 * ColorOctree_BuildClusters
 * Purpose: Build color clusters in the octree to reduce 24-bit RGB colors to 8-bit palette.
 */""",
        "ColorOctree_InsertColor": """/*
 * ColorOctree_InsertColor
 * Purpose: Insert a 24-bit RGB color into the color octree at the specified depth.
 */""",
        "ColorOctree_FreeTree": """/*
 * ColorOctree_FreeTree
 * Purpose: Recursively free all nodes and cluster buffers in a color octree.
 */""",
        "Color_QuantizeRGBToPalette": """/*
 * Color_QuantizeRGBToPalette
 * Purpose: Convert a 24-bit RGB color to the best matching palette entry.
 */""",
        "Palette_BuildFastColorLookup": """/*
 * Palette_BuildFastColorLookup
 * Purpose: Generate precomputed lookup tables for rapid color quantization.
 */""",
        "Color_FindNearestRGB": """/*
 * Color_FindNearestRGB
 * Purpose: Find the closest matching RGB color in the palette.
 */""",
        "Color_FindNearestPaletteIndex": """/*
 * Color_FindNearestPaletteIndex
 * Purpose: Find the 8-bit palette index for a given 24-bit RGB color.
 */""",
        "Palette_RemapBitmapRGB": """/*
 * Palette_RemapBitmapRGB
 * Purpose: Remap a 24-bit RGB bitmap into an 8-bit paletted image buffer.
 */""",
        "Palette_DitherBitmapRGB": """/*
 * Palette_DitherBitmapRGB
 * Purpose: Apply Floyd-Steinberg error diffusion dithering across image scanlines.
 * Procedure:
 * 1. Read source 24-bit RGB pixels along the scanline.
 * 2. Add accumulated quantization error from neighbor pixels.
 * 3. Find closest matching palette color.
 * 4. Compute quantization error (source - matched).
 * 5. Distribute error fractions to neighboring and next-row pixels.
 * 6. Reverse scan direction if serpentine dithering is enabled.
 */"""
    }

    for func_name, ste_comment in comments.items():
        pattern = r"(/\*\s+\*\s+Decompiled function:\s+" + re.escape(func_name) + r"\s+\*\s+Entry Point:[^\n]+\n\s+\*\s+Size:[^\n]+\n\s+\*/)"
        replacement = ste_comment + "\n\\1"
        if re.search(pattern, content):
            content = re.sub(pattern, replacement, content, count=1)
            print(f"Added STE comment to Catalog.c: {func_name}")

    with open(filepath, "w") as f:
        f.write(content)

if __name__ == "__main__":
    process_magic_c()
    process_catalog_c()
