/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:55:34 by flafonso          #+#    #+#             */
/*   Updated: 2019/07/01 17:56:53 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE  1024
# include <SDL2/SDL.h>

typedef struct	s_my_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Rect		rect;
	int				delay;
	int				v;
	int				max;
	int				w_l;
	int				w_h;
}				t_my_sdl;

typedef struct	s_stack
{
	int			*tab_a;
	int			*tab_b;
	int			*tab_c;
	int			n;
	int			na;
	int			nb;
	int			nb_ra;
	int			nb_rb;
	int			last_blk;
	int			not_rrb;
	int			checker;
	struct s_op	*op;
}				t_stack;

typedef struct	s_op
{
	char			*arg;
	struct s_op		*next;
	struct s_op		*pres;
}				t_op;

typedef struct	s_listt
{
	char			*str;
	int				fd;
	int				i;
	struct s_listt	*next;
}				t_listt;

typedef struct	s_qsort
{
	int				nb_p;
	struct s_qsort	*next;
	struct s_qsort	*pres;
}				t_qsort;

int				push_swap(t_stack *c);
int				fill(int ac, char **av, t_stack *c);
void			error(t_stack *c);
void			error_chck(t_stack *c, t_my_sdl *my_sdl);
int				count_nb_word(char const *str, char c);
int				count_arg(int ac, char **av);
void			ft_dnb(t_stack *c);
int				checker(t_stack *c, t_my_sdl *my_sdl);
int				check_sort(t_stack *c, int max, int min, int s);
int				mediane(int *tab, int max, int min, int nb);
int				higher_p(int max, int *tab, int dep, int p);
int				lower_p(int max, int *tab, int dep, int p);
t_op			*new_op(t_stack *c, t_op *op, char *str);
void			op_del_one(t_op *op);
void			pre_print(t_op *op);
void			push_init(t_stack *c, int ac, char **av);
void			checker_init(t_stack *c, t_my_sdl *my_sdl, int ac, char **av);
void			print_op(t_op *op);
void			swap_after_push(t_stack *c, int ia, int ib, char det);
t_qsort			*new_qs(t_stack *c, t_qsort *list);
int				next_for_b(t_stack *c, int ib, int fin, int p);
int				next_for_a(t_stack *c, int ia, int fin, int p);
t_op			*the_start(t_op *op);
void			free_qs(t_qsort *qs);
void			free_all(t_stack *c);
void			print_visu(t_stack *c, t_my_sdl *my_sdl);
void			fill_visu_a(t_stack *c, t_my_sdl *my_sdl);
int				ft_max(t_stack *c);
void			visu_init(t_my_sdl *my_sdl, int v, int n);
int				nbgood(t_stack *c);
int				qs_tab_a(t_stack *c, int dep, int fin);
void			one_block(t_stack *c, int push);
void			pg_small_a(t_stack *c, int dep, int fin);
int				small_b(t_stack *c, int dep, int fin);
void			ft_sa(t_stack *c);
void			ft_sb(t_stack *c);
void			ft_ra(t_stack *c);
void			ft_rb(t_stack *c);
void			ft_pa(t_stack *c);
void			ft_pb(t_stack *c);
void			ft_rra(t_stack *c);
void			ft_rrb(t_stack *c);
int				ft_atoi(t_stack *c, const char *str);
int				ft_isdigit(int c);
int				ft_isspace(int c);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
void			ft_putnbr(int nbr);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
int				get_next_line(const int fd, char **line);
char			*ft_strchr(const char *s, int c);
char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
void			ft_strdel(char **as);
int				ft_cmp(const char *s1, const char *s2);
void			ft_memdel(void **ap);
int				sdl_event(t_my_sdl *my_sdl);
void			sdl_sleep(void);
void			sdl_wait_end(void);
void			endsdl(t_my_sdl *my_sdl);
void			last_small_a(t_stack *c);

#endif
