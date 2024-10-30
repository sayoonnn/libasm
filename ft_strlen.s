section .text
	global ft_strlen

ft_strlen:
	mov rax, 0

count:
	cmp byte [rdi + rax], 0
	je end
	inc rax
	jmp count

end:
	ret