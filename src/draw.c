/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:55:56 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/20 15:23:10 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_line(mlx_image_t *img, t_point p0, t_point p1)
{
	int		dist[2];
	double	coord[2];
	int		steps;
	int		i;

	dist[0] = p1.x - p0.x;
	dist[1] = p1.y - p0.y;
	steps = imax(abs(dist[0]), abs(dist[1]));
	coord[0] = p0.x;
	coord[1] = p0.y;
	i = 0;
	while (i < steps)
	{
		mlx_put_pixel(img, round(coord[0]), round(coord[1]), UINT_MAX);
		coord[0] += dist[0] / steps;
		coord[1] += dist[1] / steps;
		i++;
	}
}

void	draw_x_lines(mlx_image_t *img, t_point *points, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i + 1 < size)
			if (points[i + 1].x)
				plot_line(img, points[i], points[i + 1]);
		i++;
	}
}

static int	get_line_len(t_point *ref_point, int size)
{
	int	i;

	i = 0;
	while (i < size && ref_point[i].y == ref_point[i + 1].y)
		i++;
	return (i + 1);
}

void	draw_y_lines(mlx_image_t *img, t_point *points, int size)
{
	int	i;
	int	width;

	i = 0;
	width = get_line_len(points, size);
	while (i + width < size)
	{
		plot_line(img, points[i], points[i + width]);
		i++;
	}
}

void	draw_points(mlx_image_t *img, t_point *points, int size)
{	
	t_vector	scalar;

	set_vector(&scalar, 10, 10 , 10);
	rotate_z_axis(points, 45, size);
	rotate_x_axis(points, atan(sqrt(2)), size);
	scale_transform(points, scalar, size);
	translate_2d(points, size, 200, 200);
	draw_x_lines(img, points, size);
	draw_y_lines(img, points, size);
}
