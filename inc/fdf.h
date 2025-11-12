/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:46:40 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/12 16:41:04 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42.h"
# include "utils.h"
# include <math.h>
# include <stdio.h>
# include <limits.h>

# define WIDTH 720
# define HEIGHT 720
# define SPACE 10

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}					t_point;

unsigned int	ft_htoui(char *hex);
t_point			*parse(char *file);
void			draw_points(mlx_image_t *img, t_point *points, int size);
void 			plot_line(mlx_image_t *img, t_point p0, t_point p1);
void			scale_transform(t_point *points, int vector[3], int size);

// DEBUG ONLY REMOVE LATER
void	print_map(t_point *points, char *file);

#endif
