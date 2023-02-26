/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:27:19 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/26 19:27:35 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	parse_int(long int n, char *base)
{
	if (ft_strlen(base) > 10 && n < 0)
	{
		ft_putnbr_base((unsigned int)n, base);
		return (ft_intlen_base((unsigned int)n, ft_strlen(base)));
	}
	else
	{
		ft_putnbr_base(n, base);
		return (ft_intlen_base(n, ft_strlen(base)));
	}
}

static unsigned int	parse_string(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static unsigned int	parse_pointer(unsigned long long n)
{
	unsigned int	len;

	if (!n)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len = ft_print_address_hex(n);
	return (len + 2);
}

static unsigned int	parse_ap(const char c, va_list ap)
{
	if (c == 'd' || c == 'i')
		return (parse_int(va_arg(ap, int), "0123456789"));
	else if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'u')
		return (parse_int(va_arg(ap, unsigned int), "0123456789"));
	else if (c == 's')
		return (parse_string(va_arg(ap, char *)));
	else if (c == 'x')
		return (parse_int(va_arg(ap, int), "0123456789abcdef"));
	else if (c == 'X')
		return (parse_int(va_arg(ap, int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (parse_pointer(va_arg(ap, unsigned long long)));
	return (1);
}

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		len;
	int		i;

	if (!arg)
		return (-1);
	i = 0;
	len = 0;
	va_start(ap, arg);
	while (arg[i] != '\0')
	{
		if (arg[i] == '%')
			len = len + parse_ap(arg[++i], ap) - 2;
		else
			ft_putchar_fd(arg[i], 1);
		i++;
	}
	va_end(ap);
	return (len + i);
}
