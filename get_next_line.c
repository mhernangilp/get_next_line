
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *buf;
	size_t	i;
	ssize_t	check;

	buf = malloc(50);
	i = 0;
	do {
		check = read(fd, buf + i, 1);
		if (!check)
			break;
		i++;
	}while (buf[i-1] != '\n');
	if (!check)
		return (NULL);
	buf[i] = '\0';
	return buf;
}
/*
int main(void)
{
	int	fd;
	char	*print;
	ssize_t	nr_bytes;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		printf("Error al abrir archivo\n");
	else
	{
		do {
			print = get_next_line(fd);
			if (print)
				printf("%s", print);
		}while (print);
		close(fd);
		if (!nr_bytes)
			printf("Archivo vacio\n");
		else
			printf("El numero de char es %d, contenido: %s\n", (int)nr_bytes, buf);
	}
	return 0;
}*/