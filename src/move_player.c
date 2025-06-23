/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:34:56 by edmatevo          #+#    #+#             */
/*   Updated: 2025/06/23 18:12:55 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

void	update_player_position(t_map *map, int y, int x, int on_exit)
{
	if (map->map[map->y][map->x] != 'E')
		map->map[map->y][map->x] = '0';
	if (!on_exit)
		map->map[y][x] = 'P';
	map->y = y;
	map->x = x;
	map->steps++;
	draw_map(map, &map->mlx);
	if (on_exit && map->coll == 0)
		destroy_img(map, "✨ You escaped Gravity Falls! ✨\n");
}

void	move_player(t_map *map, int new_y, int new_x)
{
	char	next_step;
	int		player_on_exit;

	next_step = map->map[new_y][new_x];
	if (next_step == '1')
		return ;
	if (next_step == 'M')
	{
		destroy_img(map, "☠️ You were caught by Bill! Game over.\n");
		return ;
	}
	if (next_step == 'C')
	{
		map->coll--;
		map->map[new_y][new_x] = '0';
	}
	player_on_exit = 0;
	if (next_step == 'E')
	{
		map->mlx.player = map->mlx.player_on_exit;
		player_on_exit = 1;
	}
	update_player_position(map, new_y, new_x, player_on_exit);
}

void	find_player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->y = i;
				map->x = j;
			}
			j++;
		}
		i++;
	}
}

int	count_collectibles(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
