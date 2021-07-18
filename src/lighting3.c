/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:22:34 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:19:10 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "linear_algebra.h"

void light_intersect_sphere(t_light_ray *light_ray, t_sphere *sphere) {
  light_ray->normal = normalize(subtract(light_ray->point, sphere->center));
}

void light_intersect_plane(t_light_ray *light_ray,
						   t_plane *plane, t_light *light) {
  float k[2];
  t_vec3f tmp[3];
  float denom;
  float t;

  tmp[1] = multiply(-1, plane->normal);
  denom = -dot(plane->normal, plane->center);
  k[0] = dot(light->position, plane->normal) + denom;
  k[1] = dot(tmp[1], plane->normal);
  t = -(k[0] / k[1]);
  tmp[2] = multiply(t, tmp[1]);
  tmp[0] = add(light->position, tmp[2]);
  tmp[2] = subtract(light->position, tmp[0]);
  light_ray->normal = normalize(tmp[2]);
}

void light_intersect_square(t_light_ray *light_ray,
							t_square *square, t_light *light) {
  t_vec3f tmp;
  t_vec3f tmp2;
  float k[2];
  float t;
  t_vec3f point;

  tmp2 = multiply(-1, square->orientation);
  k[0] = dot(light->position, square->orientation) -
	  (dot(square->orientation, square->center));
  k[1] = dot(tmp2, square->orientation);
  t = -(k[0] / k[1]);
  tmp = multiply(t, tmp2);
  point = add(light->position, tmp);
  tmp = subtract(light->position, point);
  light_ray->normal = normalize(tmp);
}

void light_intersect_triangle(t_light_ray *light_ray,
							  t_triangle *triangle, t_light *light) {
  t_vec3f v[6];
  float k[4];
  float t;

  v[1] = subtract(triangle->b, triangle->a);
  v[2] = subtract(triangle->c, triangle->a);
  v[0] = cross(v[1], v[2]);
  v[3] = multiply(-1, v[0]);
  k[0] = dot(light->position, v[0]) - dot(v[0], triangle->a);
  k[1] = dot(v[3], v[0]);
  t = -(k[0] / k[1]);
  v[5] = multiply(t, v[3]);
  v[4] = add(light->position, v[5]);
  v[5] = subtract(light->position, v[4]);
  light_ray->normal = normalize(v[5]);
}
