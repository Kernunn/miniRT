/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:51:08 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:52:28 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SPHERE_H
#	define SPHERE_H

#include "vector.h"
#include "scene.h"

typedef struct	s_sphere
{
	t_vec3f	center;
	float	radius;
	t_vec3f	color;
}				t_sphere;

float			intersect_ray_sphere(t_vec3f origin, t_vec3f direction,
		t_sphere *sphere);

#	endif
