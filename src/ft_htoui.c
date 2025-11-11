/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:04:42 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/11 15:25:44 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	get_decimal(char hex_char)
{
	char	*hex_chars;
	int		i;

	hex_chars = "0123456789ABCDEF";
	i = 0;
	while (hex_chars[i])
	{
		if (hex_chars[i] == ft_toupper(hex_char))
			break ;
		i++;
	}
	return (i);
}

unsigned int	ft_htoui(char *hex)
{
	int				i;
	int				hexlen;
	unsigned int	result;

	i = 0;
	result = 0;
	hexlen = ft_strlen(hex) - 1;
	while (ft_isspace(hex[i]))
		i++;
	if (hex[i] == '0')
		i++;
	if (hex[i] == 'x')
		i++;
	hexlen -= i;
	while (hex[i])
	{
		if (hexlen > 0)
			result += get_decimal(hex[i]) * (pow(16, hexlen));
		else
			result += get_decimal(hex[i]);
		hexlen--;
		i++;
	}
	return (result);
}
