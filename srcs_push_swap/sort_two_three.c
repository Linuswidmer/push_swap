#include "push_swap.h"

t_data *sort_two(t_data *data)
{
	int first;
	int second;
	
	first = data->stack_a->num;
	second = data->stack_a->next->num;
	if (first < second)
		return (data);
	else
		return (swap(data, 'a'));
}

t_data *sort_three(t_data *data)
{
	int first;
	int second;
	int third;

	first = data->stack_a->num;
	second = data->stack_a->next->num;
	third = data->stack_a->prev->num;
	if (first > second && second < third && third > first)
		data = swap(data, 'a');
	else if (first > second && second < third && third < first)
		data = rotate(data, 'a');
	else if (first > second && second > third)
	{
		data = swap(data, 'a');
		data = rev_rotate(data, 'a');
	}
	else if (first < second && second > third && third > first)
	{
		data = swap(data, 'a');
		data = rotate(data, 'a');
	}
	else if (first < second && second > third && third < first)
		data = rev_rotate(data, 'a');
	return (data);
}
