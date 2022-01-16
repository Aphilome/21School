NAME = libftprintf.a

SRCS = ft_utils/ft_putchar.c ft_printf.c \
ft_formats/ft_formats.c ft_formats/ft_parse_format_type.c \
ft_utils/ft_isdigit.c ft_utils/ft_simple_atoi.c ft_printers/fr_print_format.c \
ft_utils/ft_nbr.c ft_printers/ft_print_type_i.c \
ft_printers/ft_print_utils.c ft_printers/ft_print_type_c.c ft_printers/ft_print_type_s.c \
ft_utils/ft_putstr.c ft_utils/ft_strlen.c ft_printers/ft_print_type_u.c \
ft_printers/ft_print_type_percent.c ft_printers/ft_print_type_x.c ft_printers/ft_print_type_p.c \
ft_printers/ft_print_type_n_bonus.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	gcc $(CFLAGS) -c $< -o $(<:.c=.o) -I .

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

bonus: all

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus