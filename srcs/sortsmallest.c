/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsmallest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:06:54 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/24 15:13:57 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_sort2(t_stack *a)
{
	if (!ft_issorted(a))
	{
		if (ft_rotate(a, 0))
			return (1);
		ft_putendl_fd("ra", 1);
	}
	return (0);
}

int	ft_sort3(t_stack *a)
{
	long	first;
	long	second;
	long	third;

	first = *a->items;
	second = *(a->items + 1);
	third = *(a->items + 2);
	if (!ft_issorted(a))
	{
		if (first > second && second <= third && third > first)
			ft_putendl_fd("sa", 1);
		else if (first <= second && second > third && third > first)
			ft_putendl_fd("sa\nra", 1);
		else if (first > second && second <= third && third <= first)
			ft_putendl_fd("ra", 1);
		else if (first <= second && second > third && third <= first)
			ft_putendl_fd("rra", 1);
		else
			ft_putendl_fd("sa\nrra", 1);
	}
	return (0);
}
