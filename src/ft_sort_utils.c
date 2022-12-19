/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:49:40 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/11 19:55:52 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_maxind(t_stack **stack)
{
	t_stack	*node;
	int		max_a_index;

	node = *stack;
	max_a_index = 0;
	while (node)
	{
		if (max_a_index < node->index)
			max_a_index = node->index;
		node = node->next;
	}
	return (max_a_index);
}

int	get_lowind_pos(t_stack **stack)
{
	t_stack	*node;
	t_stack	*lowind_node;
	int		position;

	node = *stack;
	lowind_node = *stack;
	position = 0;
	while (node)
	{
		if (node->index < lowind_node->index)
			lowind_node = node;
		node = node->next;
	}
	position = lowind_node->pos;
	return (position);
}
