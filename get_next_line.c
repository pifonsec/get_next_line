/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:37:31 by pifonsec          #+#    #+#             */
/*   Updated: 2025/12/19 13:32:14 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **buffer)
{
	char	*line;
	char	*tmp;

	if (!*buffer)
		return (NULL);
	line = get_line(*buffer);
	if (!line)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	tmp = *buffer;
	*buffer = get_remaining(tmp);
	free(tmp);
	if (!*buffer || **buffer == '\0')
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*fill_buffer(char **buffer, int fd)
{
	char	temp_store[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*tmp;

	while (!find_new_line(*buffer))
	{
		bytes_read = read(fd, temp_store, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		temp_store[bytes_read] = '\0';
		tmp = *buffer;
		*buffer = ft_strjoin(tmp, temp_store);
		free(tmp);
		tmp = NULL;
		if (!*buffer)
			return (NULL);
	}
	if (!*buffer || **buffer == '\0')
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!fill_buffer(&buffer, fd))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (extract_line(&buffer));
}
