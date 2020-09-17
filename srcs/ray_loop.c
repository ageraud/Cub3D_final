/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:26:11 by agathe            #+#    #+#             */
/*   Updated: 2020/09/14 16:55:19 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	dist_ray_to_wall(t_ray *r)
{
	if (r->side == 0)
		r->perp_wall_dist = (r->map_x - r->pos_x +
							(1 - r->step_x) / 2) / r->ray_dir_x;
	else
		r->perp_wall_dist = (r->map_y - r->pos_y +
							(1 - r->step_y) / 2) / r->ray_dir_y;
	r->line_height = (int)(r->h / r->perp_wall_dist);
	r->draw_start = -(r->line_height) / 2 + r->h / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + r->h / 2;
	if (r->draw_end >= r->h)
		r->draw_end = r->h - 1;
}

void	ray_hits_the_wall(t_ray *r, t_parse *parse)
{
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (parse->map[r->map_x][r->map_y] == '1')
			r->hit = 1;
	}
}

void	calculate_side_dist(t_ray *r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (r->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - r->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (r->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - r->pos_y) * r->delta_dist_y;
	}
}

void	init_data_ray(t_ray *r)
{
	r->camera_x = 2 * r->x / r->w - 1;
	r->ray_dir_x = r->dir_x + r->plane_x * r->camera_x;
	r->ray_dir_y = r->dir_y + r->plane_y * r->camera_x;
	r->map_x = (int)r->pos_x;
	r->map_y = (int)r->pos_y;
	r->delta_dist_x = fabs(1 / r->ray_dir_x);
	r->delta_dist_y = fabs(1 / r->ray_dir_y);
	r->hit = 0;
}
