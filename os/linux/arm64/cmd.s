/**
  execute command using /bin/sh
  tested with ubuntu/AArch64

  http://modexp.wordpress.com/  
*/

// 72 bytes
    .global _start
    .text

_start:
    // execve("/bin/sh", {"/bin/sh", "-c", cmd, NULL}, NULL);
    eor    x3, x3, x3     // x3 = NULL
    
    adr    x0, sh         // x0 = "/bin/sh"
    adr    x1, c_arg      // x1 = "-c"
    adr    x2, cmd        // x4 = cmd

    push   {x0, x1, x2, x3}
    eor    x2, x2, x2     // penv = NULL
    mov    x1, sp         // r1 = argv
    mov    x8, #221       // x8 = execve
    svc    0  
sh:    
    .ascii "/bin/sh"
c_arg:
    .ascii "-c"
cmd:
    .ascii "echo Hello, World!"

