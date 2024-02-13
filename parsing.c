/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:42:22 by jteste            #+#    #+#             */
/*   Updated: 2024/02/13 17:24:23 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicate(t_list **stack_a)
{
	t_list	*current;
	t_list	*runner;

	current = *stack_a;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->content == runner->content)
				return (false);
			runner = runner->next;
		}
		current = current->next;
	}
	return (true);
}

int	ft_create_stack(t_list **stack_a, int nb)
{
	t_list	*new;

	new = ft_lstnew(nb);
	if (new == NULL)
		return (false);
	ft_lstadd_back(stack_a, new);
	return (true);
}

int	ft_check_int(long long nb)
{
	if (nb < -2147483648 || nb > 2147483647)
		return (false);
	else
		return (true);
}

int	ft_check_value(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '-')
		i++;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	ft_check_and_add(t_list **stack_a, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_check_value(argv[i]) == false)
			return (ft_free_split(argv));
		if (ft_check_int(ft_atoi(argv[i])) == false)
			return (ft_free_split(argv));
		if (ft_create_stack(stack_a, ft_atoi(argv[i])) == false)
			return (ft_free_split(argv));
		if (ft_check_duplicate(stack_a) == false)
			return (ft_free_split(argv));
		i++;
	}
	ft_free_split(argv);
	return (true);
}
