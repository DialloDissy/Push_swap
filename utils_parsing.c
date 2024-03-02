/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:59:27 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/02 19:05:02 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack *ft_add_back(t_stack *stack, int i)
{
    t_stack *new;
    t_stack *last;

    // new = malloc(sizeof(*new));
    // if (!new)
    // {
    //     perror("malloc failed");
    //     return NULL;
    // }
    // new->value = i;
    // new->next = NULL;
	new = list_new(i);
    if (!stack)
        return new;
    last = stack;
    while (last->next)
        last = last->next;
    last->next = new;
    return stack;
}

t_stack *list_new(int value)
{
    t_stack *new_stack;

    
    new_stack = (t_stack*)malloc(sizeof(t_stack));
    if(!new_stack)
        return(NULL);
    new_stack->next = NULL;
    new_stack->value = value;
	new_stack->previous = NULL;
	new_stack->target = NULL;
    return(new_stack);
    
}
// t_stack ft_back_front(t_stack *stack, int i)
// {
//     t_stack *new;
    

//     new = list_new(i);
//     new->next = stack;
    
//     return(*new);
// }

// t_stack *ft_add_back(t_stack *stack, int i)
// {
// 	t_stack *new;
// 	t_stack	*last;
	
// 	last = 
// 	new = list_new(i);
// 	if(!stack)
// 		return(new);
// 	last = ft_stacklast(&stack);
// 	last->next =new;
	

// 	return(stack);
// }


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
// t_stack	*ft_stacklast(t_stack **stack)
// {
// 	while (*stack)
// 	{
// 		if (!(*stack)->next)
// 			return (*stack);
// 		*stack = (*stack)->next;
// 	}
// 	return (*stack);
// }