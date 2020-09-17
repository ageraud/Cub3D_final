/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:26:57 by ageraud           #+#    #+#             */
/*   Updated: 2020/09/09 14:16:26 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	ft_free(char **new_tab)
{
	int		i;

	i = 0;
	while (new_tab[i])
	{
		free(new_tab[i]);
		i++;
	}
	free(new_tab);
	*new_tab = NULL;
}

static int	ft_count_words(const char *s, char c)
{
	int		i;
	int		count_words;

	i = 0;
	count_words = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			count_words++;
		i++;
	}
	if (s[i] == '\0' && s[i - 1] != c)
		count_words++;
	return (count_words);
}

static int	ft_count_letter(const char *s, char c, int *j, int *i)
{
	int		tmp;
	int		count_letter;

	tmp = *i;
	while (s[tmp] && s[tmp] == c)
		tmp++;
	*j = tmp;
	count_letter = 0;
	while (s[tmp] && s[tmp] != c)
	{
		tmp++;
		count_letter++;
	}
	*i = tmp;
	return (count_letter);
}

static void	ft_alloc_line(const char *s, char c,
							int nbr_lines, char **new_tab)
{
	int		i;
	int		i_line;
	int		count_letter;
	int		j;

	i = 0;
	i_line = 0;
	while (i_line < nbr_lines)
	{
		count_letter = ft_count_letter(s, c, &j, &i);
		if (!(new_tab[i_line] = ft_calloc(sizeof(char), (count_letter + 1))))
		{
			ft_free(new_tab);
			return ;
		}
		count_letter = 0;
		while (s[j + count_letter] && s[j + count_letter] != c)
		{
			new_tab[i_line][count_letter] = s[j + count_letter];
			count_letter++;
		}
		new_tab[i_line][count_letter] = '\0';
		i_line++;
	}
	new_tab[i_line] = NULL;
}

char		**ft_split(char const *s, char c)
{
	int		nbr_lines;
	char	**new_tab;

	if (!s || s[0] == '\0')
	{
		if (!(new_tab = ft_calloc(1, sizeof(*new_tab))))
			return (NULL);
		return (new_tab);
	}
	nbr_lines = ft_count_words(s, c);
	if (!(new_tab = ft_calloc(sizeof(char *), (nbr_lines + 1))))
	{
		free(new_tab);
		return (NULL);
	}
	ft_alloc_line(s, c, nbr_lines, new_tab);
	return (new_tab);
}
