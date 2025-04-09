NAME	= libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
HEADER	= ft_printf.h
SRCS	= ft_printf.c ft_printf_conv.c ft_printf_uns.c ft_printf_hex.c ft_printf_address.c ft_itoa.c
OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

%.o : %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re