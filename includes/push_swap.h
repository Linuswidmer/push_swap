/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:34:09 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/27 00:09:35 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h> 

typedef struct s_stack
{
	int			num;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data {

	char	**split_arr;
	t_stack *stack_a;
	t_stack *stack_b;

} t_data;


size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
unsigned int	ft_intlen_base(long int n, unsigned int base);
void			ft_putnbr_base(long int nbr, char *base);
unsigned int	ft_print_address_hex(unsigned long long address);
int				ft_printf(const char *arg, ...);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
void			*ft_calloc(size_t nmeb, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);


int				check_input(int argc);
#endif
