/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:32:43 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/01/03 15:43:32 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_new(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!new_buffer)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	return (free(buffer), new_buffer);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

void	ft_free2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*ft_read(int fd, char *buffer)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	tmp = ft_calloc((BUFFER_SIZE + 1), 1);
	if (!tmp)
		return (ft_free2d(&buffer), NULL);
	while (bytes_read)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(tmp), NULL);
		tmp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (!buffer)
			return (free(tmp), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(tmp), buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[FD_SETSIZE];
	int			i;

	i = -1;
	if (fd < 0 || fd >= FD_SETSIZE || BUFFER_SIZE <= 0)
		return (ft_free2d(buffer), NULL);
	while (++i < FD_SETSIZE)
	{
		buffer[i] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer[i])
			return (NULL);
	}
	if (!buffer[fd])
		return (NULL);
	if (read(fd, NULL, 0) < 0)
		return (ft_bzero(buffer[fd], BUFFER_SIZE + 1), NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	if (!line)
		return (ft_bzero(buffer[fd], BUFFER_SIZE + 1), NULL);
	buffer[fd] = ft_new(buffer[fd]);
	return (free(buffer), line);
}
