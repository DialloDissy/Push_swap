/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:58:11 by sidiallo          #+#    #+#             */
/*   Updated: 2024/02/27 21:30:02 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push(t_stack **stack,t_stack **dest )
{
    
    t_stack *tmp;
    
    if(*stack == NULL)
        return;
    tmp = (*stack)->next;
    (*stack)->next = *dest;
    *dest = *stack;
    *stack = tmp;
    
}

void    do_pa(t_stack   **stack_b, t_stack **stack_a)
{
    ft_push(stack_b,stack_a);
    write(1,"pa\n",3);
}
void    do_pb(t_stack   **stack_a, t_stack **stack_b)
{
    ft_push(stack_a,stack_b);
    write(1,"pb\n",3);
}

