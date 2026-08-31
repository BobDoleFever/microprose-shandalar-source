"""Test the deterministic PE32 generator artifacts."""

from __future__ import annotations

import json
import re
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
GENERATED = ROOT / "build/generated/pe32"
IMAGE = ROOT / "build/generated/magic_image.bin"


class MagicPeGeneratorTests(unittest.TestCase):
    def test_audit_has_no_fatal_generation_gaps(self) -> None:
        audit = json.loads(
            (GENERATED / "magic_pe_audit.json").read_text(encoding="utf-8")
        )
        self.assertEqual(audit["target"], "i686-w64-mingw32")
        self.assertEqual(audit["fatal_errors"], [])
        self.assertEqual(audit["counts"]["unresolved_imports"], 0)
        self.assertGreater(audit["counts"]["recovered_functions"], 1000)
        self.assertGreater(audit["counts"]["callbacks"], 0)

    def test_generated_source_uses_the_recovered_entry_point(self) -> None:
        source = (GENERATED / "magic_pe.c").read_text(encoding="utf-8")
        self.assertIn("int __cdecl MagicRecovered_WinMain(", source)
        self.assertNotIn("uintptr_t WinMain(", source)
        self.assertIn("MagicPe_ResolveCallable", source)
        self.assertIn("_Static_assert(sizeof(void *) == 4", source)
        self.assertIn("MagicPe_GlobalAddress", source)

    def test_symbol_table_and_lookup_generated(self) -> None:
        callable_source = (GENERATED / "magic_callable_map.c").read_text(encoding="utf-8")
        self.assertIn("MagicPe_LookupSymbolName", callable_source)
        self.assertIn("g_MagicPe_SymbolTable", callable_source)

    def test_required_companion_ordinals_and_def_files(self) -> None:
        manifest = json.loads(
            (GENERATED / "magic_module_ordinals.json").read_text(encoding="utf-8")
        )
        self.assertEqual(manifest["fatal_errors"], [])
        modules = {module["module"]: module for module in manifest["modules"]}
        self.assertEqual(len(modules["STATWIN.DLL"]["exports"]), 3)
        self.assertEqual(len(modules["MAGSND.DLL"]["exports"]), 27)
        self.assertEqual(len(modules["MAGVID.DLL"]["exports"]), 20)
        self.assertEqual(len(modules["DECKDLL.DLL"]["exports"]), 4)
        for module in modules.values():
            for export in module["exports"]:
                self.assertIn(export["calling_convention"], {"__cdecl", "__stdcall", "DATA"})
                self.assertTrue(export["prototype"].endswith(";"))

        for def_name in ("statwin.def", "magsnd.def", "magvid.def", "deckdll.def"):
            def_path = GENERATED / def_name
            self.assertTrue(def_path.exists(), f"{def_name} should exist")
            content = def_path.read_text(encoding="utf-8")
            self.assertIn("LIBRARY", content)
            self.assertIn("EXPORTS", content)

    def test_companion_module_audits(self) -> None:
        for mod in ("statwin", "magsnd", "magvid", "deckdll", "duel", "deck"):
            audit_file = GENERATED / mod / f"{mod}_pe_audit.json"
            self.assertTrue(audit_file.exists(), f"Audit file for {mod} should exist")
            audit = json.loads(audit_file.read_text(encoding="utf-8"))
            self.assertEqual(audit["fatal_errors"], [], f"{mod} has fatal ABI errors: {audit['fatal_errors']}")
            self.assertEqual(audit["counts"]["unresolved_imports"], 0, f"{mod} has unresolved imports")

    def test_resource_export_is_deterministic(self) -> None:
        with tempfile.TemporaryDirectory() as first, tempfile.TemporaryDirectory() as second:
            outputs = []
            for directory in (Path(first), Path(second)):
                result = directory / "magic_resources.res"
                manifest = directory / "magic_resources.json"
                subprocess.run(
                    [
                        sys.executable,
                        str(ROOT / "scripts/export_magic_pe_resources.py"),
                        "--image",
                        str(IMAGE),
                        "--output-res",
                        str(result),
                        "--output-manifest",
                        str(manifest),
                    ],
                    check=True,
                    cwd=ROOT,
                )
                outputs.append((result.read_bytes(), manifest.read_bytes()))
            self.assertEqual(outputs[0], outputs[1])
            manifest_data = json.loads(outputs[0][1])
            self.assertGreater(manifest_data["resource_count"], 0)
            self.assertEqual(
                manifest_data["resource_count"], len(manifest_data["resources"])
            )

    def test_runtime_keeps_the_recovered_image_non_executable(self) -> None:
        runtime = (ROOT / "src/magic_pe_runtime.c").read_text(encoding="utf-8")
        allocation = re.search(r"g_Image = VirtualAlloc\([\s\S]*?\n\s*\);", runtime)
        self.assertIsNotNone(allocation)
        self.assertIn("PAGE_READWRITE", allocation.group(0))
        self.assertNotIn("PAGE_EXECUTE", allocation.group(0))
        self.assertIn("MAGIC_PE_IMAGE_BASE", runtime)
        self.assertIn("MagicPe_LookupSymbolName", runtime)
        self.assertIn("VirtualQuery", runtime)

    def test_game_build_produces_valid_pe32_executable(self) -> None:
        exe_path = ROOT / "build/pe32/bin/MAGIC.EXE"
        self.assertTrue(exe_path.exists(), "build/pe32/bin/MAGIC.EXE must exist")

        file_header = subprocess.check_output(
            ["i686-w64-mingw32-objdump", "-f", str(exe_path)],
            text=True,
        )
        self.assertIn("file format pei-i386", file_header)
        self.assertIn("architecture: i386", file_header)

        private_headers = subprocess.check_output(
            ["i686-w64-mingw32-objdump", "-p", str(exe_path)],
            text=True,
        )
        self.assertRegex(private_headers, r"ImageBase\s+10000000")
        self.assertNotIn("DYNAMIC_BASE", private_headers)

        for dll in ("KERNEL32", "USER32", "GDI32", "ADVAPI32", "WINMM", "COMDLG32", "DECKDLL"):
            self.assertRegex(
                private_headers,
                rf"DLL Name:\s+{dll}\.(?:dll|DLL)",
                f"MAGIC.EXE must import from {dll}",
            )

    def test_import_stubs_removed_from_recovered_definitions(self) -> None:
        source = (GENERATED / "magic_pe.c").read_text(encoding="utf-8")
        for fn in ("GetSaveFileNameA", "DeckBuilderMain", "MCIWndCreateA", "__dllonexit", "initterm"):
            self.assertNotRegex(
                source,
                rf"(?m)^(?:uintptr_t|void|int|BOOL|WPARAM)\s+__cdecl\s+{fn}\s*\(",
                f"{fn} must not be defined as a recovered function in magic_pe.c",
            )

    def test_import_prototypes_have_correct_calling_conventions(self) -> None:
        imports_header = (GENERATED / "magic_pe_imports.h").read_text(encoding="utf-8")
        self.assertRegex(imports_header, r"BOOL\s+WINAPI\s+GetSaveFileNameA\s*\(\s*LPOPENFILENAMEA")
        self.assertRegex(imports_header, r"WPARAM\s+__cdecl\s+DeckBuilderMain\s*\(\s*HWND")
        self.assertRegex(imports_header, r"HWND\s+WINAPIV\s+MCIWndCreateA\s*\(\s*HWND")

    def test_no_direct_self_recursive_thunks(self) -> None:
        source = (GENERATED / "magic_pe.c").read_text(encoding="utf-8")
        pattern = re.compile(
            r"(?ms)^(?:uintptr_t|int|void|int32_t|uint32_t)(?:\s+__cdecl)?\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*?\)\s*\n\s*\{([\s\S]*?^\}\n)"
        )
        for m in pattern.finditer(source):
            name = m.group(1)
            inner = m.group(2)
            clean = re.sub(r"/\*[\s\S]*?\*/", "", inner)
            clean = re.sub(r"//[^\n]*", "", clean).strip()
            clean = re.sub(r"\breturn(?:\s+[^;]+)?\s*;", "", clean).strip()
            self.assertFalse(
                re.fullmatch(rf"{re.escape(name)}\s*\([^;]*\)\s*;", clean),
                f"Function {name} is an unhandled direct self-recursive thunk",
            )


if __name__ == "__main__":
    unittest.main()
