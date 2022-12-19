/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:30:34 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/11 22:33:44 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Shift up all elements of stack a by 1.
The first element becomes the last one.
 * 
 * @param a_stack 
 * @param rr_call 
 */
void	ra(t_stack **a_stack, int rr_call)
{
	t_stack	*node;
	t_stack	*temp;

	if (!a_stack || !(*a_stack))
		return ;
	if ((*a_stack)->next == NULL)
		return ;
	node = add_lsvalues(a_stack);
	ft_lstadd_back_mod(a_stack, node);
	temp = (*a_stack)->next;
	free(*a_stack);
	*a_stack = temp;
	if (!rr_call)
		ft_putstr_fd("ra\n", 1);
	return ;
}

/**
 * @brief Shift up all elements of stack b by 1. 
 * The first element becomes the last one.
 * 
 * @param b_stack 
 * @param rr_call 
 */
void	rb(t_stack **b_stack, int rr_call)
{
	t_stack	*node;
	t_stack	*temp;

	if (!b_stack || !(*b_stack))
		return ;
	if ((*b_stack)->next == NULL)
		return ;
	node = add_lsvalues(b_stack);
	ft_lstadd_back_mod(b_stack, node);
	temp = (*b_stack)->next;
	free(*b_stack);
	*b_stack = temp;
	if (!rr_call)
		ft_putstr_fd("rb\n", 1);
	return ;
}

/**
 * @brief ra and rb at the same time.
 * 
 * @param a_stack 
 * @param b_stack 
 */
void	rr(t_stack **a_stack, t_stack **b_stack)
{
	ra(a_stack, 1);
	rb(b_stack, 1);
	ft_putstr_fd("rr\n", 1);
	return ;
}
