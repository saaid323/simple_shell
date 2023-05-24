#include "shell.h"

/**
 * prompt - Displays the shell prompt.
 */
void prompt(void)
{
	int _isatty = isatty(0);

	if (_isatty)
	{
		my_write(STDOUT_FILENO, "#cisfun$ ", 10);
	}
}

/**
 * my_write - Writes data to a file descriptor.
 * @fd: File descriptor to write to.
 * @buf: Pointer to the buffer containing the data.
 * @count: Number of bytes to write.
 * Return: Number of bytes written on success, -1 on failure.
 */
ssize_t my_write(int fd, const void *buf, size_t count)
{
	const char *c_buf = buf;
	size_t bytes_written = 0;

	while (bytes_written < count)
	{
		ssize_t result = write(fd, c_buf + bytes_written, count - bytes_written);

		if (result == -1)
		{
			return (-1);
		}
		bytes_written += result;
	}
	return (bytes_written);
}
