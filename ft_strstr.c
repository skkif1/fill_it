/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:50:48 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/11/28 16:40:17 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strstr(const char *big, const char *ltl)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (ltl[0] == '\0')
		return ((char*)&big[0]);
	while (big[++i] != '\0')
	{
		j = 0;
		while ((big[i + j] == ltl[j]) && (ltl[j] != '\0'))
			j++;
		if (ltl[j] == '\0')
			return ((char*)&big[i]);
	}
	return (NULL);
}
