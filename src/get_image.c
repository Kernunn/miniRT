/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:06:37 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:34:01 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "math_function.h"
#include "mlx.h"
#include "render.h"
#include <stdlib.h>

void	put_pixel_in_image(t_vars *v, int x, int y, int color)
{
	char	*dst;

	dst = v->data.addr + (y * v->data.line_lenght +
			x * (v->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		color(t_vec3f pixel)
{
	int r;
	int g;
	int b;
	int	color;

	r = (char)(max(0, min(255, pixel.x)));
	g = (char)(max(0, min(255, pixel.y)));
	b = (char)(max(0, min(255, pixel.z)));
	color = r << 16 | g << 8 | b;
	return (color);
}

void	put_pixel(t_vars *v, t_vec3f *framebuffer, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			put_pixel_in_image(v, j, i, color(framebuffer[i * x + j]));
			j++;
		}
		i++;
	}
}

void	set_camera(t_scene *scene, int option)
{
	int		k;
	t_list	*obj;

	k = 1;
	if (option == 1)
	{
		if (scene->cur_camera == 1)
			k = scene->count_camera;
		else
			k = scene->cur_camera - 1;
	}
	else if (option == 2)
	{
		if (scene->cur_camera == scene->count_camera)
			k = 1;
		else
			k = scene->cur_camera + 1;
	}
	scene->cur_camera = k;
	obj = ft_lst_at(scene->cameras, k);
	scene->current_camera = obj->content;
}

void	get_image(t_vars *v, int option)
{
	t_vec3f *framebuffer;

	v->data.img = mlx_new_image(v->mlx, v->scene->width, v->scene->height);
	v->data.addr = mlx_get_data_addr(v->data.img, &(v->data.bits_per_pixel),
			&(v->data.line_lenght), &(v->data.endian));
	set_camera(v->scene, option);
	framebuffer = render(v->scene);
	put_pixel(v, framebuffer, v->scene->width, v->scene->height);
	free(framebuffer);
}
