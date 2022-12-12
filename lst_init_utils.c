/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:59:19 by takumasaoka       #+#    #+#             */
/*   Updated: 2022/12/03 17:19:25 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(int target[], int left, int right)
{
	int	left_i;
	int	right_i;
	int	pivot;

	left_i = left;
	right_i = right;
	pivot = target[(left + right) / 2];
	while (1)
	{
		while (target[left_i] < pivot)
			left_i++;
		while (pivot < target[right_i])
			right_i--;
		if (left_i >= right_i)
			break ;
		swap(&target[left_i], &target[right_i]);
		left_i++;
		right_i--;
	}
	if (left < left_i - 1)
		quick_sort(target, left, left_i - 1);
	if (right_i + 1 < right)
		quick_sort(target, right_i + 1, right);
}

void	stack_init(t_list **stack, int tar_list[], int sor_list[], int list_len)
{
	t_list	*last_stack;
	t_list	*head;
	t_list	*nil_stack;
	t_list	*new_stack;
	int		i;

	i = 0;
	while (i < list_len)
	{
		new_stack = ft_lstnew(tar_list[i], (void *)"flag");
		new_stack->destloc = \
		search_intlist(sor_list, tar_list[i], list_len);
		ft_lstadd_back(stack, new_stack);
		i++;
	}
	head = *stack;
	last_stack = ft_lstlast(*stack);
	nil_stack = ft_lstnew(0, NULL);
	last_stack->next = nil_stack;
	nil_stack->next = head;
	nil_stack->before = last_stack;
	head->before = nil_stack;
}

int	duplicate_cheaker(int arg_int_sorted[], int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (arg_int_sorted[i] == arg_int_sorted[i + 1])
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	func_init(int argc, char *args[], t_list **a_stack, t_list **b_stack)
{
	int		*arg_int;
	int		*arg_int_sorted;
	int		i;

	arg_int = (int *)malloc(sizeof(int) * (argc - 1));
	arg_int_sorted = (int *)malloc(sizeof(int) * (argc - 1));
	if (arg_int == NULL || arg_int_sorted == NULL)
		exit(1);
	i = 0;
	while (i < argc - 1)
	{	
		if (ft_error_check(args[i + 1]) == ERROR)
			return (ERROR);
		arg_int[i] = ft_atoi(args[i + 1]);
		arg_int_sorted[i] = arg_int[i];
		i++;
	}
	quick_sort(arg_int_sorted, 0, argc - 2);
	if (duplicate_cheaker(arg_int_sorted, argc - 2) == ERROR)
		return (ERROR);
	stack_init(a_stack, arg_int, arg_int_sorted, argc - 1);
	ft_lstadd_back(b_stack, ft_lstnew(0, NULL));
	b_stack[0]->before = b_stack[0];
	b_stack[0]->next = b_stack[0];
	return (SUCCESS);
}
