/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:14:11 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/24 15:03:24 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_puterror(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

static int	ft_execaction(t_stack *a, t_stack *b, char *action)
{
	if (*action == 'p')
	{
		if (ft_execpush(a, b, action))
			return (1);
	}
	else if (*action == 'r')
	{
		if (ft_execrotate(a, b, action))
			return (1);
	}
	else if (*action == 's')
	{
		if (ft_execswap(a, b, action))
			return (1);
	}
	else
		return (1);
	return (0);
}

static void	ft_initstacks(t_stack *stacks[2], char **av)
{
	stacks[0] = ft_initstack();
	if (!stacks[0])
		ft_puterror();
	stacks[1] = ft_initstack();
	if (!stacks[1])
	{
		ft_freestack(stacks[0]);
		ft_puterror();
	}
	if (ft_loadstack(stacks[0], av + 1))
	{
		ft_freestack(stacks[1]);
		ft_puterror();
	}
}

int	main(int ac, char **av)
{
	char	*action;
	t_stack	*stacks[2];

	if (ac == 1)
		return (0);
	ft_initstacks(stacks, av);
	action = get_next_line(0);
	while (action != NULL)
	{
		if (ft_execaction(stacks[0], stacks[1], action))
		{
			ft_freestack(stacks[0]);
			ft_freestack(stacks[1]);
			ft_puterror();
		}
		free(action);
		action = get_next_line(0);
	}
	if (ft_issorted(stacks[0]) && !stacks[1]->top)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_freestack(stacks[0]);
	ft_freestack(stacks[1]);
	return (0);
}
