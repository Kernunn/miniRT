/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:48:23 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/15 16:44:48 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef BMP_H
#	define BMP_H

#include <stdint.h>
#include "vector.h"

#pragma pack(push, 1)

typedef struct s_bitmapfileheader {
  uint16_t bf_type;
  uint32_t bf_size;
  uint16_t bf_reserved1;
  uint16_t bf_reserved2;
  uint32_t bf_off_bits;
} t_bitmapfileheader;

#pragma pack(pop)

typedef struct s_bitmapinfoheader {
  uint32_t bi_size;
  int32_t bi_width;
  int32_t bi_height;
  uint16_t bi_planes;
  uint16_t bi_bit_count;
  uint32_t bi_compression;
  uint32_t bi_size_image;
  int32_t bi_x_pels_per_meter;
  int32_t bi_y_pels_per_meter;
  uint32_t bi_clr_used;
  uint32_t bi_clr_important;
} t_bitmapinfoheader;

void init(t_bitmapfileheader *bfh, t_bitmapinfoheader *bih,
		  int32_t width, int32_t height);
void write_to_bmp(t_vec3f *framebuffer, int32_t width,
				  int32_t height);

#	endif
