/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:28:53 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/20 16:35:17 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static long	ft_getsortedpos(t_stack *b, long val)
{
	int		j;
	long	max;

	if (!b->top)
		return (ERR);
	max = ft_getmax(b);
	j = 0;
	while (b->items[j] != max)
		j++;
	while (j < b->top && b->items[j] > val)
		j++;
	if (j != b->top)
		return (b->items[j]);
	j = 0;
	while (j < b->top && b->items[j] > val)
		j++;
	if (j < b->top)
		return (b->items[j]);
	else
		return (max);
}

static int	ft_getcost(t_stack *a, t_stack *b, int index)
{
	int	cost;
	int	dista;
	int	distb;
	int	distbindex;

	if (index > a->top / 2)
		dista = a->top - index;
	else
		dista = index;
	distb = ft_getsortedpos(b, a->items[index]);
	if (distb != ERR)
		distbindex = ft_getindex(b, distb);
	if (distb != ERR && distbindex > b->top / 2)
		distb = b->top - distbindex;
	else if (distb != ERR)
		distb = distbindex;
	cost = dista + distb + 1;
	return (cost);
}

static long	ft_getlowestcost(t_stack *a, t_stack *b)
{
	long	lowestcost;
	int		i;

	lowestcost = a->items[0];
	i = 1;
	while (i < a->top)
	{
		if (ft_getcost(a, b, ft_getindex(a, lowestcost))
			> ft_getcost(a, b, i))
			lowestcost = a->items[i];
		i++;
	}
	return (lowestcost);
}

static int	ft_movetoplace(t_stack *a, t_stack *b, long topush, long toput)
{
	int	topushindex;
	int	toputindex;

	if (toput == ERR)
	{
		if (ft_puttotop(a, topush, 1))
			return (1);
		return (0);
	}
	topushindex = ft_getindex(a, topush);
	toputindex = ft_getindex(b, toput);
	if ((topushindex > a->top / 2 && toputindex <= b->top / 2)
		|| (topushindex <= a->top / 2 && toputindex > b->top / 2)
		|| !topushindex || !toputindex)
	{
		if (ft_puttotop(a, topush, 1) || ft_puttotop(b, toput, 0))
			return (1);
		return (0);
	}
	if (ft_putbothtotop(a, b, topush, toput) || ft_puttotop(b, toput, 0))
		return (1);
	return (0);
}

int	ft_costsort(t_stack *a, t_stack *b)
{
	long	topush;
	long	toput;

	if (ft_push(b, *a->items) || ft_pop(a) == ERR)
		return (1);
	ft_putendl_fd("pb", 1);
	while (a->top > 45)
	{
		topush = ft_getlowestcost(a, b);
		toput = ft_getsortedpos(b, topush);
		if (toput == ERR)
		{
			if (ft_puttotop(a, topush, 1))
				return (1);
			return (0);
		}
		else
			if (ft_movetoplace(a, b, topush, toput))
				return (1);
		if (ft_push(b, *a->items) || ft_pop(a) == ERR)
			return (1);
		ft_putendl_fd("pb", 1);
	}
	return (0);
}
