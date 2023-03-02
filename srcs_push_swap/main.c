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

// Operations

//previos dinger sind eigentlich erstmal egaal

void swap(t_elem *elem1, t_elem *elem2)
{
  t_elem *tmp;

  if (elem1 && elem2)
  {
    tmp = elem1;
    elem1->prev = elem2;
    elem1->next = elem2->next;
    elem2->next = tmp;
    elem2->prev = tmp->prev;
  }
}

t_elem *stack_last(t_elem *elem)
{
  while (elem->next)
    elem = elem->next;
  return (elem);
}

t_elem *rotate(t_elem *old_stack_beginning)
{
  t_elem *tmp;
  t_elem *new_stack_beginning;

  if (old_stack_beginning)
  {
    new_stack_beginning = old_stack_beginning->next;
    new_stack_beginning->prev = NULL;
    tmp = stack_last(old_stack_beginning);
    tmp->next = old_stack_beginning;
    old_stack_beginning->prev = tmp;
    old_stack_beginning->next = NULL;
    return (new_stack_beginning);
  }
  else
    return (NULL);
}

t_elem *rev_rotate(t_elem *old_stack_beginning)
{
  t_elem *tmp;
  t_elem *new_stack_beginning;

  if (old_stack_beginning)
  {
    tmp = stack_last(old_stack_beginning);
    tmp = tmp->prev;
    tmp->next = NULL;
    new_stack_beginning = stack_last(old_stack_beginning);
    new_stack_beginning->prev = NULL;
    new_stack_beginning->next = old_stack_beginning;
    // tmp = stack_last(old_stack_beginning);
    // tmp->next = old_stack_beginning;
    // old_stack_beginning->prev = tmp;
    // old_stack_beginning->next = NULL;
    return (new_stack_beginning);
  }
  else
    return (NULL);
}

void process_input(t_data *data, char **argv)
{
	data->split_arr = ft_split(argv[1], ' ');
	if (data->split_arr && check_input(data->split_arr))
	{
		calc_stack_size(data);
    if (data->size > 1)
    {
      ft_printf("Size of Stack a is %i\n", data->size);
		  split_arr_to_stack(data);
		  ft_printf("Stack A:\n");
      data->stack_a = rev_rotate(data->stack_a);
      // data->stack_a = rotate(data->stack_a);
      // swap(data->stack_a, next);
		  print_stack(data->stack_a);
    }
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
