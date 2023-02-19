/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:55:23 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/19 20:19:30 by mhernang         ###   ########.fr       */
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
	} else if (line_has_n(mem) != -1)
	{
		ret = return_mem(mem, 1);
		mem = ret_out_mem(mem);
		free(buf);
		return (ret);
	} else
	{
		if (mem)
		{
			if (mem[0] == '\0')
			{
				free(buf);
				free(mem);
				mem = NULL;
				return (NULL);
			}
		}
		ret = return_mem(mem, 0);
		mem = ret_out_mem(mem);
		free(buf);
		return (ret);
	}
}
/*
int main(void)
{
	int	fd;
	char	*print;
	ssize_t	nr_bytes;
	int	num = 50;

	fd = open("files/read_error.txt", O_RDONLY);
	if (fd == -1)
		printf("Error al abrir archivo\n");
	else
	{
		do {
			//printf("leo linea\n");
			print = get_next_line(fd);
			if (print)
				printf("Sol: '%s'\n", print);
		}while (print && --num > 0);
		printf("%s\n", get_next_line(fd));
		close(fd);
		//if (!nr_bytes)
		//	printf("Archivo vacio\n");
		//else
		//	printf("El numero de char es %d, contenido: %s\n", (int)nr_bytes, buf);
	}
	return 0;
}*/
