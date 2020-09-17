/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:58:29 by ageraud           #+#    #+#             */
/*   Updated: 2020/09/09 14:15:46 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			backslash_n(char *buf)
{
	int		i;

	i = 0;
	while (buf && buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_strdup_m(const char *s1)
{
	int		i;
	char	*new_s1;

	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
		i++;
	new_s1 = (malloc(sizeof(char) * i + 1));
	if (new_s1 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		new_s1[i] = s1[i];
		i++;
	}
	new_s1[i] = '\0';
	return (new_s1);
}

size_t		ft_strlen_m(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin_m(char *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*new_s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen_m(s1);
	len_s2 = ft_strlen_m(s2);
	if (!(new_s = malloc(sizeof(char) * len_s1 + len_s2 + 1)))
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		new_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
		new_s[i++] = s2[j++];
	new_s[i] = '\0';
	free(s1);
	return (new_s);
}

char		*ft_substr_m(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	len_s;
	size_t	i;

	if (s == 0)
		return (NULL);
	len_s = ft_strlen_m(s);
	if (len > len_s)
		len = len_s;
	if (start >= len_s)
		len = 0;
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len > i)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}
