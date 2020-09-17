/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_alloc_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:31:29 by agathe            #+#    #+#             */
/*   Updated: 2020/09/14 18:54:21 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		alloc_map(int nbr_of_line_map, t_parse *parse)
{
	parse->map = ft_calloc(sizeof(char *), (nbr_of_line_map + 1));
	parse->map[nbr_of_line_map] = 0;
	free(parse->map);
	parse->map = ft_split(parse->joinmap, '|');
}

int			count_line_map(t_parse *parse)
{
	int		nbr_line;
	int		i;

	nbr_line = 0;
	i = 0;
	while (parse->joinmap[i] != '\0')
	{
		i++;
		if (parse->joinmap[i] == '|')
			nbr_line++;
	}
	return (nbr_line);
}
