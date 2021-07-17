/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:51:01 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:54:28 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SCENE_H
#	define SCENE_H

#include "libft.h"
#include "light.h"

typedef struct	s_camera
{
	t_vec3f	position;
	t_vec3f	orientation;
	float	fov;
}				t_camera;

typedef enum	e_type_object{
	SPHERE, PLANE, SQUARE, CYLINDER, TRIANGLE
}				t_type_object;

typedef struct	s_object
{
	t_type_object	type;
	void			*object;
}				t_object;

typedef struct	s_objects_lst
{
	t_object				*object;
	struct s_objects_lst	*next;
}				t_objects_lst;

typedef struct	s_scene
{
	int				width;
	int				height;
	t_ambient_light	*ambient_light;
	t_list			*cameras;
	t_camera		*current_camera;
	int				cur_camera;
	int				count_camera;
	t_list			*lights;
	t_objects_lst	*objects;
	float			t_min;
	float			t_max;
}				t_scene;

t_scene			*new_scene(void);
void			del_scene(t_scene *scene);
void			ft_lstclear2(t_objects_lst **lst, void (*del)(void *));

#	endif
