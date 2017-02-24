/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:38:05 by omotyliu          #+#    #+#             */
/*   Updated: 2016/12/22 19:17:22 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **g_map;

int		set_point(t_telem *figure, int y, int x, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (y + figure->points[i].y < 0 || x + figure->points[i].x < 0 ||
			y + figure->points[i].y >= size ||
			x + figure->points[i].x >= size)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		g_map[y + figure->points[i].y][x + figure->points[i].x] = '.';
		i++;
	}
	return (1);
}

int		algo(t_telem **mass, int pos, int size)
{
	int y;
	int x;

	y = 0;
	x = 0;
	if (mass[pos] == NULL)
		return (1);
	while (y < size)
	{
		while (x < size)
		{
			if (place_figure(mass[pos], y, x, size))
			{
				if (algo(mass, pos + 1, size))
					return (1);
				else
					set_point(mass[pos], y, x, size);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

char	**main_algo(t_telem **mass)
{
	int		size;
	int		boolean;

	size = 0;
	while (mass[size] != NULL)
		size++;
	size = ft_sqrt_up(size * 4);
	init(size);
	boolean = algo(mass, 0, size);
	while (!boolean)
	{
		init(++size);
		boolean = algo(mass, 0, size);
	}
	return (g_map);
}

void	init(int size)
{
	int		i;
	char	*str;

	i = 0;
	g_map = (char **)malloc(sizeof(char**) * size + 1);
	while (i < size)
	{
		str = (char *)malloc(sizeof(char) * size + 1);
		fill_blank(str, size);
		g_map[i] = str;
		i++;
	}
	g_map[i] = NULL;
}

int		place_figure(t_telem *figure, int y, int x, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (y + figure->points[i].y < 0 || x + figure->points[i].x < 0 ||
			y + figure->points[i].y >= size ||
			x + figure->points[i].x >= size)
			return (0);
		if (ft_isalpha(g_map[y + figure->points[i].y][x + figure->points[i].x]))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		g_map[y + figure->points[i].y][x + figure->points[i].x] = figure->order;
		i++;
	}
	return (1);
}
