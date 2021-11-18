#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	char	*str;
	int i = 0;
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%d : %s", i, str);
		i++;
		free(str);
	}
	return (0);
}