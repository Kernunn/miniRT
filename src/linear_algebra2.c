/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:29:16 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:20:13 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"
#include <math.h>

t_vec3f	normalize(t_vec3f v)
{
	t_vec3f result;

	result = v;
	result = multiply(1 / length(v), v);
	return (result);
}

t_vec3f	cross(t_vec3f v1, t_vec3f v2)
{
	t_vec3f result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

t_vec3f	mult_vec_matrix(float *mat, t_vec3f vec)
{
	t_vec3f result;
	float	a;
	float	b;
	float	c;
	float	w;

	a = vec.x * mat[0] + vec.y * mat[4] + vec.z * mat[8] + mat[12];
	b = vec.x * mat[1] + vec.y * mat[5] + vec.z * mat[9] + mat[13];
	c = vec.x * mat[2] + vec.y * mat[6] + vec.z * mat[10] + mat[14];
	w = vec.x * mat[3] + vec.y * mat[7] + vec.z * mat[11] + mat[15];
	result.x = a / w;
	result.y = b / w;
	result.z = c / w;
	return (result);
}

t_vec3f	mult_dir_matrix(float *mat, t_vec3f vec)
{
	t_vec3f	result;
	float	a;
	float	b;
	float	c;

	a = vec.x * mat[0] + vec.y * mat[4] + vec.z * mat[8];
	b = vec.x * mat[1] + vec.y * mat[5] + vec.z * mat[9];
	c = vec.x * mat[2] + vec.y * mat[6] + vec.z * mat[10];
	result.x = a;
	result.y = b;
	result.z = c;
	return (result);
}

float	distance_points(t_vec3f p1, t_vec3f p2)
{
	return (sqrtf((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) *
				(p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z)));
}
