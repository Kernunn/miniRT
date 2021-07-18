/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:49:53 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:49:38 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LINEAR_ALGEBRA_H
#	define LINEAR_ALGEBRA_H

#include "vector.h"

float dot(t_vec3f v1, t_vec3f v2);
float length(t_vec3f v);
t_vec3f multiply(float k, t_vec3f v);
t_vec3f add(t_vec3f v1, t_vec3f v2);
t_vec3f subtract(t_vec3f v1, t_vec3f v2);
t_vec3f normalize(t_vec3f v);
t_vec3f cross(t_vec3f v1, t_vec3f v2);
t_vec3f mult_vec_matrix(float *mat, t_vec3f vec);
t_vec3f mult_dir_matrix(float *mat, t_vec3f vec);
t_vec3f rotation(t_vec3f vector, t_vec3f orientation);
float distance_points(t_vec3f p1, t_vec3f p2);

#	endif
