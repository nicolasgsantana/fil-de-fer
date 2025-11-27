/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:17:24 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/27 18:24:50 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_bounds(t_point *p, t_vector *min, t_vector *max, int size)
{
	int	i;

	set_vector(max, __DBL_MIN__, __DBL_MIN__, 0);
	set_vector(min, __DBL_MAX__, __DBL_MAX__, 0);
	i = 0;
	while (i < size)
	{
		if (max->x < p[i].x)
			max->x = p[i].x;
		if (max->y < p[i].y)
			max->y = p[i].y;
		if (min->x > p[i].x)
			min->x = p[i].x;
		if (min->y > p[i].y)
			min->y = p[i].y;
		i++;
	}
}
