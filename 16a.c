
/*
Himanshu Shivhare
MT2024058
*/

// 16. Write a program to perform mandatory locking.
// a. Implement write lock


#include <unistd.h>    
#include <fcntl.h>     
#include <sys/types.h> 
#include <sys/stat.h>  
#include <stdio.h>     

int main(int argc, char *argv[])
{
    char *filename;
    struct flock lock, lockStatus;
    int fileDescriptor;

    // Check if the filename argument is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    filename = argv[1];

   
    lock.l_type = F_WRLCK;    
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;         
    lock.l_len = 0;           
    lock.l_pid = getpid();    

  
    lockStatus = lock;

    
    fileDescriptor = open(filename, O_RDWR);

    
    if (fileDescriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    
    if (fcntl(fileDescriptor, F_GETLK, &lockStatus) == -1) {
        perror("Error getting lock status");
        close(fileDescriptor);
        return 1;
    }

    
    if (lockStatus.l_type == F_WRLCK) {
        printf("File is already locked for writing.\n");
    } else if (lockStatus.l_type == F_RDLCK) {
        printf("File is already locked for reading.\n");
    } else {
        
        if (fcntl(fileDescriptor, F_SETLK, &lock) == -1) {
            perror("Error setting lock");
            close(fileDescriptor);
            return 1;
        }
        printf("File is now locked for writing.\n");
    }

   
    close(fileDescriptor);

    return 0;
}
// File is now locked for writing.
