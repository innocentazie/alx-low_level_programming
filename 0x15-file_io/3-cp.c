#include "main.h"
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * error_file - handles file-related errors and exits accordingly.
 * @file_from: file descriptor for file_from.
 * @file_to: file descriptor for file_to.
 *
 * Description: exits with appropriate error codes based on file operations.
 */
void error_file(int file_from, int file_to)
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file\n");
		exit(99);
	}
}

/**
 * open_files - opens file_from and file_to and performs error handling.
 * @file_from: name of file to be copied.
 * @file_to: name of destination file.
 *
 * Return: file descriptor for file_to.
 *
 * Description: opens the files and checks for errors.
 */
int open_files(char *file_from, char *file_to)
{
	int file_from_fd = open(file_from, O_RDONLY);
	int file_to_fd = open(file_to, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	if (file_from_fd == -1 || file_to_fd == -1)
	{
		error_file(file_from_fd, file_to_fd);
	}

	return (file_to_fd);
}

/**
 * copy_file_content - copies content from file_from to file_to.
 * @file_from_fd: file descriptor of source file.
 * @file_to_fd: file descriptor of destination file.
 *
 * Description: reads content from source file and writes to destination file.
 */
void copy_file_content(int file_from_fd, int file_to_fd)
{
	ssize_t nchars, nwr;
	char buf[BUFFER_SIZE];

	while ((nchars = read(file_from_fd, buf, BUFFER_SIZE)) > 0)
	{
		if (nchars == -1)
			error_file(-1, 0);
		nwr = write(file_to_fd, buf, nchars);
		if (nwr == -1)
			error_file(0, -1);
	}

	if (nchars == -1)
		error_file(-1, 0);
}

/**
 * close_files - closes file descriptors for file_from and file_to.
 * @file_from_fd: file descriptor of source file.
 * @file_to_fd: file descriptor of destination file.
 *
 * Description: closes the file descriptors and checks for errors.
 */
void close_files(int file_from_fd, int file_to_fd)
{
	int err_close;

	err_close = close(file_from_fd);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close source file\n");
		exit(100);
	}

	err_close = close(file_to_fd);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close destination file\n");
		exit(100);
	}
}

/**
 * main - copies content of a file to another file.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: always 0.
 *
 * Description: checks arguments, performs file copy, and handles errors.
 */
int main(int argc, char *argv[])
{
	int file_to_fd;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_to_fd = open_files(argv[1], argv[2]);
	copy_file_content(file_to_fd, file_to_fd);
	close_files(file_to_fd, file_to_fd);

	return (0);
}

