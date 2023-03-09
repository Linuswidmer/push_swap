/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:23:42 by lwidmer           #+#    #+#             */
/*   Updated: 2023/03/09 10:45:08 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data *rotate(t_data *data, char which)
{
	if ((which == 'a' || which == 'r') && data->stack_a)
			data->stack_a = data->stack_a->next;	
	if ((which == 'b' || which == 'r') && data->stack_b)
			data->stack_b = data->stack_b->next;	
    ft_printf("r%c\n", which);
	return (data);
}

t_data *rev_rotate(t_data *data, char which)
{
	if ((which == 'a' || which == 'r') && data->stack_a)
			data->stack_a = data->stack_a->prev;
	if ((which == 'b'|| which == 'r') && data->stack_b)
			data->stack_b = data->stack_b->prev;	
    ft_printf("rr%c\n", which);
	return (data);
}

t_data *rotate_both(t_data *data)
{
	if (data)
		data = rotate(data, 'r');
	return (data);
}


t_data *rev_rotate_both(t_data *data)
{
	if (data)
		data = rev_rotate(data, 'r');
	return (data);
}
