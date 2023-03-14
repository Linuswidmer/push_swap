/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:09:10 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/13 12:50:49 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void process_input(t_data *data, char **argv)
{
	int *arr;

	data->split_arr = ft_split(argv[1], ' ');
	if (data->split_arr && check_input(data->split_arr))
	{
		data->size_a = calc_stack_size(data->split_arr);
    		if (data->size_a >= 1)
    		{
			arr = calc_data_index(data);
      data->max_value = data->size_a - 1;
			//ft_printf("Index Array: \n");
			//print_arr_index(arr, data->size_a);
			//ft_printf("Size of Stack a is %i\n", data->size_a);
			split_arr_to_stack_a(data, arr);
		}
	}
}

static t_data *init_data_struct()
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
	//ft_printf("Size of data is %i\n", sizeof(t_data));
	if (data)
		process_input(data, argv);
	return (data);
}
