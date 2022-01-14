/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:18:11 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/14 17:22:30 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_haschunk(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->items[i] >= min && a->items[i] <= max)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_getclosestchunk(t_stack *stack, long min, long max)
{
	int	i;
	int	j;

	i = 0;
	j = stack->top - 1;
	while (!(stack->items[i] >= min && stack->items[i] <= max))
		i++;
	while (!(stack->items[i] >= min && stack->items[i] <= max))
		j--;
	if (i > stack->top - j)
		return (j);
	else
		return (i);
}

 int	ft_pushchunk(t_stack *a, t_stack *b, int chunk, int chunknum)
{
	int	max;
	int	min;

	max = (a->top + b->top) - ((chunknum - chunk) * (a->top + b->top) / chunknum);
	min = max - (a->top + b->top) / chunknum;
	while (ft_haschunk(a, min, max))
	{
		while (!(*a->items >= min && *a->items <= max))
		{
			if (ft_getclosestchunk(a, min, max) > a->top / 2)
			{
				if (ft_rotate(a, 1))
					return (1);
				ft_putendl_fd("rra", 1);
			}
			else
			{
				if (ft_rotate(a, 0))
					return (1);
				ft_putendl_fd("ra", 1);
			}
		}
		if (ft_push(b, *a->items) || ft_pop(a) == ERR)
			return (1);
		ft_putendl_fd("pb", 1);
	}
	return (0);
}
