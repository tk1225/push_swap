/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:30:32 by takumasaoka       #+#    #+#             */
/*   Updated: 2022/12/02 21:34:34 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define SUCCESS 0
# define ERROR 1
# define RETURN 2
# define CONTINUE 3
# define ROTATE_A 4
# define ROTATE_B 5
# define PASS 	6

typedef struct s_list
{
	void			*flag;
	int				num;
	struct s_list	*next;
	struct s_list	*before;
	int				destloc;
	int				sorted;
}	t_list;

int				ft_atoi(const char *str);
int				search_intlist(int target[], int num, int length);
t_list			*ft_lstnew(int number, void *flag);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lst_swap(t_list *first, t_list *second);
void			ft_lst_sa_sb(t_list **stack, char type, int output);
void			ft_lst_ra_rb(t_list **stack, char type, int output);
void			ft_lst_rra_rrb(t_list **stack, char type, int output);
void			ft_lst_pa_pb(t_list **st_from, \
t_list **st_to, char type, int output);
void			ft_putstr_fd(char *s, int fd);
void			st_a_quick_sort(t_list **a_stack, \
t_list **b_stack, int min, int max);
void			st_b_quick_sort(t_list **a_stack, \
t_list **b_stack, int min, int max);
void			show_stack(t_list *stack);
int				abs(int num);
int				ft_lst_cheak_sorting_asc(t_list *stack, int len, int loc);
int				ft_lst_cheak_sorting_dec(t_list *stack, int len, int loc);
void			ft_putnbr_fd(int n, int fd);
void			treat_only_three_stack(t_list **a_stack, t_list **b_stack);
void			stack_init(t_list **stack, \
int targetlist[], int sortinglist[], int list_length);
int				ft_max(int a, int b);
void			treat_three_stack(t_list **a_stack, t_list **b_stack);
void			treat_only_undersix(int argc, \
t_list **a_stack, t_list **b_stack);
char			*get_next_line(int fd);
size_t			ft_strlen(const char *target);
long long int	ft_strchr_len(const char *s, int c);
char			*ft_strjoin_bf_newline(char const *s1, char const *s2);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strdup(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			quick_sort(int target[], int left, int right);
int				func_init(int argc, char *args[], \
t_list **a_stack, t_list **b_stack);
int				ft_overflow_checker(const char *str, \
long res, int i, int minus);
int				ft_error_check(const char	*str);

#endif