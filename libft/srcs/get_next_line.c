/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/27 13:48:22 by dfreire        #+#    #+#                */
/*   Updated: 2019/02/08 11:02:52 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*add_char(char const *s1, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = ft_strnew(n)))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

t_list			*get_list(int fd, t_list **list)
{
	t_list *temp;

	if (!list)
		return (NULL);
	temp = *list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("", fd);
	ft_lstadd(list, temp);
	return (temp);
}

static int		copy_file(char **line, char *file, char c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *line;
	while (file[i] && file[i] != c)
		i++;
	if (!(*line = add_char(file, i)))
		return (0);
	return (i);
}

static int		get_full_file(int fd, char **file)
{
	int		reading;
	char	*temp;
	char	buf[BUFF_SIZE + 1];

	while ((reading = read(fd, buf, BUFF_SIZE)))
	{
		buf[reading] = '\0';
		temp = *file;
		if (*file)
		{
			temp = *file;
			*file = ft_strjoin(*file, buf);
			free(temp);
			temp = NULL;
		}
		else
			*file = ft_strdup(buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (reading);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	size_t			result;
	static t_list	*list;
	t_list			*now;
	char			*temp;

	now = 0;
	if (fd < 0 || !line || (read(fd, buf, 0)) < 0 ||
		(!(now = get_list(fd, &list))))
		return (-1);
	temp = now->content;
	result = get_full_file(fd, &temp);
	now->content = temp;
	if (!result && !*temp)
		return (0);
	result = copy_file(line, now->content, '\n');
	temp = now->content;
	if (temp[result] != '\0')
	{
		now->content = ft_strdup(&((now->content)[result + 1]));
		free(temp);
	}
	else
		temp[0] = '\0';
	return (1);
}
