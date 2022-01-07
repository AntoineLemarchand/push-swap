/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:14:52 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/07 11:04:21 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_puterror(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

#include<stdio.h>
void	pstack(t_stack *stack)
{
	printf("________________________________________________________________\n");
	int i = 0;
	while (i < stack->top)
		printf("->%li\n", stack->items[i++]);
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	a = ft_initstack();
	if (!a)
		ft_puterror();
	b = ft_initstack();
	if (!b)
	{
		ft_freestack(a);
		ft_puterror();
	}
	if (ac < 2 || ft_loadstack(a, av + 1))
		ft_puterror();
	else
		ft_sortstack(a, b);
	ft_freestack(a);
	ft_freestack(b);
}
