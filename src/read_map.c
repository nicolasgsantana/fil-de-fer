/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgsantana <nicolasgsantana@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:15:26 by nde-sant          #+#    #+#             */
/*   Updated: 2025/09/23 16:14:40 by nicolasgsan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arrlen(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**get_row_array(int map_fd)
{
	char *row;
	char **points;

	row = get_next_line(map_fd);
	if (row)
		points = ft_split(row, ' ');
	else
		return (NULL);
	free(row);
	return(points);
}

int	*get_point_values(char **row_array, size_t row_len)
{
	int		i;
	int 	j;
	int		*point_values;
	char	*point;

	point_values = ft_calloc(sizeof(int), 2);
	i = 0;
	while(row_array[i])
	{
		point = ft_split(row_array[i], ',');
		j = 0;
		while (point[j])
		{
			point_values[j] = ft_atoi(point[j]);
			j++;
		}
		i++;
	}
	return (point_values);
}

t_list *get_map(int map_fd)
{
	char	**current_row;
	int		**row_points;
	char	**cell;
	size_t	horizontal_size;
	int		i;

	current_row = get_row_array(map_fd);
	horizontal_size = ft_arrlen(current_row);
	i = 0;
	while (current_row[i])
	{
		row_points = ft_calloc(sizeof(int *), horizontal_size + 1);
		row_points[i] = get_point_values(current_row, horizontal_size);
	}
}
