/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_close_window_free_tab.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:14:06 by agathe            #+#    #+#             */
/*   Updated: 2020/09/14 16:55:45 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_tab_map(char **map)
{
	int i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		map = NULL;
	}
}

void	free_all(t_a *a)
{
	free(a->parse.no);
	free(a->parse.so);
	free(a->parse.sprite);
	free(a->parse.we);
	free(a->parse.ea);
	free(a->parse.joinmap);
}

int		close_window(t_a *a)
{
	mlx_clear_window(a->parse.mlx_ptr, a->parse.win_ptr);
	mlx_destroy_window(a->parse.mlx_ptr, a->parse.win_ptr);
	free_tab_map(a->parse.map);
	free(a->buf);
	free(a->sp);
	free_all(a);
	exit(0);
}
