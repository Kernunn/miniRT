/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:48:34 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:45:31 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CHECK_ARGUMENT_H
#	define CHECK_ARGUMENT_H

#include "libft.h"

t_list	*read_file(char *name_of_file);
t_list	*check_file(t_list *lines);
int		check_line(char *line);
int		check_r(char *line);
int		check_sp(char *line);
int		check_pl(char *line);
int		check_sq(char *line);
int		check_cy(char *line);
int		check_tr(char *line);
int		check_a(char *line);
int		check_c(char *line);
int		check_l(char *line);

#	endif
