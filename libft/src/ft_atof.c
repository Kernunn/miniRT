/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:54:03 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/14 23:57:45 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	pow_rem(int k)
{
	float	result;

	result = 1;
	while (k-- != 0)
		result *= 0.1;
	return (result);
}

float			ft_atof(const char *str)
{
	float	result;
	float	tmp;
	size_t	k;
	int		sign;

	tmp = 0;
	k = 0;
	result = ft_atoi(str);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = *str == '-' ? -1 : 1;
	while (*str != '.' && *str != '\0')
		str++;
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		tmp = tmp * 10 + sign * (*str++ - '0');
		k++;
	}
	result += tmp * pow_rem(k);
	return (result);
}
