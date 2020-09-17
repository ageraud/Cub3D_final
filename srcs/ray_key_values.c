/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_key_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:42:44 by agathe            #+#    #+#             */
/*   Updated: 2020/09/14 16:55:14 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_key(t_key *k)
{
	k->key_w = 13;
	k->key_a = 0;
	k->key_s = 1;
	k->key_d = 2;
	k->key_right = 124;
	k->key_left = 123;
	k->key_shift_left = 257;
	k->key_space = 49;
	k->key_ctrl_left = 257;
	k->key_escape = 53;
}

void	key_values(t_ray *r, t_key *key)
{
	r->frame_time = 0.02;
	r->move_speed = r->frame_time * 5.0;
	r->rot_speed = r->frame_time * 3.0;
	init_key(key);
}

int		holdinput(int key, t_a *a)
{
	if (key == a->key.key_w)
		a->key.w = 1;
	if (key == a->key.key_a)
		a->key.a = 1;
	if (key == a->key.key_s)
		a->key.s = 1;
	if (key == a->key.key_d)
		a->key.d = 1;
	if (key == a->key.key_right)
		a->key.right = 1;
	if (key == a->key.key_left)
		a->key.left = 1;
	if (key == a->key.key_shift_left)
		a->key.shift_l = 1;
	if (key == a->key.key_space)
		a->key.space = 1;
	if (key == a->key.key_ctrl_left)
		a->key.ctrl_l = 1;
	if (key == a->key.key_escape)
		a->key.escape = 1;
	return (0);
}

int		stopinput(int key, t_a *a)
{
	if (key == a->key.key_w)
		a->key.w = 0;
	if (key == a->key.key_a)
		a->key.a = 0;
	if (key == a->key.key_s)
		a->key.s = 0;
	if (key == a->key.key_d)
		a->key.d = 0;
	if (key == a->key.key_right)
		a->key.right = 0;
	if (key == a->key.key_left)
		a->key.left = 0;
	if (key == a->key.key_shift_left)
		a->key.shift_l = 0;
	if (key == a->key.key_space)
		a->key.space = 0;
	if (key == a->key.key_ctrl_left)
		a->key.ctrl_l = 0;
	if (key == a->key.key_escape)
		a->key.escape = 0;
	return (0);
}
