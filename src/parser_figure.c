/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:40:44 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:25:39 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "triangle.h"
#include "square.h"
#include "cylinder.h"
#include "plane.h"
#include <stdlib.h>
#include "additional_functions_for_parsing.h"
#include "scene.h"
#include "parser_figure.h"

void	add_sphere(t_scene *scene, char *line)
{
	char		**tab;
	char		**param;
	t_sphere	*new;

	param = ft_split(line, ' ');
	new = (t_sphere*)malloc(sizeof(t_sphere));
	if (!new || !param)
		return ;
	tab = ft_split(param[1], ',');
	new->center = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	new->radius = ft_atof(param[2]) / 2;
	tab = ft_split(param[3], ',');
	new->color = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	ft_free_mas(param);
	ft_add_object(scene, new, SPHERE);
}

void	add_plane(t_scene *scene, char *line)
{
	t_plane	*new;
	char	**tab;
	char	**param;

	param = ft_split(line, ' ');
	new = (t_plane*)malloc(sizeof(t_plane));
	if (!new || !param)
		return ;
	tab = ft_split(param[1], ',');
	new->center = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	tab = ft_split(param[2], ',');
	new->normal = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	tab = ft_split(param[3], ',');
	new->color = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	ft_free_mas(param);
	ft_add_object(scene, new, PLANE);
}

void	add_square(t_scene *scene, char *line)
{
	t_square	*new;
	char		**tab;
	char		**param;

	param = ft_split(line, ' ');
	new = (t_square*)malloc(sizeof(t_square));
	if (!new || !param)
		return ;
	tab = ft_split(param[1], ',');
	new->center = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	tab = ft_split(param[2], ',');
	new->orientation = (t_vec3f){ft_atof(tab[0]),
		ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	new->side_size = ft_atof(param[3]);
	tab = ft_split(param[4], ',');
	new->color = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	square_calculation(new);
	ft_free_mas(tab);
	ft_free_mas(param);
	ft_add_object(scene, new, SQUARE);
}

void	add_cylinder(t_scene *scene, char *line)
{
	t_cylinder	*new;
	char		**tab;
	char		**param;

	param = ft_split(line, ' ');
	new = (t_cylinder*)malloc(sizeof(t_cylinder));
	if (!new || !param)
		return ;
	tab = ft_split(param[1], ',');
	new->center = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	tab = ft_split(param[2], ',');
	new->orientation = (t_vec3f){ft_atof(tab[0]),
		ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	tab = ft_split(param[3], ',');
	new->color = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	new->diameter = ft_atof(param[4]);
	new->height = ft_atof(param[5]);
	cylinder_calculation(new);
	ft_free_mas(param);
	ft_add_object(scene, new, CYLINDER);
}

void	add_triangle(t_scene *scene, char *line)
{
	t_triangle	*new;
	char		**tab;
	char		**param;

	param = ft_split(line, ' ');
	new = (t_triangle*)malloc(sizeof(t_triangle));
	if (!new || !param)
		return ;
	tab = ft_split(param[1], ',');
	new->a = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	tab = ft_split(param[2], ',');
	new->b = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	tab = ft_split(param[3], ',');
	new->c = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	tab = ft_split(param[4], ',');
	new->color = (t_vec3f){ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2])};
	ft_free_mas(tab);
	ft_free_mas(param);
	triangle_calculation(new);
	ft_add_object(scene, new, TRIANGLE);
}
