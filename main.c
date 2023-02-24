/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:14:06 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/24 20:19:32 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void start(int argc, char **argv)
{

	int i;

	i = 0;
	printf("Arguments:\n")
	while (i < argc)
	{
		printf("%s\n", argv)
	}
}

void end()
{
	printf("Programm ended\n");
}

int main(int argc, char **argv)
{
	start(argc, argv);
	end();
}
