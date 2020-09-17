/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_convert_texture_to_img.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:40:27 by agathe            #+#    #+#             */
/*   Updated: 2020/09/14 16:55:48 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	convert_north_texture(t_ray *ray, t_parse *parse)
{
	ray->img[NO].image_ptr = mlx_xpm_file_to_image(parse->mlx_ptr, parse->no,
	&ray->img[NO].img_width, &ray->img[NO].img_height);
	if (!ray->img[NO].image_ptr)
	{
		write(1, "/!| NORTH CONVERT TEXTURE ERROR /!| \n", 37);
		exit(0);
	}
	ray->img[NO].data = (int *)mlx_get_data_addr(ray->img[NO].image_ptr,
	&ray->img[NO].bits_per_pixel, &ray->img[NO].size_line,
	&ray->img[NO].endian);
}

void	convert_south_texture(t_ray *ray, t_parse *parse)
{
	ray->img[SO].image_ptr = mlx_xpm_file_to_image(parse->mlx_ptr, parse->so,
	&ray->img[SO].img_width, &ray->img[SO].img_height);
	if (!ray->img[SO].image_ptr)
	{
		write(1, "/!| SOUTH CONVERT TEXTURE ERROR /!| \n", 37);
		exit(0);
	}
	ray->img[SO].data = (int *)mlx_get_data_addr(ray->img[SO].image_ptr,
	&ray->img[SO].bits_per_pixel, &ray->img[SO].size_line,
	&ray->img[SO].endian);
}

void	convert_west_texture(t_ray *ray, t_parse *parse)
{
	ray->img[WE].image_ptr = mlx_xpm_file_to_image(parse->mlx_ptr, parse->we,
	&ray->img[WE].img_width, &ray->img[WE].img_height);
	if (!ray->img[WE].image_ptr)
	{
		write(1, "/!| WEST CONVERT TEXTURE ERROR /!| \n", 36);
		exit(0);
	}
	ray->img[WE].data = (int *)mlx_get_data_addr(ray->img[WE].image_ptr,
	&ray->img[WE].bits_per_pixel, &ray->img[WE].size_line,
	&ray->img[WE].endian);
}

void	convert_east_texture(t_ray *ray, t_parse *parse)
{
	ray->img[EA].image_ptr = mlx_xpm_file_to_image(parse->mlx_ptr, parse->ea,
	&ray->img[EA].img_width, &ray->img[EA].img_height);
	if (!ray->img[EA].image_ptr)
	{
		write(1, "/!| EAST CONVERT TEXTURE ERROR /!| \n", 36);
		exit(0);
	}
	ray->img[EA].data = (int *)mlx_get_data_addr(ray->img[EA].image_ptr,
	&ray->img[EA].bits_per_pixel, &ray->img[EA].size_line,
	&ray->img[EA].endian);
}

void	convert_sprite_texture(t_ray *ray, t_parse *parse)
{
	ray->img[SP].image_ptr = mlx_xpm_file_to_image(parse->mlx_ptr,
	parse->sprite, &ray->img[SP].img_width, &ray->img[SP].img_height);
	if (!ray->img[SP].image_ptr)
	{
		write(1, "/!| SPRITE CONVERT TEXTURE ERROR /!| \n", 38);
		exit(0);
	}
	ray->img[SP].data = (int *)mlx_get_data_addr(ray->img[SP].image_ptr,
	&ray->img[SP].bits_per_pixel, &ray->img[SP].size_line,
	&ray->img[SP].endian);
}
