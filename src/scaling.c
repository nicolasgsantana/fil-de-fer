/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:51:12 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/27 15:54:26 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_transform(t_point *points, t_vector scalar, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		points[i].x *= scalar.x;
		points[i].y *= scalar.y;
		points[i].z *= scalar.z;
		i++;
	}
}
