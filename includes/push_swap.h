/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:34:09 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/26 19:37:34 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h> 

size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
unsigned int	ft_intlen_base(long int n, unsigned int base);
void			ft_putnbr_base(long int nbr, char *base);
unsigned int	ft_print_address_hex(unsigned long long address);
int				ft_printf(const char *arg, ...);
#endif
