/*
Himanshu Shivhare
MT2024058

10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
*/
	
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	// Define the file name
    const char *fileName = "file10.txt";
    // get file descriptor	
    int fileDescriptor = open(fileName, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fileDescriptor < 0) {
        perror("Error opening file");
        return 1;
    }

	// Data to write into the file
    char buffer1[10] = "1234567890";
	char buffer2[10] = "ABCDEFGHIJ";
	// write in the file
	write(fileDescriptor , buffer1 , 10);
	write(fileDescriptor , buffer2 , 10);
	write(fileDescriptor , buffer1 , 10);
	int n = lseek(fileDescriptor, 0, SEEK_CUR);
	printf("%d\n", n);
	n = lseek(fileDescriptor , 10 , SEEK_CUR);
	printf("%d\n", n);
	n = lseek(fileDescriptor, 10, SEEK_CUR);
	printf("%d\n", n);

}

/*
	OUTPUT-
30
40
50

*/
