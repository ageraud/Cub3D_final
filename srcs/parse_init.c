/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:04:09 by agathe            #+#    #+#             */
/*   Updated: 2020/09/17 16:50:14 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_parse_next(t_parse *parse, t_a *a)
{
	parse->playerposy = 0;
	parse->playerposx = 0;
	parse->width_map = 0;
	parse->height_map = 0;
	parse->nbr_pixel_width = 0;
	parse->nbr_pixel_height = 0;
	parse->square_color = 0;
	parse->square_pos_x = 0;
	parse->square_pos_y = 0;
	parse->letter = 'X';
	parse->nbr_of_sprite = 0;
	a->key.w = 0;
	a->key.a = 0;
	a->key.s = 0;
	a->key.d = 0;
	a->key.right = 0;
	a->key.left = 0;
	a->key.shift_l = 0;
	a->key.space = 0;
	a->key.ctrl_l = 0;
	a->key.escape = 0;
	parse->error_parsing = 0;
}

void	init_parse(t_parse *parse, t_a *a)
{
	parse->resx = -1;
	parse->resy = -1;
	parse->floor = -1;
	parse->ceiling = -1;
	parse->no = NULL;
	parse->so = NULL;
	parse->sprite = NULL;
	parse->we = NULL;
	parse->ea = NULL;
	parse->map = NULL;
	parse->joinmap = NULL;
	parse->r = 0;
	parse->g = 0;
	parse->b = 0;
	parse->unvalid_nbr = 0;
	parse->i = 0;
	parse->xtmp = 0;
	parse->max_width = 0;
	parse->max_height = 0;
	parse->first_line = 0;
	parse->second_line = 0;
	init_parse_next(parse, a);
}
