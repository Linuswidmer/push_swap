/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:14:06 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/13 13:00:33 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data *sort_two(t_data *data)
{
	int first;
	int second;
	
	first = data->stack_a->num;
	second = data->stack_a->next->num;
	if (first < second)
		return (data);
	else
		return (swap(data, 'a'));
}

t_data *sort_three(t_data *data)
{
	int first;
	int second;
	int third;

	first = data->stack_a->num;
	second = data->stack_a->next->num;
	third = data->stack_a->prev->num;
	if (first > second && second < third && third > first)
		data = swap(data, 'a');
	else if (first > second && second < third && third < first)
		data = rotate(data, 'a');
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

t_data *rotate_sorted_list(t_data *data, char which)
{
	int i;
	t_elem *tmp;

	i = 0;
	tmp = data->stack_a;
	while (tmp->num != 0)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= data->size_a / 2)
	{ 
		while (data->stack_a->num != 0)
			rotate(data, which);
	}
	else 
	{ 
		while (data->stack_a->num != 0)
			rev_rotate(data, which);
	}
	return (data);
}


t_data *insert_adjacent_found(t_data *data, int rotations)
{
	ft_printf("adjacent found\n");
	while (rotations)
	{
		data = rotate(data, 'a');
		rotations--;
	}
	data = push(data, 'a');
	return (data);

}

t_data *insert_adjacent_not_found(t_data *data)
{
}

t_data *insertion_sort(t_data *data)
{
	int rotations;
	t_elem *tmp;
	
	tmp = data->stack_a;
	rotations = 0;
	while (rotations < data->size_a)
	{
		if (tmp->prev->num < data->stack_b->num && tmp->num > data->stack_b->num)
			break;
		tmp = tmp->next;
		rotations++;
	}
	if (rotations < data->size_a)
		data = insert_adjacent_found(data, rotations);
	else
		data = insert_adjacent_not_found(data);
	return (data);
}

/*
t_data *insertion_sort(t_data *data)
{
	int rotations;
	t_elem *tmp;

	tmp = data->stack_a;
	rotations = 0;
	while (rotations < data->size_a)
	{
		if (tmp->prev->num < data->stack_b->num && tmp->num > data->stack_b->num)
			break;
		tmp = tmp->next;
		rotations++;
	}
	{
		while (rotations)
		{
			data = rotate(data, 'a');
			rotations--;
		}
	}
	else
	{
		while (1)
		{
			if (data->stack_a->prev->num + 1 == data->stack_b->num)
				break ;
			else if(data->stack_a->num - 1 == data->stack_b->num)
				break;
			data = rotate(data, 'a');
		}
	}
	data = push(data, 'a');
	return (data);
}

*/

t_data *sort_five(t_data *data)
{
	data = push(data, 'b');
	if (data->size_a == 4)
		data = push(data, 'b');

	data = sort_three(data);
	data = insertion_sort(data);
	if (data->stack_b)
		data = insertion_sort(data);
	data = rotate_sorted_list(data, 'a');
	return (data);
}

t_data *sorting_decision(t_data *data, int size)
{

	if (size == 2)
		data = sort_two(data);
	else if (size == 3)
		data = sort_three(data);
	else if (size <= 5)
		data = sort_five(data);
	else
		ft_printf("cannot sort yet\n");
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
		//data = sort_three(data);
		//data = sorting_decision(data, data->size_a);
		data = sort_five(data);

		//ft_printf("Stack A:\n");
		//print_stack(data->stack_a, data->size_a);
		terminate(data);
	}
	else
		ft_printf("Error");
}
