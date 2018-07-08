	.file	1 "exe.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align	2
$LC0:
	.ascii	"/bin/sh\000"
	.section	.text.startup,"ax",@progbits
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$sp,40,$31		# vars= 8, regs= 1/0, args= 16, gp= 8
	.mask	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	lw	$2,%got($LC0)($28)
	addiu	$sp,$sp,-40
	lw	$25,%call16(execve)($28)
	move	$6,$0
	addiu	$5,$sp,24
	addiu	$2,$2,%lo($LC0)
	sw	$31,36($sp)
	.cprestore	16
	sw	$0,28($sp)
	move	$4,$2
	.reloc	1f,R_MIPS_JALR,execve
1:	jalr	$25
	sw	$2,24($sp)

	move	$2,$0
	lw	$31,36($sp)
	jr	$31
	addiu	$sp,$sp,40

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Debian 6.3.0-18) 6.3.0 20170516"
