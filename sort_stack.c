/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:10:09 by jteste            #+#    #+#             */
/*   Updated: 2024/03/19 03:26:20 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = ft_lstsize(*stack_a);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		ft_pb(stack_a, stack_b);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		ft_pb(stack_a, stack_b);
	while (len_a-- > 3 && !is_sorted(*stack_a))
	{
		init_stack_a(*stack_a, *stack_b);
		from_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		init_stack_b(*stack_a, *stack_b);
		from_b_to_a(stack_a, stack_b);
	}
	calc_index(*stack_a);
	min_on_top(stack_a);
}

void	prep_push(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
}

void	from_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = find_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest);
	prep_push(stack_a, cheapest, 'a');
	prep_push(stack_b, cheapest->target, 'b');
	ft_pb(stack_a, stack_b);
}

void	from_b_to_a(t_list **stack_a, t_list **stack_b)
{
	prep_push(stack_a, (*stack_b)->target, 'a');
	ft_pa(stack_b, stack_a);
}

void	min_on_top(t_list **stack_a)
{
	while ((*stack_a)->content != min_in_stack(*stack_a)->content)
	{
		if (min_in_stack(*stack_a)->above_median == true)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}
