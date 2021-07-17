/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_environment.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:50:12 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:50:00 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PARSER_ENVIRONMENT_H
#	define PARSER_ENVIRONMENT_H

#include "scene.h"

void	add_size(t_scene *scene, char *param);
void	add_ambient(t_scene *scene, char *param);
void	add_camera(t_scene *scene, char *param);
void	add_light(t_scene *scene, char *param);

#	endif
