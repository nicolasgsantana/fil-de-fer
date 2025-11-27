/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:40:59 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/27 18:20:47 by nde-sant         ###   ########.fr       */
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

static void	close_window(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	mlx_close_window(mlx);
}

static void	keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(param);
}

int32_t	main(int argc, char **argv)
{
	t_app	app;

	if (argc == 2)
	{
		parse(argv[1], &app.points, &app.grid);
		init_window(&app.mlx, &app.img);
		draw_map(app.img, app.points, app.grid);
		mlx_close_hook(app.mlx, close_window, app.mlx);
		mlx_key_hook(app.mlx, keyhook, app.mlx);
		mlx_loop(app.mlx);
		free(app.points);
		mlx_delete_image(app.mlx, app.img);
		mlx_terminate(app.mlx);
	}
	return (EXIT_SUCCESS);
}
