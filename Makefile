NAME = so_long

OBJS = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

INCLUDES = -I/opt/X11/include -Imlx

SRC =	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c\
		map/map_parsing.c \
		map/map_checker.c \
		map/map_check_paths.c \
		map/map_utils.c \
		graphic_management/window.c \
		graphic_management/exit_window.c \
		game/players_goal.c \
		game/players_movements.c \
		ft_error.c \
		ft_utils.c \
		main.c

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re