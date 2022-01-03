/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:36:11 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/03 12:35:33 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_initstack()
{
	t_stack	*ret = malloc(sizeof(t_stack));
	ret->top = 0;
	ret->items = malloc(0);
	return (ret);
}

void	ft_push(t_stack *stack, int topush)
{
	int	i;
	int	*ret;

	i = 0;
	ret = malloc((++stack->top) * sizeof(int));
	ret[i++] = topush;
	while (i < stack->top)
	{
		ret[i] = stack->items[i - 1];
		i++;
	}
	free(stack->items);
	stack->items = ret;
}

void	ft_pushbot(t_stack *stack, int topush)
{
	int	i;
	int	*ret;

	i = 0;
	ret = malloc((++stack->top) * sizeof(int));
	while (i + 1 < stack->top)
	{
		ret[i] = stack->items[i];
		i++;
	}
	ret[i] = topush;
	free(stack->items);
	stack->items = ret;
}

int	ft_pop(t_stack *stack)
{
	int	ret;
	int	i;
	int	*newitems;
	
	ret = stack->items[0];
	newitems = malloc((--stack->top) * sizeof(int));
	i = 1;
	while (i <= stack->top)
	{
		newitems[i - 1] = stack->items[i];
		i++;
	}
	free(stack->items);
	stack->items = newitems;
	return (ret);
}

int	ft_popbot(t_stack *stack)
{
	int	ret;
	int	i;
	int	*newitems;
	
	ret = stack->items[stack->top - 1];
	newitems = malloc((--stack->top) * sizeof(int));
	i = 0;
	while (i < stack->top)
	{
		newitems[i] = stack->items[i];
		i++;
	}
	return (ret);
}
