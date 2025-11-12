/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:26:33 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/12 10:34:28 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "utils.h"
# include <errno.h>
# include <stdio.h>
# include "MLX42.h"

void	extension_error(void);
void	mlx_error(void);

#endif
