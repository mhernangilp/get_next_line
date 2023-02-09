/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:55:23 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/09 11:14:23 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*ret;
	size_t	i;
	ssize_t	check;

	if (fd < 0)
		return (NULL);
	buf = malloc(9999);
	if (!buf)
		return (NULL);
	i = 0;
	do
		check = read(fd, &buf[i++], BUFFER_SIZE);
	while (buf[i - 1] != '\n' && check);
	if (!check)
	{
		if (i == 1)
		{
			free(buf);
			return (NULL);
		}
		else
			i--;
	}
	buf[i] = '\0';
	ret = malloc(sizeof(char) * i + 1);
	ft_strcpy(ret, buf);
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
				printf("%s", print);
		}while (print);
		close(fd);
		//if (!nr_bytes)
		//	printf("Archivo vacio\n");
		//else
		//	printf("El numero de char es %d, contenido: %s\n", (int)nr_bytes, buf);
	}
	return 0;
}
