/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:27:12 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/12 10:42:28 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	last_small_a(t_stack *c)
{
	int		b;
	int		d;

	b = c->tab_a[c->n - c->na + 1];
	d = c->tab_a[c->n - c->na + 2];
	if (c->tab_a[c->n - c->na] < b && c->tab_a[c->n - c->na] < d && b > d)
	{
		ft_sa(c);
		ft_ra(c);
	}
	else if (c->tab_a[c->n - c->na] > b && c->tab_a[c->n - c->na] < d && b < d)
		ft_sa(c);
	else if (c->tab_a[c->n - c->na] < b && c->tab_a[c->n - c->na] > d)
		ft_rra(c);
	else if (c->tab_a[c->n - c->na] > b && c->tab_a[c->n - c->na] > d && b > d)
	{
		ft_sa(c);
		ft_rra(c);
	}
	else if (c->tab_a[c->n - c->na] > b && c->tab_a[c->n - c->na] > d && b < d)
	{
		ft_rra(c);
		ft_rra(c);
	}
}

void	swap_after_push(t_stack *c, int ia, int ib, char det)
{
	if (det == 'a')
	{
		if (ib + 1 <= c->n && c->tab_b[ib] < c->tab_b[ib + 1])
		{
			ft_sb(c);
			if (ia + 1 <= c->n && c->tab_a[ia] > c->tab_a[ia + 1])
				ft_sa(c);
		}
	}
	else if (det == 'b')
	{
		if (ia + 1 <= c->n && c->tab_a[ia] > c->tab_a[ia + 1])
		{
			ft_sa(c);
			if (ib + 1 <= c->n && c->tab_b[ib] < c->tab_b[ib + 1])
				ft_sb(c);
		}
	}
}

void	pg_small_a(t_stack *c, int dep, int fin)
{
	int		i;

	c->nb_ra = 0;
	i = fin;
	while (check_sort(c, fin, dep, 1) != 0)
	{
		while (check_sort(c, i, dep, 1) != 0)
		{
			if (dep + 1 <= fin && c->tab_a[dep] > c->tab_a[dep + 1])
				ft_sa(c);
			else
			{
				ft_ra(c);
				i--;
				c->nb_ra++;
			}
		}
		while (c->nb_ra-- > 0)
		{
			ft_rra(c);
			i++;
			if (dep + 1 <= fin && c->tab_a[dep] > c->tab_a[dep + 1])
				ft_sa(c);
		}
	}
}

int		small_b(t_stack *c, int dep, int fin)
{
	int		i;
	int		p;
	int		nb_p;

	nb_p = 0;
	i = dep;
	p = c->tab_b[mediane(c->tab_b, fin + 1, dep, (fin + 1) - dep)];
	while (higher_p(fin, c->tab_b, c->n - c->nb + 1, p))
	{
		if (c->tab_b[i] >= p)
		{
			ft_pa(c);
			nb_p++;
			i++;
		}
		else
		{
			ft_sb(c);
			if (c->tab_a[c->n - c->na] > c->tab_a[c->n - c->na + 1])
				ft_sa(c);
		}
	}
	return (nb_p);
}
