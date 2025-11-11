/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:10:30 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/11 15:39:52 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	check_extension(char *file)
{
	int	len;
	int	pos;

	len = ft_strlen(file);
	pos = len - 4;
	if (ft_strncmp(".fdf", &file[pos], 5))
		extension_error();
}
