/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:23:42 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/03 15:23:44 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem *rotate(t_elem *stack, char which)
{
  if (stack && stack->next)
  {
	if (which != 'r')
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
	if (which != 'r')
    	ft_printf("rr%c\n", which);
    return(stack->prev);
  }
  else
    return (stack);
}

t_data *rotate_both(t_data *data)
{
    ft_printf("rr\n");
	if (data)
	{
		data->stack_a = rotate(data->stack_a, 'r');
		data->stack_b = rotate(data->stack_b, 'r');
	}
	return (data);
}

t_data *rev_rotate_both(t_data *data)
{
    ft_printf("rrr\n");
	if (data)
	{
		data->stack_a = rev_rotate(data->stack_a, 'r');
		data->stack_b = rev_rotate(data->stack_b, 'r');
	}
	return (data);
}
