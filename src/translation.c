/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:50:34 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/27 16:35:59 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_2d(t_point *points, int size, int dx, int dy)
{
	int	i;

	i = 0;
	while (i < size)
	{
		points[i].x += dx;
		points[i].y += dy;
		i++;
	}
}

void	translate_to_center(t_point *points, int size)
{
	t_vector	min;
	t_vector	max;
	int			dx;
	int			dy;

	get_bounds(points, &min, &max, size);
	dx = (WIDTH / 2.0) - ((max.x + min.x) / 2.0);
	dy = (HEIGHT / 2.0) - ((max.y + min.y) / 2.0);
	translate_2d(points, size, dx, dy);
}
