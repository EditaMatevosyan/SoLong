/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:32:51 by edmatevo          #+#    #+#             */
/*   Updated: 2025/07/06 16:03:01 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

char	**map_copy(char **map, int row)
{
	int		i;
	char	**copy;

	if (!map || !map[0])
		return (NULL);
	copy = (char **)malloc(sizeof(char *) * (row + 1));
	if (!copy)
		exit(1 && free_map(copy) && write(1, "Allocation failed\n", 18));
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy);
			exit(1 && write(1, "Allocation failed\n", 18));
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y, int row)
{
	if (!map)
		return ;
	if (x < 0 || x >= row || y < 0 || y >= ft_strlen(map[0]) || map[x][y] == '1'
		|| map[x][y] == 'v' || map[x][y] == 'M')
		return ;
	map[x][y] = 'v';
	flood_fill(map, x + 1, y, row);
	flood_fill(map, x - 1, y, row);
	flood_fill(map, x, y + 1, row);
	flood_fill(map, x, y - 1, row);
}

void	check_copy(char **copy, char **map, int c)
{
	int	i;
	int	j;
	int	e;
	int	p;

	i = -1;
	e = 0;
	p = 0;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j])
		{
			if (copy[i][j] == 'C')
				c++;
			if (copy[i][j] == 'E')
				e++;
			if (copy[i][j] == 'P')
				p++;
		}
	}
	if (c != 0 || e != 0 || p != 0)
		exit(1 && free_map(copy) && free_map(map) && write(1,
				"Error.Can't reach to exit", 25));
}

void	fill(char **map, int row)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	copy = map_copy(map, row);
	if (!copy)
		exit(1 && free_map(copy) && write(1, "Allocation failed\n", 18));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				flood_fill(copy, i, j, row);
				break ;
			}
			j++;
		}
		i++;
	}
	check_copy(copy, map, 0);
	free_map(copy);
}
