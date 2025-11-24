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
	while (i <= steps)
	{
		mlx_put_pixel(img, round(coord[0]), round(coord[1]), UINT_MAX);
		coord[0] += dist[0] / steps;
		coord[1] += dist[1] / steps;
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
			{
				plot_line(img, p[i], p[i + 1]);
				ft_printf("draw horizontal connected p1.x: %d p1.y: %d with p2.x: %d p2.y %d\n", p[i].x, p[i].y, p[i+1].x, p[i+1].y);
			}
				
			if (r + 1 < grid.rows)
			{
				plot_line(img, p[i], p[i + grid.cols]);
				ft_printf("draw vertical connected p1.x: %d p1.y: %d with p2.x: %d p2.y %d\n", p[i].x, p[i].y, p[i+grid.cols].x, p[i+grid.cols].y);
			}
				
			c++;
		}
		r++;
	}
}

void	draw_map(mlx_image_t *img, t_point *points, t_grid grid)
{	
	t_vector	scalar;

	set_vector(&scalar, 20, 20, 20);
	rotate_z_axis(points, 45, grid.size);
	rotate_x_axis(points, 35.264389683, grid.size);
	scale_transform(points, scalar, grid.size);
	translate_2d(points, grid.size, 200, 200);
	draw_lines(img, points, grid);
}
