/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassar <mcassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 09:43:19 by mcassar           #+#    #+#             */
/*   Updated: 2017/02/23 11:20:48 by mcassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000
# include "Libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

int	get_next_line(const int fd, char **line);

#endif
