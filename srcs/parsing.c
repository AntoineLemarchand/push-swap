/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:40:51 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/03 13:16:35 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_loadstack(t_stack *stack, ac, av)
{
	int	*input;
	int	size;
	int	i;

	if (ft_checkinput(ac, av))
	{
		stack->top = -1;
		return
	}
	size = ft_loadinput(input, ac, av);
	while (i < size)
	{
		ft_pushbot(input[i]);
		size++;
	}
}
