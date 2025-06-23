/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:03:02 by edmatevo          #+#    #+#             */
/*   Updated: 2025/06/03 18:18:05 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

static char	*read_into_buffer(int fd, char *left_str, char *buff)
{
	int		bytes_read;
	char	*temp;

	while (1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(left_str);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		if (!left_str)
			left_str = ft_strdup("");
		temp = left_str;
		left_str = ft_strjoin(temp, buff);
		if (!left_str)
			return (NULL);
		if (ft_strchr(left_str, '\n'))
			break ;
	}
	return (left_str);
}

static char	*extract_line(char *line)
{
	char	*result;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!result)
		result = NULL;
	line[i + 1] = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*left_str = NULL;
	char		*read_line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_line = read_into_buffer(fd, left_str, buff);
	free(buff);
	if (!read_line || *read_line == '\0')
	{
		free(read_line);
		buff = NULL;
		left_str = NULL;
		return (NULL);
	}
	buff = NULL;
	left_str = extract_line(read_line);
	return (read_line);
}

// int main(void)
// {
//     int     fd;
//     char    *line;
//     // int count = 0;

//     fd = open("read_error.txt", O_RDONLY);
//     line = get_next_line(fd);
//     free(line);
//     line = NULL;
//     printf("%s", line);
//     // while ((line = get_next_line(fd)))
//     // {
//     //     // printf("%s", line);
//     //     // free(line);
//     //     count++;
//     // }
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
//     line = NULL;
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
//     line = NULL;
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
//     line = NULL;
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
//     line = NULL;
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
//     line = NULL;
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
//     line = NULL;
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
//     line = NULL;
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
//     close(fd);
//     return (0);
// }