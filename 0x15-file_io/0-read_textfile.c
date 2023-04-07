#include "main.h"

/**
 * read_textfile - read text file and print it to stdout
 * @letters: no of letters
 * @filename: namefile
 * Return: letters
 * 0 if filename is NULL and file can't be
 * opened and read
 * or write fails
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int t;
	size_r xyz, abc;
	char *buffer;

	if (!filename)
		return (0);

	t = open(filename, O_RDONLY);

	if (t == 1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
		return (0);

	xyz = read(t, buffer, letters);
	abc = write(STDOUT_FILENO, buffer, xyz);

	close(t);

	free(buffer);

	return (abc);
}
