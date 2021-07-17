/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:50:32 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:51:10 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PLANE_H
#	define PLANE_H

#include "vector.h"

typedef struct	s_plane
{
	t_vec3f	center;
	t_vec3f	normal;
	t_vec3f	color;
}				t_plane;

float			intersect_ray_plane(t_vec3f origin,
		t_vec3f direction, t_plane *plane);

#	endif
