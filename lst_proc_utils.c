/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_proc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:22:33 by takumasaoka       #+#    #+#             */
/*   Updated: 2022/12/01 22:40:32 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_swap(t_list *first, t_list *second)
{
	t_list	*zero;
	t_list	*third;

	zero = first->before;
	third = second->next;
	first->before = second;
	second->next = first;
	first->next = third;
	third->before = first;
	zero->next = second;
	second->before = zero;
}
//sa -> 先頭２つ逆転

void	ft_lst_sa_sb(t_list **stack, char type, int output)
{
	t_list	*head;
	t_list	*second;

	head = *stack;
	if (head == NULL || head->next == NULL)
		return ;
	if (ft_lstsize(*stack) == 0)
		return ;
	second = head->next;
	*stack = second;
	ft_lst_swap(head, second);
	if (output == 0)
		return ;
	if (type == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}
//ra -> 上方向回転

void	ft_lst_ra_rb(t_list **stack, char type, int output)
{
	t_list	*nullnode;
	t_list	*head;
	t_list	*second;

	head = *stack;
	if (head == NULL || head->next == NULL)
		return ;
	if (ft_lstsize(*stack) == 1)
		return ;
	nullnode = head->before;
	second = head->next;
	*stack = second;
	ft_lst_swap(nullnode, head);
	if (output == 0)
		return ;
	if (type == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
	return ;
}
//ra -> 下方向回転

void	ft_lst_rra_rrb(t_list **stack, char type, int output)
{
	t_list	*nullnode;
	t_list	*head;
	t_list	*lastnode;

	head = *stack;
	if (head == NULL || head->next == NULL)
		return ;
	nullnode = head->before;
	lastnode = nullnode->before;
	*stack = lastnode;
	ft_lst_swap(lastnode, nullnode);
	if (output == 0)
		return ;
	if (type == 'a')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
	return ;
}
//pa -> push

void	ft_lst_pa_pb(t_list **st_from, t_list **st_to, char type, int output)
{
	t_list	*head_from;
	t_list	*head_from_nullnode;
	t_list	*head_to;
	t_list	*head_to_nullnode;

	if (*st_from == NULL || *st_to == NULL)
		return ;
	if (ft_lstsize(*st_from) == 0)
		return ;
	head_from = *st_from;
	head_to = *st_to;
	head_from_nullnode = head_from->before;
	head_from_nullnode->next = head_from->next;
	head_from->next->before = head_from_nullnode;
	*st_from = head_from->next;
	*st_to = head_from;
	head_to_nullnode = head_to->before;
	head_from->before = head_to_nullnode;
	head_to_nullnode->next = head_from;
	head_from->next = head_to;
	head_to->before = head_from;
	if (type == 'a' && output == 1)
		ft_putstr_fd("pa\n", 1);
	else if (output == 1)
		ft_putstr_fd("pb\n", 1);
}
