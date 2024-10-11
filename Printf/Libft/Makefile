# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:34:27 by tbartocc          #+#    #+#              #
#    Updated: 2024/10/07 15:18:08 by tbartocc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_atoi.c \
	ft_atol.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_free_tab.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_print_tab.c \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putnbr_unsigned.c \
	ft_putnbr_hex.c \
	ft_putstr_fd.c \
	ft_putstr_n.c \
	ft_putstr.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_tabdup.c \
	ft_tablen.c \
	ft_tolower.c \
	ft_toupper.c

INCLUDE = includes
HEADER = $(INCLUDE)/ft.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJ)

bonus: 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
