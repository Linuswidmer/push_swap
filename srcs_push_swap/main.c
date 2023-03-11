/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:14:06 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/09 14:06:47 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data *sort_three(t_data *data)
{
	int first;
	int second;
	int third;

	first = data->stack_a->num;
	second = data->stack_a->next->num;
	third = data->stack_a->prev->num;
	if (first > second && second < third)
		data = swap(data, 'a');
	else if (first > second && second > third)
	{
		data = swap(data, 'a');
		data = rev_rotate(data, 'a');
	}
	else if (first < second && second > third && third > first)
	{
		data = swap(data, 'a');
		data = rotate(data, 'a');
	}
	else if (first < second && second > third && third < first)
		data = rev_rotate(data, 'a');
	return (data);
}

/*
t_data *sort_five(t_data *data)
{
	data = push(data, 'b');
	data = push(data, 'b');
}
*/

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

int main(int argc, char **argv)
{
	t_data *data;

	if (argc == 2)
	{	
		data = init(argv);
		//ft_printf("Stack A:\n");
		//print_stack(data->stack_a, data->size_a);
		//ft_printf("Stack B:\n");
		//print_stack(data->stack_b, data->size_b);
		//data = bubble_sort(data);
		data = sort_three(data);
		//data = swap(data, 'a');
		//data = rotate(data, 'a');
		//ft_printf("Stack A:\n");
		//print_stack(data->stack_a, data->size_a);
		terminate(data);
	}
	else
		ft_printf("Error");
}
