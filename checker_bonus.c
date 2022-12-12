/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:35:34 by takumasaoka       #+#    #+#             */
/*   Updated: 2022/12/03 17:11:20 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	checker_helper_a(char *res, t_list **a_stack, t_list **b_stack)
{
	if (ft_strncmp(res, "sa\n", 3) == 0)
	{
		ft_lst_sa_sb(a_stack, 'a', 0);
		return (SUCCESS);
	}
	else if (ft_strncmp(res, "sb\n", 3) == 0)
	{
		ft_lst_sa_sb(b_stack, 'b', 0);
		return (SUCCESS);
	}
	else if (ft_strncmp(res, "ss\n", 3) == 0)
	{
		ft_lst_sa_sb(a_stack, 'a', 0);
		ft_lst_sa_sb(b_stack, 'b', 0);
		return (SUCCESS);
	}
	else if (ft_strncmp(res, "ra\n", 3) == 0)
	{
		ft_lst_ra_rb(a_stack, 'a', 0);
		return (SUCCESS);
	}
	return (ERROR);
}

static int	checker_helper_b(char *res, t_list **a_stack, t_list **b_stack)
{
	if (ft_strncmp(res, "rb\n", 3) == 0)
	{
		ft_lst_ra_rb(b_stack, 'b', 0);
		return (SUCCESS);
	}
	else if (ft_strncmp(res, "rr\n", 3) == 0)
	{
		ft_lst_ra_rb(a_stack, 'a', 0);
		ft_lst_ra_rb(b_stack, 'b', 0);
		return (SUCCESS);
	}
	else if (ft_strncmp(res, "rra\n", 4) == 0)
	{
		ft_lst_rra_rrb(a_stack, 'a', 0);
		return (SUCCESS);
	}
	else if (ft_strncmp(res, "rrb\n", 4) == 0)
	{
		ft_lst_rra_rrb(b_stack, 'b', 0);
		return (SUCCESS);
	}
	return (ERROR);
}

static int	checker_helper_c(char *res, t_list **a_stack, t_list **b_stack)
{
	if (ft_strncmp(res, "rrr\n", 4) == 0)
	{
		ft_lst_rra_rrb(a_stack, 'a', 0);
		ft_lst_rra_rrb(b_stack, 'b', 0);
		return (SUCCESS);
	}
	else if (ft_strncmp(res, "pa\n", 3) == 0)
	{
		ft_lst_pa_pb(b_stack, a_stack, 'a', 0);
		return (SUCCESS);
	}
	else if (ft_strncmp(res, "pb\n", 3) == 0)
	{
		ft_lst_pa_pb(a_stack, b_stack, 'b', 0);
		return (SUCCESS);
	}
	return (ERROR);
}

static int	read_stdinput(t_list **a_stack, t_list **b_stack)
{
	char	*res;

	res = "start";
	while (res != NULL)
	{
		res = get_next_line(0);
		if (res == NULL)
			break ;
		if (checker_helper_a(res, a_stack, b_stack) == ERROR \
		&& checker_helper_b(res, a_stack, b_stack) == ERROR \
		&& checker_helper_c(res, a_stack, b_stack) == ERROR)
		{
			ft_putstr_fd("Error\n", 2);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	main(int argc, char*args[])
{
	t_list	*a_stack;
	t_list	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (argc == 1)
		return (0);
	if (func_init(argc, args, &a_stack, &b_stack) == ERROR)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (read_stdinput(&a_stack, &b_stack) == ERROR)
		return (0);
	if (ft_lst_cheak_sorting_asc(a_stack, argc - 1, 0) \
	== 0 && ft_lstsize(b_stack) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear(&a_stack, free);
	ft_lstclear(&b_stack, free);
	return (0);
}
