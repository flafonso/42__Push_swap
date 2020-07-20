/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:50:00 by flafonso          #+#    #+#             */
/*   Updated: 2019/07/08 10:46:27 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_stack *c)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = c->n;
	while (c->n - c->na < i)
	{
		tmp = c->tab_a[i];
		c->tab_a[i] = c->tab_a[i - 1];
		c->tab_a[i - 1] = tmp;
		i--;
	}
	if (c->checker == 0)
	{
		c->op->next = new_op(c, c->op, "rra");
		c->op = c->op->next;
	}
}

void	ft_rrb(t_stack *c)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = c->n;
	while (c->n - (c->nb - 1) < i)
	{
		tmp = c->tab_b[i];
		c->tab_b[i] = c->tab_b[i - 1];
		c->tab_b[i - 1] = tmp;
		i--;
	}
	if (c->checker == 0)
	{
		c->op->next = new_op(c, c->op, "rrb");
		c->op = c->op->next;
	}
}

void	ft_pa(t_stack *c)
{
	int		ia;
	int		ib;

	ia = c->n - c->na;
	ib = c->n - (c->nb - 1);
	if (c->nb != 0)
	{
		c->tab_a[ia - 1] = c->tab_b[ib];
		c->tab_b[ib] = 0;
		c->nb--;
		c->na++;
		if (c->checker == 0)
		{
			c->op->next = new_op(c, c->op, "pa");
			c->op = c->op->next;
		}
	}
}

void	ft_pb(t_stack *c)
{
	int		ia;
	int		ib;

	ia = c->n - c->na;
	ib = c->n - c->nb;
	if (c->na != -1)
	{
		c->tab_b[ib] = c->tab_a[ia];
		c->tab_a[ia] = 0;
		c->nb++;
		c->na--;
		if (c->checker == 0)
		{
			c->op->next = new_op(c, c->op, "pb");
			c->op = c->op->next;
		}
	}
}
