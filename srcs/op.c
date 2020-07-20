/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:49:53 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/18 17:08:28 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_op	*new_op(t_stack *c, t_op *op, char *str)
{
	t_op	*new;

	if (!(new = (t_op*)malloc(sizeof(t_op) * 1)))
		error(c);
	new->pres = op;
	new->next = NULL;
	new->arg = ft_strdup(str);
	return (new);
}

void	ft_sa(t_stack *c)
{
	int		tmp;
	int		i;

	i = c->n - c->na;
	if (c->na == 0)
		return ;
	tmp = c->tab_a[i];
	c->tab_a[i] = c->tab_a[i + 1];
	c->tab_a[i + 1] = tmp;
	if (c->checker == 0)
	{
		c->op->next = new_op(c, c->op, "sa");
		c->op = c->op->next;
	}
}

void	ft_sb(t_stack *c)
{
	int		tmp;
	int		i;

	i = c->n - (c->nb - 1);
	if (c->nb == 0)
		return ;
	tmp = c->tab_b[i];
	c->tab_b[i] = c->tab_b[i + 1];
	c->tab_b[i + 1] = tmp;
	if (c->checker == 0)
	{
		c->op->next = new_op(c, c->op, "sb");
		c->op = c->op->next;
	}
}

void	ft_ra(t_stack *c)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = c->n - c->na;
	while (i < c->n)
	{
		tmp = c->tab_a[i];
		c->tab_a[i] = c->tab_a[i + 1];
		c->tab_a[i + 1] = tmp;
		i++;
	}
	if (c->checker == 0)
	{
		c->op->next = new_op(c, c->op, "ra");
		c->op = c->op->next;
	}
}

void	ft_rb(t_stack *c)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = c->n - (c->nb - 1);
	while (i < c->n)
	{
		tmp = c->tab_b[i];
		c->tab_b[i] = c->tab_b[i + 1];
		c->tab_b[i + 1] = tmp;
		i++;
	}
	if (c->checker == 0)
	{
		c->op->next = new_op(c, c->op, "rb");
		c->op = c->op->next;
	}
}
