# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loamar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 19:29:49 by loamar            #+#    #+#              #
#    Updated: 2019/11/30 19:29:51 by loamar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

SRC=./SRCS/
SRCS= $(SRC)ft_printf.c \
	$(SRC)/utils/flags_utils.c \
	$(SRC)/utils/flags_utils2.c \
	$(SRC)ft_display.c \
	$(SRC)ft_display2.c \
	$(SRC)ft_display3.c \
	$(SRC)/get_display/get_type.c \
	$(SRC)/get_display/get_flag.c \
	$(SRC)/get_display/get_arg.c \
	$(SRC)/get_display/get_address.c \
	$(SRC)/utils/checkprint.c \
	$(SRC)/utils/check_utils.c

OBJ=$(SRCS:.c=.o)

FLAGS=-Wall -Wextra -Werror

INC=./INCLUDES

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@cp libft/libft.a $(NAME)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

.o: .c
	@$(CC) $(FLAGS) -I$(INC) -o $@ -c $<

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re

.SILENT: $(OBJ)
