/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:36:27 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/12 16:39:54 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_transform(t_point *points, int vector[3], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		points[i].x *= vector[0];
		points[i].y *= vector[1];
		points[i].z *= vector[2];
		i++;
	}
}
