/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:45:50 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/03 12:37:14 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		nbgood(t_stack *c)
{
	int		i;
	int		cb;

	i = c->n;
	cb = 0;
	while (i >= c->n - c->na)
	{
		if (c->tab_a[i] != c->tab_c[i])
			return (cb);
		cb++;
		i--;
	}
	return (cb);
}

int		check_sort(t_stack *c, int max, int min, int s)
{
	if (min == max)
		return (0);
	if (s > 0)
	{
		while (min < max)
		{
			if (min + 1 <= max && c->tab_a[min] >= c->tab_a[min + 1])
				return (-1);
			min++;
		}
	}
	else if (s < 0)
	{
		while (min < max)
		{
			if (min - 1 >= 0 && c->tab_b[min] <= c->tab_b[min - 1])
				return (-1);
			min++;
		}
	}
	return (0);
}

int		mediane(int *tab, int max, int min, int nb)
{
	int		tmp;
	int		y;
	int		medium;

	tmp = min;
	while (min <= max)
	{
		y = tmp - 1;
		medium = 0;
		while (++y < max)
		{
			if (tab[y] < tab[min])
				medium--;
			if (tab[y] > tab[min])
				medium++;
		}
		if (nb % 2 != 0)
			if (medium == 0)
				return (min);
		if (nb % 2 == 0)
			if (medium == 1)
				return (min);
		min++;
	}
	return (0);
}
