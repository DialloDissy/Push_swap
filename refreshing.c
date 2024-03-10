/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refreshing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:54:19 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/10 18:33:36 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_cheapest(t_stack *stack_b)
{
	int		cheap;
	t_stack	*current_cheap;

	cheap = stack_b->cost;
	current_cheap = stack_b;
	current_cheap->cheapest = true;
	stack_b = stack_b->next;
	while (stack_b)
	{
		stack_b->cheapest = false;
		if (stack_b->cost < cheap)
		{
			current_cheap->cheapest = false;
			current_cheap = stack_b;
			cheap = stack_b->cost;
			current_cheap->cheapest = true;
		}
		stack_b = stack_b->next;
	}
}

void	cost_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_b)
	{
		stack_b->cost = stack_b->index;
		if (!(stack_b->above_median))
			stack_b->cost = len_b - stack_b->index;
		if (stack_b->target->above_median)
			stack_b->cost += stack_b->target->index;
		else
			stack_b->cost += len_a - stack_b->target->index;
		stack_b = stack_b->next;
	}
}

void	refresh_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_match;

	while (stack_b)
	{
		best_match = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			stack_b->target = find_min(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	refresh_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	refreshing(t_stack *stack_a, t_stack *stack_b)
{
	refresh_index(stack_a);
	refresh_index(stack_b);
	refresh_target(stack_a, stack_b);
	cost_stack(stack_a, stack_b);
	the_cheapest(stack_b);
}
