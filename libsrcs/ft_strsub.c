/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 08:43:26 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/03 11:10:39 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

void	*ft_memalloc(size_t size)
{
	void	*tab;

	if (!(tab = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	s2 = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = len + 1;
	if (!(s) || !(str = ft_memalloc(i)))
		return (NULL);
	str = ft_strncpy(str, &s[start], len);
	return (str);
}
