/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cocktailparty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:20:15 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/14 17:23:11 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_getmin(t_stack *stack)
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

static int	ft_getmax(t_stack *stack)
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

int	ft_cocktailparty(t_stack *a, t_stack *b)
{
	ft_getmin(b);
	ft_getmax(b);
	(void)a;
	(void)b;
	return (0);
}
