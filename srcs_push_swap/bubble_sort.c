/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:31:38 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/13 09:31:41 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data *bubble_sort(t_data *data)
{
	int i;
	int j;
	int size;
	int iterations;

	size = data->size_a - 1;
	iterations = 0;
	while (size > 0)
	{
	i = 0;
	j = 0;
		while (i < size)
		{
			if (data->stack_a->num > data->stack_a->next->num)
				data = swap(data, 'a');
			data = rotate(data, 'a');
			i++;
		}
		size --;
		iterations++;
		while (j < iterations)
		{ 
			data = rotate(data, 'a');
			j++;
		}
	}
	return (data);
}
