/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:28:28 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/24 15:07:29 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ERR 2147482648
# include "libft.h"
# include "stdlib.h"

typedef struct s_stack
{
	int		top;
	long	*items;
}	t_stack;
// stack.c
t_stack	*ft_initstack(void);
int		ft_push(t_stack *stack, long topush);
int		ft_pushbot(t_stack *stack, long topush);
long	ft_pop(t_stack *stack);
long	ft_popbot(t_stack *stack);
// stackop.c
void	ft_freestack(t_stack *stack);
void	ft_swap(t_stack *stack);
int		ft_rotate(t_stack *stack, int isreverse);
// parse.c
int		ft_loadstack(t_stack *stack, char **av);
// sort.c
int		ft_issorted(t_stack *a);
int		ft_sortstack(t_stack *a, t_stack *b);
// sortsmallest.c
int		ft_sort2(t_stack *a);
int		ft_sort3(t_stack *a);
// sortsmall.c
int		ft_selectionsort(t_stack *a, t_stack *b, int ismall);
// costsort.c
int		ft_costsort(t_stack *a, t_stack *b);
// utils.c
long	ft_getmax(t_stack *stack);
long	ft_getmin(t_stack *stack);
int		ft_puttotop(t_stack *stack, long val, int isa);
int		ft_getindex(t_stack *stack, long val);
int		ft_putbothtotop(t_stack *a, t_stack *b, long topush, long toput);
#endif
