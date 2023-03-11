/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:06:03 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/09 12:06:04 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_stack(t_elem *stack, int size)
{
  int i;
	t_elem *tmp;

  i = 0;
	while (i < size)
	{
		tmp = stack->prev;
		free(stack);
		stack = tmp;
    i++;
	}
}

void terminate(t_data *data)
{
	int	i;

	i = 0;
	if (data)
	{
		if (data->split_arr)
		{
			while (data->split_arr[i])
			{
				free(data->split_arr[i]);
				i++;
			}
			free(data->split_arr);
		}
		if (data->stack_a)
			free_stack(data->stack_a, data->size_a);
		if (data->stack_b)
			free_stack(data->stack_b, data->size_b);
		free(data);
	}
}
