/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:30:39 by agathe            #+#    #+#             */
/*   Updated: 2020/09/14 16:54:01 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		check_right_one(int ytmp, int xtmp, t_parse *parse)
{
	while (parse->map[ytmp][xtmp] != 1)
	{
		if (parse->map[ytmp][xtmp] == '1')
			break ;
		if (parse->map[ytmp][xtmp] == '\0' || parse->map[ytmp][xtmp] == ' ')
		{
			write(1, "Error\n/!| UNVALID MAP, 0,2,N,S,E or W /!|\n", 42);
			write(1, "/!| NOT SURROUNDED ON THE RIGHT /!|\n", 36);
			exit(0);
		}
		xtmp++;
	}
}

void		check_left_one(int ytmp, int xtmp, t_parse *parse)
{
	while (parse->map[ytmp][xtmp] != 1)
	{
		if (parse->map[ytmp][xtmp] == '1')
			break ;
		if (parse->map[ytmp][xtmp] == 0 || parse->map[ytmp][xtmp] == ' ')
		{
			write(1, "Error\n/!| UNVALID MAP, 0,2,N,S,E or W /!|\n", 42);
			write(1, "/!| NOT SURROUNDED ON THE LEFT /!|\n", 35);
			exit(0);
		}
		xtmp--;
	}
}

void		check_top_one(int ytmp, int xtmp, t_parse *parse)
{
	while (parse->map[ytmp][xtmp] != 1)
	{
		if (parse->map[ytmp][xtmp] == '1')
			break ;
		if (parse->map[ytmp][xtmp] == 0 || parse->map[ytmp][xtmp] == ' ')
		{
			write(1, "Error\n/!| UNVALID MAP, 0,2,N,S,E or W /!|\n", 42);
			write(1, "/!| NOT SURROUNDED ON THE TOP /!|\n", 34);
			exit(0);
		}
		ytmp--;
	}
}

void		check_down_one(int ytmp, int xtmp, t_parse *parse)
{
	while (parse->map[ytmp][xtmp] != 1)
	{
		if (parse->map[ytmp][xtmp] == '1')
			break ;
		if (parse->map[ytmp][xtmp] == 0 || parse->map[ytmp][xtmp] == ' ')
		{
			write(1, "Error\n/!| UNVALID MAP, 0,2,N,S,E or W /!|\n", 42);
			write(1, "/!| NOT SURROUNDED ON THE UNDER /!|\n", 36);
			exit(0);
		}
		ytmp++;
	}
}
