/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:03:12 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:13:57 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_functions_for_parsing.h"
#include "libft.h"

int	check_r(char *line)
{
	char		**tab;
	static int	count = 0;

	if (count > 0)
		return (0);
	tab = ft_split(line, ' ');
	if (!count_of_word_in_the_mas(tab, 3))
		return (free_and_return(tab, NULL));
	if (ft_atoi(tab[1]) < 0)
		return (free_and_return(tab, NULL));
	if (ft_atoi(tab[2]) < 0)
		return (free_and_return(tab, NULL));
	ft_free_mas(tab);
	count++;
	return (1);
}

int	check_a(char *line)
{
	char		**tab;
	char		**tmp;
	static int	count = 0;

	if (count > 0)
		return (0);
	tab = ft_split(line, ' ');
	if (!count_of_word_in_the_mas(tab, 3))
		return (free_and_return(tab, NULL));
	if (ft_atof(tab[1]) < 0 || ft_atof(tab[1]) > 1)
		return (free_and_return(tab, NULL));
	tmp = ft_split(tab[2], ',');
	if (!check_vector(tmp, 0, 255))
		return (free_and_return(tab, tmp));
	ft_free_mas(tmp);
	ft_free_mas(tab);
	count++;
	return (1);
}

int	check_c(char *line)
{
	char	**tab;
	char	**tmp;

	tab = ft_split(line, ' ');
	if (!count_of_word_in_the_mas(tab, 4))
		return (free_and_return(tab, NULL));
	if (!count_of_word_in_the_line(tab[1], 3))
		return (free_and_return(tab, NULL));
	tmp = ft_split(tab[2], ',');
	if (!check_vector(tmp, -1, 1))
		return (free_and_return(tab, tmp));
	ft_free_mas(tmp);
	if (ft_atof(tab[3]) < 0 || ft_atof(tab[3]) > 180)
		return (free_and_return(tab, NULL));
	ft_free_mas(tab);
	return (1);
}

int	check_l(char *line)
{
	char	**tab;
	char	**tmp;

	tab = ft_split(line, ' ');
	if (!count_of_word_in_the_mas(tab, 4))
		return (free_and_return(tab, NULL));
	if (!count_of_word_in_the_line(tab[1], 3))
		return (free_and_return(tab, NULL));
	if (ft_atof(tab[2]) < 0 || ft_atof(tab[2]) > 1)
		return (free_and_return(tab, NULL));
	tmp = ft_split(tab[3], ',');
	if (!check_vector(tmp, 0, 255))
		return (free_and_return(tab, tmp));
	ft_free_mas(tmp);
	ft_free_mas(tab);
	return (1);
}
