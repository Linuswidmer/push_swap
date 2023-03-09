/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:14:06 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/09 11:46:06 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			ft_printf("Index Array: \n");
			print_arr_index(arr, data->size_a);
			ft_printf("Size of Stack a is %i\n", data->size_a);
			split_arr_to_stack_a(data, arr);
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
