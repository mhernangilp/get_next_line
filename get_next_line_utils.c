/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:59:58 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/19 19:36:29 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cat_mem_buf(char *mem, char *buf, int read)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (mem)
		temp = malloc(ft_strlen(mem) + read + 1);
	else
		temp = malloc(read + 1);
	if (mem)
		while (mem[i])
		{
			temp[j] = mem[i];
			i++;
			j++;
		}
	i = 0;
	while (read > 0)
	{
		temp[j] = buf[i];
		i++;
		j++;
		read--;
	}
	temp[j] = '\0';
	free(mem);
	mem = temp;
	return (mem);
}

char	*ret_out_mem(char *mem)
{
	char	*temp;

	if (!mem)
		return (NULL);
	if (line_has_n(mem) != -1)
		temp = ft_strdup(&mem[line_has_n(mem) + 1]);
	else
		temp = ft_strdup(&mem[ft_strlen(mem)]);
	free(mem);
	mem = temp;
	return (mem);
}

char	*return_mem(char *mem, int mode)
{
	int		len;
	char	*ret;

	if (!mem)
		return (NULL);
	if (!mode)
		len = ft_strlen(mem);
	else
		len = line_has_n(mem) + 1;
	ret = ft_substr(mem, 0, len);
	return (ret);
}

char	*ft_strdup(const char *src)
{
	char	*target;

	target = malloc(ft_strlen(src) + 1);
	if (!target)
		return (NULL);
	ft_strcpy(target, src);
	return (target);
}

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

int	line_has_n(char *buf)
{
	ssize_t	j;

	if (!buf)
		return (-1);
	j = 0;
	while (buf[j])
	{
		if (buf[j] == '\n')
			return (j);
		j++;
	}
	return (-1);
}

