/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmatevo <edmatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:20:54 by edmatevo          #+#    #+#             */
/*   Updated: 2025/06/24 20:10:18 by edmatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

char	*ft_strncpy(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while (s2[i] && i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	**alloc_word(char *str, char **res)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		start = i;
		while (str[i] && str[i] != '\n')
			i++;
		if (start < i)
		{
			res[j] = (char *)malloc(sizeof(char) * (i - start + 1));
			if (!res[j])
				free_map(res);
			ft_strncpy(res[j++], &str[start], (i - start));
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char *str)
{
	int		i;
	int		wc;
	char	**res;

	i = 0;
	wc = 0;
	res = NULL;
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		if (str[i])
			wc++;
		while (str[i] && str[i] != '\n')
			i++;
	}
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	return (alloc_word(str, res));
}
