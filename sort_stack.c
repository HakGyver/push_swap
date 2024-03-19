/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:10:09 by jteste            #+#    #+#             */
/*   Updated: 2024/03/19 02:02:16 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = ft_lstsize(*stack_a);
	if (len_a > 3 && !is_sorted(*stack_a))
	{
		ft_pb(stack_a, stack_b);
		len_a--;
	}
	if (len_a > 3 && !is_sorted(*stack_a))
	{
		ft_pb(stack_a, stack_b);
		len_a--;
	}
	while (len_a > 3 && !is_sorted(*stack_a))
	{
		init_stack_a(*stack_a, *stack_b);
		from_a_to_b(stack_a, stack_b);
	}
}

void	from_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = find_cheapest(stack_a);
}