/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:40:17 by jteste            #+#    #+#             */
/*   Updated: 2024/02/15 15:48:56 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (false);
	first = *stack;
	second = first->next;
	third = second->next;
	first->prev = second;
	first->next = third;
	second->next = first;
	second->prev = NULL;
	if (third)
		third->prev = first;
	*stack = second;
	return (true);
}

int	ft_swap_a(t_list **stack_a)
{
	if (ft_swap(stack_a) == false)
		return (false);
	ft_printf("sa\n");
	return (true);
}

int	ft_swap_b(t_list **stack_b)
{
	if (ft_swap(stack_b) == false)
		return (false);
	ft_printf("sb\n");
	return (true);
}
