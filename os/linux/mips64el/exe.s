	.file	1 "exe.c"
	.section .mdebug.abi64
	.previous
	.nan	legacy
	.module	fp=64
	.module	oddspreg
	.abicalls
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align	3
.LC0:
	.ascii	"/bin/sh\000"
	.section	.text.startup,"ax",@progbits
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$sp,32,$31		# vars= 16, regs= 2/0, args= 0, gp= 0
	.mask	0x90000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	daddiu	$sp,$sp,-32
	sd	$28,16($sp)
	lui	$28,%hi(%neg(%gp_rel(main)))
	daddu	$28,$28,$25
	daddiu	$28,$28,%lo(%neg(%gp_rel(main)))
	ld	$4,%got_page(.LC0)($28)
	ld	$25,%call16(execve)($28)
	daddiu	$4,$4,%got_ofst(.LC0)
	move	$5,$sp
	move	$6,$0
	sd	$31,24($sp)
	sd	$4,0($sp)
	.reloc	1f,R_MIPS_JALR,execve
1:	jalr	$25
	sd	$0,8($sp)

	ld	$31,24($sp)
	ld	$28,16($sp)
	move	$2,$0
	jr	$31
	daddiu	$sp,$sp,32

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Debian 6.3.0-18) 6.3.0 20170516"
