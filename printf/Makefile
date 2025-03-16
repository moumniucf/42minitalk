# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 09:53:31 by youmoumn          #+#    #+#              #
#    Updated: 2024/11/30 16:49:16 by youmoumn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

SRC = ft_puthex.c ft_putchar.c ft_putnbr.c  ft_putstr.c ft_printf.c ft_putunsigned.c ft_putpoint.c ft_putprc.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

%.o : %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "compiling" $< "to" $@

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean :
	@rm -f $(NAME) $(OBJ)

re : fclean all

.PHONY : clean fclean
