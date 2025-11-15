/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:15:26 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/15 16:15:16 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "validation.h"

static void	set_point(t_point *point, t_vector vector, unsigned int color)
{
	point->x = vector.x;
	point->y = vector.y;
	point->z = vector.z;
	point->color = color;
}

static void	complete_line(t_point **tmp, int x, int y, int line_size)
{
	t_vector	coordinates;	

	while (x < line_size)
	{
		set_vector(&coordinates, x, y, 0);
		set_point(*tmp, coordinates, UINT_MAX);
		(*tmp)++;
		x++;
	}
}

static void	parse_line(t_point **tmp, char *line, int y, int line_size)
{
	int			i;
	char		**row;
	char		**point;
	t_vector	coordinates;

	row = ft_split(line, ' ');
	i = 0;
	while (row[i])
	{
		point = ft_split(row[i], ',');
		set_vector(&coordinates, i, y, ft_atoi(point[0]));
		if (point[1])
			set_point(*tmp, coordinates, ft_htoui(point[1]));
		else
			set_point(*tmp, coordinates, UINT_MAX);
		free_char_array(point);
		(*tmp)++;
		i++;
	}
	complete_line(tmp, i, y, line_size);
	free_char_array(row);
}

static void	get_points(t_point *points, int fd, int line_size)
{
	int		y;
	char	*line;
	t_point	*tmp;

	tmp = points;
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		parse_line(&tmp, line, y, line_size);
		free(line);
		line = get_next_line(fd);
		y++;
	}
}

t_point	*parse(char *file)
{
	int		fd;
	t_point	*points;
	int		line_size;

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
	line_size = get_row_size(file);
	get_points(points, fd, line_size);
	close(fd);
	return (points);
}
