/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:03:36 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:29:11 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "display.h"
#include "get_image.h"

int close_window(void *param) {
  mlx_destroy_image(((t_vars *) param)->mlx,
					(t_data *) (((t_vars *) param)->data).img);
  mlx_destroy_window(((t_vars *) param)->mlx, ((t_vars *) param)->win);
  free(((t_vars *) param)->mlx);
  del_scene(((t_vars *) param)->scene);
  exit(0);
}

int key_press(int keycode, void *param) {
  if (keycode == 65307) {
	mlx_destroy_image(((t_vars *) param)->mlx,
					  (t_data *) (((t_vars *) param)->data).img);
	mlx_destroy_window(((t_vars *) param)->mlx, ((t_vars *) param)->win);
	free(((t_vars *) param)->mlx);
	del_scene(((t_vars *) param)->scene);
	exit(0);
  }
  if (keycode == 65361 || keycode == 65363) {
	mlx_destroy_image(((t_vars *) param)->mlx,
					  (t_data *) (((t_vars *) param)->data).img);
	if (keycode == 65361)
	  get_image(param, 1);
	else
	  get_image(param, 2);
	mlx_put_image_to_window(((t_vars *) param)->mlx, ((t_vars *) param)->win,
							((t_vars *) param)->data.img, 0, 0);
  }
  return (0);
}

void set_screen_size(t_scene *scene, t_vars vars) {
  int x;
  int y;

  mlx_get_screen_size(vars.mlx, &x, &y);
  if (x < scene->width)
	scene->width = x;
  if (y < scene->height)
	scene->height = y;
}

void display_on_screen(t_scene *scene) {
  t_vars vars;

  if ((vars.mlx = mlx_init()) == NULL)
	exit(1);
  set_screen_size(scene, vars);
  if ((vars.win = mlx_new_window(vars.mlx, scene->width,
								 scene->height, "minirt")) == NULL)
	exit(1);
  vars.scene = scene;
  get_image(&vars, 0);
  mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
  mlx_hook(vars.win, 17, 1L << 17, close_window, &vars);
  mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
  mlx_loop(vars.mlx);
}
