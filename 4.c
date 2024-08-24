// Himanshu Shivhare
// MT2024058
// Program :4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd = open("program4.txt" , O_RDWR); // read write operation
	if(fd == -1){
		perror("File doesn't Exist \n");
	}else{
		printf("File Status : %d\n" , fd);
	}
	int temp = open("program4.txt" , O_EXCL); // it enrures that open fails if the file is already exist
	printf("Status %d" , temp);
}
