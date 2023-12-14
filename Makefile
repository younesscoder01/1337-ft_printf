CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar -crs
RM = rm -f

NAME = libftprintf.a

src = ./ft_putchar.c ./ft_putnbr_u.c ./ft_printf.c \
	  ./ft_printhex.c ./ft_putnbr.c ./ft_putstr.c ./ft_address.c

obj = $(src:.c=.o)

all: $(NAME)

$(NAME): $(obj)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $^
	$(AR) $(NAME) $@

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(NAME)