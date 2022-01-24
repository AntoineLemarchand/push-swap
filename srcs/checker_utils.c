/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:45:12 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/24 15:05:51 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_execpush(t_stack *a, t_stack *b, char *action)
{
	if (!ft_strncmp(action, "pa\n", 3))
	{
		if (!b->top || (ft_push(a, *b->items) || ft_pop(b) == ERR))
			return (1);
	}
	else if (!ft_strncmp(action, "pb\n", 3))
	{
		if (!a->top || (ft_push(b, *a->items) || ft_pop(a) == ERR))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	ft_execrotate(t_stack *a, t_stack *b, char *action)
{
	if (!ft_strncmp(action, "ra\n", 3) || !ft_strncmp(action, "rra\n", 4))
	{
		if (!a->top || ft_rotate(a, action[2] == 'a'))
			return (1);
	}
	else if (!ft_strncmp(action, "rb\n", 3) || !ft_strncmp(action, "rrb\n", 3))
	{
		if (!b->top || ft_rotate(b, action[2] == 'b'))
			return (1);
	}
	else if (!ft_strncmp(action, "rr\n", 3) || !ft_strncmp(action, "rrr\n", 4))
	{
		if (!a->top || !b->top
			|| ft_rotate(a, action[2] == 'r') || ft_rotate(b, action[2] == 'r'))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	ft_execswap(t_stack *a, t_stack *b, char *action)
{
	if (!ft_strncmp(action, "sa\n", 3))
		ft_swap(a);
	else if (!ft_strncmp(action, "sb\n", 3))
		ft_swap(b);
	else if (!ft_strncmp(action, "ss\n", 3))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else
		return (1);
	return (0);
}
