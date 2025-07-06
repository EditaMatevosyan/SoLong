/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:16:59 by edmatevo          #+#    #+#             */
/*   Updated: 2025/07/06 18:05:11 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

int	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (1);
	while (map[i])
	{
		if (map[i])
		{
			free(map[i]);
			map[i] = NULL;
		}
		i++;
	}
	free(map);
	return (1);
}

char	**parse_map(int fd)
{
	char	*line;
	char	*joined;
	char	**map;
	char	*temp;

	joined = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		joined = ft_strjoin(joined, line);
		free(line);
		line = get_next_line(fd);
	}
	temp = joined;
	joined = ft_strtrim(joined, " \n\t\r\v\f");
	if (!joined)
		free(joined);
	free(temp);
	check_blank_lines(joined);
	map = ft_split(joined);
	free(joined);
	check_line(map);
	check_chars(map);
	return (map);
}
