/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:24:42 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:19:33 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "linear_algebra.h"

void check(t_light_ray *light_ray, t_cylinder *cylinder, t_light *light) {
  float denom;
  float k[4];
  float t;
  t_vec3f tmp[2];
  t_vec3f point;

  tmp[0] = multiply(-1, cylinder->orientation);
  denom = -dot(cylinder->orientation, cylinder->center);
  k[0] = dot(light->position, cylinder->orientation) + denom;
  k[1] = dot(tmp[0], cylinder->orientation);
  t = -(k[0] / k[1]);
  tmp[1] = multiply(t, tmp[0]);
  point = add(light->position, tmp[1]);
  tmp[1] = subtract(light->position, point);
  light_ray->normal = normalize(tmp[1]);
}

void intersect_face(t_light_ray *light_ray, t_vec3f direction,
					t_cylinder *cylinder, t_light *light) {
  float k[3];
  t_vec3f tmp;
  t_vec3f point;

  k[0] = dot(((t_camera *) light_ray->scene->cameras->content)->position,
			 cylinder->orientation) -
	  dot(cylinder->orientation, cylinder->point1);
  k[1] = dot(direction, cylinder->orientation);
  k[2] = -(k[0] / k[1]);
  if (k[2] > 0) {
	tmp = multiply(k[2], direction);
	point = add(((t_camera *) light_ray->scene->cameras->content)->position,
				tmp);
	k[0] = distance_points(point, cylinder->point1);
	if (k[0] < cylinder->diameter / 2)
	  check(light_ray, cylinder, light);
  }
}

void intersect_ext(t_light_ray *light_ray, t_vec3f direction,
				   t_cylinder *cylinder, t_light *light) {
  t_vec3f tmp[2];
  float denom;
  float k[3];

  denom = -(dot(cylinder->orientation, cylinder->point2));
  k[0] = dot(((t_camera *) light_ray->scene->cameras->content)->position,
			 cylinder->orientation) + denom;
  k[1] = dot(direction, cylinder->orientation);
  k[2] = -(k[0] / k[1]);
  if (k[2] > 0) {
	tmp[0] = multiply(k[2], direction);
	tmp[1] = add(((t_camera *) light_ray->scene->cameras->content)->position,
				 tmp[0]);
	k[0] = distance_points(tmp[1], cylinder->point2);
	if (k[0] < cylinder->diameter / 2)
	  check(light_ray, cylinder, light);
  }
}

void light_intersect_cylinder(t_light_ray *light_ray, t_vec3f direction,
							  t_cylinder *cylinder, t_light *light) {
  t_vec3f tmp;

  tmp = subtract(light_ray->point, cylinder->center);
  light_ray->normal = normalize(tmp);
  if (dot(cylinder->orientation, direction) < 0)
	intersect_face(light_ray, direction, cylinder, light);
  else if (dot(cylinder->orientation, direction) > 0)
	intersect_ext(light_ray, direction, cylinder, light);
}
