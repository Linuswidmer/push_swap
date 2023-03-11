/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:27:36 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/09 11:51:51 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_stack_size(char **split_arr)
{
	int i;

	i = 0;
	while (split_arr[i])
		i++;
	return (i);
}

int  *calc_data_index(t_data *data)
{
	int *arr;
	int i;
	int j;
	int index;

	arr = malloc(sizeof(int) * data->size_a);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < data->size_a)
	{
		j = 0;
		index = 0;
		while (j < data->size_a)
		{
			if (ft_atoi(data->split_arr[i]) > ft_atoi(data->split_arr[j]))
				index++;
			j++;
		}
		arr[i] = index;
		i++;
	}
	return (arr);
}

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

void split_arr_to_stack_a(t_data *data, int *index_arr)
{
	int i;
	t_elem *tmp;
	t_elem *tmp_2;

	i = 2;
	data->stack_a = new_elem(index_arr[0]);
	if (data->size_a > 1)
	{
		tmp = new_elem(index_arr[1]);
		data->stack_a->next = tmp;
		tmp->prev = data->stack_a;
		while (data->split_arr[i])
		{
			tmp_2 = new_elem(index_arr[i]);	
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
