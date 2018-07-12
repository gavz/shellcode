

#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYSCALL(instr, scnum, out) \
do { \
__asm__ __volatile__( \
   "movl %1,%%eax\n" \
   "leal 0f,%%edx\n" /* Set return address for SYSENTER. */ \
   instr "\n" \
   "0:\n" \
   "movl %%eax,%0\n" \
   : "=m" (out) \
   : "i" (scnum) \
   : "eax", "edx", "cc", "memory"); \
} while (0)
 
static void check_pid(int pid, int pid2, const char *instr)
{
   if (pid == pid2)
      return;

   fprintf(stderr, "Pid values differ, instruction: %s\n", instr);
}
 
int
main(void)
{
   int pid, pid2, dummy;

   /* Normal Solaris/x86 syscall instructions. */
   SYSCALL("int $0x91", SYS_getpid, pid);

   /* AMD's syscall instruction. */
   SYSCALL("syscall", SYS_getpid, pid2);
   check_pid(pid, pid2, "syscall");

   /* Intel's sysenter instruction. */
   SYSCALL("sysenter", SYS_getpid, pid2);
   check_pid(pid, pid2, "sysenter");

   /* Linux syscall instructions that are handled as "int $0x91". */
   SYSCALL("int $0x80", SYS_getpid, pid2);
check_pid(pid, pid2, "int $0x80");

  return 0;
}
