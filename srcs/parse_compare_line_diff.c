/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_compare_line_diff.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 02:12:23 by agathe            #+#    #+#             */
/*   Updated: 2020/09/17 02:16:49 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		compare_lines_diff_nextbis(t_parse *parse, int *x, int *y, int diff)
{
	if (parse->second_line > parse->first_line)
	{
		diff = parse->second_line - parse->first_line;
		*x = *x - diff;
		while (parse->map[*y][*x])
		{
			if (parse->map[*y][*x] != ' ' && parse->map[*y][*x] != '1')
			{
				write(1, "Error\n/!| UNVALID MAP /!|\n", 26);
				exit(0);
			}
			(*x)++;
		}
		parse->first_line = parse->second_line;
		parse->second_line = 0;
	}
	else
	{
		parse->first_line = parse->second_line;
		parse->second_line = 0;
	}
}

void		compare_lines_diff_next(t_parse *parse, int x, int y, int diff)
{
	while (parse->map[y])
	{
		while (parse->map[y][x])
			x++;
		if (parse->first_line == -1)
			parse->first_line = x;
		else
			parse->second_line = x;
		if (parse->second_line > -1)
			compare_lines_diff_nextbis(parse, &x, &y, diff);
		x = 0;
		y++;
	}
}

void		compare_lines_difference_in_map(t_parse *parse)
{
	int		x;
	int		y;
	int		diff;

	x = 0;
	y = 0;
	parse->first_line = -1;
	parse->second_line = -1;
	diff = 0;
	compare_lines_diff_next(parse, x, y, diff);
}
