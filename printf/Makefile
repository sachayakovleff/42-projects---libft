# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 12:01:20 by syakovle          #+#    #+#              #
#    Updated: 2022/11/24 15:21:45 by syakovle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT = libft/libft.a

FILES = ft_printf

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


.c.o:
	$(CC) -c $(CFLAGS) $< -o $@ 

$(NAME): $(SRCS:.c=.o)
	@make -C libft/
	cp libft/libft.a libftprintf.a
	$(AR) $@ $(OBJS) libftprintf.a $^

all: $(NAME)

clean:
	@make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
