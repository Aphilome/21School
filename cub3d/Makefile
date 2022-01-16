NAME = cub3d

SRCS =	./main.c

MLX	 = 	libmlx.a

HDRS =

OBJS = $(SRCS:.c=.o)

FLAGS = -O3 -Wall -Wextra -Werror

MLX_FLAGS = -Lminilibx_opengl -lminilibx_opengl -framework OpenGL -framework AppKit -lm

.c.o:
			gcc $(FLAGS) -I minilibx_opengl -I . -c $< -o $@

all:		$(NAME)

$(NAME):	$(MLX) $(OBJS) $(HDRS)
			gcc $(FLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

$(MLX):
			$(MAKE) -sC minilibx_opengl
			mv minilibx_opengl/libmlx.a .

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
