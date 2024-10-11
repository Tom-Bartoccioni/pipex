# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 15:18:00 by tbartocc          #+#    #+#              #
#    Updated: 2024/10/11 11:42:58 by tbartocc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
PRINTF = ./Printf/
LIBFT = ./Printf/Libft/

SRC_COMMON =	get_next_line.c \
				get_next_line_utils.c \
				pipes.c \
				utils.c \

SRC = $(SRC_COMMON)\
	pipex.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c src.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF)libftprintf.a -o $(NAME)

clean:
	@rm -f $(OBJ)
	@$(MAKE) --no-print-directory -C $(PRINTF) clean
	@$(MAKE) --no-print-directory -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(PRINTF) fclean
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean

re: fclean all

tester: end
	@git clone https://github.com/michmos/42_pipex_tester.git
	@cd 42_pipex_tester && bash run.sh

end:
	@rm -rf 42_pipex_tester

.PHONY: all clean fclean re debug tester checker visualizer