AS=nasm
OUTPUT=bin
EXT=bin
all: 
  $(AS) -f$(OUTPUT) sh32.asm -osh.$(EXT)
  $(AS) -f$(OUTPUT) cmd32.asm -ocmd.$(EXT)
  $(AS) -f$(OUTPUT) rs32.asm -ors.$(EXT)
  $(AS) -f$(OUTPUT) bs32.asm -obs.$(EXT)
  disasm -m32 -fc sh.bin >sh32.h
  disasm -m32 -fc cmd.bin >cmd32.h
  disasm -m32 -fc rs.bin >rs32.h
  disasm -m32 -fc bs.bin >bs32.h
  
  $(AS) -f$(OUTPUT) sh64.asm -osh.$(EXT)
  $(AS) -f$(OUTPUT) cmd64.asm -ocmd.$(EXT)
  $(AS) -f$(OUTPUT) rs64.asm -ors.$(EXT)
  $(AS) -f$(OUTPUT) bs64.asm -obs.$(EXT)
  disasm -m64 -fc sh.bin >sh64.h
  disasm -m64 -fc cmd.bin >cmd64.h
  disasm -m64 -fc rs.bin >rs64.h
  disasm -m64 -fc bs.bin >bs64.h
clean:
  rm -rf *.bin *.obj *.o  