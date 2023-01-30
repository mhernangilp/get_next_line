
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
