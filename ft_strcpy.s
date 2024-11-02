section .text
	global _ft_strcpy

_ft_strcpy:
	xor rax, rax
	mov rdx, rdi

copy:
    mov al, byte [rsi]
    mov byte [rdi], al
    inc rsi
    inc rdi

	test al, al
	jnz copy

	mov rax, rdx
	ret
