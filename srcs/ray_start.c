/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:05:29 by agathe            #+#    #+#             */
/*   Updated: 2020/09/16 17:29:05 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	define_move_around(t_a *a)
{
	if (a->key.w == 1 || a->key.s == 1)
		vertical_move(a);
	if (a->key.d == 1 || a->key.a == 1)
		horizontal_move(a);
	if (a->key.right == 1 || a->key.left == 1)
		angle_move(a);
	if (a->key.escape == 1)
		close_window(a);
}

void	raycasting(t_a *a, t_ray *r, t_parse *parse, t_key *key)
{
	r->x = 0;
	while (r->x < r->w)
	{
		init_data_ray(r);
		calculate_side_dist(r);
		ray_hits_the_wall(r, parse);
		dist_ray_to_wall(r);
		print_wall_color(parse, r);
		key_values(r, key);
		a->buf[r->x] = r->perp_wall_dist;
		r->x = r->x + 1;
	}
	if (parse->nbr_of_sprite > 0)
	{
		raycasting_sprite(a, r, parse);
	}
}

int		raycast_start(t_a *a)
{
	define_move_around(a);
	raycasting(a, &a->ray, &a->parse, &a->key);
	mlx_put_image_to_window(a->parse.mlx_ptr, a->parse.win_ptr,
							a->parse.new_img, 0, 0);
	return (1);
}
