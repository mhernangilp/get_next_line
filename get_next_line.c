/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:55:23 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/19 20:43:30 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*mem = NULL;
	char		*buf;
	char		*ret;
	ssize_t		check;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	if (mem && line_has_n(mem) != -1)
	{
		ret = return_mem(mem, 1);
		mem = ret_out_mem(mem);
		free(buf);
		return (ret);
	}
	check = 1;
	while (check && check != -1 && line_has_n(mem) == -1)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check > 0)
			mem = cat_mem_buf(mem, buf, check);
	}
	if (check == -1)
	{
		if (mem)
		{
			free(mem);
			mem = NULL;
		}
		free(buf);
		return (NULL);
	}
	else if (line_has_n(mem) != -1)
	{
		ret = return_mem(mem, 1);
		mem = ret_out_mem(mem);
		free(buf);
		return (ret);
	}
	else
	{
		if (mem && mem[0] == '\0')
		{
			free(buf);
			free(mem);
			mem = NULL;
			return (NULL);
		}
		ret = return_mem(mem, 0);
		mem = ret_out_mem(mem);
		free(buf);
		return (ret);
	}
}

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
		temp[j++] = mem[i++];
	i = 0;
	while (read > 0)
	{
		temp[j++] = buf[i++];
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
