/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:14:06 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/26 19:40:25 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void start(int argc, char **argv)
{

	int i;

	i = 0;
	ft_printf("Arguments:\n");
	while (i < argc)
	{
		ft_printf("%s\n", argv[0]);
		i++;
	}
}

void end()
{
	ft_printf("Programm ended\n");
}

int main(int argc, char **argv)
{
	start(argc, argv);
	end();
}
