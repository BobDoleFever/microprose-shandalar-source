import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;

import java.io.*;
import java.nio.charset.StandardCharsets;

public class RenameGlobalSymbols extends GhidraScript {

    @Override
    public void run() throws Exception {
        if (currentProgram == null) return;

        String progName = currentProgram.getName();
        File csvFile = new File("/Users/ben/decomp/engine_globals_map.csv");

        if (!csvFile.exists()) {
            println("CSV file not found: " + csvFile.getAbsolutePath());
            return;
        }

        println("Renaming global variables in " + progName + "...");

        SymbolTable st = currentProgram.getSymbolTable();
        int renamedCount = 0;

        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(csvFile), StandardCharsets.UTF_8))) {
            String line = br.readLine(); // Header
            while ((line = br.readLine()) != null) {
                if (line.trim().isEmpty()) continue;
                String[] parts = line.split(",");
                if (parts.length < 2) continue;

                String addrStr = parts[0].trim();
                String newName = parts[1].trim();

                Address addr = currentProgram.getAddressFactory().getAddress(addrStr);
                if (addr != null) {
                    Symbol[] syms = st.getSymbols(addr);
                    if (syms != null && syms.length > 0) {
                        for (Symbol s : syms) {
                            try {
                                s.setName(newName, SourceType.USER_DEFINED);
                                println("   Renamed " + addrStr + " -> " + newName);
                                renamedCount++;
                                break;
                            } catch (Exception ex) {
                                // ignore collision
                            }
                        }
                    } else {
                        try {
                            st.createLabel(addr, newName, SourceType.USER_DEFINED);
                            println("   Created label " + addrStr + " -> " + newName);
                            renamedCount++;
                        } catch (Exception ex) {
                            // ignore collision
                        }
                    }
                }
            }
        }

        println("Successfully renamed " + renamedCount + " global variables in " + progName + "!");
    }
}
