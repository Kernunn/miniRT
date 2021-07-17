/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:49:46 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:59:11 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIGHTING_H
#	define LIGHTING_H

#include "vector.h"
#include "scene.h"
#include "cylinder.h"
#include "triangle.h"
#include "square.h"
#include "sphere.h"
#include "plane.h"

typedef struct	s_light_ray
{
	t_vec3f	point;
	t_vec3f	normal;
	t_vec3f	view;
	t_scene	*scene;
	t_vec3f	color[4];
}				t_light_ray;

t_vec3f			compute_lighting(t_vec3f point, t_vec3f view,
		t_scene *scene, t_object *object);
float			compute_point_lighting(t_light_ray *light_ray,
		t_light *light, t_object *obj);
void			ambient_light(t_light_ray *l_ray, t_ambient_light *light);
void			point_light(t_light_ray *light_ray,
		t_object *obj, t_light *light);
t_vec3f			clamp(t_vec3f vec);
float			scene_intersect(t_vec3f orig, t_vec3f dir, t_scene *scene,
		t_object **closest_obj);
void			light_intersect_sphere(t_light_ray *light_ray,
		t_sphere *sphere);
void			light_intersect_plane(t_light_ray *light_ray,
		t_plane *plane, t_light *light);
void			light_intersect_square(t_light_ray *light_ray,
		t_square *square, t_light *light);
void			light_intersect_triangle(t_light_ray *light_ray,
		t_triangle *triangle, t_light *light);
void			light_intersect_cylinder(t_light_ray *light_ray,
		t_vec3f direction, t_cylinder *cylinder, t_light *light);

#	endif
