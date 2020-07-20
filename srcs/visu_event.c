/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:09:13 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/12 11:57:27 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sdl_wait_end(void)
{
	SDL_Event	event;
	int			quit;

	quit = 1;
	while (quit == 1)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			quit = 0;
		if (event.type == SDL_QUIT)
			quit = 0;
	}
}

void	sdl_sleep(void)
{
	SDL_Event	event;
	int			quit;

	quit = 1;
	while (quit == 1)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
			quit = 0;
	}
}

int		sdl_event(t_my_sdl *my_sdl)
{
	SDL_Event	event;

	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		endsdl(my_sdl);
		return (1);
	}
	if (event.type == SDL_KEYDOWN)
	{
		if (my_sdl->delay - 20 >= 0 && event.key.keysym.sym == SDLK_UP)
			my_sdl->delay -= 20;
		if (my_sdl->delay + 20 <= 3000 && event.key.keysym.sym == SDLK_DOWN)
			my_sdl->delay += 20;
		if (event.key.keysym.sym == SDLK_SPACE)
			sdl_sleep();
		if (event.key.keysym.sym == SDLK_ESCAPE)
		{
			endsdl(my_sdl);
			return (1);
		}
	}
	return (0);
}
