import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.ClangTokenGroup;
import ghidra.app.script.GhidraScript;
import ghidra.app.util.Option;
import ghidra.app.util.exporter.CppExporter;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolType;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.text.SimpleDateFormat;
import java.util.*;

public class DecompileToAnsiC extends GhidraScript {

    private static final int TIMEOUT_SECS = 60;

    @Override
    public void run() throws Exception {
        if (currentProgram == null) {
            println("ERROR: No current program loaded.");
            return;
        }

        String progName = currentProgram.getName();
        String baseName = progName;
        if (baseName.toLowerCase().endsWith(".exe") || baseName.toLowerCase().endsWith(".dll")) {
            baseName = baseName.substring(0, baseName.lastIndexOf('.'));
        }
        String cleanBase = baseName.toLowerCase().replaceAll("[^a-zA-Z0-9_]", "_");

        String[] args = getScriptArgs();
        File baseOutputDir;
        if (args != null && args.length > 0 && args[0] != null && !args[0].trim().isEmpty()) {
            baseOutputDir = new File(args[0].trim());
        } else {
            baseOutputDir = new File("/Users/ben/decomp");
        }

        File progDir = new File(baseOutputDir, cleanBase);
        File includeDir = new File(baseOutputDir, "include");
        progDir.mkdirs();
        includeDir.mkdirs();

        println("=========================================================");
        println(" Decompiling " + progName + " to ANSI C");
        println(" Output directory: " + progDir.getAbsolutePath());
        println("=========================================================");

        // 1. Export standard CppExporter files (Complete C + H)
        exportViaCppExporter(progDir, cleanBase);

        // 2. Initialize Ghidra Decompiler Interface
        DecompInterface decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        // Configure options
        decompiler.setOptions(options);
        if (!decompiler.openProgram(currentProgram)) {
            println("ERROR: Failed to initialize decompiler for program: " + progName);
            return;
        }

        // 3. Export all functions to unified ANSI C and header files
        exportFunctions(decompiler, progDir, includeDir, cleanBase);

        // 4. Export symbols and global variables
        exportGlobalsAndSymbols(progDir, includeDir, cleanBase);

        // 5. Generate common Windows API types header if needed
        generateWindowsTypesHeader(includeDir);

        decompiler.dispose();

        println("=========================================================");
        println(" Decompilation of " + progName + " completed successfully!");
        println("=========================================================");
    }

    private void exportViaCppExporter(File progDir, String cleanBase) {
        try {
            println("[1/4] Running Ghidra CppExporter for unified baseline...");
            CppExporter exporter = new CppExporter();
            
            List<Option> opts = exporter.getOptions(null);
            for (Option opt : opts) {
                if (opt.getName().equals("Create Header File (.h)")) {
                    opt.setValue(Boolean.TRUE);
                } else if (opt.getName().equals("Create C File (.c)")) {
                    opt.setValue(Boolean.TRUE);
                } else if (opt.getName().equals("Use C++ Style Comments (//)")) {
                    opt.setValue(Boolean.FALSE); // Strictly ANSI C /* ... */
                } else if (opt.getName().equals("Emit Data-type Definitions")) {
                    opt.setValue(Boolean.TRUE);
                } else if (opt.getName().equals("Emit Referenced Globals")) {
                    opt.setValue(Boolean.TRUE);
                }
            }

            File unifiedCFile = new File(progDir, cleanBase + "_unified.c");
            exporter.setOptions(opts);
            exporter.export(unifiedCFile, currentProgram, currentProgram.getMemory().getLoadedAndInitializedAddressSet(), monitor);
            println("   -> Generated: " + unifiedCFile.getName() + " and " + cleanBase + "_unified.h");
        } catch (Exception e) {
            println("   -> Warning in CppExporter: " + e.getMessage());
        }
    }

    private void exportFunctions(DecompInterface decompiler, File progDir, File includeDir, String cleanBase) throws Exception {
        println("[2/4] Decompiling all individual functions...");

        File allCFile = new File(progDir, cleanBase + "_all.c");
        File allHFile = new File(includeDir, cleanBase + ".h");
        File indexCsvFile = new File(progDir, "function_index.csv");

        PrintWriter allCWtr = new PrintWriter(new OutputStreamWriter(new FileOutputStream(allCFile), StandardCharsets.UTF_8));
        PrintWriter allHWtr = new PrintWriter(new OutputStreamWriter(new FileOutputStream(allHFile), StandardCharsets.UTF_8));
        PrintWriter indexWtr = new PrintWriter(new OutputStreamWriter(new FileOutputStream(indexCsvFile), StandardCharsets.UTF_8));

        String timeStamp = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date());
        String headerGuard = cleanBase.toUpperCase() + "_H";

        allHWtr.println("/*");
        allHWtr.println(" * " + cleanBase + ".h - Function Prototypes and Header for " + currentProgram.getName());
        allHWtr.println(" * Decompiled using Ghidra on " + timeStamp);
        allHWtr.println(" */");
        allHWtr.println("#ifndef " + headerGuard);
        allHWtr.println("#define " + headerGuard);
        allHWtr.println();
        allHWtr.println("#include \"windows_types.h\"");
        allHWtr.println("#include \"" + cleanBase + "_types.h\"");
        allHWtr.println();
        allHWtr.println("#ifdef __cplusplus");
        allHWtr.println("extern \"C\" {");
        allHWtr.println("#endif");
        allHWtr.println();

        allCWtr.println("/*");
        allCWtr.println(" * " + cleanBase + "_all.c - Decompiled ANSI C Source for " + currentProgram.getName());
        allCWtr.println(" * Total Address Space: " + currentProgram.getMinAddress() + " - " + currentProgram.getMaxAddress());
        allCWtr.println(" * Generated by Ghidra Decompiler on " + timeStamp);
        allCWtr.println(" */");
        allCWtr.println("#include <stdio.h>");
        allCWtr.println("#include <stdlib.h>");
        allCWtr.println("#include <string.h>");
        allCWtr.println("#include <stdbool.h>");
        allCWtr.println("#include <stdint.h>");
        allCWtr.println();
        allCWtr.println("#include \"shandalar/shandalar.h\"");
        allCWtr.println("#include \"" + cleanBase + ".h\"");
        allCWtr.println();

        indexWtr.println("Address,FunctionName,ReturnType,ParameterCount,BodySize,Status");

        FunctionIterator iter = currentProgram.getListing().getFunctions(true);
        int totalFuncs = 0;
        int decompSuccess = 0;
        int decompFailed = 0;

        while (iter.hasNext()) {
            if (monitor.isCancelled()) break;
            Function func = iter.next();
            totalFuncs++;

            Address entry = func.getEntryPoint();
            String name = func.getName();
            long bodySize = func.getBody().getNumAddresses();

            DecompileResults results = decompiler.decompileFunction(func, TIMEOUT_SECS, monitor);

            if (results != null && results.decompileCompleted()) {
                String cCode = results.getDecompiledFunction().getC();
                String signature = results.getDecompiledFunction().getSignature();

                // Format ANSI C comments in signature
                allHWtr.println("/* Function at " + entry + " (Size: " + bodySize + " bytes) */");
                allHWtr.println(signature + ";");
                allHWtr.println();

                allCWtr.println("/* ==========================================================================");
                allCWtr.println(" * Function: " + name + " @ " + entry);
                allCWtr.println(" * ========================================================================== */");
                allCWtr.println(cCode);
                allCWtr.println();

                indexWtr.println(entry + ",\"" + name + "\",\"" + func.getReturnType().getDisplayName() + "\"," + func.getParameterCount() + "," + bodySize + ",SUCCESS");
                decompSuccess++;
            } else {
                String errorMsg = (results != null) ? results.getErrorMessage() : "Null results";
                allCWtr.println("/* DECOMPILATION FAILED FOR: " + name + " @ " + entry + ": " + errorMsg + " */");
                indexWtr.println(entry + ",\"" + name + "\",\"" + func.getReturnType().getDisplayName() + "\"," + func.getParameterCount() + "," + bodySize + ",FAILED");
                decompFailed++;
            }

            if (totalFuncs % 200 == 0) {
                println("   -> Processed " + totalFuncs + " functions (" + decompSuccess + " succeeded, " + decompFailed + " failed)...");
            }
        }

        allHWtr.println();
        allHWtr.println("#ifdef __cplusplus");
        allHWtr.println("}");
        allHWtr.println("#endif");
        allHWtr.println();
        allHWtr.println("#endif /* " + headerGuard + " */");

        allCWtr.close();
        allHWtr.close();
        indexWtr.close();

        println("   -> Completed " + totalFuncs + " functions total: " + decompSuccess + " decompiled successfully, " + decompFailed + " failed.");
        println("   -> Output: " + allCFile.getAbsolutePath());
        println("   -> Header: " + allHFile.getAbsolutePath());
    }

    private void exportGlobalsAndSymbols(File progDir, File includeDir, String cleanBase) throws Exception {
        println("[3/4] Exporting global variables, symbols, and data types...");

        // Export data types
        File typesHFile = new File(includeDir, cleanBase + "_types.h");
        try (PrintWriter typesWtr = new PrintWriter(new OutputStreamWriter(new FileOutputStream(typesHFile), StandardCharsets.UTF_8))) {
            typesWtr.println("/*");
            typesWtr.println(" * " + cleanBase + "_types.h - Data Types and Structure Definitions for " + currentProgram.getName());
            typesWtr.println(" */");
            typesWtr.println("#ifndef " + cleanBase.toUpperCase() + "_TYPES_H");
            typesWtr.println("#define " + cleanBase.toUpperCase() + "_TYPES_H");
            typesWtr.println();
            typesWtr.println("#include \"windows_types.h\"");
            typesWtr.println();

            DataTypeManager dtm = currentProgram.getDataTypeManager();
            Iterator<DataType> dtIter = dtm.getAllDataTypes();
            List<Structure> structs = new ArrayList<>();
            List<EnumDataType> enums = new ArrayList<>();

            while (dtIter.hasNext()) {
                DataType dt = dtIter.next();
                if (dt instanceof Structure) {
                    Structure s = (Structure) dt;
                    if (!s.isNotYetDefined() && s.getLength() > 0) {
                        structs.add(s);
                    }
                } else if (dt instanceof EnumDataType) {
                    enums.add((EnumDataType) dt);
                }
            }

            typesWtr.println("/* Forward Declarations */");
            for (Structure s : structs) {
                typesWtr.println("typedef struct " + sanitizeIdentifier(s.getName()) + " " + sanitizeIdentifier(s.getName()) + ";");
            }
            typesWtr.println();

            for (EnumDataType e : enums) {
                typesWtr.println("/* Enum: " + e.getName() + " */");
                typesWtr.println("typedef enum " + sanitizeIdentifier(e.getName()) + " {");
                long[] values = e.getValues();
                for (int i = 0; i < values.length; i++) {
                    String name = e.getName(values[i]);
                    typesWtr.println("    " + sanitizeIdentifier(name) + " = " + values[i] + (i < values.length - 1 ? "," : ""));
                }
                typesWtr.println("} " + sanitizeIdentifier(e.getName()) + ";");
                typesWtr.println();
            }

            int structCount = 0;
            for (Structure s : structs) {
                typesWtr.println("/* Struct: " + s.getName() + " (Size: " + s.getLength() + " bytes) */");
                typesWtr.println("struct " + sanitizeIdentifier(s.getName()) + " {");
                for (DataTypeComponent comp : s.getComponents()) {
                    String fieldName = comp.getFieldName();
                    if (fieldName == null || fieldName.isEmpty()) {
                        fieldName = "field_" + Integer.toHexString(comp.getOffset());
                    }
                    String dtName = comp.getDataType().getDisplayName();
                    String arrayDim = "";
                    if (dtName.contains("[") && dtName.endsWith("]")) {
                        int idx = dtName.indexOf('[');
                        arrayDim = dtName.substring(idx);
                        dtName = dtName.substring(0, idx).trim();
                    }
                    typesWtr.println("    " + dtName + " " + sanitizeIdentifier(fieldName) + arrayDim + "; /* offset: 0x" + Integer.toHexString(comp.getOffset()) + " */");
                }
                typesWtr.println("};");
                typesWtr.println();
                structCount++;
            }
            typesWtr.println("#endif /* " + cleanBase.toUpperCase() + "_TYPES_H */");
            println("   -> Exported " + structCount + " structures to " + typesHFile.getName());
        }

        // Export symbols and global memory data
        File symbolsCsvFile = new File(progDir, "symbols.csv");
        File globalsCFile = new File(progDir, cleanBase + "_globals.c");
        try (PrintWriter symWtr = new PrintWriter(new OutputStreamWriter(new FileOutputStream(symbolsCsvFile), StandardCharsets.UTF_8));
             PrintWriter globWtr = new PrintWriter(new OutputStreamWriter(new FileOutputStream(globalsCFile), StandardCharsets.UTF_8))) {

            symWtr.println("Address,SymbolName,SymbolType,IsGlobal,IsFunction");
            globWtr.println("/* Global variable references and defined data for " + currentProgram.getName() + " */");
            globWtr.println("#include \"" + cleanBase + ".h\"");
            globWtr.println();

            SymbolIterator sIter = currentProgram.getSymbolTable().getAllSymbols(true);
            int globCount = 0;
            while (sIter.hasNext()) {
                Symbol sym = sIter.next();
                symWtr.println(sym.getAddress() + ",\"" + sym.getName() + "\"," + sym.getSymbolType() + "," + sym.isGlobal() + "," + (sym.getSymbolType() == SymbolType.FUNCTION));
                if (sym.isGlobal() && sym.getSymbolType() == SymbolType.LABEL) {
                    globCount++;
                }
            }
            println("   -> Exported symbol table to " + symbolsCsvFile.getName() + " (" + globCount + " global labels)");
        }
    }

    private void generateWindowsTypesHeader(File includeDir) throws Exception {
        File winTypes = new File(includeDir, "windows_types.h");
        if (winTypes.exists()) return;

        try (PrintWriter w = new PrintWriter(new OutputStreamWriter(new FileOutputStream(winTypes), StandardCharsets.UTF_8))) {
            w.println("/*");
            w.println(" * windows_types.h - Standard ANSI C Win32/x86 Type Definitions");
            w.println(" */");
            w.println("#ifndef WINDOWS_TYPES_H");
            w.println("#define WINDOWS_TYPES_H");
            w.println();
            w.println("#include <stdint.h>");
            w.println("#include <stddef.h>");
            w.println("#include <stdbool.h>");
            w.println();
            w.println("/* Calling conventions */");
            w.println("#ifndef __cdecl");
            w.println("#define __cdecl");
            w.println("#endif");
            w.println("#ifndef __stdcall");
            w.println("#define __stdcall");
            w.println("#endif");
            w.println("#ifndef __fastcall");
            w.println("#define __fastcall");
            w.println("#endif");
            w.println();
            w.println("/* Basic Windows Types */");
            w.println("typedef uint8_t   BYTE;");
            w.println("typedef uint16_t  WORD;");
            w.println("typedef uint32_t  DWORD;");
            w.println("typedef int32_t   BOOL;");
            w.println("typedef int32_t   LONG;");
            w.println("typedef uint32_t  ULONG;");
            w.println("typedef uint32_t  UINT;");
            w.println("typedef int32_t   INT;");
            w.println("typedef int16_t   SHORT;");
            w.println("typedef uint16_t  USHORT;");
            w.println("typedef uint8_t   UCHAR;");
            w.println("typedef char      CHAR;");
            w.println("typedef void*     LPVOID;");
            w.println("typedef void*     PVOID;");
            w.println("typedef void*     HANDLE;");
            w.println("typedef void*     HWND;");
            w.println("typedef void*     HDC;");
            w.println("typedef void*     HINSTANCE;");
            w.println("typedef void*     HBITMAP;");
            w.println("typedef void*     HMENU;");
            w.println("typedef void*     HPEN;");
            w.println("typedef void*     HBRUSH;");
            w.println("typedef void*     HFONT;");
            w.println("typedef char*     LPSTR;");
            w.println("typedef const char* LPCSTR;");
            w.println("typedef int32_t   LRESULT;");
            w.println("typedef uint32_t  WPARAM;");
            w.println("typedef int32_t   LPARAM;");
            w.println();
            w.println("/* Ghidra Builtin Pseudo-types */");
            w.println("typedef uint8_t   undefined;");
            w.println("typedef uint8_t   undefined1;");
            w.println("typedef uint16_t  undefined2;");
            w.println("typedef uint32_t  undefined4;");
            w.println("typedef uint64_t  undefined8;");
            w.println("typedef uint8_t   byte;");
            w.println("typedef uint16_t  word;");
            w.println("typedef uint32_t  dword;");
            w.println("typedef uint64_t  qword;");
            w.println("typedef uint32_t  uint;");
            w.println("typedef uint16_t  ushort;");
            w.println("typedef uint8_t   uchar;");
            w.println("typedef uint32_t  ulong;");
            w.println();
            w.println("#endif /* WINDOWS_TYPES_H */");
        }
        println("   -> Generated windows_types.h");
    }

    private String sanitizeIdentifier(String name) {
        if (name == null || name.isEmpty()) return "unnamed";
        String s = name.replaceAll("[^a-zA-Z0-9_]", "_");
        if (Character.isDigit(s.charAt(0))) {
            s = "_" + s;
        }
        return s;
    }

    private String sanitizeFilename(String name) {
        if (name == null || name.isEmpty()) return "unnamed";
        return name.replaceAll("[^a-zA-Z0-9_.-]", "_");
    }
}
