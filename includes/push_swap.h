/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:34:09 by lwidmer           #+#    #+#             */
/*   Updated: 2023/02/28 12:09:14 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h> 

typedef struct s_elem
{
	int			num;
	struct s_elem	*prev;
	struct s_elem	*next;
}	t_elem;

typedef struct s_data {

	char	**split_arr;
	t_elem *stack_a;
	t_elem *stack_b;
	int		size_a;
	int   size_b;

} t_data;

/*srcs printf */

size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
unsigned int	ft_intlen_base(long int n, unsigned int base);
void			ft_putnbr_base(long int nbr, char *base);
unsigned int	ft_print_address_hex(unsigned long long address);
int				ft_printf(const char *arg, ...);

/*srcs push_swap */

/* utils.c */
int	ft_isdigit(char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_calloc(size_t nmeb, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *nptr);

/* split.c */
char			**ft_split(char const *s, char c);

/* check_input.c */
int				check_input(char **split_arr);

/* stack.c */
t_elem	*new_elem(int num);
void split_arr_to_stack_a(t_data *data, int *index_arr);
int calc_stack_size(char ** split_arr);
int  *calc_data_index(t_data *data);

/* print.c */
void print_stack(t_elem *stack, int size);
void print_arr_index(int *arr, int size);

/* swap.c */
t_data *swap(t_data *data, char which);
t_data *swap_both(t_data *data);

/* rotate.c */
t_data *rotate(t_data *data, char which);
t_data *rev_rotate(t_data *data, char which);
t_data *rotate_both(t_data *data);
t_data *rev_rotate_both(t_data *data);

/* push.c */
t_data *push(t_data *data, char which);

/* init.c */
t_data *init(char **argv);
void process_input(t_data *data, char **argv);

/* terminate.c */
void terminate(t_data *data);

/* sort.c */
t_data *bubble_sort(t_data *data);


#endif
