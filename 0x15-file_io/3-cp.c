#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

/**
 * error_message - prints error messages.
 * @error_code: error number.
 * @file_name: name of the file related to the error.
 *
 * Description: prints error messages based on the given
 * error number and file name.
 */
void error_message(int error_code, char *file_name)
{
	if (error_code == 97)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	else if (error_code == 98)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
	else if (error_code == 99)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
	else if (error_code == 100)
		dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", file_name);
}

/**
 * copy_file - copies content from one file to another.
 * @file_from: source file to copy from.
 * @file_to: destination file to copy to.
 *
 * Return: 0 on success, otherwise error numbers.
 *
 * Description: copies the content from file_from to file_to.
 */
int copy_file(char *file_from, char *file_to)
{
	int file_from_fd, file_to_fd, err_close;
	ssize_t nread, nwrite;
	char buffer[BUFFER_SIZE];

	file_from_fd = open(file_from, O_RDONLY);
	if (file_from_fd == -1)
	{
		error_message(98, file_from);
		return (98);
	}
	file_to_fd = open(file_to, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file_to_fd == -1)
	{
		error_message(99, file_to);
		return (99);
	}
	while ((nread = read(file_from_fd, buffer, BUFFER_SIZE)) > 0)
	{
		nwrite = write(file_to_fd, buffer, nread);
		if (nwrite == -1 || nwrite != nread)
		{
			error_message(99, file_to);
			return (99);
		}
	}
	if (nread == -1)
	{
		error_message(98, file_from);
		return (98);
	}
	err_close = close(file_from_fd);
	if (err_close == -1)
	{
		error_message(100, file_from);
		return (100);
	}
	err_close = close(file_to_fd);
	if (err_close == -1)
	{
		error_message(100, file_to);
		return (100);
	}
	return (0);
}

/**
 * main - entry point.
 * @argc: number of arguments.
 * @argv: array of arguments.
 *
 * Return: 0 on success, otherwise error codes.
 *
 * Description: main function to copy the content of a file to another.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		error_message(97, NULL);
		return (97);
	}

	return (copy_file(argv[1], argv[2]));
}

