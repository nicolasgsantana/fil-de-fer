/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:08:30 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/12 10:30:52 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include <fcntl.h>

size_t	ft_arrlen(char **array);
void	free_char_array(char **array);
int		point_count(char *file);

#endif
