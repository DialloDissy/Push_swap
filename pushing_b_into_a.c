/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_b_into_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:29:05 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/10 18:31:55 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_both_above_median(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest)
{
	while ((cheapest->index != 0 && cheapest->target->index != 0))
	{
		do_rr(stack_a, stack_b);
		refresh_index(*stack_a);
		refresh_index(*stack_b);
	}
	if (cheapest->index != 0)
	{
		while (cheapest->index != 0)
		{
			do_rb(stack_b);
			refresh_index(*stack_b);
		}
	}
	else
	{
		while (cheapest->target->index != 0)
		{
			do_ra(stack_a);
			refresh_index(*stack_a);
		}
	}
}

void	move_both_under_median(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest)
{
	while ((cheapest->index != 0 && cheapest->target->index != 0))
	{
		do_rrr(stack_a, stack_b);
		refresh_index(*stack_a);
		refresh_index(*stack_b);
	}
	if (cheapest->index != 0)
	{
		while (cheapest->index != 0)
		{
			do_rrb(stack_b);
			refresh_index(*stack_b);
		}
	}
	else
	{
		while (cheapest->target->index != 0)
		{
			do_rra(stack_a);
			refresh_index(*stack_a);
		}
	}
}

void	move_a_above_and_b_below_median(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest)
{
	while (cheapest->index != 0)
	{
		do_rb(stack_b);
		refresh_index(*stack_b);
	}
	while (cheapest->target->index != 0)
	{
		do_rra(stack_a);
		refresh_index(*stack_a);
	}
}

void	move_a_below_and_b_above_median(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest)
{
	while (cheapest->index != 0)
	{
		do_rrb(stack_b);
		refresh_index(*stack_b);
	}
	while (cheapest->target->index != 0)
	{
		do_ra(stack_a);
		refresh_index(*stack_a);
	}
}
