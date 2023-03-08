/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:27:36 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/08 11:38:06 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_elem	*new_elem(int num)
{
	t_elem	*element;

	element = malloc(sizeof(t_elem));
	if (!element)
		return (NULL);
	element->num = num;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}


void split_arr_to_stack_a(t_data *data)
{
	int i;
	t_elem *tmp;
	t_elem *tmp_2;

	i = 2;
	data->stack_a = new_elem(ft_atoi(data->split_arr[0]));
	if (data->size_a > 1)
	{
		tmp = new_elem(ft_atoi(data->split_arr[1]));
		data->stack_a->next = tmp;
		tmp->prev = data->stack_a;
		while (data->split_arr[i])
		{
			tmp_2 = new_elem(ft_atoi(data->split_arr[i]));	
			tmp->next = tmp_2;
			tmp_2->prev = tmp;
			tmp = tmp_2;
			i++; 
		}
  		tmp->next = data->stack_a;
  		data->stack_a->prev = tmp;
	}
	else 
	{
		data->stack_a->prev = data->stack_a;
		data->stack_a->next = data->stack_a;
	}
}

int calc_stack_size(char **split_arr)
{
	int i;

	i = 0;
	while (split_arr[i])
		i++;
	return (i);
}

void print_stack(t_elem *stack, int size)
{
  int i;

  i = 0;
	ft_printf("First List elem is %p\n", stack);
	while(i < size)
	{
		ft_printf("Value is %i,     Previous is %i,    Next is %i\n", stack->num, stack->prev->num, stack->next->num);
		stack = stack->next;
	  i++;
  }
}

void free_stack(t_elem *stack, int size)
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
