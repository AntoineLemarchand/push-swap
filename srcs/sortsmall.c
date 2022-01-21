/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:47:16 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/21 14:24:30 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_sort2(t_stack *a)
{
	if (!ft_issorted(a))
	{
		if (ft_rotate(a, 0))
			return (1);
		ft_putendl_fd("ra", 1);
	}
	return (0);
}

int	ft_sort3(t_stack *a)
{
	long	first;
	long	second;
	long	third;

	first = *a->items;
	second = *(a->items + 1);
	third = *(a->items + 2);
	if (!ft_issorted(a))
	{
		if (first > second && second <= third && third > first)
			ft_putendl_fd("sa", 1);
		else if (first <= second && second > third && third > first)
			ft_putendl_fd("sa\nra", 1);
		else if (first > second && second <= third && third <= first)
			ft_putendl_fd("ra", 1);
		else if (first <= second && second > third && third <= first)
			ft_putendl_fd("rra", 1);
		else
			ft_putendl_fd("sa\nrra", 1);
	}
	return (0);
}

static int	ft_dumpb(t_stack *a, t_stack *b)
{
	while (b->top > 1 && b->items[0] > b->items[1])
	{
		if (ft_push(a, *b->items) || ft_pop(b) == ERR)
			return (1);
		ft_putendl_fd("pa", 1);
	}
	if (ft_push(a, *b->items) || ft_pop(b) == ERR)
		return (1);
	ft_putendl_fd("pa", 1);
	while (b->top)
	{
		if (a->items[a->top - 1] > *b->items 
			&& a->items[a->top - 1] != ft_getmax(a))
		{
			if (ft_rotate(a, 1))
				return (1);
			ft_putendl_fd("rra", 1);
		}
		else
		{
			if (ft_push(a, *b->items) || ft_pop(b) == ERR)
				return (1);
			ft_putendl_fd("pa", 1);
		}
	}
	return (0);
}

int	ft_selectionsort(t_stack *a, t_stack *b, int issmall)
{
	if (b->top && ft_getmax(a) > ft_getmax(b))
	{
		if (ft_puttotop(a, ft_getmax(a), 1)
			|| ft_push(b, *a->items) 
			|| ft_pop(a) == ERR)
			return (1);
		ft_putendl_fd("pb", 1);
	}
	while (a->top > 2 * issmall)
	{
		if (ft_puttotop(a, ft_getmin(a), 1))
			return (1);
		if (ft_push(b, *a->items) || ft_pop(a) == ERR)
			return (1);
		ft_putendl_fd("pb", 1);
	}
	if (a->top + b->top < 45)
	{
		if (*a->items > a->items[1])
		{
			ft_swap(a);
			ft_putendl_fd("sa", 1);
		}
	}
	if (ft_dumpb(a, b))
		return (1);
	while (*a->items != ft_getmin(a))
	{
		if (ft_rotate(a, 1))
			return (1);
		ft_putendl_fd("rra", 1);
	}
	return (0);
}
