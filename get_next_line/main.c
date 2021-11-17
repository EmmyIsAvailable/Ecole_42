#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	char	*str = NULL;
	int i = 0;
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("line : %s", str);
		i++;
		free(str);
	}
	char	*oui = "oui";
	//printf("%s\n", ft_strjoin(str, oui));
	return (0);
}