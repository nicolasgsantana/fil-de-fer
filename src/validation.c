/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:10:30 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/10 13:01:00 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static void	check_extension(char *file)
{
	int	len;
	int	pos;
	
	len = ft_strlen(file);
	pos = len - 4;
	if (ft_strncmp(".fdf", &file[pos], 5))
		extension_error();
}

static int	check_rect_map(int fd)
{
	char	*line;
	char	**points;
	size_t	len;
	int		errors;

	line = get_next_line(fd);
	points = ft_split(line, ' ');
	len = ft_arrlen(points);
	errors = 0;
	while (line)
	{
		if(len != ft_arrlen(points))
			errors++;
		len = ft_arrlen(points);
		free(line);
		free_char_array(points);
		line = get_next_line(fd);
		points = ft_split(line, ' ');
	}
	return (errors);
}

void	validate_file(char *file)
{
	int	fd;

	check_extension(file);
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		perror("Error opening file");
		close(fd);
		exit (EXIT_FAILURE);
	}
	if (check_rect_map(fd))
		map_not_rect_error(fd);
	close(fd);
}
