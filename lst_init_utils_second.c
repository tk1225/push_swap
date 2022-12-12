/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init_utils_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:12:28 by takuokam          #+#    #+#             */
/*   Updated: 2022/12/02 21:21:44 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_checker_helper(const char *str, long res, int i, int minus)
{
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (ERROR);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res + str[i] - '0';
		if (ft_overflow_checker(str, res, i, minus) == 1)
			return (ERROR);
		else if (ft_overflow_checker(str, res, i, minus) == -1)
			return (ERROR);
		res *= 10;
		i++;
	}
	return (SUCCESS);
}

int	ft_error_check(const char	*str)
{
	int		i;
	long	res;
	int		minus;

	i = 0;
	res = 0;
	minus = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i ++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = ft_checker_helper(str, res, i, minus);
	if (res == ERROR)
		return (ERROR);
	return (SUCCESS);
}
