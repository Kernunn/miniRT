/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:03:29 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:16:38 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"
#include "cylinder.h"
#include <math.h>

float intersect_cylinder5(float d[8], t_vec3f origin, t_vec3f direction,
						  t_cylinder *o) {
  t_vec3f temp;
  t_vec3f point;
  float denom;
  float l[2];

  denom = -(dot(o->orientation, o->point2));
  l[0] = dot(origin, o->orientation) + denom;
  l[1] = dot(direction, o->orientation);
  d[5] = -(l[0] / l[1]);
  if (d[5] > 0) {
	temp = multiply(d[5], direction);
	point = add(origin, temp);
	d[0] = distance_points(point, o->point2);
	d[1] = distance_points(point, origin);
	if (d[0] < o->diameter / 2 && (!(d[2] > o->height || d[3] > o->height)))
	  return (d[4]);
	if (d[0] < o->diameter / 2)
	  return (d[5]);
  }
  if ((d[2] > o->height || d[3] > o->height))
	return (0);
  return (d[4]);
}

float intersect_cylinder4(float d[8], t_vec3f origin, t_vec3f direction,
						  t_cylinder *o) {
  t_vec3f temp;
  t_vec3f point;
  float denom;
  float l[2];

  denom = -(dot(o->orientation, o->point1));
  l[0] = dot(origin, o->orientation) + denom;
  l[1] = dot(direction, o->orientation);
  d[5] = -(l[0] / l[1]);
  if (d[5] > 0) {
	temp = multiply(d[5], direction);
	point = add(origin, temp);
	d[0] = distance_points(point, o->point1);
	d[1] = distance_points(point, origin);
	if (d[0] < o->diameter / 2 && (!(d[2] > o->height || d[3] > o->height)))
	  return (d[4]);
	if (d[0] < o->diameter / 2)
	  return (d[5]);
  }
  return (intersect_cylinder5(d, origin, direction, o));
}

float intersect_cylinder3(float d[8], t_vec3f origin, t_vec3f direction,
						  t_cylinder *o) {
  t_vec3f temp[2];
  t_vec3f point;
  float denom;
  t_vec3f point_tmp;
  float tt;

  temp[0] = multiply(d[4], direction);
  point = add(origin, temp[0]);
  denom = -(dot(o->orientation, o->point2));
  d[5] = dot(point, o->orientation) + denom;
  temp[1] = multiply(-1, o->orientation);
  d[6] = dot(temp[1], o->orientation);
  tt = -(d[5] / d[6]);
  temp[0] = multiply(tt, temp[1]);
  point_tmp = add(point, temp[0]);
  d[3] = distance_points(point, point_tmp);
  return (intersect_cylinder4(d, origin, direction, o));
}

float intersect_cylinder2(t_vec3f origin, t_vec3f direction,
						  t_cylinder *object, float ret) {
  t_vec3f temp;
  t_vec3f point;
  float denom;
  t_vec3f point_tmp;
  float d[8];

  d[4] = ret;
  temp = multiply(ret, direction);
  point = add(origin, temp);
  denom = -(dot(object->orientation, object->point1));
  d[5] = dot(point, object->orientation) + denom;
  d[6] = dot(object->orientation, object->orientation);
  d[7] = -(d[5] / d[6]);
  temp = multiply(d[7], object->orientation);
  point_tmp = add(point, temp);
  d[2] = distance_points(point, point_tmp);
  return (intersect_cylinder3(d, origin, direction, object));
}

float intersect_ray_cylinder(t_vec3f origin, t_vec3f direction,
							 t_cylinder *o) {
  float calcul_b;
  float d[6];
  float delta;
  float ret;

  cylinder_calculation2(origin, o);
  calcul_b = dot(direction, o->orientation);
  d[0] = dot(direction, direction) - (calcul_b *
	  calcul_b * o->calcul_a);
  d[1] = 2.0 * (dot(direction, o->difference)) -
	  (2 * calcul_b * o->calcul_d * o->calcul_a);
  d[2] = o->calcul_c - ((o->diameter / 2.0) * (o->diameter / 2.0)) -
	  ((o->calcul_d * o->calcul_d) * o->calcul_a);
  delta = (d[1] * d[1]) - (4.0 * d[0] * d[2]);
  if (delta < 0)
	return (0);
  d[3] = (-d[1] + sqrt(delta)) / (2.0 * d[0]);
  d[4] = (-d[1] - sqrt(delta)) / (2.0 * d[0]);
  if (d[3] < d[4])
	ret = d[3];
  else
	ret = d[4];
  return (intersect_cylinder2(origin, direction, o, ret));
}
