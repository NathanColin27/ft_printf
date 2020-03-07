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
		srcs/ft_flags.c \
		utils/ft_isdigit.c \
		utils/ft_putchar.c \
		utils/ft_putnbr.c \
		utils/ft_strdup.c \
		utils/ft_strlen.c \
		utils/ft_strchr.c

OBJS = $(SRCS:.c=.o)

INCLUDES = ft_printf.h 

all: $(NAME) 

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(INCLUDES)
	@gcc -c $(SRCS) 
	@ar rc $(NAME) *.o

test:
	@gcc -L. -lftprintf -o test
 
clean:
	@rm -rf *.o test

fclean: clean
	@rm -rf $(NAME)

re: fclean all