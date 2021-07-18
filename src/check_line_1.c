/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:03:08 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:12:44 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_functions_for_parsing.h"
#include "libft.h"

int check_sp(char *line) {
  char **tab;
  char **tmp;

  tab = ft_split(line, ' ');
  if (!count_of_word_in_the_mas(tab, 4))
	return (free_and_return(tab, NULL));
  if (!count_of_word_in_the_line(tab[1], 3))
	return (free_and_return(tab, NULL));
  if (ft_atof(tab[2]) < 0)
	return (free_and_return(tab, NULL));
  tmp = ft_split(tab[3], ',');
  if (!check_vector(tmp, 0, 255))
	return (free_and_return(tab, tmp));
  ft_free_mas(tab);
  ft_free_mas(tmp);
  return (1);
}

int check_pl(char *line) {
  char **tab;
  char **tmp;

  tab = ft_split(line, ' ');
  if (!count_of_word_in_the_mas(tab, 4))
	return (free_and_return(tab, NULL));
  if (!count_of_word_in_the_line(tab[1], 3))
	return (free_and_return(tab, NULL));
  tmp = ft_split(tab[2], ',');
  if (!check_vector(tmp, -1, 1))
	return (free_and_return(tab, tmp));
  ft_free_mas(tmp);
  tmp = ft_split(tab[3], ',');
  if (!check_vector(tmp, 0, 255))
	return (free_and_return(tab, tmp));
  ft_free_mas(tmp);
  ft_free_mas(tab);
  return (1);
}

int check_sq(char *line) {
  char **tab;
  char **tmp;

  tab = ft_split(line, ' ');
  if (!count_of_word_in_the_mas(tab, 5))
	return (free_and_return(tab, NULL));
  if (!count_of_word_in_the_line(tab[1], 3))
	return (free_and_return(tab, NULL));
  tmp = ft_split(tab[2], ',');
  if (!check_vector(tmp, -1, 1))
	return (free_and_return(tab, tmp));
  ft_free_mas(tmp);
  if (ft_atof(tab[3]) < 0)
	return (free_and_return(tab, NULL));
  tmp = ft_split(tab[4], ',');
  if (!check_vector(tmp, 0, 255))
	return (free_and_return(tab, tmp));
  ft_free_mas(tmp);
  ft_free_mas(tab);
  return (1);
}

int check_cy(char *line) {
  char **tab;
  char **tmp;

  tab = ft_split(line, ' ');
  if (!count_of_word_in_the_mas(tab, 6))
	return (free_and_return(tab, NULL));
  if (!count_of_word_in_the_line(tab[1], 3))
	return (free_and_return(tab, NULL));
  tmp = ft_split(tab[2], ',');
  if (!check_vector(tmp, -1, 1))
	return (free_and_return(tab, tmp));
  ft_free_mas(tmp);
  tmp = ft_split(tab[3], ',');
  if (!check_vector(tmp, 0, 255))
	return (free_and_return(tab, tmp));
  ft_free_mas(tmp);
  if (ft_atof(tab[4]) < 0 || ft_atof(tab[5]) < 0)
	return (free_and_return(tab, NULL));
  ft_free_mas(tab);
  return (1);
}

int check_tr(char *line) {
  char **tab;
  char **tmp;

  tab = ft_split(line, ' ');
  if (!count_of_word_in_the_mas(tab, 5))
	return (free_and_return(tab, NULL));
  if (!count_of_word_in_the_line(tab[1], 3) ||
	  !count_of_word_in_the_line(tab[2], 3) ||
	  !count_of_word_in_the_line(tab[3], 3))
	return (free_and_return(tab, NULL));
  tmp = ft_split(tab[4], ',');
  if (!check_vector(tmp, 0, 255))
	return (free_and_return(tab, tmp));
  ft_free_mas(tmp);
  ft_free_mas(tab);
  return (1);
}
