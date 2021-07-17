/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:50:25 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:50:57 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PARSER_SCENE_H
#	define PARSER_SCENE_H

#include "scene.h"
#include "libft.h"

t_scene			*parser_scene(t_list *lines);
void			new_object(t_scene *scene, char *line);
void			ft_lstadd_back2(t_objects_lst **lst, t_objects_lst *new);
t_objects_lst	*ft_lstnew2(void *content);

#	endif
