/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:11:01 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/26 22:11:25 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
