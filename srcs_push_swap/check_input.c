/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:16:59 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/28 12:27:28 by lwidmer          ###   ########.fr       */
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

int check_if_no_doubles(char **split_arr)
{
	int i;
	int j;

	i = 0;
	while (split_arr[i])
	{
		j = i + 1;
		while (split_arr[j])
		{
			if (ft_atoi(split_arr[i]) == ft_atoi(split_arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
	
}

int check_if_input_numeric(char **split_arr)
{
	int i;
	int j;

	i = 0;
	while (split_arr[i])
	{
		j = 0;
		while (split_arr[i][j] != '\0')
		{
			if (ft_isdigit(split_arr[i][j]) != 0)
				j++;
			else
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}
int check_input(char **split_arr)
{
	if (check_if_input_numeric(split_arr) == 0)
	{
		ft_printf("Error");
		return (0);
	}
	if (check_if_no_doubles(split_arr) == 0)
	{
		ft_printf("Error");
		return (0);
	}
	return (1);
}
