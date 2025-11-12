/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:55:56 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/12 16:19:34 by nde-sant         ###   ########.fr       */
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

void	draw_points(mlx_image_t *img, t_point *points, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_put_pixel(img, points[i].x * 30, points[i].y * 30, points[i].color);
		i++;
	}
}
