	.arch armv8-a
	.file	"exe.c"
	.section	.text.startup,"ax",@progbits
	.align	2
	.global	main
	.type	main, %function
main:
	stp	x29, x30, [sp, -32]!
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	mov	x2, 0
	add	x29, sp, 0
	add	x1, x29, 16
	stp	x0, xzr, [x29, 16]
	bl	execve
	mov	w0, 0
	ldp	x29, x30, [sp], 32
	ret
	.size	main, .-main
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"/bin/sh"
	.ident	"GCC: (Ubuntu/Linaro 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
