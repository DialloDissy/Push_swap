/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:19 by sidiallo          #+#    #+#             */
/*   Updated: 2024/02/27 21:43:04 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack  **stack)
{
    t_stack *tmp;
    t_stack *swap;
    
    
    tmp = *stack;
    swap = (*stack)->next;
    
    if(*stack == NULL || (*stack)->next == NULL)
        return;
    tmp->next = swap->next;
    swap->next = tmp;
    *stack = swap;
}
void    do_sa(t_stack   **stack_a)
{
    ft_swap(stack_a);
    write(1,"sa\n",3);
}
void    do_sb(t_stack   **stack_b)
{
    ft_swap(stack_b);
    write(1,"sb\n",3);
}

void    do_ss(t_stack   **stack_a, t_stack  **stack_b)
{
     ft_swap(stack_a);
     ft_swap(stack_b);
    write(1,"ss\n",3);
}