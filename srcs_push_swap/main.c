/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:14:06 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/28 12:07:12 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*stacknew(int num)
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

void print_stack(t_elem *stack)
{
	while(stack)
	{
		ft_printf("%i\n", stack->num);
		stack = stack->next;
	}
}

void split_arr_to_stack(t_data *data)
{
	int i;
	t_elem *tmp;
	t_elem *tmp_2;

	i = 2;
	data->stack_a = stacknew(ft_atoi(data->split_arr[0]));
	tmp = stacknew(ft_atoi(data->split_arr[1]));
	data->stack_a->next = tmp;
	tmp->prev = data->stack_a;
	while (data->split_arr[i])
	{
		tmp_2 = stacknew(ft_atoi(data->split_arr[i]));	
		tmp->next = tmp_2;
		tmp_2->prev = tmp;
		tmp = tmp_2;
		i++; 
	}
	
}


void calc_stack_size(t_data *data)
{
	int i;

	i = 0;
	while (data->split_arr[i])
		i++;
	data->size = i;
}

void process_input(t_data *data, char **argv)
{
	int	i;
	
	i = 0;
	data->split_arr = ft_split(argv[1], ' ');
	if (data->split_arr && check_input(data->split_arr))
	{
		calc_stack_size(data);
		ft_printf("Size of Stack a is %i\n", data->size);
		split_arr_to_stack(data);
		ft_printf("Stack A:\n");
		print_stack(data->stack_a);
	}
}

t_data *init(char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	ft_printf("Size of data is %i\n", sizeof(t_data));
	if (data)
		process_input(data, argv);
	return (data);
}

void free_stack(t_elem *stack)
{
	t_elem *tmp;

	while (stack->next)
	{
		stack = stack->next;
	}
	while (stack)
	{
		tmp = stack->prev;
		free(stack);
		stack = tmp;
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
			free_stack(data->stack_a);
		if (data->stack_b)
			free_stack(data->stack_b);
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
