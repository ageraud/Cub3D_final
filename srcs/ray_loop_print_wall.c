/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop_print_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:35:09 by agathe            #+#    #+#             */
/*   Updated: 2020/09/15 15:09:36 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_vertical_line(t_parse *parse, t_ray *r)
{
	int	i;

	i = -1;
	while (++i < parse->resy)
	{
		if (i < r->draw_start)
			parse->pixel[r->x + i * parse->resx] = parse->ceiling;
		if (i >= r->draw_start && i <= r->draw_end)
		{
			r->tex_y = ((i - r->h * 0.5f + r->line_height * 0.5f) *
						r->img[r->texture_nb].img_height - 1) / r->line_height;
			r->color = r->img[r->texture_nb].data[r->tex_y *
						r->img[r->texture_nb].img_width + r->tex_x];
			parse->pixel[r->x + i * parse->resx] = r->color;
			if ((r->color & 0xffffff) == 0)
				parse->pixel[r->x + i * parse->resx] = 0;
		}
		if (i > r->draw_end)
			parse->pixel[r->x + i * parse->resx] = parse->floor;
	}
}

void	print_wall_color_next(t_parse *parse, t_ray *r)
{
	if (r->side == 0)
		r->wall_x = r->pos_y + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wall_x = r->pos_x + r->perp_wall_dist * r->ray_dir_x;
	r->wall_x -= floor((r->wall_x));
	r->tex_x = (int)(r->wall_x * (double)(r->img[r->texture_nb].img_width));
	if (r->side == 0 && r->ray_dir_x > 0)
		r->tex_x = r->img[r->texture_nb].img_width - r->tex_x - 1;
	if (r->side == 1 && r->ray_dir_y < 0)
		r->tex_x = r->img[r->texture_nb].img_width - r->tex_x - 1;
	draw_vertical_line(parse, r);
}

void	print_wall_color(t_parse *parse, t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x < 0)
			r->texture_nb = NO;
		else
			r->texture_nb = SO;
	}
	else if (r->side == 1)
	{
		if (r->ray_dir_y < 0)
			r->texture_nb = WE;
		else
			r->texture_nb = EA;
	}
	print_wall_color_next(parse, r);
}
