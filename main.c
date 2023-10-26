#include "get_next_line.h"
// #include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    char *line;
    int fd;
	int fd2;

	// No arguments: reading from stdin
    if (argc == 1)
    {
        fd = 0;
        while ((line = get_next_line(fd)))
		{
			write(1, line, ft_strlen(line));
			free(line);
		}
		write(1, "\n", 1);
    }
    else if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while ((line = get_next_line(fd)))
        {
            write(1, line, ft_strlen(line));
            free(line);
        }
        write(1, "\n", 1);
		close(fd);
    }
	else if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while (((line = get_next_line(fd))) || ((line = get_next_line(fd2))))
		{
			write(1, line, ft_strlen(line));
			free(line);
		}
		write(1, "\n", 1);
		close(fd);
		close(fd2);
	}
    else
        write(1, "Error de parametros...\n", 23);
    return (0);
}
