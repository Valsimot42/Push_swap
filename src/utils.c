/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:00:34 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/16 16:29:06 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

int	abs_val(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	is_sorted(t_stack *a_stack)
{
	while (a_stack->next != NULL)
	{
		if (a_stack->value > a_stack->next->value)
			return (0);
		a_stack = a_stack->next;
	}
	return (1);
}

void	free_str_arr(char **argv)
{
	char	**temp;

	temp = argv;
	while (*argv)
	{
		free(*argv);
		argv++;
	}
	free (temp);
}
