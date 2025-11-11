/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:29:27 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/11 14:35:04 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	point_count(char *file)
{
	int		fd;
	char	*line;
	char	**row;
	int		count;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		row = ft_split(line, ' ');
		count += (int)ft_arrlen(row);
		free_char_array(row);
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

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
