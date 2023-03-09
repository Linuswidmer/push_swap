/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:24:20 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/09 11:15:33 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_data *stack_first(t_data *data, t_elem *from, t_elem *new_beginning_from, t_elem* new_beginning_to)
{
	if (from == data->stack_a)
	{
		data->stack_b = new_beginning_to;
		data->stack_a = new_beginning_from;
	}
	else 
	{
		data->stack_a = new_beginning_to;
		data->stack_b = new_beginning_from;
	}
	return (data);
}

static t_data *push_stack_size_zero(t_data *data, t_elem *from)
{
	t_elem *zero_from;
	t_elem *second_from;
	t_elem *new_beginning_to;

	new_beginning_to = new_elem(from->num);
	new_beginning_to->next  = new_beginning_to;
	new_beginning_to->prev  = new_beginning_to;
	if (from == from->prev)
		second_from = NULL;
	else
	{
		zero_from = from->prev;
		second_from = from->next;
		zero_from->next = second_from;
		second_from->prev = zero_from;
	}
	data = stack_first(data, from, second_from, new_beginning_to);
	free(from);
	return (data);
}

static t_data *push_stack_size_one(t_data *data, t_elem *from, t_elem *to)
{
	t_elem *zero_from;
	t_elem *second_from;
	t_elem *new_beginning_to;

	new_beginning_to = new_elem(from->num);
	new_beginning_to->prev = to;
	new_beginning_to->next = to;
	to->next = new_beginning_to;
	to->prev = new_beginning_to;
	if (from == from->prev)
		second_from = NULL;
	else
	{
		zero_from = from->prev;
		second_from = from->next;
		zero_from->next = second_from;
		second_from->prev = zero_from;
	}
	data = stack_first(data, from, second_from, new_beginning_to);
	free(from);
	return (data);
}

static t_data *push_stack_size_bigger_one(t_data *data, t_elem *from, t_elem *to)
{
	t_elem *zero_from;
	t_elem *second_from;
	t_elem *zero_to;
	t_elem *new_beginning_to;

	zero_to = to->prev;
	new_beginning_to = new_elem(from->num);
	new_beginning_to->prev = zero_to;
	new_beginning_to->next = to;
	zero_to->next = new_beginning_to;
	to->prev = new_beginning_to;
	data->stack_b = new_beginning_to;
	if (from == from->next)
		second_from = NULL;
	else
	{
		second_from = from->next;
		zero_from = from->prev;
		zero_from->next = second_from;
		second_from->prev = zero_from;
	}
	data = stack_first(data, from, second_from, new_beginning_to);
	free(from);
	return (data);
}

t_data *push(t_data *data, char which)
{
	ft_printf("p%c\n", which);
	if (data)
	{
		if (which == 'b' && data->stack_a)
		{
			if (data->size_b == 0)
				data = push_stack_size_zero(data, data->stack_a);
			else if (data->size_b == 1)
				data = push_stack_size_one(data, data->stack_a, data->stack_b);
			else
				data = push_stack_size_bigger_one(data, data->stack_a, data->stack_b);
			data->size_a = data->size_a - 1;
			data->size_b = data->size_b + 1;
		}	
		else if (which == 'a' && data->stack_b)
		{
			if (data->size_a == 0)
				data = push_stack_size_zero(data, data->stack_b);
			else if (data->size_a == 1)
				data = push_stack_size_one(data, data->stack_b, data->stack_a);
			else
				data = push_stack_size_bigger_one(data, data->stack_b, data->stack_a);
			data->size_a = data->size_a + 1;
			data->size_b = data->size_b - 1;
		}
	}
	return (data);
}
