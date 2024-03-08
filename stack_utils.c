/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:59:27 by sidiallo          #+#    #+#             */
/*   Updated: 2024/02/28 20:35:29 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack *list_new(int value)
{
    t_stack *new_stack;

    
    new_stack = (t_stack*)malloc(sizeof(t_stack));
    if(!new_stack)
        return(NULL);
    new_stack->next = NULL;
    new_stack->value = value;
    return(new_stack);
    
}

void ft_add_back(t_stack **stack, int i)
{
	t_stack *new;

	if (*stack)
	{
		new = ft_stacklast(*stack);
		new->next = &*new;
	}
	else
		*stack = new;
}


int check_duplicate(t_stack *stack_a, int nbr)
{

    while(stack_a != NULL)
    {
        if(stack_a->value == nbr)
            return(1);
        stack_a = stack_a->next;
    }
    return(0);

}
t_stack	*ft_stacklast(t_stack **stack)
{
	while (*stack)
	{
		if (!(*stack)->next)
			return (*stack);
		*stack = (*stack)->next;
	}
	return (*stack);
}