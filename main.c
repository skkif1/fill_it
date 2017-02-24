/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:56:03 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/12/21 19:55:12 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_telem	**grab_elements(char **arguv)
{
	char	*buff;
	t_telem	**storage;

	if (!(buff = read_file(arguv[1])))
		return (NULL);
	if (!(validation_string(buff)))
		return (NULL);
	if (!(storage = ft_file_analyze(buff)))
		return (NULL);
	return (storage);
}

int		main(int argc, char **argv)
{
	t_telem	**storage;
	char	**map;

	if (argc != 2)
	{
		ft_putstr("usage : ./fillit source\n");
		return (0);
	}
	if (!(storage = grab_elements(argv)))
	{
		ft_putstr("error");
		return (0);
	}
	map = main_algo(storage);
	print(map);
	return (0);
}
