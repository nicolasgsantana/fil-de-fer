/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:36:27 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/19 14:01:00 by nde-sant         ###   ########.fr       */
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

void	rotate_x_axis(t_point *pts, int angle, int size)
{
	int	i;
	double	rad;

	rad = angle * (3.14159265358979323846 / 180);
	i = 0;
	while (i < size)
	{
		pts[i].y = (pts[i].y * cos(rad)) + (pts[i].z * sin(rad));
		pts[i].z = (pts[i].y *(-sin(rad))) + (pts[i].z * cos(rad));
		i++;
	}
}

void	rotate_y_axis(t_point *pts, int angle, int size)
{
	int	i;
	double	rad;

	rad = angle * (3.14159265358979323846 / 180);
	i = 0;
	while (i < size)
	{
		pts[i].x = (pts[i].x * cos(rad)) + (pts[i].z * (-sin(rad)));
		pts[i].z = (pts[i].x * sin(rad)) + (pts[i].z * cos(rad));
		i++;
	}
}

void	rotate_z_axis(t_point *pts, int angle, int size)
{
	int	i;
	double	rad;

	rad = angle * (3.14159265358979323846 / 180);
	i = 0;
	while (i < size)
	{
		pts[i].x = (pts[i].x * cos(rad)) + (pts[i].y * sin(rad));
		pts[i].y = (pts[i].x * (-sin(rad))) + (pts[i].y * cos(rad));
		i++;
	}
}
