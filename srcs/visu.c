/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:30:14 by flafonso          #+#    #+#             */
/*   Updated: 2019/07/08 10:45:52 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_abs(int nb)
{
	int		n_abs;

	if (nb < 0)
		n_abs = -nb;
	else
		n_abs = nb;
	return (n_abs);
}

int		ft_max(t_stack *c)
{
	int		i;
	int		max;
	int		tmp;

	i = 0;
	max = ft_abs(c->tab_a[i]);
	while (i < c->n + 1)
	{
		tmp = ft_abs(c->tab_a[i]);
		if (tmp > max)
			max = tmp;
		i++;
	}
	return (max);
}

void	fill_visu_b(t_stack *c, t_my_sdl *my_sdl)
{
	int		i;
	int		tmp;

	i = c->n;
	my_sdl->rect.h = my_sdl->w_h / (c->n + 1);
	my_sdl->rect.y = my_sdl->w_h;
	while (i >= c->n - (c->nb - 1))
	{
		tmp = ft_abs(c->tab_b[i]);
		if (c->tab_b[i] > 0)
			SDL_SetRenderDrawColor(my_sdl->renderer, 252, 163, 17, 255);
		else
			SDL_SetRenderDrawColor(my_sdl->renderer, 210, 63, 29, 255);
		my_sdl->rect.w = (tmp * ((my_sdl->w_l / 2) - 5)) / my_sdl->max;
		if (c->tab_b[i] == 0)
		{
			SDL_SetRenderDrawColor(my_sdl->renderer, 255, 0, 0, 255);
			my_sdl->rect.w = 2;
		}
		my_sdl->rect.x = (my_sdl->w_l / 2) +
			((((my_sdl->w_l / 2) + 5) - my_sdl->rect.w) / 2);
		my_sdl->rect.y = my_sdl->rect.y - my_sdl->rect.h;
		SDL_RenderFillRect(my_sdl->renderer, &(my_sdl->rect));
		i--;
	}
}

void	fill_visu_a(t_stack *c, t_my_sdl *my_sdl)
{
	int		i;
	int		tmp;

	i = c->n;
	my_sdl->rect.h = my_sdl->w_h / (c->n + 1);
	my_sdl->rect.y = my_sdl->w_h;
	while (i >= c->n - c->na)
	{
		tmp = ft_abs(c->tab_a[i]);
		if (c->tab_a[i] > 0)
			SDL_SetRenderDrawColor(my_sdl->renderer, 252, 163, 17, 255);
		else
			SDL_SetRenderDrawColor(my_sdl->renderer, 210, 63, 29, 255);
		my_sdl->rect.w = (tmp * ((my_sdl->w_l / 2) - 5)) / my_sdl->max;
		if (c->tab_a[i] == 0)
		{
			SDL_SetRenderDrawColor(my_sdl->renderer, 255, 0, 0, 255);
			my_sdl->rect.w = 2;
		}
		my_sdl->rect.x = (((my_sdl->w_l / 2) - 5) - my_sdl->rect.w) / 2;
		my_sdl->rect.y = my_sdl->rect.y - my_sdl->rect.h;
		SDL_RenderFillRect(my_sdl->renderer, &(my_sdl->rect));
		i--;
	}
}

void	print_visu(t_stack *c, t_my_sdl *my_sdl)
{
	if (sdl_event(my_sdl) == 1)
		return ;
	if (0 != SDL_SetRenderDrawColor(my_sdl->renderer, 0, 0, 0, 255))
		error_chck(c, my_sdl);
	if (0 != SDL_RenderClear(my_sdl->renderer))
		error_chck(c, my_sdl);
	my_sdl->rect.x = 0;
	my_sdl->rect.y = 0;
	my_sdl->rect.h = my_sdl->w_h;
	my_sdl->rect.w = my_sdl->w_l / 2;
	SDL_SetRenderDrawColor(my_sdl->renderer, 41, 50, 65, 255);
	SDL_RenderFillRect(my_sdl->renderer, &(my_sdl->rect));
	my_sdl->rect.x = my_sdl->w_l / 2;
	my_sdl->rect.y = 0;
	SDL_SetRenderDrawColor(my_sdl->renderer, 20, 33, 61, 255);
	SDL_RenderFillRect(my_sdl->renderer, &(my_sdl->rect));
	fill_visu_a(c, my_sdl);
	fill_visu_b(c, my_sdl);
	SDL_RenderPresent(my_sdl->renderer);
	SDL_Delay(my_sdl->delay);
}
