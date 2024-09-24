	.file	"Program3.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "Enter an 8-bit InputValue (0-255): \0"
LC1:
	.ascii "%hhu\0"
	.align 4
LC2:
	.ascii "Modified OutputValue with MSB set/reset from InputValue: %u\12\0"
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
	subl	$32, %esp
	call	___main
	movb	$0, 31(%esp)
	movl	$LC0, (%esp)
	call	_printf
	leal	19(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	$0, 24(%esp)
	jmp	L2
L5:
	movzbl	19(%esp), %eax
	movzbl	%al, %edx
	movl	24(%esp), %eax
	movl	%eax, %ecx
	sarl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	movl	%eax, 20(%esp)
	cmpl	$0, 20(%esp)
	je	L3
	movl	24(%esp), %eax
	addl	$4, %eax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	movl	%eax, %edx
	movzbl	31(%esp), %eax
	orl	%edx, %eax
	movb	%al, 31(%esp)
	jmp	L4
L3:
	movl	24(%esp), %eax
	addl	$4, %eax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	notl	%eax
	movl	%eax, %edx
	movzbl	31(%esp), %eax
	andl	%edx, %eax
	movb	%al, 31(%esp)
L4:
	addl	$1, 24(%esp)
L2:
	cmpl	$3, 24(%esp)
	jle	L5
	movzbl	31(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
