/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions_for_parsing.h                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:55:57 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:43:09 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef ADDITIONAL_FUNCTIONS_FOR_PARSING_H
#	define ADDITIONAL_FUNCTIONS_FOR_PARSING_H

int		count_of_word_in_the_line(char *line, int k);
int		count_of_word_in_the_mas(char **tab, int k);
int		check_vector(char **tab, int min, int max);
void	ft_free_mas(char **tab);
int		free_and_return(char **tab, char **tmp);

#	endif
