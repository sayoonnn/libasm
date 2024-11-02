
NAME	=	libasm.a

test	=	test

SRC	=	ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_write.s\
		ft_read.s\
		ft_strdup.s

OBJDIR	=	.objs
OBJ		=	$(SRC:%.s=$(OBJDIR)/%.o)

NASM		= /Users/sayoon/Downloads/nasm-2.16.03/nasm
NASMFLAGS	= -f macho64

MAKEFLAGS += --no-print-directory

all :
	@make $(NAME) $(MAKEFLAGS)

test:
	@make all
	@cc -Wall -Wextra -Werror main.c -o test -lasm -L.
	@./test
	@echo TEST DONE ✅

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo $(NAME) DONE ✅ 


$(OBJDIR)/%.o: %.s | $(OBJDIR)
	@$(NASM) $(NASMFLAGS) $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@rm -rf test
	@echo CLEAN DONE ✅

fclean:
	@make clean
	@rm -f $(NAME)
	@echo FCLEAN DONE ✅

re: 
	@make fclean
	@make all

.PHONY:	all bonus clean fclean re test