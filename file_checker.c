/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:00:44 by omotyliu          #+#    #+#             */
/*   Updated: 2016/12/23 18:10:55 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const char *g_storage[] = {
	"#...#..##", "#...###", "##..#...#", "###...#",
	"#...#...##", "###.#", "##...#...#", "#.###",
	"##..##", "####", "#...#...#...#", "#...##...#",
	"##.##", "#..##..#", "##...##", "#..###",
	"#...##..#", "###..#", "#..##...#"};
const int	g_storage_pos[19][8] = {
	{0, 0, 1, 0, 2, 0, 2, -1}, {0, 0, 1, 0, 1, 1, 1, 2},
	{0, 0, 0, 1, 1, 0, 2, 0}, {0, 0, 0, 1, 0, 2, 1, 2},
	{0, 0, 1, 0, 2, 0, 2, 1}, {0, 0, 0, 1, 0, 2, 1, 0},
	{0, 0, 0, 1, 1, 1, 2, 1}, {0, 0, 1, 0, 1, -1, 1, -2},
	{0, 0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 1, 0, 2, 0, 3},
	{0, 0, 1, 0, 2, 0, 3, 0}, {0, 0, 1, 0, 1, 1, 2, 1},
	{0, 0, 0, 1, 1, 0, 1, -1}, {0, 0, 1, 0, 1, -1, 2, -1},
	{0, 0, 0, 1, 1, 1, 1, 2}, {0, 0, 1, 0, 1, -1, 1, 1},
	{0, 0, 1, 0, 1, 1, 2, 0}, {0, 0, 0, 1, 0, 2, 1, 1},
	{0, 0, 1, 0, 2, 0, 1, -1}};

char	*read_file(char *file_name)
{
	int		file;
	int		i;
	char	*buff;

	buff = ft_strnew(547);
	if ((file = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	if ((i = read(file, buff, 547)) == -1)
		return (NULL);
	if (ft_strlen(buff) > 546 || (ft_strlen(buff) + 1) % 21 != 0)
		return (NULL);
	return (buff);
}

int		validation_string(char *buff)
{
	int i;
	int dies;
	int point;
	int nl;
	int fig;

	i = 0;
	dies = 0;
	point = 0;
	nl = 0;
	fig = (ft_strlen(buff) + 1) / 21;
	while (buff[i] != '\0')
	{
		if (buff[i] == '#')
			dies++;
		if (buff[i] == '.')
			point++;
		if (buff[i] == '\n')
			nl++;
		i++;
	}
	nl++;
	if ((dies / fig) == 4 && (point / fig) == 12 && (nl / fig) == 5)
		return (1);
	return (0);
}

t_point	*set_points(int pos)
{
	int			i;
	int			j;
	t_point		*points;
	t_point		*point;

	i = 0;
	j = 0;
	points = (t_point*)malloc(sizeof(t_point*));
	while (i < 8)
	{
		point = (t_point *)malloc(sizeof(t_point*));
		point->y = g_storage_pos[pos][i++];
		point->x = g_storage_pos[pos][i++];
		points[j++] = *point;
	}
	return (points);
}

t_telem	*check_pattern(char *str, int order)
{
	int		i;
	t_telem *figure;

	i = -1;
	while (g_storage[++i] != NULL)
	{
		if (ft_strstr(str, g_storage[i]) != NULL)
			break ;
		if (i == 18)
			return (NULL);
	}
	figure = (t_telem*)malloc(sizeof(t_telem*));
	figure->order = order + 65;
	figure->points = set_points(i);
	return (figure);
}

t_telem	**ft_file_analyze(char *str)
{
	t_telem	**out;
	char	**s;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(temp = (char*)malloc(sizeof(char) * 17)))
		return (NULL);
	s = check_split(str, '\n');
	if (!(figure_check(s)))
		return (NULL);
	out = (t_telem**)malloc(sizeof(t_telem*) * ((ft_strlen(str) + 1) / 21) + 1);
	while (s[i] != NULL)
	{
		temp = ft_strcat(ft_strcat(s[i], s[i + 1]),
				ft_strcat(s[i + 2], s[i + 3]));
		if (!(out[j] = check_pattern(temp, j)))
			return (NULL);
		j++;
		i = i + 4;
	}
	out[j++] = NULL;
	return (out);
}
