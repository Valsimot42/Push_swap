/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:27:35 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/11 19:58:20 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lst_len(t_stack **lst)
{
	t_stack	*node;
	int		len;

	node = *lst;
	len = 0;
	if (!lst || !(*lst))
		return (0);
	while (node->next != NULL)
	{
		node = node->next;
		len++;
	}
	len++;
	return (len);
}

t_stack	*ft_lstnew_mod(int value, int index)
{
	t_stack	*output;

	output = malloc(sizeof(t_stack));
	if (!output)
		return (NULL);
	output->value = value;
	output->next = NULL;
	if (index)
		output->index = index;
	return (output);
}

t_stack	*add_lsvalues(t_stack **stack)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = (*stack)->value;
	node->index = (*stack)->index;
	node->pos = (*stack)->pos;
	node->target_pos = (*stack)->target_pos;
	node->cost_a = (*stack)->cost_a;
	node->cost_b = (*stack)->cost_b;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back_mod(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	last_node = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new;
	return ;
}

void	ft_lstadd_front_mod(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
