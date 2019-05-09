	.file	"main.cpp"
	.text
	.section	.text$_ZNSt14numeric_limitsIdE8infinityEv,"x"
	.linkonce discard
	.globl	_ZNSt14numeric_limitsIdE8infinityEv
	.def	_ZNSt14numeric_limitsIdE8infinityEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt14numeric_limitsIdE8infinityEv
_ZNSt14numeric_limitsIdE8infinityEv:
.LFB928:
	.seh_endprologue
	movsd	.LC0(%rip), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	ret
	.seh_endproc
.lcomm _ZStL8__ioinit,1,1
	.section .rdata,"dr"
	.align 4
_ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
	.section	.text$_ZN4saki5isnanIdLDn0EEEbT_,"x"
	.linkonce discard
	.globl	_ZN4saki5isnanIdLDn0EEEbT_
	.def	_ZN4saki5isnanIdLDn0EEEbT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4saki5isnanIdLDn0EEEbT_
_ZN4saki5isnanIdLDn0EEEbT_:
.LFB5362:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movl	$1, %eax
	movsd	16(%rbp), %xmm0
	ucomisd	16(%rbp), %xmm0
	jp	.L5
	movsd	16(%rbp), %xmm0
	ucomisd	16(%rbp), %xmm0
	jne	.L5
	movl	$0, %eax
.L5:
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN4saki5isinfIdLDn0EEEbT_,"x"
	.linkonce discard
	.globl	_ZN4saki5isinfIdLDn0EEEbT_
	.def	_ZN4saki5isinfIdLDn0EEEbT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4saki5isinfIdLDn0EEEbT_
_ZN4saki5isinfIdLDn0EEEbT_:
.LFB5363:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	call	_ZNSt14numeric_limitsIdE8infinityEv
	ucomisd	16(%rbp), %xmm0
	jp	.L13
	ucomisd	16(%rbp), %xmm0
	je	.L7
.L13:
	call	_ZNSt14numeric_limitsIdE8infinityEv
	movapd	%xmm0, %xmm1
	movq	.LC1(%rip), %xmm0
	xorpd	%xmm1, %xmm0
	ucomisd	16(%rbp), %xmm0
	jp	.L9
	ucomisd	16(%rbp), %xmm0
	jne	.L9
.L7:
	movl	$1, %eax
	jmp	.L11
.L9:
	movl	$0, %eax
.L11:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN4saki7details5pow_nIdiLDn0EEET_S2_T0_,"x"
	.linkonce discard
	.globl	_ZN4saki7details5pow_nIdiLDn0EEET_S2_T0_
	.def	_ZN4saki7details5pow_nIdiLDn0EEET_S2_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4saki7details5pow_nIdiLDn0EEET_S2_T0_
_ZN4saki7details5pow_nIdiLDn0EEET_S2_T0_:
.LFB5382:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movl	%edx, 24(%rbp)
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	cmpl	$0, 24(%rbp)
	jle	.L15
.L18:
	cmpl	$0, 24(%rbp)
	je	.L15
	movl	24(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L16
	movsd	16(%rbp), %xmm0
	jmp	.L17
.L16:
	movsd	.LC2(%rip), %xmm0
.L17:
	movsd	-8(%rbp), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	16(%rbp), %xmm0
	mulsd	16(%rbp), %xmm0
	movsd	%xmm0, 16(%rbp)
	sarl	24(%rbp)
	jmp	.L18
.L15:
	cmpl	$0, 24(%rbp)
	jns	.L19
	negl	24(%rbp)
.L22:
	cmpl	$0, 24(%rbp)
	je	.L19
	movl	24(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L20
	movsd	16(%rbp), %xmm0
	jmp	.L21
.L20:
	movsd	.LC2(%rip), %xmm0
.L21:
	movsd	-8(%rbp), %xmm1
	divsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	16(%rbp), %xmm0
	mulsd	16(%rbp), %xmm0
	movsd	%xmm0, 16(%rbp)
	sarl	24(%rbp)
	jmp	.L22
.L19:
	movsd	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZSt14is_invocable_vIUliE_JiEE:
	.byte	1
	.section	.text$_ZN4saki5ldexpIiiLDn0EEEdT_T0_,"x"
	.linkonce discard
	.globl	_ZN4saki5ldexpIiiLDn0EEEdT_T0_
	.def	_ZN4saki5ldexpIiiLDn0EEEdT_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4saki5ldexpIiiLDn0EEEdT_T0_
_ZN4saki5ldexpIiiLDn0EEEdT_T0_:
.LFB5650:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cvtsi2sd	16(%rbp), %xmm0
	movl	24(%rbp), %eax
	movl	%eax, %edx
	call	_ZN4saki5ldexpIdiLDn0EEET_S1_T0_
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN4saki5ldexpIdiLDn0EEET_S1_T0_,"x"
	.linkonce discard
	.globl	_ZN4saki5ldexpIdiLDn0EEET_S1_T0_
	.def	_ZN4saki5ldexpIdiLDn0EEET_S1_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4saki5ldexpIdiLDn0EEET_S1_T0_
_ZN4saki5ldexpIdiLDn0EEET_S1_T0_:
.LFB5651:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movl	%edx, 24(%rbp)
	movsd	16(%rbp), %xmm0
	call	_ZN4saki5isnanIdLDn0EEEbT_
	testb	%al, %al
	jne	.L27
	movsd	16(%rbp), %xmm0
	call	_ZN4saki5isinfIdLDn0EEEbT_
	testb	%al, %al
	jne	.L27
	pxor	%xmm0, %xmm0
	ucomisd	16(%rbp), %xmm0
	jp	.L33
	pxor	%xmm0, %xmm0
	ucomisd	16(%rbp), %xmm0
	je	.L27
.L33:
	cmpl	$0, 24(%rbp)
	jne	.L29
.L27:
	movl	$1, %eax
	jmp	.L30
.L29:
	movl	$0, %eax
.L30:
	testb	%al, %al
	je	.L31
	movsd	16(%rbp), %xmm0
	jmp	.L32
.L31:
	movl	24(%rbp), %eax
	movq	.LC4(%rip), %rcx
	movl	%eax, %edx
	movq	%rcx, %xmm0
	call	_ZN4saki7details5pow_nIdiLDn0EEET_S2_T0_
	mulsd	16(%rbp), %xmm0
.L32:
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt5ldexpIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_i,"x"
	.linkonce discard
	.globl	_ZSt5ldexpIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_i
	.def	_ZSt5ldexpIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_i;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt5ldexpIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_i
_ZSt5ldexpIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_i:
.LFB5652:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cvtsi2sd	16(%rbp), %xmm0
	movl	24(%rbp), %eax
	movl	%eax, %edx
	call	ldexp
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB5649:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$5, %edx
	movl	$10, %ecx
	call	_ZN4saki5ldexpIiiLDn0EEEdT_T0_
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_Z7CommentIJdELDn0EEvDpRKT_
	movl	$5, %edx
	movl	$10, %ecx
	call	_ZSt5ldexpIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_i
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_Z7CommentIJdELDn0EEvDpRKT_
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z7CommentIJdELDn0EEvDpRKT_,"x"
	.linkonce discard
	.globl	_Z7CommentIJdELDn0EEvDpRKT_
	.def	_Z7CommentIJdELDn0EEvDpRKT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7CommentIJdELDn0EEvDpRKT_
_Z7CommentIJdELDn0EEvDpRKT_:
.LFB6004:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movsd	(%rax), %xmm0
	movapd	%xmm0, %xmm1
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEd
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB6391:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB6390:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L42
	cmpl	$65535, 24(%rbp)
	jne	.L42
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L42:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZN4sakiL7has_x_vI4HasXEE:
	.byte	1
_ZN4sakiL7has_x_vI7NotHasXEE:
	.space 1
	.align 4
_ZN4sakiL16float_constant_vILi10ELy11ELy2EEE:
	.long	1092617345
_ZN4sakiL11can_begin_vISt6vectorIiSaIiEEEE:
	.byte	1
_ZN4sakiL9can_end_vISt6vectorIiSaIiEEEE:
	.byte	1
_ZN4sakiL21can_range_based_for_vISt6vectorIiSaIiEEEE:
	.byte	1
_ZN4sakiL11can_begin_vISt5queueIiSt5dequeIiSaIiEEEEE:
	.space 1
_ZN4sakiL9can_end_vISt5queueIiSt5dequeIiSaIiEEEEE:
	.space 1
_ZN4sakiL21can_range_based_for_vISt5queueIiSt5dequeIiSaIiEEEEE:
	.space 1
_ZN4sakiL17can_equal_equal_vIdEE:
	.byte	1
	.align 8
_ZN4saki7detailsL6sqrt_vILi2EdEE:
	.long	1719614412
	.long	1073127582
	.text
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB6392:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section .rdata,"dr"
	.align 8
.LC0:
	.long	0
	.long	2146435072
	.align 16
.LC1:
	.long	0
	.long	-2147483648
	.long	0
	.long	0
	.align 8
.LC2:
	.long	0
	.long	1072693248
	.align 8
.LC4:
	.long	0
	.long	1073741824
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	ldexp;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEd;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
