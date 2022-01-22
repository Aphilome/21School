NAME = cub3d

SRCS =	main.c \
		parser/parser.c  \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		list/list.c utils/utils.c

MLX	 = 	libmlx.a

HDRS = utils/utils.h parser/parser.h get_next_line/get_next_line.h list/list.h

OBJS = $(SRCS:.c=.o)

FLAGS = -O3 -Wall -Wextra -Werror

MLX_FLAGS = -Lminilibx_opengl -lmlx -framework OpenGL -framework AppKit -lm

.c.o:
			gcc $(FLAGS) -I minilibx_opengl -I . -c $< -o $@

all:		$(NAME)

$(NAME):	$(MLX) $(OBJS) $(HDRS)
			gcc $(FLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

$(MLX):
			@echo "mlx start..."
			@$(MAKE) -sC minilibx_opengl 2>/dev/null
			@echo "mlx end..."
			mv minilibx_opengl/libmlx.a .

clean:
			$(MAKE) -C minilibx_opengl clean
			rm -f $(OBJS)

fclean:		clean
			rm -f $(MLX)
			rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
