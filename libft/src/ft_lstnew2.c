/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:27:32 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/14 23:52:43 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scene.h"

t_objects_lst	*ft_lstnew2(void *content)
{
	t_objects_lst *new;

	new = (t_objects_lst *)malloc(sizeof(t_objects_lst));
	if (new)
	{
		new->object = content;
		new->next = NULL;
	}
	return (new);
}
