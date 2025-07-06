/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:08:59 by edmatevo          #+#    #+#             */
/*   Updated: 2025/07/06 15:13:11 by edmatevo         ###   ########.fr       */
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
	write(1, message, ft_strlen(message));
	free_map(map->map);
	exit(0);
}

int	destroy(t_map *map)
{
	destroy_img(map, "Closed.\n");
	return (0);
}

void	destroy_pic1(t_img *img)
{
	if (img->lplayer)
		mlx_destroy_image(img->mlx, img->lplayer);
	if (img->rplayer)
		mlx_destroy_image(img->mlx, img->rplayer);
	if (img->uplayer)
		mlx_destroy_image(img->mlx, img->uplayer);
	if (img->dplayer)
		mlx_destroy_image(img->mlx, img->dplayer);
	if (img->player_on_exit)
		mlx_destroy_image(img->mlx, img->player_on_exit);
	if (img->enemy1)
		mlx_destroy_image(img->mlx, img->enemy1);
	if (img->enemy2)
		mlx_destroy_image(img->mlx, img->enemy2);
}

void	destroy_pic(t_img *img, char *message)
{
	destroy_pic1(img);
	if (img->book[0])
		mlx_destroy_image(img->mlx, img->book[0]);
	if (img->book[1])
		mlx_destroy_image(img->mlx, img->book[1]);
	if (img->book[2])
		mlx_destroy_image(img->mlx, img->book[2]);
	if (img->road)
		mlx_destroy_image(img->mlx, img->road);
	if (img->wall)
		mlx_destroy_image(img->mlx, img->wall);
	if (img->exit)
	{
		mlx_destroy_image(img->mlx, img->exit);
	}
	mlx_destroy_window(img->mlx, img->window);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(1 && write(1, message, ft_strlen(message)));
}
