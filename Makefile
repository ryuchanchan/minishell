CC			=	cc
NAME		=	minishell
DIR_RL		=	$(shell brew --prefix readline)
INCLUDES	=	-I ./include -I $(DIR_RL)/include
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)
LFLAGS		=	-L$(DIR_RL)/lib -lreadline
LIBFT		=	./libft/libft.a

DIR_SRC		=	./src
SRCS		=	$(DIR_SRC)/main.c				\
				$(DIR_SRC)/signal/set_signal.c	\
				$(DIR_SRC)/utils/quotes.c		\
				$(DIR_SRC)/lexer/token.c		\
				$(DIR_SRC)/lexer/lexer.c		\
				$(DIR_SRC)/parser/parser.c		\
				$(DIR_SRC)/executor/redirect.c \
				$(DIR_SRC)/executor/heredoc.c
OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

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
