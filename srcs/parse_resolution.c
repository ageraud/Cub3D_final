/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:19:28 by agathe            #+#    #+#             */
/*   Updated: 2020/09/17 17:50:49 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	resize_screen(t_parse *parse)
{
	if (parse->resx > 1440)
		parse->resx = 1440;
	if (parse->resy > 900)
		parse->resy = 900;
	if (parse->resx < 100)
		parse->resx = 100;
	if (parse->resy < 100)
		parse->resy = 100;
}

void	ft_parse_resolution_next(char *line, t_parse *parse, int i)
{
	if (parse->resx < 0 || parse->resy < 0)
	{
		write(1, "Error\n/!| RESOLUTION ERROR /!|\n", 32);
		exit(0);
	}
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v'
			&& line[i] != '\n' && line[i] != '\r')
		{
			write(1, "Error\n/!| UNVALID CHAR IN PARSING ELEMENTS /!|\n", 47);
			exit(0);
		}
		i++;
	}
}

int		ft_parse_resolution(char *line, t_parse *parse)
{
	int	i;

	parse->error_parsing++;
	i = 0;
	while (line[i] != 'R' && line[i] != '\0')
	{
		i++;
		if (line[i + 1] == '\0')
			return (-1);
	}
	i++;
	parse->resx = ft_atoi_m(line, &i);
	parse->resy = ft_atoi_m(line, &i);
	if ((parse->resy < 2147483647) && ((parse->resy % 10 == 1)
		|| (parse->resy % 10 == 3) || (parse->resy % 10 == 5)
		|| (parse->resy % 10 == 7) || (parse->resy % 10 == 9)))
		parse->resy++;
	ft_parse_resolution_next(line, parse, i);
	resize_screen(parse);
	return (0);
}
