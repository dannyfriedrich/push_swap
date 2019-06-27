/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/27 13:48:42 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/22 10:23:46 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 128

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int	get_next_line(const int fd, char **line);

#endif
