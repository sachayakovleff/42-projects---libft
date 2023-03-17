# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 02:23:38 by syakovle          #+#    #+#              #
#    Updated: 2023/03/17 13:51:29 by syakovle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	main.c \
		main_utils.c \
		pushswap/pb.c \
		pushswap/push_swap_utils.c \
		pushswap/push_swap.c \
		PilesMethods/methods_reverserotate.c \
		PilesMethods/methods_rotate.c \
		PilesMethods/methods_swap.c \
		PilesMethods/methods_push.c \
		ListEdit/methods.c \
		ListEdit/methods2.c \
		ListEdit/methods3.c \
		libft/ft_atoi.c \
		libft/ft_strjoin.c \
		printf/ft_printf.c \


OBJ	=	$(SRC:.c=.o)

NAME = push_swap.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
