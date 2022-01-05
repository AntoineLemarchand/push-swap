/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:52:14 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/05 13:58:00 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_getmin(t_stack *stack)
{
	int		i;
	int		minindex;
	long	min;

	i = 0;
	min = stack->items[i++];
	while (i < stack->top)
	{
		if (stack->items[i] < min)
		{
			min = stack->items[i];
			minindex = i;
		}
		i++;
	}
	return (minindex);
}

int	ft_sortstack(t_stack *a, t_stack *b)
{
	int		i;
	int		minindex;
	long	topush;

	while (a->top > 0)
	{
		i = 0;
		minindex = ft_getmin(a);
		while (i < minindex)
		{
			if (ft_rotate(a, 0) == ERR)
				return (ERR);
			write(1, "ra\n", 3);
			i++;
		}
		topush = ft_pop(a);
		if (topush == ERR || ft_push(b, topush) == ERR)
			return (ERR);
		write(1, "pb\n", 3);
	}
	while (b->top > 0)
	{
		topush = ft_pop(b);
		if (topush == ERR || ft_push(a, topush) == ERR)
			return (ERR);
		write(1, "pa\n", 3);
	}
	return (0);
}
