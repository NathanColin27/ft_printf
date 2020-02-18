NAME = libftprintf.a

SRCS = 	ft_printf.c \
		srcs/print_c.c \
		srcs/print_s.c \
		srcs/print_d.c \
		srcs/print_x.c \
		srcs/print_p.c \
		srcs/print_u.c \
		srcs/print_percent.c \
		srcs/ft_u_putnbr.c \
		srcs/ft_width.c \
		srcs/ft_flags.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME):
	@gcc -c -Wall -Werror -Wextra libft/*.c -I libft/libft.h
	@gcc -c $(SRCS)
	@ar rc $(NAME) *.o

test:
	@gcc -L. -lftprintf $(SRCS) -o test
 
clean:
	@rm -rf *.o libft/*.o test

fclean: clean
	@rm -rf $(NAME)

re: fclean all