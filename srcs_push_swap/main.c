/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:14:06 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/08 11:58:18 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data *push_stack_size_zero(t_data *data, t_elem *from)
{
	t_elem *zero_from;
	t_elem *second_from;

	data->stack_b = new_elem(from->num);
	data->stack_b->next = data->stack_b;
	data->stack_b->prev = data->stack_b;
	
	if (from == from->prev)
		data->stack_a = NULL;
	else
	{
		zero_from = from->prev;
		second_from = from->next;
		zero_from->next = second_from;
		second_from->prev = zero_from;
		data->stack_a = second_from;
	}
	free(from);
	return (data);
}

t_data *push_stack_size_one(t_data *data, t_elem *from, t_elem *to)
{
	t_elem *zero_from;
	t_elem *second_from;
	t_elem *new_beginning_to;

	new_beginning_to = new_elem(from->num);
	new_beginning_to->prev = to;
	new_beginning_to->next = to;
	to->next = new_beginning_to;
	to->prev = new_beginning_to;
	data->stack_b = new_beginning_to;
	if (from == from->prev)
		data->stack_a = NULL;
	else
	{
		zero_from = from->prev;
		second_from = from->next;
		zero_from->next = second_from;
		second_from->prev = zero_from;
		data->stack_a = second_from;
	}
	free(from);
	return (data);
}

t_data *push_stack_size_bigger_one(t_data *data, t_elem *from, t_elem *to)
{
	t_elem *zero_from;
	t_elem *second_from;
	t_elem *zero_to;
	t_elem *new_beginning_to;

	if (from)
	{
		zero_to = to->prev;
		new_beginning_to = new_elem(from->num);
		new_beginning_to->prev = zero_to;
		new_beginning_to->next = to;
		zero_to->next = new_beginning_to;
		to->prev = new_beginning_to;
		data->stack_b = new_beginning_to;
		if (from == from->next)
			data->stack_a = NULL;
		else
		{
			second_from = from->next;
			zero_from = from->prev;
			zero_from->next = second_from;
			second_from->prev = zero_from;
			data->stack_a = second_from;
		}
		free(from);
	}
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
		
void process_input(t_data *data, char **argv)
{
	data->split_arr = ft_split(argv[1], ' ');
	if (data->split_arr && check_input(data->split_arr))
	{
		data->size_a = calc_stack_size(data->split_arr);
    	if (data->size_a >= 1)
    	{
			ft_printf("Size of Stack a is %i\n", data->size_a);
			split_arr_to_stack_a(data);
			ft_printf("test\n");
			//data->stack_a = rev_rotate(data->stack_a, 'a');
			//data->stack_a = swap(data->stack_a, data->size_a, 'a');
			// data->stack_a = rotate(data->stack_a, 'a');
			data = push(data, 'b');
			data = push(data, 'b');
			data = push(data, 'b');
			data = push(data, 'b');
			//data = push(data, 'a');
			//data = swap_both(data);
			//data = push(data, data->stack_a, data->stack_b, 'b');
			ft_printf("Stack A:\n");
			print_stack(data->stack_a, data->size_a);
			ft_printf("Stack B:\n");
			print_stack(data->stack_b, data->size_b);
		}
	}
}

t_data *init_data_struct()
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->split_arr = NULL;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	return (data);
}

t_data *init(char **argv)
{
	t_data *data;

	data = init_data_struct();
	ft_printf("Size of data is %i\n", sizeof(t_data));
	if (data)
		process_input(data, argv);
	return (data);
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

int main(int argc, char **argv)
{
	t_data *data;

	if (argc == 2)
	{	
		data = init(argv);
		terminate(data);
	}
	else
		ft_printf("Error");
}
