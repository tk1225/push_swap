/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utls_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:30:27 by takumasaoka       #+#    #+#             */
/*   Updated: 2022/12/02 21:22:41 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_cheak_sorting_dec(t_list *stack, int len, int loc)
{
	int	diff;

	diff = 0;
	while (stack->flag && len)
	{
		diff += abs(stack->destloc - loc);
		loc --;
		stack = stack->next;
		len--;
	}
	return (diff);
}

int	ft_lst_cheak_sorting_asc(t_list *stack, int len, int loc)
{
	int	diff;

	diff = 0;
	while (stack->flag && len)
	{
		diff += abs(stack->destloc - loc);
		loc ++;
		stack = stack->next;
		len--;
	}
	return (diff);
}

int	search_intlist(int target[], int num, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (target[i] == num)
			return (i);
		i++;
	}
	return (-1);
}
