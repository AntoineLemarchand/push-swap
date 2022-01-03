/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:06:40 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/03 12:19:56 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->items[0];
	stack->items[0] = stack->items[1];
	stack->items[1] = tmp;
}

void	ft_rotate(t_stack *stack,int isreverse)
{
	if (!isreverse)
		ft_pushbot(stack, ft_pop(stack));
	else
		ft_push(stack, ft_popbot(stack));
}
