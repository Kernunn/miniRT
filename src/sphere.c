/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:26:54 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:33:00 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include <math.h>
#include <linear_algebra.h>

float	intersect_ray_sphere(t_vec3f origin, t_vec3f direction,
		t_sphere *sphere)
{
	float	dist;
	t_vec3f	l;
	float	tca;
	float	d2;
	float	thc;

	l = subtract(sphere->center, origin);
	tca = dot(l, direction);
	d2 = dot(l, l) - tca * tca;
	if (d2 > sphere->radius * sphere->radius)
		return (0);
	thc = sqrtf(sphere->radius * sphere->radius - d2);
	dist = tca - thc;
	d2 = tca + thc;
	if (dist < 0)
		dist = d2;
	if (dist < 0)
		return (0);
	return (dist);
}
