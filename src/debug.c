/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:29:27 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/24 12:32:40 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_map(t_point *points, t_grid grid)
{
	t_point	*tmp;
	int	col;

	tmp = points;
	col = 0;
	while (grid.size)
	{
		if (col > grid.cols)
		{
			col = 0;
			printf("\n");
		}
		printf("X:%10.2f  Y:%10.2f  Z:%10.2f | ", tmp->x, tmp->y, tmp->z);
		//printf("color: %u | ", tmp->color);
		grid.size--;
		tmp++;
		col++;
	}
}
