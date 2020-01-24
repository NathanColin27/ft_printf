NAME = libftprintf.a

SRCS = ft_printf.c print_c.c print_s.c print_d.c print_x.c 

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