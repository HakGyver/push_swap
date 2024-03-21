/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:02:54 by jteste            #+#    #+#             */
/*   Updated: 2024/03/21 04:21:52 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_b(t_list *stack_a, t_list *stack_b)
{
	calc_index(stack_a);
	calc_index(stack_b);
	calc_target_b(stack_a, stack_b);
}

t_list	*find_cheapest(t_list	*stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	calc_target_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*target;
	long	best_index;

	while (stack_b != NULL)
	{
		best_index = LONG_MAX;
		current_a = stack_a;
		while (current_a != NULL)
		{
			if (current_a->content > stack_b->content
				&& current_a->content < best_index)
			{
				best_index = current_a->content;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == LONG_MAX)
			stack_b->target = min_in_stack(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}
