/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:35:00 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:20:51 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parser_scene.h"
#include "check_argument.h"
#include "render.h"
#include "libft.h"
#include "save.h"
#include <unistd.h>
#include "display.h"

int main(int argc, char *argv[]) {
  t_scene *scene;

  if (argc < 2) {
	write(1, "Error\nMissing argument\n", 24);
	return (1);
  }
  scene = parser_scene(check_file(read_file(argv[1])));
  if (argc > 2 && !ft_strncmp(argv[2], "--save", 7)) {
	save(scene);
	del_scene(scene);
  } else
	display_on_screen(scene);
  return (0);
}
