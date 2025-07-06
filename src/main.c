/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:19:02 by edmatevo          #+#    #+#             */
/*   Updated: 2025/07/06 14:17:46 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

void	init_map_struct(t_map *map_struct, char **map)
{
	int	row;

	row = 0;
	while (map[row])
		row++;
	map_struct->map = map;
	map_struct->map_height = row;
	map_struct->map_width = ft_strlen(map[0]);
	map_struct->coll = count_collectibles(map_struct);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	map_struct;
	char	**map;

	if (argc != 2)
		exit(1 && write(1, "No arguments passed!\n", 21));
	if (check_file_ext(argv[1]) == 0)
		exit(1 && write(1, "Error! Wrong file name.\n", 24));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1 && write(1, "Error! FD error.\n", 17));
	map = parse_map(fd);
	close(fd);
	if (check_map_shape(map) == 1 || check_walls(map) == 1)
	{
		free_map(map);
		exit(1);
	}
	init_map_struct(&map_struct, map);
	fill(map, map_struct.map_height);
	start_game(&map_struct);
	free_map(map);
	return (0);
}
