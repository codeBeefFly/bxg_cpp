	.file	"day12_observer_classRoomExample.cpp"
	.text
	.section	.text$_ZnwjPv,"x"
	.linkonce discard
	.globl	__ZnwjPv
	.def	__ZnwjPv;	.scl	2;	.type	32;	.endef
__ZnwjPv:
LFB42:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE42:
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
	.section	.text$_ZN7Monitor10addObseverEP7obsever,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7Monitor10addObseverEP7obsever
	.def	__ZN7Monitor10addObseverEP7obsever;	.scl	2;	.type	32;	.endef
__ZN7Monitor10addObseverEP7obsever:
LFB1882:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$4, %eax
	leal	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorIP7obseverSaIS1_EE9push_backERKS1_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1882:
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "\260\340\263\244\322\321\276\255\265\275\264\357\301\313\304\263\326\326\327\264\314\254\243\254\322\252\310\245\315\250\326\252\271\333\262\354\325\337\301\313\0"
	.section	.text$_ZN7Monitor6notifyENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7Monitor6notifyENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.def	__ZN7Monitor6notifyENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE;	.scl	2;	.type	32;	.endef
__ZN7Monitor6notifyENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
LFB1883:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1883
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$84, %esp
	.cfi_offset 3, -12
	movl	%ecx, -60(%ebp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
LEHB0:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	movl	-60(%ebp), %eax
	addl	$4, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIP7obseverSaIS1_EE5beginEv
	movl	%eax, -44(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIP7obseverSaIS1_EE3endEv
	movl	%eax, -48(%ebp)
L6:
	leal	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxneIPP7obseverSt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_
	testb	%al, %al
	je	L9
	leal	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEdeEv
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %ebx
	leal	-40(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_
LEHE0:
	subl	$4, %esp
	movl	-16(%ebp), %eax
	leal	-40(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB1:
	call	*%ebx
LEHE1:
	subl	$4, %esp
	leal	-40(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	leal	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEppEv
	jmp	L6
L8:
	movl	%eax, %ebx
	leal	-40(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB2:
	call	__Unwind_Resume
LEHE2:
L9:
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1883:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1883:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1883-LLSDACSB1883
LLSDACSB1883:
	.uleb128 LEHB0-LFB1883
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB1883
	.uleb128 LEHE1-LEHB1
	.uleb128 L8-LFB1883
	.uleb128 0
	.uleb128 LEHB2-LFB1883
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE1883:
	.section	.text$_ZN7Monitor6notifyENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"x"
	.linkonce discard
	.section	.text$_ZN2ZS10setSubjectEP7subject,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2ZS10setSubjectEP7subject
	.def	__ZN2ZS10setSubjectEP7subject;	.scl	2;	.type	32;	.endef
__ZN2ZS10setSubjectEP7subject:
LFB1884:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1884:
	.section .rdata,"dr"
LC1:
	.ascii "\325\305\310\375\312\325\265\275\315\250\326\252\243\272\0"
LC2:
	.ascii "  \243\254\262\273\322\252\315\346\323\316\317\267\301\313!\0"
	.section	.text$_ZN2ZS6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2ZS6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.def	__ZN2ZS6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE;	.scl	2;	.type	32;	.endef
__ZN2ZS6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
LFB1885:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1885:
	.section	.text$_ZN2LS10setSubjectEP7subject,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2LS10setSubjectEP7subject
	.def	__ZN2LS10setSubjectEP7subject;	.scl	2;	.type	32;	.endef
__ZN2LS10setSubjectEP7subject:
LFB1886:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1886:
	.section .rdata,"dr"
LC3:
	.ascii "\300\356\313\304\312\325\265\275\315\250\326\252\243\272\0"
LC4:
	.ascii "  \243\254\262\273\322\252\277\264\320\241\313\265\301\313!\0"
	.section	.text$_ZN2LS6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2LS6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.def	__ZN2LS6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE;	.scl	2;	.type	32;	.endef
__ZN2LS6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
LFB1887:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	$LC4, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1887:
	.section	.text$_ZN2WW10setSubjectEP7subject,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2WW10setSubjectEP7subject
	.def	__ZN2WW10setSubjectEP7subject;	.scl	2;	.type	32;	.endef
__ZN2WW10setSubjectEP7subject:
LFB1888:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1888:
	.section .rdata,"dr"
LC5:
	.ascii "\315\365\316\345\312\325\265\275\315\250\326\252\243\272\0"
LC6:
	.ascii "  \243\254\262\273\322\252\301\304\314\354\301\313!\0"
	.section	.text$_ZN2WW6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2WW6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.def	__ZN2WW6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE;	.scl	2;	.type	32;	.endef
__ZN2WW6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
LFB1889:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$LC5, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	$LC6, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1889:
	.section	.text$_ZN7subjectC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7subjectC2Ev
	.def	__ZN7subjectC2Ev;	.scl	2;	.type	32;	.endef
__ZN7subjectC2Ev:
LFB1893:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$__ZTV7subject+8, %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1893:
	.section	.text$_ZN7subjectD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7subjectD2Ev
	.def	__ZN7subjectD2Ev;	.scl	2;	.type	32;	.endef
__ZN7subjectD2Ev:
LFB1896:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$__ZTV7subject+8, %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1896:
	.section	.text$_ZNSt12_Vector_baseIP7obseverSaIS1_EE12_Vector_implD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIP7obseverSaIS1_EE12_Vector_implD1Ev
	.def	__ZNSt12_Vector_baseIP7obseverSaIS1_EE12_Vector_implD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIP7obseverSaIS1_EE12_Vector_implD1Ev:
LFB1903:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIP7obseverED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1903:
	.section	.text$_ZNSt12_Vector_baseIP7obseverSaIS1_EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIP7obseverSaIS1_EEC2Ev
	.def	__ZNSt12_Vector_baseIP7obseverSaIS1_EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIP7obseverSaIS1_EEC2Ev:
LFB1904:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE12_Vector_implC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1904:
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIP7obseverSaIS1_EEC1Ev
	.def	__ZNSt6vectorIP7obseverSaIS1_EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIP7obseverSaIS1_EEC1Ev:
LFB1907:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EEC2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1907:
	.section	.text$_ZN7MonitorC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7MonitorC1Ev
	.def	__ZN7MonitorC1Ev;	.scl	2;	.type	32;	.endef
__ZN7MonitorC1Ev:
LFB1909:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7subjectC2Ev
	movl	$__ZTV7Monitor+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	addl	$4, %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIP7obseverSaIS1_EEC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1909:
	.section	.text$_ZN7obseverC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7obseverC2Ev
	.def	__ZN7obseverC2Ev;	.scl	2;	.type	32;	.endef
__ZN7obseverC2Ev:
LFB1912:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$__ZTV7obsever+8, %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1912:
	.section	.text$_ZN7obseverD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7obseverD2Ev
	.def	__ZN7obseverD2Ev;	.scl	2;	.type	32;	.endef
__ZN7obseverD2Ev:
LFB1915:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$__ZTV7obsever+8, %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1915:
	.section	.text$_ZN2ZSC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2ZSC1Ev
	.def	__ZN2ZSC1Ev;	.scl	2;	.type	32;	.endef
__ZN2ZSC1Ev:
LFB1919:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7obseverC2Ev
	movl	$__ZTV2ZS+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1919:
	.section	.text$_ZN2LSC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2LSC1Ev
	.def	__ZN2LSC1Ev;	.scl	2;	.type	32;	.endef
__ZN2LSC1Ev:
LFB1922:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7obseverC2Ev
	movl	$__ZTV2LS+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1922:
	.section	.text$_ZN2WWC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2WWC1Ev
	.def	__ZN2WWC1Ev;	.scl	2;	.type	32;	.endef
__ZN2WWC1Ev:
LFB1925:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7obseverC2Ev
	movl	$__ZTV2WW+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1925:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC7:
	.ascii "i ----> \0"
LC8:
	.ascii "\260\340\326\367\310\316\300\264\301\313\243\241\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1890:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1890
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$64, %esp
	call	___main
	movl	$16, (%esp)
LEHB3:
	call	__Znwj
	movl	%eax, %ebx
	movl	$0, (%ebx)
	movl	$0, 4(%ebx)
	movl	$0, 8(%ebx)
	movl	$0, 12(%ebx)
	movl	%ebx, %ecx
	call	__ZN7MonitorC1Ev
	movl	%ebx, -16(%ebp)
	movl	$8, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	$0, (%ebx)
	movl	$0, 4(%ebx)
	movl	%ebx, %ecx
	call	__ZN2ZSC1Ev
	movl	%ebx, -20(%ebp)
	movl	$8, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	$0, (%ebx)
	movl	$0, 4(%ebx)
	movl	%ebx, %ecx
	call	__ZN2LSC1Ev
	movl	%ebx, -24(%ebp)
	movl	$8, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	$0, (%ebx)
	movl	$0, 4(%ebx)
	movl	%ebx, %ecx
	call	__ZN2WWC1Ev
	movl	%ebx, -28(%ebp)
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	*%edx
	subl	$4, %esp
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	*%edx
	subl	$4, %esp
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	movl	-28(%ebp), %ecx
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	*%edx
	subl	$4, %esp
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %eax
	movl	-16(%ebp), %ecx
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	*%edx
	subl	$4, %esp
	movl	-24(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	-24(%ebp), %eax
	movl	-16(%ebp), %ecx
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	*%edx
	subl	$4, %esp
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %edx
	movl	-28(%ebp), %eax
	movl	-16(%ebp), %ecx
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	*%edx
	subl	$4, %esp
	movl	$1, -12(%ebp)
L30:
	cmpl	$19, -12(%ebp)
	jg	L28
	movl	$LC7, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
LEHE3:
	subl	$4, %esp
	movl	-12(%ebp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	%ecx, %eax
	subl	%edx, %eax
	testl	%eax, %eax
	jne	L29
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %ebx
	leal	-29(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcEC1Ev
	leal	-56(%ebp), %eax
	leal	-29(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	$LC8, (%esp)
	movl	%eax, %ecx
LEHB4:
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
LEHE4:
	subl	$8, %esp
	movl	-16(%ebp), %eax
	leal	-56(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB5:
	call	*%ebx
LEHE5:
	subl	$4, %esp
	leal	-56(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	leal	-29(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcED1Ev
L29:
	movl	$1000, (%esp)
LEHB6:
	call	_Sleep@4
	subl	$4, %esp
	addl	$1, -12(%ebp)
	jmp	L30
L28:
	movl	$0, %eax
	jmp	L36
L35:
	movl	%eax, %ebx
	leal	-56(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	L33
L34:
	movl	%eax, %ebx
L33:
	leal	-29(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE6:
L36:
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1890:
	.section	.gcc_except_table,"w"
LLSDA1890:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1890-LLSDACSB1890
LLSDACSB1890:
	.uleb128 LEHB3-LFB1890
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB4-LFB1890
	.uleb128 LEHE4-LEHB4
	.uleb128 L34-LFB1890
	.uleb128 0
	.uleb128 LEHB5-LFB1890
	.uleb128 LEHE5-LEHB5
	.uleb128 L35-LFB1890
	.uleb128 0
	.uleb128 LEHB6-LFB1890
	.uleb128 LEHE6-LEHB6
	.uleb128 0
	.uleb128 0
LLSDACSE1890:
	.text
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EE9push_backERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIP7obseverSaIS1_EE9push_backERKS1_
	.def	__ZNSt6vectorIP7obseverSaIS1_EE9push_backERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIP7obseverSaIS1_EE9push_backERKS1_:
LFB2161:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	je	L38
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIP7obseverEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	leal	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	jmp	L40
L38:
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIP7obseverSaIS1_EE3endEv
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorIP7obseverSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	subl	$8, %esp
L40:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE2161:
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIP7obseverSaIS1_EE5beginEv
	.def	__ZNSt6vectorIP7obseverSaIS1_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIP7obseverSaIS1_EE5beginEv:
LFB2165:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEC1ERKS3_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2165:
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIP7obseverSaIS1_EE3endEv
	.def	__ZNSt6vectorIP7obseverSaIS1_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIP7obseverSaIS1_EE3endEv:
LFB2166:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEC1ERKS3_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2166:
	.section	.text$_ZN9__gnu_cxxneIPP7obseverSt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxxneIPP7obseverSt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_
	.def	__ZN9__gnu_cxxneIPP7obseverSt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxneIPP7obseverSt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_:
LFB2167:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	cmpl	%eax, %ebx
	setne	%al
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2167:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEppEv
	.def	__ZN9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEppEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEppEv:
LFB2168:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leal	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2168:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEdeEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEdeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEdeEv:
LFB2169:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2169:
	.section	.text$_ZNSt12_Vector_baseIP7obseverSaIS1_EE12_Vector_implC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIP7obseverSaIS1_EE12_Vector_implC1Ev
	.def	__ZNSt12_Vector_baseIP7obseverSaIS1_EE12_Vector_implC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIP7obseverSaIS1_EE12_Vector_implC1Ev:
LFB2176:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIP7obseverEC2Ev
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE17_Vector_impl_dataC2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2176:
	.section	.text$_ZNSaIP7obseverED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIP7obseverED2Ev
	.def	__ZNSaIP7obseverED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaIP7obseverED2Ev:
LFB2178:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorIP7obseverED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2178:
	.section	.text$_ZNSt12_Vector_baseIP7obseverSaIS1_EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIP7obseverSaIS1_EED2Ev
	.def	__ZNSt12_Vector_baseIP7obseverSaIS1_EED2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIP7obseverSaIS1_EED2Ev:
LFB2181:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2181
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$2, %eax
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE13_M_deallocateEPS1_j
	subl	$8, %esp
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE12_Vector_implD1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2181:
	.section	.gcc_except_table,"w"
LLSDA2181:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2181-LLSDACSB2181
LLSDACSB2181:
LLSDACSE2181:
	.section	.text$_ZNSt12_Vector_baseIP7obseverSaIS1_EED2Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIP7obseverSaIS1_EED1Ev
	.def	__ZNSt6vectorIP7obseverSaIS1_EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIP7obseverSaIS1_EED1Ev:
LFB2185:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2185
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv
	movl	-12(%ebp), %edx
	movl	4(%edx), %ecx
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt8_DestroyIPP7obseverS1_EvT_S3_RSaIT0_E
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2185:
	.section	.gcc_except_table,"w"
LLSDA2185:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE2185-LLSDACSB2185
LLSDACSB2185:
LLSDACSE2185:
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EED1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt16allocator_traitsISaIP7obseverEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIP7obseverEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_
	.def	__ZNSt16allocator_traitsISaIP7obseverEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIP7obseverEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_:
LFB2291:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKP7obseverEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIP7obseverE9constructIS2_JRKS2_EEEvPT_DpOT0_
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2291:
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EE15_S_use_relocateEv,"x"
	.linkonce discard
	.globl	__ZNSt6vectorIP7obseverSaIS1_EE15_S_use_relocateEv
	.def	__ZNSt6vectorIP7obseverSaIS1_EE15_S_use_relocateEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIP7obseverSaIS1_EE15_S_use_relocateEv:
LFB2293:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	%al, (%esp)
	call	__ZNSt6vectorIP7obseverSaIS1_EE19_S_nothrow_relocateESt17integral_constantIbLb1EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2293:
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EE19_S_nothrow_relocateESt17integral_constantIbLb1EE,"x"
	.linkonce discard
	.globl	__ZNSt6vectorIP7obseverSaIS1_EE19_S_nothrow_relocateESt17integral_constantIbLb1EE
	.def	__ZNSt6vectorIP7obseverSaIS1_EE19_S_nothrow_relocateESt17integral_constantIbLb1EE;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIP7obseverSaIS1_EE19_S_nothrow_relocateESt17integral_constantIbLb1EE:
LFB2294:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$1, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2294:
	.section .rdata,"dr"
LC9:
	.ascii "vector::_M_realloc_insert\0"
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIP7obseverSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	.def	__ZNSt6vectorIP7obseverSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIP7obseverSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_:
LFB2292:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA2292
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	%ecx, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	$LC9, 4(%esp)
	movl	$1, (%esp)
	movl	%eax, %ecx
LEHB7:
	call	__ZNKSt6vectorIP7obseverSaIS1_EE12_M_check_lenEjPKc
	subl	$8, %esp
	movl	%eax, -16(%ebp)
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	-44(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIP7obseverSaIS1_EE5beginEv
	movl	%eax, -36(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxmiIPP7obseverSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_
	movl	%eax, -28(%ebp)
	movl	-44(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE11_M_allocateEj
LEHE7:
	subl	$4, %esp
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKP7obseverEOT_RNSt16remove_referenceIS4_E4typeE
	movl	-28(%ebp), %edx
	leal	0(,%edx,4), %ecx
	movl	-32(%ebp), %edx
	addl	%edx, %ecx
	movl	-44(%ebp), %edx
	movl	%eax, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSt16allocator_traitsISaIP7obseverEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_
	movl	$0, -12(%ebp)
	call	__ZNSt6vectorIP7obseverSaIS1_EE15_S_use_relocateEv
	testb	%al, %al
	je	L61
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6vectorIP7obseverSaIS1_EE11_S_relocateEPS1_S4_S4_RS2_
	movl	%eax, -12(%ebp)
	addl	$4, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt6vectorIP7obseverSaIS1_EE11_S_relocateEPS1_S4_S4_RS2_
	movl	%eax, -12(%ebp)
	jmp	L62
L61:
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
LEHB8:
	call	__ZSt34__uninitialized_move_if_noexcept_aIPP7obseverS2_SaIS1_EET0_T_S5_S4_RT1_
	movl	%eax, -12(%ebp)
	addl	$4, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt34__uninitialized_move_if_noexcept_aIPP7obseverS2_SaIS1_EET0_T_S5_S4_RT1_
LEHE8:
	movl	%eax, -12(%ebp)
L62:
	call	__ZNSt6vectorIP7obseverSaIS1_EE15_S_use_relocateEv
	xorl	$1, %eax
	testb	%al, %al
	je	L63
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
LEHB9:
	call	__ZSt8_DestroyIPP7obseverS1_EvT_S3_RSaIT0_E
L63:
	movl	-44(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	8(%edx), %edx
	subl	-20(%ebp), %edx
	sarl	$2, %edx
	movl	%edx, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE13_M_deallocateEPS1_j
LEHE9:
	subl	$8, %esp
	movl	-44(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%eax)
	movl	-44(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 8(%eax)
	jmp	L70
L68:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	cmpl	$0, -12(%ebp)
	jne	L65
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIP7obseverEE7destroyIS1_EEvRS2_PT_
	jmp	L66
L65:
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
LEHB10:
	call	__ZSt8_DestroyIPP7obseverS1_EvT_S3_RSaIT0_E
L66:
	movl	-44(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIP7obseverSaIS1_EE13_M_deallocateEPS1_j
	subl	$8, %esp
	call	___cxa_rethrow
LEHE10:
L69:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB11:
	call	__Unwind_Resume
LEHE11:
L70:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE2292:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA2292:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT2292-LLSDATTD2292
LLSDATTD2292:
	.byte	0x1
	.uleb128 LLSDACSE2292-LLSDACSB2292
LLSDACSB2292:
	.uleb128 LEHB7-LFB2292
	.uleb128 LEHE7-LEHB7
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB8-LFB2292
	.uleb128 LEHE8-LEHB8
	.uleb128 L68-LFB2292
	.uleb128 0x1
	.uleb128 LEHB9-LFB2292
	.uleb128 LEHE9-LEHB9
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB10-LFB2292
	.uleb128 LEHE10-LEHB10
	.uleb128 L69-LFB2292
	.uleb128 0
	.uleb128 LEHB11-LFB2292
	.uleb128 LEHE11-LEHB11
	.uleb128 0
	.uleb128 0
LLSDACSE2292:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT2292:
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEC1ERKS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEC1ERKS3_
	.def	__ZN9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEC1ERKS3_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEEC1ERKS3_:
LFB2300:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE2300:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv:
LFB2301:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2301:
	.section	.text$_ZNSaIP7obseverEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIP7obseverEC2Ev
	.def	__ZNSaIP7obseverEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSaIP7obseverEC2Ev:
LFB2306:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorIP7obseverEC2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2306:
	.section	.text$_ZNSt12_Vector_baseIP7obseverSaIS1_EE17_Vector_impl_dataC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIP7obseverSaIS1_EE17_Vector_impl_dataC2Ev
	.def	__ZNSt12_Vector_baseIP7obseverSaIS1_EE17_Vector_impl_dataC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIP7obseverSaIS1_EE17_Vector_impl_dataC2Ev:
LFB2309:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	$0, (%eax)
	movl	-4(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-4(%ebp), %eax
	movl	$0, 8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2309:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIP7obseverED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIP7obseverED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIP7obseverED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIP7obseverED2Ev:
LFB2312:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2312:
	.section	.text$_ZNSt12_Vector_baseIP7obseverSaIS1_EE13_M_deallocateEPS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIP7obseverSaIS1_EE13_M_deallocateEPS1_j
	.def	__ZNSt12_Vector_baseIP7obseverSaIS1_EE13_M_deallocateEPS1_j;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIP7obseverSaIS1_EE13_M_deallocateEPS1_j:
LFB2314:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L79
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIP7obseverEE10deallocateERS2_PS1_j
L79:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE2314:
	.section	.text$_ZNSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv
	.def	__ZNSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv:
LFB2315:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2315:
	.section	.text$_ZSt8_DestroyIPP7obseverS1_EvT_S3_RSaIT0_E,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIPP7obseverS1_EvT_S3_RSaIT0_E
	.def	__ZSt8_DestroyIPP7obseverS1_EvT_S3_RSaIT0_E;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIPP7obseverS1_EvT_S3_RSaIT0_E:
LFB2316:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIPP7obseverEvT_S3_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2316:
	.section	.text$_ZSt7forwardIRKP7obseverEOT_RNSt16remove_referenceIS4_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRKP7obseverEOT_RNSt16remove_referenceIS4_E4typeE
	.def	__ZSt7forwardIRKP7obseverEOT_RNSt16remove_referenceIS4_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRKP7obseverEOT_RNSt16remove_referenceIS4_E4typeE:
LFB2347:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2347:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIP7obseverE9constructIS2_JRKS2_EEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIP7obseverE9constructIS2_JRKS2_EEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorIP7obseverE9constructIS2_JRKS2_EEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIP7obseverE9constructIS2_JRKS2_EEEvPT_DpOT0_:
LFB2348:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKP7obseverEOT_RNSt16remove_referenceIS4_E4typeE
	movl	(%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjPv
	movl	%ebx, (%eax)
	nop
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE2348:
	.section	.text$_ZNKSt6vectorIP7obseverSaIS1_EE12_M_check_lenEjPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIP7obseverSaIS1_EE12_M_check_lenEjPKc
	.def	__ZNKSt6vectorIP7obseverSaIS1_EE12_M_check_lenEjPKc;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIP7obseverSaIS1_EE12_M_check_lenEjPKc:
LFB2349:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIP7obseverSaIS1_EE8max_sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIP7obseverSaIS1_EE4sizeEv
	movl	%ebx, %edx
	subl	%eax, %edx
	movl	8(%ebp), %eax
	cmpl	%eax, %edx
	setb	%al
	testb	%al, %al
	je	L87
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt20__throw_length_errorPKc
L87:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIP7obseverSaIS1_EE4sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIP7obseverSaIS1_EE4sizeEv
	movl	%eax, -16(%ebp)
	leal	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3maxIjERKT_S2_S2_
	movl	(%eax), %eax
	addl	%ebx, %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIP7obseverSaIS1_EE4sizeEv
	cmpl	%eax, -12(%ebp)
	jb	L88
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIP7obseverSaIS1_EE8max_sizeEv
	cmpl	%eax, -12(%ebp)
	jbe	L89
L88:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIP7obseverSaIS1_EE8max_sizeEv
	jmp	L90
L89:
	movl	-12(%ebp), %eax
L90:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE2349:
	.section	.text$_ZN9__gnu_cxxmiIPP7obseverSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxxmiIPP7obseverSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_
	.def	__ZN9__gnu_cxxmiIPP7obseverSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxmiIPP7obseverSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_:
LFB2350:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPP7obseverSt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	subl	%eax, %ebx
	movl	%ebx, %eax
	sarl	$2, %eax
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2350:
	.section	.text$_ZNSt12_Vector_baseIP7obseverSaIS1_EE11_M_allocateEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIP7obseverSaIS1_EE11_M_allocateEj
	.def	__ZNSt12_Vector_baseIP7obseverSaIS1_EE11_M_allocateEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIP7obseverSaIS1_EE11_M_allocateEj:
LFB2351:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L95
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIP7obseverEE8allocateERS2_j
	jmp	L97
L95:
	movl	$0, %eax
L97:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE2351:
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EE11_S_relocateEPS1_S4_S4_RS2_,"x"
	.linkonce discard
	.globl	__ZNSt6vectorIP7obseverSaIS1_EE11_S_relocateEPS1_S4_S4_RS2_
	.def	__ZNSt6vectorIP7obseverSaIS1_EE11_S_relocateEPS1_S4_S4_RS2_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIP7obseverSaIS1_EE11_S_relocateEPS1_S4_S4_RS2_:
LFB2352:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movb	%al, 16(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6vectorIP7obseverSaIS1_EE14_S_do_relocateEPS1_S4_S4_RS2_St17integral_constantIbLb1EE
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2352:
	.section	.text$_ZSt34__uninitialized_move_if_noexcept_aIPP7obseverS2_SaIS1_EET0_T_S5_S4_RT1_,"x"
	.linkonce discard
	.globl	__ZSt34__uninitialized_move_if_noexcept_aIPP7obseverS2_SaIS1_EET0_T_S5_S4_RT1_
	.def	__ZSt34__uninitialized_move_if_noexcept_aIPP7obseverS2_SaIS1_EET0_T_S5_S4_RT1_;	.scl	2;	.type	32;	.endef
__ZSt34__uninitialized_move_if_noexcept_aIPP7obseverS2_SaIS1_EET0_T_S5_S4_RT1_:
LFB2353:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt32__make_move_if_noexcept_iteratorIP7obseverSt13move_iteratorIPS1_EET0_PT_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt32__make_move_if_noexcept_iteratorIP7obseverSt13move_iteratorIPS1_EET0_PT_
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt22__uninitialized_copy_aISt13move_iteratorIPP7obseverES3_S2_ET0_T_S6_S5_RSaIT1_E
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2353:
	.section	.text$_ZNSt16allocator_traitsISaIP7obseverEE7destroyIS1_EEvRS2_PT_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIP7obseverEE7destroyIS1_EEvRS2_PT_
	.def	__ZNSt16allocator_traitsISaIP7obseverEE7destroyIS1_EEvRS2_PT_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIP7obseverEE7destroyIS1_EEvRS2_PT_:
LFB2354:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIP7obseverE7destroyIS2_EEvPT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2354:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIP7obseverEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIP7obseverEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIP7obseverEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIP7obseverEC2Ev:
LFB2360:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2360:
	.section	.text$_ZNSt16allocator_traitsISaIP7obseverEE10deallocateERS2_PS1_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIP7obseverEE10deallocateERS2_PS1_j
	.def	__ZNSt16allocator_traitsISaIP7obseverEE10deallocateERS2_PS1_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIP7obseverEE10deallocateERS2_PS1_j:
LFB2362:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIP7obseverE10deallocateEPS2_j
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2362:
	.section	.text$_ZSt8_DestroyIPP7obseverEvT_S3_,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIPP7obseverEvT_S3_
	.def	__ZSt8_DestroyIPP7obseverEvT_S3_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIPP7obseverEvT_S3_:
LFB2363:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Destroy_auxILb1EE9__destroyIPP7obseverEEvT_S5_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2363:
	.section	.text$_ZNKSt6vectorIP7obseverSaIS1_EE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIP7obseverSaIS1_EE8max_sizeEv
	.def	__ZNKSt6vectorIP7obseverSaIS1_EE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIP7obseverSaIS1_EE8max_sizeEv:
LFB2395:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, (%esp)
	call	__ZNSt6vectorIP7obseverSaIS1_EE11_S_max_sizeERKS2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2395:
	.section	.text$_ZNKSt6vectorIP7obseverSaIS1_EE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIP7obseverSaIS1_EE4sizeEv
	.def	__ZNKSt6vectorIP7obseverSaIS1_EE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIP7obseverSaIS1_EE4sizeEv:
LFB2396:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$2, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2396:
	.section	.text$_ZSt3maxIjERKT_S2_S2_,"x"
	.linkonce discard
	.globl	__ZSt3maxIjERKT_S2_S2_
	.def	__ZSt3maxIjERKT_S2_S2_;	.scl	2;	.type	32;	.endef
__ZSt3maxIjERKT_S2_S2_:
LFB2397:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jnb	L111
	movl	12(%ebp), %eax
	jmp	L112
L111:
	movl	8(%ebp), %eax
L112:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2397:
	.section	.text$_ZNSt16allocator_traitsISaIP7obseverEE8allocateERS2_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIP7obseverEE8allocateERS2_j
	.def	__ZNSt16allocator_traitsISaIP7obseverEE8allocateERS2_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIP7obseverEE8allocateERS2_j:
LFB2398:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIP7obseverE8allocateEjPKv
	subl	$8, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2398:
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EE14_S_do_relocateEPS1_S4_S4_RS2_St17integral_constantIbLb1EE,"x"
	.linkonce discard
	.globl	__ZNSt6vectorIP7obseverSaIS1_EE14_S_do_relocateEPS1_S4_S4_RS2_St17integral_constantIbLb1EE
	.def	__ZNSt6vectorIP7obseverSaIS1_EE14_S_do_relocateEPS1_S4_S4_RS2_St17integral_constantIbLb1EE;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIP7obseverSaIS1_EE14_S_do_relocateEPS1_S4_S4_RS2_St17integral_constantIbLb1EE:
LFB2399:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__relocate_aIPP7obseverS2_SaIS1_EET0_T_S5_S4_RT1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2399:
	.section	.text$_ZSt32__make_move_if_noexcept_iteratorIP7obseverSt13move_iteratorIPS1_EET0_PT_,"x"
	.linkonce discard
	.globl	__ZSt32__make_move_if_noexcept_iteratorIP7obseverSt13move_iteratorIPS1_EET0_PT_
	.def	__ZSt32__make_move_if_noexcept_iteratorIP7obseverSt13move_iteratorIPS1_EET0_PT_;	.scl	2;	.type	32;	.endef
__ZSt32__make_move_if_noexcept_iteratorIP7obseverSt13move_iteratorIPS1_EET0_PT_:
LFB2400:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt13move_iteratorIPP7obseverEC1ES2_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2400:
	.section	.text$_ZSt22__uninitialized_copy_aISt13move_iteratorIPP7obseverES3_S2_ET0_T_S6_S5_RSaIT1_E,"x"
	.linkonce discard
	.globl	__ZSt22__uninitialized_copy_aISt13move_iteratorIPP7obseverES3_S2_ET0_T_S6_S5_RSaIT1_E
	.def	__ZSt22__uninitialized_copy_aISt13move_iteratorIPP7obseverES3_S2_ET0_T_S6_S5_RSaIT1_E;	.scl	2;	.type	32;	.endef
__ZSt22__uninitialized_copy_aISt13move_iteratorIPP7obseverES3_S2_ET0_T_S6_S5_RSaIT1_E:
LFB2401:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt18uninitialized_copyISt13move_iteratorIPP7obseverES3_ET0_T_S6_S5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2401:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIP7obseverE7destroyIS2_EEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIP7obseverE7destroyIS2_EEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorIP7obseverE7destroyIS2_EEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIP7obseverE7destroyIS2_EEvPT_:
LFB2402:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE2402:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIP7obseverE10deallocateEPS2_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIP7obseverE10deallocateEPS2_j
	.def	__ZN9__gnu_cxx13new_allocatorIP7obseverE10deallocateEPS2_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIP7obseverE10deallocateEPS2_j:
LFB2404:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE2404:
	.section	.text$_ZNSt12_Destroy_auxILb1EE9__destroyIPP7obseverEEvT_S5_,"x"
	.linkonce discard
	.globl	__ZNSt12_Destroy_auxILb1EE9__destroyIPP7obseverEEvT_S5_
	.def	__ZNSt12_Destroy_auxILb1EE9__destroyIPP7obseverEEvT_S5_;	.scl	2;	.type	32;	.endef
__ZNSt12_Destroy_auxILb1EE9__destroyIPP7obseverEEvT_S5_:
LFB2405:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2405:
	.section	.text$_ZNSt6vectorIP7obseverSaIS1_EE11_S_max_sizeERKS2_,"x"
	.linkonce discard
	.globl	__ZNSt6vectorIP7obseverSaIS1_EE11_S_max_sizeERKS2_
	.def	__ZNSt6vectorIP7obseverSaIS1_EE11_S_max_sizeERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIP7obseverSaIS1_EE11_S_max_sizeERKS2_:
LFB2433:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$536870911, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIP7obseverEE8max_sizeERKS2_
	movl	%eax, -16(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3minIjERKT_S2_S2_
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2433:
	.section	.text$_ZNKSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv
	.def	__ZNKSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNKSt12_Vector_baseIP7obseverSaIS1_EE19_M_get_Tp_allocatorEv:
LFB2434:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2434:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIP7obseverE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIP7obseverE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorIP7obseverE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIP7obseverE8allocateEjPKv:
LFB2435:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx13new_allocatorIP7obseverE8max_sizeEv
	cmpl	%eax, 8(%ebp)
	seta	%al
	testb	%al, %al
	je	L129
	call	__ZSt17__throw_bad_allocv
L129:
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE2435:
	.section	.text$_ZSt12__relocate_aIPP7obseverS2_SaIS1_EET0_T_S5_S4_RT1_,"x"
	.linkonce discard
	.globl	__ZSt12__relocate_aIPP7obseverS2_SaIS1_EET0_T_S5_S4_RT1_
	.def	__ZSt12__relocate_aIPP7obseverS2_SaIS1_EET0_T_S5_S4_RT1_;	.scl	2;	.type	32;	.endef
__ZSt12__relocate_aIPP7obseverS2_SaIS1_EET0_T_S5_S4_RT1_:
LFB2436:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP7obseverET_S3_
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP7obseverET_S3_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP7obseverET_S3_
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt14__relocate_a_1IP7obseverS1_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS4_E4typeES6_S6_S6_RSaIT0_E
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2436:
	.section	.text$_ZNSt13move_iteratorIPP7obseverEC1ES2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13move_iteratorIPP7obseverEC1ES2_
	.def	__ZNSt13move_iteratorIPP7obseverEC1ES2_;	.scl	2;	.type	32;	.endef
__ZNSt13move_iteratorIPP7obseverEC1ES2_:
LFB2439:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE2439:
	.section	.text$_ZSt18uninitialized_copyISt13move_iteratorIPP7obseverES3_ET0_T_S6_S5_,"x"
	.linkonce discard
	.globl	__ZSt18uninitialized_copyISt13move_iteratorIPP7obseverES3_ET0_T_S6_S5_
	.def	__ZSt18uninitialized_copyISt13move_iteratorIPP7obseverES3_ET0_T_S6_S5_;	.scl	2;	.type	32;	.endef
__ZSt18uninitialized_copyISt13move_iteratorIPP7obseverES3_ET0_T_S6_S5_:
LFB2440:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$1, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP7obseverES5_EET0_T_S8_S7_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2440:
	.section	.text$_ZNSt16allocator_traitsISaIP7obseverEE8max_sizeERKS2_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIP7obseverEE8max_sizeERKS2_
	.def	__ZNSt16allocator_traitsISaIP7obseverEE8max_sizeERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIP7obseverEE8max_sizeERKS2_:
LFB2465:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx13new_allocatorIP7obseverE8max_sizeEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2465:
	.section	.text$_ZSt3minIjERKT_S2_S2_,"x"
	.linkonce discard
	.globl	__ZSt3minIjERKT_S2_S2_
	.def	__ZSt3minIjERKT_S2_S2_;	.scl	2;	.type	32;	.endef
__ZSt3minIjERKT_S2_S2_:
LFB2466:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jnb	L139
	movl	12(%ebp), %eax
	jmp	L140
L139:
	movl	8(%ebp), %eax
L140:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2466:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorIP7obseverE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorIP7obseverE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorIP7obseverE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorIP7obseverE8max_sizeEv:
LFB2467:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$536870911, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2467:
	.section	.text$_ZSt12__niter_baseIPP7obseverET_S3_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_baseIPP7obseverET_S3_
	.def	__ZSt12__niter_baseIPP7obseverET_S3_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_baseIPP7obseverET_S3_:
LFB2468:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2468:
	.section	.text$_ZSt14__relocate_a_1IP7obseverS1_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS4_E4typeES6_S6_S6_RSaIT0_E,"x"
	.linkonce discard
	.globl	__ZSt14__relocate_a_1IP7obseverS1_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS4_E4typeES6_S6_S6_RSaIT0_E
	.def	__ZSt14__relocate_a_1IP7obseverS1_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS4_E4typeES6_S6_S6_RSaIT0_E;	.scl	2;	.type	32;	.endef
__ZSt14__relocate_a_1IP7obseverS1_ENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS4_E4typeES6_S6_S6_RSaIT0_E:
LFB2469:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	sarl	$2, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jle	L146
	movl	-12(%ebp), %eax
	sall	$2, %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_memmove
L146:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2469:
	.section	.text$_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP7obseverES5_EET0_T_S8_S7_,"x"
	.linkonce discard
	.globl	__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP7obseverES5_EET0_T_S8_S7_
	.def	__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP7obseverES5_EET0_T_S8_S7_;	.scl	2;	.type	32;	.endef
__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP7obseverES5_EET0_T_S8_S7_:
LFB2470:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4copyISt13move_iteratorIPP7obseverES3_ET0_T_S6_S5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2470:
	.section	.text$_ZSt4copyISt13move_iteratorIPP7obseverES3_ET0_T_S6_S5_,"x"
	.linkonce discard
	.globl	__ZSt4copyISt13move_iteratorIPP7obseverES3_ET0_T_S6_S5_
	.def	__ZSt4copyISt13move_iteratorIPP7obseverES3_ET0_T_S6_S5_;	.scl	2;	.type	32;	.endef
__ZSt4copyISt13move_iteratorIPP7obseverES3_ET0_T_S6_S5_:
LFB2479:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPP7obseverEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPP7obseverEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt14__copy_move_a2ILb1EPP7obseverS2_ET1_T0_S4_S3_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2479:
	.section	.text$_ZSt12__miter_baseIPP7obseverEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E,"x"
	.linkonce discard
	.globl	__ZSt12__miter_baseIPP7obseverEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E
	.def	__ZSt12__miter_baseIPP7obseverEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E;	.scl	2;	.type	32;	.endef
__ZSt12__miter_baseIPP7obseverEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E:
LFB2482:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	leal	8(%ebp), %ecx
	call	__ZNKSt13move_iteratorIPP7obseverE4baseEv
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPP7obseverET_S3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2482:
	.section	.text$_ZSt14__copy_move_a2ILb1EPP7obseverS2_ET1_T0_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt14__copy_move_a2ILb1EPP7obseverS2_ET1_T0_S4_S3_
	.def	__ZSt14__copy_move_a2ILb1EPP7obseverS2_ET1_T0_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt14__copy_move_a2ILb1EPP7obseverS2_ET1_T0_S4_S3_:
LFB2483:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP7obseverET_S3_
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP7obseverET_S3_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP7obseverET_S3_
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt13__copy_move_aILb1EPP7obseverS2_ET1_T0_S4_S3_
	movl	%eax, 4(%esp)
	leal	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_wrapIPP7obseverET_RKS3_S3_
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2483:
	.section	.text$_ZNKSt13move_iteratorIPP7obseverE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13move_iteratorIPP7obseverE4baseEv
	.def	__ZNKSt13move_iteratorIPP7obseverE4baseEv;	.scl	2;	.type	32;	.endef
__ZNKSt13move_iteratorIPP7obseverE4baseEv:
LFB2484:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2484:
	.section	.text$_ZSt12__miter_baseIPP7obseverET_S3_,"x"
	.linkonce discard
	.globl	__ZSt12__miter_baseIPP7obseverET_S3_
	.def	__ZSt12__miter_baseIPP7obseverET_S3_;	.scl	2;	.type	32;	.endef
__ZSt12__miter_baseIPP7obseverET_S3_:
LFB2485:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2485:
	.section	.text$_ZSt13__copy_move_aILb1EPP7obseverS2_ET1_T0_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt13__copy_move_aILb1EPP7obseverS2_ET1_T0_S4_S3_
	.def	__ZSt13__copy_move_aILb1EPP7obseverS2_ET1_T0_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt13__copy_move_aILb1EPP7obseverS2_ET1_T0_S4_S3_:
LFB2486:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$1, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP7obseverEEPT_PKS5_S8_S6_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2486:
	.section	.text$_ZSt12__niter_wrapIPP7obseverET_RKS3_S3_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_wrapIPP7obseverET_RKS3_S3_
	.def	__ZSt12__niter_wrapIPP7obseverET_RKS3_S3_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_wrapIPP7obseverET_RKS3_S3_:
LFB2487:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2487:
	.section	.text$_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP7obseverEEPT_PKS5_S8_S6_,"x"
	.linkonce discard
	.globl	__ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP7obseverEEPT_PKS5_S8_S6_
	.def	__ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP7obseverEEPT_PKS5_S8_S6_;	.scl	2;	.type	32;	.endef
__ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP7obseverEEPT_PKS5_S8_S6_:
LFB2488:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	sarl	$2, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L165
	movl	-12(%ebp), %eax
	sall	$2, %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_memmove
L165:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2488:
	.globl	__ZTV2WW
	.section	.rdata$_ZTV2WW,"dr"
	.linkonce same_size
	.align 4
__ZTV2WW:
	.long	0
	.long	__ZTI2WW
	.long	__ZN2WW10setSubjectEP7subject
	.long	__ZN2WW6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.long	__ZN2WWD1Ev
	.long	__ZN2WWD0Ev
	.section	.text$_ZN2WWD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2WWD1Ev
	.def	__ZN2WWD1Ev;	.scl	2;	.type	32;	.endef
__ZN2WWD1Ev:
LFB2491:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV2WW+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7obseverD2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2491:
	.section	.text$_ZN2WWD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2WWD0Ev
	.def	__ZN2WWD0Ev;	.scl	2;	.type	32;	.endef
__ZN2WWD0Ev:
LFB2492:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN2WWD1Ev
	movl	$8, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPvj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2492:
	.globl	__ZTV2LS
	.section	.rdata$_ZTV2LS,"dr"
	.linkonce same_size
	.align 4
__ZTV2LS:
	.long	0
	.long	__ZTI2LS
	.long	__ZN2LS10setSubjectEP7subject
	.long	__ZN2LS6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.long	__ZN2LSD1Ev
	.long	__ZN2LSD0Ev
	.section	.text$_ZN2LSD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2LSD1Ev
	.def	__ZN2LSD1Ev;	.scl	2;	.type	32;	.endef
__ZN2LSD1Ev:
LFB2495:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV2LS+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7obseverD2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2495:
	.section	.text$_ZN2LSD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2LSD0Ev
	.def	__ZN2LSD0Ev;	.scl	2;	.type	32;	.endef
__ZN2LSD0Ev:
LFB2496:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN2LSD1Ev
	movl	$8, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPvj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2496:
	.globl	__ZTV2ZS
	.section	.rdata$_ZTV2ZS,"dr"
	.linkonce same_size
	.align 4
__ZTV2ZS:
	.long	0
	.long	__ZTI2ZS
	.long	__ZN2ZS10setSubjectEP7subject
	.long	__ZN2ZS6updateENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.long	__ZN2ZSD1Ev
	.long	__ZN2ZSD0Ev
	.section	.text$_ZN2ZSD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2ZSD1Ev
	.def	__ZN2ZSD1Ev;	.scl	2;	.type	32;	.endef
__ZN2ZSD1Ev:
LFB2499:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV2ZS+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7obseverD2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2499:
	.section	.text$_ZN2ZSD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN2ZSD0Ev
	.def	__ZN2ZSD0Ev;	.scl	2;	.type	32;	.endef
__ZN2ZSD0Ev:
LFB2500:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN2ZSD1Ev
	movl	$8, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPvj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2500:
	.globl	__ZTV7Monitor
	.section	.rdata$_ZTV7Monitor,"dr"
	.linkonce same_size
	.align 4
__ZTV7Monitor:
	.long	0
	.long	__ZTI7Monitor
	.long	__ZN7Monitor10addObseverEP7obsever
	.long	__ZN7Monitor6notifyENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.long	__ZN7MonitorD1Ev
	.long	__ZN7MonitorD0Ev
	.section	.text$_ZN7MonitorD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7MonitorD1Ev
	.def	__ZN7MonitorD1Ev;	.scl	2;	.type	32;	.endef
__ZN7MonitorD1Ev:
LFB2503:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV7Monitor+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	addl	$4, %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIP7obseverSaIS1_EED1Ev
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7subjectD2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2503:
	.section	.text$_ZN7MonitorD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7MonitorD0Ev
	.def	__ZN7MonitorD0Ev;	.scl	2;	.type	32;	.endef
__ZN7MonitorD0Ev:
LFB2504:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN7MonitorD1Ev
	movl	$16, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPvj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2504:
	.globl	__ZTV7subject
	.section	.rdata$_ZTV7subject,"dr"
	.linkonce same_size
	.align 4
__ZTV7subject:
	.long	0
	.long	__ZTI7subject
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	0
	.long	0
	.globl	__ZTV7obsever
	.section	.rdata$_ZTV7obsever,"dr"
	.linkonce same_size
	.align 4
__ZTV7obsever:
	.long	0
	.long	__ZTI7obsever
	.long	___cxa_pure_virtual
	.long	___cxa_pure_virtual
	.long	0
	.long	0
	.globl	__ZTI2WW
	.section	.rdata$_ZTI2WW,"dr"
	.linkonce same_size
	.align 4
__ZTI2WW:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS2WW
	.long	__ZTI7obsever
	.globl	__ZTS2WW
	.section	.rdata$_ZTS2WW,"dr"
	.linkonce same_size
	.align 4
__ZTS2WW:
	.ascii "2WW\0"
	.globl	__ZTI2LS
	.section	.rdata$_ZTI2LS,"dr"
	.linkonce same_size
	.align 4
__ZTI2LS:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS2LS
	.long	__ZTI7obsever
	.globl	__ZTS2LS
	.section	.rdata$_ZTS2LS,"dr"
	.linkonce same_size
	.align 4
__ZTS2LS:
	.ascii "2LS\0"
	.globl	__ZTI2ZS
	.section	.rdata$_ZTI2ZS,"dr"
	.linkonce same_size
	.align 4
__ZTI2ZS:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS2ZS
	.long	__ZTI7obsever
	.globl	__ZTS2ZS
	.section	.rdata$_ZTS2ZS,"dr"
	.linkonce same_size
	.align 4
__ZTS2ZS:
	.ascii "2ZS\0"
	.globl	__ZTI7Monitor
	.section	.rdata$_ZTI7Monitor,"dr"
	.linkonce same_size
	.align 4
__ZTI7Monitor:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS7Monitor
	.long	__ZTI7subject
	.globl	__ZTS7Monitor
	.section	.rdata$_ZTS7Monitor,"dr"
	.linkonce same_size
	.align 4
__ZTS7Monitor:
	.ascii "7Monitor\0"
	.globl	__ZTI7subject
	.section	.rdata$_ZTI7subject,"dr"
	.linkonce same_size
	.align 4
__ZTI7subject:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS7subject
	.globl	__ZTS7subject
	.section	.rdata$_ZTS7subject,"dr"
	.linkonce same_size
	.align 4
__ZTS7subject:
	.ascii "7subject\0"
	.globl	__ZTI7obsever
	.section	.rdata$_ZTI7obsever,"dr"
	.linkonce same_size
	.align 4
__ZTI7obsever:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS7obsever
	.globl	__ZTS7obsever
	.section	.rdata$_ZTS7obsever,"dr"
	.linkonce same_size
	.align 4
__ZTS7obsever:
	.ascii "7obsever\0"
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB2506:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2506:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB2505:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L178
	cmpl	$65535, 12(%ebp)
	jne	L178
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L178:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2505:
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB2507:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE2507:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	_Sleep@4;	.scl	2;	.type	32;	.endef
	.def	___cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	___cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	__ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	_memmove;	.scl	2;	.type	32;	.endef
	.def	__ZdlPvj;	.scl	2;	.type	32;	.endef
	.def	___cxa_pure_virtual;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
