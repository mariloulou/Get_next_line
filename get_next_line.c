/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassar <mcassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 09:43:05 by mcassar           #+#    #+#             */
/*   Updated: 2017/05/07 13:14:33 by mcassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_inl(char *str, int i)
{
	size_t	n;

	if (!str[0])
		return (0);
	n = 0;
	while (str[n])
	{
		if (str[n] == '\n')
			return (n);
		n++;
	}
	if (i < 1)
		return (n);
	if (str[n] == '\0')
		return (0);
	return (n);
}

void	ft_str_realloc(char **str, char *buf, int i)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*str) + i;
	tmp = malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return ;
	ft_bzero(tmp, len + 1);
	ft_strcpy(tmp, *str);
	ft_strncat(tmp, buf, i);
	free(*str);
	*str = tmp;
}

int		gnl_without_lf(char **line, char **str, int i, int l)
{
	if (i == -1)
		return (-1);
	if (ft_strchr(*str, '\n') == NULL && *str[0] != '\0')
	{
		l = ft_inl(*str, i);
		i = ft_strlen(*str);
		*line = ft_strnew(l);
		ft_strncpy(*line, *str, l);
		ft_strncpy(*str, *str + l + 1, ft_strlen(*str) - l);
		*str[0] = '\0';
		return (1);
	}
	if (ft_strchr(*str, '\n') != NULL && *str[0] != '\0')
	{
		*line = ft_strnew(l);
		ft_strncpy(*line, *str, l);
		ft_strncpy(*str, *str + l + 1, ft_strlen(*str) - l);
		return (1);
	}
	else
	{
		ft_str_realloc(&*str, *line, i);
		return (0);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		buf[BUFF_SIZE];
	int			i;
	int			l;

	if (fd == -1)
		return (-1);
	i = 1;
	(!str) ? str = ft_strnew(0) : 0;
	while (i > 0)
	{
		l = ft_inl(str, i);
		if (l)
			return (gnl_without_lf(&*line, &str, i, l));
		else if (!l)
		{
			ft_bzero(buf, BUFF_SIZE);
			i = (read(fd, buf, BUFF_SIZE));
			if (i < 1)
				return (gnl_without_lf(&*line, &str, i, l));
			if (i)
				ft_str_realloc(&str, buf, i);
		}
	}
	return (0);
}
