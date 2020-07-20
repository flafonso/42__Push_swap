/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 07:11:14 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/12 11:23:19 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			first_qsort(t_stack *c, int fin, int dep)
{
	int		nb_p;
	int		p;

	nb_p = 0;
	if (c->n + 1 == 3 || c->na + 1 == 3)
		last_small_a(c);
	if ((fin + 1) - dep <= 3)
	{
		pg_small_a(c, dep, fin);
		return (0);
	}
	p = c->tab_a[mediane(c->tab_a, c->n + 1, c->n - c->na, c->na + 1)];
	while (dep < c->n && lower_p(fin, c->tab_a, dep, p))
	{
		if (c->tab_a[dep] > p)
			ft_ra(c);
		else if (c->tab_a[dep] <= p)
		{
			ft_pb(c);
			dep++;
			nb_p++;
		}
	}
	return (nb_p);
}

int			qs_tab_b(t_stack *c, int dep, int fin)
{
	int		p;
	int		ib;
	int		nb_p;

	c->nb_rb = 0;
	nb_p = 0;
	ib = dep;
	if ((fin + 1) - dep <= 3 && c->not_rrb != 1)
		return (small_b(c, dep, fin));
	p = c->tab_b[mediane(c->tab_b, fin + 1, dep, (fin + 1) - dep)];
	if (dep == fin && c->tab_c[c->n - c->na - 1] == c->tab_b[ib])
	{
		ft_pa(c);
		return (1);
	}
	nb_p = next_for_b(c, ib, fin, p);
	if (c->not_rrb != 1)
		while (c->nb_rb-- > 0)
			ft_rrb(c);
	return (nb_p);
}

int			qs_tab_a(t_stack *c, int dep, int fin)
{
	int		p;
	int		ia;
	int		nb_p;

	c->nb_ra = 0;
	nb_p = 0;
	ia = dep;
	if ((fin + 1) - dep <= 3)
	{
		pg_small_a(c, dep, fin);
		return (0);
	}
	p = c->tab_a[mediane(c->tab_a, fin + 1, dep, (fin + 1) - dep)];
	nb_p = next_for_a(c, ia, fin, p);
	while (c->nb_ra-- > 0)
		ft_rra(c);
	return (nb_p);
}

void		one_block(t_stack *c, int fin)
{
	int		push_a;
	int		push_b;

	push_a = 0;
	push_b = 0;
	if (nbgood(c) != c->na + 1)
	{
		push_a = qs_tab_a(c, c->n - c->na, c->n - nbgood(c));
		one_block(c, push_a);
	}
	if (fin > 0)
	{
		if (c->last_blk == fin)
			c->not_rrb = 1;
		else
			c->not_rrb = 0;
		push_b = qs_tab_b(c, c->n - c->nb + 1, c->n - c->nb + fin);
		if (c->last_blk == fin)
			c->last_blk -= push_b;
		one_block(c, fin - push_b);
	}
	return ;
}

int			push_swap(t_stack *c)
{
	t_qsort		*qs;

	qs = (t_qsort*)malloc(sizeof(t_qsort) * 1);
	qs->next = NULL;
	qs->pres = NULL;
	qs->nb_p = c->n;
	while (check_sort(c, c->n, c->n - c->na, 1) != 0)
	{
		qs->next = new_qs(c, qs);
		qs = qs->next;
		qs->nb_p = first_qsort(c, c->n, c->n - c->na);
		if (c->n - c->na + 1 == c->n && c->tab_a[c->n - c->na] > c->tab_a[c->n])
			ft_ra(c);
	}
	while (qs->pres != NULL)
	{
		if (qs->pres->pres == NULL)
			c->last_blk = qs->nb_p;
		one_block(c, qs->nb_p);
		qs = qs->pres;
	}
	free_qs(qs);
	return (0);
}
