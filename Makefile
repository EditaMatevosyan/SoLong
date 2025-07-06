SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/, destroy.c flood_fill.c ft_itoa.c ft_split.c ft_strtrim.c get_next_line.c \
	get_next_line_utils.c  main.c map_check.c map_check2.c move_player.c move.c parse_map.c \
	utils.c start_graphic.c)

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address -O0

MLX_DIR = ./minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -Iincludes -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
