/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:39:19 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/10 18:22:44 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && !ft_issign(av[i][j])
				&& av[i][j] != ' ')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*ft_get_number(char *av, t_stack *stack)
{
	int			i;
	long long	n;

	i = 0;
	while (av[i])
	{
		n = ft_atoi_swap(av, &i);
		if (n > 2147483647 || n < -2147483648)
		{
			if (stack)
				free_stack(&stack);
			return (NULL);
		}
		if (check_duplicate(stack, n))
		{
			if (stack)
				free_stack(&stack);
			return (0);
		}
		stack = ft_add_back(stack, n);
		while (av[i] == ' ' || (av[i] >= 9 && av[i] <= 13))
			i++;
	}
	return (stack);
}

t_stack	*ft_parsing(char **argv, t_stack **stack)
{
	int	i;

	i = 0;
	if (ft_check_digit(argv) == 0)
		return (0);
	while (argv[i])
	{
		*stack = ft_get_number(argv[i], *stack);
		if (!(*stack))
			return (0);
		i++;
	}
	return (*stack);
}
