/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 07:48:10 by jteste            #+#    #+#             */
/*   Updated: 2024/03/12 08:03:56 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (false);
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last = ft_lstlast(*stack);
	last->next = first;
	first->prev = last;
	first->next = NULL;
	return (true);
}

int	ft_ra(t_list **stack_a)
{
	if (ft_rotate(stack_a) == false)
		return (false);
	ft_printf("ra\n");
	return (true);
}

int	ft_rb(t_list **stack_b)
{
	if (ft_rotate(stack_b) == false)
		return (false);
	ft_printf("rb\n");
	return (true);
}

int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_rotate(stack_a) == false)
		return (false);
	if (ft_rotate(stack_b) == false)
		return (false);
	ft_printf("rr\n");
	return (true);
}
