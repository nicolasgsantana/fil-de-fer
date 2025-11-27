/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:19:26 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/27 16:17:46 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

int	get_col_count(char *file)
{
	int		fd;
	char	*line;
	char	**row;
	int		size;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	size = 0;
	while (line)
	{
		row = ft_split(line, ' ');
		if (size < (int)ft_arrlen(row))
			size = ft_arrlen(row);
		free_char_array(row);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}

int	get_row_count(char *file)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
