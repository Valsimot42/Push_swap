/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:45:12 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/11 22:43:20 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a_stack)
{
	t_stack	*node;

	node = *a_stack;
	if (node->index > node->next->index
		&& node->index > node->next->next->index)
		ra(a_stack, 0);
	else if (node->next->index > node->index
		&& node->next->index > node->next->next->index)
		rra(a_stack, 0);
	node = *a_stack;
	if (node->index > node->next->index)
		sa(a_stack, 0);
}

void	pass_to_b(t_stack **a_stack, t_stack **b_stack)
{
	int	a_size;
	int	pushed;

	a_size = ft_lst_len(a_stack);
	pushed = 0;
	while (pushed < a_size / 2 && a_size - pushed > 3)
	{
		if ((*a_stack)->index <= a_size / 2)
		{
			pb(a_stack, b_stack);
			pushed++;
		}
		else
			ra(a_stack, 0);
	}
	while (a_size - pushed > 3)
	{
		pb(a_stack, b_stack);
		pushed++;
	}
}

void	sort_more(t_stack **a_stack, t_stack **b_stack)
{
	pass_to_b(a_stack, b_stack);
	sort_three(a_stack);
	while (*b_stack)
	{
		add_pos(a_stack, b_stack);
		find_tp(a_stack, b_stack);
		calc_cost(a_stack, b_stack);
		exec_actions(a_stack, b_stack);
		pa(a_stack, b_stack);
	}
	final_sort(a_stack);
}

void	ft_sort(t_stack **a_stack, t_stack **b_stack)
{
	int		a_stack_len;

	a_stack_len = ft_lst_len(a_stack);
	if (a_stack_len == 2)
	{
		sa(a_stack, 0);
		return ;
	}
	if (a_stack_len == 3)
	{
		sort_three(a_stack);
		return ;
	}	
	sort_more(a_stack, b_stack);
}
