NAME = libftprintf.a

INCDS = includes/ft_printf.h

SRCS = $(wildcard srcs/ft*.c)

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
