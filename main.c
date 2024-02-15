/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:05:01 by jteste            #+#    #+#             */
/*   Updated: 2024/02/15 15:51:49 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*tmp;
	int		i;

	stack_a = NULL;
	i = 1;
	if (argc < 2)
		exit(0);
	while (i < argc)
	{
		if (ft_check_and_add(&stack_a, ft_split(argv[i], ' ')) == false)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	tmp = stack_a;
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	stack_a = tmp;
	ft_swap_a(&stack_a);
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return (0);
}
