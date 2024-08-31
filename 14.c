/*
Himanshu Shivhare
MT2024058

14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    struct stat fileStat;

    // Retrieve file status
    if (lstat(argv[1], &fileStat) == -1) {
        perror("lstat failed");
        return EXIT_FAILURE;
    }

    printf("File type: ");

    // Determine the type of the file based on mode
    switch (fileStat.st_mode & S_IFMT)
    {
    case S_IFBLK:
        printf("Block device\n");
        break;
    case S_IFCHR:
        printf("Character device\n");
        break;
    case S_IFDIR:
        printf("Directory\n");
        break;
    case S_IFIFO:
        printf("FIFO/pipe\n");
        break;
    case S_IFLNK:
        printf("Symbolic link\n");
        break;
    case S_IFREG:
        printf("Regular file\n");
        break;
    case S_IFSOCK:
        printf("Socket\n");
        break;
    default:
        printf("Unknown type\n");
        break;
    }

    return EXIT_SUCCESS;
}

/*
File type: Regular file
*/
