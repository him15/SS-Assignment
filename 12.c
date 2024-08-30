
/*
Himanshu Shivhare
MT2024058

12. Write a program to find out the opening mode of a file. Use fcntl.
*/





#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    // Open the file specified by the command-line argument in read-only mode
    int fileDescriptor = open(argv[1], O_RDONLY);
    
    // Retrieve the file status flags
    int fileFlags = fcntl(fileDescriptor, F_GETFL);
    printf("File status flags: %d\n", fileFlags);
    
    // Extract the access mode from the file status flags
    int accessMode = fileFlags & O_ACCMODE;
    printf("Access mode: %d\n", accessMode);
    
    // Print the access mode in a human-readable format
    switch (accessMode)
    {
    case O_RDWR:
        printf("File is opened in read and write mode.\n");
        break;
    case O_WRONLY:
        printf("File is opened in write-only mode.\n");
        break;
    case O_RDONLY:
        printf("File is opened in read-only mode.\n");
        break;
    default:
        printf("Unknown access mode.\n");
        break;
    }
    
    // Close the file descriptor
    close(fileDescriptor);

    return 0;
}



/*
OUTPUT 

File status flags: 32768
Access mode: 0
File is opened in read-only mode.
*/


