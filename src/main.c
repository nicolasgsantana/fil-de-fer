/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:40:59 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/27 12:52:52 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error.h"

static void	init_window(mlx_t **mlx, mlx_image_t **img)
{
	*mlx = mlx_init(WIDTH, HEIGHT, "Fil de Fer", false);
	if (!(*mlx))
		graphic_error();
	*img = mlx_new_image(*mlx, WIDTH, HEIGHT);
	if (!(*img) || (mlx_image_to_window(*mlx, *img, 0, 0) < 0))
		graphic_error();
	mlx_set_window_pos(*mlx, (1920 - WIDTH) / 2, (1080 - HEIGHT) / 2);
}

int32_t	main(int argc, char **argv)
{
	t_app	app;

	if (argc == 2)
	{
		app.initialized = 0;
		parse(argv[1], &app.points, &app.grid);
		init_window(&app.mlx, &app.img);
		draw_map(app.img, app.points, app.grid);
		mlx_loop(app.mlx);
		mlx_terminate(app.mlx);
		free(app.points);
	}
	return (EXIT_SUCCESS);
}
