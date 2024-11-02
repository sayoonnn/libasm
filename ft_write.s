section .text
	global _ft_write
	extern ___error

_ft_write:
	mov rax, 0x2000004		; write syscall number
	syscall
	jc err
	ret

err:
	push rax
	call ___error
	pop rdx
	mov [rax], rdx
	mov rax, -1
	ret

