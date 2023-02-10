/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:55:23 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/09 13:29:07 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*buf;
	char		*ret;
	ssize_t		check;
	size_t		i;

	buf = malloc(9999);
	if (!buf)
		return (NULL);
	i = 0;
	if (mem)
	{
		if (mem[0])
		{
			printf("Entro 1\n");
			ft_strcpy(buf, mem);
			i = ft_strlen(mem);
		}
		free(mem);
	}
	do {
		check = read(fd, &buf[i], BUFFER_SIZE);
		//write(1, "--", 2);
		//write(1, &buf[i], 10);
		//write(1, "--", 2);
		i += check;
	}while (check && !line_has_n(buf, i));
	if (!check)
		return (NULL);
	ret = malloc(sizeof(char) * line_has_n(buf, i) + 1);
	ft_strlcpy(ret, buf, line_has_n(buf, i) + 2);
	mem = ft_substr(buf, line_has_n(buf, i) + 1, i - line_has_n(buf, i));
	free(buf);
	return (ret);
}

int main(void)
{
	int	fd;
	char	*print;
	ssize_t	nr_bytes;

	fd = open("files/file.txt", O_RDONLY);
	if (fd == -1)
		printf("Error al abrir archivo\n");
	else
	{
		do {
			//printf("leo linea\n");
			print = get_next_line(fd);
			if (print)
				printf("'%s'", print);
		}while (print);
		close(fd);
		//if (!nr_bytes)
		//	printf("Archivo vacio\n");
		//else
		//	printf("El numero de char es %d, contenido: %s\n", (int)nr_bytes, buf);
	}
	return 0;
}
