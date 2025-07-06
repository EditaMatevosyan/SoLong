/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:04:29 by edmatevo          #+#    #+#             */
/*   Updated: 2025/07/06 15:10:23 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

void	print_steps_on_window(t_map *map)
{
	char	*steps;

	steps = ft_itoa(map->steps);
	if (!steps)
		return ;
	mlx_string_put(map->mlx.mlx, map->mlx.window, 10, 20, 0xFFFFFF, steps);
	free(steps);
	steps = NULL;
}

void	*animate_bill(t_map *map)
{
	static int	count;
	static void	*bill;

	if (count % 500 < 250)
		bill = map->mlx.enemy1;
	else
		bill = map->mlx.enemy2;
	count++;
	return (bill);
}

int	update_enemy(t_map *map)
{
	map->mlx.current_enemy = animate_bill(map);
	draw_map(map, &map->mlx);
	return (0);
}
