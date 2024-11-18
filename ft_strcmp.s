section .text
	global _ft_strcmp

_ft_strcmp:
	xor rax, rax
	xor rbx, rbx
	xor rcx, rcx

compare:
	mov al, byte [rdi + rcx]
	mov bl, byte [rsi + rcx]

	cmp al, bl
	jnz diff

	test al, al
	jz end

	inc rcx
	jmp compare

diff:
	sub rax, rbx
	ret

end:
	mov rax, 0
	ret