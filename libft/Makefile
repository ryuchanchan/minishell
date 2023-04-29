# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 19:51:05 by toryoshi          #+#    #+#              #
#    Updated: 2022/05/06 19:51:23 by toryoshi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
DIR_INCLUDE = ./include
CFLAGS = -Wall -Wextra -Werror -I $(DIR_INCLUDE) #-MMD -MP
NAME = libft.a
DIR_SRC = src

SRC_CTYPE =		$(DIR_SRC)/ctype/ft_isalnum.c		\
				$(DIR_SRC)/ctype/ft_isalpha.c		\
				$(DIR_SRC)/ctype/ft_isascii.c		\
				$(DIR_SRC)/ctype/ft_isdigit.c		\
				$(DIR_SRC)/ctype/ft_isprint.c		\
				$(DIR_SRC)/ctype/ft_tolower.c		\
				$(DIR_SRC)/ctype/ft_toupper.c		

SRC_IO =		$(DIR_SRC)/io/ft_putchar_fd.c		\
				$(DIR_SRC)/io/ft_putendl_fd.c		\
				$(DIR_SRC)/io/ft_putnbr_fd.c		\
				$(DIR_SRC)/io/ft_putstr_fd.c		

SRC_LIST =		$(DIR_SRC)/list/ft_lstadd_back.c	\
				$(DIR_SRC)/list/ft_lstadd_front.c	\
        		$(DIR_SRC)/list/ft_lstclear.c		\
        		$(DIR_SRC)/list/ft_lstdelone.c		\
        		$(DIR_SRC)/list/ft_lstiter.c		\
        		$(DIR_SRC)/list/ft_lstlast.c		\
        		$(DIR_SRC)/list/ft_lstmap.c			\
        		$(DIR_SRC)/list/ft_lstnew.c			\
        		$(DIR_SRC)/list/ft_lstsize.c		

SRC_MEM =		$(DIR_SRC)/mem/ft_bzero.c			\
				$(DIR_SRC)/mem/ft_memchr.c			\
				$(DIR_SRC)/mem/ft_memcmp.c			\
				$(DIR_SRC)/mem/ft_memcpy.c			\
				$(DIR_SRC)/mem/ft_memmove.c			\
				$(DIR_SRC)/mem/ft_memset.c			

SRC_STDLIB =	$(DIR_SRC)/stdlib/ft_atoi.c			\
				$(DIR_SRC)/stdlib/ft_atol.c			\
				$(DIR_SRC)/stdlib/ft_itoa.c			\
				$(DIR_SRC)/stdlib/ft_calloc.c		

SRC_STRING =	$(DIR_SRC)/string/ft_split.c		\
				$(DIR_SRC)/string/ft_strchr.c		\
				$(DIR_SRC)/string/ft_strdup.c		\
				$(DIR_SRC)/string/ft_striteri.c		\
				$(DIR_SRC)/string/ft_strjoin.c		\
				$(DIR_SRC)/string/ft_strlcat.c		\
				$(DIR_SRC)/string/ft_strlcpy.c		\
				$(DIR_SRC)/string/ft_strlen.c		\
				$(DIR_SRC)/string/ft_strmapi.c		\
				$(DIR_SRC)/string/ft_strcmp.c		\
				$(DIR_SRC)/string/ft_strncmp.c		\
				$(DIR_SRC)/string/ft_strndup.c		\
				$(DIR_SRC)/string/ft_strnstr.c		\
				$(DIR_SRC)/string/ft_strrchr.c		\
				$(DIR_SRC)/string/ft_strtrim.c		\
				$(DIR_SRC)/string/ft_substr.c		

SRC_GNL =	$(DIR_SRC)/gnl/get_next_line.c

SRCS =			$(SRC_CTYPE)		\
				$(SRC_IO)			\
				$(SRC_LIST)			\
				$(SRC_MEM)			\
				$(SRC_STDLIB)		\
				$(SRC_STRING)		\
				$(SRC_PRINTF)	\
				$(SRC_GNL)

DIR_OBJ = obj
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $@ $^

re:	fclean all
fclean: clean
	$(RM) $(NAME)
clean:
	$(RM) $(OBJS)

.PHONY:	all re fclean clean
