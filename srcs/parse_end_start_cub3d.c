/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_end_start_cub3d.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:39:50 by agathe            #+#    #+#             */
/*   Updated: 2020/09/14 18:59:42 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			count_map_witdh_and_height(t_parse *parse)
{
	int		i;
	int		width_count;
	int		biggest_width;

	i = 0;
	width_count = 0;
	biggest_width = 0;
	while (parse->joinmap[i] != '\0')
	{
		i++;
		width_count++;
		if (parse->joinmap[i] == '|')
		{
			parse->height_map++;
			if (biggest_width <= width_count)
				biggest_width = width_count;
			width_count = 0;
		}
	}
	parse->width_map = biggest_width - 1;
	return (0);
}

int			convert_map_into_resolution(t_parse *parse)
{
	parse->nbr_pixel_width = parse->resx / parse->width_map;
	parse->nbr_pixel_height = parse->resy / parse->height_map;
	return (0);
}

void		create_new_image(t_parse *parse)
{
	parse->new_img = mlx_new_image(parse->mlx_ptr, parse->resx, parse->resy);
	parse->pixel = (int *)mlx_get_data_addr(parse->new_img,
					&parse->bits_per_pixel, &parse->size_line, &parse->endian);
}

int			start_cub3d(t_a *a, t_parse *parse)
{
	parse->mlx_ptr = mlx_init();
	parse->win_ptr = mlx_new_window(parse->mlx_ptr, parse->resx,
					parse->resy, "Cub3D");
	create_new_image(parse);
	count_map_witdh_and_height(parse);
	convert_map_into_resolution(parse);
	init_ray(&a->ray, parse);
	convert_north_texture(&a->ray, parse);
	convert_south_texture(&a->ray, parse);
	convert_west_texture(&a->ray, parse);
	convert_east_texture(&a->ray, parse);
	convert_sprite_texture(&a->ray, parse);
	a->sp = (t_sp *)malloc((a->parse.nbr_of_sprite) * sizeof(t_sp));
	a->buf = malloc(sizeof(double) * ((int)a->ray.w));
	return (0);
}
