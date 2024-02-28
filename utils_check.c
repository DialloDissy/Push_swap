/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:12:19 by sidiallo          #+#    #+#             */
/*   Updated: 2024/02/27 20:11:19 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issign(int c)
{
	return(c == '+' || c == '-');
}


long long	ft_atoi_swap(const char *nptr, int *pos)
{
	long long	i;
	long long	sign;
	long long	res;

	i = *pos;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10 + nptr[i] - '0');
		if (res > 2147483647 )
			return(2147483650);
		i++;
	}
	res =  res * sign;
	if (res > 2147483647 || res < -2147483648 || ft_issign(nptr[i]))
			return(2147483650);
	return (*pos = i, res);
}

