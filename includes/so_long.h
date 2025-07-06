/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:05:29 by edmatevo          #+#    #+#             */
/*   Updated: 2025/07/06 15:12:20 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE 100
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// #define KEY_W 13
// #define KEY_S 1
// #define KEY_A 0
// #define KEY_D 2
// #define KEY_ESC 53

// # ifdef __APPLE__
// #  include "../minilibx-macos/mlx.h"
// # else
// #  include "../minilibx-linux/mlx.h"
// # endif

typedef struct s_img
{
	void	*mlx;
	void	*window;
	void	*player;
	void	*lplayer;
	void	*rplayer;
	void	*uplayer;
	void	*dplayer;
	void	*player_on_exit;
	void	*road;
	void	*wall;
	void	*book[3];
	void	*exit;
	void	*enemy1;
	void	*enemy2;
	int		width;
	int		height;
	int		current_state;
	void	*current_enemy;
}			t_img;

typedef struct s_map
{
	char	**map;
	int		coll;
	int		steps;
	int		x;
	int		y;
	int		map_width;
	int		map_height;
	int		player_on_exit;
	t_img	mlx;
}			t_map;

char		**map_copy(char **map, int row);
char		**map_copy(char **map, int row);
void		check_copy(char **copy, char **map, int c);
void		fill(char **map, int row);
int			count(long long int n);
char		*int_to_char(char *s, long long int n, long long int len);
char		*ft_itoa(int n);
char		*ft_strncpy(char *s1, char *s2, int len);
char		**alloc_word(char *str, char **res);
char		**ft_split(char *str);
int			check(char c, unsigned char *set);
char		*ft_strtrim(char *s1, char *set);
char		*strtrim_for_line(char const *s1, char const *set);
void		init_map_struct(t_map *map_struct, char **map);
void		check_char_count(char **line);
void		check_chars(char **line);
int			check_top_bottom_walls(char **lines, int rows);
int			check_walls(char **lines);
int			check_map_shape(char **map);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		check_blank_lines(char *str);
int			check_file_ext(char *map);
void		check_line(char **str);
void		update_player_position(t_map *map, int y, int x, int on_exit);
void		move_player(t_map *map, int new_y, int new_x);
void		find_player_position(t_map *map);
int			count_collectibles(t_map *map);
void		move_up(t_map *map);
void		move_down(t_map *map);
void		move_right(t_map *map);
void		move_left(t_map *map);
int			key_press(int keycode, t_map *map);
int			free_map(char **map);
char		**parse_map(int fd);
void		init_players(t_img *img, t_map *map);
void		init_images(t_img *img, t_map *map);
void		draw_tile(t_map *map, t_img *img, int i, int j);
void		draw_map(t_map *map, t_img *img);
void		start_game(t_map *map);
void		destroy_img(t_map *map, char *message);
int			destroy(t_map *map);
void		destroy_pic1(t_img *img);
void		destroy_pic(t_img *img, char *message);
void		print_steps_on_window(t_map *map);
void		*animate_bill(t_map *map);
int			update_enemy(t_map *map);

#endif