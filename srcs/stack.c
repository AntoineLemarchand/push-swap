/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:36:11 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/19 20:49:50 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_initstack(void)
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
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
	ret = malloc(++stack->top * sizeof(long));
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

long	ft_pop(t_stack *stack)
{
	long	ret;
	int		i;
	long	*newitems;

	if (stack->top == 0)
		return (ERR);
	ret = *stack->items;
	newitems = malloc((--stack->top) * sizeof(long));
	if (!newitems)
		return (ERR);
	i = 0;
	while (i < stack->top)
	{
		newitems[i] = stack->items[i + 1];
		i++;
	}
	free(stack->items);
	stack->items = newitems;
	return (ret);
}

long	ft_popbot(t_stack *stack)
{
	long	ret;
	int		i;
	long	*newitems;

	ret = stack->items[stack->top - 1];
	newitems = malloc((--stack->top) * sizeof(long));
	if (!newitems)
		return (ERR);
	i = 0;
	while (i < stack->top)
	{
		newitems[i] = stack->items[i];
		i++;
	}
	free(stack->items);
	stack->items = newitems;
	return (ret);
}
