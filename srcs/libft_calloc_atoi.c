/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_calloc_atoi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:36:05 by agathe            #+#    #+#             */
/*   Updated: 2020/09/10 16:33:24 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		if (i < n)
			str[i] = 0;
		i++;
	}
}

void		*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void		ft_atoi_m_next(const char *nptr, int *i, long *result, long *sign)
{
	while (nptr[*i] == ' ' || (nptr[*i] >= '\t' && nptr[*i] <= '\r'))
		(*i)++;
	if (nptr[*i] == '\0')
	{
		*result = -1;
		return ;
	}
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		*result = *result * 10 + (nptr[*i] - '0');
		(*i)++;
	}
	if (*result >= 2147483648)
		*result = 2147483647;
}

int			ft_atoi_m(const char *nptr, int *i)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	ft_atoi_m_next(nptr, i, &result, &sign);
	return (sign * result);
}
