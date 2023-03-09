/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:52:13 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/09 11:52:14 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_arr_index(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("%i   ", arr[i]);
		i++;
	}
	ft_printf("\n");
}

void print_stack(t_elem *stack, int size)
{
  int i;

  i = 0;
	ft_printf("First List elem is %p\n", stack);
	while(i < size)
	{
		ft_printf("Value is %i,     Previous is %i,    Next is %i\n", stack->num, stack->prev->num, stack->next->num);
		stack = stack->next;
	  i++;
  }
}
