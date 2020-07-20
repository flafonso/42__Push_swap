/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 21:04:04 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/12 10:58:26 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_chck(t_stack *c, t_my_sdl *my_sdl)
{
	free_all(c);
	if (my_sdl->v == 1)
		endsdl(my_sdl);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	error(t_stack *c)
{
	free_all(c);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_dnb(t_stack *c)
{
	int		i;
	int		y;

	i = -1;
	while (++i < c->n + 1)
	{
		y = -1;
		while (++y < c->n + 1)
			if (c->tab_a[i] == c->tab_a[y] && (i != y))
				error(c);
	}
}
