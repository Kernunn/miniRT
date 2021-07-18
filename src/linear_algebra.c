/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:28:07 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:19:58 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"
#include <math.h>

float dot(t_vec3f v1, t_vec3f v2) {
  return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float length(t_vec3f v) {
  return (sqrt(dot(v, v)));
}

t_vec3f multiply(float k, t_vec3f v) {
  t_vec3f result;

  result.x = k * v.x;
  result.y = k * v.y;
  result.z = k * v.z;
  return (result);
}

t_vec3f add(t_vec3f v1, t_vec3f v2) {
  t_vec3f result;

  result.x = v1.x + v2.x;
  result.y = v1.y + v2.y;
  result.z = v1.z + v2.z;
  return (result);
}

t_vec3f subtract(t_vec3f v1, t_vec3f v2) {
  t_vec3f result;

  result.x = v1.x - v2.x;
  result.y = v1.y - v2.y;
  result.z = v1.z - v2.z;
  return (result);
}
