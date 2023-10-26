/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:09:31 by alejango          #+#    #+#             */
/*   Updated: 2023/10/19 20:09:58 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
 * my_reading_file
 *
 * INPUT:		The file descriptor and the global string
 * OUTPUT:		A single string with '\n' (when happens),
 * 				NULL if there is nothing to read.
 * DESCRIPTION:	Iterative reading from file descriptor;
 * 				accumulative joining of the global string
 * 				with the just read buffer.
 *
 * */
char	*my_reading_file(int fd, char *str)
{
	char	*line;
	int		bytes;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (free_and_null(&str));
	bytes = 1;
	while (bytes > 0 && !ft_strchr(str, '\n'))
	{
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes > 0)
		{
			line[bytes] = '\0';
			str = ft_strjoin(str, line);
		}
	}
	free(line);
	if (bytes == -1)
		return (free_and_null(&str));
	return (str);
}

/*
 * clean_line
 *
 * INPUT: 		The global string
 * OUTPUT:		A single string without any '\n' occurences,
 * 				NULL if something was wrong.
 * DESCRIPTION: Gets the substring before the first occurence
 * 				of '\n' (when happens).
 * */
char	*clean_line(char *str)
{
	char	*line;
	char	*aux;
	size_t	length;

	aux = ft_strchr(str, '\n');
	if (!aux)
		length = ft_strlen(str);
	else
		length = aux - str + 1;
	line = ft_substr(str, 0, length);
	if (!line)
		return (NULL);
	return (line);
}

/*
 * clean_garbage
 *
 * INPUT:		The global string
 * OUTPUT:		A string with the remaining characters 
 * 				after '\n', NULL if something was wrong.
 * DESCRIPTION: Cleans the global string before the first
 * 				occurence of '\n' (when happens).
 * */
char	*clean_garbage(char *str)
{
	char	*line;
	char	*aux;
	size_t	length;

	aux = ft_strchr(str, '\n');
	if (!aux)
	{
		line = NULL;
		return (free_and_null(&str));
	}
	else
		length = aux - str + 1;
	if (!str[length])
		return (free_and_null(&str));
	line = ft_substr(str, length, ft_strlen(str) - length);
	free_and_null(&str);
	if (!line)
		return (NULL);
	return (line);
}

/*
 * free_and_null
 *
 * INPUT:		A pointer to the global string
 * OUTPUT:		Always NULL
 * DESCRIPTION: Frees the content of the given pointer,
 * 				then it points to NULL.
 * */
char	*free_and_null(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

/******************************************************/
/* The behavior is like standard 'get_next_line', but */
/* this one can handle multiple file descriptors at   */
/* once. OPEN_MAX is the maximum number of fd's that  */
/* can be opened at the same time.                    */
/******************************************************/
char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!str[fd] || !ft_strchr(str[fd], '\n'))
		str[fd] = my_reading_file(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = clean_line(str[fd]);
	if (!line)
		return (free_and_null(&str[fd]));
	str[fd] = clean_garbage(str[fd]);
	return (line);
}
