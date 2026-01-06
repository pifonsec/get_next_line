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

char *extract_next_line(char **buffer, int fd)
{
	char	*line;
	char	*tmp;
	char	temp_store[BUFFER_SIZE + 1];
	int		bytes_read;

	while (!find_new_line(*buffer))
	{
		bytes_read = read(fd, temp_store, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		temp_store[bytes_read] = '\0';
		tmp = *buffer;
		*buffer = ft_strjoin(tmp, temp_store);
		free(tmp);
		if (!*buffer)
			return (NULL);
	}
	if (!*buffer || **buffer == '\0')
		return (NULL);
	line = get_line(*buffer);
	tmp = *buffer;
	*buffer = get_remaining(tmp);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (extract_next_line(&buffer, fd));
}
