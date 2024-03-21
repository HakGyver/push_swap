/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:09:30 by jteste            #+#    #+#             */
/*   Updated: 2024/03/21 01:45:43 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (false);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*next;

	if (stack == NULL)
		return ;
	temp = *stack;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
	exit(0);
}

void	ft_error_exit(t_list **stack)
{
	write(2, "Error\n", 6);
	ft_free_stack(stack);
}
