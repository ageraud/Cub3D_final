/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:14:13 by agathe            #+#    #+#             */
/*   Updated: 2020/09/17 16:29:54 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		ft_color_parse_nextbis(char *line, int *color, t_parse *p, int i)
{
	p->b = ft_atoi_m(line, &i);
	if ((p->r < 0 || p->r > 255) || (p->g < 0 || p->g > 255)
		|| (p->b < 0 || p->b > 255))
		p->unvalid_nbr = 1;
	if (p->unvalid_nbr == 1)
	{
		write(1, "Error\n/!| UNVALID COLOR NUMBER /!|\n", 36);
		exit(0);
	}
	*color = (p->r * 65536) + (p->g * 256) + p->b;
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

void		ft_color_parse_next(char *line, int *color, t_parse *parse, int i)
{
	parse->r = ft_atoi_m(line, &i);
	if (line[i] == ',')
		i++;
	else
	{
		write(1, "Error\n/!| UNVALID CHAR IN PARSING ELEMENTS /!|\n", 47);
		exit(0);
	}
	if (line[i] == ',')
	{
		write(1, "Error\n/!| UNVALID CHAR IN PARSING ELEMENTS /!|\n", 47);
		exit(0);
	}
	parse->g = ft_atoi_m(line, &i);
	if (line[i] == ',')
		i++;
	else
	{
		write(1, "Error\n/!| UNVALID CHAR IN PARSING ELEMENTS /!|\n", 47);
		exit(0);
	}
	ft_color_parse_nextbis(line, color, parse, i);
}

int			ft_color_parse(char *line, int *color, t_parse *parse)
{
	int		i;

	i = 0;
	parse->unvalid_nbr = 0;
	parse->error_parsing++;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\r')
		i++;
	if ((line[i] == 'C') || (line[i] == 'F'))
		i++;
	while (ft_isdigit(line[i]) == 0)
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v'
		&& line[i] != '\n' && line[i] != '\r')
		{
			write(1, "Error\n/!| UNVALID CHAR IN PARSING ELEMENTS /!|\n", 47);
			exit(0);
		}
		i++;
	}
	ft_color_parse_next(line, color, parse, i);
	return (0);
}
