/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:18:39 by jteste            #+#    #+#             */
/*   Updated: 2024/03/19 03:56:43 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	t_list	*biggest;

	biggest = max_in_stack(*stack);
	if (biggest == *stack)
		ft_ra(stack);
	else if (biggest == (*stack)->next)
		ft_rra(stack);
	if ((*stack)->content > (*stack)->next->content)
		ft_sa(stack);
}
