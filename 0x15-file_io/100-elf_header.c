#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void elf_file(unsigned char *e_ident);
void print_ELF_magic(unsigned char *e_ident);
void print_data_of_ELF(unsigned char *e_ident);
void print_ELF_class(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_os_abi(unsigned char *e_ident);
void print_abi_version(unsigned char *e_ident);
void print_type_of_ELF(unsigned int e_type, unsigned char *e_ident);
void print_entrypoint(unsigned long int e_entry, unsigned char *e_ident);
void close_elf_file(int elf);


/**
 * elf_file - Checks to see id the file is an ELF file
 * @e_ident: Elf identification
 * Return: No return
*/
void elf_file(unsigned char* e_ident)
{
   int i;

   for (i = 0; i < 4; i++)
   {
   	if (e_ident[i] != 0x7f && e_ident[i] != 'E' && e_ident[i] != 'L' && e_ident[i] != 'F')
   	{	
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * print_ELF_magic - Prints the magic numbers of an ELF header
 * @e_ident: Elf id
 * 
 * Return: No return
*/
void print_ELF_magic(unsigned char* e_ident)
{
    int i;

    printf("Magic Number:    ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x ", e_ident[i]);
    }
    printf("\n");
}

/**
 * print_data_of_ELF - Prints the data of ELF header
 * @e_ident: Elf ID
 * 
 * Return: no return
*/
void print_data_of_ELF(unsigned char* e_ident)
{
    uint8_t data;  
    data = e_ident[EI_DATA];		
    printf("Data of ELF:      ");


    if (data == ELFDATANONE)
    {
        printf("none\n");
    }else if (data == ELFDATA2LSB)
    {
        printf("2's complement, little endian\n");
    }else if ( data == ELFDATA2MSB)
    {
        printf("2's complement, big endian\n");
    }
}

/**
 * print_ELF_class - Prints the class of ELF header
 * @e_indent: ELF ID
 * 
 * Return: no return
*/
void print_ELF_class(unsigned char* e_ident)
{
    uint8_t elf_class;
    elf_class  = e_ident[EI_CLASS];
    printf("class:                               ");


    if (elf_class == ELFCLASSNONE)
    {
        printf("none\n");
    }else if (elf_class == ELFCLASS32)
    {
        printf("ELF32\n");
    }else if (elf_class == ELFCLASS64)
    {
        printf("ELF64\n");
    }else
    {
        printf("<Unknown:0x%x>\n", elf_class);
    }

}

/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer of the ELF ID.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version of ELF:                           %d",
	    e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_os_abi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_os_abi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi_version - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi_version(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type_of_ELF - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type_of_ELF(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entrypoint - Prints the entry point address of an ELF header.
 * @e_entry: The address of the ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_entrypoint(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf_file - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf_file(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the content of the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf_file(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf_file(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	elf_file(header->e_ident);
	printf("ELF Header:\n");
	print_ELF_magic(header->e_ident);
	print_ELF_class(header->e_ident);
	print_data_of_ELF(header->e_ident);
	print_version(header->e_ident);
	print_os_abi(header->e_ident);
	print_abi_version(header->e_ident);
	print_type_of_ELF(header->e_type, header->e_ident);
	print_entrypoint(header->e_entry, header->e_ident);

	free(header);
	close_elf_file(o);
	return (0);
}

#include <elf.h>
