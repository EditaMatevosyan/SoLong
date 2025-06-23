/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:31:03 by edmatevo          #+#    #+#             */
/*   Updated: 2025/06/23 16:20:14 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"


void	init_players(t_img *img)
{
	img->lplayer = mlx_xpm_file_to_image(img->mlx, "xpm/lplayer.xpm", 
        &img->width, &img->height);
	img->rplayer = mlx_xpm_file_to_image(img->mlx, "xpm/rplayer.xpm", 
        &img->width, &img->height);
	img->uplayer = mlx_xpm_file_to_image(img->mlx, "xpm/uplayer.xpm", 
        &img->width, &img->height);
	img->player_on_exit = mlx_xpm_file_to_image(img->mlx, "xpm/on_exit.xpm", 
        &img->width, &img->height);
    img->enemy1 = mlx_xpm_file_to_image(img->mlx, "xpm/enemy1.xpm", 
        &img->width, &img->height);
	img->enemy2 = mlx_xpm_file_to_image(img->mlx, "xpm/enemy2.xpm", 
        &img->width, &img->height);
    img->book[0] = mlx_xpm_file_to_image(img->mlx, "xpm/book1.xpm", 
        &img->width, &img->height);
	img->book[1] = mlx_xpm_file_to_image(img->mlx, "xpm/book2.xpm", 
        &img->width, &img->height);
	img->book[2] = mlx_xpm_file_to_image(img->mlx, "xpm/book3.xpm", 
        &img->width, &img->height);
}

void init_images(t_img *img)
{
    img->road = mlx_xpm_file_to_image(img->mlx, "xpm/field.xpm", &img->width, 
        &img->height);
	img->wall = mlx_xpm_file_to_image(img->mlx, "xpm/wall.xpm", &img->width, 
        &img->height);
	img->player = mlx_xpm_file_to_image(img->mlx, "xpm/player.xpm", 
        &img->width, &img->height);
	img->exit = mlx_xpm_file_to_image(img->mlx, "xpm/exit.xpm", &img->width, 
        &img->height);
	init_players(img);
    img->dplayer = img->player;
    img->current_state = 0;
}

void	draw_tile(t_map *map, t_img *img, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(img->mlx, img->window, img->wall, j * SIZE,
            i * SIZE);
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(img->mlx, img->window, img->road, j * SIZE, 
            i * SIZE);
	else if (map->map[i][j] == 'C')
	{
		int book_index = (i + j) % 3;
		mlx_put_image_to_window(img->mlx, img->window, img->book[book_index], 
            j * SIZE, i * SIZE);
	}
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(img->mlx, img->window, img->exit, j * SIZE, 
            i * SIZE);
	else if (map->map[i][j] == 'M')
		mlx_put_image_to_window(img->mlx, img->window, img->current_enemy, 
            j * SIZE, i * SIZE);
	if (i == map->y && j == map->x)
		mlx_put_image_to_window(img->mlx, img->window, img->player, j * SIZE, 
            i * SIZE);
}

void	draw_map(t_map *map, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
            print_steps_on_window(map);
			draw_tile(map, img, i, j);
			j++;
		}
		i++;
	}
}

void start_game(t_map *map)
{
    map->steps = 0;
    map->mlx.mlx = mlx_init();
    if (!map->mlx.mlx)
        exit(1 && write(1, "MLX initialization failed\n", 26));
    map->mlx.window = mlx_new_window(map->mlx.mlx, map->map_width * SIZE,
        map->map_height * SIZE, "Gravity Falls - So long");
    if (!map->mlx.window)
        exit(1 && write(1, "Window creation failed\n", 23));
    find_player_position(map);
    mlx_hook(map->mlx.window, 2, 1L<<0, key_press, map);     
	mlx_hook(map->mlx.window, 17, 1L<<17, destroy, map); 
    init_images(&map->mlx);
    map->mlx.current_enemy = map->mlx.enemy1;
    draw_map(map, &map->mlx);
    mlx_loop_hook(map->mlx.mlx, update_enemy, map);
    print_steps_on_window(map);
    mlx_loop(map->mlx.mlx);
}
