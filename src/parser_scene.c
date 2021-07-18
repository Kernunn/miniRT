/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:46:03 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:27:27 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_figure.h"
#include "parser_environment.h"
#include "parser_scene.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int check_scene(t_scene *scene) {
  if (scene->width <= 0 || scene->height <= 0)
	return (0);
  if (scene->ambient_light == NULL)
	return (0);
  if (scene->cameras == NULL)
	return (0);
  return (1);
}

t_scene *parser_scene(t_list *lines) {
  t_scene *scene;
  t_list *tmp;

  tmp = lines;
  scene = new_scene();
  if (!scene) {
	perror("allocation error\n");
	ft_lstclear(&lines, free);
	exit(1);
  }
  while (tmp) {
	new_object(scene, tmp->content);
	tmp = tmp->next;
  }
  ft_lstclear(&lines, free);
  if (check_scene(scene) == 0) {
	write(1, "Error\n", 6);
	del_scene(scene);
	exit(1);
  }
  return (scene);
}

void new_object(t_scene *scene, char *line) {
  if (line[0] == 'R')
	add_size(scene, line);
  else if (line[0] == 's' && line[1] == 'p')
	add_sphere(scene, line);
  else if (line[0] == 'p' && line[1] == 'l')
	add_plane(scene, line);
  else if (line[0] == 's' && line[1] == 'q')
	add_square(scene, line);
  else if (line[0] == 'c' && line[1] == 'y')
	add_cylinder(scene, line);
  else if (line[0] == 't' && line[1] == 'r')
	add_triangle(scene, line);
  else if (line[0] == 'A')
	add_ambient(scene, line);
  else if (line[0] == 'c')
	add_camera(scene, line);
  else if (line[0] == 'l')
	add_light(scene, line);
}

void ft_add_object(t_scene *scene, void *object, t_type_object type) {
  t_objects_lst *new_object;

  new_object = (t_objects_lst *) malloc(sizeof(t_objects_lst));
  new_object->next = NULL;
  if (!new_object)
	return;
  new_object->object = (t_object *) malloc(sizeof(t_object));
  if (!new_object->object)
	return;
  new_object->object->object = object;
  new_object->object->type = type;
  ft_lstadd_back2(&scene->objects, new_object);
}
