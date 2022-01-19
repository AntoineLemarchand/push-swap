/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:28:53 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/19 15:51:03 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	ft_getsortedpos(t_stack *b, long val)
{
	int		j;
	int		sortedval;

	if (b->top)
	{
		sortedval = b->top - 1;
		j = b->top - 2;
		while (j > 0)
		{
			if (val - b->items[j] >= 0 && val - b->items[j] < val - b->items[sortedval])
				sortedval = j;
			j--;
		}
		return (b->items[sortedval]);
	}
	else
		return (ERR);
}

int	ft_getcost(t_stack *a, t_stack *b, int index)
{
	int	cost;
	int	dista;
	int	distb;

	if (index > a->top / 2)
		dista = a->top - index;
	else
		dista = index;
	distb = ft_getsortedpos(b, a->items[index]);
	if (distb != ERR && ft_getindex(b, distb) > b->top / 2)
		distb = b->top - ft_getindex(b, distb);
	else if (distb != ERR)
		distb = ft_getindex(b, distb);
	cost = dista + distb + 1;
	return (cost);
}

long	ft_getlowestcost(t_stack *a, t_stack *b)
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

int	ft_costsort(t_stack *a, t_stack *b)
{
	long	topush;
	long	toput;

	while (a->top)
	{
		topush = ft_getlowestcost(a, b);
		toput = ft_getsortedpos(b, topush);
		if (toput != ERR)
		{
			if (ft_puttotop(b, toput, 0))
				return (1);
		}
		if (ft_puttotop(a, topush, 1))
			return (1);
		if (ft_push(b, *a->items) || ft_pop(a) == ERR)
			return (1);
		ft_putendl_fd("pb", 1);
	}
	ft_puttotop(b, ft_getmax(b), 0);
	ft_selectionsort(a, b);
	return (0);
}
