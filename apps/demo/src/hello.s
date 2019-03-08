	.cstring
lC0:
	.ascii "Hello, world!\0"
	.section __TEXT,__text_startup,regular,pure_instructions
	.globl _main
_main:
LFB1:
	subl	$24, %esp
LCFI0:
	call	___x86.get_pc_thunk.ax
L1$pb:
	leal	lC0-L1$pb(%eax), %eax
	pushl	%eax
LCFI1:
	call	_printf
	call	_getchar
	movl	$0, %eax
	addl	$28, %esp
LCFI2:
	ret
LFE1:
	.text
	.weak_definition	___x86.get_pc_thunk.ax
	.private_extern	___x86.get_pc_thunk.ax
___x86.get_pc_thunk.ax:
LFB2:
	movl	(%esp), %eax
	ret
LFE2:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x7c
	.byte	0x8
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x5
	.byte	0x4
	.byte	0x88
	.byte	0x1
	.align 2
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.long	LFB1-.
	.set L$set$2,LFE1-LFB1
	.long L$set$2
	.byte	0
	.byte	0x4
	.set L$set$3,LCFI0-LFB1
	.long L$set$3
	.byte	0xe
	.byte	0x1c
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xe
	.byte	0x20
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0xe
	.byte	0x4
	.align 2
LEFDE1:
LSFDE3:
	.set L$set$6,LEFDE3-LASFDE3
	.long L$set$6
LASFDE3:
	.long	LASFDE3-EH_frame1
	.long	LFB2-.
	.set L$set$7,LFE2-LFB2
	.long L$set$7
	.byte	0
	.align 2
LEFDE3:
	.subsections_via_symbols
