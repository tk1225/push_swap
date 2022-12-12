/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_recursive_utils_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:46:11 by takumasaoka       #+#    #+#             */
/*   Updated: 2022/12/01 21:30:51 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	b_checker(t_list **a_stack, t_list **b_stack, int range, int max)
{
	if (ft_lst_cheak_sorting_dec(*b_stack, range, max) == 0)
	{
		while (range > 0)
		{
			ft_lst_pa_pb(b_stack, a_stack, 'a', 1);
			range--;
		}
		return (RETURN);
	}
	return (CONTINUE);
}

static void	b_helper(t_list **a_stack, t_list **b_stack, int range, int med)
{
	while (range > 0)
	{
		if ((b_stack[0]->destloc == a_stack[0]->before->before->destloc + 1 \
		&& a_stack[0]->before->sorted == 1) || (b_stack[0]->destloc == 0))
		{
			b_stack[0]->sorted = 1;
			if (b_stack[0]->destloc == 0)
				a_stack[0]->before->sorted = 1;
			ft_lst_pa_pb(b_stack, a_stack, 'a', 1);
			ft_lst_ra_rb(a_stack, 'a', 1);
			range--;
		}
		if (range <= 0)
			break ;
		if (b_stack[0]->destloc > med)
			ft_lst_pa_pb(b_stack, a_stack, 'a', 1);
		else
			ft_lst_ra_rb(b_stack, 'b', 1);
		range--;
	}
}

void	st_b_quick_sort(t_list **a_stack, t_list **b_stack, int min, int max)
{
	int	med;
	int	range;
	int	a_bottom;

	med = min + (max - min) / 2;
	range = max - min + 1;
	a_bottom = 0;
	if (b_checker(a_stack, b_stack, range, max) == RETURN)
		return ;
	b_helper(a_stack, b_stack, range, med);
	if (a_stack[0]->before->sorted == 1)
		a_bottom = a_stack[0]->before->before->destloc + 1;
	if (med - ft_max(a_bottom, min) >= 0)
		st_b_quick_sort(a_stack, b_stack, ft_max(a_bottom, min), med);
	if (max - ft_max(a_bottom, med + 1) >= 0)
		st_a_quick_sort(a_stack, b_stack, ft_max(a_bottom, med + 1), max);
	if (med - ft_max(a_bottom, min) < 0)
	{
		while (b_stack[0]->destloc != -1)
			ft_lst_pa_pb(b_stack, a_stack, 'a', 1);
	}
}
