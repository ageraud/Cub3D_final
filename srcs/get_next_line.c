/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:56:48 by ageraud           #+#    #+#             */
/*   Updated: 2020/09/09 14:15:26 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				free_str_temp(char **str_temp, int fd)
{
	free(str_temp[fd]);
	str_temp[fd] = NULL;
	return (-1);
}

int				next_gnl(char **str_temp, char **line, int fd)
{
	char		*temp_bis;
	int			indice_n;

	indice_n = backslash_n(str_temp[fd]);
	temp_bis = ft_substr_m(str_temp[fd], (indice_n + 1),
				ft_strlen_m(str_temp[fd] + indice_n + 1));
	*line = ft_substr_m(str_temp[fd], 0, indice_n);
	free(str_temp[fd]);
	str_temp[fd] = NULL;
	str_temp[fd] = ft_substr_m(temp_bis, 0, ft_strlen_m(temp_bis));
	free(temp_bis);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int			end_of_file;
	char		buf[BUFFER_SIZE + 1];
	static char	*str_temp[10240];

	if (fd < 0)
		return (-1);
	if (str_temp[fd] == NULL)
		str_temp[fd] = ft_strdup_m("");
	while (backslash_n(str_temp[fd]) == -1)
	{
		end_of_file = read(fd, buf, BUFFER_SIZE);
		if (end_of_file == -1)
			return (free_str_temp(str_temp, fd));
		buf[end_of_file] = '\0';
		str_temp[fd] = ft_strjoin_m(str_temp[fd], buf);
		if (end_of_file == 0)
		{
			end_of_file = backslash_n(str_temp[fd]);
			*line = ft_substr_m(str_temp[fd], 0, ft_strlen_m(str_temp[fd]));
			free(str_temp[fd]);
			str_temp[fd] = NULL;
			return (0);
		}
	}
	return (next_gnl(str_temp, line, fd));
}
