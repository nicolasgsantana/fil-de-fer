/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:55:56 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/12 19:35:13 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_line(mlx_image_t *img, t_point p0, t_point p1)
{
	int	dx;
	int	dy;
	int	d;
	int	y;
	int	x;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	d = 2 * dy - dx;
	y = p0.y;
	x = p0.x;
	while (x <= p1.x)
	{
		mlx_put_pixel(img, x, y, 0xFFFFFFFF);
		if (d > 0)
		{
			y++;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
		x++;
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

void	draw_points(mlx_image_t *img, t_point *points, int size)
{
	int	vector[3];

	vector[0] = 3;
	vector[1] = 3;
	vector[2] = 2;
	scale_transform(points, vector, size);
	draw_x_lines(img, points, size);
}
