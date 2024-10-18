# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 15:18:00 by tbartocc          #+#    #+#              #
#    Updated: 2024/10/16 17:02:45 by tbartocc         ###   ########.fr        #
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

SRC_BONUS = $(SRC_COMMON)\
	bonus.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

%.o: %.c src.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF)libftprintf.a -o $(NAME)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) --no-print-directory -C $(PRINTF) clean
	@$(MAKE) --no-print-directory -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(PRINTF) fclean
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean

re: fclean all

bonus: $(OBJ_BONUS)
	@$(MAKE) --no-print-directory -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(PRINTF)libftprintf.a -o $(NAME)

tester: end
	@git clone https://github.com/michmos/42_pipex_tester.git
	@cd 42_pipex_tester && bash run.sh

end:
	@rm -rf 42_pipex_tester

.PHONY: all clean fclean re debug tester