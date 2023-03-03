/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:45 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/03 15:23:27 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem *swap_stack_size_two(t_elem *first, t_elem *second)
{
	first->next = second;
	second->prev = first;
	second->next = first;
	first->prev = second;
	return (second);
	
}

static t_elem *swap_stack_size_bigger_two(t_elem *first, t_elem *second)
{
	t_elem *tmp;
	
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

t_elem *swap(t_elem *first, int size, char which)
{
	t_elem *second;

	if (which != 's')
		ft_printf("s%c\n", which);
	second = first->next;
	if (!second || !first || size <= 1)
		return (first);
	else if (size == 2)
		return (swap_stack_size_two(first, second));
	else
		return (swap_stack_size_bigger_two(first, second));
}

t_data *swap_both(t_data *data)
{
	ft_printf("ss\n");
	if (data)
	{
		data->stack_a = swap(data->stack_a, data->size_a, 's');
		data->stack_b = swap(data->stack_b, data->size_b, 's');
	}
	return (data);
}
