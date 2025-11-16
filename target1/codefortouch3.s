.section .text
.global _start

_start:
    lea 0x10(%rsp),%rdi
	pushq 0x4018fa
	ret
	

