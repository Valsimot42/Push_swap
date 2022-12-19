/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:30:31 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/11 22:33:48 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Swap the first 2 elements at the top of stack a. 
 * Do nothing if there is only one or no elements.
 * 
 * @param a_stack 
 */
void	sa(t_stack **a_stack, int ss_call)
{
	t_stack	*node;
	t_stack	*temp;

	if (!a_stack || !(*a_stack))
		return ;
	if ((*a_stack)->next == NULL)
		return ;
	node = add_lsvalues(&(*a_stack)->next);
	temp = (*a_stack)->next;
	(*a_stack)->next = (*a_stack)->next->next;
	free(temp);
	ft_lstadd_front_mod(a_stack, node);
	if (!ss_call)
		ft_putstr_fd("sa\n", 1);
	return ;
}

/**
 * @brief Swap the first 2 elements at the top of stack b. 
 * Do nothing if there is only one or no elements.
 * 
 * @param b_stack 
 */
void	sb(t_stack **b_stack, int ss_call)
{
	t_stack	*node;
	t_stack	*temp;

	if (!b_stack || !(*b_stack))
		return ;
	if ((*b_stack)->next == NULL)
		return ;
	node = add_lsvalues(&(*b_stack)->next);
	temp = (*b_stack)->next;
	(*b_stack)->next = (*b_stack)->next->next;
	free(temp);
	ft_lstadd_front_mod(b_stack, node);
	if (!ss_call)
		ft_putstr_fd("sb\n", 1);
	return ;
}

/**
 * @brief Do sa and sb at the same time.
 * 
 * @param a_stack 
 * @param b_stack 
 */
void	ss(t_stack **a_stack, t_stack **b_stack)
{
	sa(a_stack, 1);
	sb(b_stack, 1);
	ft_putstr_fd("ss\n", 1);
	return ;
}
