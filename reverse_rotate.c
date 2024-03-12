/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:08:55 by jteste            #+#    #+#             */
/*   Updated: 2024/03/12 08:19:54 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*prev_to_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (false);
	last = ft_lstlast(*stack);
	prev_to_last = last->prev;
	prev_to_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
	return (true);
}

int	ft_rra(t_list **stack_a)
{
	if (ft_reverse_rotate(stack_a) == false)
		return (false);
	ft_printf("rra\n");
	return (true);
}

int	ft_rrb(t_list **stack_b)
{
	if (ft_reverse_rotate(stack_b) == false)
		return (false);
	ft_printf("rrb\n");
	return (true);
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_reverse_rotate(stack_a) == false)
		return (false);
	if (ft_reverse_rotate(stack_b) == false)
		return (false);
	ft_printf("rrr\n");
	return (true);
}
