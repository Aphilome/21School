NAME = philo_bonus

SRCS =	data_parser/data_parser.c initializer/initializer.c philo_life_circle/philo_life_circle.c \
		utils/utils.c utils/ft_time.c philo_life_circle/actions.c \
		main.c

HDRS =	data_parser/data_parser.h initializer/initializer.h philo_data/philo_data.h philo_life_circle/philo_life_circle.h \
		utils/utils.h

OBJS = $(SRCS:.c=.o)

FLAGS = -O3 -Wall -Wextra -Werror

# COLORS
WHITE	=	\033[0m
BLACK	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[0;36m

.c.o:
				@gcc $(FLAGS) -c $< -o $(<:.c=.o)
				@echo "$(GREEN).$(WHITE)\c"

all:			$(NAME)
				@echo " "

$(NAME):		$(OBJS) $(SRCS) $(HDRS)
				@gcc $(FLAGS) $(OBJS) -o $(NAME)
				@echo "$(BLUE).$(WHITE)\c"

clean:
				@rm -f $(OBJS)
				@echo "$(MAGENTA).$(WHITE)"

fclean:			clean
				@rm -f $(NAME)
				@echo "$(RED).$(WHITE)"

re:				fclean all

.PHONY:			all clean fclean re
