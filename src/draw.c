/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:55:56 by nde-sant          #+#    #+#             */
/*   Updated: 2025/09/25 15:58:37 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calc_x(int x, int y, int z)
{
	int	x_pos;
	int	angle;

	angle = 45;
	x_pos = (x * 10)  * cos(angle) + (y * 10) * cos(angle + 2) + (z * 5) * cos(angle - 2);
	return (x_pos);
}

int	calc_y(int x, int y, int z)
{
	int	y_pos;
	int	angle;

	angle = 45;
	y_pos = (x * 10)  * sin(angle) + (y * 10)  * sin(angle + 2) + (z * 5) * sin(angle - 2);
	return (y_pos);
}

void	draw_points(mlx_image_t *img, t_list *map)
{
	t_list	*node;
	int		**row;
	int		x;
	int		y;

	node = map;
	y = 0;
	while (node)
	{
		row = (int **)node->content;
		x = 0;
		while (row[x])
		{
			mlx_put_pixel(img, calc_x(x, y, row[x][0]) + 200, calc_y(x, y, row[x][0]) + 200, row[x][1]);
			ft_printf("X: %d, Y: %d\n", calc_x(x, y, row[x][0]), calc_y(x, y, row[x][0]));
			x++;
		}
		y++;
		node = node->next;
	}
}
