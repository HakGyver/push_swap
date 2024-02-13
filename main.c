/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:05:01 by jteste            #+#    #+#             */
/*   Updated: 2024/02/12 15:19:11 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;

	i = 1;
	if (argc < 2)
		exit(0);
	while (i < argc)
	{
		if (ft_check_and_add(ft_split(argv[i], ' ')) == false)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	return (0);
}
