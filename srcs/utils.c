/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:49:14 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/20 12:26:41 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_getindex(t_stack *stack, long val)
{
	int	i;

	i = 0;
	while (stack->items[i] != val)
		i++;
	return (i);
}

long	ft_getmax(t_stack *stack)
{
	int		i;
	long	max;

	max = *stack->items;
	i = 1;
	while (i < stack->top)
	{
		if (stack->items[i] > max)
			max = stack->items[i];
		i++;
	}
	return (max);
}

long	ft_getmin(t_stack *stack)
{
	int		i;
	long	min;

	min = *stack->items;
	i = 1;
	while (i < stack->top)
	{
		if (stack->items[i] < min)
			min = stack->items[i];
		i++;
	}
	return (min);
}

int	ft_puttotop(t_stack *stack, long val, int isa)
{
	while (*stack->items != val)
	{
		if (ft_getindex(stack, val) > stack->top / 2)
		{
			if (ft_rotate(stack, 1))
				return (1);
			if (isa)
				ft_putendl_fd("rra", 1);
			else
				ft_putendl_fd("rrb", 1);
		}
		else
		{
			if (ft_rotate(stack, 0))
				return (1);
			if (isa)
				ft_putendl_fd("ra", 1);
			else
				ft_putendl_fd("rb", 1);
		}
	}
	return (0);
}

int	ft_putbothtotop(t_stack *a, t_stack *b, long topush, long toput)
{
	while (*a->items != topush)
	{
		if (*b->items != toput)
		{
			if (ft_getindex(a, topush) > a->top / 2)
			{
				if (ft_rotate(a, 1) || ft_rotate(b, 1))
					return (1);
				ft_putendl_fd("rrr", 1);
			}
			else
			{
				if (ft_rotate(a, 0) || ft_rotate(b, 0))
					return (1);
				ft_putendl_fd("rr", 1);
			}
		}
		else
		{
			if (ft_puttotop(a, topush, 1))
				return (1);
		}
	}
	return (0);
}
