/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pifonsec <pifonsec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:37:31 by pifonsec          #+#    #+#             */
/*   Updated: 2026/02/11 11:50:52 by pifonsec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_buffer(char **buffer)
{
	if (!*buffer || **buffer == '\0')
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (*buffer);
}

static char	*extract_line(char **buffer)
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

static char	*fill_buffer(char **buffer, int fd)
{
	char	*temp_store;
	int		bytes_read;
	char	*tmp;

	temp_store = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_store)
		return (NULL);
	while (!find_new_line(*buffer))
	{
		bytes_read = read(fd, temp_store, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		temp_store[bytes_read] = '\0';
		tmp = *buffer;
		*buffer = ft_strjoin(tmp, temp_store);
		if (!*buffer)
			return (NULL);
		free(tmp);
	}
	free(temp_store);
	check_buffer(buffer);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line_stock;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 10000000 || fd < 0)
		return (NULL);
	if (!fill_buffer(&buffer, fd))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line_stock = extract_line(&buffer);
	if (line_stock == NULL)
	{
		free(line_stock);
		return (NULL);
	}
	return (line_stock);
}
