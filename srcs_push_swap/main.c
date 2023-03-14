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

int find_next_elem_in_chunk_rotate(t_elem *stack, int stack_size, int chunk_min, int chunk_max)
{
  t_elem *tmp;
  int iterations;

  iterations = 0;
  tmp = stack;
  while (iterations < stack_size)
  {
    if (tmp->num >=chunk_min && tmp->num <= chunk_max)
        break;
    iterations++;
    tmp = tmp->next;
  }
  return (iterations);
}

int find_next_elem_in_chunk_rev_rotate(t_elem *stack, int stack_size, int chunk_min, int chunk_max)
{
  t_elem *tmp;
  int iterations;

  iterations = 0;
  tmp = stack;
  while (iterations < stack_size)
  {
    if (tmp->num >=chunk_min && tmp->num <= chunk_max)
        break;
    iterations++;
    tmp = tmp->prev;
  }
  return (iterations);
}

t_data *push_chunk_to_stack_b(t_data *data, int chunk_min, int chunk_max)
{
  int i_rotate;
  int i_rev_rotate;
  int current_chunk_count;

  i_rotate = 0;
  i_rev_rotate = 0;
  current_chunk_count = 0;
  while (current_chunk_count <= (chunk_max - chunk_min))
  {
    i_rotate = find_next_elem_in_chunk_rotate(data->stack_a, data->size_a, chunk_min, chunk_max);
    i_rev_rotate = find_next_elem_in_chunk_rev_rotate(data->stack_a, data->size_a, chunk_min, chunk_max);
    if (i_rotate <= i_rev_rotate)
    {
      while (i_rotate)
      {
        data = rotate(data, 'a');
        i_rotate--;
      }
    }
    else if (i_rev_rotate < i_rotate)
    {
      while (i_rev_rotate)
      {
        data = rev_rotate(data, 'a');
        i_rev_rotate--;
      }
    }
    data = push(data, 'b');
    current_chunk_count++;
  }
  return (data);
}

t_data *find_in_stack_and_push(t_data *data, int find)
{
  int i_rotate;
  int i_rev_rotate;

  i_rotate = find_next_elem_in_chunk_rotate(data->stack_b, data->size_b, find, find);
  i_rev_rotate = find_next_elem_in_chunk_rev_rotate(data->stack_b, data->size_b, find, find);
  if (i_rotate <= i_rev_rotate)
  {
    while (i_rotate)
    {
      data = rotate(data, 'b');
      i_rotate--;
    }
  }
  else if (i_rev_rotate < i_rotate)
  {
    while (i_rev_rotate)
    {
      data = rev_rotate(data, 'b');
      i_rev_rotate--;
    }
  }
  data = push(data, 'a');
  return (data);
}


t_data *chunk_sort(t_data *data)
{
  int i;

  i = 19;
  data = push_chunk_to_stack_b(data, 0, 9);
  data = push_chunk_to_stack_b(data, 10, 19);
  
  while (i >= 0)
  {
    data = find_in_stack_and_push(data, i);
    i--;
  }
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
	//ft_printf("adjacent found\n");
	while (rotations)
	{
		data = rotate(data, 'a');
		rotations--;
	}
	data = push(data, 'a');
	return (data);

}

t_data *insert_biggest_smallest(t_data *data)
{
  t_elem *tmp;
  int rotations;
  int dif;

  //ft_printf("insert biggest smallest\n");
  tmp = data->stack_a;
  rotations = 0;
  dif = 1;
  if (data->stack_b->num == 0)
  {
    while (dif < 3)
    {
      while (rotations < data->size_a)
      {
        if (data->stack_b->num + dif == tmp->num)
          break;
        tmp = tmp->next;
        rotations++;
      }
      if (rotations < data->size_a)
        break;
      dif++;
      rotations = 0;
    }
  }
  else if (data->stack_b->num == 4)
  {
    while (dif < 3)
    {
      while (rotations < data->size_a)
      {
        if (data->stack_b->num - dif == tmp->prev->num)
          break;
        tmp = tmp->next;
        rotations++;
      }
      if (rotations < data->size_a)
        break;
      dif++;
      rotations = 0;
    }
  }
  while (rotations)
  {
    data = rotate(data, 'a');
    rotations--;
  }
  data = push(data, 'a');
  return (data);
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
	  data = insert_biggest_smallest(data);
	return (data);
}

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
		// ft_printf("Stack A:\n");
	 //  print_stack(data->stack_a, data->size_a);
		//ft_printf("Stack B:\n");
		//print_stack(data->stack_b, data->size_b);
		//ft_printf("Max value is: %i\n", data->max_value);
    //data = bubble_sort(data);
		//data = sort_three(data);
		//data = sorting_decision(data, data->size_a);
		//if (data->stack_a)
    //  data = sorting_decision(data, data->size_a);

    data = chunk_sort(data);
    // data = chunk_sort(data);
		// ft_printf("Stack A:\n");
		// print_stack(data->stack_a, data->size_a);
		// ft_printf("Stack B:\n");
		// print_stack(data->stack_b, data->size_b);
		//terminate(data);
	}
	else
		ft_printf("Error\n");
}
