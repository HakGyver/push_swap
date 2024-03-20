/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:05:01 by jteste            #+#    #+#             */
/*   Updated: 2024/03/20 04:01:09 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (argc == 1 || ((argc == 2) && argv[1][0] == '\0'))
		exit(0);
	while (++i < argc)
	{
		if (ft_check_and_add(&stack_a, ft_split(argv[i], ' ')) == false)
			ft_error_exit(&stack_a);
	}
	if (!is_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) == 2)
			ft_sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	return (0);
}
