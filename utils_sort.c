/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:30:11 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/06 20:56:26 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*find_max(t_stack *stack)
{
	int		max;
	int		temp;
	t_stack	*higher;

	if (!stack)
		return (NULL);
	max = stack->value;
	higher = stack;
	stack = stack->next;
	while (stack)
	{
		temp = stack->value;
		if (temp > max)
		{
			max = temp;
			higher = stack;
		}
		stack = stack->next;
	}
	return (higher);
}

t_stack	*find_min(t_stack *stack)
{
	int min;
	int temp;
	t_stack *least;

	if (!stack)
		return (NULL);
	min = stack->value;
	least = stack;
	stack = stack->next;
	while (stack)
	{
		temp = stack->value;
		if (temp < min)
		{
			min = temp;
			least = stack;
		}
		stack = stack->next;
	}
	return (least);
}