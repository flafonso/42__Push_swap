/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:48:42 by flafonso          #+#    #+#             */
/*   Updated: 2019/07/01 12:03:46 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_check(t_stack *c, const char *str)
{
	int		i;
	int		s;
	int		p;
	int		n;

	i = 0;
	s = 0;
	p = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+')
			p = (n >= 1) ? (42) : (p + 1);
		if (str[i] == '-')
			s = (n >= 1) ? (42) : (s + 1);
		if (ft_isdigit(str[i]) == 1)
			n++;
		if (ft_isdigit(str[i]) == 0 && str[i] != '-' && str[i] != '+')
			error(c);
		i++;
	}
	if (s > 1 || p > 1 || n == 0 || (s >= 1 && p >= 1))
		error(c);
	return (p == 1) ? (2) : (s);
}

int			ft_atoi(t_stack *c, const char *str)
{
	int				i;
	int				s;
	long long		nb;

	i = 0;
	s = 1;
	nb = 0;
	if ((i = i + ft_check(c, str)) == 1)
		s = -1;
	if ((i = i + ft_check(c, str)) > 1)
		i = 1;
	while (ft_isdigit((int)str[i]) == 1)
	{
		nb = (nb * 10) + (str[i] - 48);
		if (s == 1 && nb > 2147483647)
			error(c);
		if (s == -1 && nb > 2147483648)
			error(c);
		i++;
	}
	return (nb * s);
}
