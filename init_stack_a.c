/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:17:49 by jteste            #+#    #+#             */
/*   Updated: 2024/03/19 03:50:35 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_list *stack_a, t_list *stack_b)
{
	calc_index(stack_a);
	calc_index(stack_b);
	calc_target_a(stack_a, stack_b);
	calc_push_cost(stack_a, stack_b);
	calc_cheapest(stack_a);
}

void	calc_index(t_list *stack)
{
	int	i;
	int	median;

	if (stack == NULL)
		return ;
	i = 0;
	median = ft_lstsize(stack) / 2;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	calc_target_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_b;
	t_list	*target;
	long	best_index;

	while (stack_a != NULL)
	{
		best_index = LONG_MIN;
		current_b = stack_b;
		while (current_b != NULL)
		{
			if (current_b->content < stack_a->content
				&& current_b->content > best_index)
			{
				best_index = current_b->content;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == LONG_MIN)
			stack_a->target = max_in_stack(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	calc_push_cost(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_a != NULL)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->above_median)
			stack_a->push_cost += stack_a->target->index;
		else
			stack_a->push_cost += len_b - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}

void	calc_cheapest(t_list *stack_a)
{
	long	cheapest_content;
	t_list	*cheapest_node;

	if (stack_a == NULL)
		return ;
	cheapest_content = LONG_MAX;
	while (stack_a != NULL)
	{
		if (stack_a->push_cost < cheapest_content)
		{
			cheapest_content = stack_a->push_cost;
			cheapest_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	cheapest_node->cheapest = true;
}
