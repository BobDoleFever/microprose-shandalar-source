import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.SourceType;

import java.io.*;
import java.nio.charset.StandardCharsets;

public class RenameSubsystemSymbols extends GhidraScript {

    @Override
    public void run() throws Exception {
        if (currentProgram == null) return;

        String progName = currentProgram.getName();
        File csvFile = new File("/Users/ben/decomp/subsystems_symbol_map.csv");

        if (!csvFile.exists()) {
            println("CSV file not found: " + csvFile.getAbsolutePath());
            return;
        }

        println("Applying subsystem symbol map from " + csvFile.getName() + " to " + progName + "...");

        FunctionManager fm = currentProgram.getFunctionManager();
        int renamedCount = 0;

        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(csvFile), StandardCharsets.UTF_8))) {
            String line = br.readLine(); // Header
            while ((line = br.readLine()) != null) {
                if (line.trim().isEmpty()) continue;
                String[] parts = line.split(",");
                if (parts.length < 3) continue;

                String addrStr = parts[0].trim();
                String newName = parts[2].trim();

                Address addr = currentProgram.getAddressFactory().getAddress(addrStr);
                if (addr != null) {
                    Function f = fm.getFunctionAt(addr);
                    if (f != null) {
                        try {
                            f.setName(newName, SourceType.USER_DEFINED);
                            renamedCount++;
                        } catch (Exception ex) {
                            // ignore duplicate conflicts
                        }
                    }
                }
            }
        }

        println("Successfully applied " + renamedCount + " subsystem symbol renames to " + progName + "!");
    }
}
