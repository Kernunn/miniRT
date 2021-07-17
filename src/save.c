/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:25:17 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 12:25:19 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "render.h"
#include "bmp.h"

void	save(t_scene *scene)
{
	t_vec3f *framebuffer;

	scene->current_camera = scene->cameras->content;
	framebuffer = render(scene);
	write_to_bmp(framebuffer, scene->width, scene->height);
	free(framebuffer);
}
