/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:37:04 by agathe            #+#    #+#             */
/*   Updated: 2020/09/09 14:18:00 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*new_s1;

	i = 0;
	while (s1[i] != '\0')
		i++;
	new_s1 = (malloc(sizeof(char) * i + 1));
	if (new_s1 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		new_s1[i] = s1[i];
		i++;
	}
	new_s1[i] = '\0';
	return (new_s1);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	len_s;
	size_t	i;

	if (s == 0)
		return (NULL);
	len_s = ft_strlen(s);
	if (len > len_s)
		len = len_s;
	if (start > len_s)
		len = 0;
	if (!(new = malloc(sizeof(char) * len + 1)))
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

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*new_s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
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
	{
		new_s[i++] = s2[j++];
	}
	new_s[i] = '\0';
	return (new_s);
}
