# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 00:21:03 by toryoshi          #+#    #+#              #
#    Updated: 2023/03/21 00:21:10 by toryoshi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
NAME		=	minishell
DIR_RL		=	$(shell brew --prefix readline)
INCLUDES	=	-I ./include -I $(DIR_RL)/include
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)
LFLAGS		=	-L$(DIR_RL)/lib -lreadline
LIBFT		=	./libft/libft.a

DIR_SRC		=	./src
SRCS		=	$(DIR_SRC)/main.c					\
				$(DIR_SRC)/utils/quotes.c			\
				$(DIR_SRC)/utils/string_array.c		\
				$(DIR_SRC)/utils/file_util.c		\
				$(DIR_SRC)/utils/fd_util.c			\
				$(DIR_SRC)/error/ms_error.c			\
				$(DIR_SRC)/signal/signal_flag.c		\
				$(DIR_SRC)/signal/ms_signal.c		\
				$(DIR_SRC)/state/ms_state.c			\
				$(DIR_SRC)/env/key_value.c			\
				$(DIR_SRC)/env/ms_env.c				\
				$(DIR_SRC)/builtin/echo.c			\
				$(DIR_SRC)/builtin/env.c			\
				$(DIR_SRC)/builtin/cd.c				\
				$(DIR_SRC)/builtin/export.c			\
				$(DIR_SRC)/builtin/key_value.c		\
				$(DIR_SRC)/builtin/pwd.c			\
				$(DIR_SRC)/builtin/unset.c			\
				$(DIR_SRC)/builtin/exit.c			\
				$(DIR_SRC)/lexer/token.c			\
				$(DIR_SRC)/lexer/lexer.c			\
				$(DIR_SRC)/parser/redirection.c		\
				$(DIR_SRC)/parser/command.c			\
				$(DIR_SRC)/parser/parser.c			\
				$(DIR_SRC)/validate_and_expand/validate_and_expand.c	\
				$(DIR_SRC)/validate_and_expand/expansion.c	\
				$(DIR_SRC)/validate_and_expand/replace_var.c	\
				$(DIR_SRC)/executor/do_heredoc.c		\
				$(DIR_SRC)/executor/do_redirect.c		\
				$(DIR_SRC)/executor/do_exec.c		\
				$(DIR_SRC)/executor/resolve_filename.c		\
				$(DIR_SRC)/executor/executor.c				\
				$(DIR_SRC)/shell/minishell.c

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
