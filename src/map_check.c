/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:05:02 by edmatevo          #+#    #+#             */
/*   Updated: 2025/07/06 16:04:38 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

void	check_char_count(char **line)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	i = -1;
	c = 0;
	e = 0;
	p = 0;
	while (line[++i])
	{
		j = -1;
		while (line[i][++j])
		{
			if (line[i][j] == 'C')
				c++;
			if (line[i][j] == 'E')
				e++;
			if (line[i][j] == 'P')
				p++;
		}
	}
	if (c <= 0 || e != 1 || p != 1)
		exit(1 && free_map(line) && write(1, "Error:Wrong num of chars\n", 25));
}

void	check_chars(char **line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] != '0' && line[i][j] != '1' && line[i][j] != 'C'
				&& line[i][j] != 'E' && line[i][j] != 'P' && line[i][j] != 'M'
				&& line[i][j] != '\n')
			{
				free_map(line);
				exit(1 && write(2, "Error: Invalid chars\n", 21));
			}
			j++;
		}
		i++;
	}
	check_char_count(line);
}

int	check_top_bottom_walls(char **lines, int rows)
{
	int	i;

	i = 0;
	while (lines[0][i])
	{
		if (lines[0][i] != '1')
		{
			free_map(lines);
			write(1, "Error: Walls!\n", 14);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (lines[rows - 1][i])
	{
		if (lines[rows - 1][i] != '1')
		{
			free_map(lines);
			write(1, "Error: Walls!\n", 14);
			exit(1);
		}
		i++;
	}
	return (0);
}

int	check_walls(char **lines)
{
	int	i;
	int	width;
	int	rows;

	rows = 0;
	i = 0;
	width = ft_strlen(lines[0]);
	while (lines[rows])
		rows++;
	while (lines[i])
	{
		if ((lines[i][0] != lines[i][width - 1]) || lines[1][0] != '1')
		{
			write(1, "Error: Sidewalls!\n", 18);
			return (1);
		}
		i++;
	}
	check_top_bottom_walls(lines, rows);
	return (0);
}

int	check_map_shape(char **map)
{
	int	first_row_len;
	int	i;

	i = 1;
	first_row_len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != first_row_len)
		{
			write(1, "Error: Wrong Shape\n", 19);
			return (1);
		}
		i++;
	}
	return (0);
}
