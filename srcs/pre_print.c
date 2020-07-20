/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 01:08:44 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/04 11:39:58 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_del_one(t_op *op)
{
	if (op != NULL)
	{
		if (op->pres != NULL)
			op->pres->next = op->next;
		if (op->next != NULL)
			op->next->pres = op->pres;
		if (op != NULL)
		{
			ft_strdel(&(op->arg));
			ft_memdel((void**)&op);
		}
	}
}

t_op	*the_start(t_op *op)
{
	if (op && op->pres != NULL)
	{
		while (op->pres->pres != NULL)
			op = op->pres;
	}
	return (op);
}

t_op	*pre_third(t_op *op)
{
	if ((ft_cmp(op->arg, "sa") == 0 && ft_cmp(op->next->arg, "sb") == 0)
		|| (ft_cmp(op->arg, "sb") == 0 && ft_cmp(op->next->arg, "sa") == 0))
	{
		op->arg[1] = 's';
		op_del_one(op->next);
		op = the_start(op);
	}
	if ((ft_cmp(op->arg, "rb") == 0 && ft_cmp(op->next->arg, "ra") == 0)
		|| (ft_cmp(op->arg, "ra") == 0 && ft_cmp(op->next->arg, "rb") == 0))
	{
		op->arg[1] = 'r';
		op_del_one(op->next);
		op = the_start(op);
	}
	if ((ft_cmp(op->arg, "rrb") == 0 && ft_cmp(op->next->arg, "rra") == 0)
		|| (ft_cmp(op->arg, "rra") == 0
		&& ft_cmp(op->next->arg, "rrb") == 0))
	{
		op->arg[2] = 'r';
		op_del_one(op->next);
		op = the_start(op);
	}
	return (op);
}

t_op	*pre_snd(t_op *op)
{
	if ((ft_cmp(op->arg, "rra") == 0 && ft_cmp(op->next->arg, "ra") == 0)
		|| (ft_cmp(op->arg, "ra") == 0 && ft_cmp(op->next->arg, "rra") == 0)
		|| (ft_cmp(op->arg, "rrb") == 0 && ft_cmp(op->next->arg, "rb") == 0)
		|| (ft_cmp(op->arg, "rb") == 0 && ft_cmp(op->next->arg, "rrb") == 0)
		|| (ft_cmp(op->arg, "sa") == 0 && ft_cmp(op->next->arg, "sa") == 0)
		|| (ft_cmp(op->arg, "sb") == 0 && ft_cmp(op->next->arg, "sb") == 0))
	{
		op = op->pres;
		op_del_one(op->next);
		op_del_one(op->next);
		op = the_start(op);
	}
	return (op);
}

void	pre_print(t_op *op)
{
	op = the_start(op);
	if (op->next != NULL)
	{
		while (op->next->next != NULL)
		{
			op = pre_snd(op);
			op = pre_third(op);
			op = op->next;
		}
	}
}
