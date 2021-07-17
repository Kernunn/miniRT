/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:51:22 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:55:13 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef TRIANGLE_H
#	define TRIANGLE_H

#include "vector.h"

typedef struct	s_triangle
{
	t_vec3f	a;
	t_vec3f	b;
	t_vec3f	c;
	t_vec3f	u;
	t_vec3f	v;
	t_vec3f	normal;
	t_vec3f	color;
	float	calcul_a;
	float	dot_uu;
	float	dot_uv;
	float	dot_vv;
	float	calcul_d;
}				t_triangle;

float			intersect_ray_triangle(t_vec3f origin, t_vec3f direction,
		t_triangle *triangle);
void			triangle_calculation(t_triangle *square);

#	endif
