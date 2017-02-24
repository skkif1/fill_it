/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:19:49 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/12/23 18:14:08 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_pow(int nb, int power)
{
	if (power < 1)
		if (power == 0)
			return (1);
		else
			return (0);
	else if (power > 1)
		nb = nb * ft_pow(nb, --power);
	return (nb);
}

int			ft_sqrt_up(int n)
{
	int	i;

	i = 0;
	while (++i < n)
	{
		if ((n >= ft_pow(i, 2)) && (n <= ft_pow(i + 1, 2)))
		{
			if (n == ft_pow(i, 2))
				return (i);
			else
				return (i + 1);
		}
	}
	return (i + 1);
}

static int	neighbour_check(char **s, int x, int y, int bg)
{
	int	flag;

	flag = 0;
	if (s[y][x] == '.')
		return (1);
	if (s[y][x + 1] == '#')
		flag++;
	if (y > 0)
		if ((s[y - 1][x] == '#') && (y > bg))
			flag++;
	if (x > 0)
		if (s[y][x - 1] == '#')
			flag++;
	if (s[y + 1] != NULL)
		if ((s[y + 1][x] == '#') && (y < bg + 3))
			flag++;
	if (flag == 0)
		return (0);
	return (1);
}

int			figure_check(char **s)
{
	int bg;
	int x;
	int y;

	bg = 0;
	y = -1;
	while (s[++y] != NULL)
	{
		x = -1;
		while (s[y][++x] != '\0')
		{
			if (!(neighbour_check(s, x, y, bg)))
				return (0);
		}
		if ((y + 1) % 4 == 0)
			bg = y + 1;
	}
	return (1);
}

char		**check_split(char *str, char n)
{
	char	**s;
	int		i;

	i = 0;
	check_height(str);
	s = ft_strsplit(str, n);
	while (s[i] != NULL)
	{
		if (ft_strlen(s[i]) != 4)
		{
			ft_putstr("error");
			exit(0);
		}
		i++;
	}
	return (s);
}
