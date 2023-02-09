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

int	line_has_n(char *buf, size_t i)
{
	size_t	j;

	j = 0;
	while (j <= i)
	{
		if (buf[j] == '\n')
			return (j);
		j++;
	}
	return (0);
}

char	*option2(int fd, char *buf, char *ret)
{
	size_t	i;
	size_t	bread;

	i = 0;
	do
	{
		printf("Entro bucle con bread: '%ld' y i: '%ld y fd: '%d''\n", bread, i, fd);
		bread = read(fd, &buf[i], BUFFER_SIZE);
		i += bread;
		printf("Termino el bucle con bread: '%ld' y i: '%ld'\n", bread, i);
	}
	while (bread && (!line_has_n(buf, i)));
	if (!line_has_n(buf, i))
		return (NULL);
	printf("i: '%ld' line_has_n: '%d'\n", i, line_has_n(buf, i));
	buf[line_has_n(buf, i) + 1] = '\0';
	ret = malloc(sizeof(char) * line_has_n(buf, i) + 1);
	printf("salgo\n");
	ft_strcpy(ret, buf);
	printf("%s\n", buf);
	printf("%s\n", ret);
	//fd = 
	return ret;
}
