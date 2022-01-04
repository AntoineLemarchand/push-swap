/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:36:11 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/04 16:00:08 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_initstack()
{
	t_stack	*ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->top = 0;
	ret->items = malloc(0);
	return (ret);
}

int	ft_push(t_stack *stack, long topush)
{
	int		i;
	long	*ret;

	i = 0;
	ret = malloc((++stack->top) * sizeof(long));
	if (!ret)
		return (1);
	ret[i++] = topush;
	while (i < stack->top)
	{
		ret[i] = stack->items[i - 1];
		i++;
	}
	free(stack->items);
	stack->items = ret;
	return (0);
}

int	ft_pushbot(t_stack *stack, long topush)
{
	int		i;
	long	*ret;

	i = 0;
	stack->top++;
	ret = malloc(stack->top * sizeof(long));
	if (!ret)
		return (1);
	while (i < stack->top - 1)
	{
		ret[i] = stack->items[i];
		i++;
	}
	ret[i] = topush;
	free(stack->items);
	stack->items = ret;
	return (0);
}

int	ft_pop(t_stack *stack)
{
	long	ret;
	int		i;
	long	*newitems;
	
	ret = stack->items[0];
	newitems = malloc((--stack->top) * sizeof(long));
	if (!newitems)
		return (1);
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
	long	ret;
	int		i;
	long	*newitems;
	
	ret = stack->items[stack->top - 1];
	newitems = malloc((--stack->top) * sizeof(long));
	if (!newitems)
		return (1);
	i = 0;
	while (i < stack->top)
	{
		newitems[i] = stack->items[i];
		i++;
	}
	return (ret);
}
