/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:25:31 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:32:18 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>

t_scene	*new_scene(void)
{
	t_scene	*new_scene;

	new_scene = (t_scene*)malloc(sizeof(t_scene));
	if (new_scene)
	{
		new_scene->width = 0;
		new_scene->height = 0;
		new_scene->cameras = NULL;
		new_scene->current_camera = NULL;
		new_scene->cur_camera = 1;
		new_scene->count_camera = 0;
		new_scene->ambient_light = NULL;
		new_scene->lights = NULL;
		new_scene->objects = NULL;
	}
	return (new_scene);
}

void	del_scene(t_scene *scene)
{
	if (scene->ambient_light)
		free(scene->ambient_light);
	if (scene->lights)
		ft_lstclear(&scene->lights, free);
	if (scene->objects)
		ft_lstclear2(&scene->objects, free);
	if (scene->cameras)
		ft_lstclear(&scene->cameras, free);
	free(scene);
}
