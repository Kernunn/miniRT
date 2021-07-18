/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:11:27 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:18:12 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "linear_algebra.h"

t_vec3f get_color(t_object *obj) {
  if (obj->type == SPHERE)
	return (((t_sphere *) obj->object)->color);
  else if (obj->type == PLANE)
	return (((t_plane *) obj->object)->color);
  else if (obj->type == SQUARE)
	return (((t_square *) obj->object)->color);
  else if (obj->type == CYLINDER)
	return (((t_cylinder *) obj->object)->color);
  else if (obj->type == TRIANGLE)
	return (((t_triangle *) obj->object)->color);
  return ((t_vec3f) {0, 0, 0});
}

void calculate_normal(t_light_ray *light_ray, t_light *light, t_object *obj) {
  t_vec3f direction;

  direction = multiply(-1, light_ray->view);
  if (obj->type == SPHERE)
	light_intersect_sphere(light_ray, obj->object);
  else if (obj->type == PLANE)
	light_intersect_plane(light_ray, obj->object, light);
  else if (obj->type == SQUARE)
	light_intersect_square(light_ray, obj->object, light);
  else if (obj->type == TRIANGLE)
	light_intersect_triangle(light_ray, obj->object, light);
  else if (obj->type == CYLINDER)
	light_intersect_cylinder(light_ray, direction, obj->object, light);
}

t_vec3f compute_lighting(t_vec3f point, t_vec3f view, t_scene *scene,
						 t_object *object) {
  t_list *tmp;
  t_light_ray l_ray;

  l_ray.scene = scene;
  l_ray.point = point;
  l_ray.view = view;
  l_ray.normal = (t_vec3f) {0, 0, 0};
  l_ray.color[3] = get_color(object);
  l_ray.color[2] = (t_vec3f) {0, 0, 0};
  tmp = scene->lights;
  ambient_light(&l_ray, scene->ambient_light);
  while (tmp) {
	point_light(&l_ray, object, tmp->content);
	tmp = tmp->next;
  }
  return (l_ray.color[2]);
}

float compute_point_lighting(t_light_ray *light_ray, t_light *light,
							 t_object *obj) {
  float i_n_dot_l[2];
  t_vec3f vec_l;
  t_object *shadow_obj;
  t_vec3f shadow_orig[2];
  float t[3];

  i_n_dot_l[0] = 0;
  vec_l = normalize(subtract(light->position, light_ray->point));
  calculate_normal(light_ray, light, obj);
  i_n_dot_l[1] = dot(vec_l, light_ray->normal);
  shadow_orig[0] = i_n_dot_l[1] < 0 ? subtract(light_ray->point,
											   multiply(1e-3, light_ray->normal)) :
				   add(light_ray->point, multiply(1e-3, light_ray->normal));
  t[0] = scene_intersect(shadow_orig[0], vec_l,
						 light_ray->scene, &shadow_obj);
  t[1] = length(subtract(light->position, light_ray->point));
  shadow_orig[1] = add(shadow_orig[0], multiply(t[0], vec_l));
  t[2] = length(subtract(shadow_orig[1], shadow_orig[0]));
  if (!shadow_obj || t[2] >= t[1])
	if (i_n_dot_l[1] > 0)
	  i_n_dot_l[0] += light->intensity * i_n_dot_l[1];
  return (i_n_dot_l[0]);
}
