/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:56:38 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/09 11:56:39 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (start >= ft_strlen(s))
	{
		ptr = ft_calloc(1, 1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (len + start > ft_strlen(s))
	{
		ptr = ft_calloc(ft_strlen(s) + 1 - start, 1);
		if (!ptr)
			return (NULL);
		ft_strlcpy(ptr, s + start, ft_strlen(s) + 1 - start);
	}
	else
	{
		ptr = ft_calloc(len + 1, 1);
		if (!ptr)
			return (NULL);
		ft_strlcpy(ptr, s + start, len + 1);
	}
	return (ptr);
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmeb > 2147483647 / size)
		return (0);
	if (nmeb != 0 && size > 2147483647 / nmeb)
		return (0);
	ptr = malloc(nmeb * size);
	if (ptr)
	{
		ft_bzero(ptr, nmeb * size);
		return (ptr);
	}
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (i < n)
		{
			((char *)s)[i] = '\0';
			i++;
		}
	}
}
int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	n;

	n = 0;
	i = 0;
	neg = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		n = n * 10;
		n = n + nptr[i] - 48;
		i++;
	}
	return (n * neg);
}
