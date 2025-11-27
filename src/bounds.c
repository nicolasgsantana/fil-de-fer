/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:17:24 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/27 16:19:50 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_bounds(t_point *points, t_vector *min, t_vector *max, int size)
{
	int	i;

	set_vector(max, __DBL_MIN__, __DBL_MIN__, 0);
	set_vector(min, __DBL_MAX__, __DBL_MAX__, 0);
	i = 0;
	while (i < size)
	{
		if (max->x < points[i].x)
			max->x = points[i].x;
		if (max->y < points[i].y)
			max->y = points[i].y;
		if (min->x > points[i].x)
			min->x = points[i].x;
		if (min->y > points[i].y)
			min->y = points[i].y;
		i++;
	}
}
