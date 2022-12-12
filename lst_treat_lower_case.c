/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_treat_lower_case.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:46:03 by takumasaoka       #+#    #+#             */
/*   Updated: 2022/12/12 17:10:06 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	treat_case_three(t_list **a_stack, t_list **b_stack)
{
	(void) b_stack;
	ft_lst_sa_sb(a_stack, 'a', 1);
	ft_lst_ra_rb(a_stack, 'a', 1);
	ft_lst_sa_sb(a_stack, 'a', 1);
	ft_lst_rra_rrb(a_stack, 'a', 1);
}

static void	treat_case_five(t_list **a_stack, t_list **b_stack)
{
	(void) b_stack;
	ft_lst_ra_rb(a_stack, 'a', 1);
	ft_lst_sa_sb(a_stack, 'a', 1);
	ft_lst_rra_rrb(a_stack, 'a', 1);
	ft_lst_sa_sb(a_stack, 'a', 1);
}

void	treat_three_stack(t_list **a_stack, t_list **b_stack)
{
	int	head_diff;
	int	second_diff;

	head_diff = a_stack[0]->destloc - a_stack[0]->next->destloc;
	second_diff = a_stack[0]->next->destloc - a_stack[0]->next->next->destloc;
	if (head_diff == 1 && second_diff == -2)
		ft_lst_sa_sb(a_stack, 'a', 1);
	else if (head_diff == 1 && second_diff == 1)
	{
		ft_lst_sa_sb(a_stack, 'a', 1);
		treat_case_five(a_stack, b_stack);
	}
	else if (head_diff == 2 && second_diff == -1)
		treat_case_three(a_stack, b_stack);
	else if (head_diff == -2 && second_diff == 1)
	{
		ft_lst_pa_pb(a_stack, b_stack, 'b', 1);
		ft_lst_sa_sb(a_stack, 'a', 1);
		ft_lst_pa_pb(b_stack, a_stack, 'a', 1);
	}
	else if (head_diff == -1 && second_diff == 2)
		treat_case_five(a_stack, b_stack);
}

void	treat_only_undersix(int argc, t_list **a_stack, t_list **b_stack)
{
	int		smallest;

	smallest = 0;
	if (ft_lst_cheak_sorting_asc(a_stack[0], ft_lstsize(a_stack[0]), 0) == 0)
		return ;
	while (argc-- >= 5)
	{
		if (a_stack[0]->before->before->destloc == smallest)
			ft_lst_rra_rrb(a_stack, 'a', 1);
		while (a_stack[0]->destloc != smallest)
			ft_lst_ra_rb(a_stack, 'a', 1);
		ft_lst_pa_pb(a_stack, b_stack, 'b', 1);
		smallest++;
	}
	treat_only_three_stack(a_stack, b_stack);
	while (b_stack[0]->destloc != -1)
		ft_lst_pa_pb(b_stack, a_stack, 'a', 1);
}

void	treat_only_three_stack(t_list **a_stack, t_list **b_stack)
{
	int		head;
	int		second;
	int		third;

	(void) b_stack;
	head = a_stack[0]->destloc;
	second = a_stack[0]->next->destloc;
	third = a_stack[0]->next->next->destloc;
	if (head > second && head < third)
		ft_lst_sa_sb(a_stack, 'a', 1);
	else if (head > second && second > third)
	{
		ft_lst_sa_sb(a_stack, 'a', 1);
		ft_lst_rra_rrb(a_stack, 'a', 1);
	}
	else if (third > second && head > third)
		ft_lst_ra_rb(a_stack, 'a', 1);
	else if (head < third && second > third)
	{
		ft_lst_sa_sb(a_stack, 'a', 1);
		ft_lst_ra_rb(a_stack, 'a', 1);
	}
	else if (head < second && head > third)
		ft_lst_rra_rrb(a_stack, 'a', 1);
}
