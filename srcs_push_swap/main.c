/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:14:06 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/09 11:07:37 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			data = swap_both(data);
			//data = rotate_both(data);
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
