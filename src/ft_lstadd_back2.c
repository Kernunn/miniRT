/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:42:12 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:29:26 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void ft_lstadd_back2(t_objects_lst **lst, t_objects_lst *new) {
  t_objects_lst *begin;

  if (lst) {
	begin = *lst;
	if (begin) {
	  while (begin->next)
		begin = begin->next;
	  begin->next = new;
	} else
	  *lst = new;
  }
}
