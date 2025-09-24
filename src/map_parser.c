/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:15:26 by nde-sant          #+#    #+#             */
/*   Updated: 2025/09/24 12:58:25 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	*get_point_values(char *row_point)
{
	int	i;
	int	*point_values;
	char	**point;

	point_values = ft_calloc(sizeof(int), 2);
	point = ft_split(row_point, ',');
	i = 0;
	while (i < 2)
	{
		if (point[i] && i == 0)
			point_values[i] = ft_atoi(point[i]);
		else if (point[i] && i == 1)
			point_values[i] = ft_atoi(point[i]); // TODO: update to htoi
		else
			point_values[i] = DEFAULT_COLOR;
		i++;
	}
	free_char_array(point);
	return (point_values);
}

t_list	*get_row_list(char **row, size_t rowlen)
{
	int	**row_points;
	int	i;

	row_points = ft_calloc(sizeof(int *), rowlen + 1);
	i = 0;
	while(row[i])
	{
		row_points[i] = get_point_values(row[i]);
		i++;
	}
	return (ft_lstnew(row_points));
}

t_list	*get_map(int map_fd)
{
	char	**current_row;
	size_t	rowlen;
	t_list	*map;

	map = NULL;
	current_row = get_row_array(map_fd);
	rowlen = ft_arrlen(current_row);
	while (current_row)
	{
		if (rowlen != ft_arrlen(current_row))
		{
			ft_printf("Map is not rectangular");
			break ;
		}
		else
			ft_lstadd_back(&map, get_row_list(current_row, rowlen));
		free_char_array(current_row);
		current_row = get_row_array(map_fd);
	}
	return (map);
}
