/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:54:49 by agathe            #+#    #+#             */
/*   Updated: 2020/09/16 19:22:50 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		calculate_sprite_next(t_ray *r)
{
	if (r->sp_draw_start_y < 0)
		r->sp_draw_start_y = 0;
	r->sp_draw_end_y = r->sp_height / 2 + r->h / 2;
	if (r->sp_draw_end_y >= r->h)
		r->sp_draw_end_y = r->h - 1;
	r->sp_width = abs((int)(r->h / r->sp_transform_y));
	r->sp_draw_start_x = -r->sp_width / 2 + r->sp_screen_x;
	if (r->sp_draw_start_x < 0)
		r->sp_draw_start_x = 0;
	r->sp_draw_end_x = r->sp_width / 2 + r->sp_screen_x;
	if (r->sp_draw_end_x >= r->w)
		r->sp_draw_end_x = r->w - 1;
}

void		calculate_sprite(t_a *a, t_ray *r, int i)
{
	r->sp_x = a->sp[i].sprite_pos_x - r->pos_x;
	r->sp_y = a->sp[i].sprite_pos_y - r->pos_y;
	r->sp_inv_det = 1.0 / ((r->plane_x * r->dir_y) - (r->dir_x * r->plane_y));
	r->sp_transform_x = r->sp_inv_det * ((r->dir_y * r->sp_x) -
						(r->dir_x * r->sp_y));
	r->sp_transform_y = r->sp_inv_det * ((-r->plane_y * r->sp_x) +
						(r->plane_x * r->sp_y));
	r->sp_screen_x = (int)((r->w / 2) * (1 + r->sp_transform_x /
						r->sp_transform_y));
	r->sp_height = abs((int)(r->h / r->sp_transform_y));
	r->sp_draw_start_y = -r->sp_height / 2 + r->h / 2;
	calculate_sprite_next(r);
}

void		draw_sprite_next(t_a *a, int c, int d, int color)
{
	a->ray.tex_y = ((d - a->ray.h * 0.5f + a->ray.sp_height * 0.5f) *
	a->ray.img[SP].img_height - 1) / a->ray.sp_height;
	color = a->ray.img[SP].data[a->ray.img[SP].img_width *
			a->ray.tex_y + a->ray.tex_x];
	if ((color & 0xffffff) != 0)
		a->parse.pixel[c + d * (int)a->ray.w] = color;
}

void		draw_sprite(t_a *a, t_ray *r)
{
	int		c;
	int		d;
	int		color;

	c = r->sp_draw_start_x;
	color = 0;
	while (c < r->sp_draw_end_x)
	{
		r->tex_x = (int)(256 * (c - (-r->sp_width / 2 + r->sp_screen_x)) *
					r->img[SP].img_width / r->sp_width) / 256;
		if (r->sp_transform_y > 0 && c > 0 && c < r->w &&
			r->sp_transform_y < a->buf[c])
		{
			d = r->sp_draw_start_y + 1;
			while (d < r->sp_draw_end_y)
			{
				draw_sprite_next(a, c, d, color);
				d++;
			}
		}
		c++;
	}
}
