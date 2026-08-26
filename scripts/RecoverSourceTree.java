import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.StringDataInstance;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.Symbol;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.*;

public class RecoverSourceTree extends GhidraScript {

    private static class SourceAttribution {
        String sourceFile;
        int line;
        String assertExpr;
        SourceAttribution(String sf, int l, String expr) {
            this.sourceFile = sf;
            this.line = l;
            this.assertExpr = expr;
        }
    }

    @Override
    public void run() throws Exception {
        if (currentProgram == null) {
            println("No current program loaded.");
            return;
        }

        String progName = currentProgram.getName();
        String baseName = progName.toLowerCase().replace(".exe", "").replace(".dll", "");
        
        File decompRoot = new File("/Users/ben/decomp");
        File srcModuleDir = new File(decompRoot, "src/" + baseName);
        srcModuleDir.mkdirs();

        println("=========================================================");
        println(" Recovering authentic source tree for " + progName);
        println(" Target directory: " + srcModuleDir.getAbsolutePath());
        println("=========================================================");

        // 1. Map string literals that refer to .c/.cpp files
        Map<Address, String> fileStrings = new HashMap<>();
        DataIterator dataIter = currentProgram.getListing().getDefinedData(true);
        while (dataIter.hasNext()) {
            Data data = dataIter.next();
            if (data.hasStringValue()) {
                Object val = data.getValue();
                if (val instanceof String) {
                    String str = (String) val;
                    if (str.endsWith(".c") || str.endsWith(".cpp") || str.endsWith(".cxx") || str.contains("\\") && str.endsWith(".c")) {
                        fileStrings.put(data.getAddress(), normalizeSourcePath(str));
                    }
                }
            }
        }

        println("Found " + fileStrings.size() + " source file string constants in binary.");

        // 2. Trace XREFs from source file strings to functions
        Map<Address, String> funcToSourceFile = new HashMap<>();
        Listing listing = currentProgram.getListing();

        for (Map.Entry<Address, String> entry : fileStrings.entrySet()) {
            Address strAddr = entry.getKey();
            String srcFile = entry.getValue();

            ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesTo(strAddr);
            while (refs.hasNext()) {
                Reference ref = refs.next();
                Address fromAddr = ref.getFromAddress();
                Function func = listing.getFunctionContaining(fromAddr);
                if (func != null) {
                    funcToSourceFile.put(func.getEntryPoint(), srcFile);
                }
            }
        }

        println("Directly attributed " + funcToSourceFile.size() + " functions via string references.");

        // 3. Propagate attribution to adjacent functions in the same code blocks / call trees
        propagateAttributions(funcToSourceFile);

        // 4. Group individual decompiled C function files into authentic source modules
        File funcDir = new File(decompRoot, baseName + "/functions");
        File mappingCsv = new File(decompRoot, baseName + "/source_mapping.csv");
        
        Map<String, List<File>> moduleFiles = new TreeMap<>();
        PrintWriter mappingWtr = new PrintWriter(new OutputStreamWriter(new FileOutputStream(mappingCsv), StandardCharsets.UTF_8));
        mappingWtr.println("Address,FunctionName,SourceFile,ModuleGroup");

        FunctionIterator funcs = currentProgram.getListing().getFunctions(true);
        while (funcs.hasNext()) {
            Function f = funcs.next();
            Address entry = f.getEntryPoint();
            String name = f.getName();
            String srcFile = funcToSourceFile.getOrDefault(entry, "unattributed/" + baseName + "_core.c");
            
            String safeName = sanitizeFilename(name) + "_" + entry.toString() + ".c";
            File singleFuncFile = new File(funcDir, safeName);

            mappingWtr.println(entry + ",\"" + name + "\",\"" + srcFile + "\",\"" + getCategory(srcFile) + "\"");

            if (singleFuncFile.exists()) {
                moduleFiles.computeIfAbsent(srcFile, k -> new ArrayList<>()).add(singleFuncFile);
            }
        }
        mappingWtr.close();

        // 5. Build consolidated module C files under src/<module>/
        for (Map.Entry<String, List<File>> modEntry : moduleFiles.entrySet()) {
            String relativeSrc = modEntry.getKey();
            List<File> files = modEntry.getValue();

            File targetModuleFile = new File(srcModuleDir, relativeSrc);
            targetModuleFile.getParentFile().mkdirs();

            try (PrintWriter modWtr = new PrintWriter(new OutputStreamWriter(new FileOutputStream(targetModuleFile), StandardCharsets.UTF_8))) {
                modWtr.println("/*");
                modWtr.println(" * " + relativeSrc + " - Reconstructed MicroProse Source Module");
                modWtr.println(" * Program: " + progName);
                modWtr.println(" * Contained Functions: " + files.size());
                modWtr.println(" */");
                modWtr.println("#include <stdio.h>");
                modWtr.println("#include <stdlib.h>");
                modWtr.println("#include <string.h>");
                modWtr.println("#include <stdbool.h>");
                modWtr.println("#include <stdint.h>");
                modWtr.println();
                modWtr.println("#include \"shandalar/shandalar.h\"");
                modWtr.println("#include \"" + baseName + ".h\"");
                modWtr.println();

                for (File f : files) {
                    List<String> lines = Files.readAllLines(f.toPath(), StandardCharsets.UTF_8);
                    for (String line : lines) {
                        // Skip local include in consolidated module
                        if (line.startsWith("#include \"" + baseName + ".h\"")) continue;
                        modWtr.println(line);
                    }
                    modWtr.println();
                }
            }
            println("   -> Created module: " + targetModuleFile.getAbsolutePath() + " (" + files.size() + " functions)");
        }

        println("=========================================================");
        println(" Source tree reconstruction for " + progName + " complete!");
        println("=========================================================");
    }

    private void propagateAttributions(Map<Address, String> funcToSourceFile) {
        FunctionIterator iter = currentProgram.getListing().getFunctions(true);
        String currentSource = null;
        Address lastEntry = null;

        while (iter.hasNext()) {
            Function f = iter.next();
            Address entry = f.getEntryPoint();
            if (funcToSourceFile.containsKey(entry)) {
                currentSource = funcToSourceFile.get(entry);
            } else if (currentSource != null && lastEntry != null) {
                // If within 8KB of preceding function in same segment, group together
                long diff = entry.subtract(lastEntry);
                if (diff > 0 && diff < 8192) {
                    funcToSourceFile.put(entry, currentSource);
                } else {
                    currentSource = null;
                }
            }
            lastEntry = entry;
        }
    }

    private String normalizeSourcePath(String raw) {
        String clean = raw.replace("\\", "/");
        if (clean.contains("sources/")) {
            clean = clean.substring(clean.indexOf("sources/") + 8);
        } else if (clean.contains("NewMagic/")) {
            clean = clean.substring(clean.indexOf("NewMagic/") + 9);
        } else if (clean.startsWith("./") || clean.startsWith("../")) {
            clean = clean.replaceAll("^\\.+/", "");
        }
        return clean;
    }

    private String getCategory(String path) {
        if (path.contains("/")) {
            return path.substring(0, path.indexOf('/'));
        }
        return "root";
    }

    private String sanitizeFilename(String name) {
        if (name == null || name.isEmpty()) return "unnamed";
        return name.replaceAll("[^a-zA-Z0-9_.-]", "_");
    }
}
