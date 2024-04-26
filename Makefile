NAME = so_long
SRC = player_movement.c 
OBJS = ${SRC:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
INCLUDES = -I/opt/X11/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

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