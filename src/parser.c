/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:15:26 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/11 10:42:59 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	point_count(char *file)
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

static void	set_point(t_point *point, int x, int y, int z, unsigned int color)
{
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = color;
}

static void	parse_line(t_point **tmp, char *line, int y)
{
	int		i;
	char	**row;
	char	**point;

	row = ft_split(line, ' ');
	i = 0;
	while (row[i])
	{
		point = ft_split(row[i], ',');
		if (point[1])
			set_point(*tmp, i, y, ft_atoi(point[0]), ft_htoi(point[1]));
		else
			set_point(*tmp, i, y, ft_atoi(point[0]), UINT_MAX);
		free_char_array(point);
		(*tmp)++;
		i++;
	}
	free_char_array(row);
}


static void	get_points(t_point *points, int fd)
{
	int		y;
	char	*line;
	t_point	*tmp;

	tmp = points;
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		parse_line(&tmp, line, y);
		free(line);
		line = get_next_line(fd);
		y++;
	}
}

t_point	*parse(char *file)
{
	int		fd;
	t_point	*points;

	points = malloc(sizeof(t_point) * point_count(file));
	if (!points)
		return (NULL);
	fd = open(file, O_RDONLY);
	get_points(points, fd);
	return (points);
}
