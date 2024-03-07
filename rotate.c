/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:57:57 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/06 20:57:58 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	top = *stack;
	tmp = *stack;
	top = top->next;
	*stack = top;
	while (top->next != NULL)
	{
		top = top->next;
	}
	top->next = tmp;
	tmp->next = NULL;
}
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}
void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
