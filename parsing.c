/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:42:22 by jteste            #+#    #+#             */
/*   Updated: 2024/02/12 17:04:08 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_check_and_add(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_check_value(argv[i]) == false)
		{
			ft_free_split(argv);
			return (false);
		}
		if (ft_check_int(ft_atoi(argv[i])) == false)
		{
			ft_free_split(argv);
			return (false);
		}
		i++;
	}
	ft_free_split(argv);
	return (true);
}
