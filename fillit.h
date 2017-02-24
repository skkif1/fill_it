/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:31:50 by omotyliu          #+#    #+#             */
/*   Updated: 2016/12/22 19:22:55 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_telem
{
	t_point	*points;
	char	order;
}				t_telem;
void			*ft_memalloc(size_t size);
void			check_height(char *str);
char			**check_split(char *str, char n);
void			*ft_memset(void *src, int ch, size_t len);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_isalpha(int c);
void			ft_putchar(char c);
char			*ft_strcpy(char *dest, const char *src);
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
char			*ft_strcat(char *s1, const char *s2);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *big, const char *sub);
int				validation_string(char *str);
t_point			*set_points(int pos);
t_telem			*check_pattern(char *str, int order);
t_telem			**ft_file_analyze(char *str);
char			*read_file(char *file_name);
int				ft_sqrt_up(int n);
int				figure_check(char **s);
int				place_figure(t_telem *figure, int y, int x, int size);
void			init(int size);
void			print(char **mass);
void			fill_blank(char *str, int size);
char			**main_algo(t_telem **mass);

#endif
