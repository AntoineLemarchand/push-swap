/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:14:52 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/04 13:17:49 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_puterror(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = ft_initstack();
	b = ft_initstack();
	if (ac < 2 || ft_loadstack(a, av + 1))
		ft_puterror();
	else
	{
		while (*a->items)
		{
			ft_putnbr_fd(*a->items, 1);
			ft_putendl_fd("", 1);
			a->items++;
		}
	}
}
