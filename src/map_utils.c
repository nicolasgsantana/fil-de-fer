/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:19:26 by nde-sant          #+#    #+#             */
/*   Updated: 2025/09/24 12:24:17 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arrlen(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	print_map(t_list *map)
{
	t_list	*node;
	int		**row;
	int		i;

	node = map;
	while (node)
	{
		row = (int **)node->content;
		i = 0;
		while (row[i])
		{
			ft_printf("[Z: %d, Color: %X] ", row[i][0], row[i][1]);
			i++;
		}
		ft_printf("\n\n");
		node = node->next;
	}
}
