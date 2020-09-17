/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_screenshot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:41:38 by agathe            #+#    #+#             */
/*   Updated: 2020/09/09 14:14:03 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	put_bmp_color(int fd, t_parse *parse, t_rgb *rgb)
{
	int	x;
	int	y;
	int	pixel;

	y = parse->resy - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < parse->resx)
		{
			pixel = parse->pixel[x + y * parse->resx];
			rgb->red = pixel % 256;
			pixel = pixel / 256;
			rgb->green = pixel % 256;
			pixel = pixel / 256;
			rgb->blue = pixel % 256;
			write(fd, &rgb->red, 1);
			write(fd, &rgb->green, 1);
			write(fd, &rgb->blue, 1);
			x++;
		}
		y--;
	}
}

void	header_bmp(t_a *a)
{
	a->bmph.header_file_type[0] = 'B';
	a->bmph.header_file_type[1] = 'M';
	a->bmph.header_file_size = (a->parse.resx * a->parse.resy * 3) + 54;
	a->bmph.header_reserved1 = 0;
	a->bmph.header_reserved2 = 0;
	a->bmph.header_pixel_data_offset = 0;
	a->bmpi.info_header_size = 40;
	a->bmpi.info_image_width = a->parse.resx;
	a->bmpi.info_image_height = a->parse.resy;
	a->bmpi.info_planes = 1;
	a->bmpi.info_bits_per_pixel = 24;
	a->bmpi.info_compression = 0;
	a->bmpi.info_image_size = (a->parse.resx * a->parse.resy * 3) + 54;
	a->bmpi.info_x_pixels_per_meter = 1;
	a->bmpi.info_y_pixels_per_meter = 1;
	a->bmpi.info_total_colors = 0;
	a->bmpi.info_important_colors = 0;
}

void	save_bmp_screenshot(t_a *a)
{
	int	fd;

	raycast_start(a);
	header_bmp(a);
	if ((fd = open("./screenshot.bmp", O_RDWR | O_CREAT, 0777)) == -1)
	{
		write(1, "/!| BMP SCREENSHOT ERROR /!|\n", 30);
		close(fd);
		close_window(a);
		exit(-1);
	}
	write(fd, &a->bmph, 14);
	write(fd, &a->bmpi, 40);
	put_bmp_color(fd, &a->parse, &a->rgb);
	close(fd);
	close_window(a);
	exit(-1);
}
