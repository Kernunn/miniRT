/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:51:15 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:55:03 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SQUARE_H
#	define SQUARE_H

#include "vector.h"

typedef struct s_square {
  t_vec3f center;
  t_vec3f orientation;
  float side_size;
  t_vec3f a;
  t_vec3f b;
  t_vec3f c;
  t_vec3f d;
  t_vec3f ab;
  t_vec3f ac;
  t_vec3f normal;
  float calcul_a;
  t_vec3f color;
} t_square;

float intersect_ray_square(t_vec3f origin, t_vec3f direction,
						   t_square *square);
void square_calculation(t_square *square);

#	endif
