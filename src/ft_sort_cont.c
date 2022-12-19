/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_cont.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:26:28 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/11 23:31:29 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calc_cost(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		a_len;
	int		b_len;

	node_a = *a_stack;
	node_b = *b_stack;
	a_len = ft_lst_len(a_stack);
	b_len = ft_lst_len(b_stack);
	while (node_b)
	{
		node_b->cost_b = node_b->pos;
		if (node_b->pos > b_len / 2)
			node_b->cost_b = (b_len - node_b->pos) * -1;
		node_b->cost_a = node_b->target_pos;
		if (node_b->target_pos > a_len / 2)
			node_b->cost_a = (a_len - node_b->target_pos) * -1;
		node_b = node_b->next;
	}
}

void	find_tp_lowind(t_stack **a_stack, t_stack *node_b)
{
	t_stack	*node_a;
	int		lowest_diff;
	int		diff;

	node_a = *a_stack;
	lowest_diff = get_maxind(a_stack);
	while (node_a)
	{
		diff = node_a->index - node_b->index;
		if (diff > 0 && diff < lowest_diff)
		{
			lowest_diff = diff;
			node_b->target_pos = node_a->pos;
		}
		node_a = node_a->next;
	}
	node_a = *a_stack;
}

void	find_tp(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node_b;
	int		max_a_index;
	int		low_a_ind_pos;

	node_b = *b_stack;
	max_a_index = get_maxind(a_stack);
	low_a_ind_pos = get_lowind_pos(a_stack);
	while (node_b)
	{
		if (node_b->index > max_a_index)
			node_b->target_pos = low_a_ind_pos;
		else
		{
			find_tp_lowind(a_stack, node_b);
		}
		node_b = node_b->next;
	}
}

void	add_pos(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		position;

	node_a = *a_stack;
	node_b = *b_stack;
	position = 0;
	while (node_a)
	{
		node_a->pos = position;
		position++;
		node_a = node_a->next;
	}
	position = 0;
	while (node_b)
	{
		node_b->pos = position;
		position++;
		node_b = node_b->next;
	}
}
