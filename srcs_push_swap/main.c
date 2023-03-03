/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:14:06 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/03 10:54:02 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Operations

t_elem *swap(t_elem *first, int size, char which)
{
	t_elem *zero;
	t_elem *second;
	t_elem *third;

	ft_printf("s%c\n", which);
	if (!first || size <= 1)
		return (first);
	else 
	{
		second = first->next;
		if (size == 2)
		{
			first->next = second;
			second->prev = first;
		}
		else
		{
			zero = first->prev;
			third = second->next;
			zero->next = second;
			first->next = third;
			second->prev = zero;
			third->prev = first;
		}
		second->next = first;
		first->prev = second;
		return (second);
	}
}

t_data *rotate_both(t_data *data)
{
	if (data)
	{
		data->stack_a = rotate(data->stack_a, 'a');
		data->stack_b = rotate(data->stack_b, 'b');
	}
	else
		return (data);
	
}


t_elem *rotate(t_elem *stack, char which)
{
  if (stack && stack->next)
  {
    ft_printf("r%c\n", which);
    return(stack->next);
  }
  else
    return (stack);
}

t_elem *rev_rotate(t_elem *stack, char which)
{
  if (stack && stack->prev)
  {
    ft_printf("rr%c\n", which);
    return(stack->prev);
  }
  else
    return (stack);
}

t_data *push(t_data *data, t_elem *first_a, t_elem *first_b, char which)
{
	t_elem *zero_a;
	t_elem *second_a;
	t_elem *zero_b;

	zero_a = first_a->prev;
	second_a = first_a->next;
	if (data->size_b == 0)
	{
		data->stack_b = new_elem(first_a-> num);
		free(first_a);
	}
	else
	{
		if (data->size_b == 1)
		{
			first_a->prev = first_b;
			first_b->next = first_a;
		}
		else
		{
			zero_b = first_b->prev;
			first_a->prev = zero_b;
			zero_b->next  = first_a;
		}
		first_b->prev = first_a;
		first_a->next = first_b;
		data->stack_b = first_a;
	}
	//first_a->prev->next = second_a;
	zero_a->next = second_a;
	second_a->prev = zero_a;
	data->stack_a = second_a;
	data->size_a = data->size_a -1;
	data->size_b = data->size_b +1;
	ft_printf("p%c\n", which);
	return (data);
}
		
void process_input(t_data *data, char **argv)
{
	data->split_arr = ft_split(argv[1], ' ');
	ft_printf("test\n");
	if (data->split_arr && check_input(data->split_arr))
	{
		data->size_a = calc_stack_size(data->split_arr);
    	if (data->size_a > 1)
    	{
			ft_printf("Size of Stack a is %i\n", data->size_a);
			split_arr_to_stack_a(data);
			//data->stack_b = new_elem(-1);
			//data->size_b = 1;
			// data->stack_a = rev_rotate(data->stack_a, 'a');
			data->stack_a = swap(data->stack_a, data->size_a, 'a');
			// data->stack_a = rotate(data->stack_a, 'a');
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
