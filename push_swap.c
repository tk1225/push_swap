/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:30:29 by takumasaoka       #+#    #+#             */
/*   Updated: 2022/12/12 17:02:37 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *args[])
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
	if (argc <= 6)
	{
		treat_only_undersix(argc, &a_stack, &b_stack);
		return (0);
	}
	st_a_quick_sort(&a_stack, &b_stack, 0, ft_lstsize(a_stack) - 1);
	while (a_stack->destloc != 0)
		ft_lst_ra_rb(&a_stack, 'a', 1);
	ft_lstclear(&a_stack, free);
	ft_lstclear(&b_stack, free);
	return (0);
}

// void show_stack(t_list *stack)
// {
//     int i;
//     printf("stack:\n%s","");
//     i = 0;
//     while(stack->flag)
//     {
//         printf("before%d:",stack->before->num);
//         printf("here%d:",stack->num);
//         printf("loc%d:",stack->destloc);
//         printf("next%d:\n",stack->next->num);
//         stack = stack->next;
//     }
//     printf("before%d:",stack->before->num);
//     printf("here%d:",stack->num);
//     printf("next%d:\n",stack->next->num);
//     printf("fin%s\n","");
// }

// t_list *stack_cp(t_list *base_stack)
// {
//     t_list *last_stack;
//     t_list *head;
//     t_list *nil_stack;
//     t_list *res_stack;
//     t_list *new_stack;

//     res_stack = NULL;
//     while (base_stack->flag != NULL)
//     {
//         new_stack =  ft_lstnew(base_stack->num, (void *)"flag");
//         new_stack->destloc = base_stack->destloc;
//         ft_lstadd_back(&res_stack, new_stack);
//         base_stack = base_stack->next;
//     }
//     head = res_stack;
//     last_stack = ft_lstlast(head);
//     nil_stack = ft_lstnew(0, NULL);
//     last_stack->next = nil_stack;
//     nil_stack->next = head;
//     nil_stack->before = last_stack;
//     head->before = nil_stack;
//     return (res_stack);
// }