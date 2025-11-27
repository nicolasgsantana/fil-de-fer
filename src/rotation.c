/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:49:40 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/27 16:13:37 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x_axis(t_point *pts, double angle, int size)
{
	int		i;
	double	rad;
	double		y;
	double		z;

	rad = angle * (3.14159265358979323846 / 180);
	i = 0;
	while (i < size)
	{
		y = pts[i].y * cos(rad) - pts[i].z * sin(rad);
		z = pts[i].y * sin(rad) + pts[i].z * cos(rad);
		pts[i].y = y;
		pts[i].z = z;
		i++;
	}
}

void	rotate_y_axis(t_point *pts, double angle, int size)
{
	int		i;
	double	rad;
	double		x;
	double		z;

	rad = angle * (3.14159265358979323846 / 180);
	i = 0;
	while (i < size)
	{
		x = pts[i].x * cos(rad) + pts[i].z * sin(rad);
		z = -pts[i].x * sin(rad) + pts[i].z * cos(rad);
		pts[i].x = x;
		pts[i].z = z;
		i++;
	}
}

void	rotate_z_axis(t_point *pts, double angle, int size)
{
	int		i;
	double	rad;
	double	x;
	double	y;

	rad = angle * (3.14159265358979323846 / 180);
	i = 0;
	while (i < size)
	{
		x = pts[i].x * cos(rad) - pts[i].y * sin(rad);
		y = pts[i].x * sin(rad) + pts[i].y * cos(rad);
		pts[i].x = x;
		pts[i].y = y;
		i++;
	}
}

void	rotate_isometric(t_point *points, int size)
{
	rotate_z_axis(points, 45, size);
	rotate_x_axis(points, 35.264389683, size);
}
