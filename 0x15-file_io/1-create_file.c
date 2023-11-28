#include "main.h"

/**
 * create_file - creates a file and writes content to it.
 * @filename: name of the file.
 * @text_content: content to be written in the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor;
	int letters_count;
	int bytes_written;

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_descriptor == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (letters_count = 0; text_content[letters_count]; letters_count++)
		;

	bytes_written = write(file_descriptor, text_content, letters_count);

	if (bytes_written == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}

