/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:04:29 by edmatevo          #+#    #+#             */
/*   Updated: 2025/06/24 17:20:02 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

void	destroy_img(t_map *map, char *message)
{
	int	i;

	i = 0;
	mlx_destroy_image(map->mlx.mlx, map->mlx.wall);
	mlx_destroy_image(map->mlx.mlx, map->mlx.road);
	mlx_destroy_image(map->mlx.mlx, map->mlx.exit);
	mlx_destroy_image(map->mlx.mlx, map->mlx.rplayer);
	mlx_destroy_image(map->mlx.mlx, map->mlx.lplayer);
	mlx_destroy_image(map->mlx.mlx, map->mlx.uplayer);
	mlx_destroy_image(map->mlx.mlx, map->mlx.dplayer);
	mlx_destroy_image(map->mlx.mlx, map->mlx.player_on_exit);
	mlx_destroy_image(map->mlx.mlx, map->mlx.enemy1);
	mlx_destroy_image(map->mlx.mlx, map->mlx.enemy2);
	while (i < 3)
	{
		mlx_destroy_image(map->mlx.mlx, map->mlx.book[i]);
		i++;
	}
	mlx_destroy_window(map->mlx.mlx, map->mlx.window);
	mlx_destroy_display(map->mlx.mlx);
	free(map->mlx.mlx);
	map->mlx.mlx = NULL;
	write(1, message, ft_strlen(message));
	free_map(map->map);
	exit(0);
}

int	destroy(t_map *map)
{
	destroy_img(map, "Closed.\n");
	return (0);
}

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
