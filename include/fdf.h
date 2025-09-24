/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:46:40 by nde-sant          #+#    #+#             */
/*   Updated: 2025/09/24 14:37:18 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "MLX42.h"
#include "libft.h"
#include <math.h>

# define WIDTH 720
# define HEIGHT 720
# define DEFAULT_COLOR 0xFFFFFFFF

void	free_char_array(char **array);
size_t	ft_arrlen(char **array);
t_list	*get_map(int fd);
void	print_map(t_list *map);
int	ft_htoi(char *hex);
