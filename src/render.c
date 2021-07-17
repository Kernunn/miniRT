/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:52:07 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:31:26 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "linear_algebra.h"
#include "scene.h"
#include "raytracing.h"

float	*fill_cam_to_world(t_vec3f forward, t_vec3f right,
		t_vec3f up, t_vec3f from)
{
	float	*cam_to_world;

	cam_to_world = malloc(sizeof(float) * 16);
	if (!cam_to_world)
		exit(1);
	cam_to_world[0] = right.x;
	cam_to_world[1] = right.y;
	cam_to_world[2] = right.z;
	cam_to_world[3] = 0;
	cam_to_world[4] = up.x;
	cam_to_world[5] = up.y;
	cam_to_world[6] = up.z;
	cam_to_world[7] = 0;
	cam_to_world[8] = forward.x;
	cam_to_world[9] = forward.y;
	cam_to_world[10] = forward.z;
	cam_to_world[11] = 0;
	cam_to_world[12] = from.x;
	cam_to_world[13] = from.y;
	cam_to_world[14] = from.z;
	cam_to_world[15] = 1;
	return (cam_to_world);
}

void	look_at(float **cam_to_world, t_vec3f from, t_vec3f to)
{
	t_vec3f forward;
	t_vec3f right;
	t_vec3f up;

	forward = normalize(subtract(from, to));
	right = cross((t_vec3f){0, 1, 0}, forward);
	if (to.y - from.y == -1 || to.y - from.y == 1)
		right = (t_vec3f){1, 0, 0};
	up = cross(forward, right);
	*cam_to_world = fill_cam_to_world(forward, right, up, from);
}

t_vec3f	*render_1(float *cam_to_world, t_scene *scene,
		float aspect_ratio, float scale)
{
	int		j;
	int		i;
	t_vec3f	dir;
	t_vec3f	orig;
	t_vec3f	*framebuffer;

	orig = mult_vec_matrix(cam_to_world, (t_vec3f){0, 0, 0});
	framebuffer = malloc(scene->width * scene->height * sizeof(t_vec3f));
	if (!framebuffer)
		exit(1);
	j = 0;
	while (j < scene->height)
	{
		i = 0;
		while (i < scene->width)
		{
			dir = normalize(mult_dir_matrix(cam_to_world, (t_vec3f){
			(2 * (i + 0.5) / (float)scene->width - 1) * aspect_ratio * scale,
			(1 - 2 * (j + 0.5) / (float)scene->height) * scale, -1}));
			framebuffer[j * scene->width + i] = castray(orig, dir, scene);
			i++;
		}
		j++;
	}
	return (framebuffer);
}

t_vec3f	*render(t_scene *scene)
{
	t_vec3f		*framebuffer;
	t_camera	*camera;
	float		*cam_to_world;
	float		scale;
	float		aspect_ratio;

	camera = scene->current_camera;
	look_at(&cam_to_world, camera->position,
			add(camera->position, camera->orientation));
	aspect_ratio = scene->width / (float)scene->height;
	scale = tan(camera->fov * 0.5 * M_PI / 180);
	framebuffer = render_1(cam_to_world, scene, aspect_ratio, scale);
	free(cam_to_world);
	return (framebuffer);
}
