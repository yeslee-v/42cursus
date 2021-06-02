section	.text
		global _ft_strcmp

_ft_strcmp :
	mov		eax, 0
	cmp		rdi, 0
	je		.diff
	cmp		rsi, 0
	je		.diff

.loop :
	mov		al, BYTE[rdi]
	mov		cl, BYTE[rsi]
	cmp		al, cl
	jne		.diff
	cmp		cl, 0
	je		.end
	jmp		.inc

.inc :
	inc		rdi
	inc		rsi
	jmp		.loop

.diff :
	movzx	edx, cl
	movzx	eax, al
	sub		eax, edx
	jmp		.end

.end :
	ret
