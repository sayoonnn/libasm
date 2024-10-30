
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

NASM		= nasm
NASMFLAGS	= -f elf64

MAKEFLAGS += --no-print-directory

all :
	@make $(NAME) $(MAKEFLAGS)

test: main.c $(NAME)
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

.PHONY:	all bonus clean fclean re