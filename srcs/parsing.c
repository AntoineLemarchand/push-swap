/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:40:51 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/04 14:00:08 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_ischarset(char c)
{
	return (c == '-' || c == ' ');
}

static int ft_containspace(char *s)
{
	while (*s)
	{
		if (*s == ' ')
			return (1);
		s++;
	}
	return (0);
}

static int	ft_checkinput(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_ischarset(av[i][j]) && !ft_isdigit(av[i][j]))
				return (1);
			else if (av[i][j] == '-' && ft_ischarset(av[i][j + 1]))
				return (1);
			else if (ft_isdigit(av[i][j]) && av[i][j + 1] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_loadinput(t_stack *stack, char **av)
{
	char **split;

	while (*av)
	{
		if (ft_containspace(*av))
		{
			split = ft_split(*av, ' ');
			if (!split)
				return (1);
			while (*split)
			{
				ft_pushbot(stack, ft_atol(*split));
				split++;
			}
		}
		else
			ft_pushbot(stack, ft_atol(*av));
		av++;
	}
	return (0);
}

int	ft_loadstack(t_stack *stack, char **av)
{
	if (ft_checkinput(av))
		return (1);
	if (ft_loadinput(stack, av))
		return (1);
	return (0);
}
