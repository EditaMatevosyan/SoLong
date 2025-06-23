/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:16:59 by edmatevo          #+#    #+#             */
/*   Updated: 2025/06/23 17:52:23 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
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
	free(temp);
	check_blank_lines(joined);
	map = ft_split(joined);
	check_line(map);
	free(joined);
	check_chars(map);
	return (map);
}
