/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:55:56 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/24 12:56:26 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	plot_line(mlx_image_t *img, t_point p0, t_point p1)
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
	while (i <= steps)
	{
		mlx_put_pixel(img, round(coord[0]), round(coord[1]), UINT_MAX);
		coord[0] += (double)dist[0] / steps;
		coord[1] += (double)dist[1] / steps;
		i++;
	}
}

static void	draw_lines(mlx_image_t *img, t_point *p, t_grid grid)
{
	int	r;
	int	c;
	int	i;

	r = 0;
	while (r < grid.rows)
	{
		c = 0;
		while (c < grid.cols)
		{
			i = r * grid.cols + c;
			if (c + 1 < grid.cols)
				plot_line(img, p[i], p[i + 1]);
			if (r + 1 < grid.rows)
				plot_line(img, p[i], p[i + grid.cols]);
			c++;
		}
		r++;
	}
}

void	draw_map(mlx_image_t *img, t_point *points, t_grid grid)
{	
	set_initial_scale(points, grid.size);
	rotate_isometric(points, grid.size);
	translate_to_center(points, grid.size);
	draw_lines(img, points, grid);
}
