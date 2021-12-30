# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 16:55:01 by tschmidt          #+#    #+#              #
#    Updated: 2021/12/16 10:35:26 by tschmidt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strnstr.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_strncmp.c ft_isascii.c ft_isprint.c ft_toupper.c \
	ft_tolower.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c

SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c  ft_lstdelone.c ft_lstclear.c ft_lstiter.c

OBJ = ${SRC:.c=.o}

OBJB = ${SRCB:.c=.o}

ifdef WITH_BONUS
	OBJ_FILES = $(OBJ) $(OBJB)
else
	OBJ_FILES = $(OBJ) 
endif


all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -crs $(NAME) $(OBJ_FILES)

clean:
	-/bin/rm -f $(OBJ) $(OBJB)
	@echo Clean done

fclean: clean
	-/bin/rm -f $(NAME)
	@echo Fclean done

re: fclean all

bonus:
	$(MAKE) WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
