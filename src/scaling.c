/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:51:12 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/27 18:23:16 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	scale_transform(t_point *p, t_vector scalar, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		p[i].x *= scalar.x;
		p[i].y *= scalar.y;
		p[i].z *= scalar.z;
		i++;
	}
}

static double	get_scale(t_point *p, int size)
{
	t_vector	min;
	t_vector	max;
	double		scale_x;
	double		scale_y;

	get_bounds(p, &min, &max, size);
	scale_x = WIDTH * 0.8 / (max.x - min.x);
	scale_y = HEIGHT * 0.8 / (max.y - min.y);
	return (fmin(scale_x, scale_y));
}

void	set_initial_scale(t_point *points, int size)
{
	t_vector	scalar;
	double		scale;
	t_point		*copy;

	copy = malloc(size * sizeof(t_point));
	copy = ft_memcpy(copy, points, size * sizeof(t_point));
	rotate_isometric(copy, size);
	scale = get_scale(copy, size);
	set_vector(&scalar, scale, scale, scale);
	scale_transform(points, scalar, size);
	free(copy);
}
