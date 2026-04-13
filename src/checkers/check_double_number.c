#include "../../include/push_swap.h"

int	check_double_number(t_stack *stack)
{
	t_stack	*current;
	t_stack	*aux;

	current = stack;
	while (current)
	{
		aux = current->next;
		while (aux)
		{
			if (current->value == aux->value)
				return (0);
			aux = aux->next;
		}
		current = current->next;
	}
	return (1);
}
