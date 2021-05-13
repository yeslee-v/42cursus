section .text
 		global _main
		extern __error

 _main:
 	move rax, 0x2000003
 	syscall
 	jc _err
 	ret

 _err:
 	push rax
 	call ___error
 	pop rdx
 	mov [rax], rdx
 	mov rax, -1
 	ret
