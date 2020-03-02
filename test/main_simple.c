
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int		fd;
	int		ret;
	char	*line;
	int		linecount;

	ret = 1;
	linecount = 1;
	fd = open("/Users/swofferh/Codam/projects/gnl/retry/read.txt", O_RDONLY);
	close(42);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (linecount > 9)
			printf("fd[%d] ret[%d] line[%d] ->%s\n", fd, ret, linecount, line);
		if (linecount < 10)
			printf("fd[%d] ret[%d] line[0%d] ->%s\n", fd, ret, linecount, line);
		if (ret >= 0)
			free(line);
		linecount++;
	}
}
