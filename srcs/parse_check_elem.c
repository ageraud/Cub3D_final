/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:27:01 by agathe            #+#    #+#             */
/*   Updated: 2020/09/17 16:50:09 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_parsing_elements_error(t_parse *parse)
{
	if (parse->error_parsing != 8)
	{
		write(1, "Error\n/!| UNVALID CHAR IN PARSING ELEMENTS /!|\n", 47);
		exit(0);
	}
}

void	check_first_and_last_line_next(t_parse *parse, int i)
{
	while (parse->joinmap[i] != '|')
	{
		if (parse->joinmap[i] != '1' && parse->joinmap[i] != ' ')
		{
			write(1, "Error\n", 6);
			write(1, "/!| UNVALID MAP, LAST LINE NUMBER IS WRONG /!|\n", 47);
			exit(0);
		}
		i--;
	}
}

void	check_first_and_last_line(t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->joinmap[i] != '|')
	{
		if (parse->joinmap[i] != '1' && parse->joinmap[i] != ' ')
		{
			write(1, "Error\n/!| UNVALID MAP, FIRST LINE IS WRONG /!|\n", 48);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (parse->joinmap[i] != '\0')
		i++;
	i--;
	i--;
	if (parse->joinmap[i] == '|')
		i--;
	check_first_and_last_line_next(parse, i);
}

void	verify_if_global_parse_okay(t_parse *parse)
{
	if (parse->resx == -1 || parse->resy == -1 || parse->floor == -1
		|| parse->ceiling == -1 || parse->no == NULL
		|| parse->so == NULL || parse->sprite == NULL
		|| parse->we == NULL || parse->ea == NULL)
	{
		write(1, "Error\n/!| GLOBAL PARSE ERROR /!|\n", 34);
		exit(0);
	}
}
