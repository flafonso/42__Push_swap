/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:38:33 by flafonso          #+#    #+#             */
/*   Updated: 2019/07/01 17:56:01 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_lst(t_op *op)
{
	while (op->pres != NULL)
		op = op->pres;
	ft_putstr(" __print_op__ \n");
	ft_putstr("/		\\\n");
	while (op != NULL)
	{
		ft_putstr("|-->");
		ft_putstr(op->arg);
		ft_putstr("	|\n");
		op = op->next;
	}
	ft_putstr("|_______________|\n");
}

void	rec_arg(t_stack *c, t_op *op)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_cmp(line, "sa") != 0 && ft_cmp(line, "sb") != 0
			&& ft_cmp(line, "ss") != 0 && ft_cmp(line, "rr") != 0
			&& ft_cmp(line, "pa") != 0 && ft_cmp(line, "pb") != 0
			&& ft_cmp(line, "ra") != 0 && ft_cmp(line, "rb") != 0
			&& ft_cmp(line, "rra") != 0 && ft_cmp(line, "rrb") != 0
			&& ft_cmp(line, "rrr") != 0 && line != NULL)
			error(c);
		if (i == 0)
			op->arg = ft_strdup(line);
		else
		{
			op->next = new_op(c, op, line);
			op = op->next;
		}
		i++;
		ft_strdel(&line);
	}
}

void	ft_exe(t_op *op, t_stack *c, t_my_sdl *my_sdl)
{
	c->na = c->n;
	c->nb = 0;
	while (op)
	{
		if ((ft_cmp(op->arg, "sa") == 0) || (ft_cmp(op->arg, "ss") == 0))
			ft_sa(c);
		if ((ft_cmp(op->arg, "sb") == 0) || (ft_cmp(op->arg, "ss") == 0))
			ft_sb(c);
		if ((ft_cmp(op->arg, "ra") == 0) || (ft_cmp(op->arg, "rr") == 0))
			ft_ra(c);
		if ((ft_cmp(op->arg, "rb") == 0) || (ft_cmp(op->arg, "rr") == 0))
			ft_rb(c);
		if (ft_cmp(op->arg, "pa") == 0)
			ft_pa(c);
		if (ft_cmp(op->arg, "pb") == 0)
			ft_pb(c);
		if ((ft_cmp(op->arg, "rra") == 0) || (ft_cmp(op->arg, "rrr") == 0))
			ft_rra(c);
		if ((ft_cmp(op->arg, "rrb") == 0) || (ft_cmp(op->arg, "rrr") == 0))
			ft_rrb(c);
		if (my_sdl->v == 1)
			print_visu(c, my_sdl);
		op = op->next;
	}
}

int		checker(t_stack *c, t_my_sdl *my_sdl)
{
	rec_arg(c, c->op);
	if (my_sdl->v == 1)
	{
		print_visu(c, my_sdl);
		SDL_Delay(50);
	}
	ft_exe(c->op, c, my_sdl);
	return (0);
}
