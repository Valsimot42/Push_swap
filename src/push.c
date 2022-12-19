/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:30:29 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/11 22:33:35 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 * 
 * @param a_stack 
 * @param b_stack 
 */
void	pa(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node;
	t_stack	*temp;

	if (!b_stack || !(*b_stack))
		return ;
	node = add_lsvalues(b_stack);
	ft_lstadd_front_mod(a_stack, node);
	temp = *b_stack;
	*b_stack = (*b_stack)->next;
	free(temp);
	ft_putstr_fd("pa\n", 1);
	return ;
}

/**
 * @brief Take the first element at the top of a and put it at 
 * the top of b. Do nothing if a is empty.
 * 
 * @param a_stack 
 * @param b_stack 
 */
void	pb(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node;
	t_stack	*temp;

	if (!a_stack || !(*a_stack))
		return ;
	node = add_lsvalues(a_stack);
	ft_lstadd_front_mod(b_stack, node);
	temp = *a_stack;
	*a_stack = (*a_stack)->next;
	free(temp);
	ft_putstr_fd("pb\n", 1);
	return ;
}
