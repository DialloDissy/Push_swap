/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:59:27 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/07 19:32:10 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_add_back(t_stack *stack, int i)
{
	t_stack	*new;
	t_stack	*last;

	new = list_new(i);
	if (!stack)
		return (new);
	last = stack;
	while (last->next)
		last = last->next;
	last->next = new;
	return (stack);
}

t_stack	*list_new(int value)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->next = NULL;
	new_stack->value = value;
	new_stack->target = NULL;
	return (new_stack);
}

int	check_duplicate(t_stack *stack_a, int nbr)
{
	while (stack_a != NULL)
	{
		if (stack_a->value == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
void	free_stack(t_stack **stack)
{
	if (!(*stack))
		return ;
	t_stack *tmp;
	tmp = *stack;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		free(tmp);
	}

	// if (!(*stack))
	// 	return ;
	// while (*stack)
	// {
	// 	free(*stack);
	// 	*stack = (*stack)->next;
	// }
}