/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:40:59 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/12 16:22:57 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error.h"

static void ft_hook(void* param)
{
	const mlx_t* mlx = param;
	
	(void)mlx;
	// printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(int argc, char **argv)
{
	t_point		*points;
	int			size;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (argc == 2)
	{
		points = parse(argv[1]);
		size = point_count(argv[1]);
		mlx = mlx_init(WIDTH, HEIGHT, "Fil de Fer", false);
		if (!mlx)
			graphic_error();
		img = mlx_new_image(mlx, WIDTH, HEIGHT);
		if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			graphic_error();
		mlx_loop_hook(mlx, ft_hook, mlx);
		draw_points(img, points, size);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		free(points);
	}
	return (EXIT_SUCCESS);
}
