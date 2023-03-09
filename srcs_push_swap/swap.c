/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:45 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/09 11:13:37 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem *swap_stack_size_two(t_elem *first)
{
	t_elem *second;

	second = first->next;
	first->next = second;
	second->prev = first;
	second->next = first;
	first->prev = second;
	return (second);
	
}

static t_elem *swap_stack_size_bigger_two(t_elem *first)
{
	t_elem *tmp;
	t_elem *second;

	second = first->next;
	tmp = first->prev;
	tmp->next = second;
	second->prev = tmp;
	tmp = second->next;
	first->next = tmp;
	tmp->prev = first;
	second->next = first;
	first->prev = second;
	return (second);
}

t_data *swap(t_data *data, char which)
{

	ft_printf("s%c\n", which);
	if ((which == 'a' || which == 's') && data->stack_a)
	{
		if (data->size_a == 2)
			data->stack_a = swap_stack_size_two(data->stack_a);
		else if (data->size_a > 2)
			data->stack_a = swap_stack_size_bigger_two(data->stack_a);
	}
	if ((which == 'b' || which == 's') && data->stack_b)
	{
		if (data->size_b == 2)
			data->stack_b = swap_stack_size_two(data->stack_b);
		else if (data->size_b > 2)
			data->stack_b = swap_stack_size_bigger_two(data->stack_b);
	}
	return (data);
}


t_data *swap_both(t_data *data)
{
	if (data)
		data = swap(data, 's');
	return (data);
}
