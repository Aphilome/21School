NAME		=	cub3D

MAIN		=	main.c

MAINB		=	main_bonus.c

SRCS		=	mlx_adapter/mlx_adapter.c \
				parser/parser.c parser/cardinal_direction_setters.c parser/file_reader.c parser/line_checkers.c parser/settings_func.c parser/color_setters.c parser/map_func.c parser/validator.c \
				loader/game_loader.c loader/textures_loader.c loader/color_loader.c\
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				list/list.c list/string_cleaner.c \
				raycasting_logic/raycasting_logic.c raycasting_logic/rc_funcs.c \
				key_handler/key_handler.c key_handler/moves.c key_handler/rotates.c key_handler/mause_handler.c \
				utils/utils.c utils/strings.c utils/printers.c utils/numbers.c

MLX			=	minilibx_opengl/libmlx.a

HDRS		=	utils/utils.h parser/parser.h parser/parser_private.h get_next_line/get_next_line.h list/list.h \
				mlx_adapter/mlx_adapter.h loader/game_loader.h loader/game_loader_private.h raycasting_logic/raycasting_logic.h \
				raycasting_logic/raycasting_logic_private.h key_handler/key_handler.h key_handler/key_handler_private.h

OBJS		=	$(SRCS:.c=.o) $(MAIN:.c=.o)

OBJSB		=	$(SRCS:.c=.o) $(MAINB:.c=.o)

CC			=	gcc

CFLAGS		=	-O3 -Wall -Wextra -Werror -I minilibx_opengl -MMD

MLX_FLAGS	=	-Lminilibx_opengl -lmlx -framework OpenGL -framework AppKit -lm

# COLORS
WHITE		=	\033[0m
BLACK		=	\033[0;30m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
MAGENTA		=	\033[0;35m

DEPENDENCIES := $(OBJS:.o=.d) $(OBJSB:.o=.d)

.PHONY		:	all bonus clean fclean re mlx norm


all			:	$(MLX) $(NAME)
				@echo " "

-include $(DEPENDENCIES)

$(OBJS)		: $(MLX)

%.o			:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)#$(WHITE)\c"

$(MLX)		:	mlx

mlx			:
	@$(MAKE) -sC minilibx_opengl 2>/dev/null

$(NAME)		:	$(OBJS)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)
	@echo "$(BLUE)#$(WHITE)\c"

bonus		:
	@make OBJS="$(OBJSB)" all

clean		:
	@$(MAKE) -C minilibx_opengl clean >/dev/null
	@echo "$(MAGENTA)#$(WHITE)\c"
	@rm -f $(OBJS)
	@rm -f $(OBJSB)
	@rm -f $(DEPENDENCIES)
	@echo "$(MAGENTA)#$(WHITE)"

fclean		:	clean
	@echo "$(RED)#$(WHITE)\c"
	@rm -f $(NAME)
	@echo "$(RED)#$(WHITE)"

re			:	fclean all

norm		:
	@norminette get_next_line key_handler list loader mlx_adapter parser raycasting_logic textures utils main.c main_bonus.c

