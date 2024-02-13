/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:40:17 by jteste            #+#    #+#             */
/*   Updated: 2024/02/13 16:08:13 by jteste           ###   ########.fr       */
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
	
}
