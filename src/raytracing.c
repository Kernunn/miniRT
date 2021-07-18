/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:49:49 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:30:02 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"
#include "cylinder.h"
#include "plane.h"
#include "square.h"
#include "sphere.h"
#include <float.h>
#include "linear_algebra.h"
#include "lighting.h"

float ray_intersect(t_vec3f orig, t_vec3f dir, t_object *object) {
  float dist;

  dist = 0;
  if (object->type == SPHERE)
	dist = intersect_ray_sphere(orig, dir, object->object);
  else if (object->type == PLANE)
	dist = intersect_ray_plane(orig, dir, object->object);
  else if (object->type == SQUARE)
	dist = intersect_ray_square(orig, dir, object->object);
  else if (object->type == CYLINDER)
	dist = intersect_ray_cylinder(orig, dir, object->object);
  else if (object->type == TRIANGLE)
	dist = intersect_ray_triangle(orig, dir, object->object);
  return (dist);
}

float scene_intersect(t_vec3f orig, t_vec3f dir, t_scene *scene,
					  t_object **closest_obj) {
  float tmp_dist;
  float closest_t;
  t_objects_lst *objects;

  *closest_obj = NULL;
  closest_t = FLT_MAX;
  objects = scene->objects;
  while (objects) {
	tmp_dist = ray_intersect(orig, dir, objects->object);
	if (tmp_dist > scene->t_min && tmp_dist < closest_t) {
	  closest_t = tmp_dist;
	  *closest_obj = objects->object;
	}
	objects = objects->next;
  }
  return (closest_t);
}

t_vec3f castray(t_vec3f orig, t_vec3f dir, t_scene *scene) {
  float closest_t;
  t_object *closest_obj;
  t_vec3f color;
  t_vec3f l_point;
  t_vec3f l_view;

  scene->t_max = -1;
  scene->t_min = 0.001f;
  closest_t = scene_intersect(orig, dir, scene, &closest_obj);
  if (!closest_obj)
	return ((t_vec3f) {10, 10, 10});
  l_point = add(orig, multiply(closest_t, dir));
  l_view = multiply(-1, dir);
  color = compute_lighting(l_point, l_view, scene, closest_obj);
  return (color);
}
