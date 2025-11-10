/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:19:34 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/10 12:59:31 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	extension_error(void)
{
	ft_putstr_fd("File name must contain .fdf extension\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
void	map_not_rect_error(int fd)
{
	ft_putstr_fd("Map is not rectangular.\n", STDERR_FILENO);
	close(fd);
	exit(EXIT_FAILURE);
}
