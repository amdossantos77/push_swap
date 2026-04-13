#include "../../include/push_swap.h"

int	find_index(t_stack *s_a, int num)
{
	int	i;

	i = 0;
	while (s_a->value != num)
	{
		i++;
		s_a = s_a->next;
	}
	return (i);
}
