/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:09:25 by edmatevo          #+#    #+#             */
/*   Updated: 2025/06/23 17:52:17 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

void	move_up(t_map *map)
{
	map->mlx.player = map->mlx.uplayer;
	move_player(map, map->y - 1, map->x);
}

void	move_down(t_map *map)
{
	map->mlx.player = map->mlx.dplayer;
	move_player(map, map->y + 1, map->x);
}

void	move_right(t_map *map)
{
	map->mlx.player = map->mlx.rplayer;
	move_player(map, map->y, map->x + 1);
}

void	move_left(t_map *map)
{
	map->mlx.player = map->mlx.lplayer;
	move_player(map, map->y, map->x - 1);
}

int	key_press(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		destroy(map);
	else if (keycode == KEY_W)
		move_up(map);
	else if (keycode == KEY_S)
		move_down(map);
	else if (keycode == KEY_A)
		move_left(map);
	else if (keycode == KEY_D)
		move_right(map);
	return (0);
}
