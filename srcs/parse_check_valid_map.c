/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_valid_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:34:39 by agathe            #+#    #+#             */
/*   Updated: 2020/09/14 16:54:03 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		check_if_char_surronded_by_one(int y, int x, t_parse *parse)
{
	if (parse->map[y][x] == '0' || parse->map[y][x] == '2' ||
	parse->map[y][x] == 'N' || parse->map[y][x] == 'S' ||
	parse->map[y][x] == 'E' || parse->map[y][x] == 'W')
	{
		check_right_one(y, x, parse);
		check_left_one(y, x, parse);
		check_top_one(y, x, parse);
		check_down_one(y, x, parse);
	}
}

void		check_if_valid_caractere(int y, int x, t_parse *parse)
{
	if (parse->map[y][x] != '0' && parse->map[y][x] != '1' &&
		parse->map[y][x] != '2' && parse->map[y][x] != ' ' &&
		parse->map[y][x] != 'W' && parse->map[y][x] != 'S' &&
		parse->map[y][x] != 'E' && parse->map[y][x] != 'N')
	{
		write(1, "Error\n/!| UNVALID MAP, WRONG CARACTERE /!|\n", 44);
		exit(0);
	}
}

int			check_if_valid_player(int y, int x, int player, t_parse *parse)
{
	if (parse->map[y][x] == 'W' || parse->map[y][x] == 'S' ||
		parse->map[y][x] == 'E' || parse->map[y][x] == 'N')
	{
		parse->playerposx = y;
		parse->playerposy = x;
		parse->letter = parse->map[y][x];
		player++;
	}
	return (player);
}

void		check_if_only_one_player(int player)
{
	if (player != 1)
	{
		write(1, "Error\n/!| UNVALID MAP, NOT ONLY ONE PLAYER /!|\n", 47);
		exit(0);
	}
}

void		check_if_valid_map(t_parse *parse)
{
	int		y;
	int		x;
	int		player;

	y = 0;
	x = 0;
	player = 0;
	while (parse->map[y])
	{
		while (parse->map[y][x])
		{
			if (parse->map[y][x] == '2')
				parse->nbr_of_sprite++;
			check_if_valid_caractere(y, x, parse);
			check_if_char_surronded_by_one(y, x, parse);
			player = check_if_valid_player(y, x, player, parse);
			x++;
		}
		x = 0;
		y++;
	}
	check_if_only_one_player(player);
}
