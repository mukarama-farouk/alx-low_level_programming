#include "main.h"

/**
 * read_textfile - function that reads a text file and
 *prints it to the POSIX standard output
 * @filename: the filename
 * @letters: Number of letters it should read and print
 *
 * Return: actual number of letters it could read and print or 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fptr;
	ssize_t nbr;
	ssize_t nbw;
	char *str;

	fptr = open(filename, O_RDONLY);
	if (fptr == -1)
		return (0);

	if (filename == NULL)
		return (0);

	str = malloc(sizeof(char) * letters);
	if (str == NULL)
		return (0);

	nbr = read(fptr, str, letters);
	nbw = write(STDOUT_FILENO, str, nbr);

	close(fptr);
	free(str);
	return (nbw);
}
