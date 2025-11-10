/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:40:59 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/10 12:45:59 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;
	
// 	(void)mlx;
// 	// printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

int32_t	main(int argc, char **argv)
{
	int		fd;
	t_list	*map;

	if (argc == 2)
	{
		validate_file(argv[1]);
		(void)map;
		(void)fd;
	// 	fd = open(argv[1], O_RDONLY);
	// 	map = get_map(fd);
	// 	close(fd);
	// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Fil de Fer", false);
	// 	if (!mlx)
	// 		ft_error();
	// 	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	// 		ft_error();
	// 	mlx_loop_hook(mlx, ft_hook, mlx);
	// 	draw_points(img, map);
	// 	mlx_loop(mlx);
	// 	mlx_terminate(mlx);
	}
	return (EXIT_SUCCESS);
}
