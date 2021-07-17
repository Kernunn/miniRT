/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:19:37 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:18:42 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "math_function.h"

t_vec3f	clamp(t_vec3f vec)
{
	t_vec3f	result;

	result.x = max(0, min(vec.x, 255));
	result.y = max(0, min(vec.y, 255));
	result.z = max(0, min(vec.z, 255));
	return (result);
}

void	ambient_light(t_light_ray *l_ray, t_ambient_light *light)
{
	float	intensity;

	intensity = light->intensity;
	l_ray->color[1] = light->color;
	l_ray->color[0] = (t_vec3f){
		(l_ray->color[1].x + l_ray->color[3].x) * intensity,
		(l_ray->color[1].y + l_ray->color[3].y) * intensity,
		(l_ray->color[1].z + l_ray->color[3].z) * intensity};
	l_ray->color[2] = clamp(l_ray->color[0]);
}

void	point_light(t_light_ray *l_ray, t_object *obj, t_light *light)
{
	float	intensity;

	intensity = compute_point_lighting(l_ray, light, obj);
	l_ray->color[1] = (t_vec3f){
		light->color.x * intensity - l_ray->color[3].x,
		light->color.y * intensity - l_ray->color[3].y,
		light->color.z * intensity - l_ray->color[3].z};
	l_ray->color[0] = (t_vec3f){
		l_ray->color[2].x + l_ray->color[3].x + l_ray->color[1].x,
		l_ray->color[2].y + l_ray->color[3].y + l_ray->color[1].y,
		l_ray->color[2].z + l_ray->color[3].z + l_ray->color[1].z};
	l_ray->color[2] = clamp(l_ray->color[0]);
}
