/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:48:35 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:27:51 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "linear_algebra.h"

float	intersect_ray_plane(t_vec3f origin, t_vec3f direction, t_plane *plane)
{
	float	denom;
	float	b;
	float	a;
	float	dist;

	dist = 0;
	denom = -dot(plane->normal, plane->center);
	a = dot(origin, plane->normal) + denom;
	b = dot(direction, plane->normal);
	dist = -(a / b);
	return (dist);
}
