/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:31:12 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:33:20 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "linear_algebra.h"

float intersect_ray_square_2(t_vec3f origin, t_vec3f direction,
							 t_square *square, float dist) {
  t_vec3f point;
  t_vec3f temp;
  t_vec3f ap;
  float alpha;
  float beta;

  temp = multiply(dist, direction);
  point = add(origin, temp);
  ap = subtract(point, square->a);
  alpha = dot(ap, square->ab) / dot(square->ab, square->ab);
  beta = dot(ap, square->ac) / dot(square->ac, square->ac);
  if (alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1)
	return (dist);
  return (0);
}

float intersect_ray_square(t_vec3f origin, t_vec3f direction,
						   t_square *square) {
  float dist;
  float denom;
  float alpha;

  denom = -dot(square->normal, square->center);
  square->calcul_a = dot(origin, square->normal) + denom;
  alpha = dot(direction, square->normal);
  dist = -(square->calcul_a / alpha);
  if (dist <= 0)
	return (0);
  return (intersect_ray_square_2(origin, direction, square, dist));
}

void calculation_corner(t_square *square) {
  t_vec3f vectors[4];

  vectors[0] = (t_vec3f) {square->side_size / 2, square->side_size / 2, 0};
  vectors[1] = (t_vec3f) {-square->side_size / 2, square->side_size / 2, 0};
  vectors[2] = (t_vec3f) {square->side_size / 2, -square->side_size / 2, 0};
  vectors[3] = (t_vec3f) {-square->side_size / 2, -square->side_size / 2, 0};
  vectors[0] = rotation(vectors[0], square->orientation);
  vectors[1] = rotation(vectors[1], square->orientation);
  vectors[2] = rotation(vectors[2], square->orientation);
  vectors[3] = rotation(vectors[3], square->orientation);
  square->a = add(vectors[0], square->center);
  square->b = add(vectors[1], square->center);
  square->c = add(vectors[2], square->center);
  square->d = add(vectors[3], square->center);
}

void square_calculation(t_square *square) {
  calculation_corner(square);
  square->ab = subtract(square->b, square->a);
  square->ac = subtract(square->c, square->a);
  square->normal = cross(square->ab, square->ac);
  square->calcul_a = 0;
}
