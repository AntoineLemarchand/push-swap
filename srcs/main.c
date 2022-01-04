/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:14:52 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/04 16:42:10 by alemarch         ###   ########.fr       */
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
	int		i;

	i = 0;
	a = ft_initstack();
	b = ft_initstack();
	if (ac < 2 || ft_loadstack(a, av + 1))
		ft_puterror();
	else
	{
		/* here will be the grandiose algorithm*/
		write(1, "todo\n", 5);
	}
	free(a->items);
	free(a);
	free(b->items);
	free(b);
}
