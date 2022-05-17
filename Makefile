# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnilprap <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 21:12:05 by vnilprap          #+#    #+#              #
#    Updated: 2022/05/17 21:17:23 by vnilprap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCDS = includes/ft_printf.h

SRCS = srcs/ft_check.c srcs/ft_convertcs.c srcs/ft_convertdi.c \
       srcs/ft_convertp.c srcs/ft_convertux.c srcs/ft_printf.c srcs/ft_util.c \
       srcs/ft_util2.c

LIBFT = libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME)

c:
	make
	$(CC) $(FLAGS) main.c $(NAME) -o output
	./output
	$(RM) output

v:
	make
	$(CC) $(CFLAGS) -g main.c $(NAME) -o output
	valgrind --leak-check=full ./output
	$(RM) output.dSYM

.PHONY:	$(NAME) all clean fclean re c v
