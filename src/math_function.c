/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:36:29 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 11:36:35 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}
