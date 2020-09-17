/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:24:43 by agathe            #+#    #+#             */
/*   Updated: 2020/09/17 17:18:09 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_parse_tex_next(char *line, char **textures, int *i)
{
	int	temp;

	temp = 0;
	temp = *i;
	while (line[temp] != ' ' && line[temp] != '\n' && line[temp] != '\0'
	&& line[temp] != '\t' && line[temp] != '\r' && line[temp] != '\v')
		temp++;
	*textures = ft_substr(line, *i, temp - *i);
}

int		ft_parse_texture(char *line, char **textures, t_parse *parse)
{
	int	i;

	i = 0;
	parse->error_parsing++;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\n' || line[i] == '\r')
		i++;
	if ((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S'
		&& line[i + 1] == 'O') || (line[i] == 'W'
		&& line[i + 1] == 'E') || (line[i] == 'E' && line[i + 1] == 'A'))
	{
		i++;
		i++;
	}
	if (line[i] == 'S')
		i++;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\n' || line[i] == '\r')
		i++;
	ft_parse_tex_next(line, textures, &i);
	return (0);
}
