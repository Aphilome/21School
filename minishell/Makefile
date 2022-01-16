NAME = minishell

SRCS =	readline_logic/readline_logic.c \
		commands/commands.c commands/std_cmd.c commands/build_in_1.c commands/build_in_2.c commands/ft_pipes.c commands/ft_processes.c commands/std_search.c commands/std_array.c commands/ft_child_pipe.c \
		ft_echo/ft_echo.c \
		ft_pwd/ft_pwd.c \
		ft_cd/ft_cd.c ft_cd/ft_cd_search.c \
		ft_export/ft_export.c ft_export/sort.c \
		ft_env/ft_env.c \
		ft_unset/ft_unset.c \
		ft_exit/ft_exit.c \
		parser/parser.c parser/redirects.c parser/redirects_ex.c parser/validator.c parser/quote_handler.c parser/pipes.c parser/structs.c parser/structs_ex.c parser/ft_dollar.c \
		signals/signals.c signals/signals_heredoc.c signals/signals_std.c \
		utils/error_handler.c utils/ft_strjoin.c utils/cleaner.c utils/numbers.c utils/printer.c utils/file.c utils/ft_split.c \
		utils/environment/environment.c utils/environment/lst_environment.c utils/environment/environment_ex.c utils/environment/environment_add_ex.c \
		utils/string.c utils/string_1.c utils/string_2.c utils/string_3.c utils/string_4.c utils/string_5.c \
		main.c

HDRS =	readline_logic/readline_logic.h parser/parser.h utils/utils.h commands/commands.h ft_echo/ft_echo.h ft_pwd/ft_pwd.h ft_cd/ft_cd.c \
		ft_export/ft_export.h ft_env/ft_env.h ft_unset/ft_unset.h signals/signals.h

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
				@gcc $(FLAGS) -c $< -o $(<:.c=.o) -I ./readline
				@echo "$(GREEN).$(WHITE)\c"

all:			$(NAME)
				@echo " "

#bonus:			$(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
#@echo "\n$(GREEN)BONUS COMPILED$(WHITE)"

#$(OBJS):		$(SRCS)
#				gcc $(FLAGS) -c $*.c -o $@ -I $(HDRS)
#@echo "$(GREEN).$(WHITE)\c"

$(NAME):		$(OBJS) $(SRCS) $(HDRS)
				@gcc $(FLAGS) $(OBJS) -L/Users/$(USER)/.brew/Cellar/readline/8.1.1/lib/ -I/Users/$(USER)/.brew/Cellar/readline/8.1.1/include -lreadline -o $(NAME)
				@stty -echoctl
				@echo "$(BLUE).$(WHITE)\c"

clean:
				@rm -f $(OBJS)
				@stty echoctl
				@echo "$(MAGENTA).$(WHITE)"

fclean:			clean
				@rm -f $(NAME)
				@echo "$(RED).$(WHITE)"

re:				fclean all

.PHONY:			all clean fclean re #bonus
