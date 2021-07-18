/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:52:22 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/14 16:56:19 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr_fd(char *s, int fd) {
  if (s) {
	while (*s)
	  write(fd, s++, 1);
  }
}
