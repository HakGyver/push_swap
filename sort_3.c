/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:18:39 by jteste            #+#    #+#             */
/*   Updated: 2024/03/12 11:28:37 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*current;

	current = *stack;
	if (*stack == NULL)
		return (true);
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			return (false);
		current = current->next;
	}
	return (true);
}
