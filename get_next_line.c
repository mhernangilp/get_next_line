
#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*buf;
	char	*ret;
	size_t	i;
	ssize_t	check;

	if (fd < 0)
		return (NULL);
	buf = malloc(1000100);
	if (!buf)
		return (NULL);
	i = 0;
	do {
		check = read(fd, &buf[i], 1);
		//printf("Leo el caracter '%c' con check = %zd\n", buf[i], check);
		i++;
	}while (buf[i-1] != '\n' && check);
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
	return ret;
}
/*
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
}*/
