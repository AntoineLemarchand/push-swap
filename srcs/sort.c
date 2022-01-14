/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:52:14 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/14 17:22:08 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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


int	ft_issorted(t_stack *a)
{
	int		i;
	long	prev;

	prev = *a->items;
	i = 1;
	while (i < a->top)
	{
		if (a->items[i] < prev)
			return (0);
		prev = a->items[i];
		i++;
	}
	return (1);
}

int	ft_sortstack(t_stack *a, t_stack *b)
{
	long	i;
	long	chunks;

	if (a->top <= 100)
		chunks = 4;
	else
		chunks = 20;

	ft_renamestack(a);
	i = 1;
	while (i <= chunks)
	{
		if (ft_pushchunk(a, b, i, chunks))
			return (1);
		i++;
	}
	if (ft_cocktailparty(a, b))
		return (1);
	return (0);
}
