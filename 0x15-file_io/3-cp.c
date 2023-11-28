#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_file - handles file-related errors and exits accordingly.
 * @file_from: file descriptor for file_from.
 * @file_to: file descriptor for file_to.
 * @argv: arguments vector.
 */
void error_file(int file_from, int file_to, char *argv[]) {
    if (file_from == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }
    if (file_to == -1) {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        exit(99);
    }
}

/**
 * main - copies content of a file to another file.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: always 0.
 */
int main(int argc, char *argv[]) {
    int file_from, file_to, err_close;
    ssize_t nchars, nwr;
    char buf[BUFFER_SIZE];

    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    file_from = open(argv[1], O_RDONLY);
    file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC,
                   S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

    error_file(file_from, file_to, argv);

    while ((nchars = read(file_from, buf, BUFFER_SIZE)) > 0) {
        if (nchars == -1)
            error_file(-1, 0, argv);
        nwr = write(file_to, buf, nchars);
        if (nwr == -1)
            error_file(0, -1, argv);
    }

    if (nchars == -1) {
        error_file(-1, 0, argv);
    }

    err_close = close(file_from);
    if (err_close == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
        exit(100);
    }

    err_close = close(file_to);
    if (err_close == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
        exit(100);
    }
    return (0);
}

