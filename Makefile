# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:31:13 by takuokam          #+#    #+#              #
#    Updated: 2022/12/03 16:59:39 by takuokam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
B_NAME := checker
FUNC	:= push_swap libft_utils lst_init_utils lst_init_utils_second lst_proc_utils lst_recursive_utils_a lst_recursive_utils_b lst_treat_lower_case lst_utils lst_utils_second
B_FUNC	:= checker get_next_line get_next_line_utils libft_utils lst_init_utils lst_init_utils_second lst_proc_utils lst_utils lst_utils_second
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
SRCS	:= $(addsuffix .c, $(FUNC))
B_SRCS	:= $(addsuffix _bonus.c, $(B_FUNC))
OBJS	:= $(addsuffix .o, $(FUNC))
B_OBJS	:= $(addsuffix _bonus.o, $(B_FUNC))

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(B_NAME):$(B_OBJS)
	$(CC) $(CFLAGS) $(B_SRCS) -o $(B_NAME)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)
	
bonus: $(B_NAME)

re: fclean all

.PHONY:	all clean fclean re
