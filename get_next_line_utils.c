/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:59:58 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/09 12:18:34 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = ft_strlen(src);
	if (size != 0)
	{
		while ((src[i] != '\0') && (i < (size - 1)))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (c);
}

static int	get_optimal_len(char const *s, unsigned int start, size_t len)
{
	size_t	len_str;

	len_str = ft_strlen(&s[start]);
	if (len < len_str)
		return (len);
	return (len_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*t;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		t = malloc(1);
		if (!t)
			return (NULL);
		t[0] = 0;
		return (t);
	}
	t = malloc ((get_optimal_len(s, start, len) * sizeof(char)) + 1);
	if (!t)
		return (NULL);
	while (s[start] && len > 0)
	{
		t[i++] = s[start];
		len--;
		start++;
	}
	t[i] = '\0';
	return ((char *) t);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	line_has_n(char *buf, size_t i)
{
	ssize_t	j;

	j = 0;
	while (j <= i)
	{
		if (buf[j] == '\n')
			return (j);
		j++;
	}
	return (0);
}

