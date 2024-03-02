/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:39:15 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/02 19:02:06 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **join_arg_solo(int ac, char **av)
{
    char **tab;
    if (ac > 2)
        return(av);
    tab = ft_split(av[1], ' ');
    return(tab);
}

int main (int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if(argc < 2)
        return(0);
    if(argc > 2)
        join_arg_solo(argc, argv);

    if(!ft_parsing(argv, &stack_a))
    {
        printf("Error swap\n");
        return(0);
    }
    else 
        printf("OK\n");
    // stack_a = ft_parsing(argv, &stack_a);
    printf("OK\n");
    print_stack(&stack_a);
    printf("\n\n");
    // rotate(&stack_a);
    // r_reverse(&stack_a);
    // ft_swap(&stack_a);
    // do_pa(&stack_a,&stack_b);
    print_stack(&stack_a);
    // printf("\n");
    // print_stack(&stack_b);
    // do_pa(&stack_b,&stack_a);
    // print_stack(&stack_a);
    // printf("\n");
    // print_stack(&stack_b);

    return (0);
}
