	.file	"exe.c"
	.abiversion 2
	.section	".toc","aw"
	.section	".text"
	.section	.rodata
	.align 3
.LC0:
	.string	"/bin/sh"
	.section	".text"
	.align 2
	.globl main
	.type	main, @function
main:
0:	addis 2,12,.TOC.-0b@ha
	addi 2,2,.TOC.-0b@l
	.localentry	main,.-main
	mflr 0
	std 0,16(1)
	std 31,-8(1)
	stdu 1,-64(1)
	mr 31,1
	addis 9,2,.LC0@toc@ha
	addi 9,9,.LC0@toc@l
	std 9,32(31)
	li 9,0
	std 9,40(31)
	addis 3,2,.LC0@toc@ha
	addi 3,3,.LC0@toc@l
	addi 9,31,32
	mr 4,9
	li 5,0
	bl execve
	nop
	li 9,0
	mr 3,9
	addi 1,31,64
	ld 0,16(1)
	mtlr 0
	ld 31,-8(1)
	blr
	.long 0
	.byte 0,0,0,1,128,1,0,1
	.size	main,.-main
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
