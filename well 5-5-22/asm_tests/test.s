.data
text:
	.string "test\n"

.text
.global _start
_start:
	movl $4, %eax
	movl $1, %ebx
	movl $text, %ecx
	movl $5, %edx
	int $0x80

	movl $1, %eax
	movl $0, %ebx
	int $0x80
