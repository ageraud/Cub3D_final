/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_join_line_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:19:55 by agathe            #+#    #+#             */
/*   Updated: 2020/09/17 02:20:30 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		check_pipe_joinmap(t_parse *parse)
{
	int		i;

	i = 0;
	while (parse->joinmap[i] != '\0')
	{
		if (parse->joinmap[i] == '|' && parse->joinmap[i + 1] == '|'
		&& parse->joinmap[i + 2] == '\0')
			return ;
		if (parse->joinmap[i] == '|' && parse->joinmap[i + 1] == '|')
		{
			write(1, "Error\n/!| UNVALID MAP, BACKSLASH N /!|\n", 40);
			exit(0);
		}
		i++;
	}
}

void		join_map(t_parse *parse, char *line)
{
	char	*temp;

	temp = ft_strdup(parse->joinmap);
	free(parse->joinmap);
	parse->joinmap = ft_strjoin(temp, line);
	free(temp);
	temp = ft_strdup(parse->joinmap);
	free(parse->joinmap);
	parse->joinmap = ft_strjoin(temp, "|");
	free(temp);
}

int			read_map_and_join(t_parse *parse, char *line, int fd)
{
	int		ret;

	ret = get_next_line(fd, &line);
	join_map(parse, line);
	free(line);
	return (ret);
}

void		join_line_map(t_parse *parse, char *line, int fd, int ret)
{
	parse->joinmap = ft_strjoin(line, "|");
	while (ret > 0)
		ret = read_map_and_join(parse, line, fd);
}
