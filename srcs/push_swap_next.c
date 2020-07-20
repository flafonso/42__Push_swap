/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 06:30:06 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/10 14:55:21 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_qsort	*new_qs(t_stack *c, t_qsort *list)
{
	t_qsort		*lstnew;

	if (!(lstnew = (t_qsort*)malloc(sizeof(t_qsort) * 1)))
	{
		free_qs(list);
		error(c);
	}
	lstnew->nb_p = 0;
	lstnew->next = NULL;
	lstnew->pres = list;
	return (lstnew);
}

int		higher_p(int max, int *tab, int dep, int p)
{
	while (dep < max + 1)
	{
		if (tab[dep] >= p)
			return (1);
		dep++;
	}
	return (0);
}

int		lower_p(int max, int *tab, int dep, int p)
{
	while (dep < max + 1)
	{
		if (tab[dep] <= p)
			return (1);
		dep++;
	}
	return (0);
}

int		next_for_b(t_stack *c, int ib, int fin, int p)
{
	int		nb_p;

	nb_p = 0;
	while (higher_p(fin, c->tab_b, ib, p))
	{
		if (c->tab_b[ib] < p)
		{
			ft_rb(c);
			c->nb_rb++;
		}
		if (c->tab_b[ib] >= p)
		{
			ft_pa(c);
			ib++;
			nb_p++;
			swap_after_push(c, c->n - c->na, ib, 'b');
		}
	}
	return (nb_p);
}

int		next_for_a(t_stack *c, int ia, int fin, int p)
{
	int		nb_p;

	nb_p = 0;
	while (lower_p(fin, c->tab_a, ia, p))
	{
		if (nbgood(c) == c->na + 1)
			break ;
		if (c->tab_a[ia] > p)
		{
			ft_ra(c);
			c->nb_ra++;
		}
		if (c->tab_a[ia] <= p)
		{
			ft_pb(c);
			ia++;
			nb_p++;
			swap_after_push(c, ia, c->n - c->nb + 1, 'a');
		}
	}
	return (nb_p);
}
