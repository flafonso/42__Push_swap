/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:22:25 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/03 13:51:07 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char		**free_dst(char **dst, int i)
{
	int		j;

	j = 0;
	while (j <= i)
	{
		free(dst[j]);
		j++;
	}
	free(dst);
	return (NULL);
}

static int		count_char(char const *str, int i, char c, int skip)
{
	int		nb_char;

	nb_char = 0;
	if (skip == 1)
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		return (i);
	}
	else
	{
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			nb_char++;
		}
	}
	return (nb_char);
}

int				count_nb_word(char const *str, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		i = count_char(str, i, c, 1);
	}
	return (word);
}

static char		**strsplit(char const *s, char c, char **dest, int len)
{
	int				i;
	int				nb_char;
	unsigned int	i_s;

	i = 0;
	i_s = 0;
	nb_char = 0;
	if (!(dest = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (i_s == 0 && s[0] == c)
			i_s = count_char(s, i_s, c, 1);
		nb_char = count_char(s, i_s, c, 0);
		if (!(dest[i] = ft_strsub(s, i_s, nb_char)))
			return (free_dst(dest, i));
		i++;
		i_s = count_char(s, nb_char + i_s, c, 1);
	}
	dest[i] = NULL;
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**dst;
	int				len;

	dst = NULL;
	len = count_nb_word(s, c);
	if (!s)
		return (NULL);
	dst = strsplit(s, c, dst, len);
	return (dst);
}
