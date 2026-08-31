// Export the recovered program image and its memory symbols for any PE module.

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.nio.charset.StandardCharsets;


public class ExportPeImage extends GhidraScript {
    private static String csvField(String value) {
        return "\"" + value.replace("\"", "\"\"") + "\"";
    }

    @Override
    protected void run() throws Exception {
        String[] arguments = getScriptArgs();
        if (arguments.length != 2) {
            throw new IllegalArgumentException(
                "Usage: ExportPeImage.java <image-path> <symbols-path>"
            );
        }

        Address imageBase = currentProgram.getMinAddress();
        Address imageEnd = currentProgram.getMaxAddress();
        long imageSizeLong = imageEnd.subtract(imageBase) + 1;
        if (imageSizeLong <= 0 || imageSizeLong > Integer.MAX_VALUE) {
            throw new IllegalStateException("The program image size is not valid.");
        }

        byte[] image = new byte[(int)imageSizeLong];
        Memory memory = currentProgram.getMemory();
        for (MemoryBlock block : memory.getBlocks()) {
            monitor.checkCancelled();
            if (!block.isLoaded() || !block.isInitialized()) {
                continue;
            }

            Address cursor = block.getStart();
            long remaining = block.getSize();
            while (remaining > 0) {
                monitor.checkCancelled();
                int count = (int)Math.min(remaining, 1024 * 1024);
                int imageOffset = (int)cursor.subtract(imageBase);
                int bytesRead = memory.getBytes(cursor, image, imageOffset, count);
                if (bytesRead <= 0) {
                    throw new IllegalStateException("Ghidra could not read a memory block.");
                }
                cursor = cursor.add(bytesRead);
                remaining -= bytesRead;
            }
        }

        try (FileOutputStream output = new FileOutputStream(arguments[0])) {
            output.write(image);
        }

        try (BufferedWriter output = new BufferedWriter(
                new FileWriter(arguments[1], StandardCharsets.UTF_8))) {
            output.write("ImageBase,ImageEnd,ImageSize\n");
            output.write(String.format(
                "%s,%s,%d\n", imageBase, imageEnd, image.length
            ));
            output.write("Address,Name,Primary,SymbolType\n");

            SymbolIterator symbols = currentProgram.getSymbolTable().getAllSymbols(true);
            while (symbols.hasNext()) {
                monitor.checkCancelled();
                Symbol symbol = symbols.next();
                Address address = symbol.getAddress();
                if (!address.isMemoryAddress()) {
                    continue;
                }
                output.write(String.format(
                    "%s,%s,%s,%s\n",
                    address,
                    csvField(symbol.getName()),
                    symbol.isPrimary(),
                    symbol.getSymbolType()
                ));
            }
        }

        println(String.format(
            "Exported %s [%s through %s] to %s and %s",
            currentProgram.getName(), imageBase, imageEnd, arguments[0], arguments[1]
        ));
    }
}
