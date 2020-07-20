/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 02:43:52 by flafonso          #+#    #+#             */
/*   Updated: 2019/07/01 17:51:46 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	visu_on(t_my_sdl *my_sdl, int n)
{
	while ((my_sdl->w_h / n) * n != my_sdl->w_h)
		my_sdl->w_h++;
	if (my_sdl->w_h > 1300)
	{
		my_sdl->w_h = 1300;
		while ((my_sdl->w_h / n) * n != my_sdl->w_h)
			my_sdl->w_h--;
	}
	my_sdl->w_l = my_sdl->w_h * 1.5;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
		exit(EXIT_FAILURE);
	my_sdl->window = SDL_CreateWindow("Visualisateur du turfu !",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		my_sdl->w_l, my_sdl->w_h, SDL_WINDOW_SHOWN);
	my_sdl->renderer = SDL_CreateRenderer(my_sdl->window, 1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void	visu_init(t_my_sdl *my_sdl, int v, int n)
{
	my_sdl->w_h = 1300;
	my_sdl->w_l = 0;
	my_sdl->rect.h = 0;
	my_sdl->rect.w = 0;
	my_sdl->rect.x = 0;
	my_sdl->delay = 100;
	my_sdl->renderer = NULL;
	my_sdl->window = NULL;
	if (v == 1)
		visu_on(my_sdl, n);
}

void	checker_init(t_stack *c, t_my_sdl *my_sdl, int ac, char **av)
{
	c->checker = 1;
	c->n = count_arg(ac, (my_sdl->v == 1) ? (&av[1]) : (av));
	visu_init(my_sdl, my_sdl->v, c->n);
	if ((c->tab_a = (int*)malloc(sizeof(int) * (c->n))) == NULL)
		error_chck(c, my_sdl);
	if ((c->tab_b = (int*)malloc(sizeof(int) * (c->n))) == NULL)
		error_chck(c, my_sdl);
	if ((c->tab_c = (int*)malloc(sizeof(int) * (c->n))) == NULL)
		error_chck(c, my_sdl);
	if (!(c->op = (t_op*)malloc(sizeof(t_op) * 1)))
		error_chck(c, my_sdl);
	c->op->next = NULL;
	c->op->pres = NULL;
	c->op->arg = NULL;
	c->n = fill(ac, (my_sdl->v == 1) ? (&av[1]) : (av), c) - 1;
	if (c->n == -1)
		c->n = 0;
	c->na = c->n;
	c->nb = 0;
	my_sdl->max = ft_max(c);
}

void	push_init(t_stack *c, int ac, char **av)
{
	if ((c->tab_a = (int*)malloc(sizeof(int) * (c->n))) == NULL)
		error(c);
	if ((c->tab_b = (int*)malloc(sizeof(int) * (c->n))) == NULL)
		error(c);
	if ((c->tab_c = (int*)malloc(sizeof(int) * (c->n))) == NULL)
		error(c);
	if (!(c->op = (t_op*)malloc(sizeof(t_op) * 1)))
		error(c);
	c->op->next = NULL;
	c->op->pres = NULL;
	c->op->arg = NULL;
	c->n = fill(ac, av, c) - 1;
	c->na = c->n;
	c->nb = 0;
	c->last_blk = -1;
	c->not_rrb = 0;
	c->checker = 0;
}
