/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:47:01 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/12 00:12:54 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_final_actions(t_stack **a_stack, int lowest_pos)
{
	int		stack_size;

	stack_size = ft_lst_len(a_stack);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(a_stack, 0);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(a_stack, 0);
			lowest_pos--;
		}
	}
}

void	final_sort(t_stack **a_stack)
{
	t_stack	*node_a;
	int		lowest_pos;

	node_a = *a_stack;
	lowest_pos = 0;
	while (node_a)
	{
		if (node_a->index == 1)
			break ;
		lowest_pos++;
		node_a = node_a->next;
	}
	do_final_actions(a_stack, lowest_pos);
}
