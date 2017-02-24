/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:33:41 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/12/11 19:22:09 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	ft_cntwrds(const char *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = -1;
	cnt = 0;
	while (s[++i] != '\0')
		if (((s[i] != c) && (s[i - 1] == c)) || ((s[i] != c) && (i == 0)))
			cnt++;
	return (cnt);
}

static size_t	ft_cntlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	wrdlen;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(res = (char**)malloc(sizeof(char*) * (ft_cntwrds(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else if (*s != c)
		{
			wrdlen = ft_cntlen(s, c);
			res[i] = ft_strnew(wrdlen);
			ft_strncpy(res[i++], s, wrdlen);
			s += wrdlen;
		}
	}
	res[i] = NULL;
	return (res);
}
