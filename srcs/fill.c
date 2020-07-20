/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 21:07:26 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/18 17:18:47 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		count_arg(int ac, char **av)
{
	int		i;
	int		na;

	i = 0;
	na = 0;
	while (i < ac - 1)
	{
		na = na + count_nb_word((const char*)av[i + 1], ' ');
		i++;
	}
	return (na);
}

int		fill(int ac, char **av, t_stack *c)
{
	int		i;
	int		y;
	int		n;
	char	**split;

	i = 0;
	n = 0;
	while (++i < ac)
	{
		y = -1;
		split = ft_strsplit(av[i], ' ');
		while (split[++y] != NULL)
		{
			c->tab_a[n] = ft_atoi(c, split[y]);
			c->tab_c[n] = c->tab_a[n];
			c->tab_b[n] = 0;
			n++;
		}
		while (--y > 0)
			ft_strdel(&(split[y]));
		if (y >= 0)
			ft_strdel(&(split[y]));
		free(split);
	}
	return (n);
}
