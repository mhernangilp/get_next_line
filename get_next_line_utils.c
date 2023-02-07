
#include "get_next_line.h"

int	get_line_length(int fd)
{
	ssize_t	check;
	size_t	i;
	char	*buf;

	buf = malloc(1);
	i = 0;
	do {
		check = read(fd, buf + i, 1);
		if (!check)
			break;
		i++;
	}while (buf[i-1] != '\n');
	return (i);
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
