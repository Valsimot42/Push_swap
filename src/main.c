/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:12:33 by stena-he          #+#    #+#             */
/*   Updated: 2022/11/10 10:56:42 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Testing
void	read_stack(t_stack **stack)
{
	t_stack	*node;
	node = *stack;

	if (*stack == NULL)
		return ;
		ft_printf("val\tind\tpos\ttp\tca\tcb\n");
	while (node)
	{
		printf("%i\t%i\t%i\t%i\t%i\t%i\n", node->value, node->index, node->pos, node->target_pos, node->cost_a, node->cost_b);		
		node = node->next;
	}
	return ;
}

void	print_stacks(t_stack **a_stack, t_stack **b_stack)
{
	ft_printf("A Stack:\n");
	read_stack(a_stack); 
	ft_printf("\n");
	ft_printf("B Stack:\n");
	read_stack(b_stack);
	ft_printf("\n");
}


//Main
int	main(int argc, char **argv)
{
	t_stack		*a_stack;
	t_stack		*b_stack;
	int			is_string;

	b_stack = NULL;
	is_string = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (0);
		is_string = 1;
	}
	a_stack = parse_args(argv, is_string);

	printf("Start\n");
	print_stacks(&a_stack, &b_stack);
	
	ft_sort(&a_stack, &b_stack);

	printf("End\n");
	print_stacks(&a_stack, &b_stack);
	
	free_stack(&a_stack);
	free_stack(&b_stack);
	return (0);
}
