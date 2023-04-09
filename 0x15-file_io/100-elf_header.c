#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * prt_addrs = print address
 * @mgc: magic
 * Return: none
 */

void prt_addrs(char *mgc)
{
	int p;
	int b;
	int s;

	printf("  Entry point address:               0x");

	s = mgc[4] + '0';
	if (s == '1')
	{
		b = 26;
		printf("80");
		p = b;
		while (p >= 22)
		{
			p--;
			if (mgc[p] > 0)
				printf("%x", mgc[p]);
			else if (mgc[p] < 0)
				printf("%x", 256 + mgc[p]);
		}
		if (mgc[7] == 6)
			printf("00");
	}

	if (s == '2')
	{
		b = 26;
		for (p = b; p > 23; p--)
		{
			if (mgc[p] >= 0)
				printf("%02x", mgc[p]);
			else if (mgc[p] < 0)
				printf("%02x", 256 + mgc[p]);
		}
	}
	printf("\n");
}

/**
 * prt_type - type-print
 * @mgc: magic
 * Return: none
 */

void prt_type(char *mgc)
{
	char type = mgc[16];

	if (mgc[5] == 1)
		type = mgc[16];
	else
		type = mgc[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * prt_osabi - print-osabi
 * @mgc: magic
 * Return: none
 */

void prt_osabi(char *mgc)
{
	char osabi = mgc[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);

	printf("  ABI Version:                       %d\n", mgc[8]);
}

/**
 * prt_version - print-version.
 * @mgc: magic
 * Return: none
 */

void prt_version(char *mgc)
{
	int version = mgc[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}

/**
 * prt_data - data-print
 * @mgc: magic
 * Return: nothing
 */

void prt_data(char *mgc)
{
	char data = mgc[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}

/**
 * prt_magic - print-magic information
 * @mgc: magic
 * Return: nothing
 */

void prt_magic(char *mgc)
{
	int x;

	printf("  Magic:  ");

	x = 0;
	while (x < 16)
	{
		x++;
		printf(" %02x", mgc[x]);
	}
	printf("\n");
}

/**
 * chk_sys - check system version.
 * @mgc: magic
 * Return: none
 */

void chk_sys(char *mgc)
{
	char sys = mgc[4] + '0';

	if (sys == '0')
		exit(98);

	printf("ELF Header:\n");
	prt_magic(mgc);

	if (sys == '1')
		printf("  Class:                             ELF32\n");

	if (sys == '2')
		printf("  Class:                             ELF64\n");

	prt_data(mgc);
	prt_version(mgc);
	prt_osabi(mgc);
	prt_type(mgc);
	prt_addrs(mgc);
}

/**
 * chk_elf - check if it's elf-file
 * @mgc: magic
 * Return: 1 for elf-file, else 0
 */

int chk_elf(char *mgc)
{
	int addrs = (int)mgc[0];
	char E = mgc[1];
	char L = mgc[2];
	char F = mgc[3];

	if (addrs == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - check the code
 * @argc: no_of_arguments
 * @argv: arguments
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int x, r_read;
	char mgc[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	x = open(argv[1], O_RDONLY);

	if (x < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(x, 0, SEEK_SET);
	r_read = read(x, mgc, 27);

	if (r_read == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file cannot be read\n");
		exit(98);
	}

	if (chk_elf(mgc))
	{
		dprintf(STDERR_FILENO, "Err: it is not an elf\n");
		exit(98);
	}

	chk_sys(mgc);
	close(x);

	return (0);
}
