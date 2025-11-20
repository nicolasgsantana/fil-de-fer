/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:36:27 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/20 13:33:37 by nde-sant         ###   ########.fr       */
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
