/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:47:16 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/24 15:17:17 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_pushsorted(t_stack *a, t_stack *b)
{
	while (b->top)
	{
		if (a->items[a->top - 1] > *b->items
			&& a->items[a->top - 1] != ft_getmax(a) && a->top + b->top > 45)
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

static int	ft_dumpb(t_stack *a, t_stack *b)
{
	if (a->top + b->top < 45 && *a->items > a->items[1])
	{
		ft_swap(a);
		ft_putendl_fd("sa", 1);
	}
	while (b->top > 2 && b->items[0] > b->items[1] && b->items[1] > b->items[2])
	{
		if (ft_push(a, *b->items) || ft_pop(b) == ERR)
			return (1);
		ft_putendl_fd("pa", 1);
	}
	if (ft_push(a, *b->items) || ft_pop(b) == ERR)
		return (1);
	ft_putendl_fd("pa", 1);
	if (ft_pushsorted(a, b))
		return (1);
	return (0);
}

int	ft_selectionsort(t_stack *a, t_stack *b, int issmall)
{
	if (b->top && ft_getmax(a) > ft_getmax(b))
	{
		if (ft_puttotop(a, ft_getmax(a), 1)
			|| ft_push(b, *a->items) || ft_pop(a) == ERR)
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
