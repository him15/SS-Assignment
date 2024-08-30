/*
Himanshu Shivhare
MT2024058

11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
*/
// The dup() system call creates a copy of the file descriptor oldfd, using the lowest-numbered
// unused file dscription for the new descriptor.
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    // Open the file specified by the first command-line argument
    int fileDescriptor = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);

    // Duplicate the file descriptor to get a new file descriptor
    int newFD1 = dup(fileDescriptor);
    write(fileDescriptor, "Hello, written with the original file descriptor\n", 46);
    write(newFD1, "Hello, written with the duplicated file descriptor\n", 50);

    // Use dup2 to duplicate the file descriptor to a specific number (10 if available)
    int newFD2 = dup2(fileDescriptor, 10);
    if (newFD2 != -1) {
        write(newFD2, "Hello, written with the dup2() file descriptor\n", 47);
    }

    // Use fcntl to duplicate the file descriptor to a file descriptor number >= 5
    int newFD3 = fcntl(fileDescriptor, F_DUPFD, 5);
    if (newFD3 != -1) {
        write(newFD3, "Hello, written with the fcntl() file descriptor\n", 46);
    }

    // Close all file descriptors
    close(fileDescriptor);
    close(newFD1);
    close(newFD2);
    close(newFD3);

    return 0;
}
