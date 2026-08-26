import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;

public class ApplyDuelSymbolSync extends GhidraScript {

    @Override
    public void run() throws Exception {
        if (currentProgram == null) return;

        String progName = currentProgram.getName();
        if (!progName.equalsIgnoreCase("DUEL.EXE")) {
            println("Skipping, current program is " + progName + " (expected DUEL.EXE)");
            return;
        }

        println("Applying synchronized symbols to " + progName + "...");

        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();

        File csvFile = new File("/Users/ben/decomp/duel_symbol_sync_map.csv");
        int fnCount = 0;

        if (csvFile.exists()) {
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
                        Function f = fm.getFunctionAt(addr);
                        if (f != null) {
                            try {
                                f.setName(newName, SourceType.USER_DEFINED);
                                fnCount++;
                            } catch (Exception ex) {
                                // ignore
                            }
                        }
                    }
                }
            }
        }

        // Global variables in DUEL.EXE
        Map<String, String> duelGlobals = new HashMap<>();
        duelGlobals.put("006baa78", "g_ActiveCardsInPlay");
        duelGlobals.put("006b9544", "g_ActivePlayer");
        duelGlobals.put("0069f264", "g_DefendingPlayer");
        duelGlobals.put("006aa9c8", "g_PlayerLifeTotals");
        duelGlobals.put("006b9548", "g_PlayerCreatureCount");
        duelGlobals.put("00694540", "g_MasterCardCount");
        duelGlobals.put("0052cea8", "g_MasterCardTable");
        duelGlobals.put("006c797c", "g_MainAppHwnd");
        duelGlobals.put("0069f1a0", "g_HdcBackBuffer");

        int globalCount = 0;
        for (Map.Entry<String, String> entry : duelGlobals.entrySet()) {
            Address addr = currentProgram.getAddressFactory().getAddress(entry.getKey());
            if (addr != null) {
                Symbol[] syms = st.getSymbols(addr);
                if (syms != null && syms.length > 0) {
                    for (Symbol s : syms) {
                        try {
                            s.setName(entry.getValue(), SourceType.USER_DEFINED);
                            globalCount++;
                            break;
                        } catch (Exception ex) {}
                    }
                } else {
                    try {
                        st.createLabel(addr, entry.getValue(), SourceType.USER_DEFINED);
                        globalCount++;
                    } catch (Exception ex) {}
                }
            }
        }

        println("Successfully synced " + fnCount + " functions and " + globalCount + " globals in DUEL.EXE!");
    }
}
