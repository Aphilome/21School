NAME = push_swap

NAME_BONUS = checker

SRCS =	ft_utils/ft_string_printers.c\
		ft_utils/ft_parser.c\
		ft_utils/one_dimension_array_functions.c\
		ft_commands/reverse_rotate_commands.c\
		ft_logic/ft_sort_logic.c\
		ft_utils/two_dimention_array_functions.c\
		ft_logic/ft_main_functions.c\
		ft_commands/swap_commands.c\
		ft_commands/rotate_commands.c\
		ft_commands/push_commands.c\
		ft_commands/ft_commands.c\
		ft_logic/ft_pump_logic.c\
		ft_logic/ft_find_pump_logic_oper_count.c\
		ft_logic/ft_find_pump_logic_min_way.c\
		ft_logic/ft_pump_logic_into_a.c\
		ft_commands/r_rr_commands_extention.c\
		ft_logic/ft_do_rotate_in_a.c\
		ft_utils/ft_split.c\
		ft_utils/ft_malloc_mas.c\
		ft_logic/ft_sort_three_logic.c\
		ft_logic/ft_sort_five_logic.c

SRC = main.c

SRC_BONUS = main_bonus.c\
			ft_checker_bonus/ft_checker_bonus.c\
			ft_checker_bonus/get_next_line.c\
			ft_checker_bonus/get_next_line_utils.c

HDRS =	ft_commands/ft_commands.h\
		ft_utils/ft_utils.h\
		ft_logic/ft_logic.h\
		ft_checker_bonus/ft_checker_bonus.h\
		ft_checker_bonus/get_next_line.h

OBJS = $(SRCS:.c=.o) $(SRC:.c=.o)

OBJS_BONUS = $(SRCS:.c=.o) $(SRC_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

.c.o:
			gcc $(FLAGS) -c $< -o $(<:.c=.o) -I .

all:		$(NAME)

bonus:		$(NAME_BONUS)

$(NAME):	$(OBJS) $(SRC) $(HDRS)
			gcc $(FLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS):	$(OBJS_BONUS) $(SRC_BONUS) $(HDRS)
				gcc $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
			rm -f $(OBJS)
			rm -f $(OBJS_BONUS)

fclean:		clean
			rm -f $(NAME)
			rm -f $(NAME_BONUS)

re:			fclean all bonus

.PHONY:	all clean fclean re bonus
