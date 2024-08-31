/*
Himanshu Shivhare
MT2024058

16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
*/

#include <unistd.h>    
#include <fcntl.h>     
#include <sys/types.h> 
#include <sys/stat.h> 
#include <stdio.h>    

int main(int argc, char *argv[])
{
    char *fileName;
    struct flock fileLock, lockStatus;
    int fd;

   
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fileName = argv[1];

    
    fileLock.l_type = F_RDLCK;    // Request a read lock
    fileLock.l_whence = SEEK_SET; // Start from the beginning of the file
    fileLock.l_start = 0;         // Lock from the start
    fileLock.l_len = 0;           // Lock the entire file
    fileLock.l_pid = getpid();    // Record the process ID

    // Copy the lock parameters to check the current lock status
    lockStatus = fileLock;

    // Open the file in read-only mode
    fd = open(fileName, O_RDONLY);

    // Check if the file was opened successfully
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Retrieve the current lock status of the file
    if (fcntl(fd, F_GETLK, &lockStatus) == -1) {
        perror("Error getting lock status");
        close(fd);
        return 1;
    }

    // Determine if the file is already locked
    if (lockStatus.l_type == F_WRLCK) {
        printf("The file is currently locked for writing.\n");
    } else if (lockStatus.l_type == F_RDLCK) {
        printf("The file is currently locked for reading.\n");
    } else {
        // Attempt to set the read lock
        if (fcntl(fd, F_SETLK, &fileLock) == -1) {
            perror("Error setting lock");
            close(fd);
            return 1;
        }
        printf("The file has been successfully locked for reading.\n");
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
/*
The file has been successfully locked for reading.
*/
