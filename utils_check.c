/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:12:19 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/10 18:36:49 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issign(int c)
{
	return (c == '+' || c == '-');
}

long long	ft_atoi_sign(const char *nptr, int *pos)
{
	long long	i;
	long long	sign;
	long long	res;

	i = *pos;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	return (*pos = i, sign);
}

long long	ft_atoi_swap(const char *nptr, int *pos)
{
	long long	sign;
	long long	i;
	long long	res;

	sign = ft_atoi_sign(nptr, pos);
	i = *pos;
	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10 + nptr[i] - '0');
		if (res > 2147483648)
			return (2147483650);
		i++;
	}
	res = res * sign;
	if (res > 2147483647 || res < -2147483648 || ft_issign(nptr[i]))
		return (2147483650);
	return (*pos = i, res);
}

void	ft_forfree_init(char **strf, int i)
{
	i = 0;
	while (strf[i])
	{
		free(strf[i]);
		i++;
	}
	free(strf);
}
