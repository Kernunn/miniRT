/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:03:00 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:09:25 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft.h"
#include "check_argument.h"
#include "additional_functions_for_parsing.h"

static int check_filename(char *name_of_file) {
  if (ft_strncmp(name_of_file + ft_strlen(name_of_file) - 3, ".rt", 3))
	return (0);
  return (1);
}

t_list *read_file(char *name_of_file) {
  t_list *lines;
  char *line;
  int fd;
  int k;

  lines = NULL;
  if (!check_filename(name_of_file) ||
	  (fd = open(name_of_file, O_RDONLY)) == -1) {
	perror("Error\n");
	exit(1);
  }
  while ((k = get_next_line(fd, &line)) > 0)
	ft_lstadd_back(&lines, ft_lstnew(line));
  if (close(fd) == -1 || k == -1) {
	perror("Error\n");
	ft_lstclear(&lines, free);
	exit(1);
  }
  ft_lstadd_back(&lines, ft_lstnew(line));
  return (lines);
}

t_list *check_file(t_list *lines) {
  t_list *tab;
  t_list *tmp;

  tab = NULL;
  tmp = lines;
  while (tmp) {
	if (((char *) tmp->content)[0] != '\0') {
	  if (check_line(tmp->content))
		ft_lstadd_back(&tab, ft_lstnew(ft_strdup(tmp->content)));
	  else {
		perror("Error\n");
		ft_lstclear(&tab, free);
		ft_lstclear(&lines, free);
		exit(1);
	  }
	}
	tmp = tmp->next;
  }
  ft_lstclear(&lines, free);
  return (tab);
}

int check_line(char *line) {
  if (line[0] == 'R')
	return (check_r(line));
  else if (line[0] == 's' && line[1] == 'p')
	return (check_sp(line));
  else if (line[0] == 'p' && line[1] == 'l')
	return (check_pl(line));
  else if (line[0] == 's' && line[1] == 'q')
	return (check_sq(line));
  else if (line[0] == 'c' && line[1] == 'y')
	return (check_cy(line));
  else if (line[0] == 't' && line[1] == 'r')
	return (check_tr(line));
  else if (line[0] == 'A')
	return (check_a(line));
  else if (line[0] == 'c')
	return (check_c(line));
  else if (line[0] == 'l')
	return (check_l(line));
  return (0);
}
