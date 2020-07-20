/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:43:59 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/11 14:43:52 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sort_c(t_stack *c, int dep, int fin, int p)
{
	int		tmp;
	int		i;
	int		y;

	i = dep;
	y = dep;
	tmp = c->tab_c[p];
	c->tab_c[p] = c->tab_c[fin];
	c->tab_c[fin] = tmp;
	while (i < fin)
	{
		if (c->tab_c[i] <= c->tab_c[fin])
		{
			tmp = c->tab_c[i];
			c->tab_c[i] = c->tab_c[y];
			c->tab_c[y] = tmp;
			y++;
		}
		i++;
	}
	tmp = c->tab_c[fin];
	c->tab_c[fin] = c->tab_c[y];
	c->tab_c[y] = tmp;
	return (y);
}

void	qsort_c(t_stack *c, int dep, int fin)
{
	int		p;

	p = 0;
	if (dep < fin)
	{
		p = mediane(c->tab_c, fin, dep, fin - dep);
		p = sort_c(c, dep, fin, p);
		qsort_c(c, dep, p - 1);
		qsort_c(c, p + 1, fin);
	}
}

void	print_op(t_op *op)
{
	if (op != NULL && !(op->next == NULL && op->pres == NULL))
	{
		op = the_start(op);
		while (op != NULL)
		{
			ft_putstr(op->arg);
			ft_putchar('\n');
			op = op->next;
		}
	}
}

int		main(int ac, char **av)
{
	t_stack		c;

	c.n = count_arg(ac, av);
	if (ac == 1)
		return (0);
	push_init(&c, ac, av);
	ft_dnb(&c);
	qsort_c(&c, 0, c.n);
	push_swap(&c);
	if (!(c.op->next == NULL && c.op->pres == NULL))
		pre_print(c.op);
	print_op(c.op);
	free_all(&c);
	return (0);
}
