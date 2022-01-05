/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:06:40 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/05 12:23:37 by alemarch         ###   ########.fr       */
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

	tmp = stack->items[0];
	stack->items[0] = stack->items[1];
	stack->items[1] = tmp;
}

int	ft_rotate(t_stack *stack,int isreverse)
{
	long	topush;

	if (isreverse)
	{
		topush = ft_pop(stack);
		if (topush == ERR || ft_push(stack, topush) == ERR)
			return (ERR);
	}
	else
	{
		topush = ft_pop(stack);
		if (topush == ERR || ft_pushbot(stack, topush) == ERR)
			return (ERR);
	}
	return (0);
}
