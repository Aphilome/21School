NAME_CLIENT = client
NAME_CLIENT_BONUS = client_bonus

NAME_SERVER = server
NAME_SERVER_BONUS = server_bonus

SRCS_STR = ft_string/ft_strings.c

SRCS_CLIENT = ft_client/ft_client.c  ft_client/ft_sending_processes.c
SRCS_CLIENT_BONUS = ft_client/ft_client_bonus.c ft_client/ft_sending_processes_bonus.c

SRCS_SERVER = ft_server/ft_server.c ft_server/ft_exit_err.c
SRCS_SERVER_BONUS = ft_server/ft_server_bonus.c ft_server/ft_exit_err_bonus.c

HDRS_STR = ft_string/ft_strings.h

HDRS_CLIENT = ft_client/ft_client.h

HDRS_SERVER = ft_server/ft_server.h

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

OBJS_STR = $(SRCS_STR:.c=.o)

FLAGS = -O3 -Wall -Wextra -Werror

all:			$(NAME_CLIENT) $(NAME_SERVER)

bonus:			$(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(OBJS_STR):	$(SRCS_STR) $(HDRS_STR)
				gcc $(FLAGS) -I $(HDRS_STR) -c $*.c -o $@

$(OBJS_CLIENT): $(SRCS_CLIENT) $(HDRS_CLIENT)
				gcc $(FLAGS) -I $(HDRS_CLIENT) -c $*.c -o $@

$(OBJS_SERVER): $(SRCS_SERVER) $(HDRS_SERVER)
				gcc $(FLAGS) -I $(HDRS_SERVER) -c $*.c -o $@

$(OBJS_CLIENT_BONUS):	$(SRCS_CLIENT_BONUS) $(HDRS_CLIENT)
						gcc $(FLAGS) -I $(HDRS_STR) -c $*.c -o $@

$(OBJS_SERVER_BONUS):	$(SRCS_SERVER_BONUS) $(HDRS_SERVER)
						gcc $(FLAGS) -I $(HDRS_SERVER) -c $*.c -o $@

$(NAME_CLIENT):	$(OBJS_STR) $(OBJS_CLIENT)
				gcc $(FLAGS) $(OBJS_STR) $(OBJS_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS_STR) $(OBJS_SERVER)
				gcc $(FLAGS) $(OBJS_STR) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT_BONUS):	$(OBJS_STR) $(OBJS_CLIENT_BONUS)
						gcc $(FLAGS) $(OBJS_STR) $(OBJS_CLIENT_BONUS) -o $(NAME_CLIENT)

$(NAME_SERVER_BONUS):	$(OBJS_STR) $(OBJS_SERVER_BONUS)
						gcc $(FLAGS) $(OBJS_STR) $(OBJS_SERVER_BONUS) -o $(NAME_SERVER)

clean:
				rm -f $(OBJS_STR) $(OBJS_CLIENT) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER) $(OBJS_SERVER_BONUS)

fclean:			clean
				rm -f $(NAME_CLIENT) $(NAME_SERVER)

re:				fclean all

.PHONY:			all clean fclean re bonus
