/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:03:23 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:15:41 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "linear_algebra.h"
#include "cylinder.h"

void	cylinder_calculation(t_cylinder *cylinder)
{
	t_vec3f	tmp;
	float	total;

	total = fabsf(cylinder->orientation.x) + fabsf(cylinder->orientation.y) +
		fabsf(cylinder->orientation.z);
	tmp = (t_vec3f){cylinder->height / 2 * (cylinder->orientation.x / total),
		cylinder->height / 2 * (cylinder->orientation.y / total),
		cylinder->height / 2 * (cylinder->orientation.z / total)};
	cylinder->point1 = add(cylinder->center, tmp);
	tmp = (t_vec3f){-cylinder->height / 2 * (cylinder->orientation.x / total),
		-cylinder->height / 2 * (cylinder->orientation.y / total),
		-cylinder->height / 2 * (cylinder->orientation.z / total)};
	cylinder->point2 = add(cylinder->center, tmp);
	cylinder->height = distance_points(cylinder->point1, cylinder->point2);
	cylinder->difference = (t_vec3f){0, 0, 0};
	cylinder->calcul_a = 1.0f / dot(cylinder->orientation,
			cylinder->orientation);
}

void	cylinder_calculation2(t_vec3f orig, t_cylinder *cylinder)
{
	cylinder->difference = subtract(orig, cylinder->center);
	cylinder->calcul_c = dot(cylinder->difference, cylinder->difference);
	cylinder->calcul_d = dot(cylinder->orientation, cylinder->difference);
}
