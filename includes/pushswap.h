/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:28:28 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/04 15:58:01 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include "libft.h"
# include "stdlib.h"

typedef struct s_stack
{
	int		top;
	long	*items;
} t_stack;
// stack.c
t_stack	*ft_initstack();
int		ft_push(t_stack *stack, long topush);
int		ft_pushbot(t_stack *stack, long topush);
int		ft_pop(t_stack *stack);
int		ft_popbot(t_stack *stack);
// stackop.c
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack,int isreverse);
// parse.c
int	ft_loadstack(t_stack *stack, char **av);
#endif
