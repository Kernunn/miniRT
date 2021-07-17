/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:49:39 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:47:21 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIGHT_H
#	define LIGHT_H

#include "vector.h"

typedef struct	s_ambient_light
{
	float	intensity;
	t_vec3f	color;
}				t_ambient_light;

typedef struct	s_light
{
	t_vec3f	position;
	float	intensity;
	t_vec3f	color;
}				t_light;

#	endif
