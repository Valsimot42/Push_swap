/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:57:06 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/17 19:55:32 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_atoi(long int output, int i)
{
	if (output < -2147483648 || output > 2147483647)
		error_exit();
	if ((i > 10 && output < -2147483648) || (i > 9 && output > 2147483647))
		error_exit();
}

/**
 * @brief Converts the initial portion of the string pointed to by str to 
 * int representation.
 * 
 * @param str 
 * @return int 
 */
int	ft_atoi_mod(const char *str)
{
	long int			output;
	long int			sign;
	int					i;

	output = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error_exit();
		output = output * 10 + (str[i] - '0');
		i++;
	}
	output = sign * output;
	exit_atoi(output, i);
	return ((int)(output));
}
