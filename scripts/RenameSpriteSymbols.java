import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.SourceType;

import java.util.HashMap;
import java.util.Map;

public class RenameSpriteSymbols extends GhidraScript {

    @Override
    public void run() throws Exception {
        if (currentProgram == null) return;

        String progName = currentProgram.getName();
        println("Renaming sprite functions in " + progName + "...");

        Map<String, String> renames = new HashMap<>();

        if (progName.equalsIgnoreCase("MAGIC.EXE")) {
            renames.put("0050fcc0", "Sprite_LoadAll");
            renames.put("0050fd50", "Sprite_LoadCount");
            renames.put("0050fdf0", "Sprite_ScanRunLength");
            renames.put("0050fe90", "Sprite_EncodeFromSurface");
            renames.put("005101e0", "Sprite_DrawDirect");
            renames.put("00510360", "Sprite_DrawClipped");
            renames.put("00510650", "Sprite_DrawScaled");
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

        println("Successfully renamed " + count + " sprite functions in " + progName);
    }
}
