CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c sort.c Utils_functions.c \
		quicksort.c push.c rotate.c \
		swap.c rerotate.c ft_split.c \
		push_swap_atoi.c
OBJS = $(SRCS:.c=.o)
LIBFTPRINTF = printf/libftprintf.a
NAME = push_swap

all: $(LIBFTPRINTF) $(NAME)

$(LIBFTPRINTF):
	make -C printf

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) -Lprintf -lftprintf -o $(NAME)

clean:
	make clean -C printf
	rm -f $(OBJS)

fclean: clean
	make fclean -C printf
	rm -f $(NAME)

re: fclean all
.PHONY:		all clean fclean re