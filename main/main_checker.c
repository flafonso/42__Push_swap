/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:44:40 by flafonso          #+#    #+#             */
/*   Updated: 2019/07/01 17:52:28 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ok_or_ko(t_stack *c)
{
	int		i;

	i = 0;
	if (c->nb != 0)
	{
		ft_putstr("KO\n");
		return ;
	}
	while (i < c->n)
	{
		if (c->tab_a[i] >= c->tab_a[i + 1])
		{
			ft_putstr("KO\n");
			return ;
		}
		i++;
	}
	ft_putstr("OK\n");
}

int		main(int ac, char **av)
{
	t_stack			c;
	t_my_sdl		my_sdl;

	c.checker = 1;
	if (av[1] != NULL && ft_cmp(av[1], "-v") == 0)
		my_sdl.v = 1;
	else
		my_sdl.v = 0;
	ac = (my_sdl.v == 1) ? (ac - 1) : (ac);
	if (ac == 1)
		return (0);
	checker_init(&c, &my_sdl, ac, av);
	ft_dnb(&c);
	checker(&c, &my_sdl);
	ok_or_ko(&c);
	if (my_sdl.v == 1)
		sdl_wait_end();
	endsdl(&my_sdl);
	free_all(&c);
	return (0);
}
