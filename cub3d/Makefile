NAME = cub3d

SRCS =	main.c \
		mlx_adapter/mlx_adapter.c \
		parser/parser.c parser/cardinal_direction_setters.c parser/file_reader.c parser/line_checkers.c parser/settings_func.c parser/color_setters.c parser/map_func.c parser/validator.c \
		loader/game_loader.c loader/textures_loader.c loader/color_loader.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		list/list.c list/string_cleaner.c \
		utils/utils.c utils/strings.c utils/printers.c

MLX	 = 	libmlx.a

HDRS = utils/utils.h parser/parser.h parser/parser_private.h get_next_line/get_next_line.h list/list.h mlx_adapter/mlx_adapter.h loader/game_loader.h loader/game_loader_private.h \

OBJS = $(SRCS:.c=.o)

FLAGS = -O3 -Wall -Wextra -Werror

MLX_FLAGS = -Lminilibx_opengl -lmlx -framework OpenGL -framework AppKit -lm

# COLORS
WHITE	=	\033[0m
BLACK	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m

.c.o:
			@gcc $(FLAGS) -I minilibx_opengl -I . -c $< -o $@
			@echo "$(GREEN)#$(WHITE)\c"

all:		$(NAME)
			@echo " "

$(NAME):	$(MLX) $(OBJS) $(HDRS)
			@gcc $(FLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)
			@echo "$(BLUE)#$(WHITE)\c"

$(MLX):
			@echo "$(YELLOW)#$(WHITE)\c"
			@$(MAKE) -sC minilibx_opengl 2>/dev/null
			@mv minilibx_opengl/libmlx.a .
			@echo "$(YELLOW)#$(WHITE)\c"

clean:
			@$(MAKE) -C minilibx_opengl clean >/dev/null
			@echo "$(MAGENTA)#$(WHITE)\c"
			@rm -f $(OBJS)
			@echo "$(MAGENTA)#$(WHITE)"

fclean:		clean
			@rm -f $(MLX)
			@echo "$(RED)#$(WHITE)\c"
			@rm -f $(NAME)
			@echo "$(RED)#$(WHITE)"

re:			fclean all

norm:		
			norminette get_next_line list loader mlx_adapter textures utils parser main.c

.PHONY:	all clean fclean re
