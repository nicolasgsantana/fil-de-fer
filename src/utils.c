/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:19:26 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/14 16:43:13 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	imax(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

size_t	ft_arrlen(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	point_count(char *file)
{
	int		fd;
	char	*line;
	char	**row;
	int		count;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		row = ft_split(line, ' ');
		count += (int)ft_arrlen(row);
		free_char_array(row);
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}
