import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.SourceType;

import java.util.HashMap;
import java.util.Map;

public class RenameSoundFunctions extends GhidraScript {

    @Override
    public void run() throws Exception {
        if (currentProgram == null) {
            println("No current program loaded.");
            return;
        }

        String progName = currentProgram.getName();
        println("Renaming sound functions in " + progName + "...");

        Map<String, String> renames = new HashMap<>();

        if (progName.equalsIgnoreCase("MAGIC.EXE")) {
            renames.put("00423980", "Sound_Init");
            renames.put("00423ae1", "CloseSnd");
            renames.put("00423b57", "InitSndTrack");
            renames.put("00423b93", "CloseSndTrack");
            renames.put("00423bc7", "StopSndTrack");
            renames.put("00423bf4", "PlaySnd");
            renames.put("00423c39", "PlaySndFile");
            renames.put("00423c82", "StopSnd");
            renames.put("00423cc3", "PauseSnd");
            renames.put("00423cf3", "ResumeSnd");
            renames.put("00423d38", "SetPitch");
            renames.put("00423d7d", "GetPitch");
            renames.put("00423dc2", "SetVol");
            renames.put("00423e07", "GetVol");
            renames.put("00423e4c", "SetPan");
            renames.put("00423e91", "GetPan");
            renames.put("00423ed6", "UpdateSnd");
            renames.put("00423f10", "SetSndMarker");
            renames.put("00423f55", "PlaySndMarker");
            renames.put("00423f9a", "GetSndTime");
            renames.put("00423fdb", "ResetSnd");
            renames.put("00424020", "GetSndState");
            renames.put("00424065", "GetAVISndBuff");
            renames.put("004240a7", "ReleaseAVISndBuff");
            renames.put("004240ec", "GetSndHWND");
            renames.put("00424123", "IsSndLoaded");
            renames.put("00424165", "GetLRUSnd");
        } else if (progName.equalsIgnoreCase("DUEL.EXE")) {
            renames.put("0043d870", "Sound_Init");
            renames.put("0043d9cf", "CloseSnd");
            renames.put("0043da45", "InitSndTrack");
            renames.put("0043da81", "CloseSndTrack");
            renames.put("0043dab5", "StopSndTrack");
            renames.put("0043dae2", "PlaySnd");
            renames.put("0043db27", "PlaySndFile");
            renames.put("0043db70", "StopSnd");
            renames.put("0043dbb1", "PauseSnd");
            renames.put("0043dbe1", "ResumeSnd");
            renames.put("0043dc26", "SetPitch");
            renames.put("0043dc6b", "GetPitch");
            renames.put("0043dcb0", "SetVol");
            renames.put("0043dcf5", "GetVol");
            renames.put("0043dd3a", "SetPan");
            renames.put("0043dd7f", "GetPan");
            renames.put("0043ddc4", "UpdateSnd");
            renames.put("0043ddfe", "SetSndMarker");
            renames.put("0043de43", "PlaySndMarker");
            renames.put("0043de88", "GetSndTime");
            renames.put("0043dec9", "ResetSnd");
            renames.put("0043df0e", "GetSndState");
            renames.put("0043df53", "GetAVISndBuff");
            renames.put("0043df95", "ReleaseAVISndBuff");
            renames.put("0043dfda", "GetSndHWND");
            renames.put("0043e011", "IsSndLoaded");
            renames.put("0043e053", "GetLRUSnd");
        }

        FunctionManager fm = currentProgram.getFunctionManager();
        int renamedCount = 0;

        for (Map.Entry<String, String> entry : renames.entrySet()) {
            Address addr = currentProgram.getAddressFactory().getAddress(entry.getKey());
            if (addr != null) {
                Function f = fm.getFunctionAt(addr);
                if (f != null) {
                    String oldName = f.getName();
                    f.setName(entry.getValue(), SourceType.USER_DEFINED);
                    println("   Renamed " + oldName + " @ " + addr + " -> " + entry.getValue());
                    renamedCount++;
                }
            }
        }

        println("Successfully renamed " + renamedCount + " functions in " + progName);
    }
}
