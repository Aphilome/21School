NAME = fractol

SRCS = ./ft_draw_data/ft_draw_data.c ft_fractol_draw/ft_fractol_draw.c ft_fractol_draw/ft_fractol_draw_main.c ft_fractol_draw/ft_handlers.c ./main.c

HDRS = ./ft_draw_data/ft_draw_data.h ft_fractol_draw/ft_fractol_draw.h ./ft_r_im_struct/ft_r_im_struct.h

OBJS = $(SRCS:.c=.o)

FLAGS = -O3 -Wall -Wextra -Werror

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

.c.o:
			gcc $(FLAGS) -Imlx -c $< -o $@ -I .
			gcc $(FLAGS) -Imlx -c $< -o $@ -I .

all:		$(NAME)

$(NAME):	$(OBJS) $(HDRS)
			gcc $(FLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re