import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.SourceType;

import java.util.HashMap;
import java.util.Map;

public class RenameSurfaceSymbols extends GhidraScript {

    @Override
    public void run() throws Exception {
        if (currentProgram == null) return;

        String progName = currentProgram.getName();
        println("Renaming surface functions in " + progName + "...");

        Map<String, String> renames = new HashMap<>();

        if (progName.equalsIgnoreCase("MAGIC.EXE")) {
            renames.put("0050d6f0", "Surface_GetPixel");
            renames.put("0050da40", "Surface_GetPixelValue");
            renames.put("0050db10", "Surface_DrawLine");
            renames.put("0050dbb0", "Surface_PutPixel");
            renames.put("0050dc30", "Surface_FillRect");
            renames.put("0050e290", "Surface_StretchBlt");
            renames.put("0050e760", "Surface_PutLine");
            renames.put("0050e850", "Surface_GetLine");
        }

        FunctionManager fm = currentProgram.getFunctionManager();
        int count = 0;

        for (Map.Entry<String, String> entry : renames.entrySet()) {
            Address addr = currentProgram.getAddressFactory().getAddress(entry.getKey());
            if (addr != null) {
                Function f = fm.getFunctionAt(addr);
                if (f != null) {
                    f.setName(entry.getValue(), SourceType.USER_DEFINED);
                    println("   Renamed " + entry.getKey() + " -> " + entry.getValue());
                    count++;
                }
            }
        }

        println("Successfully renamed " + count + " surface functions in " + progName);
    }
}
