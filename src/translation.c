/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:50:34 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/27 15:52:14 by nde-sant         ###   ########.fr       */
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
