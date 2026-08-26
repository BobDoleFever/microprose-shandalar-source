import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ExtractFunctionContext extends GhidraScript {
    @Override
    public void run() throws Exception {
        if (currentProgram == null) return;

        String progName = currentProgram.getName();
        File outFile = new File("/Users/ben/decomp/scratch_" + progName.toLowerCase().replace(".", "_") + "_context.tsv");
        PrintWriter w = new PrintWriter(new OutputStreamWriter(new FileOutputStream(outFile), StandardCharsets.UTF_8));
        w.println("Address\tCurrentName\tStringsReferenced\tCalledAPIs\tCallsCount\tSize");

        Listing listing = currentProgram.getListing();
        FunctionIterator funcs = listing.getFunctions(true);

        while (funcs.hasNext()) {
            Function f = funcs.next();
            Address entry = f.getEntryPoint();
            String name = f.getName();
            long size = f.getBody().getNumAddresses();

            Set<String> strRefs = new TreeSet<>();
            Set<String> apiRefs = new TreeSet<>();

            InstructionIterator instIter = listing.getInstructions(f.getBody(), true);
            while (instIter.hasNext()) {
                Instruction inst = instIter.next();
                Reference[] refs = inst.getReferencesFrom();
                for (Reference r : refs) {
                    Address toAddr = r.getToAddress();
                    Data d = listing.getDefinedDataAt(toAddr);
                    if (d != null && d.hasStringValue()) {
                        Object val = d.getValue();
                        if (val instanceof String) {
                            String s = ((String) val).trim().replace("\t", " ").replace("\n", " ");
                            if (s.length() > 2 && s.length() < 100) {
                                strRefs.add(s);
                            }
                        }
                    }
                    Function called = listing.getFunctionAt(toAddr);
                    if (called != null) {
                        String cName = called.getName();
                        if (!cName.startsWith("FUN_") && !cName.startsWith("thunk_")) {
                            apiRefs.add(cName);
                        }
                    }
                }
            }

            w.println(entry + "\t" + name + "\t" + String.join(" | ", strRefs) + "\t" + String.join(" | ", apiRefs) + "\t" + f.getCalledFunctions(monitor).size() + "\t" + size);
        }

        w.close();
        println("Exported function context to " + outFile.getAbsolutePath());
    }
}
