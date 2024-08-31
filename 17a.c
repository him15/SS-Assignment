/*
Himanshu Shivhare
MT2024058

17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/

#include <sys/stat.h>   // For file mode constants
#include <sys/types.h>  // For data types used in system calls
#include <unistd.h>     // For read, write, and close functions
#include <stdio.h>      // For standard I/O functions
#include <fcntl.h>      // For file control options

int main(int argc, char *argv[])
{
    // Ensure that a file name is provided as an argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file specified by the argument
    int fileDescriptor = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
    if (fileDescriptor == -1) {
        perror("Failed to open the file");
        return 1;
    }

    // Buffer to hold the input
    char buffer[10];
    ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

    // Check if reading from standard input was successful
    if (bytesRead < 0) {
        perror("Error reading input");
        close(fileDescriptor);
        return 1;
    }

    // Null-terminate the buffer to ensure safe string handling
    buffer[bytesRead] = '\0';

    // Write the input to the file
    if (write(fileDescriptor, buffer, bytesRead) == -1) {
        perror("Error writing to file");
        close(fileDescriptor);
        return 1;
    }

    printf("Ticket number has been successfully saved to the file.\n");

    // Close the file descriptor
    close(fileDescriptor);

    return 0;
}
