/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 13:10:59 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/03 17:38:20 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	endsdl(t_my_sdl *my_sdl)
{
	SDL_DestroyRenderer(my_sdl->renderer);
	SDL_DestroyWindow(my_sdl->window);
	SDL_Quit();
	my_sdl->v = 0;
}

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	free_qs(t_qsort *qs)
{
	while (qs->pres != NULL)
		qs = qs->pres;
	while (qs->next != NULL)
	{
		qs = qs->next;
		if (qs->pres != NULL)
			free(qs->pres);
	}
	if (qs != NULL)
		free(qs);
}

void	free_all(t_stack *c)
{
	if (c->tab_a != NULL)
		free(c->tab_a);
	if (c->tab_b != NULL)
		free(c->tab_b);
	if (c->tab_c != NULL)
		free(c->tab_c);
	c->op = the_start(c->op);
	if (c->op->pres)
		ft_memdel((void**)&c->op->pres);
	while (c->op->next != NULL)
	{
		c->op = c->op->next;
		op_del_one(c->op->pres);
	}
	op_del_one(c->op);
}
