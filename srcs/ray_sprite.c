/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:49:26 by agathe            #+#    #+#             */
/*   Updated: 2020/09/14 16:55:34 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		sprite_pos_and_dist_next(t_a *a, int x, int y, int i)
{
	a->sp[i].sprite_pos_x = x + 0.5;
	a->sp[i].sprite_pos_y = y + 0.5;
	a->sp[i].sprite_dist = ((a->ray.pos_x - a->sp[i].sprite_pos_x)
	* (a->ray.pos_x - a->sp[i].sprite_pos_x) +
	(a->ray.pos_y - a->sp[i].sprite_pos_y) *
	(a->ray.pos_y - a->sp[i].sprite_pos_y));
}

void		find_sprite_pos_and_dist(t_a *a, t_parse *parse)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	i = 0;
	while (parse->map[x])
	{
		y = 0;
		while (parse->map[x][y])
		{
			if (parse->map[x][y] == '2')
			{
				sprite_pos_and_dist_next(a, x, y, i);
				i++;
			}
			y++;
		}
		x++;
	}
}

void		sort_dist_sprite(t_a *a, t_parse *parse)
{
	int		i;
	int		j;
	t_sp	sp_tmp;

	i = 0;
	while (i < parse->nbr_of_sprite - 1)
	{
		j = i + 1;
		while (j < parse->nbr_of_sprite)
		{
			if (a->sp[i].sprite_dist < a->sp[j].sprite_dist)
			{
				sp_tmp = a->sp[i];
				a->sp[i] = a->sp[j];
				a->sp[j] = sp_tmp;
			}
			j++;
		}
		i++;
	}
}

void		raycasting_sprite(t_a *a, t_ray *r, t_parse *parse)
{
	int		y;

	y = 0;
	find_sprite_pos_and_dist(a, parse);
	sort_dist_sprite(a, parse);
	while (y < parse->nbr_of_sprite)
	{
		calculate_sprite(a, r, y);
		draw_sprite(a, r);
		y++;
	}
}
