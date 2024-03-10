/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:39:10 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/10 18:22:55 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;

	struct s_stack	*next;
	struct s_stack	*target;

}					t_stack;

// parsing

t_stack				*ft_parsing(char **argv, t_stack **stack);
int					ft_issign(int c);
long long			ft_atoi_swap(const char *nptr, int *pos);
long long			ft_atoi_sign(const char *nptr, int *pos);
int					ft_check_digit(char **av);
int					check_duplicate(t_stack *stack_a, int nbr);
t_stack				*ft_get_number(char *av, t_stack *stack);
char				**join_arg_solo(int ac, char **av);

t_stack				*list_new(int value);
t_stack				*ft_add_back(t_stack *stack, int i);
void				free_stack(t_stack **stack);
void				ft_forfree_init(char **strf, int i);

// for sort

// commmand allowed

void				ft_swap(t_stack **stack);
void				ft_push(t_stack **stack, t_stack **dest);
void				r_reverse(t_stack **stack);
void				print_stack(t_stack **stack);
void				rotate(t_stack **stack);

void				do_ra(t_stack **stack_a);
void				do_rb(t_stack **stack_b);
void				do_rr(t_stack **stack_a, t_stack **stack_b);

void				do_pa(t_stack **stack_b, t_stack **stack_a);
void				do_pb(t_stack **stack_a, t_stack **stack_b);

void				do_rra(t_stack **stack_a);
void				do_rrb(t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);

void				do_sa(t_stack **stack_a);
void				do_sb(t_stack **stack_b);
void				do_ss(t_stack **stack_a, t_stack **stack_b);

// sort

void				three_sort(t_stack **node);
bool				is_sorted(t_stack *stack);
int					stack_len(t_stack *stack);
void				sort(t_stack **stack_a, t_stack **stack_b);
t_stack				*find_max(t_stack *stack);
t_stack				*find_min(t_stack *stack);
void				sort_big(t_stack **stack_a, t_stack **stack_b);
void				push_a_into_b(t_stack **stack_a, t_stack **stack_b,
						int median);
void				push_b_into_a(t_stack **stack_a, t_stack **stack_b);
void				cost_b(t_stack *stack_a, t_stack *stack_b);
t_stack				*get_cheapest(t_stack *stack);
void				set_the_top(t_stack **stack_a);
void				refreshing(t_stack *stack_a, t_stack *stack_b);
void				refresh_index(t_stack *stack);
void				refresh_target(t_stack *stack_a, t_stack *stack_b);
void				cost_stack(t_stack *stack_a, t_stack *stack_b);
void				the_cheapest(t_stack *stack_b);
void				set_the_top(t_stack **stack_a);

void				move_both_above_median(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest);
void				move_both_under_median(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest);
void				move_a_above_and_b_below_median(t_stack **stack_a,
						t_stack **stack_b, t_stack *cheapest);
void				move_a_below_and_b_above_median(t_stack **stack_a,
						t_stack **stack_b, t_stack *cheapest);

#endif