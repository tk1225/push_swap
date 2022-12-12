/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:20:33 by takuokam          #+#    #+#             */
/*   Updated: 2022/12/03 17:30:28 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (un_s1[i] != '\0' && un_s2[i] != '\0' && i < n)
	{
		if (un_s1[i] != un_s2[i])
			return (un_s1[i] - un_s2[i]);
		i++;
	}
	if (i != n)
		return (un_s1[i] - un_s2[i]);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
	return ;
}

int	ft_overflow_checker(const char *str, long res, int i, int minus)
{
	if (minus == 0)
	{
		if (((res > INT_MAX / 10) && (str[i + 1] != '\0')) || \
		((res == INT_MAX / 10) && (str[i + 1] >= '8')))
			return (1);
	}
	else
	{
		if (((res > INT_MAX / 10) && (str[i + 1] != '\0')) || \
		((res == INT_MAX / 10) && (str[i + 1] >= '9')))
			return (-1);
	}
	return (0);
}

static	int	ft_atoi_helper(const char *str, long res, int i, int minus)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res + str[i] - '0';
		if (ft_overflow_checker(str, res, i, minus) == 1)
			return ((int)LONG_MAX);
		else if (ft_overflow_checker(str, res, i, minus) == -1)
			return ((int)LONG_MIN);
		res *= 10;
		i++;
	}
	res /= 10;
	if (minus == 1)
		res = -res;
	return (res);
}

int	ft_atoi(const char *str)
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
	{
		if (str[i] == '-')
			minus ++;
		i++;
	}
	return (ft_atoi_helper(str, res, i, minus));
}
