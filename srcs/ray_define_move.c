/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_define_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:09:37 by agathe            #+#    #+#             */
/*   Updated: 2020/09/14 16:55:02 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	vertical_move(t_a *a)
{
	if (a->key.w == 1)
	{
		if (a->parse.map[(int)(a->ray.pos_x + a->ray.dir_x * a->ray.move_speed)]
			[(int)a->ray.pos_y] != '1')
			a->ray.pos_x += a->ray.dir_x * (a->ray.move_speed);
		if (a->parse.map[(int)(a->ray.pos_x)][(int)(a->ray.pos_y +
			a->ray.dir_y * a->ray.move_speed)] != '1')
			a->ray.pos_y += a->ray.dir_y * (a->ray.move_speed);
	}
	if (a->key.s == 1)
	{
		if (a->parse.map[(int)(a->ray.pos_x - a->ray.dir_x * a->ray.move_speed)]
			[(int)a->ray.pos_y] != '1')
			a->ray.pos_x -= a->ray.dir_x * (a->ray.move_speed);
		if (a->parse.map[(int)(a->ray.pos_x)][(int)(a->ray.pos_y -
			a->ray.dir_y * a->ray.move_speed)] != '1')
			a->ray.pos_y -= a->ray.dir_y * (a->ray.move_speed);
	}
}

void	angle_move_right(t_a *a)
{
	a->ray.old_dir_x = a->ray.dir_x;
	a->ray.dir_x = a->ray.dir_x * cos(-a->ray.rot_speed) -
					a->ray.dir_y * sin(-a->ray.rot_speed);
	a->ray.dir_y = a->ray.old_dir_x * sin(-a->ray.rot_speed) +
					a->ray.dir_y * cos(-a->ray.rot_speed);
	a->ray.old_plane_x = a->ray.plane_x;
	a->ray.plane_x = a->ray.plane_x * cos(-a->ray.rot_speed) -
					a->ray.plane_y * sin(-a->ray.rot_speed);
	a->ray.plane_y = a->ray.old_plane_x * sin(-a->ray.rot_speed) +
					a->ray.plane_y * cos(-a->ray.rot_speed);
}

void	angle_move_left(t_a *a)
{
	a->ray.old_dir_x = a->ray.dir_x;
	a->ray.dir_x = a->ray.dir_x * cos(a->ray.rot_speed) -
					a->ray.dir_y * sin(a->ray.rot_speed);
	a->ray.dir_y = a->ray.old_dir_x * sin(a->ray.rot_speed) +
					a->ray.dir_y * cos(a->ray.rot_speed);
	a->ray.old_plane_x = a->ray.plane_x;
	a->ray.plane_x = a->ray.plane_x * cos(a->ray.rot_speed) -
					a->ray.plane_y * sin(a->ray.rot_speed);
	a->ray.plane_y = a->ray.old_plane_x * sin(a->ray.rot_speed) +
					a->ray.plane_y * cos(a->ray.rot_speed);
}

void	angle_move(t_a *a)
{
	if (a->key.right == 1)
	{
		angle_move_right(a);
	}
	if (a->key.left == 1)
	{
		angle_move_left(a);
	}
}

void	horizontal_move(t_a *a)
{
	if (a->key.d == 1)
	{
		if (a->parse.map[(int)(a->ray.pos_x + a->ray.plane_x *
			a->ray.move_speed)][(int)a->ray.pos_y] != '1')
			a->ray.pos_x += a->ray.plane_x * (a->ray.move_speed);
		if (a->parse.map[(int)(a->ray.pos_x)][(int)(a->ray.pos_y +
			a->ray.plane_y * a->ray.move_speed)] != '1')
			a->ray.pos_y += a->ray.plane_y * (a->ray.move_speed);
	}
	if (a->key.a == 1)
	{
		if (a->parse.map[(int)(a->ray.pos_x - a->ray.plane_x *
			a->ray.move_speed)][(int)a->ray.pos_y] != '1')
			a->ray.pos_x -= a->ray.plane_x * (a->ray.move_speed);
		if (a->parse.map[(int)(a->ray.pos_x)][(int)(a->ray.pos_y -
			a->ray.plane_y * a->ray.move_speed)] != '1')
			a->ray.pos_y -= a->ray.plane_y * (a->ray.move_speed);
	}
}
