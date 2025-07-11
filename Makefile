SRC_DIR = src
SRCS = $(SRC_DIR)/destroy.c \
       $(SRC_DIR)/flood_fill.c \
       $(SRC_DIR)/ft_itoa.c \
       $(SRC_DIR)/ft_split.c \
       $(SRC_DIR)/ft_strtrim.c \
       $(SRC_DIR)/get_next_line.c \
       $(SRC_DIR)/get_next_line_utils.c \
       $(SRC_DIR)/main.c \
       $(SRC_DIR)/map_check.c \
       $(SRC_DIR)/map_check2.c \
       $(SRC_DIR)/move_player.c \
       $(SRC_DIR)/move.c \
       $(SRC_DIR)/parse_map.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/start_graphic.c


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
