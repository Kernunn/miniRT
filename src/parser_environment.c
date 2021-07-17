/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:37:01 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:22:20 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>
#include "additional_functions_for_parsing.h"

void	add_size(t_scene *scene, char *line)
{
	char	**param;

	param = ft_split(line, ' ');
	if (!param)
		return ;
	scene->width = ft_atoi(param[1]);
	scene->height = ft_atoi(param[2]);
	ft_free_mas(param);
}

void	add_ambient(t_scene *scene, char *line)
{
	char			**color;
	char			**param;
	t_ambient_light	*new;

	param = ft_split(line, ' ');
	new = (t_ambient_light*)malloc(sizeof(t_ambient_light));
	if (!param || !new)
		return ;
	color = ft_split(param[2], ',');
	if (!color)
		return ;
	scene->ambient_light = new;
	((t_ambient_light*)(scene->ambient_light))->intensity = ft_atof(param[1]);
	((t_ambient_light*)(scene->ambient_light))->color = (t_vec3f){
		ft_atof(color[0]),
		ft_atof(color[1]),
		ft_atof(color[2])};
	ft_free_mas(color);
	ft_free_mas(param);
}

void	add_camera(t_scene *scene, char *line)
{
	t_camera	*new;
	char		**tab;
	char		**param;

	param = ft_split(line, ' ');
	new = (t_camera*)malloc(sizeof(t_camera));
	if (!new || !param)
		return ;
	ft_lstadd_back(&scene->cameras, ft_lstnew(new));
	tab = ft_split(param[1], ',');
	new->position = (t_vec3f){ft_atof(tab[0]),
		ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	tab = ft_split(param[2], ',');
	new->orientation = (t_vec3f){ft_atof(tab[0]),
		ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	new->fov = ft_atof(param[3]);
	scene->count_camera += 1;
	ft_free_mas(param);
}

void	add_light(t_scene *scene, char *line)
{
	t_light	*new;
	char	**tab;
	char	**param;

	param = ft_split(line, ' ');
	new = (t_light*)malloc(sizeof(t_light));
	if (!new || !param)
		return ;
	ft_lstadd_back(&scene->lights, ft_lstnew(new));
	tab = ft_split(param[1], ',');
	new->position = (t_vec3f){ft_atof(tab[0]),
		ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	new->intensity = ft_atof(param[2]);
	tab = ft_split(param[3], ',');
	new->color = (t_vec3f){ft_atof(tab[0]),
		ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	ft_free_mas(param);
}
