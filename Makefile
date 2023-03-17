CC			=	cc
NAME		=	minishell
DIR_RL		=	$(shell brew --prefix readline)
INCLUDES	=	-I ./include -I $(DIR_RL)/include
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)
LFLAGS		=	-L$(DIR_RL)/lib -lreadline
LIBFT		=	./libft/libft.a

DIR_SRC		=	./src
SRCS		=	$(DIR_SRC)/main.c					\
				$(DIR_SRC)/error/ms_error.c			\
				$(DIR_SRC)/signal/set_signal.c		\
				$(DIR_SRC)/utils/quotes.c			\
				$(DIR_SRC)/utils/string_array.c		\
				$(DIR_SRC)/env/key_value.c		\
				$(DIR_SRC)/env/ms_env.c		\
				$(DIR_SRC)/lexer/token.c			\
				$(DIR_SRC)/lexer/lexer.c			\
				$(DIR_SRC)/parser/redirection.c		\
				$(DIR_SRC)/parser/command.c			\
				$(DIR_SRC)/parser/parser.c			\
				$(DIR_SRC)/executor/redirect.c		\
				$(DIR_SRC)/executor/heredoc.c		\
				$(DIR_SRC)/executor/executor.c		\
				$(DIR_SRC)/validate_and_expand/validate_and_expand.c	\
				$(DIR_SRC)/validate_and_expand/expansion.c	\
				$(DIR_SRC)/validate_and_expand/replace_var.c

OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(LIBFT) :
	make -C libft

clean :
	make clean -C libft
	$(RM) $(OBJS)

fclean : clean
	make fclean -C libft
	$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean re
