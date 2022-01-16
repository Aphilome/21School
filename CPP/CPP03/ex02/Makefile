NAME = fragtrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

HDRS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -O3 -Wall -Wextra -Werror -std=c++98

COMP = c++

# COLORS
WHITE	=	\033[0m
BLACK	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[0;36m

%.o: %.cpp		$(HDRS)
				@$(COMP) $(FLAGS) -c $< -o $@
				@echo "$(GREEN).$(WHITE)\c"

all:			$(NAME)
				@echo " "

$(NAME):		$(OBJS)
				@$(COMP) $(FLAGS) $(OBJS) -o $@
				@echo "$(BLUE).$(WHITE)\c"

clean:
				@rm -f $(OBJS)
				@echo "$(MAGENTA).$(WHITE)"

fclean:			clean
				@rm -f $(NAME)
				@echo "$(RED).$(WHITE)"

re:				fclean all

.PHONY:			all clean fclean re
