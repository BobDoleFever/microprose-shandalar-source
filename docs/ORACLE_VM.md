# Oracle VM: Windows 98SE under QEMU

The reference ("oracle") for verifying the decompilation is the original 1997 game running
unmodified in a Windows 98SE virtual machine. Nothing from the game or from Windows is stored in
this repository: installers, ISOs, disk images and extracted game files live in the git-ignored
`sources/` folder, and you must supply your own legally obtained copies.

## Current setup

- UTM 4.7.5 (QEMU backend) VM named "Windows": mode **Emulate** (software x86, no Rosetta),
  machine `pc` (i440FX, 1996), 512 MB RAM, 4 GiB disk (FAT32), Cirrus VGA, SB16, ne2k_isa.
- Guest: Windows 98 Second Edition. Game installed to `C:\Magic\Program` from the retail
  disc image (`MTG v1.0`).
- The VM bundle lives at
  `~/Library/Containers/com.utmapp.UTM/Data/Documents/Windows.utm` (`config.plist` + `Data/`).

## Preparing the media

- The game disc came as an Alcohol 120% `.mdf/.mds` pair. The `.mdf` is a *raw-sector* image
  (2352 bytes/sector, starts with the CD sync pattern), so renaming to `.iso` does not work.
  Convert with `brew install mdf2iso && mdf2iso "MTG v1.0.mdf" "MTG v1.0.iso"`.
- Getting files out of the VM: shut Windows down, then
  `qemu-img convert -O raw <disk>.qcow2 win98-disk.raw` and
  `hdiutil attach -readonly -nobrowse -imagekey diskimage-class=CRawDiskImage win98-disk.raw`.

## Fingerprints (installed build)

| File | SHA-256 |
|---|---|
| `MAGIC.EXE` | `4dc592695b6ee390485f283feb2a248cd3f3f739749c2800ab3b1100ea03845c` |
| `DUEL.EXE` | `7c4e618b4a8ab4330c71d2dd30637c522573c133d32c667c97924dc8edc2efed` |
| `DECK.EXE` | `193f8abea01d4f2c03b769224b06eece6e263a18f13a5b4e2509ed25a01e3d90` |
| `DECKDLL.DLL` | `a21f714bea465077c4fabe4a407ff7503b0ce5f9bb1a277826e74276e35c2c18` |
| `STATWIN.DLL` | `95bd14de41e8fff84217cdf627a48392da5e7be9c3d064a68e04ed1455334bd7` |
| `MAGSND.DLL` | `6f6d51cd2b8a5800b0b3c994e3ee8217f7b40ba2621f9738783387f3250a9882` |
| `MAGVID.DLL` | `d2db1435ae96e9e41d77ded7a7b222969d44d5af642fa9968fe51768c1ce83a3` |

## Proof this is the decompiled build

Checked by mapping addresses from the decompiled source into the installed `MAGIC.EXE`
(image base `0x00400000`, SizeOfImage `0x32c000`):

- `0x0052f0c0` holds `advfac64.pic` and `0x0052f0d0` holds `dbox.spr`, exactly as the decomp
  references them.
- The functions listed at `0x00474c7f` (143 bytes), `0x00474d0e` (16) and `0x00474d1e` (44)
  each start with `55 8b ec` and end with `c9 c3`, and the sizes tile with no gaps.

Only `MAGIC.EXE` has been checked so far. The other six binaries still need the same test.

## Quirks (all verified the hard way)

- **Two IDE drives maximum.** UTM gives each IDE drive its own bus (`ide.0`, `ide.1`); a third
  fails with `Bus 'ide.2' not found`. The second slot is the CD-ROM.
- **Swapping the CD.** UTM's Drives menu entries are greyed out while running. Shut the guest
  down, quit UTM, edit `Drive.1.ImageName` in `config.plist` with `plutil` (copy the ISO into
  `Data/` first), relaunch, start with `utmctl start Windows`.
- **CD drive must be `ImageType: CD`.** As `Disk` it is a second hard drive and Windows cannot
  see the disc.
- **Input.** The guest mouse does not track synthetic clicks (PS/2 relative mouse); keyboard input
  does reach the guest. Never send Escape then Return blindly: Escape did not dismiss the Shut Down
  dialog, so Return then shut Windows down.
- **ACPI shutdown requests are ignored** (`utmctl stop --request`); shut down from inside the guest.
- **Boot prompt.** Every boot shows a harmless `vnetbios.vxd` missing-file prompt (the network
  driver was never installed). Press a key.
- **Installer boot menu.** The first "Boot from Hard Disk / CD-ROM" menu is the CD's own boot
  loader. Choose CD-ROM until Windows Setup itself has finished.
- **The 1997 patch `mtgbv11a.exe` does not apply.** It patches only `GAME.RFS`, which exists
  neither on the disc nor on the installed disk, and its README is for a different product.

## Scriptable oracle (plain QEMU)

`tools/verification_harness/oracle_launch.sh [name]` boots the same disk with QMP and a gdbstub
(`127.0.0.1:1234`) from a throwaway overlay, using hardware that mirrors the UTM VM
(`pc-i440fx-10.0`, Cirrus, SB16, ne2k_isa, hd on ide.0, CD on ide.1) so Windows shows no
new-hardware dialogs. It expects `sources/oracle/base.raw`: a copy of the raw disk into which a copy
of the `Shandalar.lnk` Start menu shortcut was placed in `WINDOWS\Start Menu\Programs\StartUp`,
so the game launches itself at boot. Delete any `._*` files macOS adds when copying onto the FAT
volume; Windows treats `._Shandalar.lnk` as a broken shortcut.

Gotchas: QMP serves one client at a time; QEMU's gdbstub pauses the guest on attach and
re-triggers a breakpoint at the current PC on continue, so step over your own breakpoint first
(`GDBRemote.resume`); all programs load at `0x00400000`, so verify code bytes before trusting a hit.

## Mouse control

The guest uses a PS/2 relative mouse. Measured on this guest: QMP relative moves in steps of 2
counts move the pointer exactly 1 pixel per count, while larger steps are doubled by pointer
acceleration. `QMP.mouse_goto(x, y)` therefore homes into the top-left corner (clamps at 0,0) and
moves in steps of 2, which is absolute to about a pixel. `oracle_ctl.py click X Y` does that and
clicks. The screen is 640x480 and coordinates are guest pixels.
