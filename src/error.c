/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:19:34 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/12 10:52:41 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	extension_error(void)
{
	ft_putstr_fd("File name must contain .fdf extension\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	graphic_error(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
