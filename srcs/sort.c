/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:52:14 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/07 12:47:22 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_getless(t_stack *a, long val)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < a->top)
	{
		if (a->items[i] < val)
			count++;
		i++;
	}
	return (count);
}

long	ft_getmax(t_stack *stack)
{
	int		i;
	long	max;

	i = 0;
	max = *stack->items;
	while (i < stack->top)
	{
		if (stack->items[i] > max)
			max = stack->items[i];
		i++;
	}
	return (max);
}

int	ft_getmaxindex(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->items[i] == ft_getmax(stack))
			return (i);
		i++;
	}
	return (0);
}

int	ft_getclosestindex(t_stack *stack, long val)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->items[i] < val)
			return (i);
		i++;
	}
	return (0);
}

int	ft_getchunk(t_stack *stack)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < stack->top)
	{
		j = 0;
		while (j < stack->top)
		{
			if (stack->items[i] > stack->items[j])
				count++;
			j++;
		}
		if (count == stack->top / 4 + 1)
			return (i);
		count = 0;
		i++;
	}
	return (0);
}


int	ft_loadb(t_stack *a, t_stack *b)
{
	long	pivot;

	while (a->top >= 2)
	{
		pivot = a->items[ft_getchunk(a)];
		while (a->top > a->top - ft_getless(a, pivot))
		{
			if (*a->items < pivot)
			{
				if (ft_push(b, *a->items) || ft_pop(a) == ERR)
					return (1);
				ft_putendl_fd("pb", 1);
			}
			else
			{
				if (ft_getclosestindex(a, pivot) < a->top / 2 - 1)
				{
					if (ft_rotate(a, 0))
						return (1);
					ft_putendl_fd("ra", 1);
				}
				else
				{
					if (ft_rotate(a, 1))
						return (1);
					ft_putendl_fd("rra", 1);
				}
			}
		}
	}
	return (0);
}

int	ft_sortstack(t_stack *a, t_stack *b)
{
	if (ft_loadb(a, b))
		return (1);
	while (b->top > 0)
	{
		while (*b->items != ft_getmax(b))
		{
			if (ft_getmaxindex(b) > b->top / 2 - 1)
			{
				if (ft_rotate(b, 1))
					return (1);
				ft_putendl_fd("rrb", 1);
			}
			else
			{
				if (ft_rotate(b, 0))
					return (1);
				ft_putendl_fd("rb", 1);
			}
		}
		if (ft_push(a, *b->items) || ft_pop(b) == ERR)
			return (1);
		ft_putendl_fd("pa", 1);
	}
	return (0);
}
