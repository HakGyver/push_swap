/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:56:43 by jteste            #+#    #+#             */
/*   Updated: 2024/02/12 15:19:44 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./printf/ft_printf.h"
# include <stdio.h>
# include <stdbool.h>

int		ft_check_and_add(char **argv);
int		ft_check_value(char *argv);
int		ft_check_int(long long nb);
void	ft_free_split(char **tab);

#endif