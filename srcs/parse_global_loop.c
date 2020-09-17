/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_global_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:12:49 by agathe            #+#    #+#             */
/*   Updated: 2020/09/17 21:52:07 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		is_the_start_of_the_map(char *line)
{
	int	i;
	int contains_a_one;

	i = 0;
	contains_a_one = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
		{
			contains_a_one = 1;
			return (contains_a_one);
		}
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\t')
			return (0);
		i++;
	}
	return (contains_a_one);
}

int		ft_global_parse(char *line, t_parse *p)
{
	p->i = 0;
	while (line[p->i] == ' ' || (line[p->i] >= '\t' && line[p->i] <= '\r'))
		p->i++;
	if (line[p->i] == '\0')
		return (0);
	if (line[p->i] == 'R')
		return (ft_parse_resolution(line, p));
	if (line[p->i] == 'N' && line[p->i + 1] == 'O')
		return (ft_parse_texture(line, &p->no, p));
	if (line[p->i] == 'S' && line[p->i + 1] == 'O')
		return (ft_parse_texture(line, &p->so, p));
	if (line[p->i] == 'W' && line[p->i + 1] == 'E')
		return (ft_parse_texture(line, &p->we, p));
	if (line[p->i] == 'E' && line[p->i + 1] == 'A')
		return (ft_parse_texture(line, &p->ea, p));
	if (line[p->i] == 'S')
		return (ft_parse_texture(line, &p->sprite, p));
	if (line[p->i] == 'F')
		return (ft_color_parse(line, &p->floor, p));
	if (line[p->i] == 'C')
		return (ft_color_parse(line, &p->ceiling, p));
	return (-1);
}

void	ft_parsing_loop(int fd, t_parse *parse, char *line)
{
	int	ret;
	int	isvalid;

	ret = 1;
	isvalid = 0;
	while (ret > 0 && isvalid == 0)
	{
		ret = get_next_line(fd, &line);
		if (is_the_start_of_the_map(line) == 1)
		{
			join_line_map(parse, line, fd, ret);
			check_pipe_joinmap(parse);
		}
		isvalid = ft_global_parse(line, parse);
		free(line);
	}
	if (parse->joinmap == NULL)
	{
		write(1, "Error\n/!| IMPOSSIBLE TO ACCESS THE MAP /!|\n", 43);
		write(1, "/!| UNVALID CHAR IN PARSING OR NO MAP /!|\n", 42);
		exit(0);
	}
}
