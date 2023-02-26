/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:30:08 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/26 19:30:30 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_intlen_base(long int n, unsigned int baselen)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > (baselen - 1))
	{
		i++;
		n = n / baselen;
	}
	return (i + 1);
}
