# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 02:23:38 by syakovle          #+#    #+#              #
#    Updated: 2023/03/17 14:39:41 by syakovle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT = libft/libft.a
PRINTF = printf/printf.a

FILES	=	main_utils \
			pushswap/pb \
			pushswap/push_swap_utils \
			pushswap/push_swap \
			PilesMethods/methods_reverserotate \
			PilesMethods/methods_rotate \
			PilesMethods/methods_swap \
			PilesMethods/methods_push \
			ListEdit/methods \
			ListEdit/methods2 \
			ListEdit/methods3 \
			libft/ft_atoi \
			libft/ft_strjoin \
			printf/ft_printf \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)
	@make all -C libft
	@make all -C printf
	$(CC) $(CFLAGS) ./main.c $(NAME) ./libft/libft.a ./printf/ft_printf.a -o push_swap

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make clean -C libft
	@make clean -C printf

fclean: clean
	$(RM) $(NAME) push_swap
	@make fclean -C libft
	@make fclean -C printf
	
re: clean all

.PHONY: all clean fclean re
