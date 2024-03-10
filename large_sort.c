/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:01:33 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/10 18:30:09 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_the_top(t_stack **stack_a)
{
	t_stack	*min;

	min = find_min(*stack_a);
	while (min->index != 0)
	{
		if (min->above_median == true)
		{
			do_ra(stack_a);
			refresh_index(*stack_a);
		}
		else
		{
			do_rra(stack_a);
			refresh_index(*stack_a);
		}
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	push_b_into_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_b);
	while (cheapest->index != 0 || cheapest->target->index != 0)
	{
		if (cheapest->above_median == true
			&& cheapest->target->above_median == true)
			move_both_above_median(stack_a, stack_b, cheapest);
		else if ((cheapest->above_median == false
				&& cheapest->target->above_median == false))
			move_both_under_median(stack_a, stack_b, cheapest);
		else if (((cheapest->above_median == true
					&& cheapest->target->above_median == false)))
			move_a_above_and_b_below_median(stack_a, stack_b, cheapest);
		else
			move_a_below_and_b_above_median(stack_a, stack_b, cheapest);
	}
	do_pa(stack_b, stack_a);
}

void	push_a_into_b(t_stack **stack_a, t_stack **stack_b, int median)
{
	if ((*stack_a)->value < median)
		do_pb(stack_a, stack_b);
	else
	{
		do_pb(stack_a, stack_b);
		do_rb(stack_b);
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack_a;
	int	median;

	len_stack_a = stack_len(*stack_a);
	median = ((find_min(*stack_a)->value + find_max(*stack_a)->value) / 2);
	while (len_stack_a > 3 && !is_sorted(*stack_a))
	{
		push_a_into_b(stack_a, stack_b, median);
		len_stack_a--;
	}
	three_sort(stack_a);
	while (*stack_b)
	{
		refreshing(*stack_a, *stack_b);
		push_b_into_a(stack_a, stack_b);
	}
	refresh_index(*stack_a);
	set_the_top(stack_a);
}
