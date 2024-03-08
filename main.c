/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:39:15 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/07 19:47:11 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **join_arg_solo(int ac, char **av)
{
	char **tab;

	if (ac > 2)
	{
		tab = av;
		av++;
		return(av);
	}	
	tab = ft_split(av[1], ' ');
	return(tab);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char **arg;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	arg = join_arg_solo(argc,argv);
	if (!ft_parsing(arg, &stack_a))
	{   
		if (argc == 2)
			ft_forfree_init(arg, argc);
		if(stack_a)
			free_stack(&stack_a);
		printf("Error\n");
		return (0);
	}
	if (!is_sorted(stack_a))
	{
		sort(&stack_a, &stack_b);
		free_stack(&stack_a);
		if(argc == 2)
			ft_forfree_init(arg, argc);
	}
	return (0);
}
