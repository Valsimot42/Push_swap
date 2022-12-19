/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:30:50 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/11 22:33:39 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Shift down all elements of stack a by 1.
The last element becomes the first one.
 * 
 * @param a_stack 
 * @param rrr_call 
 */
void	rra(t_stack **a_stack, int rrr_call)
{
	t_stack	*node;
	t_stack	*temp;
	t_stack	*last_node;

	if (!a_stack || !(*a_stack))
		return ;
	if (*a_stack == NULL)
		return ;
	last_node = *a_stack;
	while (last_node->next->next != NULL)
		last_node = last_node->next;
	node = add_lsvalues(&last_node->next);
	ft_lstadd_front_mod(a_stack, node);
	temp = last_node->next;
	free(temp);
	last_node->next = NULL;
	if (!rrr_call)
		ft_putstr_fd("rra\n", 1);
	return ;
}

/**
 * @brief Shift down all elements of stack b by 1. 
 * The last element becomes the first one.

 * 
 * @param b_stack 
 * @param rrr_call 
 */
void	rrb(t_stack **b_stack, int rrr_call)
{
	t_stack	*node;
	t_stack	*temp;
	t_stack	*last_node;

	if (!b_stack || !(*b_stack))
		return ;
	if (*b_stack == NULL)
		return ;
	last_node = *b_stack;
	while (last_node->next->next != NULL)
		last_node = last_node->next;
	node = add_lsvalues(&last_node->next);
	ft_lstadd_front_mod(b_stack, node);
	temp = last_node->next;
	free(temp);
	last_node->next = NULL;
	if (!rrr_call)
		ft_putstr_fd("rrb\n", 1);
	return ;
}

/**
 * @brief rra and rrb at the same time.
 * 
 * @param a_stack 
 * @param b_stack 
 */
void	rrr(t_stack **a_stack, t_stack **b_stack)
{
	rra(a_stack, 1);
	rrb(b_stack, 1);
	ft_putstr_fd("rrr\n", 1);
	return ;
}
