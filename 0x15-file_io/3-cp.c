#include "main.h"
#include <stdio.h>

/**
 * cp_file - copys the content of one file to another.
 * @file_from: first file
 * @file_to: second file
 * @argv: Argument vector
 *
 * Return: no return
 */
void cp_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

}
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from;
	int file_to;
	int error_close;

	ssize_t nch;
	ssize_t nbw;
	char buffer[1024];

	if (argc < 3 || argc > 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	file_from = open(argv[1], O_RDONLY);

	nch = 1024;
	while (nch == 1024)
	{
		nch = read(file_from, buffer, 1024);
		if (nch == -1)
			cp_file(-1, 0, argv);
		nbw = write(file_to, buffer, nch);
		if (nbw == -1)
			cp_file(0, -1, argv);
	}
	error_close = close(file_from);
	if (error_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	error_close = close(file_to);
	if (error_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
	return (0);
}
