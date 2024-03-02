/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:39:10 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/02 17:40:06 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include<stdio.h>
# include<stdlib.h>
# include "./libft/libft.h"
# include<stdbool.h>


typedef struct s_stack
{
    int value;
    int index;
    int cost;
    bool above_median;
    bool cheapest;
    
    struct s_stack  *next;
    struct s_stack  *previous;
    struct s_stack  *target;
    
    
}   t_stack;



// parsing

t_stack *ft_parsing(char **argv, t_stack **stack );
int	ft_issign(int c);
long long	ft_atoi_swap(const char *nptr, int *pos);
int ft_check_digit(char **av);
int check_duplicate(t_stack *stack_a, int nbr);
t_stack  *ft_get_number(char *av,t_stack *stack);



t_stack *list_new(int value);
// t_stack ft_back_front(t_stack **stack, int i);
// t_stack *ft_add_back(t_stack *stack, int i);
// t_stack	*ft_stacklast(t_stack **stack);
t_stack *ft_add_back(t_stack *stack, int i);

// for sort

// commmand allowed

void ft_swap(t_stack  **stack);
void ft_push(t_stack **stack,t_stack **dest);
void r_reverse(t_stack **stack);
void print_stack(t_stack **stack);
void rotate(t_stack **stack);

void	do_ra(t_stack **stack_a);
void    do_rb(t_stack  **stack_b);
void    do_rr(t_stack   **stack_a, t_stack **stack_b);

void    do_pa(t_stack   **stack_b, t_stack **stack_a);
void    do_pb(t_stack   **stack_a, t_stack **stack_b);


void    do_rra(t_stack  **stack_a);
void    do_rrb(t_stack  **stack_b);
void    do_rrr(t_stack **stack_a, t_stack **stack_b);

void    do_sa(t_stack   **stack_a);
void    do_sb(t_stack   **stack_b);
void    do_ss(t_stack   **stack_a, t_stack  **stack_b);


#endif