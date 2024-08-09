NAME = so_long

OBJS = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

INCLUDES = -I/opt/X11/include -Imlx

SRC =	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c\
		main.c \
		map/map_checker.c \
		map/map_parsing.c \
		game/init_game.c \
		game/get_image.c \
		game/put_image.c \
		game/put_image_2.c \
		game/hooks.c \
		game/destroy_image.c \
		utils/ft_utils_1.c \
		utils/ft_utils_2.c \
		utils/ft_utils_3.c

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	make -C ./mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

all: ${NAME}

clean:
	make -C ./mlx
	${RM} ${OBJS}

fclean: clean
	make clean -C ./mlx
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re