#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char *read_and_accumulate(int fd, char *accumulation)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        accumulation = ft_strjoin(accumulation, buffer);
        if (ft_strchr(accumulation, '\n') != -1)
            break;
    }
    return accumulation;
}

char *extract_line(char **accumulation)
{
    char *line;
    int newline_pos = ft_strchr(*accumulation, '\n');
    if (newline_pos != -1)
    {
        line = ft_substr(*accumulation, 0, newline_pos + 1);
        char *new_accumulation = ft_strdup(*accumulation + newline_pos + 1);
        free(*accumulation);
        *accumulation = new_accumulation;
    }
    else
    {
        line = ft_strdup(*accumulation);
        free(*accumulation);
        *accumulation = NULL;
    }
    return line;
}

char *get_next_line(int fd)
{
    static char *accumulation;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
        return NULL;
    accumulation = read_and_accumulate(fd, accumulation);
    if (!accumulation || !*accumulation)
    {
        free(accumulation);
        accumulation = NULL;
        return NULL;
    }
    return extract_line(&accumulation);
}