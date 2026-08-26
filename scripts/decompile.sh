#!/usr/bin/env bash
set -e

export JAVA_HOME="/opt/homebrew/Cellar/openjdk@21/21.0.12.1/libexec/openjdk.jdk/Contents/Home"
export PATH="$JAVA_HOME/bin:$PATH"

GHIDRA_HEADLESS="/opt/homebrew/Cellar/ghidra/12.1.3/libexec/support/analyzeHeadless"
PROJECT_DIR="/Users/ben"
PROJECT_NAME="ShandalarDecomp"
SCRIPT_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
OUTPUT_DIR="${1:-/Users/ben/decomp}"

PROGRAMS=(
    "MAGIC.EXE"
    "DUEL.EXE"
    "DECK.EXE"
    "DECKDLL.DLL"
    "STATWIN.DLL"
    "MAGSND.DLL"
    "MAGVID.DLL"
)

echo "=========================================================="
echo " Starting Full Shandalar ANSI C Decompilation Pipeline"
echo " Target Project: $PROJECT_DIR/$PROJECT_NAME"
echo " Output Dir:     $OUTPUT_DIR"
echo " Modules:        ${PROGRAMS[*]}"
echo "=========================================================="

mkdir -p "$OUTPUT_DIR"

for prog in "${PROGRAMS[@]}"; do
    echo ""
    echo ">>> Decompiling $prog..."
    "$GHIDRA_HEADLESS" "$PROJECT_DIR" "$PROJECT_NAME" \
        -process "$prog" \
        -readOnly \
        -noanalysis \
        -scriptPath "$SCRIPT_PATH" \
        -postScript DecompileToAnsiC.java "$OUTPUT_DIR"
done

echo ""
echo ">>> Reconstructing authentic source trees (MAGIC.EXE & DUEL.EXE)..."
for prog in "MAGIC.EXE" "DUEL.EXE"; do
    "$GHIDRA_HEADLESS" "$PROJECT_DIR" "$PROJECT_NAME" \
        -process "$prog" \
        -readOnly \
        -noanalysis \
        -scriptPath "$SCRIPT_PATH" \
        -postScript RecoverSourceTree.java
done

echo ""
echo "=========================================================="
echo " Full Decompilation Suite Finished!"
echo " Code output generated in $OUTPUT_DIR"
echo "=========================================================="
