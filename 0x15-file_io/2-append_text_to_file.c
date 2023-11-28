#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file.
 * @filename: name of the file.
 * @text_content: content to append.
 *
 * Return: 1 if the file exists, -1 if the file doesn't exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;
	int letters_count;
	int bytes_written;

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
		return (-1);

	if (text_content)
	{
		for (letters_count = 0; text_content[letters_count]; letters_count++)
			;

		bytes_written = write(file_descriptor, text_content, letters_count);

		if (bytes_written == -1)
			return (-1);
	}

	close(file_descriptor);

	return (1);
}

