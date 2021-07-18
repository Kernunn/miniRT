/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:52:27 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/14 23:53:47 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lst_at(t_list *begin_list, unsigned int nbr) {
  unsigned int i;

  i = 1;
  while (begin_list && i < nbr) {
	begin_list = begin_list->next;
	i++;
  }
  return (begin_list);
}
