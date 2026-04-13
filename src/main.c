#include "../include/push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*s_a;

	s_a = interpreter_args(ac, av);
	if (!s_a || !check_double_number(s_a))
	{
		free_stack(&s_a);
		ft_error();
	}
	if (!check_order(s_a))
		algorithm(&s_a);
	free_stack(&s_a);
	return (0);
}
