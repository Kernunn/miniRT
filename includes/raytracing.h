/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:50:41 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:51:27 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RAYTRACING_H
#	define RAYTRACING_H

#include "vector.h"
#include "scene.h"

t_vec3f	castray(t_vec3f camera_position, t_vec3f direction, t_scene *scene);

#	endif
