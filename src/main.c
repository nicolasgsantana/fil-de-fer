/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:40:59 by nde-sant          #+#    #+#             */
/*   Updated: 2025/09/24 12:24:52 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	
	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		print_map(get_map(fd));
		close(fd);
		ft_printf("%s\n", argv[1]);
	}
	return (0);
}
