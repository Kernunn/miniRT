/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:50:33 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:17:32 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>

void	ft_lstclear2(t_objects_lst **lst, void (*del)(void *))
{
	t_objects_lst	*tmp;

	if (lst && del)
		while (*lst)
		{
			tmp = (*lst)->next;
			del((*lst)->object->object);
			free((*lst)->object);
			free(*lst);
			*lst = tmp;
		}
}
