/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:52:14 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/20 12:23:56 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_issorted(t_stack *a)
{
	int		i;
	long	prev;

	prev = *a->items;
	i = 1;
	while (i < a->top)
	{
		if (a->items[i] <= prev)
			return (0);
		prev = a->items[i];
		i++;
	}
	return (1);
}

void	ft_renamestack(t_stack *stack)
{
	int		i;
	int		j;
	int		count;
	long	*ret;

	i = 0;
	ret = malloc (stack->top * sizeof(long));
	while (i < stack->top)
	{
		j = 0;
		count = 0;
		while (j < stack->top)
		{
			if (stack->items[j] < stack->items[i])
				count++;
			j++;
		}
		ret[i] = count;
		i++;
	}
	free(stack->items);
	stack->items = ret;
}

int	ft_sortstack(t_stack *a, t_stack *b)
{
	if (!ft_issorted(a))
	{
		if (a->top <= 2)
		{
			if (ft_sort2(a))
				return (1);
		}
		else if (a->top <= 3)
		{
			if (ft_sort3(a))
				return (1);
		}
		else if (a->top <= 45)
		{
			if (ft_selectionsort(a, b))
				return (1);
		}
		else
		{
			if (ft_costsort(a, b) || ft_puttotop(b, ft_getmax(b), 0)
				|| ft_selectionsort(a, b))
				return (1);
		}
	}
	return (0);
}
