/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:47:56 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/14 23:37:43 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef INTERSECTION_H
#	define INTERSECTION_H

#include "sphere.h"

typedef	struct	s_intersection
{
	int			is_exist;
	t_sphere	*closest_sphere;
	float		closest_t;
}				t_intersection;

#	endif
