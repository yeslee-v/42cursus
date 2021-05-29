section .text
		global _ft_strcpy

_ft_strcpy :
	cmp		rsi, 0
	je		.end
	mov		rcx, 0

.loop :
	mov		al, BYTE[rsi + rcx]
	mov		BYTE[rdi + rcx], al
	cmp		al, 0
	je		.end
	inc		rcx
	jmp		.loop

.end :
	mov		rax, rdi
	ret
