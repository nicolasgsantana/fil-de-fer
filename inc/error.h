/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:26:33 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/10 13:10:29 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "utils.h"
# include <errno.h>
# include <stdio.h>

void	extension_error(void);
void	map_not_rect_error(int fd);

#endif
