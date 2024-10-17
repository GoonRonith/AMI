	.file	"Program4.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "Enter marks for 5 subjects (out of 100):\0"
LC1:
	.ascii "Subject %d: \0"
LC2:
	.ascii "%d\0"
LC10:
	.ascii "\12Total Marks: %d / 500\12\0"
LC11:
	.ascii "Percentage: %.2f%%\12\0"
LC12:
	.ascii "Grade: %c\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$80, %esp
	call	___main
	movl	$0, 76(%esp)
	movl	$LC0, (%esp)
	call	_puts
	movl	$0, 68(%esp)
	jmp	L2
L3:
	movl	68(%esp), %eax
	addl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leal	44(%esp), %eax
	movl	68(%esp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_scanf
	movl	68(%esp), %eax
	movl	44(%esp,%eax,4), %eax
	addl	%eax, 76(%esp)
	addl	$1, 68(%esp)
L2:
	cmpl	$4, 68(%esp)
	jle	L3
	fildl	76(%esp)
	fldl	LC3
	fdivrp	%st, %st(1)
	fldl	LC4
	fmulp	%st, %st(1)
	fstps	64(%esp)
	flds	64(%esp)
	flds	LC5
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jb	L21
	movb	$65, 75(%esp)
	jmp	L6
L21:
	flds	64(%esp)
	flds	LC6
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jb	L22
	movb	$66, 75(%esp)
	jmp	L6
L22:
	flds	64(%esp)
	flds	LC7
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jb	L23
	movb	$67, 75(%esp)
	jmp	L6
L23:
	flds	64(%esp)
	flds	LC8
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jb	L24
	movb	$68, 75(%esp)
	jmp	L6
L24:
	flds	64(%esp)
	flds	LC9
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jb	L25
	movb	$69, 75(%esp)
	jmp	L6
L25:
	movb	$70, 75(%esp)
L6:
	movl	76(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	flds	64(%esp)
	fstpl	4(%esp)
	movl	$LC11, (%esp)
	call	_printf
	movsbl	75(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.section .rdata,"dr"
	.align 8
LC3:
	.long	0
	.long	1082081280
	.align 8
LC4:
	.long	0
	.long	1079574528
	.align 4
LC5:
	.long	1119092736
	.align 4
LC6:
	.long	1117782016
	.align 4
LC7:
	.long	1116471296
	.align 4
LC8:
	.long	1114636288
	.align 4
LC9:
	.long	1109393408
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
