import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;

import java.util.*;

public class RenameFunctionParameters extends GhidraScript {

    @Override
    public void run() throws Exception {
        if (currentProgram == null) return;

        String progName = currentProgram.getName();
        println("Renaming function parameters in " + progName + "...");

        Listing listing = currentProgram.getListing();
        FunctionIterator funcs = listing.getFunctions(true);
        int renamedParamsCount = 0;
        int funcCount = 0;

        while (funcs.hasNext()) {
            Function f = funcs.next();
            funcCount++;
            String fname = f.getName();
            String fnameLower = fname.toLowerCase();
            Parameter[] params = f.getParameters();
            if (params == null || params.length == 0) continue;

            String[] newNames = generateParamNames(fname, fnameLower, params);

            for (int i = 0; i < params.length; i++) {
                if (i < newNames.length && newNames[i] != null && !newNames[i].isEmpty()) {
                    String oldName = params[i].getName();
                    if (!newNames[i].equals(oldName)) {
                        try {
                            params[i].setName(newNames[i], SourceType.USER_DEFINED);
                            renamedParamsCount++;
                        } catch (Exception ex) {
                            // ignore conflicts
                        }
                    }
                }
            }
        }

        println("Renamed " + renamedParamsCount + " parameters across " + funcCount + " functions in " + progName + "!");
    }

    private String[] generateParamNames(String fname, String fnameLower, Parameter[] params) {
        int count = params.length;
        String[] names = new String[count];

        // 1. Audio API
        if (fname.equals("PlaySnd")) {
            if (count >= 1) names[0] = "sound_id";
            if (count >= 2) names[1] = "flags";
            return names;
        }
        if (fname.equals("PlaySndFile")) {
            if (count >= 1) names[0] = "filename";
            if (count >= 2) names[1] = "loop_flag";
            if (count >= 3) names[2] = "out_handle";
            return names;
        }
        if (fname.equals("StopSnd")) {
            if (count >= 1) names[0] = "sound_id";
            return names;
        }
        if (fname.equals("SetVol") || fname.equals("SetPitch") || fname.equals("SetPan")) {
            if (count >= 1) names[0] = "value";
            return names;
        }
        if (fname.equals("Sound_Init")) {
            if (count >= 1) names[0] = "hInst";
            if (count >= 2) names[1] = "hWnd";
            if (count >= 3) names[2] = "flags";
            return names;
        }
        if (fname.equals("InitSndTrack")) {
            if (count >= 1) names[0] = "track_id";
            if (count >= 2) names[1] = "param_2";
            if (count >= 3) names[2] = "param_3";
            return names;
        }
        if (fname.equals("SetSndMarker") || fname.equals("PlaySndMarker")) {
            if (count >= 1) names[0] = "marker_id";
            if (count >= 2) names[1] = "flags";
            return names;
        }

        // 2. Win32 Window & Dialog Procs
        if (fnameLower.contains("wndproc") || fnameLower.contains("dialogproc")) {
            if (count == 4) {
                names[0] = "hwnd";
                names[1] = "uMsg";
                names[2] = "wParam";
                names[3] = "lParam";
                return names;
            }
        }
        if (fnameLower.contains("register") && count >= 1) {
            names[0] = "hInstance";
            return names;
        }

        // 3. File & CSV Loaders
        if (fnameLower.contains("load") || fnameLower.contains("read") || fnameLower.contains("search") || fnameLower.contains("csv") || fnameLower.contains("hints") || fnameLower.contains("story")) {
            if (count >= 1 && isStringType(params[0].getDataType())) {
                names[0] = "filepath";
            }
            if (count >= 2 && isStringType(params[1].getDataType())) {
                names[1] = "mode";
            }
            if (count >= 2 && params[1].getDataType() instanceof Pointer) {
                names[1] = "out_buffer";
            }
        }

        // 4. Card rules & filters
        if (fnameLower.contains("rules") || fnameLower.contains("filter")) {
            if (count >= 1) names[0] = isStringType(params[0].getDataType()) ? "filter_string" : "card_id";
            if (count >= 2) names[1] = (params[1].getDataType() instanceof Pointer) ? "out_filter" : "color_mask";
            return names;
        }
        if (fnameLower.contains("target") || fnameLower.contains("action_prompt") || fnameLower.contains("action_validate")) {
            if (count >= 1) names[0] = "spell_id";
            if (count >= 2) names[1] = "target_id";
            if (count >= 3) names[2] = "flags";
            return names;
        }

        // 5. General heuristics based on parameter types & positions
        for (int i = 0; i < count; i++) {
            if (names[i] != null) continue;

            DataType dt = params[i].getDataType();
            String dtName = dt.getName().toLowerCase();

            if (dtName.contains("char") && (dt instanceof Pointer || dtName.contains("*"))) {
                names[i] = (i == 0 && (fnameLower.contains("file") || fnameLower.contains("pic") || fnameLower.contains("open"))) ? "filename" : "str_" + (i + 1);
            } else if (dtName.contains("file") && (dt instanceof Pointer || dtName.contains("*"))) {
                names[i] = "fp";
            } else if (dtName.contains("hwnd")) {
                names[i] = "hwnd";
            } else if (dtName.contains("hdc")) {
                names[i] = "hdc";
            } else if (dtName.contains("hinstance")) {
                names[i] = "hInstance";
            } else if (dt instanceof Pointer) {
                names[i] = "ptr_" + (i + 1);
            } else if (count == 2 && i == 0 && dtName.contains("int")) {
                names[0] = "arg1";
                names[1] = "arg2";
                break;
            } else if (count == 4 && dtName.contains("int")) {
                names[0] = "x";
                names[1] = "y";
                names[2] = "width";
                names[3] = "height";
                break;
            } else {
                names[i] = "arg_" + (i + 1);
            }
        }

        return names;
    }

    private boolean isStringType(DataType dt) {
        if (dt == null) return false;
        String n = dt.getName().toLowerCase();
        return n.contains("char") && (dt instanceof Pointer || n.contains("*") || n.contains("lpstr") || n.contains("lpcstr"));
    }
}
