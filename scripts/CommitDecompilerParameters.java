import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.pcode.*;

import java.util.*;

public class CommitDecompilerParameters extends GhidraScript {

    @Override
    public void run() throws Exception {
        if (currentProgram == null) return;

        String progName = currentProgram.getName();
        println("Decompiling and renaming parameters in " + progName + " via HighFunctionDBUtil...");

        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);

        Listing listing = currentProgram.getListing();
        FunctionIterator funcs = listing.getFunctions(true);

        int totalRenamed = 0;
        int funcsProcessed = 0;

        while (funcs.hasNext()) {
            Function f = funcs.next();
            funcsProcessed++;

            DecompileResults results = decompiler.decompileFunction(f, 30, monitor);
            if (results == null || !results.decompileCompleted()) continue;

            HighFunction highFunc = results.getHighFunction();
            if (highFunc == null) continue;

            LocalSymbolMap symMap = highFunc.getLocalSymbolMap();
            if (symMap == null) continue;

            int paramCount = symMap.getNumParams();
            if (paramCount == 0) continue;

            String fname = f.getName();
            String fnameLower = fname.toLowerCase();

            for (int i = 0; i < paramCount; i++) {
                HighSymbol sym = symMap.getParamSymbol(i);
                if (sym == null) continue;

                String oldName = sym.getName();
                String newName = chooseParamName(fname, fnameLower, i, paramCount, sym.getDataType().getName().toLowerCase());

                if (newName != null && !newName.equals(oldName) && (oldName.startsWith("param_") || oldName.startsWith("unaff_") || oldName.startsWith("in_"))) {
                    try {
                        HighFunctionDBUtil.updateDBVariable(sym, newName, null, SourceType.USER_DEFINED);
                        totalRenamed++;
                    } catch (Exception ex) {
                        // ignore duplicate name errors
                    }
                }
            }
        }

        decompiler.dispose();
        println("Successfully renamed and committed " + totalRenamed + " parameters across " + funcsProcessed + " functions in " + progName + "!");
    }

    private String chooseParamName(String fname, String fnameLower, int index, int totalParams, String typeName) {
        // Audio
        if (fname.equals("PlaySnd")) {
            if (index == 0) return "sound_id";
            if (index == 1) return "flags";
        }
        if (fname.equals("PlaySndFile")) {
            if (index == 0) return "filename";
            if (index == 1) return "loop_flag";
            if (index == 2) return "out_handle";
        }
        if (fname.equals("StopSnd")) {
            if (index == 0) return "sound_id";
        }
        if (fname.equals("Sound_Init")) {
            if (index == 0) return "hInst";
            if (index == 1) return "hWnd";
            if (index == 2) return "flags";
        }
        if (fname.equals("SetVol") || fname.equals("SetPitch") || fname.equals("SetPan")) {
            if (index == 0) return "value";
        }

        // Win32 Procs
        if (fnameLower.contains("wndproc") || fnameLower.contains("dialogproc")) {
            if (totalParams == 4) {
                if (index == 0) return "hwnd";
                if (index == 1) return "uMsg";
                if (index == 2) return "wParam";
                if (index == 3) return "lParam";
            }
        }

        // CSV & File loaders
        if (fnameLower.contains("load") || fnameLower.contains("read") || fnameLower.contains("search") || fnameLower.contains("csv") || fnameLower.contains("hints") || fnameLower.contains("story")) {
            if (index == 0 && (typeName.contains("char") || typeName.contains("str"))) return "filepath";
            if (index == 1 && (typeName.contains("char") || typeName.contains("str"))) return "mode";
            if (index == 1 && (typeName.contains("*") || typeName.contains("void"))) return "out_buffer";
        }

        // Card rules & targeting
        if (fnameLower.contains("target") || fnameLower.contains("prompt") || fnameLower.contains("validate")) {
            if (index == 0) return "spell_id";
            if (index == 1) return "target_id";
            if (index == 2) return "flags";
        }

        if (fnameLower.contains("filter") || fnameLower.contains("rules")) {
            if (index == 0) return (typeName.contains("char") || typeName.contains("str")) ? "filter_string" : "card_id";
            if (index == 1) return (typeName.contains("*") || typeName.contains("void")) ? "out_filter" : "color_mask";
        }

        // Common type heuristics
        if (typeName.contains("char*") || typeName.contains("char *") || typeName.contains("lpstr") || typeName.contains("lpcstr")) {
            return (index == 0 && (fnameLower.contains("file") || fnameLower.contains("pic") || fnameLower.contains("open"))) ? "filename" : "str_" + (index + 1);
        }
        if (typeName.contains("hwnd")) return "hwnd";
        if (typeName.contains("hdc")) return "hdc";
        if (typeName.contains("hinstance")) return "hInstance";
        if (typeName.contains("file*") || typeName.contains("file *")) return "fp";

        if (totalParams == 2) {
            return (index == 0) ? "arg1" : "arg2";
        }
        if (totalParams == 4 && typeName.contains("int")) {
            if (index == 0) return "x";
            if (index == 1) return "y";
            if (index == 2) return "width";
            if (index == 3) return "height";
        }

        return "arg_" + (index + 1);
    }
}
