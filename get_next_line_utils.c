
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] && (i < (size - 1)))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (c);
}
