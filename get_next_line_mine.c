# include "get_next_line.h"

char	*read_and_accumulate(int fd, char *accumulation)
{
	char buffer[BUFFER_SIZE + 1];
	ssize_t		read_return;

	read_return = read(fd, buffer, BUFFER_SIZE);
	while (read_return > 0)
	{
		buffer[read_return] = '\0';
		accumulation = ft_strjoin(accumulation, buffer);
		// check for the new line , break
		if (ft_strchr(accumulation, '\n') >= 0)
			break;
		read_return = read(fd, buffer, BUFFER_SIZE);
	}
	return (accumulation);
}

char *get_next_line(int fd)
{
	static char *accumulation;

	if(fd < 0 || BUFFER_SIZE <=0 || read(fd, NULL, 0) < 0)
		return (NULL);
	// printf("buffer: %s\n", buffer);

	
	return (NULL);
}