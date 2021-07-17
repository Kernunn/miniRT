/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:02:52 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 17:04:22 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "bmp.h"
#include "math_function.h"

void		init(t_bitmapfileheader *bfh, t_bitmapinfoheader *bih,
		int32_t width, int32_t height)
{
	bih->bi_size = sizeof(t_bitmapinfoheader);
	bih->bi_width = width;
	bih->bi_height = height;
	bih->bi_size_image = width * height * 3;
	bih->bi_planes = 1;
	bih->bi_bit_count = 24;
	bih->bi_compression = 0;
	bih->bi_x_pels_per_meter = 3780;
	bih->bi_y_pels_per_meter = 3780;
	bih->bi_clr_used = 0;
	bih->bi_clr_important = 0;
	bfh->bf_type = 0x4D42;
	bfh->bf_reserved1 = 0;
	bfh->bf_reserved2 = 0;
	bfh->bf_off_bits = sizeof(t_bitmapfileheader) + bih->bi_size;
	bfh->bf_size = sizeof(t_bitmapfileheader) + sizeof(t_bitmapinfoheader) +
		bih->bi_width * bih->bi_height * 4;
}

static void	claim_color(uint8_t *tmp, t_vec3f *buf,
		int32_t x, int32_t y)
{
	int k;
	int j;
	int	i;
	int n;

	k = 0;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			tmp[k++] = (uint8_t)(max(0, min(255, buf[(y - j - 1) * x + i].z)));
			tmp[k++] = (uint8_t)(max(0, min(255, buf[(y - j - 1) * x + i].y)));
			tmp[k++] = (uint8_t)(max(0, min(255, buf[(y - j - 1) * x + i].x)));
			n = 0;
			while (n < x % 4)
			{
				tmp[k++] = 0;
				n++;
			}
			++i;
		}
		j++;
	}
}

void		write_to_bmp(t_vec3f *framebuffer, int32_t width, int32_t height)
{
	t_bitmapfileheader	bfh;
	t_bitmapinfoheader	bih;
	int					fd;
	uint8_t				*tmp;

	init(&bfh, &bih, width, height);
	fd = open("./out.bmp", O_CREAT | O_WRONLY, S_IREAD | S_IWRITE);
	if (fd == -1)
	{
		perror("Error\n");
		free(framebuffer);
		exit(1);
	}
	write(fd, &bfh, sizeof(bfh));
	write(fd, &bih, sizeof(bih));
	tmp = (uint8_t*)malloc(sizeof(uint8_t) *
			width * height * 3 + width * width % 4);
	claim_color(tmp, framebuffer, width, height);
	write(fd, tmp, sizeof(uint8_t) * width * height * 3);
	free(tmp);
	close(fd);
}
