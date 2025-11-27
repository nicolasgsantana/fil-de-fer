/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:46:40 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/27 16:22:37 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42.h"
# include "utils.h"
# include <math.h>
# include <stdio.h>
# include <limits.h>

# define WIDTH 1600
# define HEIGHT 900
# define SPACE 10

typedef struct s_point
{
	double				x;
	double				y;
	double				z;
	unsigned int	color;
}					t_point;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}		t_vector;

typedef struct s_grid
{
	int	cols;
	int	rows;
	int	size;
}		t_grid;

typedef struct s_app
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_point		*points;
	t_grid		grid;
}				t_app;


void			set_vector(t_vector *vector, double x, double y, double z);
unsigned int	ft_htoui(char *hex);
void			parse(char *file, t_point **points, t_grid *grid);
void			draw_map(mlx_image_t *img, t_point *points, t_grid grid);
void			set_initial_scale(t_point *points, int size);
void			translate_2d(t_point *points, int size, int dx, int dy);
void			rotate_x_axis(t_point *pts, double angle, int size);
void			rotate_y_axis(t_point *pts, double angle, int size);
void			rotate_z_axis(t_point *pts, double angle, int size);
void			rotate_isometric(t_point *points, int size);
void			translate_to_center(t_point *points, int size);
int				imax(int x, int y);
int				get_col_count(char *file);
void			set_grid(t_grid *grid, int cols, int rows);
int				get_row_count(char *file);
void			get_bounds(t_point *points, t_vector *min, t_vector *max, int size);

// DEBUG ONLY REMOVE LATER
void	print_map(t_point *points, t_grid grid);

#endif
