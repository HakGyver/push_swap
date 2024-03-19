/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:56:43 by jteste            #+#    #+#             */
/*   Updated: 2024/03/19 03:12:03 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./printf/ft_printf.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

/*PARSING FUNCTIONS*/
int		ft_check_and_add(t_list **stack_a, char **argv);
int		ft_check_value(char *argv);
int		ft_check_int(long long nb);
int		ft_free_split(char **tab);
int		ft_check_duplicate(t_list **stack_a);
bool	is_sorted(t_list *stack);

/*LINKED LIST UTILS*/
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

/*SWAP FUNCTIONS*/
int		ft_swap(t_list **stack);
int		ft_sa(t_list **stack_a);
int		ft_sb(t_list **stack_b);
int		ft_ss(t_list **stack_a, t_list **stack_b);

/*PUSH FUNCTIONS*/
int		ft_push(t_list **stack_from, t_list **stack_to);
int		ft_pa(t_list **stack_b, t_list **stack_a);
int		ft_pb(t_list **stack_a, t_list **stack_b);

/*ROTATE FUNCTIONS*/
int		ft_rotate(t_list **stack);
int		ft_ra(t_list **stack_a);
int		ft_rb(t_list **stack_b);
int		ft_rr(t_list **stack_a, t_list **stack_b);
void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest);

/*REVERSE ROTATE FUNCTIONS*/
int		ft_reverse_rotate(t_list **stack);
int		ft_rra(t_list **stack_a);
int		ft_rrb(t_list **stack_b);
int		ft_rrr(t_list **stack_a, t_list **stack_b);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest);

/*ALGORITHME*/
void	sort_three(t_list **stack);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	init_stack_a(t_list *stack_a, t_list *stack_b);
void	init_stack_b(t_list *stack_a, t_list *stack_b);
void	calc_index(t_list *stack);
t_list	*max_in_stack(t_list *stack);
t_list	*min_in_stack(t_list *stack);
void	calc_target_a(t_list *stack_a, t_list *stack_b);
void	calc_push_cost(t_list *stack_a, t_list *stack_b);
void	calc_cheapest(t_list *stack_a);
t_list	*find_cheapest(t_list	*stack);
void	prep_push(t_list **stack, t_list *top_node, char stack_name);
void	calc_target_b(t_list *stack_a, t_list *stack_b);
void	from_a_to_b(t_list **stack_a, t_list **stack_b);
void	from_b_to_a(t_list **stack_a, t_list **stack_b);
void	min_on_top(t_list **stack_a);

#endif