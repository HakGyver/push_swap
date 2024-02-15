/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:56:43 by jteste            #+#    #+#             */
/*   Updated: 2024/02/15 15:47:19 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./printf/ft_printf.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		ft_check_and_add(t_list **stack_a, char **argv);
int		ft_check_value(char *argv);
int		ft_check_int(long long nb);
int		ft_free_split(char **tab);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_check_duplicate(t_list **stack_a);
int		ft_swap(t_list **stack);
int		ft_swap_a(t_list **stack_a);
int		ft_swap_b(t_list **stack_b);

#endif