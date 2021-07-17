/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_figure.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:50:19 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:50:25 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PARSER_FIGURE_H
#	define PARSER_FIGURE_H

#include "scene.h"

void	add_sphere(t_scene *scene, char *param);
void	add_plane(t_scene *scene, char *param);
void	add_square(t_scene *scene, char *param);
void	add_cylinder(t_scene *scene, char *param);
void	add_triangle(t_scene *scene, char *param);
void	ft_add_object(t_scene *scene, void *object, t_type_object type);

#	endif
