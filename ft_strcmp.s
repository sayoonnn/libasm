section .text
	global ft_strcmp

ft_strcmp:
	mov rax, 0
	mov rcx, 0

compare:
	mov al, byte [rdi + rcx]
	mov bl, byte [rsi + rcx]

	cmp al, bl
	jne diff

	cmp al, 0
	je end

	inc rcx
	jmp compare

diff:
	sub rax, rbx
	ret

end:
	mov rax, 0
	ret