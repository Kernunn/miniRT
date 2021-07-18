/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:23:44 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:31:59 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"
#include <math.h>

t_vec3f rt_x(t_vec3f vector, float x) {
  t_vec3f result;

  result.x = vector.x;
  result.y = vector.y * cosf(x) - vector.z * sinf(x);
  result.z = vector.y * sinf(x) + vector.z * cosf(x);
  return (result);
}

t_vec3f rt_y(t_vec3f vector, float y) {
  t_vec3f result;

  result.x = vector.x * cosf(y) + vector.z * sinf(y);
  result.y = vector.y;
  result.z = vector.x * -sinf(y) + vector.z * cosf(y);
  return (result);
}

t_vec3f rt_z(t_vec3f vector, float z) {
  t_vec3f result;

  result.x = vector.x * cosf(z) - vector.y * sinf(z);
  result.y = vector.x * sinf(z) + vector.y * cosf(z);
  result.z = vector.z;
  return (result);
}

t_vec3f rotation(t_vec3f vector, t_vec3f orientation) {
  t_vec3f result;

  result = vector;
  result = rt_x(result, orientation.x);
  result = rt_y(result, orientation.y);
  result = rt_z(result, orientation.z);
  return (result);
}
