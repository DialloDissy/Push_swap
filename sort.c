/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:58:01 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/06 16:11:10 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **stack)
{
	t_stack	*higher;

	higher = find_max(*stack);
	if (higher == *stack)
		do_ra(stack);
	else if ((*stack)->next == higher)
		do_rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		do_sa(stack);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_len(*stack_a) == 2)
		do_sa(stack_a);
	else if (stack_len(*stack_a) == 3)
		three_sort(stack_a);
	else
		sort_big(stack_a, stack_b);
}