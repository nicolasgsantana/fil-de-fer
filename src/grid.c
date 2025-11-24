/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:02:44 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/24 10:19:59 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_grid(t_grid *grid, int cols, int rows)
{
	grid->cols = cols;
	grid->rows = rows;
	grid->size = cols * rows;
}
