/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:59:58 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/12 20:59:28 by mhernang         ###   ########.fr       */
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

char	*ret_out_mem(char *mem, char *ret)
{
	char	*temp;

	temp = ft_strdup(&mem[line_has_n(mem) + 1]);
	free(mem);
	mem = temp;
	return (mem);
}

char	*return_mem(char *mem, int mode)
{
	int		len;
	char	*ret;
	char	*temp;

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

static void	sum(int *i, int *j)
{
	*i += 1;
	*j += 1;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	t = malloc(ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1);
	if (!t)
		return (NULL);
	while (s1[j])
	{
		t[i] = s1[j];
		sum(&i, &j);
	}
	j = 0;
	while (s2[j])
	{
		t[i] = s2[j];
		sum(&i, &j);
	}
	t[i] = '\0';
	return (t);
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

int	line_has_n(char *buf)
{
	ssize_t	j;

	j = 0;
	while (buf[j])
	{
		if (buf[j] == '\n')
			return (j);
		j++;
	}
	return (0);
}

