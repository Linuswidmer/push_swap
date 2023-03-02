#include "push_swap.h"


t_elem	*new_elem(int num)
{
	t_elem	*element;

	element = malloc(sizeof(t_elem));
	if (!element)
		return (NULL);
	element->num = num;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}


void split_arr_to_stack(t_data *data)
{
	int i;
	t_elem *tmp;
	t_elem *tmp_2;

	i = 2;
	data->stack_a = new_elem(ft_atoi(data->split_arr[0]));
	tmp = new_elem(ft_atoi(data->split_arr[1]));
	data->stack_a->next = tmp;
	tmp->prev = data->stack_a;
	while (data->split_arr[i])
	{
		tmp_2 = new_elem(ft_atoi(data->split_arr[i]));	
		tmp->next = tmp_2;
		tmp_2->prev = tmp;
		tmp = tmp_2;
		i++; 
	}
  tmp->next = data->stack_a;
  data->stack_a->prev = tmp;
}

void calc_stack_size(t_data *data)
{
	int i;

	i = 0;
	while (data->split_arr[i])
		i++;
	data->size_a = i;
}

void print_stack(t_elem *stack, int size)
{
  int i;

  i = 0;
	while(i < size)
	{
		ft_printf("%i\n", stack->num);
		stack = stack->next;
	  i++;
  }
}

void free_stack(t_elem *stack, int size)
{
  int i;
	t_elem *tmp;

  i = 0;
	while (i < size)
	{
		tmp = stack->prev;
		free(stack);
		stack = tmp;
    i++;
	}
}
