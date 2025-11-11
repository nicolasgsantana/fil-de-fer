/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:15:26 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/11 15:48:22 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "validation.h"

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

static void	set_point(t_point *point, int coordinates[3], unsigned int color)
{
	point->x = coordinates[0];
	point->y = coordinates[1];
	point->z = coordinates[2];
	point->color = color;
}

static void	parse_line(t_point **tmp, char *line, int y)
{
	int		i;
	char	**row;
	char	**point;
	int		coordinates[3];

	row = ft_split(line, ' ');
	i = 0;
	while (row[i])
	{
		point = ft_split(row[i], ',');
		coordinates[0] = i;
		coordinates[1] = y;
		coordinates[2] = ft_atoi(point[0]);
		if (point[1])
			set_point(*tmp, coordinates, ft_htoui(point[1]));
		else
			set_point(*tmp, coordinates, UINT_MAX);
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

	check_extension(file);
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		perror("Error opening file");
		close(fd);
		exit (EXIT_FAILURE);
	}
	points = malloc(sizeof(t_point) * point_count(file));
	if (!points)
		return (NULL);
	get_points(points, fd);
	close(fd);
	return (points);
}
