/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:15:30 by ageraud           #+#    #+#             */
/*   Updated: 2020/09/14 16:55:12 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	alloc_player_direction(t_ray *ray, t_parse *parse)
{
	if (parse->letter == 'W')
	{
		ray->dir_x = 0;
		ray->dir_y = -1;
	}
	if (parse->letter == 'S')
	{
		ray->dir_x = 1;
		ray->dir_y = 0;
	}
	if (parse->letter == 'E')
	{
		ray->dir_x = 0;
		ray->dir_y = 1;
	}
	if (parse->letter == 'N')
	{
		ray->dir_x = -1;
		ray->dir_y = 0;
	}
}

void	alloc_player_plane(t_ray *ray, t_parse *parse)
{
	if (parse->letter == 'W')
	{
		ray->plane_x = -0.66;
		ray->plane_y = 0;
	}
	if (parse->letter == 'S')
	{
		ray->plane_x = 0;
		ray->plane_y = -0.66;
	}
	if (parse->letter == 'E')
	{
		ray->plane_x = 0.66;
		ray->plane_y = 0;
	}
	if (parse->letter == 'N')
	{
		ray->plane_x = 0;
		ray->plane_y = 0.66;
	}
}

void	init_ray(t_ray *ray, t_parse *parse)
{
	ray->pos_x = parse->playerposx + 0.5;
	ray->pos_y = parse->playerposy + 0.5;
	alloc_player_direction(ray, parse);
	alloc_player_plane(ray, parse);
	ray->w = parse->resx;
	ray->h = parse->resy;
}
