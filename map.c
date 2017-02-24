/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:48:49 by omotyliu          #+#    #+#             */
/*   Updated: 2016/12/23 18:12:35 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_blank(char *str, int len)
{
	int i;

	i = -1;
	while (++i < len)
		str[i] = '.';
	str[i] = '\0';
}

void	print(char **mass)
{
	int i;

	i = 0;
	while (mass[i] != '\0')
		ft_putendl(mass[i++]);
}

void	check_height(char *str)
{
	int i;
	int	other;
	int	height;

	other = 0;
	i = -1;
	height = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '\n')
			height++;
		else
			other++;
		if (height == 4)
		{
			if (other / 4 != 4)
			{
				ft_putstr("error");
				exit(0);
			}
			other = 0;
			height = 0;
			i++;
		}
	}
}
