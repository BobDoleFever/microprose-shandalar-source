/*
 * engine.c - calls out of native code, and the table of native functions.
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "engine.h"

static const char *const CALLEE_NAMES[CALLEE_COUNT] = {
    [CALLEE_SCAN_CARDS] = "Magic_ScanCards",
    [CALLEE_IS_TAPPED] = "Card_IsTapped",
    [CALLEE_COLOR_OVERRIDE_FF] = "Card_UntapCard (colour override +0xff)",
    [CALLEE_COLOR_OVERRIDE_F9] = "Card_SetTapState (colour override +0xf9)",
    [CALLEE_COLOR_MASK_TO_INDEX] = "Card_ColorMaskToColorIndex",
    [CALLEE_MARK_CARD] = "Pic_Subsystem_0044867e",
    [CALLEE_AFTER_MARK] = "Pic_Subsystem_004488a0",
    [CALLEE_FIND_FREE_SLOT] = "Pic_Subsystem_00451291 (find free slot)",
    [CALLEE_PUSH_EVENT_CONTEXT] = "Magic_PushEventContext",
    [CALLEE_POP_EVENT_CONTEXT] = "Magic_PopEventContext",
};

const char *callee_name(Callee c)
{
    return (unsigned)c < CALLEE_COUNT ? CALLEE_NAMES[c] : "?";
}

uint32_t vm_call(Vm *vm, Callee callee, int nargs, const uint32_t *args)
{
    if (!vm->call) {
        fprintf(stderr, "native: call to %s with no call hook\n", callee_name(callee));
        abort();
    }
    return vm->call(vm->call_ctx, callee, vm->L->callee[callee], nargs, args);
}

void native_unimplemented(const char *what, const char *file, int line)
{
    fprintf(stderr, "native: unimplemented: %s (%s:%d)\n", what, file, line);
    assert(0 && "unimplemented native code path");
    abort();
}

static uint32_t run_query(Vm *vm, const uint32_t *a)
{
    return Native_Magic_QueryCardAttribute(vm, (int32_t)a[0], (int32_t)a[1], (int32_t)a[2], a[3]);
}

static uint32_t run_is_mana_source(Vm *vm, const uint32_t *a)
{
    return Native_Magic_IsManaSource(vm, (int32_t)a[0], (int32_t)a[1]);
}

static uint32_t run_drop(Vm *vm, const uint32_t *a)
{
    (void)a;
    return Native_Magic_DropTopSpell(vm);
}

static uint32_t run_push(Vm *vm, const uint32_t *a)
{
    return Native_Magic_PushSpellStack(vm, (int32_t)a[0], (int32_t)a[1], (int32_t)a[2], (int32_t)a[3], a[4]);
}

static uint32_t run_clear(Vm *vm, const uint32_t *a)
{
    (void)a;
    return Native_Magic_ClearSpellStack(vm);
}

static uint32_t run_color_flags(Vm *vm, const uint32_t *a)
{
    return Native_Card_GetColorAndTypeFlags(vm, (int32_t)a[0], (int32_t)a[1]);
}

const NativeInfo NATIVE_FUNCTIONS[FN_COUNT] = {
    {FN_QUERY_CARD_ATTRIBUTE, "Magic_QueryCardAttribute", 4, 32, run_query},
    {FN_IS_MANA_SOURCE, "Magic_IsManaSource", 2, 8, run_is_mana_source},
    {FN_DROP_TOP_SPELL, "Magic_DropTopSpell", 0, 32, run_drop},
    {FN_PUSH_SPELL_STACK, "Magic_PushSpellStack", 5, 32, run_push},
    {FN_CLEAR_SPELL_STACK, "Magic_ClearSpellStack", 0, 32, run_clear},
    {FN_GET_COLOR_AND_TYPE_FLAGS, "Card_GetColorAndTypeFlags", 2, 32, run_color_flags},
};

const NativeInfo *native_find(const char *name)
{
    int i;
    for (i = 0; i < FN_COUNT; i++)
        if (strcmp(NATIVE_FUNCTIONS[i].name, name) == 0)
            return &NATIVE_FUNCTIONS[i];
    return NULL;
}
