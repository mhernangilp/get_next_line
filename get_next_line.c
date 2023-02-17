/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:55:23 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/17 12:23:20 by mhernang         ###   ########.fr       */
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
	//printf("Mem al inicio: '%s'\n", mem);
	if (mem && line_has_n(mem))
	{
		//printf("Ya tenemos en mem guardado con mem: %s\n", mem);
		ret = return_mem(mem, 1);
		mem = ret_out_mem(mem);
		return (ret);
	}
	check = 1;
	//printf("Mem antes de bucle: %s\n", mem);
	//printf("Check: %ld line_has_n: %d\n", check, line_has_n(mem));
	while (check && check != -1 && !line_has_n(mem))
	{
		//printf("Read buffer\n");
		check = read(fd, buf, BUFFER_SIZE);
		//printf("Check: %ld\n", check);
		if (check > 0)
			mem = cat_mem_buf(mem, buf, check);
	}
	//printf("Mem despues del bucle: %s\n", mem);
	if (check == -1)
	{
		//printf("Entro check -1\n");
		free(buf);
		return (NULL);
	} else if (line_has_n(mem))
	{
		//printf("Entro line_has_n(mem)\n");
		ret = return_mem(mem, 1);
		mem = ret_out_mem(mem);
		free(buf);
		return (ret);
	} else
	{
		//printf("Entro !check\n");
		if (mem[0] == '\0')
		{
			//printf("Entro mem[0] == /0\n");
			free(buf);
			free(mem);
			return (NULL);
		}
		ret = return_mem(mem, 0);
		mem = ret_out_mem(mem);
		return (ret);
	}
	//printf("Mem antes de salir: %s\n", mem);
	//system("leaks a.out");
}
/*
int main(void)
{
	int	fd;
	char	*print;
	ssize_t	nr_bytes;
	int	num = 50;

	fd = open("files/file.txt", O_RDONLY);
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
		close(fd);
		//if (!nr_bytes)
		//	printf("Archivo vacio\n");
		//else
		//	printf("El numero de char es %d, contenido: %s\n", (int)nr_bytes, buf);
	}
	return 0;
}*/
