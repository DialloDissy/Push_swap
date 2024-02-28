/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_reverse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:58:01 by sidiallo          #+#    #+#             */
/*   Updated: 2024/02/27 21:37:53 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static  void r_reverse(t_stack **stack)
// {
//     t_stack *head;
//     t_stack *pos;
    
//     //  pos = *stack;
//     //  head = *stack;
//     while(pos->next != NULL)
//     {
//         pos->next = pos;    
//     }
//     pos = head;
    
    
// }

void print_stack(t_stack **stack)
{

    t_stack *current = *stack;

    printf("stack values: ");
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    
    
}
void r_reverse(t_stack **stack)
{
    t_stack *current;
    t_stack *before_bottom;

    
    current = *stack;
    while (current->next != NULL)
    {
        before_bottom = current;
        current = current->next;
    }
    before_bottom->next = NULL;
    current->next = *stack;
    *stack = current;
    printf("============\n");
}


void    do_rra(t_stack  **stack_a)
{
    r_reverse(stack_a);
    write(1,"rra\n",4);
}
void    do_rrb(t_stack  **stack_b)
{
    r_reverse(stack_b);
    write(1,"rrb\n",4);
}

void do_rrr(t_stack **stack_a, t_stack **stack_b)
{
    r_reverse(stack_a);
    r_reverse(stack_b);
    write(1,"rrr\n",4);
    
}