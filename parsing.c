/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:39:19 by sidiallo          #+#    #+#             */
/*   Updated: 2024/02/28 18:38:45 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_digit(char **av)
{
    int i;

    i = 1;
    while (av[i])
    {
        int j = 0;
        while (av[i][j])
        {
            if (!ft_isdigit(av[i][j]) && !ft_issign(av[i][j]) && av[i][j] != ' ')
            {
                printf("fail digit");
                return(0);
            }
            j++;
        }
        i++;
    }
    return(1);

}


// int ft_duplicate(char **av)
// {
//     int i;

//     i = 1;
//     while (av[i])
//     {
//         if (ft_atoi_swap(av[i]) > 2147483647 || ft_atoi_swap(av[i]) < -2147483648)
//             return(0);
//         i++;
//     }
//     i = 1;
//     while (av[i])
//     {
//         int j = i + 1;
//         while (av[j])
//         {
//            if (ft_atoi_swap(av[i]) == ft_atoi_swap(av[j]))
//            {
//                 // printf("fails");
//                 return(0);
//            }
//             j++;
//         }
//         i++;
//     }
//     return (1);
// }

    t_stack  *ft_get_number(char *av,t_stack *stack)
{
    int i;
	long long n;
	
	i = 0;
    while (av[i])
    {
        n = ft_atoi_swap(av,&i);
        if (n > 2147483647 || n < -2147483648)
            return(NULL);
        while (av[i] == ' ' || (av[i] >= 9 && av[i] <= 13))
            i++;
    }
    i = 0;
    if (stack == NULL)
        stack =list_new((int)ft_atoi_swap(av,&i));
     while (av[i])
    {
        n = ft_atoi_swap(av, &i);
        if (check_duplicate(stack, n))
            exit(EXIT_FAILURE);
        stack = ft_back_front(stack, n);
        while (av[i] == ' ' || (av[i] >= 9 && av[i] <= 13))
            i++;
    }
    return(stack);
}


// int ft_parsing(char **argv, t_stack **stack )
// {
//     int i;
    
//     i = 1;
//     if (ft_check_digit(argv) == 0)
//         return(0);
//     while(argv[i])
//     {
//         stack = ft_get_number(argv[i], stack );
//         printf("%d ",(*stack)->value);

//         if(!stack)
//             return(0);
//         i++;
//     }
//     printf("%d ",(*stack)->value);
//     return(1);
// }

t_stack *ft_parsing(char **argv, t_stack **stack )
{
    int i;

    i = 1;
    if (ft_check_digit(argv) == 0)
        return(0);
    while(argv[i])
    {
        *stack = ft_get_number(argv[i], *stack );

        if(!(*stack))
            return(0);
        i++;
    }
    return(*stack);
}

