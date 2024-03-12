/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:47:25 by jteste            #+#    #+#             */
/*   Updated: 2024/03/12 07:33:23 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*temp;

	if (*stack_from == NULL)
		return (false);
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (*stack_from != NULL)
		(*stack_from)->prev = NULL;
	temp->next = *stack_to;
	temp->prev = NULL;
	if (*stack_to != NULL)
		(*stack_to)->prev = temp;
	*stack_to = temp;
	return (true);
}

int	ft_pa(t_list **stack_b, t_list **stack_a)
{
	if (ft_push(stack_b, stack_a) == false)
		return (false);
	ft_printf("pa\n");
	return (true);
}

int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_a, stack_b) == false)
		return (false);
	ft_printf("pb\n");
	return (true);
}
