/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:48:40 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:46:20 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CYLINDER_H
#	define CYLINDER_H

#include "vector.h"

typedef struct	s_cylinder
{
	t_vec3f	center;
	t_vec3f	orientation;
	t_vec3f	point1;
	t_vec3f	point2;
	float	diameter;
	float	height;
	t_vec3f	color;
	t_vec3f	difference;
	float	calcul_a;
	float	calcul_c;
	float	calcul_d;
}				t_cylinder;

void			cylinder_calculation(t_cylinder *cylinder);
void			cylinder_calculation2(t_vec3f orig, t_cylinder *cylinder);
float			intersect_ray_cylinder(t_vec3f origin, t_vec3f direction,
		t_cylinder *cylinder);

#	endif
