/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:29:34 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/26 19:29:46 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_base(long int nbr, char *base)
{
	int		len;
	char	print;

	len = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr < len)
	{
		print = base[nbr % len];
		write(1, &print, 1);
	}
	else
	{
		ft_putnbr_base(nbr / len, base);
		print = base[nbr % len];
		write(1, &print, 1);
	}
}
