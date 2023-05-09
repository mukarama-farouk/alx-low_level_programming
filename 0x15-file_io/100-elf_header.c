#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

void error_exit(char *msg);
Elf64_Ehdr *read_elf_header(int fd);
void print_elf_header(Elf64_Ehdr *header);

/**
 * error_exit - Print error message
 * @msg: error message
 */
void error_exit(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * read_elf_header - Read and validate ELF header from file descriptor
 * @fd: file descriptor of ELF file
 * Return: pointer to ELF header on success, NULL on failure
 */
Elf64_Ehdr *read_elf_header(int fd)
{
	Elf64_Ehdr *header;
	ssize_t nr;

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
		error_exit("Error: Can't allocate memory for ELF header");

	nr = read(fd, header, sizeof(Elf64_Ehdr));
	if (nr == -1 || nr != sizeof(Elf64_Ehdr))
	{
		free(header);
		return (NULL);
	}

	if (memcmp(header->e_ident, ELFMAG, SELFMAG) != 0)
	{
		free(header);
		return (NULL);
	}

	return (header);
}

/**
 * print_elf_header - Print ELF header details
 * @header: ELF header to print
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("  Magic:   ");
	while (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             %s\n",
		header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
		header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
		header->e_ident[EI_CLASS] == ELFCLASSNONE ? "none" : "unknown");

	printf("  Data:                              %s\n",
		header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
		header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
		header->e_ident[EI_DATA] == ELFDATANONE ? "none" : "unknown");

	printf("  Version:                           %d%s\n",
		header->e_ident[EI_VERSION],
		header->e_ident[EI_VERSION] == EV_CURRENT ? " (current)" :
		header->e_ident[EI_VERSION] == EV_NONE ? " (invalid)" : "");

	printf("  OS/ABI:                            %s\n",
		header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
		header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
		header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
		header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
		header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
		header->e_ident[EI_OSABI] == ELFOSABI_AIX ? "UNIX - AIX" :
		header->e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
		header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX" : ;
}
