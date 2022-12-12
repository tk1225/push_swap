/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_recursive_utils_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:30:22 by takumasaoka       #+#    #+#             */
/*   Updated: 2022/12/02 22:22:34 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static int	a_checker(t_list **a_stack, t_list **b_stack, int range, int min)
{
	if (ft_lst_cheak_sorting_asc(*a_stack, range, min) == 0)
		return (RETURN);
	if (ft_lst_cheak_sorting_asc(*a_stack, range, min) == 2)
	{
		while (a_stack[0]->destloc == min++)
			ft_lst_ra_rb(a_stack, 'a', 1);
		ft_lst_sa_sb(a_stack, 'a', 1);
		return (RETURN);
	}
	if (range == 2)
	{
		if (a_stack[0]->destloc - a_stack[0]->next->destloc == 1)
			ft_lst_sa_sb(a_stack, 'a', 1);
		return (RETURN);
	}
	if (range == 3)
	{
		treat_three_stack(a_stack, b_stack);
		return (RETURN);
	}
	return (CONTINUE);
}

static int	a_treat_sorted(t_list **a_stack, t_list **b_stack)
{
	(void) b_stack;
	if (a_stack[0]->before->before->sorted == 1 && \
		a_stack[0]->before->before->destloc + 1 == a_stack[0]->destloc)
	{
		a_stack[0]->sorted = 1;
		ft_lst_ra_rb(a_stack, 'a', 1);
		return (ROTATE_A);
	}
	return (PASS);
}

static void	a_helper(t_list **a_stack, t_list **b_stack, int max, int min)
{
	int	count_push;
	int	under_num_c;
	int	range;

	range = max - min + 1;
	under_num_c = (max - min) / 3 * 2 + 1;
	count_push = 0;
	while (range-- && under_num_c)
	{
		if (a_stack[0]->destloc <= min + (max - min) / 3 * 2)
				under_num_c--;
		if (a_treat_sorted(a_stack, b_stack) == ROTATE_A)
		{
		}
		else if (a_stack[0]->destloc <= min + (max - min) / 3 * 2)
			ft_lst_pa_pb(a_stack, b_stack, 'b', 1);
		else
		{
			ft_lst_ra_rb(a_stack, 'a', 1);
			count_push++;
		}
	}
	if (a_stack[0]->before->sorted == 1)
		while (a_stack[0]->before->before->sorted != 1 && count_push--)
			ft_lst_rra_rrb(a_stack, 'a', 1);
}

void	st_a_quick_sort(t_list **a_stack, t_list **b_stack, int min, int max)
{
	int	med;
	int	range;
	int	med_med;
	int	a_bottom;

	med = min + (max - min) / 3 * 2;
	range = max - min + 1;
	while ((a_stack[0]->destloc < min) || (a_stack[0]->destloc > max))
	{
		if (a_stack[0]->before->before->sorted == 1 && \
		a_stack[0]->before->before->destloc + 1 == a_stack[0]->destloc)
			a_stack[0]->sorted = 1;
		ft_lst_ra_rb(a_stack, 'a', 1);
	}
	if (a_checker(a_stack, b_stack, range, min) == RETURN)
		return ;
	a_helper(a_stack, b_stack, max, min);
	med_med = (med + min) / 2;
	a_bottom = 0;
	if (a_stack[0]->before->sorted == 1)
		a_bottom = a_stack[0]->before->before->destloc + 1;
	st_b_quick_sort(a_stack, b_stack, ft_max(a_bottom, min), med);
	if (max - med - 1 >= 1 && max - a_bottom >= 1)
		st_a_quick_sort(a_stack, b_stack, ft_max(a_bottom, med + 1), max);
}
