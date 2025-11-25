/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:29:27 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/25 09:37:23 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void print_map(t_point *points, t_grid grid)
{
	int total = grid.size;
	int cols  = grid.cols;

	for (int i = 0; i < total; i++)
	{
		int row = i / cols;
		int col = i % cols;

		if (col == 0 && i != 0)
			printf("\n");

		printf("[%2d,%2d]  X:%10.2f  Y:%10.2f  Z:%10.2f | ",
				row, col, points[i].x, points[i].y, points[i].z);
	}
	printf("\n");
}
