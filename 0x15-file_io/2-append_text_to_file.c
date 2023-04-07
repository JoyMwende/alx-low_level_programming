#include "main.h"

/**
 * append_text_to_file - append text at file end
 * @filename: namefile
 * @text_content: NULL string
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int s;
	int n;
	int r;

	if (!filename)
		return (-1);

	s = open(filename, O_WRONLY | O_APPEND);

	if (s == -1)
		return (-1);

	if (text_content)
	{
		for (n = 0; text_content[n]; n++)
			;

		r = write(s, text_content, n);

		if (r == -1)
			return (-1);
	}

	close(s);

	return (1);
}
