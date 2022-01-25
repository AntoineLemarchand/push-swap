/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:14:52 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/25 09:38:38 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_puterror(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = ft_initstack();
	if (!a)
		ft_puterror();
	b = ft_initstack();
	if (!b)
	{
		ft_freestack(a);
		ft_puterror();
	}
	else if (ft_loadstack(a, av + 1))
	{
		ft_freestack(a);
		ft_freestack(b);
		ft_puterror();
	}
	else
		ft_sortstack(a, b);
	ft_freestack(a);
	ft_freestack(b);
}
