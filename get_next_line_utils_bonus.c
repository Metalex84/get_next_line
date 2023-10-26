/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:10:14 by alejango          #+#    #+#             */
/*   Updated: 2023/10/19 20:10:34 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
 * ft_strchr
 *
 * INPUT:		A string and ASCII value
 * OUTPUT:		A pointer to the first occurence of the
 * 				character; zero if the character doesn't
 * 				belong to the string.
 * */
char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return (&((char *)str)[i]);
	if (str[i] == (char)c)
		return (&((char *)str)[i]);
	return (0);
}

/*
 * ft_strjoin
 *
 * INPUT:		Two strings
 * OUTPUT:		A string formed by the union of s1 and s2.
 * 				It allocates memory enough to store both strings,
 * 				and frees the 1st string.
 * 				Returns NULL if anything was wrong.
 * */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		c;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (free_and_null(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}

/*
 * ft_strlen
 *
 * INPUT:		A string
 * OUTPUT:		The length of the string
 * */
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
 * ft_substr
 *
 * INPUT:		A string, an index and number of positions
 * OUTPUT:		The substring from str, starting in 'start'
 * 				index, sized on 'len' bytes. NULL if there
 * 				isn't nothing to return.
 * */
char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
	{
		res = (char *)malloc(sizeof(char));
		if (!res)
			return (NULL);
		*res = '\0';
		return (res);
	}
	if (ft_strlen(str) - start < len)
		len = ft_strlen(str) - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < ft_strlen(str) && i < len && str[start])
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}
