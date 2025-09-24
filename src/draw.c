/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:55:56 by nde-sant          #+#    #+#             */
/*   Updated: 2025/09/24 17:20:05 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calc_x(int x, int y, int z)
{
	int	x_pos;
	int	angle;

	angle = 120;
	x_pos = x * cos(angle) + y * cos(angle + 2) + z * cos(angle - 2);
	return (x_pos);
}

int	calc_y(int x, int y, int z)
{
	int	y_pos;
	int	angle;

	angle = 120;
	y_pos = x * sin(angle) + y * sin(angle + 2) + z * sin(angle - 2);
	return (y_pos);
}

void	draw_points(mlx_image_t *img, t_list *map)
{
	t_list	*node;
	int		**row;
	int		x;
	int		y;

	node = map;
	while (node)
	{
		row = (int **)node->content;
		x = 0;
		while (row[x])
		{
			mlx_put_pixel(img, x, y, row[x][1]);
			x++;
		}
		y++;
		node = node->next;
	}
}
