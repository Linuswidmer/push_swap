#include "push_swap.h"

static void	print_address(unsigned long long address)
{
	char	print;
	char	*base;

	base = malloc(17);
	ft_strlcpy(base, "0123456789abcdef", 17);
	if (address < 16)
	{
		print = base[address % 16];
		write(1, &print, 1);
	}
	else
	{
		print_address(address / 16);
		print = base[address % 16];
		write(1, &print, 1);
	}
	free(base);
}

static unsigned int	length_address(unsigned long long address)
{
	unsigned int	len;

	len = 1;
	while (address > 15)
	{
		len++;
		address = address / 16;
	}
	return (len);
}

unsigned int	ft_print_address_hex(unsigned long long address)
{
	if (address)
	{
		ft_putstr_fd("0x", 1);
		print_address(address);
	}
	return (length_address(address));
}
