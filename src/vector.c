/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:25:44 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/24 12:40:44 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_vector(t_vector *vector, double x, double y, double z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
}
