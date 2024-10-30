section .text
	global ft_strcpy

ft_strcpy:
	mov rax, 0
	mov rbx, rdi

copy:
    mov al, byte [rsi]
    mov byte [rdi], al
    inc rsi
    inc rdi

	cmp al, 0
	jne copy

	mov rax, rbx
	ret
