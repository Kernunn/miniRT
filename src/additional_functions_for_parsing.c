/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions_for_parsing.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:02:44 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:41:16 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_functions_for_parsing.h"
#include "libft.h"
#include <stdlib.h>

int count_of_word_in_the_line(char *line, int k) {
  char **tab;
  int result;

  if (!line)
	return (0);
  tab = ft_split(line, ',');
  result = count_of_word_in_the_mas(tab, k);
  ft_free_mas(tab);
  return (result);
}

int count_of_word_in_the_mas(char **tab, int k) {
  int i;

  i = 0;
  if (!tab)
	return (0);
  while (*(tab + i) != NULL)
	i++;
  if (i == k)
	return (1);
  return (0);
}

int check_vector(char **tab, int min, int max) {
  size_t i;

  i = 0;
  if (!tab)
	return (0);
  while (*(tab + i) != NULL) {
	if (ft_atof(tab[i]) < min || ft_atof(tab[i]) > max)
	  return (0);
	i++;
  }
  if (i != 3)
	return (0);
  return (1);
}

void ft_free_mas(char **tab) {
  size_t i;

  i = 0;
  if (!tab)
	return;
  while (*(tab + i)) {
	free(*(tab + i));
	i++;
  }
  free(tab);
}

int free_and_return(char **tab, char **tmp) {
  if (tab)
	ft_free_mas(tab);
  if (tmp)
	ft_free_mas(tmp);
  return (0);
}
