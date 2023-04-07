#include "main.h"

/**
 * create_file - function that does file creation
 * @filename: name of file to create
 * @text_content: NULL terminated string
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int s;
	int n;
	int r;

	if (!filename)
		return (-1);

	s = open(filename, 0_CREAT | 0_WRONLY | 0_TRUNC, 0600);

	if (s == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	if (n = 0; text_content[n]; n++)
		;

	r = write(s, text_content, n);

	if (r == -1)
		return (-1);

	close(s);

	return (1);
}
