/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:29:27 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/12 10:36:00 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_point *points, char *file)
{
	t_point	*tmp;
	int		last_y;
	int		size;

	tmp = points;
	last_y = tmp->y;
	size = point_count(file);
	while (size)
	{
		if (last_y < tmp->y)
		{
			last_y = tmp->y;
			ft_printf("\n");
		}
		ft_printf("X:%i, ", tmp->x);
		ft_printf("Y:%i, ", tmp->y);
		ft_printf("Z:%i, ", tmp->z);
		ft_printf("color: %u ", tmp->color);
		size--;
		tmp++;
	}
}
