#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename to be craeted
 * @text_content: A NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fptr;
	int ch;
	int nbyte;

	if (filename == NULL)
		return (-1);
	fptr = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fptr == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";
	for (ch = 0; text_content[ch]; ch++)
		;

	nbyte = write(fptr, text_content, ch);
	if (nbyte == -1)
		return (-1);
	close(fptr);
	return (1);
}
