/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:32:45 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:33:42 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"
#include "linear_algebra.h"

void	triangle_calculation(t_triangle *triangle)
{
	triangle->u = subtract(triangle->b, triangle->a);
	triangle->v = subtract(triangle->c, triangle->a);
	triangle->normal = cross(triangle->u, triangle->v);
	triangle->dot_uu = dot(triangle->u, triangle->u);
	triangle->dot_uv = dot(triangle->u, triangle->v);
	triangle->dot_vv = dot(triangle->v, triangle->v);
	triangle->calcul_a = 0;
	triangle->calcul_d = triangle->dot_uv * triangle->dot_uv -
		triangle->dot_uu * triangle->dot_vv;
}

float	intersect_ray_triangle2(t_vec3f orig, t_vec3f dir,
		t_triangle *triangle, float dist)
{
	t_vec3f	tmp;
	t_vec3f	point;
	float	dot_wv_wu[2];
	t_vec3f	w;
	float	r[2];

	tmp = multiply(dist, dir);
	point = add(orig, tmp);
	w = subtract(point, triangle->a);
	dot_wv_wu[0] = dot(w, triangle->u);
	dot_wv_wu[1] = dot(w, triangle->v);
	r[0] = (triangle->dot_uv * dot_wv_wu[1] - triangle->dot_vv * dot_wv_wu[0])
		/ triangle->calcul_d;
	if (r[0] < 0 || r[0] > 1)
		return (0);
	r[1] = (triangle->dot_uv * dot_wv_wu[0] - triangle->dot_uu * dot_wv_wu[1])
		/ triangle->calcul_d;
	if (r[1] < 0 || r[0] + r[1] > 1)
		return (0);
	return (dist);
}

float	intersect_ray_triangle(t_vec3f orig, t_vec3f dir, t_triangle *triangle)
{
	float	denom;
	float	b;
	float	dist;

	dist = 0;
	denom = -dot(triangle->normal, triangle->a);
	triangle->calcul_a = dot(orig, triangle->normal) + denom;
	b = dot(dir, triangle->normal);
	dist = -(triangle->calcul_a / b);
	if (dist <= 0)
		return (0);
	return (intersect_ray_triangle2(orig, dir, triangle, dist));
}
