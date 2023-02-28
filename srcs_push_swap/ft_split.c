/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:09:47 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/26 22:10:38 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	next_sep_pos(char const *str, char c, size_t pos)
{
	while (str[pos] != '\0')
	{
		if (str[pos] == c)
			return (pos);
		pos++;
	}
	return (pos);
}

size_t	ft_skip(char const *str, char c, size_t str_pos)
{
	while (str[str_pos] == c)
		str_pos++;
	return (str_pos);
}

size_t	ft_num_elements(char const *str, char c)
{
	size_t	i;
	int		num_elements;

	i = ft_skip(str, c, 0);
	num_elements = 0;
	while (i < ft_strlen(str))
	{
		i = next_sep_pos(str, c, i);
		if (str[i - 1] != c)
			num_elements++;
		i = ft_skip(str, c, i);
	}
	return (num_elements);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_elements;
	char	**arr;
	size_t	i;
	size_t	str_pos;
	size_t	str_length;

	i = 0;
	str_pos = 0;
	num_elements = ft_num_elements(s, c);
	arr = malloc(sizeof(arr) * (num_elements + 1));
	if (!arr)
		return (NULL);
	while (i < num_elements)
	{
		str_pos = ft_skip(s, c, str_pos);
		str_length = next_sep_pos(s, c, str_pos) - str_pos;
		arr[i] = ft_substr(s, str_pos, str_length);
		str_pos = str_pos + str_length + 1;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
