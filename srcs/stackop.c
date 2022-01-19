/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:06:40 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/19 20:46:38 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_freestack(t_stack *stack)
{
	free(stack->items);
	free(stack);
}

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->top > 2)
	{
		tmp = stack->items[0];
		stack->items[0] = stack->items[1];
		stack->items[1] = tmp;
	}
}

int	ft_rotate(t_stack *stack, int isreverse)
{
	long	topush;

	if (isreverse)
	{
		topush = ft_popbot(stack);
		if (topush == ERR || ft_push(stack, topush))
			return (1);
	}
	else
	{
		topush = ft_pop(stack);
		if (topush == ERR || ft_pushbot(stack, topush))
			return (1);
	}
	return (0);
}
